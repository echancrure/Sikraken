%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                 Copyright 2024 SETU - Dr Christophe Meudec 
%%                                     <https://github.com/echancrure/Sikraken>
%% This file is part of Sikraken.
%% Sikraken is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
%%   the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
%% Sikraken is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
%%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
%% You should have received a copy of the GNU General Public License along with Mika.  If not, see <https://www.gnu.org/licenses/>.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% defines module se_main
% symbolic execution of parsed C code
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- get_flag(version, '7.1').    %check for valid ECLiPSe version: issue warning only if not 
%%%
mytrace.            %call this to start debugging
:- spy mytrace/0.
%%%
:- (is_predicate(prolog_c/2) -> abolish prolog_c/2 ; dynamic prolog_c/2).   %to ensure clean environment when using 'make' during development 

:- use_module(library('lists')).

:- use_module("./../Solver/PTC-Solver/source/ptc_solver").

:- use_module(['common_util', 'se_globals']).

:- use_module(['se_name_atts', 'se_seav_atts', 'se_sub_atts']).

:- compile(['se_handle_declarations', 'se_symbolically_execute', 'se_symbolically_interpret']).
:- compile(['se_write_tests_testcomp']).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% home pc   se_main('//C/Users/Chris2/GoogleDrive/Sikraken/', '//C/Users/Chris2/GoogleDrive/Sikraken/SampleCode/', basic001, main, debug)
% laptop    se_main('//C/Users/echan/My Drive/Sikraken/', '//C/Users/echan/My Drive/Sikraken/SampleCode/', basic001, basic, debug)
go_laptop :- se_main('//C/Users/echan/My Drive/Sikraken/', '//C/Users/echan/My Drive/Sikraken/SampleCode/', basic001, basic, debug).
go_pc :- se_main('//C/Users/Chris2/GoogleDrive/Sikraken/', '//C/Users/Chris2/GoogleDrive/Sikraken/SampleCode/', basic002, basic, debug).
go_linux :- se_main('/home/chris/Sikraken/', '/home/chris/Sikraken/SampleCode/', testcov_simple_if, main, debug, testcomp).
se_main(Install_dir, Parsed_dir, Target_source_file_name, Target_raw_subprogram_name, Debug_mode, Output_mode) :-
    initialise,
    se_globals__set_globals(Install_dir, Debug_mode),
    capitalize_first_letter(Target_raw_subprogram_name, Target_subprogram_name),
    read_parsed_file(Parsed_dir, Target_source_file_name, Target_subprogram_name, prolog_c(Parsed_prolog_code), Main, Target_subprogram_var, Return_var),      %may fail if badly formed due to parsing errors
    mytrace,
    symbolic_execute(Parsed_prolog_code),   %always symbolically execute all global declarations for now: initiailisations could be ignored via a switch if desired
    (Output_mode == 'testcomp' ->
        ((se_sub_atts__get(Main, 'parameters', []), se_sub_atts__get(Main, 'return_type', 'integer')) ->
            (print_preamble_testcomp(Parsed_dir, Target_source_file_name),
             se_sub_atts__get(Main, 'body', Main_compound_statement),
             symbolic_execute(Main_compound_statement),
             se_globals__getref('verifier_inputs', Verifier_inputs),
             label_testcomp(Verifier_inputs)
            )
        ;
            common_util__error(10, "Unexpected main format in testcomp mode", "Best not to proceed", [('Main', Main)], 10140824_1, 'se_main', 'se_main', no_localisation, no_extra_info)
        )
    ;
        (%always symbolically execute void main(void) for now: should be a switch allowing the main to be ignored via a switch if desired
         se_sub_atts__get(Main, 'parameters', [param_no_decl([void], [])]),  %only handling main with no parameters for now
         se_sub_atts__get(Main, 'return_type', void),                        %only handling main with void return type for now
         se_sub_atts__get(Main, 'body', Main_compound_statement),
         symbolic_execute(Main_compound_statement),         %symbolically execute the target C function: for now only inputs are its arguments (expand to globals that get overwritten with a switch)
         se_sub_atts__get(Target_subprogram_var, 'return_type', Return_type),
         declare_return(Return_var, Return_type),    %belong to the outer scope
         se_sub_atts__get(Target_subprogram_var, 'parameters', Params),
         se_globals__push_scope_stack,       %create function parameter scope
         declare_params(Params, SEAV_Inputs),
         se_sub_atts__get(Target_subprogram_var, 'body', Compound_statement),
         symbolic_execute(Compound_statement),
         label(SEAV_Inputs)
        )
    ),
    se_globals__getval('path_nb', Test_nb),
    Inc_test_nb is Test_nb + 1,
    se_globals__setval('path_nb', Inc_test_nb),
    (Output_mode == 'testcomp' ->
        print_test_inputs_testcomp(Verifier_inputs)
    ;
        print_test_inputs(SEAV_Inputs)
    ),
    (Output_mode == 'testcomp' ->
        true    %don't print expected outputs
    ;
        (se_globals__pop_scope_stack,    %only after labeling and printed to preserve parameters
         term_variables(Parsed_prolog_code, All_Ids),
         get_all_outputs(All_Ids, All_seavs),
         print_test_outputs(All_seavs),    
         flush(user_output)
        )
    ),
    fail.       %oh yes!
se_main(_Install_dir, _Parsed_dir, Target_source_file_name, _Target_raw_subprogram_name, _Debug_mode, Output_mode) :-
    (Output_mode == 'testcomp' ->
        terminate_testcomp(Target_source_file_name)
    ;
        printf(user_output, "\nSUCCESS", [])
    ).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    capitalize_first_letter(Input, Output) :-
        atom_string(Input, Input_string),
        string_chars(Input_string, [FirstChar|RestChars]),
        char_code(FirstChar, FirstCharCode),
        ((FirstCharCode >= 97, FirstCharCode =< 122) -> %a lowercase letter (ASCII a-z)
            (UpperFirstCharCode is FirstCharCode - 32,
             char_code(UpperFirstChar, UpperFirstCharCode)
            )
        ; 
            UpperFirstChar = FirstChar
        ),
        string_chars(Output_string, [UpperFirstChar|RestChars]),
        atom_string(Output, Output_string). 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
initialise :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
read_parsed_file(Parsed_dir, Target_source_file_name, Target_raw_subprogram_name, CProlog, Main, Target_subprogram_var, Return_var) :-
    concat_atom([Parsed_dir, Target_source_file_name, '.pl'], Parsed_filename),
    (open(Parsed_filename, read, Stream) ->
        (read_term(Stream, CProlog, [variable_names(VarsNames)]) ->
            (close(Stream),
             se_name_atts__initL(VarsNames),     %initialise all C vars with their id
             (memberchk(Target_raw_subprogram_name = Target_subprogram_var, VarsNames) ->
                (memberchk('Main' = Main, VarsNames) ->
                    (memberchk('Sikraken_return' = Return_var, VarsNames) ->
                        true
                    ;
                        Return_var = null
                    )
                ;
                    Main = null
                )
             ;
                common_util__error(10, "Could not find the target function", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename), ('Target_raw_subprogram_name', Target_raw_subprogram_name)], 10080824_1, 'se_main', 'read_parsed_file', no_localisation, "make sure the function name starts with an uppercase")
             )
            )
        ;
            common_util__error(10, "Reading parsed file failed", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename)], 102607241, 'se_main', 'read_parsed_file', no_localisation, "the parser probably produced bad Prolog code")
        )
    ;
        common_util__error(10, "Parsed file does not exist", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename)], 10260724, 'se_main', 'read_parsed_file', no_localisation, no_extra_info)
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
label(SEAV_Inputs) :-
    get_all_inputs(SEAV_Inputs, InputsL),
    ptc_solver__label_integers(InputsL),
    !.
    %%%
    get_all_inputs([], []).
    get_all_inputs([Seav|R_seavs], [Input|R_inputs]) :-
        seav__get(Seav, 'input', Input),
        get_all_inputs(R_seavs, R_inputs).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
label_testcomp(Verifier_inputs) :-
    ptc_solver__label_integers(Verifier_inputs),
    !.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
get_all_outputs([], []).
get_all_outputs([Id|R_ids], All_outputs) :-
    (seav__seav_is_in_scope(Id) ->
         All_outputs = [Id|R_outputs]
    ;
        All_outputs = R_outputs
    ),
    get_all_outputs(R_ids, R_outputs).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_inputs([]).
print_test_inputs([SEAV|R]) :-
    se_name_atts__get(SEAV, 'name', Name),
    seav__get(SEAV, 'input', Input_value),
    printf(user_output, "\nInput %w = %w", [Name, Input_value]),
    print_test_inputs(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_outputs([]).
print_test_outputs([SEAV|R]) :-
    se_name_atts__get(SEAV, 'name', Name),
    seav__get(SEAV, 'output', Output_value),
    printf(user_output, "\nOutput %w = %w", [Name, Output_value]),
    print_test_outputs(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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

:-compile(['se_handle_declarations', 'se_symbolically_execute', 'se_symbolically_interpret']).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% home pc   se_main('//C/Users/Chris2/GoogleDrive/Sikraken/', '//C/Users/Chris2/GoogleDrive/Sikraken/SampleCode/', basic001, main, debug)
% laptop    se_main('//C/Users/echan/My Drive/Sikraken/', '//C/Users/echan/My Drive/Sikraken/SampleCode/', basic001, basic, debug)
go_laptop :- se_main('//C/Users/echan/My Drive/Sikraken/', '//C/Users/echan/My Drive/Sikraken/SampleCode/', basic001, basic, debug).
go_pc :- se_main('//C/Users/Chris2/GoogleDrive/Sikraken/', '//C/Users/Chris2/GoogleDrive/Sikraken/SampleCode/', basic001, basic, debug).
se_main(Install_dir, Parsed_dir, Target_source_file_name, Target_raw_subprogram_name, Debug_mode) :-
    initialise,
    se_globals__set_globals(Install_dir, Debug_mode),
    read_parsed_file(Parsed_dir, Target_source_file_name),      %may fail if badly formed due to parsing errors
    prolog_c(Parsed_prolog_code, sikraken_xref(NamesL)),        %retrieve the entire contents of the parsed Prolog code
    se_name_atts__initL(NamesL),     %initialise all C vars with their id 
    symbolic_execute(Parsed_prolog_code),   %always symbolically execute all global declarations for now: initiailisations could be ignored via a switch if desired 
    %always symbolically execute void main(void) for now: should be a switch allowing the main to be ignored via a switch if desired
    memberchk(a(Main, 'main'), NamesL),
    se_sub_atts__get(Main, 'parameters', [param_no_decl([void], [])]),  %only handling main with no parameters for now
    se_sub_atts__get(Main, 'return_type', void),                        %only handling main with void return type for now
    se_sub_atts__get(Main, 'body', Main_compound_statement),
    symbolic_execute(Main_compound_statement),
    %symbolically execute the target C function: for now only inputs are its arguments (expand to globals that get overwritten with a switch)
    memberchk(a(Target_subprogram_var, Target_raw_subprogram_name), NamesL),
    se_sub_atts__get(Target_subprogram_var, 'parameters', Params),
    declare_params(Params, Declared_params_seavs),
    se_sub_atts__get(Target_subprogram_var, 'return_type', Return_type),
    memberchk(a(Return_var, 'Sikraken_return'), NamesL),
    declare_return(Return_var, Return_type),
    se_sub_atts__get(Target_subprogram_var, 'body', Compound_statement),
    symbolic_execute(Compound_statement),
    mytrace,
    label(Declared_params_seavs),
    print_test_inputs(Declared_params_seavs),
    term_variables(Parsed_prolog_code, All_Ids),
    get_all_outputs(All_Ids, All_seavs),
    print_test_outputs(All_seavs),
    fail.       %oh yes!
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
initialise :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
read_parsed_file(Parsed_dir, Target_source_file_name) :-
    concat_atom([Parsed_dir, Target_source_file_name, '.pl'], Parsed_filename),
    (exists(Parsed_filename) ->
        (compile(Parsed_filename) ->    %may fail if parsed file contents is not well formed
            true
        ;
            common_util__error(10, "Compilation of parsed file failed", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename)], 102607241, 'se_main', 'read_parsed_file', no_localisation, "the parser probably produced bad Prolog code")
        )
    ;
        common_util__error(10, "Parsed file does not exist", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename)], 10260724, 'se_main', 'read_parsed_file', no_localisation, no_extra_info)
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
label(Declared_params_seavs) :-
    get_all_inputs(Declared_params_seavs, InputsL),
    ptc_solver__label_integers(InputsL),
    !.
    %%%
    get_all_inputs([], []).
    get_all_inputs([Seav|R_seavs], [Input|R_inputs]) :-
        seav__get(Seav, 'input', Input),
        get_all_inputs(R_seavs, R_inputs).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
get_all_outputs([], []).
get_all_outputs([Id|R_ids], All_outputs) :-
    (seav__is_seav(Id) ->
         All_outputs = [Id|R_outputs]
    ;
        All_outputs = R_outputs
    ),
    get_all_outputs(R_ids, R_outputs).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_inputs([]).
print_test_inputs([Seav|R]) :-
    se_name_atts__get(Seav, 'name', Name),
    seav__get(Seav, 'input', Input_value),
    printf(user_output, "\nInput %w = %w", [Name, Input_value]),
    print_test_inputs(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_outputs([]).
print_test_outputs([Seav|R]) :-
    se_name_atts__get(Seav, 'name', Name),
    seav__get(Seav, 'output', Output_value),
    printf(user_output, "\nOutput %w = %w", [Name, Output_value]),
    print_test_outputs(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
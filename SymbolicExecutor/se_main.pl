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
%:- set_flag('debug_compile', 'off').   %does not really help 
:- get_flag(version, '7.1').            %check for valid ECLiPSe version: issue warning only if not 
%:- set_flag(after_event_timer, virtual). %tdo check why this does not work and causes an error: out of range in set_flag(after_event_timer, virtual)

mytrace.            %call this to start debugging
:- spy mytrace/0.
%%%
:- (is_predicate(prolog_c/2) -> abolish prolog_c/2 ; dynamic prolog_c/2).   %to ensure clean environment when using 'make' during development 

:- use_module(library('ic')).
:- use_module(library('lists')).
:- use_module(library('timeout')).

:- use_module("./../PTC-Solver/source/ptc_solver").

:- use_module(['super_util', 'se_globals', 'se_name_atts', 'se_seav_atts', 'se_sub_atts']).

:- compile(['common_util', 'se_handle_declarations', 'se_symbolically_execute', 'se_symbolically_interpret']).
:- compile(['se_write_tests_testcomp']).
:- compile(['se_coverage']).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  
go(Restart, Tries) :- se_main(['/home/chris/Sikraken/', '/home/chris/Sikraken/SampleCode/','hardness_codestructure_dependencies_file-0', main, release, testcomp, '-m32', Restart, Tries]).
%go1 :- se_main(['/home/chris/Sikraken/', '/home/chris/Sikraken/regression_tests/','Problem03_label00', main, debug, testcomp, '-m32', 30, 25]).
go_linux(Target_source_file_name_no_ext, Restart, Tries) :- se_main(['/home/chris/Sikraken/', "/home/chris/Sikraken/SampleCode/", Target_source_file_name_no_ext, main, debug, testcomp, '-m32', Restart, Tries]).
go_linux(Parsed_dir, Target_source_file_name_no_ext, Restart, Tries) :- se_main(['/home/chris/Sikraken/', Parsed_dir, Target_source_file_name_no_ext, main, debug, testcomp, '-m32', Restart, Tries]).

se_main(ArgsL) :-
    (ArgsL = [Install_dir, Parsed_dir, Target_source_file_name_no_ext, Target_raw_subprogram_name, Debug_mode, Output_mode, Data_model, Restart, Nb_of_paths_to_try] ->
        true
    ;
        common_util__error(10, "Calling se_main/? with invalid argument list", "Review calling syntax of se_main/?", [], '10_240824_1', 'se_main', 'se_main', no_localisation, no_extra_info)
    ),
    print_test_run_log__preamble(ArgsL),
    %concat_string([Install_dir, "PTC-Solver/source/"], Solver_install_dir),
    super_util__quick_dev_info("Analysing %w with %w restarts and %w tries.", [Target_source_file_name_no_ext, Restart, Nb_of_paths_to_try]),
    se_globals__set_globals(Install_dir, Target_source_file_name_no_ext, Debug_mode, Output_mode, Data_model),
    initialise_ptc_solver,
    capitalize_first_letter(Target_raw_subprogram_name, Target_subprogram_name),
    read_parsed_file(Parsed_dir, Target_source_file_name_no_ext, Target_subprogram_name, prolog_c(Parsed_prolog_code), Main, Target_subprogram_var),      %may fail if badly formed due to parsing errors
    symbolic_execute(Parsed_prolog_code, _),   %always symbolically execute all global declarations for now: initialisations could be ignored via a switch if desired
    print_preamble_testcomp(Parsed_dir),
    (catch(search_CFG(Restart, param(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code, Nb_of_paths_to_try)), 'global_trail_overflow', overflow_caught('global_trail_overflow', Output_mode)) ->
        true
    ;
        common_util__error(10, "global_trail_overflow trigerred", "Investigate and/or increase global strail stack size", [], '10_190924_1', 'se_main', 'se_main', no_localisation, no_extra_info)
    ),
    log_and_zip(Output_mode).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    overflow_caught(Overflow_type, Output_mode) :-
        log_and_zip(Output_mode),
        common_util__error(9, "!!!!!!!!!!!!!! Stack overflow during search caught", "Review symbolic executio and/or increase initial ECLiPSe stack", [('Overflow_type', Overflow_type)], '9_190924_1', 'se_main', 'se_main', no_localisation, no_extra_info).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    log_and_zip(Output_mode) :-
        (Output_mode == 'testcomp' ->
            terminate_testcomp
        ;
            printf(user_output, "\nSUCCESS", [])
        ),
        print_test_run_log__terminate.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* %work in progress
search_CFG_budget(Budget, param(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code, Nb_of_paths_to_try)) :-
    try_budget(
    

try_budget(...) :-
    se_globals__get_val('path_nb', Pre_test_number),
    timeout(    find_one_path(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code),
                Single_test_time_limit,
                (super_util__quick_dev_info("Timer trigerred", []), Post_test_number = -999),
                'per_solution',
                _Timer,
                _Due_time,
                _Time_remaining
           ),
    (Post_test_number == -999 ->
        %timer was triggered: we increase the timer and try again
         ???
    ;
        (%if we are here we attempted a path, but perhaps no test vector was generated because there was nothing new to cover or labeling failed
         se_globals__get_val('path_nb', Post_test_number),
         (Post_test_number == Pre_test_number ->
            (%potentially bad: we attempted a path, but no test vector was generated because there was nothing new to cover or labeling failed
             %we can only do that so many times...
             ???
            )
         ;
            %good a test input was generated within the Single_test_time_limit so we backtrack
            fail    %to generate a new solution based on backtracking 
         )
        )
    ).
*/

search_CFG(Restart, param(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code, Nb_of_paths_to_try)) :-
    se_globals__set_val('single_test_time_limit', 0.01),
    (for(I, 1, Restart), loop_name('restart'), param(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code, Nb_of_paths_to_try)
     do (
            (Debug_mode == 'debug' -> 
                (printf(user_error, "Restart number: %w%n", [I])
                 %,mytrace
                ) 
            ; 
                true
            ),
            not(
                (try_nb_path_budget(param(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)) -> %try_nb_path(Nb_of_paths_to_try, 'try', param(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)) ->
                    fail
                ;
                    (common_util__error(9, "!!!!!!!!!!!!!! Unexpected fail in try_nb_path: either it is a bug [mostly likely] or full coverage was achieved", "Best not to proceed", [], '10_210824_1', 'se_main', 'se_main', no_localisation, no_extra_info),
                     fail   %to make sure top level succeeds...
                    )
                )
            )
        )
    ).
%%%
try_nb_path(_, Iteration_counter, _) :-
    setval(Iteration_counter, 0),
    fail.
try_nb_path(Nb_of_paths_to_try, Iteration_counter, param(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)) :-
    Time_limit = 2,
    timeout(    find_one_path(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code),
                Time_limit,
                super_util__quick_dev_info("Timer trigerred", []),      
                'per_solution',
                _Timer,
                _Due_time,
                _Time_remaining
           ),
    getval(Iteration_counter, I),
    I1 is I + 1,
    setval(Iteration_counter, I1),
    (Nb_of_paths_to_try == I1 ->
        true    %reached target number of test inputs generated 
    ;
        fail    %will generate more solutions by backtracking through find_one_path (and eventually symbolic_execution)
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*search_CFG_budget(Restart, param(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code, Nb_of_paths_to_try)) :-
(for(I, 1, Restart), loop_name('restart'), param(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code, Nb_of_paths_to_try)
 do (
        (Debug_mode == 'debug' -> 
            (printf(user_error, "Restart number: %w%n", [I])
             %,mytrace
            ) 
        ; 
            true
        ),
        not(
            (try_nb_path(Nb_of_paths_to_try, 'try', param(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)) ->
                fail
            ;
                (common_util__error(9, "!!!!!!!!!!!!!! Unexpected fail in try_nb_path: either it is a bug [mostly likely] or full coverage was achieved", "Best not to proceed", [], '10_210824_1', 'se_main', 'se_main', no_localisation, no_extra_info),
                 fail   %to make sure top level succeeds...
                )
            )
        )
    )
).*/
%%%
try_nb_path_budget(param(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)) :-
    %mytrace,
    se_globals__get_val('single_test_time_limit', Single_test_time_limit),
    se_globals__get_val('path_nb', Pre_test_number),
    set_event_handler('single_test_time_out_event', handle_single_test_time_out_event/0),
    timeout(    (statistics(event_time, Start_time), find_one_path(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)),
                30,
                (Post_test_number = -999),  
                'all_solution',
                Path_timer,
                Due_time,
                Time_remaining
    ),
    (Post_test_number == -999 ->
        (super_util__quick_dev_info("Timer trigerred", [])
        )
    ;
        (%if we are here we attempted a path, but perhaps no test vector was generated because there was nothing new to cover or labeling failed
         se_globals__get_val('path_nb', Post_test_number),
         (Post_test_number == Pre_test_number ->
            (%potentially bad: we attempted a path, but no test vector was generated because there was nothing new to cover or labeling failed
             %we can only do that so many times...
             fail
            )
        ;
            (%good a test input was generated within the Single_test_time_limit so we backtrack
             cancel_after_event(Path_timer, _CancelledEvents),
             statistics(event_time, End_time),
             Solution_duration is End_time - Start_time,
             super_util__quick_dev_info("Solution duration:", [Solution_duration]),
             getval('single_test_time_out', Single_test_time_out),
             (Single_test_time_out == inf ->    %first time
                (New_single_test_time_out is 2 * Solution_duration,
                 setval('single_test_time_out', New_single_test_time_out),
                 event_after(Path_timer, New_single_test_time_out)
                )
             ;
                true    %Single_test_time_out left as is for now
             ),
             fail    %to generate a new solution based on backtracking 
            )
         )
        )
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
find_one_path(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code) :-
    (Output_mode == 'testcomp' ->
        (se_sub_atts__get(Main, 'parameters', Parameters),
         ((Parameters == [] ; Parameters == [param_no_decl([void], [])]) -> %i.e. main() or main(void)
            (se_sub_atts__get(Main, 'return_type', Return),
             (Return == 'int' ->
                (se_sub_atts__get(Main, 'body', Main_compound_statement),
                 se_globals__update_ref('current_path_bran', start('Target_raw_subprogram_name', true)),
                 %mytrace,
                 symbolic_execute(Main_compound_statement, _Flow)
                )
             ;
                common_util__error(10, "Unexpected main return in testcomp mode", "Best not to proceed", [('Return', Return)], '10_050924_1', 'se_main', 'se_main', no_localisation, no_extra_info)
             )
            )
          ;
            common_util__error(10, "Unexpected main parameters in testcomp mode", "Best not to proceed", [('Parameters', Parameters)], '10_140824_1', 'se_main', 'se_main', no_localisation, no_extra_info)
         )
        )
    ;
        (%ignore this alternative for now: not testcomp
         %always symbolically execute void main(void) for now: should be a switch allowing the main to be ignored via a switch if desired
         se_sub_atts__get(Main, 'parameters', [param_no_decl([void], [])]),  %only handling main with no parameters for now
         se_sub_atts__get(Main, 'return_type', void),                        %only handling main with void return type for now
         se_sub_atts__get(Main, 'body', Main_compound_statement),
         symbolic_execute(Main_compound_statement, _Flow),         %symbolically execute the target C function: for now only inputs are its arguments (expand to globals that get overwritten with a switch)
         se_sub_atts__get(Target_subprogram_var, 'return_type', _Return_type),
         se_sub_atts__get(Target_subprogram_var, 'parameters', Params),
         se_globals__push_scope_stack,       %create function parameter scope
         declare_params(Params, SEAV_Inputs),
         se_sub_atts__get(Target_subprogram_var, 'body', Compound_statement),
         symbolic_execute(Compound_statement, _Flow)
        )
    ),
    end_of_path_predicate(SEAV_Inputs, Parsed_prolog_code).
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
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    end_of_path_predicate(SEAV_Inputs, Parsed_prolog_code) :-
        se_coverage__bran_newly_covered(Newly_covered),
        (Newly_covered == [] -> %no need to label: saves labelling run and test execution time
            true %common_util__error(0, "End of path: no new branches", 'no_error_consequences', [], '0_210824_1', 'se_main', 'end_of_path_predicate', no_localisation, no_extra_info)
        ;
            (se_globals__get_val('output_mode', Output_mode),
             (Output_mode = 'testcomp' ->
                (se_globals__get_ref('verifier_inputs', Verifier_inputs),
                 %mytrace,
                 (label_testcomp(Verifier_inputs, Labeled_inputs) ->
                    (se_globals__get_val('path_nb', Test_nb),
                     Inc_test_nb is Test_nb + 1,
                     %(Inc_test_nb == 9 -> mytrace ; true),
                     se_globals__set_val('path_nb', Inc_test_nb),
                     se_globals__get_ref('current_path_bran', Current_path),
                     prune_instances(Current_path, Current_path_no_duplicates),
                     se_globals__get_val('covered_bran', Already_covered),
                     union(Already_covered, Current_path_no_duplicates, Covered),
                     se_globals__set_val('covered_bran', Covered),
                     common_util__error(0, "End of path", 'no_error_consequences', [('Path Nb', Inc_test_nb), ('Newly_covered', Newly_covered), ('Current_path', Current_path)], '0_190824_1', 'se_main', 'end_of_path_predicate', no_localisation, no_extra_info),
                     (Output_mode == 'testcomp' ->
                        print_test_inputs_testcomp(Labeled_inputs)   %but don't print expected outputs
                     ;
                        (print_test_inputs(SEAV_Inputs),
                         se_globals__pop_scope_stack,    %only after labeling and printed to preserve parameters
                         term_variables(Parsed_prolog_code, All_Ids),
                         get_all_outputs(All_Ids, All_seavs),
                         print_test_outputs(All_seavs),    
                         flush(user_output)
                        )
                     )
                    )
                 ;
                    true    %labeling failed (perhaps floating points could not be labeled or there was no solution to integer non-linear constraints, who knows), we succeed to count it as a valid attempt
                 )
                )
             ;
                common_util__error(10, "Unexpected output mode", "Only testcomp format is supported for now", [('Output_mode', Output_mode)], '10_100924_1', 'se_main', 'end_of_path_predicate', no_localisation, no_extra_info)
             )
            )
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
initialise_ptc_solver :-
    ptc_solver__clean_up,
    se_globals__get_val('data_model', Data_model),
    ptc_solver__default_declarations(Data_model).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
read_parsed_file(Parsed_dir, Target_source_file_name_no_ext, Target_raw_subprogram_name, CProlog, Main, Target_subprogram_var) :-
    concat_atom([Parsed_dir, Target_source_file_name_no_ext, '.pl'], Parsed_filename),
    (exists(Parsed_filename) ->
        (open(Parsed_filename, read, Stream),
         read_term(Stream, CProlog, [variable_names(VarsNames)]) ->
            (close(Stream),
             se_name_atts__initL(VarsNames),     %initialise all C vars with their id
             (memberchk(Target_raw_subprogram_name = Target_subprogram_var, VarsNames) ->
                (memberchk('Main' = Main, VarsNames) ->
                    true
                ;
                    Main = null
                )
             ;
                common_util__error(10, "Could not find the target function", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename), ('Target_raw_subprogram_name', Target_raw_subprogram_name)], '10_080824_1', 'se_main', 'read_parsed_file', no_localisation, "make sure the function name starts with an uppercase")
             )
            )
        ;
            common_util__error(10, "Reading parsed file failed", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename)], '10_260724_1', 'se_main', 'read_parsed_file', no_localisation, "the parser probably produced bad Prolog code")
        )
    ;
        common_util__error(10, "Parsed file does not exist", "Cannot process parsed C code", [('Parsed_filename', Parsed_filename)], '10_260724', 'se_main', 'read_parsed_file', no_localisation, no_extra_info)
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
%Verifier_inputs is of the form [verif(Type, Input)|...] 
label_testcomp(Verifier_inputs, Labeled_inputs) :- 
    %mytrace,
    partition(Verifier_inputs, Integers, Floats, Grounded_floats, Labeled_inputs),
    (ptc_solver__label_integers(Integers) ->
        (ptc_solver__label_reals(Floats, Grounded_floats) ->    %integers and floats labeling kept separate for now
            true
        ;
            (common_util__error(0, "Floating point numbers labeling failed", "Perhaps worth investigating", [], '0_100924', 'se_main', 'label_testcomp', no_localisation, no_extra_info),
             fail
            )
        )
    ;
        (common_util__error(0, "Integer labeling failed", "Should be rare: e.g. non-linear, out of bounds", [], '0_200824', 'se_main', 'label_testcomp', no_localisation, no_extra_info),
         fail
        )
    ),
    !.
    %%%
    partition([], [], [], [], []).
    partition([verif(Type, Input)|R], Integers_out, Floats_out, Grounded_floats, [Labeled_input|R_Labeled]) :-
        ((Type == float ; Type == double ; Type == long_double) ->
            (Floats_out = [Input|R_Floats],
             Grounded_floats = [Ground_float|R_Grounded_floats],    %a list of vars grounded to floating point numbers during labeling
             Labeled_input = Ground_float,
             partition(R, Integers_out, R_Floats, R_Grounded_floats, R_Labeled)
            )
        ;
            (Integers_out = [verif(Type, Input)|R_Integers],
             Labeled_input = Input,
             partition(R, R_Integers, Floats_out, Grounded_floats, R_Labeled)
            )
        ).
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
print_test_run_log__preamble(ArgsL) :-
    ArgsL = [Install_dir, Parsed_dir, Target_source_file_name_no_ext, Target_raw_subprogram_name, Debug_mode, Output_mode, Data_model, Restart, Nb_of_paths_to_try],
    get_flag('unix_time', Time), 
    local_time_string(Time, "%Y_%m_%d_%H_%M_%S", Timestamp),
    concat_string([Install_dir, "SikrakenDevSpace/experiments/test_run_logs/test_run_", Target_source_file_name_no_ext, "_", Timestamp, ".txt"], Test_run_filename),
    setval('test_run_filename', Test_run_filename), 
    open(Test_run_filename, 'write', 'test_run_stream'),
    printf('test_run_stream', "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf('test_run_stream', "Sikraken Test Inputs Generation Run Log\n", []),
    printf('test_run_stream', "Raw Arguments:\t%w\n", [ArgsL]),
    printf('test_run_stream', "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf('test_run_stream', "Relevant ECLiPSe Configurations:\n", []),
    get_flag('debug_compile', Debug_compile),
    get_flag('debugging', Debugging),
    get_flag('max_local_control', Max_local_control), 
    Max_local_control_in_MB is fix((Max_local_control / 1024) / 1024),
    get_flag('version', Version), 
    printf('test_run_stream', "\tECLiPSe version:\t%w\n", [Version]),
    printf('test_run_stream', "\tdebug_compile:\t\t%w\n", [Debug_compile]),
    printf('test_run_stream', "\tdebugging:\t\t\t%w\n", [Debugging]),
    printf('test_run_stream', "\tCalculated maximum allowed local/control user stack:\t%wMB\n", [Max_local_control_in_MB]),
    printf('test_run_stream', "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf('test_run_stream', "Sikraken Session Configurations at: %w\n", [Timestamp]),
    printf('test_run_stream', "\tRun mode:\t%w\n", [Debug_mode]),
    printf('test_run_stream', "\tTests inputs target format:\t%w\n", [Output_mode]),
    printf('test_run_stream', "\tTarget data model:\t%w\n", [Data_model]),
    printf('test_run_stream', "\tTarget function:\t%w\n", [Target_raw_subprogram_name]),   
    printf('test_run_stream', "\tTarget C file:\t%w (in folder:%w)\n", [Target_source_file_name_no_ext, Parsed_dir]),
    printf('test_run_stream', "\tNb of restarts:\t\t%w\n", [Restart]),
    printf('test_run_stream', "\tNb of path to try:\t%w\n", [Nb_of_paths_to_try]),
    close('test_run_stream').
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_run_log__terminate :-
    getval('test_run_filename', Test_run_filename),
    open(Test_run_filename, 'append', Test_run_stream),
    printf(Test_run_stream, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(Test_run_stream, "Sikraken Session Results:\n", []),
    statistics('cputime', Cputime),
    Cputime_seconds is fix(Cputime),
    se_globals__get_val('path_nb', Test_nb),
    printf(Test_run_stream, "\tECLiPSe CPU time: \t%w seconds\n", [Cputime_seconds]),
    printf(Test_run_stream, "\tGenerated: \t\t\t%w tests\n", [Test_nb]),
    printf(Test_run_stream, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(Test_run_stream, "ECLiPSe Statistics Dump:\n", []), 
    get_stream('log_output', Log_output_stream),
    set_stream('log_output', Test_run_stream),
    statistics,     %printing out ECLiPSe internal statistics into redirected stream
    set_stream('log_output', Log_output_stream),
    printf(Test_run_stream, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%", []),
    close(Test_run_stream).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
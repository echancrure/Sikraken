%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                 Copyright 2024 SETU - Dr Christophe Meudec 
%%                                     <https://github.com/echancrure/Sikraken>
%% This file is part of Sikraken.
%% Sikraken is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
%%   the Free Software Foundation.
%% Sikraken is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
%%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
%% GNU Lesser General Public License v3.0 only
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% defines module se_main
% symbolic execution of parsed C code
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- set_flag('debug_compile', 'on').   %does not really help 
:- get_flag(version, '7.1').            %check for valid ECLiPSe version: issue warning only if not 
%:- set_flag(after_event_timer, virtual). %causes out of range error when set to virtual (what you want) but ok for real: checked in tkeclipse and from CLI

mytrace.            %call this to start debugging
:- spy mytrace/0.
%%%
:- (is_predicate(prolog_c/2) -> abolish prolog_c/2 ; dynamic prolog_c/2).   %to ensure clean environment when using 'make' during development 

:- use_module(library('ic')).
:- use_module(library('lists')).
:- use_module(library('timeout')).
:- lib('ordset').   %for ordered list with no duplicates

:- use_module("./../PTC-Solver/source/ptc_solver").

:- use_module(['se_globals', 'se_name_atts', 'se_seav_atts', 'se_sub_atts', 'se_typedef_atts']).

:- compile(['common_util', 'se_handle_declarations', 'se_symbolically_execute', 'se_symbolically_interpret', 'se_get_symbolic_lvalue_for_addressing']).
:- compile([se_print, 'se_write_tests_testcomp']).
:- compile(['cfg_main']).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  
se_main(ArgsL) :-
    %set_flag('gc_policy', 'fixed'),
    (ArgsL = [Install_dir, Source_dir, Target_source_file_name_no_ext, Target_raw_subprogram_name, Debug_mode, Output_mode, Data_model, Search_algo|Options] ->
        true
    ;
        common_util__error(10, "Calling se_main/? with invalid argument list", "Review calling syntax of se_main/?", [], '10_240824_1', 'se_main', 'se_main', no_localisation, no_extra_info)
    ),
    se_globals__set_globals(Install_dir, Target_source_file_name_no_ext, Debug_mode, Output_mode, Data_model, Options),    
    (Search_algo = regression(Restarts, Tries) ->   %for more stable results during regression testing and to evaluate changes
        (setval('algo', 'regression'),
         setval('nb_restarts', Restarts),
         setval('nb_tries', Tries),
         (Debug_mode = 'debug' ->
            Budget = 1e99        %to work without timeouts at tkeclipse level during developement for example 
         ;   
            Budget = 65          %we put a limit for some regression tests which may not complete a full restart
         ),
         First_time_out is Budget - 5.0  %ensure not triggered at the same time as overall timeout
        )
    ; 
     (Search_algo =.. [budget|Args]) ->
        (setval('algo', 'time_budget'),
         setval('nb_restarts', 1e99),   %infinite restarts and tries allowed
         setval('nb_tries', 1e99),
         (Args = [Budget] ->
            (First_time_out = 0.2, %can be much too sort for program involving loops which take longer than this: not a problem itself as the budget will increase (but only slowly if the Increase_duration_multiplier is small)
             Max_time_out = 100,
             Multiplier = 1.05,
             Min_time_out = 0.5,
             Margin = 10
            )
         ;
          Args = [Budget, First_time_out, Max_time_out, Multiplier, Min_time_out, Margin] ->
            true    %todo
         ;
            common_util__error(10, "Calling se_main/? with invalid budget configuration", "Review budget algo argument syntax", [('Search_algo', Search_algo)], '10_240926_1', 'se_main', 'se_main', no_localisation, no_extra_info)
         ),
         se_globals__set_val('First_time_out', First_time_out),
         se_globals__set_val('Max_time_out', Max_time_out),
         se_globals__set_val('Multiplier', Multiplier),
         se_globals__set_val('Min_time_out', Min_time_out),
         se_globals__set_val('Margin', Margin)        
        )
    ;
        common_util__error(10, "Calling se_main/? with invalid search algo configuration", "Review search algo argument syntax", [('Search_algo', Search_algo)], '10_240926_2', 'se_main', 'se_main', no_localisation, no_extra_info)
    ),         
    se_globals__set_val('single_test_time_out', First_time_out),    
    set_event_handler('overall_generation_time_out', handle_overall_time_out_event/0),
    event_after('overall_generation_time_out', Budget),
    print_test_run_log__preamble(ArgsL),
    initialise_ptc_solver,
    capitalize_first_letter(Target_raw_subprogram_name, Target_subprogram_name),
    read_parsed_file(Install_dir, Target_source_file_name_no_ext, Target_subprogram_name, prolog_c(Parsed_prolog_code), Main, Target_subprogram_var),      %may fail if badly formed due to parsing errors
    %%%pre-symbolic execution
    cfg_main__declare_functions(Parsed_prolog_code),
    setval('execution_mode', 'global'),   %i.e. C compile time (as opposed to runtime), tackling globals when implicit initialisation to 0 occurs 
    (symbolic_execute(Parsed_prolog_code, _) ->   %always symbolically execute all global declarations for now: initialisations could be ignored via a switch if desired
        true
    ;
        common_util__error(10, "Sikraken failed to execute the global declarations: cannot recover from this", "Should never happen: code needs to be traced", [], '10_021224_3', 'se_main', 'search_CFG_inner', no_localisation, no_extra_info)
    ),
    %mytrace,
    cfg_main__build_cfg(Parsed_prolog_code),
    setval('execution_mode', 'local'),    %i.e. C run time (as opposed to compile time), tackling locals when implicit initialisation to 0 does not occur
    %%%
    statistics(event_time, Session_time),
    setval('start_session_time', Session_time),
    print_preamble_testcomp(Install_dir, Source_dir, Target_source_file_name_no_ext),
    (se_globals__get_val('EdgeCount', 0) -> 
        print_test_inputs_testcomp([])      %silly edge case: no branches at all; we still print an empty test input vector to keep Testcov happy
    ;
        %%% where it all happens
        catch(search_CFG(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code), Any_exception, search_CFG_exception_handler(Any_exception))
    ),
    print_test_run_log.   %only run once 
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    handle_overall_time_out_event :-
        cancel_after_event('single_test_time_out_event', _), %to ensure none are left and triggered later on especially in development mode
        throw('outatime').
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    search_CFG_exception_handler(Exception) :-
        (Exception == 'outatime' ->
            easter_egg
        ;
            (Exception == 'global_trail_overflow' ->
                (get_flag('max_global_trail', Max),
                 MB is (Max div 1024) div 1024,
                 common_util__error(10, "!!!Global/Trail stack overflow during search caught", "Review symbolic execution and/or increase initial ECLiPSe stack using -g", [('Curent Max global/trail stack in MB is', MB)], '10_260924_1', 'se_main', 'se_main', no_localisation, no_extra_info)
                )
            ;
             Exception == 'local_control_overflow ' ->
                (get_flag('max_local_control', Max),
                 MB is (Max div 1024) div 1024,
                 common_util__error(10, "!!!Local/Control stack overflow during search caught", "Review symbolic execution and/or increase initial ECLiPSe stack using -l", [('Curent Max local/control stack in MB is', MB)], '10_051024_1', 'se_main', 'se_main', no_localisation, no_extra_info)
                )
            ;
             Exception == 'abort' ->
                (print_test_run_log,
                 throw('abort')
                )
            ; 
                common_util__error(10, "Unknown exception caught", "Review, investigate and catch it better next time", [('Exception', Exception)], '10_260924_2', 'se_main', 'se_main', no_localisation, no_extra_info)
            )
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
search_CFG(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code) :-
    set_event_handler('single_test_time_out_event', handle_single_test_time_out_event/0),
    getval('nb_restarts', Restarts),
    (for(Restart_counter, 1, Restarts), loop_name('restart'), param(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)
        do (
            printf('output', "\nDev Info: Restart number %w\n", [Restart_counter]),
            search_CFG_inner(Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)
        )
    ).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    search_CFG_inner(_Debug_mode, Output_mode, Main, Target_subprogram_var, Parsed_prolog_code) :-
        se_globals__get_val('single_test_time_out', Current_single_test_time_out),
        printf('output', "Dev Info: Time budget for a single test is %.2f seconds\n", [Current_single_test_time_out]),
        se_globals__get_val('path_nb', Initial_try_solution_number),
        setval(nb_try_solution, Initial_try_solution_number),
        setval(shortcut_gen_triggered, 'false'),
        not(
            (catch(try_nb_path_budget(param(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)), 'single_test_time_out_exception', handle_single_test_time_out_exception) -> 
                (%should logically never happen
                 common_util__error(10, "try_nb_path_budget SUCCESS: something is seriously wrong", "Big bug", [], '10_240924_1', 'se_main', 'search_CFG_inner', no_localisation, no_extra_info), 
                 fail
                )
            ;
                (cancel_after_event('single_test_time_out_event', _CancelledEvents),    %to ensure none are left and be triggered later on
                 fail   %to make sure the not succeeds...
                )
            )
        ),
        se_globals__get_val('path_nb', Post_try_solution_number),
        getval(nb_try_solution, Pre_try_solution_number),
        Number_of_new_solutions is Post_try_solution_number - Pre_try_solution_number,
        (Number_of_new_solutions == 0 ->    %we tried a path for Current_single_test_time_out amount of time and no tests were generated
            (getval('algo', 'time_budget') ->
                (se_globals__get_val('Max_time_out', Max_time_out),
                 se_globals__get_val('Multiplier', Increase_duration_multiplier),
                 %we should retrieve se_globals__get_val('single_test_time_out', Current_single_test_time_out), because it may have changed within try_nb_path_budget
                 New_single_test_time_out is min(Current_single_test_time_out*Increase_duration_multiplier, Max_time_out), %but there is a maximum 
                 se_globals__set_val('single_test_time_out', New_single_test_time_out),   %todo should depend on global budget remaining
                 statistics(event_time, Current_session_time),
                 printf('output', "Dev Info: Restart single test budget changed to: %.2f seconds; overall elapsed time is %.2f seconds\n", [New_single_test_time_out, Current_session_time])
                )
            ;
                true
            )
        ;
            (%the last inner try did generate solutions
             setval(nb_try_solution, Post_try_solution_number)
            )
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%tries to generate at most nb_tries of test input vectors using backtracking
%always fails by design
try_nb_path_budget(param(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code)):-
    getval('nb_tries', Nb_tries),
    setval(try_counter, 0),
    se_globals__get_val('path_nb', Initial_test_number),
    setval(nbSolution, Initial_test_number),
    se_globals__get_val('single_test_time_out', Single_test_time_out),
    event_after('single_test_time_out_event', Single_test_time_out),
    statistics(event_time, Start_time),
    setval(start_time, Start_time),
    %%%where it all happens
    catch(find_one_path(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code), Any_exception, find_one_path_exception_handler(Any_exception)),
    %%%
    getval(try_counter, I),
    I1 is I + 1,
    setval(try_counter, I1),
    (I1 == Nb_tries ->
        true    %target number of test inputs generated 
    ;
        fail    %will generate more solutions by backtracking through find_one_path (and eventually symbolic_execution)
    ),
    !,  
    fail.       %I know this is ugly: but this will only be reached during regression testing when the number of tries has been reached
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    handle_single_test_time_out_event :-
        %mytrace,
        printf('output', "Dev Info: Time out triggered.\n", []),
        (cfg_main__bran_newly_covered(_Overall_covered, []) ->
            printf('output', "Dev Info: Nothing new in the current subpath.\n", [])    
        ;
            (se_globals__get_ref('verifier_inputs', Verifier_inputs),
             se_globals__get_val('single_test_time_out', Current_single_test_time_out),
             (timeout(label_testcomp(Verifier_inputs, Labeled_inputs), Current_single_test_time_out, fail) ->    %timout added to avoid very long / impossible labelling
                display_successful_test_stats(_Last_test_duration, _Current_session_time),
                printf('output', "Dev Info: Incomplete test vector\n", []),
                record_path_coverage,
                print_test_inputs_testcomp(Labeled_inputs)     %banking a partial answer as allowed by testcomp                
             ;
                printf('output', "Dev Info: Labelling failed.\n", [])    %labeling failed...no test input vector could be generated
             )
            )
        ),
        throw('single_test_time_out_exception').
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    handle_single_test_time_out_exception :-
        fail. %to make sure the not in search_CFG_inner succeeds and a restart from the top is triggerred 
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    find_one_path_exception_handler(Exception) :-
        (Exception == 'abort' ->    %covers ECLiPSe exceptions: language/constraints violations and explicit calls to abort in Sikraken error messages
            ((get_stream(error, X), get_stream(null, X)) -> %error stream has already been set to null
                true
            ;   
                (common_util__error(9, "Caught ECLiPSe abort", "", [], '9_281024_1', 'se_main', 'se_main', no_localisation, no_extra_info)
                 %,set_stream(error, null)   %can be set to avoid thousands additional identical error messages from ECLiPSe
                 %as this handler succeeds, the catch for find_one_path will succeed and count as a try, and hopefully backtrack out of the error and find another subpath, if not it will eventually reach the max number of tries or timeout
                )
            )
        ;
            throw(Exception)    %rethrow...
        ).    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
find_one_path(Output_mode, Main, Target_subprogram_var, Parsed_prolog_code) :-
    (Output_mode == 'testcomp' ->   %in the spirit of C we do not check Main: we accept any version (including argc/argv) 
        (se_sub_atts__get(Main, 'body', Main_compound_statement),   
         se_globals__update_ref('current_path_bran', start('Main', true)),
         symbolic_execute(Main_compound_statement, _Flow)
        )
    ;
        (%ignore this alternative for now: not testcomp
         %always symbolically execute void main(void) for now: should be a switch allowing the main to be ignored via a switch if desired
         se_sub_atts__get(Main, 'parameters', [unnamed_param([void], [])]),  
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
    %always succeeds (even when labeling fails)
    end_of_path_predicate(SEAV_Inputs, Parsed_prolog_code) :-
        (getval(shortcut_gen_triggered, 'true') ->  %we are in shortcut generation mode, so we do not create new verifier inputs
            (setval(shortcut_gen_triggered, 'false'),  %reset for next time
             reset_timer,
             record_path_coverage
            )
        ;
            (cfg_main__bran_newly_covered(_Overall_covered, Newly_covered),
             (Newly_covered == [] -> %no need to label: saves labelling run and test execution time
                true %common_util__error(1, "End of path: no new branches", 'no_error_consequences', [], '0_210824_1', 'se_main', 'end_of_path_predicate', no_localisation, no_extra_info)
            ;
                (se_globals__get_val('output_mode', Output_mode),
                 (Output_mode = 'testcomp' ->
                    (se_globals__get_ref('verifier_inputs', Verifier_inputs),
                     %mytrace,
                     (label_testcomp(Verifier_inputs, Labeled_inputs) ->
                        (reset_timer,
                         record_path_coverage,
                        %%%
                        %common_util__error(1, "End of path", 'no_error_consequences', [('Path Nb', Inc_test_nb), ('Newly_covered', Newly_covered), ('Current_path', Current_path)], '0_190824_1', 'se_main', 'end_of_path_predicate', no_localisation, no_extra_info),
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
             )
            )
        ).
        %%%
        reset_timer :-
            cancel_after_event('single_test_time_out_event', _CancelledEvents), 
            display_successful_test_stats(Last_test_duration, Current_session_time),
            %mytrace,
            (getval('algo', 'time_budget') ->
                (se_globals__get_val('Min_time_out', Min_time_out), %seconds whatever is close but above the overheads
                 se_globals__get_val('Margin', Margin),
                 se_globals__get_val('single_test_time_out', Current_single_test_time_out),
                 (Current_single_test_time_out > Min_time_out, Current_single_test_time_out > Margin * Last_test_duration ->  %last test generation was faster by a wide margin: allocated budget is reduced
                    (New_single_test_time_out is max(Margin * Last_test_duration, Min_time_out), %but there is a minimum to reduce overheads
                     se_globals__set_val('single_test_time_out', New_single_test_time_out),
                     printf('output', "Dev Info: Single test budget changed to: %.2f seconds; overall elapsed time is %.2f seconds\n", [New_single_test_time_out, Current_session_time])
                    )
                 ;
                    New_single_test_time_out = Current_single_test_time_out
                 ),    
                 event_after('single_test_time_out_event', New_single_test_time_out)
                )
            ;
                true
            ),
            statistics(event_time, New_start_time),
            setval(start_time, New_start_time).
        %%%
        display_successful_test_stats(Last_test_duration, Current_session_time) :-
            statistics(event_time, Current_session_time),
            getval(start_time, Current_start_time),
            Last_test_duration is Current_session_time - Current_start_time,
            printf('output', "\nDev Info: Test generated in %.2f seconds; overall elapsed time is %.2f seconds\n", [Last_test_duration, Current_session_time]).
        %%%
        record_path_coverage :-
            %mytrace,
            se_globals__get_val('path_nb', Test_nb),
            Inc_test_nb is Test_nb + 1,
            %(Inc_test_nb == 9 -> mytrace ; true),
            se_globals__set_val('path_nb', Inc_test_nb),
            cfg_main__bran_newly_covered(Overall_covered, Newly_covered),
            (se_globals__get_val('debug_mode', 'debug') -> print_branches_list(Newly_covered) ; true),
            length(Newly_covered, Nb_new),
            se_globals__set_val('covered_bran', Overall_covered),
            se_globals__get_val('EdgeCount', EdgeCount),
            (EdgeCount == 0 -> Coverage_delta = 100.0 ; Coverage_delta is (Nb_new / EdgeCount) * 100),
            printf('output', "Dev Info: Covered  %d new branches increasing coverage by %.2f%%\n", [Nb_new, Coverage_delta]),
            flush('output').
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
initialise_ptc_solver :-
    ptc_solver__clean_up,
    se_globals__get_val('data_model', Data_model),
    ptc_solver__default_declarations(Data_model, 'ignore').
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%returns CProlog the C code in Prolog format, Main the var of the main function, and Target_subprogram_var the var of the target function 
read_parsed_file(Install_dir, Target_source_file_name_no_ext, Target_raw_subprogram_name, CProlog, Main, Target_subprogram_var) :-
    concat_atom([Install_dir, '/sikraken_output/', Target_source_file_name_no_ext, '/', Target_source_file_name_no_ext, '.pl'], Parsed_filename),
    (exists(Parsed_filename) ->
        (open(Parsed_filename, read, Stream),
         read_term(Stream, CProlog, [variable_names(VarsNames)]) -> %Varnames is list of Atom = Var (e.g. 'X' = X)
            (close(Stream),
             se_name_atts__initL(VarsNames),     %initialise all C vars with their Names
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
%alternative labelling strategy: label all delayed vars not just the inputs
%not used for now
label_all :-
    delayed_goals(GoalList),
    term_variables(GoalList, All_delayed_vars),
    partition_delayed_vars(All_delayed_vars, Integers, Reals),
    (ptc_solver__label_integers(Integers) ->
        (ptc_solver__label_reals(Reals) ->    %integers and floats labeling kept separate for now
            true
        ;
            (common_util__error(1, "Floating point numbers labeling failed", "Perhaps worth investigating", [], '0_100924', 'se_main', 'label_all', no_localisation, no_extra_info),
             fail
            )
        )
    ),
    !.
    %%%
    partition_delayed_vars([], [], []).
    partition_delayed_vars([Var|Rest], Integers, Reals) :-
        (get_solver_type(Var, integer) ->
            (Integers = [Var|R_Integers],
             partition_delayed_vars(Rest, R_Integers, Reals)
            )
        ;
            (Reals = [Var|R_Reals],
             partition_delayed_vars(Rest, Integers, R_Reals)
            )
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Verifier_inputs is of the form [verif(Type, Input)|...] 
label_testcomp(Verifier_inputs, Labeled_inputs) :- 
    %mytrace,
    partition(Verifier_inputs, Integers, Floats, Grounded_floats, Labeled_inputs),
    (ptc_solver__label_integers(Integers) ->
        (ptc_solver__label_reals(Floats, Grounded_floats) ->    %integers and floats labeling kept separate for now
            true
        ;
            (common_util__error(1, "Floating point numbers labeling failed", "Perhaps worth investigating", [], '0_100924', 'se_main', 'label_testcomp', no_localisation, no_extra_info),
             fail
            )
        )
    ;
        (common_util__error(1, "Integer labeling failed", "Should be rare: e.g. non-linear, out of bounds", [], '0_200824', 'se_main', 'label_testcomp', no_localisation, no_extra_info),
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
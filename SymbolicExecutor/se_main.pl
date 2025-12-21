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
:- use_module(library('lists')).
mytrace.            %call this to start debugging
:- (argv(all, Args),    %to be set after -- on the comand line for ECLiPse e.g. -- -m32 -release
    (member("-m32", Args) -> 
        setval(data_model, 32)  
    ; 
        setval(data_model, 64)
    ),
    (member("-debug", Args) -> 
        setval(debug_mode, debug),
        spy mytrace/0
    ; 
        set_flag(debug_compile, off),   %ECLiPSe compiler will not generate debuggable code
        setval(debug_mode, release)
    )
).
:- inline(super_util__quick_dev_info/2, tr_dev_info2/2).
:- inline(super_util__quick_dev_info/3, tr_dev_info3/2).
tr_dev_info3(super_util__quick_dev_info(Goal, Msg, Args), Expanded) :-
    (getval(debug_mode, debug) -> 
        Expanded = (Goal, printf(output, "Dev Info: ", []), printf(output, Msg, Args), flush(output))
    ; 
        Expanded = true
    ).
tr_dev_info2(super_util__quick_dev_info(Msg, Args), Expanded) :-
    (getval(debug_mode, debug) -> 
        Expanded = (printf(output, "Dev Info: ", []), printf(output, Msg, Args), flush(output))
    ; 
        Expanded = true
    ).
% Fallback definition for when inlining doesn't occur
super_util__quick_dev_info(Msg, Args) :-
    (getval(debug_mode, debug) -> 
        printf(output, "Dev Info: ", []), 
        printf(output, Msg, Args), 
        flush(output)
    ; 
        true
    ).

super_util__quick_dev_info(Goal, Msg, Args) :-
    Goal,
    super_util__quick_dev_info(Msg, Args).
:- get_flag(version, '7.1').            %check for valid ECLiPSe version: issue warning only if not 
%:- set_flag(after_event_timer, virtual). %causes out of range error when set to virtual (what you want) but ok for real: checked in tkeclipse and from CLI

%%%
:- (is_predicate(prolog_c/2) -> abolish prolog_c/2 ; dynamic prolog_c/2).   %to ensure clean environment when using 'make' during development 

:- use_module(library('ic')).
:- use_module(library('timeout')).
:- lib('ordset').   %for ordered list with no duplicates

:- use_module("./../PTC-Solver/source/ptc_solver").

:- use_module(['se_globals', 'se_name_atts', 'se_seav_atts', 'se_sub_atts', 'se_typedef_atts']).

:- compile(['common_util', 'se_handle_declarations', 'se_symbolically_execute', 'se_symbolically_interpret', 'se_get_symbolic_lvalue_for_addressing']).
:- compile([se_print, 'se_write_tests_testcomp']).
:- compile(['cfg_main']).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:- set_interrupt_handler(24, dump_stats_and_exit/0).    %SIGXCPU from external bash use of prlimit
:- setval(xcpu_handled, false).

dump_stats_and_exit :-
    set_interrupt_handler(24, default/0),   %to prevent others to be triggered
    (getval(xcpu_handled, false) ->         %to ensure printing only once
        setval(xcpu_handled, true),    
        print_test_run_log,
        getval(main_engine, Main_engine),    
        engine_post(Main_engine, prints_stats)  %so we get the statistics of the main engine, not the one handling interrupts...
    ;
        true
    ).
  
se_main(ArgsL) :-
    set_event_handler(prints_stats, prints_stats/0),
    printf(output, "Inter-cov:0.00%%\n", []), flush(output),
    statistics(event_time, Session_time),
    setval(start_session_time, Session_time),
    engine_self(Engine),
    setval(main_engine, Engine),
    set_flag(gc_policy, fixed),                 %for better predictability
    get_flag('max_global_trail', Max_global_trail),
    GC_interval is Max_global_trail div 16,     %larger than default 1/32th to reduce gc time
    set_flag(gc_interval, GC_interval),
    (ArgsL = [Install_dir, Source_dir, Target_source_file_name_no_ext, Target_raw_subprogram_name, Output_mode, Search_algo|Options] ->
        true
    ;
        common_util__error(10, "Calling se_main/? with invalid argument list", "Review calling syntax of se_main/?", [], '10_240824_1', 'se_main', 'se_main', no_localisation, no_extra_info)
    ),
    se_globals__set_globals(Install_dir, Target_source_file_name_no_ext, Output_mode, Options),    
    (Search_algo = regression(Restarts, Tries) ->   %for more stable results during regression testing and to evaluate changes
        (setval('algo', 'regression'),
         setval(nb_restarts, Restarts),
         setval('nb_tries', Tries),
         (getval(debug_mode, debug) ->
            Budget = 1e99        %to work without timeouts at tkeclipse level during developement for example 
         ;   
            Budget = 65          %we put a limit for some regression tests which may not complete a full restart
         ),
         First_time_out is Budget - 5.0  %ensure not triggered at the same time as overall timeout
        )
    ; 
     (Search_algo =.. [budget|Args]) ->
        (setval('algo', 'time_budget'),
         setval(nb_restarts, 1e99),   %infinite restarts and tries allowed
         setval('nb_tries', 1e99),
         (Args = [_Budget] ->
            (First_time_out = 0.2, %can be much too sort for program involving loops which take longer than this: not a problem itself as the budget will increase (but only slowly if the Increase_duration_multiplier is small)
             Max_time_out = 100,
             Multiplier = 1.05,
             Min_time_out = 0.5,
             Margin = 10
            )
         ;
          Args = [_Budget, First_time_out, Max_time_out, Multiplier, Min_time_out, Margin] ->   %low level customisation
            true    
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
    catch(
        (
            print_test_run_log__preamble(ArgsL),
            print_preamble_testcomp(Install_dir, Source_dir, Target_source_file_name_no_ext),
            initialise_ptc_solver,
            capitalize_first_letter(Target_raw_subprogram_name, Target_subprogram_name),
            read_parsed_file(Install_dir, Target_source_file_name_no_ext, Target_subprogram_name, prolog_c(Parsed_prolog_code), Main, _Target_subprogram_var),      %may fail if badly formed due to parsing errors
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
            (se_globals__get_val('EdgeCount', 0) -> 
                print_test_inputs_testcomp([], 0)      %silly edge case: no branches at all; we still print a single empty test input vector to keep Testcov happy
            ;
                search_CFG(Main)%%% where it all happens
            ),
            print_test_run_log   %only run once
        ),
        Exception,
        handle_outer_exception(Exception)
    ).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    handle_outer_exception(Exception) :-
        cancel_after_event(single_test_time_out_event, _),
        (Exception == prints_stats ->
            prints_stats,
            halt
        ;    
         Exception == abort ->  %ECLiPSe abort
            print_test_run_log,
            exit(10)   %ends execution with error code
        ; 
         Exception == my_abort ->   %Sikraken abort print_test_run_log has already been printed
            exit(11)   %ends execution with error code
        ;    
            common_util__error(10, "Unknown exception caught", "Review, investigate and catch it better next time", [('Exception', Exception)], '10_260924_2', 'se_main', 'se_main', no_localisation, no_extra_info)
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
search_CFG(Main) :-
    set_event_handler(single_test_time_out_event, handle_single_test_time_out_event/0),
    getval(nb_restarts, Restarts),
    (for(Restart_counter, 1, Restarts), loop_name('restart'), param(Main)
        do (
            super_util__quick_dev_info("\nRestart number %w\n", [Restart_counter]),
            search_CFG_inner(Main)
        )
    ).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    search_CFG_inner(Main) :-
        se_globals__get_val(single_test_time_out, Current_single_test_time_out),
        super_util__quick_dev_info("Time budget for a single test is %.2f seconds\n", [Current_single_test_time_out]),
        se_globals__get_val(path_nb, Initial_try_solution_number),
        setval(nb_try_solution, Initial_try_solution_number),
        setval(shortcut_gen_triggered, false),
        setval(time_out_triggered, false),
        not(
            (catch(try_nb_path_budget(Main), 
                   Any_exception, 
                   handle_try_nb_path_budget_exception(Any_exception)
                  ) -> 
                (%should logically never happen
                 common_util__error(10, "try_nb_path_budget SUCCESS: something is seriously wrong", "Big bug", [], '10_240924_1', 'se_main', 'search_CFG_inner', no_localisation, no_extra_info), 
                 fail
                )
            ;
                (cancel_after_event(single_test_time_out_event, _CancelledEvents),    %to ensure none are left and be triggered later on
                 fail   %to make sure the not succeeds...
                )
            )
        ),
        %a restart from the top is triggered
        se_globals__get_val(path_nb, Post_try_solution_number),
        getval(nb_try_solution, Pre_try_solution_number),
        Number_of_new_solutions is Post_try_solution_number - Pre_try_solution_number,
        (Number_of_new_solutions == 0 ->    %we tried a path for Current_single_test_time_out amount of time and no tests were generated
            (getval('algo', 'time_budget') ->
                (se_globals__get_val('Max_time_out', Max_time_out),
                 se_globals__get_val('Multiplier', Increase_duration_multiplier),
                 %we should retrieve se_globals__get_val('single_test_time_out', Current_single_test_time_out), because it may have changed within try_nb_path_budget
                 New_single_test_time_out is min(Current_single_test_time_out*Increase_duration_multiplier, Max_time_out), %but there is a maximum 
                 se_globals__set_val('single_test_time_out', New_single_test_time_out),   %todo should depend on global budget remaining
                 super_util__quick_dev_info(statistics(event_time, Current_session_time), "Restart single test budget changed to: %.2f seconds; overall elapsed time is %.2f seconds\n", [New_single_test_time_out, Current_session_time])
                )
            ;
                true
            )
        ;
            (%the last inner try did generate solutions
             setval(nb_try_solution, Post_try_solution_number)
            )
        ).
        %%%
        %used to bring control back to the catch within search_CFG_inner/? predicate above
        handle_try_nb_path_budget_exception(Exception) :-
            (Exception == single_test_time_out_exception ->
                fail                    %single path exploration fails : triggers a restart
            ;
             Exception == global_trail_overflow ->
                (get_flag(max_global_trail, Max),
                 MB is Max div 1000000,
                 common_util__error(9, "Global/Trail stack overflow during search caught", "Review symbolic execution and/or increase initial ECLiPSe stack using -g", [('Curent Max global/trail stack in MB is', MB)], '9_260924_1', 'se_main', 'se_main', no_localisation, no_extra_info),
                 fail %will trigger restart: current search is abandoned because it is too deep, stack will be reclaimed, a fresh path is started 
                )
            ;
             Exception == local_control_overflow ->
                (get_flag(max_local_control, Max),
                 MB is Max div 1000000,
                 common_util__error(9, "!!!Local/Control stack overflow during search caught", "Review symbolic execution and/or increase initial ECLiPSe stack using -l", [('Curent Max local/control stack in MB is', MB)], '9_051024_1', 'se_main', 'se_main', no_localisation, no_extra_info),
                 fail %will trigger restart: current search is abandoned because it is too deep, stack will be reclaimed, a fresh path is started 
                )
            ; 
             Exception == abort ->          %catches ECLiPSe exceptions: language/constraints violations
                common_util__error(9, "Caught ECLiPSe abort", "Will retry with a different path", [], '9_281024_1', 'se_main', 'se_main', no_localisation, no_extra_info),
                fail
            ;
             Exception == my_abort ->       %explicit calls to abort in Sikraken error messages
                throw(my_abort)             %rethrow: will be handled in handle_outer_exception/1 above
            ;
                common_util__error(9, "Caught unknown exception", "Will retry with a different path", [('Exception', Exception)], '9_151125_1', 'se_main', 'se_main', no_localisation, no_extra_info),
                fail    %anything else: the current "try" fails and a restart from the top is triggerred 
            ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%tries to generate at most nb_tries of test input vectors using backtracking
%always fails by design
try_nb_path_budget(Main):-
    getval('nb_tries', Nb_tries),
    setval(try_counter, 0),
    se_globals__get_val('path_nb', Initial_test_number),
    setval(nbSolution, Initial_test_number),
    se_globals__get_val('single_test_time_out', Single_test_time_out),
    event_after(single_test_time_out_event, Single_test_time_out),
    statistics(event_time, Start_time),
    setval(start_time, Start_time),
    %%%where it all happens
    find_one_path(Main), 
    (getval(algo, time_budget) ->
        fail        %will generate more solutions by backtracking
    ;
        getval(try_counter, I), %all this should only be done in regression mode
        I1 is I + 1,
        setval(try_counter, I1),
        (I1 == Nb_tries ->
            true    %target number of test inputs generated 
        ;
            fail    %will generate more solutions by backtracking through find_one_path (and eventually symbolic_execution)
        )
    ),
    !,  
    fail.       %I know this is ugly: but this will only be reached during regression testing when the number of tries has been reached
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %this may be triggered at any time asynchronously during a "try" search
    handle_single_test_time_out_event :-       %single path exploration time is up
        %mytrace,
        super_util__quick_dev_info("\nTime out triggered.\n", []),
        cfg_main__bran_newly_covered(_Overall_covered, Newly_covered),
        (Newly_covered == [] ->
            super_util__quick_dev_info("time out handler: Nothing new in the current subpath.\n", []),
            throw(single_test_time_out_exception)       %will trigger a restart
        ;
            (label_testcomp(_Labeled_inputs) ->
                ((getval(debug_mode, debug) -> 
                    super_util__quick_dev_info("time out handler: This is an incomplete test vector\n", []),
                    %display_successful_test_stats(Last_test_duration, Current_session_time),
                    se_globals__get_ref(current_path_bran, Current_path_with_calls),
                    super_util__quick_dev_info("time out handler: current Path: ", []), 
                    print_branches_list(Current_path_with_calls)
                 ;
                    true
                 ),
                 statistics(event_time, Current_session_time),
                 getval(start_time, Current_start_time),
                 Last_test_duration is Current_session_time - Current_start_time,
                 reset_timer(Last_test_duration, Current_session_time) %and carry on with true
                 %throw('single_test_time_out_exception')    %debug
                 %the handler succeeds: execution continues where the timeout was triggered: the subpath continues to be explored
                 %this may lead to may testvectors with the same prefix which should be filtered out to reduce the number of tests without reducing the amount of coverage achieved
                )
             ;
                super_util__quick_dev_info("time out handler: Labelling failed after time out.\n", []),  %no test input vector could be generated
                %should fail where the timeout was triggered: we are following a subpath that is 'infeasible' (or at least we cannot generate tests for e.g. because of non-linearity) 
                %perhaps, but for now just fail the entire try
                throw(single_test_time_out_exception)
            )
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
find_one_path(Main) :-
    %in the spirit of C we do not check Main: we accept any version (including argc/argv) 
    se_sub_atts__get(Main, 'body', Main_compound_statement),   
    se_globals__update_ref('current_path_bran', start('Main', true)),
    symbolic_execute(Main_compound_statement, _Flow),
    end_of_path_predicate.
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
    end_of_path_predicate :-
        setval(time_out_triggered, false),
        (getval(shortcut_gen_triggered, 'true') ->  %we are in shortcut generation mode
            (setval(shortcut_gen_triggered, 'false'),   %reset for next time
             statistics(event_time, Current_session_time),
             reset_timer(Current_session_time),
             record_path_coverage(_Test_nb)            %partial path recorded, but the test vector has already been generated
            )
        ;
            (cfg_main__bran_newly_covered(_Overall_covered, Newly_covered),
             (Newly_covered == [] ->
                super_util__quick_dev_info("Nothing new: backtrack, timer is still running.\n", []),
                true %will fail above in try_nb_path_budget/...
            ;
                (cancel_after_event(single_test_time_out_event, _CancelledEvents),  %stop timer: reach the end and something new is in the path
                 (se_globals__get_val(output_mode, testcomp)->
                    (label_testcomp(Labeled_inputs) ->   
                        (display_successful_test_stats(Last_test_duration, Current_session_time),
                         record_path_coverage(Test_nb),
                         %common_util__error(1, "End of path", 'no_error_consequences', [('Path Nb', Inc_test_nb), ('Newly_covered', Newly_covered), ('Current_path', Current_path)], '0_190824_1', 'se_main', 'end_of_path_predicate', no_localisation, no_extra_info),
                         print_test_inputs_testcomp(Labeled_inputs, Test_nb),       %but don't print predicted outputs
                         reset_timer(Last_test_duration, Current_session_time)      %timer restarts, possibly on reduced time
                        )
                    ;
                        statistics(event_time, Current_session_time),
                        getval(start_time, Current_start_time),
                        Last_test_duration is Current_session_time - Current_start_time,
                        se_globals__get_val(single_test_time_out, Current_single_test_time_out),
                        Remaining_time is Current_single_test_time_out - Last_test_duration,
                        (Remaining_time > 0 ->
                            event_after(single_test_time_out_event, Remaining_time) %timer is restarted with remaining time, will backtrack
                        ;
                            throw(single_test_time_out_exception) %time is up and labeling failed: no hope
                        )
                    )
                 ;
                    common_util__error(10, "Unexpected output mode", "Only testcomp format is supported for now", [], '10_100924_1', 'se_main', 'end_of_path_predicate', no_localisation, no_extra_info)
                 )
                )
             )
            )
        ).
        %%%
        reset_timer(Last_test_duration, Current_session_time) :-
            cancel_after_event(single_test_time_out_event, _CancelledEvents), 
            %mytrace,
            (getval('algo', 'time_budget') ->
                (se_globals__get_val('Min_time_out', Min_time_out), %seconds whatever is close but above the overheads
                 se_globals__get_val('Margin', Margin),
                 se_globals__get_val('single_test_time_out', Current_single_test_time_out),
                 (Current_single_test_time_out > Min_time_out, Current_single_test_time_out > Margin * Last_test_duration ->  %last test generation was faster by a wide margin: allocated budget is reduced
                    (New_single_test_time_out is max(Margin * Last_test_duration, Min_time_out), %but there is a minimum to reduce overheads
                     se_globals__set_val('single_test_time_out', New_single_test_time_out),
                     super_util__quick_dev_info("Single test budget changed to: %.2f seconds; overall elapsed time is %.2f seconds\n", [New_single_test_time_out, Current_session_time])
                    )
                 ;
                    New_single_test_time_out = Current_single_test_time_out
                 ),    
                 event_after(single_test_time_out_event, New_single_test_time_out)
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
            super_util__quick_dev_info("Test generated in %.2f seconds; overall elapsed time is %.2f seconds\n", [Last_test_duration, Current_session_time]).
        %%%
        record_path_coverage(Test_nb) :-
            %mytrace,
            se_globals__get_val('path_nb', Latest_test_nb),
            Test_nb is Latest_test_nb + 1,
            se_globals__set_val('path_nb', Test_nb),
            cfg_main__bran_newly_covered(Overall_covered, Newly_covered),
            (getval(debug_mode, debug) -> 
                super_util__quick_dev_info("New branches covered: ", []), 
                print_branches_list(Newly_covered) 
            ; 
                true
            ),
            se_globals__get_val('EdgeCount', EdgeCount),
            super_util__quick_dev_info((length(Newly_covered, Nb_new), (EdgeCount == 0 -> Coverage_delta = 100.0 ; Coverage_delta is (Nb_new / EdgeCount) * 100)), "Test %d covers %d new branches increasing coverage by %.2f%%\n", [Test_nb, Nb_new, Coverage_delta]),
            se_globals__set_val('covered_bran', Overall_covered),
            length(Overall_covered, Covered_nb),
            (EdgeCount == 0 -> 
                Coverage is 100.0     %Some tests generated but EdgeCount is 0: a C file with no branches
            ; 
                Coverage is (Covered_nb / EdgeCount) * 100
            ),
            printf(output, "Inter-cov:%.2f%%\n", [Coverage]),   %intermediate coverage should be in dev mode only
            flush(output).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
initialise_ptc_solver :-
    ptc_solver__clean_up,
    getval(data_model, Data_model),
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
label_testcomp(Labeled_inputs) :- 
    se_globals__get_ref(verifier_inputs, Verifier_inputs),
    se_globals__get_val(single_test_time_out, Current_single_test_time_out),
    length(Verifier_inputs, Nb_inputs),
    Labeling_timeout is Current_single_test_time_out + Nb_inputs * 0.005, % adding 5 thousandths of a second per input: will only make an impact if number of inputs is large e.g. 1000 inputs add 5 seconds
    %timeout added to labeling avoid very long / impossible labelling
    %this is done while the timer is cancelled: very wastful to interrupt labeling while it is running
    timeout(
        (
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
            !
        ),
        Labeling_timeout,
        (super_util__quick_dev_info("Labelling timed out after %.2f seconds.\n", [Labeling_timeout]),
         fail
        )
    ).
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
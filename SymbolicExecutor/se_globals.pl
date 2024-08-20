:- module('se_globals').
:- export se_globals__set_globals/4, se_globals__get_val/2, se_globals__set_val/2, se_globals__get_ref/2, se_globals__set_ref/2.
:- export se_globals__update_ref/2.
:- export se_globals__push_scope_stack/0, se_globals__pop_scope_stack/0.

%declaring global references: undone on backtracking
:- local reference('current_path_bran', []).    %list of branches followed so far
:- local reference('call_stack_bran', []).      %list of functions entered so far
:- local reference('scope_stack', [scope(0, dummy)]).          %[scope(level_nb|Var)|Older] with Var only used for delaying and awakening, see SEAV module
:- local reference('verifier_inputs', []).      %only used in 'testcomp' testing mode to track the order of the verifier variables
%%%
%declaring global non-logical variables: not undone on backtracking
se_globals__set_globals(Install_dir, Target_source_file_name_no_ext, Debug_mode, Output_mode) :-    
    setval('errorMessageNb', 0),	            %number of error messages generated: used to set trace_points in debug mode only
    setval('debug_info', 'pre_symbolic_execution'),    %used in debug mode only to hold the current processing position of the symbolic executor: a phase, file, or function being handled
    setval('phase', 'elaboration'),             %initially we are in the elaboration phase: used during cfg building and elaboration control
    setval('covered_bran', []),                 %list of branches covered so far
    setval('to_cover', []),                     %list of branches remaining to cover
    setval('path_nb', 0),                       %number of paths generated
    setval('test_driver_test_nb', 0),
    setval('abandoned_path_nb', 0),	            %counts the number of timed out and unsuccessful labeling tests
    setval('install_dir', Install_dir),         %the install dir of the generator executable
    setval('target_source_file_name_no_ext', Target_source_file_name_no_ext),   %the name of target source file without extension
    setval('debug_mode', Debug_mode),           %'debug' or 'release'
    setval('output_mode', Output_mode),         %'testcomp' or something else 
    setval('message_mode', Debug_mode),         %debug or release todo: remove, just use debug_mode
    setval('already_printed', []),              %list of already printed error messages : used in release mode only
    !.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_globals__get_val(Global, Value) :-
    getval(Global, Value).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_globals__set_val(Global, Value) :-      
    setval(Global, Value). 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_globals__get_ref(Global, Value) :-
    getref(Global, Value).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_globals__set_ref(Global, Value) :-
    setref(Global, Value).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_globals__update_ref(Global, Value) :-
    (Global == 'current_path_bran' ->
        (se_globals__get_ref('current_path_bran', Current_path),
         se_globals__set_ref('current_path_bran', [Value|Current_path]),
         printf(user_error, "Following branch: %w\n", Value)
        )
    ;        
        setref(Global, Value)
    ). 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_globals__push_scope_stack :-
    getref('scope_stack', [scope(Current_level, Current_var_scope)|Rest_stack]),
    Next_level is Current_level + 1,
    setref('scope_stack', [scope(Next_level, _Next_var_scope), scope(Current_level, Current_var_scope)|Rest_stack]).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_globals__pop_scope_stack :-
    getref('scope_stack', [scope(Exit_level, Exist_var_scope)|Exit_stack]),
    Exist_var_scope = Exit_level,      %will trigger awakening of variables for that level: pops their own variable-level stack
    setref('scope_stack', Exit_stack).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
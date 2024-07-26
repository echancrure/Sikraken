:- module('se_globals').
:- export se_globals__set_globals/2, se_globals__getval/2, se_globals__setval/2, se_globals__getref/2, se_globals__setref/2.

%declaring global references: undone on backtracking
:- local reference('current_path_bran', []).   %list of branches followed so far
:- local reference('call_stack_bran', []).     %list of functions entered so far

%%%
se_globals__set_globals(Install_dir, Debug_mode) :-
    %declaring global non-logical variables: not undone on backtracking
    setval('errorMessageNb', 0),	            %number of error messages generated: used to set trace_points in debug mode only
    setval('debug_info', 'pre_symbolic_execution'),    %used in debug mode only to hold the current processing position of the symbolic executor: a phase, file, or function being handled
    setval('phase', 'elaboration'),             %initially we are in the elaboration phase: used during cfg building and elaboration control
    setval('covered_bran', []),                 %list of branches covered so far
    setval('to_cover', []),                     %list of branches remaining to cover
    setval('path_nb', 0),                       %number of paths generated
    setval('test_driver_test_nb', 0),
    setval('abandoned_path_nb', 0),	            %counts the number of timed out and unsuccessful labeling tests
    setval('install_dir', Install_dir),         %the install dir of the generator executable
    setval('debug_mode', Debug_mode),           %debug or release
    setval('message_mode', Debug_mode),         %debug or release
    setval('already_printed', []),              %list of already printed error messages : used in release mode only
    !.
%%%
se_globals__getval(Global, Value) :-
    getval(Global, Value).
%%%
se_globals__setval(Global, Value) :-
    setval(Global, Value).
%%%
se_globals__getref(Global, Value) :-
    getref(Global, Value).
%%%
se_globals__setref(Global, Value) :-
    setref(Global, Value).
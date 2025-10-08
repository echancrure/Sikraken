%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_run_log__preamble(ArgsL) :-
    get_flag('unix_time', Time), 
    local_time_string(Time, "%c", Timestamp),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(output, "Sikraken Raw Arguments:\t%w\n", [ArgsL]),
    printf(output, "Time Stamp: %w\n", [Timestamp]),
    get_flag('max_local_control', Max_local_control), 
    Max_local_control_in_MB is (Max_local_control div 1024) div 1024,
    get_flag('max_global_trail', Max_global_trail), 
    Max_global_trail_in_MB is (Max_global_trail div 1024) div 1024,
    get_flag('version', Version), 
    printf(output, "ECLiPSe version:\t%w\n", [Version]),
    printf(output, "ECLiPSe Maximum allowed local/control user stack (-l option):\t%wMB\n", [Max_local_control_in_MB]),
    printf(output, "ECLiPSe Maximum allowed global/trail user stack (-g option):\t%wMB\n", [Max_global_trail_in_MB]),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    close(output).
    %%%
    print_options([]).
    print_options([Option|R]) :-
        printf(output, "\tOption:\t\t%w\n", [Option]),
        print_options(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_run_log :-
    statistics(event_time, Current_session_time),
    printf('output', "Dev Info: Session time is %.2f seconds\n", [Current_session_time]),
    %getval('test_run_filename', Test_run_filename),
    %open(Test_run_filename, 'append', Test_run_stream),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(output, "Sikraken Session Results:\n", []),
    statistics('cputime', Cputime),
    Cputime_seconds is fix(Cputime),
    se_globals__get_val('path_nb', Test_nb),
    printf(output, "\tECLiPSe CPU time: \t%w seconds\n", [Cputime_seconds]),
    printf(output, "\tGenerated: \t\t%w tests\n", [Test_nb]),
    mytrace,
    se_globals__get_val('covered_bran', Overall_covered),
    length(Overall_covered, Covered_nb),
    se_globals__get_val('EdgeCount', EdgeCount),
    (EdgeCount == 0 -> Coverage = 100.0 ; Coverage is (Covered_nb / EdgeCount) * 100),
    printf(output, "\tCFG: \t\t\t%w edges\n", [EdgeCount]),
    printf(output, "\tCoverage: \t\t%.2f%%\n", [Coverage]),
    se_globals__get_val('AllEdges', All_pure_edges_sorted),
    printf(output, "\tAll: \t\t\t", []),
    print_branches_list(All_pure_edges_sorted),
    printf(output, "\tCovered: \t\t", []),
    print_branches_list(Overall_covered),
    ord_subtract(All_pure_edges_sorted, Overall_covered, Uncovered_edges),
    printf(output, "\tMissing: \t\t", []),
    print_branches_list(Uncovered_edges),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(output, "ECLiPSe Statistics Dump:", []), 
    get_stream('log_output', Log_output_stream),
    set_stream('log_output', output),
    statistics,     %printing out ECLiPSe internal statistics into redirected stream
    set_stream('log_output', Log_output_stream),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []). 
    %%%
    print_branches_list([]) :-
        printf(output, "\n", []).
    print_branches_list([Branch]) :-
        printf(output, "%w\n", [Branch]).
    print_branches_list([Branch|R]) :-
        printf(output, "%w,", [Branch]),
        print_branches_list(R).
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
easter_egg :-
    printf('output', "                                                                                                       .         .                          \n", []),
    printf('output', "        ,o888888o.     8 8888      88 8888888 8888888888   .8.    8888888 8888888888  8 8888          ,8.       ,8.          8 8888888888   \n", []),
    printf('output', "     . 8888     `88.   8 8888      88       8 8888        .888.         8 8888        8 8888         ,888.     ,888.         8 8888         \n", []),
    printf('output', "    ,8 8888       `8b  8 8888      88       8 8888       :88888.        8 8888        8 8888        .`8888.   .`8888.        8 8888         \n", []),
    printf('output', "    88 8888        `8b 8 8888      88       8 8888      . `88888.       8 8888        8 8888       ,8.`8888. ,8.`8888.       8 8888         \n", []),
    printf('output', "    88 8888         88 8 8888      88       8 8888     .8. `88888.      8 8888        8 8888      ,8'8.`8888,8^8.`8888.      8 888888888888 \n", []),
    printf('output', "    88 8888         88 8 8888      88       8 8888    .8`8. `88888.     8 8888        8 8888     ,8' `8.`8888' `8.`8888.     8 8888         \n", []),
    printf('output', "    88 8888        ,8P 8 8888      88       8 8888   .8' `8. `88888.    8 8888        8 8888    ,8'   `8.`88'   `8.`8888.    8 8888         \n", []),
    printf('output', "    `8 8888       ,8P  ` 8888     ,8P       8 8888  .8'   `8. `88888.   8 8888        8 8888   ,8'     `8.`'     `8.`8888.   8 8888         \n", []),
    printf('output', "     ` 8888     ,88'     8888   ,d8P        8 8888 .888888888. `88888.  8 8888        8 8888  ,8'       `8        `8.`8888.  8 8888         \n", []),
    printf('output', "        `8888888P'        `Y88888P'         8 8888.8'       `8. `88888. 8 8888        8 8888 ,8'         `         `8.`8888. 8 888888888888 \n\n", []).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
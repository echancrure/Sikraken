%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_test_run_log__preamble(ArgsL) :-
    ArgsL = [_Install_dir, Source_dir, Target_source_file_name_no_ext, Target_raw_subprogram_name, Debug_mode, Output_mode, Data_model, Budget|Options],
    get_flag('unix_time', Time), 
    local_time_string(Time, "%Y_%m_%d_%H_%M_%S", Timestamp),
    %concat_string([Install_dir, '/sikraken_output/', Target_source_file_name_no_ext, "/test_run_", Target_source_file_name_no_ext, ".log"], Test_run_filename),
    %setval('test_run_filename', Test_run_filename), 
    %open(Test_run_filename, 'write', 'test_run_stream'),    %the directory must exist otherwise open/3 aborts
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(output, "Sikraken Test Inputs Generation Run Log\n", []),
    printf(output, "Raw Arguments:\t%w\n", [ArgsL]),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(output, "Relevant ECLiPSe Configurations:\n", []),
    get_flag('debug_compile', Debug_compile),
    get_flag('debugging', Debugging),
    get_flag('max_local_control', Max_local_control), 
    Max_local_control_in_MB is (Max_local_control div 1024) div 1024,
    get_flag('max_global_trail', Max_global_trail), 
    Max_global_trail_in_MB is (Max_global_trail div 1024) div 1024,
    get_flag('version', Version), 
    printf(output, "\tECLiPSe version:\t%w\n", [Version]),
    printf(output, "\tdebug_compile:\t\t%w\n", [Debug_compile]),
    printf(output, "\tdebugging:\t\t\t%w\n", [Debugging]),
    printf(output, "\tMaximum allowed local/control user stack (-l option):\t%wMB\n", [Max_local_control_in_MB]),
    printf(output, "\tMaximum allowed global/trail user stack (-g option):\t%wMB\n", [Max_global_trail_in_MB]),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(output, "Sikraken Session Configurations at: %w\n", [Timestamp]),
    printf(output, "\tRun mode:\t%w\n", [Debug_mode]),
    printf(output, "\tTests inputs target format:\t%w\n", [Output_mode]),
    printf(output, "\tTarget data model:\t%w\n", [Data_model]),
    printf(output, "\tTarget function:\t%w\n", [Target_raw_subprogram_name]),   
    printf(output, "\tTarget C file:\t\t%w (in folder:%w)\n", [Target_source_file_name_no_ext, Source_dir]),
    printf(output, "\tTime budget:\t\t%w\n", [Budget]),
    print_options(Options),
    close(output).
    %%%
    print_options([]).
    print_options([Option|R]) :-
        printf(output, "\tOption:\t\t\t%w\n", [Option]),
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
    printf(output, "\tGenerated: \t\t\t%w tests\n", [Test_nb]),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", []),
    printf(output, "ECLiPSe Statistics Dump:\n", []), 
    get_stream('log_output', Log_output_stream),
    set_stream('log_output', output),
    statistics,     %printing out ECLiPSe internal statistics into redirected stream
    set_stream('log_output', Log_output_stream),
    printf(output, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%", []).
    %close(Test_run_stream).
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
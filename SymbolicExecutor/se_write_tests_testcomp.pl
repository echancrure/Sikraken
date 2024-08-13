:- lib(calendar).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%create the folder for TestComp format and the metadat file
print_preamble_testcomp(Parsed_dir, Target_source_file_name, Test_suite_folder) :-
    concat_atom([Parsed_dir, 'suite-', Target_source_file_name], Test_suite_folder),
    concat_atom([Parsed_dir, Target_source_file_name, '.c'], Filename),
    mkdir(Test_suite_folder),
    open('metadata.xml', 'write', _, [alias('answer_output')]),
    format('answer_output', "<?xml version=""1.0"" encoding=""UTF-8"" standalone=""no""?>\n", []),
    format('answer_output', "<!DOCTYPE test-metadata PUBLIC ""+//IDN sosy-lab.org//DTD test-format test-metadata 1.1//EN"" ""https://sosy-lab.org/test-format/test-metadata-1.1.dtd"">\n", []),
    format('answer_output', "<test-metadata>\n", []),
    format('answer_output', "<sourcecodelang>C</sourcecodelang>\n", []),
    format('answer_output', "<producer>Sikraken</producer>\n", []),
    format('answer_output', "<specification>CHECK( init(main()), FQL(cover EDGES(@DECISIONEDGE)) )</specification>\n", []),
    format('answer_output', "<programfile>%w</programfile>\n", [Filename]),
    get_hash(Filename, Hash),
    format('answer_output', "<programhash>%w</programhash>\n", [Hash]),
    format('answer_output', "<entryfunction>main</entryfunction>\n", []),
    format('answer_output', "<architecture>32bit</architecture>\n", []),
    get_Date_time(Date_time),
    format('answer_output', "<creationtime>%w</creationtime>\n", [Date_time]),
    format('answer_output', "</test-metadata>", []),
    close('answer_output').
    %%%
    get_hash(Filename, Hash) :-
        concat_atom(['get_hash.sh ', Filename, '.c'], Script_call),
        exec(Script_call, [stdout(pipe(Out))]),
        read_string(Out, _, Hash),
        close(Out).
    %%%
    get_Date_time(Date_time) :-
        mjd_now(Now), 
        mjd_to_ymd(Now, YMD), 
        mjd_to_time(Now, Time),
        concat_atom([YMD, ' - ', Time], Date_time).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%create a new test case .xml file
print_test_inputs_testcomp(SEAV_list, Test_suite_folder) :-
    se_globals__getval('path_nb', Test_nb),
    concat_atom(['testinput-', Test_nb, '.xml'], Filename),
    open(Filename, 'write', _, [alias('answer_output')]),
    format('answer_output', "<?xml version=""1.0"" encoding=""UTF-8"" standalone=""no""?>\n", []),
    format('answer_output', "<!DOCTYPE testcase PUBLIC ""+//IDN sosy-lab.org//DTD test-format testcase 1.1//EN"" ""https://sosy-lab.org/test-format/testcase-1.1.dtd"">\n", []),
    format('answer_output', "<testcase>\n", []),
    print_SEAVs(SEAV_list, 'answer_output'),
    format('answer_output', "</testcase>", []),
    close('answer_output').
    %%%
    print_SEAVs([], _).
    print_SEAVs([SEAV|R], Stream) :-
        se_name_atts__get(SEAV, 'name', Name),
        seav__get(SEAV, 'input', Input_value),
        printf(Stream, "\t<input variable=""%w"" type=""int"">%w</input>\n", [Name, Input_value]),
        print_SEAVs(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%zip the Test_suite_folder directory for TestCov consumption
terminate_test_comp(Test_suite_folder):-
    true.

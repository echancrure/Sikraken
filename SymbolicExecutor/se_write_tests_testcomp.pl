%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%create the folder for TestComp format and the metadata file
print_preamble_testcomp(Parsed_dir, Target_source_file_name) :-
    concat_atom([Parsed_dir, 'suite-', Target_source_file_name], Test_suite_folder),
    concat_atom([Parsed_dir, Target_source_file_name, '.c'], Filename),
    (exists(Test_suite_folder) ->
        (concat_atom(['rm -rf ', Test_suite_folder], Delete_call),
         system(Delete_call)
        )
    ;
        true
    ),
    mkdir(Test_suite_folder),
    se_globals__setval(testcomp_test_suite_folder, Test_suite_folder),
    cd(Test_suite_folder),
    open('metadata.xml', 'write', 'metadata_stream'),
    printf('metadata_stream', "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n", []),
    printf('metadata_stream', "<!DOCTYPE test-metadata PUBLIC \"+//IDN sosy-lab.org//DTD test-format test-metadata 1.1//EN\" \"https://sosy-lab.org/test-format/test-metadata-1.1.dtd\">\n", []),
    printf('metadata_stream', "<test-metadata>\n", []),
    printf('metadata_stream', "\t<sourcecodelang>C</sourcecodelang>\n", []),
    printf('metadata_stream', "\t<producer>Sikraken</producer>\n", []),
    printf('metadata_stream', "\t<specification>CHECK( init(main()), FQL(cover EDGES(@DECISIONEDGE)) )</specification>\n", []),
    printf('metadata_stream', "\t<programfile>%w</programfile>\n", [Filename]),
    get_hash(Filename, Hash),
    printf('metadata_stream', "\t<programhash>%w</programhash>\n", [Hash]),
    printf('metadata_stream', "\t<entryfunction>main</entryfunction>\n", []),
    printf('metadata_stream', "\t<architecture>32bit</architecture>\n", []),
    get_Date_time(Date_time),
    printf('metadata_stream', "\t<creationtime>%w</creationtime>\n", [Date_time]),
    printf('metadata_stream', "</test-metadata>", []),
    close('metadata_stream').
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    get_hash(Filename, Hash) :-
        se_globals__getval('install_dir', Install_dir),
        concat_atom([Install_dir, 'SymbolicExecutor/get_hash.sh ', Filename], Hash_call),
        exec(Hash_call, [_, 'hash_stream', _]),
        read_string('hash_stream', end_of_line, "", _, Hash),
        close('hash_stream').
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    get_Date_time(Date_time) :-
        get_flag(unix_time, T), 
        local_time_string(T, "%c", Date_time).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%create a new test case .xml file
print_test_inputs_testcomp(Verifier_inputs) :-
    se_globals__getval('path_nb', Test_nb),
    concat_atom(['test_input-', Test_nb, '.xml'], Filename),
    open(Filename, 'write', 'test_input_stream'),
    printf('test_input_stream', "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n", []),
    printf('test_input_stream', "<!DOCTYPE testcase PUBLIC \"+//IDN sosy-lab.org//DTD test-format testcase 1.1//EN\" \"https://sosy-lab.org/test-format/testcase-1.1.dtd\">\n", []),
    printf('test_input_stream', "<testcase>\n", []),
    %mytrace,
    print_inputs(Verifier_inputs),
    printf('test_input_stream', "</testcase>", []),
    close('test_input_stream').
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    print_inputs([]).
    print_inputs([Input|R]) :-
        printf('test_input_stream', "\t<input>%w</input>\n", [Input]),
        print_inputs(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%zip the Test_suite_folder directory for TestCov consumption
terminate_testcomp(Target_source_file_name):-
    mytrace,
    se_globals__getval(testcomp_test_suite_folder, Test_suite_folder),
    cd('..'),
    concat_string(["zip -r suite-", Target_source_file_name, ".zip ", Test_suite_folder], Zip_call),
    exec(Zip_call, []).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
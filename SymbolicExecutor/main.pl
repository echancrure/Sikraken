:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(function_info).

:- ['c_type_decls'].
:- ['memory_model'].
:- ['declaration'].
:- ['expressions'].
:- ['statement_handler'].
:- ['utils'].

% sub_atom/5 is used in creating function_info variables.
% It strips the LC_/UC_ from the function name, while retaining it as an atom.
:- import sub_atom/5 from iso_light.

% Used in regression_main/1 to convert an atom to a string
:- import atom_codes/2 from iso_light.

% Prolog Global values (getval/2, setval/2):
%  test_folder_path (String): The path to the folder where the test-cases are generated
%  test_id (integer, default: 1): This is an Id used to identify test cases generated
% tests (List, default: []): This list holds the names of the generated test cases
%      Eg: ["test_1", "test_2", "test_3"...]
%  free_address (integer, default: 1000): This is the address of the next free memory location in the memory model

%% Prolog Global References (getref/2, setref/2):
%%  memory_model (hash -- key: integer(getval(free_address)), value: c_var): Global memory model (In the form of a hash table)

% A shortcut predicate to main/3 outputting to the Prolog directory
% Useful for development. This is not called in code, only by the regression testing tool.
regression_main(Function_name) :-
    atom(Function_name),
    atom_codes(Function_name, Codes),
    string_codes(Filename_string, Codes),
    main(Filename_string, Function_name, "./", false, 'yes_ts').

% A shortcut predicate to main/3 outputting to the Prolog directory
% Useful for development. This is not called in code, only by a developer
main(Function_name) :-
    main("sign", Function_name, "./", false, 'yes_ts').

%the entrypoint to the symbolic executor
%% Filename_without_extension: The name of the file without the .pl extension. This should be a string. E.g. "sign"
%% Function_name: The entry function to be tested. This should be an atom. E.g. get_sign
%% Path_to_C_file: The folder-path to the C file to be symbolically executed. This should be a string. E.g. "C:\\Users\\user\\Desktop"
%% Override_globals: A boolean option if global variables should be overridden This should be either the atoms true or false. E.g. true
main(Filename_without_extension, Function_name, Path_to_C_file, Override_globals, CreateTimeStampedDirectory) :-
    utils__assert(string(Filename_without_extension), "Filename must be a string", []),
    utils__assert(not string_contains(Filename_without_extension, ".pl"), "Filename should not contain an extension", []),
    utils__assert(atom(Function_name), "Function name must be an atom", []),
    utils__assert(string(Path_to_C_file), "Path to C file must be a string", []),
    utils__assert(get_file_info(Path_to_C_file, type, directory), "Path to C file is not a valid directory-path", []),
    utils__assert(once member(Override_globals, [false, true]), "Override globals option must be an atom of a boolean ('true' or 'false')", []),
    (CreateTimeStampedDirectory == 'yes_ts' ->
        (get_flag(unix_time, Unix_time),
         local_time_string(Unix_time,"%y_%m_%d__%H_%M_%S", Date_string),     %built-in, Format: year_month_day__24Hours_Minutes_Seconds Eg: 24_06_18__13_22_05
         concat_string([Path_to_C_file, "/", Function_name, "_tests_", Date_string, "/"], Test_folder_path)
        )
    ;
     CreateTimeStampedDirectory == 'no_ts' ->
        concat_string([Path_to_C_file, "/", Function_name, "_tests/"], Test_folder_path)
    ;
        utils__assert(fail, "CreateTimeStampedDirectory must be 'yes_ts' or 'no_ts' instead of %s", [CreateTimeStampedDirectory])
    ),
    setval(test_folder_path, Test_folder_path),       %output directory for the generated test suites test drivers
    setval(test_id, 1),     %initial Id used to identify test cases generated. Used in test_generation.pl
    setval(tests, []),      %a list holding the names of test cases in the form ["test_1","test_2"...] used in test_generation.pl when generating the '_main' cunit .c file
    initialise_memory_model,
    setup_ptc_solver,
    concat_string([Path_to_C_file, "/", Filename_without_extension, ".pl"], Prolog_filepath),     
    open(Prolog_filepath, read, Stream),
    read_term(Stream, Parsed_terms, []),    %read the terms from the foo.pl todo add error handling
    close(Stream),
    Parsed_terms = parsed(Terms),
    process_global_variables(Terms, All_globals),   %execute all globals
    declare_functions(Terms, Function_name, Function_info), 
    sprintf(Error_message, "The entry function '%a' cannot be found", [Function_name]),
    utils__assert(not free(Function_info), Error_message, []),
    function_info__get_clean_function(Function_info, _, Parameters, Body, Return_type),
    utils__assert(Return_type \= void, "No unit tests to generate for a void-returning function", []),
    declare_static_variables(Body),
    override_globals(Override_globals, All_globals, Parameters, Processed_parameters),

    symbolically_execute_function(Filename_without_extension, Function_name, Body, Processed_parameters, Return_type). % From Statement_handler.pl
%%%
%setup for the ptc_solver, additionally declaring the C types to the solver
setup_ptc_solver :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(boolean_int, integer, range_bounds(0, 1)),
    declare_c_types_to_ptc_solver.
%%%
%declare_c_types_to_ptc_solver/0
declare_c_types_to_ptc_solver :-
    c_type_decl(Type, _, Minimum_bound, Maximum_bound), %retrieve basic c type declaration
    (integer(Maximum_bound) ->
        ptc_solver__type(Type, integer, range_bounds(Minimum_bound, Maximum_bound))
    ;
        % For the moment, floating-point types outside of the built-in ptc 'float' type are unsupported
        true
        % Type \= float % The ptc_solver already has a definition of a 'float' type - It can be override if desired
        % ptc_solver__type(Type, float, range_bounds(Minimum_bound, Maximum_bound))
    ),
    fail.
declare_c_types_to_ptc_solver.
%%%
% process_global_variables/2
% process_global_variables(+Terms, -List_of_global_declarations)
% Initialise global variables
% Parameters:
%  Terms: The contents of the parser-result prolog file
%  List_of_global_declarations: The list of global declarations
process_global_variables(Terms, List_of_global_declarations) :-
    process_global_variables(Terms, [], List_of_global_declarations).

process_global_variables([], List_of_global_declarations, List_of_global_declarations) :- !.
process_global_variables([global_variables([Declaration | _], _) | More_terms], Global_declaration_accumulator, List_of_global_declarations) :-
    Declaration, % From declaration.pl
    term_variables(Declaration, [Global_variable | _]),
    c_var__set_scope(Global_variable, global),
    process_global_variables(More_terms, [Declaration | Global_declaration_accumulator], List_of_global_declarations).
process_global_variables([_ | More_terms], Global_declaration_accumulator, List_of_global_declarations) :-
    process_global_variables(More_terms, Global_declaration_accumulator, List_of_global_declarations).

%% declare_static_variables/1
%% declare_static_variables(+Body)
%% Declares functions as attributed variables and returns a desired function_info
%% Parameters:
%%  Terms: The contents of the parser-result prolog file
%%  Function_name: The name of the function to be found
%%  Function_info: The function_info matching to the function_name
declare_functions([], _, _).
declare_functions([function_definition(Function_info, Params, Body, Return_type) | More_terms], Function_name_to_be_found, Found_function) :-
    get_var_info(Function_info, name, Function_name_as_atom),
    !,
    % Strip 'LC_' or 'UC_' from the function name
    sub_atom(Function_name_as_atom, 3, _, 0, Stripped_function_name),
    function_info__create(function_definition(Stripped_function_name, Params, Body, Return_type), Function_info),
    (Stripped_function_name = Function_name_to_be_found ->
        Found_function = Function_info
    ;
        true
    ),
    declare_functions(More_terms, Function_name_to_be_found, Found_function).
declare_functions([_ | More_terms], Function_name_to_be_found, Function_info) :-
    declare_functions(More_terms, Function_name_to_be_found, Function_info).

override_globals(true, All_globals, [void], All_globals) :- !.
override_globals(true, All_globals, Function_parameters, Parameters) :-
    append(All_globals, Function_parameters, Parameters).
override_globals(false, _, Parameters, Parameters).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     END   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
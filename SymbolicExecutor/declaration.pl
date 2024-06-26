:- lib(ptc_solver).
:- lib(regex).

:- use_module(c_var).

declaration(Type, [C_variable], Assignment) :-
    declaration__get_variable_name(C_variable, C_name),

    % Check if it is a pointer type
    (sub_atom(Type, _, _, _, 'pointer') ->
        (
            ptc_solver__variable([In], pointer),
            once ptc_solver__label_integers([In], 'indomain_random')
        )
    ;
        (
            ptc_solver__variable([In], Type)
        )
    ),
    c_var__create(Type, In, local, C_name, _, C_variable),
    add_to_memory(C_variable),
    statement_handler(Assignment, _),
    !.

%% declaration__get_variable_name/2
%% declaration__get_variable_name(+Variable, -Name)
%% Gets a clean variable name as a string from the parser-output
%% Parameters:
%%  Variable: The variable to get the name of
%%  Name: The name of the variable, as a string
%% Eg: declaration__get_variable_name(LC_x_83, Result) -> Result = "x"
declaration__get_variable_name(Variable, Name) :-
    once get_var_info(Variable, name, Parser_name),
    atom_string(Parser_name, Parser_name_as_string),
    % Strip 'LC_' or 'UC_' from the variable name
    sub_string(Parser_name_as_string, 3, _, 0, Parser_name_as_string_without_lc_or_uc),
    % Removes the line number suffix from a string, added by the parser.
    % Eg: "__x__183" becomes "__x_"
    split("(_[0-9]+)$", Parser_name_as_string_without_lc_or_uc, [], [Name | _]).

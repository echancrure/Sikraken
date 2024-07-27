symbolic_execute_all_declarations([]).
symbolic_execute_all_declarations([Declaration|R]) :-
    symbolic_execute(Declaration),
    symbolic_execute_all_declarations(R).

symbolic_execute(declaration(Specifiers, Declarators)) :-
    extract_type(Specifiers, Type_name),
    declare_declarators(Declarators, Type_name).

symbolic_execute(function(Specifiers, Function_name, Params, [], Compound_statement)) :-
    .  
%%%
extract_type([int], int) :-
    !.
extract_type(Specifiers, _Type_name) :-
    common_util__error(9, "Not Handled", "Sikraken needs expanding", [('Specifiers', Specifiers)], 9270724, 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
%%%
declare_declarators([], _).
declare_declarators([Declarator|R], Type_name) :-
    (Declarator = initialised(Var, Expresion) ->
        (symbolically_interpret(Expression, Symbolic, Constraint, Type),
         se_heap__create_var(Var, Type_name, Constraint)
        )
    ;
        se_heap__create_var(Var, Type_name, no_init)
    ).
%%% 
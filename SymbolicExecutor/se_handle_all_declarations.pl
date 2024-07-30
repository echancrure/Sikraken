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
    (Declarator = initialised(Var, Expression) ->
        symbolically_interpret(Expression, Symbolic)
    ;
        (Var = Declarator,
         ptc_solver__variable([Symbolic], Type_name)
        )
    ),
    se_seav__create_var(Var, Type_name, SEAV),
    se_seav__update(SEAV, input, Symbolic),
    se_seav__update(SEAV, output, Symbolic).
%%% 
symbolic_execute_all_declarations([]).
symbolic_execute_all_declarations([Declaration|R]) :-
    symbolic_execute(Declaration),
    symbolic_execute_all_declarations(R).

symbolic_execute(declaration(Specifiers, Declarators)) :-
    extract_type(Specifiers, Type_name),
    declare_declarators(Declarators, Type_name).

symbolic_execute(function(_Specifiers, _Function_name, _Params, [], _Compound_statement)) :-
    true.  
%%%
extract_type([int], integer) :-
    !.
extract_type(Specifiers, _Type_name) :-
    common_util__error(9, "Not Handled", "Sikraken needs expanding", [('Specifiers', Specifiers)], 9270724, 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
%%%
declare_declarators([], _).
declare_declarators([Declarator|R], Type_name) :-
    mytrace,
    (nonvar(Declarator), Declarator = initialised(Var, Expression) ->   %added nonvar(...) as a guard 30/07/24
        symbolically_interpret(Expression, Symbolic)
    ;
        (Var = Declarator,
         ptc_solver__variable([Symbolic], Type_name)
        )
    ),
    seav__create_var(Type_name, Var),
    seav__update(Var, 'input', Symbolic),
    seav__update(Var, 'output', Symbolic),
    declare_declarators(R, Type_name).
%%% 
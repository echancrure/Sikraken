symbolic_execute([]).
symbolic_execute([Item|R]) :-
    symbolic_execute(Item),
    symbolic_execute(R).
%%%
symbolic_execute(mytrace) :-
    mytrace.
symbolic_execute(declaration(Specifiers, Declarators)) :-
    extract_type(Specifiers, Type_name),
    declare_declarators(Declarators, Type_name).
symbolic_execute(function(Specifiers, Function, Parameters, [], Compound_statement)) :-
    extract_type(Specifiers, Return_type_name),
    se_sub_atts__create(Return_type_name, Parameters, Compound_statement, Function).
symbolic_execute(cmp_stmts(List)) :-
    symbolic_execute(List).
symbolic_execute(stmt(assign(LValue, Expression))) :-
    %mytrace,
    (seav__is_seav(LValue) ->
        (symbolically_interpret(Expression, Symbolic_expression),
         seav__update(LValue, 'output', Symbolic_expression)
        )
    ;
        (symbolically_interpret(LValue, Symbolic_LValue),
         symbolic_execute(stmt(assign(Symbolic_LValue, Expression)))
        )
    ).
%%%
extract_type([int], integer) :-
    !.
extract_type([void], void) :-
    !.
extract_type(Specifiers, _Type_name) :-
    common_util__error(9, "Not Handled", "Sikraken needs expanding", [('Specifiers', Specifiers)], 9270724, 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
%%%
declare_declarators([], _).
declare_declarators([Declarator|R], Type_name) :-
    %mytrace,
    (nonvar(Declarator), Declarator = initialised(Var, Expression) ->   %added nonvar(...) as a guard 30/07/24
        symbolically_interpret(Expression, Symbolic)
    ;
        (%declaration of non-initialised variable
         Var = Declarator,
         Symbolic = null %for static variables; for non-static, automatic objects use ptc_solver__variable([Symbolic], Type_name) as they are not initialised in C see K&R p. 219
        )
    ),
    extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var),
    seav__create_var(Type_name_ptr_opt, Clean_var),
    seav__update(Clean_var, 'input', Symbolic),
    seav__update(Clean_var, 'output', Symbolic),
    declare_declarators(R, Type_name).
%%%
%e.g. extract_pointers(pointer(X), int, pointer(int), X)
extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var) :-
    (nonvar(Var), Var = pointer(Inner_var) ->
        (extract_pointers(Inner_var, Type_name, Inner_type_name, Clean_var),
         Type_name_ptr_opt = pointer(Inner_type_name)
        )
    ;
        (Type_name_ptr_opt = Type_name,
         Clean_var = Var
        )    
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
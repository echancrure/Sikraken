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
     LValue = deref(LValue_ptr) ->
        (symbolically_interpret(LValue_ptr, Symbolic_LValue_ptr),
         (Symbolic_LValue_ptr = addr(New_LValue) ->
            symbolic_execute(stmt(assign(New_LValue, Expression)))
         ;
            common_util__error(10, "Unexpected derefed expression", "Sikraken's logic is wrong", [('Symbolic_LValue_ptr', Symbolic_LValue_ptr)], 10030824, 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info)
         )
        )
    ;
        common_util__error(10, "Unexpected LValue", "Sikraken's logic is wrong", [('LValue', LValue)], 10030824_2, 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info)
    ).
symbolic_execute(if_stmt(Condition, True_statements, False_statements)) :-
    mytrace,
    symbolically_interpret(Condition, Symbolic_condition),
    (   (ptc_solver__sdl(Symbolic_condition),
         symbolic_execute(True_statements)
        )
    ;   %deliberate choice point
        (ptc_solver__sdl(not(Symbolic_condition)),
         symbolic_execute(False_statements)
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
    mytrace,
    (nonvar(Declarator), Declarator = initialised(Var, Expression) ->   %added nonvar(...) as a guard 30/07/24
        symbolically_interpret(Expression, Symbolic)    %todo: handling initialised variables without re-using assignment symbolic execution is probably a bad idea
    ;
        (%declaration of non-initialised variable
         Var = Declarator,
         Symbolic = 0 %todo: should be only for global and static variables as non-static and automatic objects are not initialised in C see K&R p. 219
        )
    ),
    extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var), %e.g. extract_pointers(pointer(Pi_3{c_id(pi)}), integer, pointer(integer), Pi_3)
    seav__create_var(Type_name_ptr_opt, Clean_var),
    seav__update(Clean_var, 'input', 'not_needed'),
    %crate ptc solver variable and == to Symbolic
    (Type_name_ptr_opt = pointer(_) ->
        Output = Symbolic           %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    ;
        (ptc_solver__variable([Output], Type_name),
         ptc_solver__sdl(Output = Symbolic)
        )
    ),
    seav__update(Clean_var, 'output', Output),
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
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
symbolic_execute(cmp_stmts(Stmts)) :-
    se_globals__push_scope_stack,
    symbolic_execute(Stmts),
    %pop scope
    se_globals__pop_scope_stack.
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
    %mytrace,
    symbolically_interpret(Condition, Symbolic_condition),
    (   (ptc_solver__sdl(Symbolic_condition),
         symbolic_execute(True_statements)
        )
    ;   %deliberate choice point
        (ptc_solver__sdl(not(Symbolic_condition)),
         symbolic_execute(False_statements)
        )
    ).
symbolic_execute(return_stmt(Return_var, Expression)) :- 
    symbolic_execute(stmt(assign(Return_var, Expression))).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%The second argument of symbolic_execute/2 is an indication of the control flow.
%  it can have the following values : 'carry_on'|goto(Label)|exit|return(expression)
symbolic_execute([], 'carry_on') :-
    !.
symbolic_execute([Item|R], Flow) :-
    !,
    symbolic_execute(Item, Inner_flow),
    (Inner_flow == 'carry_on' ->
        symbolic_execute(R, Flow)
    ;
        Flow = Inner_flow
    ).
symbolic_execute(mytrace, 'carry_on') :-
    !,
    mytrace.
symbolic_execute(declaration(Declaration_specifiers, Declarators), 'carry_on') :-
    !,
    ((Declarators = [Declarator], nonvar(Declarator), Declarator = function(Function_name, Parameters)) ->  %a function forward declaration
        (memberchk('extern', Declaration_specifiers) ->  %(need to use memberchk because 'extern' does not necessairily come first) found an extern function declaration
            (subtract(Declaration_specifiers, ['extern'], Other_specifiers),
             extract_type(Other_specifiers, Return_type_name),
             se_sub_atts__create(Return_type_name, Parameters, 'no_body_is_extern', Function_name)
            )
        ;
            true    %we ignore all, non-extern, forward function declarations: they will be declared later
        )
    ;
        (%a variable declaration
         extract_type(Declaration_specifiers, Type_name),
         declare_declarators(Declarators, Type_name)
        )
    ).
symbolic_execute(function(Specifiers, function(Function_name, Parameters), [], Compound_statement), 'carry_on') :-
    !,
    extract_type(Specifiers, Return_type_name),
    se_sub_atts__create(Return_type_name, Parameters, Compound_statement, Function_name).
symbolic_execute(cmp_stmts(Stmts), Flow) :-
    !,
    se_globals__push_scope_stack,
    symbolic_execute(Stmts, Flow),
    %pop scope
    se_globals__pop_scope_stack.
symbolic_execute(stmt(Expression_statement), Flow) :-
    !,
    symbolic_execute(Expression_statement, Flow).
symbolic_execute(assign(LValue, Expression), Flow) :-
    !,
    %mytrace,
    (seav__is_seav(LValue) ->
        (!,
         symbolically_interpret(Expression, Symbolic_expression),
         seav__update(LValue, 'output', Symbolic_expression),
         Flow = 'carry_on'
        )
    ;
     LValue = deref(LValue_ptr) ->
        (symbolically_interpret(LValue_ptr, Symbolic_LValue_ptr),
         (Symbolic_LValue_ptr = addr(New_LValue) ->
            symbolic_execute(assign(New_LValue, Expression), Flow)
         ;
            common_util__error(10, "Unexpected derefed expression", "Sikraken's logic is wrong", [('Symbolic_LValue_ptr', Symbolic_LValue_ptr)], '10_030824', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info)
         )
        )
    ;
        common_util__error(10, "Unexpected LValue", "Sikraken's logic is wrong", [('LValue', LValue)], '10_030824_2', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info)
    ).
symbolic_execute(function_call(Function, Arguments), 'carry_on') :-
    !,
    symbolically_interpret(function_call(Function, Arguments), _Symbolic_expression).
symbolic_execute(if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
    !,
    %mytrace,
    symbolically_interpret(Condition, Symbolic_condition),
    (se_coverage__bran_is_already_covered(branch(Id, 'true')) ->
        (
            (ptc_solver__sdl(not(Symbolic_condition)),
             se_globals__update_ref('current_path_bran', branch(Id, 'false')),
             symbolic_execute(False_statements, Flow)
            )
        ;   %deliberate choice point
            (random(1, R),
             (R == 0 ->
                (ptc_solver__sdl(Symbolic_condition),
                 se_globals__update_ref('current_path_bran', branch(Id, 'true')),
                 symbolic_execute(True_statements, Flow)
                )
             ;
                (%mytrace, 
                 fail
                )
             )
            )
        )
    ;
        (   (ptc_solver__sdl(Symbolic_condition),
             mytrace,
             se_globals__update_ref('current_path_bran', branch(Id, 'true')),
             symbolic_execute(True_statements, Flow)
            )
        ;   %deliberate choice point
            (random(1, R),
             (R == 0 ->
                (%mytrace,
                 ptc_solver__sdl(not(Symbolic_condition)),
                 se_globals__update_ref('current_path_bran', branch(Id, 'false')),
                 symbolic_execute(False_statements, Flow)
                )
             ;
                (%mytrace, 
                 fail
                )
             )
            )
        )
    ).
symbolic_execute(if_stmt(Branch, True_statements), Flow) :-
    !,
    symbolic_execute(if_stmt(Branch, True_statements, []), Flow).
symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow) :-
    !,
    %mytrace,
    symbolically_interpret(Condition, Symbolic_condition),
    (ptc_solver__sdl(Symbolic_condition <> 0) ->  %15 August 2024 hack for now...to deal with while(1)
        (se_globals__update_ref('current_path_bran', branch(Id, true)),
         symbolic_execute(Statements, Inner_flow), 
         (Inner_flow == 'carry_on' ->
            symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow)
         ;
            Flow = Inner_flow
         )
        )
    ;   %deliberate choice point
        (ptc_solver__sdl(not(Symbolic_condition)),
         se_globals__update_ref('current_path_bran', branch(Id, false)),
         Flow = 'carry_on'
        )
    ).
symbolic_execute(label_stmt(_Label, Statement), Flow) :- 
    !,
    symbolic_execute(Statement, Flow).
symbolic_execute(return_stmt(Expression), return(Symbolic)) :- 
    !,
    symbolically_interpret(Expression, Symbolic),
    ptc_solver__variable([Value], 'integer'),
    ptc_solver__sdl(Value = Symbolic).
    %common_util__error(0, "Return Statement Value:", 'no_error_consequences', [('Value', Value)], '0_150824_3', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info).
symbolic_execute(postfix_inc_op(Expression), 'carry_on') :-
    !,
    symbolically_interpret(postfix_inc_op(Expression), _).
symbolic_execute(Unknown_statement, _) :-
    !,
common_util__error(10, "Unexpected statement", "Could not possibly continue", [('Unknown_statement', Unknown_statement)], '10_150824_2', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
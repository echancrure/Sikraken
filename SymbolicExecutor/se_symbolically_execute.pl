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
    mytrace.    %within symbolic_execute/2
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
    se_globals__pop_scope_stack.
symbolic_execute(stmt(Expression_statement), Flow) :-
    !,
    symbolic_execute(Expression_statement, Flow).
symbolic_execute(assign(LValue, Expression), Flow) :-
    !,
    (seav__is_seav(LValue) ->
        (!,
         seav__get(LValue, 'type', To_type),
         symbolically_interpret(cast(To_type, Expression), symb(To_type, Casted)),
         seav__update(LValue, 'output', Casted),
         Flow = 'carry_on'
        )
    ;
     LValue = deref(LValue_ptr) ->
        (symbolically_interpret(LValue_ptr, symb(_, Symbolic_LValue_ptr)),
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
    symbolically_interpret(function_call(Function, Arguments), _Symbolic_expression).   %todo ok for exit and abort but not is it has a non-void return
symbolic_execute(if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
    !,
    %(Id == 155 -> mytrace ; true),
    %mytrace,
    symbolically_interpret(Condition, symb(_, Condition_value)),
    (Condition_value == 1   ->
        (se_globals__update_ref('current_path_bran', branch(Id, 'true')),
            symbolic_execute(True_statements, Flow)
        )
    ;
     Condition_value == 0   ->
        (se_globals__update_ref('current_path_bran', branch(Id, 'false')),
            symbolic_execute(False_statements, Flow)
        )
    ;   
     (
        ((True_statements = cmp_stmts([label_stmt(_, stmt(function_call(Exit, [int(_)])))]),
            se_name_atts__get(Exit, 'name', 'Exit')
            )
        ;
            (True_statements = cmp_stmts([stmt(function_call(Abort, []))]),
            se_name_atts__get(Abort, 'name', 'Abort')
            )
        ),
            !,   % added as if any of below fails, induces uncessariry backtracking above
        se_coverage__bran_is_already_covered(branch(Id, 'true')),  %costly so left at the end
        se_coverage__bran_newly_covered([])   %this is probably the most costly check: leave it last [unsound if commented out]
     ) ->
        (%until we have a CFG
         %nothing new covered so far, true branch is already covered and leads to exit or abort so we skip the true branch and only try the false branch
         %mytrace,
         ptc_solver__sdl(not(Condition_value)),
         se_globals__update_ref('current_path_bran', branch(Id, 'false')),
         symbolic_execute(False_statements, Flow)
        )
    ; 
        (random(2, R2), %i.e. between 0 and 2-1, so only 2 values allowed 0 or 1
            (R2 == 0 -> %randomness to ensure true and false branches are given equal chances
                (
                    (%super_util__quick_dev_info("Trying branch: %w", [branch(Id, 'true')]),
                    %mytrace,
                     ptc_solver__sdl(Condition_value),
                     se_globals__update_ref('current_path_bran', branch(Id, 'true')),
                     symbolic_execute(True_statements, Flow)
                    )
                ;% if statement deliberate choice point
                    (%super_util__quick_dev_info("Trying branch: %w", [branch(Id, 'false')]),
                     ptc_solver__sdl(not(Condition_value)),
                     se_globals__update_ref('current_path_bran', branch(Id, 'false')),
                     symbolic_execute(False_statements, Flow)
                    )
                )
            ;
                (
                    (ptc_solver__sdl(not(Condition_value)),
                     se_globals__update_ref('current_path_bran', branch(Id, 'false')),
                     symbolic_execute(False_statements, Flow)
                    )
                ;%if statement deliberate choice point
                    (ptc_solver__sdl(Condition_value),
                     se_globals__update_ref('current_path_bran', branch(Id, 'true')),
                     symbolic_execute(True_statements, Flow)
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
    symbolically_interpret(Condition, symb(_, Condition_value)),
    (Condition_value == 1   ->
        (se_globals__update_ref('current_path_bran', branch(Id, 'true')),
         symbolic_execute(Statements, Inner_flow), 
         (Inner_flow == 'carry_on' ->
           symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow)
         ;
           Flow = Inner_flow
         )
        )
    ;
     Condition_value == 0   ->
        (se_globals__update_ref('current_path_bran', branch(Id, 'false')),
         Flow = 'carry_on'  %loop exits
        )
    ;    
        (
            (ptc_solver__sdl(Condition_value),
             se_globals__update_ref('current_path_bran', branch(Id, 'true')),
             symbolic_execute(Statements, Inner_flow), 
             (Inner_flow == 'carry_on' ->
                symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow)
             ;
                Flow = Inner_flow
             )
            )
        ;%while loop deliberate choice point
            (ptc_solver__sdl(not(Condition_value)),
             se_globals__update_ref('current_path_bran', branch(Id, 'false')),
             Flow = 'carry_on'  %loop exits
            )
        )
    ).
symbolic_execute(label_stmt(_Label, Statement), Flow) :- 
    !,
    symbolic_execute(Statement, Flow).
symbolic_execute(return_stmt(Expression), return(Expression)) :-    %will be handled in post function call by checking Flow
    !.  %todo it would make more sense to symbolically execute expression here rather than outside: more logical
symbolic_execute(return_stmt, return) :-    %a return with no expression
    %mytrace,
    !.
symbolic_execute(postfix_inc_op(Expression), 'carry_on') :-
    !,
    symbolically_interpret(postfix_inc_op(Expression), _).  %this is a statement: we don't care about its evaluation
symbolic_execute(postfix_dec_op(Expression), 'carry_on') :-
    !,
    symbolically_interpret(postfix_dec_op(Expression), _).  %this is a statement: we don't care about its evaluation    
symbolic_execute(Unknown_statement, _) :-
    !,
    common_util__error(10, "Unexpected statement", "Could not possibly continue", [('Unknown_statement', Unknown_statement)], '10_150824_2', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
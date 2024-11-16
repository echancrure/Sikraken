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
        (memberchk('extern', Declaration_specifiers) ->  %(need to use memberchk because 'extern' does not necessarily come first) found an extern function declaration
            (subtract(Declaration_specifiers, ['extern'], Other_specifiers),
             extract_type(Other_specifiers, Return_type_name),
             se_sub_atts__create(Return_type_name, Parameters, 'no_body_is_extern', Function_name)
            )
        ;
         (se_name_atts__get(Function_name, 'name', Inner_name), is_verifier_input_function(Inner_name, _)) -> %some testcomp benchmarks do not declare the verifier functions as extern; as a hack we declare them here
            (extract_type(Declaration_specifiers, Return_type_name),
             se_sub_atts__create(Return_type_name, Parameters, 'no_body_is_extern', Function_name)
            )
        ; 
            true    %we ignore all other, non-extern, forward function declarations: they will be declared later
        )
    ;
        (Declaration_specifiers = [Specifier|Rest_declaration_specifiers], Specifier == 'typedef') ->
            (extract_type(Rest_declaration_specifiers, Type_name),
             declare_typedefs(Declarators, Type_name)
            )
    ;
        (%variable declarations
         extract_type(Declaration_specifiers, Type_name),
         declare_declarators(Declarators, Type_name)
        )
    ).
%e.g. a struct declaration without variables declarations  e.g. declaration([struct(point, [struct_decl([int], [X, Y, Z, T]), struct_decl([float], [Weight])])]), 
symbolic_execute(declaration(Declaration_specifiers), 'carry_on') :-
    extract_type(Declaration_specifiers, _Type_name).
symbolic_execute(function(Specifiers, function(Function_name, Parameters), [], Compound_statement), 'carry_on') :-
    !,
    extract_type(Specifiers, Return_type_name),
    se_sub_atts__create(Return_type_name, Parameters, Compound_statement, Function_name).
symbolic_execute(cmp_stmts(Stmts), Flow) :-
    !,
    se_globals__push_scope_stack,
    symbolic_execute(Stmts, Flow),
    se_globals__pop_scope_stack.
symbolic_execute(stmt(Expression_statement), Flow) :-   %could be an assignment statement, comma_op positfix_inc_op etc. anything really
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
            (common_util__error(9, "Unexpected derefed expression", "Sikraken's logic is wrong", [('Symbolic_LValue_ptr', Symbolic_LValue_ptr)], '9_030824', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info),
             Flow = 'carry_on'
            )
         )
        )
    ;
        (common_util__error(9, "Unexpected LValue", "Sikraken's logic is wrong", [('LValue', LValue)], '9_030824_2', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info),
         Flow = 'carry_on'
        )
    ).
symbolic_execute(function_call(Function, Arguments), 'carry_on') :- %as a statement
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
     (  %until we have a CFG: this is quick hack easy to check that should be generalised based on what covered to date and potential successors
        (True_statements = cmp_stmts([label_stmt(_, stmt(function_call(Exit, [int(_)])))]),
            se_name_atts__get(Exit, 'name', 'Exit')
        )
     ;%just or
        (True_statements = cmp_stmts([stmt(function_call(Abort, []))]),
            se_name_atts__get(Abort, 'name', 'Abort')
        )
     ) ->
        ((se_coverage__bran_is_already_covered(branch(Id, 'true')),  %costly so left at the end
          se_coverage__bran_newly_covered([])   %this is probably the most costly check: leave it last [unsound if commented out]
         ) ->
            traverse(not(Condition_value), branch(Id, 'false'), False_statements, Flow) % nothing new covered so far, true branch is already covered and leads to exit or abort so we skip the true branch and only try the false branch
            %if the above fails no point carrying with true branch: it exits with nothing new covered            
        ;
            (%mytrace,
             %either labeling succeeded and a testinput was generated, and everything that was to be covered has now been covered
             (traverse(Condition_value, branch(Id, 'true'), True_statements, Flow) %something new has been covered and we can exit right now
                   %we could return to the top-level (using Flow) as the logic implies but bit of a waste of a path: let's try to go back up and discovered something new
                %but it would be waste of time trying the false branch here directly (it may be tried anyway on subsequent execution now that this arc has been covered and exits
             ;
                (%labeling failed, exit was not taken
                 traverse(not(Condition_value), branch(Id, 'false'), False_statements, Flow)
                )
             )
            )
        )
    ;     
     (random(2, R2),
        (R2 == 0 ->
            (
                traverse(Condition_value, branch(Id, 'true'), True_statements, Flow)
            ;%if statement deliberate choice point
                traverse(not(Condition_value), branch(Id, 'false'), False_statements, Flow)
            )
        ;
            (
                traverse(not(Condition_value), branch(Id, 'false'), False_statements, Flow)
            ;%if statement deliberate choice point
                traverse(Condition_value, branch(Id, 'true'), True_statements, Flow)
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
          Inner_flow == 'break' ->  %terminates this while statement
            Flow = 'carry_on'
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
        (random(2, R2), %i.e. between 0 and 2-1, so only 2 values allowed 0 or 1
         (R2 == 0 -> %randomness to ensure true and false branches are given equal chances
            (
                (traverse(Condition_value, branch(Id, 'true'), Statements, Inner_flow),
                 (Inner_flow == 'carry_on' ->
                    symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow)
                 ;
                  Inner_flow == 'break' ->  %terminates this while statement
                    Flow = 'carry_on'
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
        ;
            (
                (ptc_solver__sdl(not(Condition_value)),
                 se_globals__update_ref('current_path_bran', branch(Id, 'false')),
                 Flow = 'carry_on'  %loop exits
                )
            ;%while loop deliberate choice point
                (traverse(Condition_value, branch(Id, 'true'), Statements, Inner_flow),
                 (Inner_flow == 'carry_on' ->
                    symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow)
                 ;
                  Inner_flow == 'break' ->  %terminates this while statement
                    Flow = 'carry_on'
                 ; 
                    Flow = Inner_flow
                 )
                )
            )
         )
        )
    ).
symbolic_execute(label_stmt(_Label, Statement), Flow) :- 
    !,
    symbolic_execute(Statement, Flow).
symbolic_execute(return_stmt(Expression), return(Expression)) :-    %will be handled in post function call by checking Flow
    !.  %todo it would make more sense to symbolically execute expression here rather than outside: more logical
symbolic_execute(return_stmt, return) :-    %a return with no expression
    !.
symbolic_execute(break_stmt, 'break') :-    %within iteration and switch statements: basically bubble up to the innermost construct
    !.
%we have anything here: an assignment, comma_op, postfix_inc_op, postfix_dec_op or any expression!
symbolic_execute(Expression, 'carry_on') :- %assuming that there is no return in there...
    !,
    symbolically_interpret(Expression, _).  %this is a statement: we don't care about its evaluation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
traverse(Condition, Arc, Statements, Flow) :-
    ptc_solver__sdl(Condition),
    se_globals__update_ref('current_path_bran', Arc),
    symbolic_execute(Statements, Flow).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
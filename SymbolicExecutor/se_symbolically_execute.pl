%The second argument of symbolic_execute/2 is an indication of the control flow.
%  it can have the following values : 'carry_on'|break|continue|return(expression)|return
%  All exits (exit, abort, assert_fail) are handled by labeling and test input generation in symbolically_interpret/2: symbolic execution backtracks (so we never have to handle exits as a Flow explicitly here) 
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
symbolic_execute(declaration(spec([typedef], Type_spec), Declarators), 'carry_on') :-
    !,
    extract_type(spec([], Type_spec), Type_name),
    declare_typedefs(Declarators, Type_name).   %single use, defined at the bottom
symbolic_execute(declaration(Declaration_specifiers, Declarators), 'carry_on') :-
    !,
    ((Declarators = [Declarator], nonvar(Declarator), 
      (Declarator = function(_Function_name, _Parameters) ; (Declarator = ptr_decl(pointer, Function), nonvar(Function), Function = function(_Function_name, _Parameters)))
     ) ->  %a function forward declaration
        (true   %all functions are declared before CFG building and symbolic execution        
        )
    ;
        (%variable declarations
         extract_type(Declaration_specifiers, Type_name),
         declare_declarators(Declarators, Type_name)
        )
    ).
%e.g. a declaration without variables declarations can be a struct type declaration e.g. declaration([struct(point, [struct_decl([int], [X, Y, Z, T]), struct_decl([float], [Weight])])])
% a union or an enum declaration
symbolic_execute(declaration(Declaration_specifiers), 'carry_on') :-
    !,
    extract_type(Declaration_specifiers, _Type).
symbolic_execute(function(_Specifiers, function(_Function_name, _Parameters), [], _Compound_statement), 'carry_on') :-
    !,
    true. %functions are declared before CFG building and symbolic execution    
symbolic_execute(function(_Specifiers, ptr_decl(pointer, function(_Function_name, _Parameters)), [], _Compound_statement), 'carry_on') :-
    !,
    true. %functions are declared before CFG building and symbolic execution  
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
         seav__update(LValue, 'output', Casted)
        )
    ;
     LValue = deref(LValue_ptr) ->
        (symbolically_interpret(LValue_ptr, symb(_, Symbolic_LValue_ptr)),
         (Symbolic_LValue_ptr = addr(New_LValue) ->
            symbolic_execute(assign(New_LValue, Expression), Flow)
         ;
            common_util__error(9, "Unexpected derefed expression", "Sikraken's logic is wrong", [('Symbolic_LValue_ptr', Symbolic_LValue_ptr)], '9_030824', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info)
         )
        )
    ;
     LValue = index(Array_exp, Index_exp) ->    %array element assignment e.g. b[0] = 12;
        (symbolically_interpret(Array_exp, symb(_, Array_value)),
         symbolically_interpret(Index_exp, symb(_, Index_value)),
         symbolically_interpret(Expression, symb(_, Expression_value)), %casting ? do it here or in solver?
         ptc_solver__arithmetic(up_arr(Array_value, [Index_value], Expression_value), New_array, _),
         seav__update(Array_exp, 'output', New_array)   %will not work is Array_exp is an expression e.g. a function call or anything that returns an array [remember in Mika we had a way to make this work]
        )
    ;
    LValue = select(Struct_exp, Field) ->   %struct field assignment e.g. p.x = 12;
        (seav__is_seav(Struct_exp) ->
            (symbolically_interpret(Struct_exp, symb(_, Struct_value)),
             symbolically_interpret(Expression, symb(_, Expression_value)), %casting ? do it here or in solver?
             ptc_solver__up_record(Struct_value, Field, Expression_value, New_struct),
             seav__update(Struct_exp, 'output', New_struct)
            )
        ;
         Struct_exp = index(Array_exp, Index_exp) -> % e.g. a[i].n = Expression becomes a[i] = up_rec(a[i], n, Expression)
            (%todo optimise and make sounder unique call to index(Array_exp, Index_exp) ?
             %mytrace,
             symbolic_execute(assign(index(Array_exp, Index_exp), up_rec(index(Array_exp, Index_exp), Field, Expression)), Flow)
            )
        ;
            common_util__error(9, "Unexpected LValue inselect", "Sikraken's logic is wrong", [('LValue', LValue)], '9_091224_1', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info)
        )
    ;
        common_util__error(9, "Unexpected LValue", "Sikraken's logic is wrong", [('LValue', LValue)], '9_030824_2', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info)
    ),
    Flow = 'carry_on'.
%basic handling of assignment operators (10 of them)
%wasteful: LValue is symbolically interpreted twice
%unsound: if LValue, somehow, has side-effects (e.g. it is a method call that returns a pointer)
symbolic_execute(mul_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, multiply_op(LValue, Expression)), Flow).
symbolic_execute(div_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, div_op(LValue, Expression)), Flow).
symbolic_execute(mod_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, mod_op(LValue, Expression)), Flow).
symbolic_execute(add_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, plus_op(LValue, Expression)), Flow).
symbolic_execute(sub_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, minus_op(LValue, Expression)), Flow).
symbolic_execute(left_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, bitwise(left_shift, LValue, Expression)), Flow).
symbolic_execute(right_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, bitwise(right_shift, LValue, Expression)), Flow).
symbolic_execute(and_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, bitwise(bw_and, LValue, Expression)), Flow).
symbolic_execute(xor_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, bitwise(bw_xor, LValue, Expression)), Flow).
symbolic_execute(or_assign(LValue, Expression), Flow) :-
    !,
    symbolic_execute(assign(LValue, bitwise(bw_or, LValue, Expression)), Flow).
%%%
symbolic_execute(function_call(Function, Arguments), 'carry_on') :-     %as a statement
    !,
    symbolically_interpret(function_call(Function, Arguments), _Symbolic_expression).   %todo ok for exit and abort but not if it has a non-void return

symbolic_execute(if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
    !,
    make_decision(Condition, Id, Outcome),
    (Outcome == 'true' ->
        symbolic_execute(True_statements, Flow)
    ;
        symbolic_execute(False_statements, Flow)
    ).
symbolic_execute(else_if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
    !,
    make_decision(Condition, Id, Outcome),
    (Outcome == 'true' ->
        symbolic_execute(True_statements, Flow)
    ;
        symbolic_execute(False_statements, Flow)
    ).

symbolic_execute(if_stmt(Branch, True_statements), Flow) :-
    !,
    symbolic_execute(if_stmt(Branch, True_statements, []), Flow).
symbolic_execute(else_if_stmt(Branch, True_statements), Flow) :-
    !,
    symbolic_execute(else_if_stmt(Branch, True_statements, []), Flow).

symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow) :-
    !,
    make_decision(Condition, Id, Outcome),
    (Outcome == 'true' ->
        (symbolic_execute(Statements, Inner_flow), 
         ((Inner_flow == 'carry_on' ; Inner_flow == 'continue') ->
            symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow)
         ;
          Inner_flow == 'break' ->  %exits from this while loop
            Flow = 'carry_on'
         ;
            Flow = Inner_flow       %i.e. return(expression)|return
         )
        )
    ;
        Flow = 'carry_on'           %exits from this while loop
    ).
    
symbolic_execute(do_while_stmt(Statements, branch(Id, Condition)), Flow) :-
    !,
    symbolic_execute(Statements, Inner_flow), 
    ((Inner_flow == 'carry_on' ; Inner_flow == 'continue') ->
        (make_decision(Condition, Id, Outcome),
         (Outcome == 'true' ->
            symbolic_execute(do_while_stmt(Statements, branch(Id, Condition)), Flow)
         ;
            Flow = 'carry_on'   %exits this do while loop
         )
        )
    ;
     Inner_flow == 'break' ->   %exit this do while loop
        Flow = 'carry_on'
    ;
        Flow = Inner_flow       %i.e. return|return(expression)
    ).
symbolic_execute(switch_stmt(branch(Id, Expression), Statements), Flow) :-
    !,
    mytrace,
    make_decision(int(1), Id, _Outcome), %we do not care about the outcome: set to true for reaching the switch node
    symbolically_interpret(Expression, Symbolic_expression),
    symbolic_execute(Statements, Flow), %this will have to change to handles case statements: the symbolic expression needs to be passsed on
    (Flow == 'break' ->
        Flow = 'carry_on'   %exit from switch statement
    ;
        true    %i.e. 'carry_on'|return(expression)|return
    ),
    common_util__error(0, "Warning: switch statements are under development", 'no_error_consequences', [], '0_060825_8', 'se_symbolically_execute', 'symbolic_execute', no_localisation, no_extra_info).
symbolic_execute(case_stmt(branch(_Id, Case_expression), Statements), Flow) :-
    !,
    symbolically_interpret(Case_expression, Case_symbolic_expression),
    %mytrace,
    %we should compare Case_symbolic_expression with the switch expression symbolic value
    symbolic_execute(Statements, Flow).
symbolic_execute(default_stmt(branch(_Id), Statements), Flow) :-
    !,
    symbolic_execute(Statements, Flow).
symbolic_execute(goto_stmt(Label, Function), Flow) :-
    !,
    se_sub_atts__get(Function, 'body', cmp_stmts(Function_stmts)),
    search_label_statement(Label, Function_stmts, Labelled_stmts_list), %only partially implemented
    symbolic_execute(Labelled_stmts_list, Flow).    
symbolic_execute(label_stmt(_Label, Statement), Flow) :- 
    !,
    symbolic_execute(Statement, Flow).
symbolic_execute(return_stmt(Expression), return(Symbolic_expression)) :-    %will be handled in post function call by checking Flow
    !,
    symbolically_interpret(Expression, Symbolic_expression).
symbolic_execute(return_stmt, return) :-    %a return with no expression
    !.
symbolic_execute(break_stmt, 'break') :-    %within iteration and switch statements: basically bubble up to the innermost construct
    !.
symbolic_execute(continue_stmt, 'continue') :-
    !. 
%we have anything here: an assignment, comma_op, postfix_inc_op, postfix_dec_op or any expression!
symbolic_execute(Expression, 'carry_on') :- %assuming that there is no return in there...
    !,
    symbolically_interpret(Expression, _).  %this is a statement: we don't care about its evaluation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    declare_typedefs([], _).
    declare_typedefs([Typedef|R], Type_name) :-
        extract_pointers(Typedef, Type_name, Type_name_ptr_opt, Clean_typedef_var),
        ((nonvar(Clean_typedef_var), Clean_typedef_var = function(Function_name, Parameters)) -> %handles pointers to functions 20/05/2025
            (se_sub_atts__create(Type_name_ptr_opt, Parameters, 'no_body_is_typedef', Anonymous_function), %because the typedef could be a pointer to a function see operations operation_gn and operation_fn in check_global_typedefs.c regression test 
             extract_pointers(Function_name, Anonymous_function, Typedef_ptr_opt, Typedef_name)
            )
        ;
            (Typedef_ptr_opt = Type_name_ptr_opt,
             Typedef_name = Clean_typedef_var
            )
        ), 
        se_typedef_atts__create(Typedef_ptr_opt, Typedef_name),
        declare_typedefs(R, Type_name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
traverse(Condition, Arc, Statements, Flow) :-
    ptc_solver__sdl(Condition),
    se_globals__update_ref('current_path_bran', Arc),
    symbolic_execute(Statements, Flow).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
force(Condition, Id, Truth, Statements, Flow) :-
    (Truth == 'true' ->
        symbolically_interpret(Condition, symb(_, 1))
    ;
        symbolically_interpret(Condition, symb(_, 0))
    ),
    se_globals__update_ref('current_path_bran', bran(Id, Truth)),
    symbolic_execute(Statements, Flow).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
make_decision(Condition, Id, Outcome) :-
    %mytrace,
    %different approach possible here: forcing or not see diary 23/09/25
    symbolically_interpret(Condition, symb(_, Cond_Symbolic)),  %leaves choice points behind because decisions are made there too (not pure delay)
    %will need redone if we want to guide the search (Cf. Mika? with combinations generated?)
    (Cond_Symbolic == 1 ->  %always true: no choice
        Outcome = 'true'
    ;
     Cond_Symbolic == 0 ->  %always false: no choice
        Outcome = 'false'
    ;
        (random(2, 0) -> %i.e. between 0 and 2-1, so only 2 values allowed 0 or 1
            (
                (ptc_solver__sdl(Cond_Symbolic),
                 Outcome = 'true'
                )
            ;%deliberate choice point
                (ptc_solver__sdl(not(Cond_Symbolic)),
                 Outcome = 'false'
                )
            )
         ;
            (
                (ptc_solver__sdl(not(Cond_Symbolic)),
                 Outcome = 'false'
                )
            ;%deliberate choice point
                (ptc_solver__sdl(Cond_Symbolic),
                 Outcome = 'true'
                )
            )
        )
    ),
    Branch = bran(Id, Outcome),
    %mytrace,
    (ghost(Id, _, Outcome) ->   %performance hit
        true    %ignored, not added to subpath
    ;
        (se_globals__update_ref('current_path_bran', Branch),
         (se_globals__get_val('shortcut_gen', true) ->  %shortcut generation
            (cfg_main__bran_is_already_covered(Branch) ->
                true    %already covered, we carry on
            ;
             setval(shortcut_gen_triggered, 'true') ->  %the test vector has already been generated
                super_util__quick_dev_info("Following next new branch in shortcut mode: %w", [Branch])
            ;
                (%Branch is new: it has never been covered and we are not in a shortcut_gen_triggered subpath
                 se_globals__get_ref('verifier_inputs', Verifier_inputs),
                 (call(label_testcomp(Verifier_inputs, Labeled_inputs)) @ eclipse ->  %"bank": we try to label what we have so far
                    (%of course, doing that, restrict the possible future because the variables become grounded: it leads to more incomplete test vectors
                     se_globals__get_val('path_nb', Previous_test_nb),
                     Test_nb is Previous_test_nb + 1,   %but we do not set this new value: it will be done when the next verifier is encountered and the full subpath is recorded
                     print_test_inputs_testcomp(Labeled_inputs, Test_nb),  %we generate the partial test vector early, to ensure completeness, the full subpath later is done at the next verifier encounter                    
                     super_util__quick_dev_info("Following first new branch in shortcut mode: %w", [Branch]),
                     setval(shortcut_gen_triggered, 'true') %and we continue until end of path or next __VERIFIER_input call to continue recording new branches covered
                    )
                 ;
                    fail  %labeling failed...no test input vector was generated, we abandon this subpath
                 )
                )
            )
         ;
            true    %continue exploring this path
         )   
        )
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
search_label_statement(Label, Stmts, Labelled_stmts_list) :-
    mytrace,
    find_label(Stmts, Label, Labelled_stmts_list),
    !,  %C rule ensures only one possible
    (Labelled_stmts_list = [] ->
        common_util__error(9, "Labeled statement not found", "gotos to non-outer statement, that are not if statements, are unhandled", [('Label', Label)], '09_221025_1', 'se_symbolically_execute', 'search_label_statement', no_localisation, no_extra_info)
    ;
        true
    ).
    %%%
    find_label(All_stmts, Label, Labelled_stmts_list) :-
        ((is_list(All_stmts), append(_, [label_stmt(Label, Stmt)|Rest], All_stmts)) ->  %the label is an outer statement: easy
            Labelled_stmts_list = [label_stmt(Label, Stmt)|Rest]   %simple case: matches outer labeled statement
        ;
            find_label_compound(All_stmts, Label, Labelled_stmts_list)
        ).
    find_label_compound([], _, _) :-    
        fail.
    find_label_compound([Statement|Rest], Label, Labelled_stmts_list) :-    %a list of statements
        !,
        (find_label_compound(Statement, Label, Inner_labelled_stmts_list) ->
            append(Inner_labelled_stmts_list, Rest, Labelled_stmts_list)    %we found the labeled statement
        ;
            find_label_compound(Rest, Label, Labelled_stmts_list)   %continue the search
        ).
    find_label_compound(cmp_stmts(Stmts), Label, Labelled_stmts_list) :-
        !,
        find_label(Stmts, Label, Labelled_stmts_list).
    find_label_compound(if_stmt(_, True_statements), Label, Labelled_stmts_list) :-
        !,
        find_label(True_statements, Label, Labelled_stmts_list).
    find_label_compound(if_stmt(_, True_statements, False_statements), Label, Labelled_stmts_list) :-
        !,
        (   find_label(True_statements, Label, Labelled_stmts_list)
        ;%deliberate choice point
            find_label(False_statements, Label, Labelled_stmts_list)
        ),
        !.
    find_label_compound(_, _Label, _Labelled_stmts_list) :-   %default for non compound statements e.g. assign, function call etc. 
        !,  %will also fail for non handled statements: while loop, switch etc.
        fail.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
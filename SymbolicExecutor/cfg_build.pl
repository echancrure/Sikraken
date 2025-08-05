%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                 Copyright 2025 SETU - Dr Christophe Meudec 
%%                                     <https://github.com/echancrure/Sikraken>
%% This file is part of Sikraken.
%% Sikraken is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
%%   the Free Software Foundation.
%% Sikraken is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
%%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
%% GNU Lesser General Public License v3.0 only
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Contains the predicate to create the CFG by covering the entire code under test
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- dynamic cfg_branch/3.                    %dynamic predicate to store the CFG's branches: cfg_branch(From, Truth_value, To)
:- local reference(current_node, start).          %the current node id during CFG building
:- local reference(current_truth_value, true).    %the current truth value during CFG building
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cfg_build__init :-  %necessary initialisations during development to start from a clean empty CFG
    retractall(cfg_branch(_, _, _)).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Build the CFG of the code under test
cfg_build__build_cfg(Parsed_prolog_code, Function_name) :-
    init(Function_name),
    (cover(Parsed_prolog_code, _Flow) *->      %'soft-cut' to enumerate all choice points in cover
        create_branch(end(Function_name))
    ;
        common_util__error(10, "Fatal error in cover/1", "Failed without leaving a choice point: Should never happen", [], '10_010825_1', 'se_main', 'cfg_build__build_cfg', no_localisation, no_extra_info)
    ),
    fail.   %induces bactracking within cover/1
cfg_build__build_cfg(_, Function_name) :-
    !,
    setref(current_node, end(Function_name)),
    true.   %build successors etc.
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    init(Function_name) :-  
        setref(current_node, start(Function_name)),
        setref(current_truth_value, true).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %cover/2 has the same heads as symbolic_execute/2: it handles the entire C language focusing on building the CFG only
    %the second argument is the Flow: it can have the following values : carry_on|break|continue|exit|return(expression)
    cover([], 'carry_on') :-
    !.
    cover([Item|R], Flow) :-
    !,
    cover(Item, Inner_flow),
    (Inner_flow == 'carry_on' ->
        symbolic_execute(R, Flow)
    ;
        Flow = Inner_flow
    ).
    cover(mytrace, 'carry_on') :-
        !.
    cover(declaration(spec([typedef], Type_spec), Declarators), 'carry_on') :-
        !.  %ignored: cannot impact coverage as a typedef cannot contain initialisers
    cover(declaration(Declaration_specifiers, Declarators), 'carry_on') :-
    !,
        ((Declarators = [Declarator], nonvar(Declarator), 
        (Declarator = function(_Function_name, _Parameters) ; (Declarator = ptr_decl(pointer, Function), nonvar(Function), Function = function(_Function_name, _Parameters)))
        ) ->  %a function forward declaration
            (true   %ignored: cannot impact coverage     
            )
        ;
            (%variable declarations
             cover_decl(Declarators)
            )
        ).
    %e.g. a declaration without variables declarations can be a struct type declaration e.g. declaration([struct(point, [struct_decl([int], [X, Y, Z, T]), struct_decl([float], [Weight])])])
    % a union or an enum declaration
    cover(declaration(Declaration_specifiers), 'carry_on') :-
        !.
    cover(function(_Specifiers, function(Function, _Parameters), [], Compound_statement), 'carry_on') :-
        !,
        (se_sub_atts__is_sub_atts(Function) ->
            (se_name_atts__get(Function, 'name', Function_name),
             cfg_build__build_cfg(Compound_statement, Function_name)
            ) 
        ;
            common_util__error(10, "Fatal error in cover/2", "A function has not been declared as a se_sub_atts: Should never happen", [], '10_020825_1', 'se_main', 'cover', no_localisation, no_extra_info)
        ).
        YOU ARE HERE
symbolic_execute(function(_Specifiers, ptr_decl(pointer, function(_Function_name, _Parameters)), [], _Compound_statement), 'carry_on') :-
    !,
    true. %functions are declared before CFG building and symbolic execution  
symbolic_execute(goto_stmt(Label, Function), Flow) :-
    !,
    %mytrace,
    se_sub_atts__get(Function, 'body', cmp_stmts(Stmts)),
    search_label_statement(Label, Stmts, Stmt_list),
    symbolic_execute(Stmt_list, Flow).
symbolic_execute(label_stmt(_Label, Stmt), Flow) :-
    !,
    symbolic_execute(Stmt, Flow).
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
        ;%could also be a function call (?) returning a record todo
            
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
symbolic_execute(function_call(Function, Arguments), 'carry_on') :- %as a statement
    !,
    symbolically_interpret(function_call(Function, Arguments), _Symbolic_expression).   %todo ok for exit and abort but not is it has a non-void return

symbolic_execute(if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
    !,
/*    
    %(Id == 155 -> mytrace ; true),
    mytrace,
    ((  %until we have a CFG: this is quick hack easy to check that should be generalised based on what covered to date and potential successors
        (True_statements = cmp_stmts([label_stmt(_, stmt(function_call(Exit, [int(_)])))]),
         se_name_atts__get(Exit, 'name', 'Exit')
        )
     ;%just or
        (True_statements = cmp_stmts([stmt(function_call(Abort, []))]),
         se_name_atts__get(Abort, 'name', 'Abort')
        )
%     ;%just or
%        True_statements = return_stmt(_)    %another opportunity to exit early
%     ;%just or
%        True_statements = cmp_stmts([return_stmt(_)])   %another opportunity to exit early
     ) ->
        (not cfg_main__bran_newly_covered([]) -> %something new has been covered so far
            (
                force(Condition, Id, 'true', True_statements, Flow)     %exit early
            ;
                force(Condition, Id, 'false', False_statements, Flow)    %allow continue as may lead to something new
            )
        %;
        % cfg_main__bran_is_already_covered(branch(Id, 'true')) ->    %nothing new and true already covered and will exit if taken
        %    force(Condition, Id, 'false', False_statements, Flow)       %only option is to try the false branch
        ;   %nothing new
            (random(2, 0) ->
                (
                    force(Condition, Id, 'true', True_statements, Flow)
                ;%deliberate choice point
                    force(Condition, Id, 'false', False_statements, Flow)
                )
            ;
                (
                    force(Condition, Id, 'false', False_statements, Flow)
                ;%deliberate choice point
                    force(Condition, Id, 'true', True_statements, Flow)
                )
            )
        )
     ;
     */
        (random(2, 0) ->    %repeated code is unfortunate
            (
                force(Condition, Id, 'true', True_statements, Flow)
            ;%deliberate choice point
                force(Condition, Id, 'false', False_statements, Flow)
            )
        ;
            (
                force(Condition, Id, 'false', False_statements, Flow)
            ;%deliberate choice point
                force(Condition, Id, 'true', True_statements, Flow)
            )
        ).
    %).
/*
symbolic_execute(if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
    !,
    %(Id == 155 -> mytrace ; true),
    mytrace,
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
        ((cfg_main__bran_is_already_covered(branch(Id, 'true')),  %costly so left at the end
          cfg_main__bran_newly_covered([])   %this is probably the most costly check: leave it last [unsound if commented out]
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
*/

symbolic_execute(if_stmt(Branch, True_statements), Flow) :-
    !,
    symbolic_execute(if_stmt(Branch, True_statements, []), Flow).
%todo there is too much duplicated code in while loop handling: but I am afraid to break before Testcomp deadline
symbolic_execute(while_stmt(branch(Id, Condition), Statements), Flow) :-
    !,
    symbolically_interpret(Condition, symb(_, Condition_value)),
    (Condition_value == 1   ->
        (se_globals__update_ref('current_path_bran', branch(Id, 'true')),
         symbolic_execute(Statements, Inner_flow), 
         ((Inner_flow == 'carry_on' ; Inner_flow == 'continue') ->
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
                 ((Inner_flow == 'carry_on' ; Inner_flow == 'continue') ->
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
                 ((Inner_flow == 'carry_on' ; Inner_flow == 'continue') ->
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
symbolic_execute(do_while_stmt(Statements, branch(Id, Condition)), Flow) :-
    symbolic_execute(Statements, Inner_flow), 
    ((Inner_flow == 'carry_on' ; Inner_flow == 'continue') ->
        (symbolically_interpret(Condition, symb(_, Condition_value)),
            (Condition_value == 1   ->
                (se_globals__update_ref('current_path_bran', branch(Id, 'true')),
                 symbolic_execute(do_while_stmt(Statements, branch(Id, Condition)), Flow)
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
                   (ptc_solver__sdl(Condition),
                    se_globals__update_ref('current_path_bran', branch(Id, 'true')),
                    symbolic_execute(do_while_stmt(Statements, branch(Id, Condition)), Flow)
                   )
                ;%do while loop deliberate choice point
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
                ;%do while loop deliberate choice point
                    (ptc_solver__sdl(Condition),
                     se_globals__update_ref('current_path_bran', branch(Id, 'true')),
                     symbolic_execute(do_while_stmt(Statements, branch(Id, Condition)), Flow)
                    )
                )
              )
             )
            )
        )
    ;
        Inner_flow == 'break' ->  %exit this loop
            Flow = 'carry_on'
    ;
        Flow = Inner_flow   %e.g. a goto, exit etc
    ).
symbolic_execute(label_stmt(_Label, Statement), Flow) :- 
    !,
    symbolic_execute(Statement, Flow).
symbolic_execute(return_stmt(Expression), return(Symbolic_expression)) :-    %will be handled in post function call by checking Flow
    !,
    symbolically_interpret(Expression, Symbolic_expression).
      %todo it would make more sense to symbolically execute expression here rather than outside: more logical
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
cover_exp(_). %todo
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    cover_decl([]).
    cover_decl([Declarator|Rest]) :-
        ((nonvar(Declarator), Declarator = initialised(_Direct_declarator, Initialiser)) ->
            cover_exp(Initialiser)
        ;
            true
        ),
        cover_decl(Rest)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    create_branch(To) :-
        getref(current_node, From),
		getref(current_truth_value, Truth),
		(cfg_branch(From, Truth, To) ->
            fail	%already exist: backtrack
		;
			(assert(cfg_branch(From, Truth, To)),
             setref(current_node, To)
            )
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
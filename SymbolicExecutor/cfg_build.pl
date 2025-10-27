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
:- dynamic edge/3.                    %dynamic predicate to store the CFG's branches: edge(From, To, Truth_value)
:- dynamic function_call/3.          %dynamic predicate to store the function calls in the CFG: function_call(From, To, Truth_value)
:- dynamic ghost/3.                  %dynamic predicate to store the jump branches in the CFG: ghost(From, To, Truth_value)
:- local reference(branch_nb, 1).    %the branch number counter
:- local reference(current_node, start).          %the current node id during CFG building
:- local reference(current_truth_value, true).    %the current truth value during CFG building
:- local reference(next_is_ghost_jump, false).    %used to create ghost jumps when needed: UGLY
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%necessary initialisations during development to start from a clean empty CFG
cfg_build__init :-  
    retractall(edge(_, _, _)),
    retractall(function_call(_, _, _)),
    retractall(ghost(_, _, _)).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Build the CFG of the code under test by asserting edge/3 facts
cfg_build__build_cfg(Parsed_prolog_code, Function_name) :-
    init(Function_name),
    %mytrace,
    (cover(Parsed_prolog_code, _Flow) *->      %'soft-cut' to enumerate all choice points in cover
        create_branch_to(end(Function_name))
    ;
        fail %common_util__error(10, "Fatal error in cover/1", "Failed without leaving a choice point: Should never happen", [], '10_010825_1', 'cfg_build', 'cfg_build__build_cfg', no_localisation, no_extra_info)
    ),
    fail.   %induces bactracking within cover/1
cfg_build__build_cfg(_, _Function_name) :-
    !.  %the CFG edges asserted facts have been created
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    init(Function_name) :-  
        setref(current_node, start(Function_name)),
        setref(current_truth_value, true).  %true is place holder here, it should be none 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Create the graph from asserted edge/3 facts: the resulting graph of the form graph(Nodes, Edges)
cfg_build__create_graph(graph(Nodes, Edges), FunctionCalls, Jumps) :-
    findall(edge(From, To, Label), edge(From, To, Label), Edges),
    %mytrace,
    findall(bran(From, Label), (member(edge(From, To, Label), Edges), integer(From)), All_pure_edges),  %removes all the edges starting by start(_)
    sort(All_pure_edges, All_pure_edges_sorted),
    length(All_pure_edges_sorted, EdgeCount),
    se_globals__set_val('EdgeCount', EdgeCount),
    se_globals__set_val('AllEdges', All_pure_edges_sorted),
    extract_nodes(Edges, AllNodes),
    sort(AllNodes, Nodes),      %removes duplicates
    findall(edge(From, To, none), function_call(From, To, _), FunctionCalls),
    findall(jump(From, To, Truth_value), ghost(From, To, Truth_value), Jumps).
    %%%
    extract_nodes([], []).
    extract_nodes([edge(From, To, _)|Rest], [From, To|Nodes]) :-
        extract_nodes(Rest, Nodes).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %cover/2 has the same heads as symbolic_execute/2: it handles the entire C language focusing on building the CFG only
    %the second argument is the Flow: it can have the following values : carry_on|break|continue|return
    % all exits (exit, abort, assert_fail) are handled by creating an arc to end('Main'): we then backtracks (so we never have to handle exits explicitly as a Flow) 
    cover([], 'carry_on') :-
        !.
    cover([Item|R], Flow) :-
        !,
        cover(Item, Inner_flow),
        (Inner_flow == 'carry_on' ->
            cover(R, Flow)
        ;
            Flow = Inner_flow   % break, continue and return are propagated upwards
        ).
    cover(mytrace, 'carry_on') :-
        !.
    cover(declaration(spec([typedef], _Type_spec), _Declarators), 'carry_on') :-
        !.  %ignored: cannot impact coverage as a typedef cannot contain initialisers
    cover(declaration(_Declaration_specifiers, Declarators), 'carry_on') :-
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
    cover(declaration(_Declaration_specifiers), 'carry_on') :-
        !.
    cover(function(_Specifiers, function(Function, _Parameters), [], Compound_statement), 'carry_on') :-
        !,
        (se_sub_atts__is_sub_atts(Function) ->
            (se_name_atts__get(Function, 'name', Function_name),
             cfg_build__build_cfg(Compound_statement, Function_name)
            ) 
        ;
            common_util__error(10, "Fatal error in cover/2", "A function declaration has not been declared as a se_sub_atts within cover: Should never happen", [], '10_020825_1', 'cfg_build', 'cover', no_localisation, no_extra_info)
        ).
    %todo check when this occurs (because pointers to functions don't have bodies so we should do nothing here)
    cover(function(_Specifiers, ptr_decl(pointer, function(_Function_name, _Parameters)), [], _Compound_statement), 'carry_on') :-
        !,
        common_util__error(0, "Warning in cover: check pointer to function", 'no_error_consequences', [], '0_060825_1', 'cfg_build', 'cover', no_localisation, no_extra_info).
    cover(label_stmt(_Label, _Stmt), 'carry_on') :-
        !,
        common_util__error(0, "Warning in cover: todo label_stmt", 'no_error_consequences', [], '0_060825_3', 'cfg_build', 'cover', no_localisation, no_extra_info).
    %symbolic_execute(Stmt, Flow).
    cover(cmp_stmts(Stmts), Flow) :-
        !,
        cover(Stmts, Flow).
    cover(stmt(Expression_statement), Flow) :-   %could be an assignment statement, comma_op positfix_inc_op, a function call etc. anything really
        !,
        cover(Expression_statement, Flow).
    cover(assign(LValue, Expression), 'carry_on') :-
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(mul_assign(LValue, Expression), 'carry_on') :-
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(div_assign(LValue, Expression), 'carry_on') :-  
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(mod_assign(LValue, Expression), 'carry_on') :-  
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(add_assign(LValue, Expression), 'carry_on') :-  
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(sub_assign(LValue, Expression), 'carry_on') :-  
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(left_assign(LValue, Expression), 'carry_on') :-         
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(right_assign(LValue, Expression), 'carry_on') :-                    
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(and_assign(LValue, Expression), 'carry_on') :-                      
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(xor_assign(LValue, Expression), 'carry_on') :-  
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(or_assign(LValue, Expression), 'carry_on') :-               
        !,
        cover_exp(LValue),
        cover_exp(Expression).
    cover(function_call(Function, Arguments), 'carry_on') :- %as a statement
        !,
        cover_exp(function_call(Function, Arguments)).  %exactly the same as a function call expression
    cover(if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
        !,
        cover_exp(Condition),
        create_branch_to(Id),
        (
            (setref(current_truth_value, true),
             cover(True_statements, Flow)
            )
        ;%deliberate choice point
            (setref(current_truth_value, false),
             cover(False_statements, Flow)
            )
        ).
    cover(else_if_stmt(branch(Id, Condition), True_statements, False_statements), Flow) :-
        !,%mytrace,
        cover_exp(Condition),
        create_ghost_branch(Id),    %dealing with fallthrough else if statements in TestCov by creating a ghost branch instead of a cfg edge
        setref(current_node, Id),
        (
            (setref(current_truth_value, true),
             cover(True_statements, Flow)
            )
        ;%deliberate choice point
            (setref(current_truth_value, false),
             cover(False_statements, Flow)
            )
        ).
    cover(if_stmt(Branch, True_statements), Flow) :-
        !,
        cover(if_stmt(Branch, True_statements, []), Flow).
    cover(else_if_stmt(Branch, True_statements), Flow) :-
        !,
        cover(else_if_stmt(Branch, True_statements, []), Flow).
    cover(while_stmt(branch(Id, Condition), Statements), Flow) :-
        !, 
        cover_exp(Condition),
        create_branch_to(Id),
        (
            (setref(current_truth_value, true),
             cover(Statements, Intermediate_flow),
             (( Intermediate_flow == 'carry_on' ; Intermediate_flow == 'continue' )->
                (create_branch_to(Id),         %creates the back edge to the while loop condition
                 fail   %odd but needed to force backtracking to explore the false branch of the while loop condition
                )
             ;
              Intermediate_flow == 'break' ->
                Flow = 'carry_on'          %the break is consumed here and the loop is exited
             ;
              Intermediate_flow == return ->
                Flow = 'return'            %the return is propagated upwards
             ;
                common_util__error(10, "Unhandled intermediate flow in while statement", "Cannot build CFG", [('Intermediate_flow', Intermediate_flow)], '10_071025', 'cfg_build', 'cover', no_localisation, no_extra_info)
             )
            )
        ;%deliberate choice point
            (setref(current_truth_value, false),
             Flow = 'carry_on'
            )
        ).
    cover(do_while_stmt(Statements, branch(Id, Condition)), Flow) :-
        !, mytrace,
        cover(Statements, Intermediate_flow), 
        (Intermediate_flow == 'break' ->
            Flow = 'carry_on'          %the break is consumed here and the loop is exited
        ;
         Intermediate_flow == return ->
            Flow = 'return'            %the return is propagated upwards and the loop is exited
        ;
         (Intermediate_flow == 'carry_on' ; Intermediate_flow == 'continue') ->
            (cover_exp(Condition),
             create_branch_to(Id),         %creates the edge to the condition
             (
                (%in Testcov do_while statements do not have a goal associated when the condition is true, so we need to create a ghost branch
                 setref(current_truth_value, true),
                 setref(next_is_ghost_jump, true),  %to create a ghost branch in create_branch_to/1
                 cover(do_while_stmt(Statements, branch(Id, Condition)), Flow) %odd but needed to force back edges when the condition is true: no infinite loop as create_branch_to fails on duplicates
                )
             ;%deliberate choice point
                (setref(current_truth_value, false),
                 Flow = 'carry_on'
                )
             )
            )
        ;
            common_util__error(10, "Unhandled intermediate flow in do_while statement", "Cannot build CFG", [('Intermediate_flow', Intermediate_flow)], '10_081025', 'cfg_build', 'cover', no_localisation, no_extra_info)
        ).
    cover(switch_stmt(branch(Id, Expression), Statements), Flow) :-
        !,
        mytrace,
        cover_exp(Expression),
        create_branch_to(Id),
        (Statements = cmp_stmts(Case_statements) -> 
            cover_outer_cases(Case_statements, Flow)       %Flow can only be carry_on, break or return [continue is not valid within a switch, and exit are dealt with separately]
        ;
            cover_outer_cases(Statements, Flow)       %single statement within the switch
        ).

    %covering a non-outer case statement, i.e a fallthrough from the previous case/default statement
    cover(case_stmt(branch(Id, _Expression), Statement), Flow) :-
        !,      %Expression can only be a constant expression: no need to cover it
        create_ghost_branch(Id),   %the jump from the switch to the case statement
        create_branch_to(Id),
        setref(current_truth_value, true),
        cover(Statement, Flow).
    cover(default_stmt(branch(Id), Statement), Flow) :- %within switch statements only
        !,
        cover(case_stmt(branch(Id, _Expression), Statement), Flow). %same coverage handling as for case statements
    cover(goto_stmt(_Label, _Function_name), 'carry_on') :-
        !,
        common_util__error(0, "Warning in cover: todo goto_stmt", 'no_error_consequences', [], '0_060825_2', 'cfg_build', 'cover', no_localisation, no_extra_info).
    %mytrace,
    %se_sub_atts__get(Function, 'body', cmp_stmts(Stmts)),
    %search_label_statement(Label, Stmts, Stmt_list),
    %symbolic_execute(Stmt_list, Flow).
    cover(label_stmt(_Label, Statement), Flow) :- 
        !,
        cover(Statement, Flow).
    cover(return_stmt(Expression), return) :-
        !,
        cover_exp(Expression).
    cover(return_stmt, return) :-
        !.
    cover(break_stmt, 'break') :-    %within iteration and switch statements: basically bubble up to the innermost construct
        !.
    cover(continue_stmt, 'continue') :-
        !. 
    cover(Expression, 'carry_on') :-    %we have anything here: comma_op, postfix_inc_op, postfix_dec_op or any expression!
        !,
        cover_exp(Expression).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    /*cover_outer_cases([], 'carry_on') :-  %end of the switch statement
        !.
        %only allow is no there is no default
    */
    cover_outer_cases([default_stmt(branch(Id), Statement)|Rest], Flow) :-  %does not have to be the last statement
        !,
        cover_outer_cases([case_stmt(branch(Id, _), Statement)|Rest], Flow).    %same handling as for case statements
    cover_outer_cases([case_stmt(branch(Id, _Expression), Statement)|Rest], Flow) :-
        !,
        (
            (create_ghost_branch(Id),   %the jump from the switch to the case statement
             setref(current_node, Id),
             setref(current_truth_value, true),
             cover([Statement|Rest], Intermediate_flow),  %Flow can only be carry_on, break or return [continue is not valid within a switch, and exit are dealt with separately]
             %here the full case statement and all its fallthroughs have been covered 
             (Intermediate_flow == 'break' ->       %Flow can only be carry_on or return [continue is not valid within a switch, and exit are dealt with separately]
                Flow = 'carry_on'                   %the break is consumed here and the switch is exited
             ;
              Intermediate_flow == return ->
                Flow = 'return'            %the return is propagated upwards and the switch is exited
             ;
              Intermediate_flow == 'carry_on' ->
                Flow = 'carry_on'          %normal exit from the switch statement
             )
            )
        ;%deliberate choice point
            (cover_outer_cases(Rest, Flow)   %cover the other outer cases
            )
        ).
    cover_outer_cases([_|Rest], Flow) :-
        !,
        cover_outer_cases(Rest, Flow).  %ignore any other statements within the switch statement 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    cover_exp(V) :-
        var(V),
        !.  %just a C variable: nothing to do
    cover_exp(A) :-
        atomic(A),
        !.  %a number, a field name, a string, a character constant, a boolean etc.: nothing to do
    cover_exp(function_call(Function, Arguments)) :- 
        !,
        (se_sub_atts__is_sub_atts(Function) ->
            se_name_atts__get(Function, 'name', Function_name),
            se_sub_atts__get(Function, 'body', Body),
            (Body == 'no_body_is_extern' -> %calling an extern function with no body
                (is_verifier_input_function(Function_name, _Type) ->
                    true    %ignored: verifier input function
                ;
                 (Function_name == 'Exit' ; Function_name == 'Abort' ; Function_name == 'UC___assert_fail') ->
                    create_branch_to(end('Main')),      %this is the end...
                    fail    %force backtrackting to explore other paths
                ;
                    common_util__error(9, "Function call to unknown external function", "Cannot perform CFG build", [('Function_name', Function_name)], '09_071025_2', 'cfg_build', 'cover_exp', no_localisation, no_extra_info)
                )
            ;
                (cover_exp(Arguments),
                 create_call_branch(start(Function_name))
                )
            )
        ;
            common_util__error(10, "Fatal error in cover_exp/1", "A function call has not been declared as a se_sub_atts in cover_exp: Should never happen", [], '10_071025_3', 'cfg_build', 'cover_exp', no_localisation, no_extra_info)
        ).
    cover_exp(cond_exp(branch(Id, Condition), True_expression, False_expression)) :-
        !,
        cover_exp(Condition),
        create_branch_to(Id),
        (
            (setref(current_truth_value, true),
             cover_exp(True_expression)
            )
        ;
            (setref(current_truth_value, false),
             cover_exp(False_expression)
            )
        ).
    cover_exp(Bin_exp) :-   %any other binary expressions including lists of any lengths [...], comma_op, plus_op, minus_op, mult_op, div_op, mod_op, left_shift_op, right_shift_op, and_op, xor_op, or_op
        Bin_exp =.. [_Functor, L, R],
        !,
        cover_exp(L),
        cover_exp(R).
    cover_exp(Una_exp) :-   %unary expressions including size_of_exp, size_of_type, stmt_exp, neg_op, plus_op, minus_op, not_op, deref_op, address_of_op
        Una_exp =.. [_Functor, Operand],
        !,
        cover_exp(Operand).
    cover_exp(Ter_exp) :-   %ternary expressions: including bitwise_op
        Ter_exp =.. [_Functor, First, Second, Third],
        !,
        cover_exp(First),
        cover_exp(Second),
        cover_exp(Third).
    cover_exp(Other) :-
        !,
        common_util__error(0, "Warning in cover_exp/1", "todo: cover_exp for other expressions", [('Other', Other)], '0_060825_4', 'cfg_build', 'cover_exp', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    cover_decl([]).
    cover_decl([Declarator|Rest]) :-
        ((nonvar(Declarator), Declarator = initialised(_Direct_declarator, Initialiser)) ->
            cover_exp(Initialiser)
        ;
            true
        ),
        cover_decl(Rest).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    create_branch_to(To) :-
        %mytrace,
        getref(current_node, From),
		getref(current_truth_value, Truth),
		(edge(From, To, Truth) ->
            fail	%already exist: don't create a new edge and backtrack: this part of the code has already been covered
		;
         ghost(From, To, Truth) ->
            fail	%already exist as a ghost edge: don't create a new edge and backtrack: this part of the code has already been covered
        ;
         getref(next_is_ghost_jump, true) ->
            (assert(ghost(From, To, Truth)),
             setref(next_is_ghost_jump, false)  %reset the flag
            )
        ;      
			assert(edge(From, To, Truth))
        ),
        setref(current_node, To).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    create_ghost_branch(To) :-  %creates a branch that is not taken into account for coverage purposes
        getref(current_node, From),
        getref(current_truth_value, Truth),
        (ghost(From, To, Truth) ->
            true	%already exist: don't create a new ghost edge
        ;
            assert(ghost(From, To, Truth))
        ).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Create a branch for a function call: this is a special branch
    % but we still use the same notation as for other branches in hope that analysis will be simpler
    create_call_branch(start(Function_name)) :-
        getref(current_node, From),
        getref(current_truth_value, Truth),
        (function_call(From, start(Function_name), Truth) ->
            true	%already exist: e.g. multiple calls to the same function
        ;
            assert(function_call(From, start(Function_name), Truth)) %but we do not change the current node
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
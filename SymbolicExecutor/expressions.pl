:- lib(ptc_solver).

:- use_module(c_var).

%% Evaluate a not expression (!). Failing if it is invalid, passing if it is valid.
%% 0 is false, anything else is true
evaluate_expression(not(Expression)) :-
    !,
    evaluate_expression(Expression, Expression_result),
    ptc_solver__sdl(not (Expression_result <> 0)).

%% Evaluate an expression. Failing if it is invalid, passing if it is valid.
%% 0 is false, anything else is true
evaluate_expression(Expression) :-
    evaluate_expression(Expression, Expression_result),
    ptc_solver__sdl(Expression_result <> 0).

%% Returns the expression if it is a singular c_var
evaluate_expression(Expression, Ptc_variable) :-
    var(Expression),
    c_var__get_out_var(Expression, Ptc_variable),
    !.

%% Returns a number-constant
%% Eg: 2
evaluate_expression(Expression, Expression) :-
    number(Expression),
    !.

%% The parser can mark expressions as expression_statements, such as in a for loop
%% Eg:
%%  for (i = 0; i < 10; i++)  becomes
%%  for (expression_statement(i = 0); i < 10; i++)
evaluate_expression(expression_statement(Expression), Expression_result) :-
    evaluate_expression(Expression, Expression_result).

%% And Operator (&&)
evaluate_expression(andop(Left, Right), Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result = 1 and_then Right_result = 1, Expression_result)).

%% Or Operator (||)
evaluate_expression(orop(Left, Right), Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result = 1 or_else Right_result = 1, Expression_result)).

%% Not Operator (!)
evaluate_expression(exclamation(Expression), Expression_result) :-
    evaluate_expression(Expression, Result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Result = 0, Expression_result)).

%% Modulo Operator (%)
evaluate_expression(mod(Left ,Right), Left_result mod Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Not Equal (!=)
evaluate_expression(Left<>Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result <> Right_result, Expression_result)).

%% Equal Boolean Operator (==)
evaluate_expression(Left==Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result = Right_result, Expression_result)).

%% Greater than Boolean Operator (>)
evaluate_expression(Left>Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result > Right_result, Expression_result)).

%% Greater than or equal Boolean Operator (>=)
evaluate_expression(Left>=Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result >= Right_result, Expression_result)).

%% Less than Boolean Operator (<)
evaluate_expression(Left<Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result < Right_result, Expression_result)).

%% Less than or equal Boolean Operator (<=)
evaluate_expression(Left<=Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result <= Right_result, Expression_result)).

%% Subtraction (Minus) Operator for two expressions (-)
evaluate_expression(Left-Right, Left_result-Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Addition Operator (+)
evaluate_expression(Left+Right, Left_result+Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Multiplication Operator for two expressions (*)
evaluate_expression(multiply(Left, Right), Left_result*Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Division Operator (/)
evaluate_expression(Left/Right, Left_result/Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Increment with ++ on the right side (Post-increment)
%% Eg: x++
evaluate_expression(post_increment(Assign_to, Increment_operation), Expression_result) :-
    (c_var__is_variable(Assign_to) ->
        c_var__get_out_var(Assign_to, Expression_result),
        c_var__get_type(Assign_to, Type)
    ;
        evaluate_expression(Assign_to, Expression_result)
    ),
    evaluate_expression(Increment_operation, Increment_operation_result),
    ptc_solver__variable([Temp], Type),
    ptc_solver__sdl(Temp = Increment_operation_result),
    c_var__set_out_var(Assign_to, Temp).

%% Increment with ++ on the left side (Pre-increment)
%% Eg: ++x
evaluate_expression(pre_increment(Assign_to, Increment_operation), Expression_result) :-
    evaluate_expression(Increment_operation, Increment_operation_result),
    c_var__get_type(Assign_to, Type),
    ptc_solver__variable([Expression_result], Type),
    ptc_solver__sdl(Expression_result = Increment_operation_result),
    c_var__set_out_var(Assign_to, Expression_result).

% %% Increment with -- on the right side (Post-decrement)
% %% Eg: x--
evaluate_expression(post_decrement(Assign_to, Decrement_operation), Expression_result) :-
    evaluate_expression(post_increment(Assign_to, Decrement_operation),Expression_result).

% %% Increment with -- on the left side (Pre-decrement)
% %% Eg: --x
evaluate_expression(pre_decrement(Assign_to, Decrement_operation), Expression_result) :-
    evaluate_expression(pre_increment(Assign_to, Decrement_operation), Expression_result).

%% Negation operator (Unary minus)
%% A value's sign being flipped with the minus operator
%% Eg: -x
evaluate_expression(-Expression, -Expression_result) :-
    evaluate_expression(Expression, Expression_result).

%% Assignment operator (=)
%% Eg: x = 2
evaluate_expression(assignment(Assign_to, Expression), Expression_result) :-
    evaluate_expression(Expression, Right_result),

    % Assign_to can be as expression such as in pointer assignment
    % Eg: *x = 2 becomes assignment(dereference(LC_x_1) , 2))
    (c_var__is_variable(Assign_to) ->
        Variable_to_assign = Assign_to
    ;
    Assign_to = dereference(Assignment_expression) ->
        evaluate_expression(Assignment_expression, Assignment_expression_result),
        get_from_memory(Assignment_expression_result, Variable_to_assign)
    ),

    utils__assignment(Variable_to_assign, Right_result, Expression_result).

%% Handle the += operator
%%  Breakdown: Variable += Expression
%%  Eg: x += 2;
evaluate_expression(add_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, Variable + Expression), Expression_result).

%% Handle the -= operator
%%  Breakdown: Variable -= Expression
%%  Eg: x -= 2;
evaluate_expression(sub_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, Variable - Expression), Expression_result).

%% Handle the *= operator
%%  Breakdown: Variable *= Expression
%%  Eg: x *= 2;
evaluate_expression(mul_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, multiply(Variable, Expression)), Expression_result).

%% Handle the /= operator
%%  Breakdown: Variable /= Expression
%%  Eg: x /= 2;
evaluate_expression(div_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, Variable / Expression), Expression_result).

% Handle the %= operator
%  Breakdown: Variable %= Expression
%  Eg: x %= 2;
evaluate_expression(mod_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, mod(Variable, Expression)), Expression_result).

%% Handles the ++ post-increment-operator as a single line statement
%% Eg: x++;
evaluate_expression(post_increment(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Handles the ++ pre-increment-operator as a single line statement
%% Eg: ++x;
evaluate_expression(pre_increment(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Handles the -- post-decrement-operator as a single line statement
%% Eg: x--;
evaluate_expression(post_decrement(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Handles the -- pre-decrement-operator as a single line statement
%% Eg: --x;
evaluate_expression(pre_decrement(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Returns the address of a variable in the memory model
evaluate_expression(address_of(Variable), Expression_result) :-
    c_var__get_address(Variable, Expression_result).

%% Dereference operator (Unary *)
%% Eg: *x
%% This returns the c_var at the memory address
evaluate_expression(dereference(Expression), Expression_result) :-
    evaluate_expression(Expression, Address),
    get_from_memory(Address, Value_at_address),
    evaluate_expression(Value_at_address, Expression_result).

%% Function call as expression
%% Eg: int x = 2 + give_five();
evaluate_expression(function_call(Function_info, Arguments), Expression_result) :-
    maplist(evaluate_expression, Arguments, Arguments_result),
    symbolically_execute_function(Function_info, Arguments_result, Expression_result). % Statement_handler.pl
    
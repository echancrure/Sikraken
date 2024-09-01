symbolically_interpret(Expression, Expression) :-
    number(Expression),
    !.
symbolically_interpret(Expression, Symbolic_expression) :-
    var(Expression),
    !,
    seav__is_seav(Expression),    
    seav__get(Expression, 'output', Symbolic_expression).
symbolically_interpret(function_call(Function, Arguments), Symbolic_expression) :-
    !,
    se_sub_atts__get(Function, 'body', Body),
    (Body == 'no_body_is_extern' -> %calling an extern function with no_body
        (se_name_atts__get(Function, 'name', Function_name),
         (Function_name == 'UC___VERIFIER_nondet_int' ->
            (%mytrace,
             ptc_solver__variable([Input_var], 'integer'),
             se_globals__get_ref('verifier_inputs', Verifier_inputs),
             append(Verifier_inputs, [Input_var], New_verifier_inputs),
             se_globals__set_ref('verifier_inputs', New_verifier_inputs),
             Symbolic_expression = Input_var
            )
         ;
          Function_name == 'Exit' ->
            (%Arguments = [Exit_code],
             %common_util__error(0, "Exit Called:", 'no_error_consequences', [('Exit_code', Exit_code)], '0_170824_1', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info),
             %mytrace,
             end_of_path_predicate(_, _),    %only works in 'testcomp'
             fail
            )
         ;
            common_util__error(10, "Function call to unknown external function", "Cannot perform symbolic interpretation", [('Function_name', Function_name)], '10_150824_3', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info)
         )
        )
    ;
        (se_sub_atts__get(Function, 'parameters', Parameters),
         se_sub_atts__get(Function, 'return_type', Return_type),
         se_globals__push_scope_stack,          %function parameters scope
         match_parameters_arguments(Parameters, Arguments),
         symbolic_execute(Body, Flow),
         (Flow = return(Return_expression) ->
            symbolically_interpret(cast(Return_type, Return_expression), Symbolic_expression)
         ;
            Symbolic_expression = void
         ),
         se_globals__pop_scope_stack            %function parameters scope
        )
    ).
symbolically_interpret(cast(_Return_type, Return_expression), Symbolic_expression) :-
    !,
    Symbolic_expression = Return_expression.    %for now
symbolically_interpret(addr(Expression), addr(Expression)) :-
    !.
symbolically_interpret(deref(Expression), Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression_ptr),
    (Symbolic_expression_ptr = addr(Inner_Symbolic_expression) ->   %todo: need testing with many levels of derefs
        symbolically_interpret(Inner_Symbolic_expression, Symbolic_expression)
    ;
        Symbolic_expression = Symbolic_expression_ptr   %todo: unsure...
    ).
symbolically_interpret(multiply_op(Le_exp, Ri_exp), Le_Symbolic * Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(div_op(Le_exp, Ri_exp), Le_Symbolic / Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(mod_op(Le_exp, Ri_exp), mod_op(Le_Symbolic, Ri_Symbolic)) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(plus_op(Le_exp, Ri_exp), Le_Symbolic + Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(minus_op(Le_exp, Ri_exp), Le_Symbolic - Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(minus_op(Expression), -Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression).
%%%relational operators
symbolically_interpret(less_op(Le_exp, Ri_exp), Le_Symbolic < Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(greater_op(Le_exp, Ri_exp), Le_Symbolic > Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(less_or_eq_op(Le_exp, Ri_exp), Le_Symbolic <= Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(greater_or_eq_op(Le_exp, Ri_exp), Le_Symbolic >= Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(equal_op(Le_exp, Ri_exp), Le_Symbolic = Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(not_equal_op(Le_exp, Ri_exp), Le_Symbolic <> Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
%%%
symbolically_interpret(postfix_inc_op(Expression), Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression),
    symbolic_execute(assign(Expression, plus_op(Expression, 1)), _).


symbolically_interpret(and_op(Le_exp, Ri_exp), 'true') :-   %C semantics of && is always short circuit
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    ptc_solver__sdl(Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic),
    ptc_solver__sdl(Ri_Symbolic).
symbolically_interpret(or_op(Le_exp, Ri_exp), 'true') :-   %C semantics of || is always short circuit
    !,
    %mytrace,
    random(2, R2),
    (R2 == 0 ->
        (A = Le_exp,
         B = Ri_exp
        )
    ;
        (A = Ri_exp,
         B = Le_exp
       )
    ),
    (
        (symbolically_interpret(A, Le_Symbolic),
         ptc_solver__sdl(Le_Symbolic)
        )
    ;%deliberate choice point
        (%but only if will lead to new path todo
         symbolically_interpret(not_op(A), Not_Le_Symbolic),
         ptc_solver__sdl(Not_Le_Symbolic),
         symbolically_interpret(B, Ri_Symbolic),
         ptc_solver__sdl(Ri_Symbolic)
        )
    ).
 
symbolically_interpret(not_op(Le_exp), Symbolic) :-
    !,
    (Le_exp = and_op(L, R) ->
        symbolically_interpret(or_op(not_op(L), not_op(R)), Symbolic)
    ;
     Le_exp = or_op(L, R) ->
        symbolically_interpret(and_op(not_op(L), not_op(R)), Symbolic)
    ;
     Le_exp = not_op(L) ->
        symbolically_interpret(L, Symbolic)
    ;
        (symbolically_interpret(Le_exp, Le_Symbolic),
         Symbolic = not(Le_Symbolic)
        )
    ).
symbolically_interpret(Unhandled_expression, _Symbolic_expression) :-
    common_util__error(10, "Expression is not handled", "Cannot perform symbolic interpretation", [('Unhandled_expression', Unhandled_expression)], '10_020824', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
symbolically_interpret(Expression, Expression) :-
    number(Expression),
    !.
symbolically_interpret(Expression, Symbolic_expression) :-
    seav__is_seav(Expression),
    !,
    seav__get(Expression, 'output', Symbolic_expression).

symbolically_interpret(addr(Expression), addr(Expression)) :-
    !.
symbolically_interpret(deref(Expression), Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression2),
    (Symbolic_expression2 = addr(Symbolic_expression3) ->   %need a version that works for many levels of derefs
        Symbolic_expression = Symbolic_expression3          %need better names 
    ;
        Symbolic_expression = Symbolic_expression2
    ).
symbolically_interpret(multiply_op(Le_exp, Ri_exp), Le_Symbolic * Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).
symbolically_interpret(plus_op(Le_exp, Ri_exp), Le_Symbolic + Ri_Symbolic) :-
    !,
    symbolically_interpret(Le_exp, Le_Symbolic),
    symbolically_interpret(Ri_exp, Ri_Symbolic).

symbolically_interpret(Unhandled_expression, _Symbolic_expression) :-
common_util__error(10, "Expression is not handled", "Cannot perform symbolic interpretation", [('Unhandled_expression', Unhandled_expression)], 10020824, 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info).
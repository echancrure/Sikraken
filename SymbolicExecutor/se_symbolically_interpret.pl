symbolically_interpret(Expression, Expression) :-
    number(Expression),
    !.
symbolically_interpret(Expression, Symbolic_expression) :-
    seav__is_seav(Expression),
    !,
    seav__get(Expression, 'output', Symbolic_expression).

symbolically_interpret(addr(Expression), addr(Expression)).
symbolically_interpret(deref(Expression), Symbolic_expression) :-
    symbolically_interpret(Expression, Symbolic_expression2),
    (Symbolic_expression2 = addr(Symbolic_expression3) ->   %need a version that works for many levels of derefs
        Symbolic_expression = Symbolic_expression3          %need better names 
    ;
        Symbolic_expression = Symbolic_expression2
    ).

symbolically_interpret(Expression, Expression) :-
    number(Expression),
    !.
symbolically_interpret(addr_of(Expression), addr_of(Expression)).
symbolically_interpret(Expression, Symbolic, Constraint, Type) :-
    number(Expression),
    !,
    midoan_solver__interpret(Expression, types(_), Constraint, Type, _Exception).
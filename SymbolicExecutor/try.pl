:- module('try').
:- meta_attribute('try', [unify:unify_name/2]).

unify_name(_, Attr) :-
    var(Attr).
unify_name(Term, Attr) :-
    compound(Attr),
    unify_term_name(Term, Attr).

unify_term_name(_{AttrY}, AttrX) :-
    -?->
    AttrX = AttrY.  

try :-
    add_attribute(X, try('X')),
    Declarator = X,
    (Declarator = 2 ->
        printf("hello there 10", [])
    ;
        printf("hello there 20", [])
    ).
try :-
printf("hello there 30", []).
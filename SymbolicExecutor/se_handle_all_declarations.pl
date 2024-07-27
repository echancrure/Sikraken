symbolic_execute_all_declarations([]).
symbolic_execute_all_declarations([Declaration|R]) :-
    symbolic_execute(Declaration),
    symbolic_execute_all_declarations(R).

symbolic_execute(declaration(Specifiers, Declarators)) :-
    .

symbolic_execute(function(Specifiers, Function_name, Params, [], Compound_statement)) :-
    .
try_with_seed :-
    seed(1970), 
    (for(_, 1, 10) do (
        random(10, N),
        writeln(N))
    ),
    fail.
try_with_seed :-
    writeln("new sequence:"),
    (for(_, 1, 10) do (random(10, N), writeln(N))).

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

try_stream:-
    open("try.txt", write, My_stream),
    set_stream('log_output', My_stream),
    write("Hello World"),   %test gets redirect to My_stream fine
    statistics,             %output does not get redirected: still printed in tkeclipse
    flush(My_stream),
    close(My_stream),
    set_stream('log_output', stdout).
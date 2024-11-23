:- lib(ic).

try_eval(V) :-
    %Y = eval(1),   %leads to number expected in set_up_ic_con(3, 1, [0 * 1, 1 * _1920{-1.0Inf .. 1.0Inf}, -1 * eval(1)])
    %eval(1, Y),     %is ok
    eval(V, Y),     %is ok too
    try_eval2(Y).

try_eval2(Y) :-
    X $= Y.

try8_28 :-
    X $:: -9.2233720368547758e+18 .. -1e-20,
    Y $= 5.4,
    try8_28_2(X, Y, Z).
try8_28_2(X, Y, Z) :-
    eval(X*Y, Z).

test :-
    statistics(hr_time, Start_time),

    (count(I,1,10000)     do    
    Message = "hi %d",
    Arguments = [I],           
        %printf(output, "Dev Info: hi %d\n", [I])    %todo could you combine 
        printf('output', "Dev Info: ", []),    %todo could you combine 
        printf('output', Message, Arguments),
        printf('output', "\n", [])
        %,flush(output)
    ),
    statistics(hr_time, End_time),
    Duration is End_time - Start_time,
    printf(output, "duration is %f", [Duration]).
troy :-
    Message = "Hello",
    (for(I, 1, 2), param(Message) do say(I, Message)).


say(_, Message) :-
    writeln(Message).
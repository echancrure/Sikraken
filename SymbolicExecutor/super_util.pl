:- module('super_util').
:- export super_util__quick_dev_info/2.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
super_util__quick_dev_info(Message, Arguments) :-
    printf('user_error', "Dev Info: ", []),
    printf('user_error', Message, Arguments),
    printf('user_error', "\n", []),
    flush('user_error').        %systematically flushing ALL debug/development messages is important or they may get displayed in a wrong order when mixed with message from other streams and be out of sync with the ECLiPse tracer

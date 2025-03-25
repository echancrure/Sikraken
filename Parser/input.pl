prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Choice]), 
do_while_stmt(int(1), branch(4, 
cmp_stmts([
stmt(function_call(Printf, ["\nMenu:\n"])), 
stmt(function_call(Printf, ["1. Say Hello\n"])), 
stmt(function_call(Printf, ["2. Print a Number\n"])), 
stmt(function_call(Printf, ["3. Exit\n"])), 
stmt(function_call(Printf, ["Enter your choice: "])), 
stmt(function_call(Scanf, ["%d", addr(Choice)])), 
switch_stmt(Choice, 
cmp_stmts([case_stmt(int(1), 
stmt(function_call(Printf, ["Hello, User!\n"]))), 
break_stmt
, case_stmt(int(2), 
stmt(function_call(Printf, ["Enter a number: "]))), 
declaration([int], [Num]), 
stmt(function_call(Scanf, ["%d", addr(Num)])), 
stmt(function_call(Printf, ["You entered: %d\n", Num])), 
break_stmt
, case_stmt(int(3), 
stmt(function_call(Printf, ["Exiting the program...\n"]))), 
return_stmt(int(0))
, default_stmt(
stmt(function_call(Printf, ["Invalid choice! Please enter a valid option.\n"])))
]))
]))), 
return_stmt(int(0))

]))
]).
prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Day]), 
stmt(function_call(Printf, ["Enter a number (1-3): "])), 
stmt(function_call(Scanf, ["%d", addr(Day)])), 
switch_stmt(Day, 
cmp_stmts([case_stmt(int(1), 
stmt(function_call(Printf, ["You selected Monday.\n"]))), 
if_stmt(branch(2, equal_op(Day, int(2))), stmt([]) ), 
break_stmt
, default_stmt(
stmt(function_call(Printf, ["Invalid selection!\n"])))
])), 
return_stmt(int(0))

]))
]).
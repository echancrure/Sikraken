prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Num]), 
stmt(function_call(Printf, ["Enter a number (1-3): "])), 
stmt(function_call(Scanf, ["%d", addr(Num)])), 
if_stmt(branch(1, equal_op(Num, int(10))), stmt([]) ), 
switch_stmt(Num, 
cmp_stmts([case_stmt(int(1), 
if_stmt(branch(3, equal_op(Num, int(1))), 
cmp_stmts([
if_stmt(branch(2, equal_op(Num, int(2))), stmt([]) )
]) )), 
if_stmt(branch(5, equal_op(Num, int(2))), stmt([]) ), 
break_stmt
, case_stmt(int(2), 
stmt(function_call(Printf, ["Case 2 executed\n"]))), 
break_stmt
, case_stmt(int(3), 
stmt(function_call(Printf, ["Case 3 executed\n"]))), 
break_stmt
, default_stmt(
if_stmt(branch(8, equal_op(Num, int(10))), stmt([]) ))
])), 
if_stmt(branch(9, equal_op(Num, int(10))), stmt([]) ), 
return_stmt(int(0))

]))
]).
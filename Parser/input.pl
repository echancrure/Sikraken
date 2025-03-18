prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Num]), 
stmt(function_call(Printf, ["Enter a number (1-3): "])), 
stmt(function_call(Scanf, ["%d", addr(Num)])), 
do_while_stmt(not_equal_op(Num, int(10)), branch(3, 
cmp_stmts([
if_stmt(branch(1, equal_op(Num, int(10))), 
cmp_stmts([]) , 
cmp_stmts([
break_stmt

])), 
if_stmt(branch(2, equal_op(Num, int(100))), stmt([]) )
]))), 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
while_stmt(branch(4, less_op(I, int(100))), 
cmp_stmts([
cmp_stmts([
break_stmt

]), postfix_inc_op(I)]))]), 
do_while_stmt(
cmp_stmts([
if_stmt(branch(5, equal_op(Num, int(100))), 
cmp_stmts([
break_stmt

]) )
]), branch(6, not_equal_op(Num, , 
return_stmt(int(0))

]))
]).
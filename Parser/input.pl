prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Day]), 
stmt(function_call(Printf, ["Enter a number (1-7) to get the day of the week: "])), 
stmt(function_call(Scanf, ["%d", addr(Day)])), 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
while_stmt(branch(4, less_op(I, int(10))), 
cmp_stmts([
cmp_stmts([
cmp_stmts([
declaration([int], [initialised(J, int(0))]), 
while_stmt(branch(2, less_op(J, int(10))), 
cmp_stmts([
cmp_stmts([
if_stmt(branch(1, equal_op(J, int(5))), 
cmp_stmts([
break_stmt

]) )
]), postfix_inc_op(J)]))]), 
if_stmt(branch(3, equal_op(I, int(5))), 
cmp_stmts([
break_stmt

]) )
]), postfix_inc_op(I)]))]), 
if_stmt(branch(5, equal_op(Day, int(7))), stmt([]) ), 
return_stmt(int(0))

]))
]).
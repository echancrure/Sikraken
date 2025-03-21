prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), label_stmt(end_loops, 
cmp_stmts([
stmt(assign(I, int(0))), 
while_stmt(branch(2, less_op(I, int(5))), 
cmp_stmts([
cmp_stmts([
goto_stmt(end_loops, Main)
, 
if_stmt(branch(1, equal_op(I, int(3))), 
cmp_stmts([]) )
]), postfix_inc_op(I)]))])), 
if_stmt(branch(3, equal_op(I, int(100))), stmt([]) ), 
if_stmt(branch(4, equal_op(I, int(10))), stmt([]) ), 
return_stmt(int(0))

]))
]).
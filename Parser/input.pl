prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
cmp_stmts([
stmt(assign(I, int(0))), 
while_stmt(branch(4, less_op(I, int(10))), 
cmp_stmts([
cmp_stmts([
do_while_stmt(not_equal_op(I, int(10)), branch(3, 
cmp_stmts([
if_stmt(branch(1, equal_op(I, int(5))), 
cmp_stmts([
return_stmt

]) ), 
if_stmt(branch(2, equal_op(I, int(6))), 
cmp_stmts([
return_stmt(int(0))

]) ), 
stmt(postfix_inc_op(I))
])))
]), postfix_inc_op(I)]))]), 
return_stmt(int(0))

]))
]).
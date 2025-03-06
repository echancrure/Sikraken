prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
if_stmt(branch(7, equal_op(I, int(0))), 
cmp_stmts([
if_stmt(branch(3, equal_op(I, int(1))), 
cmp_stmts([
if_stmt(branch(2, equal_op(I, int(2))), 
cmp_stmts([]) , 
if_stmt(branch(1, equal_op(I, int(3))), 
cmp_stmts([]) ))
]) ), 
if_stmt(branch(4, equal_op(I, int(5))), 
cmp_stmts([]) )
]) , 
cmp_stmts([
if_stmt(branch(6, equal_op(I, int(8))), 
cmp_stmts([]) , 
if_stmt(branch(5, equal_op(int(1), int(9))), 
cmp_stmts([]) ))
])), 
if_stmt(branch(8, equal_op(I, int(6))), 
cmp_stmts([]) ), 
if_stmt(branch(9, equal_op(I, int(7))), 
cmp_stmts([]) ), 
return_stmt(int(0))

]))
]).
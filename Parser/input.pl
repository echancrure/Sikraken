prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
cmp_stmts([
stmt(assign(I, int(0))), 
while_stmt(branch(2, less_op(I, int(5))), 
cmp_stmts([
cmp_stmts([
if_stmt(branch(1, equal_op(I, int(3))), 
cmp_stmts([
goto_stmt(end_loops, Main)

]) )
]), postfix_inc_op(I)]))]), 
if_stmt(branch(3, equal_op(I, int(100))), stmt([]) ), label_stmt(end_loops, 
if_stmt(branch(4, equal_op(I, int(10))), stmt([]) )), 
return_stmt(int(0))

])), 
function([void], function(GetRecords, []), [], 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
if_stmt(branch(5, equal_op(I, int(10))), stmt([]) ), 
if_stmt(branch(6, equal_op(I, int(11))), stmt([]) )
])), 
function([void], function(SetRecords, []), [], 
cmp_stmts([]))
]).
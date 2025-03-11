prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Day]), 
if_stmt(branch(1, equal_op(Day, int(360))), stmt([]) ), 
do_while_stmt(
cmp_stmts([
if_stmt(branch(2, equal_op(Day, int(10))), stmt([]) ), 
if_stmt(branch(3, equal_op(Day, int(20))), stmt([]) ), 
do_while_stmt(
cmp_stmts([
if_stmt(branch(4, equal_op(Day, int(40))), stmt([]) )
]), branch(5, not_equal_op(Day,, 
if_stmt(branch(6, equal_op(Day, int(20))), stmt([]) )
]), branch(7, not_equal_op(Day, , 
return_stmt(int(0))

]))
]).
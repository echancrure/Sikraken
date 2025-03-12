prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Day]), 
stmt(cond_exp(branch(1, (equal_op(Day, int(360)))), cast([void], int(0)), cast([void], int(0)))), 
do_while_stmt(
cmp_stmts([
stmt(cond_exp(branch(2, (equal_op(Day, int(10)))), cast([void], int(0)), cast([void], int(0)))), 
stmt(cond_exp(branch(3, (equal_op(Day, int(20)))), cast([void], int(0)), cast([void], int(0)))), 
do_while_stmt(
cmp_stmts([
stmt(cond_exp(branch(4, (equal_op(Day, int(40)))), cast([void], int(0)), cast([void], int(0))))
]), branch(5, not_equal_op(Day,, 
stmt(cond_exp(branch(6, (equal_op(Day, int(20)))), cast([void], int(0)), cast([void], int(0))))
]), branch(7, not_equal_op(Day, , 
do_while_stmt(
cmp_stmts([]), branch(8, equal_op(Day, , 
return_stmt(int(0))

]))
]).
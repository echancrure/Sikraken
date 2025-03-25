prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [Day]), 
stmt(function_call(Printf, ["Enter a number (1-7) to get the corresponding day of the week: "])), 
stmt(function_call(Scanf, ["%d", addr(Day)])), 
switch_stmt(Day, 
cmp_stmts([case_stmt(int(1), 
stmt(function_call(Printf, ["Sunday\n"]))), case_stmt(int(2), 
stmt(function_call(Printf, ["Monday\n"]))), 
break_stmt
, case_stmt(int(3), 
stmt(function_call(Printf, ["Tuesday\n"]))), 
break_stmt
, case_stmt(int(4), 
stmt(function_call(Printf, ["Wednesday\n"]))), 
break_stmt
, case_stmt(int(5), 
stmt(function_call(Printf, ["Thursday\n"]))), 
break_stmt
, case_stmt(int(6), 
stmt(function_call(Printf, ["Friday\n"]))), 
break_stmt
, case_stmt(int(7), 
stmt(function_call(Printf, ["Saturday\n"]))), 
break_stmt
, default_stmt(
if_stmt(branch(8, equal_op(Day, int(100))), stmt([]) ))
])), 
return_stmt(int(0))

]))
]).
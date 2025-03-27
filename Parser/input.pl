prolog_c([
declaration([extern, int], [function(UC___VERIFIER_nondet_int, [param_no_decl([void], [])])]), 
function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [initialised(K, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [array_decl(A, int(1048))]), 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
while_stmt(branch(1, less_op(I, int(1048))), 
cmp_stmts([
cmp_stmts([
stmt(assign(index(A, I), function_call(UC___VERIFIER_nondet_int, [])))
]), postfix_inc_op(I)]))]), 
if_stmt(branch(4, and_op(greater_or_eq_op(K, int(0)), less_op(K, int(1048)))), 
cmp_stmts([
if_stmt(branch(3, and_op(equal_op(index(A, int(0)), int(23)), equal_op(index(A, K), int(42)))), 
cmp_stmts([
declaration([int], [initialised(X, function_call(UC___VERIFIER_nondet_int, []))]), 
do_while_stmt(greater_or_eq_op(X, int(0)), branch(2, 
cmp_stmts([
stmt(assign(X, minus_op(X, K)))
])))
]) )
]) ), 
return_stmt(int(0))

]))
]).
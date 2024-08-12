prolog_c([
declaration([int], [initialised(A, 1)]), 
function([int], Basic, [param([int], X)], [], 
cmp_stmts([
declaration([int], [initialised(A, 2)]), 
declaration([int], [initialised(B, 0)]), 
cmp_stmts([
declaration([int], [initialised(A, 3)]), 
cmp_stmts([
declaration([int], [initialised(A, 4)]), 
stmt(assign(B, plus_op(X, A))), 
if_stmt(greater_op(B, 42), 
stmt(assign(B, plus_op(B, 1))), 
stmt(assign(B, plus_op(B, 1000))))
]), 
stmt(assign(B, plus_op(B, A)))
]), 
stmt(assign(B, plus_op(B, A))), 
return_stmt(Sikraken_return, plus_op(B, X))

])), 
function([void], Main, [param_no_decl([void], [])], [], 
cmp_stmts([]))
]).
prolog_c([
declaration([int], [initialised(A, 1)]), 
function([int], Basic, [param([int], X)], [], 
cmp_stmts([
declaration([int], [initialised(A, 2)]), 
declaration([int], [initialised(B, 0)]), 
cmp_stmts([
declaration([int], [initialised(A, 3)]), 
cmp_stmts([
declaration([int], [initialised(A, 4)]), 
stmt(assign(B, plus_op(X, A))), 
if_stmt(greater_op(B, 42), 
stmt(assign(B, plus_op(B, 1))), 
stmt(assign(B, plus_op(B, 1000))))
]), 
stmt(assign(B, plus_op(B, A)))
]), 
stmt(assign(B, plus_op(B, A))), 
return_stmt(Sikraken_return, plus_op(B, X))

])), 
function([void], Main, [param_no_decl([void], [])], [], 
cmp_stmts([]))
]).
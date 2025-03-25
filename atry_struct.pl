prolog_c([
declaration([extern, int], [function(UC___VERIFIER_nondet_int, [])]), 

declaration([struct(Struct_of_struct, [struct_decl([int], [x, y, z, t]), struct_decl([struct('anonymous', [struct_decl([int], [anon])])], [inner]), anonymous_member(struct('anonymous', [struct_decl([int], [anon])]))])]), 

declaration([struct(Point, [struct_decl([int], [x, y, z, t]), struct_decl([float], [weight])])], [initialised(P78, initializer([int(1), int(2), int(3), int(4), double(4.004)])), initialised(P79, initializer([int(1)]))]), 

declaration([struct(Point2, [struct_decl([int], [x, y, z, t]), struct_decl([float], [weight])])], [initialised(P1, initializer([int(1), int(2), int(3), int(4), double(67.0)])), P2]), 

declaration([struct(Point3)]), 

declaration([struct(Point3, [struct_decl([int], [x, y, z, t]), struct_decl([float], [weight])])]), 

declaration([struct('anonymous', [struct_decl([int], [x, y, z, t]), struct_decl([float], [weight])])], [initialised(Anon1, initializer([int(1), int(2), int(3), int(4), double(67.0)])), Anon2]), 

declaration([int], [initialised(A, int(1))]), 

declaration([typedef, struct(Plot)], [Plot]), 

declaration([struct(Plot, [struct_decl([int], [x, y])])]), 

declaration([Plot], [initialised(P, initializer([int(10), int(20)]))]), 

declaration([typedef, struct('anonymous', [struct_decl([int], [n])])], [UC_S]), 

declaration([UC_S], [UC_Sx]), 
function([int], function(Main, [param_no_decl([void], [])]), [], 
cmp_stmts([
stmt(assign(Anon2, Anon1)), 
declaration([int], [initialised(P3, P1)]), 
declaration([int], [initialised(I, int(0))]), 
declaration([struct(Point_1, [struct_decl([int], [x, y, z, t]), struct_decl([float], [weight])])], [initialised(P78_1, initializer([int(1), int(2), int(3), int(4), double(4.004)])), initialised(P79_1, initializer([int(1)]))]), 
declaration([int], [Gy]), 
stmt(assign(Gy, select(P79_1, y))), 
if_stmt(branch(1, equal_op(Gy, function_call(UC___VERIFIER_nondet_int, []))), 
stmt(postfix_dec_op(I)) ), 
stmt(postfix_inc_op(I)), 
if_stmt(branch(2, and_op(and_op(and_op(equal_op(select(P78_1, x), int(1)), equal_op(select(P79_1, x), int(1))), equal_op(select(P78, x), int(1))), equal_op(select(P79, x), int(1)))), 
stmt(postfix_inc_op(I)) , 
stmt(postfix_dec_op(I))), 
if_stmt(branch(3, equal_op(select(P79, y), int(0))), 
stmt(postfix_inc_op(I)) , 
return_stmt(int(1))
), 
declaration([float], [initialised(Fl, select(P78, x))]), 
declaration([int], [initialised(Gh, plus_op(select(P, x), select(P, y)))]), 
if_stmt(branch(4, equal_op(Gh, function_call(UC___VERIFIER_nondet_int, []))), 
stmt(postfix_inc_op(I)) , 
stmt(postfix_dec_op(I))), 
declaration([UC_S], [X]), 
stmt(assign(select(X, n), function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(5, equal_op(select(X, n), int(99))), 
stmt(postfix_inc_op(I)) , 
stmt(postfix_dec_op(I))), 
declaration([struct(Point)], [S1]), 
declaration([struct(Point)], [initialised(S2, initializer([int(1), int(2), int(3), int(4), double(42.42)]))]), 
declaration([struct(Point)], [initialised(S3, initializer([int(1), int(2), int(3)]))]), 
stmt(assign(select(S1, x), function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(6, equal_op(select(S1, x), minus_op(int(5)))), 
stmt(postfix_inc_op(I)) , 
stmt(postfix_dec_op(I))), 
return_stmt(int(0))

]))
]).
prolog_c([
declaration([extern, void], [function(Abort, [param_no_decl([void], [])])]), 

declaration([extern, int], [function(UC___assert_fail, [param_no_decl([const, char], dummy_abstract_declarator), param_no_decl([const, char], dummy_abstract_declarator), param_no_decl([unsigned, int], []), param_no_decl([const, char], dummy_abstract_declarator)])]), 
function([void], function(Reach_error, []), [], 
cmp_stmts([
stmt(function_call(UC___assert_fail, ["0", "toy2.cil.c", int(3), "reach_error"]))
])), 

declaration([extern, int], [function(UC___VERIFIER_nondet_int, [])]), 
function([void], function(Error, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([label_stmt(ERROR, 
cmp_stmts([
stmt(function_call(Reach_error, [])), 
stmt(function_call(Abort, []))
])), 
return_stmt

])
])), 

declaration([int], [C]), 

declaration([int], [C_t]), 

declaration([int], [C_req_up]), 

declaration([int], [P_in]), 

declaration([int], [P_out]), 

declaration([int], [Wl_st]), 

declaration([int], [C1_st]), 

declaration([int], [C2_st]), 

declaration([int], [Wb_st]), 

declaration([int], [R_st]), 

declaration([int], [Wl_i]), 

declaration([int], [C1_i]), 

declaration([int], [C2_i]), 

declaration([int], [Wb_i]), 

declaration([int], [R_i]), 

declaration([int], [Wl_pc]), 

declaration([int], [C1_pc]), 

declaration([int], [C2_pc]), 

declaration([int], [Wb_pc]), 

declaration([int], [E_e]), 

declaration([int], [E_f]), 

declaration([int], [E_g]), 

declaration([int], [E_c]), 

declaration([int], [E_p_in]), 

declaration([int], [E_wl]), 

declaration([void], [function(Write_loop, [param_no_decl([void], [])])]), 

declaration([void], [function(Compute1, [param_no_decl([void], [])])]), 

declaration([void], [function(Compute2, [param_no_decl([void], [])])]), 

declaration([void], [function(Write_back, [param_no_decl([void], [])])]), 

declaration([void], [function(Read, [param_no_decl([void], [])])]), 

declaration([int], [D]), 

declaration([int], [Data]), 

declaration([int], [Processed]), 

declaration([static, int], [T_b]), 
function([void], function(Write_loop, [param_no_decl([void], [])]), [], 
cmp_stmts([
declaration([int], [T]), 
cmp_stmts([
if_stmt(branch(3, equal_op(cast([int], Wl_pc), int(0))), 
cmp_stmts([
goto_stmt(WL_ENTRY_LOC, Write_loop)

]) , 
cmp_stmts([
if_stmt(branch(2, equal_op(cast([int], Wl_pc), int(2))), 
cmp_stmts([
goto_stmt(WL_WAIT_2_LOC, Write_loop)

]) , 
cmp_stmts([
if_stmt(branch(1, equal_op(cast([int], Wl_pc), int(1))), 
cmp_stmts([
goto_stmt(WL_WAIT_1_LOC, Write_loop)

]) , 
cmp_stmts([]))
]))
])), label_stmt(WL_ENTRY_LOC, 
stmt(assign(Wl_st, int(2)))), 
stmt(assign(Wl_pc, int(1))), 
stmt(assign(E_wl, int(0))), 
goto_stmt(return_label, Write_loop)
, label_stmt(WL_WAIT_1_LOC, 
cmp_stmts([
do_while_stmt(int(1), branch(9, 
cmp_stmts([label_stmt(while_0_continue, stmt([])), 
stmt(assign(T, D)), 
stmt(assign(Data, D)), 
stmt(assign(Processed, int(0))), 
stmt(assign(E_f, int(1))), 
if_stmt(branch(5, equal_op(cast([int], C1_pc), int(1))), 
cmp_stmts([
if_stmt(branch(4, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(C1_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(7, equal_op(cast([int], C2_pc), int(1))), 
cmp_stmts([
if_stmt(branch(6, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(C2_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
stmt(assign(E_f, int(2))), 
stmt(assign(Wl_st, int(2))), 
stmt(assign(Wl_pc, int(2))), 
stmt(assign(T_b, T)), 
goto_stmt(return_label, Write_loop)
, label_stmt(WL_WAIT_2_LOC, 
stmt(assign(T, T_b))), 
if_stmt(branch(8, equal_op(D, plus_op(T, int(1)))), 
cmp_stmts([]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(Error, []))
])
]))
]))), label_stmt(while_0_break, stmt([]))
])), label_stmt(return_label, 
return_stmt
)
])
])), 
function([void], function(Compute1, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([
if_stmt(branch(11, equal_op(cast([int], C1_pc), int(0))), 
cmp_stmts([
goto_stmt(C1_ENTRY_LOC, Compute1)

]) , 
cmp_stmts([
if_stmt(branch(10, equal_op(cast([int], C1_pc), int(1))), 
cmp_stmts([
goto_stmt(C1_WAIT_LOC, Compute1)

]) , 
cmp_stmts([]))
])), label_stmt(C1_ENTRY_LOC, 
cmp_stmts([
do_while_stmt(int(1), branch(15, 
cmp_stmts([label_stmt(while_1_continue, stmt([])), 
stmt(assign(C1_st, int(2))), 
stmt(assign(C1_pc, int(1))), 
goto_stmt(return_label, Compute1)
, label_stmt(C1_WAIT_LOC, 
if_stmt(branch(14, not_op(Processed)), 
cmp_stmts([
stmt(add_assign(Data, int(1))), 
stmt(assign(E_g, int(1))), 
if_stmt(branch(13, equal_op(cast([int], Wb_pc), int(1))), 
cmp_stmts([
if_stmt(branch(12, equal_op(cast([int], E_g), int(1))), 
cmp_stmts([
stmt(assign(Wb_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
stmt(assign(E_g, int(2)))
]) , 
cmp_stmts([])))
]))), label_stmt(while_1_break, stmt([]))
])), label_stmt(return_label, 
return_stmt
)
])
])), 
function([void], function(Compute2, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([
if_stmt(branch(17, equal_op(cast([int], C2_pc), int(0))), 
cmp_stmts([
goto_stmt(C2_ENTRY_LOC, Compute2)

]) , 
cmp_stmts([
if_stmt(branch(16, equal_op(cast([int], C2_pc), int(1))), 
cmp_stmts([
goto_stmt(C2_WAIT_LOC, Compute2)

]) , 
cmp_stmts([]))
])), label_stmt(C2_ENTRY_LOC, 
cmp_stmts([
do_while_stmt(int(1), branch(21, 
cmp_stmts([label_stmt(while_2_continue, stmt([])), 
stmt(assign(C2_st, int(2))), 
stmt(assign(C2_pc, int(1))), 
goto_stmt(return_label, Compute2)
, label_stmt(C2_WAIT_LOC, 
if_stmt(branch(20, not_op(Processed)), 
cmp_stmts([
stmt(add_assign(Data, int(1))), 
stmt(assign(E_g, int(1))), 
if_stmt(branch(19, equal_op(cast([int], Wb_pc), int(1))), 
cmp_stmts([
if_stmt(branch(18, equal_op(cast([int], E_g), int(1))), 
cmp_stmts([
stmt(assign(Wb_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
stmt(assign(E_g, int(2)))
]) , 
cmp_stmts([])))
]))), label_stmt(while_2_break, stmt([]))
])), label_stmt(return_label, 
return_stmt
)
])
])), 
function([void], function(Write_back, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([
if_stmt(branch(23, equal_op(cast([int], Wb_pc), int(0))), 
cmp_stmts([
goto_stmt(WB_ENTRY_LOC, Write_back)

]) , 
cmp_stmts([
if_stmt(branch(22, equal_op(cast([int], Wb_pc), int(1))), 
cmp_stmts([
goto_stmt(WB_WAIT_LOC, Write_back)

]) , 
cmp_stmts([]))
])), label_stmt(WB_ENTRY_LOC, 
cmp_stmts([
do_while_stmt(int(1), branch(24, 
cmp_stmts([label_stmt(while_3_continue, stmt([])), 
stmt(assign(Wb_st, int(2))), 
stmt(assign(Wb_pc, int(1))), 
goto_stmt(return_label, Write_back)
, label_stmt(WB_WAIT_LOC, 
stmt(assign(C_t, Data))), 
stmt(assign(C_req_up, int(1))), 
stmt(assign(Processed, int(1)))
]))), label_stmt(while_3_break, stmt([]))
])), label_stmt(return_label, 
return_stmt
)
])
])), 
function([void], function(Read, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([
stmt(assign(D, C)), 
stmt(assign(E_e, int(1))), 
if_stmt(branch(28, equal_op(cast([int], Wl_pc), int(1))), 
cmp_stmts([
if_stmt(branch(25, equal_op(cast([int], E_wl), int(1))), 
cmp_stmts([
stmt(assign(Wl_st, int(0)))
]) , 
cmp_stmts([
goto_stmt(_L, Read)

]))
]) , 
cmp_stmts([label_stmt(_L, 
if_stmt(branch(27, equal_op(cast([int], Wl_pc), int(2))), 
cmp_stmts([
if_stmt(branch(26, equal_op(cast([int], E_e), int(1))), 
cmp_stmts([
stmt(assign(Wl_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])))
])), 
stmt(assign(E_e, int(2))), 
stmt(assign(R_st, int(2))), 
return_stmt

])
])), 
function([void], function(Eval, [param_no_decl([void], [])]), [], 
cmp_stmts([
declaration([int], [Tmp]), 
declaration([int], [Tmp___0]), 
declaration([int], [Tmp___1]), 
declaration([int], [Tmp___2]), 
declaration([int], [Tmp___3]), 
cmp_stmts([
cmp_stmts([
do_while_stmt(int(1), branch(44, 
cmp_stmts([label_stmt(while_4_continue, stmt([])), 
if_stmt(branch(33, equal_op(cast([int], Wl_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(32, equal_op(cast([int], C1_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(31, equal_op(cast([int], C2_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(30, equal_op(cast([int], Wb_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(29, equal_op(cast([int], R_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
goto_stmt(while_4_break, Eval)

]))
]))
]))
]))
])), 
if_stmt(branch(35, equal_op(cast([int], Wl_st), int(0))), 
cmp_stmts([
cmp_stmts([
stmt(assign(Tmp, function_call(UC___VERIFIER_nondet_int, [])))
]), 
if_stmt(branch(34, Tmp), 
cmp_stmts([
cmp_stmts([
stmt(assign(Wl_st, int(1))), 
stmt(function_call(Write_loop, []))
])
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(37, equal_op(cast([int], C1_st), int(0))), 
cmp_stmts([
cmp_stmts([
stmt(assign(Tmp___0, function_call(UC___VERIFIER_nondet_int, [])))
]), 
if_stmt(branch(36, Tmp___0), 
cmp_stmts([
cmp_stmts([
stmt(assign(C1_st, int(1))), 
stmt(function_call(Compute1, []))
])
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(39, equal_op(cast([int], C2_st), int(0))), 
cmp_stmts([
cmp_stmts([
stmt(assign(Tmp___1, function_call(UC___VERIFIER_nondet_int, [])))
]), 
if_stmt(branch(38, Tmp___1), 
cmp_stmts([
cmp_stmts([
stmt(assign(C2_st, int(1))), 
stmt(function_call(Compute2, []))
])
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(41, equal_op(cast([int], Wb_st), int(0))), 
cmp_stmts([
cmp_stmts([
stmt(assign(Tmp___2, function_call(UC___VERIFIER_nondet_int, [])))
]), 
if_stmt(branch(40, Tmp___2), 
cmp_stmts([
cmp_stmts([
stmt(assign(Wb_st, int(1))), 
stmt(function_call(Write_back, []))
])
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(43, equal_op(cast([int], R_st), int(0))), 
cmp_stmts([
cmp_stmts([
stmt(assign(Tmp___3, function_call(UC___VERIFIER_nondet_int, [])))
]), 
if_stmt(branch(42, Tmp___3), 
cmp_stmts([
cmp_stmts([
stmt(assign(R_st, int(1))), 
stmt(function_call(Read, []))
])
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([]))
]))), label_stmt(while_4_break, stmt([]))
]), 
return_stmt

])
])), 
function([void], function(Start_simulation, [param_no_decl([void], [])]), [], 
cmp_stmts([
declaration([int], [Kernel_st]), 
cmp_stmts([
stmt(assign(Kernel_st, int(0))), 
if_stmt(branch(46, equal_op(cast([int], C_req_up), int(1))), 
cmp_stmts([
if_stmt(branch(45, not_equal_op(C, C_t)), 
cmp_stmts([
stmt(assign(C, C_t)), 
stmt(assign(E_c, int(0)))
]) , 
cmp_stmts([])), 
stmt(assign(C_req_up, int(0)))
]) , 
cmp_stmts([])), 
if_stmt(branch(47, equal_op(cast([int], Wl_i), int(1))), 
cmp_stmts([
stmt(assign(Wl_st, int(0)))
]) , 
cmp_stmts([
stmt(assign(Wl_st, int(2)))
])), 
if_stmt(branch(48, equal_op(cast([int], C1_i), int(1))), 
cmp_stmts([
stmt(assign(C1_st, int(0)))
]) , 
cmp_stmts([
stmt(assign(C1_st, int(2)))
])), 
if_stmt(branch(49, equal_op(cast([int], C2_i), int(1))), 
cmp_stmts([
stmt(assign(C2_st, int(0)))
]) , 
cmp_stmts([
stmt(assign(C2_st, int(2)))
])), 
if_stmt(branch(50, equal_op(cast([int], Wb_i), int(1))), 
cmp_stmts([
stmt(assign(Wb_st, int(0)))
]) , 
cmp_stmts([
stmt(assign(Wb_st, int(2)))
])), 
if_stmt(branch(51, equal_op(cast([int], R_i), int(1))), 
cmp_stmts([
stmt(assign(R_st, int(0)))
]) , 
cmp_stmts([
stmt(assign(R_st, int(2)))
])), 
if_stmt(branch(52, equal_op(cast([int], E_f), int(0))), 
cmp_stmts([
stmt(assign(E_f, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(53, equal_op(cast([int], E_g), int(0))), 
cmp_stmts([
stmt(assign(E_g, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(54, equal_op(cast([int], E_e), int(0))), 
cmp_stmts([
stmt(assign(E_e, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(55, equal_op(cast([int], E_c), int(0))), 
cmp_stmts([
stmt(assign(E_c, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(56, equal_op(cast([int], E_wl), int(0))), 
cmp_stmts([
stmt(assign(E_wl, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(60, equal_op(cast([int], Wl_pc), int(1))), 
cmp_stmts([
if_stmt(branch(57, equal_op(cast([int], E_wl), int(1))), 
cmp_stmts([
stmt(assign(Wl_st, int(0)))
]) , 
cmp_stmts([
goto_stmt(_L, Start_simulation)

]))
]) , 
cmp_stmts([label_stmt(_L, 
if_stmt(branch(59, equal_op(cast([int], Wl_pc), int(2))), 
cmp_stmts([
if_stmt(branch(58, equal_op(cast([int], E_e), int(1))), 
cmp_stmts([
stmt(assign(Wl_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])))
])), 
if_stmt(branch(62, equal_op(cast([int], C1_pc), int(1))), 
cmp_stmts([
if_stmt(branch(61, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(C1_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(64, equal_op(cast([int], C2_pc), int(1))), 
cmp_stmts([
if_stmt(branch(63, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(C2_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(66, equal_op(cast([int], Wb_pc), int(1))), 
cmp_stmts([
if_stmt(branch(65, equal_op(cast([int], E_g), int(1))), 
cmp_stmts([
stmt(assign(Wb_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(67, equal_op(cast([int], E_c), int(1))), 
cmp_stmts([
stmt(assign(R_st, int(0)))
]) , 
cmp_stmts([])), 
if_stmt(branch(68, equal_op(cast([int], E_e), int(1))), 
cmp_stmts([
stmt(assign(E_e, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(69, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(E_f, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(70, equal_op(cast([int], E_g), int(1))), 
cmp_stmts([
stmt(assign(E_g, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(71, equal_op(cast([int], E_c), int(1))), 
cmp_stmts([
stmt(assign(E_c, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(72, equal_op(cast([int], E_wl), int(1))), 
cmp_stmts([
stmt(assign(E_wl, int(2)))
]) , 
cmp_stmts([])), 
cmp_stmts([
do_while_stmt(int(1), branch(101, 
cmp_stmts([label_stmt(while_5_continue, stmt([])), 
cmp_stmts([
stmt(assign(Kernel_st, int(1))), 
stmt(function_call(Eval, []))
]), 
stmt(assign(Kernel_st, int(2))), 
if_stmt(branch(74, equal_op(cast([int], C_req_up), int(1))), 
cmp_stmts([
if_stmt(branch(73, not_equal_op(C, C_t)), 
cmp_stmts([
stmt(assign(C, C_t)), 
stmt(assign(E_c, int(0)))
]) , 
cmp_stmts([])), 
stmt(assign(C_req_up, int(0)))
]) , 
cmp_stmts([])), 
stmt(assign(Kernel_st, int(3))), 
if_stmt(branch(75, equal_op(cast([int], E_f), int(0))), 
cmp_stmts([
stmt(assign(E_f, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(76, equal_op(cast([int], E_g), int(0))), 
cmp_stmts([
stmt(assign(E_g, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(77, equal_op(cast([int], E_e), int(0))), 
cmp_stmts([
stmt(assign(E_e, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(78, equal_op(cast([int], E_c), int(0))), 
cmp_stmts([
stmt(assign(E_c, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(79, equal_op(cast([int], E_wl), int(0))), 
cmp_stmts([
stmt(assign(E_wl, int(1)))
]) , 
cmp_stmts([])), 
if_stmt(branch(83, equal_op(cast([int], Wl_pc), int(1))), 
cmp_stmts([
if_stmt(branch(80, equal_op(cast([int], E_wl), int(1))), 
cmp_stmts([
stmt(assign(Wl_st, int(0)))
]) , 
cmp_stmts([
goto_stmt(_L___0, Start_simulation)

]))
]) , 
cmp_stmts([label_stmt(_L___0, 
if_stmt(branch(82, equal_op(cast([int], Wl_pc), int(2))), 
cmp_stmts([
if_stmt(branch(81, equal_op(cast([int], E_e), int(1))), 
cmp_stmts([
stmt(assign(Wl_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])))
])), 
if_stmt(branch(85, equal_op(cast([int], C1_pc), int(1))), 
cmp_stmts([
if_stmt(branch(84, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(C1_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(87, equal_op(cast([int], C2_pc), int(1))), 
cmp_stmts([
if_stmt(branch(86, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(C2_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(89, equal_op(cast([int], Wb_pc), int(1))), 
cmp_stmts([
if_stmt(branch(88, equal_op(cast([int], E_g), int(1))), 
cmp_stmts([
stmt(assign(Wb_st, int(0)))
]) , 
cmp_stmts([]))
]) , 
cmp_stmts([])), 
if_stmt(branch(90, equal_op(cast([int], E_c), int(1))), 
cmp_stmts([
stmt(assign(R_st, int(0)))
]) , 
cmp_stmts([])), 
if_stmt(branch(91, equal_op(cast([int], E_e), int(1))), 
cmp_stmts([
stmt(assign(E_e, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(92, equal_op(cast([int], E_f), int(1))), 
cmp_stmts([
stmt(assign(E_f, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(93, equal_op(cast([int], E_g), int(1))), 
cmp_stmts([
stmt(assign(E_g, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(94, equal_op(cast([int], E_c), int(1))), 
cmp_stmts([
stmt(assign(E_c, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(95, equal_op(cast([int], E_wl), int(1))), 
cmp_stmts([
stmt(assign(E_wl, int(2)))
]) , 
cmp_stmts([])), 
if_stmt(branch(100, equal_op(cast([int], Wl_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(99, equal_op(cast([int], C1_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(98, equal_op(cast([int], C2_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(97, equal_op(cast([int], Wb_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
if_stmt(branch(96, equal_op(cast([int], R_st), int(0))), 
cmp_stmts([]) , 
cmp_stmts([
goto_stmt(while_5_break, Start_simulation)

]))
]))
]))
]))
]))
]))), label_stmt(while_5_break, stmt([]))
]), 
return_stmt

])
])), 
function([int], function(Main, [param_no_decl([void], [])]), [], 
cmp_stmts([
declaration([int], [UC___retres1]), 
cmp_stmts([
cmp_stmts([
stmt(assign(E_wl, int(2))), 
stmt(assign(E_c, E_wl)), 
stmt(assign(E_g, E_c)), 
stmt(assign(E_f, E_g)), 
stmt(assign(E_e, E_f)), 
stmt(assign(Wl_pc, int(0))), 
stmt(assign(C1_pc, int(0))), 
stmt(assign(C2_pc, int(0))), 
stmt(assign(Wb_pc, int(0))), 
stmt(assign(Wb_i, int(1))), 
stmt(assign(C2_i, Wb_i)), 
stmt(assign(C1_i, C2_i)), 
stmt(assign(Wl_i, C1_i)), 
stmt(assign(R_i, int(0))), 
stmt(assign(C_req_up, int(0))), 
stmt(assign(D, int(0))), 
stmt(assign(C, int(0))), 
stmt(function_call(Start_simulation, []))
]), 
stmt(assign(UC___retres1, int(0))), 
return_stmt((UC___retres1))

])
]))
]).
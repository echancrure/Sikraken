prolog_c([
declaration([typedef, long, int], [Ptrdiff_t]), 

declaration([typedef, long, unsigned, int], [Size_t]), 

declaration([typedef, int], [Wchar_t]), 

declaration([typedef, struct('anonymous', [struct_decl([long, long], [UC___max_align_ll]), struct_decl([long, double], [UC___max_align_ld])])], [Max_align_t]), 

declaration([typedef, struct('anonymous', [struct_decl([int], [Quot]), struct_decl([int], [Rem])])], [Div_t]), 

declaration([typedef, struct('anonymous', [struct_decl([long, int], [Quot]), struct_decl([long, int], [Rem])])], [Ldiv_t]), 

declaration([typedef, struct('anonymous', [struct_decl([long, long, int], [Quot]), struct_decl([long, long, int], [Rem])])], [Lldiv_t]), 

declaration([extern, Size_t], [function(UC___ctype_get_mb_cur_max, [param_no_decl([void], [])])]), 

declaration([extern, double], [function(Atof, [param([const, char], ptr_decl(pointer, UC___nptr))])]), 

declaration([extern, int], [function(Atoi, [param([const, char], ptr_decl(pointer, UC___nptr))])]), 

declaration([extern, long, int], [function(Atol, [param([const, char], ptr_decl(pointer, UC___nptr))])]), 

declaration([extern, long, long, int], [function(Atoll, [param([const, char], ptr_decl(pointer, UC___nptr))])]), 

declaration([extern, double], [function(Strtod, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr))])]), 

declaration([extern, float], [function(Strtof, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr))])]), 

declaration([extern, long, double], [function(Strtold, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr))])]), 

declaration([extern, long, int], [function(Strtol, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr)), param([int], UC___base)])]), 

declaration([extern, unsigned, long, int], [function(Strtoul, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr)), param([int], UC___base)])]), 

declaration([extern, long, long, int], [function(Strtoq, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr)), param([int], UC___base)])]), 

declaration([extern, unsigned, long, long, int], [function(Strtouq, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr)), param([int], UC___base)])]), 

declaration([extern, long, long, int], [function(Strtoll, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr)), param([int], UC___base)])]), 

declaration([extern, unsigned, long, long, int], [function(Strtoull, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___nptr)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___endptr)), param([int], UC___base)])]), 

declaration([extern, char], [ptr_decl(pointer, function(L64a, [param([long, int], UC___n)]))]), 

declaration([extern, long, int], [function(A64l, [param([const, char], ptr_decl(pointer, UC___s))])]), 

declaration([typedef, unsigned, char], [UC___u_char]), 

declaration([typedef, unsigned, short, int], [UC___u_short]), 

declaration([typedef, unsigned, int], [UC___u_int]), 

declaration([typedef, unsigned, long, int], [UC___u_long]), 

declaration([typedef, signed, char], [UC___int8_t]), 

declaration([typedef, unsigned, char], [UC___uint8_t]), 

declaration([typedef, signed, short, int], [UC___int16_t]), 

declaration([typedef, unsigned, short, int], [UC___uint16_t]), 

declaration([typedef, signed, int], [UC___int32_t]), 

declaration([typedef, unsigned, int], [UC___uint32_t]), 

declaration([typedef, signed, long, int], [UC___int64_t]), 

declaration([typedef, unsigned, long, int], [UC___uint64_t]), 

declaration([typedef, long, int], [UC___quad_t]), 

declaration([typedef, unsigned, long, int], [UC___u_quad_t]), 

declaration([typedef, long, int], [UC___intmax_t]), 

declaration([typedef, unsigned, long, int], [UC___uintmax_t]), 

declaration([typedef, unsigned, long, int], [UC___dev_t]), 

declaration([typedef, unsigned, int], [UC___uid_t]), 

declaration([typedef, unsigned, int], [UC___gid_t]), 

declaration([typedef, unsigned, long, int], [UC___ino_t]), 

declaration([typedef, unsigned, long, int], [UC___ino64_t]), 

declaration([typedef, unsigned, int], [UC___mode_t]), 

declaration([typedef, unsigned, long, int], [UC___nlink_t]), 

declaration([typedef, long, int], [UC___off_t]), 

declaration([typedef, long, int], [UC___off64_t]), 

declaration([typedef, int], [UC___pid_t]), 

declaration([typedef, struct('anonymous', [struct_decl([int], [array_decl(UC___val, int(2))])])], [UC___fsid_t]), 

declaration([typedef, long, int], [UC___clock_t]), 

declaration([typedef, unsigned, long, int], [UC___rlim_t]), 

declaration([typedef, unsigned, long, int], [UC___rlim64_t]), 

declaration([typedef, unsigned, int], [UC___id_t]), 

declaration([typedef, long, int], [UC___time_t]), 

declaration([typedef, unsigned, int], [UC___useconds_t]), 

declaration([typedef, long, int], [UC___suseconds_t]), 

declaration([typedef, int], [UC___daddr_t]), 

declaration([typedef, int], [UC___key_t]), 

declaration([typedef, int], [UC___clockid_t]), 

declaration([typedef, void], [ptr_decl(pointer, UC___timer_t)]), 

declaration([typedef, long, int], [UC___blksize_t]), 

declaration([typedef, long, int], [UC___blkcnt_t]), 

declaration([typedef, long, int], [UC___blkcnt64_t]), 

declaration([typedef, unsigned, long, int], [UC___fsblkcnt_t]), 

declaration([typedef, unsigned, long, int], [UC___fsblkcnt64_t]), 

declaration([typedef, unsigned, long, int], [UC___fsfilcnt_t]), 

declaration([typedef, unsigned, long, int], [UC___fsfilcnt64_t]), 

declaration([typedef, long, int], [UC___fsword_t]), 

declaration([typedef, long, int], [UC___ssize_t]), 

declaration([typedef, long, int], [UC___syscall_slong_t]), 

declaration([typedef, unsigned, long, int], [UC___syscall_ulong_t]), 

declaration([typedef, UC___off64_t], [UC___loff_t]), 

declaration([typedef, UC___quad_t], [ptr_decl(pointer, UC___qaddr_t)]), 

declaration([typedef, char], [ptr_decl(pointer, UC___caddr_t)]), 

declaration([typedef, long, int], [UC___intptr_t]), 

declaration([typedef, unsigned, int], [UC___socklen_t]), 

declaration([typedef, int], [UC___sig_atomic_t]), 

declaration([typedef, UC___u_char], [U_char]), 

declaration([typedef, UC___u_short], [U_short]), 

declaration([typedef, UC___u_int], [U_int]), 

declaration([typedef, UC___u_long], [U_long]), 

declaration([typedef, UC___quad_t], [Quad_t]), 

declaration([typedef, UC___u_quad_t], [U_quad_t]), 

declaration([typedef, UC___fsid_t], [Fsid_t]), 

declaration([typedef, UC___loff_t], [Loff_t]), 

declaration([typedef, UC___ino_t], [Ino_t]), 

declaration([typedef, UC___dev_t], [Dev_t]), 

declaration([typedef, UC___gid_t], [Gid_t]), 

declaration([typedef, UC___mode_t], [Mode_t]), 

declaration([typedef, UC___nlink_t], [Nlink_t]), 

declaration([typedef, UC___uid_t], [Uid_t]), 

declaration([typedef, UC___off_t], [Off_t]), 

declaration([typedef, UC___pid_t], [Pid_t]), 

declaration([typedef, UC___id_t], [Id_t]), 

declaration([typedef, UC___ssize_t], [Ssize_t]), 

declaration([typedef, UC___daddr_t], [Daddr_t]), 

declaration([typedef, UC___caddr_t], [Caddr_t]), 

declaration([typedef, UC___key_t], [Key_t]), 

declaration([typedef, UC___clock_t], [Clock_t]), 

declaration([typedef, UC___clockid_t], [Clockid_t]), 

declaration([typedef, UC___time_t], [Time_t]), 

declaration([typedef, UC___timer_t], [Timer_t]), 

declaration([typedef, unsigned, long, int], [Ulong]), 

declaration([typedef, unsigned, short, int], [Ushort]), 

declaration([typedef, unsigned, int], [Uint]), 

declaration([typedef, UC___int8_t], [Int8_t]), 

declaration([typedef, UC___int16_t], [Int16_t]), 

declaration([typedef, UC___int32_t], [Int32_t]), 

declaration([typedef, UC___int64_t], [Int64_t]), 

declaration([typedef, unsigned, int], [U_int8_t]), 

declaration([typedef, unsigned, int], [U_int16_t]), 

declaration([typedef, unsigned, int], [U_int32_t]), 

declaration([typedef, unsigned, int], [U_int64_t]), 

declaration([typedef, int], [Register_t]), 
function([static, dummy_function_specifier, dummy_declaration_specifiers], function(UC___bswap_32, [param([unsigned, int], UC___bsx)]), [], 
cmp_stmts([
return_stmt(function_call(UC___builtin_bswap32, [UC___bsx]))

])), 
function([static, dummy_function_specifier, dummy_declaration_specifiers], function(UC___bswap_64, [param([UC___uint64_t], UC___bsx)]), [], 
cmp_stmts([
return_stmt(function_call(UC___builtin_bswap64, [UC___bsx]))

])), 
function([static, dummy_function_specifier, dummy_declaration_specifiers], function(UC___uint16_identity, [param([UC___uint16_t], UC___x)]), [], 
cmp_stmts([
return_stmt(UC___x)

])), 
function([static, dummy_function_specifier, dummy_declaration_specifiers], function(UC___uint32_identity, [param([UC___uint32_t], UC___x)]), [], 
cmp_stmts([
return_stmt(UC___x)

])), 
function([static, dummy_function_specifier, dummy_declaration_specifiers], function(UC___uint64_identity, [param([UC___uint64_t], UC___x)]), [], 
cmp_stmts([
return_stmt(UC___x)

])), 

declaration([typedef, struct('anonymous', [struct_decl([unsigned, long, int], [array_decl(UC___val, (div_op(int(1024), (multiply_op(int(8), size_of_type([unsigned, long, int]))))))])])], [UC___sigset_t]), 

declaration([typedef, UC___sigset_t], [Sigset_t]), 

declaration([struct(timeval, [struct_decl([UC___time_t], [Tv_sec]), struct_decl([UC___suseconds_t], [Tv_usec])])]), 

declaration([struct(timespec, [struct_decl([UC___time_t], [Tv_sec]), struct_decl([UC___syscall_slong_t], [Tv_nsec])])]), 

declaration([typedef, UC___suseconds_t], [Suseconds_t]), 

declaration([typedef, long, int], [UC___fd_mask]), 

declaration([typedef, struct('anonymous', [struct_decl([UC___fd_mask], [array_decl(UC___fds_bits, div_op(int(1024), (multiply_op(int(8), cast([int], size_of_exp((UC___fd_mask)))))))])])], [Fd_set]), 

declaration([typedef, UC___fd_mask], [Fd_mask]), 

declaration([extern, int], [function(Select, [param([int], UC___nfds), param([Fd_set], ptr_decl(pointer(quals(restrict)), UC___readfds)), param([Fd_set], ptr_decl(pointer(quals(restrict)), UC___writefds)), param([Fd_set], ptr_decl(pointer(quals(restrict)), UC___exceptfds)), param([struct(timeval, 'forward')], ptr_decl(pointer(quals(restrict)), UC___timeout))])]), 

declaration([extern, int], [function(Pselect, [param([int], UC___nfds), param([Fd_set], ptr_decl(pointer(quals(restrict)), UC___readfds)), param([Fd_set], ptr_decl(pointer(quals(restrict)), UC___writefds)), param([Fd_set], ptr_decl(pointer(quals(restrict)), UC___exceptfds)), param([const, struct(timespec, 'forward')], ptr_decl(pointer(quals(restrict)), UC___timeout)), param([const, UC___sigset_t], ptr_decl(pointer(quals(restrict)), UC___sigmask))])]), 

declaration([typedef, UC___blksize_t], [Blksize_t]), 

declaration([typedef, UC___blkcnt_t], [Blkcnt_t]), 

declaration([typedef, UC___fsblkcnt_t], [Fsblkcnt_t]), 

declaration([typedef, UC___fsfilcnt_t], [Fsfilcnt_t]), 

declaration([struct(__pthread_rwlock_arch_t, [struct_decl([unsigned, int], [UC___readers]), struct_decl([unsigned, int], [UC___writers]), struct_decl([unsigned, int], [UC___wrphase_futex]), struct_decl([unsigned, int], [UC___writers_futex]), struct_decl([unsigned, int], [UC___pad3]), struct_decl([unsigned, int], [UC___pad4]), struct_decl([int], [UC___cur_writer]), struct_decl([int], [UC___shared]), struct_decl([signed, char], [UC___rwelision]), struct_decl([unsigned, char], [array_decl(UC___pad1, int(7))]), struct_decl([unsigned, long, int], [UC___pad2]), struct_decl([unsigned, int], [UC___flags])])]), 

declaration([typedef, struct(__pthread_internal_list, [struct_decl([struct(__pthread_internal_list, 'forward')], [ptr_decl(pointer, UC___prev)]), struct_decl([struct(__pthread_internal_list, 'forward')], [ptr_decl(pointer, UC___next)])])], [UC___pthread_list_t]), 

declaration([struct(__pthread_mutex_s, [struct_decl([int], [UC___lock]), struct_decl([unsigned, int], [UC___count]), struct_decl([int], [UC___owner]), struct_decl([unsigned, int], [UC___nusers]), struct_decl([int], [UC___kind]), struct_decl([short], [UC___spins]), struct_decl([short], [UC___elision]), struct_decl([UC___pthread_list_t], [UC___list])])]), 

declaration([struct(__pthread_cond_s, [struct_decl_anonymous(union('anonymous', [struct_decl([unsigned, long, long, int], [UC___wseq]), struct_decl([struct('anonymous', [struct_decl([unsigned, int], [UC___low]), struct_decl([unsigned, int], [UC___high])])], [UC___wseq32])])), struct_decl_anonymous(union('anonymous', [struct_decl([unsigned, long, long, int], [UC___g1_start]), struct_decl([struct('anonymous', [struct_decl([unsigned, int], [UC___low]), struct_decl([unsigned, int], [UC___high])])], [UC___g1_start32])])), struct_decl([unsigned, int], [array_decl(UC___g_refs, int(2))]), struct_decl([unsigned, int], [array_decl(UC___g_size, int(2))]), struct_decl([unsigned, int], [UC___g1_orig_size]), struct_decl([unsigned, int], [UC___wrefs]), struct_decl([unsigned, int], [array_decl(UC___g_signals, int(2))])])]), 

declaration([typedef, unsigned, long, int], [Pthread_t]), 

declaration([typedef, union('anonymous', [struct_decl([char], [array_decl(UC___size, int(4))]), struct_decl([int], [UC___align])])], [Pthread_mutexattr_t]), 

declaration([typedef, union('anonymous', [struct_decl([char], [array_decl(UC___size, int(4))]), struct_decl([int], [UC___align])])], [Pthread_condattr_t]), 

declaration([typedef, unsigned, int], [Pthread_key_t]), 

declaration([typedef, int], [Pthread_once_t]), 

declaration([union(pthread_attr_t, [struct_decl([char], [array_decl(UC___size, int(56))]), struct_decl([long, int], [UC___align])])]), 

declaration([typedef, union(pthread_attr_t, 'forward')], [Pthread_attr_t]), 

declaration([typedef, union('anonymous', [struct_decl([struct(__pthread_mutex_s, 'forward')], [UC___data]), struct_decl([char], [array_decl(UC___size, int(40))]), struct_decl([long, int], [UC___align])])], [Pthread_mutex_t]), 

declaration([typedef, union('anonymous', [struct_decl([struct(__pthread_cond_s, 'forward')], [UC___data]), struct_decl([char], [array_decl(UC___size, int(48))]), struct_decl([long, long, int], [UC___align])])], [Pthread_cond_t]), 

declaration([typedef, union('anonymous', [struct_decl([struct(__pthread_rwlock_arch_t, 'forward')], [UC___data]), struct_decl([char], [array_decl(UC___size, int(56))]), struct_decl([long, int], [UC___align])])], [Pthread_rwlock_t]), 

declaration([typedef, union('anonymous', [struct_decl([char], [array_decl(UC___size, int(8))]), struct_decl([long, int], [UC___align])])], [Pthread_rwlockattr_t]), 

declaration([typedef, volatile, int], [Pthread_spinlock_t]), 

declaration([typedef, union('anonymous', [struct_decl([char], [array_decl(UC___size, int(32))]), struct_decl([long, int], [UC___align])])], [Pthread_barrier_t]), 

declaration([typedef, union('anonymous', [struct_decl([char], [array_decl(UC___size, int(4))]), struct_decl([int], [UC___align])])], [Pthread_barrierattr_t]), 

declaration([extern, long, int], [function(Random, [param_no_decl([void], [])])]), 

declaration([extern, void], [function(Srandom, [param([unsigned, int], UC___seed)])]), 

declaration([extern, char], [ptr_decl(pointer, function(Initstate, [param([unsigned, int], UC___seed), param([char], ptr_decl(pointer, UC___statebuf)), param([Size_t], UC___statelen)]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Setstate, [param([char], ptr_decl(pointer, UC___statebuf))]))]), 

declaration([struct(random_data, [struct_decl([Int32_t], [ptr_decl(pointer, Fptr)]), struct_decl([Int32_t], [ptr_decl(pointer, Rptr)]), struct_decl([Int32_t], [ptr_decl(pointer, State)]), struct_decl([int], [Rand_type]), struct_decl([int], [Rand_deg]), struct_decl([int], [Rand_sep]), struct_decl([Int32_t], [ptr_decl(pointer, End_ptr)])])]), 

declaration([extern, int], [function(Random_r, [param([struct(random_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buf)), param([Int32_t], ptr_decl(pointer(quals(restrict)), UC___result))])]), 

declaration([extern, int], [function(Srandom_r, [param([unsigned, int], UC___seed), param([struct(random_data, 'forward')], ptr_decl(pointer, UC___buf))])]), 

declaration([extern, int], [function(Initstate_r, [param([unsigned, int], UC___seed), param([char], ptr_decl(pointer(quals(restrict)), UC___statebuf)), param([Size_t], UC___statelen), param([struct(random_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buf))])]), 

declaration([extern, int], [function(Setstate_r, [param([char], ptr_decl(pointer(quals(restrict)), UC___statebuf)), param([struct(random_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buf))])]), 

declaration([extern, int], [function(Rand, [param_no_decl([void], [])])]), 

declaration([extern, void], [function(Srand, [param([unsigned, int], UC___seed)])]), 

declaration([extern, int], [function(Rand_r, [param([unsigned, int], ptr_decl(pointer, UC___seed))])]), 

declaration([extern, double], [function(Drand48, [param_no_decl([void], [])])]), 

declaration([extern, double], [function(Erand48, [param([unsigned, short, int], array_decl(UC___xsubi, int(3)))])]), 

declaration([extern, long, int], [function(Lrand48, [param_no_decl([void], [])])]), 

declaration([extern, long, int], [function(Nrand48, [param([unsigned, short, int], array_decl(UC___xsubi, int(3)))])]), 

declaration([extern, long, int], [function(Mrand48, [param_no_decl([void], [])])]), 

declaration([extern, long, int], [function(Jrand48, [param([unsigned, short, int], array_decl(UC___xsubi, int(3)))])]), 

declaration([extern, void], [function(Srand48, [param([long, int], UC___seedval)])]), 

declaration([extern, unsigned, short, int], [ptr_decl(pointer, function(Seed48, [param([unsigned, short, int], array_decl(UC___seed16v, int(3)))]))]), 

declaration([extern, void], [function(Lcong48, [param([unsigned, short, int], array_decl(UC___param, int(7)))])]), 

declaration([struct(drand48_data, [struct_decl([unsigned, short, int], [array_decl(UC___x, int(3))]), struct_decl([unsigned, short, int], [array_decl(UC___old_x, int(3))]), struct_decl([unsigned, short, int], [UC___c]), struct_decl([unsigned, short, int], [UC___init]), struct_decl([unsigned, long, long, int], [UC___a])])]), 

declaration([extern, int], [function(Drand48_r, [param([struct(drand48_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buffer)), param([double], ptr_decl(pointer(quals(restrict)), UC___result))])]), 

declaration([extern, int], [function(Erand48_r, [param([unsigned, short, int], array_decl(UC___xsubi, int(3))), param([struct(drand48_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buffer)), param([double], ptr_decl(pointer(quals(restrict)), UC___result))])]), 

declaration([extern, int], [function(Lrand48_r, [param([struct(drand48_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buffer)), param([long, int], ptr_decl(pointer(quals(restrict)), UC___result))])]), 

declaration([extern, int], [function(Nrand48_r, [param([unsigned, short, int], array_decl(UC___xsubi, int(3))), param([struct(drand48_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buffer)), param([long, int], ptr_decl(pointer(quals(restrict)), UC___result))])]), 

declaration([extern, int], [function(Mrand48_r, [param([struct(drand48_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buffer)), param([long, int], ptr_decl(pointer(quals(restrict)), UC___result))])]), 

declaration([extern, int], [function(Jrand48_r, [param([unsigned, short, int], array_decl(UC___xsubi, int(3))), param([struct(drand48_data, 'forward')], ptr_decl(pointer(quals(restrict)), UC___buffer)), param([long, int], ptr_decl(pointer(quals(restrict)), UC___result))])]), 

declaration([extern, int], [function(Srand48_r, [param([long, int], UC___seedval), param([struct(drand48_data, 'forward')], ptr_decl(pointer, UC___buffer))])]), 

declaration([extern, int], [function(Seed48_r, [param([unsigned, short, int], array_decl(UC___seed16v, int(3))), param([struct(drand48_data, 'forward')], ptr_decl(pointer, UC___buffer))])]), 

declaration([extern, int], [function(Lcong48_r, [param([unsigned, short, int], array_decl(UC___param, int(7))), param([struct(drand48_data, 'forward')], ptr_decl(pointer, UC___buffer))])]), 

declaration([extern, void], [ptr_decl(pointer, function(Malloc, [param([Size_t], UC___size)]))]), 

declaration([extern, void], [ptr_decl(pointer, function(Calloc, [param([Size_t], UC___nmemb), param([Size_t], UC___size)]))]), 

declaration([extern, void], [ptr_decl(pointer, function(Realloc, [param([void], ptr_decl(pointer, UC___ptr)), param([Size_t], UC___size)]))]), 

declaration([extern, void], [function(Free, [param([void], ptr_decl(pointer, UC___ptr))])]), 

declaration([extern, void], [ptr_decl(pointer, function(Alloca, [param([Size_t], UC___size)]))]), 

declaration([extern, void], [ptr_decl(pointer, function(Valloc, [param([Size_t], UC___size)]))]), 

declaration([extern, int], [function(Posix_memalign, [param([void], ptr_decl(pointer(pointer), UC___memptr)), param([Size_t], UC___alignment), param([Size_t], UC___size)])]), 

declaration([extern, void], [ptr_decl(pointer, function(Aligned_alloc, [param([Size_t], UC___alignment), param([Size_t], UC___size)]))]), 

declaration([extern, void], [function(Abort, [param_no_decl([void], [])])]), 

declaration([extern, int], [function(Atexit, [param([void], function(ptr_decl(pointer, UC___func), [param_no_decl([void], [])]))])]), 

declaration([extern, int], [function(At_quick_exit, [param([void], function(ptr_decl(pointer, UC___func), [param_no_decl([void], [])]))])]), 

declaration([extern, int], [function(On_exit, [param([void], function(ptr_decl(pointer, UC___func), [param([int], UC___status), param([void], ptr_decl(pointer, UC___arg))])), param([void], ptr_decl(pointer, UC___arg))])]), 

declaration([extern, void], [function(Exit, [param([int], UC___status)])]), 

declaration([extern, void], [function(Quick_exit, [param([int], UC___status)])]), 

declaration([extern, void], [function(UC__Exit, [param([int], UC___status)])]), 

declaration([extern, char], [ptr_decl(pointer, function(Getenv, [param([const, char], ptr_decl(pointer, UC___name))]))]), 

declaration([extern, int], [function(Putenv, [param([char], ptr_decl(pointer, UC___string))])]), 

declaration([extern, int], [function(Setenv, [param([const, char], ptr_decl(pointer, UC___name)), param([const, char], ptr_decl(pointer, UC___value)), param([int], UC___replace)])]), 

declaration([extern, int], [function(Unsetenv, [param([const, char], ptr_decl(pointer, UC___name))])]), 

declaration([extern, int], [function(Clearenv, [param_no_decl([void], [])])]), 

declaration([extern, char], [ptr_decl(pointer, function(Mktemp, [param([char], ptr_decl(pointer, UC___template))]))]), 

declaration([extern, int], [function(Mkstemp, [param([char], ptr_decl(pointer, UC___template))])]), 

declaration([extern, int], [function(Mkstemps, [param([char], ptr_decl(pointer, UC___template)), param([int], UC___suffixlen)])]), 

declaration([extern, char], [ptr_decl(pointer, function(Mkdtemp, [param([char], ptr_decl(pointer, UC___template))]))]), 

declaration([extern, int], [function(System, [param([const, char], ptr_decl(pointer, UC___command))])]), 

declaration([extern, char], [ptr_decl(pointer, function(Realpath, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___name)), param([char], ptr_decl(pointer(quals(restrict)), UC___resolved))]))]), 

declaration([typedef, int], [function(ptr_decl(pointer, UC___compar_fn_t), [param_no_decl([const, void], dummy_abstract_declarator), param_no_decl([const, void], dummy_abstract_declarator)])]), 

declaration([extern, void], [ptr_decl(pointer, function(Bsearch, [param([const, void], ptr_decl(pointer, UC___key)), param([const, void], ptr_decl(pointer, UC___base)), param([Size_t], UC___nmemb), param([Size_t], UC___size), param([UC___compar_fn_t], UC___compar)]))]), 

declaration([extern, void], [function(Qsort, [param([void], ptr_decl(pointer, UC___base)), param([Size_t], UC___nmemb), param([Size_t], UC___size), param([UC___compar_fn_t], UC___compar)])]), 

declaration([extern, int], [function(Abs, [param([int], UC___x)])]), 

declaration([extern, long, int], [function(Labs, [param([long, int], UC___x)])]), 

declaration([extern, long, long, int], [function(Llabs, [param([long, long, int], UC___x)])]), 

declaration([extern, Div_t], [function(Div, [param([int], UC___numer), param([int], UC___denom)])]), 

declaration([extern, Ldiv_t], [function(Ldiv, [param([long, int], UC___numer), param([long, int], UC___denom)])]), 

declaration([extern, Lldiv_t], [function(Lldiv, [param([long, long, int], UC___numer), param([long, long, int], UC___denom)])]), 

declaration([extern, char], [ptr_decl(pointer, function(Ecvt, [param([double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign))]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Fcvt, [param([double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign))]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Gcvt, [param([double], UC___value), param([int], UC___ndigit), param([char], ptr_decl(pointer, UC___buf))]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Qecvt, [param([long, double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign))]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Qfcvt, [param([long, double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign))]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Qgcvt, [param([long, double], UC___value), param([int], UC___ndigit), param([char], ptr_decl(pointer, UC___buf))]))]), 

declaration([extern, int], [function(Ecvt_r, [param([double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign)), param([char], ptr_decl(pointer(quals(restrict)), UC___buf)), param([Size_t], UC___len)])]), 

declaration([extern, int], [function(Fcvt_r, [param([double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign)), param([char], ptr_decl(pointer(quals(restrict)), UC___buf)), param([Size_t], UC___len)])]), 

declaration([extern, int], [function(Qecvt_r, [param([long, double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign)), param([char], ptr_decl(pointer(quals(restrict)), UC___buf)), param([Size_t], UC___len)])]), 

declaration([extern, int], [function(Qfcvt_r, [param([long, double], UC___value), param([int], UC___ndigit), param([int], ptr_decl(pointer(quals(restrict)), UC___decpt)), param([int], ptr_decl(pointer(quals(restrict)), UC___sign)), param([char], ptr_decl(pointer(quals(restrict)), UC___buf)), param([Size_t], UC___len)])]), 

declaration([extern, int], [function(Mblen, [param([const, char], ptr_decl(pointer, UC___s)), param([Size_t], UC___n)])]), 

declaration([extern, int], [function(Mbtowc, [param([Wchar_t], ptr_decl(pointer(quals(restrict)), UC___pwc)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___s)), param([Size_t], UC___n)])]), 

declaration([extern, int], [function(Wctomb, [param([char], ptr_decl(pointer, UC___s)), param([Wchar_t], UC___wchar)])]), 

declaration([extern, Size_t], [function(Mbstowcs, [param([Wchar_t], ptr_decl(pointer(quals(restrict)), UC___pwcs)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___s)), param([Size_t], UC___n)])]), 

declaration([extern, Size_t], [function(Wcstombs, [param([char], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, Wchar_t], ptr_decl(pointer(quals(restrict)), UC___pwcs)), param([Size_t], UC___n)])]), 

declaration([extern, int], [function(Rpmatch, [param([const, char], ptr_decl(pointer, UC___response))])]), 

declaration([extern, int], [function(Getsubopt, [param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___optionp)), param([char], ptr_decl(pointer(quals(const), pointer(quals(restrict))), UC___tokens)), param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___valuep))])]), 

declaration([extern, int], [function(Getloadavg, [param([double], array_decl(UC___loadavg, int(0))), param([int], UC___nelem)])]), 

declaration([extern, int], [function(UC___VERIFIER_nondet_int, [param_no_decl([void], [])])]), 

declaration([extern, char], [function(UC___VERIFIER_nondet_char, [param_no_decl([void], [])])]), 
function([int], function(Atoi, [param([const, char], ptr_decl(pointer, S))]), [], 
cmp_stmts([
declaration([long, int], [initialised(V, int(0))]), 
declaration([int], [initialised(Sign, int(1))]), 
while_stmt(branch(1, equal_op(deref(S), 32)), 
stmt(postfix_inc_op(S))), 
switch_stmt(deref(S), 
cmp_stmts([case_stmt(45, 
stmt(assign(Sign, minus_op(int(1))))), case_stmt(43, 
stmt(prefix_inc_op(S)))
])), 
while_stmt(branch(2, and_op(greater_op((minus_op(deref(S), 48)), int(0)), less_op((minus_op(deref(S), 48)), int(10)))), 
cmp_stmts([
stmt(assign(V, minus_op(plus_op(multiply_op(V, int(10)), deref(S)), 48))), 
stmt(prefix_inc_op(S))
])), 
return_stmt(cond_exp(branch(4, equal_op(Sign, minus_op(int(1)))), minus_op(V), V))

])), 
function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [initialised(In_len, function_call(UC___VERIFIER_nondet_int, []))]), 
if_stmt(branch(5, less_op(In_len, int(1))), 
cmp_stmts([
return_stmt(int(1))

]) ), 
declaration([char], [initialised(ptr_decl(pointer, In), function_call(UC___builtin_alloca, [In_len]))]), 
cmp_stmts([
declaration([int], [initialised(I, int(0))]), 
while_stmt(branch(6, less_op(I, minus_op(In_len, int(1)))), 
cmp_stmts([
cmp_stmts([
stmt(assign(index(In, I), function_call(UC___VERIFIER_nondet_char, [])))
]), postfix_inc_op(I)]))]), 
stmt(assign(index(In, minus_op(In_len, int(1))), int(0))), 
return_stmt(function_call(Atoi, [In]))

]))
]).
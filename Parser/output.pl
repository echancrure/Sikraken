prolog_c([
declaration([typedef, long, unsigned, int], [Size_t]), 

declaration([typedef, va_list], [UC___gnuc_va_list]), 

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

declaration([typedef, UC___int8_t], [UC___int_least8_t]), 

declaration([typedef, UC___uint8_t], [UC___uint_least8_t]), 

declaration([typedef, UC___int16_t], [UC___int_least16_t]), 

declaration([typedef, UC___uint16_t], [UC___uint_least16_t]), 

declaration([typedef, UC___int32_t], [UC___int_least32_t]), 

declaration([typedef, UC___uint32_t], [UC___uint_least32_t]), 

declaration([typedef, UC___int64_t], [UC___int_least64_t]), 

declaration([typedef, UC___uint64_t], [UC___uint_least64_t]), 

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

declaration([typedef, long, int], [UC___suseconds64_t]), 

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

declaration([typedef, char], [ptr_decl(pointer, UC___caddr_t)]), 

declaration([typedef, long, int], [UC___intptr_t]), 

declaration([typedef, unsigned, int], [UC___socklen_t]), 

declaration([typedef, int], [UC___sig_atomic_t]), 

declaration([typedef, struct('anonymous', [struct_decl([int], [UC___count]), struct_decl([union('anonymous', [struct_decl([unsigned, int], [UC___wch]), struct_decl([char], [array_decl(UC___wchb, int(4))])])], [UC___value])])], [UC___mbstate_t]), 

declaration([typedef, struct(_G_fpos_t, [struct_decl([UC___off_t], [UC___pos]), struct_decl([UC___mbstate_t], [UC___state])])], [UC___fpos_t]), 

declaration([typedef, struct(_G_fpos64_t, [struct_decl([UC___off64_t], [UC___pos]), struct_decl([UC___mbstate_t], [UC___state])])], [UC___fpos64_t]), 

declaration([struct(_IO_FILE, 'forward')]), 

declaration([typedef, struct(_IO_FILE, 'forward')], [UC___FILE]), 

declaration([struct(_IO_FILE, 'forward')]), 

declaration([typedef, struct(_IO_FILE, 'forward')], [UC_FILE]), 

declaration([struct(_IO_FILE, 'forward')]), 

declaration([struct(_IO_marker, 'forward')]), 

declaration([struct(_IO_codecvt, 'forward')]), 

declaration([struct(_IO_wide_data, 'forward')]), 

declaration([typedef, void], [UC__IO_lock_t]), 

declaration([struct(_IO_FILE, [struct_decl([int], [UC__flags]), struct_decl([char], [ptr_decl(pointer, UC__IO_read_ptr)]), struct_decl([char], [ptr_decl(pointer, UC__IO_read_end)]), struct_decl([char], [ptr_decl(pointer, UC__IO_read_base)]), struct_decl([char], [ptr_decl(pointer, UC__IO_write_base)]), struct_decl([char], [ptr_decl(pointer, UC__IO_write_ptr)]), struct_decl([char], [ptr_decl(pointer, UC__IO_write_end)]), struct_decl([char], [ptr_decl(pointer, UC__IO_buf_base)]), struct_decl([char], [ptr_decl(pointer, UC__IO_buf_end)]), struct_decl([char], [ptr_decl(pointer, UC__IO_save_base)]), struct_decl([char], [ptr_decl(pointer, UC__IO_backup_base)]), struct_decl([char], [ptr_decl(pointer, UC__IO_save_end)]), struct_decl([struct(_IO_marker, 'forward')], [ptr_decl(pointer, UC__markers)]), struct_decl([struct(_IO_FILE, 'forward')], [ptr_decl(pointer, UC__chain)]), struct_decl([int], [UC__fileno]), struct_decl([int], [UC__flags2]), struct_decl([UC___off_t], [UC__old_offset]), struct_decl([unsigned, short], [UC__cur_column]), struct_decl([signed, char], [UC__vtable_offset]), struct_decl([char], [array_decl(UC__shortbuf, int(1))]), struct_decl([UC__IO_lock_t], [ptr_decl(pointer, UC__lock)]), struct_decl([UC___off64_t], [UC__offset]), struct_decl([struct(_IO_codecvt, 'forward')], [ptr_decl(pointer, UC__codecvt)]), struct_decl([struct(_IO_wide_data, 'forward')], [ptr_decl(pointer, UC__wide_data)]), struct_decl([struct(_IO_FILE, 'forward')], [ptr_decl(pointer, UC__freeres_list)]), struct_decl([void], [ptr_decl(pointer, UC__freeres_buf)]), struct_decl([Size_t], [UC___pad5]), struct_decl([int], [UC__mode]), struct_decl([char], [array_decl(UC__unused2, minus_op(minus_op(multiply_op(int(15), size_of_type([int])), multiply_op(int(4), size_of_type(typenamedummy1))), size_of_exp((Size_t))))])])]), 

declaration([typedef, UC___ssize_t], [function(Cookie_read_function_t, [param([void], ptr_decl(pointer, UC___cookie)), param([char], ptr_decl(pointer, UC___buf)), param([Size_t], UC___nbytes)])]), 

declaration([typedef, UC___ssize_t], [function(Cookie_write_function_t, [param([void], ptr_decl(pointer, UC___cookie)), param([const, char], ptr_decl(pointer, UC___buf)), param([Size_t], UC___nbytes)])]), 

declaration([typedef, int], [function(Cookie_seek_function_t, [param([void], ptr_decl(pointer, UC___cookie)), param([UC___off64_t], ptr_decl(pointer, UC___pos)), param([int], UC___w)])]), 

declaration([typedef, int], [function(Cookie_close_function_t, [param([void], ptr_decl(pointer, UC___cookie))])]), 

declaration([typedef, struct(_IO_cookie_io_functions_t, [struct_decl([Cookie_read_function_t], [ptr_decl(pointer, Read)]), struct_decl([Cookie_write_function_t], [ptr_decl(pointer, Write)]), struct_decl([Cookie_seek_function_t], [ptr_decl(pointer, Seek)]), struct_decl([Cookie_close_function_t], [ptr_decl(pointer, Close)])])], [Cookie_io_functions_t]), 

declaration([typedef, UC___gnuc_va_list], [Va_list]), 

declaration([typedef, UC___off_t], [Off_t]), 

declaration([typedef, UC___ssize_t], [Ssize_t]), 

declaration([typedef, UC___fpos_t], [Fpos_t]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, Stdin)]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, Stdout)]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, Stderr)]), 

declaration([extern, int], [function(Remove, [param([const, char], ptr_decl(pointer, UC___filename))])]), 

declaration([extern, int], [function(Rename, [param([const, char], ptr_decl(pointer, UC___old)), param([const, char], ptr_decl(pointer, UC___new))])]), 

declaration([extern, int], [function(Renameat, [param([int], UC___oldfd), param([const, char], ptr_decl(pointer, UC___old)), param([int], UC___newfd), param([const, char], ptr_decl(pointer, UC___new))])]), 

declaration([extern, int], [function(Fclose, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Tmpfile, [param_no_decl([void], [])]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Tmpnam, [param_no_decl([char], dummy_abstract_declarator)]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Tmpnam_r, [param([char], array_decl(UC___s, int(20)))]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Tempnam, [param([const, char], ptr_decl(pointer, UC___dir)), param([const, char], ptr_decl(pointer, UC___pfx))]))]), 

declaration([extern, int], [function(Fflush, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Fflush_unlocked, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Fopen, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___filename)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___modes))]))]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Freopen, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___filename)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___modes)), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))]))]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Fdopen, [param([int], UC___fd), param([const, char], ptr_decl(pointer, UC___modes))]))]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Fopencookie, [param([void], ptr_decl(pointer(quals(restrict)), UC___magic_cookie)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___modes)), param([Cookie_io_functions_t], UC___io_funcs)]))]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Fmemopen, [param([void], ptr_decl(pointer, UC___s)), param([Size_t], UC___len), param([const, char], ptr_decl(pointer, UC___modes))]))]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Open_memstream, [param([char], ptr_decl(pointer(pointer), UC___bufloc)), param([Size_t], ptr_decl(pointer, UC___sizeloc))]))]), 

declaration([extern, void], [function(Setbuf, [param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream)), param([char], ptr_decl(pointer(quals(restrict)), UC___buf))])]), 

declaration([extern, int], [function(Setvbuf, [param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream)), param([char], ptr_decl(pointer(quals(restrict)), UC___buf)), param([int], UC___modes), param([Size_t], UC___n)])]), 

declaration([extern, void], [function(Setbuffer, [param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream)), param([char], ptr_decl(pointer(quals(restrict)), UC___buf)), param([Size_t], UC___size)])]), 

declaration([extern, void], [function(Setlinebuf, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Fprintf, variable_length_args([param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Printf, variable_length_args([param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Sprintf, variable_length_args([param([char], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Vfprintf, [param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vprintf, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vsprintf, [param([char], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Snprintf, variable_length_args([param([char], ptr_decl(pointer(quals(restrict)), UC___s)), param([Size_t], UC___maxlen), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Vsnprintf, [param([char], ptr_decl(pointer(quals(restrict)), UC___s)), param([Size_t], UC___maxlen), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vasprintf, [param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___ptr)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___f)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(UC___asprintf, variable_length_args([param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___ptr)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___fmt))]))]), 

declaration([extern, int], [function(Asprintf, variable_length_args([param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___ptr)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___fmt))]))]), 

declaration([extern, int], [function(Vdprintf, [param([int], UC___fd), param([const, char], ptr_decl(pointer(quals(restrict)), UC___fmt)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Dprintf, variable_length_args([param([int], UC___fd), param([const, char], ptr_decl(pointer(quals(restrict)), UC___fmt))]))]), 

declaration([extern, int], [function(Fscanf, variable_length_args([param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Scanf, variable_length_args([param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Sscanf, variable_length_args([param([const, char], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Fscanf, variable_length_args([param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Scanf, variable_length_args([param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Sscanf, variable_length_args([param([const, char], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format))]))]), 

declaration([extern, int], [function(Vfscanf, [param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vscanf, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vsscanf, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vfscanf, [param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vscanf, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Vsscanf, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___s)), param([const, char], ptr_decl(pointer(quals(restrict)), UC___format)), param([UC___gnuc_va_list], UC___arg)])]), 

declaration([extern, int], [function(Fgetc, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Getc, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Getchar, [param_no_decl([void], [])])]), 

declaration([extern, int], [function(Getc_unlocked, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Getchar_unlocked, [param_no_decl([void], [])])]), 

declaration([extern, int], [function(Fgetc_unlocked, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Fputc, [param([int], UC___c), param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Putc, [param([int], UC___c), param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Putchar, [param([int], UC___c)])]), 

declaration([extern, int], [function(Fputc_unlocked, [param([int], UC___c), param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Putc_unlocked, [param([int], UC___c), param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Putchar_unlocked, [param([int], UC___c)])]), 

declaration([extern, int], [function(Getw, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Putw, [param([int], UC___w), param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, char], [ptr_decl(pointer, function(Fgets, [param([char], ptr_decl(pointer(quals(restrict)), UC___s)), param([int], UC___n), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))]))]), 

declaration([extern, UC___ssize_t], [function(UC___getdelim, [param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___lineptr)), param([Size_t], ptr_decl(pointer(quals(restrict)), UC___n)), param([int], UC___delimiter), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))])]), 

declaration([extern, UC___ssize_t], [function(Getdelim, [param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___lineptr)), param([Size_t], ptr_decl(pointer(quals(restrict)), UC___n)), param([int], UC___delimiter), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))])]), 

declaration([extern, UC___ssize_t], [function(Getline, [param([char], ptr_decl(pointer(pointer(quals(restrict))), UC___lineptr)), param([Size_t], ptr_decl(pointer(quals(restrict)), UC___n)), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))])]), 

declaration([extern, int], [function(Fputs, [param([const, char], ptr_decl(pointer(quals(restrict)), UC___s)), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))])]), 

declaration([extern, int], [function(Puts, [param([const, char], ptr_decl(pointer, UC___s))])]), 

declaration([extern, int], [function(Ungetc, [param([int], UC___c), param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, Size_t], [function(Fread, [param([void], ptr_decl(pointer(quals(restrict)), UC___ptr)), param([Size_t], UC___size), param([Size_t], UC___n), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))])]), 

declaration([extern, Size_t], [function(Fwrite, [param([const, void], ptr_decl(pointer(quals(restrict)), UC___ptr)), param([Size_t], UC___size), param([Size_t], UC___n), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___s))])]), 

declaration([extern, Size_t], [function(Fread_unlocked, [param([void], ptr_decl(pointer(quals(restrict)), UC___ptr)), param([Size_t], UC___size), param([Size_t], UC___n), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))])]), 

declaration([extern, Size_t], [function(Fwrite_unlocked, [param([const, void], ptr_decl(pointer(quals(restrict)), UC___ptr)), param([Size_t], UC___size), param([Size_t], UC___n), param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream))])]), 

declaration([extern, int], [function(Fseek, [param([UC_FILE], ptr_decl(pointer, UC___stream)), param([long, int], UC___off), param([int], UC___whence)])]), 

declaration([extern, long, int], [function(Ftell, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, void], [function(Rewind, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Fseeko, [param([UC_FILE], ptr_decl(pointer, UC___stream)), param([UC___off_t], UC___off), param([int], UC___whence)])]), 

declaration([extern, UC___off_t], [function(Ftello, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Fgetpos, [param([UC_FILE], ptr_decl(pointer(quals(restrict)), UC___stream)), param([Fpos_t], ptr_decl(pointer(quals(restrict)), UC___pos))])]), 

declaration([extern, int], [function(Fsetpos, [param([UC_FILE], ptr_decl(pointer, UC___stream)), param([const, Fpos_t], ptr_decl(pointer, UC___pos))])]), 

declaration([extern, void], [function(Clearerr, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Feof, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Ferror, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, void], [function(Clearerr_unlocked, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Feof_unlocked, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Ferror_unlocked, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, void], [function(Perror, [param([const, char], ptr_decl(pointer, UC___s))])]), 

declaration([extern, int], [function(Fileno, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Fileno_unlocked, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Pclose, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, UC_FILE], [ptr_decl(pointer, function(Popen, [param([const, char], ptr_decl(pointer, UC___command)), param([const, char], ptr_decl(pointer, UC___modes))]))]), 

declaration([extern, char], [ptr_decl(pointer, function(Ctermid, [param([char], ptr_decl(pointer, UC___s))]))]), 

declaration([extern, void], [function(Flockfile, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(Ftrylockfile, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, void], [function(Funlockfile, [param([UC_FILE], ptr_decl(pointer, UC___stream))])]), 

declaration([extern, int], [function(UC___uflow, [param_no_decl([UC_FILE], dummy_abstract_declarator)])]), 

declaration([extern, int], [function(UC___overflow, [param_no_decl([UC_FILE], dummy_abstract_declarator), param_no_decl([int], [])])]), 
function([int], function(Main, []), [], 
cmp_stmts([
declaration([int], [initialised(Hex0, int(16'0))]), 
declaration([int], [initialised(Hex1, int(16'1))]), 
declaration([int], [initialised(HexA, int(16'A))]), 
declaration([int], [initialised(HexF, int(16'F))]), 
declaration([int], [initialised(Hex10, int(16'10))]), 
declaration([int], [initialised(Hex1F, int(16'1F))]), 
declaration([int], [initialised(Hex2A, int(16'2A))]), 
declaration([int], [initialised(HexFF, int(16'FF))]), 
declaration([int], [initialised(Hex7FFF, int(16'7FFF))]), 
declaration([int], [initialised(NegHex1A, minus_op(int(16'1A)))]), 
declaration([int], [initialised(NegHex80, minus_op(int(16'80)))]), 
declaration([int], [initialised(HexLower, int(16'1a))]), 
declaration([int], [initialised(HexUpper, int(16'1A))]), 
declaration([unsigned, int], [initialised(HexUnsigned, unsigned(16'1A))]), 
declaration([long], [initialised(HexLong, long(16'1A))]), 
declaration([unsigned, long], [initialised(HexULong, unsigned_long(16'1A))]), 
declaration([unsigned, int], [initialised(Hex32bit, int(16'FFFFFFFF))]), 
declaration([unsigned, long, long], [initialised(Hex64bit, int(16'FFFFFFFFFFFFFFFF))]), 
declaration([int], [initialised(Mask8bit, int(16'FF))]), 
declaration([int], [initialised(Mask16bit, int(16'FFFF))]), 
declaration([unsigned, int], [initialised(MemoryAddr, int(16'7FFF0000))]), 
declaration([unsigned, int], [initialised(WhiteColor, int(16'FFFFFF))]), 
declaration([unsigned, int], [initialised(GreenColor, int(16'00FF00))]), 
stmt(function_call(Printf, ["Basic Hex Constants: %d, %d, %d, %d\n", Hex0, Hex1, HexA, HexF])), 
stmt(function_call(Printf, ["Multi-Digit Hex: %d, %d, %d, %d, %d\n", Hex10, Hex1F, Hex2A, HexFF, Hex7FFF])), 
stmt(function_call(Printf, ["Negative Hex: %d, %d\n", NegHex1A, NegHex80])), 
stmt(function_call(Printf, ["Case Sensitivity: %d, %d\n", HexLower, HexUpper])), 
stmt(function_call(Printf, ["Hex with Types: %u, %ld, %lu\n", HexUnsigned, HexLong, HexULong])), 
stmt(function_call(Printf, ["Large Hex: %u, %llu\n", Hex32bit, Hex64bit])), 
stmt(function_call(Printf, ["Bit Masks: %d, %d\n", Mask8bit, Mask16bit])), 
stmt(function_call(Printf, ["Memory Address: 0x%X\n", MemoryAddr])), 
stmt(function_call(Printf, ["Colors: 0x%X (White), 0x%X (Green)\n", WhiteColor, GreenColor])), 
return_stmt(int(0))

]))
]).
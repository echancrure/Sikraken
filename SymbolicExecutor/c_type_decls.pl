%% c_type_decl/4
%% c_type_decl(+Type, -Size_in_bytes, -Minimum_bound, -Maximum_bound)
%% Gets the size of a c type in bytes
%% Parameters:
%%   Type: The type to get the size of
%%   Size_in_bytes: The size of the type in bytes
%%   Minimum_bound: The minimum value of the type
%%   Maximum_bound: The maximum value of the type

c_type_decl(char, 1, -128, 127).
c_type_decl(signed_char,1,-128,127).
c_type_decl(unsigned_char,1,0,255).
c_type_decl(short,2,-32768,32767).
c_type_decl(signed_short,2,-32768,32767).
c_type_decl(unsigned_short,2,0,65535).
c_type_decl(short_int,2,-32768,32767).
c_type_decl(signed_short_int,2,-32768,32767).
c_type_decl(unsigned_short_int,2,0,65535).
c_type_decl(int,4,-2147483648,2147483647).
c_type_decl(signed_int,4,-2147483648,2147483647).
c_type_decl(unsigned_int,4,0,4294967295).
c_type_decl(signed,4,-2147483648,2147483647).
c_type_decl(unsigned,4,0,4294967295).
c_type_decl(long,8,-9223372036854775808,9223372036854775807).
c_type_decl(signed_long,8,-9223372036854775808,9223372036854775807).
c_type_decl(unsigned_long,8,0,18446744073709551615).
c_type_decl(long_int,8,-9223372036854775808,9223372036854775807).
c_type_decl(signed_long_int,8,-9223372036854775808,9223372036854775807).
c_type_decl(unsigned_long_int,8,0,18446744073709551615).
c_type_decl(long_long,8,-9223372036854775808,9223372036854775807).
c_type_decl(signed_long_long,8,-9223372036854775808,9223372036854775807).
c_type_decl(unsigned_long_long,8,0,18446744073709551615).
c_type_decl(long_long_int,8,-9223372036854775808,9223372036854775807).
c_type_decl(signed_long_long_int,8,-9223372036854775808,9223372036854775807).
c_type_decl(unsigned_long_long_int,8,0,18446744073709551615).
c_type_decl(float,4,1.17549e-38,3.40282e+38).
c_type_decl(double,8,2.22507e-308,1.79769e+308).
c_type_decl(long_double,8,2.22507e-308,1.79769e+308).
c_type_decl(pointer,8,0,200000).
c_type_decl('_Bool',1,0,1).
c_type_decl(enum,4,-2147483648,2147483647).

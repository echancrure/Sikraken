# 0 "/home/chris/Sikraken/SampleCode/atry_enum.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/chris/Sikraken/SampleCode/atry_enum.c"
extern int __VERIFIER_nondet_int();
# 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h" 1 3 4
# 34 "/usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h" 1 3 4
# 205 "/usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 26 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 394 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/bits/timesize.h" 1 3 4
# 19 "/usr/include/bits/timesize.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 20 "/usr/include/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 395 "/usr/include/features.h" 2 3 4
# 502 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 576 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 577 "/usr/include/sys/cdefs.h" 2 3 4
# 1 "/usr/include/bits/long-double.h" 1 3 4
# 578 "/usr/include/sys/cdefs.h" 2 3 4
# 503 "/usr/include/features.h" 2 3 4
# 526 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4






# 1 "/usr/include/gnu/stubs-32.h" 1 3 4
# 8 "/usr/include/gnu/stubs.h" 2 3 4
# 527 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/limits.h" 2 3 4
# 195 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/posix1_lim.h" 1 3 4
# 27 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/posix1_lim.h" 2 3 4
# 161 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/local_lim.h" 1 3 4
# 38 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 39 "/usr/include/bits/local_lim.h" 2 3 4
# 81 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/bits/pthread_stack_min-dynamic.h" 1 3 4
# 29 "/usr/include/bits/pthread_stack_min-dynamic.h" 3 4
# 1 "/usr/include/bits/pthread_stack_min.h" 1 3 4
# 30 "/usr/include/bits/pthread_stack_min-dynamic.h" 2 3 4
# 82 "/usr/include/bits/local_lim.h" 2 3 4
# 162 "/usr/include/bits/posix1_lim.h" 2 3 4
# 196 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/posix2_lim.h" 1 3 4
# 200 "/usr/include/limits.h" 2 3 4
# 206 "/usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h" 2 3 4
# 35 "/usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h" 2 3 4
# 3 "/home/chris/Sikraken/SampleCode/atry_enum.c" 2
typedef int Red;
int f(void) {
    enum Color {
        Red,
        Green,
        Blue,
        ColorCount
    };
    typedef int Reddish;
    return Red + Green + Blue;
}


enum Status {
    Ok = 0,
    Warn = 2,
    Error,
    Fatal = -1,
    Unknown
};


enum Flags {
    F_None = 0,
    F_Read = 1 << 0,
    F_Write = 1 << 1,
    F_Exec = 1 << 2,
    F_RW = F_Read | F_Write,
    F_Mask = ~0,
    F_CharA = 'A',
    F_Hex = 0x10,
    F_Oct = 077,
    F_SizeInt = (int)sizeof(int),
    F_SizeLong = (int)sizeof(long),
    F_Max = 0x7fffffff

# 38 "/home/chris/Sikraken/SampleCode/atry_enum.c"
};

enum TrailingComma {
    TC_A = 1,
    TC_B = 2,
    TC_C = 3,
};





enum {
    AE_X = 10,
    AE_Y,
    AE_Z = AE_X + AE_Y
};






enum ColorTag { CT_R, CT_G, CT_B };
enum ColorTag ct = CT_B;
int ColorTag = 42;





enum Outer {
    X = 1,
    Y = 2
};
typedef int Z;

void shadow_demo(void) {
    int a = X;

    {

        enum Inner { X = 100, Z = 200, ColorTag };
        int b = X;
        int c = Z;

        {

            int d = X;
            if (X + d + c + ColorTag + Z == __VERIFIER_nondet_int()) ; else ;
        }
    }
    int e = X;
    if (a + e + ColorTag + sizeof(Z) == __VERIFIER_nondet_int()) ; else ;
}






static enum Flags defaultFlag;
static enum Status defaultStatus = Ok;
# 309 "/home/chris/Sikraken/SampleCode/atry_enum.c"
int main(void) {
    shadow_demo();
    int F = f();
    if (F == __VERIFIER_nondet_int()) ; else ;
    return 0;
}

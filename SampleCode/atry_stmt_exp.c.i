# 0 "/home/chris/Sikraken/SampleCode/atry_stmt_exp.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/chris/Sikraken/SampleCode/atry_stmt_exp.c"

extern unsigned long __VERIFIER_nondet_ulong();
extern int __VERIFIER_nondet_int(void);
int main(int argc, char **argv) {
    int i = __VERIFIER_nondet_int();
    int result = ({
        int a = 5;
        int b = 10;
        a + b;
    });
    if (result == __VERIFIER_nondet_int()) ; else ;
    return result;
}

//#include <stdio.h>
extern unsigned long __VERIFIER_nondet_ulong();
extern int __VERIFIER_nondet_int(void);
int main(int argc, char **argv) {
    int i = __VERIFIER_nondet_int();
    int result = ({
        int a = 5;
        int b = 10;
        a + b; // This is the 'return' value of the expression, it is an expression statement
    }); // result is now 15
    if (result == __VERIFIER_nondet_int()) ; else ;
    return result;
}
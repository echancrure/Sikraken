# 0 "SampleCode/atry_local_return.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "SampleCode/atry_local_return.c"
extern int __VERIFIER_nondet_int();

int fn(int x) {
    int z = x+1;
    return z;
}


void main() {
    int b = fn(42);
    if (b == __VERIFIER_nondet_int()) ;
    else ;
    int x = fn(b);
    if (x == __VERIFIER_nondet_int()) ;
    else ;
    if (fn(__VERIFIER_nondet_int()) == 999) ;
    else ;
}

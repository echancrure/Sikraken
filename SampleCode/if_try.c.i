# 0 "SampleCode/if_try.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "SampleCode/if_try.c"
extern int __VERIFIER_nondet_int(void);

int main() {
    int i = __VERIFIER_nondet_int();
    if (i==0)
        if (i==1)
            i = 10;
        else
            i = 100;
    else
        {if (i==1) {
            i = 10;
        }}
    if (i>10) if (i ==100) i = 42;

    return i;
}

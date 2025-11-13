# 0 "SampleCode/switch_try2.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "SampleCode/switch_try2.c"
extern int __VERIFIER_nondet_int(void);

int main() {
    for(int i = 0; i < 5; i++) {
        int y = 0;
        switch (i) {
            case 0: y += 1; break;
            case 1: y += 2;
            default : y += 4; break;
        }
    }
    return 0;
}

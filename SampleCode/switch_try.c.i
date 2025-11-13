# 0 "SampleCode/switch_try.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "SampleCode/switch_try.c"
extern int __VERIFIER_nondet_int(void);

int main() {
    for(int i = 0; i < 5; i++) {
        int j = __VERIFIER_nondet_int();
        switch (j) {



            case 0:
            case 42:
                i++;



            case 100: return 1;
            case 1: return 10;
            case 2: return 100;
            case 3: return 1000;
            default: break;
        }
    }
    int k = 8;
    goto end;
    k--;
    end: k++;
# 53 "SampleCode/switch_try.c"
    return 0;
}

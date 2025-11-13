# 0 "SampleCode/try_cfg.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "SampleCode/try_cfg.c"
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

void demo_loop_exits(int target) {
    for (int i = 0; i < 10; i++) {
        if (i == 2) {
            continue;
        }
        if (i == 4) {
            break;
        }
        if (i == target) {
            return;
        }
        if (i == 7) {
            exit(0);
        }
        if (i == 5) {
            goto done;
        }
    }
done:
    return;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    demo_loop_exits(n);
    return 0;
}

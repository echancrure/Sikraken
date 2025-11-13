# 0 "/home/chris/Sikraken/SampleCode/try_while.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/chris/Sikraken/SampleCode/try_while.c"
extern int __VERIFIER_nondet_int(void);
int main() {
    int x = __VERIFIER_nondet_int();
    while (x > 0 && x < 100) {

        if (x == 42)
            break;

        x++;
    }

    return 0;
}

extern void exit(int);
extern int __VERIFIER_nondet_int();
extern float __VERIFIER_nondet_float();
extern unsigned char __VERIFIER_nondet_uchar();

int main() {
    unsigned char limit = __VERIFIER_nondet_uchar();
    int i = 0;
    do {
        if (i == 0) {           //id 1
            i++;    //was goto inside_label;
        }
        if (i == 1) {           //id 2
            i++;
            continue;
        }
        if (i == 2) {           //id 3 (false is unreachable)
            return 42;          // reachable and demonstrates early return
        }
        if (i == 3) {           //id 4 is unreachable
            break;
        }
        inside_label:
            i++;
    } while (i < limit);        //id 5
    return 0;
}
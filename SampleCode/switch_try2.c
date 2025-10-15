extern int __VERIFIER_nondet_int(void);

int main() {
    for(int i = 0; i < 5; i++) {
        int y = 0;
        switch (i) {
            case 0: y += 1; break;
            case 1: y += 2;
            //default : y += 4; break;
        }
    }
    return 0;
}
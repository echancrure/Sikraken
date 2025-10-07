extern int __VERIFIER_nondet_int(void);
extern void exit(int);

void demo_loop_exits(int target) {
    for (int i = 0; i < 10; i++) {  //id 6
        if (i == 2) {               //id 1
            continue;                 // skip rest of this iteration
        }
        if (i == 4) {               //id 2
            break;                    // exit loop only
        }
        if (i == target) {          //id 3
            return;                   // exit entire function
        }
        if (i == 7) {               //id 4
            exit(0);                  // terminate program
        }
        if (i == 5) {               //id 5
            goto done;                // jump to label outside loop
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

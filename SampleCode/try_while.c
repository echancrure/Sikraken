extern int __VERIFIER_nondet_int(void);
int main() {
    int x = __VERIFIER_nondet_int();
    while (x > 0 && x < 100) {
        //Goal1
        if (x == 42) //Goal3 
            break;
        //Goal4
        x++;
    }
    //Goal2
    return 0;
}
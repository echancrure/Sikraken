extern int __VERIFIER_nondet_int(void);

int main() {
    int x = __VERIFIER_nondet_int();
    switch (x) {    //does nothing
    }
    /*
    switch (x) {    //does nothing if   x != 1
        case 1: f(); break;
    }
    switch (x) {    //fallthrough
        case 0: f();
        case 1: g(); break;
    }
    switch (x) {    //mutiple labels to same block
        case 0:
        case 42:
        case 100:
            return 1;
    }
    switch (x) {
        int y = 5;    // Declaration OK (block item) has to be executed
        case 0: y++; break;
    }
    switch (x) {
    case 0:
        switch (y) {    //nested switch
            case 1: f(); break;
        }
        break;
    }
    switch (x) {
        case 0:
            switch (y) {
                case 1: break;  // breaks only inner switch
            }
            f();                // still runs
            break;
    }
    switch (x) {
        case 0:;            //empty statement
        case 1:;
        default:;
    }
    switch (x) {
        case 2147483648u: break;  // OK (unsigned)
        case 2147483648: break;   // ⚠️ overflow if x is int
    }
    switch (x) {
        default: f();   //Mix of case and default ordering
        case 0: g();
    }
    switch (x) {
        {
            case 0: f(); break; //labels can appear inside blocks inside the switch.
        }
    }
    switch (x);  // ✅ legal, switch body is an empty statement
    */
}
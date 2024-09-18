extern void exit(int);
extern int __VERIFIER_nondet_int();
extern float __VERIFIER_nondet_float();

int main() {
    int x = __VERIFIER_nondet_int();
    int y;
    y = (x>6 && x<10) + 41;
    if (y != 42 && y != 41) exit(2);    //can only be false
    int var_1_10 = __VERIFIER_nondet_int();
    float var_1_14 = __VERIFIER_nondet_float();
    float var_1_12 = __VERIFIER_nondet_float();
    int var_1_8;
    var_1_8 = (((var_1_14 / var_1_12) >= var_1_14) || var_1_10);    
    if (var_1_8) ;  //both covered
    else ;
    exit(0);    //it would be good to check that this regression test returns with 0
}
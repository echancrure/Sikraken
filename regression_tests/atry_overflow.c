extern int __VERIFIER_nondet_int();
int main() {
    int s = 5 + 2147483647; // overflow occurs here
//    if (s == -2147483644) ; // should always be true
//    else ;                  // dead code
//    s = -5 - 2147483648;    // underflow occurs here
//    if (s == 2147483643) ;  // should always be true
//    else ;                  // dead code
 //   s = 2147483647 + __VERIFIER_nondet_int();
 //   if (s == -2147483644) ; // overflow necessary i.e. input must be 5 
 //   else ;                  // any negative value is fine or different than 5
    s = -2147483647 + __VERIFIER_nondet_int();
    if (s == 2147483644) ;  // underflow necessary i.e. input must be -5
    else ;                  // any positive value is fine or different than -5
 //   s = 42 + __VERIFIER_nondet_int();
 //   if (s == 42) ;          // no overflow necessary input == 0
 //   else ;                  // any value different than 0 is fine 
    return s;
}
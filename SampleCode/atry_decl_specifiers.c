extern int __VERIFIER_nondet_int();

void f(signed int) {
    return 0;
}

//signed can always be ignored
//int is the default
//short takes precedence on int
//long takes precedence on int
//long long takes precedence on int
//float, double and long double cannot be combined
//gcc issues errors otherwise (remember though, Sikraken only links, so no compilation errors are reported
int main() {
    int i0;
    
    unsigned i1; //unsigned int
    unsigned int i2; //unsigned int
    signed int i3; //int
    signed i4; //int
    signed char c1; //char
    unsigned char c2; //char
    signed short s1; //short
    signed short int s2; //short
    /*signed int short s3; //short
    unsigned short s4; //short
    unsigned short int s5; //short
    signed short int s6; //short
    signed long long ll1; //long long
    signed long long int ll2; //long long
    unsigned long long ll3; //long long
    unsigned long long int ll4; //long long     
    signed long long int ll5; //long long
    long l1;    //long
    long int l2;    //long
    signed long int l3; //long
    int long signed l4; //long
    signed long int l5; //long
    float f1; //float
    double d1; //double
    long double ld1; //long double
    double long ld2; //long double
    int const i5; //int
    const int const i6; //int
    int typedef * ptr;      // Valid, but unconventional
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();
    if (z == 42) ;
    else ;*/
    return 0;
} 
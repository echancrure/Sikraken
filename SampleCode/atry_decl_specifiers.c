extern int __VERIFIER_nondet_int();

inline int f(signed int) {
    return 0;
}

struct Point1 {
    long int x,y,z;
    _Bool isLanded1;
};

struct Point2 {
    long int x,y;
    _Bool isLanded;
} p1, p2;
struct Point2 p3 = {0, 0, 0}; //struct Point p3 = {0, 0, 0};

union U {
    int i;
    char c;
};

enum E {
    A = 1,
    B = 2,
    C = 3
};
typedef int long long money;
typedef struct {
    int x;
    int y;
} Point;
typedef union {
    int i;
    char c;
} U;

const static _Atomic int i = 0; //static const int
//signed can always be ignored
//int is the default
//short takes precedence on int
//long takes precedence on int
//long long takes precedence on int
//float, double and long double cannot be combined
//gcc issues errors otherwise (remember though, Sikraken only links, so no compilation errors are reported
int main() {
    int i0; //int
    unsigned i1; //unsigned int
    unsigned int i2; //unsigned int
    signed int i3; //int
    signed i4; //int
    signed char c1; //char
    unsigned char c2; //unsigned char
    signed short s1; //short
    signed short int s2; //short
    signed int short s3; //short
    unsigned short s4; //unsigned short
    unsigned short int s5; //unsigned short
    signed short int s6; //short
    signed long long ll1; //long long
    signed long long int ll2; //long long
    unsigned long long ll3; //unsigned long long
    unsigned long long int ll4; //unsigned long long     
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
    else ;
    f(8);
    return 0;
} 
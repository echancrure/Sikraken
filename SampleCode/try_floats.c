int main() {
    // Floating-point constants
    float f1 = 123.0f;           // float
    float f2 = 123.0F;           // float
    double d1 = 123.0;           // double (default type for floating-point literals)
    double d1 = 123.;           // double (default type for floating-point literals)
    double d1 = 123.E10;           // double (default type for floating-point literals)
    long double d1 = 123.E10L;           // double (default type for floating-point literals)
    long double ld1 = 123.0L;    // long double
    long double ld2 = 123.0l;    // long double

    // Floating-point constants with exponent notation and no digits after the decimal point
    float f3 = 1e2f;            // float, exponent notation with no decimal digits
    float f4 = 1E2F;            // float, exponent notation with no decimal digits
    double d3 = 1e2;            // double, exponent notation with no decimal digits
    double d4 = 1E2;            // double, exponent notation with no decimal digits
    long double ld3 = 1e2L;     // long double, exponent notation with no decimal digits
    long double ld4 = 1E2l;     // long double, exponent notation with no decimal digits

    // Floating-point constants with hexadecimal notation and no digits after the decimal point
    float f5 = 0x1p2f;         // float, hexadecimal notation with no decimal digits
    double d5 = 0x1p2;         // double, hexadecimal notation with no decimal digits
    long double ld5 = 0x1p2L;  // long double, hexadecimal notation with no decimal digits

    // Floating-point constants with optional decimal point
    float f6 = 1.E1f;          // float, exponent notation with optional decimal point
    double d6 = 1.E1;          // double, exponent notation with optional decimal point
    long double ld6 = 1.E1L;   // long double, exponent notation with optional decimal point

     // Hexadecimal floating-point constants with no decimal part and various exponents
    float f1 = 0x1.0p0f;     // float, hexadecimal notation with no decimal digits and exponent 0
    float f2 = 0x1.0p1f;     // float, hexadecimal notation with no decimal digits and exponent 1
    float f3 = 0x1.0p2f;     // float, hexadecimal notation with no decimal digits and exponent 2
    float f4 = 0x1.0p3f;     // float, hexadecimal notation with no decimal digits and exponent 3
    float f4 = 0x1.p3f;     // float, hexadecimal notation with no decimal digits and exponent 3

    // Hexadecimal floating-point constants with some digits after the decimal point
    float f5 = 0x1.4p1f;     // float, hexadecimal notation with some decimal digits and exponent 1
    float f6 = 0x1.8p1f;     // float, hexadecimal notation with some decimal digits and exponent 1
    float f7 = 0x1.Cp2f;     // float, hexadecimal notation with some decimal digits and exponent 2
    float f8 = 0x1.fp2f;     // float, hexadecimal notation with some decimal digits and exponent 2

    // Double precision hexadecimal floating-point constants
    double d1 = 0x1.0p0;     // double, hexadecimal notation with no decimal digits and exponent 0
    double d2 = 0x1.0p1;     // double, hexadecimal notation with no decimal digits and exponent 1
    double d3 = 0x1.0p2;     // double, hexadecimal notation with no decimal digits and exponent 2
    double d4 = 0x1.0p3;     // double, hexadecimal notation with no decimal digits and exponent 3

    double d5 = 0x1.4p1;     // double, hexadecimal notation with some decimal digits and exponent 1
    double d6 = 0x1.8p1;     // double, hexadecimal notation with some decimal digits and exponent 1
    double d7 = 0x1.Cp2;     // double, hexadecimal notation with some decimal digits and exponent 2
    double d8 = 0x1.fp2;     // double, hexadecimal notation with some decimal digits and exponent 2

    // Long double precision hexadecimal floating-point constants
    long double ld1 = 0x1.0p0L; // long double, hexadecimal notation with no decimal digits and exponent 0
    long double ld2 = 0x1.0p1L; // long double, hexadecimal notation with no decimal digits and exponent 1
    long double ld3 = 0x1.0p2L; // long double, hexadecimal notation with no decimal digits and exponent 2
    long double ld4 = 0x1.0p3L; // long double, hexadecimal notation with no decimal digits and exponent 3

    long double ld5 = 0x1.4p1L; // long double, hexadecimal notation with some decimal digits and exponent 1
    long double ld6 = 0x1.8p1L; // long double, hexadecimal notation with some decimal digits and exponent 1
    long double ld7 = 0x1.Cp2L; // long double, hexadecimal notation with some decimal digits and exponent 2
    long double ld8 = 0x1.fp2L; // long double, hexadecimal notation with some decimal digits and exponent 2

}
extern int __VERIFIER_nondet_int(); 
#include <limits.h>
typedef int Red;
int f(void) {
    enum Color {        // 1.1 Named enum with implicit values (0, 1, 2, ...)
        Red,            // 0
        Green,          // 1
        Blue,           // 2
        ColorCount      // 3
    };
    typedef int Reddish;
    return Red + Green + Blue;
}


enum Status {       // 1.2 Explicit values, mixed with implicit
    Ok = 0,
    Warn = 2,
    Error,          // 3 (previous + 1)
    Fatal = -1,
    Unknown         // 0 (previous + 1 from -1 -> 0)
};

// 1.3 Expressions, negatives, char, hex, octal, bitwise, sizeof, INT_MAX
enum Flags {
    F_None      = 0,
    F_Read      = 1 << 0,      // 1
    F_Write     = 1 << 1,      // 2
    F_Exec      = 1 << 2,      // 4
    F_RW        = F_Read | F_Write, // 3
    F_Mask      = ~0,          // typically -1 (implementation-defined for int)
    F_CharA     = 'A',         // 65
    F_Hex       = 0x10,        // 16
    F_Oct       = 077,         // 63
    F_SizeInt   = (int)sizeof(int),  // typically 4
    F_SizeLong  = (int)sizeof(long),
    F_Max       = INT_MAX
};

enum TrailingComma {    // 1.4 Trailing comma allowed (C99+)
    TC_A = 1,
    TC_B = 2,
    TC_C = 3,
};

// ------------------------------------------------------
// 2) Anonymous enums: enumerators leak into containing scope
// ------------------------------------------------------

enum {
    AE_X = 10,
    AE_Y,
    AE_Z = AE_X + AE_Y // 10 + 11 = 21
};

// ------------------------------------------------------
// 3) Tag namespace vs ordinary identifiers
// ------------------------------------------------------

// Tags are a distinct namespace from variables/functions.
enum ColorTag { CT_R, CT_G, CT_B };
enum ColorTag ct = CT_B;
int ColorTag = 42; // OK: ordinary identifier "ColorTag" coexists with tag "enum ColorTag"

// ------------------------------------------------------
// 4) Shadowing enumerator literals in inner scopes
// ------------------------------------------------------

enum Outer {
    X = 1,
    Y = 2
};
typedef int Z;

void shadow_demo(void) {
    int a = X; // refers to Outer::X (1)

    {
        // Inner enum defines an enumerator 'X' that shadows the outer one
        enum Inner { X = 100, Z = 200, ColorTag };  //ColorTag shadows ColorTag int variable, X enum shadows outer enum X, Enum Z shadows Z typedef
        int b = X; // 100 (Inner::X)
        int c = Z; // 200

        {// Ordinary identifiers can also shadow enumerators
            //int X = 999;  // shadows inner enum constant X within this block
            int d = X;    // 999
            if (X + d + c + ColorTag + Z == __VERIFIER_nondet_int()) ; else ; 
        }
    }
    int e = X; // back to Outer::X (1)
    if (a + e + ColorTag + sizeof(Z) == __VERIFIER_nondet_int()) ; else ; 
}

// ------------------------------------------------------
// 5) Various initializations with enums
// ------------------------------------------------------

// 5.1 Global/static initialization
static enum Color defaultColor;           // zero-initialized => Red
static enum Status defaultStatus = Ok;    // explicit initializer
/*
// 5.2 Automatic/block initialization, brace-wrapped scalar allowed
void init_demo(void) {
    enum Color c1 = Green;
    enum Color c2 = (enum Color){ Blue };  // brace-wrapped scalar initializer
    enum Status s1 = Fatal;
    enum Status s2 = (enum Status)3;       // value not declared; allowed (may warn)
    if (c1 + c2 + s1 + s2 + defaultStatus + defaultColor == __VERIFIER_nondet_int()) ; else ; 
}

// 5.3 Arrays with designated initializers using enum constants as indices
int colorWeights[ColorCount] = {    // 'ColorCount' is the count, not an enumerator used as index here.
    [Red]   = 100,
    [Green] = 80,
    [Blue]  = 120,
};

// 5.4 Using enum values to size arrays and initialize them
int flagTable[F_Exec + 1] = {
    [F_None]  = 0,
    [F_Read]  = 1,
    [F_Write] = 2,
    [F_Exec]  = 3
};

// 5.5 Structs, designated initializers, and compound literals
struct Pixel {
    enum Color color;
    int        alpha;
};

struct Pixel p1 = { .color = Red,  .alpha = 255 };
struct Pixel p2 = { .color = Blue, .alpha = 128 };

void compound_literal_demo(void) {
    struct Pixel p3 = (struct Pixel){ .color = Green, .alpha = 64 };
    (void)p3;
}

// 5.6 Bit-field widths using enumerators (must be nonnegative and fit)
struct Reg {
    unsigned r : F_Read;   // width = 1
    unsigned w : F_Write;  // width = 2
    unsigned x : F_Exec;   // width = 4
};

// 5.7 Switch/case with enum constants
void switch_demo(enum Color c) {
    switch (c) {
        case Red:    break;
        case Green:  break;
        case Blue:   break;
        default:     break;
    }
}

// ------------------------------------------------------
// 6) Enums inside struct declarations (anonymous members)
// ------------------------------------------------------

// Enumerator names introduced inside these enums still enter the surrounding scope.
struct S {
    enum { S_A = 1, S_B = 2 } kind1;
    enum { S_C = 3, S_D = 4 } kind2;
};

// S_A..S_D are visible at the same scope as the struct definition:
int sVals[] = { S_A, S_B, S_C, S_D };

// ------------------------------------------------------
// 7) Typedefs of enums and reusing tags
// ------------------------------------------------------

typedef enum Color Color_t;
Color_t paint = Red;

enum Mode { M_A, M_B };
typedef enum Mode Mode;

// Forward-declaring enums is not allowed (INVALID):
// enum Future;        // INVALID: forward declaration of enum not allowed
// enum Future *pf;    // INVALID: pointer to undefined enum type

// ------------------------------------------------------
// 8) Macros interacting with enumerator names
// ------------------------------------------------------

enum MacroTest { MT_A = 1, MT_B = 2, MT_C = 3 };
#define MT_B 999   // Preprocessor macro shadows the token 'MT_B'

int macro_demo(void) {
    // MT_B expands to 999 before compilation; uses integer literal 999.
    int v = MT_B;  // v = 999
    return v;
}

#undef MT_B

enum MacroTest2 { MT2_A = 10, MT2_B = 20 };

// ------------------------------------------------------
// 9) Cross-referencing, duplicates, and diagnostics
// ------------------------------------------------------

enum CrossRef {
    CR_A = 5,
    CR_B = CR_A + 7,     // 12
    CR_C = CR_B * 2      // 24
};

// Referencing later enumerator is invalid (order matters):
// enum BadOrder {
//     BO_X = BO_Y,  // INVALID: BO_Y not yet declared
//     BO_Y = 1
// };

// Duplicate enumerator names in the same scope are invalid:
// enum Dup1 { D_A, D_B };
// enum Dup2 { D_A, D_C }; // INVALID: D_A already declared in the same scope

// Same value for different enumerators is allowed:
enum SameVal {
    SV_A = 0,
    SV_B = 0,  // OK: duplicate value, distinct names
    SV_C = SV_A
};

// ------------------------------------------------------
// 10) Enums with functions, parameters, and casts
// ------------------------------------------------------

typedef enum Status Status_t;

Status_t clamp_status(int x) {
    if (x < -1) return Fatal;
    if (x == 0) return Ok;
    if (x == 2) return Warn;
    if (x == 3) return Error;
    return Unknown; // not all compilers warn about missing enumerators
}

void call_demo(void) {
    Status_t s = clamp_status(3);
    Status_t t = (Status_t)42; // outside declared set; allowed (may warn)
    (void)s; (void)t;
}

// ------------------------------------------------------
// 11) Edge cases: unary plus, negatives, nested expressions, INT_MAX
// ------------------------------------------------------

enum Edge {
    E_Plus   = +5,
    E_Neg    = -E_Plus,        // -5
    E_Combo  = (E_Plus * 3) + (int)sizeof(long long), // constant expression
    E_MaxInt = INT_MAX
};

int edge_arr[E_Plus + 1] = { [0] = 0, [E_Plus] = 5 };

// ------------------------------------------------------
// 12) Putting shadowing and initialization together
// ------------------------------------------------------

// Outer enum and its enumerators
enum Level { L0, L1, L2 };

int shadow_and_init(void) {
    enum Level lvl = L1; // init with enumerator (outer)
    int val = L2;        // enumerators are plain ints

    {
        // Inner definition with the same tag name shadows the outer tag in this block.
        enum Level { L0 = 100, L1 = 200, L2 = 300 }; // shadows outer L0/L1/L2
        enum Level inner = L0; // 100 (inner enum)
        val += L2;             // +300 (inner L2)
        (void)inner;
    }

    // Back to outer L2 == 2
    val += L2; // +2
    return val; // 300 + 2
}

// ------------------------------------------------------
// Main (optional): touch demos to avoid "unused" warnings
// ------------------------------------------------------

int main(void) {
    shadow_demo();
    init_demo();
    compound_literal_demo();
    switch_demo(Red);
    (void)macro_demo();
    call_demo();
    int result = shadow_and_init();

    if (AE_Z + ColorTag + p1.alpha + result == __VERIFIER_nondet_int()) ; else ; 

    if (colorWeights[Red] + flagTable[F_Exec] == __VERIFIER_nondet_int()) ; else ;

    // Bit-field structure size example (implementation-defined)
    struct Reg r = {0};
    if ((int)sizeof r == __VERIFIER_nondet_int()) ; else ;

    return 0;
}
*/
int main(void) {
    shadow_demo();
    int F = f();
    if (F == __VERIFIER_nondet_int()) ; else ;
    return 0;
}
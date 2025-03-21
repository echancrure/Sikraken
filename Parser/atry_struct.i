extern int __VERIFIER_nondet_int();
struct struct_of_struct {
    int x, y, z, t;
    struct {
        int anon;
    } inner;
    struct {
        int anon;
    };
};
struct point {
    int x, y, z, t;
    float weight;
} p78 = {1,2,3,4,4.004}, p79 = {1};
struct point2 {
    int x, y, z, t;
    float weight;
} p1 = {1, 2, 3, 4, 67.0}, p2;
struct point3;
struct point3 {
    int x, y, z, t;
    float weight;
};
struct {
    int x, y, z, t;
    float weight;
} anon1 = {1, 2, 3, 4, 67.0}, anon2;
int a = 1;
typedef struct plot plot;
struct plot {
    int x, y;
};
plot p = {10, 20};
typedef struct {
    int n;
}S;
S Sx;
int main(void) {
    anon2 = anon1;
    struct point2 p3 = p1;
    int i = 0;
    struct point_1 {
      int x, y, z, t;
      float weight;
    } p78_1 = {1,2,3,4,4.004}, p79_1 = {1};
    int gy;
    gy = p79_1.y;
    if (gy == __VERIFIER_nondet_int()) i--;
    i++;
    if (p78_1.x == 1 && p79_1.x == 1 && p78.x == 1 && p79.x == 1) i++;
    else i--;
    if (p79.y == 0) i++;
    else return 1;
    float fl = p78.x;
    int gh = p.x + p.y;
    if (gh == __VERIFIER_nondet_int()) i++;
    else i--;
    S x;
    x.n = __VERIFIER_nondet_int();
    if (x.n == 99) i++;
    else i--;
    struct point s1;
    struct point s2 = {1, 2, 3, 4, 42.42};
    struct point s3 = {1, 2, 3};
    s1.x = __VERIFIER_nondet_int();
    if (s1.x == -5) i++;
    else i--;
    return 0;
}

extern int __VERIFIER_nondet_int();

struct point {
    int x, y, z, t;
    float weight;
};
struct point2 {
    int x, y, z, t;
    float weight;
} p1, p2;
struct point3;  //forward declaration
struct point3 {
    int x, y, z, t;
    float weight;
};
struct {        //anonymous declaration has no tag
    int x, y, z, t;
    float weight;
} anon1, anon2;

int a = 1;

int basic(int x) {
    int a = 2;
    int b = 0;          //b == 0
    {
        int a = 3;
        { 
            int a = 4;
            b = x+a;    //b == x + 4
            if (b>42) b = b + 1; //b == x + 4 + 1
            else b = b + 1000;   //b == x + 4 + 1000
        }
        b = b+a;        //b == 4 + x + 1 + 3 or b == x + 4 + 1000 + 3
    }
    b = b+a;            //b == 4 + x + 1 + 3 + 2 or b == x + 4 + 1000 + 3 + 2 
    return b+x; //b == 4 + x + 1 + 3 + 2 + x or b == b == x + 4 + 1000 + 3 + 2 + x
}

void *ldv_malloc(int size) {

}// ;;;;;;;;;; //allowed in gcc

void main(void) {
    struct point s1;
    struct point s2 = {1, 2, 3, 4, 42.42};  //list of initialisers can only be used at declaration time
    struct point s3 = {1, 2, 3};    //only partial initialisations is allowed: remaining fileds are initialised to 0
    s1.x = __VERIFIER_nondet_int();
    if (s1.x == -5) ;
    else ;
}

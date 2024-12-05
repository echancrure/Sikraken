extern int __VERIFIER_nondet_int();

typedef struct {
    int n;
}S; //S is a typedef to an anonymous struct

S Sx;       //an object of type struct
S Ax[5];    //an array of struct

struct point {
    int x, y, z, t; 
    float weight;
};
struct point2 {
    int x, y, z, t;
    float weight;
} p1, p2;           //all members of p1 and p2 to 0 by default because they are globals
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



typedef struct plot plot;   //typedef of a forward declaration
struct plot {
    int x, y;
};
plot p = {10, 20};  // Works due to typedef

int marks[10];

typedef struct Address {
    char city[50];
    int zip;
} Address;
typedef struct Person {
    char name[50];
    int age;
    Address address;  // No need for 'struct Address'
} Person;

//Person p = {"Alice", 25, {"Wonderland", 12345} };   //inner initialiser are string to be handled later

typedef struct {
    int x, y;
} Point;    //upper case P does not interfere with other anonymous struct point
typedef Point PointArray[10];  // PointArray is an array of 10 Points
PointArray points = {{1, 2}, {3, 4}};  // Array of points: only the first 2 points are initialised



typedef struct Node Node;   //Node is a typedef to struct Node which is a forward declaration
struct Node {               //the struct Node is declared
    int value;
    Node *next;             // Pointer to the same struct type using the earlier typedef
};
Node n = {10, 0};

void main(void) {
    S x;
    x.n = __VERIFIER_nondet_int();
    if (x.n == 99) ;
    else ;
    struct point s1;
    struct point s2 = {1, 2, 3, 4, 42.42};  //list of initialisers can only be used at declaration time
    struct point s3 = {1, 2, 3};    //only partial initialisations is allowed: remaining fields are initialised to 0
    s1.x = __VERIFIER_nondet_int();
    if (s1.x == -5) ;
    else ;
}

//21 June 2024 testing parser for pointer as a member of a structure
typedef int Money;
typedef char *String;
unsigned short const *aa;
struct b_struct {
    unsigned short const *a;
    Money b;
    unsigned int *c;
};

typedef struct try_struct { //try_struct is structure here
    unsigned short const *a;
    Money b;
    unsigned int c;
} try_struct;   //try_struct is the alias of the typedef, which basically stands for struct try_struct

struct point{
    int X;
    int y;
};

void main() {
    struct point pt = {320, 200};
    int tot = pt.x + pt.y;
    if (tot > 42) {
        int tot = -1;
        tot = tot + 1;
    }
    tot = tot +1;    

}
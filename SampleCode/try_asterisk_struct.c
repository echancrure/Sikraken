//21 June 2024 testing parser for pointer as a member of a structure
typedef int Money;
unsigned short const *aa;
struct b_struct {
    unsigned short const *a;
    Money b;
    unsigned int *c;
};

typedef struct try_struct {
    unsigned short const *a;
    Money b;
    unsigned int c;
} try_struct;

struct point{
    int X;
    int y;
};

void main() {
    struct point pt = {320, 200};
    pt.x + pt.y;

}
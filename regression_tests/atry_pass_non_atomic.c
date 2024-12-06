extern int __VERIFIER_nondet_int();

struct Point {
    int x,y;
};

int sum_fn(struct Point p) {    
    return p.x + p.y;
}

struct Point pt_fn(int x, int y) {
    struct Point result = {x, y};
    return result;
}

void main(void) {
    struct Point p1 = {__VERIFIER_nondet_int(), __VERIFIER_nondet_int()};
    struct Point p2 = {__VERIFIER_nondet_int(), __VERIFIER_nondet_int()};
    int sum = sum_fn(p1);   //passing a struct as argument
    if (sum == __VERIFIER_nondet_int()) ;
    else ;    

    //struct Point p3 = pt_fn(p1.x, p1.y);    //returning a struct
    struct Point p3;
    p3 = pt_fn(42, -42);
    if (p3.x == p1.y && p3.y == p2.y) ; //i.e. p1.x = p1.y && p2.y == p1.y
    else ;
}

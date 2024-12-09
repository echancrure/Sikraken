extern int __VERIFIER_nondet_int();
extern char __VERIFIER_nondet_char();

int dum[];

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

int calc_avg(char a[], int size) {
    int result;
    for (int i=0; i< size; i++) result += a[i];
    return result / size;
}

int main(void) {
    char x[10] = {}; //initialised to 0 
    for (int i=0; i< 10; i++) x[i] = __VERIFIER_nondet_char();
    int avg = calc_avg(x, 10);
    int i = 99;
    struct Point p1 = {__VERIFIER_nondet_int(), __VERIFIER_nondet_int()};
    struct Point p2 = {__VERIFIER_nondet_int(), __VERIFIER_nondet_int()};
    int sum = sum_fn(p1);   //works: passing a struct as argument: works
    if (sum + avg == __VERIFIER_nondet_int()) ;
    else ;    

    struct Point p3 = pt_fn(p1.x, p1.y);    //works: returning a struct
    //struct Point p3;
    //p3 = pt_fn(42, -42);
    if (p3.x == p1.y && p3.y == p2.y) i += p1.x; //i.e. p1.x = p1.y && p2.y == p1.y
    else i--;
    return i;
}

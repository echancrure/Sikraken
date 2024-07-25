int x, y = 42;
int *pi = &y;

int basic(int x) {
    int m;
    m = 2*x;
    if (x > *pi) return y;
    else return y + *pi + 1 + m;
}
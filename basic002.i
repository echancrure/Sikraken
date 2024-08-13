int a = 1;
int basic(int x) {
    int a = 2;
    int b = 0;
    {
        int a = 3;
        {
            int a = 4;
            b = x+a;
            if (b>42) b = b + 1;
            else b = b + 1000;
        }
        b = b+a;
    }
    b = b+a;
    return b+x;
}
void main(void) {
}

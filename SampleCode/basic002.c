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
struct {        //anonymous declaration
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


void main(void) {           //must be main(void) or the parser misbehaves

}

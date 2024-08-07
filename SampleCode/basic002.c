int a = 1;

int basic(int x) {
    int a = 2;
    int b = 0;          //b == 0
    {
        int a = 3;
        { 
            int a = 4;
            b = x+a;    //b == 4 + x
            if (b>42) b = b + 1; //b == 4 + x + 1
            else b = b + 1000;   //b == 4 + x + 1000
        }
        b = b+a;        //b == 7
    }
    b = b+a;            //b == 9
    return b+x; //b == x + 10 or b == x + 1009
}


void main(void) {           //must be main(void) or the parser misbehaves

}

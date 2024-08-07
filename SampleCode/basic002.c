int a = 1;

int basic(int x) {
    int a = 2;
    int b = 0;          //b == 0
    {
        int a = 3;
        { 
            int a = 4;
            b = b+a;    //b == 4
        }
        b = b+a;        //b == 7
    }
    b = b+a;            //b == 9
    return b+x;
}


void main(void) {           //must be main(void) or the parser misbehaves

}

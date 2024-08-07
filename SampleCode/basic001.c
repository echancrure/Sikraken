int x, y = 42;  //x is initialised to 0
int *pi = &y;

//31 July 2024 example #5 from the diary
int num = 0;		    //num=seav(num, 0)
int *pi;				//[pi=seav(ptr(integer), addr_of(null), _)?]			

int a = 10;
int a;  // Error: redefinition of 'a'

int basic(int x) {
    int m;
    m = 2*x;
    if (x > *pi) return y;      //*pi = num = 200 from main
    else return y + *pi + 1 + m;    //243 + 2*x
}

void swap(int *px, int *py) {	//Eileen's Thesis p. 106
    int temp;				//temp = seav('temp', int, _)
    temp = *px;				//temp = dref(addr(a))	[assign(temp, a) <=> temp = a]
    *px = *py;				//assign(deref(addr(a)), deref(addr(b)) <=> assign(a, b)
    *py = temp;				//assign(deref(addr(b)), a <=> assign(b, a)
}

void main(void) {           //must be main(void) or the parser misbehaves
    pi = &num;				//example 5 pi = seav(ptr(integer), addr(null), addr(seav(num, 0)))
    *pi = 200;	            //example 5 deref(addr(seav(num, 0))) = 200 i.e. num == 200
    int m;
    m = 2*x;                //m = 2*0;
    int z = y + *pi + 1 + m; //int z = 42 + 200 + 1 + 0 i.e. 243
    if (z > 42) {
        x = 42;
    } else x = -1;
}
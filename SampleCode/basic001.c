int x, y = 42;
int *pi = &y;

//31 July 2024 example #5 from the diary
int num = 0;		    //num=seav(num, 0)
int *pi;				//[pi=seav(ptr(integer), addr_of(null), _)?]			


int basic(int x) {
    int m;
    m = 2*x;
    if (x > *pi) return y;
    else return y + *pi + 1 + m;
}

void swap(int *px, int *py) {	//Eileen's Thesis p. 106
    int temp;				//temp = seav('temp', int, _)
    temp = *px;				//temp = dref(addr_of(a))	[assign(temp, a) <=> temp = a]
    *px = *py;				//assign(deref(addr_of(a)), deref(addr_of(b)) <=> assign(a, b)
    *py = temp;				//assign(deref(addr_of(b)), a <=> assign(b, a)
}

void main() {
    pi = &num;				//example 5 pi = seav(ptr(integer), addr_of(null), addr_of(seav(num, 0)))
    *pi = 200;	            //example 5 num == 200
}
extern int __VERIFIER_nondet_int();
	int b[5];   //initialised with 0s
int main() {
    b[0] = 12;
    int c[];
    int x = b[0] + b[1];    //evaluate to 12
    int a[] = {44,45,46,47,48,49};
	int *ap = a;    //a is a pointer 
    int x = 5;
    x = ap[3] + a[3];   //94

    int input = __VERIFIER_nondet_int();
    if (input == x) ; else ;
    return 0;
}
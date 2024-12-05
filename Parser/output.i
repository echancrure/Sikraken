int main(){
    /*signed long int a = 2;
    long signed int b = 1;
    int long signed c = 3;
    const int signed long d = 4;
    int e = 6;
    long int long signed f = 5;
    long int g;
    signed long int g = 6;
    signed long long int const h = 7;
    long j = 9;
    short k = 10;
    unsigned int l = 9, m=10;
    static int n = 11;

    long double z = 10.11;
    double x = 12.15;

    printf("%ld, %ld, %ld, %ld, %d, %lld, %ld, %lld, %ld, %d \n", a, b, c, d ,e ,f ,g, h, j, k);*/

typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;


    return 0;
}

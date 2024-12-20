extern void abort(void);

extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

void reach_error() { ((void) sizeof ((0) ? 1 : 0), __extension__ ({ if (0) ; else __assert_fail ("0", "flag_loopdep_simple.c", 3, __extension__ __PRETTY_FUNCTION__); })); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }
extern int __VERIFIER_nondet_int();
typedef struct
{
 int n;
}S;
void init(S a[], int size)
{
 int i;
 for(i = 0; i < size; i++)
 {
  a[i].n = __VERIFIER_nondet_int();
 }
}
int main()
{int SIZE = 10; //1000000;
 S a[SIZE];
 int i;
 int flag;
 flag = 0;
 init(a, SIZE);
 for(i = 0; i < SIZE; i++)
 {
  if(a[i].n != 0)
  {
   flag = 1;
  }
 }
 for(i = 0; i < SIZE; i++)
 {
  if (flag == 0)
  __VERIFIER_assert(a[i].n == 0 );
 }
 return 0;
}

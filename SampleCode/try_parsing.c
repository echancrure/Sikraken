void reach_error() { 
    ((void) sizeof ((0) ? 1 : 0), 
    //__extension__ 
    ({ 
        if (0) 
        ; 
        else __assert_fail ("0", "/home/chris/sv-benchmarks/c/array-programs/copysome1-1.c", 3, __extension__ __PRETTY_FUNCTION__);
    })
    ); 
}
extern int __VERIFIER_nondet_int();

int main() {
  int x = __VERIFIER_nondet_int();
  if (x > 0) {
    x++;
  }
}
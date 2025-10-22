extern int __VERIFIER_nondet_int();

int main(void) {
      int x = 1;
      try_again: ;
      int y = __VERIFIER_nondet_int();
      if (y == 24) {
          goto error;      //forward jump to outer label statement
      }
      if (y == -42) {
          goto weirderror;      //forward jump to within an if
      }
      if (y == 42) {
          weirderror: y--;    //a label statement that is part of an if statement: not and 'outer' statement
      }
      int z = __VERIFIER_nondet_int();
      if (z == 666) {
        goto weirderror;
      }
      if (y == z) goto error;   //forward jump
      else goto try_again;      //backward jump
      return 0;
      error: x++;   //outer label statement
      return -1;
}
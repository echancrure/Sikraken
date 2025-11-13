# 0 "SampleCode/Collatz.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "SampleCode/Collatz.c"







extern int __VERIFIER_nondet_int(void);

int main()
{
 int y = __VERIFIER_nondet_int();
 while (y > 1) {
  if (y % 2 == 0) {
   y = y / 2;
  } else {
   y = 3*y + 1;
  }
 }
 return 0;
}

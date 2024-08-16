// function_calls.c
extern int __VERIFIER_nondet_int();

int calc(int x) {
  if (x>42) return 1;
  else return 0;
}


int main() {
  int x, input;
  input = __VERIFIER_nondet_int();
  x = calc(input);
}
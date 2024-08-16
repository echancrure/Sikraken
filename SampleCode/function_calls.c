// function_calls.c
extern int __VERIFIER_nondet_int();

int calc(int x) {
  if (x>42) return 1;
  else return 0;
}

int two_params(int x, int y) {
  if (x+y>42) return 1;
  else return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case: Fibonacci(0) is 0
    } else if (n == 1) {
        return 1; // Base case: Fibonacci(1) is 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
  int x, y, input, input2;
  input = __VERIFIER_nondet_int();
  y = fibonacci(5); // fibonacci(17) returns 1597 after 5167 calls
  x = x + calc(input) + calc(input) + two_params(input, input);
  input2 = __VERIFIER_nondet_int();
  if (input2 == 42) return input2;
}
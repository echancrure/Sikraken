extern void exit(int);
int main() {
    // 1. Implicit conversion (integer promotion)
    char c = 120;
    int i = c;  // char promoted to int
    if (i != 120) exit(1);
    // 2. Implicit conversion (int to float)
    int x = 42;
    float f = x;  // int converted to float
    if (f != 42.0) exit(1);
    // 3. Explicit conversion (float to int)
    float pi = 3.14;
    int truncated = (int)pi;  // float truncated to int
    if (truncated != 3) exit(1);
}
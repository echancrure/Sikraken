extern void exit(int);
int main() {
    // 1. Implicit conversion (integer promotion)
    char c = 120;
    int i = c;  // char promoted to int
    if ((i == 120)) exit(1);
}
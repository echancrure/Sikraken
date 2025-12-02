
// Compile with: gcc -Wall -Wextra -std=c11 demo.c -o demo
#include <stdio.h>
#include <stdarg.h>

void demo(int count, ...) {
    va_list ap;
    va_start(ap, count);

    // Fetch the next argument as a void**
    void **out_ptr = __builtin_va_arg(ap, void **);

    // Fetch the next argument as an int (note default promotions apply)
    int value = __builtin_va_arg(ap, int);

    // Write to the location pointed to by out_ptr
    static int stored;         // static just to keep the address alive for printing
    stored = value;
    *out_ptr = &stored;

    printf("Stored value: %d\n", *(int *)(*out_ptr));

    va_end(ap);
}

int main(void) {
    void *p = NULL;   // we'll pass &p (type: void**) so demo can set it
    demo(2, &p, 42);  // count is arbitrary; next args are void** then int

    // After demo, p should point to an int holding 42
    printf("Main sees: %d\n", *(int *)p);
    return 0;
}

#include "safe_alloc.h"
#include <stdlib.h>
#include <stdio.h>

void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Error: safe_malloc failed for %zu bytes\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

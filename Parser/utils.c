#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void simple_str_copy(char **SS, char *S1) {
    size_t size = strlen(S1) + 1;
    *SS = (char*)malloc(size);
    strcpy_safe(*SS, size, S1);
    free(S1);
}

void simple_str_lit_copy(char** SS, const char* S1) {
    size_t size = strlen(S1) + 1;
    *SS = (char*)malloc(size);
    strcpy_safe(*SS, size, S1);
}
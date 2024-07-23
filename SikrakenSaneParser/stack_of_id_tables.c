//started with chatGPT template Mon 22 July 2024

#include "uthash.h"

#define MAX_ID_LENGTH 255

extern void my_exit(int);

struct symbol {
    char name[MAX_ID_LENGTH];
    char Prolog_name[MAX_ID_LENGTH];
    UT_hash_handle hh;
};

struct scope {
    struct symbol *symbols;
    struct scope *next;
};

// Enter a new scope
void enter_scope(struct scope **scope) {
    struct scope *new_scope = malloc(sizeof(struct scope));
    new_scope->symbols = NULL;
    new_scope->next = *scope;
    *scope = new_scope;
}

// Leave the current scope
void leave_scope(struct scope **scope) {
    struct scope *old_scope = *scope;
    *scope = (*scope)->next;
    // Free the symbols in the old scope
    struct symbol *current_symbol, *tmp;
    HASH_ITER(hh, old_scope->symbols, current_symbol, tmp) {
        HASH_DEL(old_scope->symbols, current_symbol);
        free(current_symbol);
    }
    free(old_scope);
}

// Add a symbol to the current scope
void add_symbol(struct scope *scope, const char *name, const char *Prolog_name) {
    if (scope == NULL) {
        fprintf(stderr, "Sikraken parsing fatal error: Null scope in add_symbol");
        my_exit(201);
    }
    struct symbol *sym = malloc(sizeof(struct symbol));
    strcpy_s(sym->name, MAX_ID_LENGTH, name);
    strcpy_s(sym->Prolog_name, MAX_ID_LENGTH, Prolog_name);
    HASH_ADD_STR(scope->symbols, name, sym);
}

// Find a symbol in the stack of scopes
struct symbol *find_symbol(struct scope *scope, const char *name) {
    struct symbol *sym;
    while (scope) {
        HASH_FIND_STR(scope->symbols, name, sym);
        if (sym) return sym;
        scope = scope->next;
    }
    fprintf(stderr, "Sikraken parsing fatal error: the Id %s was not found in the stack of scopes", name);
    my_exit(202);
    return NULL;
}
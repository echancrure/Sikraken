//started with chatGPT template Mon 22 July 2024
#include "uthash.h"

struct symbol {
    char name[50];
    char type[50];
    UT_hash_handle hh;
};

struct scope {
    struct symbol *symbols;
    struct scope *next;
};

struct scope *scope_stack = NULL;

// Enter a new scope
void enter_scope() {
    struct scope *new_scope = malloc(sizeof(struct scope));
    new_scope->symbols = NULL;
    new_scope->next = scope_stack;
    scope_stack = new_scope;
}

// Leave the current scope
void leave_scope() {
    struct scope *old_scope = scope_stack;
    scope_stack = scope_stack->next;
    // Free the symbols in the old scope
    struct symbol *current_symbol, *tmp;
    HASH_ITER(hh, old_scope->symbols, current_symbol, tmp) {
        HASH_DEL(old_scope->symbols, current_symbol);
        free(current_symbol);
    }
    free(old_scope);
}

// Add a symbol to the current scope
void add_symbol(const char *name, const char *type) {
    struct symbol *sym = malloc(sizeof(struct symbol));
    strcpy(sym->name, name);
    strcpy(sym->type, type);
    HASH_ADD_STR(scope_stack->symbols, name, sym);
}

// Find a symbol in the current scope
struct symbol *find_symbol(const char *name) {
    struct symbol *sym;
    HASH_FIND_STR(scope_stack->symbols, name, sym);
    return sym;
}
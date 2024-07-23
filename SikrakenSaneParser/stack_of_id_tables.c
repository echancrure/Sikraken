//started with chatGPT template Mon 22 July 2024

#include "uthash.h"

#define MAX_ID_LENGTH 255
extern StringBuilder *id_names;
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

// Leave the scope
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

// Add a symbol to the scope
void add_symbol(struct scope *scope, const char *name, const char *Prolog_name) {
    if (scope == NULL) {
        fprintf(stderr, "Sikraken parsing fatal error: Null scope in add_symbol");
        my_exit(201);
    }
    //appending Prolog var names details (e.g. a(I_407, 'ch8_1.adb:39:7:i')) to the string id_names
    size_t const size_name = strlen(name) + 1;
    size_t const size_prolog_name = strlen(Prolog_name) + 1;
    char id_details[MAX_ID_LENGTH*3] = "";
    if (id_names->length != 0) {    //i.e. this is not the first id declared
        sb_append(id_names, ",\n");
    }
    sprintf_s(id_details, MAX_ID_LENGTH * 3, "    a(%s, \'%s\')", Prolog_name, name);
    sb_append(id_names, id_details);

    //adding the id details to the scope
    struct symbol *sym = malloc(sizeof(struct symbol));
    strcpy_s(sym->name, size_name, name);
    strcpy_s(sym->Prolog_name, size_prolog_name, Prolog_name);
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
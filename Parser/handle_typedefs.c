#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

#define HASH_TABLE_SIZE 101

extern void* safe_malloc(size_t);
extern int debugMode;

typedef struct scope_node {
    int scope_nb;
    hash_table* typedef_table;
    struct scope_node* below;
} scope_node;

scope_node* scope_stack = NULL;

void print_scope_stack() {
    scope_node* current_scope = scope_stack;
    if (current_scope == NULL) {
        if (debugMode) {
            printf("Scope stack is empty\n");
            fflush(stdout);
        }
        return;
    }
    while (current_scope != NULL) {
        if (debugMode) {
            printf("Scope %d:\n", current_scope->scope_nb);
            fflush(stdout);
        }
        hash_table* ht = current_scope->typedef_table;
        if (ht) {
            for (int i = 0; i < ht->size; i++) {
                hash_node* node = ht->table[i];
                while (node) {
                    if (debugMode) {
                        printf("\t%s is a %s\n", node->name, (node->is_typedef_name == 1 ? "TYPEDEF_NAME" : "shadow IDENTIFIER"));
                        fflush(stdout);
                    }
                    node = node->next;
                }
            }
        }
        current_scope = current_scope->below;
    }
}

void push_scope(int scope_nb) {
    scope_node* new_scope_node = (scope_node*)safe_malloc(sizeof(scope_node));
    new_scope_node->scope_nb = scope_nb;
    new_scope_node->typedef_table = ht_create(HASH_TABLE_SIZE);
    new_scope_node->below = scope_stack;
    scope_stack = new_scope_node;
    if (debugMode) {
        printf("Pushed scope %d\n", scope_nb);
        fflush(stdout);
    }
}

void pop_scope(int* scope_nb) {
    if (debugMode) {
        if (scope_stack == NULL) {
            printf("Trying to Pop scope %d on empty scope_stack\n", *scope_nb);
        } else {
            printf("Trying to Pop scope %d when scope_stack scope_nb is %d\n", *scope_nb, scope_stack->scope_nb);
        }
        fflush(stdout);
    }
    if (scope_stack != NULL && scope_stack->scope_nb == *scope_nb) {
        scope_node* top_scope = scope_stack;
        scope_stack = scope_stack->below;
        ht_destroy(top_scope->typedef_table);
        free(top_scope);
        if (debugMode) {
            printf("Popped scope %d\n", *scope_nb);
            fflush(stdout);
        }
    }
    (*scope_nb)--;
}

void add_typedef_id(int scope, char* id, int is_typedef_name) {
    if (is_typedef_name != 1 && is_typedef_name != 2) {
        printf("add_typedef_id: Illegal Arguments, invalid is_typedef_name value: %d\n", is_typedef_name);
        fflush(stdout);
        exit(1);
    }
    if (scope_stack == NULL || scope_stack->scope_nb != scope) {
        if (debugMode && scope_stack) {
            fprintf(stderr, "add_typedef_id: Creating a new scope because current scope is %d but incoming scope is %d\n", scope_stack->scope_nb, scope);
        }
        push_scope(scope);
    }
    if (!strncmp(id, "UC_", 3)) {
        id = &id[3];
    } else {
        id[0] = tolower(id[0]);
    }
    ht_insert(scope_stack->typedef_table, id, is_typedef_name);
    if (debugMode) {
        printf("add_typedef_id: Added %s as a %s to typedef table\n", id, (is_typedef_name == 1 ? "TYPEDEF_NAME" : "shadow IDENTIFIER"));
        fflush(stdout);
    }
}

int is_typedef_name(char* id) {
    if (debugMode) {
        printf("is_typedef_name: Looking for %s in typedef list\n", id);
        fflush(stdout);
        print_scope_stack();
    }
    scope_node* current_scope = scope_stack;
    while (current_scope != NULL) {
        int is_typedef = ht_lookup(current_scope->typedef_table, id);
        if (is_typedef) {
            if (debugMode) {
                printf("is_typedef_name: a matching id has been found it is a %s\n", (is_typedef == 1 ? "TYPEDEF_NAME" : "shadow IDENTIFIER"));
                fflush(stdout);
            }
            return is_typedef;
        }
        current_scope = current_scope->below;
    }
    if (debugMode) {
        printf("is_typedef_name: not found %s is a basic IDENTIFIER\n", id);
        fflush(stdout);
    }
    return 0;
}
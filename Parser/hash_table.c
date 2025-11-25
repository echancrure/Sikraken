#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "utils.h"

// Hash function (djb2)
static unsigned long hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// Create a new hash table
hash_table* ht_create(int size) {
    hash_table* ht = (hash_table*)safe_malloc(sizeof(hash_table));
    ht->size = size;
    ht->table = (hash_node**)safe_malloc(sizeof(hash_node*) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Destroy a hash table and free all memory
void ht_destroy(hash_table* ht) {
    if (!ht) return;
    for (int i = 0; i < ht->size; i++) {
        hash_node* node = ht->table[i];
        while (node) {
            hash_node* temp = node;
            node = node->next;
            free(temp->name);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

// Insert a new key-value pair into the hash table
int ht_insert(hash_table* ht, const char* name, int is_typedef_name) {
    if (!ht || !name) return -1;
    unsigned long h = hash(name) % ht->size;
    hash_node* new_node = (hash_node*)safe_malloc(sizeof(hash_node));
    size_t name_len = strlen(name);
    new_node->name = (char*)safe_malloc(name_len + 1);
    strcpy_safe(new_node->name, name_len + 1, name);
    new_node->is_typedef_name = is_typedef_name;
    new_node->next = ht->table[h];
    ht->table[h] = new_node;
    return 0;
}

// Look up a key in the hash table
int ht_lookup(hash_table* ht, const char* name) {
    if (!ht || !name) return 0;
    unsigned long h = hash(name) % ht->size;
    hash_node* node = ht->table[h];
    while (node) {
        if (strcmp(node->name, name) == 0) {
            return node->is_typedef_name;
        }
        node = node->next;
    }
    return 0;
}
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

// Node for storing key-value pairs in the hash table
typedef struct hash_node {
    char* name;
    int is_typedef_name;
    struct hash_node* next;
} hash_node;

// The hash table structure
typedef struct {
    int size;
    hash_node** table;
} hash_table;

// Function prototypes
hash_table* ht_create(int size);
void ht_destroy(hash_table* ht);
int ht_insert(hash_table* ht, const char* name, int is_typedef_name);
int ht_lookup(hash_table* ht, const char* name);

#endif // HASH_TABLE_H
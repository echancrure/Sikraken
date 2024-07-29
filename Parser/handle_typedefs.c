#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void* safe_malloc(size_t);

typedef struct node {
	char* typedef_name;
	struct node* next;
} list_node;

list_node *typedef_list = NULL;


void add_typedef_name(char* id) {
	list_node* new_node = (list_node *)safe_malloc(sizeof(list_node));
	new_node->typedef_name = (char*)safe_malloc(strlen(id) + 1);
	strcpy_s(new_node->typedef_name, strlen(id) + 1, id);
	if (typedef_list != NULL) new_node->next = typedef_list;
	else new_node->next = NULL;
	typedef_list = new_node;
}

int is_typedef_name(char* id) {
	list_node* current = typedef_list;
	while (current != NULL) {
		if (strcmp(current->typedef_name, id) == 0) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void* safe_malloc(size_t);

int typedef_flag = 0;	//indicates that we are within a typedef declaration

typedef struct node {
	char* typedef_name;
	struct node* next;
} list_node;

list_node *typedef_list = NULL;


void add_typedef_name(char* id) {
	list_node* current = typedef_list;
	while (current) {
		current = current->next;
	}
	list_node* new_node = (list_node *)safe_malloc(sizeof(list_node));
	new_node->typedef_name = (char*)safe_malloc(strlen(id) + 1);
	strcpy_s(new_node->typedef_name, strlen(id) + 1, id);
	new_node->next = NULL;
	current = new_node;
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
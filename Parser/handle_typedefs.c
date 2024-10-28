#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void* safe_malloc(size_t);
extern int debugMode;

typedef struct node {
	char* typedef_name;
	struct node* next;
} list_node;

list_node *typedef_list = NULL;

void add_typedef_name(const char* id) {
	//id can be pointer(pointer( ... id ...)) but we only want to add id as a typedef
	char *result = NULL;
	char *first_close_paren = strchr(id, ')');
	if (first_close_paren) {	//there is a ')'
		char *last_open_paren = first_close_paren;
		while (last_open_paren != id && *last_open_paren != '(') {
        	last_open_paren--;
    	}
		int var_length = first_close_paren - last_open_paren - 1;
		result = (char*)malloc(var_length + 1);
		strncpy(result, last_open_paren + 1, var_length);	//overwrite id
		result[var_length] = '\0';
	} else {
		result = strdup(id); // Duplicate the original string
	}
	if (!strncmp(result, "UC_", 3)) result = &result[3];	//removing the "UC_"  prefix before adding to collection of typedef
	else result[0] = tolower(result[0]);	//lowering the first letter before adding to collection of typedef
	if (debugMode) printf("Debug: adding %s to typedef collection\n", result);
	list_node* new_node = (list_node *)safe_malloc(sizeof(list_node));
	new_node->typedef_name = (char*)safe_malloc(strlen(result) + 1);
	strcpy_safe(new_node->typedef_name, strlen(result) + 1, result);
	if (typedef_list != NULL) new_node->next = typedef_list;
	else new_node->next = NULL;
	typedef_list = new_node;
	//free(result);
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
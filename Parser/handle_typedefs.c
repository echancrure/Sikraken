#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void* safe_malloc(size_t);

typedef struct node {
	int is_typedef_name;	// 1 a pure typedef_name, 2 a shadowing identifier
	char* name;				// the name of the id
	struct node* next;
} list_node;

void free_list_node(list_node* node) {
	while (node != NULL) {
		list_node* temp = node;
		node = node->next;
		free(temp->name);
		free(temp);
	}
}

typedef struct scope_node {
	int scope_nb;
	list_node* typedef_list;
	struct scope_node* below;
} scope_node;
scope_node* scope_stack = NULL;

void print_scope_stack() {
	scope_node* current_scope = scope_stack;
	if (current_scope == NULL) {
		if (debugMode) {printf("Scope stack is empty\n"); fflush(stdout);}
		return;
	}
	while (current_scope != NULL) {
		if (debugMode) {printf("Scope %d:\n", current_scope->scope_nb); fflush(stdout);}
		list_node* current_typedef_node = current_scope->typedef_list;
		while (current_typedef_node != NULL) {
			if (debugMode) {printf("\t%s is a %s\n", current_typedef_node->name, (current_typedef_node->is_typedef_name==1 ? "TYPEDEF_NAME" : "shadow IDENTIFIER")); fflush(stdout);}
			current_typedef_node = current_typedef_node->next;
		}
		current_scope = current_scope->below;
	}
}

void push_scope(int scope_nb) {
	scope_node* new_scope_node = (scope_node *)safe_malloc(sizeof(scope_node));
	new_scope_node->scope_nb = scope_nb;
	new_scope_node->typedef_list = NULL;
	if (scope_stack != NULL) new_scope_node->below = scope_stack;
	else new_scope_node->below = NULL;
	scope_stack = new_scope_node;
	if (debugMode) {printf("Pushed scope %d\n", scope_nb); fflush(stdout);}
}

//only pop the top scope if its scope number matches the given scope number
void pop_scope(int *scope_nb) {
	if (debugMode) { 
		if (scope_stack == NULL) printf("Trying to Pop scope %d on empty scope_stack\n", *scope_nb);
		else printf("Trying to Pop scope %d when scope_stack scope_nb is %d\n", *scope_nb, scope_stack->scope_nb); 
		fflush(stdout);
	}
	if (scope_stack != NULL && scope_stack->scope_nb == *scope_nb) {
		scope_node* top_scope = scope_stack;
		scope_stack = scope_stack->below;
		free_list_node(top_scope->typedef_list);
		free(top_scope);
		if (debugMode) {printf("Popped scope %d\n", *scope_nb); fflush(stdout);}
	}
	(*scope_nb)--;
}

void add_typedef_id(int scope, char* id, int is_typedef_name) {
	if (is_typedef_name != 1 && is_typedef_name != 2) {
		printf("add_typedef_id: Illegal Arguments, invalid is_typedef_name value: %d\n", is_typedef_name);
		fflush(stdout);
		exit(1);
	}
	if (scope_stack == NULL) push_scope(scope);
	else if (scope_stack->scope_nb != scope) {	//a new scope is needed		
		if (debugMode) fprintf(stderr, "add_typedef_id: Creating a new scope in because current scope is %d but incoming scope is %d\n", scope_stack->scope_nb, scope);
		push_scope(scope);
	}
	if (!strncmp(id, "UC_", 3)) id = &id[3];	//removing the "UC_"  prefix before adding to collection of typedef
	else id[0] = tolower(id[0]);	//lowering the first letter before adding to collection of typedef
	list_node* new_node = (list_node *)safe_malloc(sizeof(list_node));	
	new_node->is_typedef_name = is_typedef_name;
	new_node->name = (char*)safe_malloc(strlen(id) + 1);
	strcpy_safe(new_node->name, strlen(id) + 1, id);
	if (scope_stack->typedef_list != NULL) new_node->next = scope_stack->typedef_list;	//adding the new node to the front of the list
	else new_node->next = NULL;
	scope_stack->typedef_list = new_node;
	if (debugMode) {printf("add_typedef_id: Added %s as a %s to typedef list\n", id, (is_typedef_name==1 ? "TYPEDEF_NAME" : "shadow IDENTIFIER")); fflush(stdout);}
}

//look for the id in the entire stack of scope of list of typedefs
//called during lexical analysis: see grammar.l
int is_typedef_name(char* id) {
	if (debugMode) {
		printf("is_typedef_name: Looking for %s in typedef list\n", id);
		fflush(stdout);
		print_scope_stack();
	}
	scope_node* current_scope = scope_stack;
	while (current_scope != NULL) {
		list_node* current_typedef_node = current_scope->typedef_list;
		while (current_typedef_node != NULL) {
			if (!strcmp(current_typedef_node->name, id)) {	//a matching node matching the a typedef_name has been found 
				int is_typedef_name = current_typedef_node->is_typedef_name;
				if (debugMode) {printf("is_typedef_name: a matching id has been found it is a %s\n", (is_typedef_name==1 ? "TYPEDEF_NAME" : "shadow IDENTIFIER")); fflush(stdout);}
				return is_typedef_name;
			}
			current_typedef_node = current_typedef_node->next;
		}
		current_scope = current_scope->below;
	}
	if (debugMode) {
		printf("is_typedef_name: not found %s is a basic IDENTIFIER\n", id);
		fflush(stdout);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void* safe_malloc(size_t);
enum symbol { SY_TYPEDEF_NAME = 1, SY_IDENTIFIER, SY_ENUM_CONSTANT };

const char *symbol_str(enum symbol s) {
	switch (s) {
        case SY_TYPEDEF_NAME: return "TYPEDEF_NAME";
        case SY_IDENTIFIER:   return "IDENTIFIER";
        case SY_ENUM_CONSTANT:   return "ENUM CONSTANT";
		default: return "UNKNOWN symbol";
	}
}

int current_enum_value = 0;
char *current_enum_expression = NULL;

void symbol_start_enum(void) {
	current_enum_value = 0;
	current_enum_expression = NULL;
}

void set_enum_expression(char *enum_expression) {
	current_enum_expression = enum_expression;
}

typedef struct node {
	enum symbol symbol_type;	// 1 a pure typedef_name, 2 a shadowing identifier, 3 an enum constant 
	char* name;					// the name of the id
	char* value_str;			// the transformed name for Prolog (or the string containing an enum constant expression e.g. 1 << 1  
	int value_int;				// the value of an enum constant
	struct node* next;
} list_node;

void free_list_nodes(list_node* node) {
	while (node != NULL) {
		list_node* temp = node;
		node = node->next;
		free(temp->name);
		free(temp->value_str);
		free(temp);
	}
}

typedef struct scope_node {
	int scope_nb;
	list_node* symbol_list;
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
		list_node* current_symbol_node = current_scope->symbol_list;
		while (current_symbol_node != NULL) {
			if (debugMode) {
				printf("\t%s is a %s", current_symbol_node->name, symbol_str(current_symbol_node->symbol_type)); 
				if (current_symbol_node->symbol_type==SY_ENUM_CONSTANT) {
					if (current_symbol_node->value_str) printf("%s\n", current_symbol_node->value_str);
					else printf("(%d)\n", current_symbol_node->value_int);
				} else printf("\n");
				
				fflush(stdout);
			}
			current_symbol_node = current_symbol_node->next;
		}
		current_scope = current_scope->below;
	}
}

void push_scope(int scope_nb) {
	scope_node* new_scope_node = (scope_node *)safe_malloc(sizeof(scope_node));
	new_scope_node->scope_nb = scope_nb;
	new_scope_node->symbol_list = NULL;
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
		free_list_nodes(top_scope->symbol_list);
		free(top_scope);
		if (debugMode) {printf("Popped scope %d\n", *scope_nb); fflush(stdout);}
	}
	(*scope_nb)--;
}

list_node *add_symbol(int scope, char* id, enum symbol symbol_type) {
	if (scope_stack == NULL) push_scope(scope);
	else if (scope_stack->scope_nb != scope) {	//a new scope is needed		
		if (debugMode) fprintf(stderr, "add_symbol: Creating a new scope in because current scope is %d but incoming scope is %d\n", scope_stack->scope_nb, scope);
		push_scope(scope);
	}
	if (symbol_type == SY_TYPEDEF_NAME) { //we remove the UC_ or the uppercase for typedef_name only because shadow identifiers are not transformed as prolog vars when this is called
		if (!strncmp(id, "UC_", 3)) id = &id[3];	//removing the "UC_"  prefix before adding to collection of typedef
		else id[0] = tolower(id[0]);	//lowering the first letter before adding to collection of typedef
	}
	list_node* new_node = (list_node *)safe_malloc(sizeof(list_node));	
	new_node->symbol_type = symbol_type;
	new_node->name = (char*)safe_malloc(strlen(id) + 1);
	strcpy_safe(new_node->name, strlen(id) + 1, id);
	new_node->value_str = NULL;
	new_node->value_int = 0;
	if (scope_stack->symbol_list != NULL) new_node->next = scope_stack->symbol_list;	//adding the new node to the front of the list
	else new_node->next = NULL;
	scope_stack->symbol_list = new_node;
	if (debugMode) {printf("add_symbol: added %s as a %s\n", id, symbol_str(symbol_type)); fflush(stdout);}
	return new_node;
}

void add_enum_symbol(int scope, char* id, char* enum_expression) {
	list_node *new_enum_symbol = add_symbol(scope, id, SY_ENUM_CONSTANT);
	if (enum_expression) { 
		current_enum_expression = enum_expression;
		new_enum_symbol->value_str = current_enum_expression;
	}
	else if (current_enum_expression) {
		size_t const size0 = strlen("(+1)") + strlen(current_enum_expression) + 1;
		char *new_enum_expression = (char*)safe_malloc(size0);
		sprintf_safe(new_enum_expression, size0, "(%s+1)", current_enum_expression);
		current_enum_expression = new_enum_expression;
		new_enum_symbol->value_str = current_enum_expression;
	} else new_enum_symbol->value_int = current_enum_value++;
}

//look for the id in the entire stack of scope of list of symbols
//called during lexical analysis: see grammar.l
enum symbol lookup_symbol(char* id) {
	if (debugMode) {
		printf("lookup_symbol: Looking for %s\n", id);
		fflush(stdout);
		print_scope_stack();
	}
	scope_node* current_scope = scope_stack;
	while (current_scope != NULL) {
		list_node* current_typedef_node = current_scope->symbol_list;
		while (current_typedef_node != NULL) {
			if (!strcmp(current_typedef_node->name, id)) {	//a matching node matching the a typedef_name has been found 
				enum symbol symbol_type = current_typedef_node->symbol_type;
				if (debugMode) {printf("lookup_symbol: a matching symbol has been found, it is a %s\n", symbol_str(symbol_type)); fflush(stdout);}
				return symbol_type;
			}
			current_typedef_node = current_typedef_node->next;
		}
		current_scope = current_scope->below;
	}
	if (debugMode) {
		printf("lookup_symbol: not found %s\n", id);
		fflush(stdout);
	}
	return 0;
}
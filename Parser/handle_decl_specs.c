#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void* safe_malloc(size_t);

struct decl_spec {
	char *non_atomic;
	struct {
		bool isVoid;
		bool isSigned;
		bool isUnSigned;
		bool isChar;
		bool isShort;
		bool isInt;
		int longCount;
		bool isFloat;
		bool isDouble;
		char *typeName;
	} atomic;
	struct {
		bool isConst;
		bool isRestrict;
		bool isVolatile;
		bool isAtomic;
	} qualifier;
	struct {
		bool isTypeDef;
		bool isExtern;
		bool isStatic;
		bool isThreadLocal;
		bool isAuto;
		bool isRegister;
	} storage;
	struct {
		bool isInLine;
		bool isNoReturn;
	} function;
	char *alignAs;
};

struct decl_spec_node {
	struct decl_spec decl_spec;
	struct decl_spec_node* next;
};

struct decl_spec_node* decl_spec_stack = NULL;

void pop_decl_spec_stack() {
    if (decl_spec_stack != NULL) {
        struct decl_spec_node* top_decl_spec = decl_spec_stack;
        decl_spec_stack = decl_spec_stack->next;
        free(top_decl_spec->decl_spec.non_atomic);
        free(top_decl_spec->decl_spec.atomic.typeName);
        free(top_decl_spec->decl_spec.alignAs);
        free(top_decl_spec);
    }
}

//In grammar, this function push_decl_spec_stack needs to be called before every instance of declaration_specifiers, specifier_qualifier_list and type_qualifier_list
void push_decl_spec_stack() {
    struct decl_spec_node* new_node = (struct decl_spec_node*)safe_malloc(sizeof(struct decl_spec_node));
    struct decl_spec* new_decl_spec = (struct decl_spec*)safe_malloc(sizeof(struct decl_spec));
	memset(new_decl_spec, 0, sizeof(struct decl_spec));	//all bytes to 0
	new_decl_spec->atomic.typeName = NULL;	//explicit NULL for strings
    new_decl_spec->non_atomic = NULL;	
    new_decl_spec->alignAs = NULL;
    new_node->decl_spec = *new_decl_spec;
    new_node->next = decl_spec_stack;
    decl_spec_stack = new_node;
}

//Types in declaration specifiers are handled separately to remove duplicates (e.g. long int) and always return them in the same order
//It makes the subsequent job of Sikraken using Prolog easier, as the intermediate form is more regular
char *create_declaration_specifiers() {
	// Calculate maximum possible size needed
	size_t size = strlen("spec([], )") + 1;  // base structure
	
	// Storage specifier (only one can be present)
	if (decl_spec_stack->decl_spec.storage.isTypeDef) size += strlen("typedef, ");
	else if (decl_spec_stack->decl_spec.storage.isExtern) size += strlen("extern, ");
	
	// Type name - could be long, so allocate generously
	if (decl_spec_stack->decl_spec.non_atomic != NULL) {
		size += strlen(decl_spec_stack->decl_spec.non_atomic);
	} else if (decl_spec_stack->decl_spec.atomic.typeName != NULL) {
		size += strlen(decl_spec_stack->decl_spec.atomic.typeName);
	} else {
		size += strlen("unsigned(long_long)");  // longest possible atomic type
	}
	
	char *result = (char *)safe_malloc(size);
	strcpy(result, "spec([");
	
	//storage specifier cannot be combined: it must be unique to be valid C
	if (decl_spec_stack->decl_spec.storage.isTypeDef) strcat(result, "typedef, ");
	else if (decl_spec_stack->decl_spec.storage.isExtern) strcat(result, "extern, ");
	else if (decl_spec_stack->decl_spec.storage.isStatic) if (debugMode) printf("Warning: the 'static' storage specifier is always ignored by the parser because Sikraken does not support it yet\n");
	else if (decl_spec_stack->decl_spec.storage.isThreadLocal) if (debugMode) printf("Warning: the '_Thread_local' storage specifier is always ignored by the parser because Sikraken does not support threads\n");
	else if (decl_spec_stack->decl_spec.storage.isAuto) if (debugMode) printf("Warning: the 'auto' storage specifier is always ignored by the parser because it is never used in 'modern' C\n");
	else if (decl_spec_stack->decl_spec.storage.isRegister) if (debugMode) printf("Warning: the 'register' storage specifier is always ignored by the parser because it has no impact on symbolic execution\n");

	//strcat(result, "func(["); //always ignored, only warnings issued: see below
	if (decl_spec_stack->decl_spec.function.isInLine || decl_spec_stack->decl_spec.function.isNoReturn) { //only for functions: can be combined
		if (decl_spec_stack->decl_spec.function.isInLine) if (debugMode) printf("Warning: the 'inline' function specifier is always ignored by the parser because Sikraken does not support it and its implications for testing coverage is unclear\n");
		if (decl_spec_stack->decl_spec.function.isNoReturn) if (debugMode) printf("Warning: the 'noreturn' function specifier is always ignored by the parser because it has no impact on symbolic execution\n");
	}

	if (decl_spec_stack->decl_spec.qualifier.isConst || decl_spec_stack->decl_spec.qualifier.isRestrict || decl_spec_stack->decl_spec.qualifier.isVolatile || decl_spec_stack->decl_spec.qualifier.isAtomic) { //can be combined
		if (decl_spec_stack->decl_spec.qualifier.isConst) if (debugMode) printf("Warning: the 'const' qualifier is always ignored by the parser because it has no impact on symbolic execution\n");
		if (decl_spec_stack->decl_spec.qualifier.isRestrict) if (debugMode) printf("Warning: the 'restrict' pointer qualifier is always ignored by the parser because it has no impact on symbolic execution\n");
		if (decl_spec_stack->decl_spec.qualifier.isVolatile) if (debugMode) printf("Warning: the 'volatile' qualifier is always ignored by the parser because Sikraken does not support it yet\n");
		if (decl_spec_stack->decl_spec.qualifier.isAtomic) if (debugMode) printf("Warning: the 'atomic' qualifier is always ignored by the parser because Sikraken does not support it and its implications for symbolic execution is unclear\n");
	}
	size_t len = strlen(result);
	if (result[len - 2] == ',') result[len - 2] = '\0';		// Remove trailing comma and space if any
	strcat(result, "], ");

	if (decl_spec_stack->decl_spec.non_atomic != NULL) {	//for struct, union, enum types
		strcat(result, decl_spec_stack->decl_spec.non_atomic);
	} else if (decl_spec_stack->decl_spec.atomic.typeName != NULL) { //for typedefname and other types not mentionned below
		if (debugMode) printf("decl_spec_stack->decl_spec.atomic.typeName is %s\n", decl_spec_stack->decl_spec.atomic.typeName);
		strcat(result, decl_spec_stack->decl_spec.atomic.typeName);
	}
	else if (decl_spec_stack->decl_spec.atomic.isVoid) strcat(result, "void");
	else if (decl_spec_stack->decl_spec.atomic.longCount > 0 && decl_spec_stack->decl_spec.atomic.isDouble) strcat(result, "long_double");
	else if (decl_spec_stack->decl_spec.atomic.isDouble) strcat(result, "double");
	else if (decl_spec_stack->decl_spec.atomic.isFloat) strcat(result, "float");
	else if (decl_spec_stack->decl_spec.atomic.longCount > 1 && decl_spec_stack->decl_spec.atomic.isUnSigned) strcat(result, "unsigned(long_long)");
	else if (decl_spec_stack->decl_spec.atomic.longCount > 1) strcat(result, "long_long");
	else if (decl_spec_stack->decl_spec.atomic.longCount == 1 && decl_spec_stack->decl_spec.atomic.isUnSigned) strcat(result, "unsigned(long)");
	else if (decl_spec_stack->decl_spec.atomic.longCount == 1) strcat(result, "long");
	else if (decl_spec_stack->decl_spec.atomic.isShort && decl_spec_stack->decl_spec.atomic.isUnSigned) strcat(result, "unsigned(short)");
	else if (decl_spec_stack->decl_spec.atomic.isShort) strcat(result, "short");
	else if (decl_spec_stack->decl_spec.atomic.isChar && decl_spec_stack->decl_spec.atomic.isUnSigned) strcat(result, "unsigned(char)");
	else if (decl_spec_stack->decl_spec.atomic.isChar) strcat(result, "char");
	else if (decl_spec_stack->decl_spec.atomic.isUnSigned) strcat(result, "unsigned(int)");
	else strcat(result, "int");
	
	if (decl_spec_stack->decl_spec.alignAs != NULL) {
		if (debugMode) printf("Warning: the 'alignas' directive is always ignored by the parser because it has no impact on symbolic execution\n");
	}
	strcat(result, ")");
	pop_decl_spec_stack();	//must be done before next use
	if (debugMode) printf("Debug: create_declaration_specifiers returned: %s\n", result);
	return result;
}
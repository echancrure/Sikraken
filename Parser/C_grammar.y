%{
	// https://www.quut.com/c/ANSI-C-grammar-y.html
	extern void yyerror(const char*);
	extern int yychar;

	#include "string.h"
	#include "definitions.h"
	#include "string_functions.h"
	#include "linkedlists.h"
	#include "parameters.h"
	#include "scopes.h"
	#include "ascii_functions.h"
	#include "switch_functions.h"
	#include "typedef_functions.h"
	#include "enum_functions.h"
	#include "output_functions.h"
	#include "array_functions.h"
	#include "decl_functions.h"
	#include "if_functions.h"
	#include "iteration_functions.h"
	#include "structures.h"
	#include "conversion_functions.h"
%}


%union
{
	char *id;
}

%token	<id> IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	<id> TYPEDEF_NAME ENUMERATION_CONSTANT
%token  ALIGN

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE FORCEINLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	WCHAR_T
%token  __INT8 __INT16 __INT32 __INT64 __PTR32 __PTR64 __UNALIGNED
%token	COMPLEX IMAGINARY
%token	STRUCT UNION ENUM ELLIPSIS

%token DECLSPEC

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%token  __CDECL __CLRCALL __STDCALL __FASTCALL __THISCALL __VECTORCALL


%type <id> microsoft_native_pointer_extension
%type <id> primary_expression
%type <id> constant
%type <id> expression
%type <id> assignment_operator
%type <id> assignment_expression
%type <id> conditional_expression
%type <id> unary_expression
%type <id> argument_expression_list
%type <id> unary_operator postfix_expression
%type <id> cast_expression
%type <id> multiplicative_expression
%type <id> additive_expression
%type <id> shift_expression
%type <id> relational_expression
%type <id> equality_expression
%type <id> and_expression
%type <id> exclusive_or_expression
%type <id> inclusive_or_expression
%type <id> logical_and_expression
%type <id> logical_or_expression
%type <id> type_name
%type <id> abstract_declarator
%type <id> direct_abstract_declarator
%type <id> constant_expression
%type <id> parameter_type_list
%type <id> parameter_list
%type <id> parameter_declaration
%type <id> declaration_specifiers
%type <id> storage_class_specifier
%type <id> type_specifier
%type <id> struct_or_union_specifier
%type <id> struct_or_union
%type <id> struct_declaration
%type <id> specifier_qualifier_list
%type <id> type_qualifier
%type <id> declarator
%type <id> direct_declarator
%type <id> pointer
%type <id> type_qualifier_list
%type <id> identifier_list
%type <id> declaration
%type <id> init_declarator_list
%type <id> init_declarator
%type <id> initializer
%type <id> initializer_list
%type <id> struct_declaration_list
%type <id> enum_specifier
%type <id> enumerator_list
%type <id> enumerator
%type <id> struct_declarator_list
%type <id> struct_declarator
%type <id> declaration_list
%type <id> expression_statement
%type <id> statement
%type <id> labeled_statement
%type <id> compound_statement
%type <id> selection_statement
%type <id> iteration_statement
%type <id> jump_statement
%type <id> function_definition
%type <id> external_declaration
%type <id> block_item
%type <id> block_item_list
%type <id> enumeration_constant
%type <id> string
%type <id> translation_unit
%type <id> designation
%type <id> designator
%type <id> designator_list
%type <id> vc_specific_modifier
%type <id> DECLSPEC_specifiers


%start translation_unit
%%

primary_expression
	: IDENTIFIER
	{
		char* identifier = identifier_function($1); // DEFINITIONS.H
        $$ = (char*) malloc(strlen(identifier) + 1);
        strcpy($$, identifier);
		free(identifier);
        free($1);
	}
	| constant
	{
        $$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, ascii_function($1)); // ASCII_FUNCTIONS.H
		strcpy($$, check_number($1));   // CONVERSION_FUNCTIONS.H
        free($1);
	}
	| string
	{
        $$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
        free($1);
	}
	| '(' expression ')'
	{
        $$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "(");
        strcat($$, $2);
        strcat($$, ")");
		free($2);
	}
	| generic_selection
	;

constant
	: I_CONSTANT		/* includes character_constant */
	{
        $$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
    }
	| F_CONSTANT
	{
        $$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
    }
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	{
        $$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
    }

	;

/* before it has been defined as such */
enumeration_constant
	: IDENTIFIER
	{
        $$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
    }
	;

string
	: STRING_LITERAL		//"blah" or wide_string("blah") see lexer
	{
		$$ = (char*) malloc(strlen($1) + 1);	
        strcpy($$, $1);
        free($1);
	}
	| FUNC_NAME
	{
		$$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
	}
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;

postfix_expression
	: primary_expression
	{
        $$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
        free($1);
	}
	| postfix_expression '[' expression ']'
	{
		if (strstr($1, "[") != NULL)
		{
			char* array = process_arrays($1, $3); // ARRAY_FUNCTIONS.H
			$$ = (char*) malloc(strlen(array) + 1);
			strcpy($$, array);
			free(array);
		}
		else
		{
			$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1 + 1);
			strcpy($$, $1);
            strcat($$, "[");
            strcat($$, $3);
            strcat($$, "]");
		}
		free($1);
		free($3);

	}
	| postfix_expression '(' ')'
	{
		// Process function calls (without arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		char* func_name = copystring($1, 3, strlen($1));
        $$ = (char*) malloc(16 + 3 + strlen(func_name) + 3 + 1 + 1 + 1);
		strcpy($$, "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat($$, "UC_");
		else
			strcat($$, "LC_");

		strcat($$, func_name);
		strcat($$, ", [");
		strcat($$, "]");
		strcat($$, ")");
        free($1);
		free(func_name);
	}
	| postfix_expression '(' argument_expression_list ')'
	{
		// Process function calls (with arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		char *func_name = copystring($1, 3, strlen($1)-3);
        $$ = (char*) malloc(16+ 3 + strlen(func_name) + 3 + strlen($3) + 1 + 1 + 1);
		strcpy($$, "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat($$, "UC_");
		else
			strcat($$, "LC_");

		strcat($$, func_name);
		strcat($$, ", [");
        strcat($$, $3);
        strcat($$, "]");
        strcat($$, ")");
		free(func_name);
        free($1);
        free($3);
	}
	| postfix_expression '.' IDENTIFIER	// structure member access
	{
		$3[0] = convert_tolower($3[0]);
		$$ = (char*) malloc(strlen($1) + strlen($3) + strlen("struct_access(, )")+ 1);
		sprintf($$, "struct_access(%s, %s)", $1, $3);
		free($1);
		free($3);
	}
	| postfix_expression PTR_OP IDENTIFIER
	{
		// Process linked list statements
        $$ = (char*) malloc(11 + strlen($1) + 2 + strlen($3) + 1 + 1);
		$3[0] = convert_tolower($3[0]);
        strcpy($$, "linkedlist(");
		strcat($$, $1);
        strcat($$, ", ");
        strcat($$, $3);
        strcat($$, ")");
        free($1);
        free($3);
	}
	| postfix_expression INC_OP
		{
		// Process statements such as i++;
        $$ = (char*) malloc(25+(2*strlen($1))+1);
        // 17 + 1 + 3 + 1 + strlen($1)+3 = 25 + strlen($1)
        // 17 + strlen($1) + 3 + strlen($1) + 3 = 23 + 2*strlen($1)

		strcpy($$, "\npost_increment(");
		if ( (strstr($1, "dereference") != NULL) && ($1[0] != '(') )
		{
			strcat($$, "(");
            strcat($$, $1);
            strcat($$, " , ");
			strcat($$, "(");
            strcat($$, $1);
            strcat($$, "+1)");
            free($1);
		}
		else
		{
			strcat($$, $1);
            strcat($$, " , ");
            strcat($$, $1);
            strcat($$, "+1)");
            free($1);
		}
	}
	| postfix_expression DEC_OP
	{
		// Process statements such as i--;
        $$ = (char*) malloc(17+strlen($1)+3+strlen($1)+3+1);
		strcpy($$, "\npost_decrement(");
        strcat($$, $1);
		strcat($$, " , ");
        strcat($$, $1);
        strcat($$, "-1)");
        free($1);
	}
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression
	{
        $$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
    }
	| argument_expression_list ',' assignment_expression
	{
        $$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
        strcpy($$, $1);
        strcat($$, ",");
        strcat($$, $3);
        free($1);
        free($3);
    }
	;

unary_expression
	: postfix_expression
	{
        $$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
    }
	| INC_OP unary_expression
	{
		// Process statements such as ++i;
        $$ = (char*) malloc(16 + strlen($2) + 3 + strlen($2) + 3 + 1);
		strcpy($$, "\npre_increment(");
        strcat($$, $2);
        strcat($$, " , ");
		strcat($$, $2);
        strcat($$, "+1)");
        free($2);
	}
	| DEC_OP unary_expression
	{
		// Process statements such as --i;
        $$ = (char*) malloc(16 + strlen($2) + 3 + strlen($2) + 3 + 1);
		strcpy($$, "\npre_decrement(");
        strcat($$, $2);
        strcat($$, " , ");
		strcat($$, $2);
        strcat($$, "-1)");
	}
	| unary_operator cast_expression
	{
		// Process casting expressions
		// DECL_FUNCTIONS.H
		char* unary_cast = process_cast_unary_rule($1, $2);
        $$ = (char*) malloc(strlen(unary_cast) + 1);
		strcpy($$, unary_cast);
		free(unary_cast);
        free($1);
        free($2);
	}
	| SIZEOF unary_expression
	{
		// Process sizeof statements
		$$ = (char*) malloc(6+1+strlen($2)+1+1);
		strcpy($$, "sizeof");
		if ($2[0] != '(')
		{
			strcat($$, "(");
			strcat($$, $2);
			strcat($$, ")");
		}
		else
		{
			strcat($$, $2);
		}
		free($2);
	}
	| SIZEOF '(' type_name ')'
	{
		// Process sizeof(type) statements
		char* type_processed = change_asterisk($3);
		$$ = (char*) malloc(6 + 1 + strlen(type_processed) + 1 + 1);
		strcpy($$, "sizeof");
		strcat($$, "(");
		strcat($$, type_processed); 	// DECL_FUNCTIONS.H
		strcat($$, ")");
		free(type_processed);
		free($3);
	}
	| ALIGNOF '(' type_name ')'
	{
		$$ = (char*) malloc(8 + 1 + strlen($3) + 1 + 1);
		strcpy($$, "alignof");
		strcat($$, "(");
		strcat($$, $3);
		strcat($$, ")");
		free($3);
	}
	;

unary_operator
	: '&'
	{
		$$ = (char*) malloc(10+1);
		strcpy($$, "address_of");

	}
	| '*'
	{
		$$ = (char*) malloc(11+1);
		strcpy($$, "dereference");
	}
	| '+'
	{
		$$ = (char*) malloc(1+1);
		strcpy($$, "+");

	}
	| '-'
	{
		$$ = (char*) malloc(1+1);
		strcpy($$, "-");
	}
	| '~'
	{
		$$ = (char*) malloc(1+1);
		strcpy($$, "~");
	}
	| '!'
	{
		$$ = (char*) malloc(11+1);
		strcpy($$, "exclamation");
	}
	;

cast_expression
	: unary_expression
	{
		// Surround negative numbers with ( and )
		$$ = (char*) malloc(1 + strlen($1) + 1 + 1);
		if ($1[0] == '-')
		{
			strcpy($$, "(");
			strcat($$, $1);
			strcat($$, ")");
		}
		else
		{
			strcpy($$, $1);
		}
		free($1);
	}
	| '(' type_name ')' cast_expression
	{
		// Process cast expressions
		char* typename = change_asterisk($2); // DECL_FUNCTIONS.H
		$$ = (char*) malloc(6 + strlen(typename) + 3 + strlen($4) + 1 + 1);
		strcpy($$, "cast((");
		strcat($$, typename);
		strcat($$, "), ");
		strcat($$, $4);
		strcat($$, ")");
		free(typename);
		free($2);
		free($4);
	}
	;

multiplicative_expression
	: cast_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| multiplicative_expression '*' cast_expression
	{
		// Process * - change '*' to multiply to avoid confusion with the pointer dereference '*'
		$$ = (char*) malloc(9 + strlen($1) + 2 + strlen($3) + 1 + 1);
		strcpy($$, "multiply(");		//should not have to do this at all
		strcat($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	| multiplicative_expression '/' cast_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "/");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| multiplicative_expression '%' cast_expression
	{
		// Process % - change '%' to modulo to avoid confusion with
		// the Prolog comments operator '%'
		$$ = (char*) malloc(4 + strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, "mod(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	;

additive_expression
	: multiplicative_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| additive_expression '+' multiplicative_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "+");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| additive_expression '-' multiplicative_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "-");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

shift_expression
	: additive_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| shift_expression LEFT_OP additive_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<<");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| shift_expression RIGHT_OP additive_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ">>");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

relational_expression
	: shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| relational_expression '<' shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| relational_expression '>' shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ">");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| relational_expression LE_OP shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<=");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| relational_expression GE_OP shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ">=");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;


equality_expression
	: relational_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| equality_expression EQ_OP relational_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "==");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| equality_expression NE_OP relational_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<>");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

and_expression
	: equality_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| and_expression '&' equality_expression 	// bitwise AND
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "&");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

exclusive_or_expression
	: and_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| exclusive_or_expression '^' and_expression 	// bitwise XOR
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "^");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

inclusive_or_expression
	: exclusive_or_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| inclusive_or_expression '|' exclusive_or_expression 	// bitwise OR
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "|");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

logical_and_expression
	: inclusive_or_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| logical_and_expression AND_OP inclusive_or_expression
	{
		$$ = (char*) malloc(6 + strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, "andop(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	;

logical_or_expression
	: logical_and_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| logical_or_expression OR_OP logical_and_expression
	{
		$$ = (char*) malloc(5 + strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, "orop(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	;

conditional_expression
	: logical_or_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| logical_or_expression '?' expression ':' conditional_expression
	{
		// Process ternary expressions from C to Prolog
		$$ = (char*) malloc(8 + 11 + strlen($1) + 2 + 1 + strlen($3) + 1 + 2 + 1 + strlen($5) + 1 + 1 + 1);
		strcpy($$, "ternary(");
		strcat($$, "expression(");
		strcat($$, $1);
		strcat($$, "),");
		strcat($$, "[");
		strcat($$, $3);
		strcat($$, "]");
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $5);
		strcat($$, "]");
		strcat($$, ")");
		free($1);
		free($3);
		free($5);
	}
	;

assignment_expression
	: conditional_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| unary_expression assignment_operator assignment_expression
	{
		$$ = (char*) malloc(strlen($2)+ strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, $2);
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($2);
		free($3);
	}
	;

assignment_operator
	: '='
	{
		$$ = (char*) malloc(13 + 1);
		strcpy($$, "\nassignment(");
	}
	| MUL_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nmul_assignment(");
	}
	| DIV_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\ndiv_assignment(");
	}
	| MOD_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nmod_assignment(");
	}
	| ADD_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nadd_assignment(");
	}
	| SUB_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nsub_assignment(");
	}
	| LEFT_ASSIGN
	{
		$$ = (char*) malloc(18 + 1);
		strcpy($$, "\nleft_assignment(");
	}
	| RIGHT_ASSIGN
	{
		$$ = (char*) malloc(19 + 1);
		strcpy($$, "\nright_assignment(");
	}
	| AND_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nand_assignment(");
	}
	| XOR_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nxor_assignment(");
	}
	| OR_ASSIGN
	{
		$$ = (char*) malloc(16 + 1);
		strcpy($$, "\nor_assignment(");
	}
	;

expression
	: assignment_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| expression ',' assignment_expression
	{
		$$ = (char*) malloc(6 + strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, "comma(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
	}
	;

constant_expression
	: conditional_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

declaration
	: declaration_specifiers ';'
	{
		char* declaration = struct_declaration($1);
		$$ = (char*) malloc(strlen(declaration) + 1);
		strcpy($$, declaration);	// STRUCTURES.H
		free(declaration);
		free($1);

		typedef_flag = NO;
		struct_flag = NO;

	}
	| declaration_specifiers init_declarator_list ';'
	{
		if(typedef_flag == YES) {
			typedef_flag = NO;
			char* declaration = process_typedef($1, $2);

			$$ = (char*) malloc(strlen(declaration) + 1);
			strcpy($$, declaration);	// STRUCTURES.H
			free(declaration);
		}
		else
		{
			int lenSS;
			char* declaration_string = findvariabledetails($1); // DECL_FUNCTIONS.H
			$$ = (char*) malloc(strlen(declaration_string) + 1 + 1);
			strcpy($$, declaration_string);
			free(declaration_string);
			lenSS = strlen($$) - 1;

			if ($$[lenSS] != ',')
				strcat($$, ",");
		}
		free($1);
		free($2);
		struct_flag = NO;
	}
	| static_assert_declaration
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| storage_class_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_specifier declaration_specifiers
	{
		// Only append comma if not a type such as "unsigned int"
		$$ = (char*) malloc(strlen($1) + 2 + strlen($2) + 1);

		strcpy($$, $1);
		if ( (strcmp($1, "signed") == 0) || (strcmp($1, "unsigned") == 0) )
		{
		}
		else if ((strcmp($1, "short") == 0) && (strcmp($2, "int") == 0))
		{
		}
		else
		{
			strcat($$, ", ");
		}
		strcat($$, $2);
		free($1);
		free($2);
	}
	| type_specifier __UNALIGNED declaration_specifiers
	{
		// Only append comma if not a type such as "unsigned int"
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);

		strcpy($$, $1);
		if ( (strcmp($1, "signed") == 0) || (strcmp($1, "unsigned") == 0) )
		{
		}
		else if ((strcmp($1, "short") == 0) && (strcmp($3, "int") == 0))
		{
		}
		else
		{
			strcat($$, ", ");
		}
		strcat($$, $3);
		free($1);
		free($3);
	}
	| type_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_specifier __UNALIGNED
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_qualifier declaration_specifiers
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| function_specifier declaration_specifiers
	{
		$$ = (char*) malloc(strlen($2) + 1);
		strcpy($$, $2);
		free($2);
	}
	| function_specifier
	{
		$$ = (char*) malloc(1 + 1);
		strcpy($$, "");
	}
	| alignment_specifier declaration_specifiers
	{
		$$ = (char*) malloc(strlen($2) + 1);
		strcpy($$, $2);
		free($2);
	}
	| alignment_specifier
	{
		$$ = (char*) malloc(1 + 1);
		strcpy($$, "");
	}
	;


init_declarator_list
	: init_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| init_declarator_list ',' init_declarator
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

init_declarator
	: declarator '=' initializer
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		addvariabledetails($1, $3); // DECL_FUNCTIONS.H
		free($1);
		free($3);
	}
	| declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		if(typedef_flag == YES)
		{
			char* declaration_cleaned = change_typedef($1); // TYPEDEF_FUNCTIONS.H
			add_typedefs(declaration_cleaned); // TYPEDEF_FUNCTIONS.H
			free(declaration_cleaned);
		}
		else
		{
			// addvariables modifies the passed parameter. Reassigning to temp
			char* temp = (char*) malloc(STRING_LIMIT);
			strcpy(temp, $1);
			addvariables(temp, NO);	// DECL_FUNCTIONS.H
			free(temp);
		}
		free($1);
	}
	;

storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
	{
		$$ = (char*) malloc(7 + 1);
		strcpy($$, "typedef");
		typedef_flag = YES;
	}
	| EXTERN
	{
		$$ = (char*) malloc(6 + 1);
		strcpy($$, "extern");
	}
	| STATIC
	{
		$$ = (char*) malloc(7 + 1);
		strcpy($$, "static_");
	}
	| THREAD_LOCAL
	| AUTO
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
	| REGISTER
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
	;

type_specifier
	: VOID
	{
		$$ = (char*) malloc(4 + 1);
		strcpy($$, "void");
	}
	| CHAR
	{
		$$ = (char*) malloc(4 + 1);
		strcpy($$, "char");
	}
	| SHORT
	{
		$$ = (char*) malloc(5 + 1);
		strcpy($$, "short");
	}
	| INT
	{
		$$ = (char*) malloc(3 + 1);
		strcpy($$, "int");
	}
	| LONG
	{
		$$ = (char*) malloc(4 + 1);
		strcpy($$, "long");
	}
	| FLOAT
	{
		 $$ = (char*) malloc(5 + 1);
		 strcpy($$, "float");
	}
	| DOUBLE
	{
		$$ = (char*) malloc(6 + 1);
		strcpy($$, "double");
	}
	| SIGNED
	{
		$$ = (char*) malloc(6 + 1);
		strcpy($$, "signed");
	}
	| UNSIGNED
	{
		 $$ = (char*) malloc(8 + 1);
		 strcpy($$, "unsigned");
	}
	| BOOL
	{
		 $$ = (char*) malloc(4 + 1);
		 strcpy($$, "bool");
	}
	| COMPLEX
	{
		 $$ = (char*) malloc(7 + 1);
		 strcpy($$, "complex");
	}
	| IMAGINARY	  	/* non-mandated extension */
	{
		 $$ = (char*) malloc(9 + 1);
		 strcpy($$, "imaginary");
	}
	| atomic_type_specifier
	| struct_or_union_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| enum_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| TYPEDEF_NAME		/* after it has been defined as such */
	{
		char* name = change_typedef($1);
		$$ = (char*) malloc(strlen(name) + 1);
		strcpy($$, name);	 // TYPEDEF_FUNCTIONS.H
		free(name);
		free($1);
	}
	| __INT8
	{
		$$ = (char*) malloc(6 + 1);
		strcpy($$, "__int8");
	}
	| __INT16
	{
		$$ = (char*) malloc(7 + 1);
		strcpy($$, "__int16");
	}
	| __INT32
	{
		$$ = (char*) malloc(7 + 1);
		strcpy($$, "__int32");
	}
	| __INT64
	{
		$$ = (char*) malloc(7 + 1);
		strcpy($$, "__int64");
	}
	| WCHAR_T
	{
		$$ = (char*) malloc(7 + 1);
		strcpy($$, "wchar_t");
	}
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	{
		$$ = (char*) malloc(strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, ", [");
		strcat($$, $3);
		Pop(); 	// SCOPES.H
		strcat($$, "]");
		free($1);
		free($3);
	}
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	{
		// change the structure name.
		char * struct_name = (char *) malloc(3 + strlen($2) + 1);
		if (islower($2[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, $2);

		$$ = (char*) malloc(strlen($1) + 2 + strlen(struct_name) + 2 + 1 + strlen($4) + 1 + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, struct_name);
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $4);
		Pop(); 	// SCOPES.H
		strcat($$, "]");

		free(struct_name);
		free($1);
		free($2);
		free($4);
	}
	| struct_or_union DECLSPEC_specifiers IDENTIFIER '{' struct_declaration_list '}'
	{
		// change the structure name.
		char* struct_name = (char *) malloc(3 + strlen($3) + 1);
		if (islower($3[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, $3);

		$$ = (char*) malloc(strlen($1) + 2 + strlen(struct_name) + 2 + 1 + strlen($5) + 1 + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, struct_name);
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $5);
		Pop(); 	// SCOPES.H
		strcat($$, "]");

		free(struct_name);
		free($1);
		free($2);
		free($3);
		free($5);
	}
	| struct_or_union IDENTIFIER
	{
		// change the structure name.
		char * struct_name = (char *) malloc(3 + strlen($2) + 1);
		if (islower($2[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, $2);

		$$ = (char*) malloc(strlen($1) + 2 + strlen(struct_name) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, struct_name);
		free($1);
		free($2);
		free(struct_name);
	}
	;

DECLSPEC_specifiers
	: DECLSPEC '(' extended_decl_modifier_seq ')'
	{
		$$ = (char*) malloc(1 + 1);
		strcpy($$, "");
	}
	| DECLSPEC '(' extended_decl_modifier_seq ')' DECLSPEC_specifiers
	{
		$$ = (char*) malloc(1 + 1);
		strcpy($$, "");
		free($5);
	}
	;

extended_decl_modifier_seq
	: ALIGN '(' I_CONSTANT ')'
	{
		free($3);
	}
	| ALIGN '(' F_CONSTANT ')'
	{
		free($3);
	}
	| IDENTIFIER
	{
		free($1);
	}
	|  type_qualifier
	{
		free($1);
	}
	| IDENTIFIER '(' primary_expression ')'
	{
		free($1);
		free($3);
	}
	;


struct_or_union
	: STRUCT
	{
		$$ = (char*) malloc(7 + 1);
		strcpy($$, "struct ");
	}
	| UNION
	{
		$$ = (char*) malloc(6 + 1);
		strcpy($$, "union ");
	}
	;

struct_declaration_list
	: struct_declaration
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| struct_declaration_list struct_declaration
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

struct_declaration
	: specifier_qualifier_list ';'
	| specifier_qualifier_list struct_declarator_list ';'
	{
		if (strstr($2, ",") != NULL) {	// Many variables declared in $2, they must be separated.
			char* struct_definition_string = seperate_fields($1, $2); // STRUCTURES.H
			$$ = (char*) malloc(strlen(struct_definition_string) + 1);
			strcpy($$, struct_definition_string);
			free(struct_definition_string);
		}
		else {	// Build the structure list, removing the 'struct' keyword if present
			char* struct_definition_string = strip_struct($1); // STRUCTURES.H
			$$ = (char*) malloc(2 + strlen($2) + 3 + strlen(struct_definition_string) + 1 + 1);
			strcpy($$, "([");
			strcat($$, $2);
			strcat($$, "], ");
			strcpy($1, struct_definition_string);
			strcat($$, $1);
			strcat($$, ")");
			free(struct_definition_string);
		}
		free($1);
		free($2);
		struct_flag = NO;
	}
	;
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| type_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_qualifier specifier_qualifier_list
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

struct_declarator_list
	: struct_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		$1[0] = convert_tolower($1[0]);
		strcpy($$, $1);
		free($1);
	}
	| struct_declarator_list ',' struct_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ",");
		$3[0] = convert_tolower($3[0]);
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

struct_declarator
	: ':' constant_expression
	{
		$$ = (char*) malloc(1 + strlen($2) + 1);
		strcpy($$, ":");
		strcat($$, $2);
		free($2);
	}
	| declarator ':' constant_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ":");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
		{
		// Build enumeration list.
		// Pop Scope when '}' is parsed and reset enumerations counter
		$$ = (char*) malloc(7 + 1 + strlen($3) + 1 + 1);
		strcpy($$, "enum , ");
		strcat($$, "[");
		strcat($$, $3);
		Pop(); 			// SCOPES.H
		strcat($$, "]");
		reset_enumcounter(); 	// ENUM_FUNCTIONS.H
		free($3);
	}
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	{
		// Build enumeration list.
		// Change their name to Prolog equivalent using change_enum()
		// Add the name to NAMES file using printnames()
		// Add the literal to Enum linked list using add_enums()
		// Pop Scope when '}' is parsed and reset enumerations counter

		char* enum_name = change_enum($2); // ENUM_FUNCTIONS.H

		$$ = (char*) malloc(7 + 1 + strlen(enum_name) + 1 + 2 + 1 + strlen($4) + 1 + 1);

		strcpy($$, "enum , ");
		strcat($$, "[");
		strcat($$, enum_name);
		strcat($$, "]");
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $4);
		Pop(); 	// SCOPES.H
		strcat($$, "]");
		reset_enumcounter(); // ENUM_FUNCTIONS.H

		free(enum_name);
		free($2);
		free($4);
	}
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	{
		// Change enum name to Prolog equivalent using change_enum()
		char* enum_name = change_enum($2); // ENUM_FUNCTIONS.H
		$$ = (char*) malloc(7 + strlen(enum_name) + 1);
		strcpy($$, "enum , ");
		strcat($$, enum_name);
		free($2);
		free(enum_name);
	}
	;

enumerator_list
	: enumerator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| enumerator_list ',' enumerator
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

/* identifiers must be flagged as ENUMERATION_CONSTANT */
enumerator
	: enumeration_constant '=' constant_expression
	{
		/*
			Process enumeration literals with initializations:
			e.g. enum daYs {mon, tues, wed = 20, thurs, fri = 7};
			Change the enum name to Prolog equivalent using change_enum()
			Add the name to NAMES file using printnames()
			Add the literal to Enum linked list using add_enums(), with its enum value.
		*/
		char *enum_name = change_enum($1); // ENUM_FUNCTIONS.H

		int i = atoi($3); // change string to integer

		$$ = (char*) malloc(strlen(enum_name) + 1);
		strcpy($$, enum_name);
		add_enums($1, i); 			// ENUM_FUNCTIONS.H

		free(enum_name);
		free($1);
		free($3);
	}
	| enumeration_constant
	{
		/*
			Process enumeration literals.
			Change their name to Prolog equivalent using change_enum()
			Add the name to NAMES file using printnames()
			Add the literal to Enum linked list using add_enums()
		*/
		char* enum_name = change_enum($1); // ENUM_FUNCTIONS.H

		$$ = (char*) malloc(strlen(enum_name) + 1);
		strcpy($$, enum_name);
		add_enums($1, -1);			// ENUM_FUNCTIONS.H

		free(enum_name);
		free($1);
	}
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'
	;

type_qualifier
	: CONST
	{
		$$ = (char*) malloc(5 + 1);
		strcpy($$, "const");
	}
	| RESTRICT
	{
		$$ = (char*) malloc(8 + 1);
		strcpy($$, "restrict");
	}
	| VOLATILE
	{
		$$ = (char*) malloc(8 + 1);
		strcpy($$, "volatile");
	}
	| ATOMIC
	{
		$$ = (char*) malloc(6 + 1);
		strcpy($$, "atomic");
	}
	;

function_specifier
	: INLINE
	| FORCEINLINE
	| NORETURN
	| DECLSPEC_specifiers
	{
		free($1);
	}
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

declarator
	: pointer direct_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| pointer microsoft_native_pointer_extension direct_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, $3);
		free($1);
		free($2);
		free($3);
	}
	| direct_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

microsoft_native_pointer_extension
	: __PTR32 
	{
		$$ = (char*) malloc(1 + 1);
		strcpy($$, "");
	}
	| __PTR64
	{
		$$ = (char*) malloc(1 + 1);
		strcpy($$, "");
	}
	;

direct_declarator
	: IDENTIFIER
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| '(' declarator ')'
	{
		if(typedef_flag == YES) {
			typedef_flag = NO;
			char *declaration_cleaned = change_typedef($2); // TYPEDEF_FUNCTIONS.H
			add_typedefs(declaration_cleaned); // TYPEDEF_FUNCTIONS.H
			free(declaration_cleaned);
		}

		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	| direct_declarator '[' ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, "]");
		free($1);
	}
	| direct_declarator '[' '*' ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, "*");
		strcat($$, "]");
		free($1);
	}
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
		free($3);
	}
	| TYPEDEF_NAME '[' assignment_expression ']' 
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
		free($3);
	}
	| direct_declarator '(' parameter_type_list ')'
	{
		/* 	function prototypes and definitions come through this rule.
			in order to distinguish them later on from variables we
			add the string "function_prototype" to $$
			if this is the function definition this will have to be stripped later.
			if it is the function prototype it is left as it is.
		*/
		$$ = (char*) malloc(19 + strlen($1) + 2 + 1 + strlen($3) + 1 + 2 + 2 + 1);

		if(typedef_flag == YES) {
			char *declaration_cleaned = change_typedef($1); // TYPEDEF_FUNCTIONS.H
			add_typedefs(declaration_cleaned); // TYPEDEF_FUNCTIONS.H
			free(declaration_cleaned);
			typedef_flag = NO;
		}

		$1[0] = convert_tolower($1[0]);
		strcpy($$, "function_prototype(");
		strcat($$, $1);
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $3);
		strcat($$, "]");
		strcat($$, ", ");
		strcat($$, ")."); //15 Jun 2024 was strcat($$, ").") full stop removed then added again due to postprocessing mess
		free($1);
		free($3);
	}
	| direct_declarator '(' ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, ")");
		free($1);
	}
	| direct_declarator '(' identifier_list ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	| vc_specific_modifier IDENTIFIER
	{
		struct_flag = NO;
		
		// Visual C extension
		$$ = (char*) malloc(strlen($2) + 1);
		strcpy($$, $2);
		free($1);
		free($2);
	}
	| '(' vc_specific_modifier declarator ')'
	{
		if(typedef_flag == YES) {
			typedef_flag = NO;
			char *type_definition = change_typedef($3); // TYPEDEF_FUNCTIONS.H
			add_typedefs(type_definition); // TYPEDEF_FUNCTIONS.H
			free(type_definition);
		}
		// Visual C extension
		$$ = (char*) malloc(strlen($3) + 1);
		strcpy($$, $3);
		free($2);
		free($3);
	}
	;

vc_specific_modifier
    : __CDECL
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
    | __CLRCALL
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
    | __STDCALL
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
    | __FASTCALL
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
    | __THISCALL
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
    | __VECTORCALL
	{
		$$ = (char*) malloc(1);
		strcpy($$, "");
	}
    ;

pointer
	: '*' type_qualifier_list pointer
	{
		$$ = (char*) malloc(11 + strlen($2) + strlen($3) + 1);
		strcpy($$, "mypointer, ");
		strcat($$, $2);
		strcat($$, $3);
		free($2);
		free($3);
	}
	| '*' type_qualifier_list
	{
		$$ = (char*) malloc(11 + strlen($2) + 1);
		strcpy($$, "mypointer, ");
		strcat($$, $2);
		free($2);
	}
	| '*' pointer
	{
		$$ = (char*) malloc(11 + strlen($2) + 1);
		strcpy($$, "mypointer, ");
		strcat($$, $2);
		free($2);
	}
	| '*'
	{
		$$ = (char*) malloc(9 + 1);
		strcpy($$, "mypointer");
	}
	;

type_qualifier_list
	: type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_qualifier_list type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS
	{
		$$ = (char*) malloc(strlen($1) + 1 + 3 + 1);
		strcpy($$, $1);
		strcat($$, ",");
		strcat($$, "...");
		free($1);
	}
	| parameter_list
	{
		$$ = (char*) malloc(strlen($1) + 1);
		int lenSS = strlen($1) - 1;
		if ($1[lenSS] == ',')
			$1[lenSS] = ' ';
		strcpy($$, $1);
		free($1);
	}
	;

parameter_list
	: parameter_declaration
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
		struct_flag = NO;
	}
	| parameter_list ',' parameter_declaration
	{
		$$ = (char*) malloc(strlen($1) + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, $3);
		free($1);
		free($3);
		struct_flag = NO;
	}
	;

parameter_declaration
	: declaration_specifiers declarator
	{
		if (PListFirstUse == NO)	// PARAMETERS.H
		{
			PListFirstUse = YES;	// PARAMETERS.H
			P = CreatePList();	// PARAMETERS.H
		}
		PushPList($2, P);		// PARAMETERS.H
		Push(yylineno);	// SCOPES.H
		addvariables($2, YES);			// DECL_FUNCTIONS.H
		char* declaration_string = findvariabledetails($1); // DECL_FUNCTIONS.H
		$$ = (char*) malloc(strlen(declaration_string) + 1);
		strcpy($$, declaration_string);
		free(declaration_string);
		free($1);
		free($2);
	}
	| declaration_specifiers abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| declaration_specifiers vc_specific_modifier abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| declaration_specifiers
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

identifier_list
	: IDENTIFIER
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| identifier_list ',' IDENTIFIER
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ",");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

type_name
	: specifier_qualifier_list abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| specifier_qualifier_list abstract_declarator microsoft_native_pointer_extension
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
		free($3);
	}
	| specifier_qualifier_list
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| IDENTIFIER
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

abstract_declarator
	: pointer direct_abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| '(' vc_specific_modifier pointer ')' direct_abstract_declarator
	{
		$$ = (char*) malloc(strlen($3) + strlen($5) + 1);
		strcpy($$, $3);
		strcat($$, $5);
		free($2);
		free($3);
		free($5);
	}
	| pointer
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| direct_abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	| '[' ']'
	{
		$$ = (char*) malloc(1 + 1 + 1);
		strcpy($$, "[");
		strcat($$, "]");
	}
	| '[' '*' ']'
	{
		$$ = (char*) malloc(1 + 1 + 1 + 1);
		strcpy($$, "[");
		strcat($$, "*");
		strcat($$, "]");
	}
	| '[' STATIC type_qualifier_list assignment_expression ']'
	| '[' STATIC assignment_expression ']'
	| '[' type_qualifier_list STATIC assignment_expression ']'
	| '[' type_qualifier_list assignment_expression ']'
	| '[' type_qualifier_list ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, "]");
		free($1);
	}
	| direct_abstract_declarator '[' '*' ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, "*");
		strcat($$, "]");
		free($1);
	}
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	{
		$$ = (char*) malloc(1 + 1 + 1);
		strcpy($$, "(");
		strcat($$, ")");
	}
	| '(' parameter_type_list ')'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	| direct_abstract_declarator '(' ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, ")");
		free($1);
	}
	| direct_abstract_declarator '(' parameter_type_list ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	;

initializer
	: '{' initializer_list '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "[");
		strcat($$, $2);
		Pop(); 	// SCOPES.H
		strcat($$, "]");

		free($2);
	}
	| '{' initializer_list ',' '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1 + 1);
		strcpy($$, "{");
		strcat($$, $2);
		strcat($$, ",");
		Pop(); 	// SCOPES.H
		strcat($$, "}");

		free($2);
	}
	| assignment_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

initializer_list
	: designation initializer
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, ",");
		strcat($$, $2);
		free($1);
		free($2);
	}
	| initializer
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1); 
		strcat($$, ","); 
		strcat($$, $3);

		free($1);
		free($3);
	}
	;

designation
	: designator_list '='
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1);
		strcpy($$, $1);
		strcat($$, "=");
		free($1);
	}
	;

designator_list
	: designator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| designator_list designator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

designator
	: '[' constant_expression ']'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "[");
		strcat($$, $2);
		strcat($$, "]");
		free($2);
	}
	| '.' IDENTIFIER
	{
		$$ = (char*) malloc(7 + strlen($2) + 1 + 1);
		strcpy($$, "access(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	;

statement
	: labeled_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| compound_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| expression_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| selection_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| iteration_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| jump_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

labeled_statement
	: IDENTIFIER ':' statement
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ":");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| CASE constant_expression ':' statement
	{
		char* case_string = case_statement($2, $4); // SWITCH_FUNCTIONS.H
		$$ = (char*) malloc(strlen(case_string) + 1);
		strcpy($$, case_string);
		free(case_string);
		free($2);
		free($4);
	}
	| DEFAULT ':' statement
	{
		char* default_string = default_statement($3); // SWITCH_FUNCTIONS.H
		$$ = (char*) malloc(strlen(default_string) + 1);
		strcpy($$, default_string);
		free(default_string);
		free($3);
	}
	;

compound_statement
	: '{' '}'
	{
		$$ = (char*) malloc(1 + 1 + 1);
		strcpy($$, "[");
		Pop(); 	// SCOPES.H
		strcat($$, "]");
	}
	| '{'  block_item_list '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "[");
		strcat($$, $2);
		Pop();  	// SCOPES.H

		int lenSS = strlen($$) - 1;
		if ($$[lenSS] == ',')
			$$[lenSS] = ']';
		else
			strcat($$, "]");
		free($2);
	}
	;

block_item_list
	: block_item
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| block_item_list block_item
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($2) + 1);
		strcpy($$, $1);

		int lenSS = strlen($$) - 1;
		if ($$[lenSS] != ',')
			strcat($$, ",");

		strcat($$, $2);
		free($1);
		free($2);
	}
	;

block_item
	: declaration
	{

		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

expression_statement
	: ';'
	{
		$$ = (char*) malloc(5);
		strcpy($$, "null");
	}
	| expression ';'
	{
		$$ = (char*) malloc(21 + strlen($1) + 1 + 1);
		strcpy($$, "expression_statement(");
		strcat($$, $1);
		strcat($$, ")");
		free($1);
	}
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement
	{
		char* if_else_statement_definition = ifelse_statement($3, $5, $7); // IF_FUNCTIONS.H
		$$ = (char*) malloc(strlen(if_else_statement_definition) + 1);
		strcpy($$, if_else_statement_definition);
		free(if_else_statement_definition);
		free($3);
		free($5);
		free($7);
	}
	| IF '(' expression ')' statement
	{
		char* if_statement_definition = if_statement($3, $5); // IF_FUNCTIONS.H
		$$ = (char*) malloc(strlen(if_statement_definition) + 1);
		strcpy($$, if_statement_definition);
		free(if_statement_definition);
		free($3);
		free($5);
	}
	| SWITCH '(' expression ')' statement
	{
		char* switch_statement_definition = switch_statement($3, $5); // SWITCH_FUNCTIONS.H
		$$ = (char*) malloc(strlen(switch_statement_definition) + 1);
		strcpy($$, switch_statement_definition);
		free(switch_statement_definition);
		free($3);
		free($5);
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement
	{
		char* while_statement_definition = while_statement($3, $5); // ITERATION_FUNCTIONS.H
		$$ = (char*) malloc(strlen(while_statement_definition) + 1);
		strcpy($$, while_statement_definition);
		free(while_statement_definition);
		free($3);
		free($5);
	}
	| DO statement WHILE '(' expression ')' ';'
	{
		char* do_statement_definition = do_statement($2, $5); // ITERATION_FUNCTIONS.H
		$$ = (char*) malloc(strlen(do_statement_definition) + 1);
		strcpy($$, do_statement_definition);
		free(do_statement_definition);
		free($2);
		free($5);
	}
	| FOR '(' expression_statement expression_statement ')' statement
	{
		char* for_statement_definition = for2_statement($3, $4, $6); // ITERATION_FUNCTIONS.H
		$$ = (char*) malloc(strlen(for_statement_definition) + 1);
		strcpy($$, for_statement_definition);
		free(for_statement_definition);
		free($3);
		free($4);
		free($6);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement
	{
		char* for_statement_definition = for_statement($3, $4, $5, $7); // ITERATION_FUNCTIONS.H
		$$ = (char*) malloc(strlen(for_statement_definition) + 1);
		strcpy($$, for_statement_definition);
		free(for_statement_definition);
		free($3);
		free($4);
		free($5);
		free($7);
	}
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	{
		$$ = (char*) malloc(4 + strlen($2) + 1 + 1);
		strcpy($$, "goto");
		strcat($$, $2);
		strcat($$, ";");
		free($2);
	}
	| CONTINUE ';'
	{
		$$ = (char*) malloc(8 + 1);
		strcpy($$, "continue");
	}
	| BREAK ';'
	{
		$$ = (char*) malloc(5 + 1);
		strcpy($$, "break");
	}
	| RETURN ';'
	{
		$$ = (char*) malloc(6 + 1);
		strcpy($$, "return");
	}
	| RETURN expression ';'
	{
		$$ = (char*) malloc(7 + strlen($2) + 1 + 1);
		strcpy($$, "return(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	;

translation_unit
	: external_declaration
	{
		//$$ = (char*) malloc(strlen($1) + 1);
		//strcpy($$, $1);
		//free($1);
	}
	| translation_unit external_declaration
	{
		//$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		//strcpy($$, $1);
		//strcat($$, $2);
		//free($1);
		//free($2);
	}
	;

external_declaration
	: function_definition
	{
		//$$ = (char*) malloc(strlen($1) + 1);
		//strcpy($$, $1);
		fprintf(pl_file, "%s\n", $1);
		free($1);
		struct_flag = NO;
	}
	| declaration
	{
		// Global Variable declarations
		int lenS1 = strlen($1) - 1;
		$$ = (char*) malloc(20 + strlen($1) + 11 + 1);
		strcpy($$, "\nglobal_variables([");
		if($1[lenS1] == ',') $1[lenS1] = ' ';
		strcat($$, $1);
		strcat($$, "], void),\n");
		fprintf(pl_file, "%s\n", $$);
		free($1);
	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		strcat($$, $3);
		strcat($$, $4);
		free($1);
		free($2);
		free($3);
		free($4);
	}
	| declaration_specifiers declarator compound_statement
	{
		// Function Defintions
		char* function = process_functions($1, $2, $3);
		$$ = (char*) malloc(strlen(function) + 1);
		strcpy($$, function);	// DECL_FUNCTIONS.H
		free(function);
		free($1);
		free($2);
		free($3);
	}
	;

declaration_list
	: declaration
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| declaration_list declaration
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

%%
#include <stdio.h>
#include "lex.yy.c"
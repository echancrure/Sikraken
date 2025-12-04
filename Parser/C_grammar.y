/****************************************************************************************************/
/* Bison documentation: https://www.gnu.org/software/bison/manual/html_node/index.html              */
/****************************************************************************************************/

%define parse.error verbose
%locations                  /* enable locations: defines YYLTYPE and yylloc */

%{
#ifdef _MSC_VER
	#include <io.h>
	#define fopen_safe(pFile, filename, mode) fopen_s(pFile, filename, mode)
	#define access_safe(path, mode) _access(path, mode)
	#define strcpy_safe(dest, destsz, src) strcpy_s(dest, destsz, src)
	#define strcat_safe(dest, destsz, src) strcat_s(dest, destsz, src)
	#define sprintf_safe(buffer, size, format, ...) sprintf_s(buffer, size, format, __VA_ARGS__)
#else
	#include <unistd.h>
	#include <errno.h>
	#define fopen_safe(pFile, filename, mode) ((*pFile = fopen(filename, mode)) == NULL ? errno : 0)
	#define access_safe(path, mode) access(path, mode)
	#define strcpy_safe(dest, destsz, src) strncpy(dest, src, destsz)
	#define strcat_safe(dest, destsz, src) strncat(dest, src, destsz)
	/* allow calling sprintf_safe(buffer,size, "fmt") or with extra args */
	#if defined(__GNUC__) || defined(__clang__)
	#define sprintf_safe(buffer, size, format, ...) snprintf(buffer, size, format, ##__VA_ARGS__)
	#else
	/* conservative fallback for other compilers -- ensure callers pass at least format */
	#define sprintf_safe(buffer, size, format, ...) snprintf(buffer, size, format, __VA_ARGS__)
	#endif
#endif

int debugMode = 0;					//flag to indicate if we are in debug mode set by -d command line switch

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser.h"
#include "utils.c"
#include "handle_typedefs.c"		//stack to keep track of typedef declared and shadowing by identifiers
#include "handle_decl_specs.c"		//

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;

#define MAX_BRANCH_STR 9		//maximum length of the string encoding the number of branches (max is "999999999" i.e. 1 billion - 1)

int dataModel = 32;				//flag to indicate data model used in the C code under analysis; set by -m32 or -m64 on the command line; default is 32
long int TARGET_LONG_MAX = 2147483647L; //the default LONG_MAX for the code under test if dataModel = 32
FILE* pl_file;					//the file of containing the Prolog predicated after parsing the target C file
char *i_file_uri;
FILE *i_file;
char *pl_file_uri;				//the full path to the Prolog file: pl_file
int branch_nb = 1;				//unique id for branches created

//start: ugly, breaking parsing spirit, flags and temporary variables
int typedef_flag = 0; 			//indicates that we are within a typedef declaration
int in_tag_declaration = 0;		//indicates to the lexer that we are in the tag namespace (for struct, union and enum tags) and that identifier should not be checked for typedef
int in_member_namespace = 0;	//indicates to the lexer that we are in the member namespace (for members of structs and unions) and that identifier should not be checked for typedef
int in_label_namespace = 0;		//used in lexer

int current_scope = 0;

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements

void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);

void fsm_reset(void);
void fsm_set_to_specs(void);
void fsm_from_none_to_spec(void);


enum ParserExitCodes {
    SUCCESS = 0,
    COMMAND_LINE_FAILURE = 1,
    PARSING_ERROR = 2,
	LEXING_FAILURE = 3,
    RENAME_ME = 9
};

%}

%union {
	char* id;
	struct for_stmt {
        char *init;				//the first part of a for statement: the initialisations
        char *cond;				//the second part of a for statement: the condition
        char *update;			//the third part of a for statement: the update
    } for_stmt_type;
	struct declarator {
		char *full;				//the full declarator
		char *ptr_declarator;	//only the declarator after pointer declarations
	} declarator_type;
}

%token <id> IDENTIFIER TYPEDEF_NAME I_CONSTANT F_CONSTANT ENUMERATION_CONSTANT STRING_LITERAL
%token  FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN

%token  TYPEDEF
%token  EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token ALIGNAS ALIGNOF ATOMIC_SPECIFIER ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL
%token INT128 FLOAT128 VA_LIST BUILTIN_VA_ARG TYPEOF TYPEOF_UNQUAL

%type <id> init_declarator initializer pointer pointer_star init_declarator_list 
%type <id> abstract_declarator_opt
%type <id> expression constant_expression assignment_expression conditional_expression assignment_operator
%type <id> logical_or_expression logical_and_expression inclusive_or_expression exclusive_or_expression and_expression equality_expression equality_expression_op relational_expression relational_expression_operator shift_expression shift_expression_op additive_expression additive_expression_op
%type <id> comma_opt
%type <id> multiplicative_expression multiplicative_expression_op cast_expression unary_expression unary_operator unary_inc_dec postfix_expression 
%type <id> type_name argument_expression_list primary_expression constant string enumeration_constant
%type <id> initializer_list designation designator_list designator
%type <id> struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration  
%type <id> struct_declarator_list struct_declarator
%type <id> static_assert_declaration enum_tag_name tag_name
%type <id> enum_specifier enum_specifier_rest enumerator_list enumerator
%type <id> parameter_type_list parameter_list parameter_declaration
%type <id> expression_statement expression_opt jump_statement statement labeled_statement compound_statement
%type <id> else_opt selection_statement iteration_statement
%type <id> block_item_list block_item
%type <id> declaration declaration_list_opt old_style_declaration_list 
%type <id> function_definition rest_function_definition
%type <id> rest_direct_declarator
%type <id> builtin_va_arg_expr
%type <for_stmt_type> for_stmt_type
%type <declarator_type> declarator direct_declarator 

%start translation_unit 

//gets rid of shift/reduce warning on if statement see pp. 233-235 Lex & Yacc 1992 Levine, Mason Brown O'Reilly 
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

primary_expression
	: IDENTIFIER
		{$$ = to_prolog_var($1);
		 free($1);
		}
	| constant
	| string
	| '(' {current_scope++; fsm_reset();} compound_statement ')'	//GCC statement-expression
		{pop_scope(&current_scope);
		 size_t const size = strlen("\nstmt_exp()") + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nstmt_exp(%s)", $3);
		 free($3);
		}
	| '(' expression ')'	
		{size_t const size = strlen("()") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "(%s)", $2);
		 free($2);
		}
	| generic_selection		{simple_str_lit_copy(&$$, "generic_selection");}
	| builtin_va_arg_expr	{$$ = $1;}
	;


builtin_va_arg_expr
    : BUILTIN_VA_ARG '(' assignment_expression ',' type_name ')'
	  {size_t const size = strlen("builtin_va_arg_expr(, )") + strlen($3) + strlen($5) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "builtin_va_arg_expr(%s, %s)", $3, $5);
	   free($3);
	   free($5);
	  }
    ;


constant
	: I_CONSTANT		/* includes character_constant */
	| F_CONSTANT	
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER			//Ordinary namespace Id declaration
	;

string
	: STRING_LITERAL	//"blah" or wide_string("blah") see lexer
	| FUNC_NAME			{simple_str_lit_copy(&$$, "thisFunctionName");}
	;

generic_selection	/* to do */
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	;

generic_assoc_list	/* to do */
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association	/* to do */
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;

postfix_expression
	: primary_expression 
	| postfix_expression '[' expression ']'
		{size_t const size = strlen("index(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "index(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	| postfix_expression '(' ')'
		{size_t const size = strlen("function_call(, [])") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "function_call(%s, [])", $1);
		 free($1);
		}
	| postfix_expression '(' argument_expression_list ')'	/* function call */
		{size_t const size = strlen("function_call(, [])") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "function_call(%s, [%s])", $1, $3);
		 free($1);
		 free($3);
		}
	| postfix_expression {in_member_namespace = 1;} '.' IDENTIFIER	//always reference an identifier in the member namespace
		{in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen($1) + strlen($4) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "select(%s, %s)", $1, $4);
		 free($1);
		 free($4);
		}
	| postfix_expression {in_member_namespace = 1;} PTR_OP IDENTIFIER
		{in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen($1) + strlen($4) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "struct_pointer(%s, %s)", $1, $4);
		 free($1);
		 free($4);
		}
	| postfix_expression INC_OP
		{size_t const size = strlen("postfix_inc_op()") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "postfix_inc_op(%s)", $1);
		 free($1);
		}
	| postfix_expression DEC_OP
		{size_t const size = strlen("postfix_dec_op()") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "postfix_dec_op(%s)", $1);
		 free($1);
		}
	| '(' type_name ')' '{' initializer_list comma_opt '}'
		{if (!strcmp($6, ",")) {
			size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen($2) + strlen($5) + 1;
		 	$$ = (char*)malloc(size);
		 	sprintf_safe($$, size, "trailing_comma_compound_literal(%s, %s)", $2, $5);
		 } else {
			size_t const size = strlen("compound_literal(, )") + strlen($2) + strlen($5) + 1;
		 	$$ = (char*)malloc(size);
		 	sprintf_safe($$, size, "compound_literal(%s, %s)", $2, $5);
		 }		 	
		 free($2);
		 free($5);
		 free($6);
		}
	;

comma_opt 
	: /* nothing */ {simple_str_lit_copy(&$$, "");}
	| ',' {simple_str_lit_copy(&$$, ",");}	
	;


argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s, %s", $1, $3);
		 free($1);
		 free($3);
		}
	;

unary_expression
	: postfix_expression
	| unary_inc_dec unary_expression
		{size_t const size = strlen("()") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s)", $1, $2);
		 free($1);
		 free($2);
		}
	| unary_operator cast_expression
		{size_t const size = strlen("()") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s)", $1, $2);
		 free($1);
		 free($2);
		}
	| SIZEOF unary_expression
		{size_t const size = strlen("size_of_exp()") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "size_of_exp(%s)", $2);
		 free($2);
		}
	| SIZEOF '(' type_name ')'
		{size_t const size = strlen("size_of_type()") + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "size_of_type(%s)", $3);
		 free($3);
		}
	| ALIGNOF '(' type_name ')'
		{size_t const size = strlen("align_of()") + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "align_of(%s)", $3);
		 free($3);
		}
	| ALIGNOF '(' expression ')'
		{size_t const size = strlen("align_of()") + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "align_of(%s)", $3);
		 free($3);
		}
	;

unary_inc_dec
	: INC_OP	{simple_str_lit_copy(&$$, "prefix_inc_op");}
	| DEC_OP	{simple_str_lit_copy(&$$, "prefix_dec_op");}
	;

unary_operator
	: '&'	{simple_str_lit_copy(&$$, "addr");}
	| '*'	{simple_str_lit_copy(&$$, "deref");}
	| '+'	{simple_str_lit_copy(&$$, "plus_op");}
	| '-'	{simple_str_lit_copy(&$$, "minus_op");}
	| '~'	{simple_str_lit_copy(&$$, "bw_one_comp");}
	| '!'	{simple_str_lit_copy(&$$, "not_op");}
	;

cast_expression
	: unary_expression
	| '('  type_name ')' cast_expression
		{size_t const size = strlen("cast(, )") + strlen($2) + strlen($4) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "cast(%s, %s)", $2, $4);
		 free($2);
		 free($4);
		}
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression multiplicative_expression_op cast_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s, %s)", $2, $1, $3);
		 free($1);
		 free($2);
		 free($3);
		}
	;

multiplicative_expression_op
	: '*'	{simple_str_lit_copy(&$$, "multiply_op");}
	| '/'	{simple_str_lit_copy(&$$, "div_op");}
	| '%'	{simple_str_lit_copy(&$$, "mod_op");}
	;

additive_expression
	: multiplicative_expression
	| additive_expression additive_expression_op multiplicative_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s, %s)", $2, $1, $3);
		 free($1);
		 free($2);
		 free($3);
		}
	;

additive_expression_op
	: '+'		{simple_str_lit_copy(&$$, "plus_op");}
	| '-'		{simple_str_lit_copy(&$$, "minus_op");}
	;

shift_expression
	: additive_expression
	| shift_expression shift_expression_op additive_expression
		{size_t const size = strlen("bitwise(, , )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "bitwise(%s, %s, %s)", $2, $1, $3);
		 free($1);
		 free($2);
		 free($3);
		}
	;

shift_expression_op
	: LEFT_OP		{simple_str_lit_copy(&$$, "left_shift");}
	| RIGHT_OP		{simple_str_lit_copy(&$$, "right_shift");}
	;

relational_expression
	: shift_expression
	| relational_expression relational_expression_operator shift_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s, %s)", $2, $1, $3);
		 free($1);
		 free($2);
		 free($3);
		}
	;

relational_expression_operator
	: '<' 		{simple_str_lit_copy(&$$, "less_op");}
	| '>'		{simple_str_lit_copy(&$$, "greater_op");}
	| LE_OP		{simple_str_lit_copy(&$$, "less_or_eq_op");}
	| GE_OP		{simple_str_lit_copy(&$$, "greater_or_eq_op");}
	;


equality_expression
	: relational_expression
	| equality_expression equality_expression_op relational_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s, %s)", $2, $1, $3);
		 free($1);
		 free($2);
		 free($3);
		}
	; 

equality_expression_op
	: EQ_OP		{simple_str_lit_copy(&$$, "equal_op");}
	| NE_OP		{simple_str_lit_copy(&$$, "not_equal_op");}
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
		{size_t const size = strlen("bitwise(bw_and, , )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "bitwise(bw_and, %s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
		{size_t const size = strlen("bitwise(bw_xor, , )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "bitwise(bw_xor, %s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
		{size_t const size = strlen("bitwise(bw_or, , )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "bitwise(bw_or, %s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
		{size_t const size = strlen("and_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "and_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
		{size_t const size = strlen("or_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "or_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression 
		{size_t const size = strlen("cond_exp(branch(, ), , )") + MAX_BRANCH_STR + strlen($1) + strlen($3) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, $1, $3, $5);
		 free($1);
		 free($3);
		 free($5);
		}
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
		{size_t const size = strlen("%s(%s, %s)") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s, %s)", $2, $1, $3);
		 free($1);
		 free($2);
		 free($3);
		}
	;

assignment_operator
	: '='			{simple_str_lit_copy(&$$, "assign");}
	| MUL_ASSIGN	{simple_str_lit_copy(&$$, "mul_assign");}
	| DIV_ASSIGN	{simple_str_lit_copy(&$$, "div_assign");}
	| MOD_ASSIGN	{simple_str_lit_copy(&$$, "mod_assign");}
	| ADD_ASSIGN	{simple_str_lit_copy(&$$, "add_assign");}
	| SUB_ASSIGN	{simple_str_lit_copy(&$$, "sub_assign");}
	| LEFT_ASSIGN	{simple_str_lit_copy(&$$, "left_assign");}
	| RIGHT_ASSIGN	{simple_str_lit_copy(&$$, "right_assign");}
	| AND_ASSIGN	{simple_str_lit_copy(&$$, "and_assign");}
	| XOR_ASSIGN	{simple_str_lit_copy(&$$, "xor_assign");}
	| OR_ASSIGN		{simple_str_lit_copy(&$$, "or_assign");}
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
		{size_t const size = strlen("comma_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "comma_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

declaration
	: type_declaration_specifiers {fsm_reset();} ';'
		{if (debugMode) printf("end of stand alone declaration specifier as a declaration on line %d\n", yylineno);
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("\ndeclaration()") + strlen(decl_specifier) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\ndeclaration(%s)", decl_specifier);
		 free(decl_specifier);
		}
	| type_declaration_specifiers init_declarator_list {fsm_reset();} ';' 
	  	{if (typedef_flag == 1) {	//we were processing typedef declarations [why not done above?]
	    	typedef_flag = 0; 
			if (debugMode) printf("Debug: typedef switched to 0\n");
	   	 }
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("\ndeclaration(, [])") + strlen(decl_specifier) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\ndeclaration(%s, [%s])", decl_specifier, $2);
		 free(decl_specifier);
		 free($2);
		}
	| static_assert_declaration		//always has an ending internal ';'
		{size_t const size = strlen("\n") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\n%s", $1);
		 free($1);
		 pop_decl_spec_stack();
		}
	;

//specify type. storage_class_specifier e.g. typedef, extern etc.
//cannot contain ids that are IDENTIFIER in the ordinary name space (they are struct, enum and union tags which are in_tag_declaration namespace, TYPEDEF_NAMES) and typeof(...) which is handled as a special case
type_declaration_specifiers
	: storage_class_specifier type_declaration_specifiers	//storage_class_specifier e.g. typedef, extern etc.
	| storage_class_specifier 
	| type_specifier type_declaration_specifiers				//type_specifier e.g. built-in type, TYPEDEF_NAME, struct, union
	| type_specifier
	| type_qualifier type_declaration_specifiers				//type_qualifier e.g. const, volatile
	| type_qualifier
	| function_specifier type_declaration_specifiers			//function_specifier e.g. inline
	| function_specifier
	| alignment_specifier type_declaration_specifiers		//alignment_specifier e.g. alignas
	| alignment_specifier
	;

init_declarator_list
	: init_declarator 
		{$$ = $1;}
	| init_declarator_list ',' init_declarator
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s, %s", $1, $3);
	     free($1);
	     free($3);
		}
	;

init_declarator
	: declarator '=' initializer	
		{size_t const size = strlen("initialised(, )") + strlen($1.full) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	   	 sprintf_safe($$, size, "initialised(%s, %s)", $1.full, $3);
	   	 free($1.full);
		 free($1.ptr_declarator);
	   	 free($3);
	  	}
	| declarator	// at the global level always add the empty initialiser: initializer([]) to trigger initialisation to 0, otherwise add 'no_initializer'
		{if (debugMode) printf("DEBUG: typedef_flag=%d, ptr_declarator=%s\n", typedef_flag, $1.ptr_declarator);
			if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_id(current_scope, $1.ptr_declarator, 1);	//the id as a TYPEDEF_NAME is added to the data structures keeping track of typedef_names (and ids shadowing)
	   	 }
		 free($1.ptr_declarator);
		 simple_str_copy(&$$, $1.full);
	  	}
	;

//only one of these per type
storage_class_specifier
	: TYPEDEF	/* the following typedef declarator identifier must be added to the list of typedefs so that it will get identified as TYPEDEF_NAME in lexer and not as an identifier*/
		{decl_spec_stack->decl_spec.storage.isTypeDef = true;
         typedef_flag = 1;
		 if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
	| EXTERN		{ decl_spec_stack->decl_spec.storage.isExtern = true; }
	| STATIC		{ decl_spec_stack->decl_spec.storage.isStatic = true; }
	| THREAD_LOCAL	{ decl_spec_stack->decl_spec.storage.isThreadLocal = true; }
	| AUTO			{ decl_spec_stack->decl_spec.storage.isAuto = true; }
	| REGISTER		{ decl_spec_stack->decl_spec.storage.isRegister = true; }
	;

//cannot contain ids that are IDENTIFIER in the ordinary name space (they are struct, enum and union tags which are in_tag_declaration namespace, TYPEDEF_NAMES) and typeof(...) which is handled as a special case
type_specifier
	: VOID					{ decl_spec_stack->decl_spec.atomic.isVoid = true;}
	| CHAR					{ decl_spec_stack->decl_spec.atomic.isChar = true;}
	| SHORT					{ decl_spec_stack->decl_spec.atomic.isShort= true;}
	| INT					{ decl_spec_stack->decl_spec.atomic.isInt = true;}
	| LONG					{ decl_spec_stack->decl_spec.atomic.longCount++;}
	| FLOAT					{ decl_spec_stack->decl_spec.atomic.isFloat = true;}
	| DOUBLE				{ decl_spec_stack->decl_spec.atomic.isDouble = true;}
	| SIGNED				{ decl_spec_stack->decl_spec.atomic.isSigned = true;}
	| UNSIGNED				{ decl_spec_stack->decl_spec.atomic.isUnSigned = true;}
	| BOOL					{ simple_str_lit_copy(&(decl_spec_stack->decl_spec.atomic.typeName), "bool");}
	| COMPLEX				{ simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "complex");}
	| IMAGINARY				{ simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "imaginary");}	
	| atomic_type_specifier	{ simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "atomic_type_specifier");}
	| struct_or_union_specifier { decl_spec_stack->decl_spec.non_atomic = $1;}
	| enum_specifier		{ decl_spec_stack->decl_spec.non_atomic = $1;}
	| typeof_specifier		{;}	//totally ignored for now
	| TYPEDEF_NAME			
		{decl_spec_stack->decl_spec.non_atomic = to_prolog_var($1);
		 free($1);
		}
	| INT128				{ simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "int128");}		//gcc extension: builtin type
	| FLOAT128				{ simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "float128");}	//gcc extension: builtin type
	| VA_LIST				{ simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "va_list");}		//gcc extension: builtin type
	;

typeof_specifier
    : TYPEOF rest_typeof_specifier
    | TYPEOF_UNQUAL rest_typeof_specifier
    ;
rest_typeof_specifier
	: '(' expression ')'
	| '(' type_name ')'
	;

struct_or_union_specifier
	: struct_or_union set_tag0 '}'		//anonymous EMPTY struct or union (GNU extension)
		{in_member_namespace = 0;
		 size_t const size = strlen("('anonymous', [])") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s('anonymous', [])", $1);
	     free($1);
	    }
	| struct_or_union set_tag0 struct_declaration_list '}'		//anonymous struct or union
		{in_member_namespace = 0;
		 size_t const size = strlen("('anonymous', [])") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s('anonymous', [%s])", $1, $3);
	     free($1);
	     free($3);
	    }
	| struct_or_union tag_name  '{' '}'	//Tag namespace Id declaration (EMPTY, GNU extension)
		{in_member_namespace = 0;
		 size_t const size = strlen("(, [])") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s(%s, [])", $1, $2);
	     free($1);
	     free($2);
	    }
	| struct_or_union tag_name '{' struct_declaration_list '}'	//Tag namespace Id declaration
		{in_member_namespace = 0;
		 size_t const size = strlen("(, [])") + strlen($1) + strlen($2) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s(%s, [%s])", $1, $2, $4);
	     free($1);
	     free($2);
		 free($4);
	    }
	| struct_or_union tag_name	//forward declaration Tag namespace Id declaration or as part of a variable or member declaration
		{fsm_from_none_to_spec();
		 in_member_namespace = 0;
		 size_t const size = strlen("%s(%s)") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s(%s)", $1, $2);
	     free($1);
	     free($2);
	    }
	;

set_tag0 :
	'{' 
		{in_tag_declaration = 0;
		 in_member_namespace = 1;
		 fsm_reset();
		}
	;	

tag_name :
	IDENTIFIER
		{in_tag_declaration = 0;
		 in_member_namespace = 1;
		 fsm_reset();
		 $$ = to_prolog_var($1);
		 free($1);
		}
	;	

struct_or_union
	: STRUCT	
		{simple_str_lit_copy(&$$, "struct");
		 in_tag_declaration = 1;
		}
	| UNION		
		{simple_str_lit_copy(&$$, "union");
		 in_tag_declaration = 1;
		}
	;

struct_declaration_list
	: {push_decl_spec_stack();} struct_declaration {$$ = $2;}
	| struct_declaration_list {push_decl_spec_stack();} struct_declaration
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $3);
	     free($1);
	     free($3);
	    }
	;

// in_member_namespace cannot be set to 1 in the grammar: same problem with shadow identifiers, a token needs to be read ahead 
struct_declaration
	: specifier_qualifier_list ';'	//for inner "Anonymous Members in Structs" C11
		{fsm_reset();
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("anonymous_member()") + strlen(decl_specifier) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "anonymous_member(%s)", decl_specifier);
	   	 free(decl_specifier);
        }
	| specifier_qualifier_list {in_member_namespace = 1;} struct_declarator_list {fsm_reset();} ';'
		{char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("struct_decl(, [])") + strlen(decl_specifier) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "struct_decl(%s, [%s])", decl_specifier, $3);
	   	 free(decl_specifier);
		 free($3);
        }
	| static_assert_declaration		//somehow the ; is in that rule
		{fsm_reset();
		 $$ = $1;
		 pop_decl_spec_stack(); 
		}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator 
		{in_member_namespace = 1;
		 $$= $1;
		}
	| struct_declarator_list ',' struct_declarator
		{in_member_namespace = 1; 
		 size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "%s, %s", $1, $3);
	   	 free($1);
	     free($3);
        }
	;

struct_declarator		//added to avoid reduce-reduce conflict
	: ':' {in_member_namespace = 0;} constant_expression		//bit field
		{in_member_namespace = 1;
		 size_t const size = strlen("anonymous_bit_field()") + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "anonymous_bit_field(%s)", $3);
	   	 free($3);
        } 
	| declarator ':' {in_member_namespace = 0;} constant_expression 	//bit field
		{in_member_namespace = 1;
		 size_t const size = strlen("bit_field(, )") + strlen($1.full) + strlen($4) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "bit_field(%s, %s)", $1.full, $4);
	   	 free($1.full);
		 free($1.ptr_declarator);
	     free($4);
        }
	| declarator
		{$$ = strdup($1.full);
		 free($1.full);
		 free($1.ptr_declarator);
		}
	;

enum_specifier
	: ENUM '{' enumerator_list comma_opt '}'
		{if (!strcmp($4, ",")) {
			size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen($3) + 1;
       	 	$$ = (char*)malloc(size);
         	sprintf_safe($$, size, "trailing_comma_anonymous_enum([%s])", $3);
		 } else {
			size_t const size = strlen("anonymous_enum([])") + strlen($3) + 1;
       	 	$$ = (char*)malloc(size);
         	sprintf_safe($$, size, "anonymous_enum([%s])", $3);
		 }
	     free($3);
		 free($4);
        }
	| ENUM {in_tag_declaration = 1;} enum_tag_name enum_specifier_rest 	//Tag namespace Id declaration ; 
		{size_t const size = strlen("enum(, [])") + strlen($3) + strlen($4) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "enum(%s, [%s])", $3, $4);
	     free($3);
		 free($4);
        }
	;

enum_tag_name :
	IDENTIFIER
		{in_tag_declaration = 0;
		 $$ = to_prolog_var($1);
		 free($1);
		}
	;	

//new rule to avoid reduce-reduce conflict when introducing in_tag_declaration in enum_specifier rule just above
enum_specifier_rest
	: /* empty */	
		{simple_str_lit_copy(&$$, "forward_enum");}
	| '{' enumerator_list '}'
		{$$ = $2;}
	| '{' enumerator_list ',' '}'
		{size_t const size = strlen("trailing_comma_enum([])") + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "trailing_comma_enum([%s])", $2);
	     free($2);
		}
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "%s, %s", $1, $3);
	   	 free($1);
	     free($3);
        }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression
		{size_t const size = strlen("init_enum(, )") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "init_enum(%s, %s)", $1, $3);
	   	 free($1);
	     free($3);
        }
	| enumeration_constant
	;

atomic_type_specifier		// new in C11 for atomic operation: used in concurrency
	: ATOMIC_SPECIFIER type_name ')'	//the opening parenthesis '(' is matched by the lexer
	;

type_qualifier
	: CONST		{decl_spec_stack->decl_spec.qualifier.isConst = true;}
	| RESTRICT	{decl_spec_stack->decl_spec.qualifier.isRestrict = true;}	//C99, pointer qualifier indicate only reference to object, allows for compiler optimisation
	| VOLATILE	{decl_spec_stack->decl_spec.qualifier.isVolatile = true;}
	| ATOMIC	{decl_spec_stack->decl_spec.qualifier.isAtomic= true;}
	;

function_specifier
	: INLINE	{decl_spec_stack->decl_spec.function.isInLine = true;}
	| NORETURN	{decl_spec_stack->decl_spec.function.isNoReturn = true;}
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
		{size_t const size = strlen("alignas()") + strlen($3) + 1;
	     decl_spec_stack->decl_spec.alignAs = (char*)malloc(size);
		 sprintf_safe(decl_spec_stack->decl_spec.alignAs, size, "alignas(%s)", $3);
		 free($3);
		}
	| ALIGNAS '(' constant_expression ')'
		{size_t const size = strlen("alignas()") + strlen($3) + 1;
	     decl_spec_stack->decl_spec.alignAs = (char*)malloc(size);
		 sprintf_safe(decl_spec_stack->decl_spec.alignAs, size, "alignas(%s)", $3);
		 free($3);
		}
	;

declarator
	: pointer direct_declarator
	  {size_t const size = strlen("ptr_decl(, )") + strlen($1) + strlen($2.full) + 1;
       $$.full = (char*)malloc(size);
       sprintf_safe($$.full, size, "ptr_decl(%s, %s)", $1, $2.full);
	   $$.ptr_declarator = $2.ptr_declarator;
	   free($1);
	   free($2.full);
      }
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER 		//Ordinary namespace id declaration unless within a struct declaration in which case it is a Member namespace id
		{if (in_member_namespace) {	//this is a member (from a struct or union) no need to transform into a Prolog var
			if (debugMode) printf("direct_declarator: in member namespace: %s on line %d\n", $1, yylineno);
			size_t const size = strlen($1) + 1;
			$$.full = (char*)malloc(size);
		 	strcpy_safe($$.full, size, $1);
			$$.ptr_declarator = (char*)malloc(size);
		 	strcpy_safe($$.ptr_declarator, size, $1);
		 } else {	//only place where a new IDENTIFIER (apart from ENUM constants) can be declared: added in the table of symbols in the lexer (it has to be done there) if it shadows a TYPEDEF_NAME
			char Prolog_var_name[MAX_ID_LENGTH+5];	//todo should use to_prolog_var($1);
			if (islower($1[0])) {
				Prolog_var_name[0] = toupper($1[0]);
				strcpy_safe(&Prolog_var_name[1], MAX_ID_LENGTH-1, &$1[1]);
			} else {
				strcpy_safe(Prolog_var_name, MAX_ID_LENGTH, "UC_");
				strcat_safe(Prolog_var_name, MAX_ID_LENGTH, $1);
			}
			size_t const size = strlen(Prolog_var_name) + 1;
		 	$$.full = (char*)malloc(size);
		 	strcpy_safe($$.full, size, Prolog_var_name);
		 	$$.ptr_declarator = strdup($$.full);
		 	free($1);
		 }
		} 
	| '(' declarator ')'			//function pointer e.g. in "int (*func_ptr)(int, int);" declarator is "*func_ptr"
		//many need in_member_namespace = 0; in case we are within a union or struct to indicate that we just processed the member and the rest my involve typedefs see diary 12/11/24
		{$$ = $2;
		}
	| direct_declarator {if (in_member_namespace) in_member_namespace=0; } rest_direct_declarator
		{size_t const size = strlen("array_decl(, )") + strlen($1.full) + strlen($3) + 1;
         $$.full = (char*)malloc(size);
         sprintf_safe($$.full, size, "array_decl(%s, %s)", $1.full, $3);
		 free($1.full);
		 free($3);
		 $$.ptr_declarator = $1.ptr_declarator;
		}
	| direct_declarator {if (in_member_namespace) in_member_namespace=0; current_scope++; } '(' rest_function_definition ')'
		{pop_scope(&current_scope);
		 size_t const size = strlen("function(, )") + strlen($1.full) + strlen($4) + 1;
	     $$.full = (char*)malloc(size);
	     sprintf_safe($$.full, size, "function(%s, %s)", $1.full, $4);
		 current_function = strdup($1.full);
	     free($1.full);
		 $$.ptr_declarator = $1.ptr_declarator;
		 free($4);
		}
	;

rest_direct_declarator
	: '[' ']'
		{simple_str_lit_copy(&$$, "int(0)"); 
		}
	| '[' assignment_expression ']'
		{$$ = $2;
		}
	| '[' '*' ']'
		{simple_str_lit_copy(&$$, "D3"); 
		}
	| '[' STATIC type_qualifier_list assignment_expression ']' 
		{simple_str_lit_copy(&$$, "D4");
		}
	| '[' STATIC assignment_expression ']'
		{simple_str_lit_copy(&$$, "D5");
		}
	| '[' type_qualifier_list '*' ']'
		{simple_str_lit_copy(&$$, "D6");
		}
	| '[' type_qualifier_list STATIC assignment_expression ']'
		{simple_str_lit_copy(&$$, "D7");
		}
	| '[' type_qualifier_list assignment_expression ']'
		{simple_str_lit_copy(&$$, "D8");
		}
	| '[' type_qualifier_list ']'
		{simple_str_lit_copy(&$$, "D9");
		}
	;

/*** Start Function Parameters Section ***/
rest_function_definition
	: /* nothing */ {simple_str_lit_copy(&$$, "[]");}
	| parameter_type_list 
	| old_style_parameter_list {simple_str_lit_copy(&$$, "dummy_identifier_list");}
	;

old_style_parameter_list	//for old-style function declaration for the parameters see p. 226 K&R : just identifiers
	: IDENTIFIER			//Ordinary Id declaration
	| old_style_parameter_list ',' IDENTIFIER	//Ordinary Id declaration
	;	

parameter_type_list
	: parameter_list ',' ELLIPSIS
		{size_t const size = strlen("variable_length_args([])") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "variable_length_args([%s])", $1);
	     free($1);
		}
	| parameter_list
		{size_t const size = strlen("[]") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "[%s]", $1);
	     free($1);
		}
	;

parameter_list
	: {push_decl_spec_stack();} parameter_declaration 
	  	{$$ = $2;
		}
	| parameter_list ',' {push_decl_spec_stack();} parameter_declaration
		{size_t const size = strlen(", ") + strlen($1) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $4);
	     free($1);
		 free($4);
		}
	;

parameter_declaration
	: type_declaration_specifiers declarator
		{char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("param(, )") + strlen(decl_specifier) + strlen($2.full) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "param(%s, %s)", decl_specifier, $2.full);
	     free(decl_specifier);
		 free($2.full); 
		 free($2.ptr_declarator);
		}
	| type_declaration_specifiers abstract_declarator
		{char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("unnamed_param(, dummy_abstract_declarator)") + strlen(decl_specifier) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "unnamed_param(%s, dummy_abstract_declarator)", decl_specifier);
	     free(decl_specifier);
		 //free($2);
		}
	| type_declaration_specifiers
		{char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("unnamed_param(, [])") + strlen(decl_specifier) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "unnamed_param(%s, [])", decl_specifier);
	     free(decl_specifier);
		}
	;
/*** End Function Parameters section ***/

pointer
	: pointer_star pointer
		{size_t const size = strlen("pointer(, )") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "pointer(%s, %s)", $1, $2);
		 free($1);
		 free($2);
		}
	| pointer_star {$$ = $1;}
	;

pointer_star
	: '*' {push_decl_spec_stack();} type_qualifier_list
		{char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("pointer()") + strlen(decl_specifier) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "pointer(%s)", decl_specifier);
	     free(decl_specifier);
		}
	| '*'
		{simple_str_lit_copy(&$$, "pointer");}
	;	

type_qualifier_list		//CONST, RESTRICT, VOLATILE etc.
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

type_name
	: {push_decl_spec_stack();} specifier_qualifier_list abstract_declarator_opt	
		{if (!strcmp($3, "")) {
			char *decl_specifier = create_declaration_specifiers();
			size_t const size = strlen("") + strlen(decl_specifier) + 1;
	     	$$ = (char*)malloc(size);
	     	sprintf_safe($$, size, "%s", decl_specifier);
			free(decl_specifier);
		 } else {
			pop_decl_spec_stack();
		 	simple_str_lit_copy(&$$, "type_abstract_declarator_dummy1");	//document please: when does this occur?
		 }
		 free($3);
		}
	;

abstract_declarator_opt
	: /* nothing */ {simple_str_lit_copy(&$$, "");}
	| abstract_declarator  {simple_str_lit_copy(&$$, "type_abstract_declarator_dummy1");}
	;

abstract_declarator 
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' '*' ']'
	| '[' STATIC type_qualifier_list assignment_expression ']'
	| '[' STATIC assignment_expression ']'
	| '[' type_qualifier_list STATIC assignment_expression ']'
	| '[' type_qualifier_list assignment_expression ']'
	| '[' type_qualifier_list ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' '*' ']'
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: '{' initializer_list '}'
		{size_t const size = strlen("initializer([])") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "initializer([%s])", $2);
	     free($2);
		}
	| '{' initializer_list ',' '}'	//trailing commas are just syntactic sugar: they can always be removed
		{size_t const size = strlen("initializer([])") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "initializer([%s])", $2);
	     free($2);
		}
	| assignment_expression
	| '{' '}'
		{simple_str_lit_copy(&$$, "initializer([])");}	//empty initialisers are allowed in GCC/Clang
	;

initializer_list
	: designation initializer
		{size_t const size = strlen("init(, )") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "init(%s, %s)", $1, $2);
	     free($1);
		 free($2);
		}
	| initializer
	| initializer_list ',' designation initializer
		{size_t const size = strlen(", init(, )") + strlen($1) + strlen($3) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, init(%s, %s)", $1, $3, $4);
	     free($1);
		 free($3);
		 free($4);
		}
	| initializer_list ',' initializer
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $3);
	     free($1);
		 free($3);
		}
	;

designation	//C99 this is for named-initializer as opposed to positional-initializer
	: designator_list '='
		{size_t const size = strlen("designation([])") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "designation([%s])", $1);
	     free($1);
		}
	;

designator_list
	: designator
	| designator_list designator
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $2);
	     free($1);
		 free($2);
		}
	;

designator
	: '[' constant_expression ']'		//for named array index
		{size_t const size = strlen("index()") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "index(%s)", $2);
		 free($2);
		}
	| {in_member_namespace = 1;}'.' IDENTIFIER					//for named struct field
		{in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "select(%s)", $3);
		 free($3);
		}
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' {fsm_reset();} ';'
		{size_t const size = strlen("static_assert(, )") + strlen($3) + strlen($5) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "static_assert(%s, %s)", $3, $5);
		 free($3);
		 free($5);
		}
	;

statement
	: labeled_statement
	| {current_scope++; fsm_reset();} 
	  compound_statement	
	  {pop_scope(&current_scope);
	   $$ = $2;
	  }
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement 	//Label Id declaration
	  {size_t const size = strlen("label_stmt(, )") + strlen($1) + strlen($3) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "label_stmt(%s, %s)", $1, $3);
	   free($1);
	   free($3);
	  }
	  /*
	| //fake rule in case a label is wrongly identified as a TYPEDEF_NAME
	  TYPEDEF_NAME ':' statement 	//Label Id declaration
	  {size_t const size = strlen("label_stmt(, )") + strlen($1) + strlen($3) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "label_stmt(%s, %s)", $1, $3);
	   free($1);
	   free($3);
	  }
	  */
	| CASE constant_expression ':' statement
	  {size_t const size = strlen("case_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen($2) + strlen($4) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "case_stmt(branch(%d, %s), %s)", branch_nb++, $2, $4);
	   free($2);
	   free($4);
	  }
	| DEFAULT ':' statement
	  {size_t const size = strlen("default_stmt(branch(), )") + MAX_BRANCH_STR + strlen($3) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "default_stmt(branch(%d), %s)", branch_nb++, $3);
	   free($3);
	  }
	;

compound_statement	//aka a 'block'
	: '{' '}'	{simple_str_lit_copy(&$$, "\ncmp_stmts([])");}
	| '{' block_item_list '}' //too late to call fsm_reset(); after '{' : the next token has already been read: must call fsm_reset(); before every call to compound_statement
	  {size_t const size = strlen("\ncmp_stmts([\n])") + strlen($2) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "\ncmp_stmts([%s\n])", $2);
	   free($2);
	  }
	;

block_item_list
	: {push_decl_spec_stack();} block_item {fsm_reset(); $$ = $2;}
	| block_item_list {push_decl_spec_stack();} block_item
	  {fsm_reset();
	   size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "%s, %s", $1, $3);
	   free($1);
	   free($3);
	  }
	;

block_item
	: declaration
	| statement {pop_decl_spec_stack();}
	;

expression_statement
	: ';'	{simple_str_lit_copy(&$$, "stmt([])");}	//todo replace with int(1) ?
	| expression ';'
		{size_t const size = strlen("\nstmt()") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nstmt(%s)", $1);
		 free($1);
		}
	;

selection_statement
	: IF '(' expression ')' statement else_opt 
		{size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen($3) + strlen($5) + strlen($6) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, $3, $5, $6);
		 free($3);
		 free($5);
		 free($6);
		} 
	| SWITCH '(' expression ')' statement
		{size_t const size = strlen("\nswitch_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen($3) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nswitch_stmt(branch(%d, %s), %s)", branch_nb++, $3, $5); 
		 free($3);
		 free($5);
		} 
	;

else_opt
	: /* empty */		%prec LOWER_THAN_ELSE 	{simple_str_lit_copy(&$$, "");}
	| ELSE statement
		{
          /* if ELSE is followed by a single if_stmt(...) produced earlier, convert it to an else_if_stmt fragment
             so the outer if will attach ", \nelse_if_stmt(...)" rather than ", \nif_stmt(...)" */
          if ($2 && strncmp($2, "\nif_stmt(branch(", 16) == 0) {
              /* build ", \nelse_if_stmt(...)" from the existing if_stmt string by replacing "if_stmt" -> "else_if_stmt" */
              const char *orig = $2 + 1; /* skip leading newline */
              const char *needle = "if_stmt";
              size_t orig_len = strlen(orig);
              size_t add = strlen("else_if_stmt") - strlen(needle); /* typically +5 */
              size_t const size = strlen(", \n") + orig_len + add + 1;
              char *else_part = (char*)malloc(size);
              /* prefix */
              sprintf_safe(else_part, size, ", \n");
              /* replace prefix "if_stmt" with "else_if_stmt" if present at start */
              if (strncmp(orig, needle, strlen(needle)) == 0) {
                  strcat_safe(else_part, size, "else_if_stmt");
                  strcat_safe(else_part, size, orig + strlen(needle));
              } else {
                  /* fallback: just append whole original */
                  strcat_safe(else_part, size, orig);
              }
              $$ = else_part;
          } else { // normal else: return ", <statement>"
              size_t const size = strlen(", ") + strlen($2) + 1;
              $$ = (char*)malloc(size);
              sprintf_safe($$, size, ", %s", $2);
          }
          free($2);
        }
	;

iteration_statement
	: WHILE '(' expression ')' statement 
		{size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen($3) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, $3, $5);
		 free($3);
		 free($5);
		} 
	| DO statement WHILE '(' expression ')' ';'
		{size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen($2) + MAX_BRANCH_STR + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\ndo_while_stmt(%s, branch(%d, %s))", $2, branch_nb++, $5);
		 free($2);
		 free($5);
		} 
	| FOR '(' for_stmt_type ')' statement	//replaced by an equivalent, a little ugly, while statement
		{size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen($3.init) + MAX_BRANCH_STR + strlen($3.cond) + strlen($5) + strlen($3.update) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", $3.init, branch_nb++, $3.cond, $5, $3.update);
		 free($3.init);
		 free($3.cond);
		 free($3.update);
		 free($5);
		} 
	;
//changed the original grammar by replacing the middle expression_statement (the condition) with expression_opt ';'
for_stmt_type
	: expression_statement expression_opt ';' expression_opt 
	  {$$ = (struct for_stmt){.init = $1, .cond = $2, .update = $4};}	//a compound literal
	| {push_decl_spec_stack();} declaration expression_opt ';' expression_opt
	  {$$ = (struct for_stmt){.init = $2, .cond = $3, .update = $5};}	//a compound literal
	;

expression_opt
	: /* empty */	{simple_str_lit_copy(&$$, "int(1)");}	//i.e. true
	| expression

jump_statement
	: GOTO IDENTIFIER ';'	//in_label_namespace is already switched on within lexer after GOTO
	  {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen($2) + strlen(current_function) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "\ngoto_stmt(%s, %s)\n", $2, current_function);
	   free($2);
	  }
	| CONTINUE ';'	{simple_str_lit_copy(&$$, "\ncontinue_stmt\n");}
	| BREAK ';'		{simple_str_lit_copy(&$$, "\nbreak_stmt\n");}
	| RETURN ';'  	{simple_str_lit_copy(&$$, "\nreturn_stmt\n");}
	| RETURN expression ';'
	  {size_t const size = strlen("\nreturn_stmt()\n") + strlen($2) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "\nreturn_stmt(%s)\n", $2);
	   free($2);
	  }
	;

//top level rule
translation_unit 			//printed out
	: {push_decl_spec_stack();} external_declaration
	| translation_unit {fprintf(pl_file, ", \n"); push_decl_spec_stack();} external_declaration
	;

external_declaration		//printed out
	: function_definition opt_semi_colon	//gcc allow an option semi-colon after a function definition
		{fprintf(pl_file, "%s", $1);
		 free($1);
		}
	|  declaration
		{
		 fprintf(pl_file, "%s", $1); 
		 free($1);
		}
	;
function_definition
	: type_declaration_specifiers declarator declaration_list_opt {fsm_reset();} compound_statement
		{char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("function(, , [], )") + strlen(decl_specifier) + strlen($2.full) + strlen($3) + strlen($5) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "function(%s, %s, [%s], %s)", decl_specifier, $2.full, $3, $5);
		 if (debugMode) printf("function parsed\n");
	     free(decl_specifier);
		 free($2.full);
		 free($2.ptr_declarator);
		 free($3);
		 free($5);
		}
	;
opt_semi_colon
	: /* empty */
	| ';'
	;
declaration_list_opt
	: /* empty */		{simple_str_lit_copy(&$$, "");}
	| old_style_declaration_list	//for old-style function declaration for the parameters see p. 226 K&R
	;

old_style_declaration_list
	: {push_decl_spec_stack();} declaration {$$ = $2;}
	| old_style_declaration_list {push_decl_spec_stack();} declaration
	  	{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $3);
	     free($1);
		 free($3);
		}
	;

%%
#include "lex.yy.c"

int main(int argc, char *argv[]) {
	char *C_file_path = NULL;				//directory where the C and .i files are
	char *filename_no_ext = NULL;	

	C_file_path = strdup(".");				//default path for input file is current directory, overwrite with -p on command line

	for (int i = 1; i <= argc - 1; i++) {	//processing command line arguments
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'h':
				printf("Usage: .\\sikraken_parser [OPTION]... FILE_NO_EXT\nParses the .i file of a C file pre-processsed by GCC to Prolog terms.\n\n-h\t Display help information\n-m32|-m64\t Specify the data model, -m32 is the default\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\sikraken_parser -p\".\" get_sign \n\t.\\sikraken_parser get_sign \n\t.\\sikraken_parser -m64 -p\"C:/Parser/\" sign \n");
				my_exit(SUCCESS);
			case 'p':	//path to the .i pre-processed input C file
				if (access_safe(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					my_exit(COMMAND_LINE_FAILURE);
				}
				free(C_file_path);
				C_file_path = strdup(&argv[i][2]);
				break;
			case 'd':
				debugMode = 1;	//we are in debug mode (false is default): will affect output of warnings amongst other things
				break;
			case 'm':
				if (argv[i][2] == '6' && argv[i][3] == '4') {
					dataModel = 64;		//anything else is assumed default i.e. 32 bit
					TARGET_LONG_MAX = 9223372036854775807LL;	//i.e. LONG_MAX for 64 bits target (using LL in case compiler is running on a 32bit machine)
				}
				break;
			default:
				fprintf(stderr, "Sikraken parser: Unsupported flag '-%s', ignoring.\n", argv[i]);
			}
		}
		else {	//must be the filename to analyse
			filename_no_ext = strdup(argv[i]);
		}
	}
	
	size_t i_path_len = strlen(C_file_path) + strlen(filename_no_ext) + 4; // "/.i\0"
	i_file_uri = malloc(i_path_len);
	snprintf(i_file_uri, i_path_len, "%s/%s.i", C_file_path, filename_no_ext);
	if (fopen_safe(&i_file, i_file_uri, "r") != 0) {
		fprintf(stderr, ".i file could not be opened for reading at: %s\n", i_file_uri);
		my_exit(COMMAND_LINE_FAILURE);
	} else fprintf(stdout, "Sikraken parser %s: parsing the file %s using %i bits data model.\n", (debugMode) ? "in debug mode" : "", i_file_uri, dataModel); 
	yyin = i_file;	//set the input to the parser

	size_t pl_path_len = strlen(C_file_path) + strlen(filename_no_ext) + 5; // "/.pl\0"
	pl_file_uri = malloc(pl_path_len);
	snprintf(pl_file_uri, pl_path_len, "%s/%s.pl", C_file_path, filename_no_ext);
	if (fopen_safe(&pl_file, pl_file_uri, "w") != 0) {
		fprintf(stderr, ".pl file could not be created for writing at: %s\n", pl_file_uri);
		my_exit(COMMAND_LINE_FAILURE);
	}
	fflush(stdout);							//to ensure all previous information messages are printed out of buffer before the parsing starts and potentially generate unbuffered error messages

	/* initialisations */
	char *predefined_typedef = strdup("__gnuc_va_list");
	add_typedef_id(current_scope, predefined_typedef, 1);		//predefined typedef in GCC

	/* call the parser */
	fprintf(pl_file, "prolog_c([");			//opening top-level predicate
	if (yyparse() != 0) {					//the parser is called here
		fprintf(stderr, "Parsing failed.\n");
		my_exit(PARSING_ERROR);
	}	
	fprintf(pl_file, "\n]).");
	fclose(pl_file);
	pl_file = NULL;
	fclose(i_file);
	i_file = NULL;
	my_exit(SUCCESS);
}

//handles parsing errors: since the C input file is the output of a C pre-processor it will only be called if
//  the syntax rules are wrong due to GCC extensions 
//  or if the .i file has been badly generated manually: i.e. during development
/*void yyerror(const char* s) {
	extern char* yytext;  	// Points to the text of the current token
    extern int yyleng;    	// Length of the current token
    fflush(stdout);			//to ensure all previous information messages are printed out of buffer before the error message
    fprintf(stderr, "Sikraken Parsing error: %s, at line %d, near token '%s' (token code: %d)\n", s, yylineno, yytext, yychar);
	fprintf(stderr, "Unexpected token: %s\n", token_name(yychar)); 
}*/

/* Non-reentrant yyerror: uses global yylloc and yylineno */
void yyerror(const char* s) {
    extern char* yytext; /* current token lexeme (from Flex) */
    extern int yyleng;   /* current token length (from Flex) */
    /* yylloc is defined by Bison when you use %locations in non-reentrant mode */

    fflush(stdout);

    /* yychar may be YYEMPTY (-2) when there is no current lookahead */
    int tok = yychar;
    const char *tokname = token_name(tok); /* you already have token_name(int) */

    /* Print precise location using yylloc (line:column span) */
    fprintf(stderr,
            "Sikraken Parsing error: %s at %d:%d–%d:%d\n",
            s,
            yylloc.first_line, yylloc.first_column,
            yylloc.last_line,  yylloc.last_column);

    /* Nice “near token …” line; fall back if no yytext */
    if (yytext && yyleng > 0) {
        fprintf(stderr, "Near token: '%.*s'\n", yyleng, yytext);
    } else {
        fprintf(stderr, "Near token: <none>\n");
    }

    if (tok >= 0) {
        fprintf(stderr, "Token code: %d (%s)\n", tok, tokname ? tokname : "unknown");
    } else {
        fprintf(stderr, "Token: <no lookahead>\n");
    }
}


const char *token_name(int token) {
    if (token >= 0 && token <= 255) {  // a char token
        static char buf[2] = {0};
        buf[0] = (char)token;
        return buf;
    } else if (token >= 256 && token < 256 + YYNTOKENS) {// Token values start at 256 (after single chars and EOF/error)
        return yytname[token - 255];
    } else {
        return "unknown token";
    }
}

void my_exit(int exit_code) {			//exits and performs some tidying up if not in debug mode
  if (!debugMode) {
    if (i_file) fclose(i_file);
    if (pl_file) fclose(pl_file);
  }
  if (exit_code == SUCCESS) fprintf(stderr, "Sikraken parsing SUCCESS, wrote %s\n", pl_file_uri);
  exit(exit_code);
}
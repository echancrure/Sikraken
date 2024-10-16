/****************************************************************************************************/
/* C11 grammar file from https://www.quut.com/c/ANSI-C-grammar-y.html								*/
/* Bison documentation: https://www.gnu.org/software/bison/manual/html_node/index.html              */
/****************************************************************************************************/

%define parse.error verbose

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
	#define sprintf_safe(buffer, size, format, ...) snprintf(buffer, size, format, __VA_ARGS__)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.c"
#include "handle_typedefs.c"

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;

#define MAX_ID_LENGTH 255
#define MAX_PATH 256
#define MAX_BRANCH_STR 9		//maximum length of the string encoding the number of branches (max is "999999999" i.e. 1 billion - 1)

int debugMode = 0;				//flag to indicate if we are in debug mode set by -d command line switch
int dataModel = 32;				//flag to indicate data model used in the C code under analysis; set by -m32 or -m64 on the command line; default is 32
long int TARGET_LONG_MAX = 2147483647L; //the default LONG_MAX for the code under test if dataModel = 32
FILE* pl_file;					//the file of containing the Prolog predicated after parsing the target C file
char i_file_uri[MAX_PATH];
FILE *i_file;
char pl_file_uri[MAX_PATH];		//the full path to the Pl_file
int branch_nb = 1;				//unique id for branches created
//start: ugly, breaking parsing spirit, flags and temporary variables
int typedef_flag = 0; 			//indicates that we are within a typedef declaration
int in_member_decl_flag = 0;	//indicates that we are parsing struct or union declarations and that the ids are part of the members namespace


void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);

%}

%union {
	char* id;
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
 


%type <id> storage_class_specifier declarator init_declarator initializer direct_declarator pointer type_qualifier type_qualifier_list init_declarator_list declaration_specifiers
%type <id> type_specifier
%type <id> function_specifier expression constant_expression assignment_expression conditional_expression assignment_operator
%type <id> logical_or_expression logical_and_expression inclusive_or_expression exclusive_or_expression and_expression equality_expression equality_expression_op relational_expression relational_expression_operator shift_expression shift_expression_op additive_expression additive_expression_op
%type <id> multiplicative_expression multiplicative_expression_op cast_expression unary_expression unary_operator unary_inc_dec postfix_expression 
%type <id> type_name argument_expression_list primary_expression constant string enumeration_constant
%type <id> initializer_list designation designator_list designator
%type <id> struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator
%type <id> static_assert_declaration
%type <id> enum_specifier enumerator_list enumerator
%type <id> parameter_type_list parameter_list parameter_declaration
%type <id> expression_statement expression_opt for_stmt_type jump_statement statement labeled_statement compound_statement
%type <id> else_opt selection_statement iteration_statement
%type <id> block_item_list block_item
%type <id> declaration declaration_list_opt declaration_list
%type <id> function_definition

%start translation_unit 

//gets rid of shift/reduce warning on if statement see pp. 233-235 Lex & Yacc 1992 Levine, Mason Brown O'Reilly 
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

primary_expression
	: IDENTIFIER	
		{char Prolog_var_name[MAX_ID_LENGTH+5];
		 if (islower($1[0])) {
			Prolog_var_name[0] = toupper($1[0]);
			strcpy_safe(&Prolog_var_name[1], MAX_ID_LENGTH-1, &$1[1]);
		 } else {
			strcpy_safe(Prolog_var_name, MAX_ID_LENGTH, "UC_");
			strcat_safe(Prolog_var_name, MAX_ID_LENGTH, $1);
		 }
		 size_t const size = strlen(Prolog_var_name) + 1;
		 $$ = (char*)malloc(size);
		 strcpy_safe($$, size, Prolog_var_name);
		 free($1);
		}
	| constant
	| string
	| '(' compound_statement ')'	//GCC statement-expression
		{size_t const size = strlen("\nstmt_exp()") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nstmt_exp(%s)", $2);
		 free($2);
		}			
	| '(' expression ')'	
		{size_t const size = strlen("()") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "(%s)", $2);
		 free($2);
		}
	| generic_selection		{simple_str_lit_copy(&$$, "generic_selection");}
	;

constant
	: I_CONSTANT		/* includes character_constant */
	| F_CONSTANT	
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER		//Ordinary namespace Id declaration
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
	| postfix_expression '.' IDENTIFIER
		{size_t const size = strlen("select(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "select(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	| postfix_expression PTR_OP IDENTIFIER
		{size_t const size = strlen("struct_pointer(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "struct_pointer(%s, %s)", $1, $3);
		 free($1);
		 free($3);
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
	| '(' type_name ')' '{' initializer_list '}'
		{size_t const size = strlen("compound_literal(, )") + strlen($2) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "compound_literal(%s, %s)", $2, $5);
		 free($2);
		 free($5);
		}
	| '(' type_name ')' '{' initializer_list ',' '}'
		{size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen($2) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "trailing_comma_compound_literal(%s, %s)", $2, $5);
		 free($2);
		 free($5);
		}
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
	| '~'	{simple_str_lit_copy(&$$, "one_comp_op");}
	| '!'	{simple_str_lit_copy(&$$, "not_op");}
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
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
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s(%s, %s)", $2, $1, $3);
		 free($1);
		 free($2);
		 free($3);
		}
	;

shift_expression_op
	: LEFT_OP		{simple_str_lit_copy(&$$, "left_shift_op");}
	| RIGHT_OP		{simple_str_lit_copy(&$$, "right_shift_op");}
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
		{size_t const size = strlen("bitw_and(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "bitw_and(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
		{size_t const size = strlen("bitw_excl_or_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "bitw_excl_or_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
		{size_t const size = strlen("bitw_incl_or_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "bitw_incl_or_op(%s, %s)", $1, $3);
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
		{size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen($1) + strlen($3) + strlen($5) + 1;
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
	: declaration_specifiers ';'
		{size_t const size = strlen("\ndeclaration([])") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\ndeclaration([%s])", $1);
		 free($1);
		}
	| declaration_specifiers init_declarator_list ';' 
	  	{if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
		 size_t const size = strlen("\ndeclaration([], [])") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\ndeclaration([%s], [%s])", $1, $2);
		 free($1);
		 free($2);
		}
	| static_assert_declaration
		{size_t const size = strlen("\n") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\n%s", $1);
		 free($1);
		}
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s, %s", $1, $2);
		 free($1);
		 free($2);
		}
	| storage_class_specifier
	| type_specifier declaration_specifiers
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "%s, %s", $1, $2);
		 free($1);
		 free($2);
		}
	| type_specifier
	| type_qualifier declaration_specifiers
		{ simple_str_lit_copy(&$$, "dummy_type_qualifier, dummy_declaration_specifiers"); }
	| type_qualifier
		{ simple_str_lit_copy(&$$, "dummy_type_qualifier"); }
	| function_specifier declaration_specifiers
		{ simple_str_lit_copy(&$$, "dummy_function_specifier, dummy_declaration_specifiers"); }
	| function_specifier
		{ simple_str_lit_copy(&$$, "dummy_function_specifier"); }
	| alignment_specifier declaration_specifiers
		{ simple_str_lit_copy(&$$, "dummy_alignment_specifier, dummy_declaration_specifiers"); }
	| alignment_specifier
		{ simple_str_lit_copy(&$$, "dummy_alignment_specifier"); }
	;

init_declarator_list
	: init_declarator
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
		{size_t const size = strlen("initialised(, )") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	   	 sprintf_safe($$, size, "initialised(%s, %s)", $1, $3);
	   	 free($1);
	   	 //free($3);
	  	}
	| declarator
	  {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name($1);
	   }
	   simple_str_copy(&$$, $1);
	  }
	;

storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
		{simple_str_lit_copy(&$$, "typedef");
         typedef_flag = 1;
	    }
	| EXTERN		{ simple_str_lit_copy(&$$, "extern"); }
	| STATIC		{ simple_str_lit_copy(&$$, "static"); }
	| THREAD_LOCAL	{ simple_str_lit_copy(&$$, "thread_local"); }
	| AUTO			{ simple_str_lit_copy(&$$, "auto"); }
	| REGISTER		{ simple_str_lit_copy(&$$, "register"); }
	;

type_specifier
	: VOID					{ simple_str_lit_copy(&$$, "void"); }
	| CHAR					{ simple_str_lit_copy(&$$, "char"); }
	| SHORT					{ simple_str_lit_copy(&$$, "short"); }
	| INT					{ simple_str_lit_copy(&$$, "int"); }
	| LONG					{ simple_str_lit_copy(&$$, "long"); }
	| FLOAT					{ simple_str_lit_copy(&$$, "float"); }
	| DOUBLE				{ simple_str_lit_copy(&$$, "double"); }
	| SIGNED				{ simple_str_lit_copy(&$$, "signed"); }
	| UNSIGNED				{ simple_str_lit_copy(&$$, "unsigned"); }
	| BOOL					{ simple_str_lit_copy(&$$, "bool"); }
	| COMPLEX				{ simple_str_lit_copy(&$$, "complex"); }
	| IMAGINARY				{ simple_str_lit_copy(&$$, "imaginary"); } 	/* non-mandated extension */
	| atomic_type_specifier	{ simple_str_lit_copy(&$$, "atomic_type_specifier"); }
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME			/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
		{size_t const size = strlen("([])") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s([%s])", $1, $3);
	     free($1);
	     free($3);
	    }
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'	//Tag namespace Id declaration
		{size_t const size = strlen("(, [])") + strlen($1) + strlen($2) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s(%s, [%s])", $1, $2, $4);
	     free($1);
	     free($2);
		 free($4);
	    }
	| struct_or_union IDENTIFIER	//Tag namespace Id declaration
		{size_t const size = strlen("()") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s(%s)", $1, $2);
	     free($1);
	     free($2);
	    }
	;

struct_or_union
	: STRUCT	{simple_str_lit_copy(&$$, "struct");}
	| UNION		{simple_str_lit_copy(&$$, "union");}
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $2);
	     free($1);
	     free($2);
	    }
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
		{size_t const size = strlen("struct_decl_anonymous()") + strlen($1) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "struct_decl_anonymous(%s)", $1);
	   	 free($1);
        }
	| specifier_qualifier_list {in_member_decl_flag = 1;} struct_declarator_list ';'
		{in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "struct_decl([%s], %s)", $1, $3);
	   	 free($1);
		 free($3);
        }
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "%s, %s", $1, $2);
	   	 free($1);
	     free($2);
        }
	| type_specifier
	| type_qualifier specifier_qualifier_list
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "%s, %s", $1, $2);
	   	 free($1);
	     free($2);
        }
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "%s, %s)", $1, $3);
	   	 free($1);
	     free($3);
        }
	;

struct_declarator
	: ':' constant_expression
		{size_t const size = strlen("anonymous_bit_field()") + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "anonymous_bit_field(%s)", $2);
	   	 free($2);
        }
	| declarator ':' constant_expression
		{size_t const size = strlen("bit_field(, )") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "bit_field(%s, %s)", $1, $3);
	   	 free($1);
	     free($3);
        }
	| declarator
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
		{size_t const size = strlen("anonymous_enum([])") + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "anonymous_enum([%s])", $3);
	     free($3);
        }
	| ENUM '{' enumerator_list ',' '}'
		{size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "trailing_comma_anonymous_enum([%s])", $3);
	     free($3);
        }
	| ENUM IDENTIFIER '{' enumerator_list '}'	//Tag namespace Id declaration
		{size_t const size = strlen("enum(, [])") + strlen($2) + strlen($4) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "enum(%s, [%s])", $2, $4);
	     free($2);
		 free($4);
        }
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'	//Tag namespace Id declaration
		{size_t const size = strlen("trailing_comma_enum(, [])") + strlen($2) + strlen($4) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "trailing_comma_enum(%s, [%s])", $2, $4);
	     free($2);
		 free($4);
        }
	| ENUM IDENTIFIER	//Tag namespace Id declaration
		{size_t const size = strlen("forward_enum()") + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_safe($$, size, "forward_enum(%s)", $2);
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
	: ATOMIC_SPECIFIER type_name ')'
	;

type_qualifier
	: CONST		{simple_str_lit_copy(&$$, "const");}
	| RESTRICT	{simple_str_lit_copy(&$$, "restrict");}
	| VOLATILE	{simple_str_lit_copy(&$$, "volatile");}
	| ATOMIC	{simple_str_lit_copy(&$$, "atomic");}
	;

function_specifier
	: INLINE	{simple_str_lit_copy(&$$, "inline");}
	| NORETURN	{simple_str_lit_copy(&$$, "noreturn");}
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

declarator
	: pointer direct_declarator
	  {size_t const size = strlen("()") + strlen($1) + strlen($2) + 1;
       $$ = (char*)malloc(size);
       sprintf_safe($$, size, "%s(%s)", $1, $2);
	   free($1);
	   free($2);
      }
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER		//Ordinary namespace id declaration unless within a struct declaration in which case it is a Member namespace id
		{char Prolog_var_name[MAX_ID_LENGTH+5];
		 if (islower($1[0])) {
			Prolog_var_name[0] = toupper($1[0]);
			strcpy_safe(&Prolog_var_name[1], MAX_ID_LENGTH-1, &$1[1]);
		 } else {
			strcpy_safe(Prolog_var_name, MAX_ID_LENGTH, "UC_");
			strcat_safe(Prolog_var_name, MAX_ID_LENGTH, $1);
		 }
		 size_t const size = strlen(Prolog_var_name) + 1;
		 $$ = (char*)malloc(size);
		 strcpy_safe($$, size, Prolog_var_name);
		 free($1);
		} 
	| '(' declarator ')'			
		{simple_str_lit_copy(&$$, "D1");}
	| direct_declarator '[' ']'		
		{simple_str_lit_copy(&$$, "D2");}
	| direct_declarator '[' '*' ']'	
		{simple_str_lit_copy(&$$, "D3");}
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']' 
		{simple_str_lit_copy(&$$, "D4");}
	| direct_declarator '[' STATIC assignment_expression ']'
		{simple_str_lit_copy(&$$, "D5");}
	| direct_declarator '[' type_qualifier_list '*' ']'
		{simple_str_lit_copy(&$$, "D6");}
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
		{simple_str_lit_copy(&$$, "D7");}
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
		{simple_str_lit_copy(&$$, "D8");}
	| direct_declarator '[' type_qualifier_list ']'
		{simple_str_lit_copy(&$$, "D9");}
	| direct_declarator '[' assignment_expression ']'
		{simple_str_lit_copy(&$$, "D10");}
	| direct_declarator '(' ')'
		{size_t const size = strlen("function(, [])") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "function(%s, [])", $1);
	     free($1);
		}
	| direct_declarator '(' parameter_type_list ')'
		{size_t const size = strlen("function(, )") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "function(%s, %s)", $1, $3);
	     free($1);
		 free($3);
		}

	| direct_declarator '(' identifier_list ')'
		{simple_str_lit_copy(&$$, "D13");}
	;

pointer
	: '*' type_qualifier_list pointer
		{size_t const size = strlen("pointer???(, )") + strlen($2) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "pointer???(%s, %s)", $2, $3);
		 free($2);
		 free($3);
		}
	| '*' type_qualifier_list
		{size_t const size = strlen("pointer()") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "pointer(%s)", $2);
	     free($2);
		}
	| '*' pointer
		{size_t const size = strlen("pointer()") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "pointer(%s)", $2);
		 free($2);
		}
	| '*'
		{simple_str_lit_copy(&$$, "pointer");}
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $2);
	     free($1);
		 free($2);
		}
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
	: parameter_declaration
	| parameter_list ',' parameter_declaration
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $3);
	     free($1);
		 free($3);
		}
	;

parameter_declaration
	: declaration_specifiers declarator
		{size_t const size = strlen("param([], )") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "param([%s], %s)", $1, $2);
	     free($1);
		 free($2);
		}
	| declaration_specifiers abstract_declarator
		{size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "param_no_decl([%s], dummy_abstract_declarator)", $1);
	     free($1);
		 //free($2);
		}
	| declaration_specifiers
		{size_t const size = strlen("param_no_decl([], [])") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "param_no_decl([%s], [])", $1);
	     free($1);
		}
	;

identifier_list
	: IDENTIFIER		//Ordinary Id declaration
	| identifier_list ',' IDENTIFIER	//Ordinary Id declaration
	;

type_name
	: specifier_qualifier_list abstract_declarator	{simple_str_lit_copy(&$$, "typenamedummy1");}
	| specifier_qualifier_list
		{size_t const size = strlen("[]") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "[%s]", $1);
	     free($1);
		}
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
	| '{' initializer_list ',' '}'
		{size_t const size = strlen("[]") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "trailing_comma_initializer([%s])", $2);
	     free($2);
		}
	| assignment_expression
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

designation
	: designator_list '='
		{size_t const size = strlen("[]") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "[%s]", $1);
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
	: '[' constant_expression ']'
		{simple_str_copy(&$$, $2);}
	| '.' IDENTIFIER
		{size_t const size = strlen("select()") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "select(%s)", $2);
		 free($2);
		}
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		{size_t const size = strlen("static_assert(, )") + strlen($3) + strlen($5) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "static_assert(%s, %s)", $3, $5);
		 free($3);
		 free($5);
		}
	;

statement
	: labeled_statement
	| compound_statement
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
	| CASE constant_expression ':' statement
	  {size_t const size = strlen("case_stmt(, )") + strlen($2) + strlen($4) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "case_stmt(%s, %s)", $2, $4);
	   free($2);
	   free($4);
	  }
	| DEFAULT ':' statement
	  {size_t const size = strlen("default_stmt(, )") + strlen($3) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "default_stmt(%s)", $3);
	   free($3);
	  }
	;

compound_statement	//aka a 'block'
	: '{' '}'	{simple_str_lit_copy(&$$, "\ncmp_stmts([])");}
	| '{' block_item_list '}' 
	  {size_t const size = strlen("\ncmp_stmts([\n])") + strlen($2) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "\ncmp_stmts([%s\n])", $2);
	   free($2);
	  }
	;

block_item_list
	: block_item
	| block_item_list block_item
	  {size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "%s, %s", $1, $2);
	   free($1);
	   free($2);
	  }
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'	{simple_str_lit_copy(&$$, "stmt([])");}
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
		{size_t const size = strlen("\nswitch_stmt(, )") + strlen($3) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nswitch_stmt(%s, %s)", $3, $5);
		 free($3);
		 free($5);
		} 
	;

else_opt
	: /* empty */		%prec LOWER_THAN_ELSE 	{simple_str_lit_copy(&$$, "");}
	| ELSE statement
		{size_t const size = strlen(", ") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, ", %s", $2);
		 free($2);
		} 

iteration_statement
	: WHILE '(' expression ')' statement 
		{size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen($3) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, $3, $5);
		 free($3);
		 free($5);
		} 
	| DO statement WHILE '(' expression ')' ';'
		{size_t const size = strlen("\ndo_while_stmt(, )") + strlen($2) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\ndo_while_stmt(%s, %s)", $2, $5);
		 free($2);
		 free($5);
		} 
	| FOR '(' for_stmt_type ')' statement
		{size_t const size = strlen("\nfor_stmt(, )") + strlen($3) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_safe($$, size, "\nfor_stmt(%s, %s)", $3, $5);
		 free($3);
		 free($5);
		} 
	;

for_stmt_type
	: expression_statement expression_statement expression_opt 
	  {size_t const size = strlen(",  ") + strlen($1) + strlen($2) + strlen($3) +1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "%s, %s %s", $1, $2, $3);
	   free($1);
	   free($2);
	   free($3);
	  }
	| declaration expression_statement expression_opt
	  {size_t const size = strlen(",  ") + strlen($1) + strlen($2) + strlen($3) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "%s, %s %s", $1, $2, $3);
	   free($1);
	   free($2);
	   free($3);
	  }
	;

expression_opt
	: /* empty */	{simple_str_lit_copy(&$$, "");}
	| expression
		{size_t const size = strlen(", ") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, ", %s", $1);
	     free($1);
	    }

jump_statement
	: GOTO IDENTIFIER ';'
	  {size_t const size = strlen("\ngoto_stmt()\n") + strlen($2) + 1;
	   $$ = (char*)malloc(size);
	   sprintf_safe($$, size, "\ngoto_stmt(%s)\n", $2);
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
	: external_declaration
	| translation_unit {fprintf(pl_file, ", \n");} external_declaration
	;

external_declaration		//printed out
	: function_definition	{fprintf(pl_file, "%s", $1); free($1);}
	| declaration			{fprintf(pl_file, "%s", $1); free($1);}
	;

function_definition
	: declaration_specifiers declarator declaration_list_opt compound_statement
		{size_t const size = strlen("function([], , [], )") + strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "function([%s], %s, [%s], %s)", $1, $2, $3, $4);
	     free($1);
		 free($2);
		 free($3);
		 free($4);
		}
	;

declaration_list_opt
	: /* empty */		{simple_str_lit_copy(&$$, "");}
	| declaration_list	//for old-style function declaration see p. 226 K&R
	;

declaration_list
	: declaration
	| declaration_list declaration
	  	{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_safe($$, size, "%s, %s", $1, $2);
	     free($1);
		 free($2);
		}
	;

%%
#include "lex.yy.c"

int main(int argc, char *argv[]) {
	char C_file_path[MAX_PATH];				//directory where the C and .i files are
	char filename_no_ext[MAX_PATH];

#ifdef _MSC_VER
	strcpy_safe(C_file_path, 3, ".");		//default path for input file is current directory, overwrite with -p on command line
#else
	strcpy_safe(C_file_path, 3, ".");
#endif
	for (int i = 1; i <= argc - 1; i++) {	//processing command line arguments
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'h':
				printf("Usage: .\\sikraken_parser [OPTION]... FILE_NO_EXT\nParses the .i file of a C file pre-processsed by GCC to Prolog terms.\n\n-h\t Display help information\n-m32|-m64\t Specify the data model, -m32 is the default\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\sikraken_parser -p\".\" get_sign \n\t.\\sikraken_parser get_sign \n\t.\\sikraken_parser -m64 -p\"C:/Parser/\" sign \n");
				my_exit(0);
			case 'p':	//path to the .i pre-processed input C file
				if (access_safe(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					my_exit(1);
				}
				strcpy_safe(C_file_path, MAX_PATH, &argv[i][2]);
				break;
			case 'd':
				debugMode = 1;	//we are in debug mode : will affect output of warnings amongst other things
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
			strcpy_safe(filename_no_ext, MAX_PATH, argv[i]);
		}
	}
	fprintf(stdout, "Sikraken parser: using %i bits data model.\n", dataModel); 

	sprintf_safe(i_file_uri, 3*MAX_PATH, "%s/%s.i", C_file_path, filename_no_ext);
	if (fopen_safe(&i_file, i_file_uri, "r") != 0) {
		fprintf(stderr, ".i file could not be opened for reading at: %s\n", i_file_uri);
		my_exit(EXIT_FAILURE);
	}
	yyin = i_file;	//set the input to the parser
	sprintf_safe(pl_file_uri, 3*MAX_PATH, "%s/%s.pl", C_file_path, filename_no_ext);
	if (fopen_safe(&pl_file, pl_file_uri, "w") != 0) {
		fprintf(stderr, ".pl file could not be created for writing at: %s\n", pl_file_uri);
		my_exit(EXIT_FAILURE);
	}
	fprintf(pl_file, "prolog_c([");			//opening predicate
	if (yyparse() != 0) {					//the parser is called
		fprintf(stderr, "Parsing failed.\n");
		my_exit(EXIT_FAILURE);
	}	
	fprintf(pl_file, "\n]).");
	fclose(pl_file);
	pl_file = NULL;
	fclose(i_file);
	i_file = NULL;
	my_exit(EXIT_SUCCESS);
}

//handles parsing errors: since the C input file is the output of a C pre-processor it will only be called if
//  the syntax rules are wrong due to GCC extensions 
//  or if .i file has been generated manually: i.e. during development
void yyerror(const char* s) {
	extern char* yytext;  	// Points to the text of the current token
    extern int yyleng;    	// Length of the current token
    const char* token_name = (yychar >= 0 && yychar < YYNTOKENS) ? yytname[yychar] : "unknown token";
    
    fprintf(stderr, "Sikraken Parsing error: %s, at line %d, near token '%s' (token code: %d)\n", s, yylineno, yytext, yychar);
    fprintf(stderr, "Problematic token: '%.*s'\n", yyleng, yytext);
	fprintf(stderr, "Unexpected token: %s\n", token_name); 
}

void my_exit(int exit_code) {			//exits and performs some tidying up if not in debug mode
  if (!debugMode) {
    if (i_file) fclose(i_file);
    if (pl_file) fclose(pl_file);
    if (access_safe(i_file_uri, 0) != -1) remove(i_file_uri);
  }
  if (exit_code == EXIT_SUCCESS) fprintf(stderr, "Sikraken parsing SUCCESS, wrote %s\n", pl_file_uri);
  exit(exit_code);
}
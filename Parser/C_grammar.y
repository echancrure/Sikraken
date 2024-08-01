/****************************************************************************************************/
/* C11 grammar file from https://www.quut.com/c/ANSI-C-grammar-y.html								*/
/* Bison documentation: https://www.gnu.org/software/bison/manual/html_node/index.html              */
/****************************************************************************************************/
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include "utils.h"
#include "handle_typedefs.h"
#include "string_buffer.h"
#include "stack_of_id_tables.c"

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;

int debugMode = 0;				//flag to indicate if we are in debug mode set by by -d command line switch
FILE* pl_file;						//the file of containing the Prolog predicated after parsing the target C file
char pl_file_uri[_MAX_PATH];		//the full path to the Pl_file
struct scope *ordinary_ids_scope_stack = NULL;	//stack of id tables to track scopes of is in the ordinary namespace 
StringBuilder *id_names;			//string buffer to hold Prolog var names and their details e.g. a(I_407, 'ch8_1.adb:39:7:i')
int id_counter = 0;					//used to generate unique Prolog var names e.g. I_1, I_2, I_3 etc.
//start: ugly, breaking parsing spirit, flags and temporary variables
int in_member_decl_flag = 0;	//indicate that we are parsing struct or union declarations and that the ids are part of the members namespace
char* tmp_current_decl_id;			//temporary holder for the id currently being declared
char* tmp_current_decl_prolog_var;	//temporary holder for the Prolog var currently being declared

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

%token ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

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

%start translation_unit 
%%

primary_expression
	: IDENTIFIER	
		{char *Prolog_name;
		 Prolog_name = find_symbol(ordinary_ids_scope_stack, $1)->Prolog_name;
		 size_t const size = strlen(Prolog_name) + 1;
		 $$ = (char*)malloc(size);
         strcpy_s($$, size, Prolog_name);
		 free($1);
		}
	| constant		{simple_str_copy(&$$, $1);}
	| string		{simple_str_copy(&$$, $1);}
	| '(' expression ')'	{simple_str_lit_copy(&$$, "prim4");}
	| generic_selection		{simple_str_lit_copy(&$$, "generic_selection");}
	;

constant
	: I_CONSTANT	{simple_str_copy(&$$, $1);}	/* includes character_constant */
	| F_CONSTANT	{simple_str_copy(&$$, $1);}
	| ENUMERATION_CONSTANT	{simple_str_copy(&$$, $1);} /* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER		//Ordinary namespace Id declaration
		{simple_str_copy(&$$, $1);}
	;

string
	: STRING_LITERAL	{simple_str_copy(&$$, $1);}	//"blah" or wide_string("blah") see lexer
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
		{simple_str_copy(&$$, $1);}
	| postfix_expression '[' expression ']'
		{size_t const size = strlen("index(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "index(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	| postfix_expression '(' ')'
		{size_t const size = strlen("([])") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s([])", $1);
		 free($1);
		}
	| postfix_expression '(' argument_expression_list ')'	/* functyion call */
		{size_t const size = strlen("([])") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s([%s])", $1, $3);
		 free($1);
		 free($3);
		}
	| postfix_expression '.' IDENTIFIER
		{size_t const size = strlen("select(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "select(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	| postfix_expression PTR_OP IDENTIFIER
		{size_t const size = strlen("struct_pointer(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "struct_pointer(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	| postfix_expression INC_OP
		{size_t const size = strlen("postfix_inc_op()") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "postfix_inc_op(%s)", $1);
		 free($1);
		}
	| postfix_expression DEC_OP
		{size_t const size = strlen("postfix_dec_op()") + strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "postfix_dec_op(%s)", $1);
		 free($1);
		}
	| '(' type_name ')' '{' initializer_list '}'
		{size_t const size = strlen("compound_literal(, )") + strlen($2) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "compound_literal(%s, %s)", $2, $5);
		 free($2);
		 free($5);
		}
	| '(' type_name ')' '{' initializer_list ',' '}'
		{size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen($2) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "trailing_comma_compound_literal(%s, %s)", $2, $5);
		 free($2);
		 free($5);
		}
	;

argument_expression_list
	: assignment_expression	{simple_str_copy(&$$, $1);}
	| argument_expression_list ',' assignment_expression
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s, %s", $1, $3);
		 free($1);
		 free($3);
		}
	;

unary_expression
	: postfix_expression		{simple_str_copy(&$$, $1);}
	| unary_inc_dec unary_expression
		{size_t const size = strlen("()") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s)", $1, $2);
		 free($1);
		 free($2);
		}
	| unary_operator cast_expression
		{size_t const size = strlen("()") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s)", $1, $2);
		 free($1);
		 free($2);
		}
	| SIZEOF unary_expression
		{size_t const size = strlen("size_of_exp()") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "size_of_exp(%s)", $2);
		 free($2);
		}
	| SIZEOF '(' type_name ')'
		{size_t const size = strlen("size_of_type()") + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "size_of_type(%s)", $3);
		 free($3);
		}
	| ALIGNOF '(' type_name ')'
		{size_t const size = strlen("align_of()") + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "align_of(%s)", $3);
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
	: unary_expression	{simple_str_copy(&$$, $1);}
	| '(' type_name ')' cast_expression
		{size_t const size = strlen("cast(, )") + strlen($2) + strlen($4) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "cast(%s, %s)", $2, $4);
		 free($2);
		 free($4);
		}
	;

multiplicative_expression
	: cast_expression	{simple_str_copy(&$$, $1);}
	| multiplicative_expression multiplicative_expression_op cast_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s, %s)", $2, $1, $3);
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
	: multiplicative_expression	{simple_str_copy(&$$, $1);}
	| additive_expression additive_expression_op multiplicative_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s, %s)", $2, $1, $3);
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
	: additive_expression	{simple_str_copy(&$$, $1);}
	| shift_expression shift_expression_op additive_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s, %s)", $2, $1, $3);
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
	: shift_expression	{simple_str_copy(&$$, $1);}
	| relational_expression relational_expression_operator shift_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s, %s)", $2, $1, $3);
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
	: relational_expression	{simple_str_copy(&$$, $1);}
	| equality_expression equality_expression_op relational_expression
		{size_t const size = strlen("(, )") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s, %s)", $2, $1, $3);
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
	: equality_expression	{simple_str_copy(&$$, $1);}
	| and_expression '&' equality_expression
		{size_t const size = strlen("bitw_and(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "bitw_and(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

exclusive_or_expression
	: and_expression	{simple_str_copy(&$$, $1);}
	| exclusive_or_expression '^' and_expression
		{size_t const size = strlen("bitw_excl_or_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "bitw_excl_or_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

inclusive_or_expression
	: exclusive_or_expression	{simple_str_copy(&$$, $1);}
	| inclusive_or_expression '|' exclusive_or_expression
		{size_t const size = strlen("bitw_incl_or_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "bitw_incl_or_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

logical_and_expression
	: inclusive_or_expression	{simple_str_copy(&$$, $1);}
	| logical_and_expression AND_OP inclusive_or_expression
		{size_t const size = strlen("and_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "and_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

logical_or_expression
	: logical_and_expression	{simple_str_copy(&$$, $1);}
	| logical_or_expression OR_OP logical_and_expression
		{size_t const size = strlen("or_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "or_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

conditional_expression
	: logical_or_expression		{simple_str_copy(&$$, $1);}
	| logical_or_expression '?' expression ':' conditional_expression 
		{size_t const size = strlen("cond_exp(, , )") + strlen($1) + strlen($3) + strlen($5) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "cond_exp(%s, %s, %s)", $1, $3, $5);
		 free($1);
		 free($3);
		 free($5);
		}
	;

assignment_expression
	: conditional_expression	{simple_str_copy(&$$, $1);}
	| unary_expression assignment_operator assignment_expression
		{size_t const size = strlen("%s(%s, %s)") + strlen($1) + strlen($2) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s(%s, %s)", $2, $1, $3);
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
	: assignment_expression	{simple_str_copy(&$$, $1);}
	| expression ',' assignment_expression
		{size_t const size = strlen("comma_op(, )") + strlen($1) + strlen($3) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "comma_op(%s, %s)", $1, $3);
		 free($1);
		 free($3);
		}
	;

constant_expression
	: conditional_expression	/* with constraints */ 	{simple_str_copy(&$$, $1);}
	;

declaration
	: declaration_specifiers ';'
		{fprintf(pl_file, "\ndeclaration([%s])", $1);
		 free($1);
		}
	| declaration_specifiers init_declarator_list ';' 
	  	{if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
	     fprintf(pl_file, "\ndeclaration([%s], [%s])", $1, $2);
	     free($1);
	     free($2);
	  }
	| static_assert_declaration
		{fprintf(pl_file, "\n%s", $1);
		 free($1);
		}
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s, %s", $1, $2);
		 free($1);
		 free($2);
		}
	| storage_class_specifier	{simple_str_copy(&$$, $1);}
	| type_specifier declaration_specifiers
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s, %s", $1, $2);
		 free($1);
		 free($2);
		}
	| type_specifier	{simple_str_copy(&$$, $1);}
	| type_qualifier declaration_specifiers
{ simple_str_lit_copy(&$$, "type_qualifier declaration_specifiers"); }
	| type_qualifier
{ simple_str_lit_copy(&$$, "type_qualifier"); }
	| function_specifier declaration_specifiers
{ simple_str_lit_copy(&$$, "function_specifier declaration_specifiers"); }
	| function_specifier
{ simple_str_lit_copy(&$$, "function_specifier"); }
	| alignment_specifier declaration_specifiers
{ simple_str_lit_copy(&$$, "alignment_specifier declaration_specifiers"); }
	| alignment_specifier
{ simple_str_lit_copy(&$$, "alignment_specifier"); }
	;

init_declarator_list
	: init_declarator	{simple_str_copy(&$$, $1);}
	| init_declarator_list ',' init_declarator
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s, %s", $1, $3);
	     free($1);
	     free($3);
		}
	;

init_declarator
	: declarator '=' initializer
		{size_t const size = strlen("initialised(, )") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	   	 sprintf_s($$, size, "initialised(%s, %s)", $1, $3);
	   	 free($1);
	   	 //free($3);
		 add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);	//i.e. only after initialisation
	  	}
	| declarator
	  {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name($1);
	   }
	   simple_str_copy(&$$, $1);
	   add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);
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
	| struct_or_union_specifier	{simple_str_copy(&$$, $1);}
	| enum_specifier		{simple_str_copy(&$$, $1);}
	| TYPEDEF_NAME			{simple_str_copy(&$$, $1);}	/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
		{size_t const size = strlen("([])") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s([%s])", $1, $3);
	     free($1);
	     free($3);
	    }
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'	//Tag namespace Id declaration
		{size_t const size = strlen("(, [])") + strlen($1) + strlen($2) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s(%s, [%s])", $1, $2, $4);
	     free($1);
	     free($2);
		 free($4);
	    }
	| struct_or_union IDENTIFIER	//Tag namespace Id declaration
		{size_t const size = strlen("()") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s(%s)", $1, $2);
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
		{simple_str_copy(&$$, $1);}
	| struct_declaration_list struct_declaration
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s, %s", $1, $2);
	     free($1);
	     free($2);
	    }
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
		{size_t const size = strlen("struct_decl_anonymous()") + strlen($1) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "struct_decl_anonymous(%s)", $1);
	   	 free($1);
        }
	| specifier_qualifier_list {in_member_decl_flag = 1;} struct_declarator_list ';'
		{in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "struct_decl([%s], %s)", $1, $3);
	   	 free($1);
		 free($3);
        }
	| static_assert_declaration
		{simple_str_copy(&$$, $1);}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "%s, %s", $1, $2);
	   	 free($1);
	     free($2);
        }
	| type_specifier
		{simple_str_copy(&$$, $1);}
	| type_qualifier specifier_qualifier_list
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "%s, %s", $1, $2);
	   	 free($1);
	     free($2);
        }
	| type_qualifier
		{simple_str_copy(&$$, $1);}
	;

struct_declarator_list
	: struct_declarator
		{simple_str_copy(&$$, $1);}
	| struct_declarator_list ',' struct_declarator
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "%s, %s)", $1, $3);
	   	 free($1);
	     free($3);
        }
	;

struct_declarator
	: ':' constant_expression
		{size_t const size = strlen("anonymous_bit_field()") + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "anonymous_bit_field(%s)", $2);
	   	 free($2);
        }
	| declarator ':' constant_expression
		{size_t const size = strlen("bit_field(, )") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "bit_field(%s, %s)", $1, $3);
	   	 free($1);
	     free($3);
        }
	| declarator
		{simple_str_copy(&$$, $1);}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
		{size_t const size = strlen("anonymous_enum([])") + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "anonymous_enum([%s])", $3);
	     free($3);
        }
	| ENUM '{' enumerator_list ',' '}'
		{size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "trailing_comma_anonymous_enum([%s])", $3);
	     free($3);
        }
	| ENUM IDENTIFIER '{' enumerator_list '}'	//Tag namespace Id declaration
		{size_t const size = strlen("enum(, [])") + strlen($2) + strlen($4) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "enum(%s, [%s])", $2, $4);
	     free($2);
		 free($4);
        }
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'	//Tag namespace Id declaration
		{size_t const size = strlen("trailing_comma_enum(, [])") + strlen($2) + strlen($4) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "trailing_comma_enum(%s, [%s])", $2, $4);
	     free($2);
		 free($4);
        }
	| ENUM IDENTIFIER	//Tag namespace Id declaration
		{size_t const size = strlen("forward_enum()") + strlen($2) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "forward_enum(%s)", $2);
	     free($2);
        }
	;

enumerator_list
	: enumerator
		{simple_str_copy(&$$, $1);}
	| enumerator_list ',' enumerator
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "%s, %s", $1, $3);
	   	 free($1);
	     free($3);
        }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression
		{size_t const size = strlen("init_enum(, )") + strlen($1) + strlen($3) + 1;
       	 $$ = (char*)malloc(size);
         sprintf_s($$, size, "init_enum(%s, %s)", $1, $3);
	   	 free($1);
	     free($3);
        }
	| enumeration_constant
		{simple_str_copy(&$$, $1);}
	;

atomic_type_specifier		// new in C11 for atomic operation: used in concurrency
	: ATOMIC '(' type_name ')'
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
       sprintf_s($$, size, "%s(%s)", $1, $2);
	   free($1);
	   free($2);
      }
	| direct_declarator
	  {simple_str_copy(&$$, $1);}
	;

direct_declarator
	: IDENTIFIER		//Ordinary namespace id declaration unless within a struct declaration in which case it is a Member namespace id
		{id_counter++;
		 char id_counter_str[20];
		 sprintf_s(id_counter_str, 20, "%d", id_counter);
		 char Prolog_var_name[MAX_ID_LENGTH];
		 if (islower($1[0])) {
			Prolog_var_name[0] = toupper($1[0]);
			strcpy_s(&Prolog_var_name[1], MAX_ID_LENGTH-1, &$1[1]);
		 } else {
			strcpy_s(Prolog_var_name, MAX_ID_LENGTH, "UC_");
			strcat_s(Prolog_var_name, MAX_ID_LENGTH, $1);
		 }
		 strcat_s(Prolog_var_name, MAX_ID_LENGTH, "_");
		 strcat_s(Prolog_var_name, MAX_ID_LENGTH, id_counter_str);
		 size_t const size = strlen(Prolog_var_name) + 1;
		 $$ = (char*)malloc(size);
		 strcpy_s($$, size, Prolog_var_name);
		 //ugly: keep declared identifer details to be pushed after possible initialisation
		 size_t const size1 = strlen($1) + 1;
		 tmp_current_decl_id = (char*)malloc(size1);
		 strcpy_s(tmp_current_decl_id, size1, $1);		
		 size_t const size2 = strlen(Prolog_var_name) + 1;
		 tmp_current_decl_prolog_var = (char*)malloc(size2);
		 strcpy_s(tmp_current_decl_prolog_var, size2, Prolog_var_name);
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
		{//size_t const size = strlen(", []") + strlen($1) + 1;
	     //$$ = (char*)malloc(size);
	     //sprintf_s($$, size, "%s, []", $1);
	     //free($1);
		 simple_str_lit_copy(&$$, "no params");
		}
	| direct_declarator '(' 
		{add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);	//for the function name
		 enter_scope(&ordinary_ids_scope_stack); 	//for parameters
		}	
	  parameter_type_list ')'
		{size_t const size = strlen(", ") + strlen($1) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s, %s", $1, $4);
	     free($1);
		 free($4);
		}

	| direct_declarator '(' identifier_list ')'
		{simple_str_lit_copy(&$$, "D13");}
	;

pointer
	: '*' type_qualifier_list pointer
		{size_t const size = strlen("pointer???(, )") + strlen($2) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "pointer???(%s, %s)", $2, $3);
		 free($2);
		 free($3);
		}
	| '*' type_qualifier_list
		{size_t const size = strlen("pointer()") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "pointer(%s)", $2);
	     free($2);
		}
	| '*' pointer
		{size_t const size = strlen("pointer()") + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "pointer(%s)", $2);
		 free($2);
		}
	| '*'
		{simple_str_lit_copy(&$$, "pointer");}
	;

type_qualifier_list
	: type_qualifier	
		{simple_str_copy(&$$, $1);}
	| type_qualifier_list type_qualifier
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s, %s", $1, $2);
	     free($1);
		 free($2);
		}
	;

parameter_type_list
	: parameter_list ',' ELLIPSIS
		{size_t const size = strlen("variable_length_args([])") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "variable_length_args([%s])", $1);
	     free($1);
		}
	| parameter_list
		{size_t const size = strlen("[]") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "[%s]", $1);
	     free($1);
		}
	;

parameter_list
	: parameter_declaration
		{simple_str_copy(&$$, $1);}
	| parameter_list ',' parameter_declaration
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s, %s", $1, $3);
	     free($1);
		 free($3);
		}
	;

parameter_declaration
	: declaration_specifiers declarator
		{size_t const size = strlen("param([], )") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "param([%s], %s)", $1, $2);
	     free($1);
		 free($2);
		 add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);
		}
	| declaration_specifiers abstract_declarator
		{size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "param_no_decl([%s], dummy_abstract_declarator)", $1);
	     free($1);
		 //free($2);
		}
	| declaration_specifiers
		{size_t const size = strlen("param_no_decl([], [])") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "param_no_decl([%s], [])", $1);
	     free($1);
		}
	;

identifier_list
	: IDENTIFIER		//Ordinary Id declaration
	| identifier_list ',' IDENTIFIER	//Ordinary Id declaration
	;

type_name
	: specifier_qualifier_list abstract_declarator	{simple_str_lit_copy(&$$, "typenamedummy1");}
	| specifier_qualifier_list						{simple_str_lit_copy(&$$, "typenamedummy2");}
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
	     sprintf_s($$, size, "initializer([%s])", $2);
	     free($2);
		}
	| '{' initializer_list ',' '}'
		{size_t const size = strlen("[]") + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "trailing_comma_initializer([%s])", $2);
	     free($2);
		}
	| assignment_expression
		{simple_str_copy(&$$, $1);}
	;

initializer_list
	: designation initializer
		{size_t const size = strlen("init(, )") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "init(%s, %s)", $1, $2);
	     free($1);
		 free($2);
		}
	| initializer				
		{simple_str_copy(&$$, $1);}
	| initializer_list ',' designation initializer
		{size_t const size = strlen(", init(, )") + strlen($1) + strlen($3) + strlen($4) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s, init(%s, %s)", $1, $3, $4);
	     free($1);
		 free($3);
		 free($4);
		}
	| initializer_list ',' initializer
		{size_t const size = strlen(", ") + strlen($1) + strlen($3) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s, %s", $1, $3);
	     free($1);
		 free($3);
		}
	;

designation
	: designator_list '='
		{size_t const size = strlen("[]") + strlen($1) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "[%s]", $1);
	     free($1);
		}
	;

designator_list
	: designator	
		{simple_str_copy(&$$, $1);}
	| designator_list designator
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "%s, %s", $1, $2);
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
	     sprintf_s($$, size, "select(%s)", $2);
		 free($2);
		}
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		{size_t const size = strlen("static_assert(, )") + strlen($3) + strlen($5) + 1;
	     $$ = (char*)malloc(size);
	     sprintf_s($$, size, "static_assert(%s, %s)", $3, $5);
		 free($3);
		 free($5);
		}
	;

statement	//printed out
	: labeled_statement		//already printed out
	| compound_statement	//already printed out
	| expression_statement	//already printed out
	| selection_statement	//already printed out
	| iteration_statement	//already printed out
	| jump_statement		//already printed out
	;

labeled_statement	//printed out
	: IDENTIFIER ':' 	//Label Id declaration
		{fprintf(pl_file, "label_stmt($1, "); 
		 free($1);
		} 
		statement 
		{fprintf(pl_file, ")");}
	| CASE constant_expression ':' {fprintf(pl_file, "case_stmt($2, "); free($2);} statement {fprintf(pl_file, ")");}
	| DEFAULT ':' {fprintf(pl_file, "default_stmt(");} statement {fprintf(pl_file, ")");}
	;

compound_statement	//printed out	//aka a 'block'
	: '{' '}' {fprintf(pl_file, "\ncmp_stmts([])");}
	| '{' 
		{enter_scope(&ordinary_ids_scope_stack);
		 fprintf(pl_file, "\ncmp_stmts([");
		} 
	   block_item_list 
	  '}' 
		{leave_scope(&ordinary_ids_scope_stack);
		 fprintf(pl_file, "\n])");
		}
	;

block_item_list		//printed out
	: block_item	//printed out already
	| block_item_list {fprintf(pl_file, ", ");} block_item
	;

block_item			//printed out
	: declaration	//printed out already
	| statement		//printed out already
	;

expression_statement	//printed out
	: ';'				{fprintf(pl_file, "stmt()");}
	| expression ';'	{fprintf(pl_file, "\nstmt(%s)", $1); free($1);}
	;

selection_statement		//printed out
	: IF '(' expression ')' {fprintf(pl_file, "\nif_stmt(%s, ", $3); free($3);} statement else_opt {fprintf(pl_file, ")");}
	| SWITCH '(' expression ')' {fprintf(pl_file, "\nswitch_stmt(%s, ", $3); free($3);} statement	{fprintf(pl_file, ")");}
	;

else_opt	//printed out
	:	/* empty */
	| ELSE {fprintf(pl_file, ", ");} statement

iteration_statement	//printed out
	: WHILE '(' expression ')' {fprintf(pl_file, "\nwhile_stmt(%s, ", $3); free($3);} statement {fprintf(pl_file, ")");}
	| DO {fprintf(pl_file, "\ndo_while_stmt(");} statement WHILE '(' expression ')' ';' {fprintf(pl_file, ", %s)", $6); free($6);}
	| FOR '(' {fprintf(pl_file, "\nfor_stmt(");} for_stmt_type ')' {fprintf(pl_file, ", ");} statement {fprintf(pl_file, ")");}
	;

for_stmt_type 		//printed out
	: expression_statement {fprintf(pl_file, ", ");} expression_statement expression_opt
	| declaration {fprintf(pl_file, ", ");} expression_statement expression_opt
	;

expression_opt 		//printed out
	: /* empty */
	| expression {fprintf(pl_file, ", %s", $1); free($1);}

jump_statement		//printed out
	: GOTO IDENTIFIER ';'	{fprintf(pl_file, "\ngoto_stmt(%s)\n", $2); free($2);}
	| CONTINUE ';'			{fprintf(pl_file, "\ncontinue_stmt\n");}
	| BREAK ';'				{fprintf(pl_file, "\nbreak_stmt\n");}
	| RETURN ';'			{fprintf(pl_file, "\nreturn_stmt\n");}
	| RETURN expression ';'	{fprintf(pl_file, "\nreturn_stmt(%s)\n", $2); free($2);}
	;

//top level rule
translation_unit 	//printed out
	: external_declaration
	| translation_unit {fprintf(pl_file, ", \n");} external_declaration
	;

external_declaration	//printed out
	: function_definition	//already printed out
	| declaration			//already printed out
	;

function_definition	//printed out
	: declaration_specifiers declarator 
		{fprintf(pl_file, "function([%s], %s, [", $1, $2); 
		 free($1); 
		 free($2);
		} 
	  declaration_list_opt 
		{fprintf(pl_file, "], ");}
	  compound_statement 			//aka a block: contains curly brackets { }
		{fprintf(pl_file, ")");
		 leave_scope(&ordinary_ids_scope_stack);	//for the surrounding parameters
		}	
	;

declaration_list_opt	//printed out
	: /* empty */
	| declaration_list	//already printed out //for old-style function declaration see p. 226 K&R
	;

declaration_list	//printed out
	: declaration	//already printed out
	| declaration_list {fprintf(pl_file, ", ");} declaration
	;

%%
int main(int argc, char *argv[]) {				//argc is the total number of strings in the argv array
	char C_file_path[_MAX_PATH];				//directory where the C and .i files are
	char filename_no_ext[_MAX_PATH];
	char i_file_uri[_MAX_PATH];
	FILE *i_file;

	id_names = sb_init();		//initialise the buffer to hold all the Prolog id details
	if (id_names==NULL) {
		fprintf(stderr, "Sikraken parser fatal error: cannot initialise buffer id_names");
		my_exit(2);
	}

	strcpy_s(C_file_path, 3, ".\\");		//default path for input file is current directory, overwrite with -p on command line
	for (int i = 1; i <= argc - 1; i++) {	//processing command line arguments
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'h':
				printf("Usage: .\\sikraken_parser [OPTION]... [FILE]\nParse a C file to Prolog terms.\n\n-h\t Display help information\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\LilyParser -p\".\" get_sign \n\t.\\LilyParser get_sign \n\t.\\LilyParser -p\"C:/Parser/\" sign \n");
				my_exit(0);
			case 'p':	//path to the .i pre-processed input C file
				if (_access(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					my_exit(1);
				}
				strcpy_s(C_file_path, _MAX_PATH, &argv[i][2]);
				break;
			case 'd':
				debugMode = 1;	//we are in debug mode : will affect output of warnings amongst other things
				break;
			default:
				fprintf(stderr, "Sikraken parser: Unsupported flag '-%s', ignoring.\n", argv[i]);
			}
		}
		else {	//must be the filename to analyse
			argv[i][strlen(argv[i]) - 2] = '\0';	//cut the out ".c"
			strcpy_s(filename_no_ext, _MAX_PATH, argv[i]);
		}
	}
	sprintf_s(i_file_uri, _MAX_PATH, "%s%s.i", C_file_path, filename_no_ext);
	if (fopen_s(&i_file, i_file_uri, "r") != 0) {
		fprintf(stderr, ".i file could opened to read at: %s\n", i_file_uri);
		my_exit(EXIT_FAILURE);
	}
	yyin = i_file;	//set the input to the parser
	sprintf_s(pl_file_uri, _MAX_PATH, "%s%s.pl", C_file_path, filename_no_ext);
	if (fopen_s(&pl_file, pl_file_uri, "w") != 0) {
		fprintf(stderr, ".pl file could created for write at: %s\n", pl_file_uri);
		my_exit(EXIT_FAILURE);
	}
	fprintf(pl_file, "prolog_c([");			//opening predicate
	enter_scope(&ordinary_ids_scope_stack);	//creates the initial scope for ordinary ids namespace
	if (yyparse() != 0) {					//the parser is called
		fprintf(stderr, "Parsing failed.\n");
		my_exit(EXIT_FAILURE);
	}	
	leave_scope(&ordinary_ids_scope_stack);	//destroys the initial scope for ordinary ids namespace
	fprintf(pl_file, "],\nsikraken_xref([\n");				//append all the ids details
	fprintf(pl_file, id_names->str);
	fprintf(pl_file, "\n    ])\n).");
	fclose(pl_file);
	fclose(i_file);
	my_exit(EXIT_SUCCESS);
}


//handles parsing errors: since the C input file is the output of a C pre-processor it is unlikely to be every called
//in fact it is only useful if the syntax rules are wrong or if .i file has been generated manually: i.e. during development
void yyerror(const char* s) {
	fprintf(stderr, "Internal parsing error, yyerror called on line %d with message \"%s\" on token %d\n", yylineno, s, yychar);
}

void my_exit(int exit_code) {			//exits and performs some tidying up if not in debug mode
  if (!debugMode) {
    if (yyin) fclose(yyin);
    if (pl_file) fclose(pl_file);
    if (_access(pl_file_uri, 0) != -1) remove(pl_file_uri);
  }
  if (exit_code == EXIT_SUCCESS) fprintf(stderr, "Sikraken parsing success, wrote %s", pl_file_uri);
  exit(exit_code);
}
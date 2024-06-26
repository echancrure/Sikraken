/****************************************************************************************************/
/* C11 grammar file from https://www.quut.com/c/ANSI-C-grammar-y.html								*/
/* Bison documentation: https://www.gnu.org/software/bison/manual/html_node/index.html              */
/****************************************************************************************************/
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "utils.h"
#include "handle_typedefs.h"

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;
extern int typedef_flag;

char pl_file_uri[_MAX_PATH];
FILE* pl_file;

void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);

int debugMode = 0;				//flag to indicate if we are in debug mode set by by -d command line switch
%}

%union {
	char* id;
}

%token <id> IDENTIFIER TYPEDEF_NAME
%token I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	ENUMERATION_CONSTANT

%token  TYPEDEF 
%token  EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%type <id> storage_class_specifier declarator init_declarator initializer direct_declarator pointer type_qualifier type_qualifier_list init_declarator_list declaration_specifiers
%type <id> type_specifier

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| constant
	| string
	| '(' expression ')'
	| generic_selection
	;

constant
	: I_CONSTANT		/* includes character_constant */
	| F_CONSTANT
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER
	;

string
	: STRING_LITERAL
	| FUNC_NAME
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
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	| ALIGNOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

declaration
	: declaration_specifiers ';'
		{fprintf(pl_file, "declaration([%s])\n", $1);
		 free($1);
		}
	| declaration_specifiers init_declarator_list ';' 
	  {if (typedef_flag == 1) {	//we were processing typedef declarations
	     typedef_flag = 0;
	   }
	   fprintf(pl_file, "declaration([%s], [%s])\n", $1, $2);
	   free($1);
	   free($2);
	  }
	| static_assert_declaration
		{fprintf(pl_file, "static_assert_declaration\n");
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
	| storage_class_specifier
		{size_t const size = strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 strcpy_s($$, size, $1);
		 free($1);
		}
	| type_specifier declaration_specifiers
		{size_t const size = strlen(", ") + strlen($1) + strlen($2) + 1;
		 $$ = (char*)malloc(size);
		 sprintf_s($$, size, "%s, %s", $1, $2);
		 free($1);
		 free($2);
		}
	| type_specifier
		{size_t const size = strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 strcpy_s($$, size, $1);
		 free($1);
		}
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
	: init_declarator
		{size_t const size = strlen($1) + 1;
		 $$ = (char*)malloc(size);
	     strcpy_s($$, size, $1);
         free($1);
		}
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
	  }
	| declarator
	  {if (typedef_flag == 1) {// we are parsing one typedef declaration
		 add_typedef_name($1);
	   }
	   size_t const size = strlen($1) + 1;
	   $$ = (char*)malloc(size);
	   strcpy_s($$, size, $1);
	   free($1);
	  }
	;

storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
		{simple_str_lit_copy(&$$, "typedef");
         typedef_flag = 1;
	    }
| EXTERN{ simple_str_lit_copy(&$$, "extern"); }
| STATIC{ simple_str_lit_copy(&$$, "static"); }
| THREAD_LOCAL{ simple_str_lit_copy(&$$, "thread_local"); }
| AUTO{ simple_str_lit_copy(&$$, "auto"); }
| REGISTER{ simple_str_lit_copy(&$$, "register"); }
	;

type_specifier
	: VOID{ simple_str_lit_copy(&$$, "void"); }
	| CHAR
{ simple_str_lit_copy(&$$, "char"); }
| SHORT{ simple_str_lit_copy(&$$, "short"); }
| INT
 { simple_str_lit_copy(&$$, "int"); }
| LONG{ simple_str_lit_copy(&$$, "long"); }
| FLOAT{ simple_str_lit_copy(&$$, "float"); }
| DOUBLE{ simple_str_lit_copy(&$$, "double"); }
| SIGNED{ simple_str_lit_copy(&$$, "signed"); }
| UNSIGNED{ simple_str_lit_copy(&$$, "unsigned"); }
| BOOL{ simple_str_lit_copy(&$$, "bool"); }
| COMPLEX{ simple_str_lit_copy(&$$, "complex"); }
| IMAGINARY{ simple_str_lit_copy(&$$, "imaginary"); } 	/* non-mandated extension */
| atomic_type_specifier{ simple_str_lit_copy(&$$, "atomic_type_specifier"); }
| struct_or_union_specifier{ simple_str_lit_copy(&$$, "struct_or_union_specifier"); }
| enum_specifier{ simple_str_lit_copy(&$$, "enum_specifier"); }
	| TYPEDEF_NAME				/* after it has been defined as such */
		{size_t const size = strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 strcpy_s($$, size, $1);
		 free($1);
		};
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: ':' constant_expression
	| declarator ':' constant_expression
	| declarator
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression
	| enumeration_constant
	;

atomic_type_specifier		// new in C11 for atomic operation: used in concurrency
	: ATOMIC '(' type_name ')'
	;

type_qualifier
	: CONST
		{simple_str_lit_copy(&$$, "const");
		}
	| RESTRICT
		{simple_str_lit_copy(&$$, "restrict");
		}
	| VOLATILE
		{simple_str_lit_copy(&$$, "volatile");
		}
	| ATOMIC
		{ simple_str_lit_copy(&$$, "atomic");
		}
	;

function_specifier
	: INLINE
	| NORETURN
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
	  {size_t const size = strlen($1) + 1;
       $$ = (char*)malloc(size);
       strcpy_s($$, size, $1);
       free($1);
      }
	;

direct_declarator
	: IDENTIFIER
		{size_t const size = strlen($1) + 1;
	     $$ = (char*)malloc(size);
		 strcpy_s($$, size, $1);
	     free($1);
		}
	| '(' declarator ')'			{simple_str_lit_copy(&$$, "D1");}
	| direct_declarator '[' ']'		{simple_str_lit_copy(&$$, "D2"); }
	| direct_declarator '[' '*' ']'	{simple_str_lit_copy(&$$, "D3"); }
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']' {simple_str_lit_copy(&$$, "D4"); }
	| direct_declarator '[' STATIC assignment_expression ']'{simple_str_lit_copy(&$$, "D5"); }
	| direct_declarator '[' type_qualifier_list '*' ']'{simple_str_lit_copy(&$$, "D6"); }
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'{simple_str_lit_copy(&$$, "D7"); }
	| direct_declarator '[' type_qualifier_list assignment_expression ']'{simple_str_lit_copy(&$$, "D8"); }
	| direct_declarator '[' type_qualifier_list ']'{simple_str_lit_copy(&$$, "D9"); }
	| direct_declarator '[' assignment_expression ']'{simple_str_lit_copy(&$$, "D10"); }
	| direct_declarator '(' parameter_type_list ')'{simple_str_lit_copy(&$$, "D11"); }
	| direct_declarator '(' ')'{simple_str_lit_copy(&$$, "D12"); }
	| direct_declarator '(' identifier_list ')'{simple_str_lit_copy(&$$, "D13"); }
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
		{simple_str_lit_copy(&$$, "pointer"); 
		}
	;

type_qualifier_list
	: type_qualifier
		{size_t const size = strlen($1) + 1;
		 $$ = (char*)malloc(size);
		 strcpy_s($$, size, $1);
		 free($1);
		}
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
	| parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
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
	| '{' initializer_list ',' '}'
	| assignment_expression
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
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
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{'  block_item_list '}'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement
	| IF '(' expression ')' statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

%%
int main(int argc, char *argv[]) {			//argc is the total number of strings in the argv array
	char C_file_path[_MAX_PATH];				//directory where the C and .i files are
	char filename_no_ext[_MAX_PATH];
	char i_file_uri[_MAX_PATH];
	FILE *i_file;

	strcpy_s(C_file_path, 3, ".\\");				//default path for input file is current directory, overwrite with -p on command line
	for (int i = 1; i <= argc - 1; i++) {	//processing command line arguments
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'h':
				printf("Usage: .\\sikraken_parser [OPTION]... [FILE]\nParse a C file to Prolog terms.\n\n-h\t Display help information\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\LilyParser -p\".\" get_sign \n\t.\\LilyParser get_sign \n\t.\\LilyParser -p\"C:/Parser/\" sign \n");
				exit(0);
			case 'p':	//path to the .i pre-processed input C file
				if (_access(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					exit(1);
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
		exit(EXIT_FAILURE);
	}
	yyin = i_file;	//set the input to the parser
	sprintf_s(pl_file_uri, _MAX_PATH, "%s%s.pl", C_file_path, filename_no_ext);
	if (fopen_s(&pl_file, pl_file_uri, "w") != 0) {
		fprintf(stderr, ".pl file could created for write at: %s\n", pl_file_uri);
		exit(EXIT_FAILURE);
	}
	if (yyparse() != 0) {
		fprintf(stderr, "Parsing failed.\n");
		exit(EXIT_FAILURE);
	}
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
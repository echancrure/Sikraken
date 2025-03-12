/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "C_grammar.y"

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
#include "parser.h"
#include "utils.c"
#include "handle_typedefs.c"
#include "linkedList.c"

typedef struct{
	bool isFalse;
	bool breakOn;
	bool switchOn;
	bool nestedDoWhile;
	int  doWhile;

} ParserContext;

extern Node *top;
extern void push(bool isFalse); //This will push the nodes onto the stack.
extern void populate_dot_file(FILE *dot_file);
extern void connectDoWhile(int doWhile);
extern void pop(int branch_num);
extern void join_nodes();
extern int 	stack_count;
extern void terminate_nodes();
extern void attach_start(FILE *dot_file);

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;

#define MAX_PATH 256
#define MAX_BRANCH_STR 9		//maximum length of the string encoding the number of branches (max is "999999999" i.e. 1 billion - 1)

int debugMode = 0;				//flag to indicate if we are in debug mode set by -d command line switch
int dataModel = 32;				//flag to indicate data model used in the C code under analysis; set by -m32 or -m64 on the command line; default is 32
long int TARGET_LONG_MAX = 2147483647L; //the default LONG_MAX for the code under test if dataModel = 32
FILE* pl_file;					//the file of containing the Prolog predicated after parsing the target C file
char i_file_uri[MAX_PATH];
FILE *i_file;
char dot_file_uri[3 * MAX_PATH];
FILE* dot_file;
char pl_file_uri[MAX_PATH];		//the full path to the Pl_file
int branch_nb = 1;				//unique id for branches created
//start: ugly, breaking parsing spirit, flags and temporary variables
int typedef_flag = 0; 			//indicates that we are within a typedef declaration
int in_tag_declaration = 0;		//indicates to the lexer that we are in the tag namespace (for struct, union and enum tags) and that identifier should not be checked for typedef
int in_member_namespace = 0;	//indicates to the lexer that we are in the member namespace (for members of structs and unions) and that identifier should not be checked for typedef
int in_ordinary_id_declaration = 0;
int in_label_namespace = 0;

int handled_function_paramaters = 0;
int current_scope = 0;

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements
void yyerror(ParserContext *ctx, const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);

void add_to_cfg(int node_num,char current_node[], char false_path[], char true_path[]); // This method will add nodes to the control flow graphs in dot format.
char *previous_cfg_node = NULL;

#line 154 "C_grammar.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "C_grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPEDEF_NAME = 4,               /* TYPEDEF_NAME  */
  YYSYMBOL_I_CONSTANT = 5,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 6,                 /* F_CONSTANT  */
  YYSYMBOL_ENUMERATION_CONSTANT = 7,       /* ENUMERATION_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 8,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 9,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 10,                    /* SIZEOF  */
  YYSYMBOL_PTR_OP = 11,                    /* PTR_OP  */
  YYSYMBOL_INC_OP = 12,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 13,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 14,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 15,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 16,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 17,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 18,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 19,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 20,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 21,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 22,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 23,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 24,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 25,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 26,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 27,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 28,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 29,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 30,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 31,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF = 32,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 33,                    /* EXTERN  */
  YYSYMBOL_STATIC = 34,                    /* STATIC  */
  YYSYMBOL_AUTO = 35,                      /* AUTO  */
  YYSYMBOL_REGISTER = 36,                  /* REGISTER  */
  YYSYMBOL_INLINE = 37,                    /* INLINE  */
  YYSYMBOL_CONST = 38,                     /* CONST  */
  YYSYMBOL_RESTRICT = 39,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 40,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_CHAR = 42,                      /* CHAR  */
  YYSYMBOL_SHORT = 43,                     /* SHORT  */
  YYSYMBOL_INT = 44,                       /* INT  */
  YYSYMBOL_LONG = 45,                      /* LONG  */
  YYSYMBOL_SIGNED = 46,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 47,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 48,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 49,                    /* DOUBLE  */
  YYSYMBOL_VOID = 50,                      /* VOID  */
  YYSYMBOL_COMPLEX = 51,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 52,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 53,                    /* STRUCT  */
  YYSYMBOL_UNION = 54,                     /* UNION  */
  YYSYMBOL_ENUM = 55,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 56,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 57,                      /* CASE  */
  YYSYMBOL_DEFAULT = 58,                   /* DEFAULT  */
  YYSYMBOL_IF = 59,                        /* IF  */
  YYSYMBOL_ELSE = 60,                      /* ELSE  */
  YYSYMBOL_SWITCH = 61,                    /* SWITCH  */
  YYSYMBOL_WHILE = 62,                     /* WHILE  */
  YYSYMBOL_DO = 63,                        /* DO  */
  YYSYMBOL_FOR = 64,                       /* FOR  */
  YYSYMBOL_GOTO = 65,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 66,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 67,                     /* BREAK  */
  YYSYMBOL_RETURN = 68,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 69,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 70,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC_SPECIFIER = 71,          /* ATOMIC_SPECIFIER  */
  YYSYMBOL_ATOMIC = 72,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 73,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 74,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 75,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 76,              /* THREAD_LOCAL  */
  YYSYMBOL_INT128 = 77,                    /* INT128  */
  YYSYMBOL_FLOAT128 = 78,                  /* FLOAT128  */
  YYSYMBOL_VA_LIST = 79,                   /* VA_LIST  */
  YYSYMBOL_LOWER_THAN_ELSE = 80,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_81_ = 81,                       /* '('  */
  YYSYMBOL_82_ = 82,                       /* ')'  */
  YYSYMBOL_83_ = 83,                       /* ','  */
  YYSYMBOL_84_ = 84,                       /* ':'  */
  YYSYMBOL_85_ = 85,                       /* '['  */
  YYSYMBOL_86_ = 86,                       /* ']'  */
  YYSYMBOL_87_ = 87,                       /* '.'  */
  YYSYMBOL_88_ = 88,                       /* '{'  */
  YYSYMBOL_89_ = 89,                       /* '}'  */
  YYSYMBOL_90_ = 90,                       /* '&'  */
  YYSYMBOL_91_ = 91,                       /* '*'  */
  YYSYMBOL_92_ = 92,                       /* '+'  */
  YYSYMBOL_93_ = 93,                       /* '-'  */
  YYSYMBOL_94_ = 94,                       /* '~'  */
  YYSYMBOL_95_ = 95,                       /* '!'  */
  YYSYMBOL_96_ = 96,                       /* '/'  */
  YYSYMBOL_97_ = 97,                       /* '%'  */
  YYSYMBOL_98_ = 98,                       /* '<'  */
  YYSYMBOL_99_ = 99,                       /* '>'  */
  YYSYMBOL_100_ = 100,                     /* '^'  */
  YYSYMBOL_101_ = 101,                     /* '|'  */
  YYSYMBOL_102_ = 102,                     /* '?'  */
  YYSYMBOL_103_ = 103,                     /* '='  */
  YYSYMBOL_104_ = 104,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 105,                 /* $accept  */
  YYSYMBOL_primary_expression = 106,       /* primary_expression  */
  YYSYMBOL_107_1 = 107,                    /* $@1  */
  YYSYMBOL_constant = 108,                 /* constant  */
  YYSYMBOL_enumeration_constant = 109,     /* enumeration_constant  */
  YYSYMBOL_string = 110,                   /* string  */
  YYSYMBOL_generic_selection = 111,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 112,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 113,      /* generic_association  */
  YYSYMBOL_114_2 = 114,                    /* $@2  */
  YYSYMBOL_postfix_expression = 115,       /* postfix_expression  */
  YYSYMBOL_116_3 = 116,                    /* $@3  */
  YYSYMBOL_117_4 = 117,                    /* $@4  */
  YYSYMBOL_comma_opt = 118,                /* comma_opt  */
  YYSYMBOL_argument_expression_list = 119, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 120,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 121,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 122,           /* unary_operator  */
  YYSYMBOL_cast_expression = 123,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 124, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 125, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 126,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 127,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 128,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 129,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 130,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 131, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 132,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 133,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 134,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 135,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 136,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 137,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 138,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 139,   /* conditional_expression  */
  YYSYMBOL_140_5 = 140,                    /* $@5  */
  YYSYMBOL_141_6 = 141,                    /* $@6  */
  YYSYMBOL_assignment_expression = 142,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 143,      /* assignment_operator  */
  YYSYMBOL_expression = 144,               /* expression  */
  YYSYMBOL_constant_expression = 145,      /* constant_expression  */
  YYSYMBOL_declaration = 146,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 147,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 148,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 149,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 150,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 151,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 152, /* struct_or_union_specifier  */
  YYSYMBOL_153_7 = 153,                    /* $@7  */
  YYSYMBOL_154_8 = 154,                    /* $@8  */
  YYSYMBOL_struct_or_union = 155,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 156,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 157,       /* struct_declaration  */
  YYSYMBOL_158_9 = 158,                    /* $@9  */
  YYSYMBOL_specifier_qualifier_list = 159, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 160,   /* struct_declarator_list  */
  YYSYMBOL_161_10 = 161,                   /* $@10  */
  YYSYMBOL_162_11 = 162,                   /* $@11  */
  YYSYMBOL_struct_declarator = 163,        /* struct_declarator  */
  YYSYMBOL_164_12 = 164,                   /* $@12  */
  YYSYMBOL_165_13 = 165,                   /* $@13  */
  YYSYMBOL_enum_specifier = 166,           /* enum_specifier  */
  YYSYMBOL_167_14 = 167,                   /* $@14  */
  YYSYMBOL_168_15 = 168,                   /* $@15  */
  YYSYMBOL_169_16 = 169,                   /* $@16  */
  YYSYMBOL_enum_specifier_rest = 170,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 171,          /* enumerator_list  */
  YYSYMBOL_enumerator = 172,               /* enumerator  */
  YYSYMBOL_173_17 = 173,                   /* $@17  */
  YYSYMBOL_atomic_type_specifier = 174,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 175,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 176,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 177,      /* alignment_specifier  */
  YYSYMBOL_declarator = 178,               /* declarator  */
  YYSYMBOL_direct_declarator = 179,        /* direct_declarator  */
  YYSYMBOL_180_18 = 180,                   /* $@18  */
  YYSYMBOL_rest_function_definition = 181, /* rest_function_definition  */
  YYSYMBOL_pointer = 182,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 183,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 184,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 185,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 186,    /* parameter_declaration  */
  YYSYMBOL_old_style_parameter_list = 187, /* old_style_parameter_list  */
  YYSYMBOL_type_name = 188,                /* type_name  */
  YYSYMBOL_abstract_declarator_opt = 189,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 190,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 191, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 192,              /* initializer  */
  YYSYMBOL_initializer_list = 193,         /* initializer_list  */
  YYSYMBOL_designation = 194,              /* designation  */
  YYSYMBOL_designator_list = 195,          /* designator_list  */
  YYSYMBOL_designator = 196,               /* designator  */
  YYSYMBOL_197_19 = 197,                   /* $@19  */
  YYSYMBOL_static_assert_declaration = 198, /* static_assert_declaration  */
  YYSYMBOL_statement = 199,                /* statement  */
  YYSYMBOL_200_20 = 200,                   /* $@20  */
  YYSYMBOL_labeled_statement = 201,        /* labeled_statement  */
  YYSYMBOL_202_21 = 202,                   /* $@21  */
  YYSYMBOL_compound_statement = 203,       /* compound_statement  */
  YYSYMBOL_block_item_list = 204,          /* block_item_list  */
  YYSYMBOL_205_22 = 205,                   /* $@22  */
  YYSYMBOL_block_item = 206,               /* block_item  */
  YYSYMBOL_expression_statement = 207,     /* expression_statement  */
  YYSYMBOL_selection_statement = 208,      /* selection_statement  */
  YYSYMBOL_209_23 = 209,                   /* $@23  */
  YYSYMBOL_210_24 = 210,                   /* $@24  */
  YYSYMBOL_else_opt = 211,                 /* else_opt  */
  YYSYMBOL_212_25 = 212,                   /* $@25  */
  YYSYMBOL_iteration_statement = 213,      /* iteration_statement  */
  YYSYMBOL_214_26 = 214,                   /* $@26  */
  YYSYMBOL_215_27 = 215,                   /* $@27  */
  YYSYMBOL_216_28 = 216,                   /* $@28  */
  YYSYMBOL_217_29 = 217,                   /* $@29  */
  YYSYMBOL_for_stmt_type = 218,            /* for_stmt_type  */
  YYSYMBOL_expression_opt = 219,           /* expression_opt  */
  YYSYMBOL_jump_statement = 220,           /* jump_statement  */
  YYSYMBOL_translation_unit = 221,         /* translation_unit  */
  YYSYMBOL_222_30 = 222,                   /* $@30  */
  YYSYMBOL_external_declaration = 223,     /* external_declaration  */
  YYSYMBOL_function_definition = 224,      /* function_definition  */
  YYSYMBOL_225_31 = 225,                   /* $@31  */
  YYSYMBOL_declaration_list_opt = 226,     /* declaration_list_opt  */
  YYSYMBOL_old_style_declaration_list = 227 /* old_style_declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  123
/* YYNRULES -- Number of rules.  */
#define YYNRULES  324
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  517

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   335


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    95,     2,     2,     2,    97,    90,     2,
      81,    82,    91,    92,    83,    93,    87,    96,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,   104,
      98,   103,    99,   102,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    85,     2,    86,   100,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,   101,    89,    94,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   155,   155,   159,   160,   161,   161,   168,   174,   178,
     179,   180,   184,   188,   189,   193,   197,   198,   202,   203,
     203,   214,   215,   222,   228,   235,   235,   243,   243,   251,
     257,   263,   280,   281,   286,   287,   297,   298,   305,   312,
     318,   324,   333,   334,   338,   339,   340,   341,   342,   343,
     347,   348,   358,   359,   370,   371,   372,   376,   377,   388,
     389,   393,   394,   405,   406,   410,   411,   422,   423,   424,
     425,   430,   431,   442,   443,   447,   448,   458,   459,   469,
     470,   480,   481,   491,   492,   502,   503,   511,   503,   525,
     526,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   551,   552,   562,   567,   575,   587,   598,   606,
     608,   616,   618,   626,   627,   631,   635,   639,   646,   650,
     661,   669,   679,   684,   685,   686,   687,   688,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   706,   707,   712,   713,   714,   718,   718,   725,
     725,   735,   748,   752,   759,   760,   770,   777,   777,   785,
     789,   796,   797,   804,   808,   808,   809,   809,   819,   819,
     825,   825,   833,   841,   841,   855,   855,   855,   867,   868,
     870,   879,   880,   891,   891,   898,   902,   906,   907,   908,
     909,   913,   914,   918,   919,   924,   933,   937,   960,   963,
     970,   975,   980,   985,   990,   995,  1000,  1005,  1013,  1013,
    1027,  1028,  1029,  1033,  1040,  1046,  1052,  1057,  1058,  1068,
    1074,  1083,  1084,  1094,  1102,  1109,  1118,  1119,  1123,  1137,
    1138,  1142,  1143,  1144,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1172,  1178,  1184,  1185,  1190,
    1197,  1198,  1206,  1216,  1225,  1226,  1236,  1242,  1242,  1252,
    1262,  1263,  1263,  1267,  1268,  1269,  1270,  1274,  1282,  1289,
    1289,  1313,  1322,  1323,  1332,  1333,  1333,  1343,  1344,  1348,
    1349,  1358,  1358,  1377,  1377,  1398,  1399,  1399,  1411,  1411,
    1434,  1434,  1434,  1455,  1455,  1482,  1484,  1489,  1490,  1493,
    1500,  1501,  1502,  1503,  1513,  1514,  1514,  1518,  1524,  1536,
    1536,  1550,  1551,  1555,  1556
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPEDEF_NAME", "I_CONSTANT", "F_CONSTANT", "ENUMERATION_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE",
  "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID", "COMPLEX", "IMAGINARY",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "ALIGNAS", "ALIGNOF", "ATOMIC_SPECIFIER", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "INT128", "FLOAT128",
  "VA_LIST", "LOWER_THAN_ELSE", "'('", "')'", "','", "':'", "'['", "']'",
  "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "primary_expression", "$@1", "constant", "enumeration_constant",
  "string", "generic_selection", "generic_assoc_list",
  "generic_association", "$@2", "postfix_expression", "$@3", "$@4",
  "comma_opt", "argument_expression_list", "unary_expression",
  "unary_inc_dec", "unary_operator", "cast_expression",
  "multiplicative_expression", "multiplicative_expression_op",
  "additive_expression", "additive_expression_op", "shift_expression",
  "shift_expression_op", "relational_expression",
  "relational_expression_operator", "equality_expression",
  "equality_expression_op", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression", "$@5", "$@6",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "$@7", "$@8",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "$@9", "specifier_qualifier_list", "struct_declarator_list", "$@10",
  "$@11", "struct_declarator", "$@12", "$@13", "enum_specifier", "$@14",
  "$@15", "$@16", "enum_specifier_rest", "enumerator_list", "enumerator",
  "$@17", "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "$@18",
  "rest_function_definition", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "old_style_parameter_list", "type_name", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "$@19", "static_assert_declaration", "statement", "$@20",
  "labeled_statement", "$@21", "compound_statement", "block_item_list",
  "$@22", "block_item", "expression_statement", "selection_statement",
  "$@23", "$@24", "else_opt", "$@25", "iteration_statement", "$@26",
  "$@27", "$@28", "$@29", "for_stmt_type", "expression_opt",
  "jump_statement", "translation_unit", "$@30", "external_declaration",
  "function_definition", "$@31", "declaration_list_opt",
  "old_style_declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-430)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-322)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2033,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,  -430,    37,   -16,  2294,  -430,  -430,
      -4,  -430,  -430,  -430,  -430,  -430,    26,  2138,  2138,  -430,
      34,  -430,  -430,  2138,  2138,  2138,  -430,    43,  -430,  -430,
      -8,    42,   902,  2294,   -39,  2294,     6,  1610,  -430,    38,
     132,  -430,   -35,  -430,   825,     4,    60,  -430,  -430,    16,
    -430,  -430,  -430,  -430,  -430,  2033,    89,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,  1625,  -430,  -430,    47,    62,   902,
    -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
     167,  -430,  1640,  1610,  -430,    90,    63,   176,    70,   179,
      72,    52,    92,   144,    10,  -430,   123,   138,  -430,  1764,
     995,   104,  -430,  -430,   111,  -430,  -430,   139,   142,  -430,
    -430,   132,    38,  -430,  1485,  -430,    26,  -430,  2033,  1010,
     145,     4,   154,  2190,  -430,  -430,   129,   152,  -430,   155,
     902,  -430,  2294,  1610,   158,   344,  -430,  -430,   117,   165,
    -430,  -430,  1501,  1610,   162,   240,   902,  -430,  -430,  -430,
    -430,  -430,  1610,  -430,  -430,  1610,  -430,  -430,  1610,  -430,
    -430,  -430,  -430,  1610,  -430,  -430,  1610,  1610,  1610,  1610,
    1610,  1610,   151,  -430,  -430,  -430,    33,   174,   175,  -430,
     178,  1319,  -430,   177,   180,  1103,   111,  1928,  1118,   253,
    -430,  -430,  -430,  -430,   159,  1334,  -430,  -430,   158,  -430,
    1319,  -430,   182,   186,  1211,  1981,  2190,  1818,  -430,   160,
    -430,   170,    89,   188,    89,  -430,   183,   193,   195,   546,
     199,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  1610,  -430,  1610,  1594,  -430,   125,  -430,   -48,
     279,   281,   203,  -430,    90,    63,   176,    70,   179,    72,
      52,    92,   144,  1610,  1704,  -430,    61,  -430,  -430,  2085,
    -430,   200,  1319,  -430,  -430,  1610,  -430,   201,  -430,   206,
    1319,  -430,   204,   207,  1226,   212,  1610,  -430,  -430,   -17,
    1485,   -46,  -430,   202,  -430,   210,  1319,  -430,  -430,  1610,
    -430,   211,   213,  -430,   218,  -430,   220,  1870,  -430,  -430,
    -430,  -430,  1610,  -430,  -430,    19,   222,  -430,  2242,   217,
     224,  1610,   229,   225,   233,   234,  -430,   235,   316,   216,
     219,   747,  -430,  -430,   -28,  -430,  -430,   158,  -430,   639,
    -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  1469,  -430,
    -430,  1610,  -430,  -430,  -430,   222,   127,  -430,  -430,  -430,
     236,   239,  -430,  -430,   241,  1319,  -430,  -430,  1610,  -430,
     242,   226,   245,  1360,  -430,  -430,  -430,  -430,   323,  -430,
     246,   247,  -430,  -430,  -430,   331,  -430,   -25,    38,  -430,
      12,  -430,  -430,   130,  -430,   252,   426,   426,  -430,   426,
    1610,  1610,  1610,   426,   732,   238,  -430,  -430,  -430,    71,
    -430,  -430,  -430,  -430,   254,  -430,  -430,  -430,  -430,  -430,
     257,   258,  -430,  -430,  -430,  -430,  -430,  1485,  -430,  -430,
    -430,  -430,    38,  -430,  -430,   261,   262,  -430,   263,  -430,
    2242,  1610,   224,  -430,  -430,   264,  -430,   133,   136,   147,
     288,  1610,  1610,   270,  -430,  -430,  -430,  1453,   265,  1610,
    -430,  -430,  -430,  -430,  1610,   269,  1610,  -430,  -430,   426,
    -430,  -430,  -430,   274,   273,   255,   256,  -430,  -430,  -430,
    -430,  -430,  1610,  -430,  -430,   426,   426,   426,  1610,  1610,
    1610,   426,  -430,   298,  -430,  -430,   157,  -430,  -430,  -430,
    -430,  -430,  -430,   426,   259,  -430,  -430
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   143,   122,   123,   124,   126,   127,   191,   187,   188,
     189,   137,   129,   130,   131,   132,   135,   136,   133,   134,
     128,   138,   139,   152,   153,   173,     0,     0,   190,   192,
       0,   125,   144,   145,   146,   318,     0,   109,   111,   141,
       0,   142,   140,   113,   115,   117,   107,   315,   314,   317,
       0,     0,     0,   161,   229,   163,     0,     0,   197,     0,
     216,   105,     0,   118,   121,   196,     0,   108,   110,   151,
     147,   112,   114,   116,     1,     0,     0,   176,     2,     9,
      10,    11,    13,    14,     0,    42,    43,     0,     0,     5,
      44,    45,    46,    47,    48,    49,    21,     3,     4,     8,
      36,    50,     0,     0,    52,    57,    61,    65,    71,    75,
      77,    79,    81,    83,    85,   104,     0,     0,   160,     0,
       0,   232,   228,   230,   233,   162,   186,     0,     0,   217,
     215,   214,     0,   106,     0,   323,     0,   319,   322,     0,
       0,   195,     0,     0,   316,    12,   185,    32,   181,   178,
       5,    39,     0,     0,     0,    50,    89,   102,     0,     0,
      29,    30,     0,     0,     0,     0,     5,    37,    38,    54,
      55,    56,     0,    59,    60,     0,    63,    64,     0,    69,
      70,    67,    68,     0,    73,    74,     0,     0,     0,     0,
       0,     0,     0,   194,   193,   251,   225,     0,   220,   221,
       0,     0,   235,    45,     0,     0,   231,     0,     0,     0,
     198,   218,   213,   119,   121,   267,   257,   120,     0,   324,
       0,   199,    45,     0,     0,   210,     0,     0,   154,   157,
     159,     0,    33,     0,     0,   177,     0,     0,     0,   271,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    91,     0,     7,     0,     0,    23,     0,    34,     0,
       0,     0,     0,    53,    58,    62,    66,    72,    76,    78,
      80,    82,    84,     0,     0,   223,   232,   224,   252,     0,
     234,     0,     0,   236,   242,     0,   241,     0,   253,     0,
       0,   243,    45,     0,     0,     0,     0,   258,   260,     0,
       0,   267,   264,     0,   320,     0,     0,   200,   207,     0,
     206,    45,     0,   226,     0,   211,   212,     0,   148,   155,
     156,   164,     0,   182,   174,     0,    40,    41,     0,     2,
     143,     0,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,   282,   289,     0,   287,   288,     0,   270,   271,
     284,   273,   274,   275,   276,     6,    90,   103,   267,    51,
      24,     0,    22,    26,    28,     0,     0,   219,   222,   238,
       0,     0,   240,   254,     0,     0,   244,   250,     0,   249,
       0,     0,     0,   267,   255,   259,   263,   265,     0,   202,
       0,     0,   203,   205,   209,     0,   150,     0,   168,   184,
       0,   179,    19,     0,    16,     0,   271,   271,   279,   271,
       0,     0,     0,   271,     0,     0,   310,   311,   312,     0,
     290,   272,   283,   285,    32,    35,    87,   237,   239,   246,
       0,     0,   247,   269,   266,   256,   262,     0,   268,   201,
     204,   227,   168,   158,   165,     0,   172,   180,     0,    15,
       0,     0,     0,   277,   278,     0,   281,     0,     0,     0,
       0,   307,   307,     0,   309,   313,   286,    33,     0,     0,
     245,   248,   261,   166,     0,     0,     0,    17,    18,   271,
     291,   293,   298,     0,   308,     0,     0,   303,    31,    88,
     167,   169,     0,    20,   280,   271,   271,   271,     0,   307,
     307,   271,   171,   295,   294,   299,     0,   306,   305,   304,
     296,   292,   301,   271,     0,   297,   302
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,   -89,  -430,
    -430,  -430,  -430,   -60,  -430,   -52,  -430,  -430,   -90,   187,
    -430,   205,  -430,   194,  -430,   192,  -430,   197,  -430,   198,
     191,   208,   190,  -430,   -51,  -430,  -430,    97,  -430,   -72,
     -55,   -57,    30,  -430,   260,  -430,     7,  -430,  -430,  -430,
    -430,   168,  -201,  -430,   -43,  -430,  -430,  -430,   -54,  -430,
    -430,  -430,  -430,  -430,  -430,  -430,   161,  -223,  -430,  -430,
       1,  -430,  -430,   -33,   -62,  -430,  -430,   -36,   -95,   -31,
    -430,   106,  -430,    -5,  -430,   -38,  -110,  -126,    35,  -334,
    -430,    95,  -430,  -129,  -386,  -430,  -430,  -430,  -199,  -430,
    -430,    50,   -14,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,  -429,  -430,  -430,  -430,   326,  -430,
    -430,  -430,  -430
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    96,   154,    97,   146,    98,    99,   403,   404,   448,
     100,   164,   165,   233,   257,   155,   102,   103,   104,   105,
     172,   106,   175,   107,   178,   108,   183,   109,   186,   110,
     111,   112,   113,   114,   156,   192,   469,   157,   252,   344,
     116,    35,   136,    62,    63,    37,    38,    39,   143,   142,
      40,   227,   228,   321,    54,   397,   398,   490,   444,   445,
     475,    41,    50,    51,   149,   235,   147,   148,   231,    42,
      43,    44,    45,   128,    65,   140,   314,    66,   131,   197,
     198,   199,   316,   405,   122,   200,   124,   298,   299,   300,
     301,   302,   303,    46,   346,   347,   348,   455,   240,   349,
     466,   350,   351,   352,   495,   496,   511,   513,   353,   497,
     413,   514,   501,   463,   485,   354,    47,    75,    48,    49,
     218,   137,   138
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   115,   127,    64,   141,   101,   115,   135,   217,   323,
     118,   206,   125,   168,   230,   145,   123,   158,   121,   304,
     453,   454,    56,   456,   130,   205,   319,   460,    55,    58,
      36,   191,   151,   486,    53,   254,    58,    69,   362,   296,
    -175,    58,   119,    74,   224,    77,   120,   117,   132,   437,
     167,   101,    60,    55,    55,   254,    55,   386,   442,    53,
      53,   129,    53,    58,    58,    52,   383,    67,    68,   133,
     507,   508,   384,    71,    72,    73,   420,    57,   158,   443,
      76,   219,   263,   121,   159,  -208,   179,   180,   126,   139,
      55,   259,   145,   494,   158,   212,    53,   230,   230,   214,
     229,   447,   400,   214,  -149,    36,   282,    59,   401,   503,
     504,   505,   -86,   294,   274,   509,   319,    60,   120,    59,
     101,   129,    70,   101,    60,   306,   101,   515,   152,    60,
      61,   101,   211,   437,   101,   101,   101,   101,   101,   101,
     129,    59,   274,   153,    55,   236,   120,   237,   421,   196,
      53,    55,   188,    55,   254,   173,   174,    53,   277,    53,
     276,   262,   187,   275,   190,   359,   206,    55,   181,   182,
       8,     9,    10,    53,   385,   465,   289,   323,   -27,   160,
     161,   169,   345,   229,   229,   119,   170,   171,   230,   120,
     176,   177,   207,   189,   315,   375,   208,   184,   185,   253,
     254,   366,   129,   101,    28,   193,   211,   360,   361,   129,
     254,   426,   449,   450,   141,   480,   254,   204,   481,   254,
     194,   129,   209,    60,   210,   211,   225,    55,    55,   482,
     254,   216,  -183,    53,    53,   232,   223,   196,   276,   512,
     254,   382,   226,   234,   101,   115,   239,   255,   162,   260,
     238,   261,   163,   273,   -25,   196,   278,   436,   279,   258,
     280,   295,   134,   283,   320,   326,   284,   399,   307,   419,
     101,   115,   308,   322,   229,   327,   408,   324,   328,   101,
     115,   355,   363,   211,   364,   365,   369,   372,   373,   388,
     376,   129,   345,   377,   381,   211,   389,   392,   281,   393,
     394,   406,   287,   395,   196,   293,   410,   211,   407,   196,
     358,   472,   216,   409,   411,   412,   414,   305,    55,   415,
     416,   312,   427,   417,    53,   428,   438,   429,   432,    55,
     433,   434,   439,   440,   441,    53,   451,   467,   457,   458,
     459,   436,   464,   470,   471,   474,  -170,   476,   479,   356,
     483,   357,   487,   492,   488,   498,   254,   461,   510,   499,
     500,   477,   264,   516,   468,   446,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   211,   266,   267,   370,
     270,   272,   371,   265,   268,   368,   269,   374,   473,   484,
     484,   380,   213,   424,   317,   325,   387,   216,   271,   423,
     462,   144,     0,   390,     0,     0,   391,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,   101,   489,   491,
       0,     0,   101,   115,     0,     0,   506,   484,   484,   329,
     452,    79,    80,    81,    82,    83,    84,   502,    85,    86,
     101,   115,     0,     0,     0,     0,     0,   251,     0,     0,
       0,    55,     0,     0,     0,   216,     0,    53,   425,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,     0,     0,   431,     0,     0,     0,     0,
     216,     0,     0,   331,   332,   333,     0,   334,   335,   336,
     337,   338,   339,   340,   341,     0,    87,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   478,   329,
     330,    79,    80,    81,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,   216,     0,     0,     0,     0,     0,
       0,     0,     0,   493,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,   331,   332,   333,     0,   334,   335,   336,
     337,   338,   339,   340,   341,    26,    87,    27,    28,    88,
      29,    30,    31,    32,    33,    34,     0,    89,     0,     0,
       0,     0,     0,     0,     0,   342,    90,    91,    92,    93,
      94,    95,   329,   330,    79,    80,    81,    82,    83,    84,
     343,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,   331,   332,   333,     0,
     334,   335,   336,   337,   338,   339,   340,   341,    26,    87,
      27,    28,    88,    29,    30,    31,    32,    33,    34,     0,
      89,     0,     0,     0,     0,     0,     0,     0,   422,    90,
      91,    92,    93,    94,    95,    78,     1,    79,    80,    81,
      82,    83,    84,   343,    85,    86,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    87,    27,    28,    88,    29,    30,    31,    32,
      33,    34,     0,    89,     0,     0,     0,    87,     0,     0,
      88,     0,    90,    91,    92,    93,    94,    95,    89,     1,
       0,     0,     0,     0,     0,     0,   343,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,   418,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
      30,    31,    32,    33,    34,    78,     1,    79,    80,    81,
      82,    83,    84,  -321,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    27,    28,    88,     0,     0,     0,    32,
      33,    34,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    28,    88,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
      87,   202,    28,    88,     0,    90,   203,    92,    93,    94,
      95,    89,     0,     0,     0,     0,   221,     0,     0,     0,
      90,   222,    92,    93,    94,    95,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,   285,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,    28,    88,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,    87,   286,
      28,    88,     0,    90,    91,    92,    93,    94,    95,    89,
       0,     0,     0,     0,   291,     0,     0,     0,    90,   292,
      92,    93,    94,    95,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,    78,
       0,    79,    80,    81,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,   309,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
     378,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    28,    88,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,    87,   310,    28,    88,
       0,    90,   311,    92,    93,    94,    95,    89,     0,     0,
       0,     0,   379,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    78,     0,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    10,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,    28,    88,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,    87,     0,     0,    88,     0,    90,
      91,    92,    93,    94,    95,    89,     0,     0,     0,   296,
       0,     0,   215,   297,    90,    91,    92,    93,    94,    95,
      87,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,   296,     0,     0,   215,   435,
      90,    91,    92,    93,    94,    95,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,    78,     0,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,   296,    87,
    -267,   215,    88,    90,    91,    92,    93,    94,    95,     0,
      89,     0,     0,     0,   296,    87,     0,   215,    88,    90,
      91,    92,    93,    94,    95,     0,    89,     0,     0,     0,
       0,    87,     0,   215,    88,    90,    91,    92,    93,    94,
      95,     0,    89,   256,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
      87,     0,   358,    88,    90,    91,    92,    93,    94,    95,
       0,    89,     0,     0,     0,    87,     0,     0,    88,     0,
      90,    91,    92,    93,    94,    95,   150,    58,     1,     0,
      87,     0,     0,    88,     0,    90,    91,    92,    93,    94,
      95,   166,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,    32,    33,    34,     0,   274,   195,     0,     0,   120,
       0,     0,     0,     0,     0,    60,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,    32,    33,    34,     0,   119,   195,     0,     0,   120,
       0,     0,     0,     0,     0,    60,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,    30,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   318,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,    30,     0,    32,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   396,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   313,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,    29,     0,    31,    32,    33,    34,     0,     0,
     288,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,    28,     0,    29,     0,    31,    32,    33,
      34,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,     0,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   367,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,    32,    33,    34,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,    29,     0,    31,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,    30,     0,    32,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
     402,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    32,    33,    34
};

static const yytype_int16 yycheck[] =
{
      52,    52,    57,    36,    66,    57,    57,    64,   134,   232,
      53,   121,    55,   103,   143,     3,    54,    89,    54,   218,
     406,   407,    27,   409,    60,   120,   227,   413,    27,     3,
       0,    21,    84,   462,    27,    83,     3,     3,    86,    85,
       3,     3,    81,     0,   139,     3,    85,    52,    83,   383,
     102,   103,    91,    52,    53,    83,    55,   103,    83,    52,
      53,    60,    55,     3,     3,    81,    83,    37,    38,   104,
     499,   500,    89,    43,    44,    45,   104,    81,   150,   104,
      88,   138,   172,   119,    89,    81,    16,    17,    82,    85,
      89,   163,     3,   479,   166,   131,    89,   226,   227,   132,
     143,    89,    83,   136,    88,    75,   201,    81,    89,   495,
     496,   497,   102,   208,    81,   501,   317,    91,    85,    81,
     172,   120,    88,   175,    91,   220,   178,   513,    81,    91,
     104,   183,   131,   467,   186,   187,   188,   189,   190,   191,
     139,    81,    81,    81,   143,   150,    85,   152,   347,   119,
     143,   150,   100,   152,    83,    92,    93,   150,   196,   152,
     196,   166,    90,   196,    20,   255,   276,   166,    98,    99,
      38,    39,    40,   166,   300,   104,   207,   400,    11,    12,
      13,    91,   239,   226,   227,    81,    96,    97,   317,    85,
      14,    15,    81,   101,   225,   290,    85,    18,    19,    82,
      83,   273,   201,   255,    72,    82,   205,    82,    83,   208,
      83,    84,    82,    83,   276,    82,    83,   120,    82,    83,
      82,   220,    83,    91,    82,   224,    81,   226,   227,    82,
      83,   134,   103,   226,   227,    83,   139,   207,   274,    82,
      83,   296,    88,    88,   296,   296,    88,    82,    81,    87,
     153,    11,    85,   102,    87,   225,    82,   383,    83,   162,
      82,     8,   103,    86,   104,    82,    86,   322,    86,   341,
     322,   322,    86,   103,   317,    82,   331,    89,    83,   331,
     331,    82,     3,   282,     3,    82,    86,    86,    82,    87,
      86,   290,   349,    86,    82,   294,    86,    86,   201,    86,
      82,    84,   205,    83,   274,   208,    81,   306,    84,   279,
      88,   437,   215,    84,    81,    81,    81,   220,   317,     3,
     104,   224,    86,   104,   317,    86,     3,    86,    86,   328,
     104,    86,    86,    86,     3,   328,    84,    83,   410,   411,
     412,   467,   104,    86,    86,    84,    84,    84,    84,   252,
      62,   254,    82,    84,    89,    81,    83,   414,    60,   104,
     104,   450,   175,   104,   424,   398,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   375,   183,   186,   282,
     189,   191,   285,   178,   187,   279,   188,   290,   442,   461,
     462,   294,   132,   358,   226,   234,   301,   300,   190,   349,
     414,    75,    -1,   306,    -1,    -1,   309,    -1,    -1,   442,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,   469,   474,
      -1,    -1,   474,   474,    -1,    -1,   498,   499,   500,     3,
       4,     5,     6,     7,     8,     9,    10,   492,    12,    13,
     492,   492,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,   450,    -1,    -1,    -1,   358,    -1,   450,   361,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   375,    -1,    -1,   378,    -1,    -1,    -1,    -1,
     383,    -1,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,     3,     4,     5,     6,     7,     8,     9,    10,
     104,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,     3,     4,     5,     6,     7,
       8,     9,    10,   104,    12,    13,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    -1,    -1,    -1,    70,    -1,    -1,
      73,    -1,    90,    91,    92,    93,    94,    95,    81,     4,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,     3,     4,     5,     6,     7,
       8,     9,    10,    88,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    77,
      78,    79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      70,    86,    72,    73,    -1,    90,    91,    92,    93,    94,
      95,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    70,    86,
      72,    73,    -1,    90,    91,    92,    93,    94,    95,    81,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    70,    86,    72,    73,
      -1,    90,    91,    92,    93,    94,    95,    81,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    90,
      91,    92,    93,    94,    95,    81,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    70,
      87,    88,    73,    90,    91,    92,    93,    94,    95,    -1,
      81,    -1,    -1,    -1,    85,    70,    -1,    88,    73,    90,
      91,    92,    93,    94,    95,    -1,    81,    -1,    -1,    -1,
      -1,    70,    -1,    88,    73,    90,    91,    92,    93,    94,
      95,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      70,    -1,    88,    73,    90,    91,    92,    93,    94,    95,
      -1,    81,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      90,    91,    92,    93,    94,    95,    81,     3,     4,    -1,
      70,    -1,    -1,    73,    -1,    90,    91,    92,    93,    94,
      95,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    81,    82,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    91,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    81,    82,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    91,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    75,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    75,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     3,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,
      82,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    75,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      -1,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,    77,    78,    79,   146,   147,   150,   151,   152,
     155,   166,   174,   175,   176,   177,   198,   221,   223,   224,
     167,   168,    81,   151,   159,   175,   188,    81,     3,    81,
      91,   104,   148,   149,   178,   179,   182,   147,   147,     3,
      88,   147,   147,   147,     0,   222,    88,     3,     3,     5,
       6,     7,     8,     9,    10,    12,    13,    70,    73,    81,
      90,    91,    92,    93,    94,    95,   106,   108,   110,   111,
     115,   120,   121,   122,   123,   124,   126,   128,   130,   132,
     134,   135,   136,   137,   138,   139,   145,   188,   159,    81,
      85,   182,   189,   190,   191,   159,    82,   145,   178,   175,
     182,   183,    83,   104,   103,   146,   147,   226,   227,    85,
     180,   179,   154,   153,   223,     3,   109,   171,   172,   169,
      81,   120,    81,    81,   107,   120,   139,   142,   144,   188,
      12,    13,    81,    85,   116,   117,    81,   120,   123,    91,
      96,    97,   125,    92,    93,   127,    14,    15,   129,    16,
      17,    98,    99,   131,    18,    19,   133,    90,   100,   101,
      20,    21,   140,    82,    82,    82,   147,   184,   185,   186,
     190,    34,    86,    91,   142,   183,   191,    81,    85,    83,
      82,   175,   182,   149,   178,    88,   142,   192,   225,   146,
      34,    86,    91,   142,   183,    81,    88,   156,   157,   159,
     198,   173,    83,   118,    88,   170,   188,   188,   142,    88,
     203,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   103,   143,    82,    83,    82,    82,   119,   142,   144,
      87,    11,   188,   123,   124,   126,   128,   130,   132,   134,
     135,   136,   137,   102,    81,   178,   182,   190,    82,    83,
      82,   142,   183,    86,    86,    34,    86,   142,    82,   184,
      34,    86,    91,   142,   183,     8,    85,    89,   192,   193,
     194,   195,   196,   197,   203,   142,   183,    86,    86,    34,
      86,    91,   142,     3,   181,   184,   187,   156,    89,   157,
     104,   158,   103,   172,    89,   171,    82,    82,    83,     3,
       4,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    89,   104,   144,   146,   199,   200,   201,   204,
     206,   207,   208,   213,   220,    82,   142,   142,    88,   123,
      82,    83,    86,     3,     3,    82,   144,    56,   186,    86,
     142,   142,    86,    82,   142,   183,    86,    86,    34,    86,
     142,    82,   145,    83,    89,   192,   103,   196,    87,    86,
     142,   142,    86,    86,    82,    83,    89,   160,   161,   145,
      83,    89,    58,   112,   113,   188,    84,    84,   145,    84,
      81,    81,    81,   215,    81,     3,   104,   104,   104,   144,
     104,   203,    89,   206,   193,   142,    84,    86,    86,    86,
     142,   142,    86,   104,    86,    89,   192,   194,     3,    86,
      86,     3,    83,   104,   163,   164,   178,    89,   114,    82,
      83,    84,     4,   199,   199,   202,   199,   144,   144,   144,
     199,   146,   207,   218,   104,   104,   205,    83,   118,   141,
      86,    86,   192,   163,    84,   165,    84,   113,   142,    84,
      82,    82,    82,    62,   144,   219,   219,    82,    89,   139,
     162,   145,    84,   142,   199,   209,   210,   214,    81,   104,
     104,   217,   145,   199,   199,   199,   144,   219,   219,   199,
      60,   211,    82,   212,   216,   199,   104
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   107,   106,   106,   106,   108,
     108,   108,   109,   110,   110,   111,   112,   112,   113,   114,
     113,   115,   115,   115,   115,   116,   115,   117,   115,   115,
     115,   115,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   122,   122,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   140,   141,   139,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   144,   144,   145,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   148,   148,
     149,   149,   150,   150,   150,   150,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   153,   152,   154,
     152,   152,   155,   155,   156,   156,   157,   158,   157,   157,
     159,   159,   159,   159,   161,   160,   162,   160,   164,   163,
     165,   163,   163,   167,   166,   168,   169,   166,   170,   170,
     170,   171,   171,   173,   172,   172,   174,   175,   175,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   180,   179,
     181,   181,   181,   182,   182,   182,   182,   183,   183,   184,
     184,   185,   185,   186,   186,   186,   187,   187,   188,   189,
     189,   190,   190,   190,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   192,   192,   192,   192,   193,
     193,   193,   193,   194,   195,   195,   196,   197,   196,   198,
     199,   200,   199,   199,   199,   199,   199,   201,   201,   202,
     201,   201,   203,   203,   204,   205,   204,   206,   206,   207,
     207,   209,   208,   210,   208,   211,   212,   211,   214,   213,
     215,   216,   213,   217,   213,   218,   218,   219,   219,   220,
     220,   220,   220,   220,   221,   222,   221,   223,   223,   225,
     224,   226,   226,   227,   227
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     0,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     3,     3,     0,
       4,     1,     4,     3,     4,     0,     4,     0,     4,     2,
       2,     7,     0,     1,     1,     3,     1,     2,     2,     2,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     0,     0,     7,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     0,
       6,     2,     1,     1,     1,     2,     2,     0,     4,     1,
       2,     1,     2,     1,     0,     2,     0,     4,     0,     3,
       0,     4,     1,     0,     6,     0,     0,     5,     0,     3,
       4,     1,     3,     0,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     4,     2,     1,     1,     3,     3,
       4,     6,     5,     5,     6,     5,     4,     4,     0,     5,
       0,     1,     1,     3,     2,     2,     1,     1,     2,     3,
       1,     1,     3,     2,     2,     1,     1,     3,     2,     0,
       1,     2,     1,     1,     3,     2,     3,     5,     4,     5,
       4,     3,     3,     3,     4,     6,     5,     5,     6,     4,
       4,     2,     3,     3,     4,     3,     4,     1,     2,     2,
       1,     4,     3,     2,     1,     2,     3,     0,     3,     7,
       1,     0,     2,     1,     1,     1,     1,     3,     3,     0,
       5,     3,     2,     3,     1,     0,     3,     1,     1,     1,
       2,     0,     7,     0,     6,     0,     0,     3,     0,     6,
       0,     0,     9,     0,     6,     4,     4,     0,     1,     3,
       2,     2,     2,     3,     1,     0,     3,     1,     1,     0,
       5,     0,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (ctx, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ParserContext *ctx)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ctx);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ParserContext *ctx)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ctx);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, ParserContext *ctx)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, ParserContext *ctx)
{
  YY_USE (yyvaluep);
  YY_USE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ParserContext *ctx)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 156 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2432 "C_grammar.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 161 "C_grammar.y"
              {in_ordinary_id_declaration = 0; current_scope++;}
#line 2438 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' $@1 compound_statement ')'  */
#line 162 "C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2449 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 169 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2459 "C_grammar.tab.c"
    break;

  case 8: /* primary_expression: generic_selection  */
#line 174 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2465 "C_grammar.tab.c"
    break;

  case 14: /* string: FUNC_NAME  */
#line 189 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2471 "C_grammar.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 203 "C_grammar.y"
                  {printf("default pushed \n");
		push(ctx->isFalse);
				if(head != NULL){
					head->false_path = top;
				}
				}
#line 2482 "C_grammar.tab.c"
    break;

  case 20: /* generic_association: DEFAULT $@2 ':' assignment_expression  */
#line 208 "C_grammar.y"
                                                           {
					pop(branch_nb++);
				}
#line 2490 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 216 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2501 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '(' ')'  */
#line 223 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2511 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 229 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2522 "C_grammar.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 235 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2528 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression $@3 '.' IDENTIFIER  */
#line 236 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2540 "C_grammar.tab.c"
    break;

  case 27: /* $@4: %empty  */
#line 243 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2546 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression $@4 PTR_OP IDENTIFIER  */
#line 244 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2558 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression INC_OP  */
#line 252 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2568 "C_grammar.tab.c"
    break;

  case 30: /* postfix_expression: postfix_expression DEC_OP  */
#line 258 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2578 "C_grammar.tab.c"
    break;

  case 31: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 264 "C_grammar.y"
                {if (!strcmp((yyvsp[-1].id), ",")) {
			size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 	(yyval.id) = (char*)malloc(size);
		 	sprintf_safe((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 } else {
			size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 	(yyval.id) = (char*)malloc(size);
		 	sprintf_safe((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 }		 	
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 2596 "C_grammar.tab.c"
    break;

  case 32: /* comma_opt: %empty  */
#line 280 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2602 "C_grammar.tab.c"
    break;

  case 33: /* comma_opt: ','  */
#line 281 "C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2608 "C_grammar.tab.c"
    break;

  case 35: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 288 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2619 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: unary_inc_dec unary_expression  */
#line 299 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2630 "C_grammar.tab.c"
    break;

  case 38: /* unary_expression: unary_operator cast_expression  */
#line 306 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2641 "C_grammar.tab.c"
    break;

  case 39: /* unary_expression: SIZEOF unary_expression  */
#line 313 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2651 "C_grammar.tab.c"
    break;

  case 40: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 319 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2661 "C_grammar.tab.c"
    break;

  case 41: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 325 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2671 "C_grammar.tab.c"
    break;

  case 42: /* unary_inc_dec: INC_OP  */
#line 333 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2677 "C_grammar.tab.c"
    break;

  case 43: /* unary_inc_dec: DEC_OP  */
#line 334 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2683 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '&'  */
#line 338 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2689 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '*'  */
#line 339 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2695 "C_grammar.tab.c"
    break;

  case 46: /* unary_operator: '+'  */
#line 340 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2701 "C_grammar.tab.c"
    break;

  case 47: /* unary_operator: '-'  */
#line 341 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2707 "C_grammar.tab.c"
    break;

  case 48: /* unary_operator: '~'  */
#line 342 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2713 "C_grammar.tab.c"
    break;

  case 49: /* unary_operator: '!'  */
#line 343 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2719 "C_grammar.tab.c"
    break;

  case 51: /* cast_expression: '(' type_name ')' cast_expression  */
#line 349 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2730 "C_grammar.tab.c"
    break;

  case 53: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 360 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2742 "C_grammar.tab.c"
    break;

  case 54: /* multiplicative_expression_op: '*'  */
#line 370 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2748 "C_grammar.tab.c"
    break;

  case 55: /* multiplicative_expression_op: '/'  */
#line 371 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2754 "C_grammar.tab.c"
    break;

  case 56: /* multiplicative_expression_op: '%'  */
#line 372 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2760 "C_grammar.tab.c"
    break;

  case 58: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 378 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2772 "C_grammar.tab.c"
    break;

  case 59: /* additive_expression_op: '+'  */
#line 388 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2778 "C_grammar.tab.c"
    break;

  case 60: /* additive_expression_op: '-'  */
#line 389 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2784 "C_grammar.tab.c"
    break;

  case 62: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 395 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2796 "C_grammar.tab.c"
    break;

  case 63: /* shift_expression_op: LEFT_OP  */
#line 405 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2802 "C_grammar.tab.c"
    break;

  case 64: /* shift_expression_op: RIGHT_OP  */
#line 406 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2808 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 412 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2820 "C_grammar.tab.c"
    break;

  case 67: /* relational_expression_operator: '<'  */
#line 422 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2826 "C_grammar.tab.c"
    break;

  case 68: /* relational_expression_operator: '>'  */
#line 423 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2832 "C_grammar.tab.c"
    break;

  case 69: /* relational_expression_operator: LE_OP  */
#line 424 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2838 "C_grammar.tab.c"
    break;

  case 70: /* relational_expression_operator: GE_OP  */
#line 425 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2844 "C_grammar.tab.c"
    break;

  case 72: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 432 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2856 "C_grammar.tab.c"
    break;

  case 73: /* equality_expression_op: EQ_OP  */
#line 442 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2862 "C_grammar.tab.c"
    break;

  case 74: /* equality_expression_op: NE_OP  */
#line 443 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2868 "C_grammar.tab.c"
    break;

  case 76: /* and_expression: and_expression '&' equality_expression  */
#line 449 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2879 "C_grammar.tab.c"
    break;

  case 78: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 460 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2890 "C_grammar.tab.c"
    break;

  case 80: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 471 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2901 "C_grammar.tab.c"
    break;

  case 82: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 482 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2912 "C_grammar.tab.c"
    break;

  case 84: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 493 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2923 "C_grammar.tab.c"
    break;

  case 86: /* $@5: %empty  */
#line 503 "C_grammar.y"
                               {
		push(ctx->isFalse);
		join_nodes();
		if(ctx->nestedDoWhile){
			top->inDoWhile = ctx->doWhile;
			ctx->nestedDoWhile = false;
		}
		ctx->isFalse = false;
	}
#line 2937 "C_grammar.tab.c"
    break;

  case 87: /* $@6: %empty  */
#line 511 "C_grammar.y"
                            {ctx->isFalse = true;}
#line 2943 "C_grammar.tab.c"
    break;

  case 88: /* conditional_expression: logical_or_expression $@5 '?' expression ':' $@6 conditional_expression  */
#line 512 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb + strlen((yyvsp[-6].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 pop(branch_nb);
		 attach_start(dot_file);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-6].id), (yyvsp[-3].id), (yyvsp[0].id));
		 ctx->isFalse = false;
		 free((yyvsp[-6].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2958 "C_grammar.tab.c"
    break;

  case 90: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 527 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2970 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: '='  */
#line 537 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2976 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: MUL_ASSIGN  */
#line 538 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2982 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: DIV_ASSIGN  */
#line 539 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2988 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: MOD_ASSIGN  */
#line 540 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2994 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: ADD_ASSIGN  */
#line 541 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 3000 "C_grammar.tab.c"
    break;

  case 96: /* assignment_operator: SUB_ASSIGN  */
#line 542 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 3006 "C_grammar.tab.c"
    break;

  case 97: /* assignment_operator: LEFT_ASSIGN  */
#line 543 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 3012 "C_grammar.tab.c"
    break;

  case 98: /* assignment_operator: RIGHT_ASSIGN  */
#line 544 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 3018 "C_grammar.tab.c"
    break;

  case 99: /* assignment_operator: AND_ASSIGN  */
#line 545 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 3024 "C_grammar.tab.c"
    break;

  case 100: /* assignment_operator: XOR_ASSIGN  */
#line 546 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3030 "C_grammar.tab.c"
    break;

  case 101: /* assignment_operator: OR_ASSIGN  */
#line 547 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3036 "C_grammar.tab.c"
    break;

  case 103: /* expression: expression ',' assignment_expression  */
#line 553 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3047 "C_grammar.tab.c"
    break;

  case 105: /* declaration: declaration_specifiers ';'  */
#line 568 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 printf("end of stand alone declaration specifier as a declaration in_ordinary_id_declaration is %d on line %d\n", in_ordinary_id_declaration, yylineno);
		 size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3059 "C_grammar.tab.c"
    break;

  case 106: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 576 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0; 
			//if (debugMode) printf("Debug: typedef switched to 0\n");
	   	 }
		 size_t const size = strlen("\ndeclaration([], [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 3075 "C_grammar.tab.c"
    break;

  case 107: /* declaration: static_assert_declaration  */
#line 588 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3086 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 599 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3098 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: storage_class_specifier  */
#line 607 "C_grammar.y"
                {in_ordinary_id_declaration = 1;}
#line 3104 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 609 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3116 "C_grammar.tab.c"
    break;

  case 111: /* declaration_specifiers: type_specifier  */
#line 617 "C_grammar.y"
                {in_ordinary_id_declaration = 1;}
#line 3122 "C_grammar.tab.c"
    break;

  case 112: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 619 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3134 "C_grammar.tab.c"
    break;

  case 113: /* declaration_specifiers: type_qualifier  */
#line 626 "C_grammar.y"
                         {in_ordinary_id_declaration = 1;}
#line 3140 "C_grammar.tab.c"
    break;

  case 114: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 628 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); 
		}
#line 3148 "C_grammar.tab.c"
    break;

  case 115: /* declaration_specifiers: function_specifier  */
#line 632 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); 
		}
#line 3156 "C_grammar.tab.c"
    break;

  case 116: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 636 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); 
		}
#line 3164 "C_grammar.tab.c"
    break;

  case 117: /* declaration_specifiers: alignment_specifier  */
#line 640 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); 
		}
#line 3172 "C_grammar.tab.c"
    break;

  case 118: /* init_declarator_list: init_declarator  */
#line 647 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 (yyval.id) = (yyvsp[0].id);
		}
#line 3180 "C_grammar.tab.c"
    break;

  case 119: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 651 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3192 "C_grammar.tab.c"
    break;

  case 120: /* init_declarator: declarator '=' initializer  */
#line 662 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));
	  	}
#line 3204 "C_grammar.tab.c"
    break;

  case 121: /* init_declarator: declarator  */
#line 670 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_id(current_scope, (yyvsp[0].declarator_type).ptr_declarator, 1);	//the id as a TYPEDEF_NAME is added to the data structures keeping track of typedef_names and ids shadowing
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3215 "C_grammar.tab.c"
    break;

  case 122: /* storage_class_specifier: TYPEDEF  */
#line 680 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3224 "C_grammar.tab.c"
    break;

  case 123: /* storage_class_specifier: EXTERN  */
#line 684 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3230 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: STATIC  */
#line 685 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3236 "C_grammar.tab.c"
    break;

  case 125: /* storage_class_specifier: THREAD_LOCAL  */
#line 686 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3242 "C_grammar.tab.c"
    break;

  case 126: /* storage_class_specifier: AUTO  */
#line 687 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3248 "C_grammar.tab.c"
    break;

  case 127: /* storage_class_specifier: REGISTER  */
#line 688 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3254 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: VOID  */
#line 692 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "void"); }
#line 3260 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: CHAR  */
#line 693 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "char"); }
#line 3266 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: SHORT  */
#line 694 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "short"); }
#line 3272 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: INT  */
#line 695 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int"); }
#line 3278 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: LONG  */
#line 696 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "long"); }
#line 3284 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: FLOAT  */
#line 697 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float"); }
#line 3290 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: DOUBLE  */
#line 698 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "double"); }
#line 3296 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: SIGNED  */
#line 699 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3302 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: UNSIGNED  */
#line 700 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3308 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: BOOL  */
#line 701 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3314 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: COMPLEX  */
#line 702 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3320 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: IMAGINARY  */
#line 703 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3326 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: atomic_type_specifier  */
#line 704 "C_grammar.y"
                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3332 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: struct_or_union_specifier  */
#line 705 "C_grammar.y"
                                    { in_ordinary_id_declaration = 1; }
#line 3338 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: enum_specifier  */
#line 706 "C_grammar.y"
                                        { in_ordinary_id_declaration = 1; }
#line 3344 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: TYPEDEF_NAME  */
#line 708 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3353 "C_grammar.tab.c"
    break;

  case 144: /* type_specifier: INT128  */
#line 712 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int128"); }
#line 3359 "C_grammar.tab.c"
    break;

  case 145: /* type_specifier: FLOAT128  */
#line 713 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float128"); }
#line 3365 "C_grammar.tab.c"
    break;

  case 146: /* type_specifier: VA_LIST  */
#line 714 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "va_list"); }
#line 3371 "C_grammar.tab.c"
    break;

  case 147: /* $@7: %empty  */
#line 718 "C_grammar.y"
                              {in_tag_declaration = 0;}
#line 3377 "C_grammar.tab.c"
    break;

  case 148: /* struct_or_union_specifier: struct_or_union '{' $@7 struct_declaration_list '}'  */
#line 719 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3388 "C_grammar.tab.c"
    break;

  case 149: /* $@8: %empty  */
#line 725 "C_grammar.y"
                                     {in_tag_declaration = 0;}
#line 3394 "C_grammar.tab.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@8 '{' struct_declaration_list '}'  */
#line 726 "C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3408 "C_grammar.tab.c"
    break;

  case 151: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 736 "C_grammar.y"
                {in_tag_declaration = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3422 "C_grammar.tab.c"
    break;

  case 152: /* struct_or_union: STRUCT  */
#line 749 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_declaration = 1;
		}
#line 3430 "C_grammar.tab.c"
    break;

  case 153: /* struct_or_union: UNION  */
#line 753 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_declaration = 1;
		}
#line 3438 "C_grammar.tab.c"
    break;

  case 155: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 761 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3449 "C_grammar.tab.c"
    break;

  case 156: /* struct_declaration: specifier_qualifier_list ';'  */
#line 771 "C_grammar.y"
                {size_t const size = strlen("anonymous_member()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3459 "C_grammar.tab.c"
    break;

  case 157: /* $@9: %empty  */
#line 777 "C_grammar.y"
                                   {in_member_namespace = 1;}
#line 3465 "C_grammar.tab.c"
    break;

  case 158: /* struct_declaration: specifier_qualifier_list $@9 struct_declarator_list ';'  */
#line 778 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3477 "C_grammar.tab.c"
    break;

  case 160: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 790 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3488 "C_grammar.tab.c"
    break;

  case 162: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 798 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3499 "C_grammar.tab.c"
    break;

  case 164: /* $@10: %empty  */
#line 808 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3505 "C_grammar.tab.c"
    break;

  case 165: /* struct_declarator_list: $@10 struct_declarator  */
#line 808 "C_grammar.y"
                                                       {(yyval.id)= (yyvsp[0].id); in_member_namespace = 1;}
#line 3511 "C_grammar.tab.c"
    break;

  case 166: /* $@11: %empty  */
#line 809 "C_grammar.y"
                                                       {in_member_namespace = 1;}
#line 3517 "C_grammar.tab.c"
    break;

  case 167: /* struct_declarator_list: struct_declarator_list ',' struct_declarator $@11  */
#line 810 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
        }
#line 3528 "C_grammar.tab.c"
    break;

  case 168: /* $@12: %empty  */
#line 819 "C_grammar.y"
          {in_member_namespace = 0;}
#line 3534 "C_grammar.tab.c"
    break;

  case 169: /* struct_declarator: $@12 ':' constant_expression  */
#line 820 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3544 "C_grammar.tab.c"
    break;

  case 170: /* $@13: %empty  */
#line 825 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 3550 "C_grammar.tab.c"
    break;

  case 171: /* struct_declarator: declarator $@13 ':' constant_expression  */
#line 826 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3562 "C_grammar.tab.c"
    break;

  case 172: /* struct_declarator: declarator  */
#line 834 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3571 "C_grammar.tab.c"
    break;

  case 173: /* $@14: %empty  */
#line 841 "C_grammar.y"
               {in_ordinary_id_declaration = 1;}
#line 3577 "C_grammar.tab.c"
    break;

  case 174: /* enum_specifier: ENUM $@14 '{' enumerator_list comma_opt '}'  */
#line 842 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 if (!strcmp((yyvsp[-1].id), ",")) {
			size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 	(yyval.id) = (char*)malloc(size);
         	sprintf_safe((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
		 } else {
			size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 	(yyval.id) = (char*)malloc(size);
         	sprintf_safe((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-2].id));
		 }
	     free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
        }
#line 3595 "C_grammar.tab.c"
    break;

  case 175: /* $@15: %empty  */
#line 855 "C_grammar.y"
               {in_tag_declaration = 1;}
#line 3601 "C_grammar.tab.c"
    break;

  case 176: /* $@16: %empty  */
#line 855 "C_grammar.y"
                                                    {in_tag_declaration = 0; in_ordinary_id_declaration = 1;}
#line 3607 "C_grammar.tab.c"
    break;

  case 177: /* enum_specifier: ENUM $@15 IDENTIFIER $@16 enum_specifier_rest  */
#line 856 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3619 "C_grammar.tab.c"
    break;

  case 178: /* enum_specifier_rest: %empty  */
#line 867 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3625 "C_grammar.tab.c"
    break;

  case 179: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 869 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3631 "C_grammar.tab.c"
    break;

  case 180: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 871 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3641 "C_grammar.tab.c"
    break;

  case 181: /* enumerator_list: enumerator  */
#line 879 "C_grammar.y"
                     {in_ordinary_id_declaration = 1;}
#line 3647 "C_grammar.tab.c"
    break;

  case 182: /* enumerator_list: enumerator_list ',' enumerator  */
#line 881 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3659 "C_grammar.tab.c"
    break;

  case 183: /* $@17: %empty  */
#line 891 "C_grammar.y"
                               {in_ordinary_id_declaration = 0;}
#line 3665 "C_grammar.tab.c"
    break;

  case 184: /* enumerator: enumeration_constant $@17 '=' constant_expression  */
#line 892 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[0].id));
        }
#line 3676 "C_grammar.tab.c"
    break;

  case 187: /* type_qualifier: CONST  */
#line 906 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3682 "C_grammar.tab.c"
    break;

  case 188: /* type_qualifier: RESTRICT  */
#line 907 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3688 "C_grammar.tab.c"
    break;

  case 189: /* type_qualifier: VOLATILE  */
#line 908 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3694 "C_grammar.tab.c"
    break;

  case 190: /* type_qualifier: ATOMIC  */
#line 909 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3700 "C_grammar.tab.c"
    break;

  case 191: /* function_specifier: INLINE  */
#line 913 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3706 "C_grammar.tab.c"
    break;

  case 192: /* function_specifier: NORETURN  */
#line 914 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3712 "C_grammar.tab.c"
    break;

  case 195: /* declarator: pointer direct_declarator  */
#line 925 "C_grammar.y"
          {in_ordinary_id_declaration = 0;
	   size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3725 "C_grammar.tab.c"
    break;

  case 196: /* declarator: direct_declarator  */
#line 933 "C_grammar.y"
                            {in_ordinary_id_declaration = 0;}
#line 3731 "C_grammar.tab.c"
    break;

  case 197: /* direct_declarator: IDENTIFIER  */
#line 938 "C_grammar.y"
                {if (in_member_namespace) {	//this is a member (from a struct or union) no need to transform into a Prolog var
			size_t const size = strlen((yyvsp[0].id)) + 1;
			(yyval.declarator_type).full = (char*)malloc(size);
		 	strcpy_safe((yyval.declarator_type).full, size, (yyvsp[0].id));
			(yyval.declarator_type).ptr_declarator = (char*)malloc(size);
		 	strcpy_safe((yyval.declarator_type).ptr_declarator, size, (yyvsp[0].id));
		 } else {
			char Prolog_var_name[MAX_ID_LENGTH+5];	//todo should use to_prolog_var($1);
			if (islower((yyvsp[0].id)[0])) {
				Prolog_var_name[0] = toupper((yyvsp[0].id)[0]);
				strcpy_safe(&Prolog_var_name[1], MAX_ID_LENGTH-1, &(yyvsp[0].id)[1]);
			} else {
				strcpy_safe(Prolog_var_name, MAX_ID_LENGTH, "UC_");
				strcat_safe(Prolog_var_name, MAX_ID_LENGTH, (yyvsp[0].id));
			}
			size_t const size = strlen(Prolog_var_name) + 1;
		 	(yyval.declarator_type).full = (char*)malloc(size);
		 	strcpy_safe((yyval.declarator_type).full, size, Prolog_var_name);
		 	(yyval.declarator_type).ptr_declarator = strdup((yyval.declarator_type).full);
		 	free((yyvsp[0].id));
		 }
		}
#line 3758 "C_grammar.tab.c"
    break;

  case 198: /* direct_declarator: '(' declarator ')'  */
#line 962 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-1].declarator_type);}
#line 3764 "C_grammar.tab.c"
    break;

  case 199: /* direct_declarator: direct_declarator '[' ']'  */
#line 964 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3775 "C_grammar.tab.c"
    break;

  case 200: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 971 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3784 "C_grammar.tab.c"
    break;

  case 201: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 976 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3793 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 981 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3802 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 986 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3811 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 991 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3820 "C_grammar.tab.c"
    break;

  case 205: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 996 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3829 "C_grammar.tab.c"
    break;

  case 206: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 1001 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3838 "C_grammar.tab.c"
    break;

  case 207: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 1006 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3850 "C_grammar.tab.c"
    break;

  case 208: /* $@18: %empty  */
#line 1013 "C_grammar.y"
                            {in_ordinary_id_declaration = 0; if (!typedef_flag) current_scope++; }
#line 3856 "C_grammar.tab.c"
    break;

  case 209: /* direct_declarator: direct_declarator $@18 '(' rest_function_definition ')'  */
#line 1014 "C_grammar.y"
                {if (typedef_flag) handled_function_paramaters = 666;
		 in_ordinary_id_declaration = 0;
		 size_t const size = strlen("function(, )") + strlen((yyvsp[-4].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-4].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-4].declarator_type).full);
	     free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 3871 "C_grammar.tab.c"
    break;

  case 210: /* rest_function_definition: %empty  */
#line 1027 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 3877 "C_grammar.tab.c"
    break;

  case 212: /* rest_function_definition: old_style_parameter_list  */
#line 1029 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 3883 "C_grammar.tab.c"
    break;

  case 213: /* pointer: '*' type_qualifier_list pointer  */
#line 1034 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3894 "C_grammar.tab.c"
    break;

  case 214: /* pointer: '*' type_qualifier_list  */
#line 1041 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3904 "C_grammar.tab.c"
    break;

  case 215: /* pointer: '*' pointer  */
#line 1047 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3914 "C_grammar.tab.c"
    break;

  case 216: /* pointer: '*'  */
#line 1053 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3920 "C_grammar.tab.c"
    break;

  case 218: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1059 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3931 "C_grammar.tab.c"
    break;

  case 219: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1069 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3941 "C_grammar.tab.c"
    break;

  case 220: /* parameter_type_list: parameter_list  */
#line 1075 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3951 "C_grammar.tab.c"
    break;

  case 222: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1085 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3962 "C_grammar.tab.c"
    break;

  case 223: /* parameter_declaration: declaration_specifiers declarator  */
#line 1095 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3974 "C_grammar.tab.c"
    break;

  case 224: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1103 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3985 "C_grammar.tab.c"
    break;

  case 225: /* parameter_declaration: declaration_specifiers  */
#line 1110 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3995 "C_grammar.tab.c"
    break;

  case 228: /* type_name: specifier_qualifier_list abstract_declarator_opt  */
#line 1124 "C_grammar.y"
                {if (!strcmp((yyvsp[0].id), "")) {
			size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     	(yyval.id) = (char*)malloc(size);
	     	sprintf_safe((yyval.id), size, "[%s]", (yyvsp[-1].id));
		 } else {
		 	simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");
		 }
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4010 "C_grammar.tab.c"
    break;

  case 229: /* abstract_declarator_opt: %empty  */
#line 1137 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4016 "C_grammar.tab.c"
    break;

  case 230: /* abstract_declarator_opt: abstract_declarator  */
#line 1138 "C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 4022 "C_grammar.tab.c"
    break;

  case 255: /* initializer: '{' initializer_list '}'  */
#line 1173 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4032 "C_grammar.tab.c"
    break;

  case 256: /* initializer: '{' initializer_list ',' '}'  */
#line 1179 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 4042 "C_grammar.tab.c"
    break;

  case 258: /* initializer: '{' '}'  */
#line 1186 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 4048 "C_grammar.tab.c"
    break;

  case 259: /* initializer_list: designation initializer  */
#line 1191 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4059 "C_grammar.tab.c"
    break;

  case 261: /* initializer_list: initializer_list ',' designation initializer  */
#line 1199 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4071 "C_grammar.tab.c"
    break;

  case 262: /* initializer_list: initializer_list ',' initializer  */
#line 1207 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4082 "C_grammar.tab.c"
    break;

  case 263: /* designation: designator_list '='  */
#line 1217 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4092 "C_grammar.tab.c"
    break;

  case 265: /* designator_list: designator_list designator  */
#line 1227 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4103 "C_grammar.tab.c"
    break;

  case 266: /* designator: '[' constant_expression ']'  */
#line 1237 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4113 "C_grammar.tab.c"
    break;

  case 267: /* $@19: %empty  */
#line 1242 "C_grammar.y"
          {in_member_namespace = 1;}
#line 4119 "C_grammar.tab.c"
    break;

  case 268: /* designator: $@19 '.' IDENTIFIER  */
#line 1243 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4130 "C_grammar.tab.c"
    break;

  case 269: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1253 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4141 "C_grammar.tab.c"
    break;

  case 271: /* $@20: %empty  */
#line 1263 "C_grammar.y"
          {in_ordinary_id_declaration = 0; current_scope++;}
#line 4147 "C_grammar.tab.c"
    break;

  case 272: /* statement: $@20 compound_statement  */
#line 1264 "C_grammar.y"
                {pop_scope(&current_scope);
		 (yyval.id) = (yyvsp[0].id);
		}
#line 4155 "C_grammar.tab.c"
    break;

  case 277: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1275 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4166 "C_grammar.tab.c"
    break;

  case 278: /* labeled_statement: TYPEDEF_NAME ':' statement  */
#line 1283 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4177 "C_grammar.tab.c"
    break;

  case 279: /* $@21: %empty  */
#line 1289 "C_grammar.y"
                                   {
		push(ctx->isFalse);
		if(head!=NULL){
			head->false_path = top;
			if(!ctx->breakOn){
				head->true_path = top;
			}else{
				ctx->breakOn = false;
			}
		}
		if(ctx->nestedDoWhile){
			top->inDoWhile = ctx->doWhile;
			ctx->nestedDoWhile = false;
		}
		ctx->isFalse = false;
	}
#line 4198 "C_grammar.tab.c"
    break;

  case 280: /* labeled_statement: CASE constant_expression $@21 ':' statement  */
#line 1305 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   printf("case poped %d\n", branch_nb);
	   pop(branch_nb++);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
	   free((yyvsp[-3].id));
	   free((yyvsp[0].id));
	  }
#line 4211 "C_grammar.tab.c"
    break;

  case 281: /* labeled_statement: DEFAULT ':' statement  */
#line 1314 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4221 "C_grammar.tab.c"
    break;

  case 282: /* compound_statement: '{' '}'  */
#line 1322 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4227 "C_grammar.tab.c"
    break;

  case 283: /* compound_statement: '{' block_item_list '}'  */
#line 1324 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4237 "C_grammar.tab.c"
    break;

  case 284: /* block_item_list: block_item  */
#line 1332 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 4243 "C_grammar.tab.c"
    break;

  case 285: /* $@22: %empty  */
#line 1333 "C_grammar.y"
                                     {in_ordinary_id_declaration = 0;}
#line 4249 "C_grammar.tab.c"
    break;

  case 286: /* block_item_list: block_item_list block_item $@22  */
#line 1334 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	  }
#line 4260 "C_grammar.tab.c"
    break;

  case 289: /* expression_statement: ';'  */
#line 1348 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4266 "C_grammar.tab.c"
    break;

  case 290: /* expression_statement: expression ';'  */
#line 1350 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4276 "C_grammar.tab.c"
    break;

  case 291: /* $@23: %empty  */
#line 1358 "C_grammar.y"
                               {
		push(ctx->isFalse);
		join_nodes();
		if(ctx->nestedDoWhile){
			top->inDoWhile = ctx->doWhile;
			ctx->nestedDoWhile = false;
		}
		ctx->isFalse = false;
		}
#line 4290 "C_grammar.tab.c"
    break;

  case 292: /* selection_statement: IF '(' expression ')' $@23 statement else_opt  */
#line 1367 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 printf("if poped %d\n", branch_nb);
		 pop(branch_nb);
		 attach_start(dot_file);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4305 "C_grammar.tab.c"
    break;

  case 293: /* $@24: %empty  */
#line 1377 "C_grammar.y"
                                   {
		push(ctx->isFalse);
		join_nodes();
		if(ctx->nestedDoWhile){
			top->inDoWhile = ctx->doWhile;
			ctx->nestedDoWhile = false;
		}
		ctx->isFalse = false;
		}
#line 4319 "C_grammar.tab.c"
    break;

  case 294: /* selection_statement: SWITCH '(' expression ')' $@24 statement  */
#line 1386 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 printf("switch poped %d\n", branch_nb);
		 pop(branch_nb++);
		 attach_start(dot_file);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 4333 "C_grammar.tab.c"
    break;

  case 295: /* else_opt: %empty  */
#line 1398 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4339 "C_grammar.tab.c"
    break;

  case 296: /* $@25: %empty  */
#line 1399 "C_grammar.y"
              {
			ctx->isFalse = true;
			}
#line 4347 "C_grammar.tab.c"
    break;

  case 297: /* else_opt: ELSE $@25 statement  */
#line 1403 "C_grammar.y"
                {
		 size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 ctx->isFalse = false;
		 free((yyvsp[0].id));
		}
#line 4359 "C_grammar.tab.c"
    break;

  case 298: /* $@26: %empty  */
#line 1411 "C_grammar.y"
                                  { 
		push(ctx->isFalse);
		join_nodes();
		ctx->isFalse = false;
		if(ctx->nestedDoWhile){
			top->inDoWhile = ctx->doWhile;
			ctx->nestedDoWhile = false;
		}
		ctx->isFalse = false;
		}
#line 4374 "C_grammar.tab.c"
    break;

  case 299: /* iteration_statement: WHILE '(' expression ')' $@26 statement  */
#line 1421 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 if(top->true_path == NULL){
			top->true_path = top;
		 }else{
			join_nodes();// The nested node will go back to iteration node
		 }
		 pop(branch_nb);
		 attach_start(dot_file);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-3].id), branch_nb++, (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 4392 "C_grammar.tab.c"
    break;

  case 300: /* $@27: %empty  */
#line 1434 "C_grammar.y"
             {ctx->doWhile++; ctx->nestedDoWhile = true;}
#line 4398 "C_grammar.tab.c"
    break;

  case 301: /* $@28: %empty  */
#line 1434 "C_grammar.y"
                                                                                            {
		push(ctx->isFalse);
		join_nodes();
		ctx->isFalse = false;
		if(ctx->nestedDoWhile){
			top->inDoWhile = ctx->doWhile;
			ctx->nestedDoWhile = false;
		}
		}
#line 4412 "C_grammar.tab.c"
    break;

  case 302: /* iteration_statement: DO $@27 statement WHILE '(' expression ')' $@28 ';'  */
#line 1443 "C_grammar.y"
                { Node *temp = head;
		 connectDoWhile(ctx->doWhile);
		 pop(branch_nb);
		 attach_start(dot_file);
		 ctx->doWhile--;
		 ctx->nestedDoWhile = false;
		 size_t const size = strlen("\ndo_while_stmt(, )") + strlen((yyvsp[-6].id)) + strlen((yyvsp[-3].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-6].id), branch_nb++, (yyvsp[-3].id));
		 free((yyvsp[-6].id));
		 free((yyvsp[-3].id));
		}
#line 4429 "C_grammar.tab.c"
    break;

  case 303: /* $@29: %empty  */
#line 1455 "C_grammar.y"
                                    {
		push(ctx->isFalse);
		join_nodes();
		if(ctx->nestedDoWhile){
			top->inDoWhile = ctx->doWhile;
			ctx->nestedDoWhile = false;
		}
		ctx->isFalse = false;
		}
#line 4443 "C_grammar.tab.c"
    break;

  case 304: /* iteration_statement: FOR '(' for_stmt_type ')' $@29 statement  */
#line 1464 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-3].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-3].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-3].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 if(top->true_path == NULL){
			top->true_path = top;
		 }else{
			join_nodes();// The nested node will go back to iteration node
		 }
		 pop(branch_nb);
		 attach_start(dot_file);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-3].for_stmt_type).init, branch_nb++, (yyvsp[-3].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-3].for_stmt_type).update);
		 free((yyvsp[-3].for_stmt_type).init);
		 free((yyvsp[-3].for_stmt_type).cond);
		 free((yyvsp[-3].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4463 "C_grammar.tab.c"
    break;

  case 305: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1483 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4469 "C_grammar.tab.c"
    break;

  case 306: /* for_stmt_type: declaration expression_opt ';' expression_opt  */
#line 1485 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4475 "C_grammar.tab.c"
    break;

  case 307: /* expression_opt: %empty  */
#line 1489 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4481 "C_grammar.tab.c"
    break;

  case 309: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1494 "C_grammar.y"
          {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4492 "C_grammar.tab.c"
    break;

  case 310: /* jump_statement: CONTINUE ';'  */
#line 1500 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4498 "C_grammar.tab.c"
    break;

  case 311: /* jump_statement: BREAK ';'  */
#line 1501 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n"); ctx->breakOn = true;}
#line 4504 "C_grammar.tab.c"
    break;

  case 312: /* jump_statement: RETURN ';'  */
#line 1502 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4510 "C_grammar.tab.c"
    break;

  case 313: /* jump_statement: RETURN expression ';'  */
#line 1504 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4520 "C_grammar.tab.c"
    break;

  case 315: /* $@30: %empty  */
#line 1514 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4526 "C_grammar.tab.c"
    break;

  case 317: /* external_declaration: function_definition  */
#line 1519 "C_grammar.y"
                {handled_function_paramaters = 0;
		 pop_scope(&current_scope);
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4536 "C_grammar.tab.c"
    break;

  case 318: /* external_declaration: declaration  */
#line 1525 "C_grammar.y"
                {if (handled_function_paramaters == 666) handled_function_paramaters = 0; 
		else if(handled_function_paramaters) {
			handled_function_paramaters = 0;
			pop_scope(&current_scope);
		 }
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4549 "C_grammar.tab.c"
    break;

  case 319: /* $@31: %empty  */
#line 1536 "C_grammar.y"
                                                                 {in_ordinary_id_declaration = 0;}
#line 4555 "C_grammar.tab.c"
    break;

  case 320: /* function_definition: declaration_specifiers declarator declaration_list_opt $@31 compound_statement  */
#line 1537 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-4].id), (yyvsp[-3].declarator_type).full, (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4570 "C_grammar.tab.c"
    break;

  case 321: /* declaration_list_opt: %empty  */
#line 1550 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4576 "C_grammar.tab.c"
    break;

  case 324: /* old_style_declaration_list: old_style_declaration_list declaration  */
#line 1557 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4587 "C_grammar.tab.c"
    break;


#line 4591 "C_grammar.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (ctx, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, ctx);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (ctx, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1565 "C_grammar.y"

#include "lex.yy.c"

int main(int argc, char *argv[]) {
	char C_file_path[MAX_PATH];				//directory where the C and .i files are
	char filename_no_ext[MAX_PATH];
	ParserContext ctx = {0};


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
	// Open the .dot file for writing
    sprintf_safe(dot_file_uri, 3 * MAX_PATH, "%s/%s.dot", C_file_path, filename_no_ext);
    dot_file = fopen(dot_file_uri, "w");
    if (!dot_file) {
        fprintf(stderr, ".dot file could not be created for writing at: %s\n", dot_file_uri);
        my_exit(EXIT_FAILURE);
    }

    // Write initial content to the .dot file
    fprintf(dot_file, "digraph CFG {\n");

	fprintf(pl_file, "prolog_c([");			//opening predicate
	if (yyparse(&ctx) != 0) {					//the parser is called
		fprintf(stderr, "Parsing failed.\n");
		my_exit(EXIT_FAILURE);
	}	
	fprintf(pl_file, "\n]).");
	fclose(pl_file);
	pl_file = NULL;
	populate_dot_file(dot_file);
    fprintf(dot_file, "}\n"); // Finalize the .dot file
    fclose(dot_file);
    dot_file = NULL;

	fclose(i_file);
	i_file = NULL;
	my_exit(EXIT_SUCCESS);
}

//handles parsing errors: since the C input file is the output of a C pre-processor it will only be called if
//  the syntax rules are wrong due to GCC extensions 
//  or if .i file has been generated manually: i.e. during development
void yyerror(ParserContext *ctx, const char* s) {
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
  }
  if (exit_code == EXIT_SUCCESS) fprintf(stderr, "Sikraken parsing SUCCESS, wrote %s\n", pl_file_uri);
  exit(exit_code);
}

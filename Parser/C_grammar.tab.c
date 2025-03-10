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
	int  doWhile;
} ParserContext;

extern Node *top;
extern void push(bool isFalse); //This will push the nodes onto the stack.
extern void populate_dot_file(FILE *dot_file);
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

#line 149 "C_grammar.tab.c"

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
  YYSYMBOL_postfix_expression = 114,       /* postfix_expression  */
  YYSYMBOL_115_2 = 115,                    /* $@2  */
  YYSYMBOL_116_3 = 116,                    /* $@3  */
  YYSYMBOL_comma_opt = 117,                /* comma_opt  */
  YYSYMBOL_argument_expression_list = 118, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 119,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 120,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 121,           /* unary_operator  */
  YYSYMBOL_cast_expression = 122,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 123, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 124, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 125,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 126,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 127,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 128,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 129,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 130, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 131,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 132,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 133,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 134,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 135,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 136,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 137,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 138,   /* conditional_expression  */
  YYSYMBOL_139_4 = 139,                    /* $@4  */
  YYSYMBOL_140_5 = 140,                    /* $@5  */
  YYSYMBOL_assignment_expression = 141,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 142,      /* assignment_operator  */
  YYSYMBOL_expression = 143,               /* expression  */
  YYSYMBOL_constant_expression = 144,      /* constant_expression  */
  YYSYMBOL_declaration = 145,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 146,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 147,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 148,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 149,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 150,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 151, /* struct_or_union_specifier  */
  YYSYMBOL_152_6 = 152,                    /* $@6  */
  YYSYMBOL_153_7 = 153,                    /* $@7  */
  YYSYMBOL_struct_or_union = 154,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 155,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 156,       /* struct_declaration  */
  YYSYMBOL_157_8 = 157,                    /* $@8  */
  YYSYMBOL_specifier_qualifier_list = 158, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 159,   /* struct_declarator_list  */
  YYSYMBOL_160_9 = 160,                    /* $@9  */
  YYSYMBOL_161_10 = 161,                   /* $@10  */
  YYSYMBOL_struct_declarator = 162,        /* struct_declarator  */
  YYSYMBOL_163_11 = 163,                   /* $@11  */
  YYSYMBOL_164_12 = 164,                   /* $@12  */
  YYSYMBOL_enum_specifier = 165,           /* enum_specifier  */
  YYSYMBOL_166_13 = 166,                   /* $@13  */
  YYSYMBOL_167_14 = 167,                   /* $@14  */
  YYSYMBOL_168_15 = 168,                   /* $@15  */
  YYSYMBOL_enum_specifier_rest = 169,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 170,          /* enumerator_list  */
  YYSYMBOL_enumerator = 171,               /* enumerator  */
  YYSYMBOL_172_16 = 172,                   /* $@16  */
  YYSYMBOL_atomic_type_specifier = 173,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 174,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 175,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 176,      /* alignment_specifier  */
  YYSYMBOL_declarator = 177,               /* declarator  */
  YYSYMBOL_direct_declarator = 178,        /* direct_declarator  */
  YYSYMBOL_179_17 = 179,                   /* $@17  */
  YYSYMBOL_rest_function_definition = 180, /* rest_function_definition  */
  YYSYMBOL_pointer = 181,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 182,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 183,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 184,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 185,    /* parameter_declaration  */
  YYSYMBOL_old_style_parameter_list = 186, /* old_style_parameter_list  */
  YYSYMBOL_type_name = 187,                /* type_name  */
  YYSYMBOL_abstract_declarator_opt = 188,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 189,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 190, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 191,              /* initializer  */
  YYSYMBOL_initializer_list = 192,         /* initializer_list  */
  YYSYMBOL_designation = 193,              /* designation  */
  YYSYMBOL_designator_list = 194,          /* designator_list  */
  YYSYMBOL_designator = 195,               /* designator  */
  YYSYMBOL_196_18 = 196,                   /* $@18  */
  YYSYMBOL_static_assert_declaration = 197, /* static_assert_declaration  */
  YYSYMBOL_statement = 198,                /* statement  */
  YYSYMBOL_199_19 = 199,                   /* $@19  */
  YYSYMBOL_labeled_statement = 200,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 201,       /* compound_statement  */
  YYSYMBOL_block_item_list = 202,          /* block_item_list  */
  YYSYMBOL_203_20 = 203,                   /* $@20  */
  YYSYMBOL_block_item = 204,               /* block_item  */
  YYSYMBOL_expression_statement = 205,     /* expression_statement  */
  YYSYMBOL_selection_statement = 206,      /* selection_statement  */
  YYSYMBOL_207_21 = 207,                   /* $@21  */
  YYSYMBOL_else_opt = 208,                 /* else_opt  */
  YYSYMBOL_209_22 = 209,                   /* $@22  */
  YYSYMBOL_iteration_statement = 210,      /* iteration_statement  */
  YYSYMBOL_211_23 = 211,                   /* $@23  */
  YYSYMBOL_212_24 = 212,                   /* $@24  */
  YYSYMBOL_213_25 = 213,                   /* $@25  */
  YYSYMBOL_214_26 = 214,                   /* $@26  */
  YYSYMBOL_for_stmt_type = 215,            /* for_stmt_type  */
  YYSYMBOL_expression_opt = 216,           /* expression_opt  */
  YYSYMBOL_jump_statement = 217,           /* jump_statement  */
  YYSYMBOL_translation_unit = 218,         /* translation_unit  */
  YYSYMBOL_219_27 = 219,                   /* $@27  */
  YYSYMBOL_external_declaration = 220,     /* external_declaration  */
  YYSYMBOL_function_definition = 221,      /* function_definition  */
  YYSYMBOL_222_28 = 222,                   /* $@28  */
  YYSYMBOL_declaration_list_opt = 223,     /* declaration_list_opt  */
  YYSYMBOL_old_style_declaration_list = 224 /* old_style_declaration_list  */
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
#define YYLAST   2361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  321
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  514

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
       0,   150,   150,   154,   155,   156,   156,   163,   169,   173,
     174,   175,   179,   183,   184,   188,   192,   193,   197,   198,
     202,   203,   210,   216,   223,   223,   231,   231,   239,   245,
     251,   268,   269,   274,   275,   285,   286,   293,   300,   306,
     312,   321,   322,   326,   327,   328,   329,   330,   331,   335,
     336,   346,   347,   358,   359,   360,   364,   365,   376,   377,
     381,   382,   393,   394,   398,   399,   410,   411,   412,   413,
     418,   419,   430,   431,   435,   436,   446,   447,   457,   458,
     468,   469,   479,   480,   490,   491,   504,   491,   518,   519,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   544,   545,   555,   560,   568,   580,   591,   599,   601,
     609,   611,   619,   620,   624,   628,   632,   639,   643,   654,
     662,   672,   677,   678,   679,   680,   681,   685,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   705,   706,   707,   711,   711,   718,   718,
     728,   741,   745,   752,   753,   763,   770,   770,   778,   782,
     789,   790,   797,   801,   801,   802,   802,   812,   812,   818,
     818,   826,   834,   834,   848,   848,   848,   860,   861,   863,
     872,   873,   884,   884,   891,   895,   899,   900,   901,   902,
     906,   907,   911,   912,   917,   926,   930,   953,   956,   963,
     968,   973,   978,   983,   988,   993,   998,  1006,  1006,  1020,
    1021,  1022,  1026,  1033,  1039,  1045,  1050,  1051,  1061,  1067,
    1076,  1077,  1087,  1095,  1102,  1111,  1112,  1116,  1130,  1131,
    1135,  1136,  1137,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1158,  1159,  1160,  1161,  1165,  1171,  1177,  1178,  1183,  1190,
    1191,  1199,  1209,  1218,  1219,  1229,  1235,  1235,  1245,  1255,
    1256,  1256,  1260,  1261,  1262,  1263,  1267,  1275,  1282,  1289,
    1298,  1299,  1308,  1309,  1309,  1319,  1320,  1324,  1325,  1334,
    1334,  1352,  1362,  1363,  1363,  1375,  1375,  1393,  1393,  1393,
    1422,  1422,  1445,  1447,  1452,  1453,  1456,  1463,  1464,  1465,
    1466,  1476,  1477,  1477,  1481,  1487,  1499,  1499,  1513,  1514,
    1518,  1519
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
  "generic_association", "postfix_expression", "$@2", "$@3", "comma_opt",
  "argument_expression_list", "unary_expression", "unary_inc_dec",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "multiplicative_expression_op", "additive_expression",
  "additive_expression_op", "shift_expression", "shift_expression_op",
  "relational_expression", "relational_expression_operator",
  "equality_expression", "equality_expression_op", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "$@4", "$@5", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "$@6", "$@7", "struct_or_union",
  "struct_declaration_list", "struct_declaration", "$@8",
  "specifier_qualifier_list", "struct_declarator_list", "$@9", "$@10",
  "struct_declarator", "$@11", "$@12", "enum_specifier", "$@13", "$@14",
  "$@15", "enum_specifier_rest", "enumerator_list", "enumerator", "$@16",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "$@17",
  "rest_function_definition", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "old_style_parameter_list", "type_name", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "$@18", "static_assert_declaration", "statement", "$@19",
  "labeled_statement", "compound_statement", "block_item_list", "$@20",
  "block_item", "expression_statement", "selection_statement", "$@21",
  "else_opt", "$@22", "iteration_statement", "$@23", "$@24", "$@25",
  "$@26", "for_stmt_type", "expression_opt", "jump_statement",
  "translation_unit", "$@27", "external_declaration",
  "function_definition", "$@28", "declaration_list_opt",
  "old_style_declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-428)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-319)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2021,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,    37,   -48,  2282,  -428,  -428,
     -29,  -428,  -428,  -428,  -428,  -428,    20,  2126,  2126,  -428,
      24,  -428,  -428,  2126,  2126,  2126,  -428,    65,  -428,  -428,
      -9,    74,   890,  2282,    90,  2282,     5,  1598,  -428,    26,
     151,  -428,   -46,  -428,   813,    48,    12,  -428,  -428,     4,
    -428,  -428,  -428,  -428,  -428,  2021,   106,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  1613,  -428,  -428,    35,    49,   890,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
     167,  -428,  1628,  1598,  -428,   -11,    -4,   104,    29,   136,
      51,    43,    55,   142,     0,  -428,    87,   105,  -428,  1752,
     983,    83,  -428,  -428,    91,  -428,  -428,   111,   114,  -428,
    -428,   151,    26,  -428,  1473,  -428,    20,  -428,  2021,   998,
     118,    48,   117,  2178,  -428,  -428,   115,   139,  -428,   138,
     890,  -428,  2282,  1598,   144,   344,  -428,  -428,   103,   153,
    -428,  -428,  1489,  1598,   152,   213,   890,  -428,  -428,  -428,
    -428,  -428,  1598,  -428,  -428,  1598,  -428,  -428,  1598,  -428,
    -428,  -428,  -428,  1598,  -428,  -428,  1598,  1598,  1598,  1598,
    1598,  1598,   141,  -428,  -428,  -428,    23,   158,   164,  -428,
     169,  1307,  -428,   163,   170,  1091,    91,  1916,  1106,   245,
    -428,  -428,  -428,  -428,   155,  1322,  -428,  -428,   144,  -428,
    1307,  -428,   174,   175,  1199,  1969,  2178,  1806,  -428,   159,
    -428,   161,   106,   173,   106,  -428,   183,   184,   185,   534,
     191,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  1598,  -428,  1598,  1582,  -428,   110,  -428,   -45,
     272,   274,   196,  -428,   -11,    -4,   104,    29,   136,    51,
      43,    55,   142,  1598,  1692,  -428,    61,  -428,  -428,  2073,
    -428,   195,  1307,  -428,  -428,  1598,  -428,   199,  -428,   200,
    1307,  -428,   201,   202,  1214,   207,  1598,  -428,  -428,   -40,
    1473,    67,  -428,   206,  -428,   208,  1307,  -428,  -428,  1598,
    -428,   210,   211,  -428,   217,  -428,   220,  1858,  -428,  -428,
    -428,  -428,  1598,  -428,  -428,   -17,   212,  -428,  2230,   222,
     224,  1598,   226,   232,   233,   234,  -428,   235,   316,   216,
     218,   735,  -428,  -428,   -41,  -428,  -428,   144,  -428,   627,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  1457,  -428,
    -428,  1598,  -428,  -428,  -428,   212,   124,  -428,  -428,  -428,
     237,   239,  -428,  -428,   240,  1307,  -428,  -428,  1598,  -428,
     241,   227,   242,  1348,  -428,  -428,  -428,  -428,   327,  -428,
     246,   247,  -428,  -428,  -428,   331,  -428,   -35,    26,  -428,
      33,  -428,   252,   128,  -428,   253,   426,   426,   258,   426,
    1598,  1598,  1598,   426,   720,   243,  -428,  -428,  -428,   -28,
    -428,  -428,  -428,  -428,   260,  -428,  -428,  -428,  -428,  -428,
     259,   262,  -428,  -428,  -428,  -428,  -428,  1473,  -428,  -428,
    -428,  -428,    26,  -428,  -428,   266,   268,  -428,  1598,  -428,
    2230,  1598,   224,  -428,  -428,   426,  -428,   130,   133,   137,
     282,  1598,  1598,   264,  -428,  -428,  -428,  1441,   265,  1598,
    -428,  -428,  -428,  -428,  1598,   269,  -428,  -428,  -428,  -428,
    -428,   426,  -428,   275,   276,   251,   254,  -428,  -428,  -428,
    -428,  -428,  1598,   426,  -428,   426,  1598,  1598,  1598,   426,
    -428,   300,  -428,   147,  -428,  -428,  -428,  -428,  -428,  -428,
     426,   257,  -428,  -428
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   142,   121,   122,   123,   125,   126,   190,   186,   187,
     188,   136,   128,   129,   130,   131,   134,   135,   132,   133,
     127,   137,   138,   151,   152,   172,     0,     0,   189,   191,
       0,   124,   143,   144,   145,   315,     0,   108,   110,   140,
       0,   141,   139,   112,   114,   116,   106,   312,   311,   314,
       0,     0,     0,   160,   228,   162,     0,     0,   196,     0,
     215,   104,     0,   117,   120,   195,     0,   107,   109,   150,
     146,   111,   113,   115,     1,     0,     0,   175,     2,     9,
      10,    11,    13,    14,     0,    41,    42,     0,     0,     5,
      43,    44,    45,    46,    47,    48,    20,     3,     4,     8,
      35,    49,     0,     0,    51,    56,    60,    64,    70,    74,
      76,    78,    80,    82,    84,   103,     0,     0,   159,     0,
       0,   231,   227,   229,   232,   161,   185,     0,     0,   216,
     214,   213,     0,   105,     0,   320,     0,   316,   319,     0,
       0,   194,     0,     0,   313,    12,   184,    31,   180,   177,
       5,    38,     0,     0,     0,    49,    88,   101,     0,     0,
      28,    29,     0,     0,     0,     0,     5,    36,    37,    53,
      54,    55,     0,    58,    59,     0,    62,    63,     0,    68,
      69,    66,    67,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,   193,   192,   250,   224,     0,   219,   220,
       0,     0,   234,    44,     0,     0,   230,     0,     0,     0,
     197,   217,   212,   118,   120,   266,   256,   119,     0,   321,
       0,   198,    44,     0,     0,   209,     0,     0,   153,   156,
     158,     0,    32,     0,     0,   176,     0,     0,     0,   270,
       0,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    90,     0,     7,     0,     0,    22,     0,    33,     0,
       0,     0,     0,    52,    57,    61,    65,    71,    75,    77,
      79,    81,    83,     0,     0,   222,   231,   223,   251,     0,
     233,     0,     0,   235,   241,     0,   240,     0,   252,     0,
       0,   242,    44,     0,     0,     0,     0,   257,   259,     0,
       0,   266,   263,     0,   317,     0,     0,   199,   206,     0,
     205,    44,     0,   225,     0,   210,   211,     0,   147,   154,
     155,   163,     0,   181,   173,     0,    39,    40,     0,     2,
     142,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,   280,   287,     0,   285,   286,     0,   269,   270,
     282,   272,   273,   274,   275,     6,    89,   102,   266,    50,
      23,     0,    21,    25,    27,     0,     0,   218,   221,   237,
       0,     0,   239,   253,     0,     0,   243,   249,     0,   248,
       0,     0,     0,   266,   254,   258,   262,   264,     0,   201,
       0,     0,   202,   204,   208,     0,   149,     0,   167,   183,
       0,   178,     0,     0,    16,     0,   270,   270,     0,   270,
       0,     0,     0,   270,     0,     0,   307,   308,   309,     0,
     288,   271,   281,   283,    31,    34,    86,   236,   238,   245,
       0,     0,   246,   268,   265,   255,   261,     0,   267,   200,
     203,   226,   167,   157,   164,     0,   171,   179,     0,    15,
       0,     0,     0,   276,   277,   270,   279,     0,     0,     0,
       0,   304,   304,     0,   306,   310,   284,    32,     0,     0,
     244,   247,   260,   165,     0,     0,    19,    17,    18,   278,
     289,   270,   295,     0,   305,     0,     0,   300,    30,    87,
     166,   168,     0,   270,   291,   270,     0,   304,   304,   270,
     170,   292,   296,     0,   303,   302,   301,   293,   290,   298,
     270,     0,   294,   299
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,   -88,  -428,
    -428,  -428,   -61,  -428,   -52,  -428,  -428,   -90,   189,  -428,
     203,  -428,   194,  -428,   192,  -428,   193,  -428,   197,   204,
     198,   205,  -428,   -51,  -428,  -428,    97,  -428,   -72,   -55,
     -57,    30,  -428,   263,  -428,     7,  -428,  -428,  -428,  -428,
     157,  -207,  -428,   -43,  -428,  -428,  -428,   -58,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,   160,  -223,  -428,  -428,     1,
    -428,  -428,   -33,   -62,  -428,  -428,   -36,   -95,  -168,  -428,
     107,  -428,    -5,  -428,   -38,  -110,  -126,    34,  -352,  -428,
      98,  -428,  -129,  -209,  -428,  -428,  -199,  -428,  -428,    52,
     -16,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -427,  -428,  -428,  -428,   325,  -428,  -428,  -428,  -428
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    96,   154,    97,   146,    98,    99,   403,   404,   100,
     164,   165,   233,   257,   155,   102,   103,   104,   105,   172,
     106,   175,   107,   178,   108,   183,   109,   186,   110,   111,
     112,   113,   114,   156,   192,   469,   157,   252,   344,   116,
      35,   136,    62,    63,    37,    38,    39,   143,   142,    40,
     227,   228,   321,    54,   397,   398,   490,   444,   445,   475,
      41,    50,    51,   149,   235,   147,   148,   231,    42,    43,
      44,    45,   128,    65,   140,   314,    66,   131,   197,   198,
     199,   316,   405,   122,   200,   124,   298,   299,   300,   301,
     302,   303,    46,   346,   347,   348,   240,   349,   466,   350,
     351,   352,   493,   508,   510,   353,   495,   413,   511,   499,
     463,   485,   354,    47,    75,    48,    49,   218,   137,   138
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   115,   127,    64,   141,   101,   115,   135,   217,   323,
     118,   206,   125,   168,   230,    58,   123,   158,   121,   304,
     319,   191,    56,    58,   130,   205,    58,    69,    55,    58,
      36,   437,   151,    52,    53,   486,   145,   132,   254,   289,
    -174,   362,   254,   383,   224,   179,   180,   117,   442,   384,
     167,   101,    57,    55,    55,   254,    55,   315,   133,    53,
      53,   129,    53,   420,    58,    74,   400,    67,    68,   443,
     504,   505,   401,    71,    72,    73,   465,    77,   158,    76,
     169,   219,   263,   121,   159,   170,   171,   126,   173,   174,
      55,   259,  -148,    59,   158,   212,    53,   230,   230,   214,
     229,    59,   -85,   214,   274,    36,   282,    59,   120,   145,
     319,    60,    70,   294,    60,   437,   152,    60,   176,   177,
     101,   129,   447,   101,    61,   306,   101,   181,   182,  -207,
     153,   101,   211,   139,   101,   101,   101,   101,   101,   101,
     129,   187,   274,   188,    55,   236,   120,   237,   421,   196,
      53,    55,   296,    55,   184,   185,   189,    53,   277,    53,
     276,   262,   190,   275,   119,   359,   206,    55,   120,   193,
     386,   119,   207,    53,   385,   120,   208,   323,   -26,   160,
     161,    60,   345,   229,   229,   253,   254,   194,   230,     8,
       9,    10,   360,   361,   209,   375,   210,   453,   454,   225,
     456,   366,   129,   101,   460,   226,   211,   254,   426,   129,
     449,   450,   480,   254,   141,   481,   254,   204,  -182,   482,
     254,   129,   232,    28,   261,   211,   234,    55,    55,   509,
     254,   216,   239,    53,    53,   255,   223,   196,   276,   260,
     278,   382,    60,   273,   101,   115,   479,   279,   162,   283,
     238,   280,   163,   295,   -24,   196,   284,   436,   134,   258,
     307,   308,   324,   320,   322,   326,   327,   399,   328,   419,
     101,   115,   494,   355,   229,   363,   408,   364,   365,   101,
     115,   369,   373,   211,   501,   372,   502,   376,   377,   381,
     506,   129,   345,   388,   389,   211,   392,   393,   281,   394,
     358,   512,   287,   395,   196,   293,   406,   211,   407,   196,
     409,   472,   216,   410,   411,   412,   414,   305,    55,   415,
     416,   312,   417,   427,    53,   428,   429,   432,   434,    55,
     438,   433,   439,   440,   441,    53,   448,   451,   457,   458,
     459,   436,   455,   467,   483,   470,   487,   464,   471,   356,
     474,   357,  -169,   492,   488,   497,   496,   461,   498,   254,
     507,   513,   477,   468,   264,   446,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   211,   266,   267,   370,
     268,   265,   371,   317,   473,   269,   368,   374,   271,   484,
     484,   380,   424,   270,   325,   213,   272,   216,   462,   387,
     144,   423,     0,   390,     0,     0,   391,     0,     0,   446,
       0,     0,     0,     0,     0,     0,     0,   101,   489,   491,
       0,     0,   101,   115,   503,   484,   484,     0,     0,   329,
     452,    79,    80,    81,    82,    83,    84,   500,    85,    86,
     101,   115,     0,     0,     0,     0,     0,   251,     0,     0,
       0,    55,     0,     0,     0,   216,     0,    53,   425,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,     0,     0,   431,     0,     0,     0,     0,
     216,     0,     0,   331,   332,   333,     0,   334,   335,   336,
     337,   338,   339,   340,   341,     0,    87,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,   216,     0,     0,   329,   330,    79,
      80,    81,    82,    83,    84,   476,    85,    86,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,   331,   332,   333,     0,   334,   335,   336,   337,   338,
     339,   340,   341,    26,    87,    27,    28,    88,    29,    30,
      31,    32,    33,    34,     0,    89,     0,     0,     0,     0,
       0,     0,     0,   342,    90,    91,    92,    93,    94,    95,
     329,   330,    79,    80,    81,    82,    83,    84,   343,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,   331,   332,   333,     0,   334,   335,
     336,   337,   338,   339,   340,   341,    26,    87,    27,    28,
      88,    29,    30,    31,    32,    33,    34,     0,    89,     0,
       0,     0,     0,     0,     0,     0,   422,    90,    91,    92,
      93,    94,    95,    78,     1,    79,    80,    81,    82,    83,
      84,   343,    85,    86,     0,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      87,    27,    28,    88,    29,    30,    31,    32,    33,    34,
       0,    89,     0,     0,     0,    87,     0,     0,    88,     0,
      90,    91,    92,    93,    94,    95,    89,     1,     0,     0,
       0,     0,     0,     0,   343,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,     0,    29,    30,    31,
      32,    33,    34,    78,     1,    79,    80,    81,    82,    83,
      84,  -318,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,    27,    28,    88,     0,     0,     0,    32,    33,    34,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,   201,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,   220,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,    28,    88,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,    87,   202,
      28,    88,     0,    90,   203,    92,    93,    94,    95,    89,
       0,     0,     0,     0,   221,     0,     0,     0,    90,   222,
      92,    93,    94,    95,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,    78,
       0,    79,    80,    81,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,   285,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    28,    88,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,    87,   286,    28,    88,
       0,    90,    91,    92,    93,    94,    95,    89,     0,     0,
       0,     0,   291,     0,     0,     0,    90,   292,    92,    93,
      94,    95,    78,     0,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,   309,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,   378,     0,
       0,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,    28,    88,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,    87,   310,    28,    88,     0,    90,
     311,    92,    93,    94,    95,    89,     0,     0,     0,     0,
     379,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,     0,    28,
      88,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,    87,     0,     0,    88,     0,    90,    91,    92,
      93,    94,    95,    89,     0,     0,     0,   296,     0,     0,
     215,   297,    90,    91,    92,    93,    94,    95,    87,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,   296,     0,     0,   215,   435,    90,    91,
      92,    93,    94,    95,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,    78,     0,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,   296,    87,  -266,   215,
      88,    90,    91,    92,    93,    94,    95,     0,    89,     0,
       0,     0,   296,    87,     0,   215,    88,    90,    91,    92,
      93,    94,    95,     0,    89,     0,     0,     0,     0,    87,
       0,   215,    88,    90,    91,    92,    93,    94,    95,     0,
      89,   256,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,    87,     0,
     358,    88,    90,    91,    92,    93,    94,    95,     0,    89,
       0,     0,     0,    87,     0,     0,    88,     0,    90,    91,
      92,    93,    94,    95,   150,    58,     1,     0,    87,     0,
       0,    88,     0,    90,    91,    92,    93,    94,    95,   166,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,    32,
      33,    34,     0,   274,   195,     0,     0,   120,     0,     0,
       0,     0,     0,    60,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,    32,
      33,    34,     0,   119,   195,     0,     0,   120,     0,     0,
       0,     0,     0,    60,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,    30,     0,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,    30,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   396,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   313,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,     0,    31,    32,    33,    34,     0,     0,   288,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,    28,     0,    29,     0,    31,    32,    33,    34,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,    28,     0,    29,    30,    31,    32,    33,
      34,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   367,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,     0,    29,     0,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,     0,    31,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,    30,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     1,     0,   402,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,    32,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,    32,
      33,    34
};

static const yytype_int16 yycheck[] =
{
      52,    52,    57,    36,    66,    57,    57,    64,   134,   232,
      53,   121,    55,   103,   143,     3,    54,    89,    54,   218,
     227,    21,    27,     3,    60,   120,     3,     3,    27,     3,
       0,   383,    84,    81,    27,   462,     3,    83,    83,   207,
       3,    86,    83,    83,   139,    16,    17,    52,    83,    89,
     102,   103,    81,    52,    53,    83,    55,   225,   104,    52,
      53,    60,    55,   104,     3,     0,    83,    37,    38,   104,
     497,   498,    89,    43,    44,    45,   104,     3,   150,    88,
      91,   138,   172,   119,    89,    96,    97,    82,    92,    93,
      89,   163,    88,    81,   166,   131,    89,   226,   227,   132,
     143,    81,   102,   136,    81,    75,   201,    81,    85,     3,
     317,    91,    88,   208,    91,   467,    81,    91,    14,    15,
     172,   120,    89,   175,   104,   220,   178,    98,    99,    81,
      81,   183,   131,    85,   186,   187,   188,   189,   190,   191,
     139,    90,    81,   100,   143,   150,    85,   152,   347,   119,
     143,   150,    85,   152,    18,    19,   101,   150,   196,   152,
     196,   166,    20,   196,    81,   255,   276,   166,    85,    82,
     103,    81,    81,   166,   300,    85,    85,   400,    11,    12,
      13,    91,   239,   226,   227,    82,    83,    82,   317,    38,
      39,    40,    82,    83,    83,   290,    82,   406,   407,    81,
     409,   273,   201,   255,   413,    88,   205,    83,    84,   208,
      82,    83,    82,    83,   276,    82,    83,   120,   103,    82,
      83,   220,    83,    72,    11,   224,    88,   226,   227,    82,
      83,   134,    88,   226,   227,    82,   139,   207,   274,    87,
      82,   296,    91,   102,   296,   296,   455,    83,    81,    86,
     153,    82,    85,     8,    87,   225,    86,   383,   103,   162,
      86,    86,    89,   104,   103,    82,    82,   322,    83,   341,
     322,   322,   481,    82,   317,     3,   331,     3,    82,   331,
     331,    86,    82,   282,   493,    86,   495,    86,    86,    82,
     499,   290,   349,    87,    86,   294,    86,    86,   201,    82,
      88,   510,   205,    83,   274,   208,    84,   306,    84,   279,
      84,   437,   215,    81,    81,    81,    81,   220,   317,     3,
     104,   224,   104,    86,   317,    86,    86,    86,    86,   328,
       3,   104,    86,    86,     3,   328,    84,    84,   410,   411,
     412,   467,    84,    83,    62,    86,    82,   104,    86,   252,
      84,   254,    84,    84,    89,   104,    81,   414,   104,    83,
      60,   104,   450,   424,   175,   398,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   375,   183,   186,   282,
     187,   178,   285,   226,   442,   188,   279,   290,   190,   461,
     462,   294,   358,   189,   234,   132,   191,   300,   414,   301,
      75,   349,    -1,   306,    -1,    -1,   309,    -1,    -1,   442,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,   469,   474,
      -1,    -1,   474,   474,   496,   497,   498,    -1,    -1,     3,
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
     104,    -1,    -1,    -1,   437,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,   448,    12,    13,   451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   467,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
       3,     4,     5,     6,     7,     8,     9,    10,   104,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,     3,     4,     5,     6,     7,     8,     9,
      10,   104,    12,    13,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      90,    91,    92,    93,    94,    95,    81,     4,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,     3,     4,     5,     6,     7,     8,     9,
      10,    88,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    77,    78,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    70,    86,    72,    73,    -1,    90,
      91,    92,    93,    94,    95,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    90,    91,    92,
      93,    94,    95,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    70,    87,    88,
      73,    90,    91,    92,    93,    94,    95,    -1,    81,    -1,
      -1,    -1,    85,    70,    -1,    88,    73,    90,    91,    92,
      93,    94,    95,    -1,    81,    -1,    -1,    -1,    -1,    70,
      -1,    88,    73,    90,    91,    92,    93,    94,    95,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    70,    -1,
      88,    73,    90,    91,    92,    93,    94,    95,    -1,    81,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    90,    91,
      92,    93,    94,    95,    81,     3,     4,    -1,    70,    -1,
      -1,    73,    -1,    90,    91,    92,    93,    94,    95,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    82,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    81,    82,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    75,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    82,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    75,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     4,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,
      78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,    77,    78,    79,   145,   146,   149,   150,   151,
     154,   165,   173,   174,   175,   176,   197,   218,   220,   221,
     166,   167,    81,   150,   158,   174,   187,    81,     3,    81,
      91,   104,   147,   148,   177,   178,   181,   146,   146,     3,
      88,   146,   146,   146,     0,   219,    88,     3,     3,     5,
       6,     7,     8,     9,    10,    12,    13,    70,    73,    81,
      90,    91,    92,    93,    94,    95,   106,   108,   110,   111,
     114,   119,   120,   121,   122,   123,   125,   127,   129,   131,
     133,   134,   135,   136,   137,   138,   144,   187,   158,    81,
      85,   181,   188,   189,   190,   158,    82,   144,   177,   174,
     181,   182,    83,   104,   103,   145,   146,   223,   224,    85,
     179,   178,   153,   152,   220,     3,   109,   170,   171,   168,
      81,   119,    81,    81,   107,   119,   138,   141,   143,   187,
      12,    13,    81,    85,   115,   116,    81,   119,   122,    91,
      96,    97,   124,    92,    93,   126,    14,    15,   128,    16,
      17,    98,    99,   130,    18,    19,   132,    90,   100,   101,
      20,    21,   139,    82,    82,    82,   146,   183,   184,   185,
     189,    34,    86,    91,   141,   182,   190,    81,    85,    83,
      82,   174,   181,   148,   177,    88,   141,   191,   222,   145,
      34,    86,    91,   141,   182,    81,    88,   155,   156,   158,
     197,   172,    83,   117,    88,   169,   187,   187,   141,    88,
     201,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   103,   142,    82,    83,    82,    82,   118,   141,   143,
      87,    11,   187,   122,   123,   125,   127,   129,   131,   133,
     134,   135,   136,   102,    81,   177,   181,   189,    82,    83,
      82,   141,   182,    86,    86,    34,    86,   141,    82,   183,
      34,    86,    91,   141,   182,     8,    85,    89,   191,   192,
     193,   194,   195,   196,   201,   141,   182,    86,    86,    34,
      86,    91,   141,     3,   180,   183,   186,   155,    89,   156,
     104,   157,   103,   171,    89,   170,    82,    82,    83,     3,
       4,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    89,   104,   143,   145,   198,   199,   200,   202,
     204,   205,   206,   210,   217,    82,   141,   141,    88,   122,
      82,    83,    86,     3,     3,    82,   143,    56,   185,    86,
     141,   141,    86,    82,   141,   182,    86,    86,    34,    86,
     141,    82,   144,    83,    89,   191,   103,   195,    87,    86,
     141,   141,    86,    86,    82,    83,    89,   159,   160,   144,
      83,    89,    58,   112,   113,   187,    84,    84,   144,    84,
      81,    81,    81,   212,    81,     3,   104,   104,   104,   143,
     104,   201,    89,   204,   192,   141,    84,    86,    86,    86,
     141,   141,    86,   104,    86,    89,   191,   193,     3,    86,
      86,     3,    83,   104,   162,   163,   177,    89,    84,    82,
      83,    84,     4,   198,   198,    84,   198,   143,   143,   143,
     198,   145,   205,   215,   104,   104,   203,    83,   117,   140,
      86,    86,   191,   162,    84,   164,   141,   113,   141,   198,
      82,    82,    82,    62,   143,   216,   216,    82,    89,   138,
     161,   144,    84,   207,   198,   211,    81,   104,   104,   214,
     144,   198,   198,   143,   216,   216,   198,    60,   208,    82,
     209,   213,   198,   104
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   107,   106,   106,   106,   108,
     108,   108,   109,   110,   110,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   115,   114,   116,   114,   114,   114,
     114,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   139,   140,   138,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   143,   143,   144,   145,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   147,   147,   148,
     148,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   152,   151,   153,   151,
     151,   154,   154,   155,   155,   156,   157,   156,   156,   158,
     158,   158,   158,   160,   159,   161,   159,   163,   162,   164,
     162,   162,   166,   165,   167,   168,   165,   169,   169,   169,
     170,   170,   172,   171,   171,   173,   174,   174,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   179,   178,   180,
     180,   180,   181,   181,   181,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   185,   186,   186,   187,   188,   188,
     189,   189,   189,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   191,   191,   191,   191,   192,   192,
     192,   192,   193,   194,   194,   195,   196,   195,   197,   198,
     199,   198,   198,   198,   198,   198,   200,   200,   200,   200,
     201,   201,   202,   203,   202,   204,   204,   205,   205,   207,
     206,   206,   208,   209,   208,   211,   210,   212,   213,   210,
     214,   210,   215,   215,   216,   216,   217,   217,   217,   217,
     217,   218,   219,   218,   220,   220,   222,   221,   223,   223,
     224,   224
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     0,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     3,     3,     3,
       1,     4,     3,     4,     0,     4,     0,     4,     2,     2,
       7,     0,     1,     1,     3,     1,     2,     2,     2,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     0,     0,     7,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     0,     6,
       2,     1,     1,     1,     2,     2,     0,     4,     1,     2,
       1,     2,     1,     0,     2,     0,     4,     0,     3,     0,
       4,     1,     0,     6,     0,     0,     5,     0,     3,     4,
       1,     3,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     1,     1,     3,     3,     4,
       6,     5,     5,     6,     5,     4,     4,     0,     5,     0,
       1,     1,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     3,     2,     2,     1,     1,     3,     2,     0,     1,
       2,     1,     1,     3,     2,     3,     5,     4,     5,     4,
       3,     3,     3,     4,     6,     5,     5,     6,     4,     4,
       2,     3,     3,     4,     3,     4,     1,     2,     2,     1,
       4,     3,     2,     1,     2,     3,     0,     3,     7,     1,
       0,     2,     1,     1,     1,     1,     3,     3,     4,     3,
       2,     3,     1,     0,     3,     1,     1,     1,     2,     0,
       7,     5,     0,     0,     3,     0,     6,     0,     0,     9,
       0,     6,     4,     4,     0,     1,     3,     2,     2,     2,
       3,     1,     0,     3,     1,     1,     0,     5,     0,     1,
       1,     2
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
#line 151 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2420 "C_grammar.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 156 "C_grammar.y"
              {in_ordinary_id_declaration = 0; current_scope++;}
#line 2426 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' $@1 compound_statement ')'  */
#line 157 "C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2437 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 164 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2447 "C_grammar.tab.c"
    break;

  case 8: /* primary_expression: generic_selection  */
#line 169 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2453 "C_grammar.tab.c"
    break;

  case 14: /* string: FUNC_NAME  */
#line 184 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2459 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 204 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2470 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' ')'  */
#line 211 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2480 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 217 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2491 "C_grammar.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 223 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2497 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression $@2 '.' IDENTIFIER  */
#line 224 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2509 "C_grammar.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 231 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2515 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression $@3 PTR_OP IDENTIFIER  */
#line 232 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2527 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression INC_OP  */
#line 240 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2537 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression DEC_OP  */
#line 246 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2547 "C_grammar.tab.c"
    break;

  case 30: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 252 "C_grammar.y"
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
#line 2565 "C_grammar.tab.c"
    break;

  case 31: /* comma_opt: %empty  */
#line 268 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2571 "C_grammar.tab.c"
    break;

  case 32: /* comma_opt: ','  */
#line 269 "C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2577 "C_grammar.tab.c"
    break;

  case 34: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 276 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2588 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: unary_inc_dec unary_expression  */
#line 287 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2599 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: unary_operator cast_expression  */
#line 294 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2610 "C_grammar.tab.c"
    break;

  case 38: /* unary_expression: SIZEOF unary_expression  */
#line 301 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2620 "C_grammar.tab.c"
    break;

  case 39: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 307 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2630 "C_grammar.tab.c"
    break;

  case 40: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 313 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2640 "C_grammar.tab.c"
    break;

  case 41: /* unary_inc_dec: INC_OP  */
#line 321 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2646 "C_grammar.tab.c"
    break;

  case 42: /* unary_inc_dec: DEC_OP  */
#line 322 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2652 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '&'  */
#line 326 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2658 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '*'  */
#line 327 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2664 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '+'  */
#line 328 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2670 "C_grammar.tab.c"
    break;

  case 46: /* unary_operator: '-'  */
#line 329 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2676 "C_grammar.tab.c"
    break;

  case 47: /* unary_operator: '~'  */
#line 330 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2682 "C_grammar.tab.c"
    break;

  case 48: /* unary_operator: '!'  */
#line 331 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2688 "C_grammar.tab.c"
    break;

  case 50: /* cast_expression: '(' type_name ')' cast_expression  */
#line 337 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2699 "C_grammar.tab.c"
    break;

  case 52: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 348 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2711 "C_grammar.tab.c"
    break;

  case 53: /* multiplicative_expression_op: '*'  */
#line 358 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2717 "C_grammar.tab.c"
    break;

  case 54: /* multiplicative_expression_op: '/'  */
#line 359 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2723 "C_grammar.tab.c"
    break;

  case 55: /* multiplicative_expression_op: '%'  */
#line 360 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2729 "C_grammar.tab.c"
    break;

  case 57: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 366 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2741 "C_grammar.tab.c"
    break;

  case 58: /* additive_expression_op: '+'  */
#line 376 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2747 "C_grammar.tab.c"
    break;

  case 59: /* additive_expression_op: '-'  */
#line 377 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2753 "C_grammar.tab.c"
    break;

  case 61: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 383 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2765 "C_grammar.tab.c"
    break;

  case 62: /* shift_expression_op: LEFT_OP  */
#line 393 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2771 "C_grammar.tab.c"
    break;

  case 63: /* shift_expression_op: RIGHT_OP  */
#line 394 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2777 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 400 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2789 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression_operator: '<'  */
#line 410 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2795 "C_grammar.tab.c"
    break;

  case 67: /* relational_expression_operator: '>'  */
#line 411 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2801 "C_grammar.tab.c"
    break;

  case 68: /* relational_expression_operator: LE_OP  */
#line 412 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2807 "C_grammar.tab.c"
    break;

  case 69: /* relational_expression_operator: GE_OP  */
#line 413 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2813 "C_grammar.tab.c"
    break;

  case 71: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 420 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2825 "C_grammar.tab.c"
    break;

  case 72: /* equality_expression_op: EQ_OP  */
#line 430 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2831 "C_grammar.tab.c"
    break;

  case 73: /* equality_expression_op: NE_OP  */
#line 431 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2837 "C_grammar.tab.c"
    break;

  case 75: /* and_expression: and_expression '&' equality_expression  */
#line 437 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2848 "C_grammar.tab.c"
    break;

  case 77: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 448 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2859 "C_grammar.tab.c"
    break;

  case 79: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 459 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2870 "C_grammar.tab.c"
    break;

  case 81: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 470 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2881 "C_grammar.tab.c"
    break;

  case 83: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 481 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2892 "C_grammar.tab.c"
    break;

  case 85: /* $@4: %empty  */
#line 491 "C_grammar.y"
                               {
		printf("ternary statement\n");
		if(stack_count == 0){
			printf("stack is zero\n");
			push(ctx->isFalse); 
			join_nodes();
		}else{
			push(ctx->isFalse);
		}     
		if(ctx->doWhile > 0){
			top->inDoWhile == true;
		}
		ctx->isFalse = false;
	}
#line 2911 "C_grammar.tab.c"
    break;

  case 86: /* $@5: %empty  */
#line 504 "C_grammar.y"
                            {ctx->isFalse = true;}
#line 2917 "C_grammar.tab.c"
    break;

  case 87: /* conditional_expression: logical_or_expression $@4 '?' expression ':' $@5 conditional_expression  */
#line 505 "C_grammar.y"
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
#line 2932 "C_grammar.tab.c"
    break;

  case 89: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 520 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2944 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: '='  */
#line 530 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2950 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: MUL_ASSIGN  */
#line 531 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2956 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: DIV_ASSIGN  */
#line 532 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2962 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: MOD_ASSIGN  */
#line 533 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2968 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: ADD_ASSIGN  */
#line 534 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2974 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: SUB_ASSIGN  */
#line 535 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2980 "C_grammar.tab.c"
    break;

  case 96: /* assignment_operator: LEFT_ASSIGN  */
#line 536 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2986 "C_grammar.tab.c"
    break;

  case 97: /* assignment_operator: RIGHT_ASSIGN  */
#line 537 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2992 "C_grammar.tab.c"
    break;

  case 98: /* assignment_operator: AND_ASSIGN  */
#line 538 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2998 "C_grammar.tab.c"
    break;

  case 99: /* assignment_operator: XOR_ASSIGN  */
#line 539 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3004 "C_grammar.tab.c"
    break;

  case 100: /* assignment_operator: OR_ASSIGN  */
#line 540 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3010 "C_grammar.tab.c"
    break;

  case 102: /* expression: expression ',' assignment_expression  */
#line 546 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3021 "C_grammar.tab.c"
    break;

  case 104: /* declaration: declaration_specifiers ';'  */
#line 561 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 printf("end of stand alone declaration specifier as a declaration in_ordinary_id_declaration is %d on line %d\n", in_ordinary_id_declaration, yylineno);
		 size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3033 "C_grammar.tab.c"
    break;

  case 105: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 569 "C_grammar.y"
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
#line 3049 "C_grammar.tab.c"
    break;

  case 106: /* declaration: static_assert_declaration  */
#line 581 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3060 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 592 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3072 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: storage_class_specifier  */
#line 600 "C_grammar.y"
                {in_ordinary_id_declaration = 1;}
#line 3078 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 602 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3090 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: type_specifier  */
#line 610 "C_grammar.y"
                {in_ordinary_id_declaration = 1;}
#line 3096 "C_grammar.tab.c"
    break;

  case 111: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 612 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3108 "C_grammar.tab.c"
    break;

  case 112: /* declaration_specifiers: type_qualifier  */
#line 619 "C_grammar.y"
                         {in_ordinary_id_declaration = 1;}
#line 3114 "C_grammar.tab.c"
    break;

  case 113: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 621 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); 
		}
#line 3122 "C_grammar.tab.c"
    break;

  case 114: /* declaration_specifiers: function_specifier  */
#line 625 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); 
		}
#line 3130 "C_grammar.tab.c"
    break;

  case 115: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 629 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); 
		}
#line 3138 "C_grammar.tab.c"
    break;

  case 116: /* declaration_specifiers: alignment_specifier  */
#line 633 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); 
		}
#line 3146 "C_grammar.tab.c"
    break;

  case 117: /* init_declarator_list: init_declarator  */
#line 640 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 (yyval.id) = (yyvsp[0].id);
		}
#line 3154 "C_grammar.tab.c"
    break;

  case 118: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 644 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3166 "C_grammar.tab.c"
    break;

  case 119: /* init_declarator: declarator '=' initializer  */
#line 655 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));
	  	}
#line 3178 "C_grammar.tab.c"
    break;

  case 120: /* init_declarator: declarator  */
#line 663 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_id(current_scope, (yyvsp[0].declarator_type).ptr_declarator, 1);	//the id as a TYPEDEF_NAME is added to the data structures keeping track of typedef_names and ids shadowing
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3189 "C_grammar.tab.c"
    break;

  case 121: /* storage_class_specifier: TYPEDEF  */
#line 673 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3198 "C_grammar.tab.c"
    break;

  case 122: /* storage_class_specifier: EXTERN  */
#line 677 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3204 "C_grammar.tab.c"
    break;

  case 123: /* storage_class_specifier: STATIC  */
#line 678 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3210 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: THREAD_LOCAL  */
#line 679 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3216 "C_grammar.tab.c"
    break;

  case 125: /* storage_class_specifier: AUTO  */
#line 680 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3222 "C_grammar.tab.c"
    break;

  case 126: /* storage_class_specifier: REGISTER  */
#line 681 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3228 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: VOID  */
#line 685 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "void"); }
#line 3234 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: CHAR  */
#line 686 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "char"); }
#line 3240 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: SHORT  */
#line 687 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "short"); }
#line 3246 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: INT  */
#line 688 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int"); }
#line 3252 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: LONG  */
#line 689 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "long"); }
#line 3258 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: FLOAT  */
#line 690 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float"); }
#line 3264 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: DOUBLE  */
#line 691 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "double"); }
#line 3270 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: SIGNED  */
#line 692 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3276 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: UNSIGNED  */
#line 693 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3282 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: BOOL  */
#line 694 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3288 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: COMPLEX  */
#line 695 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3294 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: IMAGINARY  */
#line 696 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3300 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: atomic_type_specifier  */
#line 697 "C_grammar.y"
                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3306 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: struct_or_union_specifier  */
#line 698 "C_grammar.y"
                                    { in_ordinary_id_declaration = 1; }
#line 3312 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: enum_specifier  */
#line 699 "C_grammar.y"
                                        { in_ordinary_id_declaration = 1; }
#line 3318 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: TYPEDEF_NAME  */
#line 701 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3327 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: INT128  */
#line 705 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int128"); }
#line 3333 "C_grammar.tab.c"
    break;

  case 144: /* type_specifier: FLOAT128  */
#line 706 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float128"); }
#line 3339 "C_grammar.tab.c"
    break;

  case 145: /* type_specifier: VA_LIST  */
#line 707 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "va_list"); }
#line 3345 "C_grammar.tab.c"
    break;

  case 146: /* $@6: %empty  */
#line 711 "C_grammar.y"
                              {in_tag_declaration = 0;}
#line 3351 "C_grammar.tab.c"
    break;

  case 147: /* struct_or_union_specifier: struct_or_union '{' $@6 struct_declaration_list '}'  */
#line 712 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3362 "C_grammar.tab.c"
    break;

  case 148: /* $@7: %empty  */
#line 718 "C_grammar.y"
                                     {in_tag_declaration = 0;}
#line 3368 "C_grammar.tab.c"
    break;

  case 149: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@7 '{' struct_declaration_list '}'  */
#line 719 "C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3382 "C_grammar.tab.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 729 "C_grammar.y"
                {in_tag_declaration = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3396 "C_grammar.tab.c"
    break;

  case 151: /* struct_or_union: STRUCT  */
#line 742 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_declaration = 1;
		}
#line 3404 "C_grammar.tab.c"
    break;

  case 152: /* struct_or_union: UNION  */
#line 746 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_declaration = 1;
		}
#line 3412 "C_grammar.tab.c"
    break;

  case 154: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 754 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3423 "C_grammar.tab.c"
    break;

  case 155: /* struct_declaration: specifier_qualifier_list ';'  */
#line 764 "C_grammar.y"
                {size_t const size = strlen("anonymous_member()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3433 "C_grammar.tab.c"
    break;

  case 156: /* $@8: %empty  */
#line 770 "C_grammar.y"
                                   {in_member_namespace = 1;}
#line 3439 "C_grammar.tab.c"
    break;

  case 157: /* struct_declaration: specifier_qualifier_list $@8 struct_declarator_list ';'  */
#line 771 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3451 "C_grammar.tab.c"
    break;

  case 159: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 783 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3462 "C_grammar.tab.c"
    break;

  case 161: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 791 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3473 "C_grammar.tab.c"
    break;

  case 163: /* $@9: %empty  */
#line 801 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3479 "C_grammar.tab.c"
    break;

  case 164: /* struct_declarator_list: $@9 struct_declarator  */
#line 801 "C_grammar.y"
                                                       {(yyval.id)= (yyvsp[0].id); in_member_namespace = 1;}
#line 3485 "C_grammar.tab.c"
    break;

  case 165: /* $@10: %empty  */
#line 802 "C_grammar.y"
                                                       {in_member_namespace = 1;}
#line 3491 "C_grammar.tab.c"
    break;

  case 166: /* struct_declarator_list: struct_declarator_list ',' struct_declarator $@10  */
#line 803 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
        }
#line 3502 "C_grammar.tab.c"
    break;

  case 167: /* $@11: %empty  */
#line 812 "C_grammar.y"
          {in_member_namespace = 0;}
#line 3508 "C_grammar.tab.c"
    break;

  case 168: /* struct_declarator: $@11 ':' constant_expression  */
#line 813 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3518 "C_grammar.tab.c"
    break;

  case 169: /* $@12: %empty  */
#line 818 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 3524 "C_grammar.tab.c"
    break;

  case 170: /* struct_declarator: declarator $@12 ':' constant_expression  */
#line 819 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3536 "C_grammar.tab.c"
    break;

  case 171: /* struct_declarator: declarator  */
#line 827 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3545 "C_grammar.tab.c"
    break;

  case 172: /* $@13: %empty  */
#line 834 "C_grammar.y"
               {in_ordinary_id_declaration = 1;}
#line 3551 "C_grammar.tab.c"
    break;

  case 173: /* enum_specifier: ENUM $@13 '{' enumerator_list comma_opt '}'  */
#line 835 "C_grammar.y"
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
#line 3569 "C_grammar.tab.c"
    break;

  case 174: /* $@14: %empty  */
#line 848 "C_grammar.y"
               {in_tag_declaration = 1;}
#line 3575 "C_grammar.tab.c"
    break;

  case 175: /* $@15: %empty  */
#line 848 "C_grammar.y"
                                                    {in_tag_declaration = 0; in_ordinary_id_declaration = 1;}
#line 3581 "C_grammar.tab.c"
    break;

  case 176: /* enum_specifier: ENUM $@14 IDENTIFIER $@15 enum_specifier_rest  */
#line 849 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3593 "C_grammar.tab.c"
    break;

  case 177: /* enum_specifier_rest: %empty  */
#line 860 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3599 "C_grammar.tab.c"
    break;

  case 178: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 862 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3605 "C_grammar.tab.c"
    break;

  case 179: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 864 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3615 "C_grammar.tab.c"
    break;

  case 180: /* enumerator_list: enumerator  */
#line 872 "C_grammar.y"
                     {in_ordinary_id_declaration = 1;}
#line 3621 "C_grammar.tab.c"
    break;

  case 181: /* enumerator_list: enumerator_list ',' enumerator  */
#line 874 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3633 "C_grammar.tab.c"
    break;

  case 182: /* $@16: %empty  */
#line 884 "C_grammar.y"
                               {in_ordinary_id_declaration = 0;}
#line 3639 "C_grammar.tab.c"
    break;

  case 183: /* enumerator: enumeration_constant $@16 '=' constant_expression  */
#line 885 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[0].id));
        }
#line 3650 "C_grammar.tab.c"
    break;

  case 186: /* type_qualifier: CONST  */
#line 899 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3656 "C_grammar.tab.c"
    break;

  case 187: /* type_qualifier: RESTRICT  */
#line 900 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3662 "C_grammar.tab.c"
    break;

  case 188: /* type_qualifier: VOLATILE  */
#line 901 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3668 "C_grammar.tab.c"
    break;

  case 189: /* type_qualifier: ATOMIC  */
#line 902 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3674 "C_grammar.tab.c"
    break;

  case 190: /* function_specifier: INLINE  */
#line 906 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3680 "C_grammar.tab.c"
    break;

  case 191: /* function_specifier: NORETURN  */
#line 907 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3686 "C_grammar.tab.c"
    break;

  case 194: /* declarator: pointer direct_declarator  */
#line 918 "C_grammar.y"
          {in_ordinary_id_declaration = 0;
	   size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3699 "C_grammar.tab.c"
    break;

  case 195: /* declarator: direct_declarator  */
#line 926 "C_grammar.y"
                            {in_ordinary_id_declaration = 0;}
#line 3705 "C_grammar.tab.c"
    break;

  case 196: /* direct_declarator: IDENTIFIER  */
#line 931 "C_grammar.y"
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
#line 3732 "C_grammar.tab.c"
    break;

  case 197: /* direct_declarator: '(' declarator ')'  */
#line 955 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-1].declarator_type);}
#line 3738 "C_grammar.tab.c"
    break;

  case 198: /* direct_declarator: direct_declarator '[' ']'  */
#line 957 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3749 "C_grammar.tab.c"
    break;

  case 199: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 964 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3758 "C_grammar.tab.c"
    break;

  case 200: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 969 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3767 "C_grammar.tab.c"
    break;

  case 201: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 974 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3776 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 979 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3785 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 984 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3794 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 989 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3803 "C_grammar.tab.c"
    break;

  case 205: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 994 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3812 "C_grammar.tab.c"
    break;

  case 206: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 999 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3824 "C_grammar.tab.c"
    break;

  case 207: /* $@17: %empty  */
#line 1006 "C_grammar.y"
                            {in_ordinary_id_declaration = 0; if (!typedef_flag) current_scope++; }
#line 3830 "C_grammar.tab.c"
    break;

  case 208: /* direct_declarator: direct_declarator $@17 '(' rest_function_definition ')'  */
#line 1007 "C_grammar.y"
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
#line 3845 "C_grammar.tab.c"
    break;

  case 209: /* rest_function_definition: %empty  */
#line 1020 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 3851 "C_grammar.tab.c"
    break;

  case 211: /* rest_function_definition: old_style_parameter_list  */
#line 1022 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 3857 "C_grammar.tab.c"
    break;

  case 212: /* pointer: '*' type_qualifier_list pointer  */
#line 1027 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3868 "C_grammar.tab.c"
    break;

  case 213: /* pointer: '*' type_qualifier_list  */
#line 1034 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3878 "C_grammar.tab.c"
    break;

  case 214: /* pointer: '*' pointer  */
#line 1040 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3888 "C_grammar.tab.c"
    break;

  case 215: /* pointer: '*'  */
#line 1046 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3894 "C_grammar.tab.c"
    break;

  case 217: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1052 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3905 "C_grammar.tab.c"
    break;

  case 218: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1062 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3915 "C_grammar.tab.c"
    break;

  case 219: /* parameter_type_list: parameter_list  */
#line 1068 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3925 "C_grammar.tab.c"
    break;

  case 221: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1078 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3936 "C_grammar.tab.c"
    break;

  case 222: /* parameter_declaration: declaration_specifiers declarator  */
#line 1088 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3948 "C_grammar.tab.c"
    break;

  case 223: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1096 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3959 "C_grammar.tab.c"
    break;

  case 224: /* parameter_declaration: declaration_specifiers  */
#line 1103 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3969 "C_grammar.tab.c"
    break;

  case 227: /* type_name: specifier_qualifier_list abstract_declarator_opt  */
#line 1117 "C_grammar.y"
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
#line 3984 "C_grammar.tab.c"
    break;

  case 228: /* abstract_declarator_opt: %empty  */
#line 1130 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 3990 "C_grammar.tab.c"
    break;

  case 229: /* abstract_declarator_opt: abstract_declarator  */
#line 1131 "C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 3996 "C_grammar.tab.c"
    break;

  case 254: /* initializer: '{' initializer_list '}'  */
#line 1166 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4006 "C_grammar.tab.c"
    break;

  case 255: /* initializer: '{' initializer_list ',' '}'  */
#line 1172 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 4016 "C_grammar.tab.c"
    break;

  case 257: /* initializer: '{' '}'  */
#line 1179 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 4022 "C_grammar.tab.c"
    break;

  case 258: /* initializer_list: designation initializer  */
#line 1184 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4033 "C_grammar.tab.c"
    break;

  case 260: /* initializer_list: initializer_list ',' designation initializer  */
#line 1192 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4045 "C_grammar.tab.c"
    break;

  case 261: /* initializer_list: initializer_list ',' initializer  */
#line 1200 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4056 "C_grammar.tab.c"
    break;

  case 262: /* designation: designator_list '='  */
#line 1210 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4066 "C_grammar.tab.c"
    break;

  case 264: /* designator_list: designator_list designator  */
#line 1220 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4077 "C_grammar.tab.c"
    break;

  case 265: /* designator: '[' constant_expression ']'  */
#line 1230 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4087 "C_grammar.tab.c"
    break;

  case 266: /* $@18: %empty  */
#line 1235 "C_grammar.y"
          {in_member_namespace = 1;}
#line 4093 "C_grammar.tab.c"
    break;

  case 267: /* designator: $@18 '.' IDENTIFIER  */
#line 1236 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4104 "C_grammar.tab.c"
    break;

  case 268: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1246 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4115 "C_grammar.tab.c"
    break;

  case 270: /* $@19: %empty  */
#line 1256 "C_grammar.y"
          {in_ordinary_id_declaration = 0; current_scope++;}
#line 4121 "C_grammar.tab.c"
    break;

  case 271: /* statement: $@19 compound_statement  */
#line 1257 "C_grammar.y"
                {pop_scope(&current_scope);
		 (yyval.id) = (yyvsp[0].id);
		}
#line 4129 "C_grammar.tab.c"
    break;

  case 276: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1268 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4140 "C_grammar.tab.c"
    break;

  case 277: /* labeled_statement: TYPEDEF_NAME ':' statement  */
#line 1276 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4151 "C_grammar.tab.c"
    break;

  case 278: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1283 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4162 "C_grammar.tab.c"
    break;

  case 279: /* labeled_statement: DEFAULT ':' statement  */
#line 1290 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4172 "C_grammar.tab.c"
    break;

  case 280: /* compound_statement: '{' '}'  */
#line 1298 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4178 "C_grammar.tab.c"
    break;

  case 281: /* compound_statement: '{' block_item_list '}'  */
#line 1300 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4188 "C_grammar.tab.c"
    break;

  case 282: /* block_item_list: block_item  */
#line 1308 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 4194 "C_grammar.tab.c"
    break;

  case 283: /* $@20: %empty  */
#line 1309 "C_grammar.y"
                                     {in_ordinary_id_declaration = 0;}
#line 4200 "C_grammar.tab.c"
    break;

  case 284: /* block_item_list: block_item_list block_item $@20  */
#line 1310 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	  }
#line 4211 "C_grammar.tab.c"
    break;

  case 287: /* expression_statement: ';'  */
#line 1324 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4217 "C_grammar.tab.c"
    break;

  case 288: /* expression_statement: expression ';'  */
#line 1326 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4227 "C_grammar.tab.c"
    break;

  case 289: /* $@21: %empty  */
#line 1334 "C_grammar.y"
                               {
		push(ctx->isFalse);
		join_nodes();
		if(ctx->doWhile){
			top->inDoWhile = true;
		}
		ctx->isFalse = false;
		}
#line 4241 "C_grammar.tab.c"
    break;

  case 290: /* selection_statement: IF '(' expression ')' $@21 statement else_opt  */
#line 1343 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 pop(branch_nb);
		 attach_start(dot_file);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4255 "C_grammar.tab.c"
    break;

  case 291: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1353 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4266 "C_grammar.tab.c"
    break;

  case 292: /* else_opt: %empty  */
#line 1362 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4272 "C_grammar.tab.c"
    break;

  case 293: /* $@22: %empty  */
#line 1363 "C_grammar.y"
              {
			ctx->isFalse = true;
			}
#line 4280 "C_grammar.tab.c"
    break;

  case 294: /* else_opt: ELSE $@22 statement  */
#line 1367 "C_grammar.y"
                {
		 size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 ctx->isFalse = false;
		 free((yyvsp[0].id));
		}
#line 4292 "C_grammar.tab.c"
    break;

  case 295: /* $@23: %empty  */
#line 1375 "C_grammar.y"
                                  { 
		push(ctx->isFalse);
		join_nodes();
		ctx->isFalse = false;
		}
#line 4302 "C_grammar.tab.c"
    break;

  case 296: /* iteration_statement: WHILE '(' expression ')' $@23 statement  */
#line 1380 "C_grammar.y"
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
#line 4320 "C_grammar.tab.c"
    break;

  case 297: /* $@24: %empty  */
#line 1393 "C_grammar.y"
             {ctx->doWhile = true;}
#line 4326 "C_grammar.tab.c"
    break;

  case 298: /* $@25: %empty  */
#line 1393 "C_grammar.y"
                                                                      {
		push(ctx->isFalse);
		join_nodes();
		ctx->isFalse = false;}
#line 4335 "C_grammar.tab.c"
    break;

  case 299: /* iteration_statement: DO $@24 statement WHILE '(' expression ')' $@25 ';'  */
#line 1397 "C_grammar.y"
                { Node *temp = head;
		while (temp != NULL) {
			if (temp->inDoWhile) {
				break;  // Stop when we find a node with inDoWhile == true
			}
			temp = temp->next_node;
		}

		if(temp == NULL){
			printf("ctx->dowhile false \n");
			top->true_path = top;
		}else{
			top->true_path = temp;
			temp->inDoWhile = false;
		}
		 pop(branch_nb);
		 attach_start(dot_file);
		 ctx->doWhile=false;
		 printf("do while loop poped %d\n", branch_nb);
		 size_t const size = strlen("\ndo_while_stmt(, )") + strlen((yyvsp[-6].id)) + strlen((yyvsp[-3].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-6].id), branch_nb++, (yyvsp[-3].id));
		 free((yyvsp[-6].id));
		 free((yyvsp[-3].id));
		}
#line 4365 "C_grammar.tab.c"
    break;

  case 300: /* $@26: %empty  */
#line 1422 "C_grammar.y"
                                    {
		push(ctx->isFalse);
		join_nodes();
		ctx->isFalse = false;
		}
#line 4375 "C_grammar.tab.c"
    break;

  case 301: /* iteration_statement: FOR '(' for_stmt_type ')' $@26 statement  */
#line 1427 "C_grammar.y"
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
#line 4395 "C_grammar.tab.c"
    break;

  case 302: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1446 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4401 "C_grammar.tab.c"
    break;

  case 303: /* for_stmt_type: declaration expression_opt ';' expression_opt  */
#line 1448 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4407 "C_grammar.tab.c"
    break;

  case 304: /* expression_opt: %empty  */
#line 1452 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4413 "C_grammar.tab.c"
    break;

  case 306: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1457 "C_grammar.y"
          {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4424 "C_grammar.tab.c"
    break;

  case 307: /* jump_statement: CONTINUE ';'  */
#line 1463 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4430 "C_grammar.tab.c"
    break;

  case 308: /* jump_statement: BREAK ';'  */
#line 1464 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4436 "C_grammar.tab.c"
    break;

  case 309: /* jump_statement: RETURN ';'  */
#line 1465 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4442 "C_grammar.tab.c"
    break;

  case 310: /* jump_statement: RETURN expression ';'  */
#line 1467 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4452 "C_grammar.tab.c"
    break;

  case 312: /* $@27: %empty  */
#line 1477 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4458 "C_grammar.tab.c"
    break;

  case 314: /* external_declaration: function_definition  */
#line 1482 "C_grammar.y"
                {handled_function_paramaters = 0;
		 pop_scope(&current_scope);
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4468 "C_grammar.tab.c"
    break;

  case 315: /* external_declaration: declaration  */
#line 1488 "C_grammar.y"
                {if (handled_function_paramaters == 666) handled_function_paramaters = 0; 
		else if(handled_function_paramaters) {
			handled_function_paramaters = 0;
			pop_scope(&current_scope);
		 }
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4481 "C_grammar.tab.c"
    break;

  case 316: /* $@28: %empty  */
#line 1499 "C_grammar.y"
                                                                 {in_ordinary_id_declaration = 0;}
#line 4487 "C_grammar.tab.c"
    break;

  case 317: /* function_definition: declaration_specifiers declarator declaration_list_opt $@28 compound_statement  */
#line 1500 "C_grammar.y"
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
#line 4502 "C_grammar.tab.c"
    break;

  case 318: /* declaration_list_opt: %empty  */
#line 1513 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4508 "C_grammar.tab.c"
    break;

  case 321: /* old_style_declaration_list: old_style_declaration_list declaration  */
#line 1520 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4519 "C_grammar.tab.c"
    break;


#line 4523 "C_grammar.tab.c"

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

#line 1528 "C_grammar.y"

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

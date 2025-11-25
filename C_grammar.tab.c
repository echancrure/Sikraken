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
#line 7 "Parser/C_grammar.y"


int debugMode = 0;					//flag to indicate if we are in debug mode set by -d command line switch

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser.h"
#include "utils.h"
#include "hash_table.h"
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

#line 120 "C_grammar.tab.c"

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
  YYSYMBOL_TYPEOF = 80,                    /* TYPEOF  */
  YYSYMBOL_TYPEOF_UNQUAL = 81,             /* TYPEOF_UNQUAL  */
  YYSYMBOL_LOWER_THAN_ELSE = 82,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_83_ = 83,                       /* '('  */
  YYSYMBOL_84_ = 84,                       /* ')'  */
  YYSYMBOL_85_ = 85,                       /* ','  */
  YYSYMBOL_86_ = 86,                       /* ':'  */
  YYSYMBOL_87_ = 87,                       /* '['  */
  YYSYMBOL_88_ = 88,                       /* ']'  */
  YYSYMBOL_89_ = 89,                       /* '.'  */
  YYSYMBOL_90_ = 90,                       /* '{'  */
  YYSYMBOL_91_ = 91,                       /* '}'  */
  YYSYMBOL_92_ = 92,                       /* '&'  */
  YYSYMBOL_93_ = 93,                       /* '*'  */
  YYSYMBOL_94_ = 94,                       /* '+'  */
  YYSYMBOL_95_ = 95,                       /* '-'  */
  YYSYMBOL_96_ = 96,                       /* '~'  */
  YYSYMBOL_97_ = 97,                       /* '!'  */
  YYSYMBOL_98_ = 98,                       /* '/'  */
  YYSYMBOL_99_ = 99,                       /* '%'  */
  YYSYMBOL_100_ = 100,                     /* '<'  */
  YYSYMBOL_101_ = 101,                     /* '>'  */
  YYSYMBOL_102_ = 102,                     /* '^'  */
  YYSYMBOL_103_ = 103,                     /* '|'  */
  YYSYMBOL_104_ = 104,                     /* '?'  */
  YYSYMBOL_105_ = 105,                     /* '='  */
  YYSYMBOL_106_ = 106,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 107,                 /* $accept  */
  YYSYMBOL_primary_expression = 108,       /* primary_expression  */
  YYSYMBOL_109_1 = 109,                    /* $@1  */
  YYSYMBOL_constant = 110,                 /* constant  */
  YYSYMBOL_enumeration_constant = 111,     /* enumeration_constant  */
  YYSYMBOL_string = 112,                   /* string  */
  YYSYMBOL_generic_selection = 113,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 114,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 115,      /* generic_association  */
  YYSYMBOL_postfix_expression = 116,       /* postfix_expression  */
  YYSYMBOL_117_2 = 117,                    /* $@2  */
  YYSYMBOL_118_3 = 118,                    /* $@3  */
  YYSYMBOL_comma_opt = 119,                /* comma_opt  */
  YYSYMBOL_argument_expression_list = 120, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 121,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 122,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 123,           /* unary_operator  */
  YYSYMBOL_cast_expression = 124,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 125, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 126, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 127,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 128,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 129,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 130,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 131,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 132, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 133,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 134,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 135,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 136,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 137,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 138,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 139,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 140,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 141,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 142,      /* assignment_operator  */
  YYSYMBOL_expression = 143,               /* expression  */
  YYSYMBOL_constant_expression = 144,      /* constant_expression  */
  YYSYMBOL_declaration = 145,              /* declaration  */
  YYSYMBOL_146_4 = 146,                    /* $@4  */
  YYSYMBOL_147_5 = 147,                    /* $@5  */
  YYSYMBOL_type_declaration_specifiers = 148, /* type_declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 149,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 150,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 151,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 152,           /* type_specifier  */
  YYSYMBOL_typeof_specifier = 153,         /* typeof_specifier  */
  YYSYMBOL_rest_typeof_specifier = 154,    /* rest_typeof_specifier  */
  YYSYMBOL_struct_or_union_specifier = 155, /* struct_or_union_specifier  */
  YYSYMBOL_set_tag0 = 156,                 /* set_tag0  */
  YYSYMBOL_tag_name = 157,                 /* tag_name  */
  YYSYMBOL_struct_or_union = 158,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 159,  /* struct_declaration_list  */
  YYSYMBOL_160_6 = 160,                    /* $@6  */
  YYSYMBOL_161_7 = 161,                    /* $@7  */
  YYSYMBOL_struct_declaration = 162,       /* struct_declaration  */
  YYSYMBOL_163_8 = 163,                    /* $@8  */
  YYSYMBOL_164_9 = 164,                    /* $@9  */
  YYSYMBOL_specifier_qualifier_list = 165, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 166,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 167,        /* struct_declarator  */
  YYSYMBOL_168_10 = 168,                   /* $@10  */
  YYSYMBOL_169_11 = 169,                   /* $@11  */
  YYSYMBOL_enum_specifier = 170,           /* enum_specifier  */
  YYSYMBOL_171_12 = 171,                   /* $@12  */
  YYSYMBOL_enum_tag_name = 172,            /* enum_tag_name  */
  YYSYMBOL_enum_specifier_rest = 173,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 174,          /* enumerator_list  */
  YYSYMBOL_enumerator = 175,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 176,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 177,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 178,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 179,      /* alignment_specifier  */
  YYSYMBOL_declarator = 180,               /* declarator  */
  YYSYMBOL_direct_declarator = 181,        /* direct_declarator  */
  YYSYMBOL_182_13 = 182,                   /* $@13  */
  YYSYMBOL_rest_direct_declarator = 183,   /* rest_direct_declarator  */
  YYSYMBOL_rest_function_definition = 184, /* rest_function_definition  */
  YYSYMBOL_old_style_parameter_list = 185, /* old_style_parameter_list  */
  YYSYMBOL_parameter_type_list = 186,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 187,           /* parameter_list  */
  YYSYMBOL_188_14 = 188,                   /* $@14  */
  YYSYMBOL_189_15 = 189,                   /* $@15  */
  YYSYMBOL_parameter_declaration = 190,    /* parameter_declaration  */
  YYSYMBOL_pointer = 191,                  /* pointer  */
  YYSYMBOL_pointer_star = 192,             /* pointer_star  */
  YYSYMBOL_193_16 = 193,                   /* $@16  */
  YYSYMBOL_type_qualifier_list = 194,      /* type_qualifier_list  */
  YYSYMBOL_type_name = 195,                /* type_name  */
  YYSYMBOL_196_17 = 196,                   /* $@17  */
  YYSYMBOL_abstract_declarator_opt = 197,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 198,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 199, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 200,              /* initializer  */
  YYSYMBOL_initializer_list = 201,         /* initializer_list  */
  YYSYMBOL_designation = 202,              /* designation  */
  YYSYMBOL_designator_list = 203,          /* designator_list  */
  YYSYMBOL_designator = 204,               /* designator  */
  YYSYMBOL_205_18 = 205,                   /* $@18  */
  YYSYMBOL_static_assert_declaration = 206, /* static_assert_declaration  */
  YYSYMBOL_207_19 = 207,                   /* $@19  */
  YYSYMBOL_statement = 208,                /* statement  */
  YYSYMBOL_209_20 = 209,                   /* $@20  */
  YYSYMBOL_labeled_statement = 210,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 211,       /* compound_statement  */
  YYSYMBOL_block_item_list = 212,          /* block_item_list  */
  YYSYMBOL_213_21 = 213,                   /* $@21  */
  YYSYMBOL_214_22 = 214,                   /* $@22  */
  YYSYMBOL_block_item = 215,               /* block_item  */
  YYSYMBOL_expression_statement = 216,     /* expression_statement  */
  YYSYMBOL_selection_statement = 217,      /* selection_statement  */
  YYSYMBOL_else_opt = 218,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 219,      /* iteration_statement  */
  YYSYMBOL_for_stmt_type = 220,            /* for_stmt_type  */
  YYSYMBOL_221_23 = 221,                   /* $@23  */
  YYSYMBOL_expression_opt = 222,           /* expression_opt  */
  YYSYMBOL_jump_statement = 223,           /* jump_statement  */
  YYSYMBOL_translation_unit = 224,         /* translation_unit  */
  YYSYMBOL_225_24 = 225,                   /* $@24  */
  YYSYMBOL_226_25 = 226,                   /* $@25  */
  YYSYMBOL_external_declaration = 227,     /* external_declaration  */
  YYSYMBOL_function_definition = 228,      /* function_definition  */
  YYSYMBOL_229_26 = 229,                   /* $@26  */
  YYSYMBOL_declaration_list_opt = 230,     /* declaration_list_opt  */
  YYSYMBOL_old_style_declaration_list = 231, /* old_style_declaration_list  */
  YYSYMBOL_232_27 = 232,                   /* $@27  */
  YYSYMBOL_233_28 = 233                    /* $@28  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  127
/* YYNRULES -- Number of rules.  */
#define YYNRULES  332
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  528

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   337


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
       2,     2,     2,    97,     2,     2,     2,    99,    92,     2,
      83,    84,    93,    94,    85,    95,    89,    98,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,   106,
     100,   105,   101,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    87,     2,    88,   102,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,   103,    91,    96,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   123,   124,   125,   125,   132,   138,   142,
     143,   144,   148,   152,   153,   157,   161,   162,   166,   167,
     171,   172,   179,   185,   192,   192,   200,   200,   208,   214,
     220,   237,   238,   243,   244,   254,   255,   262,   269,   275,
     281,   287,   296,   297,   301,   302,   303,   304,   305,   306,
     310,   311,   321,   322,   333,   334,   335,   339,   340,   351,
     352,   356,   357,   368,   369,   373,   374,   385,   386,   387,
     388,   393,   394,   405,   406,   410,   411,   421,   422,   432,
     433,   443,   444,   454,   455,   465,   466,   477,   478,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     503,   504,   514,   518,   518,   526,   526,   538,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   563,   565,
     575,   583,   595,   600,   601,   602,   603,   604,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   629,   630,   631,   635,   636,
     639,   640,   644,   651,   659,   667,   676,   688,   696,   706,
     710,   717,   717,   718,   718,   729,   737,   737,   737,   745,
     753,   754,   755,   756,   760,   764,   775,   775,   782,   782,
     791,   799,   812,   812,   822,   832,   833,   835,   844,   845,
     855,   862,   866,   870,   871,   872,   873,   877,   878,   882,
     888,   897,   905,   909,   933,   937,   945,   945,   958,   961,
     964,   967,   970,   973,   976,   979,   982,   989,   990,   991,
     995,   996,  1000,  1006,  1015,  1015,  1018,  1018,  1028,  1037,
    1045,  1056,  1063,  1067,  1067,  1074,  1079,  1080,  1084,  1084,
    1100,  1101,  1105,  1106,  1107,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1135,  1141,  1147,  1148,
    1153,  1160,  1161,  1169,  1179,  1188,  1189,  1199,  1205,  1205,
    1215,  1215,  1225,  1226,  1226,  1231,  1232,  1233,  1234,  1238,
    1255,  1262,  1271,  1272,  1281,  1281,  1282,  1282,  1293,  1294,
    1298,  1299,  1308,  1316,  1326,  1327,  1360,  1367,  1374,  1386,
    1388,  1388,  1393,  1394,  1397,  1404,  1405,  1406,  1407,  1417,
    1417,  1418,  1418,  1422,  1426,  1433,  1433,  1448,  1449,  1453,
    1453,  1454,  1454
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
  "VA_LIST", "TYPEOF", "TYPEOF_UNQUAL", "LOWER_THAN_ELSE", "'('", "')'",
  "','", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "'='", "';'", "$accept", "primary_expression", "$@1", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression", "$@2",
  "$@3", "comma_opt", "argument_expression_list", "unary_expression",
  "unary_inc_dec", "unary_operator", "cast_expression",
  "multiplicative_expression", "multiplicative_expression_op",
  "additive_expression", "additive_expression_op", "shift_expression",
  "shift_expression_op", "relational_expression",
  "relational_expression_operator", "equality_expression",
  "equality_expression_op", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "$@4", "$@5",
  "type_declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "typeof_specifier",
  "rest_typeof_specifier", "struct_or_union_specifier", "set_tag0",
  "tag_name", "struct_or_union", "struct_declaration_list", "$@6", "$@7",
  "struct_declaration", "$@8", "$@9", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "$@10", "$@11",
  "enum_specifier", "$@12", "enum_tag_name", "enum_specifier_rest",
  "enumerator_list", "enumerator", "atomic_type_specifier",
  "type_qualifier", "function_specifier", "alignment_specifier",
  "declarator", "direct_declarator", "$@13", "rest_direct_declarator",
  "rest_function_definition", "old_style_parameter_list",
  "parameter_type_list", "parameter_list", "$@14", "$@15",
  "parameter_declaration", "pointer", "pointer_star", "$@16",
  "type_qualifier_list", "type_name", "$@17", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "$@18", "static_assert_declaration", "$@19", "statement", "$@20",
  "labeled_statement", "compound_statement", "block_item_list", "$@21",
  "$@22", "block_item", "expression_statement", "selection_statement",
  "else_opt", "iteration_statement", "for_stmt_type", "$@23",
  "expression_opt", "jump_statement", "translation_unit", "$@24", "$@25",
  "external_declaration", "function_definition", "$@26",
  "declaration_list_opt", "old_style_declaration_list", "$@27", "$@28", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-349)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-329)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -349,    27,  1382,  -349,  1382,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,   -50,
     -12,  -349,  -349,  -349,    14,  -349,  -349,  -349,  -349,    66,
      66,  -349,    79,  1434,  1434,  -349,  -349,    31,  -349,  -349,
    1434,  1434,  1434,  -349,  -349,  -349,  -349,    84,    89,  1220,
      74,  1538,  1220,  1220,  -349,  -349,  -349,    79,    28,    21,
      76,  -349,   -32,     7,    43,    93,  -349,  -349,  -349,  -349,
      97,   105,  -349,  -349,  -349,  -349,    95,   113,  -349,  -349,
     118,  -349,  -349,  -349,  -349,  -349,  -349,  1279,  -349,  -349,
     128,   130,  1111,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,   219,  -349,  1315,  1220,  -349,   117,   -70,
      36,    53,    44,   155,   134,   148,   233,    20,  -349,   171,
     174,  -349,  1538,   157,  1538,   200,   376,  -349,  -349,    -6,
     203,   207,   167,  -349,    79,   193,  1151,  -349,   222,  1382,
     665,   218,  -349,     7,  -349,  -349,   212,  1486,   223,  1220,
      84,   226,    84,  -349,  1111,  -349,  1220,  1220,   228,   144,
     229,  -349,  -349,  1166,  1220,   230,   309,  1111,  -349,  -349,
    -349,  -349,  -349,  1220,  -349,  -349,  1220,  -349,  -349,  1220,
    -349,  -349,  -349,  -349,  1220,  -349,  -349,  1220,  1220,  1220,
    1220,  1220,  1220,  1220,  -349,  -349,  -349,   177,   682,    26,
    -349,  -349,   139,  -349,   313,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  1220,  -349,  1220,  -349,
    -349,  -349,   167,  -349,   217,  -349,   184,  -349,  -349,   228,
    1382,  -349,    79,  1001,  -349,   236,   237,   777,    15,  -349,
    1486,  -349,   221,  -349,  -349,   238,  -349,  -349,  -349,    -5,
     244,   178,   246,   247,   240,   250,  -349,  1183,  -349,   181,
    -349,    92,   332,   333,   254,  -349,   117,   -70,    36,    53,
      44,   155,   134,   148,   233,   183,  -349,   256,   257,  1434,
     259,  1001,  -349,   258,   261,   794,   139,   263,   889,   266,
    -349,  -349,  -349,  1220,  -349,  -349,    47,  1151,   -30,  -349,
     265,  -349,  -349,   264,  1001,  -349,  -349,  1220,  -349,   267,
     268,  -349,   275,   276,  -349,  -349,  -349,    81,  -349,    19,
    -349,   270,  -349,  -349,   304,  -349,   277,   460,  -349,  1056,
    -349,  -349,  1220,  -349,  -349,  -349,   270,  1220,  -349,   311,
      86,  -349,  -349,   281,  1001,  -349,  -349,  1220,  -349,   282,
    -349,   288,  1001,  -349,   285,   286,   906,  -349,   289,   961,
    -349,  -349,  -349,  -349,   373,  -349,   291,   292,  -349,  -349,
    -349,   378,  -349,   297,  -349,   298,  -349,   300,   188,  -349,
     301,  -349,   460,   302,  1220,   306,   307,   310,   326,   555,
     327,   380,   305,   308,    23,  -349,   -47,  -349,  -349,   228,
    -349,  -349,  -349,  -349,  -349,  -349,   328,  -349,  -349,  -349,
    1434,    73,  -349,    88,  -349,  -349,   324,   329,  -349,  -349,
     330,  1001,  -349,  -349,  1220,  -349,   331,   314,  -349,  -349,
    -349,  1151,  -349,  -349,  -349,  -349,  1220,    81,   315,  -349,
    1220,  -349,   304,  1220,  -349,   555,   339,   555,  1220,  1220,
    1220,   353,   570,   320,  -349,  -349,  -349,   -41,  -349,  -349,
    1016,   303,  -349,  -349,  -349,  -349,   340,   342,  -349,  -349,
    -349,  -349,  -349,  -349,  1220,  -349,  -349,  -349,  -349,   555,
    -349,   199,   211,   213,   348,  1220,   349,  1382,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,   555,   555,   555,  1220,   350,
     335,   555,  1220,   356,  -349,  -349,   225,  1220,  -349,   336,
     555,  -349,   338,  -349,  1220,  -349,  -349,  -349
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     319,   321,     0,     1,     0,   144,   122,   123,   124,   126,
     127,   197,   193,   194,   195,   137,   129,   130,   131,   132,
     135,   136,   133,   134,   128,   138,   139,   159,   160,   182,
       0,   238,   196,   198,     0,   125,   145,   146,   147,     0,
       0,   324,   103,   109,   111,   143,   141,     0,   142,   140,
     113,   115,   117,   107,   320,   323,   322,     0,     0,   238,
       0,     0,     0,   238,   148,   149,   203,     0,   235,     0,
     105,   118,   329,   202,     0,   232,   108,   110,   158,   157,
     161,   156,   112,   114,   116,    12,   191,    31,   188,   184,
     185,     2,     9,    10,    11,    13,    14,     0,    42,    43,
       0,     0,   238,    44,    45,    46,    47,    48,    49,    20,
       3,     4,     8,    35,    50,     0,     0,    52,    57,    61,
      65,    71,    75,    77,    79,    81,    83,    85,   102,     0,
       0,   192,   171,   240,   173,     0,    50,    87,   100,     0,
       0,     0,     0,   104,     0,     0,     0,   325,   331,     0,
       0,     0,   205,   201,   231,   152,   163,     0,   161,     0,
      32,     0,     0,   183,   238,    38,   238,     0,     0,     0,
       0,    28,    29,     0,     0,     0,     0,   238,    36,    37,
      54,    55,    56,     0,    59,    60,     0,    63,    64,     0,
      69,    70,    67,    68,     0,    73,    74,     0,     0,     0,
       0,     0,     0,     0,   200,   199,   170,   224,     0,   243,
     239,   241,   244,   172,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    89,     0,   150,     0,   151,
     204,   236,   234,   119,   121,   106,   278,   268,   120,     0,
       0,   330,   103,     0,   208,    45,     0,     0,   224,   153,
       0,   162,   166,   169,   154,   163,   190,   189,   181,     0,
       0,     0,     0,     0,   294,     0,     7,     0,    22,     0,
      33,     0,     0,     0,     0,    53,    58,    62,    66,    72,
      76,    78,    80,    82,    84,     0,   262,     0,   223,     0,
       0,     0,   246,    45,     0,     0,   242,   224,     0,     0,
      88,   101,   237,     0,   269,   271,     0,     0,   278,   275,
       0,   326,   332,     0,     0,   210,   209,     0,   216,    45,
       0,   220,     0,   219,   218,   164,   165,     0,   155,     0,
     186,    39,    41,    40,   238,   292,   296,   283,     6,   278,
      51,    23,     0,    21,    25,    27,     0,     0,   263,   226,
     230,   225,   245,     0,     0,   247,   253,     0,   252,     0,
     264,     0,     0,   254,    45,     0,     0,   280,     0,   278,
     266,   270,   274,   276,     0,   212,     0,     0,   213,   215,
     207,     0,   176,   167,   174,   180,   187,     0,     0,    16,
       0,   293,   283,     2,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,     0,   300,     0,   298,   299,     0,
     282,   295,   285,   286,   287,   288,    31,    34,    86,   222,
       0,   224,   228,   243,   229,   249,     0,     0,   251,   265,
       0,     0,   255,   261,     0,   260,     0,     0,   277,   267,
     273,     0,   279,   211,   214,   221,     0,     0,     0,   178,
       0,    15,   238,     0,   297,   283,     0,   283,     0,     0,
       0,     0,   310,     0,   315,   316,   317,     0,   301,   284,
      32,     0,   227,   248,   250,   257,     0,     0,   258,   281,
     272,   177,   175,   168,     0,    19,    17,    18,   289,   283,
     291,     0,     0,     0,     0,   312,     0,     0,   314,   318,
      30,   256,   259,   179,   290,   283,   283,   283,     0,   313,
       0,   283,   312,   304,   303,   306,     0,   312,   308,     0,
     283,   302,     0,   309,   312,   305,   307,   311
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,   -18,  -349,
    -349,  -349,    22,  -349,   -55,  -349,  -349,  -102,   251,  -349,
     262,  -349,   242,  -349,   249,  -349,   241,  -349,   248,   252,
     255,   253,  -349,   -57,     9,  -349,   -63,   -61,  -133,  -349,
    -349,     4,  -349,   316,  -349,   -49,  -349,   408,  -349,  -349,
    -349,  -349,   295,  -349,  -349,   208,  -349,  -349,     3,  -349,
      10,  -349,  -349,  -349,  -349,  -349,  -349,   312,  -145,  -349,
      -9,  -349,  -349,   -39,   -65,  -349,  -349,  -349,  -349,  -225,
    -349,  -349,  -349,    51,   -56,  -349,  -349,  -113,   -14,  -349,
    -349,  -123,  -198,  -126,   136,  -348,  -349,   168,  -349,  -114,
    -349,  -287,  -349,  -349,  -226,  -349,  -349,  -349,    85,    16,
    -349,  -349,  -349,  -349,  -349,  -303,  -349,  -349,  -349,  -349,
     476,  -349,  -349,  -349,  -349,  -349,  -349
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   109,   168,   110,    86,   111,   112,   388,   389,   113,
     175,   176,   161,   269,   136,   115,   116,   117,   118,   183,
     119,   186,   120,   189,   121,   194,   122,   197,   123,   124,
     125,   126,   127,   137,   138,   226,   406,   129,    41,    69,
     145,   242,    70,    71,    43,    44,    45,    64,    46,    80,
      81,    47,   156,   157,   250,   251,   327,   448,   252,   383,
     384,   446,   484,    48,    58,    90,   163,    87,    88,    49,
      50,    51,    52,   141,    73,   151,   152,   322,   323,   287,
     288,   289,   420,   351,    74,    75,   142,   232,   390,    61,
     210,   290,   212,   305,   306,   307,   308,   309,   310,    53,
     437,   408,   409,   410,   265,   336,   337,   392,   411,   412,
     413,   521,   414,   496,   497,   510,   415,     1,     2,     4,
      54,    55,   239,   147,   148,   149,   240
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     139,   135,   128,    72,   114,   128,    42,   114,    42,   153,
     211,   296,   132,   311,   179,   257,   241,    60,   321,   154,
     238,   441,    85,   324,   184,   185,    91,     3,    92,    93,
      94,    95,    96,    97,    78,    98,    99,   247,   228,   169,
      57,   202,   165,   253,   228,   130,    66,    76,    77,   140,
     187,   188,   134,  -121,    82,    83,    84,   303,  -327,   468,
     178,   114,   195,   196,   133,   499,  -233,  -233,  -233,   190,
     191,    59,   361,   146,  -121,   372,    66,   209,   227,   228,
     329,   275,    66,   132,    66,   132,   330,    85,   170,    66,
    -206,    66,    89,   100,   150,   295,   101,    62,   256,  -217,
    -233,   169,   128,   261,   114,   234,   102,   312,   132,   207,
     386,   271,   461,   208,   169,   103,   104,   105,   106,   107,
     108,    79,   441,   134,   203,   134,    67,   143,   114,   466,
     314,   114,   369,   231,   114,   206,   253,   213,   370,   114,
     285,   231,   114,   114,   114,   114,   114,   114,   134,    63,
     260,   209,   262,   192,   193,   237,   421,   286,   131,   246,
     208,   144,    67,   274,    67,   340,    68,   382,   488,   421,
     490,   421,    68,   208,    68,   208,   263,   228,   354,    68,
     343,   371,   270,   469,   257,   366,    68,    91,   155,    92,
      93,    94,    95,    96,    97,   158,    98,    99,   160,   231,
     159,   132,   504,   234,   407,    12,    13,    14,   162,   519,
     180,   166,   114,   167,   523,   181,   182,   294,   513,   514,
     515,   527,   297,   302,   518,   296,   298,   424,   266,   228,
     -26,   171,   172,   525,   231,   300,   199,   301,   302,    32,
     207,   134,   368,   440,   208,   237,   128,   198,   114,   431,
      68,   200,   313,   201,   100,   204,   320,   101,   205,   407,
     207,   286,   332,   228,   208,   341,   342,   102,   228,   347,
      68,   303,   451,   452,   236,   304,   103,   104,   105,   106,
     107,   108,   231,   505,   228,   214,   302,   229,   385,   231,
     418,   230,   114,   350,   423,   506,   228,   507,   228,   235,
     353,   248,   173,   249,   359,   302,   174,   365,   -24,   522,
     228,   422,  -328,   267,   254,   480,   237,   258,   264,   272,
     273,   299,   146,   376,   315,   316,   377,   326,   331,   328,
     333,   335,   334,   456,   338,   344,   345,   128,   346,   114,
     348,   467,   349,   352,   440,   302,   355,   360,   237,   356,
     367,   417,   375,   231,   374,   378,   379,   302,   153,   380,
     339,   381,   387,   426,   512,   423,   427,   419,   391,   425,
     428,   430,   429,   432,   433,   436,   442,   438,   237,   443,
     444,   445,   447,   463,   449,   481,   450,   453,   455,   128,
     458,   114,   457,   459,   500,   491,   492,   493,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   385,   460,
     462,   464,   473,   470,   465,   494,   520,   474,   475,   478,
     479,   483,   302,   503,   350,   489,   498,   128,   501,   114,
     502,   508,   509,   511,   486,   228,   278,   276,   471,   280,
     476,   517,   524,   477,   526,   516,   279,   281,    65,   509,
     237,   277,   282,   255,   509,   284,   283,   482,   325,   485,
     233,   509,   487,   393,     5,    92,    93,    94,    95,    96,
      97,   472,    98,    99,   259,   416,   373,   454,   495,   237,
      56,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,   394,   395,   396,
       0,   397,   398,   399,   400,   401,   402,   403,   404,    30,
     100,    31,    32,   101,    33,    34,    35,    36,    37,    38,
      39,    40,     0,   102,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   393,     0,
      92,    93,    94,    95,    96,    97,   405,    98,    99,     0,
       0,     0,     0,    91,     0,    92,    93,    94,    95,    96,
      97,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,   395,   396,     0,   397,   398,   399,   400,
     401,   402,   403,   404,     0,   100,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
     100,     0,     0,   101,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   102,     0,     0,     0,     0,     0,     0,
       0,   405,   103,   104,   105,   106,   107,   108,    91,     0,
      92,    93,    94,    95,    96,    97,   405,    98,    99,     0,
       0,     0,     0,     0,     0,    91,     0,    92,    93,    94,
      95,    96,    97,     0,    98,    99,     0,     0,     0,   243,
       0,     0,     0,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
      12,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,    32,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,     0,   100,   244,    32,   101,     0,   103,   245,   105,
     106,   107,   108,     0,     0,   102,     0,     0,     0,     0,
     292,     0,     0,     0,   103,   293,   105,   106,   107,   108,
      91,     0,    92,    93,    94,    95,    96,    97,     0,    98,
      99,     0,     0,     0,     0,     0,     0,    91,     0,    92,
      93,    94,    95,    96,    97,     0,    98,    99,     0,     0,
       0,   317,     0,     0,     0,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   357,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,     0,    32,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,     0,     0,     0,   100,   318,    32,   101,     0,   103,
     319,   105,   106,   107,   108,     0,     0,   102,     0,     0,
       0,     0,   358,     0,     0,     0,   103,   104,   105,   106,
     107,   108,    91,     0,    92,    93,    94,    95,    96,    97,
       0,    98,    99,     0,     0,     0,     0,     0,     0,    91,
       0,    92,    93,    94,    95,    96,    97,     0,    98,    99,
       0,     0,     0,   362,     0,     0,     0,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     434,     0,     0,     0,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,    32,   101,     0,    91,     0,    92,    93,    94,    95,
      96,    97,   102,    98,    99,     0,   100,   363,    32,   101,
       0,   103,   364,   105,   106,   107,   108,     0,     0,   102,
       0,     0,     0,     0,   435,     0,     0,     0,   103,   104,
     105,   106,   107,   108,    91,     0,    92,    93,    94,    95,
      96,    97,     0,    98,    99,     0,     0,     0,     0,    91,
       0,    92,    93,    94,    95,    96,    97,     0,    98,    99,
       0,   100,     0,     0,   101,     0,     0,     0,     0,    12,
      13,    14,     0,     0,   102,     0,     0,     0,   303,     0,
       0,   236,   439,   103,   104,   105,   106,   107,   108,    91,
       0,    92,    93,    94,    95,    96,    97,     0,    98,    99,
       0,   100,     0,    32,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,   100,     0,     0,   101,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   102,
       0,     0,     0,   303,     0,  -278,   236,     0,   103,   104,
     105,   106,   107,   108,    91,     0,    92,    93,    94,    95,
      96,    97,     0,    98,    99,     0,   100,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
       0,     0,     0,   303,     0,     0,   236,     0,   103,   104,
     105,   106,   107,   108,    91,     0,    92,    93,    94,    95,
      96,    97,     0,    98,    99,     0,     0,     0,     0,    91,
       0,    92,    93,    94,    95,    96,    97,     0,    98,    99,
       0,   100,     0,     0,   101,     0,    91,     0,    92,    93,
      94,    95,    96,    97,   102,    98,    99,     0,     0,     0,
       0,    -5,     0,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,    91,   101,    92,    93,    94,    95,    96,
      97,     0,    98,    99,   102,     0,   100,     0,     0,   101,
       0,   236,     0,   103,   104,   105,   106,   107,   108,   102,
     268,     0,     0,   100,     0,     0,   101,     0,   103,   104,
     105,   106,   107,   108,     0,     0,   102,     0,     0,     0,
       0,     0,     0,   339,     0,   103,   104,   105,   106,   107,
     108,     0,    91,     0,    92,    93,    94,    95,    96,    97,
     100,    98,    99,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,    91,     0,
      92,    93,    94,    95,    96,    97,     0,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     5,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    31,    32,     0,    33,     0,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
       0,    34,     0,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,    36,    37,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
      63,    62,    59,    42,    59,    62,     2,    62,     4,    74,
     133,   209,    61,   239,   116,   160,   149,    31,     3,    75,
     146,   369,     3,   248,    94,    95,     3,     0,     5,     6,
       7,     8,     9,    10,     3,    12,    13,   150,    85,   102,
      90,    21,    97,   157,    85,    59,     3,    43,    44,    63,
      14,    15,    61,    85,    50,    51,    52,    87,    90,   106,
     115,   116,    18,    19,    61,   106,    38,    39,    40,    16,
      17,    83,   297,   105,   106,   105,     3,   133,    84,    85,
      85,   183,     3,   132,     3,   134,    91,     3,   102,     3,
      83,     3,     3,    70,    87,   208,    73,    83,   159,    84,
      72,   164,   159,   166,   159,   144,    83,   240,   157,    83,
      91,   174,   399,    87,   177,    92,    93,    94,    95,    96,
      97,    90,   470,   132,   104,   134,    83,   106,   183,   106,
     243,   186,    85,   142,   189,   132,   250,   134,    91,   194,
     203,   150,   197,   198,   199,   200,   201,   202,   157,    83,
     164,   207,   166,   100,   101,   146,    83,    84,    84,   150,
      87,    85,    83,   177,    83,   267,    93,    86,   455,    83,
     457,    83,    93,    87,    93,    87,   167,    85,   291,    93,
      88,   307,   173,   409,   329,   298,    93,     3,    91,     5,
       6,     7,     8,     9,    10,    90,    12,    13,    85,   208,
     105,   250,   489,   242,   337,    38,    39,    40,    90,   512,
      93,    83,   267,    83,   517,    98,    99,   208,   505,   506,
     507,   524,    83,   232,   511,   423,    87,   350,    84,    85,
      11,    12,    13,   520,   243,   226,   102,   228,   247,    72,
      83,   250,   303,   369,    87,   236,   303,    92,   303,   362,
      93,   103,   243,    20,    70,    84,   247,    73,    84,   392,
      83,    84,    84,    85,    87,    84,    85,    83,    85,    86,
      93,    87,    84,    85,    90,    91,    92,    93,    94,    95,
      96,    97,   291,    84,    85,    85,   295,    84,   327,   298,
     347,    84,   347,   289,   350,    84,    85,    84,    85,   106,
     291,    83,    83,    91,   295,   314,    87,   298,    89,    84,
      85,   350,    90,    84,    91,   441,   307,    91,    90,    89,
      11,     8,   105,   314,    88,    88,   317,   106,    84,    91,
      84,    91,    85,   394,    84,     3,     3,   394,    84,   394,
      84,   404,    85,    84,   470,   354,    88,    84,   339,    88,
      84,   342,    88,   362,    89,    88,    88,   366,   423,    84,
      90,    85,    58,   354,   497,   421,   357,    56,    91,    88,
      88,   362,    84,    88,    88,   366,     3,    88,   369,    88,
      88,     3,    85,     3,    86,   446,    86,    86,    86,   446,
      83,   446,    86,    83,    91,   458,   459,   460,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   447,    83,
      83,   106,    88,    85,   106,    62,    60,    88,    88,    88,
     106,   106,   431,   484,   420,    86,   106,   484,    88,   484,
      88,    83,   495,    84,   452,    85,   194,   186,   416,   198,
     431,   106,   106,   434,   106,   508,   197,   199,    40,   512,
     441,   189,   200,   158,   517,   202,   201,   447,   250,   450,
     144,   524,   453,     3,     4,     5,     6,     7,     8,     9,
      10,   420,    12,    13,   162,   339,   308,   392,   462,   470,
       4,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,     3,    -1,
       5,     6,     7,     8,     9,    10,   106,    12,    13,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    92,    93,    94,    95,    96,    97,     3,    -1,
       5,     6,     7,     8,     9,    10,   106,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    70,    88,    72,    73,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    70,    88,    72,    73,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    73,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    83,    12,    13,    -1,    70,    88,    72,    73,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    83,    -1,    -1,    -1,    87,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    70,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    83,
      -1,    -1,    -1,    87,    -1,    89,    90,    -1,    92,    93,
      94,    95,    96,    97,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    87,    -1,    -1,    90,    -1,    92,    93,
      94,    95,    96,    97,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    70,    -1,    -1,    73,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    83,    12,    13,    -1,    -1,    -1,
      -1,    90,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,     3,    73,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    83,    -1,    70,    -1,    -1,    73,
      -1,    90,    -1,    92,    93,    94,    95,    96,    97,    83,
      84,    -1,    -1,    70,    -1,    -1,    73,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,    96,
      97,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      70,    12,    13,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,     4,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    -1,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   224,   225,     0,   226,     4,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      69,    71,    72,    74,    75,    76,    77,    78,    79,    80,
      81,   145,   148,   151,   152,   153,   155,   158,   170,   176,
     177,   178,   179,   206,   227,   228,   227,    90,   171,    83,
     195,   196,    83,    83,   154,   154,     3,    83,    93,   146,
     149,   150,   180,   181,   191,   192,   148,   148,     3,    90,
     156,   157,   148,   148,   148,     3,   111,   174,   175,     3,
     172,     3,     5,     6,     7,     8,     9,    10,    12,    13,
      70,    73,    83,    92,    93,    94,    95,    96,    97,   108,
     110,   112,   113,   116,   121,   122,   123,   124,   125,   127,
     129,   131,   133,   135,   136,   137,   138,   139,   140,   144,
     195,    84,   152,   165,   177,   144,   121,   140,   141,   143,
     195,   180,   193,   106,    85,   147,   105,   230,   231,   232,
      87,   182,   183,   181,   191,    91,   159,   160,    90,   105,
      85,   119,    90,   173,    83,   121,    83,    83,   109,   143,
     195,    12,    13,    83,    87,   117,   118,    83,   121,   124,
      93,    98,    99,   126,    94,    95,   128,    14,    15,   130,
      16,    17,   100,   101,   132,    18,    19,   134,    92,   102,
     103,    20,    21,   104,    84,    84,   165,    83,    87,   191,
     197,   198,   199,   165,    85,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   105,   142,    84,    85,    84,
      84,   177,   194,   150,   180,   106,    90,   141,   200,   229,
     233,   145,   148,    34,    88,    93,   141,   194,    83,    91,
     161,   162,   165,   206,    91,   159,   144,   175,    91,   174,
     195,   143,   195,   141,    90,   211,    84,    84,    84,   120,
     141,   143,    89,    11,   195,   124,   125,   127,   129,   131,
     133,   135,   136,   137,   138,   143,    84,   186,   187,   188,
     198,    34,    88,    93,   141,   194,   199,    83,    87,     8,
     141,   141,   177,    87,    91,   200,   201,   202,   203,   204,
     205,   211,   145,   141,   194,    88,    88,    34,    88,    93,
     141,     3,   184,   185,   186,   162,   106,   163,    91,    85,
      91,    84,    84,    84,    85,    91,   212,   213,    84,    90,
     124,    84,    85,    88,     3,     3,    84,    86,    84,    85,
     148,   190,    84,   141,   194,    88,    88,    34,    88,   141,
      84,   186,    34,    88,    93,   141,   194,    84,   144,    85,
      91,   200,   105,   204,    89,    88,   141,   141,    88,    88,
      84,    85,    86,   166,   167,   180,    91,    58,   114,   115,
     195,    91,   214,     3,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,   106,   143,   145,   208,   209,
     210,   215,   216,   217,   219,   223,   201,   141,   140,    56,
     189,    83,   180,   191,   198,    88,   141,   141,    88,    84,
     141,   194,    88,    88,    34,    88,   141,   207,    88,    91,
     200,   202,     3,    88,    88,     3,   168,    85,   164,    86,
      86,    84,    85,    86,   215,    86,   144,    86,    83,    83,
      83,   208,    83,     3,   106,   106,   106,   143,   106,   211,
      85,   119,   190,    88,    88,    88,   141,   141,    88,   106,
     200,   144,   167,   106,   169,   141,   115,   141,   208,    86,
     208,   143,   143,   143,    62,   216,   220,   221,   106,   106,
      91,    88,    88,   144,   208,    84,    84,    84,    83,   143,
     222,    84,   145,   208,   208,   208,   143,   106,   208,   222,
      60,   218,    84,   222,   106,   208,   106,   222
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   108,   109,   108,   108,   108,   110,
     110,   110,   111,   112,   112,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   117,   116,   118,   116,   116,   116,
     116,   119,   119,   120,   120,   121,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   123,   123,   123,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   143,   144,   146,   145,   147,   145,   145,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   151,   151,   151,   151,   151,   151,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   153,   153,
     154,   154,   155,   155,   155,   155,   155,   156,   157,   158,
     158,   160,   159,   161,   159,   162,   163,   164,   162,   162,
     165,   165,   165,   165,   166,   166,   168,   167,   169,   167,
     167,   170,   171,   170,   172,   173,   173,   173,   174,   174,
     175,   175,   176,   177,   177,   177,   177,   178,   178,   179,
     179,   180,   180,   181,   181,   181,   182,   181,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   184,   184,   184,
     185,   185,   186,   186,   188,   187,   189,   187,   190,   190,
     190,   191,   191,   193,   192,   192,   194,   194,   196,   195,
     197,   197,   198,   198,   198,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   200,   200,   200,   200,
     201,   201,   201,   201,   202,   203,   203,   204,   205,   204,
     207,   206,   208,   209,   208,   208,   208,   208,   208,   210,
     210,   210,   211,   211,   213,   212,   214,   212,   215,   215,
     216,   216,   217,   217,   218,   218,   219,   219,   219,   220,
     221,   220,   222,   222,   223,   223,   223,   223,   223,   225,
     224,   226,   224,   227,   227,   229,   228,   230,   230,   232,
     231,   233,   231
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     0,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     3,     3,     3,
       1,     4,     3,     4,     0,     4,     0,     4,     2,     2,
       7,     0,     1,     1,     3,     1,     2,     2,     2,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     0,     4,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     4,     4,     5,     2,     1,     1,     1,
       1,     0,     2,     0,     3,     2,     0,     0,     5,     1,
       2,     1,     2,     1,     1,     3,     0,     3,     0,     4,
       1,     5,     0,     4,     1,     0,     3,     4,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       4,     2,     1,     1,     3,     2,     0,     5,     2,     3,
       3,     5,     4,     4,     5,     4,     3,     0,     1,     1,
       1,     3,     3,     1,     0,     2,     0,     4,     2,     2,
       1,     2,     1,     0,     3,     1,     1,     2,     0,     3,
       0,     1,     2,     1,     1,     3,     2,     3,     5,     4,
       5,     4,     3,     3,     3,     4,     6,     5,     5,     6,
       4,     4,     2,     3,     3,     4,     3,     4,     1,     2,
       2,     1,     4,     3,     2,     1,     2,     3,     0,     3,
       0,     8,     1,     0,     2,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     0,     2,     0,     3,     1,     1,
       1,     2,     6,     5,     0,     2,     5,     7,     5,     4,
       0,     5,     0,     1,     3,     2,     2,     2,     3,     0,
       2,     0,     3,     1,     1,     0,     5,     0,     1,     0,
       2,     0,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
yyparse (void)
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
#line 120 "Parser/C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2258 "C_grammar.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 125 "Parser/C_grammar.y"
              {current_scope++; fsm_reset();}
#line 2264 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' $@1 compound_statement ')'  */
#line 126 "Parser/C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2275 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 133 "Parser/C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2285 "C_grammar.tab.c"
    break;

  case 8: /* primary_expression: generic_selection  */
#line 138 "Parser/C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2291 "C_grammar.tab.c"
    break;

  case 14: /* string: FUNC_NAME  */
#line 153 "Parser/C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2297 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 173 "Parser/C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2308 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' ')'  */
#line 180 "Parser/C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2318 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 186 "Parser/C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2329 "C_grammar.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 192 "Parser/C_grammar.y"
                             {in_member_namespace = 1;}
#line 2335 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression $@2 '.' IDENTIFIER  */
#line 193 "Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2347 "C_grammar.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 200 "Parser/C_grammar.y"
                             {in_member_namespace = 1;}
#line 2353 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression $@3 PTR_OP IDENTIFIER  */
#line 201 "Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2365 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression INC_OP  */
#line 209 "Parser/C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2375 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression DEC_OP  */
#line 215 "Parser/C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2385 "C_grammar.tab.c"
    break;

  case 30: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 221 "Parser/C_grammar.y"
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
#line 2403 "C_grammar.tab.c"
    break;

  case 31: /* comma_opt: %empty  */
#line 237 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2409 "C_grammar.tab.c"
    break;

  case 32: /* comma_opt: ','  */
#line 238 "Parser/C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2415 "C_grammar.tab.c"
    break;

  case 34: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 245 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2426 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: unary_inc_dec unary_expression  */
#line 256 "Parser/C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2437 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: unary_operator cast_expression  */
#line 263 "Parser/C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2448 "C_grammar.tab.c"
    break;

  case 38: /* unary_expression: SIZEOF unary_expression  */
#line 270 "Parser/C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2458 "C_grammar.tab.c"
    break;

  case 39: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 276 "Parser/C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2468 "C_grammar.tab.c"
    break;

  case 40: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 282 "Parser/C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2478 "C_grammar.tab.c"
    break;

  case 41: /* unary_expression: ALIGNOF '(' expression ')'  */
#line 288 "Parser/C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2488 "C_grammar.tab.c"
    break;

  case 42: /* unary_inc_dec: INC_OP  */
#line 296 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2494 "C_grammar.tab.c"
    break;

  case 43: /* unary_inc_dec: DEC_OP  */
#line 297 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2500 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '&'  */
#line 301 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2506 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '*'  */
#line 302 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2512 "C_grammar.tab.c"
    break;

  case 46: /* unary_operator: '+'  */
#line 303 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2518 "C_grammar.tab.c"
    break;

  case 47: /* unary_operator: '-'  */
#line 304 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2524 "C_grammar.tab.c"
    break;

  case 48: /* unary_operator: '~'  */
#line 305 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2530 "C_grammar.tab.c"
    break;

  case 49: /* unary_operator: '!'  */
#line 306 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2536 "C_grammar.tab.c"
    break;

  case 51: /* cast_expression: '(' type_name ')' cast_expression  */
#line 312 "Parser/C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2547 "C_grammar.tab.c"
    break;

  case 53: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 323 "Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2559 "C_grammar.tab.c"
    break;

  case 54: /* multiplicative_expression_op: '*'  */
#line 333 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2565 "C_grammar.tab.c"
    break;

  case 55: /* multiplicative_expression_op: '/'  */
#line 334 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2571 "C_grammar.tab.c"
    break;

  case 56: /* multiplicative_expression_op: '%'  */
#line 335 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2577 "C_grammar.tab.c"
    break;

  case 58: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 341 "Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2589 "C_grammar.tab.c"
    break;

  case 59: /* additive_expression_op: '+'  */
#line 351 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2595 "C_grammar.tab.c"
    break;

  case 60: /* additive_expression_op: '-'  */
#line 352 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2601 "C_grammar.tab.c"
    break;

  case 62: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 358 "Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2613 "C_grammar.tab.c"
    break;

  case 63: /* shift_expression_op: LEFT_OP  */
#line 368 "Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2619 "C_grammar.tab.c"
    break;

  case 64: /* shift_expression_op: RIGHT_OP  */
#line 369 "Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2625 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 375 "Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2637 "C_grammar.tab.c"
    break;

  case 67: /* relational_expression_operator: '<'  */
#line 385 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2643 "C_grammar.tab.c"
    break;

  case 68: /* relational_expression_operator: '>'  */
#line 386 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2649 "C_grammar.tab.c"
    break;

  case 69: /* relational_expression_operator: LE_OP  */
#line 387 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2655 "C_grammar.tab.c"
    break;

  case 70: /* relational_expression_operator: GE_OP  */
#line 388 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2661 "C_grammar.tab.c"
    break;

  case 72: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 395 "Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2673 "C_grammar.tab.c"
    break;

  case 73: /* equality_expression_op: EQ_OP  */
#line 405 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2679 "C_grammar.tab.c"
    break;

  case 74: /* equality_expression_op: NE_OP  */
#line 406 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2685 "C_grammar.tab.c"
    break;

  case 76: /* and_expression: and_expression '&' equality_expression  */
#line 412 "Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2696 "C_grammar.tab.c"
    break;

  case 78: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 423 "Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2707 "C_grammar.tab.c"
    break;

  case 80: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 434 "Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2718 "C_grammar.tab.c"
    break;

  case 82: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 445 "Parser/C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2729 "C_grammar.tab.c"
    break;

  case 84: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 456 "Parser/C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2740 "C_grammar.tab.c"
    break;

  case 86: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 467 "Parser/C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + MAX_BRANCH_STR + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2752 "C_grammar.tab.c"
    break;

  case 88: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 479 "Parser/C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2764 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: '='  */
#line 489 "Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2770 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: MUL_ASSIGN  */
#line 490 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2776 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: DIV_ASSIGN  */
#line 491 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2782 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: MOD_ASSIGN  */
#line 492 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2788 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: ADD_ASSIGN  */
#line 493 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2794 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: SUB_ASSIGN  */
#line 494 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2800 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: LEFT_ASSIGN  */
#line 495 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2806 "C_grammar.tab.c"
    break;

  case 96: /* assignment_operator: RIGHT_ASSIGN  */
#line 496 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2812 "C_grammar.tab.c"
    break;

  case 97: /* assignment_operator: AND_ASSIGN  */
#line 497 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2818 "C_grammar.tab.c"
    break;

  case 98: /* assignment_operator: XOR_ASSIGN  */
#line 498 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2824 "C_grammar.tab.c"
    break;

  case 99: /* assignment_operator: OR_ASSIGN  */
#line 499 "Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2830 "C_grammar.tab.c"
    break;

  case 101: /* expression: expression ',' assignment_expression  */
#line 505 "Parser/C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2841 "C_grammar.tab.c"
    break;

  case 103: /* $@4: %empty  */
#line 518 "Parser/C_grammar.y"
                                      {fsm_reset();}
#line 2847 "C_grammar.tab.c"
    break;

  case 104: /* declaration: type_declaration_specifiers $@4 ';'  */
#line 519 "Parser/C_grammar.y"
                {if (debugMode) printf("end of stand alone declaration specifier as a declaration on line %d\n", yylineno);
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("\ndeclaration()") + strlen(decl_specifier) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration(%s)", decl_specifier);
		 free(decl_specifier);
		}
#line 2859 "C_grammar.tab.c"
    break;

  case 105: /* $@5: %empty  */
#line 526 "Parser/C_grammar.y"
                                                           {fsm_reset();}
#line 2865 "C_grammar.tab.c"
    break;

  case 106: /* declaration: type_declaration_specifiers init_declarator_list $@5 ';'  */
#line 527 "Parser/C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations [why not done above?]
	    	typedef_flag = 0; 
			if (debugMode) printf("Debug: typedef switched to 0\n");
	   	 }
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("\ndeclaration(, [])") + strlen(decl_specifier) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration(%s, [%s])", decl_specifier, (yyvsp[-2].id));
		 free(decl_specifier);
		 free((yyvsp[-2].id));
		}
#line 2881 "C_grammar.tab.c"
    break;

  case 107: /* declaration: static_assert_declaration  */
#line 539 "Parser/C_grammar.y"
                {size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		 pop_decl_spec_stack();
		}
#line 2892 "C_grammar.tab.c"
    break;

  case 118: /* init_declarator_list: init_declarator  */
#line 564 "Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);}
#line 2898 "C_grammar.tab.c"
    break;

  case 119: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 566 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 2909 "C_grammar.tab.c"
    break;

  case 120: /* init_declarator: declarator '=' initializer  */
#line 576 "Parser/C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));
	  	}
#line 2921 "C_grammar.tab.c"
    break;

  case 121: /* init_declarator: declarator  */
#line 584 "Parser/C_grammar.y"
                {if (debugMode) printf("DEBUG: typedef_flag=%d, ptr_declarator=%s\n", typedef_flag, (yyvsp[0].declarator_type).ptr_declarator);
			if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_id(current_scope, (yyvsp[0].declarator_type).ptr_declarator, 1);	//the id as a TYPEDEF_NAME is added to the data structures keeping track of typedef_names (and ids shadowing)
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 2933 "C_grammar.tab.c"
    break;

  case 122: /* storage_class_specifier: TYPEDEF  */
#line 596 "Parser/C_grammar.y"
                {decl_spec_stack->decl_spec.storage.isTypeDef = true;
         typedef_flag = 1;
		 if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 2942 "C_grammar.tab.c"
    break;

  case 123: /* storage_class_specifier: EXTERN  */
#line 600 "Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isExtern = true; }
#line 2948 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: STATIC  */
#line 601 "Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isStatic = true; }
#line 2954 "C_grammar.tab.c"
    break;

  case 125: /* storage_class_specifier: THREAD_LOCAL  */
#line 602 "Parser/C_grammar.y"
                        { decl_spec_stack->decl_spec.storage.isThreadLocal = true; }
#line 2960 "C_grammar.tab.c"
    break;

  case 126: /* storage_class_specifier: AUTO  */
#line 603 "Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isAuto = true; }
#line 2966 "C_grammar.tab.c"
    break;

  case 127: /* storage_class_specifier: REGISTER  */
#line 604 "Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isRegister = true; }
#line 2972 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: VOID  */
#line 609 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isVoid = true;}
#line 2978 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: CHAR  */
#line 610 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isChar = true;}
#line 2984 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: SHORT  */
#line 611 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isShort= true;}
#line 2990 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: INT  */
#line 612 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isInt = true;}
#line 2996 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: LONG  */
#line 613 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.longCount++;}
#line 3002 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: FLOAT  */
#line 614 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isFloat = true;}
#line 3008 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: DOUBLE  */
#line 615 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isDouble = true;}
#line 3014 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: SIGNED  */
#line 616 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isSigned = true;}
#line 3020 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: UNSIGNED  */
#line 617 "Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isUnSigned = true;}
#line 3026 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: BOOL  */
#line 618 "Parser/C_grammar.y"
                                                { simple_str_lit_copy(&(decl_spec_stack->decl_spec.atomic.typeName), "bool");}
#line 3032 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: COMPLEX  */
#line 619 "Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "complex");}
#line 3038 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: IMAGINARY  */
#line 620 "Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "imaginary");}
#line 3044 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: atomic_type_specifier  */
#line 621 "Parser/C_grammar.y"
                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "atomic_type_specifier");}
#line 3050 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: struct_or_union_specifier  */
#line 622 "Parser/C_grammar.y"
                                    { decl_spec_stack->decl_spec.non_atomic = (yyvsp[0].id);}
#line 3056 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: enum_specifier  */
#line 623 "Parser/C_grammar.y"
                                        { decl_spec_stack->decl_spec.non_atomic = (yyvsp[0].id);}
#line 3062 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: typeof_specifier  */
#line 624 "Parser/C_grammar.y"
                                        {;}
#line 3068 "C_grammar.tab.c"
    break;

  case 144: /* type_specifier: TYPEDEF_NAME  */
#line 626 "Parser/C_grammar.y"
                {decl_spec_stack->decl_spec.non_atomic = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3076 "C_grammar.tab.c"
    break;

  case 145: /* type_specifier: INT128  */
#line 629 "Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "int128");}
#line 3082 "C_grammar.tab.c"
    break;

  case 146: /* type_specifier: FLOAT128  */
#line 630 "Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "float128");}
#line 3088 "C_grammar.tab.c"
    break;

  case 147: /* type_specifier: VA_LIST  */
#line 631 "Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "va_list");}
#line 3094 "C_grammar.tab.c"
    break;

  case 152: /* struct_or_union_specifier: struct_or_union set_tag0 '}'  */
#line 645 "Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
	    }
#line 3105 "C_grammar.tab.c"
    break;

  case 153: /* struct_or_union_specifier: struct_or_union set_tag0 struct_declaration_list '}'  */
#line 652 "Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
	    }
#line 3117 "C_grammar.tab.c"
    break;

  case 154: /* struct_or_union_specifier: struct_or_union tag_name '{' '}'  */
#line 660 "Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [])", (yyvsp[-3].id), (yyvsp[-2].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-2].id));
	    }
#line 3129 "C_grammar.tab.c"
    break;

  case 155: /* struct_or_union_specifier: struct_or_union tag_name '{' struct_declaration_list '}'  */
#line 668 "Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
	    }
#line 3142 "C_grammar.tab.c"
    break;

  case 156: /* struct_or_union_specifier: struct_or_union tag_name  */
#line 677 "Parser/C_grammar.y"
                {fsm_from_none_to_spec();
		 in_member_namespace = 0;
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3155 "C_grammar.tab.c"
    break;

  case 157: /* set_tag0: '{'  */
#line 689 "Parser/C_grammar.y"
                {in_tag_declaration = 0;
		 in_member_namespace = 1;
		 fsm_reset();
		}
#line 3164 "C_grammar.tab.c"
    break;

  case 158: /* tag_name: IDENTIFIER  */
#line 697 "Parser/C_grammar.y"
                {in_tag_declaration = 0;
		 in_member_namespace = 1;
		 fsm_reset();
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3175 "C_grammar.tab.c"
    break;

  case 159: /* struct_or_union: STRUCT  */
#line 707 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_declaration = 1;
		}
#line 3183 "C_grammar.tab.c"
    break;

  case 160: /* struct_or_union: UNION  */
#line 711 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_declaration = 1;
		}
#line 3191 "C_grammar.tab.c"
    break;

  case 161: /* $@6: %empty  */
#line 717 "Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 3197 "C_grammar.tab.c"
    break;

  case 162: /* struct_declaration_list: $@6 struct_declaration  */
#line 717 "Parser/C_grammar.y"
                                                       {(yyval.id) = (yyvsp[0].id);}
#line 3203 "C_grammar.tab.c"
    break;

  case 163: /* $@7: %empty  */
#line 718 "Parser/C_grammar.y"
                                  {push_decl_spec_stack();}
#line 3209 "C_grammar.tab.c"
    break;

  case 164: /* struct_declaration_list: struct_declaration_list $@7 struct_declaration  */
#line 719 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
	    }
#line 3220 "C_grammar.tab.c"
    break;

  case 165: /* struct_declaration: specifier_qualifier_list ';'  */
#line 730 "Parser/C_grammar.y"
                {fsm_reset();
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("anonymous_member()") + strlen(decl_specifier) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", decl_specifier);
	   	 free(decl_specifier);
        }
#line 3232 "C_grammar.tab.c"
    break;

  case 166: /* $@8: %empty  */
#line 737 "Parser/C_grammar.y"
                                   {in_member_namespace = 1;}
#line 3238 "C_grammar.tab.c"
    break;

  case 167: /* $@9: %empty  */
#line 737 "Parser/C_grammar.y"
                                                                                     {fsm_reset();}
#line 3244 "C_grammar.tab.c"
    break;

  case 168: /* struct_declaration: specifier_qualifier_list $@8 struct_declarator_list $@9 ';'  */
#line 738 "Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("struct_decl(, [])") + strlen(decl_specifier) + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl(%s, [%s])", decl_specifier, (yyvsp[-2].id));
	   	 free(decl_specifier);
		 free((yyvsp[-2].id));
        }
#line 3256 "C_grammar.tab.c"
    break;

  case 169: /* struct_declaration: static_assert_declaration  */
#line 746 "Parser/C_grammar.y"
                {fsm_reset();
		 (yyval.id) = (yyvsp[0].id);
		 pop_decl_spec_stack(); 
		}
#line 3265 "C_grammar.tab.c"
    break;

  case 174: /* struct_declarator_list: struct_declarator  */
#line 761 "Parser/C_grammar.y"
                {in_member_namespace = 1;
		 (yyval.id)= (yyvsp[0].id);
		}
#line 3273 "C_grammar.tab.c"
    break;

  case 175: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 765 "Parser/C_grammar.y"
                {in_member_namespace = 1; 
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3285 "C_grammar.tab.c"
    break;

  case 176: /* $@10: %empty  */
#line 775 "Parser/C_grammar.y"
              {in_member_namespace = 0;}
#line 3291 "C_grammar.tab.c"
    break;

  case 177: /* struct_declarator: ':' $@10 constant_expression  */
#line 776 "Parser/C_grammar.y"
                {in_member_namespace = 1;
		 size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3302 "C_grammar.tab.c"
    break;

  case 178: /* $@11: %empty  */
#line 782 "Parser/C_grammar.y"
                         {in_member_namespace = 0;}
#line 3308 "C_grammar.tab.c"
    break;

  case 179: /* struct_declarator: declarator ':' $@11 constant_expression  */
#line 783 "Parser/C_grammar.y"
                {in_member_namespace = 1;
		 size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3321 "C_grammar.tab.c"
    break;

  case 180: /* struct_declarator: declarator  */
#line 792 "Parser/C_grammar.y"
                {(yyval.id) = strdup((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3330 "C_grammar.tab.c"
    break;

  case 181: /* enum_specifier: ENUM '{' enumerator_list comma_opt '}'  */
#line 800 "Parser/C_grammar.y"
                {if (!strcmp((yyvsp[-1].id), ",")) {
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
#line 3347 "C_grammar.tab.c"
    break;

  case 182: /* $@12: %empty  */
#line 812 "Parser/C_grammar.y"
               {in_tag_declaration = 1;}
#line 3353 "C_grammar.tab.c"
    break;

  case 183: /* enum_specifier: ENUM $@12 enum_tag_name enum_specifier_rest  */
#line 813 "Parser/C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
        }
#line 3364 "C_grammar.tab.c"
    break;

  case 184: /* enum_tag_name: IDENTIFIER  */
#line 823 "Parser/C_grammar.y"
                {in_tag_declaration = 0;
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3373 "C_grammar.tab.c"
    break;

  case 185: /* enum_specifier_rest: %empty  */
#line 832 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3379 "C_grammar.tab.c"
    break;

  case 186: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 834 "Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3385 "C_grammar.tab.c"
    break;

  case 187: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 836 "Parser/C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3395 "C_grammar.tab.c"
    break;

  case 189: /* enumerator_list: enumerator_list ',' enumerator  */
#line 846 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3406 "C_grammar.tab.c"
    break;

  case 190: /* enumerator: enumeration_constant '=' constant_expression  */
#line 856 "Parser/C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3417 "C_grammar.tab.c"
    break;

  case 193: /* type_qualifier: CONST  */
#line 870 "Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isConst = true;}
#line 3423 "C_grammar.tab.c"
    break;

  case 194: /* type_qualifier: RESTRICT  */
#line 871 "Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isRestrict = true;}
#line 3429 "C_grammar.tab.c"
    break;

  case 195: /* type_qualifier: VOLATILE  */
#line 872 "Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isVolatile = true;}
#line 3435 "C_grammar.tab.c"
    break;

  case 196: /* type_qualifier: ATOMIC  */
#line 873 "Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isAtomic= true;}
#line 3441 "C_grammar.tab.c"
    break;

  case 197: /* function_specifier: INLINE  */
#line 877 "Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.function.isInLine = true;}
#line 3447 "C_grammar.tab.c"
    break;

  case 198: /* function_specifier: NORETURN  */
#line 878 "Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.function.isNoReturn = true;}
#line 3453 "C_grammar.tab.c"
    break;

  case 199: /* alignment_specifier: ALIGNAS '(' type_name ')'  */
#line 883 "Parser/C_grammar.y"
                {size_t const size = strlen("alignas()") + strlen((yyvsp[-1].id)) + 1;
	     decl_spec_stack->decl_spec.alignAs = (char*)malloc(size);
		 sprintf_safe(decl_spec_stack->decl_spec.alignAs, size, "alignas(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3463 "C_grammar.tab.c"
    break;

  case 200: /* alignment_specifier: ALIGNAS '(' constant_expression ')'  */
#line 889 "Parser/C_grammar.y"
                {size_t const size = strlen("alignas()") + strlen((yyvsp[-1].id)) + 1;
	     decl_spec_stack->decl_spec.alignAs = (char*)malloc(size);
		 sprintf_safe(decl_spec_stack->decl_spec.alignAs, size, "alignas(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3473 "C_grammar.tab.c"
    break;

  case 201: /* declarator: pointer direct_declarator  */
#line 898 "Parser/C_grammar.y"
          {size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3485 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: IDENTIFIER  */
#line 910 "Parser/C_grammar.y"
                {if (in_member_namespace) {	//this is a member (from a struct or union) no need to transform into a Prolog var
			if (debugMode) printf("direct_declarator: in member namespace: %s on line %d\n", (yyvsp[0].id), yylineno);
			size_t const size = strlen((yyvsp[0].id)) + 1;
			(yyval.declarator_type).full = (char*)malloc(size);
		 	strcpy_safe((yyval.declarator_type).full, size, (yyvsp[0].id));
			(yyval.declarator_type).ptr_declarator = (char*)malloc(size);
		 	strcpy_safe((yyval.declarator_type).ptr_declarator, size, (yyvsp[0].id));
		 } else {	//only place where a new IDENTIFIER (apart from ENUM constants) can be declared: added in the table of symbols in the lexer (it has to be done there) if it shadows a TYPEDEF_NAME
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
#line 3513 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: '(' declarator ')'  */
#line 935 "Parser/C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-1].declarator_type);
		}
#line 3520 "C_grammar.tab.c"
    break;

  case 205: /* direct_declarator: direct_declarator rest_direct_declarator  */
#line 938 "Parser/C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-1].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-1].declarator_type).full, (yyvsp[0].id));
		 free((yyvsp[-1].declarator_type).full);
		 free((yyvsp[0].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-1].declarator_type).ptr_declarator;
		}
#line 3532 "C_grammar.tab.c"
    break;

  case 206: /* $@13: %empty  */
#line 945 "Parser/C_grammar.y"
                            {current_scope++; }
#line 3538 "C_grammar.tab.c"
    break;

  case 207: /* direct_declarator: direct_declarator $@13 '(' rest_function_definition ')'  */
#line 946 "Parser/C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("function(, )") + strlen((yyvsp[-4].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-4].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-4].declarator_type).full);
	     free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 3552 "C_grammar.tab.c"
    break;

  case 208: /* rest_direct_declarator: '[' ']'  */
#line 959 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "int(0)"); 
		}
#line 3559 "C_grammar.tab.c"
    break;

  case 209: /* rest_direct_declarator: '[' assignment_expression ']'  */
#line 962 "Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);
		}
#line 3566 "C_grammar.tab.c"
    break;

  case 210: /* rest_direct_declarator: '[' '*' ']'  */
#line 965 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D3"); 
		}
#line 3573 "C_grammar.tab.c"
    break;

  case 211: /* rest_direct_declarator: '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 968 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D4");
		}
#line 3580 "C_grammar.tab.c"
    break;

  case 212: /* rest_direct_declarator: '[' STATIC assignment_expression ']'  */
#line 971 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D5");
		}
#line 3587 "C_grammar.tab.c"
    break;

  case 213: /* rest_direct_declarator: '[' type_qualifier_list '*' ']'  */
#line 974 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D6");
		}
#line 3594 "C_grammar.tab.c"
    break;

  case 214: /* rest_direct_declarator: '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 977 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D7");
		}
#line 3601 "C_grammar.tab.c"
    break;

  case 215: /* rest_direct_declarator: '[' type_qualifier_list assignment_expression ']'  */
#line 980 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D8");
		}
#line 3608 "C_grammar.tab.c"
    break;

  case 216: /* rest_direct_declarator: '[' type_qualifier_list ']'  */
#line 983 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D9");
		}
#line 3615 "C_grammar.tab.c"
    break;

  case 217: /* rest_function_definition: %empty  */
#line 989 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 3621 "C_grammar.tab.c"
    break;

  case 219: /* rest_function_definition: old_style_parameter_list  */
#line 991 "Parser/C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 3627 "C_grammar.tab.c"
    break;

  case 222: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1001 "Parser/C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3637 "C_grammar.tab.c"
    break;

  case 223: /* parameter_type_list: parameter_list  */
#line 1007 "Parser/C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3647 "C_grammar.tab.c"
    break;

  case 224: /* $@14: %empty  */
#line 1015 "Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 3653 "C_grammar.tab.c"
    break;

  case 225: /* parameter_list: $@14 parameter_declaration  */
#line 1016 "Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);
		}
#line 3660 "C_grammar.tab.c"
    break;

  case 226: /* $@15: %empty  */
#line 1018 "Parser/C_grammar.y"
                             {push_decl_spec_stack();}
#line 3666 "C_grammar.tab.c"
    break;

  case 227: /* parameter_list: parameter_list ',' $@15 parameter_declaration  */
#line 1019 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 3677 "C_grammar.tab.c"
    break;

  case 228: /* parameter_declaration: type_declaration_specifiers declarator  */
#line 1029 "Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("param(, )") + strlen(decl_specifier) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param(%s, %s)", decl_specifier, (yyvsp[0].declarator_type).full);
	     free(decl_specifier);
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3690 "C_grammar.tab.c"
    break;

  case 229: /* parameter_declaration: type_declaration_specifiers abstract_declarator  */
#line 1038 "Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("unnamed_param(, dummy_abstract_declarator)") + strlen(decl_specifier) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "unnamed_param(%s, dummy_abstract_declarator)", decl_specifier);
	     free(decl_specifier);
		 //free($2);
		}
#line 3702 "C_grammar.tab.c"
    break;

  case 230: /* parameter_declaration: type_declaration_specifiers  */
#line 1046 "Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("unnamed_param(, [])") + strlen(decl_specifier) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "unnamed_param(%s, [])", decl_specifier);
	     free(decl_specifier);
		}
#line 3713 "C_grammar.tab.c"
    break;

  case 231: /* pointer: pointer_star pointer  */
#line 1057 "Parser/C_grammar.y"
                {size_t const size = strlen("pointer(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3724 "C_grammar.tab.c"
    break;

  case 232: /* pointer: pointer_star  */
#line 1063 "Parser/C_grammar.y"
                       {(yyval.id) = (yyvsp[0].id);}
#line 3730 "C_grammar.tab.c"
    break;

  case 233: /* $@16: %empty  */
#line 1067 "Parser/C_grammar.y"
              {push_decl_spec_stack();}
#line 3736 "C_grammar.tab.c"
    break;

  case 234: /* pointer_star: '*' $@16 type_qualifier_list  */
#line 1068 "Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("pointer()") + strlen(decl_specifier) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s)", decl_specifier);
	     free(decl_specifier);
		}
#line 3747 "C_grammar.tab.c"
    break;

  case 235: /* pointer_star: '*'  */
#line 1075 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3753 "C_grammar.tab.c"
    break;

  case 238: /* $@17: %empty  */
#line 1084 "Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 3759 "C_grammar.tab.c"
    break;

  case 239: /* type_name: $@17 specifier_qualifier_list abstract_declarator_opt  */
#line 1085 "Parser/C_grammar.y"
                {if (!strcmp((yyvsp[0].id), "")) {
			char *decl_specifier = create_declaration_specifiers();
			size_t const size = strlen("") + strlen(decl_specifier) + 1;
	     	(yyval.id) = (char*)malloc(size);
	     	sprintf_safe((yyval.id), size, "%s", decl_specifier);
			free(decl_specifier);
		 } else {
			pop_decl_spec_stack();
		 	simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");	//document please: when does this occur?
		 }
		 free((yyvsp[0].id));
		}
#line 3776 "C_grammar.tab.c"
    break;

  case 240: /* abstract_declarator_opt: %empty  */
#line 1100 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 3782 "C_grammar.tab.c"
    break;

  case 241: /* abstract_declarator_opt: abstract_declarator  */
#line 1101 "Parser/C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 3788 "C_grammar.tab.c"
    break;

  case 266: /* initializer: '{' initializer_list '}'  */
#line 1136 "Parser/C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3798 "C_grammar.tab.c"
    break;

  case 267: /* initializer: '{' initializer_list ',' '}'  */
#line 1142 "Parser/C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3808 "C_grammar.tab.c"
    break;

  case 269: /* initializer: '{' '}'  */
#line 1149 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 3814 "C_grammar.tab.c"
    break;

  case 270: /* initializer_list: designation initializer  */
#line 1154 "Parser/C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3825 "C_grammar.tab.c"
    break;

  case 272: /* initializer_list: initializer_list ',' designation initializer  */
#line 1162 "Parser/C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3837 "C_grammar.tab.c"
    break;

  case 273: /* initializer_list: initializer_list ',' initializer  */
#line 1170 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3848 "C_grammar.tab.c"
    break;

  case 274: /* designation: designator_list '='  */
#line 1180 "Parser/C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3858 "C_grammar.tab.c"
    break;

  case 276: /* designator_list: designator_list designator  */
#line 1190 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3869 "C_grammar.tab.c"
    break;

  case 277: /* designator: '[' constant_expression ']'  */
#line 1200 "Parser/C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3879 "C_grammar.tab.c"
    break;

  case 278: /* $@18: %empty  */
#line 1205 "Parser/C_grammar.y"
          {in_member_namespace = 1;}
#line 3885 "C_grammar.tab.c"
    break;

  case 279: /* designator: $@18 '.' IDENTIFIER  */
#line 1206 "Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3896 "C_grammar.tab.c"
    break;

  case 280: /* $@19: %empty  */
#line 1215 "Parser/C_grammar.y"
                                                                       {fsm_reset();}
#line 3902 "C_grammar.tab.c"
    break;

  case 281: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' $@19 ';'  */
#line 1216 "Parser/C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-3].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-5].id), (yyvsp[-3].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-3].id));
		}
#line 3913 "C_grammar.tab.c"
    break;

  case 283: /* $@20: %empty  */
#line 1226 "Parser/C_grammar.y"
          {current_scope++; fsm_reset();}
#line 3919 "C_grammar.tab.c"
    break;

  case 284: /* statement: $@20 compound_statement  */
#line 1228 "Parser/C_grammar.y"
          {pop_scope(&current_scope);
	   (yyval.id) = (yyvsp[0].id);
	  }
#line 3927 "C_grammar.tab.c"
    break;

  case 289: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1239 "Parser/C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3938 "C_grammar.tab.c"
    break;

  case 290: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1256 "Parser/C_grammar.y"
          {size_t const size = strlen("case_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3949 "C_grammar.tab.c"
    break;

  case 291: /* labeled_statement: DEFAULT ':' statement  */
#line 1263 "Parser/C_grammar.y"
          {size_t const size = strlen("default_stmt(branch(), )") + MAX_BRANCH_STR + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(branch(%d), %s)", branch_nb++, (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 3959 "C_grammar.tab.c"
    break;

  case 292: /* compound_statement: '{' '}'  */
#line 1271 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 3965 "C_grammar.tab.c"
    break;

  case 293: /* compound_statement: '{' block_item_list '}'  */
#line 1273 "Parser/C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 3975 "C_grammar.tab.c"
    break;

  case 294: /* $@21: %empty  */
#line 1281 "Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 3981 "C_grammar.tab.c"
    break;

  case 295: /* block_item_list: $@21 block_item  */
#line 1281 "Parser/C_grammar.y"
                                               {fsm_reset(); (yyval.id) = (yyvsp[0].id);}
#line 3987 "C_grammar.tab.c"
    break;

  case 296: /* $@22: %empty  */
#line 1282 "Parser/C_grammar.y"
                          {push_decl_spec_stack();}
#line 3993 "C_grammar.tab.c"
    break;

  case 297: /* block_item_list: block_item_list $@22 block_item  */
#line 1283 "Parser/C_grammar.y"
          {fsm_reset();
	   size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4005 "C_grammar.tab.c"
    break;

  case 299: /* block_item: statement  */
#line 1294 "Parser/C_grammar.y"
                    {pop_decl_spec_stack();}
#line 4011 "C_grammar.tab.c"
    break;

  case 300: /* expression_statement: ';'  */
#line 1298 "Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4017 "C_grammar.tab.c"
    break;

  case 301: /* expression_statement: expression ';'  */
#line 1300 "Parser/C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4027 "C_grammar.tab.c"
    break;

  case 302: /* selection_statement: IF '(' expression ')' statement else_opt  */
#line 1309 "Parser/C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4039 "C_grammar.tab.c"
    break;

  case 303: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1317 "Parser/C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id)); 
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4050 "C_grammar.tab.c"
    break;

  case 304: /* else_opt: %empty  */
#line 1326 "Parser/C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4056 "C_grammar.tab.c"
    break;

  case 305: /* else_opt: ELSE statement  */
#line 1328 "Parser/C_grammar.y"
                {
          /* if ELSE is followed by a single if_stmt(...) produced earlier, convert it to an else_if_stmt fragment
             so the outer if will attach ", \nelse_if_stmt(...)" rather than ", \nif_stmt(...)" */
          if ((yyvsp[0].id) && strncmp((yyvsp[0].id), "\nif_stmt(branch(", 16) == 0) {
              /* build ", \nelse_if_stmt(...)" from the existing if_stmt string by replacing "if_stmt" -> "else_if_stmt" */
              const char *orig = (yyvsp[0].id) + 1; /* skip leading newline */
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
              (yyval.id) = else_part;
          } else { // normal else: return ", <statement>"
              size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
              (yyval.id) = (char*)malloc(size);
              sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
          }
          free((yyvsp[0].id));
        }
#line 4090 "C_grammar.tab.c"
    break;

  case 306: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1361 "Parser/C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4101 "C_grammar.tab.c"
    break;

  case 307: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1368 "Parser/C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4112 "C_grammar.tab.c"
    break;

  case 308: /* iteration_statement: FOR '(' for_stmt_type ')' statement  */
#line 1375 "Parser/C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4125 "C_grammar.tab.c"
    break;

  case 309: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1387 "Parser/C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4131 "C_grammar.tab.c"
    break;

  case 310: /* $@23: %empty  */
#line 1388 "Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 4137 "C_grammar.tab.c"
    break;

  case 311: /* for_stmt_type: $@23 declaration expression_opt ';' expression_opt  */
#line 1389 "Parser/C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4143 "C_grammar.tab.c"
    break;

  case 312: /* expression_opt: %empty  */
#line 1393 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4149 "C_grammar.tab.c"
    break;

  case 314: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1398 "Parser/C_grammar.y"
          {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4160 "C_grammar.tab.c"
    break;

  case 315: /* jump_statement: CONTINUE ';'  */
#line 1404 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4166 "C_grammar.tab.c"
    break;

  case 316: /* jump_statement: BREAK ';'  */
#line 1405 "Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4172 "C_grammar.tab.c"
    break;

  case 317: /* jump_statement: RETURN ';'  */
#line 1406 "Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4178 "C_grammar.tab.c"
    break;

  case 318: /* jump_statement: RETURN expression ';'  */
#line 1408 "Parser/C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4188 "C_grammar.tab.c"
    break;

  case 319: /* $@24: %empty  */
#line 1417 "Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 4194 "C_grammar.tab.c"
    break;

  case 321: /* $@25: %empty  */
#line 1418 "Parser/C_grammar.y"
                           {fprintf(pl_file, ", \n"); push_decl_spec_stack();}
#line 4200 "C_grammar.tab.c"
    break;

  case 323: /* external_declaration: function_definition  */
#line 1423 "Parser/C_grammar.y"
                {fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4208 "C_grammar.tab.c"
    break;

  case 324: /* external_declaration: declaration  */
#line 1427 "Parser/C_grammar.y"
                {
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4217 "C_grammar.tab.c"
    break;

  case 325: /* $@26: %empty  */
#line 1433 "Parser/C_grammar.y"
                                                                      {fsm_reset();}
#line 4223 "C_grammar.tab.c"
    break;

  case 326: /* function_definition: type_declaration_specifiers declarator declaration_list_opt $@26 compound_statement  */
#line 1434 "Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("function(, , [], )") + strlen(decl_specifier) + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, %s, [%s], %s)", decl_specifier, (yyvsp[-3].declarator_type).full, (yyvsp[-2].id), (yyvsp[0].id));
		 if (debugMode) printf("function parsed\n");
	     free(decl_specifier);
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4239 "C_grammar.tab.c"
    break;

  case 327: /* declaration_list_opt: %empty  */
#line 1448 "Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4245 "C_grammar.tab.c"
    break;

  case 329: /* $@27: %empty  */
#line 1453 "Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 4251 "C_grammar.tab.c"
    break;

  case 330: /* old_style_declaration_list: $@27 declaration  */
#line 1453 "Parser/C_grammar.y"
                                                {(yyval.id) = (yyvsp[0].id);}
#line 4257 "C_grammar.tab.c"
    break;

  case 331: /* $@28: %empty  */
#line 1454 "Parser/C_grammar.y"
                                     {push_decl_spec_stack();}
#line 4263 "C_grammar.tab.c"
    break;

  case 332: /* old_style_declaration_list: old_style_declaration_list $@28 declaration  */
#line 1455 "Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4274 "C_grammar.tab.c"
    break;


#line 4278 "C_grammar.tab.c"

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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 1463 "Parser/C_grammar.y"

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
				my_exit(0);
			case 'p':	//path to the .i pre-processed input C file
				if (access_safe(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					my_exit(1);
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
		my_exit(EXIT_FAILURE);
	} else fprintf(stdout, "Sikraken parser %s: parsing the file %s using %i bits data model.\n", (debugMode) ? "in debug mode" : "", i_file_uri, dataModel);
	yyin = i_file;	//set the input to the parser

	size_t pl_path_len = strlen(C_file_path) + strlen(filename_no_ext) + 5; // "/.pl\0"
	pl_file_uri = malloc(pl_path_len);
	snprintf(pl_file_uri, pl_path_len, "%s/%s.pl", C_file_path, filename_no_ext);
	if (fopen_safe(&pl_file, pl_file_uri, "w") != 0) {
		fprintf(stderr, ".pl file could not be created for writing at: %s\n", pl_file_uri);
		my_exit(EXIT_FAILURE);
	}
	fflush(stdout);							//to ensure all previous information messages are printed out of buffer before the parsing starts and potentially generate unbuffered error messages

	/* initialisations */
	char *predefined_typedef = strdup("__gnuc_va_list");
	add_typedef_id(current_scope, predefined_typedef, 1);		//predefined typedef in GCC

	/* call the parser */
	fprintf(pl_file, "prolog_c([");			//opening top-level predicate
	if (yyparse() != 0) {					//the parser is called here
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
//  or if the .i file has been badly generated manually: i.e. during development
void yyerror(const char* s) {
	extern char* yytext;  	// Points to the text of the current token
    extern int yyleng;    	// Length of the current token
    fflush(stdout);			//to ensure all previous information messages are printed out of buffer before the error message
    fprintf(stderr, "Sikraken Parsing error: %s, at line %d, near token '%s' (token code: %d)\n", s, yylineno, yytext, yychar);
	fprintf(stderr, "Unexpected token: %s\n", token_name(yychar));
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
  if (exit_code == EXIT_SUCCESS) fprintf(stderr, "Sikraken parsing SUCCESS, wrote %s\n", pl_file_uri);
  exit(exit_code);
}

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
#include <stdbool.h>
#include "parser.h"
#include "utils.c"
#include "handle_typedefs.c"

typedef struct {
    bool isTypeDef;
    bool isExtern;
    bool isConstant;
    bool isStatic;
    bool isInt;
    bool isSigned;
    bool isShort;
    bool isRestrict;
    bool isVolatile;
    bool isAtomic;
    int longCount;
} SpecifierFlags;

bool otherDataTypes = false;

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
void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);
void process_declaration_specifiers(char a[]);


#line 148 "C_grammar.tab.c"

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
  YYSYMBOL_assignment_expression = 139,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 140,      /* assignment_operator  */
  YYSYMBOL_expression = 141,               /* expression  */
  YYSYMBOL_constant_expression = 142,      /* constant_expression  */
  YYSYMBOL_declaration = 143,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 144,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 145,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 146,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 147,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 148,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 149, /* struct_or_union_specifier  */
  YYSYMBOL_150_4 = 150,                    /* $@4  */
  YYSYMBOL_151_5 = 151,                    /* $@5  */
  YYSYMBOL_struct_or_union = 152,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 153,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 154,       /* struct_declaration  */
  YYSYMBOL_155_6 = 155,                    /* $@6  */
  YYSYMBOL_specifier_qualifier_list = 156, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 157,   /* struct_declarator_list  */
  YYSYMBOL_158_7 = 158,                    /* $@7  */
  YYSYMBOL_159_8 = 159,                    /* $@8  */
  YYSYMBOL_struct_declarator = 160,        /* struct_declarator  */
  YYSYMBOL_161_9 = 161,                    /* $@9  */
  YYSYMBOL_162_10 = 162,                   /* $@10  */
  YYSYMBOL_enum_specifier = 163,           /* enum_specifier  */
  YYSYMBOL_164_11 = 164,                   /* $@11  */
  YYSYMBOL_165_12 = 165,                   /* $@12  */
  YYSYMBOL_166_13 = 166,                   /* $@13  */
  YYSYMBOL_enum_specifier_rest = 167,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 168,          /* enumerator_list  */
  YYSYMBOL_enumerator = 169,               /* enumerator  */
  YYSYMBOL_170_14 = 170,                   /* $@14  */
  YYSYMBOL_atomic_type_specifier = 171,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 172,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 173,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 174,      /* alignment_specifier  */
  YYSYMBOL_declarator = 175,               /* declarator  */
  YYSYMBOL_direct_declarator = 176,        /* direct_declarator  */
  YYSYMBOL_177_15 = 177,                   /* $@15  */
  YYSYMBOL_rest_function_definition = 178, /* rest_function_definition  */
  YYSYMBOL_pointer = 179,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 180,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 181,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 182,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 183,    /* parameter_declaration  */
  YYSYMBOL_old_style_parameter_list = 184, /* old_style_parameter_list  */
  YYSYMBOL_type_name = 185,                /* type_name  */
  YYSYMBOL_abstract_declarator_opt = 186,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 187,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 188, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 189,              /* initializer  */
  YYSYMBOL_initializer_list = 190,         /* initializer_list  */
  YYSYMBOL_designation = 191,              /* designation  */
  YYSYMBOL_designator_list = 192,          /* designator_list  */
  YYSYMBOL_designator = 193,               /* designator  */
  YYSYMBOL_194_16 = 194,                   /* $@16  */
  YYSYMBOL_static_assert_declaration = 195, /* static_assert_declaration  */
  YYSYMBOL_statement = 196,                /* statement  */
  YYSYMBOL_197_17 = 197,                   /* $@17  */
  YYSYMBOL_labeled_statement = 198,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 199,       /* compound_statement  */
  YYSYMBOL_block_item_list = 200,          /* block_item_list  */
  YYSYMBOL_201_18 = 201,                   /* $@18  */
  YYSYMBOL_block_item = 202,               /* block_item  */
  YYSYMBOL_expression_statement = 203,     /* expression_statement  */
  YYSYMBOL_selection_statement = 204,      /* selection_statement  */
  YYSYMBOL_else_opt = 205,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 206,      /* iteration_statement  */
  YYSYMBOL_for_stmt_type = 207,            /* for_stmt_type  */
  YYSYMBOL_expression_opt = 208,           /* expression_opt  */
  YYSYMBOL_jump_statement = 209,           /* jump_statement  */
  YYSYMBOL_translation_unit = 210,         /* translation_unit  */
  YYSYMBOL_211_19 = 211,                   /* $@19  */
  YYSYMBOL_external_declaration = 212,     /* external_declaration  */
  YYSYMBOL_function_definition = 213,      /* function_definition  */
  YYSYMBOL_214_20 = 214,                   /* $@20  */
  YYSYMBOL_declaration_list_opt = 215,     /* declaration_list_opt  */
  YYSYMBOL_old_style_declaration_list = 216 /* old_style_declaration_list  */
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
#define YYLAST   2350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  313
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  506

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
       0,   147,   147,   151,   152,   153,   153,   160,   166,   170,
     171,   172,   176,   180,   181,   185,   189,   190,   194,   195,
     199,   200,   207,   213,   220,   220,   228,   228,   236,   242,
     248,   265,   266,   271,   272,   282,   283,   290,   297,   303,
     309,   318,   319,   323,   324,   325,   326,   327,   328,   332,
     333,   343,   344,   355,   356,   357,   361,   362,   373,   374,
     378,   379,   390,   391,   395,   396,   407,   408,   409,   410,
     415,   416,   427,   428,   432,   433,   443,   444,   454,   455,
     465,   466,   476,   477,   487,   488,   499,   500,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   525,
     526,   536,   541,   549,   566,   577,   585,   587,   595,   597,
     605,   606,   610,   614,   618,   625,   629,   640,   648,   658,
     663,   664,   665,   666,   667,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   691,   692,   693,   696,   696,   703,   703,   713,   726,
     730,   737,   738,   748,   755,   755,   763,   767,   774,   775,
     782,   786,   786,   787,   787,   797,   797,   803,   803,   811,
     819,   819,   833,   833,   833,   845,   846,   848,   857,   858,
     869,   869,   876,   880,   884,   885,   886,   887,   891,   892,
     896,   897,   902,   911,   915,   938,   941,   948,   953,   958,
     963,   968,   973,   978,   983,   991,   991,  1005,  1006,  1007,
    1011,  1018,  1024,  1030,  1035,  1036,  1046,  1052,  1061,  1062,
    1072,  1080,  1087,  1096,  1097,  1101,  1115,  1116,  1120,  1121,
    1122,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1150,  1156,  1162,  1163,  1168,  1175,  1176,  1184,
    1194,  1203,  1204,  1214,  1220,  1220,  1230,  1240,  1241,  1241,
    1245,  1246,  1247,  1248,  1252,  1260,  1267,  1274,  1283,  1284,
    1293,  1294,  1294,  1304,  1305,  1309,  1310,  1319,  1327,  1337,
    1338,  1346,  1353,  1360,  1372,  1374,  1379,  1380,  1383,  1390,
    1391,  1392,  1393,  1403,  1404,  1404,  1408,  1414,  1426,  1426,
    1440,  1441,  1445,  1446
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
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "$@4", "$@5", "struct_or_union", "struct_declaration_list",
  "struct_declaration", "$@6", "specifier_qualifier_list",
  "struct_declarator_list", "$@7", "$@8", "struct_declarator", "$@9",
  "$@10", "enum_specifier", "$@11", "$@12", "$@13", "enum_specifier_rest",
  "enumerator_list", "enumerator", "$@14", "atomic_type_specifier",
  "type_qualifier", "function_specifier", "alignment_specifier",
  "declarator", "direct_declarator", "$@15", "rest_function_definition",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "old_style_parameter_list",
  "type_name", "abstract_declarator_opt", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "$@16",
  "static_assert_declaration", "statement", "$@17", "labeled_statement",
  "compound_statement", "block_item_list", "$@18", "block_item",
  "expression_statement", "selection_statement", "else_opt",
  "iteration_statement", "for_stmt_type", "expression_opt",
  "jump_statement", "translation_unit", "$@19", "external_declaration",
  "function_definition", "$@20", "declaration_list_opt",
  "old_style_declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-432)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-311)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2010,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,
    -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,
    -432,  -432,  -432,  -432,  -432,    37,   -32,  2271,  -432,  -432,
     -29,  -432,  -432,  -432,  -432,  -432,    38,  2115,  2115,  -432,
      18,  -432,  -432,  2115,  2115,  2115,  -432,    69,  -432,  -432,
      -8,    99,   879,  2271,    75,  2271,     6,  1587,  -432,    52,
     158,  -432,   -58,  -432,   802,    87,    32,  -432,  -432,    19,
    -432,  -432,  -432,  -432,  -432,  2010,   107,  -432,  -432,  -432,
    -432,  -432,  -432,  -432,  1602,  -432,  -432,    33,    49,   879,
    -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,
     165,  -432,  1617,  1587,  -432,   -20,    -1,   113,    26,   136,
      51,    46,    48,   145,     9,  -432,    98,   117,  -432,  1741,
     972,   101,  -432,  -432,   126,  -432,  -432,   118,   134,  -432,
    -432,   158,    52,  -432,  1462,  -432,    38,  -432,  2010,   987,
     137,    87,   138,  2167,  -432,  -432,   148,   146,  -432,   147,
     879,  -432,  2271,  1587,   151,   836,  -432,  -432,   109,   155,
    -432,  -432,  1478,  1587,   133,   237,   879,  -432,  -432,  -432,
    -432,  -432,  1587,  -432,  -432,  1587,  -432,  -432,  1587,  -432,
    -432,  -432,  -432,  1587,  -432,  -432,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  -432,  -432,  -432,   119,   171,   175,  -432,
     177,  1296,  -432,   174,   176,  1080,   126,  1905,  1095,   255,
    -432,  -432,  -432,  -432,   161,  1311,  -432,  -432,   151,  -432,
    1296,  -432,   179,   180,  1188,  1958,  2167,  1795,  -432,   164,
    -432,   166,   107,   183,   107,  -432,   191,   193,   194,   523,
     196,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,
    -432,  -432,  1587,  -432,  1587,  1571,  -432,   111,  -432,    -4,
     278,   279,   202,  -432,   -20,    -1,   113,    26,   136,    51,
      46,    48,   145,   129,  1681,  -432,    90,  -432,  -432,  2062,
    -432,   199,  1296,  -432,  -432,  1587,  -432,   201,  -432,   206,
    1296,  -432,   208,   210,  1203,   215,  1587,  -432,  -432,   -50,
    1462,   -28,  -432,   205,  -432,   212,  1296,  -432,  -432,  1587,
    -432,   213,   216,  -432,   219,  -432,   221,  1847,  -432,  -432,
    -432,  -432,  1587,  -432,  -432,   -45,   218,  -432,  2219,   226,
     227,  1587,   229,   235,   236,   238,   420,   239,   318,   222,
     223,   724,  -432,  -432,   -56,  -432,  -432,   151,  -432,   616,
    -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,  1446,  -432,
    -432,  1587,  -432,  -432,  -432,   218,  1587,  -432,  -432,  -432,
     242,   247,  -432,  -432,   248,  1296,  -432,  -432,  1587,  -432,
     250,   234,   254,  1337,  -432,  -432,  -432,  -432,   319,  -432,
     256,   257,  -432,  -432,  -432,   320,  -432,   -46,    52,  -432,
      12,  -432,   241,   132,  -432,   260,   420,   420,   261,   420,
    1587,  1587,  1587,   227,   284,   709,   243,  -432,  -432,  -432,
     -15,  -432,  -432,  -432,  -432,   265,  -432,  -432,  -432,  -432,
    -432,   263,   264,  -432,  -432,  -432,  -432,  -432,  1462,  -432,
    -432,  -432,  -432,    52,  -432,  -432,   267,   268,  -432,  1587,
    -432,  2219,  1587,  -432,  -432,   420,  -432,   140,   149,   160,
     272,  1587,  1587,   274,  -432,  -432,  -432,  1430,   269,  -432,
    -432,  -432,  -432,  1587,   270,  -432,  -432,  -432,  -432,   420,
     420,   420,  1587,   276,   253,   258,   420,  -432,  -432,  -432,
    1587,   300,  -432,  -432,   173,  1587,  1587,  -432,  -432,   420,
    -432,   259,  -432,  -432,  -432,  -432
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   140,   119,   120,   121,   123,   124,   188,   184,   185,
     186,   134,   126,   127,   128,   129,   132,   133,   130,   131,
     125,   135,   136,   149,   150,   170,     0,     0,   187,   189,
       0,   122,   141,   142,   143,   307,     0,   106,   108,   138,
       0,   139,   137,   110,   112,   114,   104,   304,   303,   306,
       0,     0,     0,   158,   226,   160,     0,     0,   194,     0,
     213,   102,     0,   115,   118,   193,     0,   105,   107,   148,
     144,   109,   111,   113,     1,     0,     0,   173,     2,     9,
      10,    11,    13,    14,     0,    41,    42,     0,     0,     5,
      43,    44,    45,    46,    47,    48,    20,     3,     4,     8,
      35,    49,     0,     0,    51,    56,    60,    64,    70,    74,
      76,    78,    80,    82,    84,   101,     0,     0,   157,     0,
       0,   229,   225,   227,   230,   159,   183,     0,     0,   214,
     212,   211,     0,   103,     0,   312,     0,   308,   311,     0,
       0,   192,     0,     0,   305,    12,   182,    31,   178,   175,
       5,    38,     0,     0,     0,    49,    86,    99,     0,     0,
      28,    29,     0,     0,     0,     0,     5,    36,    37,    53,
      54,    55,     0,    58,    59,     0,    62,    63,     0,    68,
      69,    66,    67,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,   191,   190,   248,   222,     0,   217,   218,
       0,     0,   232,    44,     0,     0,   228,     0,     0,     0,
     195,   215,   210,   116,   118,   264,   254,   117,     0,   313,
       0,   196,    44,     0,     0,   207,     0,     0,   151,   154,
     156,     0,    32,     0,     0,   174,     0,     0,     0,   268,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    88,     0,     7,     0,     0,    22,     0,    33,     0,
       0,     0,     0,    52,    57,    61,    65,    71,    75,    77,
      79,    81,    83,     0,     0,   220,   229,   221,   249,     0,
     231,     0,     0,   233,   239,     0,   238,     0,   250,     0,
       0,   240,    44,     0,     0,     0,     0,   255,   257,     0,
       0,   264,   261,     0,   309,     0,     0,   197,   204,     0,
     203,    44,     0,   223,     0,   208,   209,     0,   145,   152,
     153,   161,     0,   179,   171,     0,    39,    40,     0,     2,
     140,     0,     0,     0,     0,     0,   268,     0,     0,     0,
       0,     0,   278,   285,     0,   283,   284,     0,   267,   268,
     280,   270,   271,   272,   273,     6,    87,   100,   264,    50,
      23,     0,    21,    25,    27,     0,     0,   216,   219,   235,
       0,     0,   237,   251,     0,     0,   241,   247,     0,   246,
       0,     0,     0,   264,   252,   256,   260,   262,     0,   199,
       0,     0,   200,   202,   206,     0,   147,     0,   165,   181,
       0,   176,     0,     0,    16,     0,   268,   268,     0,   268,
       0,     0,     0,     0,     0,     0,     0,   299,   300,   301,
       0,   286,   269,   279,   281,    31,    34,    85,   234,   236,
     243,     0,     0,   244,   266,   263,   253,   259,     0,   265,
     198,   201,   224,   165,   155,   162,     0,   169,   177,     0,
      15,     0,     0,   274,   275,   268,   277,     0,     0,     0,
       0,   296,   296,     0,   298,   302,   282,    32,     0,   242,
     245,   258,   163,     0,     0,    19,    17,    18,   276,   268,
     268,   268,     0,   297,     0,     0,   268,    30,   164,   166,
       0,   289,   288,   291,     0,   296,   296,   293,   168,   268,
     287,     0,   295,   294,   290,   292
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -432,  -432,  -432,  -432,  -432,  -432,  -432,  -432,   -90,  -432,
    -432,  -432,   -61,  -432,   -52,  -432,  -432,   -85,   197,  -432,
     188,  -432,   185,  -432,   187,  -432,   182,  -432,   186,   189,
     181,   192,  -432,   -51,    85,  -432,   -80,   -55,   -60,    29,
    -432,   245,  -432,     7,  -432,  -432,  -432,  -432,   154,  -208,
    -432,   -43,  -432,  -432,  -432,   -57,  -432,  -432,  -432,  -432,
    -432,  -432,  -432,   150,  -219,  -432,  -432,     1,  -432,  -432,
     -33,   -59,  -432,  -432,   -34,  -103,  -144,  -432,   108,  -432,
      -5,  -432,   -38,  -107,  -126,    30,  -359,  -432,    88,  -432,
    -132,  -291,  -432,  -432,  -195,  -432,  -432,    41,   -23,  -432,
    -432,  -432,  -432,  -431,  -432,  -432,  -432,   321,  -432,  -432,
    -432,  -432
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    96,   154,    97,   146,    98,    99,   403,   404,   100,
     164,   165,   233,   257,   155,   102,   103,   104,   105,   172,
     106,   175,   107,   178,   108,   183,   109,   186,   110,   111,
     112,   113,   114,   156,   157,   252,   344,   116,    35,   136,
      62,    63,    37,    38,    39,   143,   142,    40,   227,   228,
     321,    54,   397,   398,   488,   445,   446,   474,    41,    50,
      51,   149,   235,   147,   148,   231,    42,    43,    44,    45,
     128,    65,   140,   314,    66,   131,   197,   198,   199,   316,
     405,   122,   200,   124,   298,   299,   300,   301,   302,   303,
      46,   346,   347,   348,   240,   349,   466,   350,   351,   352,
     500,   353,   463,   484,   354,    47,    75,    48,    49,   218,
     137,   138
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   115,   127,    64,   135,   101,   115,   141,   217,   158,
     118,   230,   125,   323,   206,   145,   123,   205,   168,   319,
     121,    69,    56,   304,   438,   132,   130,   254,    55,    36,
     191,   485,   151,   383,    53,    58,   224,   443,   400,   384,
    -172,    58,   179,   180,   401,   414,   133,   117,   421,    52,
     167,   101,    57,    55,    55,    58,    55,   296,   444,    53,
      53,   129,    53,   289,   502,   503,    67,    68,   254,    74,
     158,   169,    71,    72,    73,   386,   170,   171,   219,   254,
      76,   315,   362,   259,   159,   121,   158,   263,   126,   465,
      55,   173,   174,    58,   230,   230,    53,   212,   282,   214,
     229,   448,    77,   214,    36,   294,    70,  -146,   438,   319,
     145,   192,   273,    59,   152,   453,   454,   306,   456,    59,
     101,   129,    58,   101,   181,   182,   101,   176,   177,    60,
     153,   101,   211,    59,   101,   101,   101,   101,   101,   101,
     129,   187,    61,    60,    55,   236,   188,   237,   196,   189,
      53,    55,   422,    55,   184,   185,   119,    53,   277,    53,
     120,   262,   276,   275,   478,   190,    60,    55,  -205,   206,
     359,   274,   139,    53,   385,   120,   -26,   160,   161,   345,
     193,   323,   119,   229,   229,   230,   120,   375,   491,   492,
     493,   253,   254,   360,   361,   497,     8,     9,    10,   194,
     274,   209,   129,   101,   120,   204,   211,   207,   504,   129,
      60,   208,   254,   366,   450,   451,   210,   141,   225,   216,
     260,   129,   479,   254,   223,   211,   226,    55,    55,   232,
      28,   480,   254,    53,    53,   234,   196,   255,   238,   239,
     276,   382,   481,   254,   101,   115,   162,   258,   261,    60,
     163,  -180,   -24,   278,   196,   501,   254,   437,   279,   280,
     283,   420,   284,   295,   134,   307,   308,   399,   320,   322,
     101,   115,   324,   326,   229,   327,   408,   328,   355,   101,
     115,   363,   364,   211,   365,   369,   281,   372,   373,   345,
     287,   129,   388,   293,   376,   211,   377,   381,   389,   392,
     216,   394,   393,   196,   395,   305,   358,   211,   196,   312,
     406,   407,   471,   409,   101,   427,   410,   411,    55,   412,
     415,   416,   439,   442,    53,   449,   417,   418,   428,    55,
     457,   458,   459,   429,   430,    53,   433,   356,   434,   357,
     435,   437,   440,   441,   452,   455,   460,   464,   467,   469,
     470,   473,  -167,   482,   490,   461,   486,   495,   487,   254,
     499,   476,   496,   505,   468,   447,   265,   370,   266,   268,
     371,   271,   264,   267,   269,   374,   211,   213,   270,   380,
     317,   483,   483,   272,   325,   216,   472,   368,   425,   387,
     424,   390,   462,     0,   391,     0,   144,     0,     0,     0,
       0,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     447,     0,     0,     0,     0,   483,   483,     0,   489,     0,
       0,   101,   115,   329,   413,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,   498,     0,     0,   101,   115,
       0,     0,     0,   216,     0,     0,   426,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,    53,     0,
     431,     0,     0,   432,     0,     0,     0,     0,   216,     0,
       0,     0,     0,     0,     0,     0,     0,   331,   332,   333,
       0,   334,   335,   336,   337,   338,   339,   340,   341,     0,
      87,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,   216,   343,     0,   329,   330,    79,    80,
      81,    82,    83,    84,   475,    85,    86,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
     331,   332,   333,     0,   334,   335,   336,   337,   338,   339,
     340,   341,    26,    87,    27,    28,    88,    29,    30,    31,
      32,    33,    34,     0,    89,     0,     0,     0,     0,     0,
       0,     0,   342,    90,    91,    92,    93,    94,    95,   329,
     330,    79,    80,    81,    82,    83,    84,   343,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,   331,   332,   333,     0,   334,   335,   336,
     337,   338,   339,   340,   341,    26,    87,    27,    28,    88,
      29,    30,    31,    32,    33,    34,     0,    89,     0,     0,
       0,     0,     0,     0,     0,   423,    90,    91,    92,    93,
      94,    95,    78,     1,    79,    80,    81,    82,    83,    84,
     343,    85,    86,     0,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    87,
      27,    28,    88,    29,    30,    31,    32,    33,    34,     0,
      89,     0,     0,     0,    87,     0,     0,    88,     0,    90,
      91,    92,    93,    94,    95,    89,     1,     0,     0,     0,
       0,     0,     0,   343,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,   419,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,     0,
       0,    26,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,    78,     1,    79,    80,    81,    82,    83,    84,
    -310,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      27,    28,    88,     0,     0,     0,    32,    33,    34,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,   201,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,    28,    88,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,    87,   202,    28,
      88,     0,    90,   203,    92,    93,    94,    95,    89,     0,
       0,     0,     0,   221,     0,     0,     0,    90,   222,    92,
      93,    94,    95,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,   285,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,    28,    88,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,    87,   286,    28,    88,     0,
      90,    91,    92,    93,    94,    95,    89,     0,     0,     0,
       0,   291,     0,     0,     0,    90,   292,    92,    93,    94,
      95,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,   309,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,   378,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
      28,    88,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,    87,   310,    28,    88,     0,    90,   311,
      92,    93,    94,    95,    89,     0,     0,     0,     0,   379,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    78,
       0,    79,    80,    81,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,    28,    88,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,    87,     0,     0,    88,     0,    90,    91,    92,    93,
      94,    95,    89,     0,     0,     0,   296,     0,     0,   215,
     297,    90,    91,    92,    93,    94,    95,    87,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,   296,     0,     0,   215,   436,    90,    91,    92,
      93,    94,    95,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,     0,    78,
       0,    79,    80,    81,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,   296,    87,  -264,   215,    88,
      90,    91,    92,    93,    94,    95,     0,    89,     0,     0,
       0,   296,    87,     0,   215,    88,    90,    91,    92,    93,
      94,    95,     0,    89,     0,     0,     0,     0,    87,     0,
     215,    88,    90,    91,    92,    93,    94,    95,     0,    89,
     256,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,    87,     0,   358,
      88,    90,    91,    92,    93,    94,    95,     0,    89,     0,
       0,     0,    87,     0,     0,    88,     0,    90,    91,    92,
      93,    94,    95,   150,    58,     1,     0,    87,     0,     0,
      88,     0,    90,    91,    92,    93,    94,    95,   166,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
      26,     0,    27,    28,     0,    29,     0,    31,    32,    33,
      34,     0,   274,   195,     0,     0,   120,     0,     0,     0,
       0,     0,    60,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,    28,     0,    29,     0,    31,    32,    33,
      34,     0,   119,   195,     0,     0,   120,     0,     0,     0,
       0,     0,    60,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      30,     0,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   318,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    30,     0,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   396,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   313,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,    32,    33,    34,     0,     0,   288,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,    29,     0,    31,    32,    33,    34,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,    30,    31,    32,    33,    34,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   367,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,    32,
      33,    34,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    30,     0,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    32,    33,
      34
};

static const yytype_int16 yycheck[] =
{
      52,    52,    57,    36,    64,    57,    57,    66,   134,    89,
      53,   143,    55,   232,   121,     3,    54,   120,   103,   227,
      54,     3,    27,   218,   383,    83,    60,    83,    27,     0,
      21,   462,    84,    83,    27,     3,   139,    83,    83,    89,
       3,     3,    16,    17,    89,   336,   104,    52,   104,    81,
     102,   103,    81,    52,    53,     3,    55,    85,   104,    52,
      53,    60,    55,   207,   495,   496,    37,    38,    83,     0,
     150,    91,    43,    44,    45,   103,    96,    97,   138,    83,
      88,   225,    86,   163,    89,   119,   166,   172,    82,   104,
      89,    92,    93,     3,   226,   227,    89,   131,   201,   132,
     143,    89,     3,   136,    75,   208,    88,    88,   467,   317,
       3,   102,   192,    81,    81,   406,   407,   220,   409,    81,
     172,   120,     3,   175,    98,    99,   178,    14,    15,    91,
      81,   183,   131,    81,   186,   187,   188,   189,   190,   191,
     139,    90,   104,    91,   143,   150,   100,   152,   119,   101,
     143,   150,   347,   152,    18,    19,    81,   150,   196,   152,
      85,   166,   196,   196,   455,    20,    91,   166,    81,   276,
     255,    81,    85,   166,   300,    85,    11,    12,    13,   239,
      82,   400,    81,   226,   227,   317,    85,   290,   479,   480,
     481,    82,    83,    82,    83,   486,    38,    39,    40,    82,
      81,    83,   201,   255,    85,   120,   205,    81,   499,   208,
      91,    85,    83,    84,    82,    83,    82,   276,    81,   134,
      87,   220,    82,    83,   139,   224,    88,   226,   227,    83,
      72,    82,    83,   226,   227,    88,   207,    82,   153,    88,
     274,   296,    82,    83,   296,   296,    81,   162,    11,    91,
      85,   103,    87,    82,   225,    82,    83,   383,    83,    82,
      86,   341,    86,     8,   103,    86,    86,   322,   104,   103,
     322,   322,    89,    82,   317,    82,   331,    83,    82,   331,
     331,     3,     3,   282,    82,    86,   201,    86,    82,   349,
     205,   290,    87,   208,    86,   294,    86,    82,    86,    86,
     215,    82,    86,   274,    83,   220,    88,   306,   279,   224,
      84,    84,   438,    84,   366,   366,    81,    81,   317,    81,
      81,     3,     3,     3,   317,    84,   104,   104,    86,   328,
     410,   411,   412,    86,    86,   328,    86,   252,   104,   254,
      86,   467,    86,    86,    84,    84,    62,   104,    83,    86,
      86,    84,    84,    81,    84,   415,    82,   104,    89,    83,
      60,   451,   104,   104,   425,   398,   178,   282,   183,   187,
     285,   190,   175,   186,   188,   290,   375,   132,   189,   294,
     226,   461,   462,   191,   234,   300,   443,   279,   358,   301,
     349,   306,   415,    -1,   309,    -1,    75,    -1,    -1,    -1,
      -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,    -1,   495,   496,    -1,   473,    -1,
      -1,   473,   473,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,   490,    -1,    -1,   490,   490,
      -1,    -1,    -1,   358,    -1,    -1,   361,    -1,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,   451,    -1,
     375,    -1,    -1,   378,    -1,    -1,    -1,    -1,   383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   438,   104,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,   449,    12,    13,   452,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   467,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,     3,
       4,     5,     6,     7,     8,     9,    10,   104,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,     3,     4,     5,     6,     7,     8,     9,    10,
     104,    12,    13,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    90,
      91,    92,    93,    94,    95,    81,     4,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    90,    91,    92,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,     3,     4,     5,     6,     7,     8,     9,    10,
      88,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    70,    86,    72,
      73,    -1,    90,    91,    92,    93,    94,    95,    81,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    70,    86,    72,    73,    -1,
      90,    91,    92,    93,    94,    95,    81,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    70,    86,    72,    73,    -1,    90,    91,
      92,    93,    94,    95,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    90,    91,    92,    93,
      94,    95,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    85,    -1,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    70,    87,    88,    73,
      90,    91,    92,    93,    94,    95,    -1,    81,    -1,    -1,
      -1,    85,    70,    -1,    88,    73,    90,    91,    92,    93,
      94,    95,    -1,    81,    -1,    -1,    -1,    -1,    70,    -1,
      88,    73,    90,    91,    92,    93,    94,    95,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    70,    -1,    88,
      73,    90,    91,    92,    93,    94,    95,    -1,    81,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    90,    91,    92,
      93,    94,    95,    81,     3,     4,    -1,    70,    -1,    -1,
      73,    -1,    90,    91,    92,    93,    94,    95,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      75,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    75,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    -1,    82,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    75,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,    78,
      79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,    77,    78,    79,   143,   144,   147,   148,   149,
     152,   163,   171,   172,   173,   174,   195,   210,   212,   213,
     164,   165,    81,   148,   156,   172,   185,    81,     3,    81,
      91,   104,   145,   146,   175,   176,   179,   144,   144,     3,
      88,   144,   144,   144,     0,   211,    88,     3,     3,     5,
       6,     7,     8,     9,    10,    12,    13,    70,    73,    81,
      90,    91,    92,    93,    94,    95,   106,   108,   110,   111,
     114,   119,   120,   121,   122,   123,   125,   127,   129,   131,
     133,   134,   135,   136,   137,   138,   142,   185,   156,    81,
      85,   179,   186,   187,   188,   156,    82,   142,   175,   172,
     179,   180,    83,   104,   103,   143,   144,   215,   216,    85,
     177,   176,   151,   150,   212,     3,   109,   168,   169,   166,
      81,   119,    81,    81,   107,   119,   138,   139,   141,   185,
      12,    13,    81,    85,   115,   116,    81,   119,   122,    91,
      96,    97,   124,    92,    93,   126,    14,    15,   128,    16,
      17,    98,    99,   130,    18,    19,   132,    90,   100,   101,
      20,    21,   102,    82,    82,    82,   144,   181,   182,   183,
     187,    34,    86,    91,   139,   180,   188,    81,    85,    83,
      82,   172,   179,   146,   175,    88,   139,   189,   214,   143,
      34,    86,    91,   139,   180,    81,    88,   153,   154,   156,
     195,   170,    83,   117,    88,   167,   185,   185,   139,    88,
     199,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   103,   140,    82,    83,    82,    82,   118,   139,   141,
      87,    11,   185,   122,   123,   125,   127,   129,   131,   133,
     134,   135,   136,   141,    81,   175,   179,   187,    82,    83,
      82,   139,   180,    86,    86,    34,    86,   139,    82,   181,
      34,    86,    91,   139,   180,     8,    85,    89,   189,   190,
     191,   192,   193,   194,   199,   139,   180,    86,    86,    34,
      86,    91,   139,     3,   178,   181,   184,   153,    89,   154,
     104,   155,   103,   169,    89,   168,    82,    82,    83,     3,
       4,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    89,   104,   141,   143,   196,   197,   198,   200,
     202,   203,   204,   206,   209,    82,   139,   139,    88,   122,
      82,    83,    86,     3,     3,    82,    84,    56,   183,    86,
     139,   139,    86,    82,   139,   180,    86,    86,    34,    86,
     139,    82,   142,    83,    89,   189,   103,   193,    87,    86,
     139,   139,    86,    86,    82,    83,    89,   157,   158,   142,
      83,    89,    58,   112,   113,   185,    84,    84,   142,    84,
      81,    81,    81,     4,   196,    81,     3,   104,   104,   104,
     141,   104,   199,    89,   202,   190,   139,   138,    86,    86,
      86,   139,   139,    86,   104,    86,    89,   189,   191,     3,
      86,    86,     3,    83,   104,   160,   161,   175,    89,    84,
      82,    83,    84,   196,   196,    84,   196,   141,   141,   141,
      62,   143,   203,   207,   104,   104,   201,    83,   117,    86,
      86,   189,   160,    84,   162,   139,   113,   139,   196,    82,
      82,    82,    81,   141,   208,   208,    82,    89,   159,   142,
      84,   196,   196,   196,   141,   104,   104,   196,   142,    60,
     205,    82,   208,   208,   196,   104
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
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   141,
     141,   142,   143,   143,   143,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   145,   145,   146,   146,   147,
     147,   147,   147,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   150,   149,   151,   149,   149,   152,
     152,   153,   153,   154,   155,   154,   154,   156,   156,   156,
     156,   158,   157,   159,   157,   161,   160,   162,   160,   160,
     164,   163,   165,   166,   163,   167,   167,   167,   168,   168,
     170,   169,   169,   171,   172,   172,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   177,   176,   178,   178,   178,
     179,   179,   179,   179,   180,   180,   181,   181,   182,   182,
     183,   183,   183,   184,   184,   185,   186,   186,   187,   187,
     187,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   189,   189,   189,   189,   190,   190,   190,   190,
     191,   192,   192,   193,   194,   193,   195,   196,   197,   196,
     196,   196,   196,   196,   198,   198,   198,   198,   199,   199,
     200,   201,   200,   202,   202,   203,   203,   204,   204,   205,
     205,   206,   206,   206,   207,   207,   208,   208,   209,   209,
     209,   209,   209,   210,   211,   210,   212,   212,   214,   213,
     215,   215,   216,   216
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
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     0,     6,     2,     1,
       1,     1,     2,     2,     0,     4,     1,     2,     1,     2,
       1,     0,     2,     0,     4,     0,     3,     0,     4,     1,
       0,     6,     0,     0,     5,     0,     3,     4,     1,     3,
       0,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       4,     4,     2,     1,     1,     3,     3,     4,     6,     5,
       5,     6,     5,     4,     4,     0,     5,     0,     1,     1,
       3,     2,     2,     1,     1,     2,     3,     1,     1,     3,
       2,     2,     1,     1,     3,     2,     0,     1,     2,     1,
       1,     3,     2,     3,     5,     4,     5,     4,     3,     3,
       3,     4,     6,     5,     5,     6,     4,     4,     2,     3,
       3,     4,     3,     4,     1,     2,     2,     1,     4,     3,
       2,     1,     2,     3,     0,     3,     7,     1,     0,     2,
       1,     1,     1,     1,     3,     3,     4,     3,     2,     3,
       1,     0,     3,     1,     1,     1,     2,     6,     5,     0,
       2,     5,     7,     5,     4,     4,     0,     1,     3,     2,
       2,     2,     3,     1,     0,     3,     1,     1,     0,     5,
       0,     1,     1,     2
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
#line 148 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2400 "C_grammar.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 153 "C_grammar.y"
              {in_ordinary_id_declaration = 0; current_scope++;}
#line 2406 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' $@1 compound_statement ')'  */
#line 154 "C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2417 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 161 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2427 "C_grammar.tab.c"
    break;

  case 8: /* primary_expression: generic_selection  */
#line 166 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2433 "C_grammar.tab.c"
    break;

  case 14: /* string: FUNC_NAME  */
#line 181 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2439 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 201 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2450 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' ')'  */
#line 208 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2460 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 214 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2471 "C_grammar.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 220 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2477 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression $@2 '.' IDENTIFIER  */
#line 221 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2489 "C_grammar.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 228 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2495 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression $@3 PTR_OP IDENTIFIER  */
#line 229 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2507 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression INC_OP  */
#line 237 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2517 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression DEC_OP  */
#line 243 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2527 "C_grammar.tab.c"
    break;

  case 30: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 249 "C_grammar.y"
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
#line 2545 "C_grammar.tab.c"
    break;

  case 31: /* comma_opt: %empty  */
#line 265 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2551 "C_grammar.tab.c"
    break;

  case 32: /* comma_opt: ','  */
#line 266 "C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2557 "C_grammar.tab.c"
    break;

  case 34: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 273 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2568 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: unary_inc_dec unary_expression  */
#line 284 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2579 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: unary_operator cast_expression  */
#line 291 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2590 "C_grammar.tab.c"
    break;

  case 38: /* unary_expression: SIZEOF unary_expression  */
#line 298 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2600 "C_grammar.tab.c"
    break;

  case 39: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 304 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2610 "C_grammar.tab.c"
    break;

  case 40: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 310 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2620 "C_grammar.tab.c"
    break;

  case 41: /* unary_inc_dec: INC_OP  */
#line 318 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2626 "C_grammar.tab.c"
    break;

  case 42: /* unary_inc_dec: DEC_OP  */
#line 319 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2632 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '&'  */
#line 323 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2638 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '*'  */
#line 324 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2644 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '+'  */
#line 325 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2650 "C_grammar.tab.c"
    break;

  case 46: /* unary_operator: '-'  */
#line 326 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2656 "C_grammar.tab.c"
    break;

  case 47: /* unary_operator: '~'  */
#line 327 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2662 "C_grammar.tab.c"
    break;

  case 48: /* unary_operator: '!'  */
#line 328 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2668 "C_grammar.tab.c"
    break;

  case 50: /* cast_expression: '(' type_name ')' cast_expression  */
#line 334 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2679 "C_grammar.tab.c"
    break;

  case 52: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 345 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2691 "C_grammar.tab.c"
    break;

  case 53: /* multiplicative_expression_op: '*'  */
#line 355 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2697 "C_grammar.tab.c"
    break;

  case 54: /* multiplicative_expression_op: '/'  */
#line 356 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2703 "C_grammar.tab.c"
    break;

  case 55: /* multiplicative_expression_op: '%'  */
#line 357 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2709 "C_grammar.tab.c"
    break;

  case 57: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 363 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2721 "C_grammar.tab.c"
    break;

  case 58: /* additive_expression_op: '+'  */
#line 373 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2727 "C_grammar.tab.c"
    break;

  case 59: /* additive_expression_op: '-'  */
#line 374 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2733 "C_grammar.tab.c"
    break;

  case 61: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 380 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2745 "C_grammar.tab.c"
    break;

  case 62: /* shift_expression_op: LEFT_OP  */
#line 390 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2751 "C_grammar.tab.c"
    break;

  case 63: /* shift_expression_op: RIGHT_OP  */
#line 391 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2757 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 397 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2769 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression_operator: '<'  */
#line 407 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2775 "C_grammar.tab.c"
    break;

  case 67: /* relational_expression_operator: '>'  */
#line 408 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2781 "C_grammar.tab.c"
    break;

  case 68: /* relational_expression_operator: LE_OP  */
#line 409 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2787 "C_grammar.tab.c"
    break;

  case 69: /* relational_expression_operator: GE_OP  */
#line 410 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2793 "C_grammar.tab.c"
    break;

  case 71: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 417 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2805 "C_grammar.tab.c"
    break;

  case 72: /* equality_expression_op: EQ_OP  */
#line 427 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2811 "C_grammar.tab.c"
    break;

  case 73: /* equality_expression_op: NE_OP  */
#line 428 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2817 "C_grammar.tab.c"
    break;

  case 75: /* and_expression: and_expression '&' equality_expression  */
#line 434 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2828 "C_grammar.tab.c"
    break;

  case 77: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 445 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2839 "C_grammar.tab.c"
    break;

  case 79: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 456 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2850 "C_grammar.tab.c"
    break;

  case 81: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 467 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2861 "C_grammar.tab.c"
    break;

  case 83: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 478 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2872 "C_grammar.tab.c"
    break;

  case 85: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 489 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2884 "C_grammar.tab.c"
    break;

  case 87: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 501 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2896 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: '='  */
#line 511 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2902 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: MUL_ASSIGN  */
#line 512 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2908 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: DIV_ASSIGN  */
#line 513 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2914 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: MOD_ASSIGN  */
#line 514 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2920 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: ADD_ASSIGN  */
#line 515 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2926 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: SUB_ASSIGN  */
#line 516 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2932 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: LEFT_ASSIGN  */
#line 517 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2938 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: RIGHT_ASSIGN  */
#line 518 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2944 "C_grammar.tab.c"
    break;

  case 96: /* assignment_operator: AND_ASSIGN  */
#line 519 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2950 "C_grammar.tab.c"
    break;

  case 97: /* assignment_operator: XOR_ASSIGN  */
#line 520 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2956 "C_grammar.tab.c"
    break;

  case 98: /* assignment_operator: OR_ASSIGN  */
#line 521 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2962 "C_grammar.tab.c"
    break;

  case 100: /* expression: expression ',' assignment_expression  */
#line 527 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2973 "C_grammar.tab.c"
    break;

  case 102: /* declaration: declaration_specifiers ';'  */
#line 542 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 printf("end of stand alone declaration specifier as a declaration in_ordinary_id_declaration is %d on line %d\n", in_ordinary_id_declaration, yylineno);
		 size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2985 "C_grammar.tab.c"
    break;

  case 103: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 550 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0; 
			//if (debugMode) printf("Debug: typedef switched to 0\n");
	   	 }
		 if(!otherDataTypes){
			process_declaration_specifiers((yyvsp[-2].id));
		 }else{
			otherDataTypes = false;
		 }
		 size_t const size = strlen("\ndeclaration([], [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 3006 "C_grammar.tab.c"
    break;

  case 104: /* declaration: static_assert_declaration  */
#line 567 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3017 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 578 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3029 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: storage_class_specifier  */
#line 586 "C_grammar.y"
                {in_ordinary_id_declaration = 1;}
#line 3035 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 588 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3047 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: type_specifier  */
#line 596 "C_grammar.y"
                {in_ordinary_id_declaration = 1;}
#line 3053 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 598 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3065 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: type_qualifier  */
#line 605 "C_grammar.y"
                         {in_ordinary_id_declaration = 1;}
#line 3071 "C_grammar.tab.c"
    break;

  case 111: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 607 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); 
		}
#line 3079 "C_grammar.tab.c"
    break;

  case 112: /* declaration_specifiers: function_specifier  */
#line 611 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); 
		}
#line 3087 "C_grammar.tab.c"
    break;

  case 113: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 615 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); 
		}
#line 3095 "C_grammar.tab.c"
    break;

  case 114: /* declaration_specifiers: alignment_specifier  */
#line 619 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); 
		}
#line 3103 "C_grammar.tab.c"
    break;

  case 115: /* init_declarator_list: init_declarator  */
#line 626 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 (yyval.id) = (yyvsp[0].id);
		}
#line 3111 "C_grammar.tab.c"
    break;

  case 116: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 630 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3123 "C_grammar.tab.c"
    break;

  case 117: /* init_declarator: declarator '=' initializer  */
#line 641 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));
	  	}
#line 3135 "C_grammar.tab.c"
    break;

  case 118: /* init_declarator: declarator  */
#line 649 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_id(current_scope, (yyvsp[0].declarator_type).ptr_declarator, 1);	//the id as a TYPEDEF_NAME is added to the data structures keeping track of typedef_names and ids shadowing
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3146 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: TYPEDEF  */
#line 659 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3155 "C_grammar.tab.c"
    break;

  case 120: /* storage_class_specifier: EXTERN  */
#line 663 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3161 "C_grammar.tab.c"
    break;

  case 121: /* storage_class_specifier: STATIC  */
#line 664 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3167 "C_grammar.tab.c"
    break;

  case 122: /* storage_class_specifier: THREAD_LOCAL  */
#line 665 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3173 "C_grammar.tab.c"
    break;

  case 123: /* storage_class_specifier: AUTO  */
#line 666 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3179 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: REGISTER  */
#line 667 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3185 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: VOID  */
#line 671 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "void"); }
#line 3191 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: CHAR  */
#line 672 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "char"); }
#line 3197 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: SHORT  */
#line 673 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "short"); }
#line 3203 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: INT  */
#line 674 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int"); }
#line 3209 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: LONG  */
#line 675 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "long"); }
#line 3215 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: FLOAT  */
#line 676 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float"); otherDataTypes = true;}
#line 3221 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: DOUBLE  */
#line 677 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "double"); otherDataTypes = true;}
#line 3227 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: SIGNED  */
#line 678 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3233 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: UNSIGNED  */
#line 679 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3239 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: BOOL  */
#line 680 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "bool"); otherDataTypes = true;}
#line 3245 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: COMPLEX  */
#line 681 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3251 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: IMAGINARY  */
#line 682 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3257 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: atomic_type_specifier  */
#line 683 "C_grammar.y"
                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3263 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: struct_or_union_specifier  */
#line 684 "C_grammar.y"
                                    { in_ordinary_id_declaration = 1; otherDataTypes = true;}
#line 3269 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: enum_specifier  */
#line 685 "C_grammar.y"
                                        { in_ordinary_id_declaration = 1;  otherDataTypes = true;}
#line 3275 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: TYPEDEF_NAME  */
#line 687 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3284 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: INT128  */
#line 691 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int128"); otherDataTypes = true;}
#line 3290 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: FLOAT128  */
#line 692 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float128"); otherDataTypes = true;}
#line 3296 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: VA_LIST  */
#line 693 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "va_list"); otherDataTypes = true;}
#line 3302 "C_grammar.tab.c"
    break;

  case 144: /* $@4: %empty  */
#line 696 "C_grammar.y"
                              {in_tag_declaration = 0;}
#line 3308 "C_grammar.tab.c"
    break;

  case 145: /* struct_or_union_specifier: struct_or_union '{' $@4 struct_declaration_list '}'  */
#line 697 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3319 "C_grammar.tab.c"
    break;

  case 146: /* $@5: %empty  */
#line 703 "C_grammar.y"
                                     {in_tag_declaration = 0;}
#line 3325 "C_grammar.tab.c"
    break;

  case 147: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@5 '{' struct_declaration_list '}'  */
#line 704 "C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3339 "C_grammar.tab.c"
    break;

  case 148: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 714 "C_grammar.y"
                {in_tag_declaration = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3353 "C_grammar.tab.c"
    break;

  case 149: /* struct_or_union: STRUCT  */
#line 727 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_declaration = 1;
		}
#line 3361 "C_grammar.tab.c"
    break;

  case 150: /* struct_or_union: UNION  */
#line 731 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_declaration = 1;
		}
#line 3369 "C_grammar.tab.c"
    break;

  case 152: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 739 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3380 "C_grammar.tab.c"
    break;

  case 153: /* struct_declaration: specifier_qualifier_list ';'  */
#line 749 "C_grammar.y"
                {size_t const size = strlen("anonymous_member()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3390 "C_grammar.tab.c"
    break;

  case 154: /* $@6: %empty  */
#line 755 "C_grammar.y"
                                   {in_member_namespace = 1;}
#line 3396 "C_grammar.tab.c"
    break;

  case 155: /* struct_declaration: specifier_qualifier_list $@6 struct_declarator_list ';'  */
#line 756 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3408 "C_grammar.tab.c"
    break;

  case 157: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 768 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3419 "C_grammar.tab.c"
    break;

  case 159: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 776 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3430 "C_grammar.tab.c"
    break;

  case 161: /* $@7: %empty  */
#line 786 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3436 "C_grammar.tab.c"
    break;

  case 162: /* struct_declarator_list: $@7 struct_declarator  */
#line 786 "C_grammar.y"
                                                       {(yyval.id)= (yyvsp[0].id); in_member_namespace = 1;}
#line 3442 "C_grammar.tab.c"
    break;

  case 163: /* $@8: %empty  */
#line 787 "C_grammar.y"
                                                       {in_member_namespace = 1;}
#line 3448 "C_grammar.tab.c"
    break;

  case 164: /* struct_declarator_list: struct_declarator_list ',' struct_declarator $@8  */
#line 788 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
        }
#line 3459 "C_grammar.tab.c"
    break;

  case 165: /* $@9: %empty  */
#line 797 "C_grammar.y"
          {in_member_namespace = 0;}
#line 3465 "C_grammar.tab.c"
    break;

  case 166: /* struct_declarator: $@9 ':' constant_expression  */
#line 798 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3475 "C_grammar.tab.c"
    break;

  case 167: /* $@10: %empty  */
#line 803 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 3481 "C_grammar.tab.c"
    break;

  case 168: /* struct_declarator: declarator $@10 ':' constant_expression  */
#line 804 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3493 "C_grammar.tab.c"
    break;

  case 169: /* struct_declarator: declarator  */
#line 812 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3502 "C_grammar.tab.c"
    break;

  case 170: /* $@11: %empty  */
#line 819 "C_grammar.y"
               {in_ordinary_id_declaration = 1;}
#line 3508 "C_grammar.tab.c"
    break;

  case 171: /* enum_specifier: ENUM $@11 '{' enumerator_list comma_opt '}'  */
#line 820 "C_grammar.y"
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
#line 3526 "C_grammar.tab.c"
    break;

  case 172: /* $@12: %empty  */
#line 833 "C_grammar.y"
               {in_tag_declaration = 1;}
#line 3532 "C_grammar.tab.c"
    break;

  case 173: /* $@13: %empty  */
#line 833 "C_grammar.y"
                                                    {in_tag_declaration = 0; in_ordinary_id_declaration = 1;}
#line 3538 "C_grammar.tab.c"
    break;

  case 174: /* enum_specifier: ENUM $@12 IDENTIFIER $@13 enum_specifier_rest  */
#line 834 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3550 "C_grammar.tab.c"
    break;

  case 175: /* enum_specifier_rest: %empty  */
#line 845 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3556 "C_grammar.tab.c"
    break;

  case 176: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 847 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3562 "C_grammar.tab.c"
    break;

  case 177: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 849 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3572 "C_grammar.tab.c"
    break;

  case 178: /* enumerator_list: enumerator  */
#line 857 "C_grammar.y"
                     {in_ordinary_id_declaration = 1;}
#line 3578 "C_grammar.tab.c"
    break;

  case 179: /* enumerator_list: enumerator_list ',' enumerator  */
#line 859 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3590 "C_grammar.tab.c"
    break;

  case 180: /* $@14: %empty  */
#line 869 "C_grammar.y"
                               {in_ordinary_id_declaration = 0;}
#line 3596 "C_grammar.tab.c"
    break;

  case 181: /* enumerator: enumeration_constant $@14 '=' constant_expression  */
#line 870 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[0].id));
        }
#line 3607 "C_grammar.tab.c"
    break;

  case 184: /* type_qualifier: CONST  */
#line 884 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3613 "C_grammar.tab.c"
    break;

  case 185: /* type_qualifier: RESTRICT  */
#line 885 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3619 "C_grammar.tab.c"
    break;

  case 186: /* type_qualifier: VOLATILE  */
#line 886 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3625 "C_grammar.tab.c"
    break;

  case 187: /* type_qualifier: ATOMIC  */
#line 887 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3631 "C_grammar.tab.c"
    break;

  case 188: /* function_specifier: INLINE  */
#line 891 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3637 "C_grammar.tab.c"
    break;

  case 189: /* function_specifier: NORETURN  */
#line 892 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3643 "C_grammar.tab.c"
    break;

  case 192: /* declarator: pointer direct_declarator  */
#line 903 "C_grammar.y"
          {in_ordinary_id_declaration = 0;
	   size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3656 "C_grammar.tab.c"
    break;

  case 193: /* declarator: direct_declarator  */
#line 911 "C_grammar.y"
                            {in_ordinary_id_declaration = 0;}
#line 3662 "C_grammar.tab.c"
    break;

  case 194: /* direct_declarator: IDENTIFIER  */
#line 916 "C_grammar.y"
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
#line 3689 "C_grammar.tab.c"
    break;

  case 195: /* direct_declarator: '(' declarator ')'  */
#line 940 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-1].declarator_type);}
#line 3695 "C_grammar.tab.c"
    break;

  case 196: /* direct_declarator: direct_declarator '[' ']'  */
#line 942 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3706 "C_grammar.tab.c"
    break;

  case 197: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 949 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3715 "C_grammar.tab.c"
    break;

  case 198: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 954 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3724 "C_grammar.tab.c"
    break;

  case 199: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 959 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3733 "C_grammar.tab.c"
    break;

  case 200: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 964 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3742 "C_grammar.tab.c"
    break;

  case 201: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 969 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3751 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 974 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3760 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 979 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3769 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 984 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3781 "C_grammar.tab.c"
    break;

  case 205: /* $@15: %empty  */
#line 991 "C_grammar.y"
                            {in_ordinary_id_declaration = 0; if (!typedef_flag) current_scope++; }
#line 3787 "C_grammar.tab.c"
    break;

  case 206: /* direct_declarator: direct_declarator $@15 '(' rest_function_definition ')'  */
#line 992 "C_grammar.y"
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
#line 3802 "C_grammar.tab.c"
    break;

  case 207: /* rest_function_definition: %empty  */
#line 1005 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 3808 "C_grammar.tab.c"
    break;

  case 209: /* rest_function_definition: old_style_parameter_list  */
#line 1007 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 3814 "C_grammar.tab.c"
    break;

  case 210: /* pointer: '*' type_qualifier_list pointer  */
#line 1012 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3825 "C_grammar.tab.c"
    break;

  case 211: /* pointer: '*' type_qualifier_list  */
#line 1019 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3835 "C_grammar.tab.c"
    break;

  case 212: /* pointer: '*' pointer  */
#line 1025 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3845 "C_grammar.tab.c"
    break;

  case 213: /* pointer: '*'  */
#line 1031 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3851 "C_grammar.tab.c"
    break;

  case 215: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1037 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3862 "C_grammar.tab.c"
    break;

  case 216: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1047 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3872 "C_grammar.tab.c"
    break;

  case 217: /* parameter_type_list: parameter_list  */
#line 1053 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3882 "C_grammar.tab.c"
    break;

  case 219: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1063 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3893 "C_grammar.tab.c"
    break;

  case 220: /* parameter_declaration: declaration_specifiers declarator  */
#line 1073 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3905 "C_grammar.tab.c"
    break;

  case 221: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1081 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3916 "C_grammar.tab.c"
    break;

  case 222: /* parameter_declaration: declaration_specifiers  */
#line 1088 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3926 "C_grammar.tab.c"
    break;

  case 225: /* type_name: specifier_qualifier_list abstract_declarator_opt  */
#line 1102 "C_grammar.y"
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
#line 3941 "C_grammar.tab.c"
    break;

  case 226: /* abstract_declarator_opt: %empty  */
#line 1115 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 3947 "C_grammar.tab.c"
    break;

  case 227: /* abstract_declarator_opt: abstract_declarator  */
#line 1116 "C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 3953 "C_grammar.tab.c"
    break;

  case 252: /* initializer: '{' initializer_list '}'  */
#line 1151 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3963 "C_grammar.tab.c"
    break;

  case 253: /* initializer: '{' initializer_list ',' '}'  */
#line 1157 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3973 "C_grammar.tab.c"
    break;

  case 255: /* initializer: '{' '}'  */
#line 1164 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 3979 "C_grammar.tab.c"
    break;

  case 256: /* initializer_list: designation initializer  */
#line 1169 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3990 "C_grammar.tab.c"
    break;

  case 258: /* initializer_list: initializer_list ',' designation initializer  */
#line 1177 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4002 "C_grammar.tab.c"
    break;

  case 259: /* initializer_list: initializer_list ',' initializer  */
#line 1185 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4013 "C_grammar.tab.c"
    break;

  case 260: /* designation: designator_list '='  */
#line 1195 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4023 "C_grammar.tab.c"
    break;

  case 262: /* designator_list: designator_list designator  */
#line 1205 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4034 "C_grammar.tab.c"
    break;

  case 263: /* designator: '[' constant_expression ']'  */
#line 1215 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4044 "C_grammar.tab.c"
    break;

  case 264: /* $@16: %empty  */
#line 1220 "C_grammar.y"
          {in_member_namespace = 1;}
#line 4050 "C_grammar.tab.c"
    break;

  case 265: /* designator: $@16 '.' IDENTIFIER  */
#line 1221 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4061 "C_grammar.tab.c"
    break;

  case 266: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1231 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4072 "C_grammar.tab.c"
    break;

  case 268: /* $@17: %empty  */
#line 1241 "C_grammar.y"
          {in_ordinary_id_declaration = 0; current_scope++;}
#line 4078 "C_grammar.tab.c"
    break;

  case 269: /* statement: $@17 compound_statement  */
#line 1242 "C_grammar.y"
                {pop_scope(&current_scope);
		 (yyval.id) = (yyvsp[0].id);
		}
#line 4086 "C_grammar.tab.c"
    break;

  case 274: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1253 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4097 "C_grammar.tab.c"
    break;

  case 275: /* labeled_statement: TYPEDEF_NAME ':' statement  */
#line 1261 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4108 "C_grammar.tab.c"
    break;

  case 276: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1268 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4119 "C_grammar.tab.c"
    break;

  case 277: /* labeled_statement: DEFAULT ':' statement  */
#line 1275 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4129 "C_grammar.tab.c"
    break;

  case 278: /* compound_statement: '{' '}'  */
#line 1283 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4135 "C_grammar.tab.c"
    break;

  case 279: /* compound_statement: '{' block_item_list '}'  */
#line 1285 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4145 "C_grammar.tab.c"
    break;

  case 280: /* block_item_list: block_item  */
#line 1293 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 4151 "C_grammar.tab.c"
    break;

  case 281: /* $@18: %empty  */
#line 1294 "C_grammar.y"
                                     {in_ordinary_id_declaration = 0;}
#line 4157 "C_grammar.tab.c"
    break;

  case 282: /* block_item_list: block_item_list block_item $@18  */
#line 1295 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	  }
#line 4168 "C_grammar.tab.c"
    break;

  case 285: /* expression_statement: ';'  */
#line 1309 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4174 "C_grammar.tab.c"
    break;

  case 286: /* expression_statement: expression ';'  */
#line 1311 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4184 "C_grammar.tab.c"
    break;

  case 287: /* selection_statement: IF '(' expression ')' statement else_opt  */
#line 1320 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4196 "C_grammar.tab.c"
    break;

  case 288: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1328 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4207 "C_grammar.tab.c"
    break;

  case 289: /* else_opt: %empty  */
#line 1337 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4213 "C_grammar.tab.c"
    break;

  case 290: /* else_opt: ELSE statement  */
#line 1339 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4223 "C_grammar.tab.c"
    break;

  case 291: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1347 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4234 "C_grammar.tab.c"
    break;

  case 292: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1354 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4245 "C_grammar.tab.c"
    break;

  case 293: /* iteration_statement: FOR '(' for_stmt_type ')' statement  */
#line 1361 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4258 "C_grammar.tab.c"
    break;

  case 294: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1373 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4264 "C_grammar.tab.c"
    break;

  case 295: /* for_stmt_type: declaration expression_opt ';' expression_opt  */
#line 1375 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4270 "C_grammar.tab.c"
    break;

  case 296: /* expression_opt: %empty  */
#line 1379 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4276 "C_grammar.tab.c"
    break;

  case 298: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1384 "C_grammar.y"
          {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4287 "C_grammar.tab.c"
    break;

  case 299: /* jump_statement: CONTINUE ';'  */
#line 1390 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4293 "C_grammar.tab.c"
    break;

  case 300: /* jump_statement: BREAK ';'  */
#line 1391 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4299 "C_grammar.tab.c"
    break;

  case 301: /* jump_statement: RETURN ';'  */
#line 1392 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4305 "C_grammar.tab.c"
    break;

  case 302: /* jump_statement: RETURN expression ';'  */
#line 1394 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4315 "C_grammar.tab.c"
    break;

  case 304: /* $@19: %empty  */
#line 1404 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4321 "C_grammar.tab.c"
    break;

  case 306: /* external_declaration: function_definition  */
#line 1409 "C_grammar.y"
                {handled_function_paramaters = 0;
		 pop_scope(&current_scope);
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4331 "C_grammar.tab.c"
    break;

  case 307: /* external_declaration: declaration  */
#line 1415 "C_grammar.y"
                {if (handled_function_paramaters == 666) handled_function_paramaters = 0; 
		else if(handled_function_paramaters) {
			handled_function_paramaters = 0;
			pop_scope(&current_scope);
		 }
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4344 "C_grammar.tab.c"
    break;

  case 308: /* $@20: %empty  */
#line 1426 "C_grammar.y"
                                                                 {in_ordinary_id_declaration = 0;}
#line 4350 "C_grammar.tab.c"
    break;

  case 309: /* function_definition: declaration_specifiers declarator declaration_list_opt $@20 compound_statement  */
#line 1427 "C_grammar.y"
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
#line 4365 "C_grammar.tab.c"
    break;

  case 310: /* declaration_list_opt: %empty  */
#line 1440 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4371 "C_grammar.tab.c"
    break;

  case 313: /* old_style_declaration_list: old_style_declaration_list declaration  */
#line 1447 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4382 "C_grammar.tab.c"
    break;


#line 4386 "C_grammar.tab.c"

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

#line 1455 "C_grammar.y"

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

void process_declaration_specifiers(char a[]) {
    char *token;
    SpecifierFlags flags = {false};
    flags.isSigned = true;

    // Allocate temp with enough space
    char *temp = (char *)malloc(sizeof(char) * (strlen(a) + 1));
    if (!temp) {
        perror("Memory allocation failed");
        return;
    }
    strcpy(temp, a);

    char result[1024] = ""; 
    token = strtok(temp, ", ");
    while (token != NULL) {
        if (strcmp(token, "int") == 0) { printf("TOKEN:	%s \n", token); }
        else if (strcmp(token, "long") == 0) { flags.longCount++; }
        else if (strcmp(token, "short") == 0) { flags.isShort = true; }
        else if (strcmp(token, "unsigned") == 0) { flags.isSigned = false; }
        else if (strcmp(token, "const") == 0) { flags.isConstant = true; }
        else if (strcmp(token, "static") == 0) { flags.isStatic = true; }
        else if (strcmp(token, "extern") == 0) { flags.isExtern = true; }
        else if (strcmp(token, "typedef") == 0) { flags.isTypeDef = true; }
        else if (strcmp(token, "volatile") == 0) { flags.isVolatile = true; }
        else if (strcmp(token, "atomic") == 0) { flags.isAtomic = true; }

        token = strtok(NULL, ", ");
    }
    if (flags.isTypeDef) strcat(result, "typedef, ");
    if (flags.isExtern) strcat(result, "extern, ");
    if (flags.isConstant) strcat(result, "const, ");
    if (flags.isStatic) strcat(result, "static, ");
    if (flags.isVolatile) strcat(result, "volatile, ");
    if (flags.isAtomic) strcat(result, "atomic, ");

    if (flags.isSigned) {
        if (flags.longCount == 1) strcat(result, "long");
        else if (flags.longCount == 2) strcat(result, "long, long");
        else if (flags.isShort) strcat(result, "short");
        else strcat(result, "int");
    } else {
        if (flags.longCount == 1) strcat(result, "unsigned, long");
        else if (flags.longCount == 2) strcat(result, "unsigned, long, long");
        else if (flags.isShort) strcat(result, "unsigned, short");
        else strcat(result, "unsigned, int");
    }
	otherDataTypes = false;
    strncpy(a, result, strlen(result) + 1);
    free(temp);
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
  }
  if (exit_code == EXIT_SUCCESS) fprintf(stderr, "Sikraken parsing SUCCESS, wrote %s\n", pl_file_uri);
  exit(exit_code);
}

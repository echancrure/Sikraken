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
#include <stdbool.h>
#include <ctype.h>
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
int in_tag_namespace = 0;		//indicates to the lexer that we are in the tag namespace (for struct, union and enum tags) and that identifier should not be checked for typedef
int in_member_namespace = 0;	//indicates to the lexer that we are in the member namespace (for members of stuct and unions) and that identifier should not be checked for typedef

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements
void process_declaration_specifiers(char a[]); //Processes declaration specifiers to generalize them for Sikraken i.e signed long int -> long.
void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 143 "C_grammar.tab.c"

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
  YYSYMBOL_constant = 107,                 /* constant  */
  YYSYMBOL_enumeration_constant = 108,     /* enumeration_constant  */
  YYSYMBOL_string = 109,                   /* string  */
  YYSYMBOL_generic_selection = 110,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 111,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 112,      /* generic_association  */
  YYSYMBOL_postfix_expression = 113,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 114, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 115,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 116,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 117,           /* unary_operator  */
  YYSYMBOL_cast_expression = 118,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 119, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 120, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 121,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 122,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 123,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 124,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 125,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 126, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 127,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 128,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 129,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 130,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 131,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 132,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 133,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 134,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 135,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 136,      /* assignment_operator  */
  YYSYMBOL_expression = 137,               /* expression  */
  YYSYMBOL_constant_expression = 138,      /* constant_expression  */
  YYSYMBOL_declaration = 139,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 140,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 141,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 142,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 143,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 144,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 145, /* struct_or_union_specifier  */
  YYSYMBOL_146_1 = 146,                    /* $@1  */
  YYSYMBOL_147_2 = 147,                    /* $@2  */
  YYSYMBOL_struct_or_union = 148,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 149,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 150,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 151, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 152,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 153,        /* struct_declarator  */
  YYSYMBOL_154_3 = 154,                    /* $@3  */
  YYSYMBOL_struct_declarator2 = 155,       /* struct_declarator2  */
  YYSYMBOL_156_4 = 156,                    /* $@4  */
  YYSYMBOL_157_5 = 157,                    /* $@5  */
  YYSYMBOL_158_6 = 158,                    /* $@6  */
  YYSYMBOL_enum_specifier = 159,           /* enum_specifier  */
  YYSYMBOL_160_7 = 160,                    /* $@7  */
  YYSYMBOL_161_8 = 161,                    /* $@8  */
  YYSYMBOL_enum_specifier_rest = 162,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 163,          /* enumerator_list  */
  YYSYMBOL_enumerator = 164,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 165,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 166,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 167,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 168,      /* alignment_specifier  */
  YYSYMBOL_declarator = 169,               /* declarator  */
  YYSYMBOL_direct_declarator = 170,        /* direct_declarator  */
  YYSYMBOL_171_9 = 171,                    /* $@9  */
  YYSYMBOL_pointer = 172,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 173,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 174,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 175,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 176,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 177,          /* identifier_list  */
  YYSYMBOL_type_name = 178,                /* type_name  */
  YYSYMBOL_abstract_declarator = 179,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 180, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 181,              /* initializer  */
  YYSYMBOL_initializer_list = 182,         /* initializer_list  */
  YYSYMBOL_designation = 183,              /* designation  */
  YYSYMBOL_designator_list = 184,          /* designator_list  */
  YYSYMBOL_designator = 185,               /* designator  */
  YYSYMBOL_static_assert_declaration = 186, /* static_assert_declaration  */
  YYSYMBOL_statement = 187,                /* statement  */
  YYSYMBOL_labeled_statement = 188,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 189,       /* compound_statement  */
  YYSYMBOL_block_item_list = 190,          /* block_item_list  */
  YYSYMBOL_block_item = 191,               /* block_item  */
  YYSYMBOL_expression_statement = 192,     /* expression_statement  */
  YYSYMBOL_selection_statement = 193,      /* selection_statement  */
  YYSYMBOL_else_opt = 194,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 195,      /* iteration_statement  */
  YYSYMBOL_for_stmt_type = 196,            /* for_stmt_type  */
  YYSYMBOL_expression_opt = 197,           /* expression_opt  */
  YYSYMBOL_jump_statement = 198,           /* jump_statement  */
  YYSYMBOL_translation_unit = 199,         /* translation_unit  */
  YYSYMBOL_200_10 = 200,                   /* $@10  */
  YYSYMBOL_external_declaration = 201,     /* external_declaration  */
  YYSYMBOL_function_definition = 202,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 203,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 204          /* declaration_list  */
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
#define YYLAST   2502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  301
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  493

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
       0,   141,   141,   145,   146,   147,   153,   159,   163,   164,
     165,   169,   173,   174,   178,   182,   183,   187,   188,   192,
     193,   200,   206,   213,   220,   227,   233,   239,   246,   256,
     257,   267,   268,   275,   282,   288,   294,   303,   304,   308,
     309,   310,   311,   312,   313,   317,   318,   328,   329,   340,
     341,   342,   346,   347,   358,   359,   363,   364,   375,   376,
     380,   381,   392,   393,   394,   395,   400,   401,   412,   413,
     417,   418,   428,   429,   439,   440,   450,   451,   461,   462,
     472,   473,   484,   485,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   510,   511,   521,   525,   531,
     554,   563,   570,   571,   578,   579,   586,   587,   589,   591,
     593,   598,   599,   609,   617,   627,   632,   633,   634,   635,
     636,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   659,   660,   661,
     665,   665,   672,   672,   682,   695,   699,   706,   707,   717,
     724,   732,   736,   743,   744,   751,   755,   756,   766,   766,
     770,   770,   776,   776,   784,   784,   792,   798,   804,   804,
     804,   815,   816,   818,   827,   828,   838,   845,   849,   853,
     854,   855,   856,   860,   861,   865,   866,   870,   878,   882,
     906,   906,   909,   916,   921,   926,   931,   936,   941,   946,
     951,   959,   967,   976,   984,   991,   997,  1003,  1008,  1009,
    1019,  1025,  1034,  1035,  1045,  1053,  1060,  1069,  1070,  1074,
    1075,  1084,  1085,  1086,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1114,  1120,  1126,  1127,  1132,
    1139,  1140,  1148,  1158,  1167,  1168,  1178,  1184,  1193,  1203,
    1204,  1205,  1206,  1207,  1208,  1212,  1219,  1226,  1235,  1236,
    1245,  1246,  1256,  1257,  1261,  1262,  1271,  1279,  1289,  1290,
    1298,  1305,  1312,  1324,  1326,  1331,  1332,  1335,  1341,  1342,
    1343,  1344,  1354,  1355,  1355,  1359,  1360,  1364,  1378,  1379,
    1383,  1384
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
  "primary_expression", "constant", "enumeration_constant", "string",
  "generic_selection", "generic_assoc_list", "generic_association",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_inc_dec", "unary_operator", "cast_expression",
  "multiplicative_expression", "multiplicative_expression_op",
  "additive_expression", "additive_expression_op", "shift_expression",
  "shift_expression_op", "relational_expression",
  "relational_expression_operator", "equality_expression",
  "equality_expression_op", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "$@1", "$@2",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "$@3", "struct_declarator2", "$@4", "$@5", "$@6",
  "enum_specifier", "$@7", "$@8", "enum_specifier_rest", "enumerator_list",
  "enumerator", "atomic_type_specifier", "type_qualifier",
  "function_specifier", "alignment_specifier", "declarator",
  "direct_declarator", "$@9", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "else_opt",
  "iteration_statement", "for_stmt_type", "expression_opt",
  "jump_statement", "translation_unit", "$@10", "external_declaration",
  "function_definition", "declaration_list_opt", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-357)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-299)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2162,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,   -54,   -33,  2423,  -357,  -357,
      44,  -357,  -357,  -357,  -357,  -357,    57,  2267,  2267,  -357,
      43,  -357,  -357,  2267,  2267,  2267,  -357,    36,  -357,  -357,
      98,   134,  1004,  2423,    -8,  2423,    62,  1721,  -357,    38,
     139,  -357,   -52,  -357,   834,     9,    54,  -357,  -357,    58,
    -357,  -357,  -357,  -357,  -357,  2162,  -357,    55,   -45,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  1736,  -357,  -357,
     101,   109,   911,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,   157,  -357,  1829,  1721,  -357,    95,   -12,
     200,    34,   199,   103,   106,   122,   212,     2,  -357,   152,
     155,  -357,  1894,  1097,   115,  -357,   131,  -357,  -357,   160,
    -357,  -357,  -357,   139,    38,  -357,  1597,  -357,    57,   161,
    2162,  2058,  1112,     9,   187,  2319,  -357,  1721,    19,  -357,
     190,   911,  -357,  2423,  1721,   555,   232,  -357,  -357,   137,
     170,   201,   279,  -357,  -357,  1690,  1721,   282,   911,  -357,
    -357,  -357,  -357,  -357,  1721,  -357,  -357,  1721,  -357,  -357,
    1721,  -357,  -357,  -357,  -357,  1721,  -357,  -357,  1721,  1721,
    1721,  1721,  1721,  1721,  1721,  -357,  -357,  -357,    75,   205,
     208,  -357,   211,  1421,  -357,   209,   213,  1205,   131,  2110,
    1220,   286,   215,  -357,  -357,  -357,   197,  1436,  -357,  -357,
    -357,  -357,  -357,  -357,   219,   146,  1421,  -357,   217,   218,
    1313,  2319,  1948,  -357,   203,  -357,  -357,  -357,  -357,    98,
    -357,   223,   226,   229,   230,  1721,   231,   236,   238,   242,
     442,   243,   324,   227,   233,   756,  -357,  -357,   -30,  -357,
    -357,  -357,  -357,   648,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    1721,  -357,  1721,  1705,  -357,  -357,  -357,   164,  -357,     6,
    -357,   251,  -357,    95,   -12,   200,    34,   199,   103,   106,
     122,   212,   156,  1815,  -357,    32,  -357,  -357,  2214,  -357,
     250,  1421,  -357,  -357,  1721,  -357,   252,  -357,   257,  1421,
    -357,   254,   255,  1328,   261,  -357,  1721,   341,  -357,  -357,
     -44,  1597,   -21,  -357,  -357,  -357,   342,   260,  1421,  -357,
    -357,  1721,  -357,   264,   265,  2000,  -357,  -357,  -357,   -29,
    -357,    81,   -13,   259,  -357,  2371,   442,   268,   442,  1721,
    1721,  1721,   291,   741,   253,  -357,  -357,  -357,   -25,  -357,
    -357,  -357,  -357,  -357,  1581,  -357,  -357,  1721,  -357,   259,
    1721,  -357,  -357,  -357,   269,   270,  -357,  -357,   272,  1421,
    -357,  -357,  1721,  -357,   273,   256,   275,  -357,  1462,  -357,
    -357,  -357,  -357,  -357,  -357,   277,   278,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,   281,    21,  -357,   283,   184,  -357,
     284,  -357,   442,  -357,   186,   189,   191,   285,  1721,  1721,
     287,  -357,  -357,    74,  -357,  -357,  -357,  -357,  -357,   288,
     289,  -357,  -357,  -357,  -357,  -357,  1597,  -357,  -357,  -357,
    1721,   292,  -357,  -357,  1721,  -357,  2371,  1721,  -357,   442,
     442,   442,  1721,   271,   266,   267,   442,  1555,  -357,  -357,
    -357,  -357,  -357,  1721,  -357,  -357,  -357,   312,  -357,  -357,
     207,  1721,  1721,  -357,  -357,  -357,   442,  -357,   274,  -357,
    -357,  -357,  -357
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   136,   115,   116,   117,   119,   120,   183,   179,   180,
     181,   130,   122,   123,   124,   125,   128,   129,   126,   127,
     121,   131,   132,   145,   146,   168,     0,     0,   182,   184,
       0,   118,   137,   138,   139,   296,     0,   102,   104,   134,
       0,   135,   133,   106,   108,   110,   100,   293,   292,   295,
       0,     0,     0,   153,   220,   155,     0,     0,   189,     0,
     207,    98,     0,   111,   114,   188,     0,   101,   103,   144,
     140,   105,   107,   109,     1,     0,    11,   177,     0,   174,
     169,     2,     8,     9,    10,    12,    13,     0,    37,    38,
       0,     0,     0,    39,    40,    41,    42,    43,    44,    19,
       3,     4,     7,    31,    45,     0,     0,    47,    52,    56,
      60,    66,    70,    72,    74,    76,    78,    80,    97,     0,
       0,   152,     0,     0,   222,   219,   223,   154,   178,     0,
     190,   208,   206,   205,     0,    99,     0,   300,     0,     0,
     299,     0,     0,   187,     0,     0,   294,     0,     0,   166,
     171,     0,    34,     0,     0,     0,    45,    82,    95,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    32,
      33,    49,    50,    51,     0,    54,    55,     0,    58,    59,
       0,    64,    65,    62,    63,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,   186,   185,   241,   216,     0,
     211,   212,     0,     0,   225,    40,     0,     0,   221,     0,
       0,     0,     0,   209,   204,   112,   114,     0,   247,   113,
     297,   301,   217,   201,     0,     0,     0,   192,    40,     0,
       0,     0,     0,   147,   158,   151,   176,   167,   175,     0,
     170,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   274,     0,   272,
     273,   259,   260,     0,   270,   261,   262,   263,   264,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    84,
       0,     6,     0,     0,     5,    24,    21,     0,    29,     0,
      23,     0,    48,    53,    57,    61,    67,    71,    73,    75,
      77,    79,     0,     0,   214,   222,   215,   242,     0,   224,
       0,     0,   226,   232,     0,   231,     0,   243,     0,     0,
     233,    40,     0,     0,     0,   191,     0,     0,   248,   250,
       0,     0,     0,   254,   202,   203,     0,     0,     0,   193,
     200,     0,   199,    40,     0,     0,   141,   148,   149,     0,
     156,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   288,   289,   290,     0,   275,
     269,   271,    83,    96,     0,    46,    22,     0,    20,     0,
       0,   210,   213,   228,     0,     0,   230,   244,     0,     0,
     234,   240,     0,   239,     0,     0,     0,   257,     0,   245,
     249,   253,   255,   218,   195,     0,     0,   196,   198,   143,
     158,   150,   160,   159,   164,     0,   172,     0,     0,    15,
       0,   265,     0,   267,     0,     0,     0,     0,   285,   285,
       0,   287,   291,     0,    30,    81,   227,   229,   236,     0,
       0,   237,   258,   256,   246,   252,     0,   194,   197,   157,
       0,     0,   165,   173,     0,    14,     0,     0,   266,     0,
       0,     0,     0,   286,     0,     0,     0,     0,    27,   235,
     238,   251,   161,     0,    18,    16,    17,   278,   277,   280,
       0,   285,   285,   282,    28,   163,     0,   276,     0,   284,
     283,   279,   281
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -357,  -357,  -357,  -357,  -357,  -357,  -357,   -79,  -357,  -357,
     -38,  -357,  -357,   -89,   196,  -357,   204,  -357,   195,  -357,
     198,  -357,   194,  -357,   202,   206,   193,   210,  -357,   -50,
      99,  -357,   -80,   -56,   -53,    18,  -357,   262,  -357,   -23,
    -357,  -357,  -357,  -357,   158,  -211,   -47,  -357,   -22,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,   148,  -138,
    -357,   -27,  -357,  -357,   -31,   -57,  -357,   -17,   -83,  -114,
    -357,    83,  -357,    20,   -34,  -108,  -133,    16,  -356,  -357,
      61,  -132,  -235,  -357,    82,  -357,   132,    35,  -357,  -357,
    -357,  -357,  -280,  -357,  -357,  -357,   329,  -357,  -357,  -357
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    99,   100,    77,   101,   102,   418,   419,   103,   287,
     156,   105,   106,   107,   108,   174,   109,   177,   110,   180,
     111,   185,   112,   188,   113,   114,   115,   116,   117,   157,
     158,   280,   258,   119,    35,   138,    62,    63,    37,    38,
      39,   145,   144,    40,   232,   233,    54,   349,   350,   351,
     413,   450,   451,   452,    41,    51,   150,   240,    78,    79,
      42,    43,    44,    45,   130,    65,   212,    66,   133,   199,
     200,   201,   225,   420,   202,   126,   329,   330,   331,   332,
     333,    46,   260,   261,   262,   263,   264,   265,   266,   487,
     267,   430,   464,   268,    47,    75,    48,    49,   139,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   129,   118,   219,    53,    64,   121,   118,   127,   143,
     238,   137,   159,   235,   104,   362,   208,   170,    36,   104,
     125,   347,    76,   193,    76,    55,    55,   224,    55,    53,
      53,   134,    53,   131,    50,    58,    74,   124,   148,   398,
     207,    58,   446,   132,   149,   399,    69,    56,    52,   152,
     181,   182,   135,   282,   410,    67,    68,    58,   282,   230,
      58,    71,    72,    73,   326,    55,   327,   169,   104,    53,
     415,   159,   120,   122,   369,   411,   416,   123,    58,   432,
     175,   176,   401,    60,    58,   292,   289,   221,   159,   282,
     141,   236,   378,    36,   142,   318,   131,   118,   234,   235,
     235,    76,   259,   216,   194,   124,   213,   216,   237,   104,
     453,   446,   160,   303,   302,   131,   214,   123,    55,    59,
     311,   421,    53,   423,    55,    57,    55,   323,    53,    60,
      53,    70,   183,   184,   347,    59,   104,    80,    59,   104,
     198,    55,   104,   338,   128,    53,  -142,   104,    60,   465,
     104,   104,   104,   104,   104,   104,   303,   467,   147,   198,
     123,    61,    59,   468,   306,   412,    60,   304,   162,   163,
     164,   241,    60,   242,   161,   368,   131,     8,     9,    10,
     213,   305,   153,   131,   234,   234,   171,   458,   291,   357,
     154,   172,   173,   189,   375,   118,   122,   208,   400,   131,
     123,   489,   490,   213,    55,    55,   190,   104,    53,    53,
     259,    28,   209,   235,   178,   179,   210,   186,   187,   281,
     282,   220,   206,   191,   477,   478,   479,   198,   335,   336,
      60,   483,   192,   161,   195,   218,   389,   196,   165,   282,
     380,   229,   166,   211,   167,   104,   376,   377,   143,   155,
     161,   491,   283,   243,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   288,   445,   455,   456,   459,   282,
     396,   460,   282,   461,   282,   231,   118,   238,   239,   424,
     425,   426,   285,   284,   213,   290,   305,   307,   104,   488,
     282,   308,   131,   309,   324,   312,   213,   325,   234,   313,
     136,   334,   310,   339,   340,   353,   316,   348,   354,   322,
     428,   213,   355,   471,   356,   358,   218,   359,    55,   360,
     414,   198,    53,   361,   363,   337,   198,   364,    55,   344,
     435,   365,    53,   379,   445,   279,   383,   366,   386,   387,
     390,   391,   104,   395,   397,   403,   404,   374,   463,   463,
     407,   408,   422,   427,   282,   436,   437,   431,   438,   441,
     442,   443,   213,   447,   448,  -162,   462,   454,   457,   466,
     481,   482,   486,   293,   469,   470,   473,   475,   492,   372,
     295,   373,   480,   297,   294,   300,   296,   352,   449,   345,
     433,   382,   298,   402,   472,   371,   215,   299,   429,     0,
     118,   463,   463,   301,   146,     0,     0,     0,     0,     0,
     384,     0,   104,   385,     0,     0,     0,   485,   388,     0,
       0,     0,   394,   118,     0,     0,     0,     0,     0,    55,
     218,     0,     0,    53,     0,   104,     0,   405,     0,     0,
     406,     0,     0,     0,     0,   244,     0,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   439,     0,
       0,   440,     0,     0,     0,     0,     0,   218,     0,   245,
     246,   247,     0,   248,   249,   250,   251,   252,   253,   254,
     255,     0,    90,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
     155,     0,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,   218,   257,     0,     0,     0,
       0,     0,     0,   474,     0,     0,   476,     0,   244,     1,
      82,    83,    84,    85,    86,    87,   218,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,   245,   246,   247,     0,   248,   249,   250,   251,
     252,   253,   254,   255,    26,    90,    27,    28,    91,    29,
      30,    31,    32,    33,    34,     0,    92,     0,     0,     0,
       0,     0,     0,   155,   256,    93,    94,    95,    96,    97,
      98,   244,     1,    82,    83,    84,    85,    86,    87,   257,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,   245,   246,   247,     0,   248,
     249,   250,   251,   252,   253,   254,   255,    26,    90,    27,
      28,    91,    29,    30,    31,    32,    33,    34,     0,    92,
       0,     0,     0,     0,     0,     0,   155,   370,    93,    94,
      95,    96,    97,    98,    81,     1,    82,    83,    84,    85,
      86,    87,   257,    88,    89,     0,     0,     0,     0,    81,
       0,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    90,    27,    28,    91,    29,    30,    31,    32,    33,
      34,     0,    92,     0,     0,     0,    90,     0,     0,    91,
       0,    93,    94,    95,    96,    97,    98,    92,     1,     0,
       0,     0,     0,     0,     0,   257,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,    30,
      31,    32,    33,    34,    81,     1,    82,    83,    84,    85,
      86,    87,  -298,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    27,    28,    91,     0,     0,     0,    32,    33,
      34,     0,    92,     0,     0,     0,     0,     0,     0,   155,
       0,    93,    94,    95,    96,    97,    98,    81,     1,    82,
      83,    84,    85,    86,    87,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    27,    28,    91,     0,     0,
       0,    32,    33,    34,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      81,     0,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,    81,     0,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,   203,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,    28,
      91,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,     0,    90,   204,    28,    91,     0,    93,   205,    95,
      96,    97,    98,    92,     0,     0,     0,     0,   227,     0,
       0,     0,    93,   228,    95,    96,    97,    98,    81,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,    81,     0,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,     0,   314,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,   319,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,    28,    91,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
      90,   315,    28,    91,     0,    93,    94,    95,    96,    97,
      98,    92,     0,     0,     0,     0,   320,     0,     0,     0,
      93,   321,    95,    96,    97,    98,    81,     0,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,    81,     0,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,   341,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,   392,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,    28,    91,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,    90,   342,
      28,    91,     0,    93,   343,    95,    96,    97,    98,    92,
       0,     0,     0,     0,   393,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    81,     0,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,    81,
       0,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,     0,     0,     0,    81,     0,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,    28,    91,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,    90,     0,     0,    91,
       0,    93,    94,    95,    96,    97,    98,    92,     0,     0,
       0,   326,     0,   327,   217,   328,    93,    94,    95,    96,
      97,    98,    90,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,   326,     0,   327,
     217,   444,    93,    94,    95,    96,    97,    98,    81,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
      81,     0,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
     326,     0,   327,   217,   484,    93,    94,    95,    96,    97,
      98,    90,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,   326,    90,   327,   217,
      91,    93,    94,    95,    96,    97,    98,     0,    92,     0,
       0,     0,     0,     0,     0,   217,     0,    93,    94,    95,
      96,    97,    98,    81,     0,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,    81,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,    81,     0,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,    81,
       0,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,    92,   286,     0,     0,    90,     0,     0,    91,     0,
      93,    94,    95,    96,    97,    98,    92,     0,     0,     0,
       0,    90,     0,   374,    91,    93,    94,    95,    96,    97,
      98,     0,    92,     0,     0,     0,    90,     0,     0,    91,
       0,    93,    94,    95,    96,    97,    98,   151,    58,     1,
       0,     0,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,    81,     0,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,    32,    33,    34,     0,   303,   197,     1,    90,
     123,     0,    91,     0,     0,     0,    60,     0,     0,     0,
     168,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,    32,    33,    34,     0,   122,   197,     0,     0,   123,
       0,     0,     0,     0,     0,    60,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,    30,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   346,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,   222,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,    30,     0,    32,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   409,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,    29,     0,    31,    32,    33,    34,     0,     0,
     223,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,     0,    31,    32,    33,    34,
       0,     0,   317,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,    30,    31,    32,
      33,    34,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     381,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,    32,    33,    34,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,    28,
       0,    29,     0,    31,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,    30,     0,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,    32,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      32,    33,    34
};

static const yytype_int16 yycheck[] =
{
      27,    57,    52,   136,    27,    36,    53,    57,    55,    66,
     148,    64,    92,   145,    52,   250,   124,   106,     0,    57,
      54,   232,     3,    21,     3,    52,    53,   141,    55,    52,
      53,    83,    55,    60,    88,     3,     0,    54,    83,    83,
     123,     3,   398,    60,    89,    89,     3,    27,    81,    87,
      16,    17,   104,    83,    83,    37,    38,     3,    83,   142,
       3,    43,    44,    45,    85,    92,    87,   105,   106,    92,
      83,   151,    52,    81,   104,   104,    89,    85,     3,   104,
      92,    93,   103,    91,     3,   174,   166,   140,   168,    83,
      81,   147,    86,    75,    85,   209,   123,   147,   145,   231,
     232,     3,   155,   134,   102,   122,   133,   138,    89,   147,
      89,   467,    92,    81,   194,   142,   133,    85,   145,    81,
     203,   356,   145,   358,   151,    81,   153,   210,   151,    91,
     153,    88,    98,    99,   345,    81,   174,     3,    81,   177,
     122,   168,   180,   226,    82,   168,    88,   185,    91,   429,
     188,   189,   190,   191,   192,   193,    81,    83,   103,   141,
      85,   104,    81,    89,   198,    84,    91,   198,    11,    12,
      13,   151,    91,   153,    92,   255,   203,    38,    39,    40,
     207,   198,    81,   210,   231,   232,    91,   422,   168,   245,
      81,    96,    97,    90,   283,   245,    81,   305,   331,   226,
      85,   481,   482,   230,   231,   232,   100,   245,   231,   232,
     263,    72,    81,   345,    14,    15,    85,    18,    19,    82,
      83,   139,   123,   101,   459,   460,   461,   209,    82,    83,
      91,   466,    20,   151,    82,   136,   319,    82,    81,    83,
      84,   142,    85,    83,    87,   283,    82,    83,   305,    88,
     168,   486,    82,   154,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   165,   398,    82,    83,    82,    83,
     326,    82,    83,    82,    83,    88,   326,   415,    88,   359,
     360,   361,     3,    82,   311,     3,   303,    82,   326,    82,
      83,    83,   319,    82,     8,    86,   323,    82,   345,    86,
     103,    82,   203,    86,    86,    82,   207,   104,    82,   210,
     363,   338,    83,   446,    84,    84,   217,    81,   345,    81,
     351,   303,   345,    81,    81,   226,   308,     3,   355,   230,
     380,   104,   355,    82,   467,   103,    86,   104,    86,    82,
      86,    86,   380,    82,     3,     3,    86,    88,   428,   429,
      86,    86,    84,    62,    83,    86,    86,   104,    86,    86,
     104,    86,   389,    86,    86,    84,    81,    84,    84,    82,
     104,   104,    60,   177,    86,    86,    84,   456,   104,   280,
     185,   282,   462,   189,   180,   192,   188,   239,   410,   231,
     374,   308,   190,   332,   450,   263,   134,   191,   363,    -1,
     450,   481,   482,   193,    75,    -1,    -1,    -1,    -1,    -1,
     311,    -1,   450,   314,    -1,    -1,    -1,   473,   319,    -1,
      -1,    -1,   323,   473,    -1,    -1,    -1,    -1,    -1,   456,
     331,    -1,    -1,   456,    -1,   473,    -1,   338,    -1,    -1,
     341,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,   398,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    90,    91,    92,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   446,   104,    -1,    -1,    -1,
      -1,    -1,    -1,   454,    -1,    -1,   457,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,   467,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,     3,     4,     5,     6,     7,     8,     9,    10,   104,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,     3,     4,     5,     6,     7,     8,
       9,    10,   104,    12,    13,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    90,    91,    92,    93,    94,    95,    81,     4,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    90,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,     3,     4,     5,     6,     7,     8,
       9,    10,    88,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    90,    91,    92,    93,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    70,    86,    72,    73,    -1,    90,    91,    92,
      93,    94,    95,    81,    -1,    -1,    -1,    -1,    86,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    90,    91,    92,    93,    94,    95,    81,    -1,    -1,
      -1,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    70,    87,    88,
      73,    90,    91,    92,    93,    94,    95,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    90,    91,    92,
      93,    94,    95,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    70,    -1,    -1,    73,    -1,
      90,    91,    92,    93,    94,    95,    81,    -1,    -1,    -1,
      -1,    70,    -1,    88,    73,    90,    91,    92,    93,    94,
      95,    -1,    81,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    90,    91,    92,    93,    94,    95,    81,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    81,    82,     4,    70,
      85,    -1,    73,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    -1,    32,    33,    34,    35,
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
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    75,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,
      82,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    -1,    82,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    75,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     4,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,
      77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,    77,    78,    79,   139,   140,   143,   144,   145,
     148,   159,   165,   166,   167,   168,   186,   199,   201,   202,
      88,   160,    81,   144,   151,   166,   178,    81,     3,    81,
      91,   104,   141,   142,   169,   170,   172,   140,   140,     3,
      88,   140,   140,   140,     0,   200,     3,   108,   163,   164,
       3,     3,     5,     6,     7,     8,     9,    10,    12,    13,
      70,    73,    81,    90,    91,    92,    93,    94,    95,   106,
     107,   109,   110,   113,   115,   116,   117,   118,   119,   121,
     123,   125,   127,   129,   130,   131,   132,   133,   134,   138,
     178,   151,    81,    85,   172,   179,   180,   151,    82,   138,
     169,   166,   172,   173,    83,   104,   103,   139,   140,   203,
     204,    81,    85,   170,   147,   146,   201,   103,    83,    89,
     161,    81,   115,    81,    81,    88,   115,   134,   135,   137,
     178,   189,    11,    12,    13,    81,    85,    87,    81,   115,
     118,    91,    96,    97,   120,    92,    93,   122,    14,    15,
     124,    16,    17,    98,    99,   126,    18,    19,   128,    90,
     100,   101,    20,    21,   102,    82,    82,    82,   140,   174,
     175,   176,   179,    34,    86,    91,   135,   173,   180,    81,
      85,    83,   171,   166,   172,   142,   169,    88,   135,   181,
     189,   139,     3,    82,   174,   177,    34,    86,    91,   135,
     173,    88,   149,   150,   151,   186,   138,    89,   164,    88,
     162,   178,   178,   135,     3,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    89,   104,   137,   139,
     187,   188,   189,   190,   191,   192,   193,   195,   198,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   103,
     136,    82,    83,    82,    82,     3,    82,   114,   135,   137,
       3,   178,   118,   119,   121,   123,   125,   127,   129,   130,
     131,   132,   137,    81,   169,   172,   179,    82,    83,    82,
     135,   173,    86,    86,    34,    86,   135,    82,   174,    34,
      86,    91,   135,   173,     8,    82,    85,    87,    89,   181,
     182,   183,   184,   185,    82,    82,    83,   135,   173,    86,
      86,    34,    86,    91,   135,   149,    89,   150,   104,   152,
     153,   154,   163,    82,    82,    83,    84,   138,    84,    81,
      81,    81,   187,    81,     3,   104,   104,   104,   137,   104,
      89,   191,   135,   135,    88,   118,    82,    83,    86,    82,
      84,    56,   176,    86,   135,   135,    86,    82,   135,   173,
      86,    86,    34,    86,   135,    82,   138,     3,    83,    89,
     181,   103,   185,     3,    86,   135,   135,    86,    86,    89,
      83,   104,    84,   155,   169,    83,    89,    58,   111,   112,
     178,   187,    84,   187,   137,   137,   137,    62,   139,   192,
     196,   104,   104,   182,   135,   134,    86,    86,    86,   135,
     135,    86,   104,    86,    89,   181,   183,    86,    86,   153,
     156,   157,   158,    89,    84,    82,    83,    84,   187,    82,
      82,    82,    81,   137,   197,   197,    82,    83,    89,    86,
      86,   181,   138,    84,   135,   112,   135,   187,   187,   187,
     137,   104,   104,   187,    89,   138,    60,   194,    82,   197,
     197,   187,   104
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   108,   109,   109,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   137,   137,   138,   139,   139,
     139,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   142,   142,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     146,   145,   147,   145,   145,   148,   148,   149,   149,   150,
     150,   150,   151,   151,   151,   151,   152,   152,   154,   153,
     156,   155,   157,   155,   158,   155,   159,   159,   160,   161,
     159,   162,   162,   162,   163,   163,   164,   164,   165,   166,
     166,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     171,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   172,   172,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   176,   177,   177,   178,
     178,   179,   179,   179,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   181,   181,   181,   181,   182,
     182,   182,   182,   183,   184,   184,   185,   185,   186,   187,
     187,   187,   187,   187,   187,   188,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     195,   195,   195,   196,   196,   197,   197,   198,   198,   198,
     198,   198,   199,   200,   199,   201,   201,   202,   203,   203,
     204,   204
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     6,     1,     3,     3,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     6,     7,     1,
       3,     1,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     6,     2,     1,     1,     1,     2,     2,
       3,     1,     2,     1,     2,     1,     1,     3,     0,     2,
       0,     3,     0,     4,     0,     2,     4,     5,     0,     0,
       5,     0,     3,     4,     1,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       0,     4,     3,     4,     6,     5,     5,     6,     5,     4,
       4,     3,     4,     4,     3,     2,     2,     1,     1,     2,
       3,     1,     1,     3,     2,     2,     1,     1,     3,     2,
       1,     2,     1,     1,     3,     2,     3,     5,     4,     5,
       4,     3,     3,     3,     4,     6,     5,     5,     6,     4,
       4,     2,     3,     3,     4,     3,     4,     1,     2,     2,
       1,     4,     3,     2,     1,     2,     3,     2,     7,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       1,     2,     1,     1,     1,     2,     6,     5,     0,     2,
       5,     7,     5,     4,     4,     0,     1,     3,     2,     2,
       2,     3,     1,     0,     3,     1,     1,     4,     0,     1,
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
#line 142 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2401 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' compound_statement ')'  */
#line 148 "C_grammar.y"
                {size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2411 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' expression ')'  */
#line 154 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2421 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: generic_selection  */
#line 159 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2427 "C_grammar.tab.c"
    break;

  case 13: /* string: FUNC_NAME  */
#line 174 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2433 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 194 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2444 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' ')'  */
#line 201 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2454 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 207 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2465 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 214 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2476 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 221 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2487 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression INC_OP  */
#line 228 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2497 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression DEC_OP  */
#line 234 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2507 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 240 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2518 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 247 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2529 "C_grammar.tab.c"
    break;

  case 30: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 258 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2540 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_inc_dec unary_expression  */
#line 269 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2551 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 276 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2562 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 283 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2572 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 289 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2582 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 295 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2592 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: INC_OP  */
#line 303 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2598 "C_grammar.tab.c"
    break;

  case 38: /* unary_inc_dec: DEC_OP  */
#line 304 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2604 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '&'  */
#line 308 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2610 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '*'  */
#line 309 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2616 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '+'  */
#line 310 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2622 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '-'  */
#line 311 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2628 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '~'  */
#line 312 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2634 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '!'  */
#line 313 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2640 "C_grammar.tab.c"
    break;

  case 46: /* cast_expression: '(' type_name ')' cast_expression  */
#line 319 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2651 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 330 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2663 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '*'  */
#line 340 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2669 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '/'  */
#line 341 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2675 "C_grammar.tab.c"
    break;

  case 51: /* multiplicative_expression_op: '%'  */
#line 342 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2681 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 348 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2693 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '+'  */
#line 358 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2699 "C_grammar.tab.c"
    break;

  case 55: /* additive_expression_op: '-'  */
#line 359 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2705 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 365 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2717 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: LEFT_OP  */
#line 375 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2723 "C_grammar.tab.c"
    break;

  case 59: /* shift_expression_op: RIGHT_OP  */
#line 376 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2729 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 382 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2741 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '<'  */
#line 392 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2747 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: '>'  */
#line 393 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2753 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: LE_OP  */
#line 394 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2759 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression_operator: GE_OP  */
#line 395 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2765 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 402 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2777 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: EQ_OP  */
#line 412 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2783 "C_grammar.tab.c"
    break;

  case 69: /* equality_expression_op: NE_OP  */
#line 413 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2789 "C_grammar.tab.c"
    break;

  case 71: /* and_expression: and_expression '&' equality_expression  */
#line 419 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2800 "C_grammar.tab.c"
    break;

  case 73: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 430 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2811 "C_grammar.tab.c"
    break;

  case 75: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 441 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2822 "C_grammar.tab.c"
    break;

  case 77: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 452 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2833 "C_grammar.tab.c"
    break;

  case 79: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 463 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2844 "C_grammar.tab.c"
    break;

  case 81: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 474 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2856 "C_grammar.tab.c"
    break;

  case 83: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 486 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2868 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: '='  */
#line 496 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2874 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: MUL_ASSIGN  */
#line 497 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2880 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: DIV_ASSIGN  */
#line 498 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2886 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: MOD_ASSIGN  */
#line 499 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2892 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: ADD_ASSIGN  */
#line 500 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2898 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: SUB_ASSIGN  */
#line 501 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2904 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: LEFT_ASSIGN  */
#line 502 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2910 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: RIGHT_ASSIGN  */
#line 503 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2916 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: AND_ASSIGN  */
#line 504 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2922 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: XOR_ASSIGN  */
#line 505 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2928 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: OR_ASSIGN  */
#line 506 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2934 "C_grammar.tab.c"
    break;

  case 96: /* expression: expression ',' assignment_expression  */
#line 512 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2945 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers ';'  */
#line 526 "C_grammar.y"
                {size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2955 "C_grammar.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 532 "C_grammar.y"
                {/*if (strstr($1, "typedef") != NULL) {
			typedef_flag = 0; 
			if (debugMode) printf("Debug: typedef switched to 0 on declaration([%s], [%s])\n", $1, $2);
		 }
		 */
		 
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
#line 2982 "C_grammar.tab.c"
    break;

  case 100: /* declaration: static_assert_declaration  */
#line 555 "C_grammar.y"
                {size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2992 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 564 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3003 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 572 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3014 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 580 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3025 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 588 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); }
#line 3031 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: function_specifier  */
#line 590 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); }
#line 3037 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 592 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); }
#line 3043 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: alignment_specifier  */
#line 594 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); }
#line 3049 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 600 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3060 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator '=' initializer  */
#line 610 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 //free($3);		//todo why is this commented out?
	  	}
#line 3072 "C_grammar.tab.c"
    break;

  case 114: /* init_declarator: declarator  */
#line 618 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_name((yyvsp[0].declarator_type).ptr_declarator);	
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3083 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: TYPEDEF  */
#line 628 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3092 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: EXTERN  */
#line 632 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3098 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: STATIC  */
#line 633 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3104 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: THREAD_LOCAL  */
#line 634 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3110 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: AUTO  */
#line 635 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3116 "C_grammar.tab.c"
    break;

  case 120: /* storage_class_specifier: REGISTER  */
#line 636 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3122 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: VOID  */
#line 640 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 3128 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: CHAR  */
#line 641 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 3134 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: SHORT  */
#line 642 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 3140 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: INT  */
#line 643 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 3146 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: LONG  */
#line 644 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 3152 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: FLOAT  */
#line 645 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); otherDataTypes = true;}
#line 3158 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: DOUBLE  */
#line 646 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); otherDataTypes = true;}
#line 3164 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: SIGNED  */
#line 647 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3170 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: UNSIGNED  */
#line 648 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3176 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: BOOL  */
#line 649 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); otherDataTypes = true;}
#line 3182 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: COMPLEX  */
#line 650 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3188 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: IMAGINARY  */
#line 651 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3194 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: atomic_type_specifier  */
#line 652 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3200 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: struct_or_union_specifier  */
#line 653 "C_grammar.y"
                                    {otherDataTypes = true;}
#line 3206 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: enum_specifier  */
#line 654 "C_grammar.y"
                         {otherDataTypes = true;}
#line 3212 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: TYPEDEF_NAME  */
#line 656 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3220 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: INT128  */
#line 659 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int128"); otherDataTypes = true;}
#line 3226 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: FLOAT128  */
#line 660 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float128"); otherDataTypes = true;}
#line 3232 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: VA_LIST  */
#line 661 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "va_list"); otherDataTypes = true;}
#line 3238 "C_grammar.tab.c"
    break;

  case 140: /* $@1: %empty  */
#line 665 "C_grammar.y"
                              {in_tag_namespace = 0;}
#line 3244 "C_grammar.tab.c"
    break;

  case 141: /* struct_or_union_specifier: struct_or_union '{' $@1 struct_declaration_list '}'  */
#line 666 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3255 "C_grammar.tab.c"
    break;

  case 142: /* $@2: %empty  */
#line 672 "C_grammar.y"
                                     {in_tag_namespace = 0;}
#line 3261 "C_grammar.tab.c"
    break;

  case 143: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@2 '{' struct_declaration_list '}'  */
#line 673 "C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3275 "C_grammar.tab.c"
    break;

  case 144: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 683 "C_grammar.y"
                {in_tag_namespace = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3289 "C_grammar.tab.c"
    break;

  case 145: /* struct_or_union: STRUCT  */
#line 696 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_namespace = 1;
		}
#line 3297 "C_grammar.tab.c"
    break;

  case 146: /* struct_or_union: UNION  */
#line 700 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_namespace = 1;
		}
#line 3305 "C_grammar.tab.c"
    break;

  case 148: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 708 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3316 "C_grammar.tab.c"
    break;

  case 149: /* struct_declaration: specifier_qualifier_list ';'  */
#line 718 "C_grammar.y"
                {size_t const size = strlen("anonymous_member()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3326 "C_grammar.tab.c"
    break;

  case 150: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 725 "C_grammar.y"
                {size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
		 process_declaration_specifiers((yyvsp[-2].id));
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
	   	 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
        }
#line 3338 "C_grammar.tab.c"
    break;

  case 152: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 737 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3349 "C_grammar.tab.c"
    break;

  case 154: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 745 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3360 "C_grammar.tab.c"
    break;

  case 157: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 757 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3371 "C_grammar.tab.c"
    break;

  case 158: /* $@3: %empty  */
#line 766 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3377 "C_grammar.tab.c"
    break;

  case 159: /* struct_declarator: $@3 struct_declarator2  */
#line 767 "C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);}
#line 3383 "C_grammar.tab.c"
    break;

  case 160: /* $@4: %empty  */
#line 770 "C_grammar.y"
              {in_member_namespace = 0;}
#line 3389 "C_grammar.tab.c"
    break;

  case 161: /* struct_declarator2: ':' $@4 constant_expression  */
#line 771 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3399 "C_grammar.tab.c"
    break;

  case 162: /* $@5: %empty  */
#line 776 "C_grammar.y"
                     {in_member_namespace = 0;}
#line 3405 "C_grammar.tab.c"
    break;

  case 163: /* struct_declarator2: declarator $@5 ':' constant_expression  */
#line 777 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3417 "C_grammar.tab.c"
    break;

  case 164: /* $@6: %empty  */
#line 784 "C_grammar.y"
                      {in_member_namespace = 0;}
#line 3423 "C_grammar.tab.c"
    break;

  case 165: /* struct_declarator2: declarator $@6  */
#line 785 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[-1].declarator_type).full);
		 free((yyvsp[-1].declarator_type).full);
		 free((yyvsp[-1].declarator_type).ptr_declarator);
		}
#line 3432 "C_grammar.tab.c"
    break;

  case 166: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 793 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3442 "C_grammar.tab.c"
    break;

  case 167: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 799 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3452 "C_grammar.tab.c"
    break;

  case 168: /* $@7: %empty  */
#line 804 "C_grammar.y"
               {in_tag_namespace = 1;}
#line 3458 "C_grammar.tab.c"
    break;

  case 169: /* $@8: %empty  */
#line 804 "C_grammar.y"
                                                  {in_tag_namespace = 0;}
#line 3464 "C_grammar.tab.c"
    break;

  case 170: /* enum_specifier: ENUM $@7 IDENTIFIER $@8 enum_specifier_rest  */
#line 805 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3475 "C_grammar.tab.c"
    break;

  case 171: /* enum_specifier_rest: %empty  */
#line 815 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3481 "C_grammar.tab.c"
    break;

  case 172: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 817 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3487 "C_grammar.tab.c"
    break;

  case 173: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 819 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3497 "C_grammar.tab.c"
    break;

  case 175: /* enumerator_list: enumerator_list ',' enumerator  */
#line 829 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3508 "C_grammar.tab.c"
    break;

  case 176: /* enumerator: enumeration_constant '=' constant_expression  */
#line 839 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3519 "C_grammar.tab.c"
    break;

  case 179: /* type_qualifier: CONST  */
#line 853 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3525 "C_grammar.tab.c"
    break;

  case 180: /* type_qualifier: RESTRICT  */
#line 854 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3531 "C_grammar.tab.c"
    break;

  case 181: /* type_qualifier: VOLATILE  */
#line 855 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3537 "C_grammar.tab.c"
    break;

  case 182: /* type_qualifier: ATOMIC  */
#line 856 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3543 "C_grammar.tab.c"
    break;

  case 183: /* function_specifier: INLINE  */
#line 860 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3549 "C_grammar.tab.c"
    break;

  case 184: /* function_specifier: NORETURN  */
#line 861 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3555 "C_grammar.tab.c"
    break;

  case 187: /* declarator: pointer direct_declarator  */
#line 871 "C_grammar.y"
          {size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3567 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: IDENTIFIER  */
#line 883 "C_grammar.y"
                {if (in_member_namespace) {	//this is a member (from a struct or union) no need to transform into a Prolog var
			size_t const size = strlen((yyvsp[0].id)) + 1;
			(yyval.declarator_type).full = (char*)malloc(size);
		 	strcpy_safe((yyval.declarator_type).full, size, (yyvsp[0].id));
			(yyval.declarator_type).ptr_declarator = (char*)malloc(size);
		 	strcpy_safe((yyval.declarator_type).ptr_declarator, size, (yyvsp[0].id));
			in_member_namespace = 0;
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
#line 3595 "C_grammar.tab.c"
    break;

  case 190: /* $@9: %empty  */
#line 906 "C_grammar.y"
                         {in_member_namespace = 0;}
#line 3601 "C_grammar.tab.c"
    break;

  case 191: /* direct_declarator: '(' declarator $@9 ')'  */
#line 908 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-2].declarator_type);}
#line 3607 "C_grammar.tab.c"
    break;

  case 192: /* direct_declarator: direct_declarator '[' ']'  */
#line 910 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3618 "C_grammar.tab.c"
    break;

  case 193: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 917 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3627 "C_grammar.tab.c"
    break;

  case 194: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 922 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3636 "C_grammar.tab.c"
    break;

  case 195: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 927 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3645 "C_grammar.tab.c"
    break;

  case 196: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 932 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3654 "C_grammar.tab.c"
    break;

  case 197: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 937 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3663 "C_grammar.tab.c"
    break;

  case 198: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 942 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3672 "C_grammar.tab.c"
    break;

  case 199: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 947 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3681 "C_grammar.tab.c"
    break;

  case 200: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 952 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3693 "C_grammar.tab.c"
    break;

  case 201: /* direct_declarator: direct_declarator '(' ')'  */
#line 960 "C_grammar.y"
                {size_t const size = strlen("function(, [])") + strlen((yyvsp[-2].declarator_type).full) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, [])", (yyvsp[-2].declarator_type).full);
		 current_function = strdup((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3705 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 968 "C_grammar.y"
                {size_t const size = strlen("function(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-3].declarator_type).full);
	     free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 3718 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 977 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D13");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3727 "C_grammar.tab.c"
    break;

  case 204: /* pointer: '*' type_qualifier_list pointer  */
#line 985 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3738 "C_grammar.tab.c"
    break;

  case 205: /* pointer: '*' type_qualifier_list  */
#line 992 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3748 "C_grammar.tab.c"
    break;

  case 206: /* pointer: '*' pointer  */
#line 998 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3758 "C_grammar.tab.c"
    break;

  case 207: /* pointer: '*'  */
#line 1004 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3764 "C_grammar.tab.c"
    break;

  case 209: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1010 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3775 "C_grammar.tab.c"
    break;

  case 210: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1020 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3785 "C_grammar.tab.c"
    break;

  case 211: /* parameter_type_list: parameter_list  */
#line 1026 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3795 "C_grammar.tab.c"
    break;

  case 213: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1036 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3806 "C_grammar.tab.c"
    break;

  case 214: /* parameter_declaration: declaration_specifiers declarator  */
#line 1046 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3818 "C_grammar.tab.c"
    break;

  case 215: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1054 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3829 "C_grammar.tab.c"
    break;

  case 216: /* parameter_declaration: declaration_specifiers  */
#line 1061 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3839 "C_grammar.tab.c"
    break;

  case 219: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 1074 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3845 "C_grammar.tab.c"
    break;

  case 220: /* type_name: specifier_qualifier_list  */
#line 1076 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3855 "C_grammar.tab.c"
    break;

  case 245: /* initializer: '{' initializer_list '}'  */
#line 1115 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3865 "C_grammar.tab.c"
    break;

  case 246: /* initializer: '{' initializer_list ',' '}'  */
#line 1121 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3875 "C_grammar.tab.c"
    break;

  case 248: /* initializer: '{' '}'  */
#line 1128 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 3881 "C_grammar.tab.c"
    break;

  case 249: /* initializer_list: designation initializer  */
#line 1133 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3892 "C_grammar.tab.c"
    break;

  case 251: /* initializer_list: initializer_list ',' designation initializer  */
#line 1141 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3904 "C_grammar.tab.c"
    break;

  case 252: /* initializer_list: initializer_list ',' initializer  */
#line 1149 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3915 "C_grammar.tab.c"
    break;

  case 253: /* designation: designator_list '='  */
#line 1159 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3925 "C_grammar.tab.c"
    break;

  case 255: /* designator_list: designator_list designator  */
#line 1169 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3936 "C_grammar.tab.c"
    break;

  case 256: /* designator: '[' constant_expression ']'  */
#line 1179 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3946 "C_grammar.tab.c"
    break;

  case 257: /* designator: '.' IDENTIFIER  */
#line 1185 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3956 "C_grammar.tab.c"
    break;

  case 258: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1194 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 3967 "C_grammar.tab.c"
    break;

  case 265: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1213 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3978 "C_grammar.tab.c"
    break;

  case 266: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1220 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3989 "C_grammar.tab.c"
    break;

  case 267: /* labeled_statement: DEFAULT ':' statement  */
#line 1227 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 3999 "C_grammar.tab.c"
    break;

  case 268: /* compound_statement: '{' '}'  */
#line 1235 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4005 "C_grammar.tab.c"
    break;

  case 269: /* compound_statement: '{' block_item_list '}'  */
#line 1237 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4015 "C_grammar.tab.c"
    break;

  case 271: /* block_item_list: block_item_list block_item  */
#line 1247 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
	  }
#line 4026 "C_grammar.tab.c"
    break;

  case 274: /* expression_statement: ';'  */
#line 1261 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4032 "C_grammar.tab.c"
    break;

  case 275: /* expression_statement: expression ';'  */
#line 1263 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4042 "C_grammar.tab.c"
    break;

  case 276: /* selection_statement: IF '(' expression ')' statement else_opt  */
#line 1272 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4054 "C_grammar.tab.c"
    break;

  case 277: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1280 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4065 "C_grammar.tab.c"
    break;

  case 278: /* else_opt: %empty  */
#line 1289 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4071 "C_grammar.tab.c"
    break;

  case 279: /* else_opt: ELSE statement  */
#line 1291 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4081 "C_grammar.tab.c"
    break;

  case 280: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1299 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4092 "C_grammar.tab.c"
    break;

  case 281: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1306 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4103 "C_grammar.tab.c"
    break;

  case 282: /* iteration_statement: FOR '(' for_stmt_type ')' statement  */
#line 1313 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4116 "C_grammar.tab.c"
    break;

  case 283: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1325 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4122 "C_grammar.tab.c"
    break;

  case 284: /* for_stmt_type: declaration expression_opt ';' expression_opt  */
#line 1327 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4128 "C_grammar.tab.c"
    break;

  case 285: /* expression_opt: %empty  */
#line 1331 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4134 "C_grammar.tab.c"
    break;

  case 287: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1336 "C_grammar.y"
          {size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4144 "C_grammar.tab.c"
    break;

  case 288: /* jump_statement: CONTINUE ';'  */
#line 1341 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4150 "C_grammar.tab.c"
    break;

  case 289: /* jump_statement: BREAK ';'  */
#line 1342 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4156 "C_grammar.tab.c"
    break;

  case 290: /* jump_statement: RETURN ';'  */
#line 1343 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4162 "C_grammar.tab.c"
    break;

  case 291: /* jump_statement: RETURN expression ';'  */
#line 1345 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4172 "C_grammar.tab.c"
    break;

  case 293: /* $@10: %empty  */
#line 1355 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4178 "C_grammar.tab.c"
    break;

  case 295: /* external_declaration: function_definition  */
#line 1359 "C_grammar.y"
                                {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4184 "C_grammar.tab.c"
    break;

  case 296: /* external_declaration: declaration  */
#line 1360 "C_grammar.y"
                                        {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4190 "C_grammar.tab.c"
    break;

  case 297: /* function_definition: declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 1365 "C_grammar.y"
                {process_declaration_specifiers((yyvsp[-3].id));
		 size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-3].id), (yyvsp[-2].declarator_type).full, (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4205 "C_grammar.tab.c"
    break;

  case 298: /* declaration_list_opt: %empty  */
#line 1378 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4211 "C_grammar.tab.c"
    break;

  case 301: /* declaration_list: declaration_list declaration  */
#line 1385 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4222 "C_grammar.tab.c"
    break;


#line 4226 "C_grammar.tab.c"

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

#line 1393 "C_grammar.y"

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
        if (strcmp(token, "int") == 0) { 
			printf("TOKEN:	%s \n", token);
			flags.isInt = true; }
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

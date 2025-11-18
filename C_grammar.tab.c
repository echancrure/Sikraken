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
#line 8 "./Parser/C_grammar.y"

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
int in_ordinary_id_declaration = 0;	//indicate to the lexer that we are declaring an IDENTIFIER that may shadow a TYPEDEF_NAME
int in_label_namespace = 0;		//used in lexer

int current_scope = 0;

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements

void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 139 "C_grammar.tab.c"

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
  YYSYMBOL_type_declaration_specifiers = 146, /* type_declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 147,     /* init_declarator_list  */
  YYSYMBOL_148_4 = 148,                    /* $@4  */
  YYSYMBOL_init_declarator = 149,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 150,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 151,           /* type_specifier  */
  YYSYMBOL_typeof_specifier = 152,         /* typeof_specifier  */
  YYSYMBOL_153_5 = 153,                    /* $@5  */
  YYSYMBOL_154_6 = 154,                    /* $@6  */
  YYSYMBOL_rest_typeof_specifier = 155,    /* rest_typeof_specifier  */
  YYSYMBOL_struct_or_union_specifier = 156, /* struct_or_union_specifier  */
  YYSYMBOL_157_7 = 157,                    /* $@7  */
  YYSYMBOL_158_8 = 158,                    /* $@8  */
  YYSYMBOL_159_9 = 159,                    /* $@9  */
  YYSYMBOL_160_10 = 160,                   /* $@10  */
  YYSYMBOL_struct_or_union = 161,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 162,  /* struct_declaration_list  */
  YYSYMBOL_163_11 = 163,                   /* $@11  */
  YYSYMBOL_164_12 = 164,                   /* $@12  */
  YYSYMBOL_struct_declaration = 165,       /* struct_declaration  */
  YYSYMBOL_166_13 = 166,                   /* $@13  */
  YYSYMBOL_specifier_qualifier_list = 167, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 168,   /* struct_declarator_list  */
  YYSYMBOL_169_14 = 169,                   /* $@14  */
  YYSYMBOL_struct_declarator = 170,        /* struct_declarator  */
  YYSYMBOL_171_15 = 171,                   /* $@15  */
  YYSYMBOL_172_16 = 172,                   /* $@16  */
  YYSYMBOL_enum_specifier = 173,           /* enum_specifier  */
  YYSYMBOL_174_17 = 174,                   /* $@17  */
  YYSYMBOL_175_18 = 175,                   /* $@18  */
  YYSYMBOL_176_19 = 176,                   /* $@19  */
  YYSYMBOL_enum_specifier_rest = 177,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 178,          /* enumerator_list  */
  YYSYMBOL_179_20 = 179,                   /* $@20  */
  YYSYMBOL_enumerator = 180,               /* enumerator  */
  YYSYMBOL_181_21 = 181,                   /* $@21  */
  YYSYMBOL_atomic_type_specifier = 182,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 183,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 184,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 185,      /* alignment_specifier  */
  YYSYMBOL_declarator = 186,               /* declarator  */
  YYSYMBOL_direct_declarator = 187,        /* direct_declarator  */
  YYSYMBOL_188_22 = 188,                   /* $@22  */
  YYSYMBOL_189_23 = 189,                   /* $@23  */
  YYSYMBOL_rest_direct_declarator = 190,   /* rest_direct_declarator  */
  YYSYMBOL_rest_function_definition = 191, /* rest_function_definition  */
  YYSYMBOL_old_style_parameter_list = 192, /* old_style_parameter_list  */
  YYSYMBOL_parameter_type_list = 193,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 194,           /* parameter_list  */
  YYSYMBOL_195_24 = 195,                   /* $@24  */
  YYSYMBOL_196_25 = 196,                   /* $@25  */
  YYSYMBOL_parameter_declaration = 197,    /* parameter_declaration  */
  YYSYMBOL_pointer = 198,                  /* pointer  */
  YYSYMBOL_pointer_star = 199,             /* pointer_star  */
  YYSYMBOL_200_26 = 200,                   /* $@26  */
  YYSYMBOL_type_qualifier_list = 201,      /* type_qualifier_list  */
  YYSYMBOL_type_name = 202,                /* type_name  */
  YYSYMBOL_203_27 = 203,                   /* $@27  */
  YYSYMBOL_abstract_declarator_opt = 204,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 205,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 206, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 207,              /* initializer  */
  YYSYMBOL_initializer_list = 208,         /* initializer_list  */
  YYSYMBOL_designation = 209,              /* designation  */
  YYSYMBOL_designator_list = 210,          /* designator_list  */
  YYSYMBOL_designator = 211,               /* designator  */
  YYSYMBOL_212_28 = 212,                   /* $@28  */
  YYSYMBOL_static_assert_declaration = 213, /* static_assert_declaration  */
  YYSYMBOL_214_29 = 214,                   /* $@29  */
  YYSYMBOL_statement = 215,                /* statement  */
  YYSYMBOL_216_30 = 216,                   /* $@30  */
  YYSYMBOL_labeled_statement = 217,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 218,       /* compound_statement  */
  YYSYMBOL_block_item_list = 219,          /* block_item_list  */
  YYSYMBOL_220_31 = 220,                   /* $@31  */
  YYSYMBOL_221_32 = 221,                   /* $@32  */
  YYSYMBOL_block_item = 222,               /* block_item  */
  YYSYMBOL_expression_statement = 223,     /* expression_statement  */
  YYSYMBOL_selection_statement = 224,      /* selection_statement  */
  YYSYMBOL_else_opt = 225,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 226,      /* iteration_statement  */
  YYSYMBOL_for_stmt_type = 227,            /* for_stmt_type  */
  YYSYMBOL_228_33 = 228,                   /* $@33  */
  YYSYMBOL_expression_opt = 229,           /* expression_opt  */
  YYSYMBOL_jump_statement = 230,           /* jump_statement  */
  YYSYMBOL_translation_unit = 231,         /* translation_unit  */
  YYSYMBOL_232_34 = 232,                   /* $@34  */
  YYSYMBOL_233_35 = 233,                   /* $@35  */
  YYSYMBOL_external_declaration = 234,     /* external_declaration  */
  YYSYMBOL_function_definition = 235,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 236,     /* declaration_list_opt  */
  YYSYMBOL_old_style_declaration_list = 237, /* old_style_declaration_list  */
  YYSYMBOL_238_36 = 238,                   /* $@36  */
  YYSYMBOL_239_37 = 239                    /* $@37  */
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
#define YYLAST   1659

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  133
/* YYNRULES -- Number of rules.  */
#define YYNRULES  339
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  537

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
       0,   139,   139,   143,   144,   145,   145,   152,   158,   162,
     163,   164,   168,   172,   173,   177,   181,   182,   186,   187,
     191,   192,   199,   205,   212,   212,   220,   220,   228,   234,
     240,   257,   258,   263,   264,   274,   275,   282,   289,   295,
     301,   310,   311,   315,   316,   317,   318,   319,   320,   324,
     325,   335,   336,   347,   348,   349,   353,   354,   365,   366,
     370,   371,   382,   383,   387,   388,   399,   400,   401,   402,
     407,   408,   419,   420,   424,   425,   435,   436,   446,   447,
     457,   458,   468,   469,   479,   480,   491,   492,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   517,
     518,   528,   532,   541,   554,   567,   569,   571,   573,   575,
     577,   579,   581,   583,   585,   590,   592,   592,   602,   610,
     621,   626,   627,   628,   629,   630,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   655,   656,   657,   662,   662,   663,   663,
     666,   667,   671,   671,   677,   677,   684,   684,   693,   693,
     703,   716,   720,   727,   727,   728,   728,   738,   745,   745,
     754,   761,   762,   763,   764,   768,   768,   772,   783,   783,
     789,   789,   797,   806,   806,   820,   820,   820,   832,   833,
     835,   844,   845,   845,   855,   855,   862,   866,   870,   871,
     872,   873,   877,   878,   882,   888,   897,   905,   909,   933,
     948,   953,   953,   961,   961,   974,   977,   980,   983,   986,
     989,   992,   995,   998,  1005,  1006,  1007,  1011,  1012,  1016,
    1022,  1031,  1031,  1034,  1034,  1044,  1054,  1063,  1075,  1082,
    1086,  1086,  1093,  1098,  1099,  1103,  1103,  1119,  1120,  1124,
    1125,  1126,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,
    1149,  1150,  1151,  1155,  1161,  1167,  1168,  1173,  1180,  1181,
    1189,  1199,  1208,  1209,  1219,  1225,  1225,  1235,  1235,  1245,
    1246,  1246,  1251,  1252,  1253,  1254,  1258,  1266,  1273,  1280,
    1289,  1290,  1299,  1299,  1300,  1300,  1310,  1311,  1315,  1316,
    1325,  1333,  1343,  1344,  1377,  1384,  1391,  1403,  1405,  1405,
    1410,  1411,  1414,  1421,  1422,  1423,  1424,  1434,  1434,  1435,
    1435,  1439,  1443,  1450,  1465,  1466,  1470,  1470,  1471,  1471
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
  "constant_expression", "declaration", "type_declaration_specifiers",
  "init_declarator_list", "$@4", "init_declarator",
  "storage_class_specifier", "type_specifier", "typeof_specifier", "$@5",
  "$@6", "rest_typeof_specifier", "struct_or_union_specifier", "$@7",
  "$@8", "$@9", "$@10", "struct_or_union", "struct_declaration_list",
  "$@11", "$@12", "struct_declaration", "$@13", "specifier_qualifier_list",
  "struct_declarator_list", "$@14", "struct_declarator", "$@15", "$@16",
  "enum_specifier", "$@17", "$@18", "$@19", "enum_specifier_rest",
  "enumerator_list", "$@20", "enumerator", "$@21", "atomic_type_specifier",
  "type_qualifier", "function_specifier", "alignment_specifier",
  "declarator", "direct_declarator", "$@22", "$@23",
  "rest_direct_declarator", "rest_function_definition",
  "old_style_parameter_list", "parameter_type_list", "parameter_list",
  "$@24", "$@25", "parameter_declaration", "pointer", "pointer_star",
  "$@26", "type_qualifier_list", "type_name", "$@27",
  "abstract_declarator_opt", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "$@28",
  "static_assert_declaration", "$@29", "statement", "$@30",
  "labeled_statement", "compound_statement", "block_item_list", "$@31",
  "$@32", "block_item", "expression_statement", "selection_statement",
  "else_opt", "iteration_statement", "for_stmt_type", "$@33",
  "expression_opt", "jump_statement", "translation_unit", "$@34", "$@35",
  "external_declaration", "function_definition", "declaration_list_opt",
  "old_style_declaration_list", "$@36", "$@37", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-377)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-336)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -377,    36,  1422,  -377,  1422,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,    43,
     -11,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,    22,  1474,  1474,  -377,  -377,    20,  -377,  -377,
    1474,  1474,  1474,  -377,  -377,  -377,  -377,   -37,    76,  1323,
      -3,  1578,    23,    30,    30,  -377,  -377,    16,   146,  -377,
     -61,  -377,   -38,    53,    40,    -5,  -377,  -377,    48,    59,
    -377,  -377,  -377,   175,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  1338,  -377,  -377,   100,   109,  1173,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,    78,  -377,  1355,
    1323,  -377,    97,    -2,   134,    42,   140,   105,   121,   108,
     205,     8,  -377,   144,   153,  -377,  1578,   129,  1578,  1323,
    1323,  -377,  -377,   159,   149,  -377,  -377,  1188,   168,   171,
    1422,   158,   166,    53,  -377,   176,   178,  -377,  -377,   157,
     185,  -377,   181,  1173,  -377,  -377,  1323,   168,   177,  -377,
    -377,   130,   189,  -377,  -377,  1228,  1323,   186,   263,  1173,
    -377,  -377,  -377,  -377,  -377,  1323,  -377,  -377,  1323,  -377,
    -377,  1323,  -377,  -377,  -377,  -377,  1323,  -377,  -377,  1323,
    1323,  1323,  1323,  1323,  1323,  1323,  -377,  -377,  -377,   126,
     687,    58,  -377,  -377,    92,  -377,   195,   151,   197,  -377,
    -377,   149,    16,   983,  -377,  -377,   192,  -377,  1422,  -377,
      22,   704,  -377,    60,   196,  -377,  -377,   198,  1526,   183,
     287,   200,   175,  -377,   208,   210,   211,   214,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  1323,
    -377,  1323,  1283,  -377,   155,  -377,   -23,   292,   298,   218,
    -377,    97,    -2,   134,    42,   140,   105,   121,   108,   205,
     156,  -377,   219,   220,  1474,   223,  1023,  -377,   216,   224,
     799,    92,   230,   816,   300,  -377,  -377,  -377,  -377,   212,
    1323,  -377,  -377,    83,  1188,   -18,  -377,   226,  -377,   225,
     467,  -377,  1023,  -377,   232,   234,   911,  -377,   240,   233,
    -377,  -377,   235,  -377,  1526,  -377,   221,  -377,  1323,   175,
    -377,   135,   238,  -377,   271,  -377,  -377,  -377,  1133,  -377,
    -377,  1323,  -377,  -377,  -377,   238,  1323,  -377,   274,    31,
    -377,  -377,   243,  1023,  -377,  -377,  1323,  -377,   244,  -377,
     249,  1023,  -377,   246,   247,   928,   252,   250,  1038,  -377,
    -377,  -377,  -377,   334,  -377,   467,   254,   255,  1323,   256,
     260,   261,   264,   562,   266,   343,   248,   251,   577,  -377,
     -52,  -377,  -377,   168,  -377,  -377,  -377,  -377,  -377,  -377,
     262,  1023,  -377,  -377,  1323,  -377,   270,   277,  -377,   356,
    -377,  -377,  -377,  -377,  -377,  -377,   275,  -377,   276,   163,
    -377,   281,   284,  -377,  -377,  -377,  1474,    24,  -377,    38,
    -377,  -377,   282,   283,  -377,  -377,   285,  1023,  -377,  -377,
    1323,  -377,   286,   272,  -377,  -377,  -377,  1188,  -377,  -377,
     562,   562,   290,   562,  1323,  1323,  1323,   255,   315,   592,
     273,  -377,  -377,  -377,   -45,  -377,  -377,  -377,   293,   294,
    -377,  -377,  -377,   -21,    16,  -377,  1323,  -377,   271,  1323,
    1078,   289,  -377,  -377,  -377,  -377,   295,   296,  -377,  -377,
    -377,  -377,  -377,   562,  -377,   167,   170,   172,   302,  1323,
     303,  1422,  -377,  -377,  -377,  -377,    16,  -377,  -377,   304,
     305,  -377,  -377,  -377,  -377,  -377,  -377,  -377,   562,   562,
     562,  1323,   301,   288,   562,  1323,  -377,  1323,  -377,   328,
    -377,  -377,   180,  1323,  -377,   299,  -377,  1323,   562,  -377,
     306,  -377,  1323,  -377,  -377,  -377,  -377
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     327,   329,     0,     1,     0,   142,   120,   121,   122,   124,
     125,   202,   198,   199,   200,   135,   127,   128,   129,   130,
     133,   134,   131,   132,   126,   136,   137,   161,   162,   183,
       0,   245,   201,   203,   287,   123,   143,   144,   145,   146,
     148,   332,     0,   106,   108,   141,   139,     0,   140,   138,
     110,   112,   114,   104,   328,   331,   330,     0,     0,   245,
       0,     0,     0,     0,     0,   208,   209,     0,   242,   102,
       0,   115,   336,   207,     0,   239,   105,   107,   160,   154,
     109,   111,   113,     0,   186,     2,     9,    10,    11,    13,
      14,     0,    41,    42,     0,     0,   245,    43,    44,    45,
      46,    47,    48,    20,     3,     4,     8,    35,    49,     0,
       0,    51,    56,    60,    64,    70,    74,    76,    78,    80,
      82,    84,   101,     0,     0,   197,   172,   247,   174,     0,
     245,   147,   149,     0,     0,   116,   103,     0,     0,   338,
       0,     0,     0,   206,   238,   158,     0,   163,    12,   196,
      31,   191,   188,   245,    38,   245,     0,     0,    49,    86,
      99,     0,     0,    28,    29,     0,     0,     0,     0,   245,
      36,    37,    53,    54,    55,     0,    58,    59,     0,    62,
      63,     0,    68,    69,    66,    67,     0,    72,    73,     0,
       0,     0,     0,     0,     0,     0,   205,   204,   171,   231,
       0,   250,   246,   248,   251,   173,     0,     0,     0,   210,
     243,   241,     0,   285,   275,   118,   302,   333,     0,   337,
       0,     0,   212,   231,     0,   163,   153,   165,     0,     0,
      32,     0,     0,   187,     0,     0,     0,     0,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    88,     0,
       7,     0,     0,    22,     0,    33,     0,     0,     0,     0,
      52,    57,    61,    65,    71,    75,    77,    79,    81,    83,
       0,   269,     0,   230,     0,     0,     0,   253,    44,     0,
       0,   249,   231,     0,     0,   150,   151,   244,   117,   119,
       0,   276,   278,     0,     0,   285,   282,     0,   300,   304,
     290,   339,     0,   215,    44,     0,     0,   227,     0,   226,
     225,   157,   165,   155,     0,   164,   168,   170,     0,     0,
     184,     0,    39,    40,   245,     6,    87,   100,   285,    50,
      23,     0,    21,    25,    27,     0,     0,   270,   233,   237,
     232,   252,     0,     0,   254,   260,     0,   259,     0,   271,
       0,     0,   261,    44,     0,     0,     0,     0,   285,   273,
     277,   281,   283,     0,   301,   290,     2,   142,     0,     0,
       0,     0,     0,   290,     0,     0,     0,     0,     0,   308,
       0,   306,   307,     0,   289,   303,   292,   293,   294,   295,
       0,     0,   217,   216,     0,   223,    44,     0,   214,     0,
     159,   166,   167,   175,   195,   193,   192,   189,     0,     0,
      16,     0,    31,    34,    85,   229,     0,   231,   235,   250,
     236,   256,     0,     0,   258,   272,     0,     0,   262,   268,
       0,   267,     0,     0,   284,   274,   280,     0,   286,   305,
     290,   290,     0,   290,     0,     0,     0,     0,     0,   318,
       0,   323,   324,   325,     0,   309,   291,   219,     0,     0,
     220,   222,   228,     0,   178,   190,     0,    15,   245,     0,
      32,     0,   234,   255,   257,   264,     0,     0,   265,   288,
     279,   296,   297,   290,   299,     0,     0,     0,     0,   320,
       0,     0,   322,   326,   218,   221,   178,   169,   176,     0,
     182,    19,    17,    18,    30,   263,   266,   298,   290,   290,
     290,     0,   321,     0,   290,   320,   177,     0,   180,   312,
     311,   314,     0,   320,   316,     0,   179,     0,   290,   310,
       0,   317,   320,   181,   313,   315,   319
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,   -79,  -377,
    -377,  -377,   -20,  -377,   -59,  -377,  -377,   -97,   217,  -377,
     228,  -377,   213,  -377,   209,  -377,   227,  -377,   215,   222,
     207,   229,  -377,   -58,    17,  -377,   -93,  -124,  -136,     5,
    -377,  -377,   190,  -377,   -51,  -377,  -377,  -377,   337,  -377,
    -377,  -377,  -377,  -377,  -377,   179,  -377,  -377,    93,  -377,
     -31,  -377,  -377,   -86,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,   184,  -377,    94,  -377,  -377,   -30,  -377,  -377,   -40,
     -63,  -377,  -377,  -377,  -377,  -377,  -202,  -377,  -377,  -377,
      -1,   -53,  -377,  -377,  -182,     7,  -377,  -377,  -115,  -186,
    -131,    91,  -341,  -377,   125,  -377,  -214,  -377,  -357,  -377,
    -377,  -149,  -377,  -377,  -377,    61,   -24,  -377,  -377,  -377,
    -377,  -377,  -376,  -377,  -377,  -377,  -377,   423,  -377,  -377,
    -377,  -377,  -377
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   103,   157,   104,   149,   105,   106,   409,   410,   107,
     167,   168,   231,   254,   158,   109,   110,   111,   112,   175,
     113,   178,   114,   181,   115,   186,   116,   189,   117,   118,
     119,   120,   121,   159,   160,   249,   380,   123,    41,   220,
      70,   212,    71,    43,    44,    45,    63,    64,   131,    46,
     146,   147,   224,   225,    47,   227,   228,   314,   315,   403,
     316,   463,   464,   498,   499,   527,    48,    57,    58,   152,
     233,   150,   319,   151,   229,    49,    50,    51,    52,   133,
      73,   141,   142,   222,   308,   309,   272,   273,   274,   416,
     340,    74,    75,   134,   211,   411,    61,   202,   275,   204,
     292,   293,   294,   295,   296,   297,    53,    62,   382,   383,
     384,   217,   299,   300,   365,   385,   386,   387,   529,   388,
     490,   491,   513,   389,     1,     2,     4,    54,    55,   138,
     139,   140,   218
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   122,    72,   161,   219,   206,   215,    42,   237,    42,
     126,   143,   203,   171,   317,   281,   448,   437,   280,    65,
      66,   310,   144,    78,   135,    65,    66,    65,    66,   194,
     127,   128,   154,   251,    65,    66,     3,   207,    60,   306,
     251,    65,    66,    65,    66,   136,  -185,  -119,    76,    77,
     170,   108,  -334,    83,   455,    80,    81,    82,   182,   183,
     161,   493,   251,   307,   496,   332,   124,   137,  -119,   290,
     108,   122,    59,   256,   201,   126,   161,   126,   260,    84,
     350,   125,   301,   481,   482,   497,   484,   361,    68,   -26,
     163,   164,   176,   177,   343,   198,   128,   205,   128,    67,
     317,   355,   270,   162,   210,    67,   129,   417,   271,    68,
      79,   200,   195,   130,   417,    68,   108,    68,   200,   108,
     391,   417,   108,    67,    68,   200,   507,   108,    69,   437,
     108,   108,   108,   108,   108,   108,  -213,   208,   145,   525,
    -211,   199,   184,   185,  -224,   200,   201,   531,   179,   180,
    -152,   519,   520,   521,   214,   329,   536,   524,   187,   188,
     234,   165,   235,   360,   381,   166,   357,   -24,   358,   427,
     210,   534,   289,   236,   359,   282,   259,   126,   148,   283,
     289,   287,   255,   155,  -240,  -240,  -240,    12,    13,    14,
     172,   210,   156,   108,   404,   173,   174,   190,   128,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   199,
     271,   192,   199,   200,   250,   251,   200,   279,  -240,    68,
     406,    32,    68,   191,   420,   193,   407,   436,   196,   381,
     214,   108,   122,   281,   456,   285,   251,   197,   305,   330,
     331,   251,   336,   209,   442,   221,   210,   467,   468,   223,
     287,   508,   251,   210,   509,   251,   510,   251,   216,   108,
     122,  -335,  -194,   126,   530,   251,   326,  -156,   327,   226,
     230,   232,   210,   252,   258,   257,   287,   108,   414,   339,
     284,   286,   248,   298,   128,   454,   419,   311,   318,   313,
    -192,   320,   322,   342,   323,   333,   324,   348,   325,   418,
     354,   334,   335,   337,   344,   338,   480,   341,   356,   108,
     122,   214,   345,   287,   349,   363,   364,   137,   399,   390,
     392,   210,   393,   397,   398,   287,   400,   402,   328,   408,
     415,   421,   424,   425,   428,   429,   433,   438,   434,   436,
     440,   441,   443,   444,   445,   214,   450,   446,   413,   449,
     457,   485,   486,   487,   451,   515,   143,   452,   460,   462,
     422,   287,   466,   423,   419,   461,   465,   469,   426,   470,
     473,   474,   432,   475,   478,   214,   483,   488,   479,   492,
     504,   494,   495,   505,   506,   511,   251,   514,   528,   502,
     517,   518,   471,   526,   523,   261,   512,   287,   264,   263,
     268,   132,   288,   533,   312,   532,   266,   401,   458,   262,
     516,   459,   535,   405,   267,   472,   321,   265,   522,   412,
     362,   339,   512,   269,   500,   489,   439,    56,     0,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,   512,
       0,     0,     0,     0,   476,     0,     0,   477,     0,     0,
       0,     0,     0,     0,   214,     0,   500,     0,   108,   122,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   122,
     366,   367,    86,    87,    88,    89,    90,    91,     0,    92,
      93,     0,     0,   501,     0,     0,   503,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,   368,   369,   370,     0,   371,   372,
     373,   374,   375,   376,   377,   378,    30,    94,    31,    32,
      95,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   366,   447,    86,    87,    88,
      89,    90,    91,   379,    92,    93,     0,     0,     0,     0,
      85,     0,    86,    87,    88,    89,    90,    91,     0,    92,
      93,     0,     0,     0,     0,    85,     0,    86,    87,    88,
      89,    90,    91,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   368,
     369,   370,     0,   371,   372,   373,   374,   375,   376,   377,
     378,     0,    94,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,     0,    94,     0,     0,
      95,     0,     0,     0,    97,    98,    99,   100,   101,   102,
      96,     0,    94,     0,     0,    95,     0,     0,   379,    97,
      98,    99,   100,   101,   102,    96,     0,     0,     0,     0,
       0,     0,     0,   453,    97,    98,    99,   100,   101,   102,
      85,     0,    86,    87,    88,    89,    90,    91,   379,    92,
      93,     0,     0,     0,     0,     0,     0,    85,     0,    86,
      87,    88,    89,    90,    91,     0,    92,    93,     0,     0,
       0,   276,     0,     0,     0,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,    32,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,    94,   277,    32,    95,     0,    97,
     278,    99,   100,   101,   102,     0,     0,    96,     0,     0,
       0,     0,   303,     0,     0,     0,    97,   304,    99,   100,
     101,   102,    85,     0,    86,    87,    88,    89,    90,    91,
       0,    92,    93,     0,     0,     0,     0,     0,     0,    85,
       0,    86,    87,    88,    89,    90,    91,     0,    92,    93,
       0,     0,     0,   346,     0,     0,     0,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     351,     0,     0,     0,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,    32,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,    94,   347,    32,    95,
       0,    97,    98,    99,   100,   101,   102,     0,     0,    96,
       0,     0,     0,     0,   352,     0,     0,     0,    97,   353,
      99,   100,   101,   102,    85,     0,    86,    87,    88,    89,
      90,    91,     0,    92,    93,     0,     0,     0,     0,     0,
       0,    85,     0,    86,    87,    88,    89,    90,    91,     0,
      92,    93,     0,     0,     0,   394,     0,     0,     0,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,     0,     0,     0,    12,    13,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,    32,    95,     0,    85,     0,    86,    87,
      88,    89,    90,    91,    96,    92,    93,     0,    94,   395,
      32,    95,     0,    97,   396,    99,   100,   101,   102,     0,
       0,    96,     0,     0,     0,     0,   431,     0,     0,     0,
      97,    98,    99,   100,   101,   102,    85,     0,    86,    87,
      88,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,    85,     0,    86,    87,    88,    89,    90,    91,     0,
      92,    93,     0,    94,     0,     0,    95,     0,     0,     0,
       0,    12,    13,    14,     0,     0,    96,     0,     0,     0,
     290,     0,     0,   213,   291,    97,    98,    99,   100,   101,
     102,    85,     0,    86,    87,    88,    89,    90,    91,     0,
      92,    93,     0,    94,     0,    32,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,    94,     0,
       0,    95,     0,     0,     0,    97,    98,    99,   100,   101,
     102,    96,     0,     0,     0,   290,     0,     0,   213,   435,
      97,    98,    99,   100,   101,   102,    85,     0,    86,    87,
      88,    89,    90,    91,     0,    92,    93,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     0,   290,     0,  -285,   213,     0,
      97,    98,    99,   100,   101,   102,    85,     0,    86,    87,
      88,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,    85,     0,    86,    87,    88,    89,    90,    91,     0,
      92,    93,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
     290,     0,     0,   213,     0,    97,    98,    99,   100,   101,
     102,    85,     0,    86,    87,    88,    89,    90,    91,     0,
      92,    93,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,    94,     0,
       0,    95,     0,    -5,     0,    97,    98,    99,   100,   101,
     102,    96,     0,     0,     0,     0,     0,     0,   213,     0,
      97,    98,    99,   100,   101,   102,    85,     0,    86,    87,
      88,    89,    90,    91,     0,    92,    93,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,   253,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,    85,     0,    86,    87,
      88,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,    85,     0,    86,    87,    88,    89,    90,    91,     0,
      92,    93,     0,    94,     0,     0,    95,     0,    85,     0,
      86,    87,    88,    89,    90,    91,    96,    92,    93,     0,
       0,     0,     0,   328,     0,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,    94,     0,
       0,    95,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   153,     0,     0,     0,    94,     5,     0,    95,     0,
      97,    98,    99,   100,   101,   102,     0,     0,   169,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,     0,     6,     7,     8,     9,    10,    11,
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
      59,    59,    42,    96,   140,   129,   137,     2,   157,     4,
      61,    74,   127,   110,   228,   201,   373,   358,   200,     3,
       4,   223,    75,     3,    85,     3,     4,     3,     4,    21,
      61,    61,    91,    85,     3,     4,     0,   130,    31,   221,
      85,     3,     4,     3,     4,   106,     3,    85,    43,    44,
     109,   110,    90,    90,   106,    50,    51,    52,    16,    17,
     153,   106,    85,     3,    85,    88,    59,   105,   106,    87,
     129,   129,    83,   166,   127,   126,   169,   128,   175,     3,
     282,    84,   218,   440,   441,   106,   443,   105,    93,    11,
      12,    13,    94,    95,   276,   126,   126,   128,   128,    83,
     314,   283,   195,    96,   134,    83,    83,    83,    84,    93,
      90,    87,   104,    83,    83,    93,   175,    93,    87,   178,
     302,    83,   181,    83,    93,    87,   483,   186,   106,   470,
     189,   190,   191,   192,   193,   194,    83,   130,    90,   515,
      87,    83,   100,   101,    84,    87,   199,   523,    14,    15,
      91,   508,   509,   510,   137,   252,   532,   514,    18,    19,
     153,    83,   155,   294,   300,    87,   290,    89,    85,   351,
     200,   528,   212,   156,    91,    83,   169,   228,     3,    87,
     220,   211,   165,    83,    38,    39,    40,    38,    39,    40,
      93,   221,    83,   252,   318,    98,    99,    92,   228,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    83,
      84,   103,    83,    87,    84,    85,    87,   200,    72,    93,
      85,    72,    93,   102,   339,    20,    91,   358,    84,   365,
     213,   290,   290,   419,   383,    84,    85,    84,   221,    84,
      85,    85,    86,    84,   368,    87,   276,    84,    85,    83,
     280,    84,    85,   283,    84,    85,    84,    85,    90,   318,
     318,    90,   105,   314,    84,    85,   249,    91,   251,    91,
      85,    90,   302,    84,    11,    89,   306,   336,   336,   274,
      85,    84,   105,    91,   314,   378,   339,    91,   105,    91,
       3,    91,    84,   276,    84,     3,    85,   280,    84,   339,
     283,     3,    84,    84,    88,    85,   437,    84,     8,   368,
     368,   294,    88,   343,    84,    89,    91,   105,    85,   302,
      88,   351,    88,   306,    84,   355,    91,   106,    90,    58,
      56,    88,    88,    84,    88,    88,    84,     3,    88,   470,
      86,    86,    86,    83,    83,   328,     3,    83,   331,    83,
      88,   444,   445,   446,   106,   491,   419,   106,    88,     3,
     343,   391,    86,   346,   417,    88,    91,    86,   351,    85,
      88,    88,   355,    88,    88,   358,    86,    62,   106,   106,
      91,    88,    88,    88,    88,    83,    85,    84,    60,   468,
      86,    86,   412,   517,   106,   178,   489,   427,   189,   186,
     193,    64,   212,   527,   225,   106,   191,   314,   391,   181,
     496,   394,   106,   319,   192,   416,   232,   190,   511,   328,
     295,   416,   515,   194,   464,   449,   365,     4,    -1,    -1,
     523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,
      -1,    -1,    -1,    -1,   437,    -1,   496,    -1,   517,   517,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,   527,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,   466,    -1,    -1,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,     3,     4,     5,     6,     7,
       8,     9,    10,   106,    12,    13,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      83,    -1,    70,    -1,    -1,    73,    -1,    -1,   106,    92,
      93,    94,    95,    96,    97,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    92,    93,    94,    95,    96,    97,
       3,    -1,     5,     6,     7,     8,     9,    10,   106,    12,
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
      -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    70,    88,    72,    73,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    73,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    83,    12,    13,    -1,    70,    88,
      72,    73,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    83,    -1,    -1,    -1,
      87,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    70,    -1,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    87,    -1,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      87,    -1,    -1,    90,    -1,    92,    93,    94,    95,    96,
      97,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    70,    -1,
      -1,    73,    -1,    90,    -1,    92,    93,    94,    95,    96,
      97,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    95,    96,    97,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    70,    -1,    -1,    73,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    83,    12,    13,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    83,    -1,    -1,    -1,    70,     4,    -1,    73,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    83,    -1,
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
       0,   231,   232,     0,   233,     4,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      69,    71,    72,    74,    75,    76,    77,    78,    79,    80,
      81,   145,   146,   150,   151,   152,   156,   161,   173,   182,
     183,   184,   185,   213,   234,   235,   234,   174,   175,    83,
     202,   203,   214,   153,   154,     3,     4,    83,    93,   106,
     147,   149,   186,   187,   198,   199,   146,   146,     3,    90,
     146,   146,   146,    90,     3,     3,     5,     6,     7,     8,
       9,    10,    12,    13,    70,    73,    83,    92,    93,    94,
      95,    96,    97,   108,   110,   112,   113,   116,   121,   122,
     123,   124,   125,   127,   129,   131,   133,   135,   136,   137,
     138,   139,   140,   144,   202,    84,   151,   167,   183,    83,
      83,   155,   155,   186,   200,    85,   106,   105,   236,   237,
     238,   188,   189,   187,   198,    90,   157,   158,     3,   111,
     178,   180,   176,    83,   121,    83,    83,   109,   121,   140,
     141,   143,   202,    12,    13,    83,    87,   117,   118,    83,
     121,   124,    93,    98,    99,   126,    94,    95,   128,    14,
      15,   130,    16,    17,   100,   101,   132,    18,    19,   134,
      92,   102,   103,    20,    21,   104,    84,    84,   167,    83,
      87,   198,   204,   205,   206,   167,   144,   143,   202,    84,
     183,   201,   148,    90,   141,   207,    90,   218,   239,   145,
     146,    87,   190,    83,   159,   160,    91,   162,   163,   181,
      85,   119,    90,   177,   202,   202,   141,   218,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   105,   142,
      84,    85,    84,    84,   120,   141,   143,    89,    11,   202,
     124,   125,   127,   129,   131,   133,   135,   136,   137,   138,
     143,    84,   193,   194,   195,   205,    34,    88,    93,   141,
     201,   206,    83,    87,    85,    84,    84,   183,   149,   186,
      87,    91,   207,   208,   209,   210,   211,   212,    91,   219,
     220,   145,    34,    88,    93,   141,   201,     3,   191,   192,
     193,    91,   162,    91,   164,   165,   167,   213,   105,   179,
      91,   178,    84,    84,    85,    84,   141,   141,    90,   124,
      84,    85,    88,     3,     3,    84,    86,    84,    85,   146,
     197,    84,   141,   201,    88,    88,    34,    88,   141,    84,
     193,    34,    88,    93,   141,   201,     8,   144,    85,    91,
     207,   105,   211,    89,    91,   221,     3,     4,    57,    58,
      59,    61,    62,    63,    64,    65,    66,    67,    68,   106,
     143,   145,   215,   216,   217,   222,   223,   224,   226,   230,
     141,   201,    88,    88,    34,    88,    93,   141,    84,    85,
      91,   165,   106,   166,   144,   180,    85,    91,    58,   114,
     115,   202,   208,   141,   140,    56,   196,    83,   186,   198,
     205,    88,   141,   141,    88,    84,   141,   201,    88,    88,
      34,    88,   141,    84,    88,    91,   207,   209,     3,   222,
      86,    86,   144,    86,    83,    83,    83,     4,   215,    83,
       3,   106,   106,   106,   143,   106,   218,    88,   141,   141,
      88,    88,     3,   168,   169,    91,    86,    84,    85,    86,
      85,   119,   197,    88,    88,    88,   141,   141,    88,   106,
     207,   215,   215,    86,   215,   143,   143,   143,    62,   223,
     227,   228,   106,   106,    88,    88,    85,   106,   170,   171,
     186,   141,   115,   141,    91,    88,    88,   215,    84,    84,
      84,    83,   143,   229,    84,   145,   170,    86,    86,   215,
     215,   215,   143,   106,   215,   229,   144,   172,    60,   225,
      84,   229,   106,   144,   215,   106,   229
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   108,   109,   108,   108,   108,   110,
     110,   110,   111,   112,   112,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   117,   116,   118,   116,   116,   116,
     116,   119,   119,   120,   120,   121,   121,   121,   121,   121,
     121,   122,   122,   123,   123,   123,   123,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   143,
     143,   144,   145,   145,   145,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   147,   148,   147,   149,   149,
     150,   150,   150,   150,   150,   150,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   153,   152,   154,   152,
     155,   155,   157,   156,   158,   156,   159,   156,   160,   156,
     156,   161,   161,   163,   162,   164,   162,   165,   166,   165,
     165,   167,   167,   167,   167,   169,   168,   168,   171,   170,
     172,   170,   170,   174,   173,   175,   176,   173,   177,   177,
     177,   178,   179,   178,   181,   180,   180,   182,   183,   183,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     187,   188,   187,   189,   187,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   191,   191,   191,   192,   192,   193,
     193,   195,   194,   196,   194,   197,   197,   197,   198,   198,
     200,   199,   199,   201,   201,   203,   202,   204,   204,   205,
     205,   205,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   207,   207,   207,   207,   208,   208,   208,
     208,   209,   210,   210,   211,   212,   211,   214,   213,   215,
     216,   215,   215,   215,   215,   215,   217,   217,   217,   217,
     218,   218,   220,   219,   221,   219,   222,   222,   223,   223,
     224,   224,   225,   225,   226,   226,   226,   227,   228,   227,
     229,   229,   230,   230,   230,   230,   230,   232,   231,   233,
     231,   234,   234,   235,   236,   236,   238,   237,   239,   237
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
       1,     2,     1,     2,     1,     1,     0,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     3,
       3,     3,     0,     4,     0,     5,     0,     5,     0,     6,
       2,     1,     1,     0,     2,     0,     3,     2,     0,     4,
       1,     2,     1,     2,     1,     0,     2,     3,     0,     3,
       0,     4,     1,     0,     6,     0,     0,     5,     0,     3,
       4,     1,     0,     4,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     4,     2,     1,     1,     1,
       3,     0,     3,     0,     5,     2,     3,     3,     5,     4,
       4,     5,     4,     3,     0,     1,     1,     1,     3,     3,
       1,     0,     2,     0,     4,     2,     2,     1,     2,     1,
       0,     3,     1,     1,     2,     0,     3,     0,     1,     2,
       1,     1,     3,     2,     3,     5,     4,     5,     4,     3,
       3,     3,     4,     6,     5,     5,     6,     4,     4,     2,
       3,     3,     4,     3,     4,     1,     2,     2,     1,     4,
       3,     2,     1,     2,     3,     0,     3,     0,     8,     1,
       0,     2,     1,     1,     1,     1,     3,     3,     4,     3,
       2,     3,     0,     2,     0,     3,     1,     1,     1,     2,
       6,     5,     0,     2,     5,     7,     5,     4,     0,     5,
       0,     1,     3,     2,     2,     2,     3,     0,     2,     0,
       3,     1,     1,     4,     0,     1,     0,     2,     0,     3
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
#line 140 "./Parser/C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2297 "C_grammar.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 145 "./Parser/C_grammar.y"
              {current_scope++;}
#line 2303 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' $@1 compound_statement ')'  */
#line 146 "./Parser/C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2314 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 153 "./Parser/C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2324 "C_grammar.tab.c"
    break;

  case 8: /* primary_expression: generic_selection  */
#line 158 "./Parser/C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2330 "C_grammar.tab.c"
    break;

  case 14: /* string: FUNC_NAME  */
#line 173 "./Parser/C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2336 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 193 "./Parser/C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2347 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' ')'  */
#line 200 "./Parser/C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2357 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 206 "./Parser/C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2368 "C_grammar.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 212 "./Parser/C_grammar.y"
                             {in_member_namespace = 1;}
#line 2374 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression $@2 '.' IDENTIFIER  */
#line 213 "./Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2386 "C_grammar.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 220 "./Parser/C_grammar.y"
                             {in_member_namespace = 1;}
#line 2392 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression $@3 PTR_OP IDENTIFIER  */
#line 221 "./Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2404 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression INC_OP  */
#line 229 "./Parser/C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2414 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression DEC_OP  */
#line 235 "./Parser/C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2424 "C_grammar.tab.c"
    break;

  case 30: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 241 "./Parser/C_grammar.y"
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
#line 2442 "C_grammar.tab.c"
    break;

  case 31: /* comma_opt: %empty  */
#line 257 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2448 "C_grammar.tab.c"
    break;

  case 32: /* comma_opt: ','  */
#line 258 "./Parser/C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2454 "C_grammar.tab.c"
    break;

  case 34: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 265 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2465 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: unary_inc_dec unary_expression  */
#line 276 "./Parser/C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2476 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: unary_operator cast_expression  */
#line 283 "./Parser/C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2487 "C_grammar.tab.c"
    break;

  case 38: /* unary_expression: SIZEOF unary_expression  */
#line 290 "./Parser/C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2497 "C_grammar.tab.c"
    break;

  case 39: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 296 "./Parser/C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2507 "C_grammar.tab.c"
    break;

  case 40: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 302 "./Parser/C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2517 "C_grammar.tab.c"
    break;

  case 41: /* unary_inc_dec: INC_OP  */
#line 310 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2523 "C_grammar.tab.c"
    break;

  case 42: /* unary_inc_dec: DEC_OP  */
#line 311 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2529 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '&'  */
#line 315 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2535 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '*'  */
#line 316 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2541 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '+'  */
#line 317 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2547 "C_grammar.tab.c"
    break;

  case 46: /* unary_operator: '-'  */
#line 318 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2553 "C_grammar.tab.c"
    break;

  case 47: /* unary_operator: '~'  */
#line 319 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2559 "C_grammar.tab.c"
    break;

  case 48: /* unary_operator: '!'  */
#line 320 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2565 "C_grammar.tab.c"
    break;

  case 50: /* cast_expression: '(' type_name ')' cast_expression  */
#line 326 "./Parser/C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2576 "C_grammar.tab.c"
    break;

  case 52: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 337 "./Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2588 "C_grammar.tab.c"
    break;

  case 53: /* multiplicative_expression_op: '*'  */
#line 347 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2594 "C_grammar.tab.c"
    break;

  case 54: /* multiplicative_expression_op: '/'  */
#line 348 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2600 "C_grammar.tab.c"
    break;

  case 55: /* multiplicative_expression_op: '%'  */
#line 349 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2606 "C_grammar.tab.c"
    break;

  case 57: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 355 "./Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2618 "C_grammar.tab.c"
    break;

  case 58: /* additive_expression_op: '+'  */
#line 365 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2624 "C_grammar.tab.c"
    break;

  case 59: /* additive_expression_op: '-'  */
#line 366 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2630 "C_grammar.tab.c"
    break;

  case 61: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 372 "./Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2642 "C_grammar.tab.c"
    break;

  case 62: /* shift_expression_op: LEFT_OP  */
#line 382 "./Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2648 "C_grammar.tab.c"
    break;

  case 63: /* shift_expression_op: RIGHT_OP  */
#line 383 "./Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2654 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 389 "./Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2666 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression_operator: '<'  */
#line 399 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2672 "C_grammar.tab.c"
    break;

  case 67: /* relational_expression_operator: '>'  */
#line 400 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2678 "C_grammar.tab.c"
    break;

  case 68: /* relational_expression_operator: LE_OP  */
#line 401 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2684 "C_grammar.tab.c"
    break;

  case 69: /* relational_expression_operator: GE_OP  */
#line 402 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2690 "C_grammar.tab.c"
    break;

  case 71: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 409 "./Parser/C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2702 "C_grammar.tab.c"
    break;

  case 72: /* equality_expression_op: EQ_OP  */
#line 419 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2708 "C_grammar.tab.c"
    break;

  case 73: /* equality_expression_op: NE_OP  */
#line 420 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2714 "C_grammar.tab.c"
    break;

  case 75: /* and_expression: and_expression '&' equality_expression  */
#line 426 "./Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2725 "C_grammar.tab.c"
    break;

  case 77: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 437 "./Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2736 "C_grammar.tab.c"
    break;

  case 79: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 448 "./Parser/C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2747 "C_grammar.tab.c"
    break;

  case 81: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 459 "./Parser/C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2758 "C_grammar.tab.c"
    break;

  case 83: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 470 "./Parser/C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2769 "C_grammar.tab.c"
    break;

  case 85: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 481 "./Parser/C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + MAX_BRANCH_STR + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2781 "C_grammar.tab.c"
    break;

  case 87: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 493 "./Parser/C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2793 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: '='  */
#line 503 "./Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2799 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: MUL_ASSIGN  */
#line 504 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2805 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: DIV_ASSIGN  */
#line 505 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2811 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: MOD_ASSIGN  */
#line 506 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2817 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: ADD_ASSIGN  */
#line 507 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2823 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: SUB_ASSIGN  */
#line 508 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2829 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: LEFT_ASSIGN  */
#line 509 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2835 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: RIGHT_ASSIGN  */
#line 510 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2841 "C_grammar.tab.c"
    break;

  case 96: /* assignment_operator: AND_ASSIGN  */
#line 511 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2847 "C_grammar.tab.c"
    break;

  case 97: /* assignment_operator: XOR_ASSIGN  */
#line 512 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2853 "C_grammar.tab.c"
    break;

  case 98: /* assignment_operator: OR_ASSIGN  */
#line 513 "./Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2859 "C_grammar.tab.c"
    break;

  case 100: /* expression: expression ',' assignment_expression  */
#line 519 "./Parser/C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2870 "C_grammar.tab.c"
    break;

  case 102: /* declaration: type_declaration_specifiers ';'  */
#line 533 "./Parser/C_grammar.y"
                {if (debugMode) printf("end of stand alone declaration specifier as a declaration on line %d\n", yylineno);
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("\ndeclaration()") + strlen(decl_specifier) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration(%s)", decl_specifier);
		 free(decl_specifier);
		 in_ordinary_id_declaration = 0;
		}
#line 2883 "C_grammar.tab.c"
    break;

  case 103: /* declaration: type_declaration_specifiers init_declarator_list ';'  */
#line 542 "./Parser/C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations [why not done above?]
	    	typedef_flag = 0; 
			if (debugMode) printf("Debug: typedef switched to 0\n");
	   	 }
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("\ndeclaration(, [])") + strlen(decl_specifier) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration(%s, [%s])", decl_specifier, (yyvsp[-1].id));
		 free(decl_specifier);
		 free((yyvsp[-1].id));
		 in_ordinary_id_declaration = 0; //not needed but added for safety
		}
#line 2900 "C_grammar.tab.c"
    break;

  case 104: /* declaration: static_assert_declaration  */
#line 555 "./Parser/C_grammar.y"
                {size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		 pop_decl_spec_stack();
		 in_ordinary_id_declaration = 0; //not needed but added for safety
		}
#line 2912 "C_grammar.tab.c"
    break;

  case 105: /* type_declaration_specifiers: storage_class_specifier type_declaration_specifiers  */
#line 568 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2918 "C_grammar.tab.c"
    break;

  case 106: /* type_declaration_specifiers: storage_class_specifier  */
#line 570 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2924 "C_grammar.tab.c"
    break;

  case 107: /* type_declaration_specifiers: type_specifier type_declaration_specifiers  */
#line 572 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2930 "C_grammar.tab.c"
    break;

  case 108: /* type_declaration_specifiers: type_specifier  */
#line 574 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2936 "C_grammar.tab.c"
    break;

  case 109: /* type_declaration_specifiers: type_qualifier type_declaration_specifiers  */
#line 576 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2942 "C_grammar.tab.c"
    break;

  case 110: /* type_declaration_specifiers: type_qualifier  */
#line 578 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2948 "C_grammar.tab.c"
    break;

  case 111: /* type_declaration_specifiers: function_specifier type_declaration_specifiers  */
#line 580 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2954 "C_grammar.tab.c"
    break;

  case 112: /* type_declaration_specifiers: function_specifier  */
#line 582 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2960 "C_grammar.tab.c"
    break;

  case 113: /* type_declaration_specifiers: alignment_specifier type_declaration_specifiers  */
#line 584 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2966 "C_grammar.tab.c"
    break;

  case 114: /* type_declaration_specifiers: alignment_specifier  */
#line 586 "./Parser/C_grammar.y"
          {in_ordinary_id_declaration = 1;}
#line 2972 "C_grammar.tab.c"
    break;

  case 115: /* init_declarator_list: init_declarator  */
#line 591 "./Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);}
#line 2978 "C_grammar.tab.c"
    break;

  case 116: /* $@4: %empty  */
#line 592 "./Parser/C_grammar.y"
                                   {in_ordinary_id_declaration = 1;}
#line 2984 "C_grammar.tab.c"
    break;

  case 117: /* init_declarator_list: init_declarator_list ',' $@4 init_declarator  */
#line 593 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[0].id));
		}
#line 2995 "C_grammar.tab.c"
    break;

  case 118: /* init_declarator: declarator '=' initializer  */
#line 603 "./Parser/C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));
	  	}
#line 3007 "C_grammar.tab.c"
    break;

  case 119: /* init_declarator: declarator  */
#line 611 "./Parser/C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_id(current_scope, (yyvsp[0].declarator_type).ptr_declarator, 1);	//the id as a TYPEDEF_NAME is added to the data structures keeping track of typedef_names (and ids shadowing)
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3018 "C_grammar.tab.c"
    break;

  case 120: /* storage_class_specifier: TYPEDEF  */
#line 622 "./Parser/C_grammar.y"
                {decl_spec_stack->decl_spec.storage.isTypeDef = true;
         typedef_flag = 1;
		 if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3027 "C_grammar.tab.c"
    break;

  case 121: /* storage_class_specifier: EXTERN  */
#line 626 "./Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isExtern = true; }
#line 3033 "C_grammar.tab.c"
    break;

  case 122: /* storage_class_specifier: STATIC  */
#line 627 "./Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isStatic = true; }
#line 3039 "C_grammar.tab.c"
    break;

  case 123: /* storage_class_specifier: THREAD_LOCAL  */
#line 628 "./Parser/C_grammar.y"
                        { decl_spec_stack->decl_spec.storage.isThreadLocal = true; }
#line 3045 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: AUTO  */
#line 629 "./Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isAuto = true; }
#line 3051 "C_grammar.tab.c"
    break;

  case 125: /* storage_class_specifier: REGISTER  */
#line 630 "./Parser/C_grammar.y"
                                { decl_spec_stack->decl_spec.storage.isRegister = true; }
#line 3057 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: VOID  */
#line 635 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isVoid = true;}
#line 3063 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: CHAR  */
#line 636 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isChar = true;}
#line 3069 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: SHORT  */
#line 637 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isShort= true;}
#line 3075 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: INT  */
#line 638 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isInt = true;}
#line 3081 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: LONG  */
#line 639 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.longCount++;}
#line 3087 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: FLOAT  */
#line 640 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isFloat = true;}
#line 3093 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: DOUBLE  */
#line 641 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isDouble = true;}
#line 3099 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: SIGNED  */
#line 642 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isSigned = true;}
#line 3105 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: UNSIGNED  */
#line 643 "./Parser/C_grammar.y"
                                                { decl_spec_stack->decl_spec.atomic.isUnSigned = true;}
#line 3111 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: BOOL  */
#line 644 "./Parser/C_grammar.y"
                                                { simple_str_lit_copy(&(decl_spec_stack->decl_spec.atomic.typeName), "bool");}
#line 3117 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: COMPLEX  */
#line 645 "./Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "complex");}
#line 3123 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: IMAGINARY  */
#line 646 "./Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "imaginary");}
#line 3129 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: atomic_type_specifier  */
#line 647 "./Parser/C_grammar.y"
                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "atomic_type_specifier");}
#line 3135 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: struct_or_union_specifier  */
#line 648 "./Parser/C_grammar.y"
                                    { decl_spec_stack->decl_spec.non_atomic = (yyvsp[0].id);}
#line 3141 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: enum_specifier  */
#line 649 "./Parser/C_grammar.y"
                                        { decl_spec_stack->decl_spec.non_atomic = (yyvsp[0].id);}
#line 3147 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: typeof_specifier  */
#line 650 "./Parser/C_grammar.y"
                                        {;}
#line 3153 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: TYPEDEF_NAME  */
#line 652 "./Parser/C_grammar.y"
                {decl_spec_stack->decl_spec.non_atomic = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3161 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: INT128  */
#line 655 "./Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "int128");}
#line 3167 "C_grammar.tab.c"
    break;

  case 144: /* type_specifier: FLOAT128  */
#line 656 "./Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "float128");}
#line 3173 "C_grammar.tab.c"
    break;

  case 145: /* type_specifier: VA_LIST  */
#line 657 "./Parser/C_grammar.y"
                                                { simple_str_lit_copy(&decl_spec_stack->decl_spec.atomic.typeName, "va_list");}
#line 3179 "C_grammar.tab.c"
    break;

  case 146: /* $@5: %empty  */
#line 662 "./Parser/C_grammar.y"
             {in_ordinary_id_declaration = 0;}
#line 3185 "C_grammar.tab.c"
    break;

  case 148: /* $@6: %empty  */
#line 663 "./Parser/C_grammar.y"
                    {in_ordinary_id_declaration = 0;}
#line 3191 "C_grammar.tab.c"
    break;

  case 152: /* $@7: %empty  */
#line 671 "./Parser/C_grammar.y"
                              {in_tag_declaration = 0;}
#line 3197 "C_grammar.tab.c"
    break;

  case 153: /* struct_or_union_specifier: struct_or_union '{' $@7 '}'  */
#line 672 "./Parser/C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-3].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [])", (yyvsp[-3].id));
	     free((yyvsp[-3].id));
	    }
#line 3207 "C_grammar.tab.c"
    break;

  case 154: /* $@8: %empty  */
#line 677 "./Parser/C_grammar.y"
                              {in_tag_declaration = 0;}
#line 3213 "C_grammar.tab.c"
    break;

  case 155: /* struct_or_union_specifier: struct_or_union '{' $@8 struct_declaration_list '}'  */
#line 678 "./Parser/C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3224 "C_grammar.tab.c"
    break;

  case 156: /* $@9: %empty  */
#line 684 "./Parser/C_grammar.y"
                                          {in_tag_declaration = 0;}
#line 3230 "C_grammar.tab.c"
    break;

  case 157: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' $@9 '}'  */
#line 685 "./Parser/C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-3].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [])", (yyvsp[-4].id), tag_to_Prolog_var);
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free(tag_to_Prolog_var);
	    }
#line 3243 "C_grammar.tab.c"
    break;

  case 158: /* $@10: %empty  */
#line 693 "./Parser/C_grammar.y"
                                         {in_tag_declaration = 0;}
#line 3249 "C_grammar.tab.c"
    break;

  case 159: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' $@10 struct_declaration_list '}'  */
#line 694 "./Parser/C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3263 "C_grammar.tab.c"
    break;

  case 160: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 704 "./Parser/C_grammar.y"
                {in_tag_declaration = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3277 "C_grammar.tab.c"
    break;

  case 161: /* struct_or_union: STRUCT  */
#line 717 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_declaration = 1;
		}
#line 3285 "C_grammar.tab.c"
    break;

  case 162: /* struct_or_union: UNION  */
#line 721 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_declaration = 1;
		}
#line 3293 "C_grammar.tab.c"
    break;

  case 163: /* $@11: %empty  */
#line 727 "./Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 3299 "C_grammar.tab.c"
    break;

  case 164: /* struct_declaration_list: $@11 struct_declaration  */
#line 727 "./Parser/C_grammar.y"
                                                       {(yyval.id) = (yyvsp[0].id);}
#line 3305 "C_grammar.tab.c"
    break;

  case 165: /* $@12: %empty  */
#line 728 "./Parser/C_grammar.y"
                                  {push_decl_spec_stack();}
#line 3311 "C_grammar.tab.c"
    break;

  case 166: /* struct_declaration_list: struct_declaration_list $@12 struct_declaration  */
#line 729 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
	    }
#line 3322 "C_grammar.tab.c"
    break;

  case 167: /* struct_declaration: specifier_qualifier_list ';'  */
#line 739 "./Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("anonymous_member()") + strlen(decl_specifier) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", decl_specifier);
	   	 free(decl_specifier);
        }
#line 3333 "C_grammar.tab.c"
    break;

  case 168: /* $@13: %empty  */
#line 745 "./Parser/C_grammar.y"
                                   {in_member_namespace = 1;}
#line 3339 "C_grammar.tab.c"
    break;

  case 169: /* struct_declaration: specifier_qualifier_list $@13 struct_declarator_list ';'  */
#line 746 "./Parser/C_grammar.y"
                {in_member_namespace = 0;
		 char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("struct_decl(, [])") + strlen(decl_specifier) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl(%s, [%s])", decl_specifier, (yyvsp[-1].id));
	   	 free(decl_specifier);
		 free((yyvsp[-1].id));
        }
#line 3352 "C_grammar.tab.c"
    break;

  case 170: /* struct_declaration: static_assert_declaration  */
#line 755 "./Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);
		 pop_decl_spec_stack(); 
		}
#line 3360 "C_grammar.tab.c"
    break;

  case 175: /* $@14: %empty  */
#line 768 "./Parser/C_grammar.y"
          {in_member_namespace = 1;}
#line 3366 "C_grammar.tab.c"
    break;

  case 176: /* struct_declarator_list: $@14 struct_declarator  */
#line 769 "./Parser/C_grammar.y"
                {in_member_namespace = 1;
		 (yyval.id)= (yyvsp[0].id); 
		}
#line 3374 "C_grammar.tab.c"
    break;

  case 177: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 773 "./Parser/C_grammar.y"
                {in_member_namespace = 1; 
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3386 "C_grammar.tab.c"
    break;

  case 178: /* $@15: %empty  */
#line 783 "./Parser/C_grammar.y"
          {in_member_namespace = 0;}
#line 3392 "C_grammar.tab.c"
    break;

  case 179: /* struct_declarator: $@15 ':' constant_expression  */
#line 784 "./Parser/C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3402 "C_grammar.tab.c"
    break;

  case 180: /* $@16: %empty  */
#line 789 "./Parser/C_grammar.y"
                         {in_member_namespace = 0;}
#line 3408 "C_grammar.tab.c"
    break;

  case 181: /* struct_declarator: declarator ':' $@16 constant_expression  */
#line 790 "./Parser/C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3420 "C_grammar.tab.c"
    break;

  case 182: /* struct_declarator: declarator  */
#line 798 "./Parser/C_grammar.y"
                {(yyval.id) = strdup((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 in_member_namespace = 0;
		}
#line 3430 "C_grammar.tab.c"
    break;

  case 183: /* $@17: %empty  */
#line 806 "./Parser/C_grammar.y"
               {in_ordinary_id_declaration = 1;}
#line 3436 "C_grammar.tab.c"
    break;

  case 184: /* enum_specifier: ENUM $@17 '{' enumerator_list comma_opt '}'  */
#line 807 "./Parser/C_grammar.y"
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
#line 3454 "C_grammar.tab.c"
    break;

  case 185: /* $@18: %empty  */
#line 820 "./Parser/C_grammar.y"
               {in_tag_declaration = 1;}
#line 3460 "C_grammar.tab.c"
    break;

  case 186: /* $@19: %empty  */
#line 820 "./Parser/C_grammar.y"
                                                    {in_tag_declaration = 0; in_ordinary_id_declaration = 1;}
#line 3466 "C_grammar.tab.c"
    break;

  case 187: /* enum_specifier: ENUM $@18 IDENTIFIER $@19 enum_specifier_rest  */
#line 821 "./Parser/C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3478 "C_grammar.tab.c"
    break;

  case 188: /* enum_specifier_rest: %empty  */
#line 832 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3484 "C_grammar.tab.c"
    break;

  case 189: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 834 "./Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3490 "C_grammar.tab.c"
    break;

  case 190: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 836 "./Parser/C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3500 "C_grammar.tab.c"
    break;

  case 192: /* $@20: %empty  */
#line 845 "./Parser/C_grammar.y"
                              {in_ordinary_id_declaration = 1;}
#line 3506 "C_grammar.tab.c"
    break;

  case 193: /* enumerator_list: enumerator_list ',' $@20 enumerator  */
#line 846 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[0].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[0].id));
        }
#line 3517 "C_grammar.tab.c"
    break;

  case 194: /* $@21: %empty  */
#line 855 "./Parser/C_grammar.y"
                               {in_ordinary_id_declaration = 0;}
#line 3523 "C_grammar.tab.c"
    break;

  case 195: /* enumerator: enumeration_constant $@21 '=' constant_expression  */
#line 856 "./Parser/C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[0].id));
        }
#line 3534 "C_grammar.tab.c"
    break;

  case 198: /* type_qualifier: CONST  */
#line 870 "./Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isConst = true;}
#line 3540 "C_grammar.tab.c"
    break;

  case 199: /* type_qualifier: RESTRICT  */
#line 871 "./Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isRestrict = true;}
#line 3546 "C_grammar.tab.c"
    break;

  case 200: /* type_qualifier: VOLATILE  */
#line 872 "./Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isVolatile = true;}
#line 3552 "C_grammar.tab.c"
    break;

  case 201: /* type_qualifier: ATOMIC  */
#line 873 "./Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.qualifier.isAtomic= true;}
#line 3558 "C_grammar.tab.c"
    break;

  case 202: /* function_specifier: INLINE  */
#line 877 "./Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.function.isInLine = true;}
#line 3564 "C_grammar.tab.c"
    break;

  case 203: /* function_specifier: NORETURN  */
#line 878 "./Parser/C_grammar.y"
                        {decl_spec_stack->decl_spec.function.isNoReturn = true;}
#line 3570 "C_grammar.tab.c"
    break;

  case 204: /* alignment_specifier: ALIGNAS '(' type_name ')'  */
#line 883 "./Parser/C_grammar.y"
                {size_t const size = strlen("alignas()") + strlen((yyvsp[-1].id)) + 1;
	     decl_spec_stack->decl_spec.alignAs = (char*)malloc(size);
		 sprintf_safe(decl_spec_stack->decl_spec.alignAs, size, "alignas(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3580 "C_grammar.tab.c"
    break;

  case 205: /* alignment_specifier: ALIGNAS '(' constant_expression ')'  */
#line 889 "./Parser/C_grammar.y"
                {size_t const size = strlen("alignas()") + strlen((yyvsp[-1].id)) + 1;
	     decl_spec_stack->decl_spec.alignAs = (char*)malloc(size);
		 sprintf_safe(decl_spec_stack->decl_spec.alignAs, size, "alignas(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3590 "C_grammar.tab.c"
    break;

  case 206: /* declarator: pointer direct_declarator  */
#line 898 "./Parser/C_grammar.y"
          {size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3602 "C_grammar.tab.c"
    break;

  case 208: /* direct_declarator: IDENTIFIER  */
#line 910 "./Parser/C_grammar.y"
                {if (in_member_namespace) {	//this is a member (from a struct or union) no need to transform into a Prolog var
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
		 in_ordinary_id_declaration = 0;
		}
#line 3630 "C_grammar.tab.c"
    break;

  case 209: /* direct_declarator: TYPEDEF_NAME  */
#line 934 "./Parser/C_grammar.y"
                {char Prolog_var_name[MAX_ID_LENGTH+5];	//todo should use to_prolog_var($1);
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
#line 3649 "C_grammar.tab.c"
    break;

  case 210: /* direct_declarator: '(' declarator ')'  */
#line 950 "./Parser/C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-1].declarator_type);
		 in_ordinary_id_declaration = 0;
		}
#line 3657 "C_grammar.tab.c"
    break;

  case 211: /* $@22: %empty  */
#line 953 "./Parser/C_grammar.y"
                            {in_ordinary_id_declaration = 0;}
#line 3663 "C_grammar.tab.c"
    break;

  case 212: /* direct_declarator: direct_declarator $@22 rest_direct_declarator  */
#line 954 "./Parser/C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
		 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[0].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3675 "C_grammar.tab.c"
    break;

  case 213: /* $@23: %empty  */
#line 961 "./Parser/C_grammar.y"
                            {current_scope++; in_ordinary_id_declaration = 0;}
#line 3681 "C_grammar.tab.c"
    break;

  case 214: /* direct_declarator: direct_declarator $@23 '(' rest_function_definition ')'  */
#line 962 "./Parser/C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("function(, )") + strlen((yyvsp[-4].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-4].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-4].declarator_type).full);
	     free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 3695 "C_grammar.tab.c"
    break;

  case 215: /* rest_direct_declarator: '[' ']'  */
#line 975 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "int(0)"); 
		}
#line 3702 "C_grammar.tab.c"
    break;

  case 216: /* rest_direct_declarator: '[' assignment_expression ']'  */
#line 978 "./Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);
		}
#line 3709 "C_grammar.tab.c"
    break;

  case 217: /* rest_direct_declarator: '[' '*' ']'  */
#line 981 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D3"); 
		}
#line 3716 "C_grammar.tab.c"
    break;

  case 218: /* rest_direct_declarator: '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 984 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D4");
		}
#line 3723 "C_grammar.tab.c"
    break;

  case 219: /* rest_direct_declarator: '[' STATIC assignment_expression ']'  */
#line 987 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D5");
		}
#line 3730 "C_grammar.tab.c"
    break;

  case 220: /* rest_direct_declarator: '[' type_qualifier_list '*' ']'  */
#line 990 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D6");
		}
#line 3737 "C_grammar.tab.c"
    break;

  case 221: /* rest_direct_declarator: '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 993 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D7");
		}
#line 3744 "C_grammar.tab.c"
    break;

  case 222: /* rest_direct_declarator: '[' type_qualifier_list assignment_expression ']'  */
#line 996 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D8");
		}
#line 3751 "C_grammar.tab.c"
    break;

  case 223: /* rest_direct_declarator: '[' type_qualifier_list ']'  */
#line 999 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D9");
		}
#line 3758 "C_grammar.tab.c"
    break;

  case 224: /* rest_function_definition: %empty  */
#line 1005 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 3764 "C_grammar.tab.c"
    break;

  case 226: /* rest_function_definition: old_style_parameter_list  */
#line 1007 "./Parser/C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 3770 "C_grammar.tab.c"
    break;

  case 229: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1017 "./Parser/C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3780 "C_grammar.tab.c"
    break;

  case 230: /* parameter_type_list: parameter_list  */
#line 1023 "./Parser/C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3790 "C_grammar.tab.c"
    break;

  case 231: /* $@24: %empty  */
#line 1031 "./Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 3796 "C_grammar.tab.c"
    break;

  case 232: /* parameter_list: $@24 parameter_declaration  */
#line 1032 "./Parser/C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);
		}
#line 3803 "C_grammar.tab.c"
    break;

  case 233: /* $@25: %empty  */
#line 1034 "./Parser/C_grammar.y"
                             {push_decl_spec_stack();}
#line 3809 "C_grammar.tab.c"
    break;

  case 234: /* parameter_list: parameter_list ',' $@25 parameter_declaration  */
#line 1035 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 3820 "C_grammar.tab.c"
    break;

  case 235: /* parameter_declaration: type_declaration_specifiers declarator  */
#line 1045 "./Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("param(, )") + strlen(decl_specifier) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param(%s, %s)", decl_specifier, (yyvsp[0].declarator_type).full);
	     free(decl_specifier);
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 in_ordinary_id_declaration = 0; //not needed but added for safety
		}
#line 3834 "C_grammar.tab.c"
    break;

  case 236: /* parameter_declaration: type_declaration_specifiers abstract_declarator  */
#line 1055 "./Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("unnamed_param(, dummy_abstract_declarator)") + strlen(decl_specifier) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "unnamed_param(%s, dummy_abstract_declarator)", decl_specifier);
	     free(decl_specifier);
		 //free($2);
		 in_ordinary_id_declaration = 0;
		}
#line 3847 "C_grammar.tab.c"
    break;

  case 237: /* parameter_declaration: type_declaration_specifiers  */
#line 1064 "./Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("unnamed_param(, [])") + strlen(decl_specifier) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "unnamed_param(%s, [])", decl_specifier);
	     free(decl_specifier);
		 in_ordinary_id_declaration = 0;
		}
#line 3859 "C_grammar.tab.c"
    break;

  case 238: /* pointer: pointer_star pointer  */
#line 1076 "./Parser/C_grammar.y"
                {size_t const size = strlen("pointer(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3870 "C_grammar.tab.c"
    break;

  case 239: /* pointer: pointer_star  */
#line 1082 "./Parser/C_grammar.y"
                       {(yyval.id) = (yyvsp[0].id);}
#line 3876 "C_grammar.tab.c"
    break;

  case 240: /* $@26: %empty  */
#line 1086 "./Parser/C_grammar.y"
              {push_decl_spec_stack();}
#line 3882 "C_grammar.tab.c"
    break;

  case 241: /* pointer_star: '*' $@26 type_qualifier_list  */
#line 1087 "./Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("pointer()") + strlen(decl_specifier) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s)", decl_specifier);
	     free(decl_specifier);
		}
#line 3893 "C_grammar.tab.c"
    break;

  case 242: /* pointer_star: '*'  */
#line 1094 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3899 "C_grammar.tab.c"
    break;

  case 245: /* $@27: %empty  */
#line 1103 "./Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 3905 "C_grammar.tab.c"
    break;

  case 246: /* type_name: $@27 specifier_qualifier_list abstract_declarator_opt  */
#line 1104 "./Parser/C_grammar.y"
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
#line 3922 "C_grammar.tab.c"
    break;

  case 247: /* abstract_declarator_opt: %empty  */
#line 1119 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 3928 "C_grammar.tab.c"
    break;

  case 248: /* abstract_declarator_opt: abstract_declarator  */
#line 1120 "./Parser/C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 3934 "C_grammar.tab.c"
    break;

  case 273: /* initializer: '{' initializer_list '}'  */
#line 1156 "./Parser/C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3944 "C_grammar.tab.c"
    break;

  case 274: /* initializer: '{' initializer_list ',' '}'  */
#line 1162 "./Parser/C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3954 "C_grammar.tab.c"
    break;

  case 276: /* initializer: '{' '}'  */
#line 1169 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 3960 "C_grammar.tab.c"
    break;

  case 277: /* initializer_list: designation initializer  */
#line 1174 "./Parser/C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3971 "C_grammar.tab.c"
    break;

  case 279: /* initializer_list: initializer_list ',' designation initializer  */
#line 1182 "./Parser/C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3983 "C_grammar.tab.c"
    break;

  case 280: /* initializer_list: initializer_list ',' initializer  */
#line 1190 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3994 "C_grammar.tab.c"
    break;

  case 281: /* designation: designator_list '='  */
#line 1200 "./Parser/C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4004 "C_grammar.tab.c"
    break;

  case 283: /* designator_list: designator_list designator  */
#line 1210 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4015 "C_grammar.tab.c"
    break;

  case 284: /* designator: '[' constant_expression ']'  */
#line 1220 "./Parser/C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4025 "C_grammar.tab.c"
    break;

  case 285: /* $@28: %empty  */
#line 1225 "./Parser/C_grammar.y"
          {in_member_namespace = 1;}
#line 4031 "C_grammar.tab.c"
    break;

  case 286: /* designator: $@28 '.' IDENTIFIER  */
#line 1226 "./Parser/C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4042 "C_grammar.tab.c"
    break;

  case 287: /* $@29: %empty  */
#line 1235 "./Parser/C_grammar.y"
                        {in_ordinary_id_declaration = 0;}
#line 4048 "C_grammar.tab.c"
    break;

  case 288: /* static_assert_declaration: STATIC_ASSERT $@29 '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1236 "./Parser/C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4059 "C_grammar.tab.c"
    break;

  case 290: /* $@30: %empty  */
#line 1246 "./Parser/C_grammar.y"
          {current_scope++;}
#line 4065 "C_grammar.tab.c"
    break;

  case 291: /* statement: $@30 compound_statement  */
#line 1248 "./Parser/C_grammar.y"
          {pop_scope(&current_scope);
	   (yyval.id) = (yyvsp[0].id);
	  }
#line 4073 "C_grammar.tab.c"
    break;

  case 296: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1259 "./Parser/C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4084 "C_grammar.tab.c"
    break;

  case 297: /* labeled_statement: TYPEDEF_NAME ':' statement  */
#line 1267 "./Parser/C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4095 "C_grammar.tab.c"
    break;

  case 298: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1274 "./Parser/C_grammar.y"
          {size_t const size = strlen("case_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4106 "C_grammar.tab.c"
    break;

  case 299: /* labeled_statement: DEFAULT ':' statement  */
#line 1281 "./Parser/C_grammar.y"
          {size_t const size = strlen("default_stmt(branch(), )") + MAX_BRANCH_STR + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(branch(%d), %s)", branch_nb++, (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4116 "C_grammar.tab.c"
    break;

  case 300: /* compound_statement: '{' '}'  */
#line 1289 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4122 "C_grammar.tab.c"
    break;

  case 301: /* compound_statement: '{' block_item_list '}'  */
#line 1291 "./Parser/C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4132 "C_grammar.tab.c"
    break;

  case 302: /* $@31: %empty  */
#line 1299 "./Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 4138 "C_grammar.tab.c"
    break;

  case 303: /* block_item_list: $@31 block_item  */
#line 1299 "./Parser/C_grammar.y"
                                               {(yyval.id) = (yyvsp[0].id);}
#line 4144 "C_grammar.tab.c"
    break;

  case 304: /* $@32: %empty  */
#line 1300 "./Parser/C_grammar.y"
                          {push_decl_spec_stack();}
#line 4150 "C_grammar.tab.c"
    break;

  case 305: /* block_item_list: block_item_list $@32 block_item  */
#line 1301 "./Parser/C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4161 "C_grammar.tab.c"
    break;

  case 307: /* block_item: statement  */
#line 1311 "./Parser/C_grammar.y"
                    {pop_decl_spec_stack();}
#line 4167 "C_grammar.tab.c"
    break;

  case 308: /* expression_statement: ';'  */
#line 1315 "./Parser/C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4173 "C_grammar.tab.c"
    break;

  case 309: /* expression_statement: expression ';'  */
#line 1317 "./Parser/C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4183 "C_grammar.tab.c"
    break;

  case 310: /* selection_statement: IF '(' expression ')' statement else_opt  */
#line 1326 "./Parser/C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4195 "C_grammar.tab.c"
    break;

  case 311: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1334 "./Parser/C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id)); 
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4206 "C_grammar.tab.c"
    break;

  case 312: /* else_opt: %empty  */
#line 1343 "./Parser/C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4212 "C_grammar.tab.c"
    break;

  case 313: /* else_opt: ELSE statement  */
#line 1345 "./Parser/C_grammar.y"
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
#line 4246 "C_grammar.tab.c"
    break;

  case 314: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1378 "./Parser/C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4257 "C_grammar.tab.c"
    break;

  case 315: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1385 "./Parser/C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4268 "C_grammar.tab.c"
    break;

  case 316: /* iteration_statement: FOR '(' for_stmt_type ')' statement  */
#line 1392 "./Parser/C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4281 "C_grammar.tab.c"
    break;

  case 317: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1404 "./Parser/C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4287 "C_grammar.tab.c"
    break;

  case 318: /* $@33: %empty  */
#line 1405 "./Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 4293 "C_grammar.tab.c"
    break;

  case 319: /* for_stmt_type: $@33 declaration expression_opt ';' expression_opt  */
#line 1406 "./Parser/C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4299 "C_grammar.tab.c"
    break;

  case 320: /* expression_opt: %empty  */
#line 1410 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4305 "C_grammar.tab.c"
    break;

  case 322: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1415 "./Parser/C_grammar.y"
          {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4316 "C_grammar.tab.c"
    break;

  case 323: /* jump_statement: CONTINUE ';'  */
#line 1421 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4322 "C_grammar.tab.c"
    break;

  case 324: /* jump_statement: BREAK ';'  */
#line 1422 "./Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4328 "C_grammar.tab.c"
    break;

  case 325: /* jump_statement: RETURN ';'  */
#line 1423 "./Parser/C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4334 "C_grammar.tab.c"
    break;

  case 326: /* jump_statement: RETURN expression ';'  */
#line 1425 "./Parser/C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4344 "C_grammar.tab.c"
    break;

  case 327: /* $@34: %empty  */
#line 1434 "./Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 4350 "C_grammar.tab.c"
    break;

  case 329: /* $@35: %empty  */
#line 1435 "./Parser/C_grammar.y"
                           {fprintf(pl_file, ", \n"); push_decl_spec_stack();}
#line 4356 "C_grammar.tab.c"
    break;

  case 331: /* external_declaration: function_definition  */
#line 1440 "./Parser/C_grammar.y"
                {fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4364 "C_grammar.tab.c"
    break;

  case 332: /* external_declaration: declaration  */
#line 1444 "./Parser/C_grammar.y"
                {
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4373 "C_grammar.tab.c"
    break;

  case 333: /* function_definition: type_declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 1451 "./Parser/C_grammar.y"
                {char *decl_specifier = create_declaration_specifiers();
		 size_t const size = strlen("function(, , [], )") + strlen(decl_specifier) + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, %s, [%s], %s)", decl_specifier, (yyvsp[-2].declarator_type).full, (yyvsp[-1].id), (yyvsp[0].id));
		 if (debugMode) printf("function parsed\n");
	     free(decl_specifier);
		 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4389 "C_grammar.tab.c"
    break;

  case 334: /* declaration_list_opt: %empty  */
#line 1465 "./Parser/C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4395 "C_grammar.tab.c"
    break;

  case 336: /* $@36: %empty  */
#line 1470 "./Parser/C_grammar.y"
          {push_decl_spec_stack();}
#line 4401 "C_grammar.tab.c"
    break;

  case 337: /* old_style_declaration_list: $@36 declaration  */
#line 1470 "./Parser/C_grammar.y"
                                                {(yyval.id) = (yyvsp[0].id);}
#line 4407 "C_grammar.tab.c"
    break;

  case 338: /* $@37: %empty  */
#line 1471 "./Parser/C_grammar.y"
                                     {push_decl_spec_stack();}
#line 4413 "C_grammar.tab.c"
    break;

  case 339: /* old_style_declaration_list: old_style_declaration_list $@37 declaration  */
#line 1472 "./Parser/C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4424 "C_grammar.tab.c"
    break;


#line 4428 "C_grammar.tab.c"

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

#line 1480 "./Parser/C_grammar.y"

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
	fprintf(stdout, "Sikraken %s parser: using %i bits data model.\n", (debugMode) ? "in debug mode" : "", dataModel); 

	size_t i_path_len = strlen(C_file_path) + strlen(filename_no_ext) + 4; // "/.i\0"
	i_file_uri = malloc(i_path_len);
	snprintf(i_file_uri, i_path_len, "%s/%s.i", C_file_path, filename_no_ext);
	if (fopen_safe(&i_file, i_file_uri, "r") != 0) {
		fprintf(stderr, ".i file could not be opened for reading at: %s\n", i_file_uri);
		my_exit(EXIT_FAILURE);
	}
	yyin = i_file;	//set the input to the parser

	size_t pl_path_len = strlen(C_file_path) + strlen(filename_no_ext) + 5; // "/.pl\0"
	pl_file_uri = malloc(pl_path_len);
	snprintf(pl_file_uri, pl_path_len, "%s/%s.pl", C_file_path, filename_no_ext);
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
//  or if the .i file has been badly generated manually: i.e. during development
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

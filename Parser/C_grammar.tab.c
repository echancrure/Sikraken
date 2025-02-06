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
int check_for_typedef = 1;

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements
void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 126 "C_grammar.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    TYPEDEF_NAME = 259,            /* TYPEDEF_NAME  */
    I_CONSTANT = 260,              /* I_CONSTANT  */
    F_CONSTANT = 261,              /* F_CONSTANT  */
    ENUMERATION_CONSTANT = 262,    /* ENUMERATION_CONSTANT  */
    STRING_LITERAL = 263,          /* STRING_LITERAL  */
    FUNC_NAME = 264,               /* FUNC_NAME  */
    SIZEOF = 265,                  /* SIZEOF  */
    PTR_OP = 266,                  /* PTR_OP  */
    INC_OP = 267,                  /* INC_OP  */
    DEC_OP = 268,                  /* DEC_OP  */
    LEFT_OP = 269,                 /* LEFT_OP  */
    RIGHT_OP = 270,                /* RIGHT_OP  */
    LE_OP = 271,                   /* LE_OP  */
    GE_OP = 272,                   /* GE_OP  */
    EQ_OP = 273,                   /* EQ_OP  */
    NE_OP = 274,                   /* NE_OP  */
    AND_OP = 275,                  /* AND_OP  */
    OR_OP = 276,                   /* OR_OP  */
    MUL_ASSIGN = 277,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 278,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 279,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 280,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 281,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 282,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 283,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 284,              /* AND_ASSIGN  */
    XOR_ASSIGN = 285,              /* XOR_ASSIGN  */
    OR_ASSIGN = 286,               /* OR_ASSIGN  */
    TYPEDEF = 287,                 /* TYPEDEF  */
    EXTERN = 288,                  /* EXTERN  */
    STATIC = 289,                  /* STATIC  */
    AUTO = 290,                    /* AUTO  */
    REGISTER = 291,                /* REGISTER  */
    INLINE = 292,                  /* INLINE  */
    CONST = 293,                   /* CONST  */
    RESTRICT = 294,                /* RESTRICT  */
    VOLATILE = 295,                /* VOLATILE  */
    BOOL = 296,                    /* BOOL  */
    CHAR = 297,                    /* CHAR  */
    SHORT = 298,                   /* SHORT  */
    INT = 299,                     /* INT  */
    LONG = 300,                    /* LONG  */
    SIGNED = 301,                  /* SIGNED  */
    UNSIGNED = 302,                /* UNSIGNED  */
    FLOAT = 303,                   /* FLOAT  */
    DOUBLE = 304,                  /* DOUBLE  */
    VOID = 305,                    /* VOID  */
    COMPLEX = 306,                 /* COMPLEX  */
    IMAGINARY = 307,               /* IMAGINARY  */
    STRUCT = 308,                  /* STRUCT  */
    UNION = 309,                   /* UNION  */
    ENUM = 310,                    /* ENUM  */
    ELLIPSIS = 311,                /* ELLIPSIS  */
    CASE = 312,                    /* CASE  */
    DEFAULT = 313,                 /* DEFAULT  */
    IF = 314,                      /* IF  */
    ELSE = 315,                    /* ELSE  */
    SWITCH = 316,                  /* SWITCH  */
    WHILE = 317,                   /* WHILE  */
    DO = 318,                      /* DO  */
    FOR = 319,                     /* FOR  */
    GOTO = 320,                    /* GOTO  */
    CONTINUE = 321,                /* CONTINUE  */
    BREAK = 322,                   /* BREAK  */
    RETURN = 323,                  /* RETURN  */
    ALIGNAS = 324,                 /* ALIGNAS  */
    ALIGNOF = 325,                 /* ALIGNOF  */
    ATOMIC_SPECIFIER = 326,        /* ATOMIC_SPECIFIER  */
    ATOMIC = 327,                  /* ATOMIC  */
    GENERIC = 328,                 /* GENERIC  */
    NORETURN = 329,                /* NORETURN  */
    STATIC_ASSERT = 330,           /* STATIC_ASSERT  */
    THREAD_LOCAL = 331,            /* THREAD_LOCAL  */
    INT128 = 332,                  /* INT128  */
    FLOAT128 = 333,                /* FLOAT128  */
    VA_LIST = 334,                 /* VA_LIST  */
    LOWER_THAN_ELSE = 335          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 63 "C_grammar.y"

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

#line 266 "C_grammar.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_comma_opt = 114,                /* comma_opt  */
  YYSYMBOL_argument_expression_list = 115, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 116,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 117,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 118,           /* unary_operator  */
  YYSYMBOL_cast_expression = 119,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 120, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 121, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 122,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 123,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 124,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 125,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 126,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 127, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 128,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 129,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 130,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 131,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 132,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 133,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 134,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 135,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 136,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 137,      /* assignment_operator  */
  YYSYMBOL_expression = 138,               /* expression  */
  YYSYMBOL_constant_expression = 139,      /* constant_expression  */
  YYSYMBOL_declaration = 140,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 141,   /* declaration_specifiers  */
  YYSYMBOL_142_1 = 142,                    /* $@1  */
  YYSYMBOL_143_2 = 143,                    /* $@2  */
  YYSYMBOL_144_3 = 144,                    /* $@3  */
  YYSYMBOL_145_4 = 145,                    /* $@4  */
  YYSYMBOL_146_5 = 146,                    /* $@5  */
  YYSYMBOL_init_declarator_list = 147,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 148,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 149,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 150,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 151, /* struct_or_union_specifier  */
  YYSYMBOL_152_6 = 152,                    /* $@6  */
  YYSYMBOL_153_7 = 153,                    /* $@7  */
  YYSYMBOL_struct_or_union = 154,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 155,  /* struct_declaration_list  */
  YYSYMBOL_156_8 = 156,                    /* $@8  */
  YYSYMBOL_157_9 = 157,                    /* $@9  */
  YYSYMBOL_struct_declaration = 158,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 159, /* specifier_qualifier_list  */
  YYSYMBOL_160_10 = 160,                   /* $@10  */
  YYSYMBOL_161_11 = 161,                   /* $@11  */
  YYSYMBOL_struct_declarator_list = 162,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 163,        /* struct_declarator  */
  YYSYMBOL_164_12 = 164,                   /* $@12  */
  YYSYMBOL_struct_declarator2 = 165,       /* struct_declarator2  */
  YYSYMBOL_166_13 = 166,                   /* $@13  */
  YYSYMBOL_167_14 = 167,                   /* $@14  */
  YYSYMBOL_168_15 = 168,                   /* $@15  */
  YYSYMBOL_enum_specifier = 169,           /* enum_specifier  */
  YYSYMBOL_170_16 = 170,                   /* $@16  */
  YYSYMBOL_171_17 = 171,                   /* $@17  */
  YYSYMBOL_enum_specifier_rest = 172,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 173,          /* enumerator_list  */
  YYSYMBOL_enumerator = 174,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 175,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 176,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 177,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 178,      /* alignment_specifier  */
  YYSYMBOL_declarator = 179,               /* declarator  */
  YYSYMBOL_direct_declarator = 180,        /* direct_declarator  */
  YYSYMBOL_181_18 = 181,                   /* $@18  */
  YYSYMBOL_182_19 = 182,                   /* $@19  */
  YYSYMBOL_rest_function_definition = 183, /* rest_function_definition  */
  YYSYMBOL_pointer = 184,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 185,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 186,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 187,           /* parameter_list  */
  YYSYMBOL_188_20 = 188,                   /* $@20  */
  YYSYMBOL_parameter_declaration = 189,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 190,          /* identifier_list  */
  YYSYMBOL_type_name = 191,                /* type_name  */
  YYSYMBOL_192_21 = 192,                   /* $@21  */
  YYSYMBOL_abstract_declarator_opt = 193,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 194,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 195, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 196,              /* initializer  */
  YYSYMBOL_initializer_list = 197,         /* initializer_list  */
  YYSYMBOL_designation = 198,              /* designation  */
  YYSYMBOL_designator_list = 199,          /* designator_list  */
  YYSYMBOL_designator = 200,               /* designator  */
  YYSYMBOL_static_assert_declaration = 201, /* static_assert_declaration  */
  YYSYMBOL_202_22 = 202,                   /* $@22  */
  YYSYMBOL_statement = 203,                /* statement  */
  YYSYMBOL_labeled_statement = 204,        /* labeled_statement  */
  YYSYMBOL_205_23 = 205,                   /* $@23  */
  YYSYMBOL_206_24 = 206,                   /* $@24  */
  YYSYMBOL_compound_statement = 207,       /* compound_statement  */
  YYSYMBOL_208_25 = 208,                   /* $@25  */
  YYSYMBOL_block_item_list = 209,          /* block_item_list  */
  YYSYMBOL_210_26 = 210,                   /* $@26  */
  YYSYMBOL_block_item = 211,               /* block_item  */
  YYSYMBOL_expression_statement = 212,     /* expression_statement  */
  YYSYMBOL_selection_statement = 213,      /* selection_statement  */
  YYSYMBOL_214_27 = 214,                   /* $@27  */
  YYSYMBOL_215_28 = 215,                   /* $@28  */
  YYSYMBOL_else_opt = 216,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 217,      /* iteration_statement  */
  YYSYMBOL_218_29 = 218,                   /* $@29  */
  YYSYMBOL_219_30 = 219,                   /* $@30  */
  YYSYMBOL_220_31 = 220,                   /* $@31  */
  YYSYMBOL_for_stmt_type = 221,            /* for_stmt_type  */
  YYSYMBOL_222_32 = 222,                   /* $@32  */
  YYSYMBOL_expression_opt = 223,           /* expression_opt  */
  YYSYMBOL_jump_statement = 224,           /* jump_statement  */
  YYSYMBOL_translation_unit = 225,         /* translation_unit  */
  YYSYMBOL_226_33 = 226,                   /* $@33  */
  YYSYMBOL_external_declaration = 227,     /* external_declaration  */
  YYSYMBOL_function_definition = 228,      /* function_definition  */
  YYSYMBOL_229_34 = 229,                   /* $@34  */
  YYSYMBOL_declaration_list_opt = 230,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 231,         /* declaration_list  */
  YYSYMBOL_232_35 = 232                    /* $@35  */
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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2077

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  128
/* YYNRULES -- Number of rules.  */
#define YYNRULES  328
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  518

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
       0,   125,   125,   129,   130,   131,   137,   143,   147,   148,
     149,   153,   157,   158,   162,   166,   167,   171,   172,   176,
     177,   184,   190,   197,   204,   211,   217,   223,   240,   241,
     246,   247,   257,   258,   265,   272,   278,   284,   293,   294,
     298,   299,   300,   301,   302,   303,   307,   308,   318,   319,
     330,   331,   332,   336,   337,   348,   349,   353,   354,   365,
     366,   370,   371,   382,   383,   384,   385,   390,   391,   402,
     403,   407,   408,   418,   419,   429,   430,   440,   441,   451,
     452,   462,   463,   474,   475,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   500,   501,   511,   515,
     521,   539,   548,   548,   556,   557,   557,   565,   566,   566,
     574,   575,   575,   579,   583,   583,   587,   594,   595,   605,
     613,   623,   628,   629,   630,   631,   632,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   656,   657,   658,   662,   662,   669,   669,
     679,   692,   697,   705,   705,   706,   706,   716,   723,   730,
     734,   734,   742,   743,   743,   751,   755,   756,   766,   766,
     770,   770,   776,   776,   784,   784,   792,   805,   805,   805,
     816,   817,   819,   828,   829,   839,   846,   850,   854,   855,
     856,   857,   861,   862,   866,   867,   871,   879,   883,   907,
     907,   910,   917,   922,   927,   932,   937,   942,   947,   952,
     960,   960,   972,   973,   974,   978,   985,   991,   997,  1002,
    1003,  1013,  1019,  1028,  1029,  1029,  1039,  1047,  1054,  1063,
    1064,  1068,  1068,  1082,  1083,  1087,  1088,  1089,  1093,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1117,
    1123,  1129,  1130,  1135,  1142,  1143,  1151,  1161,  1170,  1171,
    1181,  1187,  1196,  1196,  1206,  1207,  1208,  1209,  1210,  1211,
    1215,  1232,  1232,  1239,  1239,  1248,  1249,  1249,  1258,  1259,
    1259,  1269,  1270,  1274,  1275,  1284,  1284,  1292,  1292,  1302,
    1303,  1311,  1311,  1318,  1318,  1325,  1325,  1337,  1339,  1339,
    1344,  1345,  1348,  1354,  1355,  1356,  1357,  1367,  1368,  1368,
    1372,  1373,  1377,  1377,  1390,  1391,  1395,  1396,  1396
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
  "postfix_expression", "comma_opt", "argument_expression_list",
  "unary_expression", "unary_inc_dec", "unary_operator", "cast_expression",
  "multiplicative_expression", "multiplicative_expression_op",
  "additive_expression", "additive_expression_op", "shift_expression",
  "shift_expression_op", "relational_expression",
  "relational_expression_operator", "equality_expression",
  "equality_expression_op", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers", "$@1",
  "$@2", "$@3", "$@4", "$@5", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "$@6", "$@7", "struct_or_union", "struct_declaration_list", "$@8", "$@9",
  "struct_declaration", "specifier_qualifier_list", "$@10", "$@11",
  "struct_declarator_list", "struct_declarator", "$@12",
  "struct_declarator2", "$@13", "$@14", "$@15", "enum_specifier", "$@16",
  "$@17", "enum_specifier_rest", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "$@18", "$@19",
  "rest_function_definition", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "$@20", "parameter_declaration",
  "identifier_list", "type_name", "$@21", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "$@22", "statement", "labeled_statement",
  "$@23", "$@24", "compound_statement", "$@25", "block_item_list", "$@26",
  "block_item", "expression_statement", "selection_statement", "$@27",
  "$@28", "else_opt", "iteration_statement", "$@29", "$@30", "$@31",
  "for_stmt_type", "$@32", "expression_opt", "jump_statement",
  "translation_unit", "$@33", "external_declaration",
  "function_definition", "$@34", "declaration_list_opt",
  "declaration_list", "$@35", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-447)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-211)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1789,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,   -67,   -36,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,   210,    26,   144,  -447,
      31,  -447,  -447,   190,   205,   241,  -447,    80,  -447,  -447,
      23,    67,  1342,     6,  1998,    44,  -447,    47,    -8,  -447,
     -68,  -447,   -55,   109,    50,  1894,  1894,    11,  -447,  1894,
    1894,  1894,  -447,  1789,  -447,    36,    65,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  1357,  -447,  -447,    85,   104,
    1194,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,   225,  -447,  1396,  1342,  -447,   -34,    95,   227,   124,
     201,    86,    97,   102,   191,    18,  -447,   132,   135,  -447,
     296,   -25,   304,  1342,  -447,  -447,  -447,    -8,    47,  -447,
    1210,  1789,   735,   149,   109,  -447,  -447,   157,  -447,  -447,
    -447,  -447,  -447,  1342,    23,   143,   159,  1194,  -447,  -447,
    1342,   200,   511,  -447,  -447,   167,   188,   197,   280,  -447,
    -447,  1249,  1342,   289,  1194,  -447,  -447,  -447,  -447,  -447,
    1342,  -447,  -447,  1342,  -447,  -447,  1342,  -447,  -447,  -447,
    -447,  1342,  -447,  -447,  1342,  1342,  1342,  1342,  1342,  1342,
    1342,  -447,  -447,  1998,  1520,   750,   125,  -447,  -447,   131,
    1998,   217,   211,  -447,  -447,  -447,   208,  1004,  -447,  -447,
    -447,   210,   215,  1789,  1063,  -447,   219,   231,   843,  1737,
    -447,  1574,  1946,  -447,  -447,  -447,    23,  -447,   236,   237,
     230,  -447,   517,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,  1342,  -447,  1342,  1303,  -447,  -447,
    -447,   173,  -447,    70,  -447,   239,  -447,   -34,    95,   227,
     124,   201,    86,    97,   102,   191,   175,  -447,  -447,   111,
     243,   244,  -447,   246,  1063,  -447,   245,   247,   858,   131,
    1684,   951,  -447,   321,  -447,  1342,   327,  -447,  -447,   -46,
    1210,    88,  -447,  -447,  -447,   249,  1063,  -447,  -447,  1342,
    -447,   250,   252,  -447,   257,  -447,   258,  1626,  -447,  -447,
     238,  -447,  -447,    94,   255,  -447,   288,   263,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,   347,   248,   251,   626,  -447,
     -39,  -447,  -447,  -447,  -447,   424,  -447,  -447,  -447,  -447,
    -447,  -447,  -447,  1156,  -447,  -447,  1342,  -447,   255,  1342,
    1460,  -447,    93,  -447,  -447,  1841,  -447,   265,  1063,  -447,
    -447,  1342,  -447,   270,  -447,   276,  1063,  -447,   273,   274,
     966,   281,   278,  -447,  1101,  -447,  -447,  -447,  -447,  -447,
    -447,   282,   284,  -447,  -447,  -447,   368,  -447,  -447,  -447,
     -37,  -447,    32,    16,  -447,   291,   179,  -447,   298,   610,
    1342,   299,   292,   303,   309,   610,   310,   290,  -447,  -447,
    -447,   -29,  -447,  -447,  -447,   313,  -447,  -447,  -447,  -447,
    -447,   306,   307,  -447,  -447,   312,  1063,  -447,  -447,  1342,
    -447,   315,   295,  -447,  -447,  -447,  1210,  -447,  -447,  -447,
    -447,  -447,  -447,  -447,   318,  -447,  1342,  -447,   288,  1342,
    -447,   319,   610,  1342,  1342,  1342,   342,   642,  -447,  -447,
    -447,  1156,   316,  -447,  -447,  -447,  -447,   320,   324,  -447,
    -447,  -447,  -447,  1342,   323,  -447,  -447,  -447,  -447,   610,
    -447,   181,   185,   194,   330,  1342,   332,  1789,  -447,  -447,
    -447,  -447,  1342,  -447,   610,   610,   610,  1342,   329,   311,
     610,  1342,  -447,   356,  -447,  -447,   202,  1342,  -447,   314,
     610,  -447,   331,  -447,  1342,  -447,  -447,  -447
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   142,   121,   122,   123,   125,   126,   192,   188,   189,
     190,   136,   128,   129,   130,   131,   134,   135,   132,   133,
     127,   137,   138,   151,   152,   177,     0,   231,   191,   193,
     272,   124,   143,   144,   145,   321,     0,   102,   105,   140,
       0,   141,   139,   108,   111,   114,   101,   318,   317,   320,
       0,     0,   231,     0,     0,     0,   198,     0,   218,    99,
       0,   117,   322,   197,     0,     0,     0,   150,   146,     0,
       0,     0,     1,     0,    11,   186,    28,   183,   178,     2,
       8,     9,    10,    12,    13,     0,    38,    39,     0,     0,
     231,    40,    41,    42,    43,    44,    45,    19,     3,     4,
       7,    32,    46,     0,     0,    48,    53,    57,    61,    67,
      71,    73,    75,    77,    79,    81,    98,     0,     0,   187,
     160,   233,   163,     0,   199,   219,   217,   216,     0,   100,
       0,   324,     0,     0,   196,   103,   106,     0,   153,   109,
     112,   115,   319,     0,    29,     0,   180,   231,    35,   231,
       0,   286,    46,    83,    96,     0,     0,     0,     0,    25,
      26,     0,     0,     0,   231,    33,    34,    50,    51,    52,
       0,    55,    56,     0,    59,    60,     0,    65,    66,    63,
      64,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,   195,   194,     0,     0,     0,   236,   232,   234,   237,
       0,     0,     0,   220,   215,   118,   120,     0,   261,   119,
     326,     0,     0,   325,     0,   201,    41,     0,     0,   212,
     153,     0,     0,   185,   184,   176,     0,   179,     0,     0,
       0,   285,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    85,     0,     6,     0,     0,     5,    24,
      21,     0,    30,     0,    23,     0,    49,    54,    58,    62,
      68,    72,    74,    76,    78,    80,     0,   161,   255,   228,
       0,   222,   223,     0,     0,   239,    41,     0,     0,   235,
       0,     0,   164,     0,   200,     0,     0,   262,   264,     0,
       0,     0,   268,   323,   327,     0,     0,   202,   209,     0,
     208,    41,     0,   229,     0,   213,   214,     0,   147,   155,
     168,   159,   154,     0,    36,    37,   231,     2,   281,   283,
     295,   297,   301,   303,   305,     0,     0,     0,     0,   293,
       0,   291,   292,   274,   275,     0,   288,   276,   277,   278,
     279,    84,    97,     0,    47,    22,     0,    20,     0,     0,
       0,   226,   236,   227,   256,     0,   238,     0,     0,   240,
     246,     0,   245,     0,   257,     0,     0,   247,    41,     0,
       0,     0,     0,   271,     0,   259,   263,   267,   269,   328,
     204,     0,     0,   205,   207,   211,     0,   149,   156,   157,
       0,   166,     0,     0,   181,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,   314,
     315,     0,   294,   287,   289,    28,    31,    82,   221,   224,
     242,     0,     0,   244,   258,     0,     0,   248,   254,     0,
     253,     0,     0,   270,   260,   266,     0,   203,   206,   230,
     168,   158,   170,   169,   174,   182,     0,    14,   231,     0,
     280,     0,     0,     0,     0,     0,     0,   308,   312,   316,
     290,    29,     0,   225,   241,   243,   250,     0,     0,   251,
     273,   265,   167,     0,     0,   175,    18,    16,    17,     0,
     284,     0,     0,     0,     0,   310,     0,     0,    27,   249,
     252,   171,     0,   282,     0,     0,     0,     0,   311,     0,
       0,   310,   173,   299,   298,   302,     0,   310,   306,     0,
       0,   296,     0,   307,   310,   300,   304,   309
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -447,  -447,  -447,  -447,  -447,  -447,  -447,   -31,  -447,     5,
    -447,   -52,  -447,  -447,   -84,   266,  -447,   262,  -447,   242,
    -447,   240,  -447,   259,  -447,   256,   260,   261,   254,  -447,
     -51,   -92,  -447,   -88,  -120,  -126,    24,  -447,  -447,  -447,
    -447,  -447,  -447,   297,  -447,   -42,  -447,  -447,  -447,  -447,
     226,  -447,  -447,   223,   -38,  -447,  -447,  -447,     8,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,   224,  -133,
    -447,   -50,  -447,  -447,   -30,   -57,  -447,  -447,  -447,   -48,
    -114,  -202,  -447,  -447,    96,  -447,    -5,  -447,  -447,  -108,
    -182,  -121,   110,  -349,  -447,   161,  -180,  -447,  -295,  -447,
    -447,  -447,   -63,  -447,  -447,  -447,   119,    -2,  -447,  -447,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -446,  -447,
    -447,  -447,   407,  -447,  -447,  -447,  -447,  -447
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    97,    98,    75,    99,   100,   396,   397,   101,   145,
     251,   152,   103,   104,   105,   106,   170,   107,   173,   108,
     176,   109,   181,   110,   184,   111,   112,   113,   114,   115,
     153,   154,   244,   330,   117,    35,   211,    65,    66,    69,
      70,    71,    60,    61,    37,    38,    39,   138,   137,    40,
     221,   222,   388,   309,   310,   193,   200,   390,   391,   392,
     443,   473,   474,   475,    41,    51,   146,   227,    76,    77,
      42,    43,    44,    45,   124,    63,   202,   133,   304,    64,
     127,   270,   271,   463,   272,   306,   398,    54,   197,   273,
     199,   288,   289,   290,   291,   292,    46,    55,   332,   333,
     400,   401,   334,   232,   335,   460,   336,   337,   338,   402,
     403,   511,   339,   404,   405,   406,   486,   487,   499,   340,
      47,    73,    48,    49,   131,   212,   213,   379
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     102,   116,   155,   201,   122,   210,    62,   134,   125,   209,
     126,   224,   120,   198,   279,   128,   121,   305,   218,    74,
     166,    50,    53,   223,    36,   436,    74,   157,  -120,  -104,
       8,     9,    10,   148,    67,    56,   129,   374,   208,   189,
     217,   311,   311,   375,   246,    52,   440,   118,   130,  -120,
      56,   165,   102,    56,   246,   509,   194,   167,   230,   155,
     195,   513,   168,   169,    28,   412,    58,   441,   517,   252,
      78,   102,   116,   196,   253,   459,   155,   203,   365,   204,
      72,   278,   125,    58,   157,   156,   256,   294,   119,   135,
     136,   102,   116,   139,   140,   141,    56,    36,   206,  -148,
     296,   157,   266,   277,   450,   445,   331,  -104,  -104,  -104,
     456,  -104,   436,    57,    56,   208,   442,  -104,   102,    68,
     190,   102,   295,    58,   102,   123,   302,   311,    57,   102,
    -104,    57,   102,   102,   102,   102,   102,   102,    58,   143,
     177,   178,   228,   122,   229,   125,   196,  -107,   144,   293,
     122,   120,   341,   246,   342,   267,   347,   480,   120,   255,
     358,   353,   282,   344,   125,   372,   149,   370,   203,   376,
     279,   122,   122,   285,   350,   286,   185,   393,   195,   120,
     120,   206,   357,   394,   493,   150,   363,   171,   172,   369,
    -210,   377,   350,  -110,   132,   102,   195,   186,   208,   503,
     504,   505,    58,   187,   381,   508,   194,   382,  -113,   331,
     195,   188,   280,    56,   191,   515,   281,   192,   269,   182,
     183,   352,   179,   180,   125,  -107,  -107,  -107,   203,  -107,
     219,   125,   225,   102,   116,  -107,   158,   159,   160,   351,
     411,   174,   175,   269,  -116,   220,   203,   226,  -107,   245,
     246,   208,   426,   435,   416,   345,   346,   122,   246,   349,
     224,   447,   448,   494,   246,   120,   421,   495,   246,   422,
     247,  -110,  -110,  -110,   425,  -110,   496,   246,   431,   248,
     451,  -110,   208,   249,   512,   246,  -113,  -113,  -113,   231,
    -113,    57,   254,   284,  -110,   134,  -113,   102,   417,  -162,
     283,    58,   352,   151,   269,   297,   161,  -165,   203,  -113,
     162,   130,   163,   316,    59,   471,   125,   298,   314,   315,
     203,   348,  -116,  -116,  -116,   354,  -116,   355,   356,   371,
     373,   359,  -116,   360,   467,   380,   383,   468,   384,   385,
     435,   386,   389,   343,   208,  -116,   395,   399,   102,   116,
     407,   420,   408,   491,   476,   409,   423,   478,   424,   427,
     428,   501,   444,   432,   433,   481,   482,   483,   437,   208,
     438,   439,   502,   453,   269,   446,   203,  -162,  -162,   269,
    -162,  -162,   449,   452,   454,  -165,  -165,  -162,  -165,  -165,
     455,   457,   464,   465,   458,  -165,   461,   498,   466,   470,
    -162,   469,  -172,   479,   484,   488,   489,   492,  -165,   506,
     490,   497,   246,   498,   500,   507,   510,   477,   514,   498,
     462,   102,   116,   259,   260,   205,   498,   317,     1,    80,
      81,    82,    83,    84,    85,   516,    86,    87,   258,   257,
     102,   116,   262,   265,   261,   312,   307,   263,   472,   264,
     313,   419,   378,   415,   414,   485,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     142,   318,   319,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,    26,    88,    27,    28,    89,    29,    30,
      31,    32,    33,    34,     0,    90,     0,     0,     0,     0,
       0,     0,   151,   413,    91,    92,    93,    94,    95,    96,
     317,     1,    80,    81,    82,    83,    84,    85,   329,    86,
      87,     0,     0,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,   318,   319,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,    26,    88,    27,    28,
      89,    29,    30,    31,    32,    33,    34,     0,    90,     0,
       0,     0,     0,     0,     0,   151,     0,    91,    92,    93,
      94,    95,    96,   317,   243,    80,    81,    82,    83,    84,
      85,   329,    86,    87,     0,     0,     0,     0,     0,    79,
       0,    80,    81,    82,    83,    84,    85,     0,    86,    87,
       0,     0,     0,     0,     0,    79,     0,    80,    81,    82,
      83,    84,    85,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   318,   319,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,     0,
      88,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,     0,    88,     0,   151,    89,
      91,    92,    93,    94,    95,    96,     0,    90,     0,     0,
       0,     0,    88,     0,   329,    89,    91,    92,    93,    94,
      95,    96,     0,    90,     0,     0,     0,     0,     0,     0,
     410,     0,    91,    92,    93,    94,    95,    96,    79,     0,
      80,    81,    82,    83,    84,    85,   329,    86,    87,     0,
       0,     0,     0,    79,     0,    80,    81,    82,    83,    84,
      85,     0,    86,    87,     0,     0,     0,     0,     0,   214,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,   274,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,    28,    89,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
      88,   215,    28,    89,     0,    91,   216,    93,    94,    95,
      96,    90,     0,     0,     0,     0,   275,     0,     0,     0,
      91,   276,    93,    94,    95,    96,    79,     0,    80,    81,
      82,    83,    84,    85,     0,    86,    87,     0,     0,     0,
       0,    79,     0,    80,    81,    82,    83,    84,    85,     0,
      86,    87,     0,     0,     0,     0,     0,   299,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,   361,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    28,    89,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,    88,   300,
      28,    89,     0,    91,   301,    93,    94,    95,    96,    90,
       0,     0,     0,     0,   362,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    79,     0,    80,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,     0,    79,
       0,    80,    81,    82,    83,    84,    85,     0,    86,    87,
       0,     0,     0,     0,     0,   366,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
     429,     0,     0,     0,     8,     9,    10,    79,     0,    80,
      81,    82,    83,    84,    85,     0,    86,    87,     0,     0,
       0,    88,     0,    28,    89,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,    88,   367,    28,    89,
       0,    91,   368,    93,    94,    95,    96,    90,     0,     0,
       0,     0,   430,     0,     0,     0,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,    79,     0,    80,    81,
      82,    83,    84,    85,    88,    86,    87,    89,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,   285,
       0,   286,   207,   287,    91,    92,    93,    94,    95,    96,
       0,     8,     9,    10,    79,     0,    80,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    28,    89,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    79,
       0,    80,    81,    82,    83,    84,    85,     0,    86,    87,
       0,    88,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,   285,     0,   286,   207,
     434,    91,    92,    93,    94,    95,    96,    79,     0,    80,
      81,    82,    83,    84,    85,     0,    86,    87,     0,     0,
       0,     0,     0,    79,     0,    80,    81,    82,    83,    84,
      85,     0,    86,    87,     0,     0,    88,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,   285,     0,   286,   207,     0,    91,    92,    93,    94,
      95,    96,    79,     0,    80,    81,    82,    83,    84,    85,
       0,    86,    87,     0,    88,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
      88,     0,   151,    89,    91,    92,    93,    94,    95,    96,
       0,    90,     0,     0,     0,     0,     0,     0,   207,     0,
      91,    92,    93,    94,    95,    96,    79,     0,    80,    81,
      82,    83,    84,    85,     0,    86,    87,     0,     0,    88,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
      90,   250,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    79,     0,    80,    81,    82,
      83,    84,    85,     0,    86,    87,     0,     0,     0,     0,
      79,     0,    80,    81,    82,    83,    84,    85,     0,    86,
      87,     0,     0,    88,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,   343,     0,    91,    92,    93,    94,    95,    96,    79,
       0,    80,    81,    82,    83,    84,    85,     0,    86,    87,
       0,     0,    88,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,    90,     0,     0,     0,    88,     0,     0,
      89,     0,    91,    92,    93,    94,    95,    96,   147,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     1,     0,    88,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,   164,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,     0,    31,    32,    33,    34,
       0,   350,   268,     0,     0,   195,     0,     0,     0,     0,
       0,    58,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,     0,    31,    32,    33,    34,
       0,   194,   268,     0,     0,   195,     0,     0,     0,     0,
       0,    58,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,    30,
       0,    32,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,    30,     0,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   387,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     303,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,    32,    33,    34,     0,     0,   364,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,    28,
       0,    29,     0,    31,    32,    33,    34,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,    28,     0,    29,    30,    31,    32,    33,    34,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   418,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,    28,     0,    29,     0,    31,    32,    33,
      34,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,    32,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,    30,     0,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,    32,    33,    34
};

static const yytype_int16 yycheck[] =
{
      52,    52,    90,   123,    54,   131,    36,    64,    58,   130,
      58,   144,    54,   121,   196,    83,    54,   219,   132,     3,
     104,    88,    27,   143,     0,   374,     3,    90,    83,     3,
      38,    39,    40,    85,     3,     3,   104,    83,   130,    21,
     132,   221,   222,    89,    83,    81,    83,    52,   103,   104,
       3,   103,   104,     3,    83,   501,    81,    91,   150,   147,
      85,   507,    96,    97,    72,   104,    91,   104,   514,   161,
       3,   123,   123,   121,   162,   104,   164,   127,   280,   127,
       0,   195,   132,    91,   147,    90,   170,   213,    82,    65,
      66,   143,   143,    69,    70,    71,     3,    73,   128,    88,
     214,   164,   190,   195,   399,    89,   232,    81,    82,    83,
     405,    85,   461,    81,     3,   207,    84,    91,   170,    88,
     102,   173,   214,    91,   176,    81,   218,   307,    81,   181,
     104,    81,   184,   185,   186,   187,   188,   189,    91,   103,
      16,    17,   147,   193,   149,   195,   194,     3,    83,   212,
     200,   193,   244,    83,   246,   193,    86,   452,   200,   164,
     274,   269,   200,   247,   214,   285,    81,   281,   218,   290,
     352,   221,   222,    85,    81,    87,    90,    83,    85,   221,
     222,   211,   274,    89,   479,    81,   278,    92,    93,   281,
      81,   103,    81,     3,    85,   247,    85,   100,   290,   494,
     495,   496,    91,   101,   296,   500,    81,   299,     3,   335,
      85,    20,    81,     3,    82,   510,    85,    82,   194,    18,
      19,   269,    98,    99,   274,    81,    82,    83,   278,    85,
      81,   281,    89,   285,   285,    91,    11,    12,    13,   269,
     328,    14,    15,   219,     3,    88,   296,    88,   104,    82,
      83,   343,   366,   374,   346,    82,    83,   307,    83,    84,
     393,    82,    83,    82,    83,   307,   358,    82,    83,   361,
      82,    81,    82,    83,   366,    85,    82,    83,   370,    82,
     400,    91,   374,     3,    82,    83,    81,    82,    83,    89,
      85,    81,     3,    82,   104,   352,    91,   349,   349,     3,
      83,    91,   350,    88,   280,    86,    81,     3,   358,   104,
      85,   103,    87,    83,   104,   436,   366,    86,    82,    82,
     370,    82,    81,    82,    83,    82,    85,    83,    82,     8,
       3,    86,    91,    86,   426,    86,    86,   429,    86,    82,
     461,    83,   104,    88,   436,   104,    58,    84,   400,   400,
       3,    86,   104,   473,   446,   104,    86,   449,    82,    86,
      86,   487,   392,    82,    86,   453,   454,   455,    86,   461,
      86,     3,   492,    81,   350,    84,   426,    81,    82,   355,
      84,    85,    84,    84,    81,    81,    82,    91,    84,    85,
      81,    81,    86,    86,   104,    91,    83,   485,    86,   104,
     104,    86,    84,    84,    62,    89,    86,    84,   104,   497,
      86,    81,    83,   501,    82,   104,    60,   448,   104,   507,
     415,   473,   473,   181,   184,   128,   514,     3,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,   176,   173,
     492,   492,   186,   189,   185,   222,   220,   187,   440,   188,
     226,   355,   291,   343,   335,   457,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      73,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
       3,     4,     5,     6,     7,     8,     9,    10,   104,    12,
      13,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    90,    91,    92,
      93,    94,    95,     3,   103,     5,     6,     7,     8,     9,
      10,   104,    12,    13,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    70,    -1,    88,    73,
      90,    91,    92,    93,    94,    95,    -1,    81,    -1,    -1,
      -1,    -1,    70,    -1,   104,    73,    90,    91,    92,    93,
      94,    95,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    90,    91,    92,    93,    94,    95,     3,    -1,
       5,     6,     7,     8,     9,    10,   104,    12,    13,    -1,
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
      34,    -1,    -1,    -1,    38,    39,    40,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    70,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    70,    86,    72,    73,
      -1,    90,    91,    92,    93,    94,    95,    81,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    70,    12,    13,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      -1,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    38,    39,    40,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      94,    95,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      70,    -1,    88,    73,    90,    91,    92,    93,    94,    95,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      90,    91,    92,    93,    94,    95,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    90,    91,    92,    93,    94,    95,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    70,    -1,    -1,
      73,    -1,    90,    91,    92,    93,    94,    95,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    81,    82,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    91,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    81,    82,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    91,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,
      -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    82,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,    77,    78,    79,   140,   141,   149,   150,   151,
     154,   169,   175,   176,   177,   178,   201,   225,   227,   228,
      88,   170,    81,   191,   192,   202,     3,    81,    91,   104,
     147,   148,   179,   180,   184,   142,   143,     3,    88,   144,
     145,   146,     0,   226,     3,   108,   173,   174,     3,     3,
       5,     6,     7,     8,     9,    10,    12,    13,    70,    73,
      81,    90,    91,    92,    93,    94,    95,   106,   107,   109,
     110,   113,   116,   117,   118,   119,   120,   122,   124,   126,
     128,   130,   131,   132,   133,   134,   135,   139,   191,    82,
     150,   159,   176,    81,   179,   176,   184,   185,    83,   104,
     103,   229,    85,   182,   180,   141,   141,   153,   152,   141,
     141,   141,   227,   103,    83,   114,   171,    81,   116,    81,
      81,    88,   116,   135,   136,   138,   191,   207,    11,    12,
      13,    81,    85,    87,    81,   116,   119,    91,    96,    97,
     121,    92,    93,   123,    14,    15,   125,    16,    17,    98,
      99,   127,    18,    19,   129,    90,   100,   101,    20,    21,
     102,    82,    82,   160,    81,    85,   184,   193,   194,   195,
     161,   139,   181,   176,   184,   148,   179,    88,   136,   196,
     140,   141,   230,   231,    34,    86,    91,   136,   185,    81,
      88,   155,   156,   139,   174,    89,    88,   172,   191,   191,
     136,    89,   208,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   103,   137,    82,    83,    82,    82,     3,
      82,   115,   136,   138,     3,   191,   119,   120,   122,   124,
     126,   128,   130,   131,   132,   133,   138,   159,    82,   141,
     186,   187,   189,   194,    34,    86,    91,   136,   185,   195,
      81,    85,   159,    83,    82,    85,    87,    89,   196,   197,
     198,   199,   200,   207,   140,   136,   185,    86,    86,    34,
      86,    91,   136,     3,   183,   186,   190,   155,    89,   158,
     159,   201,   158,   173,    82,    82,    83,     3,    57,    58,
      59,    61,    62,    63,    64,    65,    66,    67,    68,   104,
     138,   140,   203,   204,   207,   209,   211,   212,   213,   217,
     224,   136,   136,    88,   119,    82,    83,    86,    82,    84,
      81,   179,   184,   194,    82,    83,    82,   136,   185,    86,
      86,    34,    86,   136,    82,   186,    34,    86,    91,   136,
     185,     8,   139,     3,    83,    89,   196,   103,   200,   232,
      86,   136,   136,    86,    86,    82,    83,    89,   157,   104,
     162,   163,   164,    83,    89,    58,   111,   112,   191,    84,
     205,   206,   214,   215,   218,   219,   220,     3,   104,   104,
     104,   138,   104,    89,   211,   197,   136,   135,    56,   189,
      86,   136,   136,    86,    82,   136,   185,    86,    86,    34,
      86,   136,    82,    86,    89,   196,   198,    86,    86,     3,
      83,   104,    84,   165,   179,    89,    84,    82,    83,    84,
     203,   139,    84,    81,    81,    81,   203,    81,   104,   104,
     210,    83,   114,   188,    86,    86,    86,   136,   136,    86,
     104,   196,   163,   166,   167,   168,   136,   112,   136,    84,
     203,   138,   138,   138,    62,   212,   221,   222,    89,    86,
      86,   139,    84,   203,    82,    82,    82,    81,   138,   223,
      82,   140,   139,   203,   203,   203,   138,   104,   203,   223,
      60,   216,    82,   223,   104,   203,   104,   223
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   108,   109,   109,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   138,   138,   139,   140,
     140,   140,   142,   141,   141,   143,   141,   141,   144,   141,
     141,   145,   141,   141,   146,   141,   141,   147,   147,   148,
     148,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   152,   151,   153,   151,
     151,   154,   154,   156,   155,   157,   155,   158,   158,   158,
     160,   159,   159,   161,   159,   159,   162,   162,   164,   163,
     166,   165,   167,   165,   168,   165,   169,   170,   171,   169,
     172,   172,   172,   173,   173,   174,   174,   175,   176,   176,
     176,   176,   177,   177,   178,   178,   179,   179,   180,   181,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     182,   180,   183,   183,   183,   184,   184,   184,   184,   185,
     185,   186,   186,   187,   188,   187,   189,   189,   189,   190,
     190,   192,   191,   193,   193,   194,   194,   194,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   196,
     196,   196,   196,   197,   197,   197,   197,   198,   199,   199,
     200,   200,   202,   201,   203,   203,   203,   203,   203,   203,
     204,   205,   204,   206,   204,   207,   208,   207,   209,   210,
     209,   211,   211,   212,   212,   214,   213,   215,   213,   216,
     216,   218,   217,   219,   217,   220,   217,   221,   222,   221,
     223,   223,   224,   224,   224,   224,   224,   225,   226,   225,
     227,   227,   229,   228,   230,   230,   231,   232,   231
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     6,     1,     3,     3,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     7,     0,     1,
       1,     3,     1,     2,     2,     2,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     0,     3,     1,     0,     3,     1,     0,     3,
       1,     0,     3,     1,     0,     3,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     0,     6,
       2,     1,     1,     0,     2,     0,     3,     2,     3,     1,
       0,     3,     1,     0,     3,     1,     1,     3,     0,     2,
       0,     3,     0,     4,     0,     2,     5,     0,     0,     5,
       0,     3,     4,     1,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     4,     2,     1,     1,     0,
       4,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       0,     5,     0,     1,     1,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     0,     4,     2,     2,     1,     1,
       3,     0,     3,     0,     1,     2,     1,     1,     3,     2,
       3,     5,     4,     5,     4,     3,     3,     3,     4,     6,
       5,     5,     6,     4,     4,     2,     3,     3,     4,     3,
       4,     1,     2,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     0,     8,     1,     1,     1,     1,     1,     1,
       3,     0,     5,     0,     4,     2,     0,     4,     1,     0,
       3,     1,     1,     1,     2,     0,     7,     0,     6,     0,
       2,     0,     6,     0,     8,     0,     6,     4,     0,     5,
       0,     1,     3,     2,     2,     2,     3,     1,     0,     3,
       1,     1,     0,     5,     0,     1,     1,     0,     3
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
#line 126 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2479 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' compound_statement ')'  */
#line 132 "C_grammar.y"
                {size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2489 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' expression ')'  */
#line 138 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2499 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: generic_selection  */
#line 143 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2505 "C_grammar.tab.c"
    break;

  case 13: /* string: FUNC_NAME  */
#line 158 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2511 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 178 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2522 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' ')'  */
#line 185 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2532 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 191 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2543 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 198 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2554 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 205 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2565 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression INC_OP  */
#line 212 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2575 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression DEC_OP  */
#line 218 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2585 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 224 "C_grammar.y"
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
#line 2603 "C_grammar.tab.c"
    break;

  case 28: /* comma_opt: %empty  */
#line 240 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2609 "C_grammar.tab.c"
    break;

  case 29: /* comma_opt: ','  */
#line 241 "C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2615 "C_grammar.tab.c"
    break;

  case 31: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 248 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2626 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_inc_dec unary_expression  */
#line 259 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2637 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: unary_operator cast_expression  */
#line 266 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2648 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF unary_expression  */
#line 273 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2658 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 279 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2668 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 285 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2678 "C_grammar.tab.c"
    break;

  case 38: /* unary_inc_dec: INC_OP  */
#line 293 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2684 "C_grammar.tab.c"
    break;

  case 39: /* unary_inc_dec: DEC_OP  */
#line 294 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2690 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '&'  */
#line 298 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2696 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '*'  */
#line 299 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2702 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '+'  */
#line 300 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2708 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '-'  */
#line 301 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2714 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '~'  */
#line 302 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2720 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '!'  */
#line 303 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2726 "C_grammar.tab.c"
    break;

  case 47: /* cast_expression: '(' type_name ')' cast_expression  */
#line 309 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2737 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 320 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2749 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '*'  */
#line 330 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2755 "C_grammar.tab.c"
    break;

  case 51: /* multiplicative_expression_op: '/'  */
#line 331 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2761 "C_grammar.tab.c"
    break;

  case 52: /* multiplicative_expression_op: '%'  */
#line 332 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2767 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 338 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2779 "C_grammar.tab.c"
    break;

  case 55: /* additive_expression_op: '+'  */
#line 348 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2785 "C_grammar.tab.c"
    break;

  case 56: /* additive_expression_op: '-'  */
#line 349 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2791 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 355 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2803 "C_grammar.tab.c"
    break;

  case 59: /* shift_expression_op: LEFT_OP  */
#line 365 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2809 "C_grammar.tab.c"
    break;

  case 60: /* shift_expression_op: RIGHT_OP  */
#line 366 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2815 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 372 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2827 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: '<'  */
#line 382 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2833 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: '>'  */
#line 383 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2839 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression_operator: LE_OP  */
#line 384 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2845 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression_operator: GE_OP  */
#line 385 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2851 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 392 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2863 "C_grammar.tab.c"
    break;

  case 69: /* equality_expression_op: EQ_OP  */
#line 402 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2869 "C_grammar.tab.c"
    break;

  case 70: /* equality_expression_op: NE_OP  */
#line 403 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2875 "C_grammar.tab.c"
    break;

  case 72: /* and_expression: and_expression '&' equality_expression  */
#line 409 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2886 "C_grammar.tab.c"
    break;

  case 74: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 420 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2897 "C_grammar.tab.c"
    break;

  case 76: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 431 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2908 "C_grammar.tab.c"
    break;

  case 78: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 442 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2919 "C_grammar.tab.c"
    break;

  case 80: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 453 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2930 "C_grammar.tab.c"
    break;

  case 82: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 464 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2942 "C_grammar.tab.c"
    break;

  case 84: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 476 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2954 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: '='  */
#line 486 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2960 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: MUL_ASSIGN  */
#line 487 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2966 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: DIV_ASSIGN  */
#line 488 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2972 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: MOD_ASSIGN  */
#line 489 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2978 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: ADD_ASSIGN  */
#line 490 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2984 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: SUB_ASSIGN  */
#line 491 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2990 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: LEFT_ASSIGN  */
#line 492 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2996 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: RIGHT_ASSIGN  */
#line 493 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 3002 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: AND_ASSIGN  */
#line 494 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 3008 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: XOR_ASSIGN  */
#line 495 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3014 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: OR_ASSIGN  */
#line 496 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3020 "C_grammar.tab.c"
    break;

  case 97: /* expression: expression ',' assignment_expression  */
#line 502 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3031 "C_grammar.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers ';'  */
#line 516 "C_grammar.y"
                {size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3041 "C_grammar.tab.c"
    break;

  case 100: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 522 "C_grammar.y"
                {/*if (strstr($1, "typedef") != NULL) {
			typedef_flag = 0; 
			if (debugMode) printf("Debug: typedef switched to 0 on declaration([%s], [%s])\n", $1, $2);
		 }
		 */
		 
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
#line 3063 "C_grammar.tab.c"
    break;

  case 101: /* declaration: static_assert_declaration  */
#line 540 "C_grammar.y"
                {size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3073 "C_grammar.tab.c"
    break;

  case 102: /* $@1: %empty  */
#line 548 "C_grammar.y"
                                  {printf("check_for_typedef after storage_class_specifier is %d\n", check_for_typedef); check_for_typedef = 1;}
#line 3079 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: storage_class_specifier $@1 declaration_specifiers  */
#line 549 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3091 "C_grammar.tab.c"
    break;

  case 104: /* declaration_specifiers: storage_class_specifier  */
#line 556 "C_grammar.y"
                                  {check_for_typedef = 0;}
#line 3097 "C_grammar.tab.c"
    break;

  case 105: /* $@2: %empty  */
#line 557 "C_grammar.y"
                         {printf("declaration_specifiers is %s on line %d\n", (yyvsp[0].id), yylineno); check_for_typedef = 1;}
#line 3103 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: type_specifier $@2 declaration_specifiers  */
#line 558 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3115 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: type_specifier  */
#line 565 "C_grammar.y"
                         {printf("declaration_specifiers is simple type_specifier %s on line %d\n", (yyvsp[0].id), yylineno); check_for_typedef = 0;}
#line 3121 "C_grammar.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 566 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3127 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: type_qualifier $@3 declaration_specifiers  */
#line 567 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3139 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: type_qualifier  */
#line 574 "C_grammar.y"
                         {check_for_typedef = 0;}
#line 3145 "C_grammar.tab.c"
    break;

  case 111: /* $@4: %empty  */
#line 575 "C_grammar.y"
                             {check_for_typedef = 1;}
#line 3151 "C_grammar.tab.c"
    break;

  case 112: /* declaration_specifiers: function_specifier $@4 declaration_specifiers  */
#line 576 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); 
		}
#line 3159 "C_grammar.tab.c"
    break;

  case 113: /* declaration_specifiers: function_specifier  */
#line 580 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); 
		}
#line 3167 "C_grammar.tab.c"
    break;

  case 114: /* $@5: %empty  */
#line 583 "C_grammar.y"
                              {check_for_typedef = 1;}
#line 3173 "C_grammar.tab.c"
    break;

  case 115: /* declaration_specifiers: alignment_specifier $@5 declaration_specifiers  */
#line 584 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); 
		}
#line 3181 "C_grammar.tab.c"
    break;

  case 116: /* declaration_specifiers: alignment_specifier  */
#line 588 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); 
		}
#line 3189 "C_grammar.tab.c"
    break;

  case 118: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 596 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3200 "C_grammar.tab.c"
    break;

  case 119: /* init_declarator: declarator '=' initializer  */
#line 606 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));		//todo why is this commented out?
	  	}
#line 3212 "C_grammar.tab.c"
    break;

  case 120: /* init_declarator: declarator  */
#line 614 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_name((yyvsp[0].declarator_type).ptr_declarator);	
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3223 "C_grammar.tab.c"
    break;

  case 121: /* storage_class_specifier: TYPEDEF  */
#line 624 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3232 "C_grammar.tab.c"
    break;

  case 122: /* storage_class_specifier: EXTERN  */
#line 628 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3238 "C_grammar.tab.c"
    break;

  case 123: /* storage_class_specifier: STATIC  */
#line 629 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3244 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: THREAD_LOCAL  */
#line 630 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3250 "C_grammar.tab.c"
    break;

  case 125: /* storage_class_specifier: AUTO  */
#line 631 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3256 "C_grammar.tab.c"
    break;

  case 126: /* storage_class_specifier: REGISTER  */
#line 632 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3262 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: VOID  */
#line 636 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "void"); }
#line 3268 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: CHAR  */
#line 637 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "char"); }
#line 3274 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: SHORT  */
#line 638 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "short"); }
#line 3280 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: INT  */
#line 639 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "int"); }
#line 3286 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: LONG  */
#line 640 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "long"); }
#line 3292 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: FLOAT  */
#line 641 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "float"); }
#line 3298 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: DOUBLE  */
#line 642 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "double"); }
#line 3304 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: SIGNED  */
#line 643 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3310 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: UNSIGNED  */
#line 644 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3316 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: BOOL  */
#line 645 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3322 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: COMPLEX  */
#line 646 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3328 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: IMAGINARY  */
#line 647 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3334 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: atomic_type_specifier  */
#line 648 "C_grammar.y"
                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3340 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: struct_or_union_specifier  */
#line 649 "C_grammar.y"
                                    { check_for_typedef = 0; }
#line 3346 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: enum_specifier  */
#line 650 "C_grammar.y"
                                        { check_for_typedef = 0; }
#line 3352 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: TYPEDEF_NAME  */
#line 652 "C_grammar.y"
                {check_for_typedef = 0; 
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3361 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: INT128  */
#line 656 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "int128"); }
#line 3367 "C_grammar.tab.c"
    break;

  case 144: /* type_specifier: FLOAT128  */
#line 657 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "float128"); }
#line 3373 "C_grammar.tab.c"
    break;

  case 145: /* type_specifier: VA_LIST  */
#line 658 "C_grammar.y"
                                                { check_for_typedef = 0; simple_str_lit_copy(&(yyval.id), "va_list"); }
#line 3379 "C_grammar.tab.c"
    break;

  case 146: /* $@6: %empty  */
#line 662 "C_grammar.y"
                              {in_tag_namespace = 0;}
#line 3385 "C_grammar.tab.c"
    break;

  case 147: /* struct_or_union_specifier: struct_or_union '{' $@6 struct_declaration_list '}'  */
#line 663 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3396 "C_grammar.tab.c"
    break;

  case 148: /* $@7: %empty  */
#line 669 "C_grammar.y"
                                     {in_tag_namespace = 0;}
#line 3402 "C_grammar.tab.c"
    break;

  case 149: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@7 '{' struct_declaration_list '}'  */
#line 670 "C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3416 "C_grammar.tab.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 680 "C_grammar.y"
                {in_tag_namespace = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3430 "C_grammar.tab.c"
    break;

  case 151: /* struct_or_union: STRUCT  */
#line 693 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_namespace = 1;
		}
#line 3439 "C_grammar.tab.c"
    break;

  case 152: /* struct_or_union: UNION  */
#line 698 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_namespace = 1;
		}
#line 3448 "C_grammar.tab.c"
    break;

  case 153: /* $@8: %empty  */
#line 705 "C_grammar.y"
          {check_for_typedef = 1;}
#line 3454 "C_grammar.tab.c"
    break;

  case 154: /* struct_declaration_list: $@8 struct_declaration  */
#line 705 "C_grammar.y"
                                                      {(yyval.id) = (yyvsp[0].id); check_for_typedef = 1;}
#line 3460 "C_grammar.tab.c"
    break;

  case 155: /* $@9: %empty  */
#line 706 "C_grammar.y"
                                                     {check_for_typedef = 1;}
#line 3466 "C_grammar.tab.c"
    break;

  case 156: /* struct_declaration_list: struct_declaration_list struct_declaration $@9  */
#line 707 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	    }
#line 3477 "C_grammar.tab.c"
    break;

  case 157: /* struct_declaration: specifier_qualifier_list ';'  */
#line 717 "C_grammar.y"
                {size_t const size = strlen("anonymous_member()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3487 "C_grammar.tab.c"
    break;

  case 158: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 724 "C_grammar.y"
                {size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
	   	 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
        }
#line 3498 "C_grammar.tab.c"
    break;

  case 160: /* $@10: %empty  */
#line 734 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3504 "C_grammar.tab.c"
    break;

  case 161: /* specifier_qualifier_list: type_specifier $@10 specifier_qualifier_list  */
#line 735 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3516 "C_grammar.tab.c"
    break;

  case 162: /* specifier_qualifier_list: type_specifier  */
#line 742 "C_grammar.y"
                         {check_for_typedef = 0;}
#line 3522 "C_grammar.tab.c"
    break;

  case 163: /* $@11: %empty  */
#line 743 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3528 "C_grammar.tab.c"
    break;

  case 164: /* specifier_qualifier_list: type_qualifier $@11 specifier_qualifier_list  */
#line 744 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3540 "C_grammar.tab.c"
    break;

  case 165: /* specifier_qualifier_list: type_qualifier  */
#line 751 "C_grammar.y"
                         {check_for_typedef = 0;}
#line 3546 "C_grammar.tab.c"
    break;

  case 167: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 757 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3557 "C_grammar.tab.c"
    break;

  case 168: /* $@12: %empty  */
#line 766 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3563 "C_grammar.tab.c"
    break;

  case 169: /* struct_declarator: $@12 struct_declarator2  */
#line 767 "C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);}
#line 3569 "C_grammar.tab.c"
    break;

  case 170: /* $@13: %empty  */
#line 770 "C_grammar.y"
              {in_member_namespace = 0;}
#line 3575 "C_grammar.tab.c"
    break;

  case 171: /* struct_declarator2: ':' $@13 constant_expression  */
#line 771 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3585 "C_grammar.tab.c"
    break;

  case 172: /* $@14: %empty  */
#line 776 "C_grammar.y"
                     {in_member_namespace = 0;}
#line 3591 "C_grammar.tab.c"
    break;

  case 173: /* struct_declarator2: declarator $@14 ':' constant_expression  */
#line 777 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3603 "C_grammar.tab.c"
    break;

  case 174: /* $@15: %empty  */
#line 784 "C_grammar.y"
                      {in_member_namespace = 0;}
#line 3609 "C_grammar.tab.c"
    break;

  case 175: /* struct_declarator2: declarator $@15  */
#line 785 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[-1].declarator_type).full);
		 free((yyvsp[-1].declarator_type).full);
		 free((yyvsp[-1].declarator_type).ptr_declarator);
		}
#line 3618 "C_grammar.tab.c"
    break;

  case 176: /* enum_specifier: ENUM '{' enumerator_list comma_opt '}'  */
#line 793 "C_grammar.y"
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
#line 3635 "C_grammar.tab.c"
    break;

  case 177: /* $@16: %empty  */
#line 805 "C_grammar.y"
               {in_tag_namespace = 1;}
#line 3641 "C_grammar.tab.c"
    break;

  case 178: /* $@17: %empty  */
#line 805 "C_grammar.y"
                                                  {in_tag_namespace = 0;}
#line 3647 "C_grammar.tab.c"
    break;

  case 179: /* enum_specifier: ENUM $@16 IDENTIFIER $@17 enum_specifier_rest  */
#line 806 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3658 "C_grammar.tab.c"
    break;

  case 180: /* enum_specifier_rest: %empty  */
#line 816 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3664 "C_grammar.tab.c"
    break;

  case 181: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 818 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3670 "C_grammar.tab.c"
    break;

  case 182: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 820 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3680 "C_grammar.tab.c"
    break;

  case 184: /* enumerator_list: enumerator_list ',' enumerator  */
#line 830 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3691 "C_grammar.tab.c"
    break;

  case 185: /* enumerator: enumeration_constant '=' constant_expression  */
#line 840 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3702 "C_grammar.tab.c"
    break;

  case 188: /* type_qualifier: CONST  */
#line 854 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3708 "C_grammar.tab.c"
    break;

  case 189: /* type_qualifier: RESTRICT  */
#line 855 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3714 "C_grammar.tab.c"
    break;

  case 190: /* type_qualifier: VOLATILE  */
#line 856 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3720 "C_grammar.tab.c"
    break;

  case 191: /* type_qualifier: ATOMIC  */
#line 857 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3726 "C_grammar.tab.c"
    break;

  case 192: /* function_specifier: INLINE  */
#line 861 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3732 "C_grammar.tab.c"
    break;

  case 193: /* function_specifier: NORETURN  */
#line 862 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3738 "C_grammar.tab.c"
    break;

  case 196: /* declarator: pointer direct_declarator  */
#line 872 "C_grammar.y"
          {size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3750 "C_grammar.tab.c"
    break;

  case 198: /* direct_declarator: IDENTIFIER  */
#line 884 "C_grammar.y"
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
#line 3778 "C_grammar.tab.c"
    break;

  case 199: /* $@18: %empty  */
#line 907 "C_grammar.y"
                         {in_member_namespace = 0;}
#line 3784 "C_grammar.tab.c"
    break;

  case 200: /* direct_declarator: '(' declarator $@18 ')'  */
#line 909 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-2].declarator_type);}
#line 3790 "C_grammar.tab.c"
    break;

  case 201: /* direct_declarator: direct_declarator '[' ']'  */
#line 911 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3801 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 918 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3810 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 923 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3819 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 928 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3828 "C_grammar.tab.c"
    break;

  case 205: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 933 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3837 "C_grammar.tab.c"
    break;

  case 206: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 938 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3846 "C_grammar.tab.c"
    break;

  case 207: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 943 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3855 "C_grammar.tab.c"
    break;

  case 208: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 948 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3864 "C_grammar.tab.c"
    break;

  case 209: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 953 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3876 "C_grammar.tab.c"
    break;

  case 210: /* $@19: %empty  */
#line 960 "C_grammar.y"
                            {check_for_typedef = 1;}
#line 3882 "C_grammar.tab.c"
    break;

  case 211: /* direct_declarator: direct_declarator $@19 '(' rest_function_definition ')'  */
#line 961 "C_grammar.y"
                {size_t const size = strlen("function(, )") + strlen((yyvsp[-4].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-4].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-4].declarator_type).full);
	     free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 3895 "C_grammar.tab.c"
    break;

  case 212: /* rest_function_definition: %empty  */
#line 972 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 3901 "C_grammar.tab.c"
    break;

  case 214: /* rest_function_definition: identifier_list  */
#line 974 "C_grammar.y"
                          {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 3907 "C_grammar.tab.c"
    break;

  case 215: /* pointer: '*' type_qualifier_list pointer  */
#line 979 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3918 "C_grammar.tab.c"
    break;

  case 216: /* pointer: '*' type_qualifier_list  */
#line 986 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3928 "C_grammar.tab.c"
    break;

  case 217: /* pointer: '*' pointer  */
#line 992 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3938 "C_grammar.tab.c"
    break;

  case 218: /* pointer: '*'  */
#line 998 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3944 "C_grammar.tab.c"
    break;

  case 220: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1004 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3955 "C_grammar.tab.c"
    break;

  case 221: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1014 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3965 "C_grammar.tab.c"
    break;

  case 222: /* parameter_type_list: parameter_list  */
#line 1020 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3975 "C_grammar.tab.c"
    break;

  case 223: /* parameter_list: parameter_declaration  */
#line 1028 "C_grammar.y"
                                {check_for_typedef = 1; printf("IN single parameter_list on line %d\n", yylineno);}
#line 3981 "C_grammar.tab.c"
    break;

  case 224: /* $@20: %empty  */
#line 1029 "C_grammar.y"
                                                   {check_for_typedef = 1;}
#line 3987 "C_grammar.tab.c"
    break;

  case 225: /* parameter_list: parameter_list ',' parameter_declaration $@20  */
#line 1030 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 3998 "C_grammar.tab.c"
    break;

  case 226: /* parameter_declaration: declaration_specifiers declarator  */
#line 1040 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 4010 "C_grammar.tab.c"
    break;

  case 227: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1048 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 4021 "C_grammar.tab.c"
    break;

  case 228: /* parameter_declaration: declaration_specifiers  */
#line 1055 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 4031 "C_grammar.tab.c"
    break;

  case 231: /* $@21: %empty  */
#line 1068 "C_grammar.y"
          {check_for_typedef = 1;}
#line 4037 "C_grammar.tab.c"
    break;

  case 232: /* type_name: $@21 specifier_qualifier_list abstract_declarator_opt  */
#line 1069 "C_grammar.y"
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
#line 4052 "C_grammar.tab.c"
    break;

  case 233: /* abstract_declarator_opt: %empty  */
#line 1082 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4058 "C_grammar.tab.c"
    break;

  case 234: /* abstract_declarator_opt: abstract_declarator  */
#line 1083 "C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 4064 "C_grammar.tab.c"
    break;

  case 259: /* initializer: '{' initializer_list '}'  */
#line 1118 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4074 "C_grammar.tab.c"
    break;

  case 260: /* initializer: '{' initializer_list ',' '}'  */
#line 1124 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 4084 "C_grammar.tab.c"
    break;

  case 262: /* initializer: '{' '}'  */
#line 1131 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 4090 "C_grammar.tab.c"
    break;

  case 263: /* initializer_list: designation initializer  */
#line 1136 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4101 "C_grammar.tab.c"
    break;

  case 265: /* initializer_list: initializer_list ',' designation initializer  */
#line 1144 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4113 "C_grammar.tab.c"
    break;

  case 266: /* initializer_list: initializer_list ',' initializer  */
#line 1152 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4124 "C_grammar.tab.c"
    break;

  case 267: /* designation: designator_list '='  */
#line 1162 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4134 "C_grammar.tab.c"
    break;

  case 269: /* designator_list: designator_list designator  */
#line 1172 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4145 "C_grammar.tab.c"
    break;

  case 270: /* designator: '[' constant_expression ']'  */
#line 1182 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4155 "C_grammar.tab.c"
    break;

  case 271: /* designator: '.' IDENTIFIER  */
#line 1188 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4165 "C_grammar.tab.c"
    break;

  case 272: /* $@22: %empty  */
#line 1196 "C_grammar.y"
                        {check_for_typedef = 0;}
#line 4171 "C_grammar.tab.c"
    break;

  case 273: /* static_assert_declaration: STATIC_ASSERT $@22 '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1197 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4182 "C_grammar.tab.c"
    break;

  case 280: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1216 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4193 "C_grammar.tab.c"
    break;

  case 281: /* $@23: %empty  */
#line 1232 "C_grammar.y"
               {check_for_typedef = 0;}
#line 4199 "C_grammar.tab.c"
    break;

  case 282: /* labeled_statement: CASE $@23 constant_expression ':' statement  */
#line 1233 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4210 "C_grammar.tab.c"
    break;

  case 283: /* $@24: %empty  */
#line 1239 "C_grammar.y"
                  {check_for_typedef = 0;}
#line 4216 "C_grammar.tab.c"
    break;

  case 284: /* labeled_statement: DEFAULT $@24 ':' statement  */
#line 1240 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4226 "C_grammar.tab.c"
    break;

  case 285: /* compound_statement: '{' '}'  */
#line 1248 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4232 "C_grammar.tab.c"
    break;

  case 286: /* $@25: %empty  */
#line 1249 "C_grammar.y"
              {check_for_typedef = 1;}
#line 4238 "C_grammar.tab.c"
    break;

  case 287: /* compound_statement: '{' $@25 block_item_list '}'  */
#line 1250 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4248 "C_grammar.tab.c"
    break;

  case 288: /* block_item_list: block_item  */
#line 1258 "C_grammar.y"
                     {check_for_typedef = 1;}
#line 4254 "C_grammar.tab.c"
    break;

  case 289: /* $@26: %empty  */
#line 1259 "C_grammar.y"
                                     {check_for_typedef = 1;}
#line 4260 "C_grammar.tab.c"
    break;

  case 290: /* block_item_list: block_item_list block_item $@26  */
#line 1260 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	  }
#line 4271 "C_grammar.tab.c"
    break;

  case 293: /* expression_statement: ';'  */
#line 1274 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4277 "C_grammar.tab.c"
    break;

  case 294: /* expression_statement: expression ';'  */
#line 1276 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4287 "C_grammar.tab.c"
    break;

  case 295: /* $@27: %empty  */
#line 1284 "C_grammar.y"
             {check_for_typedef = 0;}
#line 4293 "C_grammar.tab.c"
    break;

  case 296: /* selection_statement: IF $@27 '(' expression ')' statement else_opt  */
#line 1285 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4305 "C_grammar.tab.c"
    break;

  case 297: /* $@28: %empty  */
#line 1292 "C_grammar.y"
                 {check_for_typedef = 0;}
#line 4311 "C_grammar.tab.c"
    break;

  case 298: /* selection_statement: SWITCH $@28 '(' expression ')' statement  */
#line 1293 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4322 "C_grammar.tab.c"
    break;

  case 299: /* else_opt: %empty  */
#line 1302 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4328 "C_grammar.tab.c"
    break;

  case 300: /* else_opt: ELSE statement  */
#line 1304 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4338 "C_grammar.tab.c"
    break;

  case 301: /* $@29: %empty  */
#line 1311 "C_grammar.y"
                {check_for_typedef = 0;}
#line 4344 "C_grammar.tab.c"
    break;

  case 302: /* iteration_statement: WHILE $@29 '(' expression ')' statement  */
#line 1312 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4355 "C_grammar.tab.c"
    break;

  case 303: /* $@30: %empty  */
#line 1318 "C_grammar.y"
             {check_for_typedef = 0;}
#line 4361 "C_grammar.tab.c"
    break;

  case 304: /* iteration_statement: DO $@30 statement WHILE '(' expression ')' ';'  */
#line 1319 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4372 "C_grammar.tab.c"
    break;

  case 305: /* $@31: %empty  */
#line 1325 "C_grammar.y"
              {check_for_typedef = 0;}
#line 4378 "C_grammar.tab.c"
    break;

  case 306: /* iteration_statement: FOR $@31 '(' for_stmt_type ')' statement  */
#line 1326 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4391 "C_grammar.tab.c"
    break;

  case 307: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1338 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4397 "C_grammar.tab.c"
    break;

  case 308: /* $@32: %empty  */
#line 1339 "C_grammar.y"
          {check_for_typedef = 1;}
#line 4403 "C_grammar.tab.c"
    break;

  case 309: /* for_stmt_type: $@32 declaration expression_opt ';' expression_opt  */
#line 1340 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4409 "C_grammar.tab.c"
    break;

  case 310: /* expression_opt: %empty  */
#line 1344 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4415 "C_grammar.tab.c"
    break;

  case 312: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1349 "C_grammar.y"
          {size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4425 "C_grammar.tab.c"
    break;

  case 313: /* jump_statement: CONTINUE ';'  */
#line 1354 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4431 "C_grammar.tab.c"
    break;

  case 314: /* jump_statement: BREAK ';'  */
#line 1355 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4437 "C_grammar.tab.c"
    break;

  case 315: /* jump_statement: RETURN ';'  */
#line 1356 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4443 "C_grammar.tab.c"
    break;

  case 316: /* jump_statement: RETURN expression ';'  */
#line 1358 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4453 "C_grammar.tab.c"
    break;

  case 317: /* translation_unit: external_declaration  */
#line 1367 "C_grammar.y"
                               {check_for_typedef = 1;}
#line 4459 "C_grammar.tab.c"
    break;

  case 318: /* $@33: %empty  */
#line 1368 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4465 "C_grammar.tab.c"
    break;

  case 319: /* translation_unit: translation_unit $@33 external_declaration  */
#line 1368 "C_grammar.y"
                                                                            {check_for_typedef = 1;}
#line 4471 "C_grammar.tab.c"
    break;

  case 320: /* external_declaration: function_definition  */
#line 1372 "C_grammar.y"
                                {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4477 "C_grammar.tab.c"
    break;

  case 321: /* external_declaration: declaration  */
#line 1373 "C_grammar.y"
                                        {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4483 "C_grammar.tab.c"
    break;

  case 322: /* $@34: %empty  */
#line 1377 "C_grammar.y"
                                            {check_for_typedef = 1;}
#line 4489 "C_grammar.tab.c"
    break;

  case 323: /* function_definition: declaration_specifiers declarator $@34 declaration_list_opt compound_statement  */
#line 1378 "C_grammar.y"
                {size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-4].id), (yyvsp[-3].declarator_type).full, (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4503 "C_grammar.tab.c"
    break;

  case 324: /* declaration_list_opt: %empty  */
#line 1390 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4509 "C_grammar.tab.c"
    break;

  case 326: /* declaration_list: declaration  */
#line 1395 "C_grammar.y"
                      {check_for_typedef = 1;}
#line 4515 "C_grammar.tab.c"
    break;

  case 327: /* $@35: %empty  */
#line 1396 "C_grammar.y"
                                       {check_for_typedef = 1;}
#line 4521 "C_grammar.tab.c"
    break;

  case 328: /* declaration_list: declaration_list declaration $@35  */
#line 1397 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 4532 "C_grammar.tab.c"
    break;


#line 4536 "C_grammar.tab.c"

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

#line 1405 "C_grammar.y"

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

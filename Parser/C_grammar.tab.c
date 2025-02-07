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
int in_tag_declaration = 0;		//indicates to the lexer that we are in the tag namespace (for struct, union and enum tags) and that identifier should not be checked for typedef
int in_member_namespace = 0;	//indicates to the lexer that we are in the member namespace (for members of structs and unions) and that identifier should not be checked for typedef
int in_ordinary_id_declaration = 0;
int in_label_namespace = 0;
int check_for_typedef = 1;
int handled_function_paramaters = 0;
int current_scope = 0;

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements
void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 130 "C_grammar.tab.c"

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
#line 67 "C_grammar.y"

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

#line 270 "C_grammar.tab.c"

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
  YYSYMBOL_145_4 = 145,                    /* $@4  */
  YYSYMBOL_146_5 = 146,                    /* $@5  */
  YYSYMBOL_147_6 = 147,                    /* $@6  */
  YYSYMBOL_148_7 = 148,                    /* $@7  */
  YYSYMBOL_149_8 = 149,                    /* $@8  */
  YYSYMBOL_init_declarator_list = 150,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 151,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 152,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 153,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 154, /* struct_or_union_specifier  */
  YYSYMBOL_155_9 = 155,                    /* $@9  */
  YYSYMBOL_156_10 = 156,                   /* $@10  */
  YYSYMBOL_struct_or_union = 157,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 158,  /* struct_declaration_list  */
  YYSYMBOL_159_11 = 159,                   /* $@11  */
  YYSYMBOL_160_12 = 160,                   /* $@12  */
  YYSYMBOL_struct_declaration = 161,       /* struct_declaration  */
  YYSYMBOL_162_13 = 162,                   /* $@13  */
  YYSYMBOL_specifier_qualifier_list = 163, /* specifier_qualifier_list  */
  YYSYMBOL_164_14 = 164,                   /* $@14  */
  YYSYMBOL_165_15 = 165,                   /* $@15  */
  YYSYMBOL_struct_declarator_list = 166,   /* struct_declarator_list  */
  YYSYMBOL_167_16 = 167,                   /* $@16  */
  YYSYMBOL_168_17 = 168,                   /* $@17  */
  YYSYMBOL_struct_declarator = 169,        /* struct_declarator  */
  YYSYMBOL_170_18 = 170,                   /* $@18  */
  YYSYMBOL_171_19 = 171,                   /* $@19  */
  YYSYMBOL_enum_specifier = 172,           /* enum_specifier  */
  YYSYMBOL_173_20 = 173,                   /* $@20  */
  YYSYMBOL_174_21 = 174,                   /* $@21  */
  YYSYMBOL_175_22 = 175,                   /* $@22  */
  YYSYMBOL_enum_specifier_rest = 176,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 177,          /* enumerator_list  */
  YYSYMBOL_enumerator = 178,               /* enumerator  */
  YYSYMBOL_179_23 = 179,                   /* $@23  */
  YYSYMBOL_atomic_type_specifier = 180,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 181,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 182,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 183,      /* alignment_specifier  */
  YYSYMBOL_declarator = 184,               /* declarator  */
  YYSYMBOL_direct_declarator = 185,        /* direct_declarator  */
  YYSYMBOL_186_24 = 186,                   /* $@24  */
  YYSYMBOL_rest_function_definition = 187, /* rest_function_definition  */
  YYSYMBOL_pointer = 188,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 189,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 190,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 191,           /* parameter_list  */
  YYSYMBOL_192_25 = 192,                   /* $@25  */
  YYSYMBOL_parameter_declaration = 193,    /* parameter_declaration  */
  YYSYMBOL_old_style_parameter_list = 194, /* old_style_parameter_list  */
  YYSYMBOL_type_name = 195,                /* type_name  */
  YYSYMBOL_196_26 = 196,                   /* $@26  */
  YYSYMBOL_abstract_declarator_opt = 197,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 198,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 199, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 200,              /* initializer  */
  YYSYMBOL_initializer_list = 201,         /* initializer_list  */
  YYSYMBOL_designation = 202,              /* designation  */
  YYSYMBOL_designator_list = 203,          /* designator_list  */
  YYSYMBOL_designator = 204,               /* designator  */
  YYSYMBOL_205_27 = 205,                   /* $@27  */
  YYSYMBOL_static_assert_declaration = 206, /* static_assert_declaration  */
  YYSYMBOL_207_28 = 207,                   /* $@28  */
  YYSYMBOL_statement = 208,                /* statement  */
  YYSYMBOL_209_29 = 209,                   /* $@29  */
  YYSYMBOL_labeled_statement = 210,        /* labeled_statement  */
  YYSYMBOL_211_30 = 211,                   /* $@30  */
  YYSYMBOL_212_31 = 212,                   /* $@31  */
  YYSYMBOL_compound_statement = 213,       /* compound_statement  */
  YYSYMBOL_block_item_list = 214,          /* block_item_list  */
  YYSYMBOL_215_32 = 215,                   /* $@32  */
  YYSYMBOL_block_item = 216,               /* block_item  */
  YYSYMBOL_expression_statement = 217,     /* expression_statement  */
  YYSYMBOL_selection_statement = 218,      /* selection_statement  */
  YYSYMBOL_219_33 = 219,                   /* $@33  */
  YYSYMBOL_220_34 = 220,                   /* $@34  */
  YYSYMBOL_else_opt = 221,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 222,      /* iteration_statement  */
  YYSYMBOL_223_35 = 223,                   /* $@35  */
  YYSYMBOL_224_36 = 224,                   /* $@36  */
  YYSYMBOL_225_37 = 225,                   /* $@37  */
  YYSYMBOL_for_stmt_type = 226,            /* for_stmt_type  */
  YYSYMBOL_227_38 = 227,                   /* $@38  */
  YYSYMBOL_expression_opt = 228,           /* expression_opt  */
  YYSYMBOL_jump_statement = 229,           /* jump_statement  */
  YYSYMBOL_translation_unit = 230,         /* translation_unit  */
  YYSYMBOL_231_39 = 231,                   /* $@39  */
  YYSYMBOL_external_declaration = 232,     /* external_declaration  */
  YYSYMBOL_function_definition = 233,      /* function_definition  */
  YYSYMBOL_234_40 = 234,                   /* $@40  */
  YYSYMBOL_235_41 = 235,                   /* $@41  */
  YYSYMBOL_declaration_list_opt = 236,     /* declaration_list_opt  */
  YYSYMBOL_old_style_declaration_list = 237, /* old_style_declaration_list  */
  YYSYMBOL_238_42 = 238                    /* $@42  */
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
#define YYLAST   2242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  335
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  528

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
       0,   129,   129,   133,   134,   135,   135,   142,   148,   152,
     153,   154,   158,   162,   163,   167,   171,   172,   176,   177,
     181,   182,   189,   195,   202,   202,   210,   210,   218,   224,
     230,   247,   248,   253,   254,   264,   265,   272,   279,   285,
     291,   300,   301,   305,   306,   307,   308,   309,   310,   314,
     315,   325,   326,   337,   338,   339,   343,   344,   355,   356,
     360,   361,   372,   373,   377,   378,   389,   390,   391,   392,
     397,   398,   409,   410,   414,   415,   425,   426,   436,   437,
     447,   448,   458,   459,   469,   470,   481,   482,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   507,
     508,   518,   523,   531,   543,   554,   554,   563,   567,   567,
     576,   580,   580,   589,   590,   590,   595,   600,   600,   605,
     613,   617,   628,   636,   646,   651,   652,   653,   654,   655,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   679,   680,   681,   685,
     685,   692,   692,   702,   715,   720,   728,   728,   729,   729,
     739,   746,   746,   754,   758,   758,   766,   767,   767,   775,
     779,   779,   780,   780,   790,   790,   796,   796,   804,   812,
     812,   826,   826,   826,   838,   839,   841,   850,   851,   862,
     862,   869,   873,   877,   878,   879,   880,   884,   885,   889,
     890,   895,   904,   908,   931,   934,   941,   946,   951,   956,
     961,   966,   971,   976,   984,   984,   998,   999,  1000,  1004,
    1011,  1017,  1023,  1028,  1029,  1039,  1045,  1054,  1055,  1055,
    1065,  1073,  1080,  1089,  1090,  1094,  1094,  1108,  1109,  1113,
    1114,  1115,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1143,  1149,  1155,  1156,  1161,  1168,  1169,
    1177,  1187,  1196,  1197,  1207,  1213,  1213,  1223,  1223,  1233,
    1234,  1234,  1238,  1239,  1240,  1241,  1245,  1253,  1260,  1260,
    1267,  1267,  1276,  1277,  1286,  1287,  1287,  1297,  1298,  1302,
    1303,  1312,  1312,  1320,  1320,  1330,  1331,  1339,  1339,  1346,
    1346,  1353,  1353,  1365,  1367,  1367,  1372,  1373,  1376,  1383,
    1384,  1385,  1386,  1396,  1397,  1397,  1401,  1407,  1418,  1418,
    1418,  1432,  1433,  1437,  1438,  1438
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
  "declaration_specifiers", "$@4", "$@5", "$@6", "$@7", "$@8",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "$@9", "$@10",
  "struct_or_union", "struct_declaration_list", "$@11", "$@12",
  "struct_declaration", "$@13", "specifier_qualifier_list", "$@14", "$@15",
  "struct_declarator_list", "$@16", "$@17", "struct_declarator", "$@18",
  "$@19", "enum_specifier", "$@20", "$@21", "$@22", "enum_specifier_rest",
  "enumerator_list", "enumerator", "$@23", "atomic_type_specifier",
  "type_qualifier", "function_specifier", "alignment_specifier",
  "declarator", "direct_declarator", "$@24", "rest_function_definition",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "$@25", "parameter_declaration",
  "old_style_parameter_list", "type_name", "$@26",
  "abstract_declarator_opt", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "$@27",
  "static_assert_declaration", "$@28", "statement", "$@29",
  "labeled_statement", "$@30", "$@31", "compound_statement",
  "block_item_list", "$@32", "block_item", "expression_statement",
  "selection_statement", "$@33", "$@34", "else_opt", "iteration_statement",
  "$@35", "$@36", "$@37", "for_stmt_type", "$@38", "expression_opt",
  "jump_statement", "translation_unit", "$@39", "external_declaration",
  "function_definition", "$@40", "$@41", "declaration_list_opt",
  "old_style_declaration_list", "$@42", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-350)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-276)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1954,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,  -350,    34,   -25,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,  -350,  -350,    19,    16,    31,  -350,
      17,  -350,  -350,   103,   121,   214,  -350,    42,  -350,  -350,
     -30,    68,  1468,     3,  2163,     6,  -350,    47,   175,  -350,
     -47,  -350,   -60,    58,    44,  2059,  2059,     5,  -350,  2059,
    2059,  2059,  -350,  1954,    93,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  1522,  -350,  -350,    21,    46,  1321,  -350,  -350,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,   197,  -350,
    1561,  1468,  -350,   -65,   -28,   140,    38,   148,    52,    49,
      43,   149,    -8,  -350,   108,   123,  -350,   186,   -18,   232,
    1468,   136,  -350,  -350,   175,    47,  -350,  1375,  1954,   811,
     141,    58,  -350,  -350,   139,  -350,  -350,  -350,  -350,  -350,
    -350,   130,   153,  -350,   150,  1321,  -350,  -350,  1468,   154,
     471,  -350,  -350,   116,   162,  -350,  -350,  1414,  1468,   159,
     239,  1321,  -350,  -350,  -350,  -350,  -350,  1468,  -350,  -350,
    1468,  -350,  -350,  1468,  -350,  -350,  -350,  -350,  1468,  -350,
    -350,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  -350,  -350,
    2163,  1685,   904,    95,  -350,  -350,   115,  2163,   171,  -350,
    -350,  -350,  -350,   158,  1173,  -350,  -350,  -350,    19,  -350,
    1954,  1135,  -350,   187,   199,   919,  1902,  -350,  1739,  2111,
     176,    93,   194,    93,  -350,   205,   206,   208,   595,   210,
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,  1468,  -350,  1468,  1429,  -350,   138,  -350,    78,   291,
     300,   222,  -350,   -65,   -28,   140,    38,   148,    52,    49,
      43,   149,   165,  -350,  -350,   106,   224,   225,  -350,   227,
    1135,  -350,   226,   229,  1012,   115,  1849,  1027,  -350,   302,
    1468,  -350,  -350,   -43,  1375,   -33,  -350,   235,   154,  -350,
     233,  1135,  -350,  -350,  1468,  -350,   238,   240,  -350,   243,
    -350,   228,  1791,  -350,  -350,   223,  -350,  -350,  1468,  -350,
    -350,   -38,   242,  -350,   270,   247,   248,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,   331,   231,   234,   703,  -350,  -350,
     -45,  -350,  -350,   154,  -350,   688,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -350,  1282,  -350,  -350,  1468,  -350,  -350,
    -350,   242,  1468,  1625,  -350,    87,  -350,  -350,  2006,  -350,
     253,  1135,  -350,  -350,  1468,  -350,   254,  -350,   259,  1135,
    -350,   256,   257,  1120,   262,   260,  1228,  -350,  -350,  -350,
    -350,   344,  -350,  -350,  -350,   264,   265,  -350,  -350,  -350,
     345,  -350,  -350,  -350,  -350,  -350,    30,  -350,   271,   170,
    -350,   273,   465,   465,  1468,   274,   278,   280,   281,   465,
     283,   250,  -350,  -350,  -350,   -44,  -350,  -350,  -350,  -350,
     282,  -350,  -350,  -350,  -350,  -350,   284,   285,  -350,  -350,
     286,  1135,  -350,  -350,  1468,  -350,   287,   263,  -350,  -350,
    -350,  1375,  -350,  -350,  -350,  -350,   -42,    47,  -350,  1468,
    -350,   270,  1468,   248,  -350,  -350,   293,   465,  1468,  1468,
    1468,   304,   796,  -350,  -350,  -350,  1266,   289,  -350,  -350,
    -350,  -350,   294,   295,  -350,  -350,  -350,    47,  -350,  -350,
     298,   301,  -350,  -350,  -350,   465,  -350,   177,   181,   193,
     303,  1468,   297,  1954,  -350,  -350,  -350,  -350,  1468,   305,
    -350,   465,   465,   465,  1468,   307,   288,   465,  1468,  -350,
    -350,  1468,   327,  -350,  -350,   198,  1468,  -350,   290,  -350,
     465,  -350,   296,  -350,  1468,  -350,  -350,  -350
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   145,   124,   125,   126,   128,   129,   197,   193,   194,
     195,   139,   131,   132,   133,   134,   137,   138,   135,   136,
     130,   140,   141,   154,   155,   179,     0,   235,   196,   198,
     277,   127,   146,   147,   148,   327,     0,   105,   108,   143,
       0,   144,   142,   111,   114,   117,   104,   324,   323,   326,
       0,     0,   235,     0,     0,     0,   203,     0,   222,   102,
       0,   120,   328,   202,     0,     0,     0,   153,   149,     0,
       0,     0,     1,     0,     0,   182,     2,     9,    10,    11,
      13,    14,     0,    41,    42,     0,     0,   235,    43,    44,
      45,    46,    47,    48,    20,     3,     4,     8,    35,    49,
       0,     0,    51,    56,    60,    64,    70,    74,    76,    78,
      80,    82,    84,   101,     0,     0,   192,   164,   237,   167,
       0,     0,   223,   221,   220,     0,   103,     0,   331,     0,
       0,   201,   106,   109,     0,   156,   112,   115,   118,   325,
      12,   191,    31,   187,   184,   235,    38,   235,     0,     0,
      49,    86,    99,     0,     0,    28,    29,     0,     0,     0,
       0,   235,    36,    37,    53,    54,    55,     0,    58,    59,
       0,    62,    63,     0,    68,    69,    66,    67,     0,    72,
      73,     0,     0,     0,     0,     0,     0,     0,   200,   199,
       0,     0,     0,   240,   236,   238,   241,     0,     0,   204,
     224,   219,   121,   123,   275,   265,   122,   333,     0,   329,
     332,     0,   205,    44,     0,     0,   216,   156,     0,     0,
       0,    32,     0,     0,   183,     0,     0,     0,   280,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      88,     0,     7,     0,     0,    22,     0,    33,     0,     0,
       0,     0,    52,    57,    61,    65,    71,    75,    77,    79,
      81,    83,     0,   165,   259,   232,     0,   226,   227,     0,
       0,   243,    44,     0,     0,   239,     0,     0,   168,     0,
       0,   266,   268,     0,     0,   275,   272,     0,     0,   334,
       0,     0,   206,   213,     0,   212,    44,     0,   233,     0,
     217,   218,     0,   150,   158,   161,   163,   157,     0,   188,
     180,     0,    39,    40,   235,     2,   145,   288,   290,   301,
     303,   307,   309,   311,     0,     0,     0,     0,   292,   299,
       0,   297,   298,     0,   279,   280,   294,   282,   283,   284,
     285,     6,    87,   100,   275,    50,    23,     0,    21,    25,
      27,     0,     0,     0,   230,   240,   231,   260,     0,   242,
       0,     0,   244,   250,     0,   249,     0,   261,     0,     0,
     251,    44,     0,     0,     0,     0,   275,   263,   267,   271,
     273,     0,   330,   335,   208,     0,     0,   209,   211,   215,
       0,   152,   159,   160,   170,   190,     0,   185,     0,     0,
      16,     0,   280,   280,     0,     0,     0,     0,     0,   280,
       0,     0,   319,   320,   321,     0,   300,   281,   293,   295,
      31,    34,    85,   225,   228,   246,     0,     0,   248,   262,
       0,     0,   252,   258,     0,   257,     0,     0,   274,   264,
     270,     0,   276,   207,   210,   234,     0,   174,   186,     0,
      15,   235,     0,     0,   286,   287,     0,   280,     0,     0,
       0,     0,   314,   318,   322,   296,    32,     0,   229,   245,
     247,   254,     0,     0,   255,   278,   269,   174,   162,   171,
       0,   178,    19,    17,    18,   280,   291,     0,     0,     0,
       0,   316,     0,     0,    30,   253,   256,   172,     0,     0,
     289,   280,   280,   280,     0,   317,     0,   280,   316,   173,
     175,     0,   305,   304,   308,     0,   316,   312,     0,   177,
     280,   302,     0,   313,   316,   306,   310,   315
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -350,  -350,  -350,  -350,  -350,  -350,  -350,  -350,   -58,  -350,
    -350,  -350,   -23,  -350,   -52,  -350,  -350,   -85,   236,  -350,
     230,  -350,   217,  -350,   218,  -350,   216,  -350,   219,   220,
     241,   215,  -350,   -51,   145,  -350,   -84,  -115,  -124,    10,
    -350,  -350,  -350,  -350,  -350,  -350,   292,  -350,   -37,  -350,
    -350,  -350,  -350,   188,  -350,  -350,   189,  -350,   -39,  -350,
    -350,  -350,  -350,  -350,   -68,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,   191,  -213,  -350,  -350,   -40,  -350,  -350,   -34,
     -57,  -350,  -350,   -46,  -100,  -181,  -350,  -350,    53,  -350,
       1,  -350,  -350,  -109,  -182,  -121,    66,  -349,  -350,   127,
    -350,  -194,  -350,  -262,  -350,  -350,  -350,  -350,  -267,  -350,
    -350,    81,   -41,  -350,  -350,  -350,  -350,  -350,  -350,  -350,
    -350,  -350,  -350,  -292,  -350,  -350,  -350,   350,  -350,  -350,
    -350,  -350,  -350,  -350
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    94,   149,    95,   141,    96,    97,   399,   400,    98,
     159,   160,   222,   246,   150,   100,   101,   102,   103,   167,
     104,   170,   105,   173,   106,   178,   107,   181,   108,   109,
     110,   111,   112,   151,   152,   241,   330,   114,    35,   208,
      65,    66,    69,    70,    71,    60,    61,    37,    38,    39,
     135,   134,    40,   218,   219,   392,   304,   394,   305,   190,
     197,   446,   447,   509,   479,   480,   499,    41,    50,    51,
     144,   224,   142,   143,   220,    42,    43,    44,    45,   121,
      63,   130,   299,    64,   124,   266,   267,   468,   268,   301,
     401,    54,   194,   269,   196,   282,   283,   284,   285,   286,
     287,    46,    55,   332,   333,   334,   404,   405,   229,   335,
     465,   336,   337,   338,   406,   407,   521,   339,   408,   409,
     410,   492,   493,   506,   340,    47,    73,    48,    49,   128,
     288,   209,   210,   383
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,   113,    62,   153,   207,   198,   206,   131,   309,   195,
      36,   275,   123,   186,   119,   118,   163,   117,   122,  -107,
      67,   382,    56,  -123,   306,   306,   164,   441,    53,   215,
     146,   165,   166,   140,  -110,   300,   125,  -181,   243,   243,
     376,   477,    72,   127,  -123,   396,   377,    56,   162,    99,
      56,   397,   280,   115,   174,   175,    52,   126,    74,   416,
     464,   153,   478,   191,   168,   169,   417,   192,    99,   113,
     379,    75,   193,    58,   248,   132,   133,   153,   201,   136,
     137,   138,   252,    36,   200,   116,   289,   120,   154,   122,
      56,   203,   274,  -151,   187,   368,   140,  -107,  -107,  -107,
      57,  -107,   147,   262,   331,    68,  -113,  -107,   306,    56,
      58,   291,  -110,  -110,  -110,    99,  -110,   441,    99,   448,
    -107,    99,  -110,    59,  -116,    57,    99,   148,    57,    99,
      99,    99,    99,    99,    99,  -110,   176,   177,    58,  -214,
     454,   455,   182,   129,   184,   193,   225,   461,   226,   183,
     119,   263,   122,   117,   171,   172,   356,   119,   278,   345,
     117,   243,   251,   378,   348,   375,   179,   180,   353,   185,
     361,   122,   192,   275,   203,   200,   191,   373,   119,   119,
     192,   117,   117,   309,  -113,  -113,  -113,   353,  -113,  -166,
     188,   192,    99,   395,  -113,   486,   276,    58,   242,   243,
     277,   265,  -116,  -116,  -116,   189,  -116,  -113,   -26,   155,
     156,   331,  -116,     8,     9,    10,   518,  -119,   199,   355,
     346,   347,   216,   500,   523,  -116,   265,   217,    99,   113,
     122,   354,   527,  -189,   200,  -169,   221,   122,   223,   512,
     513,   514,   228,   415,   244,   517,   249,    28,   243,   352,
     250,   200,   450,   451,   279,   440,    99,   113,   525,   501,
     243,   127,   119,   502,   243,   117,    58,  -166,  -166,   431,
    -166,  -166,   205,   292,   214,   503,   243,  -166,   157,   308,
     522,   243,   158,   310,   -24,   293,   265,   312,   313,   456,
    -166,   314,   341,   227,   349,  -119,  -119,  -119,   131,  -119,
      99,   422,   247,   350,   351,  -119,   357,   355,   358,   359,
     374,   390,   362,  -169,  -169,   363,  -169,  -169,  -119,   384,
     476,   200,   381,  -169,   387,   389,   388,   393,   398,   122,
     344,   402,   403,   200,   411,   412,  -169,   273,   413,   425,
     428,   429,   432,   433,   437,   440,   438,   442,   445,   205,
     443,   444,    99,   113,   463,   449,   290,   452,   457,   458,
     297,   459,   460,   265,   462,   466,   490,   475,   265,   508,
     469,   470,   471,   474,   487,   488,   489,   485,   494,   507,
     495,   496,   498,   510,   504,  -176,   342,   520,   343,   511,
     243,   200,   516,   483,   524,   255,   519,   467,   257,   256,
     526,   261,   258,   254,   259,   302,   253,   505,   307,   497,
     420,   424,   380,   481,   311,   360,   419,   202,     0,   366,
     515,   491,   372,   139,   505,     0,   260,     0,     0,   205,
       0,     0,   505,     0,     0,     0,   385,     0,     0,   386,
     505,     0,     0,   481,     0,     0,    99,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     113,     0,     0,     0,     0,     0,     0,     0,   315,   453,
      77,    78,    79,    80,    81,    82,     0,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   421,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     0,   426,     0,     0,   427,
       0,     0,     0,     0,   430,     0,     0,     0,   436,     0,
       0,   205,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,     0,    85,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,   329,
       0,     0,     0,     0,   240,     0,   472,     0,     0,   473,
       0,     0,     0,     0,     0,     0,   205,     0,     0,     0,
       0,     0,     0,     0,   482,     0,     0,   484,   315,   316,
      77,    78,    79,    80,    81,    82,     0,    83,    84,     0,
       0,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,    26,    85,    27,    28,    86,    29,
      30,    31,    32,    33,    34,     0,    87,     0,     0,     0,
       0,     0,     0,     0,   328,    88,    89,    90,    91,    92,
      93,   315,   316,    77,    78,    79,    80,    81,    82,   329,
      83,    84,     0,     0,     0,     0,    76,     0,    77,    78,
      79,    80,    81,    82,     0,    83,    84,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,    26,    85,    27,
      28,    86,    29,    30,    31,    32,    33,    34,     0,    87,
       0,     0,     0,    85,     0,     0,    86,   418,    88,    89,
      90,    91,    92,    93,    87,     0,     0,     0,     0,     0,
       0,     0,   329,    88,    89,    90,    91,    92,    93,    76,
       0,    77,    78,    79,    80,    81,    82,   414,    83,    84,
       0,     0,     0,     0,    76,     0,    77,    78,    79,    80,
      81,    82,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,    85,     0,    28,    86,     0,    88,    89,    90,    91,
      92,    93,    87,     0,     0,     0,     0,   212,     0,     0,
     329,    88,   213,    90,    91,    92,    93,    76,     0,    77,
      78,    79,    80,    81,    82,     0,    83,    84,     0,     0,
       0,     0,    76,     0,    77,    78,    79,    80,    81,    82,
       0,    83,    84,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,    28,    86,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,    85,
     271,    28,    86,     0,    88,   272,    90,    91,    92,    93,
      87,     0,     0,     0,     0,   295,     0,     0,     0,    88,
     296,    90,    91,    92,    93,    76,     0,    77,    78,    79,
      80,    81,    82,     0,    83,    84,     0,     0,     0,     0,
      76,     0,    77,    78,    79,    80,    81,    82,     0,    83,
      84,     0,     0,     0,     0,     0,   364,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,   369,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,    28,    86,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,    85,   365,    28,
      86,     0,    88,    89,    90,    91,    92,    93,    87,     0,
       0,     0,     0,   370,     0,     0,     0,    88,   371,    90,
      91,    92,    93,    76,     0,    77,    78,    79,    80,    81,
      82,     0,    83,    84,     0,     0,     0,     0,    76,     0,
      77,    78,    79,    80,    81,    82,     0,    83,    84,     0,
       0,     0,     0,     0,   434,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    76,     0,    77,    78,
      79,    80,    81,    82,     0,    83,    84,     0,     0,     0,
      85,     0,    28,    86,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,     0,    85,   435,    28,    86,     0,
      88,    89,    90,    91,    92,    93,    87,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
      93,    76,     0,    77,    78,    79,    80,    81,    82,     0,
      83,    84,     0,    85,     0,     0,    86,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,   280,     0,
       0,   204,   281,    88,    89,    90,    91,    92,    93,    76,
       0,    77,    78,    79,    80,    81,    82,     0,    83,    84,
       0,     0,     0,     0,     0,    76,     0,    77,    78,    79,
      80,    81,    82,     0,    83,    84,     0,     0,    85,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,   280,     0,     0,   204,   439,    88,    89,
      90,    91,    92,    93,    76,     0,    77,    78,    79,    80,
      81,    82,     0,    83,    84,     0,    85,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,   280,    85,  -275,   204,    86,    88,    89,    90,    91,
      92,    93,     0,    87,     0,     0,     0,   280,     0,     0,
     204,     0,    88,    89,    90,    91,    92,    93,    76,     0,
      77,    78,    79,    80,    81,    82,     0,    83,    84,     0,
       0,    85,     0,     0,    86,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,    -5,
       0,    88,    89,    90,    91,    92,    93,    76,     0,    77,
      78,    79,    80,    81,    82,     0,    83,    84,     0,     0,
       0,     0,    76,     0,    77,    78,    79,    80,    81,    82,
       0,    83,    84,     0,     0,    85,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,   204,     0,    88,    89,    90,    91,    92,
      93,    76,     0,    77,    78,    79,    80,    81,    82,     0,
      83,    84,     0,     0,    85,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,    87,   245,     0,     0,    85,
       0,     0,    86,     0,    88,    89,    90,    91,    92,    93,
      87,     0,     0,     0,     0,     0,     0,   344,     0,    88,
      89,    90,    91,    92,    93,    76,     0,    77,    78,    79,
      80,    81,    82,     0,    83,    84,     0,     0,    85,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    76,     0,    77,    78,    79,    80,
      81,    82,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     1,
       0,    85,     0,     0,    86,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,    32,    33,    34,     0,   353,   264,     0,     0,
     192,     0,     0,     0,     0,     0,    58,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,    32,    33,    34,     0,   191,   264,     0,     0,
     192,     0,     0,     0,     0,     0,    58,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,    30,     0,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,    30,     0,    32,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     391,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   298,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,    28,     0,    29,     0,    31,    32,    33,    34,     0,
       0,   367,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,    32,
      33,    34,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,    30,
      31,    32,    33,    34,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   423,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,     0,    31,    32,    33,    34,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,    28,     0,    29,     0,    31,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,    30,     0,    32,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
      32,    33,    34
};

static const yytype_int16 yycheck[] =
{
      52,    52,    36,    87,   128,   120,   127,    64,   221,   118,
       0,   193,    58,    21,    54,    54,   101,    54,    58,     3,
       3,   288,     3,    83,   218,   219,    91,   376,    27,   129,
      82,    96,    97,     3,     3,   216,    83,     3,    83,    83,
      83,    83,     0,   103,   104,    83,    89,     3,   100,   101,
       3,    89,    85,    52,    16,    17,    81,   104,    88,   104,
     104,   145,   104,    81,    92,    93,   333,    85,   120,   120,
     103,     3,   118,    91,   158,    65,    66,   161,   124,    69,
      70,    71,   167,    73,   124,    82,   210,    81,    87,   129,
       3,   125,   192,    88,   102,   276,     3,    81,    82,    83,
      81,    85,    81,   187,   228,    88,     3,    91,   302,     3,
      91,   211,    81,    82,    83,   167,    85,   466,   170,    89,
     104,   173,    91,   104,     3,    81,   178,    81,    81,   181,
     182,   183,   184,   185,   186,   104,    98,    99,    91,    81,
     402,   403,    90,    85,   101,   191,   145,   409,   147,   100,
     190,   190,   192,   190,    14,    15,   265,   197,   197,   244,
     197,    83,   161,   284,    86,   280,    18,    19,    81,    20,
     270,   211,    85,   355,   208,   215,    81,   277,   218,   219,
      85,   218,   219,   396,    81,    82,    83,    81,    85,     3,
      82,    85,   244,   308,    91,   457,    81,    91,    82,    83,
      85,   191,    81,    82,    83,    82,    85,   104,    11,    12,
      13,   335,    91,    38,    39,    40,   508,     3,    82,   265,
      82,    83,    81,   485,   516,   104,   216,    88,   280,   280,
     270,   265,   524,   103,   274,     3,    83,   277,    88,   501,
     502,   503,    88,   327,    82,   507,    87,    72,    83,    84,
      11,   291,    82,    83,    83,   376,   308,   308,   520,    82,
      83,   103,   302,    82,    83,   302,    91,    81,    82,   369,
      84,    85,   127,    86,   129,    82,    83,    91,    81,   103,
      82,    83,    85,    89,    87,    86,   276,    82,    82,   404,
     104,    83,    82,   148,     3,    81,    82,    83,   355,    85,
     352,   352,   157,     3,    82,    91,    82,   353,    83,    82,
       8,    83,    86,    81,    82,    86,    84,    85,   104,    86,
     441,   361,    87,    91,    86,    82,    86,   104,    58,   369,
      88,    84,    84,   373,     3,   104,   104,   192,   104,    86,
      86,    82,    86,    86,    82,   466,    86,     3,     3,   204,
      86,    86,   404,   404,   104,    84,   211,    84,    84,    81,
     215,    81,    81,   353,    81,    83,    62,   104,   358,   493,
      86,    86,    86,    86,   458,   459,   460,    84,    89,    82,
      86,    86,    84,   498,    81,    84,   241,    60,   243,    84,
      83,   431,   104,   451,   104,   178,   511,   420,   182,   181,
     104,   186,   183,   173,   184,   217,   170,   491,   219,   477,
     344,   358,   285,   447,   223,   270,   335,   125,    -1,   274,
     504,   462,   277,    73,   508,    -1,   185,    -1,    -1,   284,
      -1,    -1,   516,    -1,    -1,    -1,   291,    -1,    -1,   294,
     524,    -1,    -1,   477,    -1,    -1,   498,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,
     511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,
      -1,    -1,   347,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,   361,    -1,    -1,   364,
      -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,   373,    -1,
      -1,   376,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   103,    -1,   431,    -1,    -1,   434,
      -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,   452,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,     3,     4,     5,     6,     7,     8,     9,    10,   104,
      12,    13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,    -1,    70,    -1,    -1,    73,    89,    90,    91,
      92,    93,    94,    95,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    90,    91,    92,    93,    94,    95,     3,
      -1,     5,     6,     7,     8,     9,    10,   104,    12,    13,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    70,    -1,    72,    73,    -1,    90,    91,    92,    93,
      94,    95,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,
     104,    90,    91,    92,    93,    94,    95,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    70,
      86,    72,    73,    -1,    90,    91,    92,    93,    94,    95,
      81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    90,
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
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      70,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    70,    86,    72,    73,    -1,
      90,    91,    92,    93,    94,    95,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    -1,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    70,    87,    88,    73,    90,    91,    92,    93,
      94,    95,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    -1,    90,    91,    92,    93,    94,    95,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    90,    91,    92,    93,    94,    95,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    90,    91,    92,    93,    94,
      95,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    70,
      -1,    -1,    73,    -1,    90,    91,    92,    93,    94,    95,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    90,
      91,    92,    93,    94,    95,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    81,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    81,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    75,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    75,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    82,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    75,    -1,    77,    78,
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
      75,    76,    77,    78,    79,   143,   144,   152,   153,   154,
     157,   172,   180,   181,   182,   183,   206,   230,   232,   233,
     173,   174,    81,   195,   196,   207,     3,    81,    91,   104,
     150,   151,   184,   185,   188,   145,   146,     3,    88,   147,
     148,   149,     0,   231,    88,     3,     3,     5,     6,     7,
       8,     9,    10,    12,    13,    70,    73,    81,    90,    91,
      92,    93,    94,    95,   106,   108,   110,   111,   114,   119,
     120,   121,   122,   123,   125,   127,   129,   131,   133,   134,
     135,   136,   137,   138,   142,   195,    82,   153,   163,   181,
      81,   184,   181,   188,   189,    83,   104,   103,   234,    85,
     186,   185,   144,   144,   156,   155,   144,   144,   144,   232,
       3,   109,   177,   178,   175,    81,   119,    81,    81,   107,
     119,   138,   139,   141,   195,    12,    13,    81,    85,   115,
     116,    81,   119,   122,    91,    96,    97,   124,    92,    93,
     126,    14,    15,   128,    16,    17,    98,    99,   130,    18,
      19,   132,    90,   100,   101,    20,    21,   102,    82,    82,
     164,    81,    85,   188,   197,   198,   199,   165,   142,    82,
     181,   188,   151,   184,    88,   139,   200,   143,   144,   236,
     237,    34,    86,    91,   139,   189,    81,    88,   158,   159,
     179,    83,   117,    88,   176,   195,   195,   139,    88,   213,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     103,   140,    82,    83,    82,    82,   118,   139,   141,    87,
      11,   195,   122,   123,   125,   127,   129,   131,   133,   134,
     135,   136,   141,   163,    82,   144,   190,   191,   193,   198,
      34,    86,    91,   139,   189,   199,    81,    85,   163,    83,
      85,    89,   200,   201,   202,   203,   204,   205,   235,   143,
     139,   189,    86,    86,    34,    86,    91,   139,     3,   187,
     190,   194,   158,    89,   161,   163,   206,   161,   103,   178,
      89,   177,    82,    82,    83,     3,     4,    57,    58,    59,
      61,    62,    63,    64,    65,    66,    67,    68,    89,   104,
     141,   143,   208,   209,   210,   214,   216,   217,   218,   222,
     229,    82,   139,   139,    88,   122,    82,    83,    86,     3,
       3,    82,    84,    81,   184,   188,   198,    82,    83,    82,
     139,   189,    86,    86,    34,    86,   139,    82,   190,    34,
      86,    91,   139,   189,     8,   142,    83,    89,   200,   103,
     204,    87,   213,   238,    86,   139,   139,    86,    86,    82,
      83,    89,   160,   104,   162,   142,    83,    89,    58,   112,
     113,   195,    84,    84,   211,   212,   219,   220,   223,   224,
     225,     3,   104,   104,   104,   141,   104,   213,    89,   216,
     201,   139,   138,    56,   193,    86,   139,   139,    86,    82,
     139,   189,    86,    86,    34,    86,   139,    82,    86,    89,
     200,   202,     3,    86,    86,     3,   166,   167,    89,    84,
      82,    83,    84,     4,   208,   208,   142,    84,    81,    81,
      81,   208,    81,   104,   104,   215,    83,   117,   192,    86,
      86,    86,   139,   139,    86,   104,   200,    83,   104,   169,
     170,   184,   139,   113,   139,    84,   208,   141,   141,   141,
      62,   217,   226,   227,    89,    86,    86,   169,    84,   171,
     208,    82,    82,    82,    81,   141,   228,    82,   143,   168,
     142,    84,   208,   208,   208,   141,   104,   208,   228,   142,
      60,   221,    82,   228,   104,   208,   104,   228
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
     141,   142,   143,   143,   143,   145,   144,   144,   146,   144,
     144,   147,   144,   144,   148,   144,   144,   149,   144,   144,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   155,
     154,   156,   154,   154,   157,   157,   159,   158,   160,   158,
     161,   162,   161,   161,   164,   163,   163,   165,   163,   163,
     167,   166,   168,   166,   170,   169,   171,   169,   169,   173,
     172,   174,   175,   172,   176,   176,   176,   177,   177,   179,
     178,   178,   180,   181,   181,   181,   181,   182,   182,   183,
     183,   184,   184,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   186,   185,   187,   187,   187,   188,
     188,   188,   188,   189,   189,   190,   190,   191,   192,   191,
     193,   193,   193,   194,   194,   196,   195,   197,   197,   198,
     198,   198,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   200,   200,   201,   201,   201,
     201,   202,   203,   203,   204,   205,   204,   207,   206,   208,
     209,   208,   208,   208,   208,   208,   210,   210,   211,   210,
     212,   210,   213,   213,   214,   215,   214,   216,   216,   217,
     217,   219,   218,   220,   218,   221,   221,   223,   222,   224,
     222,   225,   222,   226,   227,   226,   228,   228,   229,   229,
     229,   229,   229,   230,   231,   230,   232,   232,   234,   235,
     233,   236,   236,   237,   238,   237
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
       3,     1,     2,     3,     1,     0,     3,     1,     0,     3,
       1,     0,     3,     1,     0,     3,     1,     0,     3,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     0,     6,     2,     1,     1,     0,     2,     0,     3,
       2,     0,     4,     1,     0,     3,     1,     0,     3,     1,
       0,     2,     0,     4,     0,     3,     0,     4,     1,     0,
       6,     0,     0,     5,     0,     3,     4,     1,     3,     0,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       4,     2,     1,     1,     3,     3,     4,     6,     5,     5,
       6,     5,     4,     4,     0,     5,     0,     1,     1,     3,
       2,     2,     1,     1,     2,     3,     1,     1,     0,     4,
       2,     2,     1,     1,     3,     0,     3,     0,     1,     2,
       1,     1,     3,     2,     3,     5,     4,     5,     4,     3,
       3,     3,     4,     6,     5,     5,     6,     4,     4,     2,
       3,     3,     4,     3,     4,     1,     2,     2,     1,     4,
       3,     2,     1,     2,     3,     0,     3,     0,     8,     1,
       0,     2,     1,     1,     1,     1,     3,     3,     0,     5,
       0,     4,     2,     3,     1,     0,     3,     1,     1,     1,
       2,     0,     7,     0,     6,     0,     2,     0,     6,     0,
       8,     0,     6,     4,     0,     5,     0,     1,     3,     2,
       2,     2,     3,     1,     0,     3,     1,     1,     0,     0,
       6,     0,     1,     1,     0,     3
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
#line 130 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2533 "C_grammar.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 135 "C_grammar.y"
              {in_ordinary_id_declaration = 0; current_scope++;}
#line 2539 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' $@1 compound_statement ')'  */
#line 136 "C_grammar.y"
                {pop_scope(&current_scope);
		 size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2550 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 143 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2560 "C_grammar.tab.c"
    break;

  case 8: /* primary_expression: generic_selection  */
#line 148 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2566 "C_grammar.tab.c"
    break;

  case 14: /* string: FUNC_NAME  */
#line 163 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2572 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 183 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2583 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' ')'  */
#line 190 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2593 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 196 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2604 "C_grammar.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 202 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2610 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression $@2 '.' IDENTIFIER  */
#line 203 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2622 "C_grammar.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 210 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2628 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression $@3 PTR_OP IDENTIFIER  */
#line 211 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2640 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression INC_OP  */
#line 219 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2650 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression DEC_OP  */
#line 225 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2660 "C_grammar.tab.c"
    break;

  case 30: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 231 "C_grammar.y"
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
#line 2678 "C_grammar.tab.c"
    break;

  case 31: /* comma_opt: %empty  */
#line 247 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2684 "C_grammar.tab.c"
    break;

  case 32: /* comma_opt: ','  */
#line 248 "C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2690 "C_grammar.tab.c"
    break;

  case 34: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 255 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2701 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: unary_inc_dec unary_expression  */
#line 266 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2712 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: unary_operator cast_expression  */
#line 273 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2723 "C_grammar.tab.c"
    break;

  case 38: /* unary_expression: SIZEOF unary_expression  */
#line 280 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2733 "C_grammar.tab.c"
    break;

  case 39: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 286 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2743 "C_grammar.tab.c"
    break;

  case 40: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 292 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2753 "C_grammar.tab.c"
    break;

  case 41: /* unary_inc_dec: INC_OP  */
#line 300 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2759 "C_grammar.tab.c"
    break;

  case 42: /* unary_inc_dec: DEC_OP  */
#line 301 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2765 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '&'  */
#line 305 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2771 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '*'  */
#line 306 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2777 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '+'  */
#line 307 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2783 "C_grammar.tab.c"
    break;

  case 46: /* unary_operator: '-'  */
#line 308 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2789 "C_grammar.tab.c"
    break;

  case 47: /* unary_operator: '~'  */
#line 309 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2795 "C_grammar.tab.c"
    break;

  case 48: /* unary_operator: '!'  */
#line 310 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2801 "C_grammar.tab.c"
    break;

  case 50: /* cast_expression: '(' type_name ')' cast_expression  */
#line 316 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2812 "C_grammar.tab.c"
    break;

  case 52: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 327 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2824 "C_grammar.tab.c"
    break;

  case 53: /* multiplicative_expression_op: '*'  */
#line 337 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2830 "C_grammar.tab.c"
    break;

  case 54: /* multiplicative_expression_op: '/'  */
#line 338 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2836 "C_grammar.tab.c"
    break;

  case 55: /* multiplicative_expression_op: '%'  */
#line 339 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2842 "C_grammar.tab.c"
    break;

  case 57: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 345 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2854 "C_grammar.tab.c"
    break;

  case 58: /* additive_expression_op: '+'  */
#line 355 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2860 "C_grammar.tab.c"
    break;

  case 59: /* additive_expression_op: '-'  */
#line 356 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2866 "C_grammar.tab.c"
    break;

  case 61: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 362 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2878 "C_grammar.tab.c"
    break;

  case 62: /* shift_expression_op: LEFT_OP  */
#line 372 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2884 "C_grammar.tab.c"
    break;

  case 63: /* shift_expression_op: RIGHT_OP  */
#line 373 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2890 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 379 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2902 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression_operator: '<'  */
#line 389 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2908 "C_grammar.tab.c"
    break;

  case 67: /* relational_expression_operator: '>'  */
#line 390 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2914 "C_grammar.tab.c"
    break;

  case 68: /* relational_expression_operator: LE_OP  */
#line 391 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2920 "C_grammar.tab.c"
    break;

  case 69: /* relational_expression_operator: GE_OP  */
#line 392 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2926 "C_grammar.tab.c"
    break;

  case 71: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 399 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2938 "C_grammar.tab.c"
    break;

  case 72: /* equality_expression_op: EQ_OP  */
#line 409 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2944 "C_grammar.tab.c"
    break;

  case 73: /* equality_expression_op: NE_OP  */
#line 410 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2950 "C_grammar.tab.c"
    break;

  case 75: /* and_expression: and_expression '&' equality_expression  */
#line 416 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2961 "C_grammar.tab.c"
    break;

  case 77: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 427 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2972 "C_grammar.tab.c"
    break;

  case 79: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 438 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2983 "C_grammar.tab.c"
    break;

  case 81: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 449 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2994 "C_grammar.tab.c"
    break;

  case 83: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 460 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3005 "C_grammar.tab.c"
    break;

  case 85: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 471 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3017 "C_grammar.tab.c"
    break;

  case 87: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 483 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3029 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: '='  */
#line 493 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 3035 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: MUL_ASSIGN  */
#line 494 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 3041 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: DIV_ASSIGN  */
#line 495 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 3047 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: MOD_ASSIGN  */
#line 496 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 3053 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: ADD_ASSIGN  */
#line 497 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 3059 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: SUB_ASSIGN  */
#line 498 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 3065 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: LEFT_ASSIGN  */
#line 499 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 3071 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: RIGHT_ASSIGN  */
#line 500 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 3077 "C_grammar.tab.c"
    break;

  case 96: /* assignment_operator: AND_ASSIGN  */
#line 501 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 3083 "C_grammar.tab.c"
    break;

  case 97: /* assignment_operator: XOR_ASSIGN  */
#line 502 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3089 "C_grammar.tab.c"
    break;

  case 98: /* assignment_operator: OR_ASSIGN  */
#line 503 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3095 "C_grammar.tab.c"
    break;

  case 100: /* expression: expression ',' assignment_expression  */
#line 509 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3106 "C_grammar.tab.c"
    break;

  case 102: /* declaration: declaration_specifiers ';'  */
#line 524 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 printf("end of stand alone declaration specifier as a declaration in_ordinary_id_declaration is %d on line %d\n", in_ordinary_id_declaration, yylineno);
		 size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3118 "C_grammar.tab.c"
    break;

  case 103: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 532 "C_grammar.y"
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
#line 3134 "C_grammar.tab.c"
    break;

  case 104: /* declaration: static_assert_declaration  */
#line 544 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3145 "C_grammar.tab.c"
    break;

  case 105: /* $@4: %empty  */
#line 554 "C_grammar.y"
                                  {check_for_typedef = 1;}
#line 3151 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: storage_class_specifier $@4 declaration_specifiers  */
#line 555 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3164 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: storage_class_specifier  */
#line 564 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 check_for_typedef = 0;
		}
#line 3172 "C_grammar.tab.c"
    break;

  case 108: /* $@5: %empty  */
#line 567 "C_grammar.y"
                         {printf("declaration_specifiers is %s on line %d\n", (yyvsp[0].id), yylineno); check_for_typedef = 1;}
#line 3178 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: type_specifier $@5 declaration_specifiers  */
#line 568 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3191 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: type_specifier  */
#line 577 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 check_for_typedef = 0;
		}
#line 3199 "C_grammar.tab.c"
    break;

  case 111: /* $@6: %empty  */
#line 580 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3205 "C_grammar.tab.c"
    break;

  case 112: /* declaration_specifiers: type_qualifier $@6 declaration_specifiers  */
#line 581 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3218 "C_grammar.tab.c"
    break;

  case 113: /* declaration_specifiers: type_qualifier  */
#line 589 "C_grammar.y"
                         {in_ordinary_id_declaration = 1; check_for_typedef = 0;}
#line 3224 "C_grammar.tab.c"
    break;

  case 114: /* $@7: %empty  */
#line 590 "C_grammar.y"
                             {check_for_typedef = 1;}
#line 3230 "C_grammar.tab.c"
    break;

  case 115: /* declaration_specifiers: function_specifier $@7 declaration_specifiers  */
#line 591 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); 
		}
#line 3239 "C_grammar.tab.c"
    break;

  case 116: /* declaration_specifiers: function_specifier  */
#line 596 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); 
		}
#line 3248 "C_grammar.tab.c"
    break;

  case 117: /* $@8: %empty  */
#line 600 "C_grammar.y"
                              {check_for_typedef = 1;}
#line 3254 "C_grammar.tab.c"
    break;

  case 118: /* declaration_specifiers: alignment_specifier $@8 declaration_specifiers  */
#line 601 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); 
		}
#line 3263 "C_grammar.tab.c"
    break;

  case 119: /* declaration_specifiers: alignment_specifier  */
#line 606 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); 
		}
#line 3272 "C_grammar.tab.c"
    break;

  case 120: /* init_declarator_list: init_declarator  */
#line 614 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 (yyval.id) = (yyvsp[0].id);
		}
#line 3280 "C_grammar.tab.c"
    break;

  case 121: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 618 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3292 "C_grammar.tab.c"
    break;

  case 122: /* init_declarator: declarator '=' initializer  */
#line 629 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));
	  	}
#line 3304 "C_grammar.tab.c"
    break;

  case 123: /* init_declarator: declarator  */
#line 637 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_id(current_scope, (yyvsp[0].declarator_type).ptr_declarator, 1);	//the id as a TYPEDEF_NAME is added to the data structures keeping track of typedef_names and ids shadowing
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3315 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: TYPEDEF  */
#line 647 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3324 "C_grammar.tab.c"
    break;

  case 125: /* storage_class_specifier: EXTERN  */
#line 651 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3330 "C_grammar.tab.c"
    break;

  case 126: /* storage_class_specifier: STATIC  */
#line 652 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3336 "C_grammar.tab.c"
    break;

  case 127: /* storage_class_specifier: THREAD_LOCAL  */
#line 653 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3342 "C_grammar.tab.c"
    break;

  case 128: /* storage_class_specifier: AUTO  */
#line 654 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3348 "C_grammar.tab.c"
    break;

  case 129: /* storage_class_specifier: REGISTER  */
#line 655 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3354 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: VOID  */
#line 659 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "void"); }
#line 3360 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: CHAR  */
#line 660 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "char"); }
#line 3366 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: SHORT  */
#line 661 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "short"); }
#line 3372 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: INT  */
#line 662 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int"); }
#line 3378 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: LONG  */
#line 663 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "long"); }
#line 3384 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: FLOAT  */
#line 664 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float"); }
#line 3390 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: DOUBLE  */
#line 665 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "double"); }
#line 3396 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: SIGNED  */
#line 666 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3402 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: UNSIGNED  */
#line 667 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3408 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: BOOL  */
#line 668 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3414 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: COMPLEX  */
#line 669 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3420 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: IMAGINARY  */
#line 670 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3426 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: atomic_type_specifier  */
#line 671 "C_grammar.y"
                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3432 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: struct_or_union_specifier  */
#line 672 "C_grammar.y"
                                    { in_ordinary_id_declaration = 1; }
#line 3438 "C_grammar.tab.c"
    break;

  case 144: /* type_specifier: enum_specifier  */
#line 673 "C_grammar.y"
                                        { in_ordinary_id_declaration = 1; }
#line 3444 "C_grammar.tab.c"
    break;

  case 145: /* type_specifier: TYPEDEF_NAME  */
#line 675 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3453 "C_grammar.tab.c"
    break;

  case 146: /* type_specifier: INT128  */
#line 679 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int128"); }
#line 3459 "C_grammar.tab.c"
    break;

  case 147: /* type_specifier: FLOAT128  */
#line 680 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float128"); }
#line 3465 "C_grammar.tab.c"
    break;

  case 148: /* type_specifier: VA_LIST  */
#line 681 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "va_list"); }
#line 3471 "C_grammar.tab.c"
    break;

  case 149: /* $@9: %empty  */
#line 685 "C_grammar.y"
                              {in_tag_declaration = 0;}
#line 3477 "C_grammar.tab.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union '{' $@9 struct_declaration_list '}'  */
#line 686 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3488 "C_grammar.tab.c"
    break;

  case 151: /* $@10: %empty  */
#line 692 "C_grammar.y"
                                     {in_tag_declaration = 0;}
#line 3494 "C_grammar.tab.c"
    break;

  case 152: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@10 '{' struct_declaration_list '}'  */
#line 693 "C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3508 "C_grammar.tab.c"
    break;

  case 153: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 703 "C_grammar.y"
                {in_tag_declaration = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3522 "C_grammar.tab.c"
    break;

  case 154: /* struct_or_union: STRUCT  */
#line 716 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_declaration = 1;
		}
#line 3531 "C_grammar.tab.c"
    break;

  case 155: /* struct_or_union: UNION  */
#line 721 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_declaration = 1;
		}
#line 3540 "C_grammar.tab.c"
    break;

  case 156: /* $@11: %empty  */
#line 728 "C_grammar.y"
          {check_for_typedef = 1;}
#line 3546 "C_grammar.tab.c"
    break;

  case 157: /* struct_declaration_list: $@11 struct_declaration  */
#line 728 "C_grammar.y"
                                                      {(yyval.id) = (yyvsp[0].id); check_for_typedef = 1;}
#line 3552 "C_grammar.tab.c"
    break;

  case 158: /* $@12: %empty  */
#line 729 "C_grammar.y"
                                                     {check_for_typedef = 1;}
#line 3558 "C_grammar.tab.c"
    break;

  case 159: /* struct_declaration_list: struct_declaration_list struct_declaration $@12  */
#line 730 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	    }
#line 3569 "C_grammar.tab.c"
    break;

  case 160: /* struct_declaration: specifier_qualifier_list ';'  */
#line 740 "C_grammar.y"
                {size_t const size = strlen("anonymous_member()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3579 "C_grammar.tab.c"
    break;

  case 161: /* $@13: %empty  */
#line 746 "C_grammar.y"
                                   {in_member_namespace = 1;}
#line 3585 "C_grammar.tab.c"
    break;

  case 162: /* struct_declaration: specifier_qualifier_list $@13 struct_declarator_list ';'  */
#line 747 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3597 "C_grammar.tab.c"
    break;

  case 164: /* $@14: %empty  */
#line 758 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3603 "C_grammar.tab.c"
    break;

  case 165: /* specifier_qualifier_list: type_specifier $@14 specifier_qualifier_list  */
#line 759 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3615 "C_grammar.tab.c"
    break;

  case 166: /* specifier_qualifier_list: type_specifier  */
#line 766 "C_grammar.y"
                         {check_for_typedef = 0;}
#line 3621 "C_grammar.tab.c"
    break;

  case 167: /* $@15: %empty  */
#line 767 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3627 "C_grammar.tab.c"
    break;

  case 168: /* specifier_qualifier_list: type_qualifier $@15 specifier_qualifier_list  */
#line 768 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3639 "C_grammar.tab.c"
    break;

  case 169: /* specifier_qualifier_list: type_qualifier  */
#line 775 "C_grammar.y"
                         {check_for_typedef = 0;}
#line 3645 "C_grammar.tab.c"
    break;

  case 170: /* $@16: %empty  */
#line 779 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3651 "C_grammar.tab.c"
    break;

  case 171: /* struct_declarator_list: $@16 struct_declarator  */
#line 779 "C_grammar.y"
                                                       {(yyval.id)= (yyvsp[0].id); in_member_namespace = 1;}
#line 3657 "C_grammar.tab.c"
    break;

  case 172: /* $@17: %empty  */
#line 780 "C_grammar.y"
                                                       {in_member_namespace = 1;}
#line 3663 "C_grammar.tab.c"
    break;

  case 173: /* struct_declarator_list: struct_declarator_list ',' struct_declarator $@17  */
#line 781 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
        }
#line 3674 "C_grammar.tab.c"
    break;

  case 174: /* $@18: %empty  */
#line 790 "C_grammar.y"
          {in_member_namespace = 0;}
#line 3680 "C_grammar.tab.c"
    break;

  case 175: /* struct_declarator: $@18 ':' constant_expression  */
#line 791 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3690 "C_grammar.tab.c"
    break;

  case 176: /* $@19: %empty  */
#line 796 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 3696 "C_grammar.tab.c"
    break;

  case 177: /* struct_declarator: declarator $@19 ':' constant_expression  */
#line 797 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3708 "C_grammar.tab.c"
    break;

  case 178: /* struct_declarator: declarator  */
#line 805 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3717 "C_grammar.tab.c"
    break;

  case 179: /* $@20: %empty  */
#line 812 "C_grammar.y"
               {in_ordinary_id_declaration = 1;}
#line 3723 "C_grammar.tab.c"
    break;

  case 180: /* enum_specifier: ENUM $@20 '{' enumerator_list comma_opt '}'  */
#line 813 "C_grammar.y"
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
#line 3741 "C_grammar.tab.c"
    break;

  case 181: /* $@21: %empty  */
#line 826 "C_grammar.y"
               {in_tag_declaration = 1;}
#line 3747 "C_grammar.tab.c"
    break;

  case 182: /* $@22: %empty  */
#line 826 "C_grammar.y"
                                                    {in_tag_declaration = 0; in_ordinary_id_declaration = 1;}
#line 3753 "C_grammar.tab.c"
    break;

  case 183: /* enum_specifier: ENUM $@21 IDENTIFIER $@22 enum_specifier_rest  */
#line 827 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3765 "C_grammar.tab.c"
    break;

  case 184: /* enum_specifier_rest: %empty  */
#line 838 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3771 "C_grammar.tab.c"
    break;

  case 185: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 840 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3777 "C_grammar.tab.c"
    break;

  case 186: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 842 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3787 "C_grammar.tab.c"
    break;

  case 187: /* enumerator_list: enumerator  */
#line 850 "C_grammar.y"
                     {in_ordinary_id_declaration = 1;}
#line 3793 "C_grammar.tab.c"
    break;

  case 188: /* enumerator_list: enumerator_list ',' enumerator  */
#line 852 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3805 "C_grammar.tab.c"
    break;

  case 189: /* $@23: %empty  */
#line 862 "C_grammar.y"
                               {in_ordinary_id_declaration = 0;}
#line 3811 "C_grammar.tab.c"
    break;

  case 190: /* enumerator: enumeration_constant $@23 '=' constant_expression  */
#line 863 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[0].id));
        }
#line 3822 "C_grammar.tab.c"
    break;

  case 193: /* type_qualifier: CONST  */
#line 877 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3828 "C_grammar.tab.c"
    break;

  case 194: /* type_qualifier: RESTRICT  */
#line 878 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3834 "C_grammar.tab.c"
    break;

  case 195: /* type_qualifier: VOLATILE  */
#line 879 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3840 "C_grammar.tab.c"
    break;

  case 196: /* type_qualifier: ATOMIC  */
#line 880 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3846 "C_grammar.tab.c"
    break;

  case 197: /* function_specifier: INLINE  */
#line 884 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3852 "C_grammar.tab.c"
    break;

  case 198: /* function_specifier: NORETURN  */
#line 885 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3858 "C_grammar.tab.c"
    break;

  case 201: /* declarator: pointer direct_declarator  */
#line 896 "C_grammar.y"
          {in_ordinary_id_declaration = 0;
	   size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3871 "C_grammar.tab.c"
    break;

  case 202: /* declarator: direct_declarator  */
#line 904 "C_grammar.y"
                            {in_ordinary_id_declaration = 0;}
#line 3877 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: IDENTIFIER  */
#line 909 "C_grammar.y"
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
#line 3904 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: '(' declarator ')'  */
#line 933 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-1].declarator_type);}
#line 3910 "C_grammar.tab.c"
    break;

  case 205: /* direct_declarator: direct_declarator '[' ']'  */
#line 935 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3921 "C_grammar.tab.c"
    break;

  case 206: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 942 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3930 "C_grammar.tab.c"
    break;

  case 207: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 947 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3939 "C_grammar.tab.c"
    break;

  case 208: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 952 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3948 "C_grammar.tab.c"
    break;

  case 209: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 957 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3957 "C_grammar.tab.c"
    break;

  case 210: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 962 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3966 "C_grammar.tab.c"
    break;

  case 211: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 967 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3975 "C_grammar.tab.c"
    break;

  case 212: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 972 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3984 "C_grammar.tab.c"
    break;

  case 213: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 977 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3996 "C_grammar.tab.c"
    break;

  case 214: /* $@24: %empty  */
#line 984 "C_grammar.y"
                            {in_ordinary_id_declaration = 0; current_scope++;}
#line 4002 "C_grammar.tab.c"
    break;

  case 215: /* direct_declarator: direct_declarator $@24 '(' rest_function_definition ')'  */
#line 985 "C_grammar.y"
                {handled_function_paramaters = 1;
		 in_ordinary_id_declaration = 0;
		 size_t const size = strlen("function(, )") + strlen((yyvsp[-4].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-4].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-4].declarator_type).full);
	     free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 4017 "C_grammar.tab.c"
    break;

  case 216: /* rest_function_definition: %empty  */
#line 998 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 4023 "C_grammar.tab.c"
    break;

  case 218: /* rest_function_definition: old_style_parameter_list  */
#line 1000 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 4029 "C_grammar.tab.c"
    break;

  case 219: /* pointer: '*' type_qualifier_list pointer  */
#line 1005 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4040 "C_grammar.tab.c"
    break;

  case 220: /* pointer: '*' type_qualifier_list  */
#line 1012 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 4050 "C_grammar.tab.c"
    break;

  case 221: /* pointer: '*' pointer  */
#line 1018 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4060 "C_grammar.tab.c"
    break;

  case 222: /* pointer: '*'  */
#line 1024 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 4066 "C_grammar.tab.c"
    break;

  case 224: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1030 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4077 "C_grammar.tab.c"
    break;

  case 225: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1040 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 4087 "C_grammar.tab.c"
    break;

  case 226: /* parameter_type_list: parameter_list  */
#line 1046 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 4097 "C_grammar.tab.c"
    break;

  case 227: /* parameter_list: parameter_declaration  */
#line 1054 "C_grammar.y"
                                {check_for_typedef = 1;}
#line 4103 "C_grammar.tab.c"
    break;

  case 228: /* $@25: %empty  */
#line 1055 "C_grammar.y"
                                                   {check_for_typedef = 1;}
#line 4109 "C_grammar.tab.c"
    break;

  case 229: /* parameter_list: parameter_list ',' parameter_declaration $@25  */
#line 1056 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 4120 "C_grammar.tab.c"
    break;

  case 230: /* parameter_declaration: declaration_specifiers declarator  */
#line 1066 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 4132 "C_grammar.tab.c"
    break;

  case 231: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1074 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 4143 "C_grammar.tab.c"
    break;

  case 232: /* parameter_declaration: declaration_specifiers  */
#line 1081 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 4153 "C_grammar.tab.c"
    break;

  case 235: /* $@26: %empty  */
#line 1094 "C_grammar.y"
          {check_for_typedef = 1;}
#line 4159 "C_grammar.tab.c"
    break;

  case 236: /* type_name: $@26 specifier_qualifier_list abstract_declarator_opt  */
#line 1095 "C_grammar.y"
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
#line 4174 "C_grammar.tab.c"
    break;

  case 237: /* abstract_declarator_opt: %empty  */
#line 1108 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4180 "C_grammar.tab.c"
    break;

  case 238: /* abstract_declarator_opt: abstract_declarator  */
#line 1109 "C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 4186 "C_grammar.tab.c"
    break;

  case 263: /* initializer: '{' initializer_list '}'  */
#line 1144 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4196 "C_grammar.tab.c"
    break;

  case 264: /* initializer: '{' initializer_list ',' '}'  */
#line 1150 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 4206 "C_grammar.tab.c"
    break;

  case 266: /* initializer: '{' '}'  */
#line 1157 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 4212 "C_grammar.tab.c"
    break;

  case 267: /* initializer_list: designation initializer  */
#line 1162 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4223 "C_grammar.tab.c"
    break;

  case 269: /* initializer_list: initializer_list ',' designation initializer  */
#line 1170 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4235 "C_grammar.tab.c"
    break;

  case 270: /* initializer_list: initializer_list ',' initializer  */
#line 1178 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4246 "C_grammar.tab.c"
    break;

  case 271: /* designation: designator_list '='  */
#line 1188 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4256 "C_grammar.tab.c"
    break;

  case 273: /* designator_list: designator_list designator  */
#line 1198 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4267 "C_grammar.tab.c"
    break;

  case 274: /* designator: '[' constant_expression ']'  */
#line 1208 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4277 "C_grammar.tab.c"
    break;

  case 275: /* $@27: %empty  */
#line 1213 "C_grammar.y"
          {in_member_namespace = 1;}
#line 4283 "C_grammar.tab.c"
    break;

  case 276: /* designator: $@27 '.' IDENTIFIER  */
#line 1214 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4294 "C_grammar.tab.c"
    break;

  case 277: /* $@28: %empty  */
#line 1223 "C_grammar.y"
                        {check_for_typedef = 0;}
#line 4300 "C_grammar.tab.c"
    break;

  case 278: /* static_assert_declaration: STATIC_ASSERT $@28 '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1224 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4311 "C_grammar.tab.c"
    break;

  case 280: /* $@29: %empty  */
#line 1234 "C_grammar.y"
          {in_ordinary_id_declaration = 0; current_scope++;}
#line 4317 "C_grammar.tab.c"
    break;

  case 281: /* statement: $@29 compound_statement  */
#line 1235 "C_grammar.y"
                {pop_scope(&current_scope);
		 (yyval.id) = (yyvsp[0].id);
		}
#line 4325 "C_grammar.tab.c"
    break;

  case 286: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1246 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4336 "C_grammar.tab.c"
    break;

  case 287: /* labeled_statement: TYPEDEF_NAME ':' statement  */
#line 1254 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4347 "C_grammar.tab.c"
    break;

  case 288: /* $@30: %empty  */
#line 1260 "C_grammar.y"
               {check_for_typedef = 0;}
#line 4353 "C_grammar.tab.c"
    break;

  case 289: /* labeled_statement: CASE $@30 constant_expression ':' statement  */
#line 1261 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4364 "C_grammar.tab.c"
    break;

  case 290: /* $@31: %empty  */
#line 1267 "C_grammar.y"
                  {check_for_typedef = 0;}
#line 4370 "C_grammar.tab.c"
    break;

  case 291: /* labeled_statement: DEFAULT $@31 ':' statement  */
#line 1268 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4380 "C_grammar.tab.c"
    break;

  case 292: /* compound_statement: '{' '}'  */
#line 1276 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4386 "C_grammar.tab.c"
    break;

  case 293: /* compound_statement: '{' block_item_list '}'  */
#line 1278 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4396 "C_grammar.tab.c"
    break;

  case 294: /* block_item_list: block_item  */
#line 1286 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 4402 "C_grammar.tab.c"
    break;

  case 295: /* $@32: %empty  */
#line 1287 "C_grammar.y"
                                     {in_ordinary_id_declaration = 0;}
#line 4408 "C_grammar.tab.c"
    break;

  case 296: /* block_item_list: block_item_list block_item $@32  */
#line 1288 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	  }
#line 4419 "C_grammar.tab.c"
    break;

  case 299: /* expression_statement: ';'  */
#line 1302 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4425 "C_grammar.tab.c"
    break;

  case 300: /* expression_statement: expression ';'  */
#line 1304 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4435 "C_grammar.tab.c"
    break;

  case 301: /* $@33: %empty  */
#line 1312 "C_grammar.y"
             {check_for_typedef = 0;}
#line 4441 "C_grammar.tab.c"
    break;

  case 302: /* selection_statement: IF $@33 '(' expression ')' statement else_opt  */
#line 1313 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4453 "C_grammar.tab.c"
    break;

  case 303: /* $@34: %empty  */
#line 1320 "C_grammar.y"
                 {check_for_typedef = 0;}
#line 4459 "C_grammar.tab.c"
    break;

  case 304: /* selection_statement: SWITCH $@34 '(' expression ')' statement  */
#line 1321 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4470 "C_grammar.tab.c"
    break;

  case 305: /* else_opt: %empty  */
#line 1330 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4476 "C_grammar.tab.c"
    break;

  case 306: /* else_opt: ELSE statement  */
#line 1332 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4486 "C_grammar.tab.c"
    break;

  case 307: /* $@35: %empty  */
#line 1339 "C_grammar.y"
                {check_for_typedef = 0;}
#line 4492 "C_grammar.tab.c"
    break;

  case 308: /* iteration_statement: WHILE $@35 '(' expression ')' statement  */
#line 1340 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4503 "C_grammar.tab.c"
    break;

  case 309: /* $@36: %empty  */
#line 1346 "C_grammar.y"
             {check_for_typedef = 0;}
#line 4509 "C_grammar.tab.c"
    break;

  case 310: /* iteration_statement: DO $@36 statement WHILE '(' expression ')' ';'  */
#line 1347 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4520 "C_grammar.tab.c"
    break;

  case 311: /* $@37: %empty  */
#line 1353 "C_grammar.y"
              {check_for_typedef = 0;}
#line 4526 "C_grammar.tab.c"
    break;

  case 312: /* iteration_statement: FOR $@37 '(' for_stmt_type ')' statement  */
#line 1354 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4539 "C_grammar.tab.c"
    break;

  case 313: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1366 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4545 "C_grammar.tab.c"
    break;

  case 314: /* $@38: %empty  */
#line 1367 "C_grammar.y"
          {check_for_typedef = 1;}
#line 4551 "C_grammar.tab.c"
    break;

  case 315: /* for_stmt_type: $@38 declaration expression_opt ';' expression_opt  */
#line 1368 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4557 "C_grammar.tab.c"
    break;

  case 316: /* expression_opt: %empty  */
#line 1372 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4563 "C_grammar.tab.c"
    break;

  case 318: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1377 "C_grammar.y"
          {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4574 "C_grammar.tab.c"
    break;

  case 319: /* jump_statement: CONTINUE ';'  */
#line 1383 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4580 "C_grammar.tab.c"
    break;

  case 320: /* jump_statement: BREAK ';'  */
#line 1384 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4586 "C_grammar.tab.c"
    break;

  case 321: /* jump_statement: RETURN ';'  */
#line 1385 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4592 "C_grammar.tab.c"
    break;

  case 322: /* jump_statement: RETURN expression ';'  */
#line 1387 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4602 "C_grammar.tab.c"
    break;

  case 323: /* translation_unit: external_declaration  */
#line 1396 "C_grammar.y"
                               {check_for_typedef = 1;}
#line 4608 "C_grammar.tab.c"
    break;

  case 324: /* $@39: %empty  */
#line 1397 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4614 "C_grammar.tab.c"
    break;

  case 325: /* translation_unit: translation_unit $@39 external_declaration  */
#line 1397 "C_grammar.y"
                                                                            {check_for_typedef = 1;}
#line 4620 "C_grammar.tab.c"
    break;

  case 326: /* external_declaration: function_definition  */
#line 1402 "C_grammar.y"
                {handled_function_paramaters = 0;
		 pop_scope(&current_scope);
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4630 "C_grammar.tab.c"
    break;

  case 327: /* external_declaration: declaration  */
#line 1408 "C_grammar.y"
                {if(handled_function_paramaters) {
			handled_function_paramaters = 0;
			pop_scope(&current_scope);
		 }
		 fprintf(pl_file, "%s", (yyvsp[0].id)); 
		 free((yyvsp[0].id));
		}
#line 4642 "C_grammar.tab.c"
    break;

  case 328: /* $@40: %empty  */
#line 1418 "C_grammar.y"
                                            {check_for_typedef = 1;}
#line 4648 "C_grammar.tab.c"
    break;

  case 329: /* $@41: %empty  */
#line 1418 "C_grammar.y"
                                                                                          {in_ordinary_id_declaration = 0;}
#line 4654 "C_grammar.tab.c"
    break;

  case 330: /* function_definition: declaration_specifiers declarator $@40 declaration_list_opt $@41 compound_statement  */
#line 1419 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-4].declarator_type).full) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-5].id), (yyvsp[-4].declarator_type).full, (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-5].id));
		 free((yyvsp[-4].declarator_type).full);
		 free((yyvsp[-4].declarator_type).ptr_declarator);
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4669 "C_grammar.tab.c"
    break;

  case 331: /* declaration_list_opt: %empty  */
#line 1432 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4675 "C_grammar.tab.c"
    break;

  case 333: /* old_style_declaration_list: declaration  */
#line 1437 "C_grammar.y"
                      {check_for_typedef = 1;}
#line 4681 "C_grammar.tab.c"
    break;

  case 334: /* $@42: %empty  */
#line 1438 "C_grammar.y"
                                                 {check_for_typedef = 1;}
#line 4687 "C_grammar.tab.c"
    break;

  case 335: /* old_style_declaration_list: old_style_declaration_list declaration $@42  */
#line 1439 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 4698 "C_grammar.tab.c"
    break;


#line 4702 "C_grammar.tab.c"

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

#line 1447 "C_grammar.y"

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

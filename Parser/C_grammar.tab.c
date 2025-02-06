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

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements
void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 128 "C_grammar.tab.c"

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
#line 65 "C_grammar.y"

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

#line 268 "C_grammar.tab.c"

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
  YYSYMBOL_114_1 = 114,                    /* $@1  */
  YYSYMBOL_115_2 = 115,                    /* $@2  */
  YYSYMBOL_comma_opt = 116,                /* comma_opt  */
  YYSYMBOL_argument_expression_list = 117, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 118,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 119,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 120,           /* unary_operator  */
  YYSYMBOL_cast_expression = 121,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 122, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 123, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 124,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 125,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 126,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 127,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 128,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 129, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 130,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 131,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 132,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 133,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 134,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 135,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 136,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 137,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 138,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 139,      /* assignment_operator  */
  YYSYMBOL_expression = 140,               /* expression  */
  YYSYMBOL_constant_expression = 141,      /* constant_expression  */
  YYSYMBOL_declaration = 142,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 143,   /* declaration_specifiers  */
  YYSYMBOL_144_3 = 144,                    /* $@3  */
  YYSYMBOL_145_4 = 145,                    /* $@4  */
  YYSYMBOL_146_5 = 146,                    /* $@5  */
  YYSYMBOL_147_6 = 147,                    /* $@6  */
  YYSYMBOL_148_7 = 148,                    /* $@7  */
  YYSYMBOL_init_declarator_list = 149,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 150,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 151,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 152,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 153, /* struct_or_union_specifier  */
  YYSYMBOL_154_8 = 154,                    /* $@8  */
  YYSYMBOL_155_9 = 155,                    /* $@9  */
  YYSYMBOL_struct_or_union = 156,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 157,  /* struct_declaration_list  */
  YYSYMBOL_158_10 = 158,                   /* $@10  */
  YYSYMBOL_159_11 = 159,                   /* $@11  */
  YYSYMBOL_struct_declaration = 160,       /* struct_declaration  */
  YYSYMBOL_161_12 = 161,                   /* $@12  */
  YYSYMBOL_specifier_qualifier_list = 162, /* specifier_qualifier_list  */
  YYSYMBOL_163_13 = 163,                   /* $@13  */
  YYSYMBOL_164_14 = 164,                   /* $@14  */
  YYSYMBOL_struct_declarator_list = 165,   /* struct_declarator_list  */
  YYSYMBOL_166_15 = 166,                   /* $@15  */
  YYSYMBOL_167_16 = 167,                   /* $@16  */
  YYSYMBOL_struct_declarator = 168,        /* struct_declarator  */
  YYSYMBOL_169_17 = 169,                   /* $@17  */
  YYSYMBOL_170_18 = 170,                   /* $@18  */
  YYSYMBOL_enum_specifier = 171,           /* enum_specifier  */
  YYSYMBOL_172_19 = 172,                   /* $@19  */
  YYSYMBOL_173_20 = 173,                   /* $@20  */
  YYSYMBOL_174_21 = 174,                   /* $@21  */
  YYSYMBOL_enum_specifier_rest = 175,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 176,          /* enumerator_list  */
  YYSYMBOL_enumerator = 177,               /* enumerator  */
  YYSYMBOL_178_22 = 178,                   /* $@22  */
  YYSYMBOL_atomic_type_specifier = 179,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 180,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 181,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 182,      /* alignment_specifier  */
  YYSYMBOL_declarator = 183,               /* declarator  */
  YYSYMBOL_direct_declarator = 184,        /* direct_declarator  */
  YYSYMBOL_185_23 = 185,                   /* $@23  */
  YYSYMBOL_rest_function_definition = 186, /* rest_function_definition  */
  YYSYMBOL_pointer = 187,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 188,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 189,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 190,           /* parameter_list  */
  YYSYMBOL_191_24 = 191,                   /* $@24  */
  YYSYMBOL_parameter_declaration = 192,    /* parameter_declaration  */
  YYSYMBOL_old_style_parameter_list = 193, /* old_style_parameter_list  */
  YYSYMBOL_type_name = 194,                /* type_name  */
  YYSYMBOL_195_25 = 195,                   /* $@25  */
  YYSYMBOL_abstract_declarator_opt = 196,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 197,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 198, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 199,              /* initializer  */
  YYSYMBOL_initializer_list = 200,         /* initializer_list  */
  YYSYMBOL_designation = 201,              /* designation  */
  YYSYMBOL_designator_list = 202,          /* designator_list  */
  YYSYMBOL_designator = 203,               /* designator  */
  YYSYMBOL_204_26 = 204,                   /* $@26  */
  YYSYMBOL_static_assert_declaration = 205, /* static_assert_declaration  */
  YYSYMBOL_206_27 = 206,                   /* $@27  */
  YYSYMBOL_statement = 207,                /* statement  */
  YYSYMBOL_labeled_statement = 208,        /* labeled_statement  */
  YYSYMBOL_209_28 = 209,                   /* $@28  */
  YYSYMBOL_210_29 = 210,                   /* $@29  */
  YYSYMBOL_compound_statement = 211,       /* compound_statement  */
  YYSYMBOL_212_30 = 212,                   /* $@30  */
  YYSYMBOL_block_item_list = 213,          /* block_item_list  */
  YYSYMBOL_214_31 = 214,                   /* $@31  */
  YYSYMBOL_block_item = 215,               /* block_item  */
  YYSYMBOL_expression_statement = 216,     /* expression_statement  */
  YYSYMBOL_selection_statement = 217,      /* selection_statement  */
  YYSYMBOL_218_32 = 218,                   /* $@32  */
  YYSYMBOL_219_33 = 219,                   /* $@33  */
  YYSYMBOL_else_opt = 220,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 221,      /* iteration_statement  */
  YYSYMBOL_222_34 = 222,                   /* $@34  */
  YYSYMBOL_223_35 = 223,                   /* $@35  */
  YYSYMBOL_224_36 = 224,                   /* $@36  */
  YYSYMBOL_for_stmt_type = 225,            /* for_stmt_type  */
  YYSYMBOL_226_37 = 226,                   /* $@37  */
  YYSYMBOL_expression_opt = 227,           /* expression_opt  */
  YYSYMBOL_jump_statement = 228,           /* jump_statement  */
  YYSYMBOL_translation_unit = 229,         /* translation_unit  */
  YYSYMBOL_230_38 = 230,                   /* $@38  */
  YYSYMBOL_external_declaration = 231,     /* external_declaration  */
  YYSYMBOL_function_definition = 232,      /* function_definition  */
  YYSYMBOL_233_39 = 233,                   /* $@39  */
  YYSYMBOL_declaration_list_opt = 234,     /* declaration_list_opt  */
  YYSYMBOL_old_style_declaration_list = 235, /* old_style_declaration_list  */
  YYSYMBOL_236_40 = 236                    /* $@40  */
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
#define YYLAST   2126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  132
/* YYNRULES -- Number of rules.  */
#define YYNRULES  333
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  526

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
       0,   127,   127,   131,   132,   133,   139,   145,   149,   150,
     151,   155,   159,   160,   164,   168,   169,   173,   174,   178,
     179,   186,   192,   199,   199,   207,   207,   215,   221,   227,
     244,   245,   250,   251,   261,   262,   269,   276,   282,   288,
     297,   298,   302,   303,   304,   305,   306,   307,   311,   312,
     322,   323,   334,   335,   336,   340,   341,   352,   353,   357,
     358,   369,   370,   374,   375,   386,   387,   388,   389,   394,
     395,   406,   407,   411,   412,   422,   423,   433,   434,   444,
     445,   455,   456,   466,   467,   478,   479,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   504,   505,
     515,   520,   528,   540,   550,   550,   559,   563,   563,   572,
     577,   577,   586,   587,   587,   592,   597,   597,   602,   610,
     614,   625,   633,   643,   648,   649,   650,   651,   652,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   676,   677,   678,   682,   682,
     689,   689,   699,   712,   717,   725,   725,   726,   726,   736,
     743,   743,   751,   755,   755,   763,   764,   764,   772,   776,
     776,   777,   777,   787,   787,   793,   793,   801,   809,   809,
     823,   823,   823,   835,   836,   838,   847,   848,   859,   859,
     866,   870,   874,   875,   876,   877,   881,   882,   886,   887,
     892,   901,   905,   928,   931,   938,   943,   948,   953,   958,
     963,   968,   973,   981,   981,   994,   995,   996,  1000,  1007,
    1013,  1019,  1024,  1025,  1035,  1041,  1050,  1051,  1051,  1061,
    1069,  1076,  1085,  1086,  1090,  1090,  1104,  1105,  1109,  1110,
    1111,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1139,  1145,  1151,  1152,  1157,  1164,  1165,  1173,
    1183,  1192,  1193,  1203,  1209,  1209,  1219,  1219,  1229,  1230,
    1231,  1232,  1233,  1234,  1238,  1246,  1253,  1253,  1260,  1260,
    1269,  1270,  1270,  1279,  1280,  1280,  1290,  1291,  1295,  1296,
    1305,  1305,  1313,  1313,  1323,  1324,  1332,  1332,  1339,  1339,
    1346,  1346,  1358,  1360,  1360,  1365,  1366,  1369,  1376,  1377,
    1378,  1379,  1389,  1390,  1390,  1394,  1395,  1399,  1399,  1413,
    1414,  1418,  1419,  1419
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
  "postfix_expression", "$@1", "$@2", "comma_opt",
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
  "declaration_specifiers", "$@3", "$@4", "$@5", "$@6", "$@7",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "$@8", "$@9",
  "struct_or_union", "struct_declaration_list", "$@10", "$@11",
  "struct_declaration", "$@12", "specifier_qualifier_list", "$@13", "$@14",
  "struct_declarator_list", "$@15", "$@16", "struct_declarator", "$@17",
  "$@18", "enum_specifier", "$@19", "$@20", "$@21", "enum_specifier_rest",
  "enumerator_list", "enumerator", "$@22", "atomic_type_specifier",
  "type_qualifier", "function_specifier", "alignment_specifier",
  "declarator", "direct_declarator", "$@23", "rest_function_definition",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "$@24", "parameter_declaration",
  "old_style_parameter_list", "type_name", "$@25",
  "abstract_declarator_opt", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "$@26",
  "static_assert_declaration", "$@27", "statement", "labeled_statement",
  "$@28", "$@29", "compound_statement", "$@30", "block_item_list", "$@31",
  "block_item", "expression_statement", "selection_statement", "$@32",
  "$@33", "else_opt", "iteration_statement", "$@34", "$@35", "$@36",
  "for_stmt_type", "$@37", "expression_opt", "jump_statement",
  "translation_unit", "$@38", "external_declaration",
  "function_definition", "$@39", "declaration_list_opt",
  "old_style_declaration_list", "$@40", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-470)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-275)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1838,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,    28,   -55,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,   237,   105,   123,  -470,
      24,  -470,  -470,   200,   207,   249,  -470,    38,  -470,  -470,
     -38,    40,  1396,   -22,  2047,   -40,  -470,    30,   304,  -470,
     -64,  -470,   -49,   -14,    13,  1943,  1943,   -36,  -470,  1943,
    1943,  1943,  -470,  1838,    67,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  1411,  -470,  -470,    14,    47,  1256,  -470,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,   294,  -470,
    1504,  1396,  -470,    -7,   -12,   183,    42,   181,    48,    43,
      54,   125,     8,  -470,    80,    88,  -470,    33,   -19,   322,
    1396,    98,  -470,  -470,   304,    30,  -470,  1272,  1838,   766,
     111,   -14,  -470,  -470,   124,  -470,  -470,  -470,  -470,  -470,
    -470,   112,   138,  -470,   146,  1256,  -470,  -470,  1396,   134,
     667,  -470,  -470,   135,   144,   156,  -470,  -470,  1365,  1396,
     164,   250,  1256,  -470,  -470,  -470,  -470,  -470,  1396,  -470,
    -470,  1396,  -470,  -470,  1396,  -470,  -470,  -470,  -470,  1396,
    -470,  -470,  1396,  1396,  1396,  1396,  1396,  1396,  1396,  -470,
    -470,  2047,  1569,   781,    73,  -470,  -470,   126,  2047,   177,
    -470,  -470,  -470,  -470,   160,  1105,  -470,  -470,  -470,   237,
     176,  1838,  1090,  -470,   190,   193,   874,  1786,  -470,  1623,
    1995,   166,    67,   191,    67,  -470,   202,   204,   210,  -470,
     564,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  1396,  -470,  1396,  1380,  -470,  -470,   137,  -470,
      37,   291,   293,   221,  -470,    -7,   -12,   183,    42,   181,
      48,    43,    54,   125,   153,  -470,  -470,   110,   230,   232,
    -470,   231,  1090,  -470,   234,   235,   889,   126,  1733,   982,
    -470,   309,  1396,  -470,  -470,   -32,  1272,   -57,  -470,   236,
    -470,  -470,   238,  1090,  -470,  -470,  1396,  -470,   241,   247,
    -470,   254,  -470,   256,  1675,  -470,  -470,   233,  -470,  -470,
    1396,  -470,  -470,    53,   257,  -470,   289,   264,   266,  -470,
    -470,  -470,  -470,  -470,  -470,  -470,   346,   258,   259,   265,
    -470,   -48,  -470,  -470,  -470,  -470,   471,  -470,  -470,  -470,
    -470,  -470,  -470,  -470,  1240,  -470,  -470,  1396,  -470,  -470,
    -470,   257,  1396,  1490,  -470,    44,  -470,  -470,  1890,  -470,
     275,  1090,  -470,  -470,  1396,  -470,   278,  -470,   283,  1090,
    -470,   280,   285,   997,   295,   292,  1131,  -470,  -470,  -470,
    -470,   380,  -470,  -470,   300,   302,  -470,  -470,  -470,   386,
    -470,  -470,  -470,  -470,  -470,    20,  -470,   307,   159,  -470,
     310,   657,   657,  1396,   313,   317,   319,   320,   657,   321,
     305,  -470,  -470,  -470,   -41,  -470,  -470,  -470,   325,  -470,
    -470,  -470,  -470,  -470,   324,   326,  -470,  -470,   328,  1090,
    -470,  -470,  1396,  -470,   329,   312,  -470,  -470,  -470,  1272,
    -470,  -470,  -470,  -470,   -39,    30,  -470,  1396,  -470,   289,
    1396,   266,  -470,  -470,   333,   657,  1396,  1396,  1396,   357,
     673,  -470,  -470,  -470,  1224,   331,  -470,  -470,  -470,  -470,
     335,   337,  -470,  -470,  -470,    30,  -470,  -470,   340,   341,
    -470,  -470,  -470,   657,  -470,   161,   165,   171,   347,  1396,
     345,  1838,  -470,  -470,  -470,  -470,  1396,   348,  -470,   657,
     657,   657,  1396,   350,   327,   657,  1396,  -470,  -470,  1396,
     369,  -470,  -470,   173,  1396,  -470,   330,  -470,   657,  -470,
     332,  -470,  1396,  -470,  -470,  -470
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   144,   123,   124,   125,   127,   128,   196,   192,   193,
     194,   138,   130,   131,   132,   133,   136,   137,   134,   135,
     129,   139,   140,   153,   154,   178,     0,   234,   195,   197,
     276,   126,   145,   146,   147,   326,     0,   104,   107,   142,
       0,   143,   141,   110,   113,   116,   103,   323,   322,   325,
       0,     0,   234,     0,     0,     0,   202,     0,   221,   101,
       0,   119,   327,   201,     0,     0,     0,   152,   148,     0,
       0,     0,     1,     0,     0,   181,     2,     8,     9,    10,
      12,    13,     0,    40,    41,     0,     0,   234,    42,    43,
      44,    45,    46,    47,    19,     3,     4,     7,    34,    48,
       0,     0,    50,    55,    59,    63,    69,    73,    75,    77,
      79,    81,    83,   100,     0,     0,   191,   163,   236,   166,
       0,     0,   222,   220,   219,     0,   102,     0,   329,     0,
       0,   200,   105,   108,     0,   155,   111,   114,   117,   324,
      11,   190,    30,   186,   183,   234,    37,   234,     0,   291,
      48,    85,    98,     0,     0,     0,    27,    28,     0,     0,
       0,     0,   234,    35,    36,    52,    53,    54,     0,    57,
      58,     0,    61,    62,     0,    67,    68,    65,    66,     0,
      71,    72,     0,     0,     0,     0,     0,     0,     0,   199,
     198,     0,     0,     0,   239,   235,   237,   240,     0,     0,
     203,   223,   218,   120,   122,   274,   264,   121,   331,     0,
       0,   330,     0,   204,    43,     0,     0,   215,   155,     0,
       0,     0,    31,     0,     0,   182,     0,     0,     0,   290,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    87,     0,     6,     0,     0,     5,    21,     0,    32,
       0,     0,     0,     0,    51,    56,    60,    64,    70,    74,
      76,    78,    80,    82,     0,   164,   258,   231,     0,   225,
     226,     0,     0,   242,    43,     0,     0,   238,     0,     0,
     167,     0,     0,   265,   267,     0,     0,   274,   271,     0,
     328,   332,     0,     0,   205,   212,     0,   211,    43,     0,
     232,     0,   216,   217,     0,   149,   157,   160,   162,   156,
       0,   187,   179,     0,    38,    39,   234,     2,   144,   286,
     288,   300,   302,   306,   308,   310,     0,     0,     0,     0,
     298,     0,   296,   297,   278,   279,     0,   293,   280,   281,
     282,   283,    86,    99,   274,    49,    22,     0,    20,    24,
      26,     0,     0,     0,   229,   239,   230,   259,     0,   241,
       0,     0,   243,   249,     0,   248,     0,   260,     0,     0,
     250,    43,     0,     0,     0,     0,   274,   262,   266,   270,
     272,     0,   333,   207,     0,     0,   208,   210,   214,     0,
     151,   158,   159,   169,   189,     0,   184,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   318,   319,   320,     0,   299,   292,   294,    30,    33,
      84,   224,   227,   245,     0,     0,   247,   261,     0,     0,
     251,   257,     0,   256,     0,     0,   273,   263,   269,     0,
     275,   206,   209,   233,     0,   173,   185,     0,    14,   234,
       0,     0,   284,   285,     0,     0,     0,     0,     0,     0,
     313,   317,   321,   295,    31,     0,   228,   244,   246,   253,
       0,     0,   254,   277,   268,   173,   161,   170,     0,   177,
      18,    16,    17,     0,   289,     0,     0,     0,     0,   315,
       0,     0,    29,   252,   255,   171,     0,     0,   287,     0,
       0,     0,     0,   316,     0,     0,   315,   172,   174,     0,
     304,   303,   307,     0,   315,   311,     0,   176,     0,   301,
       0,   312,   315,   305,   309,   314
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -470,  -470,  -470,  -470,  -470,  -470,  -470,   -10,  -470,  -470,
    -470,    17,  -470,   -52,  -470,  -470,   -81,   269,  -470,   263,
    -470,   267,  -470,   260,  -470,   268,  -470,   270,   262,   273,
     261,  -470,   -51,    23,  -470,   -84,  -116,  -123,    32,  -470,
    -470,  -470,  -470,  -470,  -470,   318,  -470,   -42,  -470,  -470,
    -470,  -470,   242,  -470,  -470,   229,  -470,   -30,  -470,  -470,
    -470,  -470,  -470,   -25,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,   239,  -213,  -470,  -470,   -47,  -470,  -470,   -34,   -58,
    -470,  -470,   -45,  -119,  -202,  -470,  -470,    95,  -470,    12,
    -470,  -470,  -104,  -176,  -110,   117,  -368,  -470,   169,  -470,
    -198,  -470,  -316,  -470,  -470,  -470,   -62,  -470,  -470,  -470,
     128,     5,  -470,  -470,  -470,  -470,  -470,  -470,  -470,  -470,
    -470,  -470,  -469,  -470,  -470,  -470,   393,  -470,  -470,  -470,
    -470,  -470
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    94,    95,   141,    96,    97,   398,   399,    98,   160,
     161,   223,   248,   150,   100,   101,   102,   103,   168,   104,
     171,   105,   174,   106,   179,   107,   182,   108,   109,   110,
     111,   112,   151,   152,   242,   331,   114,    35,   209,    65,
      66,    69,    70,    71,    60,    61,    37,    38,    39,   135,
     134,    40,   219,   220,   391,   306,   393,   307,   191,   198,
     444,   445,   507,   477,   478,   497,    41,    50,    51,   144,
     225,   142,   143,   221,    42,    43,    44,    45,   121,    63,
     130,   301,    64,   124,   268,   269,   466,   270,   303,   400,
      54,   195,   271,   197,   284,   285,   286,   287,   288,   289,
      46,    55,   333,   334,   403,   404,   335,   230,   336,   463,
     337,   338,   339,   405,   406,   519,   340,   407,   408,   409,
     490,   491,   504,   341,    47,    73,    48,    49,   128,   210,
     211,   382
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,   113,    62,   153,   199,   208,   131,   119,   439,   311,
     216,   122,   117,   123,   196,   302,    56,   207,   277,   125,
     164,   308,   308,   140,   118,   155,    52,    67,   282,   187,
     146,  -180,    36,    56,  -122,   244,  -165,   516,    72,    53,
     126,   120,   244,    75,   475,   521,   379,    56,   163,    99,
      74,   376,  -150,   525,   127,  -122,   415,   377,   175,   176,
     116,   153,   192,   462,   115,   476,   193,  -213,    99,   113,
     140,   129,    58,   194,   276,   250,   368,   201,   153,   202,
     169,   170,   122,   155,   165,   452,   453,   254,   291,   166,
     167,   204,   459,   293,    57,   147,   439,   132,   133,   154,
     155,   136,   137,   138,   264,    36,   308,   332,  -106,   446,
     188,    57,    68,    56,  -165,  -165,    99,  -165,  -165,    99,
     244,    58,    99,   348,  -165,   353,  -109,    99,   148,   193,
      99,    99,    99,    99,    99,    99,   395,  -165,   183,   484,
     177,   178,   396,   184,   119,   186,   122,   194,   290,   117,
     206,   119,   215,   361,   192,   185,   117,   226,   193,   227,
     373,   265,   189,   356,   345,   122,   375,   498,   280,   201,
     190,   228,   119,   119,   253,   204,   378,   117,   117,   277,
     200,   249,   311,   510,   511,   512,  -106,  -106,  -106,   515,
    -106,   353,   217,    99,   394,   193,  -106,   172,   173,   180,
     181,    58,   523,  -112,  -109,  -109,  -109,   278,  -109,  -106,
    -115,   279,   218,   332,  -109,  -188,   275,   243,   244,   346,
     347,   222,   355,   229,   267,   122,   245,  -109,   206,   201,
      99,   113,   122,   354,   224,   292,   244,   352,   246,   299,
      56,   448,   449,   499,   244,   414,   201,   500,   244,   267,
     429,   251,  -118,   501,   244,   520,   244,   119,    99,   113,
     281,   252,   117,   127,   149,   342,   438,   343,    76,   310,
      77,    78,    79,    80,    81,    82,   294,    83,    84,   295,
     312,  -112,  -112,  -112,   314,  -112,   315,   454,  -115,  -115,
    -115,  -112,  -115,   316,   349,   360,   350,   131,  -115,   366,
      99,   420,   372,   351,  -112,   -25,   156,   157,   355,   206,
     267,  -115,   357,   359,   201,   358,   384,   374,    57,   385,
     362,   363,   122,   381,   383,  -168,   201,   386,    58,   474,
    -118,  -118,  -118,   387,  -118,    85,   388,   392,    86,   389,
    -118,    59,     8,     9,    10,   344,    87,   397,   401,   410,
     402,    99,   113,  -118,   438,    88,    89,    90,    91,    92,
      93,   423,   411,   412,   426,   427,   430,   206,   506,   413,
     419,   431,   485,   486,   487,   158,    28,   435,   436,   159,
     508,   -23,   201,   440,   424,   267,   441,   425,   442,   443,
     267,   447,   428,   517,   450,    58,   434,   455,   456,   206,
     457,   458,   460,  -168,  -168,   503,  -168,  -168,   464,   461,
     467,   479,   468,  -168,   469,   472,   473,   483,   513,   488,
     492,   493,   503,   494,   496,  -175,  -168,   505,   502,   518,
     503,   514,   509,   244,   522,   465,   524,   256,   503,   481,
     255,   479,   258,   203,    99,   113,   257,   261,   263,   309,
     495,   259,   470,   422,   260,   471,   380,    99,   113,   262,
     304,   418,   206,   313,   417,   489,   139,     0,     0,     0,
     480,     0,     0,   482,   317,   318,    77,    78,    79,    80,
      81,    82,     0,    83,    84,     0,     0,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   319,   320,
     321,     0,   322,   323,   324,   325,   326,   327,   328,   329,
      26,    85,    27,    28,    86,    29,    30,    31,    32,    33,
      34,     0,    87,     0,     0,     0,     0,     0,     0,   149,
     416,    88,    89,    90,    91,    92,    93,   317,   318,    77,
      78,    79,    80,    81,    82,   330,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,   319,   320,   321,     0,   322,   323,   324,   325,   326,
     327,   328,   329,    26,    85,    27,    28,    86,    29,    30,
      31,    32,    33,    34,     0,    87,     0,     0,     0,     0,
       0,     0,   149,     0,    88,    89,    90,    91,    92,    93,
     317,   451,    77,    78,    79,    80,    81,    82,   330,    83,
      84,     0,     0,     0,     0,     0,    76,     0,    77,    78,
      79,    80,    81,    82,     0,    83,    84,     0,     0,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   319,   320,   321,     0,   322,   323,
     324,   325,   326,   327,   328,   329,     0,    85,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,    85,     0,   149,    86,    88,    89,    90,
      91,    92,    93,     0,    87,     0,     0,     0,     0,     0,
       0,   330,     0,    88,    89,    90,    91,    92,    93,    76,
     241,    77,    78,    79,    80,    81,    82,   330,    83,    84,
       0,     0,     0,     0,    76,     0,    77,    78,    79,    80,
      81,    82,     0,    83,    84,     0,     0,     0,     0,     0,
     212,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,    28,    86,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,    85,   213,    28,    86,     0,    88,   214,    90,    91,
      92,    93,    87,     0,     0,     0,     0,   273,     0,     0,
       0,    88,   274,    90,    91,    92,    93,    76,     0,    77,
      78,    79,    80,    81,    82,     0,    83,    84,     0,     0,
       0,     0,    76,     0,    77,    78,    79,    80,    81,    82,
       0,    83,    84,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,   364,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,    28,    86,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,    85,
     297,    28,    86,     0,    88,   298,    90,    91,    92,    93,
      87,     0,     0,     0,     0,   365,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    76,     0,    77,    78,    79,
      80,    81,    82,     0,    83,    84,     0,     0,     0,     0,
      76,     0,    77,    78,    79,    80,    81,    82,     0,    83,
      84,     0,     0,     0,     0,     0,   369,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,   432,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,    28,    86,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,    85,   370,    28,
      86,     0,    88,   371,    90,    91,    92,    93,    87,     0,
       0,     0,     0,   433,     0,     0,     0,    88,    89,    90,
      91,    92,    93,    76,     0,    77,    78,    79,    80,    81,
      82,     0,    83,    84,     0,     0,     0,     0,    76,     0,
      77,    78,    79,    80,    81,    82,     0,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,     0,     0,     0,    76,     0,    77,    78,    79,    80,
      81,    82,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,    28,    86,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,     0,    85,     0,     0,    86,     0,
      88,    89,    90,    91,    92,    93,    87,     0,     0,     0,
     282,     0,     0,   205,   283,    88,    89,    90,    91,    92,
      93,    85,     0,     0,    86,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,   282,     0,     0,   205,
     437,    88,    89,    90,    91,    92,    93,    76,     0,    77,
      78,    79,    80,    81,    82,     0,    83,    84,     0,     0,
       0,     0,     0,    76,     0,    77,    78,    79,    80,    81,
      82,     0,    83,    84,     0,     0,     0,     0,     0,    76,
       0,    77,    78,    79,    80,    81,    82,     0,    83,    84,
       0,     0,     0,     0,     0,    76,     0,    77,    78,    79,
      80,    81,    82,     0,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,   282,
      85,  -274,   205,    86,    88,    89,    90,    91,    92,    93,
       0,    87,     0,     0,     0,   282,    85,     0,   205,    86,
      88,    89,    90,    91,    92,    93,     0,    87,     0,     0,
       0,     0,    85,     0,   149,    86,    88,    89,    90,    91,
      92,    93,     0,    87,     0,     0,     0,     0,     0,     0,
     205,     0,    88,    89,    90,    91,    92,    93,    76,     0,
      77,    78,    79,    80,    81,    82,     0,    83,    84,     0,
       0,     0,     0,    76,     0,    77,    78,    79,    80,    81,
      82,     0,    83,    84,     0,     0,     0,     0,     0,    76,
       0,    77,    78,    79,    80,    81,    82,     0,    83,    84,
       0,     0,     0,     0,    76,     0,    77,    78,    79,    80,
      81,    82,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,    87,   247,     0,     0,
      85,     0,     0,    86,     0,    88,    89,    90,    91,    92,
      93,    87,     0,     0,     0,     0,    85,     0,   344,    86,
      88,    89,    90,    91,    92,    93,     0,    87,     0,     0,
       0,    85,     0,     0,    86,     0,    88,    89,    90,    91,
      92,    93,   145,    56,     1,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,    76,     0,    77,
      78,    79,    80,    81,    82,     0,    83,    84,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,     0,    31,    32,    33,    34,
       0,   353,   266,     1,    85,   193,     0,    86,     0,     0,
       0,    58,     0,     0,     0,   162,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,    28,     0,    29,     0,    31,    32,    33,    34,     0,
     192,   266,     0,     0,   193,     0,     0,     0,     0,     0,
      58,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,    30,     0,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      30,     0,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   390,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   300,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,     0,    29,     0,    31,
      32,    33,    34,     0,     0,   367,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,     0,    31,    32,    33,    34,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,    29,    30,    31,    32,    33,    34,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   421,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,     0,    31,    32,    33,    34,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,     0,    29,     0,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      30,     0,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    32,    33,    34
};

static const yytype_int16 yycheck[] =
{
      52,    52,    36,    87,   120,   128,    64,    54,   376,   222,
     129,    58,    54,    58,   118,   217,     3,   127,   194,    83,
     101,   219,   220,     3,    54,    87,    81,     3,    85,    21,
      82,     3,     0,     3,    83,    83,     3,   506,     0,    27,
     104,    81,    83,     3,    83,   514,   103,     3,   100,   101,
      88,    83,    88,   522,   103,   104,   104,    89,    16,    17,
      82,   145,    81,   104,    52,   104,    85,    81,   120,   120,
       3,    85,    91,   118,   193,   159,   278,   124,   162,   124,
      92,    93,   129,   145,    91,   401,   402,   168,   211,    96,
      97,   125,   408,   212,    81,    81,   464,    65,    66,    87,
     162,    69,    70,    71,   188,    73,   304,   230,     3,    89,
     102,    81,    88,     3,    81,    82,   168,    84,    85,   171,
      83,    91,   174,    86,    91,    81,     3,   179,    81,    85,
     182,   183,   184,   185,   186,   187,    83,   104,    90,   455,
      98,    99,    89,   100,   191,    20,   193,   192,   210,   191,
     127,   198,   129,   272,    81,   101,   198,   145,    85,   147,
     279,   191,    82,   267,   245,   212,   282,   483,   198,   216,
      82,   148,   219,   220,   162,   209,   286,   219,   220,   355,
      82,   158,   395,   499,   500,   501,    81,    82,    83,   505,
      85,    81,    81,   245,   310,    85,    91,    14,    15,    18,
      19,    91,   518,     3,    81,    82,    83,    81,    85,   104,
       3,    85,    88,   336,    91,   103,   193,    82,    83,    82,
      83,    83,   267,    89,   192,   272,    82,   104,   205,   276,
     282,   282,   279,   267,    88,   212,    83,    84,    82,   216,
       3,    82,    83,    82,    83,   329,   293,    82,    83,   217,
     369,    87,     3,    82,    83,    82,    83,   304,   310,   310,
      83,    11,   304,   103,    88,   242,   376,   244,     3,   103,
       5,     6,     7,     8,     9,    10,    86,    12,    13,    86,
      89,    81,    82,    83,    82,    85,    82,   403,    81,    82,
      83,    91,    85,    83,     3,   272,     3,   355,    91,   276,
     352,   352,   279,    82,   104,    11,    12,    13,   353,   286,
     278,   104,    82,    82,   361,    83,   293,     8,    81,   296,
      86,    86,   369,    87,    86,     3,   373,    86,    91,   439,
      81,    82,    83,    86,    85,    70,    82,   104,    73,    83,
      91,   104,    38,    39,    40,    88,    81,    58,    84,     3,
      84,   403,   403,   104,   464,    90,    91,    92,    93,    94,
      95,    86,   104,   104,    86,    82,    86,   344,   491,   104,
     347,    86,   456,   457,   458,    81,    72,    82,    86,    85,
     496,    87,   429,     3,   361,   353,    86,   364,    86,     3,
     358,    84,   369,   509,    84,    91,   373,    84,    81,   376,
      81,    81,    81,    81,    82,   489,    84,    85,    83,   104,
      86,   445,    86,    91,    86,    86,   104,    84,   502,    62,
      89,    86,   506,    86,    84,    84,   104,    82,    81,    60,
     514,   104,    84,    83,   104,   418,   104,   174,   522,   449,
     171,   475,   182,   125,   496,   496,   179,   185,   187,   220,
     475,   183,   429,   358,   184,   432,   287,   509,   509,   186,
     218,   344,   439,   224,   336,   460,    73,    -1,    -1,    -1,
     447,    -1,    -1,   450,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,   464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    90,    91,    92,    93,    94,    95,
       3,     4,     5,     6,     7,     8,     9,    10,   104,    12,
      13,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    70,    -1,    88,    73,    90,    91,    92,
      93,    94,    95,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    90,    91,    92,    93,    94,    95,     3,
     103,     5,     6,     7,     8,     9,    10,   104,    12,    13,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    70,    86,    72,    73,    -1,    90,    91,    92,    93,
      94,    95,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,     3,    -1,     5,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      90,    91,    92,    93,    94,    95,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      70,    87,    88,    73,    90,    91,    92,    93,    94,    95,
      -1,    81,    -1,    -1,    -1,    85,    70,    -1,    88,    73,
      90,    91,    92,    93,    94,    95,    -1,    81,    -1,    -1,
      -1,    -1,    70,    -1,    88,    73,    90,    91,    92,    93,
      94,    95,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    90,    91,    92,    93,    94,    95,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      70,    -1,    -1,    73,    -1,    90,    91,    92,    93,    94,
      95,    81,    -1,    -1,    -1,    -1,    70,    -1,    88,    73,
      90,    91,    92,    93,    94,    95,    -1,    81,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    90,    91,    92,    93,
      94,    95,    81,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    81,    82,     4,    70,    85,    -1,    73,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      81,    82,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      91,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      75,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,
      77,    78,    79,    -1,    -1,    82,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      75,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    -1,    -1,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,    77,    78,    79,   142,   143,   151,   152,   153,
     156,   171,   179,   180,   181,   182,   205,   229,   231,   232,
     172,   173,    81,   194,   195,   206,     3,    81,    91,   104,
     149,   150,   183,   184,   187,   144,   145,     3,    88,   146,
     147,   148,     0,   230,    88,     3,     3,     5,     6,     7,
       8,     9,    10,    12,    13,    70,    73,    81,    90,    91,
      92,    93,    94,    95,   106,   107,   109,   110,   113,   118,
     119,   120,   121,   122,   124,   126,   128,   130,   132,   133,
     134,   135,   136,   137,   141,   194,    82,   152,   162,   180,
      81,   183,   180,   187,   188,    83,   104,   103,   233,    85,
     185,   184,   143,   143,   155,   154,   143,   143,   143,   231,
       3,   108,   176,   177,   174,    81,   118,    81,    81,    88,
     118,   137,   138,   140,   194,   211,    12,    13,    81,    85,
     114,   115,    81,   118,   121,    91,    96,    97,   123,    92,
      93,   125,    14,    15,   127,    16,    17,    98,    99,   129,
      18,    19,   131,    90,   100,   101,    20,    21,   102,    82,
      82,   163,    81,    85,   187,   196,   197,   198,   164,   141,
      82,   180,   187,   150,   183,    88,   138,   199,   142,   143,
     234,   235,    34,    86,    91,   138,   188,    81,    88,   157,
     158,   178,    83,   116,    88,   175,   194,   194,   138,    89,
     212,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   103,   139,    82,    83,    82,    82,    82,   117,   138,
     140,    87,    11,   194,   121,   122,   124,   126,   128,   130,
     132,   133,   134,   135,   140,   162,    82,   143,   189,   190,
     192,   197,    34,    86,    91,   138,   188,   198,    81,    85,
     162,    83,    85,    89,   199,   200,   201,   202,   203,   204,
     211,   142,   138,   188,    86,    86,    34,    86,    91,   138,
       3,   186,   189,   193,   157,    89,   160,   162,   205,   160,
     103,   177,    89,   176,    82,    82,    83,     3,     4,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
     104,   140,   142,   207,   208,   211,   213,   215,   216,   217,
     221,   228,   138,   138,    88,   121,    82,    83,    86,     3,
       3,    82,    84,    81,   183,   187,   197,    82,    83,    82,
     138,   188,    86,    86,    34,    86,   138,    82,   189,    34,
      86,    91,   138,   188,     8,   141,    83,    89,   199,   103,
     203,    87,   236,    86,   138,   138,    86,    86,    82,    83,
      89,   159,   104,   161,   141,    83,    89,    58,   111,   112,
     194,    84,    84,   209,   210,   218,   219,   222,   223,   224,
       3,   104,   104,   104,   140,   104,    89,   215,   200,   138,
     137,    56,   192,    86,   138,   138,    86,    82,   138,   188,
      86,    86,    34,    86,   138,    82,    86,    89,   199,   201,
       3,    86,    86,     3,   165,   166,    89,    84,    82,    83,
      84,     4,   207,   207,   141,    84,    81,    81,    81,   207,
      81,   104,   104,   214,    83,   116,   191,    86,    86,    86,
     138,   138,    86,   104,   199,    83,   104,   168,   169,   183,
     138,   112,   138,    84,   207,   140,   140,   140,    62,   216,
     225,   226,    89,    86,    86,   168,    84,   170,   207,    82,
      82,    82,    81,   140,   227,    82,   142,   167,   141,    84,
     207,   207,   207,   140,   104,   207,   227,   141,    60,   220,
      82,   227,   104,   207,   104,   227
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   108,   109,   109,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   113,   115,   113,   113,   113,   113,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   121,   121,
     122,   122,   123,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   140,
     141,   142,   142,   142,   144,   143,   143,   145,   143,   143,
     146,   143,   143,   147,   143,   143,   148,   143,   143,   149,
     149,   150,   150,   151,   151,   151,   151,   151,   151,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   154,   153,
     155,   153,   153,   156,   156,   158,   157,   159,   157,   160,
     161,   160,   160,   163,   162,   162,   164,   162,   162,   166,
     165,   167,   165,   169,   168,   170,   168,   168,   172,   171,
     173,   174,   171,   175,   175,   175,   176,   176,   178,   177,
     177,   179,   180,   180,   180,   180,   181,   181,   182,   182,
     183,   183,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   185,   184,   186,   186,   186,   187,   187,
     187,   187,   188,   188,   189,   189,   190,   191,   190,   192,
     192,   192,   193,   193,   195,   194,   196,   196,   197,   197,
     197,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   199,   199,   199,   199,   200,   200,   200,   200,
     201,   202,   202,   203,   204,   203,   206,   205,   207,   207,
     207,   207,   207,   207,   208,   208,   209,   208,   210,   208,
     211,   212,   211,   213,   214,   213,   215,   215,   216,   216,
     218,   217,   219,   217,   220,   220,   222,   221,   223,   221,
     224,   221,   225,   226,   225,   227,   227,   228,   228,   228,
     228,   228,   229,   230,   229,   231,   231,   233,   232,   234,
     234,   235,   236,   235
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     6,     1,     3,     3,     3,     1,
       4,     3,     4,     0,     4,     0,     4,     2,     2,     7,
       0,     1,     1,     3,     1,     2,     2,     2,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     0,     3,     1,     0,     3,     1,
       0,     3,     1,     0,     3,     1,     0,     3,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       0,     6,     2,     1,     1,     0,     2,     0,     3,     2,
       0,     4,     1,     0,     3,     1,     0,     3,     1,     0,
       2,     0,     4,     0,     3,     0,     4,     1,     0,     6,
       0,     0,     5,     0,     3,     4,     1,     3,     0,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     4,
       2,     1,     1,     3,     3,     4,     6,     5,     5,     6,
       5,     4,     4,     0,     5,     0,     1,     1,     3,     2,
       2,     1,     1,     2,     3,     1,     1,     0,     4,     2,
       2,     1,     1,     3,     0,     3,     0,     1,     2,     1,
       1,     3,     2,     3,     5,     4,     5,     4,     3,     3,
       3,     4,     6,     5,     5,     6,     4,     4,     2,     3,
       3,     4,     3,     4,     1,     2,     2,     1,     4,     3,
       2,     1,     2,     3,     0,     3,     0,     8,     1,     1,
       1,     1,     1,     1,     3,     3,     0,     5,     0,     4,
       2,     0,     4,     1,     0,     3,     1,     1,     1,     2,
       0,     7,     0,     6,     0,     2,     0,     6,     0,     8,
       0,     6,     4,     0,     5,     0,     1,     3,     2,     2,
       2,     3,     1,     0,     3,     1,     1,     0,     5,     0,
       1,     1,     0,     3
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
#line 128 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2505 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' compound_statement ')'  */
#line 134 "C_grammar.y"
                {size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2515 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' expression ')'  */
#line 140 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2525 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: generic_selection  */
#line 145 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2531 "C_grammar.tab.c"
    break;

  case 13: /* string: FUNC_NAME  */
#line 160 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2537 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 180 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2548 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' ')'  */
#line 187 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2558 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 193 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2569 "C_grammar.tab.c"
    break;

  case 23: /* $@1: %empty  */
#line 199 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2575 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression $@1 '.' IDENTIFIER  */
#line 200 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2587 "C_grammar.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 207 "C_grammar.y"
                             {in_member_namespace = 1;}
#line 2593 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression $@2 PTR_OP IDENTIFIER  */
#line 208 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[0].id));
		}
#line 2605 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression INC_OP  */
#line 216 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2615 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression DEC_OP  */
#line 222 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2625 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: '(' type_name ')' '{' initializer_list comma_opt '}'  */
#line 228 "C_grammar.y"
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
#line 2643 "C_grammar.tab.c"
    break;

  case 30: /* comma_opt: %empty  */
#line 244 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 2649 "C_grammar.tab.c"
    break;

  case 31: /* comma_opt: ','  */
#line 245 "C_grammar.y"
              {simple_str_lit_copy(&(yyval.id), ",");}
#line 2655 "C_grammar.tab.c"
    break;

  case 33: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 252 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2666 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: unary_inc_dec unary_expression  */
#line 263 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2677 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: unary_operator cast_expression  */
#line 270 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2688 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: SIZEOF unary_expression  */
#line 277 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2698 "C_grammar.tab.c"
    break;

  case 38: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 283 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2708 "C_grammar.tab.c"
    break;

  case 39: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 289 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2718 "C_grammar.tab.c"
    break;

  case 40: /* unary_inc_dec: INC_OP  */
#line 297 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2724 "C_grammar.tab.c"
    break;

  case 41: /* unary_inc_dec: DEC_OP  */
#line 298 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2730 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '&'  */
#line 302 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2736 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '*'  */
#line 303 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2742 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '+'  */
#line 304 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2748 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '-'  */
#line 305 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2754 "C_grammar.tab.c"
    break;

  case 46: /* unary_operator: '~'  */
#line 306 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2760 "C_grammar.tab.c"
    break;

  case 47: /* unary_operator: '!'  */
#line 307 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2766 "C_grammar.tab.c"
    break;

  case 49: /* cast_expression: '(' type_name ')' cast_expression  */
#line 313 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2777 "C_grammar.tab.c"
    break;

  case 51: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 324 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2789 "C_grammar.tab.c"
    break;

  case 52: /* multiplicative_expression_op: '*'  */
#line 334 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2795 "C_grammar.tab.c"
    break;

  case 53: /* multiplicative_expression_op: '/'  */
#line 335 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2801 "C_grammar.tab.c"
    break;

  case 54: /* multiplicative_expression_op: '%'  */
#line 336 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2807 "C_grammar.tab.c"
    break;

  case 56: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 342 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2819 "C_grammar.tab.c"
    break;

  case 57: /* additive_expression_op: '+'  */
#line 352 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2825 "C_grammar.tab.c"
    break;

  case 58: /* additive_expression_op: '-'  */
#line 353 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2831 "C_grammar.tab.c"
    break;

  case 60: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 359 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2843 "C_grammar.tab.c"
    break;

  case 61: /* shift_expression_op: LEFT_OP  */
#line 369 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2849 "C_grammar.tab.c"
    break;

  case 62: /* shift_expression_op: RIGHT_OP  */
#line 370 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2855 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 376 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2867 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression_operator: '<'  */
#line 386 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2873 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression_operator: '>'  */
#line 387 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2879 "C_grammar.tab.c"
    break;

  case 67: /* relational_expression_operator: LE_OP  */
#line 388 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2885 "C_grammar.tab.c"
    break;

  case 68: /* relational_expression_operator: GE_OP  */
#line 389 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2891 "C_grammar.tab.c"
    break;

  case 70: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 396 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2903 "C_grammar.tab.c"
    break;

  case 71: /* equality_expression_op: EQ_OP  */
#line 406 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2909 "C_grammar.tab.c"
    break;

  case 72: /* equality_expression_op: NE_OP  */
#line 407 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2915 "C_grammar.tab.c"
    break;

  case 74: /* and_expression: and_expression '&' equality_expression  */
#line 413 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2926 "C_grammar.tab.c"
    break;

  case 76: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 424 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2937 "C_grammar.tab.c"
    break;

  case 78: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 435 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2948 "C_grammar.tab.c"
    break;

  case 80: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 446 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2959 "C_grammar.tab.c"
    break;

  case 82: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 457 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2970 "C_grammar.tab.c"
    break;

  case 84: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 468 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2982 "C_grammar.tab.c"
    break;

  case 86: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 480 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2994 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: '='  */
#line 490 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 3000 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: MUL_ASSIGN  */
#line 491 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 3006 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: DIV_ASSIGN  */
#line 492 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 3012 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: MOD_ASSIGN  */
#line 493 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 3018 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: ADD_ASSIGN  */
#line 494 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 3024 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: SUB_ASSIGN  */
#line 495 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 3030 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: LEFT_ASSIGN  */
#line 496 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 3036 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: RIGHT_ASSIGN  */
#line 497 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 3042 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: AND_ASSIGN  */
#line 498 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 3048 "C_grammar.tab.c"
    break;

  case 96: /* assignment_operator: XOR_ASSIGN  */
#line 499 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3054 "C_grammar.tab.c"
    break;

  case 97: /* assignment_operator: OR_ASSIGN  */
#line 500 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3060 "C_grammar.tab.c"
    break;

  case 99: /* expression: expression ',' assignment_expression  */
#line 506 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3071 "C_grammar.tab.c"
    break;

  case 101: /* declaration: declaration_specifiers ';'  */
#line 521 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 printf("end of stand alone declaration specifier as a declaration in_ordinary_id_declaration is %d on line %d\n", in_ordinary_id_declaration, yylineno);
		 size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3083 "C_grammar.tab.c"
    break;

  case 102: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 529 "C_grammar.y"
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
#line 3099 "C_grammar.tab.c"
    break;

  case 103: /* declaration: static_assert_declaration  */
#line 541 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3110 "C_grammar.tab.c"
    break;

  case 104: /* $@3: %empty  */
#line 550 "C_grammar.y"
                                  {check_for_typedef = 1;}
#line 3116 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: storage_class_specifier $@3 declaration_specifiers  */
#line 551 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3129 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: storage_class_specifier  */
#line 560 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 check_for_typedef = 0;
		}
#line 3137 "C_grammar.tab.c"
    break;

  case 107: /* $@4: %empty  */
#line 563 "C_grammar.y"
                         {printf("declaration_specifiers is %s on line %d\n", (yyvsp[0].id), yylineno); check_for_typedef = 1;}
#line 3143 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: type_specifier $@4 declaration_specifiers  */
#line 564 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3156 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: type_specifier  */
#line 573 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 printf("declaration_specifiers is simple type_specifier %s on line %d\n", (yyvsp[0].id), yylineno); 
		 check_for_typedef = 0;
		}
#line 3165 "C_grammar.tab.c"
    break;

  case 110: /* $@5: %empty  */
#line 577 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3171 "C_grammar.tab.c"
    break;

  case 111: /* declaration_specifiers: type_qualifier $@5 declaration_specifiers  */
#line 578 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3184 "C_grammar.tab.c"
    break;

  case 112: /* declaration_specifiers: type_qualifier  */
#line 586 "C_grammar.y"
                         {in_ordinary_id_declaration = 1; check_for_typedef = 0;}
#line 3190 "C_grammar.tab.c"
    break;

  case 113: /* $@6: %empty  */
#line 587 "C_grammar.y"
                             {check_for_typedef = 1;}
#line 3196 "C_grammar.tab.c"
    break;

  case 114: /* declaration_specifiers: function_specifier $@6 declaration_specifiers  */
#line 588 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); 
		}
#line 3205 "C_grammar.tab.c"
    break;

  case 115: /* declaration_specifiers: function_specifier  */
#line 593 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); 
		}
#line 3214 "C_grammar.tab.c"
    break;

  case 116: /* $@7: %empty  */
#line 597 "C_grammar.y"
                              {check_for_typedef = 1;}
#line 3220 "C_grammar.tab.c"
    break;

  case 117: /* declaration_specifiers: alignment_specifier $@7 declaration_specifiers  */
#line 598 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); 
		}
#line 3229 "C_grammar.tab.c"
    break;

  case 118: /* declaration_specifiers: alignment_specifier  */
#line 603 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); 
		}
#line 3238 "C_grammar.tab.c"
    break;

  case 119: /* init_declarator_list: init_declarator  */
#line 611 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 (yyval.id) = (yyvsp[0].id);
		}
#line 3246 "C_grammar.tab.c"
    break;

  case 120: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 615 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3258 "C_grammar.tab.c"
    break;

  case 121: /* init_declarator: declarator '=' initializer  */
#line 626 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 free((yyvsp[0].id));
	  	}
#line 3270 "C_grammar.tab.c"
    break;

  case 122: /* init_declarator: declarator  */
#line 634 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_name((yyvsp[0].declarator_type).ptr_declarator);	
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3281 "C_grammar.tab.c"
    break;

  case 123: /* storage_class_specifier: TYPEDEF  */
#line 644 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3290 "C_grammar.tab.c"
    break;

  case 124: /* storage_class_specifier: EXTERN  */
#line 648 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3296 "C_grammar.tab.c"
    break;

  case 125: /* storage_class_specifier: STATIC  */
#line 649 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3302 "C_grammar.tab.c"
    break;

  case 126: /* storage_class_specifier: THREAD_LOCAL  */
#line 650 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3308 "C_grammar.tab.c"
    break;

  case 127: /* storage_class_specifier: AUTO  */
#line 651 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3314 "C_grammar.tab.c"
    break;

  case 128: /* storage_class_specifier: REGISTER  */
#line 652 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3320 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: VOID  */
#line 656 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "void"); }
#line 3326 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: CHAR  */
#line 657 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "char"); }
#line 3332 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: SHORT  */
#line 658 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "short"); }
#line 3338 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: INT  */
#line 659 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int"); }
#line 3344 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: LONG  */
#line 660 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "long"); }
#line 3350 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: FLOAT  */
#line 661 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float"); }
#line 3356 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: DOUBLE  */
#line 662 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "double"); }
#line 3362 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: SIGNED  */
#line 663 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3368 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: UNSIGNED  */
#line 664 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3374 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: BOOL  */
#line 665 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3380 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: COMPLEX  */
#line 666 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3386 "C_grammar.tab.c"
    break;

  case 140: /* type_specifier: IMAGINARY  */
#line 667 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3392 "C_grammar.tab.c"
    break;

  case 141: /* type_specifier: atomic_type_specifier  */
#line 668 "C_grammar.y"
                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3398 "C_grammar.tab.c"
    break;

  case 142: /* type_specifier: struct_or_union_specifier  */
#line 669 "C_grammar.y"
                                    { in_ordinary_id_declaration = 1; }
#line 3404 "C_grammar.tab.c"
    break;

  case 143: /* type_specifier: enum_specifier  */
#line 670 "C_grammar.y"
                                        { in_ordinary_id_declaration = 1; }
#line 3410 "C_grammar.tab.c"
    break;

  case 144: /* type_specifier: TYPEDEF_NAME  */
#line 672 "C_grammar.y"
                {in_ordinary_id_declaration = 1; 
		 (yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3419 "C_grammar.tab.c"
    break;

  case 145: /* type_specifier: INT128  */
#line 676 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "int128"); }
#line 3425 "C_grammar.tab.c"
    break;

  case 146: /* type_specifier: FLOAT128  */
#line 677 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "float128"); }
#line 3431 "C_grammar.tab.c"
    break;

  case 147: /* type_specifier: VA_LIST  */
#line 678 "C_grammar.y"
                                                { in_ordinary_id_declaration = 1; simple_str_lit_copy(&(yyval.id), "va_list"); }
#line 3437 "C_grammar.tab.c"
    break;

  case 148: /* $@8: %empty  */
#line 682 "C_grammar.y"
                              {in_tag_declaration = 0;}
#line 3443 "C_grammar.tab.c"
    break;

  case 149: /* struct_or_union_specifier: struct_or_union '{' $@8 struct_declaration_list '}'  */
#line 683 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3454 "C_grammar.tab.c"
    break;

  case 150: /* $@9: %empty  */
#line 689 "C_grammar.y"
                                     {in_tag_declaration = 0;}
#line 3460 "C_grammar.tab.c"
    break;

  case 151: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@9 '{' struct_declaration_list '}'  */
#line 690 "C_grammar.y"
                {char *tag_to_Prolog_var = to_prolog_var((yyvsp[-4].id));
		 size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen(tag_to_Prolog_var) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), tag_to_Prolog_var, (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		 free(tag_to_Prolog_var);
	    }
#line 3474 "C_grammar.tab.c"
    break;

  case 152: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 700 "C_grammar.y"
                {in_tag_declaration = 0;
		 char *tag_to_Prolog_var = to_prolog_var((yyvsp[0].id));
		 size_t const size = strlen("%s(%s)") + strlen((yyvsp[-1].id)) + strlen(tag_to_Prolog_var) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), tag_to_Prolog_var);
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
		 free(tag_to_Prolog_var);
	    }
#line 3488 "C_grammar.tab.c"
    break;

  case 153: /* struct_or_union: STRUCT  */
#line 713 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_declaration = 1;
		}
#line 3497 "C_grammar.tab.c"
    break;

  case 154: /* struct_or_union: UNION  */
#line 718 "C_grammar.y"
                {check_for_typedef = 0;
		 simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_declaration = 1;
		}
#line 3506 "C_grammar.tab.c"
    break;

  case 155: /* $@10: %empty  */
#line 725 "C_grammar.y"
          {check_for_typedef = 1;}
#line 3512 "C_grammar.tab.c"
    break;

  case 156: /* struct_declaration_list: $@10 struct_declaration  */
#line 725 "C_grammar.y"
                                                      {(yyval.id) = (yyvsp[0].id); check_for_typedef = 1;}
#line 3518 "C_grammar.tab.c"
    break;

  case 157: /* $@11: %empty  */
#line 726 "C_grammar.y"
                                                     {check_for_typedef = 1;}
#line 3524 "C_grammar.tab.c"
    break;

  case 158: /* struct_declaration_list: struct_declaration_list struct_declaration $@11  */
#line 727 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	    }
#line 3535 "C_grammar.tab.c"
    break;

  case 159: /* struct_declaration: specifier_qualifier_list ';'  */
#line 737 "C_grammar.y"
                {size_t const size = strlen("anonymous_member()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_member(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3545 "C_grammar.tab.c"
    break;

  case 160: /* $@12: %empty  */
#line 743 "C_grammar.y"
                                   {in_member_namespace = 1;}
#line 3551 "C_grammar.tab.c"
    break;

  case 161: /* struct_declaration: specifier_qualifier_list $@12 struct_declarator_list ';'  */
#line 744 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3563 "C_grammar.tab.c"
    break;

  case 163: /* $@13: %empty  */
#line 755 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3569 "C_grammar.tab.c"
    break;

  case 164: /* specifier_qualifier_list: type_specifier $@13 specifier_qualifier_list  */
#line 756 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3581 "C_grammar.tab.c"
    break;

  case 165: /* specifier_qualifier_list: type_specifier  */
#line 763 "C_grammar.y"
                         {check_for_typedef = 0;}
#line 3587 "C_grammar.tab.c"
    break;

  case 166: /* $@14: %empty  */
#line 764 "C_grammar.y"
                         {check_for_typedef = 1;}
#line 3593 "C_grammar.tab.c"
    break;

  case 167: /* specifier_qualifier_list: type_qualifier $@14 specifier_qualifier_list  */
#line 765 "C_grammar.y"
                {check_for_typedef = 0;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3605 "C_grammar.tab.c"
    break;

  case 168: /* specifier_qualifier_list: type_qualifier  */
#line 772 "C_grammar.y"
                         {check_for_typedef = 0;}
#line 3611 "C_grammar.tab.c"
    break;

  case 169: /* $@15: %empty  */
#line 776 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3617 "C_grammar.tab.c"
    break;

  case 170: /* struct_declarator_list: $@15 struct_declarator  */
#line 776 "C_grammar.y"
                                                       {(yyval.id)= (yyvsp[0].id); in_member_namespace = 1;}
#line 3623 "C_grammar.tab.c"
    break;

  case 171: /* $@16: %empty  */
#line 777 "C_grammar.y"
                                                       {in_member_namespace = 1;}
#line 3629 "C_grammar.tab.c"
    break;

  case 172: /* struct_declarator_list: struct_declarator_list ',' struct_declarator $@16  */
#line 778 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
        }
#line 3640 "C_grammar.tab.c"
    break;

  case 173: /* $@17: %empty  */
#line 787 "C_grammar.y"
          {in_member_namespace = 0;}
#line 3646 "C_grammar.tab.c"
    break;

  case 174: /* struct_declarator: $@17 ':' constant_expression  */
#line 788 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3656 "C_grammar.tab.c"
    break;

  case 175: /* $@18: %empty  */
#line 793 "C_grammar.y"
                     {in_ordinary_id_declaration = 0;}
#line 3662 "C_grammar.tab.c"
    break;

  case 176: /* struct_declarator: declarator $@18 ':' constant_expression  */
#line 794 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3674 "C_grammar.tab.c"
    break;

  case 177: /* struct_declarator: declarator  */
#line 802 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3683 "C_grammar.tab.c"
    break;

  case 178: /* $@19: %empty  */
#line 809 "C_grammar.y"
               {in_ordinary_id_declaration = 1;}
#line 3689 "C_grammar.tab.c"
    break;

  case 179: /* enum_specifier: ENUM $@19 '{' enumerator_list comma_opt '}'  */
#line 810 "C_grammar.y"
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
#line 3707 "C_grammar.tab.c"
    break;

  case 180: /* $@20: %empty  */
#line 823 "C_grammar.y"
               {in_tag_declaration = 1;}
#line 3713 "C_grammar.tab.c"
    break;

  case 181: /* $@21: %empty  */
#line 823 "C_grammar.y"
                                                    {in_tag_declaration = 0; in_ordinary_id_declaration = 1;}
#line 3719 "C_grammar.tab.c"
    break;

  case 182: /* enum_specifier: ENUM $@20 IDENTIFIER $@21 enum_specifier_rest  */
#line 824 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3731 "C_grammar.tab.c"
    break;

  case 183: /* enum_specifier_rest: %empty  */
#line 835 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3737 "C_grammar.tab.c"
    break;

  case 184: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 837 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3743 "C_grammar.tab.c"
    break;

  case 185: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 839 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3753 "C_grammar.tab.c"
    break;

  case 186: /* enumerator_list: enumerator  */
#line 847 "C_grammar.y"
                     {in_ordinary_id_declaration = 1;}
#line 3759 "C_grammar.tab.c"
    break;

  case 187: /* enumerator_list: enumerator_list ',' enumerator  */
#line 849 "C_grammar.y"
                {in_ordinary_id_declaration = 1;
		 size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3771 "C_grammar.tab.c"
    break;

  case 188: /* $@22: %empty  */
#line 859 "C_grammar.y"
                               {in_ordinary_id_declaration = 0;}
#line 3777 "C_grammar.tab.c"
    break;

  case 189: /* enumerator: enumeration_constant $@22 '=' constant_expression  */
#line 860 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-3].id), (yyvsp[0].id));
	   	 free((yyvsp[-3].id));
	     free((yyvsp[0].id));
        }
#line 3788 "C_grammar.tab.c"
    break;

  case 192: /* type_qualifier: CONST  */
#line 874 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3794 "C_grammar.tab.c"
    break;

  case 193: /* type_qualifier: RESTRICT  */
#line 875 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3800 "C_grammar.tab.c"
    break;

  case 194: /* type_qualifier: VOLATILE  */
#line 876 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3806 "C_grammar.tab.c"
    break;

  case 195: /* type_qualifier: ATOMIC  */
#line 877 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3812 "C_grammar.tab.c"
    break;

  case 196: /* function_specifier: INLINE  */
#line 881 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3818 "C_grammar.tab.c"
    break;

  case 197: /* function_specifier: NORETURN  */
#line 882 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3824 "C_grammar.tab.c"
    break;

  case 200: /* declarator: pointer direct_declarator  */
#line 893 "C_grammar.y"
          {in_ordinary_id_declaration = 0;
	   size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3837 "C_grammar.tab.c"
    break;

  case 201: /* declarator: direct_declarator  */
#line 901 "C_grammar.y"
                            {in_ordinary_id_declaration = 0;}
#line 3843 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: IDENTIFIER  */
#line 906 "C_grammar.y"
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
#line 3870 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: '(' declarator ')'  */
#line 930 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-1].declarator_type);}
#line 3876 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: direct_declarator '[' ']'  */
#line 932 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3887 "C_grammar.tab.c"
    break;

  case 205: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 939 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3896 "C_grammar.tab.c"
    break;

  case 206: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 944 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3905 "C_grammar.tab.c"
    break;

  case 207: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 949 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3914 "C_grammar.tab.c"
    break;

  case 208: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 954 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3923 "C_grammar.tab.c"
    break;

  case 209: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 959 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3932 "C_grammar.tab.c"
    break;

  case 210: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 964 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3941 "C_grammar.tab.c"
    break;

  case 211: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 969 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3950 "C_grammar.tab.c"
    break;

  case 212: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 974 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3962 "C_grammar.tab.c"
    break;

  case 213: /* $@23: %empty  */
#line 981 "C_grammar.y"
                            {in_ordinary_id_declaration = 0; check_for_typedef = 1;}
#line 3968 "C_grammar.tab.c"
    break;

  case 214: /* direct_declarator: direct_declarator $@23 '(' rest_function_definition ')'  */
#line 982 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("function(, )") + strlen((yyvsp[-4].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-4].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-4].declarator_type).full);
	     free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 3982 "C_grammar.tab.c"
    break;

  case 215: /* rest_function_definition: %empty  */
#line 994 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "[]");}
#line 3988 "C_grammar.tab.c"
    break;

  case 217: /* rest_function_definition: old_style_parameter_list  */
#line 996 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "dummy_identifier_list");}
#line 3994 "C_grammar.tab.c"
    break;

  case 218: /* pointer: '*' type_qualifier_list pointer  */
#line 1001 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4005 "C_grammar.tab.c"
    break;

  case 219: /* pointer: '*' type_qualifier_list  */
#line 1008 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 4015 "C_grammar.tab.c"
    break;

  case 220: /* pointer: '*' pointer  */
#line 1014 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4025 "C_grammar.tab.c"
    break;

  case 221: /* pointer: '*'  */
#line 1020 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 4031 "C_grammar.tab.c"
    break;

  case 223: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1026 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4042 "C_grammar.tab.c"
    break;

  case 224: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1036 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 4052 "C_grammar.tab.c"
    break;

  case 225: /* parameter_type_list: parameter_list  */
#line 1042 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 4062 "C_grammar.tab.c"
    break;

  case 226: /* parameter_list: parameter_declaration  */
#line 1050 "C_grammar.y"
                                {check_for_typedef = 1;}
#line 4068 "C_grammar.tab.c"
    break;

  case 227: /* $@24: %empty  */
#line 1051 "C_grammar.y"
                                                   {check_for_typedef = 1;}
#line 4074 "C_grammar.tab.c"
    break;

  case 228: /* parameter_list: parameter_list ',' parameter_declaration $@24  */
#line 1052 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 4085 "C_grammar.tab.c"
    break;

  case 229: /* parameter_declaration: declaration_specifiers declarator  */
#line 1062 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full); 
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 4097 "C_grammar.tab.c"
    break;

  case 230: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1070 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 4108 "C_grammar.tab.c"
    break;

  case 231: /* parameter_declaration: declaration_specifiers  */
#line 1077 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 4118 "C_grammar.tab.c"
    break;

  case 234: /* $@25: %empty  */
#line 1090 "C_grammar.y"
          {check_for_typedef = 1;}
#line 4124 "C_grammar.tab.c"
    break;

  case 235: /* type_name: $@25 specifier_qualifier_list abstract_declarator_opt  */
#line 1091 "C_grammar.y"
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
#line 4139 "C_grammar.tab.c"
    break;

  case 236: /* abstract_declarator_opt: %empty  */
#line 1104 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4145 "C_grammar.tab.c"
    break;

  case 237: /* abstract_declarator_opt: abstract_declarator  */
#line 1105 "C_grammar.y"
                               {simple_str_lit_copy(&(yyval.id), "type_abstract_declarator_dummy1");}
#line 4151 "C_grammar.tab.c"
    break;

  case 262: /* initializer: '{' initializer_list '}'  */
#line 1140 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4161 "C_grammar.tab.c"
    break;

  case 263: /* initializer: '{' initializer_list ',' '}'  */
#line 1146 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 4171 "C_grammar.tab.c"
    break;

  case 265: /* initializer: '{' '}'  */
#line 1153 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "initializer([])");}
#line 4177 "C_grammar.tab.c"
    break;

  case 266: /* initializer_list: designation initializer  */
#line 1158 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4188 "C_grammar.tab.c"
    break;

  case 268: /* initializer_list: initializer_list ',' designation initializer  */
#line 1166 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4200 "C_grammar.tab.c"
    break;

  case 269: /* initializer_list: initializer_list ',' initializer  */
#line 1174 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4211 "C_grammar.tab.c"
    break;

  case 270: /* designation: designator_list '='  */
#line 1184 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4221 "C_grammar.tab.c"
    break;

  case 272: /* designator_list: designator_list designator  */
#line 1194 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4232 "C_grammar.tab.c"
    break;

  case 273: /* designator: '[' constant_expression ']'  */
#line 1204 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4242 "C_grammar.tab.c"
    break;

  case 274: /* $@26: %empty  */
#line 1209 "C_grammar.y"
          {in_member_namespace = 1;}
#line 4248 "C_grammar.tab.c"
    break;

  case 275: /* designator: $@26 '.' IDENTIFIER  */
#line 1210 "C_grammar.y"
                {in_member_namespace = 0;
		 size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4259 "C_grammar.tab.c"
    break;

  case 276: /* $@27: %empty  */
#line 1219 "C_grammar.y"
                        {check_for_typedef = 0;}
#line 4265 "C_grammar.tab.c"
    break;

  case 277: /* static_assert_declaration: STATIC_ASSERT $@27 '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1220 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4276 "C_grammar.tab.c"
    break;

  case 284: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1239 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4287 "C_grammar.tab.c"
    break;

  case 285: /* labeled_statement: TYPEDEF_NAME ':' statement  */
#line 1247 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4298 "C_grammar.tab.c"
    break;

  case 286: /* $@28: %empty  */
#line 1253 "C_grammar.y"
               {check_for_typedef = 0;}
#line 4304 "C_grammar.tab.c"
    break;

  case 287: /* labeled_statement: CASE $@28 constant_expression ':' statement  */
#line 1254 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4315 "C_grammar.tab.c"
    break;

  case 288: /* $@29: %empty  */
#line 1260 "C_grammar.y"
                  {check_for_typedef = 0;}
#line 4321 "C_grammar.tab.c"
    break;

  case 289: /* labeled_statement: DEFAULT $@29 ':' statement  */
#line 1261 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4331 "C_grammar.tab.c"
    break;

  case 290: /* compound_statement: '{' '}'  */
#line 1269 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4337 "C_grammar.tab.c"
    break;

  case 291: /* $@30: %empty  */
#line 1270 "C_grammar.y"
              {check_for_typedef = 1;}
#line 4343 "C_grammar.tab.c"
    break;

  case 292: /* compound_statement: '{' $@30 block_item_list '}'  */
#line 1271 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4353 "C_grammar.tab.c"
    break;

  case 293: /* block_item_list: block_item  */
#line 1279 "C_grammar.y"
                     {check_for_typedef = 1;}
#line 4359 "C_grammar.tab.c"
    break;

  case 294: /* $@31: %empty  */
#line 1280 "C_grammar.y"
                                     {check_for_typedef = 1;}
#line 4365 "C_grammar.tab.c"
    break;

  case 295: /* block_item_list: block_item_list block_item $@31  */
#line 1281 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	  }
#line 4376 "C_grammar.tab.c"
    break;

  case 298: /* expression_statement: ';'  */
#line 1295 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4382 "C_grammar.tab.c"
    break;

  case 299: /* expression_statement: expression ';'  */
#line 1297 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4392 "C_grammar.tab.c"
    break;

  case 300: /* $@32: %empty  */
#line 1305 "C_grammar.y"
             {check_for_typedef = 0;}
#line 4398 "C_grammar.tab.c"
    break;

  case 301: /* selection_statement: IF $@32 '(' expression ')' statement else_opt  */
#line 1306 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4410 "C_grammar.tab.c"
    break;

  case 302: /* $@33: %empty  */
#line 1313 "C_grammar.y"
                 {check_for_typedef = 0;}
#line 4416 "C_grammar.tab.c"
    break;

  case 303: /* selection_statement: SWITCH $@33 '(' expression ')' statement  */
#line 1314 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4427 "C_grammar.tab.c"
    break;

  case 304: /* else_opt: %empty  */
#line 1323 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4433 "C_grammar.tab.c"
    break;

  case 305: /* else_opt: ELSE statement  */
#line 1325 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4443 "C_grammar.tab.c"
    break;

  case 306: /* $@34: %empty  */
#line 1332 "C_grammar.y"
                {check_for_typedef = 0;}
#line 4449 "C_grammar.tab.c"
    break;

  case 307: /* iteration_statement: WHILE $@34 '(' expression ')' statement  */
#line 1333 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4460 "C_grammar.tab.c"
    break;

  case 308: /* $@35: %empty  */
#line 1339 "C_grammar.y"
             {check_for_typedef = 0;}
#line 4466 "C_grammar.tab.c"
    break;

  case 309: /* iteration_statement: DO $@35 statement WHILE '(' expression ')' ';'  */
#line 1340 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4477 "C_grammar.tab.c"
    break;

  case 310: /* $@36: %empty  */
#line 1346 "C_grammar.y"
              {check_for_typedef = 0;}
#line 4483 "C_grammar.tab.c"
    break;

  case 311: /* iteration_statement: FOR $@36 '(' for_stmt_type ')' statement  */
#line 1347 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4496 "C_grammar.tab.c"
    break;

  case 312: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1359 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4502 "C_grammar.tab.c"
    break;

  case 313: /* $@37: %empty  */
#line 1360 "C_grammar.y"
          {check_for_typedef = 1;}
#line 4508 "C_grammar.tab.c"
    break;

  case 314: /* for_stmt_type: $@37 declaration expression_opt ';' expression_opt  */
#line 1361 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4514 "C_grammar.tab.c"
    break;

  case 315: /* expression_opt: %empty  */
#line 1365 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4520 "C_grammar.tab.c"
    break;

  case 317: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1370 "C_grammar.y"
          {in_label_namespace = 0;
	   size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4531 "C_grammar.tab.c"
    break;

  case 318: /* jump_statement: CONTINUE ';'  */
#line 1376 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4537 "C_grammar.tab.c"
    break;

  case 319: /* jump_statement: BREAK ';'  */
#line 1377 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4543 "C_grammar.tab.c"
    break;

  case 320: /* jump_statement: RETURN ';'  */
#line 1378 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4549 "C_grammar.tab.c"
    break;

  case 321: /* jump_statement: RETURN expression ';'  */
#line 1380 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4559 "C_grammar.tab.c"
    break;

  case 322: /* translation_unit: external_declaration  */
#line 1389 "C_grammar.y"
                               {check_for_typedef = 1;}
#line 4565 "C_grammar.tab.c"
    break;

  case 323: /* $@38: %empty  */
#line 1390 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4571 "C_grammar.tab.c"
    break;

  case 324: /* translation_unit: translation_unit $@38 external_declaration  */
#line 1390 "C_grammar.y"
                                                                            {check_for_typedef = 1;}
#line 4577 "C_grammar.tab.c"
    break;

  case 325: /* external_declaration: function_definition  */
#line 1394 "C_grammar.y"
                                {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4583 "C_grammar.tab.c"
    break;

  case 326: /* external_declaration: declaration  */
#line 1395 "C_grammar.y"
                                        {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4589 "C_grammar.tab.c"
    break;

  case 327: /* $@39: %empty  */
#line 1399 "C_grammar.y"
                                            {check_for_typedef = 1;}
#line 4595 "C_grammar.tab.c"
    break;

  case 328: /* function_definition: declaration_specifiers declarator $@39 declaration_list_opt compound_statement  */
#line 1400 "C_grammar.y"
                {in_ordinary_id_declaration = 0;
		 size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-4].id), (yyvsp[-3].declarator_type).full, (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4610 "C_grammar.tab.c"
    break;

  case 329: /* declaration_list_opt: %empty  */
#line 1413 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4616 "C_grammar.tab.c"
    break;

  case 331: /* old_style_declaration_list: declaration  */
#line 1418 "C_grammar.y"
                      {check_for_typedef = 1;}
#line 4622 "C_grammar.tab.c"
    break;

  case 332: /* $@40: %empty  */
#line 1419 "C_grammar.y"
                                                 {check_for_typedef = 1;}
#line 4628 "C_grammar.tab.c"
    break;

  case 333: /* old_style_declaration_list: old_style_declaration_list declaration $@40  */
#line 1420 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 4639 "C_grammar.tab.c"
    break;


#line 4643 "C_grammar.tab.c"

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

#line 1428 "C_grammar.y"

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

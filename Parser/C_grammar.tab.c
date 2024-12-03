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

char *current_function;			//we keep track of the function being parsed so that we can add it to goto statements
void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 125 "C_grammar.tab.c"

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
#line 62 "C_grammar.y"

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

#line 265 "C_grammar.tab.c"

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
#define YYLAST   2440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  300
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  492

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
       0,   123,   123,   127,   128,   129,   135,   141,   145,   146,
     147,   151,   155,   156,   160,   164,   165,   169,   170,   174,
     175,   182,   188,   195,   202,   209,   215,   221,   228,   238,
     239,   249,   250,   257,   264,   270,   276,   285,   286,   290,
     291,   292,   293,   294,   295,   299,   300,   310,   311,   322,
     323,   324,   328,   329,   340,   341,   345,   346,   357,   358,
     362,   363,   374,   375,   376,   377,   382,   383,   394,   395,
     399,   400,   410,   411,   421,   422,   432,   433,   443,   444,
     454,   455,   466,   467,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   492,   493,   503,   507,   513,
     531,   540,   547,   548,   555,   556,   563,   564,   566,   568,
     570,   575,   576,   586,   594,   604,   609,   610,   611,   612,
     613,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   636,   637,   638,
     642,   642,   649,   649,   657,   668,   672,   679,   680,   690,
     696,   703,   707,   714,   715,   722,   726,   727,   737,   737,
     741,   741,   747,   747,   755,   755,   763,   769,   775,   775,
     775,   786,   787,   789,   798,   799,   809,   816,   820,   824,
     825,   826,   827,   831,   832,   836,   837,   841,   849,   853,
     877,   877,   880,   887,   892,   897,   902,   907,   912,   917,
     922,   930,   938,   947,   955,   962,   968,   974,   979,   980,
     990,   996,  1005,  1006,  1016,  1024,  1031,  1040,  1041,  1045,
    1046,  1055,  1056,  1057,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1085,  1091,  1097,  1101,  1108,
    1109,  1117,  1127,  1136,  1137,  1147,  1153,  1162,  1172,  1173,
    1174,  1175,  1176,  1177,  1181,  1188,  1195,  1204,  1205,  1214,
    1215,  1225,  1226,  1230,  1231,  1240,  1248,  1258,  1259,  1267,
    1274,  1281,  1293,  1295,  1300,  1301,  1304,  1310,  1311,  1312,
    1313,  1323,  1324,  1324,  1328,  1329,  1333,  1346,  1347,  1351,
    1352
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

#define YYPACT_NINF (-387)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-298)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2100,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,   -52,    19,  2361,  -387,  -387,
      31,  -387,  -387,  -387,  -387,  -387,    40,  2205,  2205,  -387,
      13,  -387,  -387,  2205,  2205,  2205,  -387,    44,  -387,  -387,
      58,   154,   987,  2361,   -46,  2361,    82,  1678,  -387,    79,
     162,  -387,   -32,  -387,   817,   -11,    53,  -387,  -387,    81,
    -387,  -387,  -387,  -387,  -387,  2100,  -387,    71,   -10,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  1693,  -387,  -387,
      98,   100,   894,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,   181,  -387,  1708,  1678,  -387,   -34,    80,
     196,    67,   197,   106,    90,    87,   194,     6,  -387,   144,
     151,  -387,  1832,  1080,    -4,  -387,   101,  -387,  -387,   153,
    -387,  -387,  -387,   162,    79,  -387,  1554,  -387,    40,   156,
    2100,  1996,  1095,   -11,   161,  2257,  -387,  1678,    28,  -387,
     166,   894,  -387,  2361,  1678,   538,   327,  -387,  -387,   135,
     160,   179,   260,  -387,  -387,  1570,  1678,   262,   894,  -387,
    -387,  -387,  -387,  -387,  1678,  -387,  -387,  1678,  -387,  -387,
    1678,  -387,  -387,  -387,  -387,  1678,  -387,  -387,  1678,  1678,
    1678,  1678,  1678,  1678,  1678,  -387,  -387,  -387,    38,   185,
     186,  -387,   189,  1404,  -387,   187,   188,  1188,   101,  2048,
    1203,   269,   199,  -387,  -387,  -387,   182,  1538,  -387,  -387,
    -387,  -387,  -387,  -387,   200,   139,  1404,  -387,   201,   205,
    1296,  2257,  1886,  -387,   190,  -387,  -387,  -387,  -387,    58,
    -387,   213,   216,   218,   215,  1678,   219,   221,   223,   224,
     430,   225,   304,   204,   210,   739,  -387,  -387,   -29,  -387,
    -387,  -387,  -387,   631,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    1678,  -387,  1678,  1585,  -387,  -387,  -387,   149,  -387,    52,
    -387,   233,  -387,   -34,    80,   196,    67,   197,   106,    90,
      87,   194,   155,  1772,  -387,    35,  -387,  -387,  2152,  -387,
     230,  1404,  -387,  -387,  1678,  -387,   234,  -387,   240,  1404,
    -387,   238,   239,  1311,   244,  -387,  1678,   325,  -387,    10,
    1554,   -37,  -387,  -387,  -387,   329,   248,  1404,  -387,  -387,
    1678,  -387,   249,   251,  1938,  -387,  -387,  -387,   -28,  -387,
      77,    60,   242,  -387,  2309,   430,   254,   430,  1678,  1678,
    1678,   277,   724,   236,  -387,  -387,  -387,   -19,  -387,  -387,
    -387,  -387,  -387,  1538,  -387,  -387,  1678,  -387,   242,  1678,
    -387,  -387,  -387,   256,   257,  -387,  -387,   258,  1404,  -387,
    -387,  1678,  -387,   259,   255,   274,  -387,  1419,  -387,  -387,
    -387,  -387,  -387,  -387,   276,   278,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,   282,    43,  -387,   283,   158,  -387,   284,
    -387,   430,  -387,   164,   169,   174,   265,  1678,  1678,   287,
    -387,  -387,    88,  -387,  -387,  -387,  -387,  -387,   285,   286,
    -387,  -387,  -387,  -387,  -387,  1554,  -387,  -387,  -387,  1678,
     289,  -387,  -387,  1678,  -387,  2309,  1678,  -387,   430,   430,
     430,  1678,   291,   266,   271,   430,  1445,  -387,  -387,  -387,
    -387,  -387,  1678,  -387,  -387,  -387,   316,  -387,  -387,   176,
    1678,  1678,  -387,  -387,  -387,   430,  -387,   273,  -387,  -387,
    -387,  -387
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   136,   115,   116,   117,   119,   120,   183,   179,   180,
     181,   130,   122,   123,   124,   125,   128,   129,   126,   127,
     121,   131,   132,   145,   146,   168,     0,     0,   182,   184,
       0,   118,   137,   138,   139,   295,     0,   102,   104,   134,
       0,   135,   133,   106,   108,   110,   100,   292,   291,   294,
       0,     0,     0,   153,   220,   155,     0,     0,   189,     0,
     207,    98,     0,   111,   114,   188,     0,   101,   103,   144,
     140,   105,   107,   109,     1,     0,    11,   177,     0,   174,
     169,     2,     8,     9,    10,    12,    13,     0,    37,    38,
       0,     0,     0,    39,    40,    41,    42,    43,    44,    19,
       3,     4,     7,    31,    45,     0,     0,    47,    52,    56,
      60,    66,    70,    72,    74,    76,    78,    80,    97,     0,
       0,   152,     0,     0,   222,   219,   223,   154,   178,     0,
     190,   208,   206,   205,     0,    99,     0,   299,     0,     0,
     298,     0,     0,   187,     0,     0,   293,     0,     0,   166,
     171,     0,    34,     0,     0,     0,    45,    82,    95,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    32,
      33,    49,    50,    51,     0,    54,    55,     0,    58,    59,
       0,    64,    65,    62,    63,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,   186,   185,   241,   216,     0,
     211,   212,     0,     0,   225,    40,     0,     0,   221,     0,
       0,     0,     0,   209,   204,   112,   114,     0,   247,   113,
     296,   300,   217,   201,     0,     0,     0,   192,    40,     0,
       0,     0,     0,   147,   158,   151,   176,   167,   175,     0,
     170,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   273,     0,   271,
     272,   258,   259,     0,   269,   260,   261,   262,   263,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    84,
       0,     6,     0,     0,     5,    24,    21,     0,    29,     0,
      23,     0,    48,    53,    57,    61,    67,    71,    73,    75,
      77,    79,     0,     0,   214,   222,   215,   242,     0,   224,
       0,     0,   226,   232,     0,   231,     0,   243,     0,     0,
     233,    40,     0,     0,     0,   191,     0,     0,   249,     0,
       0,     0,   253,   202,   203,     0,     0,     0,   193,   200,
       0,   199,    40,     0,     0,   141,   148,   149,     0,   156,
       0,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,     0,   274,   268,
     270,    83,    96,     0,    46,    22,     0,    20,     0,     0,
     210,   213,   228,     0,     0,   230,   244,     0,     0,   234,
     240,     0,   239,     0,     0,     0,   256,     0,   245,   248,
     252,   254,   218,   195,     0,     0,   196,   198,   143,   158,
     150,   160,   159,   164,     0,   172,     0,     0,    15,     0,
     264,     0,   266,     0,     0,     0,     0,   284,   284,     0,
     286,   290,     0,    30,    81,   227,   229,   236,     0,     0,
     237,   257,   255,   246,   251,     0,   194,   197,   157,     0,
       0,   165,   173,     0,    14,     0,     0,   265,     0,     0,
       0,     0,   285,     0,     0,     0,     0,    27,   235,   238,
     250,   161,     0,    18,    16,    17,   277,   276,   279,     0,
     284,   284,   281,    28,   163,     0,   275,     0,   283,   282,
     278,   280
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -387,  -387,  -387,  -387,  -387,  -387,  -387,   -77,  -387,  -387,
     -38,  -387,  -387,   -96,   202,  -387,   203,  -387,   195,  -387,
     198,  -387,   193,  -387,   206,   207,   192,   211,  -387,   -50,
      83,  -387,   -80,   -56,   -51,    15,  -387,   253,  -387,   -23,
    -387,  -387,  -387,  -387,   157,  -211,   -47,  -387,   -24,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,   150,  -139,
    -387,   -27,  -387,  -387,   -31,   -55,  -387,   -20,    17,  -104,
    -387,    84,  -387,    -5,   -36,  -107,  -133,    18,  -374,  -387,
      59,  -121,  -230,  -387,   121,  -387,   132,    41,  -387,  -387,
    -387,  -387,  -386,  -387,  -387,  -387,   330,  -387,  -387,  -387
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    99,   100,    77,   101,   102,   417,   418,   103,   287,
     156,   105,   106,   107,   108,   174,   109,   177,   110,   180,
     111,   185,   112,   188,   113,   114,   115,   116,   117,   157,
     158,   280,   258,   119,    35,   138,    62,    63,    37,    38,
      39,   145,   144,    40,   232,   233,    54,   348,   349,   350,
     412,   449,   450,   451,    41,    51,   150,   240,    78,    79,
      42,    43,    44,    45,   130,    65,   212,    66,   133,   199,
     200,   201,   225,   419,   202,   126,   328,   329,   330,   331,
     332,    46,   260,   261,   262,   263,   264,   265,   266,   486,
     267,   429,   463,   268,    47,    75,    48,    49,   139,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   129,   118,   219,    53,    64,   121,   118,   127,   238,
     170,   143,   159,   137,   104,    36,    69,   208,   125,   104,
     361,   346,    56,   445,   235,    55,    55,   193,    55,    53,
      53,    76,    53,   131,   124,   122,    50,   224,    58,   123,
     132,    58,   464,    58,    74,    60,    76,   120,   326,   152,
     327,   134,    67,    68,   282,   409,    58,   171,    71,    72,
      73,    76,   172,   173,   282,    55,   400,   169,   104,    53,
     141,   159,   135,   148,   142,   368,   410,   122,   292,   149,
      58,   123,    58,   181,   182,   431,   289,   160,   159,   221,
      36,   236,   445,   397,   488,   489,   131,   118,   234,   398,
      52,    70,   124,   216,   259,   318,   213,   216,   194,   104,
     235,   235,    57,   214,   302,   131,   303,   237,    55,   303,
     123,    59,    53,   123,    55,   420,    55,   422,    53,    60,
      53,    60,   452,   346,    59,   282,   104,   198,   377,   104,
     207,    55,   104,   414,    61,    53,   241,   104,   242,   415,
     104,   104,   104,   104,   104,   104,   198,    80,    59,   230,
      59,   411,   306,   291,   128,   183,   184,   304,    60,  -142,
      60,   466,   175,   176,   147,   367,   131,   467,   305,   153,
     213,   154,   209,   131,   234,   234,   210,   374,   191,   356,
     190,   457,   162,   163,   164,   118,   189,   399,   208,   131,
       8,     9,    10,   213,    55,    55,   206,   104,    53,    53,
     178,   179,   259,   161,   192,   186,   187,   281,   282,   218,
     311,   334,   335,   235,   198,   229,   195,   323,   476,   477,
     478,   375,   376,   196,    28,   482,   211,   243,   282,   379,
     454,   455,   283,   337,   155,   104,   458,   282,   288,   231,
     143,   459,   282,    60,   239,   490,   460,   282,   487,   282,
     220,   284,   165,   285,   444,   290,   166,   307,   167,   308,
     395,   309,   161,   312,   313,   238,   118,   324,   423,   424,
     425,   325,   333,   305,   213,   136,   310,   338,   104,   161,
     316,   339,   131,   322,   347,   352,   213,   234,   353,   355,
     218,   354,   358,   357,   359,   360,   362,   363,   364,   336,
     213,   427,   470,   343,   365,   378,   382,    55,   198,   413,
     385,    53,   386,   198,   389,   390,   394,    55,   396,   434,
     373,    53,   402,   444,   403,   406,   388,   407,   421,   426,
     430,   104,   435,   436,   437,   440,   461,   462,   462,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   441,
     442,   213,   446,   371,   447,   372,  -162,   453,   456,   465,
     480,   468,   469,   472,   282,   481,   485,   491,   474,   293,
     295,   479,   297,   294,   300,   448,   296,   215,   344,   351,
     401,   432,   381,   471,   383,   370,   298,   384,   299,   118,
     462,   462,   387,   428,   301,   146,   393,     0,     0,     0,
       0,   104,     0,   218,     0,     0,   484,     0,     0,     0,
     404,     0,   118,   405,     0,     0,     0,     0,    55,     0,
     279,     0,    53,   244,   104,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,     0,     0,   433,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,     0,     0,   439,     0,     0,     0,     0,     0,
     218,     0,     0,     0,     0,     0,     0,   245,   246,   247,
       0,   248,   249,   250,   251,   252,   253,   254,   255,     0,
      90,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,     0,   155,     0,
      93,    94,    95,    96,    97,    98,     0,     0,   218,     0,
       0,     0,     0,     0,   257,     0,   473,     0,     0,   475,
       0,   244,     1,    82,    83,    84,    85,    86,    87,   218,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,   245,   246,   247,     0,   248,
     249,   250,   251,   252,   253,   254,   255,    26,    90,    27,
      28,    91,    29,    30,    31,    32,    33,    34,     0,    92,
       0,     0,     0,     0,     0,     0,   155,   256,    93,    94,
      95,    96,    97,    98,   244,     1,    82,    83,    84,    85,
      86,    87,   257,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   245,   246,
     247,     0,   248,   249,   250,   251,   252,   253,   254,   255,
      26,    90,    27,    28,    91,    29,    30,    31,    32,    33,
      34,     0,    92,     0,     0,     0,     0,     0,     0,   155,
     369,    93,    94,    95,    96,    97,    98,    81,     1,    82,
      83,    84,    85,    86,    87,   257,    88,    89,     0,     0,
       0,     0,    81,     0,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    90,    27,    28,    91,    29,    30,
      31,    32,    33,    34,     0,    92,     0,     0,     0,    90,
       0,     0,    91,     0,    93,    94,    95,    96,    97,    98,
      92,     1,     0,     0,     0,     0,     0,     0,   257,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,   366,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    81,     1,    82,
      83,    84,    85,    86,    87,  -297,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    27,    28,    91,     0,     0,
       0,    32,    33,    34,     0,    92,     0,     0,     0,     0,
       0,     0,   155,     0,    93,    94,    95,    96,    97,    98,
      81,     1,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    27,    28,
      91,     0,     0,     0,    32,    33,    34,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,    81,     0,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,    81,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,   203,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,    28,    91,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,     0,    90,   204,    28,    91,     0,
      93,   205,    95,    96,    97,    98,    92,     0,     0,     0,
       0,   227,     0,     0,     0,    93,   228,    95,    96,    97,
      98,    81,     0,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,    81,     0,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,   314,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,   319,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
      28,    91,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,    90,   315,    28,    91,     0,    93,    94,
      95,    96,    97,    98,    92,     0,     0,     0,     0,   320,
       0,     0,     0,    93,   321,    95,    96,    97,    98,    81,
       0,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,    81,     0,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
     340,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,   391,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,    28,    91,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
       0,    90,   341,    28,    91,     0,    93,   342,    95,    96,
      97,    98,    92,     0,     0,     0,     0,   392,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    81,     0,    82,
      83,    84,    85,    86,    87,     0,    88,    89,     0,     0,
       0,     0,    81,     0,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,     0,     0,     0,    81,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,    28,    91,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,    90,
       0,     0,    91,     0,    93,    94,    95,    96,    97,    98,
      92,     0,     0,     0,   326,     0,   327,   217,   443,    93,
      94,    95,    96,    97,    98,    90,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
     326,     0,   327,   217,   483,    93,    94,    95,    96,    97,
      98,    81,     0,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,    81,     0,    82,
      83,    84,    85,    86,    87,     0,    88,    89,     0,     0,
       0,     0,     0,    81,     0,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,    81,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,   326,    90,   327,   217,    91,    93,    94,
      95,    96,    97,    98,     0,    92,     0,     0,     0,     0,
      90,     0,   217,    91,    93,    94,    95,    96,    97,    98,
       0,    92,   286,     0,     0,    90,     0,     0,    91,     0,
      93,    94,    95,    96,    97,    98,    92,     0,     0,     0,
       0,     0,     0,   373,     0,    93,    94,    95,    96,    97,
      98,    81,     0,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,    81,     0,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,    81,     0,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,    90,     0,     0,    91,     0,    93,    94,
      95,    96,    97,    98,   151,    58,     1,     0,    90,     0,
       0,    91,     0,    93,    94,    95,    96,    97,    98,   168,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97,    98,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,    32,
      33,    34,     0,   303,   197,     0,     0,   123,     0,     0,
       0,     0,     0,    60,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,    32,
      33,    34,     0,   122,   197,     0,     0,   123,     0,     0,
       0,     0,     0,    60,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,    30,     0,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   345,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,   222,
       1,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,    30,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   408,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,     0,    31,    32,    33,    34,     0,     0,   223,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,    29,     0,    31,    32,    33,    34,     0,     0,
     317,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,    30,    31,    32,    33,    34,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   380,     1,
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
      21,    22,    23,    24,    25,     1,     0,   416,     0,     0,
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
      27,    57,    52,   136,    27,    36,    53,    57,    55,   148,
     106,    66,    92,    64,    52,     0,     3,   124,    54,    57,
     250,   232,    27,   397,   145,    52,    53,    21,    55,    52,
      53,     3,    55,    60,    54,    81,    88,   141,     3,    85,
      60,     3,   428,     3,     0,    91,     3,    52,    85,    87,
      87,    83,    37,    38,    83,    83,     3,    91,    43,    44,
      45,     3,    96,    97,    83,    92,   103,   105,   106,    92,
      81,   151,   104,    83,    85,   104,   104,    81,   174,    89,
       3,    85,     3,    16,    17,   104,   166,    92,   168,   140,
      75,   147,   466,    83,   480,   481,   123,   147,   145,    89,
      81,    88,   122,   134,   155,   209,   133,   138,   102,   147,
     231,   232,    81,   133,   194,   142,    81,    89,   145,    81,
      85,    81,   145,    85,   151,   355,   153,   357,   151,    91,
     153,    91,    89,   344,    81,    83,   174,   122,    86,   177,
     123,   168,   180,    83,   104,   168,   151,   185,   153,    89,
     188,   189,   190,   191,   192,   193,   141,     3,    81,   142,
      81,    84,   198,   168,    82,    98,    99,   198,    91,    88,
      91,    83,    92,    93,   103,   255,   203,    89,   198,    81,
     207,    81,    81,   210,   231,   232,    85,   283,   101,   245,
     100,   421,    11,    12,    13,   245,    90,   330,   305,   226,
      38,    39,    40,   230,   231,   232,   123,   245,   231,   232,
      14,    15,   263,    92,    20,    18,    19,    82,    83,   136,
     203,    82,    83,   344,   209,   142,    82,   210,   458,   459,
     460,    82,    83,    82,    72,   465,    83,   154,    83,    84,
      82,    83,    82,   226,    88,   283,    82,    83,   165,    88,
     305,    82,    83,    91,    88,   485,    82,    83,    82,    83,
     139,    82,    81,     3,   397,     3,    85,    82,    87,    83,
     326,    82,   151,    86,    86,   414,   326,     8,   358,   359,
     360,    82,    82,   303,   311,   103,   203,    86,   326,   168,
     207,    86,   319,   210,   104,    82,   323,   344,    82,    84,
     217,    83,    81,    84,    81,    81,    81,     3,   104,   226,
     337,   362,   445,   230,   104,    82,    86,   344,   303,   350,
      86,   344,    82,   308,    86,    86,    82,   354,     3,   379,
      88,   354,     3,   466,    86,    86,   319,    86,    84,    62,
     104,   379,    86,    86,    86,    86,    81,   427,   428,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   104,
      86,   388,    86,   280,    86,   282,    84,    84,    84,    82,
     104,    86,    86,    84,    83,   104,    60,   104,   455,   177,
     185,   461,   189,   180,   192,   409,   188,   134,   231,   239,
     331,   373,   308,   449,   311,   263,   190,   314,   191,   449,
     480,   481,   319,   362,   193,    75,   323,    -1,    -1,    -1,
      -1,   449,    -1,   330,    -1,    -1,   472,    -1,    -1,    -1,
     337,    -1,   472,   340,    -1,    -1,    -1,    -1,   455,    -1,
     103,    -1,   455,     3,   472,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   388,    -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,
     397,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      90,    91,    92,    93,    94,    95,    -1,    -1,   445,    -1,
      -1,    -1,    -1,    -1,   104,    -1,   453,    -1,    -1,   456,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,   466,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,     3,     4,     5,     6,     7,     8,
       9,    10,   104,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,     3,     4,     5,
       6,     7,     8,     9,    10,   104,    12,    13,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    90,    91,    92,    93,    94,    95,
      81,     4,    -1,    -1,    -1,    -1,    -1,    -1,   104,    90,
      91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    76,    77,    78,    79,     3,     4,     5,
       6,     7,     8,     9,    10,    88,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    77,    78,    79,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    90,    91,    92,    93,    94,    95,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
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
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    90,    91,    92,    93,    94,    95,
      81,    -1,    -1,    -1,    85,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    70,    87,    88,    73,    90,    91,
      92,    93,    94,    95,    -1,    81,    -1,    -1,    -1,    -1,
      70,    -1,    88,    73,    90,    91,    92,    93,    94,    95,
      -1,    81,    82,    -1,    -1,    70,    -1,    -1,    73,    -1,
      90,    91,    92,    93,    94,    95,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    90,    91,    92,    93,    94,
      95,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
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
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    75,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    82,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,
      82,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
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
      86,    91,   135,   173,     8,    82,    85,    87,   181,   182,
     183,   184,   185,    82,    82,    83,   135,   173,    86,    86,
      34,    86,    91,   135,   149,    89,   150,   104,   152,   153,
     154,   163,    82,    82,    83,    84,   138,    84,    81,    81,
      81,   187,    81,     3,   104,   104,   104,   137,   104,    89,
     191,   135,   135,    88,   118,    82,    83,    86,    82,    84,
      56,   176,    86,   135,   135,    86,    82,   135,   173,    86,
      86,    34,    86,   135,    82,   138,     3,    83,    89,   181,
     103,   185,     3,    86,   135,   135,    86,    86,    89,    83,
     104,    84,   155,   169,    83,    89,    58,   111,   112,   178,
     187,    84,   187,   137,   137,   137,    62,   139,   192,   196,
     104,   104,   182,   135,   134,    86,    86,    86,   135,   135,
      86,   104,    86,    89,   181,   183,    86,    86,   153,   156,
     157,   158,    89,    84,    82,    83,    84,   187,    82,    82,
      82,    81,   137,   197,   197,    82,    83,    89,    86,    86,
     181,   138,    84,   135,   112,   135,   187,   187,   187,   137,
     104,   104,   187,    89,   138,    60,   194,    82,   197,   197,
     187,   104
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
     180,   180,   180,   180,   180,   181,   181,   181,   182,   182,
     182,   182,   183,   184,   184,   185,   185,   186,   187,   187,
     187,   187,   187,   187,   188,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   194,   195,
     195,   195,   196,   196,   197,   197,   198,   198,   198,   198,
     198,   199,   200,   199,   201,   201,   202,   203,   203,   204,
     204
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
       4,     2,     3,     3,     4,     3,     4,     1,     2,     1,
       4,     3,     2,     1,     2,     3,     2,     7,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     1,
       2,     1,     1,     1,     2,     6,     5,     0,     2,     5,
       7,     5,     4,     4,     0,     1,     3,     2,     2,     2,
       3,     1,     0,     3,     1,     1,     4,     0,     1,     1,
       2
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
#line 124 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2503 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' compound_statement ')'  */
#line 130 "C_grammar.y"
                {size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2513 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' expression ')'  */
#line 136 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2523 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: generic_selection  */
#line 141 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2529 "C_grammar.tab.c"
    break;

  case 13: /* string: FUNC_NAME  */
#line 156 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2535 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 176 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2546 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' ')'  */
#line 183 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2556 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 189 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2567 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 196 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2578 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 203 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2589 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression INC_OP  */
#line 210 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2599 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression DEC_OP  */
#line 216 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2609 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 222 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2620 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 229 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2631 "C_grammar.tab.c"
    break;

  case 30: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 240 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2642 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_inc_dec unary_expression  */
#line 251 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2653 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 258 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2664 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 265 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2674 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 271 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2684 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 277 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2694 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: INC_OP  */
#line 285 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2700 "C_grammar.tab.c"
    break;

  case 38: /* unary_inc_dec: DEC_OP  */
#line 286 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2706 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '&'  */
#line 290 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2712 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '*'  */
#line 291 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2718 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '+'  */
#line 292 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2724 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '-'  */
#line 293 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2730 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '~'  */
#line 294 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2736 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '!'  */
#line 295 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2742 "C_grammar.tab.c"
    break;

  case 46: /* cast_expression: '(' type_name ')' cast_expression  */
#line 301 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2753 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 312 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2765 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '*'  */
#line 322 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2771 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '/'  */
#line 323 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2777 "C_grammar.tab.c"
    break;

  case 51: /* multiplicative_expression_op: '%'  */
#line 324 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2783 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 330 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2795 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '+'  */
#line 340 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2801 "C_grammar.tab.c"
    break;

  case 55: /* additive_expression_op: '-'  */
#line 341 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2807 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 347 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2819 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: LEFT_OP  */
#line 357 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2825 "C_grammar.tab.c"
    break;

  case 59: /* shift_expression_op: RIGHT_OP  */
#line 358 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2831 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 364 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2843 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '<'  */
#line 374 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2849 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: '>'  */
#line 375 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2855 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: LE_OP  */
#line 376 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2861 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression_operator: GE_OP  */
#line 377 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2867 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 384 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2879 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: EQ_OP  */
#line 394 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2885 "C_grammar.tab.c"
    break;

  case 69: /* equality_expression_op: NE_OP  */
#line 395 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2891 "C_grammar.tab.c"
    break;

  case 71: /* and_expression: and_expression '&' equality_expression  */
#line 401 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2902 "C_grammar.tab.c"
    break;

  case 73: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 412 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2913 "C_grammar.tab.c"
    break;

  case 75: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 423 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2924 "C_grammar.tab.c"
    break;

  case 77: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 434 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2935 "C_grammar.tab.c"
    break;

  case 79: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 445 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2946 "C_grammar.tab.c"
    break;

  case 81: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 456 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2958 "C_grammar.tab.c"
    break;

  case 83: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 468 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2970 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: '='  */
#line 478 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2976 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: MUL_ASSIGN  */
#line 479 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2982 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: DIV_ASSIGN  */
#line 480 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2988 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: MOD_ASSIGN  */
#line 481 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2994 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: ADD_ASSIGN  */
#line 482 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 3000 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: SUB_ASSIGN  */
#line 483 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 3006 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: LEFT_ASSIGN  */
#line 484 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 3012 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: RIGHT_ASSIGN  */
#line 485 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 3018 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: AND_ASSIGN  */
#line 486 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 3024 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: XOR_ASSIGN  */
#line 487 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3030 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: OR_ASSIGN  */
#line 488 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3036 "C_grammar.tab.c"
    break;

  case 96: /* expression: expression ',' assignment_expression  */
#line 494 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3047 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers ';'  */
#line 508 "C_grammar.y"
                {size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3057 "C_grammar.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 514 "C_grammar.y"
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
#line 3079 "C_grammar.tab.c"
    break;

  case 100: /* declaration: static_assert_declaration  */
#line 532 "C_grammar.y"
                {size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3089 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 541 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3100 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 549 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3111 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 557 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3122 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 565 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); }
#line 3128 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: function_specifier  */
#line 567 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); }
#line 3134 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 569 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); }
#line 3140 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: alignment_specifier  */
#line 571 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); }
#line 3146 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 577 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3157 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator '=' initializer  */
#line 587 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
	   	 //free($3);		//todo why is this commented out?
	  	}
#line 3169 "C_grammar.tab.c"
    break;

  case 114: /* init_declarator: declarator  */
#line 595 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_name((yyvsp[0].declarator_type).ptr_declarator);	
	   	 }
		 free((yyvsp[0].declarator_type).ptr_declarator);
		 simple_str_copy(&(yyval.id), (yyvsp[0].declarator_type).full);
	  	}
#line 3180 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: TYPEDEF  */
#line 605 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 //if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3189 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: EXTERN  */
#line 609 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3195 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: STATIC  */
#line 610 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3201 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: THREAD_LOCAL  */
#line 611 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3207 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: AUTO  */
#line 612 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3213 "C_grammar.tab.c"
    break;

  case 120: /* storage_class_specifier: REGISTER  */
#line 613 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3219 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: VOID  */
#line 617 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 3225 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: CHAR  */
#line 618 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 3231 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: SHORT  */
#line 619 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 3237 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: INT  */
#line 620 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 3243 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: LONG  */
#line 621 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 3249 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: FLOAT  */
#line 622 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 3255 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: DOUBLE  */
#line 623 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 3261 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: SIGNED  */
#line 624 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3267 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: UNSIGNED  */
#line 625 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3273 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: BOOL  */
#line 626 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3279 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: COMPLEX  */
#line 627 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3285 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: IMAGINARY  */
#line 628 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3291 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: atomic_type_specifier  */
#line 629 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3297 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: TYPEDEF_NAME  */
#line 633 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3305 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: INT128  */
#line 636 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int128"); }
#line 3311 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: FLOAT128  */
#line 637 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float128"); }
#line 3317 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: VA_LIST  */
#line 638 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "va_list"); }
#line 3323 "C_grammar.tab.c"
    break;

  case 140: /* $@1: %empty  */
#line 642 "C_grammar.y"
                              {in_tag_namespace = 0;}
#line 3329 "C_grammar.tab.c"
    break;

  case 141: /* struct_or_union_specifier: struct_or_union '{' $@1 struct_declaration_list '}'  */
#line 643 "C_grammar.y"
                {size_t const size = strlen("('anonymous', [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s('anonymous', [%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3340 "C_grammar.tab.c"
    break;

  case 142: /* $@2: %empty  */
#line 649 "C_grammar.y"
                                     {in_tag_namespace = 0;}
#line 3346 "C_grammar.tab.c"
    break;

  case 143: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@2 '{' struct_declaration_list '}'  */
#line 650 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
	    }
#line 3358 "C_grammar.tab.c"
    break;

  case 144: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 658 "C_grammar.y"
                {in_tag_namespace = 0;
		 size_t const size = strlen("%s(%s, 'forward')") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, 'forward')", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3370 "C_grammar.tab.c"
    break;

  case 145: /* struct_or_union: STRUCT  */
#line 669 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_namespace = 1;
		}
#line 3378 "C_grammar.tab.c"
    break;

  case 146: /* struct_or_union: UNION  */
#line 673 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_namespace = 1;
		}
#line 3386 "C_grammar.tab.c"
    break;

  case 148: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 681 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3397 "C_grammar.tab.c"
    break;

  case 149: /* struct_declaration: specifier_qualifier_list ';'  */
#line 691 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3407 "C_grammar.tab.c"
    break;

  case 150: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 697 "C_grammar.y"
                {size_t const size = strlen("struct_decl([], [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
	   	 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
        }
#line 3418 "C_grammar.tab.c"
    break;

  case 152: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 708 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3429 "C_grammar.tab.c"
    break;

  case 154: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 716 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3440 "C_grammar.tab.c"
    break;

  case 157: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 728 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3451 "C_grammar.tab.c"
    break;

  case 158: /* $@3: %empty  */
#line 737 "C_grammar.y"
          {in_member_namespace = 1;}
#line 3457 "C_grammar.tab.c"
    break;

  case 159: /* struct_declarator: $@3 struct_declarator2  */
#line 738 "C_grammar.y"
                {(yyval.id) = (yyvsp[0].id);}
#line 3463 "C_grammar.tab.c"
    break;

  case 160: /* $@4: %empty  */
#line 741 "C_grammar.y"
              {in_member_namespace = 0;}
#line 3469 "C_grammar.tab.c"
    break;

  case 161: /* struct_declarator2: ':' $@4 constant_expression  */
#line 742 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3479 "C_grammar.tab.c"
    break;

  case 162: /* $@5: %empty  */
#line 747 "C_grammar.y"
                     {in_member_namespace = 0;}
#line 3485 "C_grammar.tab.c"
    break;

  case 163: /* struct_declarator2: declarator $@5 ':' constant_expression  */
#line 748 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[0].id));
	   	 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-3].declarator_type).ptr_declarator);
	     free((yyvsp[0].id));
        }
#line 3497 "C_grammar.tab.c"
    break;

  case 164: /* $@6: %empty  */
#line 755 "C_grammar.y"
                      {in_member_namespace = 0;}
#line 3503 "C_grammar.tab.c"
    break;

  case 165: /* struct_declarator2: declarator $@6  */
#line 756 "C_grammar.y"
                {(yyval.id) = strdup((yyvsp[-1].declarator_type).full);
		 free((yyvsp[-1].declarator_type).full);
		 free((yyvsp[-1].declarator_type).ptr_declarator);
		}
#line 3512 "C_grammar.tab.c"
    break;

  case 166: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 764 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3522 "C_grammar.tab.c"
    break;

  case 167: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 770 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3532 "C_grammar.tab.c"
    break;

  case 168: /* $@7: %empty  */
#line 775 "C_grammar.y"
               {in_tag_namespace = 1;}
#line 3538 "C_grammar.tab.c"
    break;

  case 169: /* $@8: %empty  */
#line 775 "C_grammar.y"
                                                  {in_tag_namespace = 0;}
#line 3544 "C_grammar.tab.c"
    break;

  case 170: /* enum_specifier: ENUM $@7 IDENTIFIER $@8 enum_specifier_rest  */
#line 776 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3555 "C_grammar.tab.c"
    break;

  case 171: /* enum_specifier_rest: %empty  */
#line 786 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3561 "C_grammar.tab.c"
    break;

  case 172: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 788 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3567 "C_grammar.tab.c"
    break;

  case 173: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 790 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3577 "C_grammar.tab.c"
    break;

  case 175: /* enumerator_list: enumerator_list ',' enumerator  */
#line 800 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3588 "C_grammar.tab.c"
    break;

  case 176: /* enumerator: enumeration_constant '=' constant_expression  */
#line 810 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3599 "C_grammar.tab.c"
    break;

  case 179: /* type_qualifier: CONST  */
#line 824 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3605 "C_grammar.tab.c"
    break;

  case 180: /* type_qualifier: RESTRICT  */
#line 825 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3611 "C_grammar.tab.c"
    break;

  case 181: /* type_qualifier: VOLATILE  */
#line 826 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3617 "C_grammar.tab.c"
    break;

  case 182: /* type_qualifier: ATOMIC  */
#line 827 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3623 "C_grammar.tab.c"
    break;

  case 183: /* function_specifier: INLINE  */
#line 831 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3629 "C_grammar.tab.c"
    break;

  case 184: /* function_specifier: NORETURN  */
#line 832 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3635 "C_grammar.tab.c"
    break;

  case 187: /* declarator: pointer direct_declarator  */
#line 842 "C_grammar.y"
          {size_t const size = strlen("ptr_decl(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
       (yyval.declarator_type).full = (char*)malloc(size);
       sprintf_safe((yyval.declarator_type).full, size, "ptr_decl(%s, %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	   (yyval.declarator_type).ptr_declarator = (yyvsp[0].declarator_type).ptr_declarator;
	   free((yyvsp[-1].id));
	   free((yyvsp[0].declarator_type).full);
      }
#line 3647 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: IDENTIFIER  */
#line 854 "C_grammar.y"
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
#line 3675 "C_grammar.tab.c"
    break;

  case 190: /* $@9: %empty  */
#line 877 "C_grammar.y"
                         {in_member_namespace = 0;}
#line 3681 "C_grammar.tab.c"
    break;

  case 191: /* direct_declarator: '(' declarator $@9 ')'  */
#line 879 "C_grammar.y"
                {(yyval.declarator_type) = (yyvsp[-2].declarator_type);}
#line 3687 "C_grammar.tab.c"
    break;

  case 192: /* direct_declarator: direct_declarator '[' ']'  */
#line 881 "C_grammar.y"
                {size_t const size = strlen("array_decl(, int(0))") + strlen((yyvsp[-2].declarator_type).full) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, int(0))", (yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3698 "C_grammar.tab.c"
    break;

  case 193: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 888 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D3");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3707 "C_grammar.tab.c"
    break;

  case 194: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 893 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D4");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3716 "C_grammar.tab.c"
    break;

  case 195: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 898 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D5");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3725 "C_grammar.tab.c"
    break;

  case 196: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 903 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D6");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3734 "C_grammar.tab.c"
    break;

  case 197: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 908 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D7");
		 free((yyvsp[-5].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-5].declarator_type).ptr_declarator;
		}
#line 3743 "C_grammar.tab.c"
    break;

  case 198: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 913 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D8");
		 free((yyvsp[-4].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-4].declarator_type).ptr_declarator;
		}
#line 3752 "C_grammar.tab.c"
    break;

  case 199: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 918 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D9");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3761 "C_grammar.tab.c"
    break;

  case 200: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 923 "C_grammar.y"
                {size_t const size = strlen("array_decl(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
         (yyval.declarator_type).full = (char*)malloc(size);
         sprintf_safe((yyval.declarator_type).full, size, "array_decl(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 free((yyvsp[-3].declarator_type).full);
		 free((yyvsp[-1].id));
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3773 "C_grammar.tab.c"
    break;

  case 201: /* direct_declarator: direct_declarator '(' ')'  */
#line 931 "C_grammar.y"
                {size_t const size = strlen("function(, [])") + strlen((yyvsp[-2].declarator_type).full) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, [])", (yyvsp[-2].declarator_type).full);
		 current_function = strdup((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-2].declarator_type).ptr_declarator;
		}
#line 3785 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 939 "C_grammar.y"
                {size_t const size = strlen("function(, )") + strlen((yyvsp[-3].declarator_type).full) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.declarator_type).full = (char*)malloc(size);
	     sprintf_safe((yyval.declarator_type).full, size, "function(%s, %s)", (yyvsp[-3].declarator_type).full, (yyvsp[-1].id));
		 current_function = strdup((yyvsp[-3].declarator_type).full);
	     free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		 free((yyvsp[-1].id));
		}
#line 3798 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 948 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.declarator_type).full, "D13");
		 free((yyvsp[-3].declarator_type).full);
		 (yyval.declarator_type).ptr_declarator = (yyvsp[-3].declarator_type).ptr_declarator;
		}
#line 3807 "C_grammar.tab.c"
    break;

  case 204: /* pointer: '*' type_qualifier_list pointer  */
#line 956 "C_grammar.y"
                {size_t const size = strlen("pointer(quals(), )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s), %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3818 "C_grammar.tab.c"
    break;

  case 205: /* pointer: '*' type_qualifier_list  */
#line 963 "C_grammar.y"
                {size_t const size = strlen("pointer(quals())") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(quals(%s))", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3828 "C_grammar.tab.c"
    break;

  case 206: /* pointer: '*' pointer  */
#line 969 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3838 "C_grammar.tab.c"
    break;

  case 207: /* pointer: '*'  */
#line 975 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3844 "C_grammar.tab.c"
    break;

  case 209: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 981 "C_grammar.y"
                {size_t const size = strlen("[, ]") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s, %s]", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3855 "C_grammar.tab.c"
    break;

  case 210: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 991 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3865 "C_grammar.tab.c"
    break;

  case 211: /* parameter_type_list: parameter_list  */
#line 997 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3875 "C_grammar.tab.c"
    break;

  case 213: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1007 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3886 "C_grammar.tab.c"
    break;

  case 214: /* parameter_declaration: declaration_specifiers declarator  */
#line 1017 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].declarator_type).full) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].declarator_type).full);
	     free((yyvsp[-1].id));
		 free((yyvsp[0].declarator_type).full);
		 free((yyvsp[0].declarator_type).ptr_declarator);
		}
#line 3898 "C_grammar.tab.c"
    break;

  case 215: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1025 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3909 "C_grammar.tab.c"
    break;

  case 216: /* parameter_declaration: declaration_specifiers  */
#line 1032 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3919 "C_grammar.tab.c"
    break;

  case 219: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 1045 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3925 "C_grammar.tab.c"
    break;

  case 220: /* type_name: specifier_qualifier_list  */
#line 1047 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3935 "C_grammar.tab.c"
    break;

  case 245: /* initializer: '{' initializer_list '}'  */
#line 1086 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3945 "C_grammar.tab.c"
    break;

  case 246: /* initializer: '{' initializer_list ',' '}'  */
#line 1092 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3955 "C_grammar.tab.c"
    break;

  case 248: /* initializer_list: designation initializer  */
#line 1102 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3966 "C_grammar.tab.c"
    break;

  case 250: /* initializer_list: initializer_list ',' designation initializer  */
#line 1110 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3978 "C_grammar.tab.c"
    break;

  case 251: /* initializer_list: initializer_list ',' initializer  */
#line 1118 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3989 "C_grammar.tab.c"
    break;

  case 252: /* designation: designator_list '='  */
#line 1128 "C_grammar.y"
                {size_t const size = strlen("designation([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "designation([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3999 "C_grammar.tab.c"
    break;

  case 254: /* designator_list: designator_list designator  */
#line 1138 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4010 "C_grammar.tab.c"
    break;

  case 255: /* designator: '[' constant_expression ']'  */
#line 1148 "C_grammar.y"
                {size_t const size = strlen("index()") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "index(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4020 "C_grammar.tab.c"
    break;

  case 256: /* designator: '.' IDENTIFIER  */
#line 1154 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4030 "C_grammar.tab.c"
    break;

  case 257: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1163 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4041 "C_grammar.tab.c"
    break;

  case 264: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1182 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4052 "C_grammar.tab.c"
    break;

  case 265: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1189 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 4063 "C_grammar.tab.c"
    break;

  case 266: /* labeled_statement: DEFAULT ':' statement  */
#line 1196 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 4073 "C_grammar.tab.c"
    break;

  case 267: /* compound_statement: '{' '}'  */
#line 1204 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 4079 "C_grammar.tab.c"
    break;

  case 268: /* compound_statement: '{' block_item_list '}'  */
#line 1206 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4089 "C_grammar.tab.c"
    break;

  case 270: /* block_item_list: block_item_list block_item  */
#line 1216 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
	  }
#line 4100 "C_grammar.tab.c"
    break;

  case 273: /* expression_statement: ';'  */
#line 1230 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 4106 "C_grammar.tab.c"
    break;

  case 274: /* expression_statement: expression ';'  */
#line 1232 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4116 "C_grammar.tab.c"
    break;

  case 275: /* selection_statement: IF '(' expression ')' statement else_opt  */
#line 1241 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4128 "C_grammar.tab.c"
    break;

  case 276: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1249 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4139 "C_grammar.tab.c"
    break;

  case 277: /* else_opt: %empty  */
#line 1258 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4145 "C_grammar.tab.c"
    break;

  case 278: /* else_opt: ELSE statement  */
#line 1260 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4155 "C_grammar.tab.c"
    break;

  case 279: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1268 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4166 "C_grammar.tab.c"
    break;

  case 280: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1275 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, branch(, ))") + strlen((yyvsp[-5].id)) + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, branch(%d, %s))", (yyvsp[-5].id), branch_nb++, (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4177 "C_grammar.tab.c"
    break;

  case 281: /* iteration_statement: FOR '(' for_stmt_type ')' statement  */
#line 1282 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4190 "C_grammar.tab.c"
    break;

  case 282: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1294 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4196 "C_grammar.tab.c"
    break;

  case 283: /* for_stmt_type: declaration expression_opt ';' expression_opt  */
#line 1296 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4202 "C_grammar.tab.c"
    break;

  case 284: /* expression_opt: %empty  */
#line 1300 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4208 "C_grammar.tab.c"
    break;

  case 286: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1305 "C_grammar.y"
          {size_t const size = strlen("\ngoto_stmt(, )\n") + strlen((yyvsp[-1].id)) + strlen(current_function) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s, %s)\n", (yyvsp[-1].id), current_function);
	   free((yyvsp[-1].id));
	  }
#line 4218 "C_grammar.tab.c"
    break;

  case 287: /* jump_statement: CONTINUE ';'  */
#line 1310 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4224 "C_grammar.tab.c"
    break;

  case 288: /* jump_statement: BREAK ';'  */
#line 1311 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4230 "C_grammar.tab.c"
    break;

  case 289: /* jump_statement: RETURN ';'  */
#line 1312 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4236 "C_grammar.tab.c"
    break;

  case 290: /* jump_statement: RETURN expression ';'  */
#line 1314 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4246 "C_grammar.tab.c"
    break;

  case 292: /* $@10: %empty  */
#line 1324 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4252 "C_grammar.tab.c"
    break;

  case 294: /* external_declaration: function_definition  */
#line 1328 "C_grammar.y"
                                {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4258 "C_grammar.tab.c"
    break;

  case 295: /* external_declaration: declaration  */
#line 1329 "C_grammar.y"
                                        {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4264 "C_grammar.tab.c"
    break;

  case 296: /* function_definition: declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 1334 "C_grammar.y"
                {size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-2].declarator_type).full) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-3].id), (yyvsp[-2].declarator_type).full, (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-2].declarator_type).full);
		 free((yyvsp[-2].declarator_type).ptr_declarator);
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4278 "C_grammar.tab.c"
    break;

  case 297: /* declaration_list_opt: %empty  */
#line 1346 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4284 "C_grammar.tab.c"
    break;

  case 300: /* declaration_list: declaration_list declaration  */
#line 1353 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4295 "C_grammar.tab.c"
    break;


#line 4299 "C_grammar.tab.c"

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

#line 1361 "C_grammar.y"

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

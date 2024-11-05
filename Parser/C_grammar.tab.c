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
int in_member_decl_flag = 0;	//indicates that we are parsing struct or union declarations and that the ids are part of the members namespace
int in_tag_namespace = 0;		//indicates to the lexer that we are in the tag namespace (for struct, union and enum tags) and that identifier should not be checked for typedef


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
        char *init;
        char *cond;
        char *update;
    } for_stmt_type;

#line 261 "C_grammar.tab.c"

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
  YYSYMBOL_151_3 = 151,                    /* $@3  */
  YYSYMBOL_specifier_qualifier_list = 152, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 153,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 154,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 155,           /* enum_specifier  */
  YYSYMBOL_156_4 = 156,                    /* $@4  */
  YYSYMBOL_157_5 = 157,                    /* $@5  */
  YYSYMBOL_enum_specifier_rest = 158,      /* enum_specifier_rest  */
  YYSYMBOL_enumerator_list = 159,          /* enumerator_list  */
  YYSYMBOL_enumerator = 160,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 161,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 162,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 163,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 164,      /* alignment_specifier  */
  YYSYMBOL_declarator = 165,               /* declarator  */
  YYSYMBOL_direct_declarator = 166,        /* direct_declarator  */
  YYSYMBOL_pointer = 167,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 168,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 169,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 170,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 171,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 172,          /* identifier_list  */
  YYSYMBOL_type_name = 173,                /* type_name  */
  YYSYMBOL_abstract_declarator = 174,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 175, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 176,              /* initializer  */
  YYSYMBOL_initializer_list = 177,         /* initializer_list  */
  YYSYMBOL_designation = 178,              /* designation  */
  YYSYMBOL_designator_list = 179,          /* designator_list  */
  YYSYMBOL_designator = 180,               /* designator  */
  YYSYMBOL_static_assert_declaration = 181, /* static_assert_declaration  */
  YYSYMBOL_statement = 182,                /* statement  */
  YYSYMBOL_labeled_statement = 183,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 184,       /* compound_statement  */
  YYSYMBOL_block_item_list = 185,          /* block_item_list  */
  YYSYMBOL_block_item = 186,               /* block_item  */
  YYSYMBOL_expression_statement = 187,     /* expression_statement  */
  YYSYMBOL_selection_statement = 188,      /* selection_statement  */
  YYSYMBOL_else_opt = 189,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 190,      /* iteration_statement  */
  YYSYMBOL_for_stmt_type = 191,            /* for_stmt_type  */
  YYSYMBOL_expression_opt = 192,           /* expression_opt  */
  YYSYMBOL_jump_statement = 193,           /* jump_statement  */
  YYSYMBOL_translation_unit = 194,         /* translation_unit  */
  YYSYMBOL_195_6 = 195,                    /* $@6  */
  YYSYMBOL_external_declaration = 196,     /* external_declaration  */
  YYSYMBOL_function_definition = 197,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 198,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 199          /* declaration_list  */
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
#define YYLAST   2450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  295
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  487

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
       0,   117,   117,   121,   122,   123,   129,   135,   139,   140,
     141,   145,   149,   150,   154,   158,   159,   163,   164,   168,
     169,   176,   182,   189,   196,   203,   209,   215,   222,   232,
     233,   243,   244,   251,   258,   264,   270,   279,   280,   284,
     285,   286,   287,   288,   289,   293,   294,   304,   305,   316,
     317,   318,   322,   323,   334,   335,   339,   340,   351,   352,
     356,   357,   368,   369,   370,   371,   376,   377,   388,   389,
     393,   394,   404,   405,   415,   416,   426,   427,   437,   438,
     448,   449,   460,   461,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   486,   487,   497,   501,   507,
     525,   534,   541,   542,   549,   550,   557,   558,   560,   562,
     564,   569,   570,   580,   587,   596,   601,   602,   603,   604,
     605,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   628,   629,   630,
     634,   634,   641,   641,   649,   660,   664,   671,   672,   682,
     688,   688,   696,   700,   707,   708,   715,   719,   720,   730,
     736,   743,   747,   753,   759,   759,   759,   770,   771,   773,
     782,   783,   793,   800,   804,   808,   809,   810,   811,   815,
     816,   820,   821,   825,   832,   836,   850,   852,   854,   856,
     858,   860,   862,   864,   866,   868,   870,   876,   884,   889,
     896,   902,   908,   913,   914,   924,   930,   939,   940,   950,
     957,   964,   973,   974,   978,   979,   988,   989,   990,   994,
     995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1018,  1024,  1030,  1034,  1041,  1042,  1050,  1060,  1069,  1070,
    1080,  1082,  1091,  1101,  1102,  1103,  1104,  1105,  1106,  1110,
    1117,  1124,  1133,  1134,  1143,  1144,  1154,  1155,  1159,  1160,
    1169,  1177,  1187,  1188,  1196,  1203,  1210,  1222,  1224,  1229,
    1230,  1233,  1239,  1240,  1241,  1242,  1252,  1253,  1253,  1257,
    1258,  1262,  1274,  1275,  1279,  1280
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
  "$@3", "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "$@4", "$@5",
  "enum_specifier_rest", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "else_opt",
  "iteration_statement", "for_stmt_type", "expression_opt",
  "jump_statement", "translation_unit", "$@6", "external_declaration",
  "function_definition", "declaration_list_opt", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-404)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-293)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2110,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,   -52,   -40,  2371,  -404,  -404,
     -19,  -404,  -404,  -404,  -404,  -404,    44,  2215,  2215,  -404,
      28,  -404,  -404,  2215,  2215,  2215,  -404,    54,  -404,  -404,
      41,    55,   997,  2371,    94,  2371,   -12,  1688,  -404,    52,
     192,  -404,   -45,  -404,   827,    76,    31,  -404,  -404,   -13,
    -404,  -404,  -404,  -404,  -404,  2110,  -404,    29,    11,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  1703,  -404,  -404,
      65,    68,   904,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,   153,  -404,  1718,  1688,  -404,   115,   -15,
      71,     6,   171,    79,    81,    70,   180,    21,  -404,   137,
     162,  -404,  1842,  1090,    77,  -404,    93,  -404,  -404,   114,
     164,  -404,  -404,   192,    52,  -404,  1564,  -404,    44,   129,
    2110,  2006,  1105,    76,   147,  2267,  -404,  1688,    40,  -404,
     169,   904,  -404,  2371,  1688,   548,   376,  -404,  -404,   133,
     170,   181,   262,  -404,  -404,  1580,  1688,   264,   904,  -404,
    -404,  -404,  -404,  -404,  1688,  -404,  -404,  1688,  -404,  -404,
    1688,  -404,  -404,  -404,  -404,  1688,  -404,  -404,  1688,  1688,
    1688,  1688,  1688,  1688,  1688,  -404,  -404,  -404,   107,   196,
     197,  -404,   199,  1414,  -404,   193,   200,  1198,    93,  2058,
    1213,   274,  -404,  -404,  -404,  -404,   182,  1548,  -404,  -404,
    -404,  -404,  -404,  -404,   206,   144,  1414,  -404,   203,   204,
    1306,  2267,  1896,  -404,   187,  -404,  -404,  -404,  -404,    41,
    -404,   211,   212,   214,   215,  1688,   217,   221,   222,   224,
     435,   227,   292,   207,   213,   749,  -404,  -404,   -44,  -404,
    -404,  -404,  -404,   641,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    1688,  -404,  1688,  1595,  -404,  -404,  -404,   154,  -404,   -30,
    -404,   216,  -404,   115,   -15,    71,     6,   171,    79,    81,
      70,   180,   159,  1782,  -404,    92,  -404,  -404,  2162,  -404,
     229,  1414,  -404,  -404,  1688,  -404,   232,  -404,   228,  1414,
    -404,   233,   235,  1321,   240,  1688,   326,  -404,    51,  1564,
     -37,  -404,  -404,  -404,   327,   245,  1414,  -404,  -404,  1688,
    -404,   246,   247,  1948,  -404,  -404,  -404,    17,   113,   251,
    -404,  2319,   435,   256,   435,  1688,  1688,  1688,   273,   734,
     237,  -404,  -404,  -404,   -43,  -404,  -404,  -404,  -404,  -404,
    1548,  -404,  -404,  1688,  -404,   251,  1688,  -404,  -404,  -404,
     257,   258,  -404,  -404,   259,  1414,  -404,  -404,  1688,  -404,
     260,   238,   261,  -404,  1429,  -404,  -404,  -404,  -404,  -404,
    -404,   263,   265,  -404,  -404,  -404,  1688,   -32,  -404,   266,
      49,  -404,   270,   167,  -404,   271,  -404,   435,  -404,   173,
     177,   191,   276,  1688,  1688,   277,  -404,  -404,   135,  -404,
    -404,  -404,  -404,  -404,   275,   278,  -404,  -404,  -404,  -404,
    -404,  1564,  -404,  -404,  -404,    17,  -404,  1688,  -404,  1688,
    -404,  2319,  1688,  -404,   435,   435,   435,  1688,   279,   267,
     268,   435,  1455,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,   300,  -404,  -404,   194,  1688,  1688,  -404,  -404,
     435,  -404,   269,  -404,  -404,  -404,  -404
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   136,   115,   116,   117,   119,   120,   179,   175,   176,
     177,   130,   122,   123,   124,   125,   128,   129,   126,   127,
     121,   131,   132,   145,   146,   164,     0,     0,   178,   180,
       0,   118,   137,   138,   139,   290,     0,   102,   104,   134,
       0,   135,   133,   106,   108,   110,   100,   287,   286,   289,
       0,     0,     0,   154,   215,   156,     0,     0,   185,     0,
     202,    98,     0,   111,   114,   184,     0,   101,   103,   144,
     140,   105,   107,   109,     1,     0,    11,   173,     0,   170,
     165,     2,     8,     9,    10,    12,    13,     0,    37,    38,
       0,     0,     0,    39,    40,    41,    42,    43,    44,    19,
       3,     4,     7,    31,    45,     0,     0,    47,    52,    56,
      60,    66,    70,    72,    74,    76,    78,    80,    97,     0,
       0,   153,     0,     0,   217,   214,   218,   155,   174,     0,
       0,   203,   201,   200,     0,    99,     0,   294,     0,     0,
     293,     0,     0,   183,     0,     0,   288,     0,     0,   162,
     167,     0,    34,     0,     0,     0,    45,    82,    95,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    32,
      33,    49,    50,    51,     0,    54,    55,     0,    58,    59,
       0,    64,    65,    62,    63,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,   182,   181,   236,   211,     0,
     206,   207,     0,     0,   220,    40,     0,     0,   216,     0,
       0,     0,   186,   204,   199,   112,   114,     0,   242,   113,
     291,   295,   212,   196,     0,     0,     0,   187,    40,     0,
       0,     0,     0,   147,   150,   152,   172,   163,   171,     0,
     166,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   268,     0,   266,
     267,   253,   254,     0,   264,   255,   256,   257,   258,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    84,
       0,     6,     0,     0,     5,    24,    21,     0,    29,     0,
      23,     0,    48,    53,    57,    61,    67,    71,    73,    75,
      77,    79,     0,     0,   209,   217,   210,   237,     0,   219,
       0,     0,   221,   227,     0,   226,     0,   238,     0,     0,
     228,    40,     0,     0,     0,     0,     0,   244,     0,     0,
       0,   248,   197,   198,     0,     0,     0,   188,   195,     0,
     194,    40,     0,     0,   141,   148,   149,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,   283,   284,     0,   269,   263,   265,    83,    96,
       0,    46,    22,     0,    20,     0,     0,   205,   208,   223,
       0,     0,   225,   239,     0,     0,   229,   235,     0,   234,
       0,     0,     0,   251,     0,   240,   243,   247,   249,   213,
     190,     0,     0,   191,   193,   143,     0,     0,   157,   161,
       0,   168,     0,     0,    15,     0,   259,     0,   261,     0,
       0,     0,     0,   279,   279,     0,   281,   285,     0,    30,
      81,   222,   224,   231,     0,     0,   232,   252,   250,   241,
     246,     0,   189,   192,   159,     0,   151,     0,   169,     0,
      14,     0,     0,   260,     0,     0,     0,     0,   280,     0,
       0,     0,     0,    27,   230,   233,   245,   158,   160,    18,
      16,    17,   272,   271,   274,     0,   279,   279,   276,    28,
       0,   270,     0,   278,   277,   273,   275
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -404,  -404,  -404,  -404,  -404,  -404,  -404,   -88,  -404,  -404,
     -38,  -404,  -404,   -90,   188,  -404,   186,  -404,   184,  -404,
     179,  -404,   185,  -404,   190,   195,   183,   189,  -404,   -50,
      97,  -404,   -87,   -54,   -53,    45,  -404,   242,  -404,   -23,
    -404,  -404,  -404,  -404,   150,  -226,  -404,   -18,  -404,   -67,
    -404,  -404,  -404,  -404,   145,  -138,  -404,   -27,  -404,  -404,
     -35,   -57,   -42,   -66,  -117,  -404,    75,  -404,    19,   -39,
    -111,  -128,    15,  -331,  -404,    57,  -118,  -233,  -404,    90,
    -404,   125,    32,  -404,  -404,  -404,  -404,  -403,  -404,  -404,
    -404,   317,  -404,  -404,  -404
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    99,   100,    77,   101,   102,   413,   414,   103,   287,
     156,   105,   106,   107,   108,   174,   109,   177,   110,   180,
     111,   185,   112,   188,   113,   114,   115,   116,   117,   157,
     158,   280,   258,   119,    35,   138,    62,    63,    37,    38,
      39,   145,   144,    40,   232,   233,   347,    54,   407,   408,
      41,    51,   150,   240,    78,    79,    42,    43,    44,    45,
     130,    65,    66,   133,   199,   200,   201,   225,   415,   202,
     126,   327,   328,   329,   330,   331,    46,   260,   261,   262,
     263,   264,   265,   266,   481,   267,   425,   459,   268,    47,
      75,    48,    49,   139,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    64,   118,   129,    53,   159,   345,   118,   219,   143,
     238,   137,   124,   208,   104,   125,   170,   358,   132,   104,
      58,   460,   181,   182,   224,    55,    55,   235,    55,    53,
      53,    69,    53,   131,    58,   121,    50,   127,   134,   282,
     282,    52,   193,    76,    76,    36,    56,    58,   325,   152,
     326,   445,    76,   282,    74,    58,   374,   207,    80,   135,
     365,   427,    57,   441,   159,    55,   397,   169,   104,    53,
     128,   120,   446,   483,   484,  -142,   230,   175,   176,   289,
     124,   159,    67,    68,   292,   178,   179,   221,    71,    72,
      73,   214,   318,   236,   148,    58,   131,   118,    59,   216,
     149,   406,   259,   216,   183,   184,   213,   302,    60,   104,
      58,   160,    59,   235,   235,   131,    70,   345,    55,   416,
      36,   418,    53,   194,    55,    59,    55,   234,    53,   237,
      53,   441,   147,    59,   394,    60,   104,   311,   448,   104,
     395,    55,   104,    60,   323,    53,   153,   104,    61,   154,
     104,   104,   104,   104,   104,   104,   305,   141,   122,   306,
     336,   142,   123,   304,   162,   163,   164,   198,   364,   189,
     241,   191,   242,   303,   209,   122,   131,   123,   210,   123,
     213,   190,   161,   131,   453,    60,   198,   291,   303,   186,
     187,   353,   123,   371,   208,   118,   410,   211,    60,   131,
     192,   396,   411,   213,    55,    55,   171,   104,    53,    53,
     259,   172,   173,   234,   234,   281,   282,   155,   462,   195,
     206,   472,   473,   474,   463,   235,   333,   334,   478,   220,
       8,     9,    10,   218,   165,   231,   372,   373,   166,   229,
     167,   161,   282,   376,   196,   104,   212,   485,   143,   450,
     451,   243,   283,   385,   198,   454,   282,   239,   161,   455,
     282,   305,   288,   284,    28,   285,   440,   290,   419,   420,
     421,   392,   238,   456,   282,   118,   482,   282,   307,   312,
     308,   309,   324,    60,   213,   136,   313,   104,   332,   337,
     338,   346,   131,   349,   350,   360,   213,   351,   375,   352,
     310,   354,   355,   356,   316,   357,   423,   322,   359,   213,
     383,   361,   409,   466,   218,   379,    55,   362,   382,   386,
      53,   387,   391,   335,    55,   234,   430,   342,    53,   393,
     399,   400,   403,   404,   440,   422,   458,   458,   104,   370,
     417,   426,   437,   431,   432,   433,   436,   438,   198,   442,
     447,   443,   444,   198,   449,   452,   118,   457,   213,   461,
     480,   464,   282,   470,   465,   293,   294,   296,   104,   295,
     475,   476,   477,   486,   297,   300,   215,   368,   467,   369,
     298,   343,   301,   378,   348,   428,   299,   398,   367,   458,
     458,   424,   146,   468,     0,     0,     0,   118,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   380,   104,
     409,   381,     0,     0,     0,     0,   384,     0,     0,     0,
     390,     0,     0,     0,    55,     0,   218,     0,    53,     0,
       0,     0,     0,   401,     0,     0,   402,     0,   244,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,     0,     0,
     429,     0,     0,     0,     0,     0,     0,     0,     0,   279,
       0,     0,   434,     0,     0,   435,     0,     0,     0,     0,
       0,   218,   245,   246,   247,     0,   248,   249,   250,   251,
     252,   253,   254,   255,     0,    90,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,   155,     0,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,     0,   218,   257,
       0,     0,     0,     0,     0,     0,   469,     0,     0,   471,
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
     366,    93,    94,    95,    96,    97,    98,    81,     1,    82,
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
       0,     0,     0,   363,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    81,     1,    82,
      83,    84,    85,    86,    87,  -292,    88,    89,     0,     0,
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
     339,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,   388,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,    28,    91,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
       0,    90,   340,    28,    91,     0,    93,   341,    95,    96,
      97,    98,    92,     0,     0,     0,     0,   389,     0,     0,
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
      92,     0,     0,     0,   325,     0,   326,   217,   439,    93,
      94,    95,    96,    97,    98,    90,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,     0,
     325,     0,   326,   217,   479,    93,    94,    95,    96,    97,
      98,    81,     0,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,    81,     0,    82,
      83,    84,    85,    86,    87,     0,    88,    89,     0,     0,
       0,     0,     0,    81,     0,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,    81,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,   325,    90,   326,   217,    91,    93,    94,
      95,    96,    97,    98,     0,    92,     0,     0,     0,     0,
      90,     0,   217,    91,    93,    94,    95,    96,    97,    98,
       0,    92,   286,     0,     0,    90,     0,     0,    91,     0,
      93,    94,    95,    96,    97,    98,    92,     0,     0,     0,
       0,     0,     0,   370,     0,    93,    94,    95,    96,    97,
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
       0,     0,     0,     0,     0,   344,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,   222,
       1,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,     0,    30,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   405,     2,     3,
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
      18,    19,    20,    21,    22,    23,    24,    25,   377,     1,
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
      21,    22,    23,    24,    25,     1,     0,   412,     0,     0,
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
      27,    36,    52,    57,    27,    92,   232,    57,   136,    66,
     148,    64,    54,   124,    52,    54,   106,   250,    60,    57,
       3,   424,    16,    17,   141,    52,    53,   145,    55,    52,
      53,     3,    55,    60,     3,    53,    88,    55,    83,    83,
      83,    81,    21,     3,     3,     0,    27,     3,    85,    87,
      87,    83,     3,    83,     0,     3,    86,   123,     3,   104,
     104,   104,    81,   394,   151,    92,   103,   105,   106,    92,
      82,    52,   104,   476,   477,    88,   142,    92,    93,   166,
     122,   168,    37,    38,   174,    14,    15,   140,    43,    44,
      45,   133,   209,   147,    83,     3,   123,   147,    81,   134,
      89,    84,   155,   138,    98,    99,   133,   194,    91,   147,
       3,    92,    81,   231,   232,   142,    88,   343,   145,   352,
      75,   354,   145,   102,   151,    81,   153,   145,   151,    89,
     153,   462,   103,    81,    83,    91,   174,   203,    89,   177,
      89,   168,   180,    91,   210,   168,    81,   185,   104,    81,
     188,   189,   190,   191,   192,   193,   198,    81,    81,   198,
     226,    85,    85,   198,    11,    12,    13,   122,   255,    90,
     151,   101,   153,    81,    81,    81,   203,    85,    85,    85,
     207,   100,    92,   210,   417,    91,   141,   168,    81,    18,
      19,   245,    85,   283,   305,   245,    83,    83,    91,   226,
      20,   329,    89,   230,   231,   232,    91,   245,   231,   232,
     263,    96,    97,   231,   232,    82,    83,    88,    83,    82,
     123,   454,   455,   456,    89,   343,    82,    83,   461,   139,
      38,    39,    40,   136,    81,    88,    82,    83,    85,   142,
      87,   151,    83,    84,    82,   283,    82,   480,   305,    82,
      83,   154,    82,   319,   209,    82,    83,    88,   168,    82,
      83,   303,   165,    82,    72,     3,   394,     3,   355,   356,
     357,   325,   410,    82,    83,   325,    82,    83,    82,    86,
      83,    82,     8,    91,   311,   103,    86,   325,    82,    86,
      86,   104,   319,    82,    82,     3,   323,    83,    82,    84,
     203,    84,    81,    81,   207,    81,   359,   210,    81,   336,
      82,   104,   347,   441,   217,    86,   343,   104,    86,    86,
     343,    86,    82,   226,   351,   343,   376,   230,   351,     3,
       3,    86,    86,    86,   462,    62,   423,   424,   376,    88,
      84,   104,   104,    86,    86,    86,    86,    86,   303,    86,
      84,    86,   406,   308,    84,    84,   406,    81,   385,    82,
      60,    86,    83,   451,    86,   177,   180,   188,   406,   185,
     457,   104,   104,   104,   189,   192,   134,   280,   445,   282,
     190,   231,   193,   308,   239,   370,   191,   330,   263,   476,
     477,   359,    75,   447,    -1,    -1,    -1,   447,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   311,   447,
     445,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,
     323,    -1,    -1,    -1,   451,    -1,   329,    -1,   451,    -1,
      -1,    -1,    -1,   336,    -1,    -1,   339,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,
     373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,   385,    -1,    -1,   388,    -1,    -1,    -1,    -1,
      -1,   394,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,   452,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,   462,
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
     148,   155,   161,   162,   163,   164,   181,   194,   196,   197,
      88,   156,    81,   144,   152,   162,   173,    81,     3,    81,
      91,   104,   141,   142,   165,   166,   167,   140,   140,     3,
      88,   140,   140,   140,     0,   195,     3,   108,   159,   160,
       3,     3,     5,     6,     7,     8,     9,    10,    12,    13,
      70,    73,    81,    90,    91,    92,    93,    94,    95,   106,
     107,   109,   110,   113,   115,   116,   117,   118,   119,   121,
     123,   125,   127,   129,   130,   131,   132,   133,   134,   138,
     173,   152,    81,    85,   167,   174,   175,   152,    82,   138,
     165,   162,   167,   168,    83,   104,   103,   139,   140,   198,
     199,    81,    85,   166,   147,   146,   196,   103,    83,    89,
     157,    81,   115,    81,    81,    88,   115,   134,   135,   137,
     173,   184,    11,    12,    13,    81,    85,    87,    81,   115,
     118,    91,    96,    97,   120,    92,    93,   122,    14,    15,
     124,    16,    17,    98,    99,   126,    18,    19,   128,    90,
     100,   101,    20,    21,   102,    82,    82,    82,   140,   169,
     170,   171,   174,    34,    86,    91,   135,   168,   175,    81,
      85,    83,    82,   162,   167,   142,   165,    88,   135,   176,
     184,   139,     3,    82,   169,   172,    34,    86,    91,   135,
     168,    88,   149,   150,   152,   181,   138,    89,   160,    88,
     158,   173,   173,   135,     3,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    89,   104,   137,   139,
     182,   183,   184,   185,   186,   187,   188,   190,   193,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   103,
     136,    82,    83,    82,    82,     3,    82,   114,   135,   137,
       3,   173,   118,   119,   121,   123,   125,   127,   129,   130,
     131,   132,   137,    81,   165,   167,   174,    82,    83,    82,
     135,   168,    86,    86,    34,    86,   135,    82,   169,    34,
      86,    91,   135,   168,     8,    85,    87,   176,   177,   178,
     179,   180,    82,    82,    83,   135,   168,    86,    86,    34,
      86,    91,   135,   149,    89,   150,   104,   151,   159,    82,
      82,    83,    84,   138,    84,    81,    81,    81,   182,    81,
       3,   104,   104,   104,   137,   104,    89,   186,   135,   135,
      88,   118,    82,    83,    86,    82,    84,    56,   171,    86,
     135,   135,    86,    82,   135,   168,    86,    86,    34,    86,
     135,    82,   138,     3,    83,    89,   176,   103,   180,     3,
      86,   135,   135,    86,    86,    89,    84,   153,   154,   165,
      83,    89,    58,   111,   112,   173,   182,    84,   182,   137,
     137,   137,    62,   139,   187,   191,   104,   104,   177,   135,
     134,    86,    86,    86,   135,   135,    86,   104,    86,    89,
     176,   178,    86,    86,   138,    83,   104,    84,    89,    84,
      82,    83,    84,   182,    82,    82,    82,    81,   137,   192,
     192,    82,    83,    89,    86,    86,   176,   154,   138,   135,
     112,   135,   182,   182,   182,   137,   104,   104,   182,    89,
      60,   189,    82,   192,   192,   182,   104
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
     151,   150,   150,   152,   152,   152,   152,   153,   153,   154,
     154,   154,   155,   155,   156,   157,   155,   158,   158,   158,
     159,   159,   160,   160,   161,   162,   162,   162,   162,   163,
     163,   164,   164,   165,   165,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   167,
     167,   167,   167,   168,   168,   169,   169,   170,   170,   171,
     171,   171,   172,   172,   173,   173,   174,   174,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   177,   177,   177,   177,   178,   179,   179,
     180,   180,   181,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   190,   190,   191,   191,   192,
     192,   193,   193,   193,   193,   193,   194,   195,   194,   196,
     196,   197,   198,   198,   199,   199
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
       0,     4,     1,     2,     1,     2,     1,     1,     3,     2,
       3,     1,     4,     5,     0,     0,     5,     0,     3,     4,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     4,     2,     1,     1,     3,     3,     4,     6,
       5,     5,     6,     5,     4,     4,     3,     4,     4,     3,
       2,     2,     1,     1,     2,     3,     1,     1,     3,     2,
       2,     1,     1,     3,     2,     1,     2,     1,     1,     3,
       2,     3,     5,     4,     5,     4,     3,     3,     3,     4,
       6,     5,     5,     6,     4,     4,     2,     3,     3,     4,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     7,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     1,     2,     1,     1,     1,     2,
       6,     5,     0,     2,     5,     7,     5,     4,     4,     0,
       1,     3,     2,     2,     2,     3,     1,     0,     3,     1,
       1,     4,     0,     1,     1,     2
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
#line 118 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2489 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' compound_statement ')'  */
#line 124 "C_grammar.y"
                {size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2499 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' expression ')'  */
#line 130 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2509 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: generic_selection  */
#line 135 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2515 "C_grammar.tab.c"
    break;

  case 13: /* string: FUNC_NAME  */
#line 150 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2521 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 170 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2532 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' ')'  */
#line 177 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2542 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 183 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2553 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 190 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2564 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 197 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2575 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression INC_OP  */
#line 204 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2585 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression DEC_OP  */
#line 210 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2595 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 216 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2606 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 223 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2617 "C_grammar.tab.c"
    break;

  case 30: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 234 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2628 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_inc_dec unary_expression  */
#line 245 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2639 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 252 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2650 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 259 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2660 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 265 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2670 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 271 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2680 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: INC_OP  */
#line 279 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2686 "C_grammar.tab.c"
    break;

  case 38: /* unary_inc_dec: DEC_OP  */
#line 280 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2692 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '&'  */
#line 284 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2698 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '*'  */
#line 285 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2704 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '+'  */
#line 286 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2710 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '-'  */
#line 287 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2716 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '~'  */
#line 288 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2722 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '!'  */
#line 289 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2728 "C_grammar.tab.c"
    break;

  case 46: /* cast_expression: '(' type_name ')' cast_expression  */
#line 295 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2739 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 306 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2751 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '*'  */
#line 316 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2757 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '/'  */
#line 317 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2763 "C_grammar.tab.c"
    break;

  case 51: /* multiplicative_expression_op: '%'  */
#line 318 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2769 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 324 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2781 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '+'  */
#line 334 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2787 "C_grammar.tab.c"
    break;

  case 55: /* additive_expression_op: '-'  */
#line 335 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2793 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 341 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2805 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: LEFT_OP  */
#line 351 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2811 "C_grammar.tab.c"
    break;

  case 59: /* shift_expression_op: RIGHT_OP  */
#line 352 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2817 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 358 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2829 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '<'  */
#line 368 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2835 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: '>'  */
#line 369 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2841 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: LE_OP  */
#line 370 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2847 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression_operator: GE_OP  */
#line 371 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2853 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 378 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2865 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: EQ_OP  */
#line 388 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2871 "C_grammar.tab.c"
    break;

  case 69: /* equality_expression_op: NE_OP  */
#line 389 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2877 "C_grammar.tab.c"
    break;

  case 71: /* and_expression: and_expression '&' equality_expression  */
#line 395 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2888 "C_grammar.tab.c"
    break;

  case 73: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 406 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2899 "C_grammar.tab.c"
    break;

  case 75: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 417 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2910 "C_grammar.tab.c"
    break;

  case 77: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 428 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2921 "C_grammar.tab.c"
    break;

  case 79: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 439 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2932 "C_grammar.tab.c"
    break;

  case 81: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 450 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2944 "C_grammar.tab.c"
    break;

  case 83: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 462 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2956 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: '='  */
#line 472 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2962 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: MUL_ASSIGN  */
#line 473 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2968 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: DIV_ASSIGN  */
#line 474 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2974 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: MOD_ASSIGN  */
#line 475 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2980 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: ADD_ASSIGN  */
#line 476 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2986 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: SUB_ASSIGN  */
#line 477 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2992 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: LEFT_ASSIGN  */
#line 478 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2998 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: RIGHT_ASSIGN  */
#line 479 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 3004 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: AND_ASSIGN  */
#line 480 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 3010 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: XOR_ASSIGN  */
#line 481 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3016 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: OR_ASSIGN  */
#line 482 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3022 "C_grammar.tab.c"
    break;

  case 96: /* expression: expression ',' assignment_expression  */
#line 488 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3033 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers ';'  */
#line 502 "C_grammar.y"
                {size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3043 "C_grammar.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 508 "C_grammar.y"
                {/*if (strstr($1, "typedef") != NULL) {
			typedef_flag = 0; 
			if (debugMode) printf("Debug: typedef switched to 0 on declaration([%s], [%s])\n", $1, $2);
		 }
		 */
		 
		 if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0; 
			if (debugMode) printf("Debug: typedef switched to 0\n");
	   	 }
		 
		 size_t const size = strlen("\ndeclaration([], [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 3065 "C_grammar.tab.c"
    break;

  case 100: /* declaration: static_assert_declaration  */
#line 526 "C_grammar.y"
                {size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3075 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 535 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3086 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 543 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3097 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 551 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3108 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 559 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); }
#line 3114 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: function_specifier  */
#line 561 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); }
#line 3120 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 563 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); }
#line 3126 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: alignment_specifier  */
#line 565 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); }
#line 3132 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 571 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3143 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator '=' initializer  */
#line 581 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	   	 //free($3);
	  	}
#line 3154 "C_grammar.tab.c"
    break;

  case 114: /* init_declarator: declarator  */
#line 588 "C_grammar.y"
                {if (typedef_flag == 1) {	// we are parsing a typedef declaration
			add_typedef_name((yyvsp[0].id));
	   	 }
		 simple_str_copy(&(yyval.id), (yyvsp[0].id));
	  	}
#line 3164 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: TYPEDEF  */
#line 597 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
		 if (debugMode) printf("Debug: typedef switched to 1\n");
	    }
#line 3173 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: EXTERN  */
#line 601 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3179 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: STATIC  */
#line 602 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3185 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: THREAD_LOCAL  */
#line 603 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3191 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: AUTO  */
#line 604 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3197 "C_grammar.tab.c"
    break;

  case 120: /* storage_class_specifier: REGISTER  */
#line 605 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3203 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: VOID  */
#line 609 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 3209 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: CHAR  */
#line 610 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 3215 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: SHORT  */
#line 611 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 3221 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: INT  */
#line 612 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 3227 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: LONG  */
#line 613 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 3233 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: FLOAT  */
#line 614 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 3239 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: DOUBLE  */
#line 615 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 3245 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: SIGNED  */
#line 616 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3251 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: UNSIGNED  */
#line 617 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3257 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: BOOL  */
#line 618 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3263 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: COMPLEX  */
#line 619 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3269 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: IMAGINARY  */
#line 620 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3275 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: atomic_type_specifier  */
#line 621 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3281 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: TYPEDEF_NAME  */
#line 625 "C_grammar.y"
                {(yyval.id) = to_prolog_var((yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3289 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: INT128  */
#line 628 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int128"); }
#line 3295 "C_grammar.tab.c"
    break;

  case 138: /* type_specifier: FLOAT128  */
#line 629 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float128"); }
#line 3301 "C_grammar.tab.c"
    break;

  case 139: /* type_specifier: VA_LIST  */
#line 630 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "va_list"); }
#line 3307 "C_grammar.tab.c"
    break;

  case 140: /* $@1: %empty  */
#line 634 "C_grammar.y"
                              {in_tag_namespace = 0;}
#line 3313 "C_grammar.tab.c"
    break;

  case 141: /* struct_or_union_specifier: struct_or_union '{' $@1 struct_declaration_list '}'  */
#line 635 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s([%s])", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-1].id));
	    }
#line 3324 "C_grammar.tab.c"
    break;

  case 142: /* $@2: %empty  */
#line 641 "C_grammar.y"
                                     {in_tag_namespace = 0;}
#line 3330 "C_grammar.tab.c"
    break;

  case 143: /* struct_or_union_specifier: struct_or_union IDENTIFIER $@2 '{' struct_declaration_list '}'  */
#line 642 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-5].id), (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-5].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
	    }
#line 3342 "C_grammar.tab.c"
    break;

  case 144: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 650 "C_grammar.y"
                {in_tag_namespace = 0;
		 size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3354 "C_grammar.tab.c"
    break;

  case 145: /* struct_or_union: STRUCT  */
#line 661 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "struct");
		 in_tag_namespace = 1;
		}
#line 3362 "C_grammar.tab.c"
    break;

  case 146: /* struct_or_union: UNION  */
#line 665 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "union");
		 in_tag_namespace = 1;
		}
#line 3370 "C_grammar.tab.c"
    break;

  case 148: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 673 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3381 "C_grammar.tab.c"
    break;

  case 149: /* struct_declaration: specifier_qualifier_list ';'  */
#line 683 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3391 "C_grammar.tab.c"
    break;

  case 150: /* $@3: %empty  */
#line 688 "C_grammar.y"
                                   {in_member_decl_flag = 1;}
#line 3397 "C_grammar.tab.c"
    break;

  case 151: /* struct_declaration: specifier_qualifier_list $@3 struct_declarator_list ';'  */
#line 689 "C_grammar.y"
                {in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3409 "C_grammar.tab.c"
    break;

  case 153: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 701 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3420 "C_grammar.tab.c"
    break;

  case 155: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 709 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3431 "C_grammar.tab.c"
    break;

  case 158: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 721 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3442 "C_grammar.tab.c"
    break;

  case 159: /* struct_declarator: ':' constant_expression  */
#line 731 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3452 "C_grammar.tab.c"
    break;

  case 160: /* struct_declarator: declarator ':' constant_expression  */
#line 737 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3463 "C_grammar.tab.c"
    break;

  case 162: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 748 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3473 "C_grammar.tab.c"
    break;

  case 163: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 754 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3483 "C_grammar.tab.c"
    break;

  case 164: /* $@4: %empty  */
#line 759 "C_grammar.y"
               {in_tag_namespace = 1;}
#line 3489 "C_grammar.tab.c"
    break;

  case 165: /* $@5: %empty  */
#line 759 "C_grammar.y"
                                                  {in_tag_namespace = 0;}
#line 3495 "C_grammar.tab.c"
    break;

  case 166: /* enum_specifier: ENUM $@4 IDENTIFIER $@5 enum_specifier_rest  */
#line 760 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
        }
#line 3506 "C_grammar.tab.c"
    break;

  case 167: /* enum_specifier_rest: %empty  */
#line 770 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "forward_enum");}
#line 3512 "C_grammar.tab.c"
    break;

  case 168: /* enum_specifier_rest: '{' enumerator_list '}'  */
#line 772 "C_grammar.y"
                {(yyval.id) = (yyvsp[-1].id);}
#line 3518 "C_grammar.tab.c"
    break;

  case 169: /* enum_specifier_rest: '{' enumerator_list ',' '}'  */
#line 774 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3528 "C_grammar.tab.c"
    break;

  case 171: /* enumerator_list: enumerator_list ',' enumerator  */
#line 784 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3539 "C_grammar.tab.c"
    break;

  case 172: /* enumerator: enumeration_constant '=' constant_expression  */
#line 794 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3550 "C_grammar.tab.c"
    break;

  case 175: /* type_qualifier: CONST  */
#line 808 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3556 "C_grammar.tab.c"
    break;

  case 176: /* type_qualifier: RESTRICT  */
#line 809 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3562 "C_grammar.tab.c"
    break;

  case 177: /* type_qualifier: VOLATILE  */
#line 810 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3568 "C_grammar.tab.c"
    break;

  case 178: /* type_qualifier: ATOMIC  */
#line 811 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3574 "C_grammar.tab.c"
    break;

  case 179: /* function_specifier: INLINE  */
#line 815 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3580 "C_grammar.tab.c"
    break;

  case 180: /* function_specifier: NORETURN  */
#line 816 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3586 "C_grammar.tab.c"
    break;

  case 183: /* declarator: pointer direct_declarator  */
#line 826 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 3597 "C_grammar.tab.c"
    break;

  case 185: /* direct_declarator: IDENTIFIER  */
#line 837 "C_grammar.y"
                {char Prolog_var_name[MAX_ID_LENGTH+5];
		 if (islower((yyvsp[0].id)[0])) {
			Prolog_var_name[0] = toupper((yyvsp[0].id)[0]);
			strcpy_safe(&Prolog_var_name[1], MAX_ID_LENGTH-1, &(yyvsp[0].id)[1]);
		 } else {
			strcpy_safe(Prolog_var_name, MAX_ID_LENGTH, "UC_");
			strcat_safe(Prolog_var_name, MAX_ID_LENGTH, (yyvsp[0].id));
		 }
		 size_t const size = strlen(Prolog_var_name) + 1;
		 (yyval.id) = (char*)malloc(size);
		 strcpy_safe((yyval.id), size, Prolog_var_name);
		 free((yyvsp[0].id));
		}
#line 3615 "C_grammar.tab.c"
    break;

  case 186: /* direct_declarator: '(' declarator ')'  */
#line 851 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 3621 "C_grammar.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '[' ']'  */
#line 853 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D2");}
#line 3627 "C_grammar.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 855 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D3");}
#line 3633 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 857 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D4");}
#line 3639 "C_grammar.tab.c"
    break;

  case 190: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 859 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D5");}
#line 3645 "C_grammar.tab.c"
    break;

  case 191: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 861 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D6");}
#line 3651 "C_grammar.tab.c"
    break;

  case 192: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 863 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D7");}
#line 3657 "C_grammar.tab.c"
    break;

  case 193: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 865 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D8");}
#line 3663 "C_grammar.tab.c"
    break;

  case 194: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 867 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D9");}
#line 3669 "C_grammar.tab.c"
    break;

  case 195: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 869 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D10");}
#line 3675 "C_grammar.tab.c"
    break;

  case 196: /* direct_declarator: direct_declarator '(' ')'  */
#line 871 "C_grammar.y"
                {size_t const size = strlen("function(, [])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, [])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3685 "C_grammar.tab.c"
    break;

  case 197: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 877 "C_grammar.y"
                {size_t const size = strlen("function(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 3696 "C_grammar.tab.c"
    break;

  case 198: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 885 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D13");}
#line 3702 "C_grammar.tab.c"
    break;

  case 199: /* pointer: '*' type_qualifier_list pointer  */
#line 890 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3713 "C_grammar.tab.c"
    break;

  case 200: /* pointer: '*' type_qualifier_list  */
#line 897 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3723 "C_grammar.tab.c"
    break;

  case 201: /* pointer: '*' pointer  */
#line 903 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3733 "C_grammar.tab.c"
    break;

  case 202: /* pointer: '*'  */
#line 909 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3739 "C_grammar.tab.c"
    break;

  case 204: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 915 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3750 "C_grammar.tab.c"
    break;

  case 205: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 925 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3760 "C_grammar.tab.c"
    break;

  case 206: /* parameter_type_list: parameter_list  */
#line 931 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3770 "C_grammar.tab.c"
    break;

  case 208: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 941 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3781 "C_grammar.tab.c"
    break;

  case 209: /* parameter_declaration: declaration_specifiers declarator  */
#line 951 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3792 "C_grammar.tab.c"
    break;

  case 210: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 958 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3803 "C_grammar.tab.c"
    break;

  case 211: /* parameter_declaration: declaration_specifiers  */
#line 965 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3813 "C_grammar.tab.c"
    break;

  case 214: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 978 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3819 "C_grammar.tab.c"
    break;

  case 215: /* type_name: specifier_qualifier_list  */
#line 980 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3829 "C_grammar.tab.c"
    break;

  case 240: /* initializer: '{' initializer_list '}'  */
#line 1019 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3839 "C_grammar.tab.c"
    break;

  case 241: /* initializer: '{' initializer_list ',' '}'  */
#line 1025 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "trailing_comma_initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3849 "C_grammar.tab.c"
    break;

  case 243: /* initializer_list: designation initializer  */
#line 1035 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3860 "C_grammar.tab.c"
    break;

  case 245: /* initializer_list: initializer_list ',' designation initializer  */
#line 1043 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3872 "C_grammar.tab.c"
    break;

  case 246: /* initializer_list: initializer_list ',' initializer  */
#line 1051 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3883 "C_grammar.tab.c"
    break;

  case 247: /* designation: designator_list '='  */
#line 1061 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3893 "C_grammar.tab.c"
    break;

  case 249: /* designator_list: designator_list designator  */
#line 1071 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3904 "C_grammar.tab.c"
    break;

  case 250: /* designator: '[' constant_expression ']'  */
#line 1081 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 3910 "C_grammar.tab.c"
    break;

  case 251: /* designator: '.' IDENTIFIER  */
#line 1083 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3920 "C_grammar.tab.c"
    break;

  case 252: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1092 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 3931 "C_grammar.tab.c"
    break;

  case 259: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1111 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3942 "C_grammar.tab.c"
    break;

  case 260: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1118 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3953 "C_grammar.tab.c"
    break;

  case 261: /* labeled_statement: DEFAULT ':' statement  */
#line 1125 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 3963 "C_grammar.tab.c"
    break;

  case 262: /* compound_statement: '{' '}'  */
#line 1133 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 3969 "C_grammar.tab.c"
    break;

  case 263: /* compound_statement: '{' block_item_list '}'  */
#line 1135 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 3979 "C_grammar.tab.c"
    break;

  case 265: /* block_item_list: block_item_list block_item  */
#line 1145 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
	  }
#line 3990 "C_grammar.tab.c"
    break;

  case 268: /* expression_statement: ';'  */
#line 1159 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 3996 "C_grammar.tab.c"
    break;

  case 269: /* expression_statement: expression ';'  */
#line 1161 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 4006 "C_grammar.tab.c"
    break;

  case 270: /* selection_statement: IF '(' expression ')' statement else_opt  */
#line 1170 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4018 "C_grammar.tab.c"
    break;

  case 271: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1178 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4029 "C_grammar.tab.c"
    break;

  case 272: /* else_opt: %empty  */
#line 1187 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4035 "C_grammar.tab.c"
    break;

  case 273: /* else_opt: ELSE statement  */
#line 1189 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4045 "C_grammar.tab.c"
    break;

  case 274: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1197 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4056 "C_grammar.tab.c"
    break;

  case 275: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1204 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 4067 "C_grammar.tab.c"
    break;

  case 276: /* iteration_statement: FOR '(' for_stmt_type ')' statement  */
#line 1211 "C_grammar.y"
                {size_t const size = strlen("\ncmp_stmts([, \nwhile_stmt(branch(, ), \ncmp_stmts([, ]))])") + strlen((yyvsp[-2].for_stmt_type).init) + MAX_BRANCH_STR + strlen((yyvsp[-2].for_stmt_type).cond) + strlen((yyvsp[0].id)) + strlen((yyvsp[-2].for_stmt_type).update) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ncmp_stmts([%s, \nwhile_stmt(branch(%d, %s), \ncmp_stmts([%s, %s]))])", (yyvsp[-2].for_stmt_type).init, branch_nb++, (yyvsp[-2].for_stmt_type).cond, (yyvsp[0].id), (yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[-2].for_stmt_type).init);
		 free((yyvsp[-2].for_stmt_type).cond);
		 free((yyvsp[-2].for_stmt_type).update);
		 free((yyvsp[0].id));
		}
#line 4080 "C_grammar.tab.c"
    break;

  case 277: /* for_stmt_type: expression_statement expression_opt ';' expression_opt  */
#line 1223 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4086 "C_grammar.tab.c"
    break;

  case 278: /* for_stmt_type: declaration expression_opt ';' expression_opt  */
#line 1225 "C_grammar.y"
          {(yyval.for_stmt_type) = (struct for_stmt){.init = (yyvsp[-3].id), .cond = (yyvsp[-2].id), .update = (yyvsp[0].id)};}
#line 4092 "C_grammar.tab.c"
    break;

  case 279: /* expression_opt: %empty  */
#line 1229 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "int(1)");}
#line 4098 "C_grammar.tab.c"
    break;

  case 281: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1234 "C_grammar.y"
          {size_t const size = strlen("\ngoto_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4108 "C_grammar.tab.c"
    break;

  case 282: /* jump_statement: CONTINUE ';'  */
#line 1239 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4114 "C_grammar.tab.c"
    break;

  case 283: /* jump_statement: BREAK ';'  */
#line 1240 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4120 "C_grammar.tab.c"
    break;

  case 284: /* jump_statement: RETURN ';'  */
#line 1241 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4126 "C_grammar.tab.c"
    break;

  case 285: /* jump_statement: RETURN expression ';'  */
#line 1243 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4136 "C_grammar.tab.c"
    break;

  case 287: /* $@6: %empty  */
#line 1253 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4142 "C_grammar.tab.c"
    break;

  case 289: /* external_declaration: function_definition  */
#line 1257 "C_grammar.y"
                                {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4148 "C_grammar.tab.c"
    break;

  case 290: /* external_declaration: declaration  */
#line 1258 "C_grammar.y"
                                        {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4154 "C_grammar.tab.c"
    break;

  case 291: /* function_definition: declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 1263 "C_grammar.y"
                {size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4167 "C_grammar.tab.c"
    break;

  case 292: /* declaration_list_opt: %empty  */
#line 1274 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4173 "C_grammar.tab.c"
    break;

  case 295: /* declaration_list: declaration_list declaration  */
#line 1281 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4184 "C_grammar.tab.c"
    break;


#line 4188 "C_grammar.tab.c"

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

#line 1289 "C_grammar.y"

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

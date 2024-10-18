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
#include "utils.c"
#include "handle_typedefs.c"

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;

#define MAX_ID_LENGTH 255
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


void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 124 "C_grammar.tab.c"

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
    LOWER_THAN_ELSE = 332          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "C_grammar.y"

	char* id;

#line 252 "C_grammar.tab.c"

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
  YYSYMBOL_LOWER_THAN_ELSE = 77,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_78_ = 78,                       /* '('  */
  YYSYMBOL_79_ = 79,                       /* ')'  */
  YYSYMBOL_80_ = 80,                       /* ','  */
  YYSYMBOL_81_ = 81,                       /* ':'  */
  YYSYMBOL_82_ = 82,                       /* '['  */
  YYSYMBOL_83_ = 83,                       /* ']'  */
  YYSYMBOL_84_ = 84,                       /* '.'  */
  YYSYMBOL_85_ = 85,                       /* '{'  */
  YYSYMBOL_86_ = 86,                       /* '}'  */
  YYSYMBOL_87_ = 87,                       /* '&'  */
  YYSYMBOL_88_ = 88,                       /* '*'  */
  YYSYMBOL_89_ = 89,                       /* '+'  */
  YYSYMBOL_90_ = 90,                       /* '-'  */
  YYSYMBOL_91_ = 91,                       /* '~'  */
  YYSYMBOL_92_ = 92,                       /* '!'  */
  YYSYMBOL_93_ = 93,                       /* '/'  */
  YYSYMBOL_94_ = 94,                       /* '%'  */
  YYSYMBOL_95_ = 95,                       /* '<'  */
  YYSYMBOL_96_ = 96,                       /* '>'  */
  YYSYMBOL_97_ = 97,                       /* '^'  */
  YYSYMBOL_98_ = 98,                       /* '|'  */
  YYSYMBOL_99_ = 99,                       /* '?'  */
  YYSYMBOL_100_ = 100,                     /* '='  */
  YYSYMBOL_101_ = 101,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 102,                 /* $accept  */
  YYSYMBOL_primary_expression = 103,       /* primary_expression  */
  YYSYMBOL_constant = 104,                 /* constant  */
  YYSYMBOL_enumeration_constant = 105,     /* enumeration_constant  */
  YYSYMBOL_string = 106,                   /* string  */
  YYSYMBOL_generic_selection = 107,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 108,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 109,      /* generic_association  */
  YYSYMBOL_postfix_expression = 110,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 111, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 112,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 113,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 114,           /* unary_operator  */
  YYSYMBOL_cast_expression = 115,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 116, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 117, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 118,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 119,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 120,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 121,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 122,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 123, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 124,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 125,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 126,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 127,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 128,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 129,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 130,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 131,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 132,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 133,      /* assignment_operator  */
  YYSYMBOL_expression = 134,               /* expression  */
  YYSYMBOL_constant_expression = 135,      /* constant_expression  */
  YYSYMBOL_declaration = 136,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 137,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 138,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 139,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 140,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 141,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 142, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 143,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 144,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 145,       /* struct_declaration  */
  YYSYMBOL_146_1 = 146,                    /* $@1  */
  YYSYMBOL_specifier_qualifier_list = 147, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 148,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 149,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 150,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 151,          /* enumerator_list  */
  YYSYMBOL_enumerator = 152,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 153,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 154,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 155,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 156,      /* alignment_specifier  */
  YYSYMBOL_declarator = 157,               /* declarator  */
  YYSYMBOL_direct_declarator = 158,        /* direct_declarator  */
  YYSYMBOL_pointer = 159,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 160,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 161,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 162,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 163,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 164,          /* identifier_list  */
  YYSYMBOL_type_name = 165,                /* type_name  */
  YYSYMBOL_abstract_declarator = 166,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 167, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 168,              /* initializer  */
  YYSYMBOL_initializer_list = 169,         /* initializer_list  */
  YYSYMBOL_designation = 170,              /* designation  */
  YYSYMBOL_designator_list = 171,          /* designator_list  */
  YYSYMBOL_designator = 172,               /* designator  */
  YYSYMBOL_static_assert_declaration = 173, /* static_assert_declaration  */
  YYSYMBOL_statement = 174,                /* statement  */
  YYSYMBOL_labeled_statement = 175,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 176,       /* compound_statement  */
  YYSYMBOL_block_item_list = 177,          /* block_item_list  */
  YYSYMBOL_block_item = 178,               /* block_item  */
  YYSYMBOL_expression_statement = 179,     /* expression_statement  */
  YYSYMBOL_selection_statement = 180,      /* selection_statement  */
  YYSYMBOL_else_opt = 181,                 /* else_opt  */
  YYSYMBOL_iteration_statement = 182,      /* iteration_statement  */
  YYSYMBOL_for_stmt_type = 183,            /* for_stmt_type  */
  YYSYMBOL_expression_opt = 184,           /* expression_opt  */
  YYSYMBOL_jump_statement = 185,           /* jump_statement  */
  YYSYMBOL_translation_unit = 186,         /* translation_unit  */
  YYSYMBOL_187_2 = 187,                    /* $@2  */
  YYSYMBOL_external_declaration = 188,     /* external_declaration  */
  YYSYMBOL_function_definition = 189,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 190,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 191          /* declaration_list  */
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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  287
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  477

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


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
       2,     2,     2,    92,     2,     2,     2,    94,    87,     2,
      78,    79,    88,    89,    80,    90,    84,    93,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,   101,
      95,   100,    96,    99,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    97,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    98,    86,    91,     2,     2,     2,
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
      75,    76,    77
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   125,   126,   127,   133,   139,   143,   144,
     145,   149,   153,   154,   158,   162,   163,   167,   168,   172,
     173,   180,   186,   193,   200,   207,   213,   219,   226,   236,
     237,   247,   248,   255,   262,   268,   274,   283,   284,   288,
     289,   290,   291,   292,   293,   297,   298,   308,   309,   320,
     321,   322,   326,   327,   338,   339,   343,   344,   355,   356,
     360,   361,   372,   373,   374,   375,   380,   381,   392,   393,
     397,   398,   408,   409,   419,   420,   430,   431,   441,   442,
     452,   453,   464,   465,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   490,   491,   501,   505,   511,
     521,   530,   537,   538,   545,   546,   548,   550,   552,   554,
     556,   561,   562,   572,   579,   588,   592,   593,   594,   595,
     596,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   619,   626,   634,
     644,   645,   649,   650,   660,   666,   666,   674,   678,   685,
     686,   693,   697,   698,   708,   714,   721,   725,   731,   737,
     744,   751,   760,   761,   771,   778,   782,   786,   787,   788,
     789,   793,   794,   798,   799,   803,   810,   814,   828,   830,
     832,   834,   836,   838,   840,   842,   844,   846,   848,   854,
     862,   867,   874,   880,   886,   891,   892,   902,   908,   917,
     918,   928,   935,   942,   951,   952,   956,   957,   966,   967,
     968,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   983,   984,   985,   986,   987,   988,   989,   990,
     991,   992,   996,  1002,  1008,  1012,  1019,  1020,  1028,  1038,
    1047,  1048,  1058,  1060,  1069,  1079,  1080,  1081,  1082,  1083,
    1084,  1088,  1095,  1102,  1111,  1112,  1121,  1122,  1132,  1133,
    1137,  1138,  1147,  1155,  1165,  1166,  1174,  1181,  1188,  1198,
    1206,  1217,  1218,  1226,  1232,  1233,  1234,  1235,  1245,  1246,
    1246,  1250,  1251,  1255,  1267,  1268,  1272,  1273
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
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "LOWER_THAN_ELSE", "'('",
  "')'", "','", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "'='", "';'", "$accept", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
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
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "$@1", "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
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
  "jump_statement", "translation_unit", "$@2", "external_declaration",
  "function_definition", "declaration_list_opt", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-371)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-285)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1996,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,    17,   -66,  2257,  -371,  -371,
     -47,  -371,  -371,     6,  2101,  2101,  -371,    31,  -371,  -371,
    2101,  2101,  2101,  -371,    57,  -371,  -371,   -15,    85,   953,
    2257,    96,  2257,    -2,  1610,  -371,    33,     3,  -371,   -45,
    -371,   824,    56,    51,  -371,  -371,    11,  2153,  -371,  -371,
    -371,  -371,  1996,    85,  -371,     0,   -41,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  1633,  -371,  -371,    71,    80,   898,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
     182,  -371,  1723,  1610,  -371,   -56,   144,   186,   127,   219,
      78,    92,    77,   161,    28,  -371,   119,   136,  -371,  1785,
    1043,   138,  -371,   146,  -371,  -371,   149,   147,  -371,  -371,
       3,    33,  -371,  1474,  -371,     6,   150,  1996,  1892,  1066,
      56,  2153,   765,  -371,   140,  -371,  -371,   106,  1610,    45,
    -371,   898,  -371,  2257,  1610,   521,   317,  -371,  -371,   160,
     164,   173,   255,  -371,  -371,  1497,  1610,   258,   898,  -371,
    -371,  -371,  -371,  -371,  1610,  -371,  -371,  1610,  -371,  -371,
    1610,  -371,  -371,  -371,  -371,  1610,  -371,  -371,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  -371,  -371,  -371,    84,   184,
     185,  -371,   196,  1315,  -371,   202,   205,  1089,   146,  1944,
    1179,   281,  -371,  -371,  -371,  -371,   190,  1451,  -371,  -371,
    -371,  -371,  -371,  -371,   212,   167,  1315,  -371,   210,   211,
    1202,  1837,  -371,  -371,  -371,    44,    47,  -371,  -371,  -371,
    -371,   218,   220,   221,   217,  1610,   222,   224,   230,   232,
     386,   233,   309,   214,   215,   422,  -371,  -371,   -29,  -371,
    -371,  -371,  -371,   611,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,
    1610,  -371,  1610,  1587,  -371,  -371,  -371,   169,  -371,    99,
    -371,   234,  -371,   -56,   144,   186,   127,   219,    78,    92,
      77,   161,   176,  1706,  -371,    95,  -371,  -371,  2048,  -371,
     237,  1315,  -371,  -371,  1610,  -371,   239,  -371,   246,  1315,
    -371,   247,   248,  1225,   250,  1610,   329,  -371,   111,  1474,
      -8,  -371,  -371,  -371,   330,   251,  1315,  -371,  -371,  1610,
    -371,   253,   266,  -371,  1610,   -12,  -371,   269,  -371,   267,
    -371,  2205,   386,   270,   386,  1610,  1610,  1610,   291,   701,
     254,  -371,  -371,  -371,    68,  -371,  -371,  -371,  -371,  -371,
    1451,  -371,  -371,  1610,  -371,   267,  1610,  -371,  -371,  -371,
     271,   273,  -371,  -371,   274,  1315,  -371,  -371,  1610,  -371,
     277,   260,   279,  -371,  1338,  -371,  -371,  -371,  -371,  -371,
    -371,   283,   284,  -371,  -371,  -371,    44,  -371,  1610,   287,
     191,  -371,   290,  -371,   386,  -371,   193,   199,   201,   294,
     754,   754,   295,  -371,  -371,   132,  -371,  -371,  -371,  -371,
    -371,   292,   297,  -371,  -371,  -371,  -371,  -371,  1474,  -371,
    -371,  -371,  -371,  1610,  -371,  2205,  1610,  -371,   386,   386,
     386,  1610,  1610,  1610,   386,  1361,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,   313,  -371,  -371,   203,   298,  -371,  -371,
    -371,  -371,   386,  -371,   280,  -371,  -371
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   136,   115,   116,   117,   119,   120,   171,   167,   168,
     169,   130,   122,   123,   124,   125,   128,   129,   126,   127,
     121,   131,   132,   140,   141,     0,     0,     0,   170,   172,
       0,   118,   282,     0,   102,   104,   134,     0,   135,   133,
     106,   108,   110,   100,   279,   278,   281,   161,     0,     0,
     149,   207,   151,     0,     0,   177,     0,   194,    98,     0,
     111,   114,   176,     0,   101,   103,   139,     0,   105,   107,
     109,     1,     0,     0,    11,   165,     0,   162,     2,     8,
       9,    10,    12,    13,     0,    37,    38,     0,     0,     0,
      39,    40,    41,    42,    43,    44,    19,     3,     4,     7,
      31,    45,     0,     0,    47,    52,    56,    60,    66,    70,
      72,    74,    76,    78,    80,    97,     0,     0,   148,     0,
       0,   209,   206,   210,   150,   166,     0,     0,   195,   193,
     192,     0,    99,     0,   286,     0,     0,   285,     0,     0,
     175,     0,     0,   142,   145,   147,   280,     0,     0,     0,
     157,     0,    34,     0,     0,     0,    45,    82,    95,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    32,
      33,    49,    50,    51,     0,    54,    55,     0,    58,    59,
       0,    64,    65,    62,    63,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,   174,   173,   228,   203,     0,
     198,   199,     0,     0,   212,    40,     0,     0,   208,     0,
       0,     0,   178,   196,   191,   112,   114,     0,   234,   113,
     283,   287,   204,   188,     0,     0,     0,   179,    40,     0,
       0,     0,   137,   143,   144,     0,     0,   159,   164,   158,
     163,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   260,     0,   258,
     259,   245,   246,     0,   256,   247,   248,   249,   250,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    84,
       0,     6,     0,     0,     5,    24,    21,     0,    29,     0,
      23,     0,    48,    53,    57,    61,    67,    71,    73,    75,
      77,    79,     0,     0,   201,   209,   202,   229,     0,   211,
       0,     0,   213,   219,     0,   218,     0,   230,     0,     0,
     220,    40,     0,     0,     0,     0,     0,   236,     0,     0,
       0,   240,   189,   190,     0,     0,     0,   180,   187,     0,
     186,    40,     0,   138,     0,     0,   152,   156,   160,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,   275,   276,     0,   261,   255,   257,    83,    96,
       0,    46,    22,     0,    20,     0,     0,   197,   200,   215,
       0,     0,   217,   231,     0,     0,   221,   227,     0,   226,
       0,     0,     0,   243,     0,   232,   235,   239,   241,   205,
     182,     0,     0,   183,   185,   154,     0,   146,     0,     0,
       0,    15,     0,   251,     0,   253,     0,     0,     0,     0,
       0,     0,     0,   273,   277,     0,    30,    81,   214,   216,
     223,     0,     0,   224,   244,   242,   233,   238,     0,   181,
     184,   153,   155,     0,    14,     0,     0,   252,     0,     0,
       0,     0,   271,   271,     0,     0,    27,   222,   225,   237,
      18,    16,    17,   264,   263,   266,     0,   272,   270,   269,
     268,    28,     0,   262,     0,   265,   267
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -371,  -371,  -371,  -371,  -371,  -371,  -371,   -63,  -371,  -371,
     -38,  -371,  -371,   -95,   206,  -371,   204,  -371,   200,  -371,
     198,  -371,   208,  -371,   197,   209,   213,   195,  -371,   -39,
      97,  -371,   -88,   -49,   -42,    18,  -371,   259,  -371,   -23,
    -371,  -371,   261,  -114,  -371,    19,  -371,    -5,  -371,   331,
    -128,  -371,   -27,  -371,  -371,   -30,   -61,    16,  -106,     2,
    -371,    98,  -371,    34,   -34,  -115,  -120,    37,  -370,  -371,
      73,   -60,  -195,  -371,    74,  -371,   151,  -189,  -371,  -371,
    -371,  -371,   -44,  -371,  -371,  -371,   338,  -371,  -371,  -371
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    96,    97,    75,    98,    99,   410,   411,   100,   287,
     156,   102,   103,   104,   105,   174,   106,   177,   107,   180,
     108,   185,   109,   188,   110,   111,   112,   113,   114,   157,
     158,   280,   258,   116,    32,   135,    59,    60,    34,    35,
      36,    37,   142,   143,   235,    51,   345,   346,    38,    76,
      77,    39,    40,    41,    42,   127,    62,    63,   130,   199,
     200,   201,   225,   412,   202,   123,   327,   328,   329,   330,
     331,    43,   260,   261,   262,   263,   264,   265,   266,   473,
     267,   422,   468,   268,    44,    72,    45,    46,   136,   137
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,   159,   140,    61,    50,   126,   208,   145,   170,    55,
     115,   101,    49,   219,   207,   115,   101,   122,    33,   134,
      47,   240,    52,    52,   438,    52,    50,    50,   233,    50,
     128,    54,   171,   230,    66,   131,    55,   172,   173,   149,
      52,     8,     9,    10,    50,   150,   152,    55,    74,   193,
      74,   282,    64,    65,    55,   358,   132,    71,    68,    69,
      70,    53,    52,   159,   169,   101,    50,   121,   406,   118,
      73,   124,   365,   129,   325,    28,   326,   125,   289,   292,
     159,   145,   145,   117,    56,   438,   144,    55,    74,   407,
      33,    57,   397,   128,    57,   221,   141,   311,    55,   238,
     148,   216,    48,   213,   323,   216,   302,    58,   240,   115,
     101,    56,   128,   259,    52,    52,    67,   233,    50,    50,
     336,    57,    56,   160,    52,   344,    52,   194,    50,    56,
      50,   239,    57,   348,   138,   121,   101,   198,   139,   101,
     224,    52,   101,   181,   182,    50,   214,   101,   282,   153,
     101,   101,   101,   101,   101,   101,   198,   413,   154,   415,
     144,   144,   303,   161,   306,   189,   120,   364,   304,   424,
     421,   145,    57,   303,   119,   191,   128,   120,   120,   282,
     213,   192,   374,   128,    57,   241,   236,   242,   371,   190,
     208,   394,   237,   162,   163,   164,   353,   395,   195,   128,
     178,   179,   291,   213,    52,   347,   115,   101,    50,   396,
     220,   318,   455,   385,   305,   196,   119,   206,   456,   447,
     120,   259,   183,   184,   209,   161,   212,   198,   210,   211,
     218,   452,   453,   175,   176,   155,   229,   186,   187,   281,
     282,   234,   161,   283,   140,   101,   333,   334,   372,   373,
     144,   243,   284,   463,   464,   465,   282,   376,   285,   470,
     165,   290,   288,   307,   166,   308,   167,   416,   417,   418,
     444,   445,   448,   282,   437,   309,   392,   475,   449,   282,
     450,   282,   474,   282,   213,   312,   115,   101,   313,   324,
     133,   332,   128,   337,   338,   405,   213,   349,   352,   350,
     310,   351,   355,   354,   316,   115,   101,   322,   356,   213,
     357,   359,   360,   375,   218,   361,   362,   420,   459,   305,
     379,   198,   382,   335,    52,   383,   198,   342,    50,   391,
     386,   387,   393,   399,   400,   437,   403,   427,   101,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   404,
     408,   414,   370,   419,   428,   423,   429,   430,   213,   442,
     433,   434,   435,   466,   467,   467,   439,   440,   443,   115,
     101,   446,   451,   472,   454,   457,   347,   368,   282,   369,
     458,   476,   461,   293,   294,   295,   296,   298,   301,   244,
     215,    79,    80,    81,    82,    83,    84,   297,    85,    86,
     299,   441,   231,   398,   147,   300,   378,   425,   380,   469,
     146,   381,     0,     0,   367,     0,   384,   279,    52,     0,
     390,     0,    50,     0,     0,    78,   218,    79,    80,    81,
      82,    83,    84,   401,    85,    86,   402,     0,     0,     0,
       0,     0,     0,   245,   246,   247,     0,   248,   249,   250,
     251,   252,   253,   254,   255,     0,    87,     0,     0,    88,
       0,     0,     0,     0,    89,     0,     0,   218,     0,     0,
     426,   155,     0,    90,    91,    92,    93,    94,    95,     0,
       0,     0,   431,     0,     0,   432,     0,   257,     0,     0,
       0,   218,    87,     0,     0,    88,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,   363,   244,     1,    79,    80,    81,    82,
      83,    84,     0,    85,    86,   218,     0,     0,     0,     0,
     460,     0,     0,   462,     0,     0,     0,     0,     0,     0,
       0,     0,   218,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   245,   246,
     247,     0,   248,   249,   250,   251,   252,   253,   254,   255,
      26,    87,    27,    28,    88,    29,    30,    31,     0,    89,
       0,     0,     0,     0,     0,     0,   155,   256,    90,    91,
      92,    93,    94,    95,   244,     1,    79,    80,    81,    82,
      83,    84,   257,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   245,   246,
     247,     0,   248,   249,   250,   251,   252,   253,   254,   255,
      26,    87,    27,    28,    88,    29,    30,    31,     0,    89,
       0,     0,     0,     0,     0,     0,   155,   366,    90,    91,
      92,    93,    94,    95,    78,     1,    79,    80,    81,    82,
      83,    84,   257,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     1,
      26,    87,    27,    28,    88,    29,    30,    31,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,    87,     0,     0,    88,     1,     0,
       0,     0,    89,     0,     0,     0,    27,    28,     0,     0,
      30,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,   232,     0,     0,     0,   257,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,    30,
      31,    78,     1,    79,    80,    81,    82,    83,    84,  -284,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,    78,     1,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,    87,    27,
      28,    88,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,   155,     0,    90,    91,    92,    93,    94,
      95,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    27,    28,    88,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,    79,    80,    81,    82,    83,    84,   203,    85,    86,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,    79,    80,    81,    82,    83,    84,
     226,    85,    86,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,    87,     0,    28,    88,     0,     0,     0,
       0,    89,     0,   314,     0,     0,   204,     8,     9,    10,
      90,   205,    92,    93,    94,    95,    87,     0,    28,    88,
       0,     0,     0,     0,    89,     0,     0,     0,     0,   227,
       0,     0,     0,    90,   228,    92,    93,    94,    95,    87,
       0,    28,    88,     0,     0,     0,     0,    89,     0,     0,
       0,     0,   315,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    78,     0,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,    79,    80,    81,
      82,    83,    84,   319,    85,    86,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    83,    84,   339,    85,    86,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,    87,
       0,    28,    88,     0,     0,     0,     0,    89,     0,   388,
       0,     0,   320,     8,     9,    10,    90,   321,    92,    93,
      94,    95,    87,     0,    28,    88,     0,     0,     0,     0,
      89,     0,     0,     0,     0,   340,     0,     0,     0,    90,
     341,    92,    93,    94,    95,    87,     0,    28,    88,     0,
       0,     0,     0,    89,     0,     0,     0,     0,   389,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    28,    88,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    87,     0,
       0,    88,     0,     0,     0,     0,    89,     0,     0,     0,
     325,     0,   326,   217,   436,    90,    91,    92,    93,    94,
      95,    87,     0,     0,    88,     0,     0,     0,     0,    89,
       0,     0,     0,   325,     0,   326,   217,   471,    90,    91,
      92,    93,    94,    95,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,    88,     0,     0,     0,     0,    89,
       0,     0,     0,   325,     0,   326,   217,     0,    90,    91,
      92,    93,    94,    95,    87,     0,     0,    88,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,   217,
       0,    90,    91,    92,    93,    94,    95,    87,     0,     0,
      88,     0,     0,     0,     0,    89,   286,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
      88,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,   370,     0,    90,    91,    92,    93,    94,    95,
      87,     0,     0,    88,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    87,     0,     0,    88,     0,     0,    55,
       1,   151,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,     0,    31,     0,   303,   197,     0,     0,   120,     1,
       0,     0,     0,    87,    57,     0,    88,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,     0,   119,   197,     0,     0,   120,     0,     0,
       0,     0,     0,    57,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,   222,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   343,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,     0,
       0,   223,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,     0,     0,   317,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   377,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,    29,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,    28,     0,    29,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28
};

static const yytype_int16 yycheck[] =
{
      27,    89,    63,    33,    27,    54,   121,    67,   103,     3,
      49,    49,    78,   133,   120,    54,    54,    51,     0,    61,
       3,   149,    49,    50,   394,    52,    49,    50,   142,    52,
      57,    78,    88,   139,     3,    80,     3,    93,    94,    80,
      67,    38,    39,    40,    67,    86,    84,     3,     3,    21,
       3,    80,    34,    35,     3,   250,   101,     0,    40,    41,
      42,    27,    89,   151,   102,   103,    89,    51,    80,    50,
      85,    52,   101,    57,    82,    72,    84,    79,   166,   174,
     168,   141,   142,    49,    78,   455,    67,     3,     3,   101,
      72,    88,   100,   120,    88,   137,    85,   203,     3,   148,
     100,   131,    85,   130,   210,   135,   194,   101,   236,   148,
     148,    78,   139,   155,   141,   142,    85,   231,   141,   142,
     226,    88,    78,    89,   151,    81,   153,    99,   151,    78,
     153,    86,    88,    86,    78,   119,   174,   119,    82,   177,
     138,   168,   180,    16,    17,   168,   130,   185,    80,    78,
     188,   189,   190,   191,   192,   193,   138,   352,    78,   354,
     141,   142,    78,    89,   198,    87,    82,   255,   198,   101,
     359,   231,    88,    78,    78,    98,   203,    82,    82,    80,
     207,    20,    83,   210,    88,   151,    80,   153,   283,    97,
     305,    80,    86,    11,    12,    13,   245,    86,    79,   226,
      14,    15,   168,   230,   231,   235,   245,   245,   231,   329,
     136,   209,    80,   319,   198,    79,    78,   120,    86,   414,
      82,   263,    95,    96,    78,   151,    79,   209,    82,    80,
     133,   420,   421,    89,    90,    85,   139,    18,    19,    79,
      80,   101,   168,    79,   305,   283,    79,    80,    79,    80,
     231,   154,    79,   448,   449,   450,    80,    81,     3,   454,
      78,     3,   165,    79,    82,    80,    84,   355,   356,   357,
      79,    80,    79,    80,   394,    79,   325,   472,    79,    80,
      79,    80,    79,    80,   311,    83,   325,   325,    83,     8,
     100,    79,   319,    83,    83,   344,   323,    79,    81,    79,
     203,    80,    78,    81,   207,   344,   344,   210,    78,   336,
      78,    78,     3,    79,   217,   101,   101,   359,   438,   303,
      83,   303,    83,   226,   351,    79,   308,   230,   351,    79,
      83,    83,     3,     3,    83,   455,    83,   376,   376,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    83,
      81,    81,    85,    62,    83,   101,    83,    83,   385,   408,
      83,   101,    83,   451,   452,   453,    83,    83,    81,   408,
     408,    81,    78,    60,    79,    83,   406,   280,    80,   282,
      83,   101,   445,   177,   180,   185,   188,   190,   193,     3,
     131,     5,     6,     7,     8,     9,    10,   189,    12,    13,
     191,   406,   141,   330,    73,   192,   308,   370,   311,   453,
      72,   314,    -1,    -1,   263,    -1,   319,   100,   445,    -1,
     323,    -1,   445,    -1,    -1,     3,   329,     5,     6,     7,
       8,     9,    10,   336,    12,    13,   339,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    78,    -1,    -1,   370,    -1,    -1,
     373,    85,    -1,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,   385,    -1,    -1,   388,    -1,   101,    -1,    -1,
      -1,   394,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,   438,    -1,    -1,    -1,    -1,
     443,    -1,    -1,   446,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   455,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,     3,     4,     5,     6,     7,     8,
       9,    10,   101,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,     3,     4,     5,     6,     7,     8,
       9,    10,   101,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,     4,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    70,    -1,    -1,    73,     4,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    71,    72,    -1,    -1,
      75,    87,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,   101,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      76,     3,     4,     5,     6,     7,     8,     9,    10,    85,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    87,    88,    89,    90,    91,
      92,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    34,    12,    13,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      34,    12,    13,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,    -1,
      -1,    78,    -1,    34,    -1,    -1,    83,    38,    39,    40,
      87,    88,    89,    90,    91,    92,    70,    -1,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,    70,
      -1,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    34,    12,    13,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    34,    12,    13,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    34,
      -1,    -1,    83,    38,    39,    40,    87,    88,    89,    90,
      91,    92,    70,    -1,    72,    73,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    70,    -1,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      82,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    87,    88,    89,    90,    91,    92,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    87,    88,    89,    90,    91,    92,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    70,    -1,    -1,    73,    -1,    -1,     3,
       4,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    -1,    76,    -1,    78,    79,    -1,    -1,    82,     4,
      -1,    -1,    -1,    70,    88,    -1,    73,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    -1,    78,    79,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,   136,   137,   140,   141,   142,   143,   150,   153,
     154,   155,   156,   173,   186,   188,   189,     3,    85,    78,
     141,   147,   154,   165,    78,     3,    78,    88,   101,   138,
     139,   157,   158,   159,   137,   137,     3,    85,   137,   137,
     137,     0,   187,    85,     3,   105,   151,   152,     3,     5,
       6,     7,     8,     9,    10,    12,    13,    70,    73,    78,
      87,    88,    89,    90,    91,    92,   103,   104,   106,   107,
     110,   112,   113,   114,   115,   116,   118,   120,   122,   124,
     126,   127,   128,   129,   130,   131,   135,   165,   147,    78,
      82,   159,   166,   167,   147,    79,   135,   157,   154,   159,
     160,    80,   101,   100,   136,   137,   190,   191,    78,    82,
     158,    85,   144,   145,   147,   173,   188,   151,   100,    80,
      86,    78,   112,    78,    78,    85,   112,   131,   132,   134,
     165,   176,    11,    12,    13,    78,    82,    84,    78,   112,
     115,    88,    93,    94,   117,    89,    90,   119,    14,    15,
     121,    16,    17,    95,    96,   123,    18,    19,   125,    87,
      97,    98,    20,    21,    99,    79,    79,    79,   137,   161,
     162,   163,   166,    34,    83,    88,   132,   160,   167,    78,
      82,    80,    79,   154,   159,   139,   157,    85,   132,   168,
     176,   136,     3,    79,   161,   164,    34,    83,    88,   132,
     160,   144,    86,   145,   101,   146,    80,    86,   135,    86,
     152,   165,   165,   132,     3,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    86,   101,   134,   136,
     174,   175,   176,   177,   178,   179,   180,   182,   185,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   100,
     133,    79,    80,    79,    79,     3,    79,   111,   132,   134,
       3,   165,   115,   116,   118,   120,   122,   124,   126,   127,
     128,   129,   134,    78,   157,   159,   166,    79,    80,    79,
     132,   160,    83,    83,    34,    83,   132,    79,   161,    34,
      83,    88,   132,   160,     8,    82,    84,   168,   169,   170,
     171,   172,    79,    79,    80,   132,   160,    83,    83,    34,
      83,    88,   132,    86,    81,   148,   149,   157,    86,    79,
      79,    80,    81,   135,    81,    78,    78,    78,   174,    78,
       3,   101,   101,   101,   134,   101,    86,   178,   132,   132,
      85,   115,    79,    80,    83,    79,    81,    56,   163,    83,
     132,   132,    83,    79,   132,   160,    83,    83,    34,    83,
     132,    79,   135,     3,    80,    86,   168,   100,   172,     3,
      83,   132,   132,    83,    83,   135,    80,   101,    81,    58,
     108,   109,   165,   174,    81,   174,   134,   134,   134,    62,
     136,   179,   183,   101,   101,   169,   132,   131,    83,    83,
      83,   132,   132,    83,   101,    83,    86,   168,   170,    83,
      83,   149,   135,    81,    79,    80,    81,   174,    79,    79,
      79,    78,   179,   179,    79,    80,    86,    83,    83,   168,
     132,   109,   132,   174,   174,   174,   134,   134,   184,   184,
     174,    86,    60,   181,    79,   174,   101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   105,   106,   106,   107,   108,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   115,   115,   116,   116,   117,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   134,   134,   135,   136,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   140,   140,   140,   140,
     140,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   142,   142,   142,
     143,   143,   144,   144,   145,   146,   145,   145,   147,   147,
     147,   147,   148,   148,   149,   149,   149,   150,   150,   150,
     150,   150,   151,   151,   152,   152,   153,   154,   154,   154,
     154,   155,   155,   156,   156,   157,   157,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   159,   159,   160,   160,   161,   161,   162,
     162,   163,   163,   163,   164,   164,   165,   165,   166,   166,
     166,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   168,   168,   168,   169,   169,   169,   169,   170,
     171,   171,   172,   172,   173,   174,   174,   174,   174,   174,
     174,   175,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   180,   180,   181,   181,   182,   182,   182,   183,
     183,   184,   184,   185,   185,   185,   185,   185,   186,   187,
     186,   188,   188,   189,   190,   190,   191,   191
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
       1,     1,     1,     1,     1,     1,     1,     4,     5,     2,
       1,     1,     1,     2,     2,     0,     4,     1,     2,     1,
       2,     1,     1,     3,     2,     3,     1,     4,     5,     5,
       6,     2,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     4,     2,     1,     1,     3,     3,
       4,     6,     5,     5,     6,     5,     4,     4,     3,     4,
       4,     3,     2,     2,     1,     1,     2,     3,     1,     1,
       3,     2,     2,     1,     1,     3,     2,     1,     2,     1,
       1,     3,     2,     3,     5,     4,     5,     4,     3,     3,
       3,     4,     6,     5,     5,     6,     4,     4,     2,     3,
       3,     4,     3,     4,     1,     2,     1,     4,     3,     2,
       1,     2,     3,     2,     7,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     1,     2,     1,     1,
       1,     2,     6,     5,     0,     2,     5,     7,     5,     3,
       3,     0,     1,     3,     2,     2,     2,     3,     1,     0,
       3,     1,     1,     4,     0,     1,     1,     2
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
#line 112 "C_grammar.y"
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
#line 2446 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' compound_statement ')'  */
#line 128 "C_grammar.y"
                {size_t const size = strlen("\nstmt_exp()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt_exp(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2456 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' expression ')'  */
#line 134 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2466 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: generic_selection  */
#line 139 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2472 "C_grammar.tab.c"
    break;

  case 13: /* string: FUNC_NAME  */
#line 154 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2478 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 174 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2489 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' ')'  */
#line 181 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2499 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 187 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2510 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 194 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2521 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 201 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2532 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression INC_OP  */
#line 208 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2542 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression DEC_OP  */
#line 214 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2552 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 220 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2563 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 227 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2574 "C_grammar.tab.c"
    break;

  case 30: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 238 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2585 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_inc_dec unary_expression  */
#line 249 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2596 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 256 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2607 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 263 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2617 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 269 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2627 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 275 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2637 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: INC_OP  */
#line 283 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2643 "C_grammar.tab.c"
    break;

  case 38: /* unary_inc_dec: DEC_OP  */
#line 284 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2649 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '&'  */
#line 288 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2655 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '*'  */
#line 289 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2661 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '+'  */
#line 290 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2667 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '-'  */
#line 291 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2673 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '~'  */
#line 292 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "bw_one_comp");}
#line 2679 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '!'  */
#line 293 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2685 "C_grammar.tab.c"
    break;

  case 46: /* cast_expression: '(' type_name ')' cast_expression  */
#line 299 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2696 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 310 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2708 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '*'  */
#line 320 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2714 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '/'  */
#line 321 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2720 "C_grammar.tab.c"
    break;

  case 51: /* multiplicative_expression_op: '%'  */
#line 322 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2726 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 328 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2738 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '+'  */
#line 338 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2744 "C_grammar.tab.c"
    break;

  case 55: /* additive_expression_op: '-'  */
#line 339 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2750 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 345 "C_grammar.y"
                {size_t const size = strlen("bitwise(, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(%s, %s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2762 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: LEFT_OP  */
#line 355 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift");}
#line 2768 "C_grammar.tab.c"
    break;

  case 59: /* shift_expression_op: RIGHT_OP  */
#line 356 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift");}
#line 2774 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 362 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2786 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '<'  */
#line 372 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2792 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: '>'  */
#line 373 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2798 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: LE_OP  */
#line 374 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2804 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression_operator: GE_OP  */
#line 375 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2810 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 382 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2822 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: EQ_OP  */
#line 392 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2828 "C_grammar.tab.c"
    break;

  case 69: /* equality_expression_op: NE_OP  */
#line 393 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2834 "C_grammar.tab.c"
    break;

  case 71: /* and_expression: and_expression '&' equality_expression  */
#line 399 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_and, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_and, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2845 "C_grammar.tab.c"
    break;

  case 73: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 410 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_xor, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_xor, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2856 "C_grammar.tab.c"
    break;

  case 75: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 421 "C_grammar.y"
                {size_t const size = strlen("bitwise(bw_or, , )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitwise(bw_or, %s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2867 "C_grammar.tab.c"
    break;

  case 77: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 432 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2878 "C_grammar.tab.c"
    break;

  case 79: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 443 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2889 "C_grammar.tab.c"
    break;

  case 81: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 454 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + branch_nb++ + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2901 "C_grammar.tab.c"
    break;

  case 83: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 466 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2913 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: '='  */
#line 476 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2919 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: MUL_ASSIGN  */
#line 477 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2925 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: DIV_ASSIGN  */
#line 478 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2931 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: MOD_ASSIGN  */
#line 479 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2937 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: ADD_ASSIGN  */
#line 480 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2943 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: SUB_ASSIGN  */
#line 481 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2949 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: LEFT_ASSIGN  */
#line 482 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2955 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: RIGHT_ASSIGN  */
#line 483 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2961 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: AND_ASSIGN  */
#line 484 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2967 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: XOR_ASSIGN  */
#line 485 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2973 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: OR_ASSIGN  */
#line 486 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2979 "C_grammar.tab.c"
    break;

  case 96: /* expression: expression ',' assignment_expression  */
#line 492 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2990 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers ';'  */
#line 506 "C_grammar.y"
                {size_t const size = strlen("\ndeclaration([])") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3000 "C_grammar.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 512 "C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
		 size_t const size = strlen("\ndeclaration([], [])") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndeclaration([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		}
#line 3014 "C_grammar.tab.c"
    break;

  case 100: /* declaration: static_assert_declaration  */
#line 522 "C_grammar.y"
                {size_t const size = strlen("\n") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3024 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 531 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3035 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 539 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3046 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 547 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_type_qualifier, dummy_declaration_specifiers"); }
#line 3052 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: type_qualifier  */
#line 549 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_type_qualifier"); }
#line 3058 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 551 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); }
#line 3064 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: function_specifier  */
#line 553 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); }
#line 3070 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 555 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); }
#line 3076 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: alignment_specifier  */
#line 557 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); }
#line 3082 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 563 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3093 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator '=' initializer  */
#line 573 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	   	 //free($3);
	  	}
#line 3104 "C_grammar.tab.c"
    break;

  case 114: /* init_declarator: declarator  */
#line 580 "C_grammar.y"
          {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name((yyvsp[0].id));
	   }
	   simple_str_copy(&(yyval.id), (yyvsp[0].id));
	  }
#line 3114 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: TYPEDEF  */
#line 589 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
	    }
#line 3122 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: EXTERN  */
#line 592 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3128 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: STATIC  */
#line 593 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3134 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: THREAD_LOCAL  */
#line 594 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3140 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: AUTO  */
#line 595 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3146 "C_grammar.tab.c"
    break;

  case 120: /* storage_class_specifier: REGISTER  */
#line 596 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3152 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: VOID  */
#line 600 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 3158 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: CHAR  */
#line 601 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 3164 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: SHORT  */
#line 602 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 3170 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: INT  */
#line 603 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 3176 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: LONG  */
#line 604 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 3182 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: FLOAT  */
#line 605 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 3188 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: DOUBLE  */
#line 606 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 3194 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: SIGNED  */
#line 607 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3200 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: UNSIGNED  */
#line 608 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3206 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: BOOL  */
#line 609 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3212 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: COMPLEX  */
#line 610 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3218 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: IMAGINARY  */
#line 611 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3224 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: atomic_type_specifier  */
#line 612 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3230 "C_grammar.tab.c"
    break;

  case 137: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 620 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
	    }
#line 3241 "C_grammar.tab.c"
    break;

  case 138: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 627 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
	    }
#line 3253 "C_grammar.tab.c"
    break;

  case 139: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 635 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3264 "C_grammar.tab.c"
    break;

  case 140: /* struct_or_union: STRUCT  */
#line 644 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "struct");}
#line 3270 "C_grammar.tab.c"
    break;

  case 141: /* struct_or_union: UNION  */
#line 645 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "union");}
#line 3276 "C_grammar.tab.c"
    break;

  case 143: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 651 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3287 "C_grammar.tab.c"
    break;

  case 144: /* struct_declaration: specifier_qualifier_list ';'  */
#line 661 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3297 "C_grammar.tab.c"
    break;

  case 145: /* $@1: %empty  */
#line 666 "C_grammar.y"
                                   {in_member_decl_flag = 1;}
#line 3303 "C_grammar.tab.c"
    break;

  case 146: /* struct_declaration: specifier_qualifier_list $@1 struct_declarator_list ';'  */
#line 667 "C_grammar.y"
                {in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3315 "C_grammar.tab.c"
    break;

  case 148: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 679 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3326 "C_grammar.tab.c"
    break;

  case 150: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 687 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3337 "C_grammar.tab.c"
    break;

  case 153: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 699 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3348 "C_grammar.tab.c"
    break;

  case 154: /* struct_declarator: ':' constant_expression  */
#line 709 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3358 "C_grammar.tab.c"
    break;

  case 155: /* struct_declarator: declarator ':' constant_expression  */
#line 715 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3369 "C_grammar.tab.c"
    break;

  case 157: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 726 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3379 "C_grammar.tab.c"
    break;

  case 158: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 732 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3389 "C_grammar.tab.c"
    break;

  case 159: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 738 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3400 "C_grammar.tab.c"
    break;

  case 160: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 745 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum(%s, [%s])", (yyvsp[-4].id), (yyvsp[-2].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
        }
#line 3411 "C_grammar.tab.c"
    break;

  case 161: /* enum_specifier: ENUM IDENTIFIER  */
#line 752 "C_grammar.y"
                {size_t const size = strlen("forward_enum()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "forward_enum(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
        }
#line 3421 "C_grammar.tab.c"
    break;

  case 163: /* enumerator_list: enumerator_list ',' enumerator  */
#line 762 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3432 "C_grammar.tab.c"
    break;

  case 164: /* enumerator: enumeration_constant '=' constant_expression  */
#line 772 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3443 "C_grammar.tab.c"
    break;

  case 167: /* type_qualifier: CONST  */
#line 786 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3449 "C_grammar.tab.c"
    break;

  case 168: /* type_qualifier: RESTRICT  */
#line 787 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3455 "C_grammar.tab.c"
    break;

  case 169: /* type_qualifier: VOLATILE  */
#line 788 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3461 "C_grammar.tab.c"
    break;

  case 170: /* type_qualifier: ATOMIC  */
#line 789 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3467 "C_grammar.tab.c"
    break;

  case 171: /* function_specifier: INLINE  */
#line 793 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3473 "C_grammar.tab.c"
    break;

  case 172: /* function_specifier: NORETURN  */
#line 794 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3479 "C_grammar.tab.c"
    break;

  case 175: /* declarator: pointer direct_declarator  */
#line 804 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 3490 "C_grammar.tab.c"
    break;

  case 177: /* direct_declarator: IDENTIFIER  */
#line 815 "C_grammar.y"
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
#line 3508 "C_grammar.tab.c"
    break;

  case 178: /* direct_declarator: '(' declarator ')'  */
#line 829 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D1");}
#line 3514 "C_grammar.tab.c"
    break;

  case 179: /* direct_declarator: direct_declarator '[' ']'  */
#line 831 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D2");}
#line 3520 "C_grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 833 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D3");}
#line 3526 "C_grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 835 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D4");}
#line 3532 "C_grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 837 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D5");}
#line 3538 "C_grammar.tab.c"
    break;

  case 183: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 839 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D6");}
#line 3544 "C_grammar.tab.c"
    break;

  case 184: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 841 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D7");}
#line 3550 "C_grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 843 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D8");}
#line 3556 "C_grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 845 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D9");}
#line 3562 "C_grammar.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 847 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D10");}
#line 3568 "C_grammar.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '(' ')'  */
#line 849 "C_grammar.y"
                {size_t const size = strlen("function(, [])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, [])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3578 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 855 "C_grammar.y"
                {size_t const size = strlen("function(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 3589 "C_grammar.tab.c"
    break;

  case 190: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 863 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D13");}
#line 3595 "C_grammar.tab.c"
    break;

  case 191: /* pointer: '*' type_qualifier_list pointer  */
#line 868 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3606 "C_grammar.tab.c"
    break;

  case 192: /* pointer: '*' type_qualifier_list  */
#line 875 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3616 "C_grammar.tab.c"
    break;

  case 193: /* pointer: '*' pointer  */
#line 881 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3626 "C_grammar.tab.c"
    break;

  case 194: /* pointer: '*'  */
#line 887 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3632 "C_grammar.tab.c"
    break;

  case 196: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 893 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3643 "C_grammar.tab.c"
    break;

  case 197: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 903 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3653 "C_grammar.tab.c"
    break;

  case 198: /* parameter_type_list: parameter_list  */
#line 909 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3663 "C_grammar.tab.c"
    break;

  case 200: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 919 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3674 "C_grammar.tab.c"
    break;

  case 201: /* parameter_declaration: declaration_specifiers declarator  */
#line 929 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3685 "C_grammar.tab.c"
    break;

  case 202: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 936 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3696 "C_grammar.tab.c"
    break;

  case 203: /* parameter_declaration: declaration_specifiers  */
#line 943 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3706 "C_grammar.tab.c"
    break;

  case 206: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 956 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3712 "C_grammar.tab.c"
    break;

  case 207: /* type_name: specifier_qualifier_list  */
#line 958 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3722 "C_grammar.tab.c"
    break;

  case 232: /* initializer: '{' initializer_list '}'  */
#line 997 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3732 "C_grammar.tab.c"
    break;

  case 233: /* initializer: '{' initializer_list ',' '}'  */
#line 1003 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "trailing_comma_initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3742 "C_grammar.tab.c"
    break;

  case 235: /* initializer_list: designation initializer  */
#line 1013 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3753 "C_grammar.tab.c"
    break;

  case 237: /* initializer_list: initializer_list ',' designation initializer  */
#line 1021 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3765 "C_grammar.tab.c"
    break;

  case 238: /* initializer_list: initializer_list ',' initializer  */
#line 1029 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3776 "C_grammar.tab.c"
    break;

  case 239: /* designation: designator_list '='  */
#line 1039 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3786 "C_grammar.tab.c"
    break;

  case 241: /* designator_list: designator_list designator  */
#line 1049 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3797 "C_grammar.tab.c"
    break;

  case 242: /* designator: '[' constant_expression ']'  */
#line 1059 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 3803 "C_grammar.tab.c"
    break;

  case 243: /* designator: '.' IDENTIFIER  */
#line 1061 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3813 "C_grammar.tab.c"
    break;

  case 244: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1070 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 3824 "C_grammar.tab.c"
    break;

  case 251: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1089 "C_grammar.y"
          {size_t const size = strlen("label_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "label_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3835 "C_grammar.tab.c"
    break;

  case 252: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1096 "C_grammar.y"
          {size_t const size = strlen("case_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "case_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[0].id));
	  }
#line 3846 "C_grammar.tab.c"
    break;

  case 253: /* labeled_statement: DEFAULT ':' statement  */
#line 1103 "C_grammar.y"
          {size_t const size = strlen("default_stmt(, )") + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "default_stmt(%s)", (yyvsp[0].id));
	   free((yyvsp[0].id));
	  }
#line 3856 "C_grammar.tab.c"
    break;

  case 254: /* compound_statement: '{' '}'  */
#line 1111 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncmp_stmts([])");}
#line 3862 "C_grammar.tab.c"
    break;

  case 255: /* compound_statement: '{' block_item_list '}'  */
#line 1113 "C_grammar.y"
          {size_t const size = strlen("\ncmp_stmts([\n])") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ncmp_stmts([%s\n])", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 3872 "C_grammar.tab.c"
    break;

  case 257: /* block_item_list: block_item_list block_item  */
#line 1123 "C_grammar.y"
          {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
	  }
#line 3883 "C_grammar.tab.c"
    break;

  case 260: /* expression_statement: ';'  */
#line 1137 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "stmt([])");}
#line 3889 "C_grammar.tab.c"
    break;

  case 261: /* expression_statement: expression ';'  */
#line 1139 "C_grammar.y"
                {size_t const size = strlen("\nstmt()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nstmt(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3899 "C_grammar.tab.c"
    break;

  case 262: /* selection_statement: IF '(' expression ')' statement else_opt  */
#line 1148 "C_grammar.y"
                {size_t const size = strlen("\nif_stmt(branch(, ),  )") + MAX_BRANCH_STR + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nif_stmt(branch(%d, %s), %s %s)", branch_nb++, (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3911 "C_grammar.tab.c"
    break;

  case 263: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1156 "C_grammar.y"
                {size_t const size = strlen("\nswitch_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nswitch_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3922 "C_grammar.tab.c"
    break;

  case 264: /* else_opt: %empty  */
#line 1165 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "");}
#line 3928 "C_grammar.tab.c"
    break;

  case 265: /* else_opt: ELSE statement  */
#line 1167 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3938 "C_grammar.tab.c"
    break;

  case 266: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1175 "C_grammar.y"
                {size_t const size = strlen("\nwhile_stmt(branch(, ), )") + MAX_BRANCH_STR + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nwhile_stmt(branch(%d, %s), %s)", branch_nb++, (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3949 "C_grammar.tab.c"
    break;

  case 267: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1182 "C_grammar.y"
                {size_t const size = strlen("\ndo_while_stmt(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\ndo_while_stmt(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 3960 "C_grammar.tab.c"
    break;

  case 268: /* iteration_statement: FOR '(' for_stmt_type ')' statement  */
#line 1189 "C_grammar.y"
                {size_t const size = strlen("\nfor_stmt(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "\nfor_stmt(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3971 "C_grammar.tab.c"
    break;

  case 269: /* for_stmt_type: expression_statement expression_statement expression_opt  */
#line 1199 "C_grammar.y"
          {size_t const size = strlen(",  ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) +1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s %s", (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
	  }
#line 3983 "C_grammar.tab.c"
    break;

  case 270: /* for_stmt_type: declaration expression_statement expression_opt  */
#line 1207 "C_grammar.y"
          {size_t const size = strlen(",  ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "%s, %s %s", (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
	  }
#line 3995 "C_grammar.tab.c"
    break;

  case 271: /* expression_opt: %empty  */
#line 1217 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "");}
#line 4001 "C_grammar.tab.c"
    break;

  case 272: /* expression_opt: expression  */
#line 1219 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, ", %s", (yyvsp[0].id));
	     free((yyvsp[0].id));
	    }
#line 4011 "C_grammar.tab.c"
    break;

  case 273: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1227 "C_grammar.y"
          {size_t const size = strlen("\ngoto_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\ngoto_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4021 "C_grammar.tab.c"
    break;

  case 274: /* jump_statement: CONTINUE ';'  */
#line 1232 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\ncontinue_stmt\n");}
#line 4027 "C_grammar.tab.c"
    break;

  case 275: /* jump_statement: BREAK ';'  */
#line 1233 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "\nbreak_stmt\n");}
#line 4033 "C_grammar.tab.c"
    break;

  case 276: /* jump_statement: RETURN ';'  */
#line 1234 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "\nreturn_stmt\n");}
#line 4039 "C_grammar.tab.c"
    break;

  case 277: /* jump_statement: RETURN expression ';'  */
#line 1236 "C_grammar.y"
          {size_t const size = strlen("\nreturn_stmt()\n") + strlen((yyvsp[-1].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_safe((yyval.id), size, "\nreturn_stmt(%s)\n", (yyvsp[-1].id));
	   free((yyvsp[-1].id));
	  }
#line 4049 "C_grammar.tab.c"
    break;

  case 279: /* $@2: %empty  */
#line 1246 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4055 "C_grammar.tab.c"
    break;

  case 281: /* external_declaration: function_definition  */
#line 1250 "C_grammar.y"
                                {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4061 "C_grammar.tab.c"
    break;

  case 282: /* external_declaration: declaration  */
#line 1251 "C_grammar.y"
                                        {fprintf(pl_file, "%s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4067 "C_grammar.tab.c"
    break;

  case 283: /* function_definition: declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 1256 "C_grammar.y"
                {size_t const size = strlen("function([], , [], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function([%s], %s, [%s], %s)", (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4080 "C_grammar.tab.c"
    break;

  case 284: /* declaration_list_opt: %empty  */
#line 1267 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "");}
#line 4086 "C_grammar.tab.c"
    break;

  case 287: /* declaration_list: declaration_list declaration  */
#line 1274 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4097 "C_grammar.tab.c"
    break;


#line 4101 "C_grammar.tab.c"

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

#line 1282 "C_grammar.y"

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
				debugMode = 1;	//we are in debug mode : will affect output of warnings amongst other things
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
    if (access_safe(i_file_uri, 0) != -1) remove(i_file_uri);
  }
  if (exit_code == EXIT_SUCCESS) fprintf(stderr, "Sikraken parsing SUCCESS, wrote %s\n", pl_file_uri);
  exit(exit_code);
}

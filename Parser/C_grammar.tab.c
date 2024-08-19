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
#line 5 "C_grammar.y"

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

int debugMode = 0;				//flag to indicate if we are in debug mode set by by -d command line switch
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


#line 121 "C_grammar.tab.c"

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
#line 55 "C_grammar.y"

	char* id;

#line 249 "C_grammar.tab.c"

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
  YYSYMBOL_176_2 = 176,                    /* $@2  */
  YYSYMBOL_177_3 = 177,                    /* $@3  */
  YYSYMBOL_178_4 = 178,                    /* $@4  */
  YYSYMBOL_compound_statement = 179,       /* compound_statement  */
  YYSYMBOL_180_5 = 180,                    /* $@5  */
  YYSYMBOL_block_item_list = 181,          /* block_item_list  */
  YYSYMBOL_182_6 = 182,                    /* $@6  */
  YYSYMBOL_block_item = 183,               /* block_item  */
  YYSYMBOL_expression_statement = 184,     /* expression_statement  */
  YYSYMBOL_selection_statement = 185,      /* selection_statement  */
  YYSYMBOL_186_7 = 186,                    /* $@7  */
  YYSYMBOL_187_8 = 187,                    /* $@8  */
  YYSYMBOL_else_opt = 188,                 /* else_opt  */
  YYSYMBOL_189_9 = 189,                    /* $@9  */
  YYSYMBOL_iteration_statement = 190,      /* iteration_statement  */
  YYSYMBOL_191_10 = 191,                   /* $@10  */
  YYSYMBOL_192_11 = 192,                   /* $@11  */
  YYSYMBOL_193_12 = 193,                   /* $@12  */
  YYSYMBOL_194_13 = 194,                   /* $@13  */
  YYSYMBOL_for_stmt_type = 195,            /* for_stmt_type  */
  YYSYMBOL_196_14 = 196,                   /* $@14  */
  YYSYMBOL_197_15 = 197,                   /* $@15  */
  YYSYMBOL_expression_opt = 198,           /* expression_opt  */
  YYSYMBOL_jump_statement = 199,           /* jump_statement  */
  YYSYMBOL_translation_unit = 200,         /* translation_unit  */
  YYSYMBOL_201_16 = 201,                   /* $@16  */
  YYSYMBOL_external_declaration = 202,     /* external_declaration  */
  YYSYMBOL_function_definition = 203,      /* function_definition  */
  YYSYMBOL_204_17 = 204,                   /* $@17  */
  YYSYMBOL_205_18 = 205,                   /* $@18  */
  YYSYMBOL_declaration_list_opt = 206,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 207,         /* declaration_list  */
  YYSYMBOL_208_19 = 208                    /* $@19  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   2157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  303
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  492

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
       0,    98,    98,   112,   113,   114,   120,   124,   125,   126,
     130,   135,   136,   140,   144,   145,   149,   150,   154,   156,
     163,   169,   176,   183,   190,   196,   202,   209,   219,   220,
     230,   231,   238,   245,   251,   257,   266,   267,   271,   272,
     273,   274,   275,   276,   280,   281,   291,   292,   303,   304,
     305,   309,   310,   321,   322,   326,   327,   338,   339,   343,
     344,   355,   356,   357,   358,   363,   364,   375,   376,   380,
     381,   391,   392,   402,   403,   413,   414,   424,   425,   435,
     436,   447,   448,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   473,   474,   484,   488,   492,   500,
     507,   514,   516,   523,   525,   527,   529,   531,   533,   535,
     540,   541,   551,   558,   567,   571,   572,   573,   574,   575,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   598,   605,   613,   623,
     624,   628,   630,   640,   646,   646,   654,   659,   666,   668,
     675,   680,   682,   692,   698,   705,   710,   716,   722,   729,
     736,   745,   747,   757,   764,   769,   773,   774,   775,   776,
     780,   781,   785,   786,   790,   797,   802,   816,   818,   820,
     822,   824,   826,   828,   830,   832,   834,   836,   842,   850,
     855,   862,   868,   874,   879,   881,   891,   897,   906,   908,
     918,   925,   932,   941,   942,   946,   947,   951,   952,   953,
     957,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   968,   969,   970,   971,   972,   973,   974,   975,   976,
     977,   981,   987,   993,   998,  1005,  1007,  1015,  1025,  1034,
    1036,  1046,  1048,  1057,  1067,  1068,  1069,  1070,  1071,  1072,
    1077,  1076,  1082,  1082,  1083,  1083,  1087,  1089,  1088,  1098,
    1099,  1099,  1103,  1104,  1108,  1109,  1114,  1113,  1121,  1120,
    1130,  1131,  1131,  1135,  1134,  1141,  1141,  1142,  1142,  1142,
    1146,  1146,  1147,  1147,  1151,  1152,  1155,  1156,  1157,  1158,
    1159,  1164,  1165,  1165,  1169,  1170,  1175,  1180,  1174,  1187,
    1188,  1192,  1193,  1193
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
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
  "static_assert_declaration", "statement", "labeled_statement", "$@2",
  "$@3", "$@4", "compound_statement", "$@5", "block_item_list", "$@6",
  "block_item", "expression_statement", "selection_statement", "$@7",
  "$@8", "else_opt", "$@9", "iteration_statement", "$@10", "$@11", "$@12",
  "$@13", "for_stmt_type", "$@14", "$@15", "expression_opt",
  "jump_statement", "translation_unit", "$@16", "external_declaration",
  "function_definition", "$@17", "$@18", "declaration_list_opt",
  "declaration_list", "$@19", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-320)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-301)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1876,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,    33,   -54,  2085,  -320,  -320,
     -10,  -320,  -320,    41,  1981,  1981,  -320,    46,  -320,  -320,
    1981,  1981,  1981,  -320,    48,  -320,  -320,   -32,    87,   785,
    2085,    78,  2085,    37,  1442,  -320,    42,   145,  -320,   -30,
    -320,   -34,    66,    44,  -320,  -320,    12,   706,  -320,  -320,
    -320,  -320,  1876,    87,  -320,    11,   -49,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  1465,  -320,  -320,    45,    68,   785,
    -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
     142,  -320,  1488,  1442,  -320,   108,    -1,   162,    40,   209,
      72,    75,    93,   144,    18,  -320,   119,   128,  -320,  1613,
     808,    69,  -320,    91,  -320,  -320,   134,   140,  -320,  -320,
     145,    42,  -320,  1306,  1876,  1772,   898,    66,   706,  1665,
    -320,   120,  -320,  -320,    52,  1442,    17,  -320,   785,  -320,
    2085,  1442,   307,  -320,  -320,   157,   146,   220,  -320,  -320,
    1329,  1442,   228,   785,  -320,  -320,  -320,  -320,  -320,  1442,
    -320,  -320,  1442,  -320,  -320,  1442,  -320,  -320,  -320,  -320,
    1442,  -320,  -320,  1442,  1442,  1442,  1442,  1442,  1442,  1442,
    -320,  -320,  -320,    55,   180,   161,  -320,   182,  1080,  -320,
     181,   184,   921,    91,  1824,   944,   261,  -320,  -320,  -320,
    -320,   171,  1216,  -320,  -320,  -320,    41,  -320,   190,  -320,
    -320,   200,   160,  1080,  -320,   203,   204,  1034,  1717,  -320,
    -320,  -320,    14,    27,  -320,  -320,  -320,  -320,   202,   210,
     208,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  1442,  -320,  1442,  1352,  -320,  -320,   163,  -320,
     106,  -320,   211,  -320,   108,    -1,   162,    40,   209,    72,
      75,    93,   144,   165,  1556,  -320,    67,  -320,  -320,  1928,
    -320,   213,  1080,  -320,  -320,  1442,  -320,   214,  -320,   212,
    1080,  -320,   216,   219,  1057,   226,  1442,   290,  -320,    82,
    1306,   -20,  -320,   221,  1876,  -320,  -320,   304,   227,  1080,
    -320,  -320,  1442,  -320,   229,   230,  -320,  1442,   -25,  -320,
     233,  -320,   224,  -320,  2033,  -320,  -320,  1216,  -320,  -320,
    1442,  -320,   224,  1442,  -320,  -320,  -320,   232,   234,  -320,
    -320,   239,  1080,  -320,  -320,  1442,  -320,   241,   238,   258,
    -320,  1170,  -320,  -320,  -320,  -320,   225,  -320,  -320,  -320,
    -320,   260,   266,  -320,  -320,  -320,    14,  -320,  1442,   263,
     169,  -320,   271,   107,  -320,  -320,  -320,  -320,  -320,   270,
     272,  -320,  -320,  -320,  -320,  -320,  1306,  -320,   462,  -320,
    -320,  -320,  -320,  1442,  -320,  2033,  1442,  1193,  -320,  -320,
    -320,  -320,   273,  1442,   275,   279,   281,   282,  -320,   283,
     360,   264,   265,   642,  -320,   -19,  -320,  -320,  -320,  -320,
     278,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,   286,  -320,  1442,  1442,  1442,   605,  -320,   267,  -320,
    -320,  -320,   -17,  -320,  -320,   462,   605,  -320,   605,   172,
     174,   194,   308,   552,  -320,  -320,  -320,  -320,   605,  -320,
    -320,  -320,  -320,   291,  -320,  -320,   293,  -320,   605,   605,
     605,  1442,   695,   695,  -320,   313,  -320,  -320,   198,  1442,
    1442,   605,  -320,  -320,   274,   294,  -320,  -320,  -320,   605,
    -320,  -320
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   135,   114,   115,   116,   118,   119,   170,   166,   167,
     168,   129,   121,   122,   123,   124,   127,   128,   125,   126,
     120,   130,   131,   139,   140,     0,     0,     0,   169,   171,
       0,   117,   295,     0,   101,   103,   133,     0,   134,   132,
     105,   107,   109,    99,   292,   291,   294,   160,     0,     0,
     148,   206,   150,     0,     0,   176,     0,   193,    97,     0,
     110,   296,   175,     0,   100,   102,   138,     0,   104,   106,
     108,     1,     0,     0,    10,   164,     0,   161,     2,     7,
       8,     9,    11,    12,     0,    36,    37,     0,     0,     0,
      38,    39,    40,    41,    42,    43,    18,     3,     4,     6,
      30,    44,     0,     0,    46,    51,    55,    59,    65,    69,
      71,    73,    75,    77,    79,    96,     0,     0,   147,     0,
       0,   208,   205,   209,   149,   165,     0,     0,   194,   192,
     191,     0,    98,     0,   299,     0,     0,   174,     0,     0,
     141,   144,   146,   293,     0,     0,     0,   156,     0,    33,
       0,     0,    44,    81,    94,     0,     0,     0,    24,    25,
       0,     0,     0,     0,    31,    32,    48,    49,    50,     0,
      53,    54,     0,    57,    58,     0,    63,    64,    61,    62,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
     173,   172,   227,   202,     0,   197,   198,     0,     0,   211,
      39,     0,     0,   207,     0,     0,     0,   177,   195,   190,
     111,   113,     0,   233,   112,   301,     0,   297,   302,   203,
     187,     0,     0,     0,   178,    39,     0,     0,     0,   136,
     142,   143,     0,     0,   158,   163,   157,   162,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    83,     0,     5,     0,     0,    23,    20,     0,    28,
       0,    22,     0,    47,    52,    56,    60,    66,    70,    72,
      74,    76,    78,     0,     0,   200,   208,   201,   228,     0,
     210,     0,     0,   212,   218,     0,   217,     0,   229,     0,
       0,   219,    39,     0,     0,     0,     0,     0,   235,     0,
       0,     0,   239,     0,     0,   188,   189,     0,     0,     0,
     179,   186,     0,   185,    39,     0,   137,     0,     0,   151,
     155,   159,    34,    35,     0,    82,    95,     0,    45,    21,
       0,    19,     0,     0,   196,   199,   214,     0,     0,   216,
     230,     0,     0,   220,   226,     0,   225,     0,     0,     0,
     242,     0,   231,   234,   238,   240,   257,   298,   303,   204,
     181,     0,     0,   182,   184,   153,     0,   145,     0,     0,
       0,    14,     0,     0,    29,    80,   213,   215,   222,     0,
       0,   223,   243,   241,   232,   237,     0,   256,     0,   180,
     183,   152,   154,     0,    13,     0,     0,     0,    26,   221,
     224,   236,     2,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,     0,   264,     0,   262,   263,   244,   245,
     260,   259,   246,   247,   248,   249,    17,    15,    16,    27,
     250,     0,   254,     0,     0,     0,     0,   277,     0,   287,
     288,   289,     0,   265,   258,     0,     0,   252,     0,     0,
       0,     0,     0,     0,   286,   290,   261,   251,     0,   255,
     266,   268,   273,     0,   282,   280,     0,   253,     0,     0,
       0,     0,     0,     0,   278,   270,   269,   274,     0,   284,
     284,     0,   271,   267,     0,   285,   283,   281,   279,     0,
     276,   272
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -320,  -320,  -320,  -320,  -320,  -320,  -320,   -18,  -320,  -320,
      25,  -320,  -320,   -92,   207,  -320,   201,  -320,   205,  -320,
     197,  -320,   215,  -320,   199,   196,   217,   206,  -320,   -41,
      96,  -320,   -88,   -52,  -125,     0,  -320,   256,  -320,     2,
    -320,  -320,   251,  -120,  -320,   -40,  -320,    29,  -320,   325,
    -123,  -320,   -24,  -320,  -320,   -26,   -58,   -36,   -98,  -117,
    -320,   121,  -320,    32,   -35,  -115,  -129,    74,  -319,  -320,
     101,   -53,  -186,  -320,  -320,  -320,  -320,   100,  -320,  -320,
    -320,   -39,  -238,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,  -320,   -71,  -320,  -320,  -320,
     338,  -320,  -320,  -320,  -320,  -320,  -320
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    96,    97,    75,    98,    99,   370,   371,   100,   258,
     152,   102,   103,   104,   105,   169,   106,   172,   107,   175,
     108,   180,   109,   183,   110,   111,   112,   113,   114,   153,
     154,   252,   415,   116,    32,   193,    59,    60,    34,    35,
      36,    37,   139,   140,   232,    51,   318,   319,    38,    76,
      77,    39,    40,    41,    42,   127,    62,    63,   130,   194,
     195,   196,   222,   372,   197,   123,   298,   299,   300,   301,
     302,    43,   417,   418,   446,   458,   448,   419,   388,   420,
     445,   421,   422,   423,   468,   469,   483,   489,   424,   470,
     436,   453,   481,   466,   473,   472,   486,   425,    44,    72,
      45,    46,   134,   303,   217,   218,   304
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   155,   126,    52,   214,   137,   203,    61,   115,   215,
     118,   165,   124,   115,   142,   121,   122,    55,   221,   230,
      74,   129,   202,   237,    49,    52,    52,   141,    52,    50,
      74,   146,   386,   128,    64,    65,    47,   147,   227,   188,
      68,    69,    70,    52,    55,    55,  -113,    55,    71,    66,
     131,    50,    50,    73,    50,   366,   176,   177,    55,    53,
     155,   254,   296,   254,   297,    52,   133,  -113,    54,    50,
      55,   132,    33,   260,   101,   155,   367,   263,   386,   101,
     354,   117,   443,   121,   455,   142,   142,   289,   170,   171,
      74,    50,    56,   235,   209,   317,   128,   138,   141,   141,
     282,   273,    57,   236,   115,   211,   208,   294,   230,   149,
     237,   145,   128,   321,    52,    52,   125,   189,    48,    56,
      56,   156,    56,   150,    52,   309,    52,   164,   101,    57,
      57,    67,   233,   274,   216,   178,   179,   120,   234,    52,
      50,    50,    58,    57,   135,   274,   151,   119,   136,   120,
      50,   120,    50,   157,   158,   159,   119,   276,   277,   184,
     120,   203,   351,   328,   187,    50,    57,   275,   352,   204,
     101,   353,   185,   205,   128,   142,   173,   174,   208,   358,
     238,   128,   239,     8,     9,    10,   254,   397,   141,   331,
     211,   186,   342,   398,   101,   262,   166,   101,   190,   128,
     101,   167,   168,   208,    52,   101,   320,   191,   101,   101,
     101,   101,   101,   101,   206,   465,   201,    28,   137,   207,
     160,   231,   385,   256,   161,   255,   162,   181,   182,   213,
      50,   261,   226,    57,   479,   480,   253,   254,   276,   306,
     307,   279,   329,   330,   349,   254,   333,   240,   394,   395,
     452,   460,   254,   461,   254,   115,   259,   401,   208,   278,
     457,   280,   459,   416,   283,   365,   128,   284,   385,   295,
     208,   133,   467,   462,   254,  -300,   115,   484,   254,   305,
     101,   322,   475,   476,   477,   208,   310,   311,   324,   323,
     332,   340,   375,   350,   281,   488,   336,   339,   287,   343,
      52,   293,   344,   491,   216,   348,   356,   359,   213,   327,
     360,   387,   363,   364,   368,   376,   392,   377,   208,   308,
     416,   101,   378,   315,   381,   442,    50,   115,   464,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   382,
     320,   383,   101,   389,   393,   449,   450,   451,   325,   390,
     326,   431,   396,   399,   430,   400,   432,   433,   101,   434,
     435,   437,   115,   438,   444,   439,   440,   447,   454,   471,
     463,    52,   474,   482,   254,   490,   265,   427,   337,   264,
     267,   338,   270,   478,   269,   266,   341,   210,   216,   228,
     347,   485,   485,   101,   272,   391,   213,    50,   144,   268,
     335,   373,   355,   357,   271,   361,   456,   251,   362,   487,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,     0,   374,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   379,     0,
       0,   380,     0,     0,     0,   216,     0,   213,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,     1,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,     0,   213,     0,     0,     0,     0,     0,     0,   426,
       0,     0,   428,   213,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,   403,
     404,   405,     0,   406,   407,   408,   409,   410,   411,   412,
     413,    26,    87,    27,    28,    88,    29,    30,    31,     0,
      89,     0,     0,     0,     0,     0,     0,   356,     0,    90,
      91,    92,    93,    94,    95,    78,     1,    79,    80,    81,
      82,    83,    84,   414,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   402,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,    26,    87,    27,    28,    88,    29,    30,    31,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    78,     0,    79,    80,    81,
      82,    83,    84,   414,    85,    86,     0,     0,     0,     0,
       0,     0,   403,   404,   405,     0,   406,   407,   408,   409,
     410,   411,   412,   413,     0,    87,     0,     0,    88,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
     356,     0,    90,    91,    92,    93,    94,    95,    78,     0,
      79,    80,    81,    82,    83,    84,   414,    85,    86,     0,
       1,     0,    87,     0,     0,    88,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,   441,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,    87,     0,     0,    88,     0,
       0,     0,     0,    89,     0,     0,     0,    27,    28,     0,
       0,    30,    90,    91,    92,    93,    94,    95,    78,     1,
      79,    80,    81,    82,    83,    84,   414,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,   198,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,    87,    27,    28,    88,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    87,     0,
      28,    88,     0,     0,     0,     0,    89,     0,     0,     0,
       0,   199,     0,     0,     0,    90,   200,    92,    93,    94,
      95,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,    79,    80,    81,    82,
      83,    84,   223,    85,    86,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,    84,   285,    85,    86,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    87,     0,
      28,    88,     0,     0,     0,     0,    89,     0,   290,     0,
       0,   224,     8,     9,    10,    90,   225,    92,    93,    94,
      95,    87,     0,    28,    88,     0,     0,     0,     0,    89,
       0,     0,     0,     0,   286,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    87,     0,    28,    88,     0,     0,
       0,     0,    89,     0,     0,     0,     0,   291,     0,     0,
       0,    90,   292,    92,    93,    94,    95,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,   312,    85,
      86,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,   345,    85,    86,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    87,     0,    28,    88,     0,     0,
       0,     0,    89,     0,     0,     0,     0,   313,     8,     9,
      10,    90,   314,    92,    93,    94,    95,    87,     0,    28,
      88,     0,     0,     0,     0,    89,     0,     0,     0,     0,
     346,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      87,     0,    28,    88,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    78,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,    79,    80,    81,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,    88,     0,     0,     0,     0,    89,     0,
       0,     0,   296,     0,   297,   212,   384,    90,    91,    92,
      93,    94,    95,    87,     0,     0,    88,     0,     0,     0,
       0,    89,     0,     0,     0,   296,     0,   297,   212,   429,
      90,    91,    92,    93,    94,    95,    87,     0,     0,    88,
       0,     0,     0,     0,    89,     0,     0,     0,   296,     0,
     297,   212,     0,    90,    91,    92,    93,    94,    95,    78,
       0,    79,    80,    81,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,     0,    88,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,   212,     0,    90,    91,    92,    93,    94,    95,    87,
       0,     0,    88,     0,     0,     0,     0,    89,   257,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    87,     0,     0,    88,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,   327,     0,    90,
      91,    92,    93,    94,    95,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,    88,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    87,     0,     0,    88,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    87,    55,
       1,    88,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,     0,    31,     0,   274,   192,     0,     0,   120,     0,
       0,     0,     0,     0,    57,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,     0,    29,     0,    31,
       0,   119,   192,     0,     0,   120,     0,     0,     0,     0,
       0,    57,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,   219,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   316,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,     0,
       0,   220,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,    28,     0,    29,     0,
      31,     0,     0,   288,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,    28,     0,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   334,     1,     0,     0,     0,     0,
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
       0,   369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28
};

static const yytype_int16 yycheck[] =
{
       0,    89,    54,    27,   133,    63,   121,    33,    49,   134,
      50,   103,    52,    54,    67,    51,    51,     3,   135,   139,
       3,    57,   120,   146,    78,    49,    50,    67,    52,    27,
       3,    80,   351,    57,    34,    35,     3,    86,   136,    21,
      40,    41,    42,    67,     3,     3,    80,     3,     0,     3,
      80,    49,    50,    85,    52,    80,    16,    17,     3,    27,
     148,    80,    82,    80,    84,    89,   100,   101,    78,    67,
       3,   101,    72,   161,    49,   163,   101,   169,   397,    54,
     100,    49,   101,   119,   101,   138,   139,   204,    89,    90,
       3,    89,    78,   145,   130,    81,   120,    85,   138,   139,
     198,   189,    88,    86,   145,   131,   130,   205,   228,    84,
     233,   100,   136,    86,   138,   139,    79,    99,    85,    78,
      78,    89,    78,    78,   148,   223,   150,   102,   103,    88,
      88,    85,    80,    78,   134,    95,    96,    82,    86,   163,
     138,   139,   101,    88,    78,    78,    78,    78,    82,    82,
     148,    82,   150,    11,    12,    13,    78,   193,   193,    87,
      82,   276,    80,   255,    20,   163,    88,   193,    86,    78,
     145,   300,    97,    82,   198,   228,    14,    15,   202,   304,
     148,   205,   150,    38,    39,    40,    80,    80,   228,    83,
     216,    98,   290,    86,   169,   163,    88,   172,    79,   223,
     175,    93,    94,   227,   228,   180,   232,    79,   183,   184,
     185,   186,   187,   188,    80,   453,   120,    72,   276,    79,
      78,   101,   351,     3,    82,    79,    84,    18,    19,   133,
     228,     3,   136,    88,   472,   473,    79,    80,   274,    79,
      80,    80,    79,    80,   296,    80,    81,   151,    79,    80,
     436,    79,    80,    79,    80,   296,   160,   386,   282,    79,
     446,    79,   448,   388,    83,   317,   290,    83,   397,     8,
     294,   100,   458,    79,    80,    85,   317,    79,    80,    79,
     255,    79,   468,   469,   470,   309,    83,    83,    80,    79,
      79,    79,   333,     3,   198,   481,    83,    83,   202,    83,
     324,   205,    83,   489,   304,    79,    85,     3,   212,    85,
      83,    86,    83,    83,    81,    83,   368,    83,   342,   223,
     445,   296,    83,   227,    83,   413,   324,   368,   453,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   101,
     366,    83,   317,    83,    81,   433,   434,   435,   252,    83,
     254,   403,    81,    83,    81,    83,    81,    78,   333,    78,
      78,    78,   403,     3,    86,   101,   101,    81,   101,    78,
      62,   395,    79,    60,    80,   101,   175,   395,   282,   172,
     183,   285,   186,   471,   185,   180,   290,   131,   388,   138,
     294,   479,   480,   368,   188,   366,   300,   395,    73,   184,
     279,   327,   301,   303,   187,   309,   445,   100,   312,   480,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,    -1,    -1,   330,    -1,   403,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,    -1,
      -1,   345,    -1,    -1,    -1,   445,    -1,   351,    -1,    -1,
      -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,   386,    -1,    -1,    -1,    -1,    -1,    -1,   393,
      -1,    -1,   396,   397,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,
      88,    89,    90,    91,    92,     3,     4,     5,     6,     7,
       8,     9,    10,   101,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,     3,    -1,     5,     6,     7,
       8,     9,    10,   101,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    91,    92,     3,    -1,
       5,     6,     7,     8,     9,    10,   101,    12,    13,    -1,
       4,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    87,    88,    89,    90,    91,    92,     3,     4,
       5,     6,     7,     8,     9,    10,   101,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    70,    -1,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      92,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    34,    12,    13,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    34,    12,    13,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    34,    -1,
      -1,    83,    38,    39,    40,    87,    88,    89,    90,    91,
      92,    70,    -1,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    70,    -1,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    34,    12,
      13,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    34,    12,    13,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    38,    39,
      40,    87,    88,    89,    90,    91,    92,    70,    -1,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      70,    -1,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    82,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    87,    88,    89,    90,    91,    92,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,
      88,    89,    90,    91,    92,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    70,     3,
       4,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      74,    -1,    76,    -1,    78,    79,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    88,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,
      -1,    78,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    38,    39,    40,    41,    42,
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
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,   136,   137,   140,   141,   142,   143,   150,   153,
     154,   155,   156,   173,   200,   202,   203,     3,    85,    78,
     141,   147,   154,   165,    78,     3,    78,    88,   101,   138,
     139,   157,   158,   159,   137,   137,     3,    85,   137,   137,
     137,     0,   201,    85,     3,   105,   151,   152,     3,     5,
       6,     7,     8,     9,    10,    12,    13,    70,    73,    78,
      87,    88,    89,    90,    91,    92,   103,   104,   106,   107,
     110,   112,   113,   114,   115,   116,   118,   120,   122,   124,
     126,   127,   128,   129,   130,   131,   135,   165,   147,    78,
      82,   159,   166,   167,   147,    79,   135,   157,   154,   159,
     160,    80,   101,   100,   204,    78,    82,   158,    85,   144,
     145,   147,   173,   202,   151,   100,    80,    86,    78,   112,
      78,    78,   112,   131,   132,   134,   165,    11,    12,    13,
      78,    82,    84,    78,   112,   115,    88,    93,    94,   117,
      89,    90,   119,    14,    15,   121,    16,    17,    95,    96,
     123,    18,    19,   125,    87,    97,    98,    20,    21,    99,
      79,    79,    79,   137,   161,   162,   163,   166,    34,    83,
      88,   132,   160,   167,    78,    82,    80,    79,   154,   159,
     139,   157,    85,   132,   168,   136,   137,   206,   207,     3,
      79,   161,   164,    34,    83,    88,   132,   160,   144,    86,
     145,   101,   146,    80,    86,   135,    86,   152,   165,   165,
     132,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   100,   133,    79,    80,    79,     3,    79,   111,   132,
     134,     3,   165,   115,   116,   118,   120,   122,   124,   126,
     127,   128,   129,   134,    78,   157,   159,   166,    79,    80,
      79,   132,   160,    83,    83,    34,    83,   132,    79,   161,
      34,    83,    88,   132,   160,     8,    82,    84,   168,   169,
     170,   171,   172,   205,   208,    79,    79,    80,   132,   160,
      83,    83,    34,    83,    88,   132,    86,    81,   148,   149,
     157,    86,    79,    79,    80,   132,   132,    85,   115,    79,
      80,    83,    79,    81,    56,   163,    83,   132,   132,    83,
      79,   132,   160,    83,    83,    34,    83,   132,    79,   135,
       3,    80,    86,   168,   100,   172,    85,   179,   136,     3,
      83,   132,   132,    83,    83,   135,    80,   101,    81,    58,
     108,   109,   165,   169,   132,   131,    83,    83,    83,   132,
     132,    83,   101,    83,    86,   168,   170,    86,   180,    83,
      83,   149,   135,    81,    79,    80,    81,    80,    86,    83,
      83,   168,     3,    57,    58,    59,    61,    62,    63,    64,
      65,    66,    67,    68,   101,   134,   136,   174,   175,   179,
     181,   183,   184,   185,   190,   199,   132,   109,   132,    86,
      81,   135,    81,    78,    78,    78,   192,    78,     3,   101,
     101,   101,   134,   101,    86,   182,   176,    81,   178,   134,
     134,   134,   174,   193,   101,   101,   183,   174,   177,   174,
      79,    79,    79,    62,   136,   184,   195,   174,   186,   187,
     191,    78,   197,   196,    79,   174,   174,   174,   134,   184,
     184,   194,    60,   188,    79,   134,   198,   198,   174,   189,
     101,   174
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   103,   103,   103,   104,   104,   104,
     105,   106,   106,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   115,   115,   116,   116,   117,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   134,   134,   135,   136,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     138,   138,   139,   139,   140,   140,   140,   140,   140,   140,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   142,   142,   142,   143,
     143,   144,   144,   145,   146,   145,   145,   147,   147,   147,
     147,   148,   148,   149,   149,   149,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   153,   154,   154,   154,   154,
     155,   155,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     159,   159,   159,   159,   160,   160,   161,   161,   162,   162,
     163,   163,   163,   164,   164,   165,   165,   166,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   168,   168,   168,   169,   169,   169,   169,   170,   171,
     171,   172,   172,   173,   174,   174,   174,   174,   174,   174,
     176,   175,   177,   175,   178,   175,   179,   180,   179,   181,
     182,   181,   183,   183,   184,   184,   186,   185,   187,   185,
     188,   189,   188,   191,   190,   192,   190,   193,   194,   190,
     196,   195,   197,   195,   198,   198,   199,   199,   199,   199,
     199,   200,   201,   200,   202,   202,   204,   205,   203,   206,
     206,   207,   208,   207
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     2,     1,
       1,     1,     2,     2,     0,     4,     1,     2,     1,     2,
       1,     1,     3,     2,     3,     1,     4,     5,     5,     6,
       2,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     1,     1,     3,     3,     4,
       6,     5,     5,     6,     5,     4,     4,     3,     4,     4,
       3,     2,     2,     1,     1,     2,     3,     1,     1,     3,
       2,     2,     1,     1,     3,     2,     1,     2,     1,     1,
       3,     2,     3,     5,     4,     5,     4,     3,     3,     3,
       4,     6,     5,     5,     6,     4,     4,     2,     3,     3,
       4,     3,     4,     1,     2,     1,     4,     3,     2,     1,
       2,     3,     2,     7,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     5,     0,     4,     2,     0,     4,     1,
       0,     3,     1,     1,     1,     2,     0,     7,     0,     6,
       0,     0,     3,     0,     6,     0,     8,     0,     0,     7,
       0,     4,     0,     4,     0,     1,     3,     2,     2,     2,
       3,     1,     0,     3,     1,     1,     0,     0,     6,     0,
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
#line 99 "C_grammar.y"
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
#line 2174 "C_grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 112 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2180 "C_grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 113 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2186 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 115 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2196 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: generic_selection  */
#line 120 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2202 "C_grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 124 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2208 "C_grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 125 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2214 "C_grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 126 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2220 "C_grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 131 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2226 "C_grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 135 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2232 "C_grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 136 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2238 "C_grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 155 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2244 "C_grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 157 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2255 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 164 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2265 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 170 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2276 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 177 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2287 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 184 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2298 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 191 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2308 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 197 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2318 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 203 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2329 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 210 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2340 "C_grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 219 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2346 "C_grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 221 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2357 "C_grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 230 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2363 "C_grammar.tab.c"
    break;

  case 31: /* unary_expression: unary_inc_dec unary_expression  */
#line 232 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2374 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_operator cast_expression  */
#line 239 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2385 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: SIZEOF unary_expression  */
#line 246 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2395 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 252 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2405 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 258 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2415 "C_grammar.tab.c"
    break;

  case 36: /* unary_inc_dec: INC_OP  */
#line 266 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2421 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: DEC_OP  */
#line 267 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2427 "C_grammar.tab.c"
    break;

  case 38: /* unary_operator: '&'  */
#line 271 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2433 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '*'  */
#line 272 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2439 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '+'  */
#line 273 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2445 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '-'  */
#line 274 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2451 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '~'  */
#line 275 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "one_comp_op");}
#line 2457 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '!'  */
#line 276 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2463 "C_grammar.tab.c"
    break;

  case 44: /* cast_expression: unary_expression  */
#line 280 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2469 "C_grammar.tab.c"
    break;

  case 45: /* cast_expression: '(' type_name ')' cast_expression  */
#line 282 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2480 "C_grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: cast_expression  */
#line 291 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2486 "C_grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 293 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2498 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression_op: '*'  */
#line 303 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2504 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '/'  */
#line 304 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2510 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '%'  */
#line 305 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2516 "C_grammar.tab.c"
    break;

  case 51: /* additive_expression: multiplicative_expression  */
#line 309 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2522 "C_grammar.tab.c"
    break;

  case 52: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 311 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2534 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression_op: '+'  */
#line 321 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2540 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '-'  */
#line 322 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2546 "C_grammar.tab.c"
    break;

  case 55: /* shift_expression: additive_expression  */
#line 326 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2552 "C_grammar.tab.c"
    break;

  case 56: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 328 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2564 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression_op: LEFT_OP  */
#line 338 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift_op");}
#line 2570 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: RIGHT_OP  */
#line 339 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift_op");}
#line 2576 "C_grammar.tab.c"
    break;

  case 59: /* relational_expression: shift_expression  */
#line 343 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2582 "C_grammar.tab.c"
    break;

  case 60: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 345 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2594 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression_operator: '<'  */
#line 355 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2600 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '>'  */
#line 356 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2606 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: LE_OP  */
#line 357 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2612 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: GE_OP  */
#line 358 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2618 "C_grammar.tab.c"
    break;

  case 65: /* equality_expression: relational_expression  */
#line 363 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2624 "C_grammar.tab.c"
    break;

  case 66: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 365 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2636 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression_op: EQ_OP  */
#line 375 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2642 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: NE_OP  */
#line 376 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2648 "C_grammar.tab.c"
    break;

  case 69: /* and_expression: equality_expression  */
#line 380 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2654 "C_grammar.tab.c"
    break;

  case 70: /* and_expression: and_expression '&' equality_expression  */
#line 382 "C_grammar.y"
                {size_t const size = strlen("bitw_and(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitw_and(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2665 "C_grammar.tab.c"
    break;

  case 71: /* exclusive_or_expression: and_expression  */
#line 391 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2671 "C_grammar.tab.c"
    break;

  case 72: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 393 "C_grammar.y"
                {size_t const size = strlen("bitw_excl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitw_excl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2682 "C_grammar.tab.c"
    break;

  case 73: /* inclusive_or_expression: exclusive_or_expression  */
#line 402 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2688 "C_grammar.tab.c"
    break;

  case 74: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 404 "C_grammar.y"
                {size_t const size = strlen("bitw_incl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitw_incl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2699 "C_grammar.tab.c"
    break;

  case 75: /* logical_and_expression: inclusive_or_expression  */
#line 413 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2705 "C_grammar.tab.c"
    break;

  case 76: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 415 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2716 "C_grammar.tab.c"
    break;

  case 77: /* logical_or_expression: logical_and_expression  */
#line 424 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2722 "C_grammar.tab.c"
    break;

  case 78: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 426 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2733 "C_grammar.tab.c"
    break;

  case 79: /* conditional_expression: logical_or_expression  */
#line 435 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2739 "C_grammar.tab.c"
    break;

  case 80: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 437 "C_grammar.y"
                {size_t const size = strlen("cond_exp(, , )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(%s, %s, %s)", (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2751 "C_grammar.tab.c"
    break;

  case 81: /* assignment_expression: conditional_expression  */
#line 447 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2757 "C_grammar.tab.c"
    break;

  case 82: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 449 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2769 "C_grammar.tab.c"
    break;

  case 83: /* assignment_operator: '='  */
#line 459 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2775 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: MUL_ASSIGN  */
#line 460 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2781 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: DIV_ASSIGN  */
#line 461 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2787 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: MOD_ASSIGN  */
#line 462 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2793 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: ADD_ASSIGN  */
#line 463 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2799 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: SUB_ASSIGN  */
#line 464 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2805 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: LEFT_ASSIGN  */
#line 465 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2811 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: RIGHT_ASSIGN  */
#line 466 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2817 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: AND_ASSIGN  */
#line 467 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2823 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: XOR_ASSIGN  */
#line 468 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2829 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: OR_ASSIGN  */
#line 469 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2835 "C_grammar.tab.c"
    break;

  case 94: /* expression: assignment_expression  */
#line 473 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2841 "C_grammar.tab.c"
    break;

  case 95: /* expression: expression ',' assignment_expression  */
#line 475 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2852 "C_grammar.tab.c"
    break;

  case 96: /* constant_expression: conditional_expression  */
#line 484 "C_grammar.y"
                                                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2858 "C_grammar.tab.c"
    break;

  case 97: /* declaration: declaration_specifiers ';'  */
#line 489 "C_grammar.y"
                {fprintf(pl_file, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2866 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 493 "C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
	     fprintf(pl_file, "\ndeclaration([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	  }
#line 2878 "C_grammar.tab.c"
    break;

  case 99: /* declaration: static_assert_declaration  */
#line 501 "C_grammar.y"
                {fprintf(pl_file, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2886 "C_grammar.tab.c"
    break;

  case 100: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 508 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2897 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier  */
#line 515 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2903 "C_grammar.tab.c"
    break;

  case 102: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 517 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2914 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier  */
#line 524 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2920 "C_grammar.tab.c"
    break;

  case 104: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 526 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_type_qualifier, dummy_declaration_specifiers"); }
#line 2926 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier  */
#line 528 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_type_qualifier"); }
#line 2932 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 530 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); }
#line 2938 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier  */
#line 532 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); }
#line 2944 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 534 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); }
#line 2950 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier  */
#line 536 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); }
#line 2956 "C_grammar.tab.c"
    break;

  case 110: /* init_declarator_list: init_declarator  */
#line 540 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2962 "C_grammar.tab.c"
    break;

  case 111: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 542 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 2973 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator: declarator '=' initializer  */
#line 552 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	   	 //free($3);
	  	}
#line 2984 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator  */
#line 559 "C_grammar.y"
          {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name((yyvsp[0].id));
	   }
	   simple_str_copy(&(yyval.id), (yyvsp[0].id));
	  }
#line 2994 "C_grammar.tab.c"
    break;

  case 114: /* storage_class_specifier: TYPEDEF  */
#line 568 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
	    }
#line 3002 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: EXTERN  */
#line 571 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3008 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: STATIC  */
#line 572 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3014 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: THREAD_LOCAL  */
#line 573 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3020 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: AUTO  */
#line 574 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3026 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: REGISTER  */
#line 575 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3032 "C_grammar.tab.c"
    break;

  case 120: /* type_specifier: VOID  */
#line 579 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 3038 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: CHAR  */
#line 580 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 3044 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: SHORT  */
#line 581 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 3050 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: INT  */
#line 582 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 3056 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: LONG  */
#line 583 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 3062 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: FLOAT  */
#line 584 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 3068 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: DOUBLE  */
#line 585 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 3074 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: SIGNED  */
#line 586 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3080 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: UNSIGNED  */
#line 587 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3086 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: BOOL  */
#line 588 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3092 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: COMPLEX  */
#line 589 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3098 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: IMAGINARY  */
#line 590 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3104 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: atomic_type_specifier  */
#line 591 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3110 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: struct_or_union_specifier  */
#line 592 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3116 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: enum_specifier  */
#line 593 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3122 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: TYPEDEF_NAME  */
#line 594 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3128 "C_grammar.tab.c"
    break;

  case 136: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 599 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
	    }
#line 3139 "C_grammar.tab.c"
    break;

  case 137: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 606 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
	    }
#line 3151 "C_grammar.tab.c"
    break;

  case 138: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 614 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3162 "C_grammar.tab.c"
    break;

  case 139: /* struct_or_union: STRUCT  */
#line 623 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "struct");}
#line 3168 "C_grammar.tab.c"
    break;

  case 140: /* struct_or_union: UNION  */
#line 624 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "union");}
#line 3174 "C_grammar.tab.c"
    break;

  case 141: /* struct_declaration_list: struct_declaration  */
#line 629 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3180 "C_grammar.tab.c"
    break;

  case 142: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 631 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3191 "C_grammar.tab.c"
    break;

  case 143: /* struct_declaration: specifier_qualifier_list ';'  */
#line 641 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3201 "C_grammar.tab.c"
    break;

  case 144: /* $@1: %empty  */
#line 646 "C_grammar.y"
                                   {in_member_decl_flag = 1;}
#line 3207 "C_grammar.tab.c"
    break;

  case 145: /* struct_declaration: specifier_qualifier_list $@1 struct_declarator_list ';'  */
#line 647 "C_grammar.y"
                {in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3219 "C_grammar.tab.c"
    break;

  case 146: /* struct_declaration: static_assert_declaration  */
#line 655 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3225 "C_grammar.tab.c"
    break;

  case 147: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 660 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3236 "C_grammar.tab.c"
    break;

  case 148: /* specifier_qualifier_list: type_specifier  */
#line 667 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3242 "C_grammar.tab.c"
    break;

  case 149: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 669 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3253 "C_grammar.tab.c"
    break;

  case 150: /* specifier_qualifier_list: type_qualifier  */
#line 676 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3259 "C_grammar.tab.c"
    break;

  case 151: /* struct_declarator_list: struct_declarator  */
#line 681 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3265 "C_grammar.tab.c"
    break;

  case 152: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 683 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3276 "C_grammar.tab.c"
    break;

  case 153: /* struct_declarator: ':' constant_expression  */
#line 693 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3286 "C_grammar.tab.c"
    break;

  case 154: /* struct_declarator: declarator ':' constant_expression  */
#line 699 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3297 "C_grammar.tab.c"
    break;

  case 155: /* struct_declarator: declarator  */
#line 706 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3303 "C_grammar.tab.c"
    break;

  case 156: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 711 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3313 "C_grammar.tab.c"
    break;

  case 157: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 717 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3323 "C_grammar.tab.c"
    break;

  case 158: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 723 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3334 "C_grammar.tab.c"
    break;

  case 159: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 730 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum(%s, [%s])", (yyvsp[-4].id), (yyvsp[-2].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
        }
#line 3345 "C_grammar.tab.c"
    break;

  case 160: /* enum_specifier: ENUM IDENTIFIER  */
#line 737 "C_grammar.y"
                {size_t const size = strlen("forward_enum()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "forward_enum(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
        }
#line 3355 "C_grammar.tab.c"
    break;

  case 161: /* enumerator_list: enumerator  */
#line 746 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3361 "C_grammar.tab.c"
    break;

  case 162: /* enumerator_list: enumerator_list ',' enumerator  */
#line 748 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3372 "C_grammar.tab.c"
    break;

  case 163: /* enumerator: enumeration_constant '=' constant_expression  */
#line 758 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3383 "C_grammar.tab.c"
    break;

  case 164: /* enumerator: enumeration_constant  */
#line 765 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3389 "C_grammar.tab.c"
    break;

  case 166: /* type_qualifier: CONST  */
#line 773 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3395 "C_grammar.tab.c"
    break;

  case 167: /* type_qualifier: RESTRICT  */
#line 774 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3401 "C_grammar.tab.c"
    break;

  case 168: /* type_qualifier: VOLATILE  */
#line 775 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3407 "C_grammar.tab.c"
    break;

  case 169: /* type_qualifier: ATOMIC  */
#line 776 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3413 "C_grammar.tab.c"
    break;

  case 170: /* function_specifier: INLINE  */
#line 780 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3419 "C_grammar.tab.c"
    break;

  case 171: /* function_specifier: NORETURN  */
#line 781 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3425 "C_grammar.tab.c"
    break;

  case 174: /* declarator: pointer direct_declarator  */
#line 791 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 3436 "C_grammar.tab.c"
    break;

  case 175: /* declarator: direct_declarator  */
#line 798 "C_grammar.y"
          {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3442 "C_grammar.tab.c"
    break;

  case 176: /* direct_declarator: IDENTIFIER  */
#line 803 "C_grammar.y"
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
#line 3460 "C_grammar.tab.c"
    break;

  case 177: /* direct_declarator: '(' declarator ')'  */
#line 817 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D1");}
#line 3466 "C_grammar.tab.c"
    break;

  case 178: /* direct_declarator: direct_declarator '[' ']'  */
#line 819 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D2");}
#line 3472 "C_grammar.tab.c"
    break;

  case 179: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 821 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D3");}
#line 3478 "C_grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 823 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D4");}
#line 3484 "C_grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 825 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D5");}
#line 3490 "C_grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 827 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D6");}
#line 3496 "C_grammar.tab.c"
    break;

  case 183: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 829 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D7");}
#line 3502 "C_grammar.tab.c"
    break;

  case 184: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 831 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D8");}
#line 3508 "C_grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 833 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D9");}
#line 3514 "C_grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 835 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D10");}
#line 3520 "C_grammar.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '(' ')'  */
#line 837 "C_grammar.y"
                {size_t const size = strlen("function(, [])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, [])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3530 "C_grammar.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 843 "C_grammar.y"
                {size_t const size = strlen("function(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 3541 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 851 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D13");}
#line 3547 "C_grammar.tab.c"
    break;

  case 190: /* pointer: '*' type_qualifier_list pointer  */
#line 856 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3558 "C_grammar.tab.c"
    break;

  case 191: /* pointer: '*' type_qualifier_list  */
#line 863 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3568 "C_grammar.tab.c"
    break;

  case 192: /* pointer: '*' pointer  */
#line 869 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3578 "C_grammar.tab.c"
    break;

  case 193: /* pointer: '*'  */
#line 875 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3584 "C_grammar.tab.c"
    break;

  case 194: /* type_qualifier_list: type_qualifier  */
#line 880 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3590 "C_grammar.tab.c"
    break;

  case 195: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 882 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3601 "C_grammar.tab.c"
    break;

  case 196: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 892 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3611 "C_grammar.tab.c"
    break;

  case 197: /* parameter_type_list: parameter_list  */
#line 898 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3621 "C_grammar.tab.c"
    break;

  case 198: /* parameter_list: parameter_declaration  */
#line 907 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3627 "C_grammar.tab.c"
    break;

  case 199: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 909 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3638 "C_grammar.tab.c"
    break;

  case 200: /* parameter_declaration: declaration_specifiers declarator  */
#line 919 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3649 "C_grammar.tab.c"
    break;

  case 201: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 926 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3660 "C_grammar.tab.c"
    break;

  case 202: /* parameter_declaration: declaration_specifiers  */
#line 933 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3670 "C_grammar.tab.c"
    break;

  case 205: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 946 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3676 "C_grammar.tab.c"
    break;

  case 206: /* type_name: specifier_qualifier_list  */
#line 947 "C_grammar.y"
                                                                                {simple_str_lit_copy(&(yyval.id), "typenamedummy2");}
#line 3682 "C_grammar.tab.c"
    break;

  case 231: /* initializer: '{' initializer_list '}'  */
#line 982 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3692 "C_grammar.tab.c"
    break;

  case 232: /* initializer: '{' initializer_list ',' '}'  */
#line 988 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "trailing_comma_initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3702 "C_grammar.tab.c"
    break;

  case 233: /* initializer: assignment_expression  */
#line 994 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3708 "C_grammar.tab.c"
    break;

  case 234: /* initializer_list: designation initializer  */
#line 999 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3719 "C_grammar.tab.c"
    break;

  case 235: /* initializer_list: initializer  */
#line 1006 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3725 "C_grammar.tab.c"
    break;

  case 236: /* initializer_list: initializer_list ',' designation initializer  */
#line 1008 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3737 "C_grammar.tab.c"
    break;

  case 237: /* initializer_list: initializer_list ',' initializer  */
#line 1016 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3748 "C_grammar.tab.c"
    break;

  case 238: /* designation: designator_list '='  */
#line 1026 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3758 "C_grammar.tab.c"
    break;

  case 239: /* designator_list: designator  */
#line 1035 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3764 "C_grammar.tab.c"
    break;

  case 240: /* designator_list: designator_list designator  */
#line 1037 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3775 "C_grammar.tab.c"
    break;

  case 241: /* designator: '[' constant_expression ']'  */
#line 1047 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 3781 "C_grammar.tab.c"
    break;

  case 242: /* designator: '.' IDENTIFIER  */
#line 1049 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3791 "C_grammar.tab.c"
    break;

  case 243: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1058 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 3802 "C_grammar.tab.c"
    break;

  case 250: /* $@2: %empty  */
#line 1077 "C_grammar.y"
                {fprintf(pl_file, "label_stmt(%s, ", (yyvsp[-1].id)); 
		 free((yyvsp[-1].id));
		}
#line 3810 "C_grammar.tab.c"
    break;

  case 251: /* labeled_statement: IDENTIFIER ':' $@2 statement  */
#line 1081 "C_grammar.y"
                {fprintf(pl_file, ")");}
#line 3816 "C_grammar.tab.c"
    break;

  case 252: /* $@3: %empty  */
#line 1082 "C_grammar.y"
                                       {fprintf(pl_file, "case_stmt($2, "); free((yyvsp[-1].id));}
#line 3822 "C_grammar.tab.c"
    break;

  case 253: /* labeled_statement: CASE constant_expression ':' $@3 statement  */
#line 1082 "C_grammar.y"
                                                                                                 {fprintf(pl_file, ")");}
#line 3828 "C_grammar.tab.c"
    break;

  case 254: /* $@4: %empty  */
#line 1083 "C_grammar.y"
                      {fprintf(pl_file, "default_stmt(");}
#line 3834 "C_grammar.tab.c"
    break;

  case 255: /* labeled_statement: DEFAULT ':' $@4 statement  */
#line 1083 "C_grammar.y"
                                                                     {fprintf(pl_file, ")");}
#line 3840 "C_grammar.tab.c"
    break;

  case 256: /* compound_statement: '{' '}'  */
#line 1087 "C_grammar.y"
                  {fprintf(pl_file, "\ncmp_stmts([])");}
#line 3846 "C_grammar.tab.c"
    break;

  case 257: /* $@5: %empty  */
#line 1089 "C_grammar.y"
                {fprintf(pl_file, "\ncmp_stmts([");
		}
#line 3853 "C_grammar.tab.c"
    break;

  case 258: /* compound_statement: '{' $@5 block_item_list '}'  */
#line 1093 "C_grammar.y"
                {fprintf(pl_file, "\n])");
		}
#line 3860 "C_grammar.tab.c"
    break;

  case 260: /* $@6: %empty  */
#line 1099 "C_grammar.y"
                          {fprintf(pl_file, ", ");}
#line 3866 "C_grammar.tab.c"
    break;

  case 264: /* expression_statement: ';'  */
#line 1108 "C_grammar.y"
                                        {fprintf(pl_file, "stmt()");}
#line 3872 "C_grammar.tab.c"
    break;

  case 265: /* expression_statement: expression ';'  */
#line 1109 "C_grammar.y"
                                {fprintf(pl_file, "\nstmt(%s)", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3878 "C_grammar.tab.c"
    break;

  case 266: /* $@7: %empty  */
#line 1114 "C_grammar.y"
                {fprintf(pl_file, "\nif_stmt(branch(%d, %s), ", branch_nb++, (yyvsp[-1].id)); 
		 free((yyvsp[-1].id)); 
		}
#line 3886 "C_grammar.tab.c"
    break;

  case 267: /* selection_statement: IF '(' expression ')' $@7 statement else_opt  */
#line 1118 "C_grammar.y"
                { fprintf(pl_file, ")"); 
		}
#line 3893 "C_grammar.tab.c"
    break;

  case 268: /* $@8: %empty  */
#line 1121 "C_grammar.y"
                {fprintf(pl_file, "\nswitch_stmt(%s, ", (yyvsp[-1].id)); 
		 free((yyvsp[-1].id));
		}
#line 3901 "C_grammar.tab.c"
    break;

  case 269: /* selection_statement: SWITCH '(' expression ')' $@8 statement  */
#line 1125 "C_grammar.y"
                {fprintf(pl_file, ")");
		}
#line 3908 "C_grammar.tab.c"
    break;

  case 271: /* $@9: %empty  */
#line 1131 "C_grammar.y"
               {fprintf(pl_file, ", ");}
#line 3914 "C_grammar.tab.c"
    break;

  case 273: /* $@10: %empty  */
#line 1135 "C_grammar.y"
                {fprintf(pl_file, "\nwhile_stmt(branch(%d, %s), ", branch_nb++, (yyvsp[-1].id)); 
		 free((yyvsp[-1].id));
		}
#line 3922 "C_grammar.tab.c"
    break;

  case 274: /* iteration_statement: WHILE '(' expression ')' $@10 statement  */
#line 1139 "C_grammar.y"
                {fprintf(pl_file, ")");
		}
#line 3929 "C_grammar.tab.c"
    break;

  case 275: /* $@11: %empty  */
#line 1141 "C_grammar.y"
             {fprintf(pl_file, "\ndo_while_stmt(");}
#line 3935 "C_grammar.tab.c"
    break;

  case 276: /* iteration_statement: DO $@11 statement WHILE '(' expression ')' ';'  */
#line 1141 "C_grammar.y"
                                                                                            {fprintf(pl_file, ", %s)", (yyvsp[-2].id)); free((yyvsp[-2].id));}
#line 3941 "C_grammar.tab.c"
    break;

  case 277: /* $@12: %empty  */
#line 1142 "C_grammar.y"
                  {fprintf(pl_file, "\nfor_stmt(");}
#line 3947 "C_grammar.tab.c"
    break;

  case 278: /* $@13: %empty  */
#line 1142 "C_grammar.y"
                                                                       {fprintf(pl_file, ", ");}
#line 3953 "C_grammar.tab.c"
    break;

  case 279: /* iteration_statement: FOR '(' $@12 for_stmt_type ')' $@13 statement  */
#line 1142 "C_grammar.y"
                                                                                                           {fprintf(pl_file, ")");}
#line 3959 "C_grammar.tab.c"
    break;

  case 280: /* $@14: %empty  */
#line 1146 "C_grammar.y"
                               {fprintf(pl_file, ", ");}
#line 3965 "C_grammar.tab.c"
    break;

  case 282: /* $@15: %empty  */
#line 1147 "C_grammar.y"
                      {fprintf(pl_file, ", ");}
#line 3971 "C_grammar.tab.c"
    break;

  case 285: /* expression_opt: expression  */
#line 1152 "C_grammar.y"
                     {fprintf(pl_file, ", %s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 3977 "C_grammar.tab.c"
    break;

  case 286: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1155 "C_grammar.y"
                                {fprintf(pl_file, "\ngoto_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3983 "C_grammar.tab.c"
    break;

  case 287: /* jump_statement: CONTINUE ';'  */
#line 1156 "C_grammar.y"
                                        {fprintf(pl_file, "\ncontinue_stmt\n");}
#line 3989 "C_grammar.tab.c"
    break;

  case 288: /* jump_statement: BREAK ';'  */
#line 1157 "C_grammar.y"
                                                {fprintf(pl_file, "\nbreak_stmt\n");}
#line 3995 "C_grammar.tab.c"
    break;

  case 289: /* jump_statement: RETURN ';'  */
#line 1158 "C_grammar.y"
                                        {fprintf(pl_file, "\nreturn_stmt\n");}
#line 4001 "C_grammar.tab.c"
    break;

  case 290: /* jump_statement: RETURN expression ';'  */
#line 1159 "C_grammar.y"
                                {fprintf(pl_file, "\nreturn_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 4007 "C_grammar.tab.c"
    break;

  case 292: /* $@16: %empty  */
#line 1165 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4013 "C_grammar.tab.c"
    break;

  case 296: /* $@17: %empty  */
#line 1175 "C_grammar.y"
                {fprintf(pl_file, "function([%s], %s, [", (yyvsp[-1].id), (yyvsp[0].id)); 
		 free((yyvsp[-1].id)); 
		 free((yyvsp[0].id));
		}
#line 4022 "C_grammar.tab.c"
    break;

  case 297: /* $@18: %empty  */
#line 1180 "C_grammar.y"
                {fprintf(pl_file, "], ");}
#line 4028 "C_grammar.tab.c"
    break;

  case 298: /* function_definition: declaration_specifiers declarator $@17 declaration_list_opt $@18 compound_statement  */
#line 1182 "C_grammar.y"
                {fprintf(pl_file, ")");
		}
#line 4035 "C_grammar.tab.c"
    break;

  case 302: /* $@19: %empty  */
#line 1193 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 4041 "C_grammar.tab.c"
    break;


#line 4045 "C_grammar.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 1196 "C_grammar.y"

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
				printf("Usage: .\\sikraken_parser [OPTION]... [FILE]\nParse a C file to Prolog terms.\n\n-h\t Display help information\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\sikraken_parser -p\".\" get_sign \n\t.\\sikraken_parser get_sign \n\t.\\sikraken_parser -p\"C:/Parser/\" sign \n");
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
			default:
				fprintf(stderr, "Sikraken parser: Unsupported flag '-%s', ignoring.\n", argv[i]);
			}
		}
		else {	//must be the filename to analyse
			argv[i][strlen(argv[i]) - 2] = '\0';	//cut the out ".c"
			strcpy_safe(filename_no_ext, MAX_PATH, argv[i]);
		}
	}
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


//handles parsing errors: since the C input file is the output of a C pre-processor it is unlikely to be every called
//in fact it is only useful if the syntax rules are wrong or if .i file has been generated manually: i.e. during development
void yyerror(const char* s) {
	fprintf(stderr, "Internal parsing error, yyerror called on line %d with message \"%s\" on token %d\n", yylineno, s, yychar);
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

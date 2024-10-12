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


#line 123 "C_grammar.tab.c"

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
#line 60 "C_grammar.y"

	char* id;

#line 251 "C_grammar.tab.c"

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
  YYSYMBOL_104_1 = 104,                    /* $@1  */
  YYSYMBOL_constant = 105,                 /* constant  */
  YYSYMBOL_enumeration_constant = 106,     /* enumeration_constant  */
  YYSYMBOL_string = 107,                   /* string  */
  YYSYMBOL_generic_selection = 108,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 109,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 110,      /* generic_association  */
  YYSYMBOL_postfix_expression = 111,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 112, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 113,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 114,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 115,           /* unary_operator  */
  YYSYMBOL_cast_expression = 116,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 117, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 118, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 119,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 120,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 121,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 122,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 123,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 124, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 125,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 126,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 127,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 128,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 129,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 130,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 131,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 132,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 133,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 134,      /* assignment_operator  */
  YYSYMBOL_expression = 135,               /* expression  */
  YYSYMBOL_constant_expression = 136,      /* constant_expression  */
  YYSYMBOL_declaration = 137,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 138,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 139,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 140,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 141,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 142,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 143, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 144,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 145,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 146,       /* struct_declaration  */
  YYSYMBOL_147_2 = 147,                    /* $@2  */
  YYSYMBOL_specifier_qualifier_list = 148, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 149,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 150,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 151,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 152,          /* enumerator_list  */
  YYSYMBOL_enumerator = 153,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 154,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 155,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 156,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 157,      /* alignment_specifier  */
  YYSYMBOL_declarator = 158,               /* declarator  */
  YYSYMBOL_direct_declarator = 159,        /* direct_declarator  */
  YYSYMBOL_pointer = 160,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 161,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 162,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 163,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 164,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 165,          /* identifier_list  */
  YYSYMBOL_type_name = 166,                /* type_name  */
  YYSYMBOL_abstract_declarator = 167,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 168, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 169,              /* initializer  */
  YYSYMBOL_initializer_list = 170,         /* initializer_list  */
  YYSYMBOL_designation = 171,              /* designation  */
  YYSYMBOL_designator_list = 172,          /* designator_list  */
  YYSYMBOL_designator = 173,               /* designator  */
  YYSYMBOL_static_assert_declaration = 174, /* static_assert_declaration  */
  YYSYMBOL_statement = 175,                /* statement  */
  YYSYMBOL_labeled_statement = 176,        /* labeled_statement  */
  YYSYMBOL_177_3 = 177,                    /* $@3  */
  YYSYMBOL_178_4 = 178,                    /* $@4  */
  YYSYMBOL_179_5 = 179,                    /* $@5  */
  YYSYMBOL_compound_statement = 180,       /* compound_statement  */
  YYSYMBOL_181_6 = 181,                    /* $@6  */
  YYSYMBOL_block_item_list = 182,          /* block_item_list  */
  YYSYMBOL_183_7 = 183,                    /* $@7  */
  YYSYMBOL_block_item = 184,               /* block_item  */
  YYSYMBOL_expression_statement = 185,     /* expression_statement  */
  YYSYMBOL_selection_statement = 186,      /* selection_statement  */
  YYSYMBOL_187_8 = 187,                    /* $@8  */
  YYSYMBOL_188_9 = 188,                    /* $@9  */
  YYSYMBOL_else_opt = 189,                 /* else_opt  */
  YYSYMBOL_190_10 = 190,                   /* $@10  */
  YYSYMBOL_iteration_statement = 191,      /* iteration_statement  */
  YYSYMBOL_192_11 = 192,                   /* $@11  */
  YYSYMBOL_193_12 = 193,                   /* $@12  */
  YYSYMBOL_194_13 = 194,                   /* $@13  */
  YYSYMBOL_195_14 = 195,                   /* $@14  */
  YYSYMBOL_for_stmt_type = 196,            /* for_stmt_type  */
  YYSYMBOL_197_15 = 197,                   /* $@15  */
  YYSYMBOL_198_16 = 198,                   /* $@16  */
  YYSYMBOL_expression_opt = 199,           /* expression_opt  */
  YYSYMBOL_jump_statement = 200,           /* jump_statement  */
  YYSYMBOL_translation_unit = 201,         /* translation_unit  */
  YYSYMBOL_202_17 = 202,                   /* $@17  */
  YYSYMBOL_external_declaration = 203,     /* external_declaration  */
  YYSYMBOL_function_definition = 204,      /* function_definition  */
  YYSYMBOL_205_18 = 205,                   /* $@18  */
  YYSYMBOL_206_19 = 206,                   /* $@19  */
  YYSYMBOL_declaration_list_opt = 207,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 208,         /* declaration_list  */
  YYSYMBOL_209_20 = 209                    /* $@20  */
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
#define YYLAST   2146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  305
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  495

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
       0,   105,   105,   119,   120,   122,   121,   128,   134,   138,
     139,   140,   144,   149,   150,   154,   158,   159,   163,   164,
     168,   170,   177,   183,   190,   197,   204,   210,   216,   223,
     233,   234,   244,   245,   252,   259,   265,   271,   280,   281,
     285,   286,   287,   288,   289,   290,   294,   295,   305,   306,
     317,   318,   319,   323,   324,   335,   336,   340,   341,   352,
     353,   357,   358,   369,   370,   371,   372,   377,   378,   389,
     390,   394,   395,   405,   406,   416,   417,   427,   428,   438,
     439,   449,   450,   461,   462,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   487,   488,   498,   502,
     506,   514,   521,   528,   530,   537,   539,   541,   543,   545,
     547,   549,   554,   555,   565,   572,   581,   585,   586,   587,
     588,   589,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   612,   619,
     627,   637,   638,   642,   644,   654,   660,   660,   668,   673,
     680,   682,   689,   694,   696,   706,   712,   719,   724,   730,
     736,   743,   750,   759,   761,   771,   778,   783,   787,   788,
     789,   790,   794,   795,   799,   800,   804,   811,   816,   830,
     832,   834,   836,   838,   840,   842,   844,   846,   848,   850,
     856,   864,   869,   876,   882,   888,   893,   895,   905,   911,
     920,   922,   932,   939,   946,   955,   956,   960,   961,   970,
     971,   972,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   996,  1000,  1006,  1012,  1017,  1024,  1026,  1034,
    1044,  1053,  1055,  1065,  1067,  1076,  1086,  1087,  1088,  1089,
    1090,  1091,  1096,  1095,  1101,  1101,  1102,  1102,  1106,  1108,
    1107,  1115,  1116,  1116,  1120,  1121,  1125,  1126,  1131,  1130,
    1138,  1137,  1147,  1148,  1148,  1152,  1151,  1158,  1158,  1159,
    1159,  1159,  1163,  1163,  1164,  1164,  1168,  1169,  1172,  1173,
    1174,  1175,  1176,  1181,  1182,  1182,  1186,  1187,  1192,  1197,
    1191,  1204,  1205,  1209,  1210,  1210
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
  "'?'", "'='", "';'", "$accept", "primary_expression", "$@1", "constant",
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
  "$@2", "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement", "$@3",
  "$@4", "$@5", "compound_statement", "$@6", "block_item_list", "$@7",
  "block_item", "expression_statement", "selection_statement", "$@8",
  "$@9", "else_opt", "$@10", "iteration_statement", "$@11", "$@12", "$@13",
  "$@14", "for_stmt_type", "$@15", "$@16", "expression_opt",
  "jump_statement", "translation_unit", "$@17", "external_declaration",
  "function_definition", "$@18", "$@19", "declaration_list_opt",
  "declaration_list", "$@20", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-338)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-303)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1865,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,    43,   -61,  2074,  -338,  -338,
     -39,  -338,  -338,    21,  1970,  1970,  -338,    47,  -338,  -338,
    1970,  1970,  1970,  -338,    51,  -338,  -338,     6,    58,   774,
    2074,    16,  2074,    37,  1431,  -338,    42,   190,  -338,   -21,
    -338,   -23,   107,    53,  -338,  -338,    84,   695,  -338,  -338,
    -338,  -338,  1865,    58,  -338,    27,   -49,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  1454,  -338,  -338,    65,    79,   774,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
      77,  -338,  1477,  1431,  -338,   151,    60,    49,    50,   183,
      75,    90,    76,   157,    26,  -338,   117,   132,  -338,  1602,
     797,   115,  -338,   134,  -338,  -338,   114,   144,  -338,  -338,
     190,    42,  -338,  1295,  1865,  1761,   887,   107,   695,  1654,
    -338,    98,  -338,  -338,   -32,  1431,    15,  -338,   774,  -338,
    2074,  1431,   140,   418,  -338,  -338,   162,   148,   230,  -338,
    -338,  1318,  1431,   232,   774,  -338,  -338,  -338,  -338,  -338,
    1431,  -338,  -338,  1431,  -338,  -338,  1431,  -338,  -338,  -338,
    -338,  1431,  -338,  -338,  1431,  1431,  1431,  1431,  1431,  1431,
    1431,  -338,  -338,  -338,    41,   164,   166,  -338,   169,  1069,
    -338,   172,   177,   910,   134,  1813,   933,   255,  -338,  -338,
    -338,  -338,   170,  1205,  -338,  -338,  -338,    21,  -338,   189,
    -338,  -338,   193,   171,  1069,  -338,   196,   210,  1023,  1706,
    -338,  -338,  -338,    66,    17,  -338,  -338,  -338,  -338,   223,
     225,   226,   219,   229,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  1431,  -338,  1431,  1341,  -338,
    -338,   179,  -338,   -51,  -338,   231,  -338,   151,    60,    49,
      50,   183,    75,    90,    76,   157,   184,  1545,  -338,    55,
    -338,  -338,  1917,  -338,   228,  1069,  -338,  -338,  1431,  -338,
     233,  -338,   234,  1069,  -338,   235,   239,  1046,   236,  1431,
     306,  -338,   -18,  1295,   108,  -338,   140,  1865,  -338,  -338,
     309,   242,  1069,  -338,  -338,  1431,  -338,   248,   252,  -338,
    1431,    72,  -338,   256,  -338,   253,  -338,  2022,  -338,   541,
    -338,  -338,  -338,  1205,  -338,  -338,  1431,  -338,   253,  1431,
    -338,  -338,  -338,   259,   260,  -338,  -338,   263,  1069,  -338,
    -338,  1431,  -338,   266,   213,   268,  -338,  1159,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,   269,   271,  -338,  -338,
    -338,    66,  -338,  1431,   275,   187,  -338,   276,   278,  1431,
     279,   280,   283,   284,  -338,   285,   367,   270,   272,   277,
    -338,    80,  -338,  -338,  -338,  -338,   288,  -338,  -338,  -338,
    -338,  -338,    -5,  -338,  -338,  -338,  -338,  -338,   293,   296,
    -338,  -338,  -338,  -338,  -338,  1295,  -338,  -338,  -338,  -338,
    1431,  -338,  2022,  1431,  -338,   299,  -338,  1431,  1431,  1431,
     421,  -338,   281,  -338,  -338,  -338,    83,  -338,  -338,   541,
    1182,  -338,  -338,  -338,  -338,  -338,  -338,  -338,   421,  -338,
     421,   197,   216,   218,   319,   631,  -338,  -338,  -338,  -338,
    -338,   421,  -338,  -338,  -338,  -338,   305,  -338,  -338,   308,
    -338,   421,   421,   421,  1431,   684,   684,  -338,   324,  -338,
    -338,   220,  1431,  1431,   421,  -338,  -338,   287,   310,  -338,
    -338,  -338,   421,  -338,  -338
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   137,   116,   117,   118,   120,   121,   172,   168,   169,
     170,   131,   123,   124,   125,   126,   129,   130,   127,   128,
     122,   132,   133,   141,   142,     0,     0,     0,   171,   173,
       0,   119,   297,     0,   103,   105,   135,     0,   136,   134,
     107,   109,   111,   101,   294,   293,   296,   162,     0,     0,
     150,   208,   152,     0,     0,   178,     0,   195,    99,     0,
     112,   298,   177,     0,   102,   104,   140,     0,   106,   108,
     110,     1,     0,     0,    12,   166,     0,   163,     2,     9,
      10,    11,    13,    14,     0,    38,    39,     0,     0,     5,
      40,    41,    42,    43,    44,    45,    20,     3,     4,     8,
      32,    46,     0,     0,    48,    53,    57,    61,    67,    71,
      73,    75,    77,    79,    81,    98,     0,     0,   149,     0,
       0,   210,   207,   211,   151,   167,     0,     0,   196,   194,
     193,     0,   100,     0,   301,     0,     0,   176,     0,     0,
     143,   146,   148,   295,     0,     0,     0,   158,     5,    35,
       0,     0,     0,    46,    83,    96,     0,     0,     0,    26,
      27,     0,     0,     0,     5,    33,    34,    50,    51,    52,
       0,    55,    56,     0,    59,    60,     0,    65,    66,    63,
      64,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,   175,   174,   229,   204,     0,   199,   200,     0,     0,
     213,    41,     0,     0,   209,     0,     0,     0,   179,   197,
     192,   113,   115,     0,   235,   114,   303,     0,   299,   304,
     205,   189,     0,     0,     0,   180,    41,     0,     0,     0,
     138,   144,   145,     0,     0,   160,   165,   159,   164,     0,
       0,     0,   259,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    85,     0,     7,     0,     0,    25,
      22,     0,    30,     0,    24,     0,    49,    54,    58,    62,
      68,    72,    74,    76,    78,    80,     0,     0,   202,   210,
     203,   230,     0,   212,     0,     0,   214,   220,     0,   219,
       0,   231,     0,     0,   221,    41,     0,     0,     0,     0,
       0,   237,     0,     0,     0,   241,     0,     0,   190,   191,
       0,     0,     0,   181,   188,     0,   187,    41,     0,   139,
       0,     0,   153,   157,   161,    36,    37,     0,   258,     0,
       6,    84,    97,     0,    47,    23,     0,    21,     0,     0,
     198,   201,   216,     0,     0,   218,   232,     0,     0,   222,
     228,     0,   227,     0,     0,     0,   244,     0,   233,   236,
     240,   242,   300,   305,   206,   183,     0,     0,   184,   186,
     155,     0,   147,     0,     0,     0,    16,     0,     2,     0,
       0,     0,     0,     0,   277,     0,     0,     0,     0,     0,
     266,     0,   264,   265,   246,   247,   262,   261,   248,   249,
     250,   251,     0,    31,    82,   215,   217,   224,     0,     0,
     225,   245,   243,   234,   239,     0,   182,   185,   154,   156,
       0,    15,     0,     0,   252,     0,   256,     0,     0,     0,
       0,   279,     0,   289,   290,   291,     0,   267,   260,     0,
       0,    28,   223,   226,   238,    19,    17,    18,     0,   254,
       0,     0,     0,     0,     0,     0,   288,   292,   263,    29,
     253,     0,   257,   268,   270,   275,     0,   284,   282,     0,
     255,     0,     0,     0,     0,     0,     0,   280,   272,   271,
     276,     0,   286,   286,     0,   273,   269,     0,   287,   285,
     283,   281,     0,   278,   274
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,   -37,  -338,
    -338,    33,  -338,  -338,   -87,   224,  -338,   215,  -338,   208,
    -338,   209,  -338,   207,  -338,   214,   212,   221,   222,  -338,
     -45,   120,  -338,   -88,   -52,  -119,     0,  -338,   265,  -338,
       3,  -338,  -338,   264,  -116,  -338,   -31,  -338,    30,  -338,
     330,  -124,  -338,   -24,  -338,  -338,   -26,   -55,   -46,   -41,
    -108,  -338,   122,  -338,    22,   -38,  -115,  -123,    74,  -319,
    -338,   106,   -53,  -235,  -338,  -338,  -338,  -338,  -140,  -338,
    -338,  -338,   -25,  -337,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,   -68,  -338,  -338,
    -338,   344,  -338,  -338,  -338,  -338,  -338,  -338
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    96,   152,    97,    75,    98,    99,   375,   376,   100,
     261,   153,   102,   103,   104,   105,   170,   106,   173,   107,
     176,   108,   181,   109,   184,   110,   111,   112,   113,   114,
     154,   155,   255,   391,   116,    32,   194,    59,    60,    34,
      35,    36,    37,   139,   140,   233,    51,   321,   322,    38,
      76,    77,    39,    40,    41,    42,   127,    62,    63,   130,
     195,   196,   197,   223,   377,   198,   123,   301,   302,   303,
     304,   305,    43,   393,   394,   448,   461,   450,   395,   329,
     396,   439,   397,   398,   399,   471,   472,   486,   492,   400,
     473,   430,   455,   484,   469,   476,   475,   489,   401,    44,
      72,    45,    46,   134,   306,   218,   219,   307
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   156,   126,    52,   115,   121,   204,    61,   137,   115,
     215,   129,   243,   122,   142,   216,   166,    49,    74,   118,
      74,   124,   238,   231,    55,    52,    52,   222,    52,   257,
      50,   146,   337,   128,    64,    65,   141,   147,   415,    54,
      68,    69,    70,    52,    55,    55,    47,   189,   234,    53,
      66,    71,    50,    50,   235,    50,    55,  -115,    55,   131,
     156,    74,   357,   174,   175,    52,   177,   178,   358,    55,
      50,   117,    33,   121,   263,   440,   156,   133,  -115,   203,
     132,   441,   101,   266,   210,   142,   142,   101,   158,   159,
     160,    73,    50,   236,   119,   228,   128,   292,   120,    56,
     115,   237,   276,   324,    57,   212,   209,   141,   141,    57,
     238,   157,   128,   231,    52,    52,   125,   149,   468,   277,
      56,   415,    58,   120,    52,   190,    52,   145,    48,    57,
      57,    56,    67,   277,   217,   165,   101,   120,   482,   483,
      52,    50,    50,   150,    56,   179,   180,   320,   279,   171,
     172,    50,   371,    50,    57,   161,   280,   151,   285,   162,
     257,   163,   185,   257,   204,   297,   362,    50,   278,   138,
     239,   334,   240,   372,   187,   128,   142,   188,   101,   209,
     359,   437,   128,   312,   457,   135,   265,   186,   363,   136,
     299,   212,   300,   119,   207,   454,   191,   120,   141,   232,
     128,   182,   183,   101,   209,    52,   101,   323,   360,   101,
     392,   192,   205,   460,   101,   462,   206,   101,   101,   101,
     101,   101,   101,   208,   137,   242,   470,   258,     8,     9,
      10,   279,    50,   259,   414,   264,   478,   479,   480,   167,
     202,   256,   257,   281,   168,   169,   282,   355,   283,   491,
     309,   310,   348,   214,   115,   286,   227,   494,   335,   336,
     287,   209,    28,   298,   257,   339,   421,   422,   370,   128,
     133,   241,   308,   209,  -302,   115,   463,   257,    57,   313,
      78,   262,    79,    80,    81,    82,    83,    84,   209,    85,
      86,   101,   444,   314,   404,   464,   257,   465,   257,   487,
     257,   436,   325,    52,   326,   328,   327,   217,   330,   356,
     338,   342,   364,   346,   411,   354,   345,   414,   349,   284,
     392,   419,   350,   290,   209,   365,   296,   425,   115,   217,
      50,   368,   101,   214,   115,   369,   467,   373,   333,   451,
     452,   453,   405,   406,   311,   323,   407,    87,   318,   410,
      88,   412,   416,   101,   417,    89,   420,   423,   427,   424,
     426,   428,   429,   431,    90,    91,    92,    93,    94,    95,
     432,   433,   101,   434,   438,   331,   442,   332,   435,   443,
     449,   466,   456,   474,   485,   446,   481,   477,   493,   269,
     257,   268,   271,   270,   488,   488,   211,   267,    52,   273,
     272,   418,   229,   144,   341,   343,   101,   402,   344,   274,
     361,   275,   101,   347,   458,   490,   143,   353,     0,     0,
       0,     0,     0,   214,   378,    50,    79,    80,    81,    82,
      83,    84,   366,    85,    86,   367,     0,     0,     0,   217,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,   214,     0,   217,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   408,     0,
       0,   409,     0,     0,     0,     0,     0,   214,   379,   380,
     381,     0,   382,   383,   384,   385,   386,   387,   388,   389,
       0,    87,     0,     0,    88,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,   242,     0,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,   254,     0,
       0,     0,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,     0,
     445,     0,     0,   447,   378,     1,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   379,   380,
     381,     0,   382,   383,   384,   385,   386,   387,   388,   389,
      26,    87,    27,    28,    88,    29,    30,    31,     0,    89,
       0,     0,     0,     0,     0,     0,   242,     0,    90,    91,
      92,    93,    94,    95,    78,     1,    79,    80,    81,    82,
      83,    84,   390,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     1,
      26,    87,    27,    28,    88,    29,    30,    31,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,   390,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,    87,     0,     0,    88,     0,     0,
       0,     0,    89,     0,     0,     0,    27,    28,     0,     0,
      30,    90,    91,    92,    93,    94,    95,    78,     1,    79,
      80,    81,    82,    83,    84,   390,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,   199,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    87,    27,    28,    88,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,    87,     0,    28,
      88,     0,     0,     0,     0,    89,     0,     0,     0,     0,
     200,     0,     0,     0,    90,   201,    92,    93,    94,    95,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,    79,    80,    81,    82,    83,
      84,   224,    85,    86,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    79,    80,
      81,    82,    83,    84,   288,    85,    86,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,    87,     0,    28,
      88,     0,     0,     0,     0,    89,     0,   293,     0,     0,
     225,     8,     9,    10,    90,   226,    92,    93,    94,    95,
      87,     0,    28,    88,     0,     0,     0,     0,    89,     0,
       0,     0,     0,   289,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    87,     0,    28,    88,     0,     0,     0,
       0,    89,     0,     0,     0,     0,   294,     0,     0,     0,
      90,   295,    92,    93,    94,    95,    78,     0,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,    79,    80,    81,    82,    83,    84,   315,    85,    86,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,    79,    80,    81,    82,    83,    84,
     351,    85,    86,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,    87,     0,    28,    88,     0,     0,     0,
       0,    89,     0,     0,     0,     0,   316,     8,     9,    10,
      90,   317,    92,    93,    94,    95,    87,     0,    28,    88,
       0,     0,     0,     0,    89,     0,     0,     0,     0,   352,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    87,
       0,    28,    88,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    78,     0,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,    79,    80,    81,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,    88,     0,     0,     0,     0,    89,     0,     0,
       0,   299,     0,   300,   213,   413,    90,    91,    92,    93,
      94,    95,    87,     0,     0,    88,     0,     0,     0,     0,
      89,     0,     0,     0,   299,     0,   300,   213,   459,    90,
      91,    92,    93,    94,    95,    87,     0,     0,    88,     0,
       0,     0,     0,    89,     0,     0,     0,   299,     0,   300,
     213,     0,    90,    91,    92,    93,    94,    95,    78,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,    88,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
     213,     0,    90,    91,    92,    93,    94,    95,    87,     0,
       0,    88,     0,     0,     0,     0,    89,   260,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    87,     0,     0,    88,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,   333,     0,    90,    91,
      92,    93,    94,    95,    78,     0,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    79,    80,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,    88,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    87,     0,     0,    88,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,    87,    55,     1,
      88,     0,     0,     0,     0,   164,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
       0,    31,     0,   277,   193,     0,     0,   120,     0,     0,
       0,     0,     0,    57,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,    29,     0,    31,     0,
     119,   193,     0,     0,   120,     0,     0,     0,     0,     0,
      57,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,   220,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,    28,     0,    29,     0,    31,     0,     0,
     221,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,     0,    29,     0,    31,
       0,     0,   291,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,    28,     0,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   340,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,    28,
       0,    29,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,     0,    29,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
     374,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28
};

static const yytype_int16 yycheck[] =
{
       0,    89,    54,    27,    49,    51,   121,    33,    63,    54,
     133,    57,   152,    51,    67,   134,   103,    78,     3,    50,
       3,    52,   146,   139,     3,    49,    50,   135,    52,    80,
      27,    80,    83,    57,    34,    35,    67,    86,   357,    78,
      40,    41,    42,    67,     3,     3,     3,    21,    80,    27,
       3,     0,    49,    50,    86,    52,     3,    80,     3,    80,
     148,     3,    80,    14,    15,    89,    16,    17,    86,     3,
      67,    49,    72,   119,   162,    80,   164,   100,   101,   120,
     101,    86,    49,   170,   130,   138,   139,    54,    11,    12,
      13,    85,    89,   145,    78,   136,   120,   205,    82,    78,
     145,    86,   190,    86,    88,   131,   130,   138,   139,    88,
     234,    89,   136,   229,   138,   139,    79,    84,   455,    78,
      78,   440,   101,    82,   148,    99,   150,   100,    85,    88,
      88,    78,    85,    78,   134,   102,   103,    82,   475,   476,
     164,   138,   139,    78,    78,    95,    96,    81,   194,    89,
      90,   148,    80,   150,    88,    78,   194,    78,   199,    82,
      80,    84,    87,    80,   279,   206,   306,   164,   194,    85,
     148,   258,   150,   101,    98,   199,   229,    20,   145,   203,
     303,   101,   206,   224,   101,    78,   164,    97,   307,    82,
      82,   217,    84,    78,    80,   430,    79,    82,   229,   101,
     224,    18,    19,   170,   228,   229,   173,   233,   100,   176,
     329,    79,    78,   448,   181,   450,    82,   184,   185,   186,
     187,   188,   189,    79,   279,    85,   461,    79,    38,    39,
      40,   277,   229,     3,   357,     3,   471,   472,   473,    88,
     120,    79,    80,    79,    93,    94,    80,   299,    79,   484,
      79,    80,   293,   133,   299,    83,   136,   492,    79,    80,
      83,   285,    72,     8,    80,    81,    79,    80,   320,   293,
     100,   151,    79,   297,    85,   320,    79,    80,    88,    83,
       3,   161,     5,     6,     7,     8,     9,    10,   312,    12,
      13,   258,   415,    83,   339,    79,    80,    79,    80,    79,
      80,   389,    79,   327,    79,    86,    80,   307,    79,     3,
      79,    83,     3,    79,   101,    79,    83,   440,    83,   199,
     439,   373,    83,   203,   348,    83,   206,   379,   373,   329,
     327,    83,   299,   213,   379,    83,   455,    81,    85,   427,
     428,   429,    83,    83,   224,   371,    83,    70,   228,    83,
      73,    83,    83,   320,    83,    78,    81,    81,    78,    81,
      81,    78,    78,    78,    87,    88,    89,    90,    91,    92,
       3,   101,   339,   101,    86,   255,    83,   257,   101,    83,
      81,    62,   101,    78,    60,   422,   474,    79,   101,   181,
      80,   176,   185,   184,   482,   483,   131,   173,   422,   187,
     186,   371,   138,    73,   282,   285,   373,   333,   288,   188,
     304,   189,   379,   293,   439,   483,    72,   297,    -1,    -1,
      -1,    -1,    -1,   303,     3,   422,     5,     6,     7,     8,
       9,    10,   312,    12,    13,   315,    -1,    -1,    -1,   439,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    -1,   333,    -1,   455,   336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,
      -1,   351,    -1,    -1,    -1,    -1,    -1,   357,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   415,    -1,    -1,    -1,    -1,
     420,    -1,    -1,   423,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
     440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    88,
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
      55,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    71,    72,    -1,    -1,
      75,    87,    88,    89,    90,    91,    92,     3,     4,     5,
       6,     7,     8,     9,    10,   101,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    70,    -1,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    34,    12,    13,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    34,    12,    13,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    34,    -1,    -1,
      83,    38,    39,    40,    87,    88,    89,    90,    91,    92,
      70,    -1,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    70,    -1,    72,    73,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    34,    12,    13,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      34,    12,    13,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    83,    38,    39,    40,
      87,    88,    89,    90,    91,    92,    70,    -1,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    87,    88,    89,    90,    91,    92,    70,
      -1,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,    92,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    82,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    82,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    91,    92,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      92,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    91,    92,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    70,     3,     4,
      73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      -1,    76,    -1,    78,    79,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    88,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,    -1,
      78,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    74,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    72,    74,
      75,    76,   137,   138,   141,   142,   143,   144,   151,   154,
     155,   156,   157,   174,   201,   203,   204,     3,    85,    78,
     142,   148,   155,   166,    78,     3,    78,    88,   101,   139,
     140,   158,   159,   160,   138,   138,     3,    85,   138,   138,
     138,     0,   202,    85,     3,   106,   152,   153,     3,     5,
       6,     7,     8,     9,    10,    12,    13,    70,    73,    78,
      87,    88,    89,    90,    91,    92,   103,   105,   107,   108,
     111,   113,   114,   115,   116,   117,   119,   121,   123,   125,
     127,   128,   129,   130,   131,   132,   136,   166,   148,    78,
      82,   160,   167,   168,   148,    79,   136,   158,   155,   160,
     161,    80,   101,   100,   205,    78,    82,   159,    85,   145,
     146,   148,   174,   203,   152,   100,    80,    86,    78,   113,
      78,    78,   104,   113,   132,   133,   135,   166,    11,    12,
      13,    78,    82,    84,    78,   113,   116,    88,    93,    94,
     118,    89,    90,   120,    14,    15,   122,    16,    17,    95,
      96,   124,    18,    19,   126,    87,    97,    98,    20,    21,
      99,    79,    79,    79,   138,   162,   163,   164,   167,    34,
      83,    88,   133,   161,   168,    78,    82,    80,    79,   155,
     160,   140,   158,    85,   133,   169,   137,   138,   207,   208,
       3,    79,   162,   165,    34,    83,    88,   133,   161,   145,
      86,   146,   101,   147,    80,    86,   136,    86,   153,   166,
     166,   133,    85,   180,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   100,   134,    79,    80,    79,     3,
      79,   112,   133,   135,     3,   166,   116,   117,   119,   121,
     123,   125,   127,   128,   129,   130,   135,    78,   158,   160,
     167,    79,    80,    79,   133,   161,    83,    83,    34,    83,
     133,    79,   162,    34,    83,    88,   133,   161,     8,    82,
      84,   169,   170,   171,   172,   173,   206,   209,    79,    79,
      80,   133,   161,    83,    83,    34,    83,    88,   133,    86,
      81,   149,   150,   158,    86,    79,    79,    80,    86,   181,
      79,   133,   133,    85,   116,    79,    80,    83,    79,    81,
      56,   164,    83,   133,   133,    83,    79,   133,   161,    83,
      83,    34,    83,   133,    79,   136,     3,    80,    86,   169,
     100,   173,   180,   137,     3,    83,   133,   133,    83,    83,
     136,    80,   101,    81,    58,   109,   110,   166,     3,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
     101,   135,   137,   175,   176,   180,   182,   184,   185,   186,
     191,   200,   170,   133,   132,    83,    83,    83,   133,   133,
      83,   101,    83,    86,   169,   171,    83,    83,   150,   136,
      81,    79,    80,    81,    81,   136,    81,    78,    78,    78,
     193,    78,     3,   101,   101,   101,   135,   101,    86,   183,
      80,    86,    83,    83,   169,   133,   110,   133,   177,    81,
     179,   135,   135,   135,   175,   194,   101,   101,   184,    86,
     175,   178,   175,    79,    79,    79,    62,   137,   185,   196,
     175,   187,   188,   192,    78,   198,   197,    79,   175,   175,
     175,   135,   185,   185,   195,    60,   189,    79,   135,   199,
     199,   175,   190,   101,   175
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   103,   104,   103,   103,   103,   105,
     105,   105,   106,   107,   107,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   136,   137,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   139,   140,   140,   141,   141,   141,   141,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   143,   143,
     143,   144,   144,   145,   145,   146,   147,   146,   146,   148,
     148,   148,   148,   149,   149,   150,   150,   150,   151,   151,
     151,   151,   151,   152,   152,   153,   153,   154,   155,   155,
     155,   155,   156,   156,   157,   157,   158,   158,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   162,   162,
     163,   163,   164,   164,   164,   165,   165,   166,   166,   167,
     167,   167,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   169,   169,   169,   170,   170,   170,   170,
     171,   172,   172,   173,   173,   174,   175,   175,   175,   175,
     175,   175,   177,   176,   178,   176,   179,   176,   180,   181,
     180,   182,   183,   182,   184,   184,   185,   185,   187,   186,
     188,   186,   189,   190,   189,   192,   191,   193,   191,   194,
     195,   191,   197,   196,   198,   196,   199,   199,   200,   200,
     200,   200,   200,   201,   202,   201,   203,   203,   205,   206,
     204,   207,   207,   208,   209,   208
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     0,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     3,     3,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       2,     1,     1,     1,     2,     2,     0,     4,     1,     2,
       1,     2,     1,     1,     3,     2,     3,     1,     4,     5,
       5,     6,     2,     1,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     4,     2,     1,     1,     3,
       3,     4,     6,     5,     5,     6,     5,     4,     4,     3,
       4,     4,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     3,     2,     2,     1,     1,     3,     2,     1,     2,
       1,     1,     3,     2,     3,     5,     4,     5,     4,     3,
       3,     3,     4,     6,     5,     5,     6,     4,     4,     2,
       3,     3,     4,     3,     4,     1,     2,     1,     4,     3,
       2,     1,     2,     3,     2,     7,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     5,     0,     4,     2,     0,
       4,     1,     0,     3,     1,     1,     1,     2,     0,     7,
       0,     6,     0,     0,     3,     0,     6,     0,     8,     0,
       0,     7,     0,     4,     0,     4,     0,     1,     3,     2,
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
#line 106 "C_grammar.y"
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
#line 2445 "C_grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 119 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2451 "C_grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 120 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2457 "C_grammar.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 122 "C_grammar.y"
                        {fprintf(pl_file, "\nstmt_exp(");}
#line 2463 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: '(' $@1 compound_statement ')'  */
#line 125 "C_grammar.y"
                        {fprintf(pl_file, ")");				//closing stmt_exp
	   		 simple_str_lit_copy(&(yyval.id), "");		//because we have to return something into $$ 
	  		}
#line 2471 "C_grammar.tab.c"
    break;

  case 7: /* primary_expression: '(' expression ')'  */
#line 129 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2481 "C_grammar.tab.c"
    break;

  case 8: /* primary_expression: generic_selection  */
#line 134 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2487 "C_grammar.tab.c"
    break;

  case 9: /* constant: I_CONSTANT  */
#line 138 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2493 "C_grammar.tab.c"
    break;

  case 10: /* constant: F_CONSTANT  */
#line 139 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2499 "C_grammar.tab.c"
    break;

  case 11: /* constant: ENUMERATION_CONSTANT  */
#line 140 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2505 "C_grammar.tab.c"
    break;

  case 12: /* enumeration_constant: IDENTIFIER  */
#line 145 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2511 "C_grammar.tab.c"
    break;

  case 13: /* string: STRING_LITERAL  */
#line 149 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2517 "C_grammar.tab.c"
    break;

  case 14: /* string: FUNC_NAME  */
#line 150 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2523 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: primary_expression  */
#line 169 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2529 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 171 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2540 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '(' ')'  */
#line 178 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2550 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 184 "C_grammar.y"
                {size_t const size = strlen("function_call(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "function_call(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2561 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 191 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2572 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 198 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2583 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression INC_OP  */
#line 205 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2593 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression DEC_OP  */
#line 211 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2603 "C_grammar.tab.c"
    break;

  case 28: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 217 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2614 "C_grammar.tab.c"
    break;

  case 29: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 224 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2625 "C_grammar.tab.c"
    break;

  case 30: /* argument_expression_list: assignment_expression  */
#line 233 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2631 "C_grammar.tab.c"
    break;

  case 31: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 235 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2642 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: postfix_expression  */
#line 244 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2648 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_inc_dec unary_expression  */
#line 246 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2659 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: unary_operator cast_expression  */
#line 253 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2670 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF unary_expression  */
#line 260 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2680 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 266 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2690 "C_grammar.tab.c"
    break;

  case 37: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 272 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2700 "C_grammar.tab.c"
    break;

  case 38: /* unary_inc_dec: INC_OP  */
#line 280 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2706 "C_grammar.tab.c"
    break;

  case 39: /* unary_inc_dec: DEC_OP  */
#line 281 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2712 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '&'  */
#line 285 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr");}
#line 2718 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '*'  */
#line 286 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "deref");}
#line 2724 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '+'  */
#line 287 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2730 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '-'  */
#line 288 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2736 "C_grammar.tab.c"
    break;

  case 44: /* unary_operator: '~'  */
#line 289 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "one_comp_op");}
#line 2742 "C_grammar.tab.c"
    break;

  case 45: /* unary_operator: '!'  */
#line 290 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2748 "C_grammar.tab.c"
    break;

  case 46: /* cast_expression: unary_expression  */
#line 294 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2754 "C_grammar.tab.c"
    break;

  case 47: /* cast_expression: '(' type_name ')' cast_expression  */
#line 296 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2765 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: cast_expression  */
#line 305 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2771 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 307 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2783 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '*'  */
#line 317 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2789 "C_grammar.tab.c"
    break;

  case 51: /* multiplicative_expression_op: '/'  */
#line 318 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2795 "C_grammar.tab.c"
    break;

  case 52: /* multiplicative_expression_op: '%'  */
#line 319 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2801 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression: multiplicative_expression  */
#line 323 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2807 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 325 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2819 "C_grammar.tab.c"
    break;

  case 55: /* additive_expression_op: '+'  */
#line 335 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2825 "C_grammar.tab.c"
    break;

  case 56: /* additive_expression_op: '-'  */
#line 336 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2831 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression: additive_expression  */
#line 340 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2837 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 342 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2849 "C_grammar.tab.c"
    break;

  case 59: /* shift_expression_op: LEFT_OP  */
#line 352 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift_op");}
#line 2855 "C_grammar.tab.c"
    break;

  case 60: /* shift_expression_op: RIGHT_OP  */
#line 353 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift_op");}
#line 2861 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression: shift_expression  */
#line 357 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2867 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 359 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2879 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: '<'  */
#line 369 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2885 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: '>'  */
#line 370 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2891 "C_grammar.tab.c"
    break;

  case 65: /* relational_expression_operator: LE_OP  */
#line 371 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2897 "C_grammar.tab.c"
    break;

  case 66: /* relational_expression_operator: GE_OP  */
#line 372 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2903 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression: relational_expression  */
#line 377 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2909 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 379 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2921 "C_grammar.tab.c"
    break;

  case 69: /* equality_expression_op: EQ_OP  */
#line 389 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2927 "C_grammar.tab.c"
    break;

  case 70: /* equality_expression_op: NE_OP  */
#line 390 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2933 "C_grammar.tab.c"
    break;

  case 71: /* and_expression: equality_expression  */
#line 394 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2939 "C_grammar.tab.c"
    break;

  case 72: /* and_expression: and_expression '&' equality_expression  */
#line 396 "C_grammar.y"
                {size_t const size = strlen("bitw_and(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitw_and(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2950 "C_grammar.tab.c"
    break;

  case 73: /* exclusive_or_expression: and_expression  */
#line 405 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2956 "C_grammar.tab.c"
    break;

  case 74: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 407 "C_grammar.y"
                {size_t const size = strlen("bitw_excl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitw_excl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2967 "C_grammar.tab.c"
    break;

  case 75: /* inclusive_or_expression: exclusive_or_expression  */
#line 416 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2973 "C_grammar.tab.c"
    break;

  case 76: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 418 "C_grammar.y"
                {size_t const size = strlen("bitw_incl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "bitw_incl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2984 "C_grammar.tab.c"
    break;

  case 77: /* logical_and_expression: inclusive_or_expression  */
#line 427 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2990 "C_grammar.tab.c"
    break;

  case 78: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 429 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3001 "C_grammar.tab.c"
    break;

  case 79: /* logical_or_expression: logical_and_expression  */
#line 438 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3007 "C_grammar.tab.c"
    break;

  case 80: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 440 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3018 "C_grammar.tab.c"
    break;

  case 81: /* conditional_expression: logical_or_expression  */
#line 449 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3024 "C_grammar.tab.c"
    break;

  case 82: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 451 "C_grammar.y"
                {size_t const size = strlen("cond_exp(branch(, ), , )") + 42 + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "cond_exp(branch(%d, %s), %s, %s)", branch_nb++, (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3036 "C_grammar.tab.c"
    break;

  case 83: /* assignment_expression: conditional_expression  */
#line 461 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3042 "C_grammar.tab.c"
    break;

  case 84: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 463 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3054 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: '='  */
#line 473 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 3060 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: MUL_ASSIGN  */
#line 474 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 3066 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: DIV_ASSIGN  */
#line 475 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 3072 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: MOD_ASSIGN  */
#line 476 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 3078 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: ADD_ASSIGN  */
#line 477 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 3084 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: SUB_ASSIGN  */
#line 478 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 3090 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: LEFT_ASSIGN  */
#line 479 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 3096 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: RIGHT_ASSIGN  */
#line 480 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 3102 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: AND_ASSIGN  */
#line 481 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 3108 "C_grammar.tab.c"
    break;

  case 94: /* assignment_operator: XOR_ASSIGN  */
#line 482 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 3114 "C_grammar.tab.c"
    break;

  case 95: /* assignment_operator: OR_ASSIGN  */
#line 483 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 3120 "C_grammar.tab.c"
    break;

  case 96: /* expression: assignment_expression  */
#line 487 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3126 "C_grammar.tab.c"
    break;

  case 97: /* expression: expression ',' assignment_expression  */
#line 489 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3137 "C_grammar.tab.c"
    break;

  case 98: /* constant_expression: conditional_expression  */
#line 498 "C_grammar.y"
                                                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3143 "C_grammar.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers ';'  */
#line 503 "C_grammar.y"
                {fprintf(pl_file, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 3151 "C_grammar.tab.c"
    break;

  case 100: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 507 "C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
	     fprintf(pl_file, "\ndeclaration([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	  }
#line 3163 "C_grammar.tab.c"
    break;

  case 101: /* declaration: static_assert_declaration  */
#line 515 "C_grammar.y"
                {fprintf(pl_file, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3171 "C_grammar.tab.c"
    break;

  case 102: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 522 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3182 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: storage_class_specifier  */
#line 529 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3188 "C_grammar.tab.c"
    break;

  case 104: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 531 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3199 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_specifier  */
#line 538 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3205 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 540 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_type_qualifier, dummy_declaration_specifiers"); }
#line 3211 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: type_qualifier  */
#line 542 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_type_qualifier"); }
#line 3217 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 544 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier, dummy_declaration_specifiers"); }
#line 3223 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: function_specifier  */
#line 546 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_function_specifier"); }
#line 3229 "C_grammar.tab.c"
    break;

  case 110: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 548 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier, dummy_declaration_specifiers"); }
#line 3235 "C_grammar.tab.c"
    break;

  case 111: /* declaration_specifiers: alignment_specifier  */
#line 550 "C_grammar.y"
                { simple_str_lit_copy(&(yyval.id), "dummy_alignment_specifier"); }
#line 3241 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator_list: init_declarator  */
#line 554 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3247 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 556 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 3258 "C_grammar.tab.c"
    break;

  case 114: /* init_declarator: declarator '=' initializer  */
#line 566 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_safe((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	   	 //free($3);
	  	}
#line 3269 "C_grammar.tab.c"
    break;

  case 115: /* init_declarator: declarator  */
#line 573 "C_grammar.y"
          {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name((yyvsp[0].id));
	   }
	   simple_str_copy(&(yyval.id), (yyvsp[0].id));
	  }
#line 3279 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: TYPEDEF  */
#line 582 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
	    }
#line 3287 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: EXTERN  */
#line 585 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 3293 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: STATIC  */
#line 586 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 3299 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: THREAD_LOCAL  */
#line 587 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 3305 "C_grammar.tab.c"
    break;

  case 120: /* storage_class_specifier: AUTO  */
#line 588 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 3311 "C_grammar.tab.c"
    break;

  case 121: /* storage_class_specifier: REGISTER  */
#line 589 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 3317 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: VOID  */
#line 593 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 3323 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: CHAR  */
#line 594 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 3329 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: SHORT  */
#line 595 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 3335 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: INT  */
#line 596 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 3341 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: LONG  */
#line 597 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 3347 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: FLOAT  */
#line 598 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 3353 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: DOUBLE  */
#line 599 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 3359 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: SIGNED  */
#line 600 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 3365 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: UNSIGNED  */
#line 601 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 3371 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: BOOL  */
#line 602 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 3377 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: COMPLEX  */
#line 603 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 3383 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: IMAGINARY  */
#line 604 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 3389 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: atomic_type_specifier  */
#line 605 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 3395 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: struct_or_union_specifier  */
#line 606 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3401 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: enum_specifier  */
#line 607 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3407 "C_grammar.tab.c"
    break;

  case 137: /* type_specifier: TYPEDEF_NAME  */
#line 608 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3413 "C_grammar.tab.c"
    break;

  case 138: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 613 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
	    }
#line 3424 "C_grammar.tab.c"
    break;

  case 139: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 620 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s, [%s])", (yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
	    }
#line 3436 "C_grammar.tab.c"
    break;

  case 140: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 628 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3447 "C_grammar.tab.c"
    break;

  case 141: /* struct_or_union: STRUCT  */
#line 637 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "struct");}
#line 3453 "C_grammar.tab.c"
    break;

  case 142: /* struct_or_union: UNION  */
#line 638 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "union");}
#line 3459 "C_grammar.tab.c"
    break;

  case 143: /* struct_declaration_list: struct_declaration  */
#line 643 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3465 "C_grammar.tab.c"
    break;

  case 144: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 645 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3476 "C_grammar.tab.c"
    break;

  case 145: /* struct_declaration: specifier_qualifier_list ';'  */
#line 655 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3486 "C_grammar.tab.c"
    break;

  case 146: /* $@2: %empty  */
#line 660 "C_grammar.y"
                                   {in_member_decl_flag = 1;}
#line 3492 "C_grammar.tab.c"
    break;

  case 147: /* struct_declaration: specifier_qualifier_list $@2 struct_declarator_list ';'  */
#line 661 "C_grammar.y"
                {in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "struct_decl([%s], %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3504 "C_grammar.tab.c"
    break;

  case 148: /* struct_declaration: static_assert_declaration  */
#line 669 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3510 "C_grammar.tab.c"
    break;

  case 149: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 674 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3521 "C_grammar.tab.c"
    break;

  case 150: /* specifier_qualifier_list: type_specifier  */
#line 681 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3527 "C_grammar.tab.c"
    break;

  case 151: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 683 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3538 "C_grammar.tab.c"
    break;

  case 152: /* specifier_qualifier_list: type_qualifier  */
#line 690 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3544 "C_grammar.tab.c"
    break;

  case 153: /* struct_declarator_list: struct_declarator  */
#line 695 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3550 "C_grammar.tab.c"
    break;

  case 154: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 697 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3561 "C_grammar.tab.c"
    break;

  case 155: /* struct_declarator: ':' constant_expression  */
#line 707 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3571 "C_grammar.tab.c"
    break;

  case 156: /* struct_declarator: declarator ':' constant_expression  */
#line 713 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3582 "C_grammar.tab.c"
    break;

  case 157: /* struct_declarator: declarator  */
#line 720 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3588 "C_grammar.tab.c"
    break;

  case 158: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 725 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3598 "C_grammar.tab.c"
    break;

  case 159: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 731 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3608 "C_grammar.tab.c"
    break;

  case 160: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 737 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "enum(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3619 "C_grammar.tab.c"
    break;

  case 161: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 744 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "trailing_comma_enum(%s, [%s])", (yyvsp[-4].id), (yyvsp[-2].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
        }
#line 3630 "C_grammar.tab.c"
    break;

  case 162: /* enum_specifier: ENUM IDENTIFIER  */
#line 751 "C_grammar.y"
                {size_t const size = strlen("forward_enum()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "forward_enum(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
        }
#line 3640 "C_grammar.tab.c"
    break;

  case 163: /* enumerator_list: enumerator  */
#line 760 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3646 "C_grammar.tab.c"
    break;

  case 164: /* enumerator_list: enumerator_list ',' enumerator  */
#line 762 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3657 "C_grammar.tab.c"
    break;

  case 165: /* enumerator: enumeration_constant '=' constant_expression  */
#line 772 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_safe((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3668 "C_grammar.tab.c"
    break;

  case 166: /* enumerator: enumeration_constant  */
#line 779 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3674 "C_grammar.tab.c"
    break;

  case 168: /* type_qualifier: CONST  */
#line 787 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3680 "C_grammar.tab.c"
    break;

  case 169: /* type_qualifier: RESTRICT  */
#line 788 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3686 "C_grammar.tab.c"
    break;

  case 170: /* type_qualifier: VOLATILE  */
#line 789 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3692 "C_grammar.tab.c"
    break;

  case 171: /* type_qualifier: ATOMIC  */
#line 790 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3698 "C_grammar.tab.c"
    break;

  case 172: /* function_specifier: INLINE  */
#line 794 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3704 "C_grammar.tab.c"
    break;

  case 173: /* function_specifier: NORETURN  */
#line 795 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3710 "C_grammar.tab.c"
    break;

  case 176: /* declarator: pointer direct_declarator  */
#line 805 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_safe((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 3721 "C_grammar.tab.c"
    break;

  case 177: /* declarator: direct_declarator  */
#line 812 "C_grammar.y"
          {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3727 "C_grammar.tab.c"
    break;

  case 178: /* direct_declarator: IDENTIFIER  */
#line 817 "C_grammar.y"
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
#line 3745 "C_grammar.tab.c"
    break;

  case 179: /* direct_declarator: '(' declarator ')'  */
#line 831 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D1");}
#line 3751 "C_grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '[' ']'  */
#line 833 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D2");}
#line 3757 "C_grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 835 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D3");}
#line 3763 "C_grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 837 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D4");}
#line 3769 "C_grammar.tab.c"
    break;

  case 183: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 839 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D5");}
#line 3775 "C_grammar.tab.c"
    break;

  case 184: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 841 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D6");}
#line 3781 "C_grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 843 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D7");}
#line 3787 "C_grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 845 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D8");}
#line 3793 "C_grammar.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 847 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D9");}
#line 3799 "C_grammar.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 849 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D10");}
#line 3805 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: direct_declarator '(' ')'  */
#line 851 "C_grammar.y"
                {size_t const size = strlen("function(, [])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, [])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3815 "C_grammar.tab.c"
    break;

  case 190: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 857 "C_grammar.y"
                {size_t const size = strlen("function(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "function(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 3826 "C_grammar.tab.c"
    break;

  case 191: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 865 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D13");}
#line 3832 "C_grammar.tab.c"
    break;

  case 192: /* pointer: '*' type_qualifier_list pointer  */
#line 870 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3843 "C_grammar.tab.c"
    break;

  case 193: /* pointer: '*' type_qualifier_list  */
#line 877 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3853 "C_grammar.tab.c"
    break;

  case 194: /* pointer: '*' pointer  */
#line 883 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_safe((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3863 "C_grammar.tab.c"
    break;

  case 195: /* pointer: '*'  */
#line 889 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3869 "C_grammar.tab.c"
    break;

  case 196: /* type_qualifier_list: type_qualifier  */
#line 894 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3875 "C_grammar.tab.c"
    break;

  case 197: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 896 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3886 "C_grammar.tab.c"
    break;

  case 198: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 906 "C_grammar.y"
                {size_t const size = strlen("variable_length_args([])") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "variable_length_args([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3896 "C_grammar.tab.c"
    break;

  case 199: /* parameter_type_list: parameter_list  */
#line 912 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3906 "C_grammar.tab.c"
    break;

  case 200: /* parameter_list: parameter_declaration  */
#line 921 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3912 "C_grammar.tab.c"
    break;

  case 201: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 923 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3923 "C_grammar.tab.c"
    break;

  case 202: /* parameter_declaration: declaration_specifiers declarator  */
#line 933 "C_grammar.y"
                {size_t const size = strlen("param([], )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param([%s], %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3934 "C_grammar.tab.c"
    break;

  case 203: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 940 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3945 "C_grammar.tab.c"
    break;

  case 204: /* parameter_declaration: declaration_specifiers  */
#line 947 "C_grammar.y"
                {size_t const size = strlen("param_no_decl([], [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "param_no_decl([%s], [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3955 "C_grammar.tab.c"
    break;

  case 207: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 960 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3961 "C_grammar.tab.c"
    break;

  case 208: /* type_name: specifier_qualifier_list  */
#line 962 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3971 "C_grammar.tab.c"
    break;

  case 233: /* initializer: '{' initializer_list '}'  */
#line 1001 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3981 "C_grammar.tab.c"
    break;

  case 234: /* initializer: '{' initializer_list ',' '}'  */
#line 1007 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "trailing_comma_initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3991 "C_grammar.tab.c"
    break;

  case 235: /* initializer: assignment_expression  */
#line 1013 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3997 "C_grammar.tab.c"
    break;

  case 236: /* initializer_list: designation initializer  */
#line 1018 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4008 "C_grammar.tab.c"
    break;

  case 237: /* initializer_list: initializer  */
#line 1025 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 4014 "C_grammar.tab.c"
    break;

  case 238: /* initializer_list: initializer_list ',' designation initializer  */
#line 1027 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4026 "C_grammar.tab.c"
    break;

  case 239: /* initializer_list: initializer_list ',' initializer  */
#line 1035 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 4037 "C_grammar.tab.c"
    break;

  case 240: /* designation: designator_list '='  */
#line 1045 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "[%s]", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 4047 "C_grammar.tab.c"
    break;

  case 241: /* designator_list: designator  */
#line 1054 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 4053 "C_grammar.tab.c"
    break;

  case 242: /* designator_list: designator_list designator  */
#line 1056 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 4064 "C_grammar.tab.c"
    break;

  case 243: /* designator: '[' constant_expression ']'  */
#line 1066 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 4070 "C_grammar.tab.c"
    break;

  case 244: /* designator: '.' IDENTIFIER  */
#line 1068 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 4080 "C_grammar.tab.c"
    break;

  case 245: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1077 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_safe((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 4091 "C_grammar.tab.c"
    break;

  case 252: /* $@3: %empty  */
#line 1096 "C_grammar.y"
                {fprintf(pl_file, "label_stmt(%s, ", (yyvsp[-1].id)); 
		 free((yyvsp[-1].id));
		}
#line 4099 "C_grammar.tab.c"
    break;

  case 253: /* labeled_statement: IDENTIFIER ':' $@3 statement  */
#line 1100 "C_grammar.y"
                {fprintf(pl_file, ")");}
#line 4105 "C_grammar.tab.c"
    break;

  case 254: /* $@4: %empty  */
#line 1101 "C_grammar.y"
                                       {fprintf(pl_file, "case_stmt($2, "); free((yyvsp[-1].id));}
#line 4111 "C_grammar.tab.c"
    break;

  case 255: /* labeled_statement: CASE constant_expression ':' $@4 statement  */
#line 1101 "C_grammar.y"
                                                                                                 {fprintf(pl_file, ")");}
#line 4117 "C_grammar.tab.c"
    break;

  case 256: /* $@5: %empty  */
#line 1102 "C_grammar.y"
                      {fprintf(pl_file, "default_stmt(");}
#line 4123 "C_grammar.tab.c"
    break;

  case 257: /* labeled_statement: DEFAULT ':' $@5 statement  */
#line 1102 "C_grammar.y"
                                                                     {fprintf(pl_file, ")");}
#line 4129 "C_grammar.tab.c"
    break;

  case 258: /* compound_statement: '{' '}'  */
#line 1106 "C_grammar.y"
                  {fprintf(pl_file, "\ncmp_stmts([])");}
#line 4135 "C_grammar.tab.c"
    break;

  case 259: /* $@6: %empty  */
#line 1108 "C_grammar.y"
                        {fprintf(pl_file, "\ncmp_stmts([");}
#line 4141 "C_grammar.tab.c"
    break;

  case 260: /* compound_statement: '{' $@6 block_item_list '}'  */
#line 1111 "C_grammar.y"
                        {fprintf(pl_file, "\n])");}
#line 4147 "C_grammar.tab.c"
    break;

  case 262: /* $@7: %empty  */
#line 1116 "C_grammar.y"
                          {fprintf(pl_file, ", ");}
#line 4153 "C_grammar.tab.c"
    break;

  case 266: /* expression_statement: ';'  */
#line 1125 "C_grammar.y"
                                        {fprintf(pl_file, "stmt([])");}
#line 4159 "C_grammar.tab.c"
    break;

  case 267: /* expression_statement: expression ';'  */
#line 1126 "C_grammar.y"
                                {fprintf(pl_file, "\nstmt(%s)", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 4165 "C_grammar.tab.c"
    break;

  case 268: /* $@8: %empty  */
#line 1131 "C_grammar.y"
                {fprintf(pl_file, "\nif_stmt(branch(%d, %s), ", branch_nb++, (yyvsp[-1].id)); 
		 free((yyvsp[-1].id)); 
		}
#line 4173 "C_grammar.tab.c"
    break;

  case 269: /* selection_statement: IF '(' expression ')' $@8 statement else_opt  */
#line 1135 "C_grammar.y"
                { fprintf(pl_file, ")"); 
		}
#line 4180 "C_grammar.tab.c"
    break;

  case 270: /* $@9: %empty  */
#line 1138 "C_grammar.y"
                {fprintf(pl_file, "\nswitch_stmt(%s, ", (yyvsp[-1].id)); 
		 free((yyvsp[-1].id));
		}
#line 4188 "C_grammar.tab.c"
    break;

  case 271: /* selection_statement: SWITCH '(' expression ')' $@9 statement  */
#line 1142 "C_grammar.y"
                {fprintf(pl_file, ")");
		}
#line 4195 "C_grammar.tab.c"
    break;

  case 273: /* $@10: %empty  */
#line 1148 "C_grammar.y"
               {fprintf(pl_file, ", ");}
#line 4201 "C_grammar.tab.c"
    break;

  case 275: /* $@11: %empty  */
#line 1152 "C_grammar.y"
                {fprintf(pl_file, "\nwhile_stmt(branch(%d, %s), ", branch_nb++, (yyvsp[-1].id)); 
		 free((yyvsp[-1].id));
		}
#line 4209 "C_grammar.tab.c"
    break;

  case 276: /* iteration_statement: WHILE '(' expression ')' $@11 statement  */
#line 1156 "C_grammar.y"
                {fprintf(pl_file, ")");
		}
#line 4216 "C_grammar.tab.c"
    break;

  case 277: /* $@12: %empty  */
#line 1158 "C_grammar.y"
             {fprintf(pl_file, "\ndo_while_stmt(");}
#line 4222 "C_grammar.tab.c"
    break;

  case 278: /* iteration_statement: DO $@12 statement WHILE '(' expression ')' ';'  */
#line 1158 "C_grammar.y"
                                                                                            {fprintf(pl_file, ", %s)", (yyvsp[-2].id)); free((yyvsp[-2].id));}
#line 4228 "C_grammar.tab.c"
    break;

  case 279: /* $@13: %empty  */
#line 1159 "C_grammar.y"
                  {fprintf(pl_file, "\nfor_stmt(");}
#line 4234 "C_grammar.tab.c"
    break;

  case 280: /* $@14: %empty  */
#line 1159 "C_grammar.y"
                                                                       {fprintf(pl_file, ", ");}
#line 4240 "C_grammar.tab.c"
    break;

  case 281: /* iteration_statement: FOR '(' $@13 for_stmt_type ')' $@14 statement  */
#line 1159 "C_grammar.y"
                                                                                                           {fprintf(pl_file, ")");}
#line 4246 "C_grammar.tab.c"
    break;

  case 282: /* $@15: %empty  */
#line 1163 "C_grammar.y"
                               {fprintf(pl_file, ", ");}
#line 4252 "C_grammar.tab.c"
    break;

  case 284: /* $@16: %empty  */
#line 1164 "C_grammar.y"
                      {fprintf(pl_file, ", ");}
#line 4258 "C_grammar.tab.c"
    break;

  case 287: /* expression_opt: expression  */
#line 1169 "C_grammar.y"
                     {fprintf(pl_file, ", %s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 4264 "C_grammar.tab.c"
    break;

  case 288: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1172 "C_grammar.y"
                                {fprintf(pl_file, "\ngoto_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 4270 "C_grammar.tab.c"
    break;

  case 289: /* jump_statement: CONTINUE ';'  */
#line 1173 "C_grammar.y"
                                        {fprintf(pl_file, "\ncontinue_stmt\n");}
#line 4276 "C_grammar.tab.c"
    break;

  case 290: /* jump_statement: BREAK ';'  */
#line 1174 "C_grammar.y"
                                                {fprintf(pl_file, "\nbreak_stmt\n");}
#line 4282 "C_grammar.tab.c"
    break;

  case 291: /* jump_statement: RETURN ';'  */
#line 1175 "C_grammar.y"
                                        {fprintf(pl_file, "\nreturn_stmt\n");}
#line 4288 "C_grammar.tab.c"
    break;

  case 292: /* jump_statement: RETURN expression ';'  */
#line 1176 "C_grammar.y"
                                {fprintf(pl_file, "\nreturn_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 4294 "C_grammar.tab.c"
    break;

  case 294: /* $@17: %empty  */
#line 1182 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 4300 "C_grammar.tab.c"
    break;

  case 298: /* $@18: %empty  */
#line 1192 "C_grammar.y"
                {fprintf(pl_file, "function([%s], %s, [", (yyvsp[-1].id), (yyvsp[0].id)); 
		 free((yyvsp[-1].id)); 
		 free((yyvsp[0].id));
		}
#line 4309 "C_grammar.tab.c"
    break;

  case 299: /* $@19: %empty  */
#line 1197 "C_grammar.y"
                {fprintf(pl_file, "], ");}
#line 4315 "C_grammar.tab.c"
    break;

  case 300: /* function_definition: declaration_specifiers declarator $@18 declaration_list_opt $@19 compound_statement  */
#line 1199 "C_grammar.y"
                {fprintf(pl_file, ")");
		}
#line 4322 "C_grammar.tab.c"
    break;

  case 304: /* $@20: %empty  */
#line 1210 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 4328 "C_grammar.tab.c"
    break;


#line 4332 "C_grammar.tab.c"

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

#line 1213 "C_grammar.y"

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

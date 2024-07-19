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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "utils.h"
#include "handle_typedefs.h"

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;
extern int typedef_flag;

char pl_file_uri[_MAX_PATH];
FILE* pl_file;

void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);

int debugMode = 0;				//flag to indicate if we are in debug mode set by by -d command line switch

#line 95 "C_grammar.tab.c"

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
  YYSYMBOL_ATOMIC = 71,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 72,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 73,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 74,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 75,              /* THREAD_LOCAL  */
  YYSYMBOL_76_ = 76,                       /* '('  */
  YYSYMBOL_77_ = 77,                       /* ')'  */
  YYSYMBOL_78_ = 78,                       /* ','  */
  YYSYMBOL_79_ = 79,                       /* ':'  */
  YYSYMBOL_80_ = 80,                       /* '['  */
  YYSYMBOL_81_ = 81,                       /* ']'  */
  YYSYMBOL_82_ = 82,                       /* '.'  */
  YYSYMBOL_83_ = 83,                       /* '{'  */
  YYSYMBOL_84_ = 84,                       /* '}'  */
  YYSYMBOL_85_ = 85,                       /* '&'  */
  YYSYMBOL_86_ = 86,                       /* '*'  */
  YYSYMBOL_87_ = 87,                       /* '+'  */
  YYSYMBOL_88_ = 88,                       /* '-'  */
  YYSYMBOL_89_ = 89,                       /* '~'  */
  YYSYMBOL_90_ = 90,                       /* '!'  */
  YYSYMBOL_91_ = 91,                       /* '/'  */
  YYSYMBOL_92_ = 92,                       /* '%'  */
  YYSYMBOL_93_ = 93,                       /* '<'  */
  YYSYMBOL_94_ = 94,                       /* '>'  */
  YYSYMBOL_95_ = 95,                       /* '^'  */
  YYSYMBOL_96_ = 96,                       /* '|'  */
  YYSYMBOL_97_ = 97,                       /* '?'  */
  YYSYMBOL_98_ = 98,                       /* '='  */
  YYSYMBOL_99_ = 99,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 100,                 /* $accept  */
  YYSYMBOL_primary_expression = 101,       /* primary_expression  */
  YYSYMBOL_constant = 102,                 /* constant  */
  YYSYMBOL_enumeration_constant = 103,     /* enumeration_constant  */
  YYSYMBOL_string = 104,                   /* string  */
  YYSYMBOL_generic_selection = 105,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 106,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 107,      /* generic_association  */
  YYSYMBOL_postfix_expression = 108,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 109, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 110,         /* unary_expression  */
  YYSYMBOL_unary_inc_dec = 111,            /* unary_inc_dec  */
  YYSYMBOL_unary_operator = 112,           /* unary_operator  */
  YYSYMBOL_cast_expression = 113,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 114, /* multiplicative_expression  */
  YYSYMBOL_multiplicative_expression_op = 115, /* multiplicative_expression_op  */
  YYSYMBOL_additive_expression = 116,      /* additive_expression  */
  YYSYMBOL_additive_expression_op = 117,   /* additive_expression_op  */
  YYSYMBOL_shift_expression = 118,         /* shift_expression  */
  YYSYMBOL_shift_expression_op = 119,      /* shift_expression_op  */
  YYSYMBOL_relational_expression = 120,    /* relational_expression  */
  YYSYMBOL_relational_expression_operator = 121, /* relational_expression_operator  */
  YYSYMBOL_equality_expression = 122,      /* equality_expression  */
  YYSYMBOL_equality_expression_op = 123,   /* equality_expression_op  */
  YYSYMBOL_and_expression = 124,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 125,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 126,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 127,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 128,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 129,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 130,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 131,      /* assignment_operator  */
  YYSYMBOL_expression = 132,               /* expression  */
  YYSYMBOL_constant_expression = 133,      /* constant_expression  */
  YYSYMBOL_declaration = 134,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 135,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 136,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 137,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 138,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 139,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 140, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 141,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 142,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 143,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 144, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 145,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 146,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 147,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 148,          /* enumerator_list  */
  YYSYMBOL_enumerator = 149,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 150,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 151,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 152,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 153,      /* alignment_specifier  */
  YYSYMBOL_declarator = 154,               /* declarator  */
  YYSYMBOL_direct_declarator = 155,        /* direct_declarator  */
  YYSYMBOL_pointer = 156,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 157,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 158,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 159,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 160,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 161,          /* identifier_list  */
  YYSYMBOL_type_name = 162,                /* type_name  */
  YYSYMBOL_abstract_declarator = 163,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 164, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 165,              /* initializer  */
  YYSYMBOL_initializer_list = 166,         /* initializer_list  */
  YYSYMBOL_designation = 167,              /* designation  */
  YYSYMBOL_designator_list = 168,          /* designator_list  */
  YYSYMBOL_designator = 169,               /* designator  */
  YYSYMBOL_static_assert_declaration = 170, /* static_assert_declaration  */
  YYSYMBOL_statement = 171,                /* statement  */
  YYSYMBOL_labeled_statement = 172,        /* labeled_statement  */
  YYSYMBOL_173_1 = 173,                    /* $@1  */
  YYSYMBOL_174_2 = 174,                    /* $@2  */
  YYSYMBOL_175_3 = 175,                    /* $@3  */
  YYSYMBOL_compound_statement = 176,       /* compound_statement  */
  YYSYMBOL_177_4 = 177,                    /* $@4  */
  YYSYMBOL_block_item_list = 178,          /* block_item_list  */
  YYSYMBOL_179_5 = 179,                    /* $@5  */
  YYSYMBOL_block_item = 180,               /* block_item  */
  YYSYMBOL_expression_statement = 181,     /* expression_statement  */
  YYSYMBOL_selection_statement = 182,      /* selection_statement  */
  YYSYMBOL_183_6 = 183,                    /* $@6  */
  YYSYMBOL_184_7 = 184,                    /* $@7  */
  YYSYMBOL_else_opt = 185,                 /* else_opt  */
  YYSYMBOL_186_8 = 186,                    /* $@8  */
  YYSYMBOL_iteration_statement = 187,      /* iteration_statement  */
  YYSYMBOL_188_9 = 188,                    /* $@9  */
  YYSYMBOL_189_10 = 189,                   /* $@10  */
  YYSYMBOL_190_11 = 190,                   /* $@11  */
  YYSYMBOL_191_12 = 191,                   /* $@12  */
  YYSYMBOL_for_stmt_type = 192,            /* for_stmt_type  */
  YYSYMBOL_193_13 = 193,                   /* $@13  */
  YYSYMBOL_194_14 = 194,                   /* $@14  */
  YYSYMBOL_expression_opt = 195,           /* expression_opt  */
  YYSYMBOL_jump_statement = 196,           /* jump_statement  */
  YYSYMBOL_translation_unit = 197,         /* translation_unit  */
  YYSYMBOL_198_15 = 198,                   /* $@15  */
  YYSYMBOL_external_declaration = 199,     /* external_declaration  */
  YYSYMBOL_function_definition = 200,      /* function_definition  */
  YYSYMBOL_201_16 = 201,                   /* $@16  */
  YYSYMBOL_202_17 = 202,                   /* $@17  */
  YYSYMBOL_declaration_list_opt = 203,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 204,         /* declaration_list  */
  YYSYMBOL_205_18 = 205                    /* $@18  */
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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2012

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  106
/* YYNRULES -- Number of rules.  */
#define YYNRULES  302
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  492

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
       2,     2,     2,    90,     2,     2,     2,    92,    85,     2,
      76,    77,    86,    87,    78,    88,    82,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    99,
      93,    98,    94,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    96,    84,    89,     2,     2,     2,
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
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    66,    67,    68,    69,    73,    74,    75,
      79,    83,    84,    88,    92,    93,    97,    98,   102,   103,
     110,   116,   123,   130,   137,   143,   149,   156,   166,   167,
     177,   178,   185,   192,   198,   204,   213,   214,   218,   219,
     220,   221,   222,   223,   227,   228,   238,   239,   250,   251,
     252,   256,   257,   268,   269,   273,   274,   285,   286,   290,
     291,   302,   303,   304,   305,   310,   311,   322,   323,   327,
     328,   338,   339,   349,   350,   360,   361,   371,   372,   382,
     383,   394,   395,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   420,   421,   431,   435,   439,   447,
     454,   461,   462,   469,   470,   472,   474,   476,   478,   480,
     485,   486,   496,   503,   512,   516,   517,   518,   519,   520,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   543,   550,   558,   568,
     569,   573,   575,   585,   591,   598,   603,   610,   612,   619,
     624,   626,   636,   642,   649,   654,   655,   656,   657,   658,
     662,   663,   667,   668,   672,   676,   677,   678,   679,   683,
     684,   688,   689,   693,   700,   705,   706,   707,   708,   709,
     710,   711,   712,   713,   714,   715,   716,   717,   718,   722,
     729,   735,   741,   746,   747,   757,   758,   762,   763,   767,
     768,   769,   773,   774,   778,   779,   783,   784,   785,   789,
     790,   791,   792,   793,   794,   795,   796,   797,   798,   799,
     800,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     813,   819,   825,   830,   837,   839,   847,   857,   866,   868,
     878,   880,   889,   899,   900,   901,   902,   903,   904,   908,
     908,   909,   909,   910,   910,   914,   915,   915,   919,   920,
     920,   924,   925,   929,   930,   934,   934,   935,   935,   939,
     940,   940,   943,   943,   944,   944,   945,   945,   945,   949,
     949,   950,   950,   954,   955,   958,   959,   960,   961,   962,
     966,   967,   967,   971,   972,   976,   976,   976,   980,   981,
     985,   986,   986
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
  "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT",
  "THREAD_LOCAL", "'('", "')'", "','", "':'", "'['", "']'", "'.'", "'{'",
  "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
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
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement", "$@1",
  "$@2", "$@3", "compound_statement", "$@4", "block_item_list", "$@5",
  "block_item", "expression_statement", "selection_statement", "$@6",
  "$@7", "else_opt", "$@8", "iteration_statement", "$@9", "$@10", "$@11",
  "$@12", "for_stmt_type", "$@13", "$@14", "expression_opt",
  "jump_statement", "translation_unit", "$@15", "external_declaration",
  "function_definition", "$@16", "$@17", "declaration_list_opt",
  "declaration_list", "$@18", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-419)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-300)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1784,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,    36,   -49,   -33,  -419,    -8,
    -419,  -419,    97,  1889,  1889,  -419,    61,  -419,  -419,  1889,
    1889,  1889,  -419,    84,  -419,  -419,    37,   158,   738,   661,
    1352,  -419,    13,   198,  -419,   -68,  -419,   -36,   -15,    11,
    -419,  -419,    55,  1447,  -419,  -419,  -419,  -419,  1784,   158,
    -419,    73,   -52,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    1440,  -419,  -419,   133,   136,   738,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,   167,  -419,  1461,  1352,
    -419,   114,    40,   173,   129,   199,   131,   119,   146,   207,
      39,  -419,   154,   661,   105,   661,   168,   171,   166,   177,
    -419,  -419,  -419,   198,    13,  -419,  1222,  1784,  1680,   685,
     -15,  1447,   365,  -419,    64,  -419,  -419,    -1,  1352,    25,
    -419,   738,  -419,   661,  1352,   503,  -419,  -419,   142,   183,
     265,  -419,  -419,  1310,  1352,   269,   738,  -419,  -419,  -419,
    -419,  -419,  1352,  -419,  -419,  1352,  -419,  -419,  1352,  -419,
    -419,  -419,  -419,  1352,  -419,  -419,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  -419,  -419,  1575,   826,   127,  -419,   135,
    -419,  -419,  -419,   277,  -419,  -419,  -419,  -419,   188,  1201,
    -419,  -419,  -419,    97,  -419,   205,  -419,  -419,    76,   210,
     212,  -419,   147,  1071,  -419,   211,   213,   849,  1627,  -419,
    -419,  1352,  -419,   -54,  -419,   217,    33,  -419,  -419,  -419,
    -419,   220,   221,   224,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  1352,  -419,  1352,  1331,  -419,
    -419,   152,  -419,   -28,  -419,   222,  -419,   114,    40,   173,
     129,   199,   131,   119,   146,   207,   162,  -419,   226,   227,
    1071,  -419,   228,   229,   937,   135,  1732,   960,   231,  1352,
     312,  -419,   106,  1222,   -61,  -419,   233,  1784,  1520,  -419,
      79,  -419,  -419,  1836,  -419,   314,   238,  1071,  -419,  -419,
    1352,  -419,   239,   240,  -419,  -419,    78,  -419,  1352,  -419,
     242,  -419,  1941,  -419,  -419,  1201,  -419,  -419,  1352,  -419,
     242,  1352,  -419,  -419,   247,  1071,  -419,  -419,  1352,  -419,
     248,  -419,   246,  1071,  -419,   250,   252,  1048,   237,   257,
    -419,  1092,  -419,  -419,  -419,  -419,   255,  -419,  -419,  -419,
    -419,  -419,  -419,   259,   260,  -419,  -419,  -419,  -419,   263,
     175,  -419,   266,   124,  -419,  -419,  -419,   270,   271,  -419,
    -419,   278,  1071,  -419,  -419,  1352,  -419,   280,  -419,  -419,
    -419,  -419,  1222,  -419,   421,  -419,  -419,  1352,  -419,  1941,
    1352,  1180,  -419,  -419,  -419,  -419,   281,   282,  -419,  -419,
     267,  1352,   268,   288,   289,   290,  -419,   291,   341,   272,
     273,   597,  -419,   -29,  -419,  -419,  -419,  -419,   274,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,   294,  -419,  1352,  1352,  1352,   562,  -419,   275,  -419,
    -419,  -419,   -21,  -419,  -419,   421,   562,  -419,   562,   179,
     187,   193,   306,   509,  -419,  -419,  -419,  -419,   562,  -419,
    -419,  -419,  -419,   300,  -419,  -419,   302,  -419,   562,   562,
     562,  1352,   650,   650,  -419,   317,  -419,  -419,   204,  1352,
    1352,   562,  -419,  -419,   283,   303,  -419,  -419,  -419,   562,
    -419,  -419
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   135,   114,   115,   116,   118,   119,   169,   165,   166,
     167,   129,   121,   122,   123,   124,   127,   128,   125,   126,
     120,   130,   131,   139,   140,     0,     0,   168,   170,     0,
     117,   294,     0,   101,   103,   133,     0,   134,   132,   105,
     107,   109,    99,   291,   290,   293,   159,     0,     0,     0,
       0,   175,     0,   192,    97,     0,   110,   295,   174,     0,
     100,   102,   138,     0,   104,   106,   108,     1,     0,     0,
      10,   163,     0,   160,     2,     7,     8,     9,    11,    12,
       0,    36,    37,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    18,     3,     4,     6,    30,    44,     0,     0,
      46,    51,    55,    59,    65,    69,    71,    73,    75,    77,
      79,    96,     0,   147,   205,   149,     0,     0,     0,     0,
     168,   193,   191,   190,     0,    98,     0,   298,     0,     0,
     173,     0,     0,   141,     0,   145,   292,     0,     0,     0,
     155,     0,    33,     0,     0,    44,    81,    94,     0,     0,
       0,    24,    25,     0,     0,     0,     0,    31,    32,    48,
      49,    50,     0,    53,    54,     0,    57,    58,     0,    63,
      64,    61,    62,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,   172,   146,     0,     0,   207,   204,   208,
     148,   171,   164,     0,   176,   194,   189,   111,   113,     0,
     232,   112,   300,     0,   296,   301,   202,   187,   201,     0,
     196,   197,     0,     0,   177,    39,     0,     0,     0,   136,
     142,     0,   143,     0,   150,   154,     0,   157,   162,   156,
     161,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    83,     0,     5,     0,     0,    23,
      20,     0,    28,     0,    22,     0,    47,    52,    56,    60,
      66,    70,    72,    74,    76,    78,     0,   226,     0,     0,
       0,   210,    39,     0,     0,   206,     0,     0,     0,     0,
       0,   234,     0,     0,     0,   238,     0,     0,     0,   199,
     207,   200,   186,     0,   188,     0,     0,     0,   178,   185,
       0,   184,    39,     0,   137,   152,     0,   144,     0,   158,
      34,    35,     0,    82,    95,     0,    45,    21,     0,    19,
       0,     0,   227,   209,     0,     0,   211,   217,     0,   216,
       0,   228,     0,     0,   218,    39,     0,     0,     0,     0,
     241,     0,   230,   233,   237,   239,   256,   297,   302,   195,
     198,   203,   180,     0,     0,   181,   183,   151,   153,     0,
       0,    14,     0,     0,    29,    80,   213,     0,     0,   215,
     229,     0,     0,   219,   225,     0,   224,     0,   242,   240,
     231,   236,     0,   255,     0,   179,   182,     0,    13,     0,
       0,     0,    26,   212,   214,   221,     0,     0,   222,   235,
       2,     0,     0,     0,     0,     0,   274,     0,     0,     0,
       0,     0,   263,     0,   261,   262,   243,   244,   259,   258,
     245,   246,   247,   248,    17,    15,    16,    27,   220,   223,
     249,     0,   253,     0,     0,     0,     0,   276,     0,   286,
     287,   288,     0,   264,   257,     0,     0,   251,     0,     0,
       0,     0,     0,     0,   285,   289,   260,   250,     0,   254,
     265,   267,   272,     0,   281,   279,     0,   252,     0,     0,
       0,     0,     0,     0,   277,   269,   268,   273,     0,   283,
     283,     0,   270,   266,     0,   284,   282,   280,   278,     0,
     275,   271
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -419,  -419,  -419,  -419,  -419,  -419,  -419,    -9,  -419,  -419,
     -47,  -419,  -419,   -76,   218,  -419,   216,  -419,   214,  -419,
     215,  -419,   219,  -419,   243,   223,   209,   241,  -419,   -46,
      60,  -419,   -85,   -45,  -118,     7,  -419,   276,  -419,    10,
    -419,  -419,   261,  -107,   -25,  -419,    92,  -419,   321,  -121,
    -419,   -19,  -419,  -419,   -26,   -51,   -38,  -112,  -116,  -419,
     130,  -419,    54,   -94,  -174,  -115,   122,  -319,  -419,   156,
      17,  -157,  -419,  -419,  -419,  -419,   155,  -419,  -419,  -419,
      -7,  -418,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,   -37,  -419,  -419,  -419,   376,
    -419,  -419,  -419,  -419,  -419,  -419
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    71,    94,    95,   360,   361,    96,   251,
     145,    98,    99,   100,   101,   162,   102,   165,   103,   168,
     104,   173,   105,   176,   106,   107,   108,   109,   110,   146,
     147,   245,   413,   112,    31,   203,    55,    56,    33,    34,
      35,    36,   132,   133,   114,   223,   224,    37,    72,    73,
      38,    39,    40,    41,   119,    58,    59,   123,   268,   210,
     211,   212,   362,   269,   189,   281,   282,   283,   284,   285,
      42,   415,   416,   446,   458,   448,   417,   384,   418,   445,
     419,   420,   421,   468,   469,   483,   489,   422,   470,   436,
     453,   481,   466,   473,   472,   486,   423,    43,    68,    44,
      45,   127,   286,   204,   205,   287
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     148,    97,   111,    97,   111,   118,    57,    32,   130,   202,
     124,   201,   209,   275,    51,   122,    51,   217,   230,   279,
     188,   280,   382,   158,   306,   220,   139,    48,    70,   115,
     115,   125,   140,   142,   121,   465,    70,   344,   134,    46,
      60,    61,  -113,    49,   115,   307,    64,    65,    66,   247,
     247,   157,    97,   319,   479,   480,   148,   247,   113,   113,
     181,   128,   126,  -113,    62,   129,   115,    51,    50,   253,
     443,   148,   382,   113,   274,    32,   187,   226,   455,    51,
     135,    51,    51,   227,    67,   196,   256,    52,   184,    52,
     190,    97,   111,   228,   115,   113,   115,   266,   198,    53,
      51,   297,   116,   117,   195,   230,   134,   134,   225,   229,
     121,   220,   115,   115,   291,    97,   275,   309,    97,    47,
      69,    97,   115,   113,   115,   113,    97,   163,   164,    97,
      97,    97,    97,    97,    97,   208,   182,   115,   131,   149,
      52,   113,   113,   221,    63,   169,   170,   187,   135,   135,
      53,   113,   288,   113,    52,   288,   186,   221,   325,   186,
     332,    70,    53,   222,    53,   337,   113,   121,   343,   348,
     290,   138,   316,    52,    97,   111,   305,   198,   150,   151,
     152,   185,   289,    53,   341,   186,   200,   166,   167,   216,
     342,    53,   208,   134,   121,   231,    54,   232,   195,   115,
     159,    97,   391,   185,   233,   160,   161,   186,   392,   143,
     255,   276,   144,   252,   178,   277,   177,   174,   175,   246,
     247,   372,   171,   172,   294,   295,   381,   180,   113,   317,
     318,   183,    97,   111,   339,   135,     8,     9,    10,   130,
     247,   321,   179,   153,   193,   191,   273,   154,   192,   155,
     290,   121,   388,   389,   194,   195,   460,   247,   121,   200,
     248,    97,   111,   358,   461,   247,   414,   399,   249,   120,
     462,   247,   254,   296,    97,   365,   381,   303,   195,   452,
     225,   484,   247,   208,    53,   278,   126,   292,  -299,   457,
     293,   459,   298,   115,   299,   208,   308,   310,   311,   320,
     208,   467,   312,   322,   323,   313,   195,   314,   338,   326,
     327,   475,   476,   477,   121,   340,   346,   351,   195,   352,
     355,   356,   113,   370,   488,   315,   442,   414,   366,   369,
     324,   373,   491,   374,   330,   464,   378,   336,   379,   383,
     385,   386,   387,   200,   438,   390,   430,   432,   449,   450,
     451,   393,   394,   195,    97,   111,   431,   353,   444,   395,
     354,   398,   428,   429,   433,   434,   435,   437,   463,     1,
     115,   439,   440,   447,   454,   200,   471,   482,   364,   474,
     425,   247,   490,   257,   258,   367,   478,   259,   368,   264,
     137,   260,   218,   371,   485,   485,   261,   377,   357,   113,
     197,   200,   263,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   262,   265,   350,   400,     1,    75,    76,    77,    78,
      79,    80,   396,    81,    82,   397,    27,   363,   456,    29,
     345,   347,   200,   487,   136,     0,     0,   424,     0,   219,
     426,   200,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   401,   402,
     403,     0,   404,   405,   406,   407,   408,   409,   410,   411,
      26,    83,    27,    84,    28,    29,    30,    85,     0,     0,
       0,     0,     0,     0,   346,     0,    86,    87,    88,    89,
      90,    91,    74,     1,    75,    76,    77,    78,    79,    80,
     412,    81,    82,     0,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   400,     0,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,    26,    83,
      27,    84,    28,    29,    30,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      74,   244,    75,    76,    77,    78,    79,    80,   412,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,   401,
     402,   403,     0,   404,   405,   406,   407,   408,   409,   410,
     411,     0,    83,     0,    84,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,   346,     0,    86,    87,    88,
      89,    90,    91,    74,     0,    75,    76,    77,    78,    79,
      80,   412,    81,    82,     0,     1,     0,    83,     0,    84,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    74,     0,
      75,    76,    77,    78,    79,    80,   441,    81,    82,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,   213,
      83,     0,    84,     8,     9,    10,    85,     0,     0,     0,
       0,     0,    27,     0,     0,    86,    87,    88,    89,    90,
      91,    74,     1,    75,    76,    77,    78,    79,    80,   412,
      81,    82,     0,     0,     0,    83,   120,    84,     0,     0,
       0,    85,     0,     0,     0,     0,   214,     0,     0,     0,
      86,   215,    88,    89,    90,    91,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    27,
      84,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,    74,
       0,    75,    76,    77,    78,    79,    80,     0,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,    75,    76,    77,    78,    79,    80,
     270,    81,    82,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   300,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,    83,   120,    84,     0,
       0,     0,    85,     0,     0,     0,     0,   271,     0,     0,
       0,    86,   272,    88,    89,    90,    91,     0,     0,    83,
     120,    84,     0,     0,     0,    85,     0,     0,     0,     0,
     301,     0,     0,     0,    86,   302,    88,    89,    90,    91,
      74,     0,    75,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    76,    77,    78,    79,
      80,   328,    81,    82,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,    83,   120,    84,
       0,     0,     0,    85,     0,     0,     0,     0,   329,     0,
       0,     0,    86,    87,    88,    89,    90,    91,     0,     0,
      83,   120,    84,     0,     0,     0,    85,     0,     0,     0,
       0,   334,     0,     0,     0,    86,   335,    88,    89,    90,
      91,    74,     0,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    80,   375,    81,    82,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    83,   120,
      84,     0,     0,     0,    85,     0,     0,     0,     0,   376,
       0,     0,     0,    86,    87,    88,    89,    90,    91,     0,
       0,    83,   120,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    83,     0,    84,     0,     0,     0,    85,     0,
       0,     0,   279,     0,   280,   199,   380,    86,    87,    88,
      89,    90,    91,    74,     0,    75,    76,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    84,     0,     0,     0,    85,     0,     0,     0,
     279,     0,   280,   199,   427,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,    85,     0,     0,
       0,   279,     0,   280,   199,     0,    86,    87,    88,    89,
      90,    91,    83,     0,    84,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,   199,     0,    86,    87,    88,
      89,    90,    91,    74,     0,    75,    76,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    84,     0,     0,     0,    85,   250,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,   315,     0,    86,    87,    88,    89,
      90,    91,    83,     0,    84,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    74,     0,    75,    76,    77,    78,    79,
      80,     1,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    84,     0,     0,     0,   141,     0,    27,     0,
       0,    29,     0,    51,     1,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,     0,    30,   288,   267,     0,     0,
     186,     0,     0,     0,     0,     0,    53,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,     0,
      30,   185,   267,     0,     0,   186,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   206,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,     0,    30,     0,   207,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,   331,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   349,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      85,    48,    48,    50,    50,    50,    32,     0,    59,   127,
      78,   126,   128,   187,     3,    53,     3,   129,   139,    80,
     114,    82,   341,    99,    78,   132,    78,    76,     3,    48,
      49,    99,    84,    80,    53,   453,     3,    98,    63,     3,
      33,    34,    78,    76,    63,    99,    39,    40,    41,    78,
      78,    98,    99,    81,   472,   473,   141,    78,    48,    49,
      21,    76,    98,    99,     3,    80,    85,     3,    76,   154,
      99,   156,   391,    63,   186,    68,   114,    78,    99,     3,
      63,     3,     3,    84,     0,   123,   162,    76,   113,    76,
     115,   138,   138,   138,   113,    85,   115,   182,   124,    86,
       3,   213,    48,    49,   123,   226,   131,   132,   134,    84,
     129,   218,   131,   132,   208,   162,   290,    84,   165,    83,
      83,   168,   141,   113,   143,   115,   173,    87,    88,   176,
     177,   178,   179,   180,   181,   128,    97,   156,    83,    85,
      76,   131,   132,    79,    83,    16,    17,   185,   131,   132,
      86,   141,    76,   143,    76,    76,    80,    79,   270,    80,
     276,     3,    86,    99,    86,   277,   156,   186,   283,   287,
     208,    98,   248,    76,   221,   221,   221,   203,    11,    12,
      13,    76,   208,    86,    78,    80,   126,    14,    15,   129,
      84,    86,   185,   218,   213,   141,    99,   143,   217,   218,
      86,   248,    78,    76,   144,    91,    92,    80,    84,    76,
     156,    76,    76,   153,    95,    80,    85,    18,    19,    77,
      78,   333,    93,    94,    77,    78,   341,    20,   218,    77,
      78,    77,   279,   279,   279,   218,    38,    39,    40,   290,
      78,    79,    96,    76,    78,    77,   186,    80,    77,    82,
     288,   270,    77,    78,    77,   274,    77,    78,   277,   199,
      77,   308,   308,   308,    77,    78,   384,   382,     3,    71,
      77,    78,     3,   213,   321,   321,   391,   217,   297,   436,
     306,    77,    78,   276,    86,     8,    98,    77,    83,   446,
      78,   448,    81,   312,    81,   288,    79,    77,    77,    77,
     293,   458,    78,    77,    77,   245,   325,   247,    77,    81,
      81,   468,   469,   470,   333,     3,    83,     3,   337,    81,
      81,    81,   312,    77,   481,    83,   411,   445,    81,    81,
     270,    81,   489,    81,   274,   453,    99,   277,    81,    84,
      81,    81,    79,   283,     3,    79,    79,    79,   433,   434,
     435,    81,    81,   372,   401,   401,   401,   297,    84,    81,
     300,    81,    81,    81,    76,    76,    76,    76,    62,     4,
     389,    99,    99,    79,    99,   315,    76,    60,   318,    77,
     389,    78,    99,   165,   168,   325,   471,   173,   328,   180,
      69,   176,   131,   333,   479,   480,   177,   337,   306,   389,
     124,   341,   179,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   178,   181,   293,     3,     4,     5,     6,     7,     8,
       9,    10,   372,    12,    13,   375,    71,   315,   445,    74,
     284,   286,   382,   480,    68,    -1,    -1,   387,    -1,    84,
     390,   391,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,     8,     9,    10,
      99,    12,    13,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       3,    98,     5,     6,     7,     8,     9,    10,    99,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,     3,    -1,     5,     6,     7,     8,     9,
      10,    99,    12,    13,    -1,     4,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,     3,    -1,
       5,     6,     7,     8,     9,    10,    99,    12,    13,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    34,
      70,    -1,    72,    38,    39,    40,    76,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    85,    86,    87,    88,    89,
      90,     3,     4,     5,     6,     7,     8,     9,    10,    99,
      12,    13,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,     3,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      34,    12,    13,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    34,    12,    13,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    34,    12,    13,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,     3,    -1,     5,     6,     7,     8,     9,
      10,     4,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    71,    -1,
      -1,    74,    -1,     3,     4,    85,    86,    87,    88,    89,
      90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    76,    77,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    86,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    76,    77,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    73,    74,
      75,   134,   135,   138,   139,   140,   141,   147,   150,   151,
     152,   153,   170,   197,   199,   200,     3,    83,    76,    76,
      76,     3,    76,    86,    99,   136,   137,   154,   155,   156,
     135,   135,     3,    83,   135,   135,   135,     0,   198,    83,
       3,   103,   148,   149,     3,     5,     6,     7,     8,     9,
      10,    12,    13,    70,    72,    76,    85,    86,    87,    88,
      89,    90,   101,   102,   104,   105,   108,   110,   111,   112,
     113,   114,   116,   118,   120,   122,   124,   125,   126,   127,
     128,   129,   133,   139,   144,   151,   162,   162,   133,   154,
      71,   151,   156,   157,    78,    99,    98,   201,    76,    80,
     155,    83,   142,   143,   144,   170,   199,   148,    98,    78,
      84,    76,   110,    76,    76,   110,   129,   130,   132,   162,
      11,    12,    13,    76,    80,    82,    76,   110,   113,    86,
      91,    92,   115,    87,    88,   117,    14,    15,   119,    16,
      17,    93,    94,   121,    18,    19,   123,    85,    95,    96,
      20,    21,    97,    77,   144,    76,    80,   156,   163,   164,
     144,    77,    77,    78,    77,   151,   156,   137,   154,    83,
     130,   165,   134,   135,   203,   204,     3,    77,   135,   158,
     159,   160,   161,    34,    81,    86,   130,   157,   142,    84,
     143,    79,    99,   145,   146,   154,    78,    84,   133,    84,
     149,   162,   162,   130,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    98,   131,    77,    78,    77,     3,
      77,   109,   130,   132,     3,   162,   113,   114,   116,   118,
     120,   122,   124,   125,   126,   127,   132,    77,   158,   163,
      34,    81,    86,   130,   157,   164,    76,    80,     8,    80,
      82,   165,   166,   167,   168,   169,   202,   205,    76,   154,
     156,   163,    77,    78,    77,    78,   130,   157,    81,    81,
      34,    81,    86,   130,    84,   133,    78,    99,    79,    84,
      77,    77,    78,   130,   130,    83,   113,    77,    78,    81,
      77,    79,    77,    77,   130,   157,    81,    81,    34,    81,
     130,    77,   158,    34,    81,    86,   130,   157,    77,   133,
       3,    78,    84,   165,    98,   169,    83,   176,   134,    56,
     160,     3,    81,   130,   130,    81,    81,   146,   133,    58,
     106,   107,   162,   166,   130,   129,    81,   130,   130,    81,
      77,   130,   157,    81,    81,    34,    81,   130,    99,    81,
      84,   165,   167,    84,   177,    81,    81,    79,    77,    78,
      79,    78,    84,    81,    81,    81,   130,   130,    81,   165,
       3,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    99,   132,   134,   171,   172,   176,   178,   180,
     181,   182,   187,   196,   130,   107,   130,    84,    81,    81,
      79,   133,    79,    76,    76,    76,   189,    76,     3,    99,
      99,    99,   132,    99,    84,   179,   173,    79,   175,   132,
     132,   132,   171,   190,    99,    99,   180,   171,   174,   171,
      77,    77,    77,    62,   134,   181,   192,   171,   183,   184,
     188,    76,   194,   193,    77,   171,   171,   171,   132,   181,
     181,   191,    60,   185,    77,   132,   195,   195,   171,   186,
      99,   171
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   101,   102,   102,   102,
     103,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   133,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   140,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   146,   146,   146,   147,   147,   147,   147,   147,
     148,   148,   149,   149,   150,   151,   151,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   156,
     156,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   160,   161,   161,   162,   162,   163,   163,   163,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     165,   165,   165,   166,   166,   166,   166,   167,   168,   168,
     169,   169,   170,   171,   171,   171,   171,   171,   171,   173,
     172,   174,   172,   175,   172,   176,   177,   176,   178,   179,
     178,   180,   180,   181,   181,   183,   182,   184,   182,   185,
     186,   185,   188,   187,   189,   187,   190,   191,   187,   193,
     192,   194,   192,   195,   195,   196,   196,   196,   196,   196,
     197,   198,   197,   199,   199,   201,   202,   200,   203,   203,
     204,   205,   204
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
       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
       1,     3,     2,     3,     1,     4,     5,     5,     6,     2,
       1,     3,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     4,     4,     2,     1,     1,     3,     3,     4,     6,
       5,     5,     6,     5,     4,     4,     4,     3,     4,     3,
       2,     2,     1,     1,     2,     3,     1,     1,     3,     2,
       2,     1,     1,     3,     2,     1,     2,     1,     1,     3,
       2,     3,     5,     4,     5,     4,     3,     3,     3,     4,
       6,     5,     5,     6,     4,     4,     2,     3,     3,     4,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     7,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     5,     0,     4,     2,     0,     4,     1,     0,
       3,     1,     1,     1,     2,     0,     7,     0,     6,     0,
       0,     3,     0,     6,     0,     8,     0,     0,     7,     0,
       4,     0,     4,     0,     1,     3,     2,     2,     2,     3,
       1,     0,     3,     1,     1,     0,     0,     6,     0,     1,
       1,     0,     3
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
#line 65 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 1985 "C_grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 66 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 1991 "C_grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 67 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 1997 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 68 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "prim4");}
#line 2003 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: generic_selection  */
#line 69 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2009 "C_grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 73 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2015 "C_grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 74 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2021 "C_grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 75 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2027 "C_grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 79 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2033 "C_grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 83 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2039 "C_grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 84 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2045 "C_grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 102 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2051 "C_grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 104 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2062 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 111 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s([])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2072 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 117 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2083 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 124 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2094 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 131 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2105 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 138 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2115 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 144 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2125 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 150 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2136 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 157 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2147 "C_grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 166 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2153 "C_grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 168 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2164 "C_grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 177 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2170 "C_grammar.tab.c"
    break;

  case 31: /* unary_expression: unary_inc_dec unary_expression  */
#line 179 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2181 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_operator cast_expression  */
#line 186 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2192 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: SIZEOF unary_expression  */
#line 193 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2202 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 199 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2212 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 205 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2222 "C_grammar.tab.c"
    break;

  case 36: /* unary_inc_dec: INC_OP  */
#line 213 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2228 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: DEC_OP  */
#line 214 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2234 "C_grammar.tab.c"
    break;

  case 38: /* unary_operator: '&'  */
#line 218 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "address_of_op");}
#line 2240 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '*'  */
#line 219 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "dereference_op");}
#line 2246 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '+'  */
#line 220 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2252 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '-'  */
#line 221 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2258 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '~'  */
#line 222 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "one_comp_op");}
#line 2264 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '!'  */
#line 223 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2270 "C_grammar.tab.c"
    break;

  case 44: /* cast_expression: unary_expression  */
#line 227 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2276 "C_grammar.tab.c"
    break;

  case 45: /* cast_expression: '(' type_name ')' cast_expression  */
#line 229 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2287 "C_grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: cast_expression  */
#line 238 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2293 "C_grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 240 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2305 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression_op: '*'  */
#line 250 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2311 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '/'  */
#line 251 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2317 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '%'  */
#line 252 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2323 "C_grammar.tab.c"
    break;

  case 51: /* additive_expression: multiplicative_expression  */
#line 256 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2329 "C_grammar.tab.c"
    break;

  case 52: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 258 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2341 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression_op: '+'  */
#line 268 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2347 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '-'  */
#line 269 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2353 "C_grammar.tab.c"
    break;

  case 55: /* shift_expression: additive_expression  */
#line 273 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2359 "C_grammar.tab.c"
    break;

  case 56: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 275 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2371 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression_op: LEFT_OP  */
#line 285 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift_op");}
#line 2377 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: RIGHT_OP  */
#line 286 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift_op");}
#line 2383 "C_grammar.tab.c"
    break;

  case 59: /* relational_expression: shift_expression  */
#line 290 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2389 "C_grammar.tab.c"
    break;

  case 60: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 292 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2401 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression_operator: '<'  */
#line 302 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2407 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '>'  */
#line 303 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2413 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: LE_OP  */
#line 304 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2419 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: GE_OP  */
#line 305 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2425 "C_grammar.tab.c"
    break;

  case 65: /* equality_expression: relational_expression  */
#line 310 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2431 "C_grammar.tab.c"
    break;

  case 66: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 312 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2443 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression_op: EQ_OP  */
#line 322 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2449 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: NE_OP  */
#line 323 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2455 "C_grammar.tab.c"
    break;

  case 69: /* and_expression: equality_expression  */
#line 327 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2461 "C_grammar.tab.c"
    break;

  case 70: /* and_expression: and_expression '&' equality_expression  */
#line 329 "C_grammar.y"
                {size_t const size = strlen("bitw_and(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_and(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2472 "C_grammar.tab.c"
    break;

  case 71: /* exclusive_or_expression: and_expression  */
#line 338 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2478 "C_grammar.tab.c"
    break;

  case 72: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 340 "C_grammar.y"
                {size_t const size = strlen("bitw_excl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_excl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2489 "C_grammar.tab.c"
    break;

  case 73: /* inclusive_or_expression: exclusive_or_expression  */
#line 349 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2495 "C_grammar.tab.c"
    break;

  case 74: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 351 "C_grammar.y"
                {size_t const size = strlen("bitw_incl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_incl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2506 "C_grammar.tab.c"
    break;

  case 75: /* logical_and_expression: inclusive_or_expression  */
#line 360 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2512 "C_grammar.tab.c"
    break;

  case 76: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 362 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2523 "C_grammar.tab.c"
    break;

  case 77: /* logical_or_expression: logical_and_expression  */
#line 371 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2529 "C_grammar.tab.c"
    break;

  case 78: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 373 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2540 "C_grammar.tab.c"
    break;

  case 79: /* conditional_expression: logical_or_expression  */
#line 382 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2546 "C_grammar.tab.c"
    break;

  case 80: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 384 "C_grammar.y"
                {size_t const size = strlen("cond_exp(, , )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "cond_exp(%s, %s, %s)", (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2558 "C_grammar.tab.c"
    break;

  case 81: /* assignment_expression: conditional_expression  */
#line 394 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2564 "C_grammar.tab.c"
    break;

  case 82: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 396 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2576 "C_grammar.tab.c"
    break;

  case 83: /* assignment_operator: '='  */
#line 406 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2582 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: MUL_ASSIGN  */
#line 407 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2588 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: DIV_ASSIGN  */
#line 408 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2594 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: MOD_ASSIGN  */
#line 409 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2600 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: ADD_ASSIGN  */
#line 410 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2606 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: SUB_ASSIGN  */
#line 411 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2612 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: LEFT_ASSIGN  */
#line 412 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2618 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: RIGHT_ASSIGN  */
#line 413 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2624 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: AND_ASSIGN  */
#line 414 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2630 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: XOR_ASSIGN  */
#line 415 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2636 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: OR_ASSIGN  */
#line 416 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2642 "C_grammar.tab.c"
    break;

  case 94: /* expression: assignment_expression  */
#line 420 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2648 "C_grammar.tab.c"
    break;

  case 95: /* expression: expression ',' assignment_expression  */
#line 422 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2659 "C_grammar.tab.c"
    break;

  case 96: /* constant_expression: conditional_expression  */
#line 431 "C_grammar.y"
                                                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2665 "C_grammar.tab.c"
    break;

  case 97: /* declaration: declaration_specifiers ';'  */
#line 436 "C_grammar.y"
                {fprintf(pl_file, "declaration([%s])\n", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2673 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 440 "C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
	     fprintf(pl_file, "declaration([%s], [%s])\n", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	  }
#line 2685 "C_grammar.tab.c"
    break;

  case 99: /* declaration: static_assert_declaration  */
#line 448 "C_grammar.y"
                {fprintf(pl_file, "%s\n", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2693 "C_grammar.tab.c"
    break;

  case 100: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 455 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2704 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier  */
#line 461 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2710 "C_grammar.tab.c"
    break;

  case 102: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 463 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2721 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier  */
#line 469 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2727 "C_grammar.tab.c"
    break;

  case 104: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 471 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier declaration_specifiers"); }
#line 2733 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier  */
#line 473 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier"); }
#line 2739 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 475 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier declaration_specifiers"); }
#line 2745 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier  */
#line 477 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier"); }
#line 2751 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 479 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier declaration_specifiers"); }
#line 2757 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier  */
#line 481 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier"); }
#line 2763 "C_grammar.tab.c"
    break;

  case 110: /* init_declarator_list: init_declarator  */
#line 485 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2769 "C_grammar.tab.c"
    break;

  case 111: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 487 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 2780 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator: declarator '=' initializer  */
#line 497 "C_grammar.y"
          {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_s((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   //free($3);
	  }
#line 2791 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator  */
#line 504 "C_grammar.y"
          {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name((yyvsp[0].id));
	   }
	   simple_str_copy(&(yyval.id), (yyvsp[0].id));
	  }
#line 2801 "C_grammar.tab.c"
    break;

  case 114: /* storage_class_specifier: TYPEDEF  */
#line 513 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
	    }
#line 2809 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: EXTERN  */
#line 516 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 2815 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: STATIC  */
#line 517 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 2821 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: THREAD_LOCAL  */
#line 518 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 2827 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: AUTO  */
#line 519 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 2833 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: REGISTER  */
#line 520 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 2839 "C_grammar.tab.c"
    break;

  case 120: /* type_specifier: VOID  */
#line 524 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 2845 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: CHAR  */
#line 525 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 2851 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: SHORT  */
#line 526 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 2857 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: INT  */
#line 527 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 2863 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: LONG  */
#line 528 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 2869 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: FLOAT  */
#line 529 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 2875 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: DOUBLE  */
#line 530 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 2881 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: SIGNED  */
#line 531 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 2887 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: UNSIGNED  */
#line 532 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 2893 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: BOOL  */
#line 533 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 2899 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: COMPLEX  */
#line 534 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 2905 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: IMAGINARY  */
#line 535 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 2911 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: atomic_type_specifier  */
#line 536 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 2917 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: struct_or_union_specifier  */
#line 537 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2923 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: enum_specifier  */
#line 538 "C_grammar.y"
                                        { simple_str_lit_copy(&(yyval.id), "enum_specifier"); }
#line 2929 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: TYPEDEF_NAME  */
#line 539 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2935 "C_grammar.tab.c"
    break;

  case 136: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 544 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
	    }
#line 2946 "C_grammar.tab.c"
    break;

  case 137: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 551 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s(%s, [%s])", (yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
	    }
#line 2958 "C_grammar.tab.c"
    break;

  case 138: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 559 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 2969 "C_grammar.tab.c"
    break;

  case 139: /* struct_or_union: STRUCT  */
#line 568 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "struct");}
#line 2975 "C_grammar.tab.c"
    break;

  case 140: /* struct_or_union: UNION  */
#line 569 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "union");}
#line 2981 "C_grammar.tab.c"
    break;

  case 141: /* struct_declaration_list: struct_declaration  */
#line 574 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2987 "C_grammar.tab.c"
    break;

  case 142: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 576 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 2998 "C_grammar.tab.c"
    break;

  case 143: /* struct_declaration: specifier_qualifier_list ';'  */
#line 586 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3008 "C_grammar.tab.c"
    break;

  case 144: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 592 "C_grammar.y"
                {size_t const size = strlen("struct_decl([], )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_decl([%s], %s)", (yyvsp[-2].id), (yyvsp[-1].id));
	   	 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
        }
#line 3019 "C_grammar.tab.c"
    break;

  case 145: /* struct_declaration: static_assert_declaration  */
#line 599 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3025 "C_grammar.tab.c"
    break;

  case 146: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 604 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3036 "C_grammar.tab.c"
    break;

  case 147: /* specifier_qualifier_list: type_specifier  */
#line 611 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3042 "C_grammar.tab.c"
    break;

  case 148: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 613 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3053 "C_grammar.tab.c"
    break;

  case 149: /* specifier_qualifier_list: type_qualifier  */
#line 620 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3059 "C_grammar.tab.c"
    break;

  case 150: /* struct_declarator_list: struct_declarator  */
#line 625 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3065 "C_grammar.tab.c"
    break;

  case 151: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 627 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3076 "C_grammar.tab.c"
    break;

  case 152: /* struct_declarator: ':' constant_expression  */
#line 637 "C_grammar.y"
                {size_t const size = strlen("struct_declarator()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_declarator(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3086 "C_grammar.tab.c"
    break;

  case 153: /* struct_declarator: declarator ':' constant_expression  */
#line 643 "C_grammar.y"
                {size_t const size = strlen("struct_declarator(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_declarator(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3097 "C_grammar.tab.c"
    break;

  case 154: /* struct_declarator: declarator  */
#line 650 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3103 "C_grammar.tab.c"
    break;

  case 165: /* type_qualifier: CONST  */
#line 676 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3109 "C_grammar.tab.c"
    break;

  case 166: /* type_qualifier: RESTRICT  */
#line 677 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3115 "C_grammar.tab.c"
    break;

  case 167: /* type_qualifier: VOLATILE  */
#line 678 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3121 "C_grammar.tab.c"
    break;

  case 168: /* type_qualifier: ATOMIC  */
#line 679 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3127 "C_grammar.tab.c"
    break;

  case 169: /* function_specifier: INLINE  */
#line 683 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3133 "C_grammar.tab.c"
    break;

  case 170: /* function_specifier: NORETURN  */
#line 684 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3139 "C_grammar.tab.c"
    break;

  case 173: /* declarator: pointer direct_declarator  */
#line 694 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 3150 "C_grammar.tab.c"
    break;

  case 174: /* declarator: direct_declarator  */
#line 701 "C_grammar.y"
          {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3156 "C_grammar.tab.c"
    break;

  case 175: /* direct_declarator: IDENTIFIER  */
#line 705 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3162 "C_grammar.tab.c"
    break;

  case 176: /* direct_declarator: '(' declarator ')'  */
#line 706 "C_grammar.y"
                                                {simple_str_lit_copy(&(yyval.id), "D1");}
#line 3168 "C_grammar.tab.c"
    break;

  case 177: /* direct_declarator: direct_declarator '[' ']'  */
#line 707 "C_grammar.y"
                                                {simple_str_lit_copy(&(yyval.id), "D2"); }
#line 3174 "C_grammar.tab.c"
    break;

  case 178: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 708 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "D3"); }
#line 3180 "C_grammar.tab.c"
    break;

  case 179: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 709 "C_grammar.y"
                                                                                     {simple_str_lit_copy(&(yyval.id), "D4"); }
#line 3186 "C_grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 710 "C_grammar.y"
                                                                {simple_str_lit_copy(&(yyval.id), "D5"); }
#line 3192 "C_grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 711 "C_grammar.y"
                                                           {simple_str_lit_copy(&(yyval.id), "D6"); }
#line 3198 "C_grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 712 "C_grammar.y"
                                                                                    {simple_str_lit_copy(&(yyval.id), "D7"); }
#line 3204 "C_grammar.tab.c"
    break;

  case 183: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 713 "C_grammar.y"
                                                                             {simple_str_lit_copy(&(yyval.id), "D8"); }
#line 3210 "C_grammar.tab.c"
    break;

  case 184: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 714 "C_grammar.y"
                                                       {simple_str_lit_copy(&(yyval.id), "D9"); }
#line 3216 "C_grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 715 "C_grammar.y"
                                                         {simple_str_lit_copy(&(yyval.id), "D10"); }
#line 3222 "C_grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 716 "C_grammar.y"
                                                       {simple_str_lit_copy(&(yyval.id), "D11"); }
#line 3228 "C_grammar.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '(' ')'  */
#line 717 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "D12"); }
#line 3234 "C_grammar.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 718 "C_grammar.y"
                                                   {simple_str_lit_copy(&(yyval.id), "D13"); }
#line 3240 "C_grammar.tab.c"
    break;

  case 189: /* pointer: '*' type_qualifier_list pointer  */
#line 723 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3251 "C_grammar.tab.c"
    break;

  case 190: /* pointer: '*' type_qualifier_list  */
#line 730 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3261 "C_grammar.tab.c"
    break;

  case 191: /* pointer: '*' pointer  */
#line 736 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3271 "C_grammar.tab.c"
    break;

  case 192: /* pointer: '*'  */
#line 742 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3277 "C_grammar.tab.c"
    break;

  case 193: /* type_qualifier_list: type_qualifier  */
#line 746 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3283 "C_grammar.tab.c"
    break;

  case 194: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 748 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3294 "C_grammar.tab.c"
    break;

  case 204: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 778 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3300 "C_grammar.tab.c"
    break;

  case 205: /* type_name: specifier_qualifier_list  */
#line 779 "C_grammar.y"
                                                                                {simple_str_lit_copy(&(yyval.id), "typenamedummy2");}
#line 3306 "C_grammar.tab.c"
    break;

  case 230: /* initializer: '{' initializer_list '}'  */
#line 814 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3316 "C_grammar.tab.c"
    break;

  case 231: /* initializer: '{' initializer_list ',' '}'  */
#line 820 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "trailing_comma_initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3326 "C_grammar.tab.c"
    break;

  case 232: /* initializer: assignment_expression  */
#line 826 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3332 "C_grammar.tab.c"
    break;

  case 233: /* initializer_list: designation initializer  */
#line 831 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3343 "C_grammar.tab.c"
    break;

  case 234: /* initializer_list: initializer  */
#line 838 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3349 "C_grammar.tab.c"
    break;

  case 235: /* initializer_list: initializer_list ',' designation initializer  */
#line 840 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3361 "C_grammar.tab.c"
    break;

  case 236: /* initializer_list: initializer_list ',' initializer  */
#line 848 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3372 "C_grammar.tab.c"
    break;

  case 237: /* designation: designator_list '='  */
#line 858 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "[%s]", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3382 "C_grammar.tab.c"
    break;

  case 238: /* designator_list: designator  */
#line 867 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3388 "C_grammar.tab.c"
    break;

  case 239: /* designator_list: designator_list designator  */
#line 869 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3399 "C_grammar.tab.c"
    break;

  case 240: /* designator: '[' constant_expression ']'  */
#line 879 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 3405 "C_grammar.tab.c"
    break;

  case 241: /* designator: '.' IDENTIFIER  */
#line 881 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3415 "C_grammar.tab.c"
    break;

  case 242: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 890 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 3426 "C_grammar.tab.c"
    break;

  case 249: /* $@1: %empty  */
#line 908 "C_grammar.y"
                         {fprintf(pl_file, "label_stmt($1, "); free((yyvsp[-1].id));}
#line 3432 "C_grammar.tab.c"
    break;

  case 250: /* labeled_statement: IDENTIFIER ':' $@1 statement  */
#line 908 "C_grammar.y"
                                                                                    {fprintf(pl_file, ")");}
#line 3438 "C_grammar.tab.c"
    break;

  case 251: /* $@2: %empty  */
#line 909 "C_grammar.y"
                                       {fprintf(pl_file, "case_stmt($2, "); free((yyvsp[-1].id));}
#line 3444 "C_grammar.tab.c"
    break;

  case 252: /* labeled_statement: CASE constant_expression ':' $@2 statement  */
#line 909 "C_grammar.y"
                                                                                                 {fprintf(pl_file, ")");}
#line 3450 "C_grammar.tab.c"
    break;

  case 253: /* $@3: %empty  */
#line 910 "C_grammar.y"
                      {fprintf(pl_file, "default_stmt(");}
#line 3456 "C_grammar.tab.c"
    break;

  case 254: /* labeled_statement: DEFAULT ':' $@3 statement  */
#line 910 "C_grammar.y"
                                                                     {fprintf(pl_file, ")");}
#line 3462 "C_grammar.tab.c"
    break;

  case 255: /* compound_statement: '{' '}'  */
#line 914 "C_grammar.y"
                  {fprintf(pl_file, "cmp_stmts([])");}
#line 3468 "C_grammar.tab.c"
    break;

  case 256: /* $@4: %empty  */
#line 915 "C_grammar.y"
              {fprintf(pl_file, "cmp_stmts([");}
#line 3474 "C_grammar.tab.c"
    break;

  case 257: /* compound_statement: '{' $@4 block_item_list '}'  */
#line 915 "C_grammar.y"
                                                                     {fprintf(pl_file, "])");}
#line 3480 "C_grammar.tab.c"
    break;

  case 259: /* $@5: %empty  */
#line 920 "C_grammar.y"
                          {fprintf(pl_file, ", ");}
#line 3486 "C_grammar.tab.c"
    break;

  case 263: /* expression_statement: ';'  */
#line 929 "C_grammar.y"
                                        {fprintf(pl_file, "exp_stmt()");}
#line 3492 "C_grammar.tab.c"
    break;

  case 264: /* expression_statement: expression ';'  */
#line 930 "C_grammar.y"
                                {fprintf(pl_file, "exp_stmt(%s)", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3498 "C_grammar.tab.c"
    break;

  case 265: /* $@6: %empty  */
#line 934 "C_grammar.y"
                                {fprintf(pl_file, "if_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3504 "C_grammar.tab.c"
    break;

  case 266: /* selection_statement: IF '(' expression ')' $@6 statement else_opt  */
#line 934 "C_grammar.y"
                                                                                                     {fprintf(pl_file, ")");}
#line 3510 "C_grammar.tab.c"
    break;

  case 267: /* $@7: %empty  */
#line 935 "C_grammar.y"
                                    {fprintf(pl_file, "switch_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3516 "C_grammar.tab.c"
    break;

  case 268: /* selection_statement: SWITCH '(' expression ')' $@7 statement  */
#line 935 "C_grammar.y"
                                                                                                        {fprintf(pl_file, ")");}
#line 3522 "C_grammar.tab.c"
    break;

  case 270: /* $@8: %empty  */
#line 940 "C_grammar.y"
               {fprintf(pl_file, ", ");}
#line 3528 "C_grammar.tab.c"
    break;

  case 272: /* $@9: %empty  */
#line 943 "C_grammar.y"
                                   {fprintf(pl_file, "while_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3534 "C_grammar.tab.c"
    break;

  case 273: /* iteration_statement: WHILE '(' expression ')' $@9 statement  */
#line 943 "C_grammar.y"
                                                                                                  {fprintf(pl_file, ")");}
#line 3540 "C_grammar.tab.c"
    break;

  case 274: /* $@10: %empty  */
#line 944 "C_grammar.y"
             {fprintf(pl_file, "do_while_stmt(");}
#line 3546 "C_grammar.tab.c"
    break;

  case 275: /* iteration_statement: DO $@10 statement WHILE '(' expression ')' ';'  */
#line 944 "C_grammar.y"
                                                                                          {fprintf(pl_file, ", %s)", (yyvsp[-2].id)); free((yyvsp[-2].id));}
#line 3552 "C_grammar.tab.c"
    break;

  case 276: /* $@11: %empty  */
#line 945 "C_grammar.y"
                  {fprintf(pl_file, "for_stmt(");}
#line 3558 "C_grammar.tab.c"
    break;

  case 277: /* $@12: %empty  */
#line 945 "C_grammar.y"
                                                                     {fprintf(pl_file, ", ");}
#line 3564 "C_grammar.tab.c"
    break;

  case 278: /* iteration_statement: FOR '(' $@11 for_stmt_type ')' $@12 statement  */
#line 945 "C_grammar.y"
                                                                                                         {fprintf(pl_file, ")");}
#line 3570 "C_grammar.tab.c"
    break;

  case 279: /* $@13: %empty  */
#line 949 "C_grammar.y"
                               {fprintf(pl_file, ", ");}
#line 3576 "C_grammar.tab.c"
    break;

  case 281: /* $@14: %empty  */
#line 950 "C_grammar.y"
                      {fprintf(pl_file, ", ");}
#line 3582 "C_grammar.tab.c"
    break;

  case 284: /* expression_opt: expression  */
#line 955 "C_grammar.y"
                     {fprintf(pl_file, ", %s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 3588 "C_grammar.tab.c"
    break;

  case 285: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 958 "C_grammar.y"
                                {fprintf(pl_file, "goto_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3594 "C_grammar.tab.c"
    break;

  case 286: /* jump_statement: CONTINUE ';'  */
#line 959 "C_grammar.y"
                                        {fprintf(pl_file, "continue_stmt\n");}
#line 3600 "C_grammar.tab.c"
    break;

  case 287: /* jump_statement: BREAK ';'  */
#line 960 "C_grammar.y"
                                                {fprintf(pl_file, "break_stmt\n");}
#line 3606 "C_grammar.tab.c"
    break;

  case 288: /* jump_statement: RETURN ';'  */
#line 961 "C_grammar.y"
                                        {fprintf(pl_file, "return_stmt\n");}
#line 3612 "C_grammar.tab.c"
    break;

  case 289: /* jump_statement: RETURN expression ';'  */
#line 962 "C_grammar.y"
                                {fprintf(pl_file, "return_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3618 "C_grammar.tab.c"
    break;

  case 291: /* $@15: %empty  */
#line 967 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 3624 "C_grammar.tab.c"
    break;

  case 295: /* $@16: %empty  */
#line 976 "C_grammar.y"
                                            {fprintf(pl_file, "function(%s, %s, [", (yyvsp[-1].id), (yyvsp[0].id)); free((yyvsp[-1].id)); free((yyvsp[0].id));}
#line 3630 "C_grammar.tab.c"
    break;

  case 296: /* $@17: %empty  */
#line 976 "C_grammar.y"
                                                                                                                                       {fprintf(pl_file, "], ");}
#line 3636 "C_grammar.tab.c"
    break;

  case 297: /* function_definition: declaration_specifiers declarator $@16 declaration_list_opt $@17 compound_statement  */
#line 976 "C_grammar.y"
                                                                                                                                                                                     {fprintf(pl_file, ")");}
#line 3642 "C_grammar.tab.c"
    break;

  case 301: /* $@18: %empty  */
#line 986 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 3648 "C_grammar.tab.c"
    break;


#line 3652 "C_grammar.tab.c"

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

#line 989 "C_grammar.y"

int main(int argc, char *argv[]) {			//argc is the total number of strings in the argv array
	char C_file_path[_MAX_PATH];				//directory where the C and .i files are
	char filename_no_ext[_MAX_PATH];
	char i_file_uri[_MAX_PATH];
	FILE *i_file;

	strcpy_s(C_file_path, 3, ".\\");				//default path for input file is current directory, overwrite with -p on command line
	for (int i = 1; i <= argc - 1; i++) {	//processing command line arguments
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'h':
				printf("Usage: .\\sikraken_parser [OPTION]... [FILE]\nParse a C file to Prolog terms.\n\n-h\t Display help information\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\LilyParser -p\".\" get_sign \n\t.\\LilyParser get_sign \n\t.\\LilyParser -p\"C:/Parser/\" sign \n");
				exit(0);
			case 'p':	//path to the .i pre-processed input C file
				if (_access(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					exit(1);
				}
				strcpy_s(C_file_path, _MAX_PATH, &argv[i][2]);
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
			strcpy_s(filename_no_ext, _MAX_PATH, argv[i]);
		}
	}
	sprintf_s(i_file_uri, _MAX_PATH, "%s%s.i", C_file_path, filename_no_ext);
	if (fopen_s(&i_file, i_file_uri, "r") != 0) {
		fprintf(stderr, ".i file could opened to read at: %s\n", i_file_uri);
		exit(EXIT_FAILURE);
	}
	yyin = i_file;	//set the input to the parser
	sprintf_s(pl_file_uri, _MAX_PATH, "%s%s.pl", C_file_path, filename_no_ext);
	if (fopen_s(&pl_file, pl_file_uri, "w") != 0) {
		fprintf(stderr, ".pl file could created for write at: %s\n", pl_file_uri);
		exit(EXIT_FAILURE);
	}
	fprintf(pl_file, "prolog_c([");	//opening predicate
	if (yyparse() != 0) {
		fprintf(stderr, "Parsing failed.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(pl_file, "\n]).");	//closing predicate
	fclose(pl_file);
	fclose(i_file);
	my_exit(EXIT_SUCCESS);
}


//handles parsing errors: since the C input file is the output of a C pre-processor it is unlikely to be every called
//in fact it is only useful if the syntax rules are wrong or if .i file has been generated manually: i.e. during development
void yyerror(const char* s) {
	fprintf(stderr, "Internal parsing error, yyerror called on line %d with message \"%s\" on token %d\n", yylineno, s, yychar);
}

void my_exit(int exit_code) {			//exits and performs some tidying up if not in debug mode
  if (!debugMode) {
    if (yyin) fclose(yyin);
    if (pl_file) fclose(pl_file);
    if (_access(pl_file_uri, 0) != -1) remove(pl_file_uri);
  }
  if (exit_code == EXIT_SUCCESS) fprintf(stderr, "Sikraken parsing success, wrote %s", pl_file_uri);
  exit(exit_code);
}

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
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 8,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 9,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 10,                    /* PTR_OP  */
  YYSYMBOL_INC_OP = 11,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 12,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 13,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 14,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 15,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 16,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 17,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 18,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 19,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 20,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 21,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 22,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 23,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 24,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 25,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 26,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 27,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 28,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 29,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 30,                 /* OR_ASSIGN  */
  YYSYMBOL_ENUMERATION_CONSTANT = 31,      /* ENUMERATION_CONSTANT  */
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
  YYSYMBOL_unary_operator = 111,           /* unary_operator  */
  YYSYMBOL_cast_expression = 112,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 113, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 114,      /* additive_expression  */
  YYSYMBOL_shift_expression = 115,         /* shift_expression  */
  YYSYMBOL_relational_expression = 116,    /* relational_expression  */
  YYSYMBOL_equality_expression = 117,      /* equality_expression  */
  YYSYMBOL_and_expression = 118,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 119,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 120,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 121,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 122,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 123,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 124,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 125,      /* assignment_operator  */
  YYSYMBOL_expression = 126,               /* expression  */
  YYSYMBOL_constant_expression = 127,      /* constant_expression  */
  YYSYMBOL_declaration = 128,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 129,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 130,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 131,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 132,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 133,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 134, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 135,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 136,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 137,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 138, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 139,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 140,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 141,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 142,          /* enumerator_list  */
  YYSYMBOL_enumerator = 143,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 144,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 145,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 146,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 147,      /* alignment_specifier  */
  YYSYMBOL_declarator = 148,               /* declarator  */
  YYSYMBOL_direct_declarator = 149,        /* direct_declarator  */
  YYSYMBOL_pointer = 150,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 151,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 152,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 153,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 154,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 155,          /* identifier_list  */
  YYSYMBOL_type_name = 156,                /* type_name  */
  YYSYMBOL_abstract_declarator = 157,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 158, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 159,              /* initializer  */
  YYSYMBOL_initializer_list = 160,         /* initializer_list  */
  YYSYMBOL_designation = 161,              /* designation  */
  YYSYMBOL_designator_list = 162,          /* designator_list  */
  YYSYMBOL_designator = 163,               /* designator  */
  YYSYMBOL_static_assert_declaration = 164, /* static_assert_declaration  */
  YYSYMBOL_statement = 165,                /* statement  */
  YYSYMBOL_labeled_statement = 166,        /* labeled_statement  */
  YYSYMBOL_167_1 = 167,                    /* $@1  */
  YYSYMBOL_168_2 = 168,                    /* $@2  */
  YYSYMBOL_169_3 = 169,                    /* $@3  */
  YYSYMBOL_compound_statement = 170,       /* compound_statement  */
  YYSYMBOL_171_4 = 171,                    /* $@4  */
  YYSYMBOL_block_item_list = 172,          /* block_item_list  */
  YYSYMBOL_173_5 = 173,                    /* $@5  */
  YYSYMBOL_block_item = 174,               /* block_item  */
  YYSYMBOL_expression_statement = 175,     /* expression_statement  */
  YYSYMBOL_selection_statement = 176,      /* selection_statement  */
  YYSYMBOL_177_6 = 177,                    /* $@6  */
  YYSYMBOL_178_7 = 178,                    /* $@7  */
  YYSYMBOL_else_opt = 179,                 /* else_opt  */
  YYSYMBOL_180_8 = 180,                    /* $@8  */
  YYSYMBOL_iteration_statement = 181,      /* iteration_statement  */
  YYSYMBOL_182_9 = 182,                    /* $@9  */
  YYSYMBOL_183_10 = 183,                   /* $@10  */
  YYSYMBOL_184_11 = 184,                   /* $@11  */
  YYSYMBOL_185_12 = 185,                   /* $@12  */
  YYSYMBOL_for_stmt_type = 186,            /* for_stmt_type  */
  YYSYMBOL_187_13 = 187,                   /* $@13  */
  YYSYMBOL_188_14 = 188,                   /* $@14  */
  YYSYMBOL_expression_opt = 189,           /* expression_opt  */
  YYSYMBOL_jump_statement = 190,           /* jump_statement  */
  YYSYMBOL_translation_unit = 191,         /* translation_unit  */
  YYSYMBOL_192_15 = 192,                   /* $@15  */
  YYSYMBOL_external_declaration = 193,     /* external_declaration  */
  YYSYMBOL_function_definition = 194,      /* function_definition  */
  YYSYMBOL_195_16 = 195,                   /* $@16  */
  YYSYMBOL_196_17 = 196,                   /* $@17  */
  YYSYMBOL_declaration_list_opt = 197,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 198,         /* declaration_list  */
  YYSYMBOL_199_18 = 199                    /* $@18  */
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
#define YYLAST   2187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  296
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  495

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
       0,    61,    61,    62,    63,    64,    65,    69,    70,    71,
      75,    79,    80,    84,    88,    89,    93,    94,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   111,   112,
     116,   117,   118,   119,   120,   121,   122,   126,   127,   128,
     129,   130,   131,   135,   136,   140,   141,   142,   143,   147,
     148,   149,   153,   154,   155,   159,   160,   161,   162,   163,
     167,   168,   169,   173,   174,   178,   179,   183,   184,   188,
     189,   193,   194,   204,   205,   216,   217,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   242,   243,
     253,   257,   261,   269,   275,   282,   283,   290,   291,   293,
     295,   297,   299,   301,   306,   307,   317,   324,   333,   337,
     338,   339,   340,   341,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     365,   366,   367,   371,   372,   376,   377,   381,   382,   383,
     387,   388,   389,   390,   394,   395,   399,   400,   401,   405,
     406,   407,   408,   409,   413,   414,   418,   419,   423,   427,
     428,   429,   430,   434,   435,   439,   440,   444,   451,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   477,   484,   490,   496,   501,   502,   512,
     513,   517,   518,   522,   523,   524,   528,   529,   533,   534,
     538,   539,   540,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   568,   569,   570,   574,   575,   576,
     577,   581,   585,   586,   590,   591,   595,   599,   600,   601,
     602,   603,   604,   608,   608,   609,   609,   610,   610,   614,
     615,   615,   619,   620,   620,   624,   625,   629,   630,   634,
     634,   635,   635,   639,   640,   640,   643,   643,   644,   644,
     645,   645,   645,   649,   649,   650,   650,   654,   655,   658,
     659,   660,   661,   662,   666,   667,   667,   671,   672,   676,
     676,   676,   680,   681,   685,   686,   686
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
  "TYPEDEF_NAME", "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL",
  "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('", "')'", "','", "':'",
  "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'",
  "$accept", "primary_expression", "constant", "enumeration_constant",
  "string", "generic_selection", "generic_assoc_list",
  "generic_association", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
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

#define YYPACT_NINF (-431)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-294)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1907,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,    17,   -41,   -35,  -431,    34,
    -431,  -431,    59,  2012,  2012,  -431,    53,  -431,  -431,  2012,
    2012,  2012,  -431,   162,  -431,  -431,    69,   164,   780,  2116,
    1460,  -431,    10,    -2,  -431,   -50,  -431,   -56,    75,     9,
    -431,  -431,    82,  1538,  -431,  -431,  -431,  -431,  1907,   164,
    -431,    86,   -61,  -431,  -431,  -431,  -431,  -431,  -431,  1481,
    1532,  1532,  -431,   115,   123,   780,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,   177,  -431,  1460,  -431,
      62,   -72,    52,   193,   195,   121,   120,   122,   202,     5,
    -431,   149,  2116,     1,  2116,   151,   160,   172,   183,  -431,
    -431,  -431,    -2,    10,  -431,  1330,  1907,  1803,   852,    75,
    1538,  1698,  -431,   143,  -431,  -431,   -30,  1460,    55,  -431,
     780,  -431,   780,  -431,  -431,  2116,  1460,   351,  -431,  -431,
     147,   186,   249,  -431,  -431,  1351,  1460,   263,  -431,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  -431,  -431,
    1646,   873,   118,  -431,   125,  -431,  -431,  -431,   223,  -431,
    -431,  -431,  -431,   170,  1309,  -431,  -431,  -431,    59,  -431,
     188,  -431,  -431,   131,   206,   201,  -431,   156,  1179,  -431,
     209,   213,   961,  1750,  -431,  -431,  1460,  -431,   -39,  -431,
     219,    60,  -431,  -431,  -431,  -431,   225,   231,   233,   234,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  1460,  -431,  1460,  1439,  -431,  -431,   178,  -431,     2,
    -431,  -431,  -431,  -431,    62,    62,   -72,   -72,    52,    52,
      52,    52,   193,   193,   195,   121,   120,   122,   202,   194,
    -431,   239,   250,  1179,  -431,   245,   247,   982,   125,  1855,
    1070,   253,  1460,   329,  -431,   -25,  1330,   -51,  -431,   251,
    1907,  1591,  -431,   140,  -431,  -431,  1959,  -431,   330,   256,
    1179,  -431,  -431,  1460,  -431,   257,   259,  -431,  -431,   175,
    -431,  1460,  -431,   260,   260,  -431,  2064,  -431,  -431,  1309,
    -431,  -431,  1460,  -431,  1460,  -431,  -431,   265,  1179,  -431,
    -431,  1460,  -431,   268,  -431,   273,  1179,  -431,   275,   280,
    1091,   264,   281,  -431,  1200,  -431,  -431,  -431,  -431,   282,
    -431,  -431,  -431,  -431,  -431,  -431,   283,   284,  -431,  -431,
    -431,  -431,   288,   197,  -431,   290,   108,  -431,  -431,  -431,
     289,   301,  -431,  -431,   302,  1179,  -431,  -431,  1460,  -431,
     303,  -431,  -431,  -431,  -431,  1330,  -431,   460,  -431,  -431,
    1460,  -431,  2064,  1460,  1221,  -431,  -431,  -431,  -431,   304,
     305,  -431,  -431,   309,  1460,   312,   316,   317,   319,  -431,
     324,   398,   306,   307,   644,  -431,   -38,  -431,  -431,  -431,
    -431,   318,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,   328,  -431,  1460,  1460,  1460,   602,
    -431,   310,  -431,  -431,  -431,   -26,  -431,  -431,   460,   602,
    -431,   602,   204,   211,   227,   341,   549,  -431,  -431,  -431,
    -431,   602,  -431,  -431,  -431,  -431,   334,  -431,  -431,   336,
    -431,   602,   602,   602,  1460,   691,   691,  -431,   354,  -431,
    -431,   229,  1460,  1460,   602,  -431,  -431,   320,   337,  -431,
    -431,  -431,   602,  -431,  -431
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   129,   108,   109,   110,   112,   113,   163,   159,   160,
     161,   123,   115,   116,   117,   118,   121,   122,   119,   120,
     114,   124,   125,   133,   134,     0,     0,   162,   164,     0,
     111,   288,     0,    95,    97,   127,     0,   128,   126,    99,
     101,   103,    93,   285,   284,   287,   153,     0,     0,     0,
       0,   169,     0,   186,    91,     0,   104,   289,   168,     0,
      94,    96,   132,     0,    98,   100,   102,     1,     0,     0,
      10,   157,     0,   154,     2,     7,     8,    11,    12,     0,
       0,     0,     9,     0,     0,     0,    37,    38,    39,    40,
      41,    42,    18,     3,     4,     6,    30,    43,     0,    45,
      49,    52,    55,    60,    63,    65,    67,    69,    71,    73,
      90,     0,   141,   199,   143,     0,     0,     0,     0,   162,
     187,   185,   184,     0,    92,     0,   292,     0,     0,   167,
       0,     0,   135,     0,   139,   286,     0,     0,     0,   149,
       0,    34,     0,    31,    32,     0,     0,    43,    75,    88,
       0,     0,     0,    24,    25,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,   140,
       0,     0,   201,   198,   202,   142,   165,   158,     0,   170,
     188,   183,   105,   107,     0,   226,   106,   294,     0,   290,
     295,   196,   181,   195,     0,   190,   191,     0,     0,   171,
      38,     0,     0,     0,   130,   136,     0,   137,     0,   144,
     148,     0,   151,   156,   150,   155,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      77,     0,     5,     0,     0,    23,    20,     0,    28,     0,
      22,    46,    47,    48,    50,    51,    53,    54,    58,    59,
      56,    57,    61,    62,    64,    66,    68,    70,    72,     0,
     220,     0,     0,     0,   204,    38,     0,     0,   200,     0,
       0,     0,     0,     0,   228,     0,     0,     0,   232,     0,
       0,     0,   193,   201,   194,   180,     0,   182,     0,     0,
       0,   172,   179,     0,   178,    38,     0,   131,   146,     0,
     138,     0,   152,    35,     0,    36,     0,    76,    89,     0,
      44,    21,     0,    19,     0,   221,   203,     0,     0,   205,
     211,     0,   210,     0,   222,     0,     0,   212,    38,     0,
       0,     0,     0,   235,     0,   224,   227,   231,   233,   250,
     291,   296,   189,   192,   197,   174,     0,     0,   175,   177,
     145,   147,     0,     0,    14,     0,     0,    29,    74,   207,
       0,     0,   209,   223,     0,     0,   213,   219,     0,   218,
       0,   236,   234,   225,   230,     0,   249,     0,   173,   176,
       0,    13,     0,     0,     0,    26,   206,   208,   215,     0,
       0,   216,   229,     2,     0,     0,     0,     0,     0,   268,
       0,     0,     0,     0,     0,   257,     0,   255,   256,   237,
     238,   253,   252,   239,   240,   241,   242,    17,    15,    16,
      27,   214,   217,   243,     0,   247,     0,     0,     0,     0,
     270,     0,   280,   281,   282,     0,   258,   251,     0,     0,
     245,     0,     0,     0,     0,     0,     0,   279,   283,   254,
     244,     0,   248,   259,   261,   266,     0,   275,   273,     0,
     246,     0,     0,     0,     0,     0,     0,   271,   263,   262,
     267,     0,   277,   277,     0,   264,   260,     0,   278,   276,
     274,   272,     0,   269,   265
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -431,  -431,  -431,  -431,  -431,  -431,  -431,    24,  -431,  -431,
     -47,  -431,   -54,   152,   153,    78,   150,   248,   244,   252,
     254,   246,  -431,   -46,    68,  -431,   -85,   -44,  -117,   142,
    -431,   300,  -431,    26,  -431,  -431,   294,  -112,   -36,  -431,
     116,  -431,   358,  -133,  -431,    19,  -431,  -431,   -24,   -52,
     -43,   -78,  -116,  -431,   132,  -431,   155,   -95,  -161,  -101,
     111,  -330,  -431,   144,   -33,  -148,  -431,  -431,  -431,  -431,
     145,  -431,  -431,  -431,   -16,  -430,  -431,  -431,  -431,  -431,
    -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,  -431,   -48,
    -431,  -431,  -431,   368,  -431,  -431,  -431,  -431,  -431,  -431
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    71,    94,    95,   363,   364,    96,   247,
     147,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   148,   149,   241,   416,   111,    31,   198,
      55,    56,    33,    34,    35,    36,   131,   132,   113,   218,
     219,    37,    72,    73,    38,    39,    40,    41,   118,    58,
      59,   122,   271,   205,   206,   207,   365,   272,   184,   284,
     285,   286,   287,   288,    42,   418,   419,   449,   461,   451,
     420,   387,   421,   448,   422,   423,   424,   471,   472,   486,
     492,   425,   473,   439,   456,   484,   469,   476,   475,   489,
     426,    43,    68,    44,    45,   126,   289,   199,   200,   290
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     150,    97,   110,    97,   110,   225,   117,   129,    57,   197,
     121,   204,    51,    51,   385,   162,   163,   138,   183,   215,
      46,   278,  -107,   139,   196,   176,   468,   133,   123,   282,
     134,   283,   141,   143,   144,    48,     8,     9,    10,   309,
     243,    49,   125,  -107,   158,   482,   483,   347,   221,   124,
     212,    97,   243,   344,   222,   150,    62,   150,    70,   345,
     310,   446,    51,    70,   385,   164,   165,   114,   114,   119,
     182,   249,   120,   458,   112,   112,   179,   180,   185,   191,
     243,   181,   114,   323,    53,    52,    52,    53,   225,   112,
      97,   110,   269,   223,   133,   133,    53,   134,   134,   193,
      47,   215,   177,   277,   114,   251,   252,   253,   294,   220,
      50,   112,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
     300,   114,   278,   114,    51,    52,    63,   182,   112,   224,
     112,   190,    32,    51,   312,    53,    51,   120,   159,   114,
     114,   127,    69,   160,   161,   128,   112,   112,    54,   114,
     293,   114,    67,   335,   114,   130,   112,    70,   112,    97,
     110,   112,   308,   351,   193,    60,    61,   133,    51,   292,
     134,    64,    65,    66,   137,   346,   394,   152,   153,   154,
     320,   145,   395,   195,   180,   328,   211,    97,   181,   146,
     120,   279,   340,   115,   116,   280,   172,   291,   166,   167,
      32,   181,   170,   171,   229,   173,   291,    53,   174,    52,
     181,   175,   216,   248,   242,   243,   178,   120,   186,    53,
     281,   190,   114,   297,   298,    97,   110,   187,   342,   112,
     151,   129,   217,   384,   258,   259,   260,   261,   293,   276,
     188,    52,   245,   155,   216,   321,   322,   156,   375,   157,
     189,    53,   195,   244,    97,   110,   250,   361,   125,   203,
     417,  -293,   243,   324,   391,   392,   299,    97,   368,   296,
     306,   463,   243,   295,   402,   220,   168,   169,   464,   243,
     301,   455,   120,   384,   302,   226,   190,   227,   311,   120,
     228,   460,   313,   462,   465,   243,   487,   243,   314,   317,
     315,   318,   316,   470,   254,   255,   325,   256,   257,   190,
     262,   263,   203,   478,   479,   480,   329,   326,   330,   445,
     341,   417,   343,   354,   349,   114,   491,   355,   358,   467,
     359,   327,   112,   319,   494,   333,   369,   190,   339,   372,
     373,   452,   453,   454,   195,   120,   376,    97,   110,   190,
     434,   377,   382,   381,   388,   389,   386,   390,   356,   393,
     396,   357,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   397,   398,   401,   431,   432,   195,   433,   481,
     367,   435,   436,   437,   190,   438,   370,   488,   488,   371,
     440,   441,   447,   466,   374,   442,   443,   450,   380,   457,
     474,   114,   195,   477,   485,   243,   428,   265,   112,   493,
     264,   203,   268,   192,   213,   360,   266,   136,   353,   267,
     366,   348,   459,   203,   350,   490,   135,     0,   203,     0,
       0,     0,     0,   399,     0,     0,   400,     0,     0,   240,
       0,     0,     0,   195,     0,     0,     0,     0,   427,     0,
       0,   429,   195,   403,     1,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,   404,   405,   406,
       0,   407,   408,   409,   410,   411,   412,   413,   414,    26,
      83,    27,    84,    28,    29,    30,    85,     0,     0,     0,
       0,     0,     0,   349,     0,    86,    87,    88,    89,    90,
      91,     0,    74,     1,    75,    76,    77,    78,    79,   415,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   403,     0,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,    26,    83,
      27,    84,    28,    29,    30,    85,     0,     0,     0,     0,
       0,     0,     0,    82,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,    74,   415,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,   404,
     405,   406,     0,   407,   408,   409,   410,   411,   412,   413,
     414,     0,    83,     0,    84,    82,     0,     0,    85,     0,
       0,     0,     0,     0,     0,   349,     0,    86,    87,    88,
      89,    90,    91,     0,    74,     0,    75,    76,    77,    78,
      79,   415,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,    84,     0,     0,     0,
      85,     0,    82,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,   444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,    74,     1,    75,    76,    77,    78,    79,
     415,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    27,    84,     0,     0,    74,    85,    75,    76,    77,
      78,    79,     0,    80,    81,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,    74,     0,    75,    76,
      77,    78,    79,    82,    80,    81,   208,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,   273,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    83,   119,    84,     0,     0,     0,    85,     0,
       0,     0,     0,   209,     0,     0,     0,    86,   210,    88,
      89,    90,    91,    83,   119,    84,     0,     0,     0,    85,
       0,     0,     0,     0,   274,     0,     0,     0,    86,   275,
      88,    89,    90,    91,    74,     0,    75,    76,    77,    78,
      79,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    82,    80,    81,   303,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,   331,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   304,     0,     0,     0,    86,   305,    88,    89,
      90,    91,    83,   119,    84,     0,     0,     0,    85,     0,
       0,     0,     0,   332,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    74,     0,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    82,    80,    81,   336,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,   378,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      83,   119,    84,     0,     0,     0,    85,     0,     0,     0,
       0,   337,     0,     0,     0,    86,   338,    88,    89,    90,
      91,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   379,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    74,     0,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    76,    77,    78,    79,
      82,    80,    81,     0,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    82,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
     119,    84,    82,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      83,     0,    84,     0,     0,     0,    85,     0,     0,     0,
     282,     0,   283,   194,   383,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,    85,     0,     0,
       0,   282,     0,   283,   194,   430,    86,    87,    88,    89,
      90,    91,    74,     0,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    76,    77,    78,    79,
      82,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    82,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,    84,    82,     0,     0,    85,     0,     0,     0,   282,
       0,   283,   194,     0,    86,    87,    88,    89,    90,    91,
      83,     0,    84,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,   194,     0,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,    85,   246,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    74,     0,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    76,    77,    78,    79,
      82,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    82,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,    84,    82,     0,     0,    85,     0,     0,     0,     0,
       0,     0,   319,     0,    86,    87,    88,    89,    90,    91,
      83,     0,    84,     0,     0,    74,    85,    75,    76,    77,
      78,    79,     1,    80,    81,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,   140,     0,     0,
       0,     0,     0,    82,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    51,     1,     0,     0,     0,     0,
       0,     0,    83,     0,    84,     0,     0,     0,   142,    27,
       0,     0,    29,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,     0,    30,   291,   270,     0,
       0,   181,     0,     0,     0,     0,     0,    53,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       0,    30,   180,   270,     0,     0,   181,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   201,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   307,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,     0,    30,     0,
     202,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,     0,
      30,     0,   334,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   352,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,   362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      85,    48,    48,    50,    50,   138,    50,    59,    32,   126,
      53,   127,     3,     3,   344,    87,    88,    78,   113,   131,
       3,   182,    78,    84,   125,    20,   456,    63,    78,    80,
      63,    82,    79,    80,    81,    76,    38,    39,    40,    78,
      78,    76,    98,    99,    98,   475,   476,    98,    78,    99,
     128,    98,    78,    78,    84,   140,     3,   142,     3,    84,
      99,    99,     3,     3,   394,    13,    14,    48,    49,    71,
     113,   156,    53,    99,    48,    49,   112,    76,   114,   122,
      78,    80,    63,    81,    86,    76,    76,    86,   221,    63,
     137,   137,   177,   137,   130,   131,    86,   130,   131,   123,
      83,   213,    97,   181,    85,   159,   160,   161,   203,   133,
      76,    85,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     208,   112,   293,   114,     3,    76,    83,   180,   112,    84,
     114,   122,     0,     3,    84,    86,     3,   128,    86,   130,
     131,    76,    83,    91,    92,    80,   130,   131,    99,   140,
     203,   142,     0,   279,   145,    83,   140,     3,   142,   216,
     216,   145,   216,   290,   198,    33,    34,   213,     3,   203,
     213,    39,    40,    41,    98,   286,    78,    10,    11,    12,
     244,    76,    84,   125,    76,   273,   128,   244,    80,    76,
     181,    76,   280,    48,    49,    80,    85,    76,    15,    16,
      68,    80,    17,    18,   146,    95,    76,    86,    96,    76,
      80,    19,    79,   155,    77,    78,    77,   208,    77,    86,
       7,   212,   213,    77,    78,   282,   282,    77,   282,   213,
      85,   293,    99,   344,   166,   167,   168,   169,   291,   181,
      78,    76,     3,    76,    79,    77,    78,    80,   336,    82,
      77,    86,   194,    77,   311,   311,     3,   311,    98,   127,
     387,    83,    78,    79,    77,    78,   208,   324,   324,    78,
     212,    77,    78,    77,   385,   309,    93,    94,    77,    78,
      81,   439,   273,   394,    81,   140,   277,   142,    79,   280,
     145,   449,    77,   451,    77,    78,    77,    78,    77,   241,
      77,   243,    78,   461,   162,   163,    77,   164,   165,   300,
     170,   171,   180,   471,   472,   473,    81,    77,    81,   414,
      77,   448,     3,     3,    83,   316,   484,    81,    81,   456,
      81,   273,   316,    83,   492,   277,    81,   328,   280,    81,
      77,   436,   437,   438,   286,   336,    81,   404,   404,   340,
     404,    81,    81,    99,    81,    81,    84,    79,   300,    79,
      81,   303,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    81,    81,    81,    81,    81,   319,    79,   474,
     322,    79,    76,    76,   375,    76,   328,   482,   483,   331,
      76,     3,    84,    62,   336,    99,    99,    79,   340,    99,
      76,   392,   344,    77,    60,    78,   392,   173,   392,    99,
     172,   279,   176,   123,   130,   309,   174,    69,   296,   175,
     319,   287,   448,   291,   289,   483,    68,    -1,   296,    -1,
      -1,    -1,    -1,   375,    -1,    -1,   378,    -1,    -1,    98,
      -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,   390,    -1,
      -1,   393,   394,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,     3,     4,     5,     6,     7,     8,     9,    99,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     3,    -1,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    99,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    31,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    -1,     3,    -1,     5,     6,     7,     8,
       9,    99,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,     3,     4,     5,     6,     7,     8,     9,
      99,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,     3,    76,     5,     6,     7,
       8,     9,    -1,    11,    12,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    31,    11,    12,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,     3,    -1,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    31,    11,    12,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    31,    11,    12,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,    -1,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      31,    11,    12,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    31,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    31,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     3,    -1,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      31,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    31,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    31,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    70,    -1,    72,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,    -1,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      31,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    31,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    31,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
      70,    -1,    72,    -1,    -1,     3,    76,     5,     6,     7,
       8,     9,     4,    11,    12,    85,    86,    87,    88,    89,
      90,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     3,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    -1,    75,    76,    77,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    76,    77,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    73,    74,
      75,   128,   129,   132,   133,   134,   135,   141,   144,   145,
     146,   147,   164,   191,   193,   194,     3,    83,    76,    76,
      76,     3,    76,    86,    99,   130,   131,   148,   149,   150,
     129,   129,     3,    83,   129,   129,   129,     0,   192,    83,
       3,   103,   142,   143,     3,     5,     6,     7,     8,     9,
      11,    12,    31,    70,    72,    76,    85,    86,    87,    88,
      89,    90,   101,   102,   104,   105,   108,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   127,   133,   138,   145,   156,   156,   127,   148,    71,
     145,   150,   151,    78,    99,    98,   195,    76,    80,   149,
      83,   136,   137,   138,   164,   193,   142,    98,    78,    84,
      76,   110,    76,   110,   110,    76,    76,   110,   123,   124,
     126,   156,    10,    11,    12,    76,    80,    82,   112,    86,
      91,    92,    87,    88,    13,    14,    15,    16,    93,    94,
      17,    18,    85,    95,    96,    19,    20,    97,    77,   138,
      76,    80,   150,   157,   158,   138,    77,    77,    78,    77,
     145,   150,   131,   148,    83,   124,   159,   128,   129,   197,
     198,     3,    77,   129,   152,   153,   154,   155,    34,    81,
      86,   124,   151,   136,    84,   137,    79,    99,   139,   140,
     148,    78,    84,   127,    84,   143,   156,   156,   156,   124,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      98,   125,    77,    78,    77,     3,    77,   109,   124,   126,
       3,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   116,   116,   117,   118,   119,   120,   121,   126,
      77,   152,   157,    34,    81,    86,   124,   151,   158,    76,
      80,     7,    80,    82,   159,   160,   161,   162,   163,   196,
     199,    76,   148,   150,   157,    77,    78,    77,    78,   124,
     151,    81,    81,    34,    81,    86,   124,    84,   127,    78,
      99,    79,    84,    77,    77,    77,    78,   124,   124,    83,
     112,    77,    78,    81,    79,    77,    77,   124,   151,    81,
      81,    34,    81,   124,    77,   152,    34,    81,    86,   124,
     151,    77,   127,     3,    78,    84,   159,    98,   163,    83,
     170,   128,    56,   154,     3,    81,   124,   124,    81,    81,
     140,   127,    58,   106,   107,   156,   160,   124,   123,    81,
     124,   124,    81,    77,   124,   151,    81,    81,    34,    81,
     124,    99,    81,    84,   159,   161,    84,   171,    81,    81,
      79,    77,    78,    79,    78,    84,    81,    81,    81,   124,
     124,    81,   159,     3,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,    99,   126,   128,   165,   166,
     170,   172,   174,   175,   176,   181,   190,   124,   107,   124,
      84,    81,    81,    79,   127,    79,    76,    76,    76,   183,
      76,     3,    99,    99,    99,   126,    99,    84,   173,   167,
      79,   169,   126,   126,   126,   165,   184,    99,    99,   174,
     165,   168,   165,    77,    77,    77,    62,   128,   175,   186,
     165,   177,   178,   182,    76,   188,   187,    77,   165,   165,
     165,   126,   175,   175,   185,    60,   179,    77,   126,   189,
     189,   165,   180,    99,   165
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   101,   102,   102,   102,
     103,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   128,   128,   128,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   138,   138,   139,   139,   140,   140,   140,   141,
     141,   141,   141,   141,   142,   142,   143,   143,   144,   145,
     145,   145,   145,   146,   146,   147,   147,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   150,   150,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   155,   155,   156,   156,
     157,   157,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   160,   160,   160,
     160,   161,   162,   162,   163,   163,   164,   165,   165,   165,
     165,   165,   165,   167,   166,   168,   166,   169,   166,   170,
     171,   170,   172,   173,   172,   174,   174,   175,   175,   177,
     176,   178,   176,   179,   180,   179,   182,   181,   183,   181,
     184,   185,   181,   187,   186,   188,   186,   189,   189,   190,
     190,   190,   190,   190,   191,   192,   191,   193,   193,   195,
     196,   194,   197,   197,   198,   199,   198
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     2,     3,     1,
       2,     1,     2,     1,     1,     3,     2,     3,     1,     4,
       5,     5,     6,     2,     1,     3,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       4,     3,     4,     3,     2,     2,     1,     1,     2,     3,
       1,     1,     3,     2,     2,     1,     1,     3,     2,     1,
       2,     1,     1,     3,     2,     3,     5,     4,     5,     4,
       3,     3,     3,     4,     6,     5,     5,     6,     4,     4,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     4,
       3,     2,     1,     2,     3,     2,     7,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     5,     0,     4,     2,
       0,     4,     1,     0,     3,     1,     1,     1,     2,     0,
       7,     0,     6,     0,     0,     3,     0,     6,     0,     8,
       0,     0,     7,     0,     4,     0,     4,     0,     1,     3,
       2,     2,     2,     3,     1,     0,     3,     1,     1,     0,
       0,     6,     0,     1,     1,     0,     3
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
  case 69: /* logical_and_expression: inclusive_or_expression  */
#line 188 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "andxxx");}
#line 2005 "C_grammar.tab.c"
    break;

  case 70: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 189 "C_grammar.y"
                                                                {simple_str_lit_copy(&(yyval.id), "andxxx");}
#line 2011 "C_grammar.tab.c"
    break;

  case 71: /* logical_or_expression: logical_and_expression  */
#line 193 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2017 "C_grammar.tab.c"
    break;

  case 72: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 195 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2028 "C_grammar.tab.c"
    break;

  case 73: /* conditional_expression: logical_or_expression  */
#line 204 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2034 "C_grammar.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 206 "C_grammar.y"
                {size_t const size = strlen("cond_exp(, , )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "cond_exp(%s, %s, %s)", (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2046 "C_grammar.tab.c"
    break;

  case 75: /* assignment_expression: conditional_expression  */
#line 216 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2052 "C_grammar.tab.c"
    break;

  case 76: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 218 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2064 "C_grammar.tab.c"
    break;

  case 77: /* assignment_operator: '='  */
#line 228 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2070 "C_grammar.tab.c"
    break;

  case 78: /* assignment_operator: MUL_ASSIGN  */
#line 229 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2076 "C_grammar.tab.c"
    break;

  case 79: /* assignment_operator: DIV_ASSIGN  */
#line 230 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2082 "C_grammar.tab.c"
    break;

  case 80: /* assignment_operator: MOD_ASSIGN  */
#line 231 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2088 "C_grammar.tab.c"
    break;

  case 81: /* assignment_operator: ADD_ASSIGN  */
#line 232 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2094 "C_grammar.tab.c"
    break;

  case 82: /* assignment_operator: SUB_ASSIGN  */
#line 233 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2100 "C_grammar.tab.c"
    break;

  case 83: /* assignment_operator: LEFT_ASSIGN  */
#line 234 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2106 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: RIGHT_ASSIGN  */
#line 235 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2112 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: AND_ASSIGN  */
#line 236 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2118 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: XOR_ASSIGN  */
#line 237 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2124 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: OR_ASSIGN  */
#line 238 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2130 "C_grammar.tab.c"
    break;

  case 88: /* expression: assignment_expression  */
#line 242 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2136 "C_grammar.tab.c"
    break;

  case 89: /* expression: expression ',' assignment_expression  */
#line 244 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2147 "C_grammar.tab.c"
    break;

  case 90: /* constant_expression: conditional_expression  */
#line 253 "C_grammar.y"
                                                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2153 "C_grammar.tab.c"
    break;

  case 91: /* declaration: declaration_specifiers ';'  */
#line 258 "C_grammar.y"
                {fprintf(pl_file, "declaration([%s])\n", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2161 "C_grammar.tab.c"
    break;

  case 92: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 262 "C_grammar.y"
          {if (typedef_flag == 1) {	//we were processing typedef declarations
	     typedef_flag = 0;
	   }
	   fprintf(pl_file, "declaration([%s], [%s])\n", (yyvsp[-2].id), (yyvsp[-1].id));
	   free((yyvsp[-2].id));
	   free((yyvsp[-1].id));
	  }
#line 2173 "C_grammar.tab.c"
    break;

  case 93: /* declaration: static_assert_declaration  */
#line 270 "C_grammar.y"
                {fprintf(pl_file, "static_assert_declaration\n");
		}
#line 2180 "C_grammar.tab.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 276 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2191 "C_grammar.tab.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier  */
#line 282 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2197 "C_grammar.tab.c"
    break;

  case 96: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 284 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2208 "C_grammar.tab.c"
    break;

  case 97: /* declaration_specifiers: type_specifier  */
#line 290 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2214 "C_grammar.tab.c"
    break;

  case 98: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 292 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier declaration_specifiers"); }
#line 2220 "C_grammar.tab.c"
    break;

  case 99: /* declaration_specifiers: type_qualifier  */
#line 294 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier"); }
#line 2226 "C_grammar.tab.c"
    break;

  case 100: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 296 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier declaration_specifiers"); }
#line 2232 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: function_specifier  */
#line 298 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier"); }
#line 2238 "C_grammar.tab.c"
    break;

  case 102: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 300 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier declaration_specifiers"); }
#line 2244 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: alignment_specifier  */
#line 302 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier"); }
#line 2250 "C_grammar.tab.c"
    break;

  case 104: /* init_declarator_list: init_declarator  */
#line 306 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2256 "C_grammar.tab.c"
    break;

  case 105: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 308 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 2267 "C_grammar.tab.c"
    break;

  case 106: /* init_declarator: declarator '=' initializer  */
#line 318 "C_grammar.y"
          {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_s((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   //free($3);
	  }
#line 2278 "C_grammar.tab.c"
    break;

  case 107: /* init_declarator: declarator  */
#line 325 "C_grammar.y"
          {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name((yyvsp[0].id));
	   }
	   simple_str_copy(&(yyval.id), (yyvsp[0].id));
	  }
#line 2288 "C_grammar.tab.c"
    break;

  case 108: /* storage_class_specifier: TYPEDEF  */
#line 334 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
	    }
#line 2296 "C_grammar.tab.c"
    break;

  case 109: /* storage_class_specifier: EXTERN  */
#line 337 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 2302 "C_grammar.tab.c"
    break;

  case 110: /* storage_class_specifier: STATIC  */
#line 338 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 2308 "C_grammar.tab.c"
    break;

  case 111: /* storage_class_specifier: THREAD_LOCAL  */
#line 339 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 2314 "C_grammar.tab.c"
    break;

  case 112: /* storage_class_specifier: AUTO  */
#line 340 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 2320 "C_grammar.tab.c"
    break;

  case 113: /* storage_class_specifier: REGISTER  */
#line 341 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 2326 "C_grammar.tab.c"
    break;

  case 114: /* type_specifier: VOID  */
#line 345 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 2332 "C_grammar.tab.c"
    break;

  case 115: /* type_specifier: CHAR  */
#line 346 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 2338 "C_grammar.tab.c"
    break;

  case 116: /* type_specifier: SHORT  */
#line 347 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 2344 "C_grammar.tab.c"
    break;

  case 117: /* type_specifier: INT  */
#line 348 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 2350 "C_grammar.tab.c"
    break;

  case 118: /* type_specifier: LONG  */
#line 349 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 2356 "C_grammar.tab.c"
    break;

  case 119: /* type_specifier: FLOAT  */
#line 350 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 2362 "C_grammar.tab.c"
    break;

  case 120: /* type_specifier: DOUBLE  */
#line 351 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 2368 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: SIGNED  */
#line 352 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 2374 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: UNSIGNED  */
#line 353 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 2380 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: BOOL  */
#line 354 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 2386 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: COMPLEX  */
#line 355 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 2392 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: IMAGINARY  */
#line 356 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 2398 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: atomic_type_specifier  */
#line 357 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 2404 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: struct_or_union_specifier  */
#line 358 "C_grammar.y"
                                        { simple_str_lit_copy(&(yyval.id), "struct_or_union_specifier"); }
#line 2410 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: enum_specifier  */
#line 359 "C_grammar.y"
                                        { simple_str_lit_copy(&(yyval.id), "enum_specifier"); }
#line 2416 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: TYPEDEF_NAME  */
#line 361 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2422 "C_grammar.tab.c"
    break;

  case 159: /* type_qualifier: CONST  */
#line 427 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 2428 "C_grammar.tab.c"
    break;

  case 160: /* type_qualifier: RESTRICT  */
#line 428 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 2434 "C_grammar.tab.c"
    break;

  case 161: /* type_qualifier: VOLATILE  */
#line 429 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 2440 "C_grammar.tab.c"
    break;

  case 162: /* type_qualifier: ATOMIC  */
#line 430 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 2446 "C_grammar.tab.c"
    break;

  case 163: /* function_specifier: INLINE  */
#line 434 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 2452 "C_grammar.tab.c"
    break;

  case 164: /* function_specifier: NORETURN  */
#line 435 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 2458 "C_grammar.tab.c"
    break;

  case 167: /* declarator: pointer direct_declarator  */
#line 445 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 2469 "C_grammar.tab.c"
    break;

  case 168: /* declarator: direct_declarator  */
#line 452 "C_grammar.y"
          {size_t const size = strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       strcpy_s((yyval.id), size, (yyvsp[0].id));
       free((yyvsp[0].id));
      }
#line 2479 "C_grammar.tab.c"
    break;

  case 169: /* direct_declarator: IDENTIFIER  */
#line 460 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2485 "C_grammar.tab.c"
    break;

  case 170: /* direct_declarator: '(' declarator ')'  */
#line 461 "C_grammar.y"
                                                {simple_str_lit_copy(&(yyval.id), "D1");}
#line 2491 "C_grammar.tab.c"
    break;

  case 171: /* direct_declarator: direct_declarator '[' ']'  */
#line 462 "C_grammar.y"
                                                {simple_str_lit_copy(&(yyval.id), "D2"); }
#line 2497 "C_grammar.tab.c"
    break;

  case 172: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 463 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "D3"); }
#line 2503 "C_grammar.tab.c"
    break;

  case 173: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 464 "C_grammar.y"
                                                                                     {simple_str_lit_copy(&(yyval.id), "D4"); }
#line 2509 "C_grammar.tab.c"
    break;

  case 174: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 465 "C_grammar.y"
                                                                {simple_str_lit_copy(&(yyval.id), "D5"); }
#line 2515 "C_grammar.tab.c"
    break;

  case 175: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 466 "C_grammar.y"
                                                           {simple_str_lit_copy(&(yyval.id), "D6"); }
#line 2521 "C_grammar.tab.c"
    break;

  case 176: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 467 "C_grammar.y"
                                                                                    {simple_str_lit_copy(&(yyval.id), "D7"); }
#line 2527 "C_grammar.tab.c"
    break;

  case 177: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 468 "C_grammar.y"
                                                                             {simple_str_lit_copy(&(yyval.id), "D8"); }
#line 2533 "C_grammar.tab.c"
    break;

  case 178: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 469 "C_grammar.y"
                                                       {simple_str_lit_copy(&(yyval.id), "D9"); }
#line 2539 "C_grammar.tab.c"
    break;

  case 179: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 470 "C_grammar.y"
                                                         {simple_str_lit_copy(&(yyval.id), "D10"); }
#line 2545 "C_grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 471 "C_grammar.y"
                                                       {simple_str_lit_copy(&(yyval.id), "D11"); }
#line 2551 "C_grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '(' ')'  */
#line 472 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "D12"); }
#line 2557 "C_grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 473 "C_grammar.y"
                                                   {simple_str_lit_copy(&(yyval.id), "D13"); }
#line 2563 "C_grammar.tab.c"
    break;

  case 183: /* pointer: '*' type_qualifier_list pointer  */
#line 478 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2574 "C_grammar.tab.c"
    break;

  case 184: /* pointer: '*' type_qualifier_list  */
#line 485 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 2584 "C_grammar.tab.c"
    break;

  case 185: /* pointer: '*' pointer  */
#line 491 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2594 "C_grammar.tab.c"
    break;

  case 186: /* pointer: '*'  */
#line 497 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 2600 "C_grammar.tab.c"
    break;

  case 187: /* type_qualifier_list: type_qualifier  */
#line 501 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2606 "C_grammar.tab.c"
    break;

  case 188: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 503 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2617 "C_grammar.tab.c"
    break;

  case 243: /* $@1: %empty  */
#line 608 "C_grammar.y"
                         {fprintf(pl_file, "label_stmt($1, "); free((yyvsp[-1].id));}
#line 2623 "C_grammar.tab.c"
    break;

  case 244: /* labeled_statement: IDENTIFIER ':' $@1 statement  */
#line 608 "C_grammar.y"
                                                                                    {fprintf(pl_file, ")");}
#line 2629 "C_grammar.tab.c"
    break;

  case 245: /* $@2: %empty  */
#line 609 "C_grammar.y"
                                       {fprintf(pl_file, "case_stmt($2, "); free((yyvsp[-1].id));}
#line 2635 "C_grammar.tab.c"
    break;

  case 246: /* labeled_statement: CASE constant_expression ':' $@2 statement  */
#line 609 "C_grammar.y"
                                                                                                 {fprintf(pl_file, ")");}
#line 2641 "C_grammar.tab.c"
    break;

  case 247: /* $@3: %empty  */
#line 610 "C_grammar.y"
                      {fprintf(pl_file, "default_stmt(");}
#line 2647 "C_grammar.tab.c"
    break;

  case 248: /* labeled_statement: DEFAULT ':' $@3 statement  */
#line 610 "C_grammar.y"
                                                                     {fprintf(pl_file, ")");}
#line 2653 "C_grammar.tab.c"
    break;

  case 249: /* compound_statement: '{' '}'  */
#line 614 "C_grammar.y"
                  {fprintf(pl_file, "cmp_stmts([])");}
#line 2659 "C_grammar.tab.c"
    break;

  case 250: /* $@4: %empty  */
#line 615 "C_grammar.y"
              {fprintf(pl_file, "cmp_stmts([");}
#line 2665 "C_grammar.tab.c"
    break;

  case 251: /* compound_statement: '{' $@4 block_item_list '}'  */
#line 615 "C_grammar.y"
                                                                     {fprintf(pl_file, "])");}
#line 2671 "C_grammar.tab.c"
    break;

  case 253: /* $@5: %empty  */
#line 620 "C_grammar.y"
                          {fprintf(pl_file, ", ");}
#line 2677 "C_grammar.tab.c"
    break;

  case 257: /* expression_statement: ';'  */
#line 629 "C_grammar.y"
                                        {fprintf(pl_file, "exp_stmt()");}
#line 2683 "C_grammar.tab.c"
    break;

  case 258: /* expression_statement: expression ';'  */
#line 630 "C_grammar.y"
                                {fprintf(pl_file, "exp_stmt(%s)", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 2689 "C_grammar.tab.c"
    break;

  case 259: /* $@6: %empty  */
#line 634 "C_grammar.y"
                                {fprintf(pl_file, "if_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 2695 "C_grammar.tab.c"
    break;

  case 260: /* selection_statement: IF '(' expression ')' $@6 statement else_opt  */
#line 634 "C_grammar.y"
                                                                                                     {fprintf(pl_file, ")");}
#line 2701 "C_grammar.tab.c"
    break;

  case 261: /* $@7: %empty  */
#line 635 "C_grammar.y"
                                    {fprintf(pl_file, "switch_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 2707 "C_grammar.tab.c"
    break;

  case 262: /* selection_statement: SWITCH '(' expression ')' $@7 statement  */
#line 635 "C_grammar.y"
                                                                                                        {fprintf(pl_file, ")");}
#line 2713 "C_grammar.tab.c"
    break;

  case 264: /* $@8: %empty  */
#line 640 "C_grammar.y"
               {fprintf(pl_file, ", ");}
#line 2719 "C_grammar.tab.c"
    break;

  case 266: /* $@9: %empty  */
#line 643 "C_grammar.y"
                                   {fprintf(pl_file, "while_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 2725 "C_grammar.tab.c"
    break;

  case 267: /* iteration_statement: WHILE '(' expression ')' $@9 statement  */
#line 643 "C_grammar.y"
                                                                                                  {fprintf(pl_file, ")");}
#line 2731 "C_grammar.tab.c"
    break;

  case 268: /* $@10: %empty  */
#line 644 "C_grammar.y"
             {fprintf(pl_file, "do_while_stmt(");}
#line 2737 "C_grammar.tab.c"
    break;

  case 269: /* iteration_statement: DO $@10 statement WHILE '(' expression ')' ';'  */
#line 644 "C_grammar.y"
                                                                                          {fprintf(pl_file, ", %s)", (yyvsp[-2].id)); free((yyvsp[-2].id));}
#line 2743 "C_grammar.tab.c"
    break;

  case 270: /* $@11: %empty  */
#line 645 "C_grammar.y"
                  {fprintf(pl_file, "for_stmt(");}
#line 2749 "C_grammar.tab.c"
    break;

  case 271: /* $@12: %empty  */
#line 645 "C_grammar.y"
                                                                     {fprintf(pl_file, ", ");}
#line 2755 "C_grammar.tab.c"
    break;

  case 272: /* iteration_statement: FOR '(' $@11 for_stmt_type ')' $@12 statement  */
#line 645 "C_grammar.y"
                                                                                                         {fprintf(pl_file, ")");}
#line 2761 "C_grammar.tab.c"
    break;

  case 273: /* $@13: %empty  */
#line 649 "C_grammar.y"
                               {fprintf(pl_file, ", ");}
#line 2767 "C_grammar.tab.c"
    break;

  case 275: /* $@14: %empty  */
#line 650 "C_grammar.y"
                      {fprintf(pl_file, ", ");}
#line 2773 "C_grammar.tab.c"
    break;

  case 278: /* expression_opt: expression  */
#line 655 "C_grammar.y"
                     {fprintf(pl_file, ", %s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 2779 "C_grammar.tab.c"
    break;

  case 279: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 658 "C_grammar.y"
                                {fprintf(pl_file, "goto_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 2785 "C_grammar.tab.c"
    break;

  case 280: /* jump_statement: CONTINUE ';'  */
#line 659 "C_grammar.y"
                                        {fprintf(pl_file, "continue_stmt\n");}
#line 2791 "C_grammar.tab.c"
    break;

  case 281: /* jump_statement: BREAK ';'  */
#line 660 "C_grammar.y"
                                                {fprintf(pl_file, "break_stmt\n");}
#line 2797 "C_grammar.tab.c"
    break;

  case 282: /* jump_statement: RETURN ';'  */
#line 661 "C_grammar.y"
                                        {fprintf(pl_file, "return_stmt\n");}
#line 2803 "C_grammar.tab.c"
    break;

  case 283: /* jump_statement: RETURN expression ';'  */
#line 662 "C_grammar.y"
                                {fprintf(pl_file, "return_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 2809 "C_grammar.tab.c"
    break;

  case 285: /* $@15: %empty  */
#line 667 "C_grammar.y"
                           { fprintf(pl_file, ", "); }
#line 2815 "C_grammar.tab.c"
    break;

  case 289: /* $@16: %empty  */
#line 676 "C_grammar.y"
                                            {fprintf(pl_file, "function(%s, %s, [", (yyvsp[-1].id), (yyvsp[0].id)); free((yyvsp[-1].id)); free((yyvsp[0].id));}
#line 2821 "C_grammar.tab.c"
    break;

  case 290: /* $@17: %empty  */
#line 676 "C_grammar.y"
                                                                                                                                       {fprintf(pl_file, "], ");}
#line 2827 "C_grammar.tab.c"
    break;

  case 291: /* function_definition: declaration_specifiers declarator $@16 declaration_list_opt $@17 compound_statement  */
#line 676 "C_grammar.y"
                                                                                                                                                                                     {fprintf(pl_file, ")");}
#line 2833 "C_grammar.tab.c"
    break;

  case 295: /* $@18: %empty  */
#line 686 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 2839 "C_grammar.tab.c"
    break;


#line 2843 "C_grammar.tab.c"

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

#line 689 "C_grammar.y"

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
	if (yyparse() != 0) {
		fprintf(stderr, "Parsing failed.\n");
		exit(EXIT_FAILURE);
	}
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

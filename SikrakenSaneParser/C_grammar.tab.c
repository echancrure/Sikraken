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

FILE* pl_file;				//the file of containing the Prolog predicated after parsing the target C file
char pl_file_uri[_MAX_PATH];	//the full path to the Pl_file
char id_names[1000];		//string to hold Prolog var names and their details e.g. a(I_407, 'ch8_1.adb:39:7:i')
int id_counter = 1;			//used to generate unique Prolog var names e.g. I_1, I_2, I_3 etc.
int in_member_decl_flag = 0;	//indicate that we are parsing struct or union declarations and that the ids are part of the members namespace

void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);

int debugMode = 0;				//flag to indicate if we are in debug mode set by by -d command line switch

#line 97 "C_grammar.tab.c"

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
  YYSYMBOL_144_1 = 144,                    /* $@1  */
  YYSYMBOL_specifier_qualifier_list = 145, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 146,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 147,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 148,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 149,          /* enumerator_list  */
  YYSYMBOL_enumerator = 150,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 151,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 152,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 153,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 154,      /* alignment_specifier  */
  YYSYMBOL_declarator = 155,               /* declarator  */
  YYSYMBOL_direct_declarator = 156,        /* direct_declarator  */
  YYSYMBOL_pointer = 157,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 158,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 159,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 160,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 161,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 162,          /* identifier_list  */
  YYSYMBOL_type_name = 163,                /* type_name  */
  YYSYMBOL_abstract_declarator = 164,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 165, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 166,              /* initializer  */
  YYSYMBOL_initializer_list = 167,         /* initializer_list  */
  YYSYMBOL_designation = 168,              /* designation  */
  YYSYMBOL_designator_list = 169,          /* designator_list  */
  YYSYMBOL_designator = 170,               /* designator  */
  YYSYMBOL_static_assert_declaration = 171, /* static_assert_declaration  */
  YYSYMBOL_statement = 172,                /* statement  */
  YYSYMBOL_labeled_statement = 173,        /* labeled_statement  */
  YYSYMBOL_174_2 = 174,                    /* $@2  */
  YYSYMBOL_175_3 = 175,                    /* $@3  */
  YYSYMBOL_176_4 = 176,                    /* $@4  */
  YYSYMBOL_compound_statement = 177,       /* compound_statement  */
  YYSYMBOL_178_5 = 178,                    /* $@5  */
  YYSYMBOL_block_item_list = 179,          /* block_item_list  */
  YYSYMBOL_180_6 = 180,                    /* $@6  */
  YYSYMBOL_block_item = 181,               /* block_item  */
  YYSYMBOL_expression_statement = 182,     /* expression_statement  */
  YYSYMBOL_selection_statement = 183,      /* selection_statement  */
  YYSYMBOL_184_7 = 184,                    /* $@7  */
  YYSYMBOL_185_8 = 185,                    /* $@8  */
  YYSYMBOL_else_opt = 186,                 /* else_opt  */
  YYSYMBOL_187_9 = 187,                    /* $@9  */
  YYSYMBOL_iteration_statement = 188,      /* iteration_statement  */
  YYSYMBOL_189_10 = 189,                   /* $@10  */
  YYSYMBOL_190_11 = 190,                   /* $@11  */
  YYSYMBOL_191_12 = 191,                   /* $@12  */
  YYSYMBOL_192_13 = 192,                   /* $@13  */
  YYSYMBOL_for_stmt_type = 193,            /* for_stmt_type  */
  YYSYMBOL_194_14 = 194,                   /* $@14  */
  YYSYMBOL_195_15 = 195,                   /* $@15  */
  YYSYMBOL_expression_opt = 196,           /* expression_opt  */
  YYSYMBOL_jump_statement = 197,           /* jump_statement  */
  YYSYMBOL_translation_unit = 198,         /* translation_unit  */
  YYSYMBOL_199_16 = 199,                   /* $@16  */
  YYSYMBOL_external_declaration = 200,     /* external_declaration  */
  YYSYMBOL_function_definition = 201,      /* function_definition  */
  YYSYMBOL_202_17 = 202,                   /* $@17  */
  YYSYMBOL_203_18 = 203,                   /* $@18  */
  YYSYMBOL_declaration_list_opt = 204,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 205,         /* declaration_list  */
  YYSYMBOL_206_19 = 206                    /* $@19  */
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
#define YYLAST   2099

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  303
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  493

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
       0,    68,    68,    69,    70,    71,    72,    76,    77,    78,
      82,    87,    88,    92,    96,    97,   101,   102,   106,   107,
     114,   120,   127,   134,   141,   147,   153,   160,   170,   171,
     181,   182,   189,   196,   202,   208,   217,   218,   222,   223,
     224,   225,   226,   227,   231,   232,   242,   243,   254,   255,
     256,   260,   261,   272,   273,   277,   278,   289,   290,   294,
     295,   306,   307,   308,   309,   314,   315,   326,   327,   331,
     332,   342,   343,   353,   354,   364,   365,   375,   376,   386,
     387,   398,   399,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   424,   425,   435,   439,   443,   451,
     458,   465,   466,   473,   474,   476,   478,   480,   482,   484,
     489,   490,   500,   507,   516,   520,   521,   522,   523,   524,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   547,   554,   562,   572,
     573,   577,   579,   589,   595,   595,   603,   608,   615,   617,
     624,   629,   631,   641,   647,   654,   659,   665,   671,   678,
     685,   694,   696,   706,   713,   718,   722,   723,   724,   725,
     729,   730,   734,   735,   739,   746,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     768,   775,   781,   787,   792,   793,   803,   804,   808,   809,
     813,   814,   815,   819,   820,   824,   825,   829,   830,   831,
     835,   836,   837,   838,   839,   840,   841,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   852,   853,   854,
     855,   859,   865,   871,   876,   883,   885,   893,   903,   912,
     914,   924,   926,   935,   945,   946,   947,   948,   949,   950,
     955,   954,   956,   956,   957,   957,   961,   962,   962,   966,
     967,   967,   971,   972,   976,   977,   981,   981,   982,   982,
     986,   987,   987,   990,   990,   991,   991,   992,   992,   992,
     996,   996,   997,   997,  1001,  1002,  1005,  1006,  1007,  1008,
    1009,  1013,  1014,  1014,  1018,  1019,  1023,  1023,  1023,  1027,
    1028,  1032,  1033,  1033
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
  "struct_declaration_list", "struct_declaration", "$@1",
  "specifier_qualifier_list", "struct_declarator_list",
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

#define YYPACT_NINF (-420)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-301)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1871,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,    31,   -34,   -16,  -420,   -14,
    -420,  -420,    60,  1976,  1976,  -420,    33,  -420,  -420,  1976,
    1976,  1976,  -420,    53,  -420,  -420,   -52,    67,   803,  2028,
    1439,  -420,    65,   155,  -420,   -41,  -420,   -60,   -50,    47,
    -420,  -420,    41,  1534,  -420,  -420,  -420,  -420,  1871,    67,
    -420,   -11,   150,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    1527,  -420,  -420,    66,    73,   803,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,   178,  -420,  1548,  1439,
    -420,   125,   -59,   163,    78,   169,    37,    58,    77,   141,
      46,  -420,   124,  2028,    74,  2028,   126,   128,   132,   135,
    -420,  -420,  -420,   155,    65,  -420,  1309,  1871,  1819,   825,
     -50,  1534,  1714,  -420,   121,  -420,  -420,   154,  1439,    14,
    -420,   803,  -420,  2028,  1439,   314,  -420,  -420,   146,   148,
     230,  -420,  -420,  1397,  1439,   232,   803,  -420,  -420,  -420,
    -420,  -420,  1439,  -420,  -420,  1439,  -420,  -420,  1439,  -420,
    -420,  -420,  -420,  1439,  -420,  -420,  1439,  1439,  1439,  1439,
    1439,  1439,  1439,  -420,  -420,  1662,   913,   -19,  -420,     4,
    -420,  -420,  -420,   229,  -420,  -420,  -420,  -420,   144,  1288,
    -420,  -420,  -420,    60,  -420,   176,  -420,  -420,    20,   167,
     183,  -420,   171,  1158,  -420,   185,   198,   936,  1766,  -420,
    -420,  -420,    69,    29,  -420,  -420,  -420,  -420,   187,   200,
     209,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  1439,  -420,  1439,  1418,  -420,  -420,   173,  -420,
      39,  -420,   211,  -420,   125,   -59,   163,    78,   169,    37,
      58,    77,   141,   174,  -420,   212,   214,  1158,  -420,   213,
     215,  1024,     4,   456,  1047,   218,  1439,   295,  -420,   161,
    1309,   -55,  -420,   216,  1871,  1607,  -420,    99,  -420,  -420,
    1923,  -420,   297,   220,  1158,  -420,  -420,  1439,  -420,   222,
     223,  -420,  1439,   -13,  -420,   227,  -420,   224,  -420,   691,
    -420,  -420,  1288,  -420,  -420,  1439,  -420,   224,  1439,  -420,
    -420,   228,  1158,  -420,  -420,  1439,  -420,   233,  -420,   231,
    1158,  -420,   234,   235,  1135,   221,   236,  -420,  1179,  -420,
    -420,  -420,  -420,   237,  -420,  -420,  -420,  -420,  -420,  -420,
     238,   241,  -420,  -420,  -420,    69,  -420,  1439,   244,   191,
    -420,   245,   162,  -420,  -420,  -420,   247,   248,  -420,  -420,
     250,  1158,  -420,  -420,  1439,  -420,   265,  -420,  -420,  -420,
    -420,  1309,  -420,   539,  -420,  -420,  -420,  -420,  1439,  -420,
     691,  1439,  1267,  -420,  -420,  -420,  -420,   266,   271,  -420,
    -420,   274,  1439,   275,   282,   283,   284,  -420,   285,   310,
     264,   269,   680,  -420,   105,  -420,  -420,  -420,  -420,   280,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,   286,  -420,  1439,  1439,  1439,   369,  -420,   270,
    -420,  -420,  -420,   119,  -420,  -420,   539,   369,  -420,   369,
     196,   204,   206,   308,   627,  -420,  -420,  -420,  -420,   369,
    -420,  -420,  -420,  -420,   304,  -420,  -420,   294,  -420,   369,
     369,   369,  1439,   715,   715,  -420,   313,  -420,  -420,   208,
    1439,  1439,   369,  -420,  -420,   289,   305,  -420,  -420,  -420,
     369,  -420,  -420
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   135,   114,   115,   116,   118,   119,   170,   166,   167,
     168,   129,   121,   122,   123,   124,   127,   128,   125,   126,
     120,   130,   131,   139,   140,     0,     0,   169,   171,     0,
     117,   295,     0,   101,   103,   133,     0,   134,   132,   105,
     107,   109,    99,   292,   291,   294,   160,     0,     0,     0,
       0,   176,     0,   193,    97,     0,   110,   296,   175,     0,
     100,   102,   138,     0,   104,   106,   108,     1,     0,     0,
      10,   164,     0,   161,     2,     7,     8,     9,    11,    12,
       0,    36,    37,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    18,     3,     4,     6,    30,    44,     0,     0,
      46,    51,    55,    59,    65,    69,    71,    73,    75,    77,
      79,    96,     0,   148,   206,   150,     0,     0,     0,     0,
     169,   194,   192,   191,     0,    98,     0,   299,     0,     0,
     174,     0,     0,   141,   144,   146,   293,     0,     0,     0,
     156,     0,    33,     0,     0,    44,    81,    94,     0,     0,
       0,    24,    25,     0,     0,     0,     0,    31,    32,    48,
      49,    50,     0,    53,    54,     0,    57,    58,     0,    63,
      64,    61,    62,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,   173,   147,     0,     0,   208,   205,   209,
     149,   172,   165,     0,   177,   195,   190,   111,   113,     0,
     233,   112,   301,     0,   297,   302,   203,   188,   202,     0,
     197,   198,     0,     0,   178,    39,     0,     0,     0,   136,
     142,   143,     0,     0,   158,   163,   157,   162,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    83,     0,     5,     0,     0,    23,    20,     0,    28,
       0,    22,     0,    47,    52,    56,    60,    66,    70,    72,
      74,    76,    78,     0,   227,     0,     0,     0,   211,    39,
       0,     0,   207,     0,     0,     0,     0,     0,   235,     0,
       0,     0,   239,     0,     0,     0,   200,   208,   201,   187,
       0,   189,     0,     0,     0,   179,   186,     0,   185,    39,
       0,   137,     0,     0,   151,   155,   159,    34,    35,     0,
      82,    95,     0,    45,    21,     0,    19,     0,     0,   228,
     210,     0,     0,   212,   218,     0,   217,     0,   229,     0,
       0,   219,    39,     0,     0,     0,     0,   242,     0,   231,
     234,   238,   240,   257,   298,   303,   196,   199,   204,   181,
       0,     0,   182,   184,   153,     0,   145,     0,     0,     0,
      14,     0,     0,    29,    80,   214,     0,     0,   216,   230,
       0,     0,   220,   226,     0,   225,     0,   243,   241,   232,
     237,     0,   256,     0,   180,   183,   152,   154,     0,    13,
       0,     0,     0,    26,   213,   215,   222,     0,     0,   223,
     236,     2,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,     0,   264,     0,   262,   263,   244,   245,   260,
     259,   246,   247,   248,   249,    17,    15,    16,    27,   221,
     224,   250,     0,   254,     0,     0,     0,     0,   277,     0,
     287,   288,   289,     0,   265,   258,     0,     0,   252,     0,
       0,     0,     0,     0,     0,   286,   290,   261,   251,     0,
     255,   266,   268,   273,     0,   282,   280,     0,   253,     0,
       0,     0,     0,     0,     0,   278,   270,   269,   274,     0,
     284,   284,     0,   271,   267,     0,   285,   283,   281,   279,
       0,   276,   272
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -420,  -420,  -420,  -420,  -420,  -420,  -420,    -6,  -420,  -420,
     -47,  -420,  -420,   -83,   225,  -420,   217,  -420,   219,  -420,
     226,  -420,   240,  -420,   243,   210,   239,   257,  -420,   -46,
     149,  -420,   -85,   -45,  -121,     7,  -420,   273,  -420,    25,
    -420,  -420,   263,  -119,  -420,   -49,  -420,    43,  -420,   330,
    -120,  -420,    -4,  -420,  -420,   -23,   -51,   -38,  -109,  -106,
    -420,   110,  -420,    59,  -103,  -175,  -116,    89,  -314,  -420,
     122,   -42,  -263,  -420,  -420,  -420,  -420,   123,  -420,  -420,
    -420,   -39,  -419,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,   -77,  -420,  -420,  -420,
     337,  -420,  -420,  -420,  -420,  -420,  -420
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    71,    94,    95,   359,   360,    96,   248,
     145,    98,    99,   100,   101,   162,   102,   165,   103,   168,
     104,   173,   105,   176,   106,   107,   108,   109,   110,   146,
     147,   242,   414,   112,    31,   203,    55,    56,    33,    34,
      35,    36,   132,   133,   222,   114,   303,   304,    37,    72,
      73,    38,    39,    40,    41,   119,    58,    59,   123,   265,
     210,   211,   212,   361,   266,   189,   278,   279,   280,   281,
     282,    42,   416,   417,   447,   459,   449,   418,   383,   419,
     446,   420,   421,   422,   469,   470,   484,   490,   423,   471,
     437,   454,   482,   467,   474,   473,   487,   424,    43,    68,
      44,    45,   127,   283,   204,   205,   284
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     148,    97,   111,    97,   111,   118,   202,    32,   130,    57,
     201,   188,   272,   220,   134,   122,   158,    70,  -113,   227,
     217,   135,   209,    51,   381,   276,   128,   277,   163,   164,
     129,    69,    70,   142,    46,   466,    62,   124,   126,  -113,
      60,    61,    48,   341,   115,   115,    64,    65,    66,   121,
      51,   157,    97,    67,   480,   481,   148,   185,   125,   115,
      49,   186,    50,    51,   184,   355,   190,   181,    51,   250,
      70,   148,    51,   113,   113,    32,   187,   271,   381,   253,
     273,   115,   134,   134,   274,   196,   356,   138,   113,   135,
     135,    97,   111,   225,   169,   170,   285,   263,   226,   220,
     186,   198,    51,   227,   294,   288,    53,   116,   117,   115,
     113,   115,   272,   306,    47,    97,    63,   244,    97,   195,
     316,    97,   177,    52,   131,   121,    97,   115,   115,    97,
      97,    97,    97,    97,    97,   208,    52,   115,   113,   115,
     113,    52,   143,   182,   149,    52,    53,   187,   302,   144,
     185,    53,   115,   178,   186,    53,   113,   113,   322,    54,
      53,   180,   313,   345,   340,   334,   113,   329,   113,   134,
     287,   171,   172,   179,   453,   285,   135,   166,   167,   186,
     198,   113,   121,   244,   458,   286,   460,   174,   175,   150,
     151,   152,   208,     8,     9,    10,   468,   244,    97,   305,
     228,   183,   229,   191,   444,   192,   476,   477,   478,   121,
     193,   159,   194,   195,   115,   252,   160,   161,   456,   489,
     221,   371,   380,   243,   244,   245,   120,   492,   139,    97,
     111,   336,   223,   246,   140,   251,   130,   275,   224,   338,
     392,    53,   126,   113,   289,   339,   393,   287,   291,   292,
     314,   315,   244,   318,   153,    97,   111,   354,   154,  -300,
     155,   290,   415,   121,   307,   400,   295,   195,   389,   390,
     121,    97,   364,   461,   244,   200,   380,   308,   216,   296,
     208,   462,   244,   463,   244,   485,   244,   309,   317,   319,
     195,   320,   208,   230,   323,   335,   324,   208,   337,   343,
     348,   349,   249,   352,   353,   115,   357,   312,   369,   365,
      97,   111,   387,   439,   368,   372,   373,   378,   195,   384,
     377,   382,   385,   388,   391,   415,   121,   443,   394,   395,
     195,   396,   305,   465,   113,   270,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   399,   429,   200,   450,
     451,   452,   430,   431,   433,    97,   111,   432,   434,   435,
     436,   438,   293,   440,   445,   448,   300,   195,   441,   455,
     464,   475,   401,   483,    75,    76,    77,    78,    79,    80,
     472,    81,    82,   244,   426,   255,   115,   479,   491,   260,
     254,   310,   256,   311,   218,   486,   486,   197,   386,   137,
     347,   362,   257,   342,   488,   136,   344,   457,     0,     0,
       0,     0,   241,     0,     0,   113,   321,   258,     0,   261,
     327,   259,     0,   333,     0,     0,   402,   403,   404,   200,
     405,   406,   407,   408,   409,   410,   411,   412,   262,    83,
       0,    84,     0,   350,     0,    85,   351,     0,     0,     0,
       0,     0,   343,     0,    86,    87,    88,    89,    90,    91,
       1,   200,     0,     0,   363,     0,     0,     0,   413,     0,
       0,   366,     0,     0,   367,     0,     0,     0,     0,   370,
       0,     0,     0,   376,     0,     0,     0,   200,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
     397,     0,     0,   398,     0,    26,     0,    27,     0,    28,
     200,    30,     0,   328,     0,     0,     0,   425,     0,     0,
     427,   200,   401,     1,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,   402,   403,   404,     0,
     405,   406,   407,   408,   409,   410,   411,   412,    26,    83,
      27,    84,    28,    29,    30,    85,     0,     0,     0,     0,
       0,     0,   343,     0,    86,    87,    88,    89,    90,    91,
      74,     1,    75,    76,    77,    78,    79,    80,   413,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    74,     0,    75,    76,    77,    78,    79,
      80,     0,    81,    82,     0,     1,    26,    83,    27,    84,
      28,    29,    30,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    74,     0,
      75,    76,    77,    78,    79,    80,   413,    81,    82,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,   358,
      83,     0,    84,     0,     0,     0,    85,     0,     0,     0,
       0,     0,    27,     0,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,    83,     0,    84,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    74,     1,    75,    76,
      77,    78,    79,    80,   413,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
      75,    76,    77,    78,    79,    80,     0,    81,    82,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   213,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,    83,    27,    84,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,     0,    83,   120,    84,     0,     0,
       0,    85,     0,     0,     0,     0,   214,     0,     0,     0,
      86,   215,    88,    89,    90,    91,    74,     0,    75,    76,
      77,    78,    79,    80,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,    75,    76,    77,    78,    79,    80,   267,    81,    82,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,    83,   120,    84,     0,     0,     0,    85,
       0,     0,     0,     0,   268,     0,     0,     0,    86,   269,
      88,    89,    90,    91,     0,     0,    83,   120,    84,     0,
       0,     0,    85,     0,     0,     0,     0,   298,     0,     0,
       0,    86,   299,    88,    89,    90,    91,    74,     0,    75,
      76,    77,    78,    79,    80,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,    75,    76,    77,    78,    79,    80,   325,    81,
      82,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   330,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,    83,   120,    84,     0,     0,     0,
      85,     0,     0,     0,     0,   326,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,    83,   120,    84,
       0,     0,     0,    85,     0,     0,     0,     0,   331,     0,
       0,     0,    86,   332,    88,    89,    90,    91,    74,     0,
      75,    76,    77,    78,    79,    80,     0,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    75,    76,    77,    78,    79,    80,   374,
      81,    82,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,    74,     0,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,    83,   120,    84,     0,     0,
       0,    85,     0,     0,     0,     0,   375,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,     0,    83,   120,
      84,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,    83,
       0,    84,     0,     0,     0,    85,     0,     0,     0,   276,
       0,   277,   199,   379,    86,    87,    88,    89,    90,    91,
      74,     0,    75,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,    84,
       0,     0,     0,    85,     0,     0,     0,   276,     0,   277,
     199,   428,    86,    87,    88,    89,    90,    91,    83,     0,
      84,     0,     0,     0,    85,     0,     0,     0,   276,     0,
     277,   199,     0,    86,    87,    88,    89,    90,    91,    83,
       0,    84,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,   199,     0,    86,    87,    88,    89,    90,    91,
      74,     0,    75,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,    84,
       0,     0,     0,    85,   247,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    83,     0,
      84,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,   312,     0,    86,    87,    88,    89,    90,    91,    83,
       0,    84,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      74,     0,    75,    76,    77,    78,    79,    80,     1,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,    83,     0,    84,
       0,     0,     0,   141,     0,    27,     0,     0,    29,     0,
      51,     1,    86,    87,    88,    89,    90,    91,    83,     0,
      84,     0,     0,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,     0,    30,   285,   264,     0,     0,   186,     0,     0,
       0,     0,     0,    53,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,   185,   264,
       0,     0,   186,     0,     0,     0,     0,     0,    53,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   206,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     301,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,     0,   207,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   346,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      85,    48,    48,    50,    50,    50,   127,     0,    59,    32,
     126,   114,   187,   132,    63,    53,    99,     3,    78,   139,
     129,    63,   128,     3,   338,    80,    76,    82,    87,    88,
      80,    83,     3,    80,     3,   454,     3,    78,    98,    99,
      33,    34,    76,    98,    48,    49,    39,    40,    41,    53,
       3,    98,    99,     0,   473,   474,   141,    76,    99,    63,
      76,    80,    76,     3,   113,    78,   115,    21,     3,   154,
       3,   156,     3,    48,    49,    68,   114,   186,   392,   162,
      76,    85,   131,   132,    80,   123,    99,    98,    63,   131,
     132,   138,   138,   138,    16,    17,    76,   182,    84,   218,
      80,   124,     3,   223,   213,   208,    86,    48,    49,   113,
      85,   115,   287,    84,    83,   162,    83,    78,   165,   123,
      81,   168,    85,    76,    83,   129,   173,   131,   132,   176,
     177,   178,   179,   180,   181,   128,    76,   141,   113,   143,
     115,    76,    76,    97,    85,    76,    86,   185,    79,    76,
      76,    86,   156,    95,    80,    86,   131,   132,   267,    99,
      86,    20,   245,   284,   280,   274,   141,   273,   143,   218,
     208,    93,    94,    96,   437,    76,   218,    14,    15,    80,
     203,   156,   186,    78,   447,   208,   449,    18,    19,    11,
      12,    13,   185,    38,    39,    40,   459,    78,   245,   222,
     141,    77,   143,    77,    99,    77,   469,   470,   471,   213,
      78,    86,    77,   217,   218,   156,    91,    92,    99,   482,
      99,   330,   338,    77,    78,    77,    71,   490,    78,   276,
     276,   276,    78,     3,    84,     3,   287,     8,    84,    78,
      78,    86,    98,   218,    77,    84,    84,   285,    77,    78,
      77,    78,    78,    79,    76,   302,   302,   302,    80,    83,
      82,    78,   383,   267,    77,   381,    81,   271,    77,    78,
     274,   318,   318,    77,    78,   126,   392,    77,   129,    81,
     273,    77,    78,    77,    78,    77,    78,    78,    77,    77,
     294,    77,   285,   144,    81,    77,    81,   290,     3,    83,
       3,    81,   153,    81,    81,   309,    79,    83,    77,    81,
     357,   357,   357,     3,    81,    81,    81,    81,   322,    81,
      99,    84,    81,    79,    79,   446,   330,   412,    81,    81,
     334,    81,   355,   454,   309,   186,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    81,    81,   199,   434,
     435,   436,    81,    79,    79,   402,   402,   402,    76,    76,
      76,    76,   213,    99,    84,    79,   217,   371,    99,    99,
      62,    77,     3,    60,     5,     6,     7,     8,     9,    10,
      76,    12,    13,    78,   390,   168,   390,   472,    99,   179,
     165,   242,   173,   244,   131,   480,   481,   124,   355,    69,
     290,   312,   176,   281,   481,    68,   283,   446,    -1,    -1,
      -1,    -1,    98,    -1,    -1,   390,   267,   177,    -1,   180,
     271,   178,    -1,   274,    -1,    -1,    57,    58,    59,   280,
      61,    62,    63,    64,    65,    66,    67,    68,   181,    70,
      -1,    72,    -1,   294,    -1,    76,   297,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
       4,   312,    -1,    -1,   315,    -1,    -1,    -1,    99,    -1,
      -1,   322,    -1,    -1,   325,    -1,    -1,    -1,    -1,   330,
      -1,    -1,    -1,   334,    -1,    -1,    -1,   338,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,    -1,    -1,   374,    -1,    69,    -1,    71,    -1,    73,
     381,    75,    -1,    77,    -1,    -1,    -1,   388,    -1,    -1,
     391,   392,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
       3,     4,     5,     6,     7,     8,     9,    10,    99,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     3,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,     4,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,     3,    -1,
       5,     6,     7,     8,     9,    10,    99,    12,    13,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,     3,     4,     5,     6,
       7,     8,     9,    10,    99,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    34,    12,    13,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,     3,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    34,    12,
      13,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,     3,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    34,
      12,    13,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    70,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    70,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    85,    86,    87,    88,    89,    90,    70,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       3,    -1,     5,     6,     7,     8,     9,    10,     4,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    71,    -1,    -1,    74,    -1,
       3,     4,    85,    86,    87,    88,    89,    90,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    77,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    86,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    77,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    73,    74,
      75,   134,   135,   138,   139,   140,   141,   148,   151,   152,
     153,   154,   171,   198,   200,   201,     3,    83,    76,    76,
      76,     3,    76,    86,    99,   136,   137,   155,   156,   157,
     135,   135,     3,    83,   135,   135,   135,     0,   199,    83,
       3,   103,   149,   150,     3,     5,     6,     7,     8,     9,
      10,    12,    13,    70,    72,    76,    85,    86,    87,    88,
      89,    90,   101,   102,   104,   105,   108,   110,   111,   112,
     113,   114,   116,   118,   120,   122,   124,   125,   126,   127,
     128,   129,   133,   139,   145,   152,   163,   163,   133,   155,
      71,   152,   157,   158,    78,    99,    98,   202,    76,    80,
     156,    83,   142,   143,   145,   171,   200,   149,    98,    78,
      84,    76,   110,    76,    76,   110,   129,   130,   132,   163,
      11,    12,    13,    76,    80,    82,    76,   110,   113,    86,
      91,    92,   115,    87,    88,   117,    14,    15,   119,    16,
      17,    93,    94,   121,    18,    19,   123,    85,    95,    96,
      20,    21,    97,    77,   145,    76,    80,   157,   164,   165,
     145,    77,    77,    78,    77,   152,   157,   137,   155,    83,
     130,   166,   134,   135,   204,   205,     3,    77,   135,   159,
     160,   161,   162,    34,    81,    86,   130,   158,   142,    84,
     143,    99,   144,    78,    84,   133,    84,   150,   163,   163,
     130,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    98,   131,    77,    78,    77,     3,    77,   109,   130,
     132,     3,   163,   113,   114,   116,   118,   120,   122,   124,
     125,   126,   127,   132,    77,   159,   164,    34,    81,    86,
     130,   158,   165,    76,    80,     8,    80,    82,   166,   167,
     168,   169,   170,   203,   206,    76,   155,   157,   164,    77,
      78,    77,    78,   130,   158,    81,    81,    34,    81,    86,
     130,    84,    79,   146,   147,   155,    84,    77,    77,    78,
     130,   130,    83,   113,    77,    78,    81,    77,    79,    77,
      77,   130,   158,    81,    81,    34,    81,   130,    77,   159,
      34,    81,    86,   130,   158,    77,   133,     3,    78,    84,
     166,    98,   170,    83,   177,   134,    56,   161,     3,    81,
     130,   130,    81,    81,   133,    78,    99,    79,    58,   106,
     107,   163,   167,   130,   129,    81,   130,   130,    81,    77,
     130,   158,    81,    81,    34,    81,   130,    99,    81,    84,
     166,   168,    84,   178,    81,    81,   147,   133,    79,    77,
      78,    79,    78,    84,    81,    81,    81,   130,   130,    81,
     166,     3,    57,    58,    59,    61,    62,    63,    64,    65,
      66,    67,    68,    99,   132,   134,   172,   173,   177,   179,
     181,   182,   183,   188,   197,   130,   107,   130,    84,    81,
      81,    79,   133,    79,    76,    76,    76,   190,    76,     3,
      99,    99,    99,   132,    99,    84,   180,   174,    79,   176,
     132,   132,   132,   172,   191,    99,    99,   181,   172,   175,
     172,    77,    77,    77,    62,   134,   182,   193,   172,   184,
     185,   189,    76,   195,   194,    77,   172,   172,   172,   132,
     182,   182,   192,    60,   186,    77,   132,   196,   196,   172,
     187,    99,   172
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
     141,   142,   142,   143,   144,   143,   143,   145,   145,   145,
     145,   146,   146,   147,   147,   147,   148,   148,   148,   148,
     148,   149,   149,   150,   150,   151,   152,   152,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   157,   157,   158,   158,   159,   159,   160,   160,
     161,   161,   161,   162,   162,   163,   163,   164,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   166,   166,   167,   167,   167,   167,   168,   169,
     169,   170,   170,   171,   172,   172,   172,   172,   172,   172,
     174,   173,   175,   173,   176,   173,   177,   178,   177,   179,
     180,   179,   181,   181,   182,   182,   184,   183,   185,   183,
     186,   187,   186,   189,   188,   190,   188,   191,   192,   188,
     194,   193,   195,   193,   196,   196,   197,   197,   197,   197,
     197,   198,   199,   198,   200,   200,   202,   203,   201,   204,
     204,   205,   206,   205
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
       2,     1,     3,     3,     1,     4,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     1,     1,     3,     3,     4,
       6,     5,     5,     6,     5,     4,     4,     4,     3,     4,
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
#line 68 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2004 "C_grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 69 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2010 "C_grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 70 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2016 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 71 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "prim4");}
#line 2022 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: generic_selection  */
#line 72 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2028 "C_grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 76 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2034 "C_grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 77 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2040 "C_grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 78 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2046 "C_grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 83 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2052 "C_grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 87 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2058 "C_grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 88 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2064 "C_grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 106 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2070 "C_grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 108 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2081 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 115 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s([])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2091 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 121 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2102 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 128 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2113 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 135 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2124 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 142 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2134 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 148 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2144 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 154 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2155 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 161 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2166 "C_grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 170 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2172 "C_grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 172 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2183 "C_grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 181 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2189 "C_grammar.tab.c"
    break;

  case 31: /* unary_expression: unary_inc_dec unary_expression  */
#line 183 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2200 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_operator cast_expression  */
#line 190 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2211 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: SIZEOF unary_expression  */
#line 197 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2221 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 203 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2231 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 209 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2241 "C_grammar.tab.c"
    break;

  case 36: /* unary_inc_dec: INC_OP  */
#line 217 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2247 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: DEC_OP  */
#line 218 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2253 "C_grammar.tab.c"
    break;

  case 38: /* unary_operator: '&'  */
#line 222 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "address_of_op");}
#line 2259 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '*'  */
#line 223 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "dereference_op");}
#line 2265 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '+'  */
#line 224 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2271 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '-'  */
#line 225 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2277 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '~'  */
#line 226 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "one_comp_op");}
#line 2283 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '!'  */
#line 227 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2289 "C_grammar.tab.c"
    break;

  case 44: /* cast_expression: unary_expression  */
#line 231 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2295 "C_grammar.tab.c"
    break;

  case 45: /* cast_expression: '(' type_name ')' cast_expression  */
#line 233 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2306 "C_grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: cast_expression  */
#line 242 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2312 "C_grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 244 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2324 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression_op: '*'  */
#line 254 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2330 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '/'  */
#line 255 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2336 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '%'  */
#line 256 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2342 "C_grammar.tab.c"
    break;

  case 51: /* additive_expression: multiplicative_expression  */
#line 260 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2348 "C_grammar.tab.c"
    break;

  case 52: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 262 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2360 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression_op: '+'  */
#line 272 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2366 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '-'  */
#line 273 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2372 "C_grammar.tab.c"
    break;

  case 55: /* shift_expression: additive_expression  */
#line 277 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2378 "C_grammar.tab.c"
    break;

  case 56: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 279 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2390 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression_op: LEFT_OP  */
#line 289 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift_op");}
#line 2396 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: RIGHT_OP  */
#line 290 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift_op");}
#line 2402 "C_grammar.tab.c"
    break;

  case 59: /* relational_expression: shift_expression  */
#line 294 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2408 "C_grammar.tab.c"
    break;

  case 60: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 296 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2420 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression_operator: '<'  */
#line 306 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2426 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '>'  */
#line 307 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2432 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: LE_OP  */
#line 308 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2438 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: GE_OP  */
#line 309 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2444 "C_grammar.tab.c"
    break;

  case 65: /* equality_expression: relational_expression  */
#line 314 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2450 "C_grammar.tab.c"
    break;

  case 66: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 316 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2462 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression_op: EQ_OP  */
#line 326 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2468 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: NE_OP  */
#line 327 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2474 "C_grammar.tab.c"
    break;

  case 69: /* and_expression: equality_expression  */
#line 331 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2480 "C_grammar.tab.c"
    break;

  case 70: /* and_expression: and_expression '&' equality_expression  */
#line 333 "C_grammar.y"
                {size_t const size = strlen("bitw_and(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_and(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2491 "C_grammar.tab.c"
    break;

  case 71: /* exclusive_or_expression: and_expression  */
#line 342 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2497 "C_grammar.tab.c"
    break;

  case 72: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 344 "C_grammar.y"
                {size_t const size = strlen("bitw_excl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_excl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2508 "C_grammar.tab.c"
    break;

  case 73: /* inclusive_or_expression: exclusive_or_expression  */
#line 353 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2514 "C_grammar.tab.c"
    break;

  case 74: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 355 "C_grammar.y"
                {size_t const size = strlen("bitw_incl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_incl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2525 "C_grammar.tab.c"
    break;

  case 75: /* logical_and_expression: inclusive_or_expression  */
#line 364 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2531 "C_grammar.tab.c"
    break;

  case 76: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 366 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2542 "C_grammar.tab.c"
    break;

  case 77: /* logical_or_expression: logical_and_expression  */
#line 375 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2548 "C_grammar.tab.c"
    break;

  case 78: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 377 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2559 "C_grammar.tab.c"
    break;

  case 79: /* conditional_expression: logical_or_expression  */
#line 386 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2565 "C_grammar.tab.c"
    break;

  case 80: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 388 "C_grammar.y"
                {size_t const size = strlen("cond_exp(, , )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "cond_exp(%s, %s, %s)", (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2577 "C_grammar.tab.c"
    break;

  case 81: /* assignment_expression: conditional_expression  */
#line 398 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2583 "C_grammar.tab.c"
    break;

  case 82: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 400 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2595 "C_grammar.tab.c"
    break;

  case 83: /* assignment_operator: '='  */
#line 410 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2601 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: MUL_ASSIGN  */
#line 411 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2607 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: DIV_ASSIGN  */
#line 412 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2613 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: MOD_ASSIGN  */
#line 413 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2619 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: ADD_ASSIGN  */
#line 414 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2625 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: SUB_ASSIGN  */
#line 415 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2631 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: LEFT_ASSIGN  */
#line 416 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2637 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: RIGHT_ASSIGN  */
#line 417 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2643 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: AND_ASSIGN  */
#line 418 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2649 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: XOR_ASSIGN  */
#line 419 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2655 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: OR_ASSIGN  */
#line 420 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2661 "C_grammar.tab.c"
    break;

  case 94: /* expression: assignment_expression  */
#line 424 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2667 "C_grammar.tab.c"
    break;

  case 95: /* expression: expression ',' assignment_expression  */
#line 426 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2678 "C_grammar.tab.c"
    break;

  case 96: /* constant_expression: conditional_expression  */
#line 435 "C_grammar.y"
                                                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2684 "C_grammar.tab.c"
    break;

  case 97: /* declaration: declaration_specifiers ';'  */
#line 440 "C_grammar.y"
                {fprintf(pl_file, "declaration([%s])\n", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2692 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 444 "C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
	     fprintf(pl_file, "declaration([%s], [%s])\n", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	  }
#line 2704 "C_grammar.tab.c"
    break;

  case 99: /* declaration: static_assert_declaration  */
#line 452 "C_grammar.y"
                {fprintf(pl_file, "%s\n", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2712 "C_grammar.tab.c"
    break;

  case 100: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 459 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2723 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier  */
#line 465 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2729 "C_grammar.tab.c"
    break;

  case 102: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 467 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2740 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier  */
#line 473 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2746 "C_grammar.tab.c"
    break;

  case 104: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 475 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier declaration_specifiers"); }
#line 2752 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier  */
#line 477 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier"); }
#line 2758 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 479 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier declaration_specifiers"); }
#line 2764 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier  */
#line 481 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier"); }
#line 2770 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 483 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier declaration_specifiers"); }
#line 2776 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier  */
#line 485 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier"); }
#line 2782 "C_grammar.tab.c"
    break;

  case 110: /* init_declarator_list: init_declarator  */
#line 489 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2788 "C_grammar.tab.c"
    break;

  case 111: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 491 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 2799 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator: declarator '=' initializer  */
#line 501 "C_grammar.y"
          {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	   (yyval.id) = (char*)malloc(size);
	   sprintf_s((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   free((yyvsp[-2].id));
	   //free($3);
	  }
#line 2810 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator  */
#line 508 "C_grammar.y"
          {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name((yyvsp[0].id));
	   }
	   simple_str_copy(&(yyval.id), (yyvsp[0].id));
	  }
#line 2820 "C_grammar.tab.c"
    break;

  case 114: /* storage_class_specifier: TYPEDEF  */
#line 517 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
	    }
#line 2828 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: EXTERN  */
#line 520 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 2834 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: STATIC  */
#line 521 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 2840 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: THREAD_LOCAL  */
#line 522 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 2846 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: AUTO  */
#line 523 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 2852 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: REGISTER  */
#line 524 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 2858 "C_grammar.tab.c"
    break;

  case 120: /* type_specifier: VOID  */
#line 528 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 2864 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: CHAR  */
#line 529 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 2870 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: SHORT  */
#line 530 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 2876 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: INT  */
#line 531 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 2882 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: LONG  */
#line 532 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 2888 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: FLOAT  */
#line 533 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 2894 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: DOUBLE  */
#line 534 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 2900 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: SIGNED  */
#line 535 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 2906 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: UNSIGNED  */
#line 536 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 2912 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: BOOL  */
#line 537 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 2918 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: COMPLEX  */
#line 538 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 2924 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: IMAGINARY  */
#line 539 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 2930 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: atomic_type_specifier  */
#line 540 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 2936 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: struct_or_union_specifier  */
#line 541 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2942 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: enum_specifier  */
#line 542 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2948 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: TYPEDEF_NAME  */
#line 543 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2954 "C_grammar.tab.c"
    break;

  case 136: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 548 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
	    }
#line 2965 "C_grammar.tab.c"
    break;

  case 137: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 555 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s(%s, [%s])", (yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
	    }
#line 2977 "C_grammar.tab.c"
    break;

  case 138: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 563 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 2988 "C_grammar.tab.c"
    break;

  case 139: /* struct_or_union: STRUCT  */
#line 572 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "struct");}
#line 2994 "C_grammar.tab.c"
    break;

  case 140: /* struct_or_union: UNION  */
#line 573 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "union");}
#line 3000 "C_grammar.tab.c"
    break;

  case 141: /* struct_declaration_list: struct_declaration  */
#line 578 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3006 "C_grammar.tab.c"
    break;

  case 142: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 580 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3017 "C_grammar.tab.c"
    break;

  case 143: /* struct_declaration: specifier_qualifier_list ';'  */
#line 590 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3027 "C_grammar.tab.c"
    break;

  case 144: /* $@1: %empty  */
#line 595 "C_grammar.y"
                                   {in_member_decl_flag = 1;}
#line 3033 "C_grammar.tab.c"
    break;

  case 145: /* struct_declaration: specifier_qualifier_list $@1 struct_declarator_list ';'  */
#line 596 "C_grammar.y"
                {in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_decl([%s], %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3045 "C_grammar.tab.c"
    break;

  case 146: /* struct_declaration: static_assert_declaration  */
#line 604 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3051 "C_grammar.tab.c"
    break;

  case 147: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 609 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3062 "C_grammar.tab.c"
    break;

  case 148: /* specifier_qualifier_list: type_specifier  */
#line 616 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3068 "C_grammar.tab.c"
    break;

  case 149: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 618 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3079 "C_grammar.tab.c"
    break;

  case 150: /* specifier_qualifier_list: type_qualifier  */
#line 625 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3085 "C_grammar.tab.c"
    break;

  case 151: /* struct_declarator_list: struct_declarator  */
#line 630 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3091 "C_grammar.tab.c"
    break;

  case 152: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 632 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3102 "C_grammar.tab.c"
    break;

  case 153: /* struct_declarator: ':' constant_expression  */
#line 642 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3112 "C_grammar.tab.c"
    break;

  case 154: /* struct_declarator: declarator ':' constant_expression  */
#line 648 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3123 "C_grammar.tab.c"
    break;

  case 155: /* struct_declarator: declarator  */
#line 655 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3129 "C_grammar.tab.c"
    break;

  case 156: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 660 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3139 "C_grammar.tab.c"
    break;

  case 157: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 666 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3149 "C_grammar.tab.c"
    break;

  case 158: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 672 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "enum(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3160 "C_grammar.tab.c"
    break;

  case 159: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 679 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "trailing_comma_enum(%s, [%s])", (yyvsp[-4].id), (yyvsp[-2].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
        }
#line 3171 "C_grammar.tab.c"
    break;

  case 160: /* enum_specifier: ENUM IDENTIFIER  */
#line 686 "C_grammar.y"
                {size_t const size = strlen("forward_enum()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "forward_enum(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
        }
#line 3181 "C_grammar.tab.c"
    break;

  case 161: /* enumerator_list: enumerator  */
#line 695 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3187 "C_grammar.tab.c"
    break;

  case 162: /* enumerator_list: enumerator_list ',' enumerator  */
#line 697 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3198 "C_grammar.tab.c"
    break;

  case 163: /* enumerator: enumeration_constant '=' constant_expression  */
#line 707 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3209 "C_grammar.tab.c"
    break;

  case 164: /* enumerator: enumeration_constant  */
#line 714 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3215 "C_grammar.tab.c"
    break;

  case 166: /* type_qualifier: CONST  */
#line 722 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3221 "C_grammar.tab.c"
    break;

  case 167: /* type_qualifier: RESTRICT  */
#line 723 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3227 "C_grammar.tab.c"
    break;

  case 168: /* type_qualifier: VOLATILE  */
#line 724 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3233 "C_grammar.tab.c"
    break;

  case 169: /* type_qualifier: ATOMIC  */
#line 725 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3239 "C_grammar.tab.c"
    break;

  case 170: /* function_specifier: INLINE  */
#line 729 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3245 "C_grammar.tab.c"
    break;

  case 171: /* function_specifier: NORETURN  */
#line 730 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3251 "C_grammar.tab.c"
    break;

  case 174: /* declarator: pointer direct_declarator  */
#line 740 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 3262 "C_grammar.tab.c"
    break;

  case 175: /* declarator: direct_declarator  */
#line 747 "C_grammar.y"
          {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3268 "C_grammar.tab.c"
    break;

  case 176: /* direct_declarator: IDENTIFIER  */
#line 751 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3274 "C_grammar.tab.c"
    break;

  case 177: /* direct_declarator: '(' declarator ')'  */
#line 752 "C_grammar.y"
                                                {simple_str_lit_copy(&(yyval.id), "D1");}
#line 3280 "C_grammar.tab.c"
    break;

  case 178: /* direct_declarator: direct_declarator '[' ']'  */
#line 753 "C_grammar.y"
                                                {simple_str_lit_copy(&(yyval.id), "D2"); }
#line 3286 "C_grammar.tab.c"
    break;

  case 179: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 754 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "D3"); }
#line 3292 "C_grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 755 "C_grammar.y"
                                                                                     {simple_str_lit_copy(&(yyval.id), "D4"); }
#line 3298 "C_grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 756 "C_grammar.y"
                                                                {simple_str_lit_copy(&(yyval.id), "D5"); }
#line 3304 "C_grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 757 "C_grammar.y"
                                                           {simple_str_lit_copy(&(yyval.id), "D6"); }
#line 3310 "C_grammar.tab.c"
    break;

  case 183: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 758 "C_grammar.y"
                                                                                    {simple_str_lit_copy(&(yyval.id), "D7"); }
#line 3316 "C_grammar.tab.c"
    break;

  case 184: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 759 "C_grammar.y"
                                                                             {simple_str_lit_copy(&(yyval.id), "D8"); }
#line 3322 "C_grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 760 "C_grammar.y"
                                                       {simple_str_lit_copy(&(yyval.id), "D9"); }
#line 3328 "C_grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 761 "C_grammar.y"
                                                         {simple_str_lit_copy(&(yyval.id), "D10"); }
#line 3334 "C_grammar.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 762 "C_grammar.y"
                                                       {simple_str_lit_copy(&(yyval.id), "D11"); }
#line 3340 "C_grammar.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '(' ')'  */
#line 763 "C_grammar.y"
                                   {simple_str_lit_copy(&(yyval.id), "D12"); }
#line 3346 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 764 "C_grammar.y"
                                                   {simple_str_lit_copy(&(yyval.id), "D13"); }
#line 3352 "C_grammar.tab.c"
    break;

  case 190: /* pointer: '*' type_qualifier_list pointer  */
#line 769 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3363 "C_grammar.tab.c"
    break;

  case 191: /* pointer: '*' type_qualifier_list  */
#line 776 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3373 "C_grammar.tab.c"
    break;

  case 192: /* pointer: '*' pointer  */
#line 782 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3383 "C_grammar.tab.c"
    break;

  case 193: /* pointer: '*'  */
#line 788 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3389 "C_grammar.tab.c"
    break;

  case 194: /* type_qualifier_list: type_qualifier  */
#line 792 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3395 "C_grammar.tab.c"
    break;

  case 195: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 794 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3406 "C_grammar.tab.c"
    break;

  case 205: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 824 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3412 "C_grammar.tab.c"
    break;

  case 206: /* type_name: specifier_qualifier_list  */
#line 825 "C_grammar.y"
                                                                                {simple_str_lit_copy(&(yyval.id), "typenamedummy2");}
#line 3418 "C_grammar.tab.c"
    break;

  case 231: /* initializer: '{' initializer_list '}'  */
#line 860 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3428 "C_grammar.tab.c"
    break;

  case 232: /* initializer: '{' initializer_list ',' '}'  */
#line 866 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "trailing_comma_initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3438 "C_grammar.tab.c"
    break;

  case 233: /* initializer: assignment_expression  */
#line 872 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3444 "C_grammar.tab.c"
    break;

  case 234: /* initializer_list: designation initializer  */
#line 877 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3455 "C_grammar.tab.c"
    break;

  case 235: /* initializer_list: initializer  */
#line 884 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3461 "C_grammar.tab.c"
    break;

  case 236: /* initializer_list: initializer_list ',' designation initializer  */
#line 886 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3473 "C_grammar.tab.c"
    break;

  case 237: /* initializer_list: initializer_list ',' initializer  */
#line 894 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3484 "C_grammar.tab.c"
    break;

  case 238: /* designation: designator_list '='  */
#line 904 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "[%s]", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3494 "C_grammar.tab.c"
    break;

  case 239: /* designator_list: designator  */
#line 913 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3500 "C_grammar.tab.c"
    break;

  case 240: /* designator_list: designator_list designator  */
#line 915 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3511 "C_grammar.tab.c"
    break;

  case 241: /* designator: '[' constant_expression ']'  */
#line 925 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 3517 "C_grammar.tab.c"
    break;

  case 242: /* designator: '.' IDENTIFIER  */
#line 927 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3527 "C_grammar.tab.c"
    break;

  case 243: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 936 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 3538 "C_grammar.tab.c"
    break;

  case 250: /* $@2: %empty  */
#line 955 "C_grammar.y"
                {fprintf(pl_file, "label_stmt($1, "); free((yyvsp[-1].id));}
#line 3544 "C_grammar.tab.c"
    break;

  case 251: /* labeled_statement: IDENTIFIER ':' $@2 statement  */
#line 955 "C_grammar.y"
                                                                           {fprintf(pl_file, ")");}
#line 3550 "C_grammar.tab.c"
    break;

  case 252: /* $@3: %empty  */
#line 956 "C_grammar.y"
                                       {fprintf(pl_file, "case_stmt($2, "); free((yyvsp[-1].id));}
#line 3556 "C_grammar.tab.c"
    break;

  case 253: /* labeled_statement: CASE constant_expression ':' $@3 statement  */
#line 956 "C_grammar.y"
                                                                                                 {fprintf(pl_file, ")");}
#line 3562 "C_grammar.tab.c"
    break;

  case 254: /* $@4: %empty  */
#line 957 "C_grammar.y"
                      {fprintf(pl_file, "default_stmt(");}
#line 3568 "C_grammar.tab.c"
    break;

  case 255: /* labeled_statement: DEFAULT ':' $@4 statement  */
#line 957 "C_grammar.y"
                                                                     {fprintf(pl_file, ")");}
#line 3574 "C_grammar.tab.c"
    break;

  case 256: /* compound_statement: '{' '}'  */
#line 961 "C_grammar.y"
                  {fprintf(pl_file, "cmp_stmts([])");}
#line 3580 "C_grammar.tab.c"
    break;

  case 257: /* $@5: %empty  */
#line 962 "C_grammar.y"
              {fprintf(pl_file, "cmp_stmts([");}
#line 3586 "C_grammar.tab.c"
    break;

  case 258: /* compound_statement: '{' $@5 block_item_list '}'  */
#line 962 "C_grammar.y"
                                                                     {fprintf(pl_file, "])");}
#line 3592 "C_grammar.tab.c"
    break;

  case 260: /* $@6: %empty  */
#line 967 "C_grammar.y"
                          {fprintf(pl_file, ", ");}
#line 3598 "C_grammar.tab.c"
    break;

  case 264: /* expression_statement: ';'  */
#line 976 "C_grammar.y"
                                        {fprintf(pl_file, "exp_stmt()");}
#line 3604 "C_grammar.tab.c"
    break;

  case 265: /* expression_statement: expression ';'  */
#line 977 "C_grammar.y"
                                {fprintf(pl_file, "exp_stmt(%s)", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3610 "C_grammar.tab.c"
    break;

  case 266: /* $@7: %empty  */
#line 981 "C_grammar.y"
                                {fprintf(pl_file, "if_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3616 "C_grammar.tab.c"
    break;

  case 267: /* selection_statement: IF '(' expression ')' $@7 statement else_opt  */
#line 981 "C_grammar.y"
                                                                                                     {fprintf(pl_file, ")");}
#line 3622 "C_grammar.tab.c"
    break;

  case 268: /* $@8: %empty  */
#line 982 "C_grammar.y"
                                    {fprintf(pl_file, "switch_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3628 "C_grammar.tab.c"
    break;

  case 269: /* selection_statement: SWITCH '(' expression ')' $@8 statement  */
#line 982 "C_grammar.y"
                                                                                                        {fprintf(pl_file, ")");}
#line 3634 "C_grammar.tab.c"
    break;

  case 271: /* $@9: %empty  */
#line 987 "C_grammar.y"
               {fprintf(pl_file, ", ");}
#line 3640 "C_grammar.tab.c"
    break;

  case 273: /* $@10: %empty  */
#line 990 "C_grammar.y"
                                   {fprintf(pl_file, "while_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3646 "C_grammar.tab.c"
    break;

  case 274: /* iteration_statement: WHILE '(' expression ')' $@10 statement  */
#line 990 "C_grammar.y"
                                                                                                  {fprintf(pl_file, ")");}
#line 3652 "C_grammar.tab.c"
    break;

  case 275: /* $@11: %empty  */
#line 991 "C_grammar.y"
             {fprintf(pl_file, "do_while_stmt(");}
#line 3658 "C_grammar.tab.c"
    break;

  case 276: /* iteration_statement: DO $@11 statement WHILE '(' expression ')' ';'  */
#line 991 "C_grammar.y"
                                                                                          {fprintf(pl_file, ", %s)", (yyvsp[-2].id)); free((yyvsp[-2].id));}
#line 3664 "C_grammar.tab.c"
    break;

  case 277: /* $@12: %empty  */
#line 992 "C_grammar.y"
                  {fprintf(pl_file, "for_stmt(");}
#line 3670 "C_grammar.tab.c"
    break;

  case 278: /* $@13: %empty  */
#line 992 "C_grammar.y"
                                                                     {fprintf(pl_file, ", ");}
#line 3676 "C_grammar.tab.c"
    break;

  case 279: /* iteration_statement: FOR '(' $@12 for_stmt_type ')' $@13 statement  */
#line 992 "C_grammar.y"
                                                                                                         {fprintf(pl_file, ")");}
#line 3682 "C_grammar.tab.c"
    break;

  case 280: /* $@14: %empty  */
#line 996 "C_grammar.y"
                               {fprintf(pl_file, ", ");}
#line 3688 "C_grammar.tab.c"
    break;

  case 282: /* $@15: %empty  */
#line 997 "C_grammar.y"
                      {fprintf(pl_file, ", ");}
#line 3694 "C_grammar.tab.c"
    break;

  case 285: /* expression_opt: expression  */
#line 1002 "C_grammar.y"
                     {fprintf(pl_file, ", %s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 3700 "C_grammar.tab.c"
    break;

  case 286: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1005 "C_grammar.y"
                                {fprintf(pl_file, "goto_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3706 "C_grammar.tab.c"
    break;

  case 287: /* jump_statement: CONTINUE ';'  */
#line 1006 "C_grammar.y"
                                        {fprintf(pl_file, "continue_stmt\n");}
#line 3712 "C_grammar.tab.c"
    break;

  case 288: /* jump_statement: BREAK ';'  */
#line 1007 "C_grammar.y"
                                                {fprintf(pl_file, "break_stmt\n");}
#line 3718 "C_grammar.tab.c"
    break;

  case 289: /* jump_statement: RETURN ';'  */
#line 1008 "C_grammar.y"
                                        {fprintf(pl_file, "return_stmt\n");}
#line 3724 "C_grammar.tab.c"
    break;

  case 290: /* jump_statement: RETURN expression ';'  */
#line 1009 "C_grammar.y"
                                {fprintf(pl_file, "return_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3730 "C_grammar.tab.c"
    break;

  case 292: /* $@16: %empty  */
#line 1014 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 3736 "C_grammar.tab.c"
    break;

  case 296: /* $@17: %empty  */
#line 1023 "C_grammar.y"
                                            {fprintf(pl_file, "function(%s, %s, [", (yyvsp[-1].id), (yyvsp[0].id)); free((yyvsp[-1].id)); free((yyvsp[0].id));}
#line 3742 "C_grammar.tab.c"
    break;

  case 297: /* $@18: %empty  */
#line 1023 "C_grammar.y"
                                                                                                                                       {fprintf(pl_file, "], ");}
#line 3748 "C_grammar.tab.c"
    break;

  case 298: /* function_definition: declaration_specifiers declarator $@17 declaration_list_opt $@18 compound_statement  */
#line 1023 "C_grammar.y"
                                                                                                                                                                                     {fprintf(pl_file, ")");}
#line 3754 "C_grammar.tab.c"
    break;

  case 302: /* $@19: %empty  */
#line 1033 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 3760 "C_grammar.tab.c"
    break;


#line 3764 "C_grammar.tab.c"

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

#line 1036 "C_grammar.y"

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

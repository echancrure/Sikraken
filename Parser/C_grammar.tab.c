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
#line 1 "C_grammar.y"

	// https://www.quut.com/c/ANSI-C-grammar-y.html
	extern void yyerror(const char*);
	extern int yychar;

	#include "string.h"
	#include "definitions.h"
	#include "string_functions.h"
	#include "linkedlists.h"
	#include "parameters.h"
	#include "scopes.h"
	#include "ascii_functions.h"
	#include "switch_functions.h"
	#include "typedef_functions.h"
	#include "enum_functions.h"
	#include "output_functions.h"
	#include "array_functions.h"
	#include "decl_functions.h"
	#include "if_functions.h"
	#include "iteration_functions.h"
	#include "structures.h"
	#include "conversion_functions.h"

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
  YYSYMBOL_I_CONSTANT = 4,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 7,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 18,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 19,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 22,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 23,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 24,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 25,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 26,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 27,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 28,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 29,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF_NAME = 30,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUMERATION_CONSTANT = 31,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_ALIGN = 32,                     /* ALIGN  */
  YYSYMBOL_TYPEDEF = 33,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 34,                    /* EXTERN  */
  YYSYMBOL_STATIC = 35,                    /* STATIC  */
  YYSYMBOL_AUTO = 36,                      /* AUTO  */
  YYSYMBOL_REGISTER = 37,                  /* REGISTER  */
  YYSYMBOL_INLINE = 38,                    /* INLINE  */
  YYSYMBOL_FORCEINLINE = 39,               /* FORCEINLINE  */
  YYSYMBOL_CONST = 40,                     /* CONST  */
  YYSYMBOL_RESTRICT = 41,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 42,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 43,                      /* BOOL  */
  YYSYMBOL_CHAR = 44,                      /* CHAR  */
  YYSYMBOL_SHORT = 45,                     /* SHORT  */
  YYSYMBOL_INT = 46,                       /* INT  */
  YYSYMBOL_LONG = 47,                      /* LONG  */
  YYSYMBOL_SIGNED = 48,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 49,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 50,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 51,                    /* DOUBLE  */
  YYSYMBOL_VOID = 52,                      /* VOID  */
  YYSYMBOL_WCHAR_T = 53,                   /* WCHAR_T  */
  YYSYMBOL___INT8 = 54,                    /* __INT8  */
  YYSYMBOL___INT16 = 55,                   /* __INT16  */
  YYSYMBOL___INT32 = 56,                   /* __INT32  */
  YYSYMBOL___INT64 = 57,                   /* __INT64  */
  YYSYMBOL___PTR32 = 58,                   /* __PTR32  */
  YYSYMBOL___PTR64 = 59,                   /* __PTR64  */
  YYSYMBOL___UNALIGNED = 60,               /* __UNALIGNED  */
  YYSYMBOL_COMPLEX = 61,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 62,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 63,                    /* STRUCT  */
  YYSYMBOL_UNION = 64,                     /* UNION  */
  YYSYMBOL_ENUM = 65,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 66,                  /* ELLIPSIS  */
  YYSYMBOL_DECLSPEC = 67,                  /* DECLSPEC  */
  YYSYMBOL_CASE = 68,                      /* CASE  */
  YYSYMBOL_DEFAULT = 69,                   /* DEFAULT  */
  YYSYMBOL_IF = 70,                        /* IF  */
  YYSYMBOL_ELSE = 71,                      /* ELSE  */
  YYSYMBOL_SWITCH = 72,                    /* SWITCH  */
  YYSYMBOL_WHILE = 73,                     /* WHILE  */
  YYSYMBOL_DO = 74,                        /* DO  */
  YYSYMBOL_FOR = 75,                       /* FOR  */
  YYSYMBOL_GOTO = 76,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 77,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 78,                     /* BREAK  */
  YYSYMBOL_RETURN = 79,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 80,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 81,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 82,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 83,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 84,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 85,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 86,              /* THREAD_LOCAL  */
  YYSYMBOL___CDECL = 87,                   /* __CDECL  */
  YYSYMBOL___CLRCALL = 88,                 /* __CLRCALL  */
  YYSYMBOL___STDCALL = 89,                 /* __STDCALL  */
  YYSYMBOL___FASTCALL = 90,                /* __FASTCALL  */
  YYSYMBOL___THISCALL = 91,                /* __THISCALL  */
  YYSYMBOL___VECTORCALL = 92,              /* __VECTORCALL  */
  YYSYMBOL_93_ = 93,                       /* '('  */
  YYSYMBOL_94_ = 94,                       /* ')'  */
  YYSYMBOL_95_ = 95,                       /* ','  */
  YYSYMBOL_96_ = 96,                       /* ':'  */
  YYSYMBOL_97_ = 97,                       /* '['  */
  YYSYMBOL_98_ = 98,                       /* ']'  */
  YYSYMBOL_99_ = 99,                       /* '.'  */
  YYSYMBOL_100_ = 100,                     /* '{'  */
  YYSYMBOL_101_ = 101,                     /* '}'  */
  YYSYMBOL_102_ = 102,                     /* '&'  */
  YYSYMBOL_103_ = 103,                     /* '*'  */
  YYSYMBOL_104_ = 104,                     /* '+'  */
  YYSYMBOL_105_ = 105,                     /* '-'  */
  YYSYMBOL_106_ = 106,                     /* '~'  */
  YYSYMBOL_107_ = 107,                     /* '!'  */
  YYSYMBOL_108_ = 108,                     /* '/'  */
  YYSYMBOL_109_ = 109,                     /* '%'  */
  YYSYMBOL_110_ = 110,                     /* '<'  */
  YYSYMBOL_111_ = 111,                     /* '>'  */
  YYSYMBOL_112_ = 112,                     /* '^'  */
  YYSYMBOL_113_ = 113,                     /* '|'  */
  YYSYMBOL_114_ = 114,                     /* '?'  */
  YYSYMBOL_115_ = 115,                     /* '='  */
  YYSYMBOL_116_ = 116,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 117,                 /* $accept  */
  YYSYMBOL_primary_expression = 118,       /* primary_expression  */
  YYSYMBOL_constant = 119,                 /* constant  */
  YYSYMBOL_enumeration_constant = 120,     /* enumeration_constant  */
  YYSYMBOL_string = 121,                   /* string  */
  YYSYMBOL_generic_selection = 122,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 123,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 124,      /* generic_association  */
  YYSYMBOL_postfix_expression = 125,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 126, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 127,         /* unary_expression  */
  YYSYMBOL_unary_operator = 128,           /* unary_operator  */
  YYSYMBOL_cast_expression = 129,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 130, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 131,      /* additive_expression  */
  YYSYMBOL_shift_expression = 132,         /* shift_expression  */
  YYSYMBOL_relational_expression = 133,    /* relational_expression  */
  YYSYMBOL_equality_expression = 134,      /* equality_expression  */
  YYSYMBOL_and_expression = 135,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 136,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 137,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 138,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 139,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 140,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 141,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 142,      /* assignment_operator  */
  YYSYMBOL_expression = 143,               /* expression  */
  YYSYMBOL_constant_expression = 144,      /* constant_expression  */
  YYSYMBOL_declaration = 145,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 146,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 147,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 148,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 149,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 150,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 151, /* struct_or_union_specifier  */
  YYSYMBOL_DECLSPEC_specifiers = 152,      /* DECLSPEC_specifiers  */
  YYSYMBOL_extended_decl_modifier_seq = 153, /* extended_decl_modifier_seq  */
  YYSYMBOL_struct_or_union = 154,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 155,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 156,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 157, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 158,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 159,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 160,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 161,          /* enumerator_list  */
  YYSYMBOL_enumerator = 162,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 163,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 164,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 165,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 166,      /* alignment_specifier  */
  YYSYMBOL_declarator = 167,               /* declarator  */
  YYSYMBOL_microsoft_native_pointer_extension = 168, /* microsoft_native_pointer_extension  */
  YYSYMBOL_direct_declarator = 169,        /* direct_declarator  */
  YYSYMBOL_vc_specific_modifier = 170,     /* vc_specific_modifier  */
  YYSYMBOL_pointer = 171,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 172,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 173,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 174,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 175,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 176,          /* identifier_list  */
  YYSYMBOL_type_name = 177,                /* type_name  */
  YYSYMBOL_abstract_declarator = 178,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 179, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 180,              /* initializer  */
  YYSYMBOL_initializer_list = 181,         /* initializer_list  */
  YYSYMBOL_designation = 182,              /* designation  */
  YYSYMBOL_designator_list = 183,          /* designator_list  */
  YYSYMBOL_designator = 184,               /* designator  */
  YYSYMBOL_static_assert_declaration = 185, /* static_assert_declaration  */
  YYSYMBOL_statement = 186,                /* statement  */
  YYSYMBOL_labeled_statement = 187,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 188,       /* compound_statement  */
  YYSYMBOL_block_item_list = 189,          /* block_item_list  */
  YYSYMBOL_block_item = 190,               /* block_item  */
  YYSYMBOL_expression_statement = 191,     /* expression_statement  */
  YYSYMBOL_selection_statement = 192,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 193,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 194,           /* jump_statement  */
  YYSYMBOL_translation_unit = 195,         /* translation_unit  */
  YYSYMBOL_external_declaration = 196,     /* external_declaration  */
  YYSYMBOL_function_definition = 197,      /* function_definition  */
  YYSYMBOL_declaration_list = 198          /* declaration_list  */
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
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2970

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  308
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  545

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   347


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
       2,     2,     2,   107,     2,     2,     2,   109,   102,     2,
      93,    94,   103,   104,    95,   105,    99,   108,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    96,   116,
     110,   115,   111,   114,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    97,     2,    98,   112,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,   113,   101,   106,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   142,   149,   155,   163,   167,   173,   179,
     190,   199,   205,   214,   218,   219,   223,   224,   228,   234,
     255,   276,   299,   307,   320,   347,   358,   359,   363,   369,
     381,   387,   398,   408,   419,   436,   448,   460,   466,   471,
     477,   482,   487,   495,   511,   528,   534,   546,   555,   571,
     577,   586,   598,   604,   613,   625,   631,   640,   649,   658,
     671,   677,   686,   698,   704,   716,   722,   734,   740,   752,
     758,   772,   778,   792,   798,   821,   827,   842,   847,   852,
     857,   862,   867,   872,   877,   882,   887,   892,   900,   906,
     918,   927,   939,   964,   968,   976,   982,  1002,  1022,  1028,
    1034,  1042,  1048,  1054,  1059,  1065,  1074,  1080,  1092,  1100,
    1123,  1129,  1134,  1139,  1140,  1145,  1153,  1158,  1163,  1168,
    1173,  1178,  1183,  1188,  1193,  1198,  1203,  1208,  1213,  1214,
    1220,  1226,  1234,  1239,  1244,  1249,  1254,  1262,  1273,  1298,
    1324,  1345,  1350,  1359,  1363,  1367,  1371,  1375,  1384,  1389,
    1397,  1403,  1415,  1416,  1440,  1444,  1452,  1458,  1466,  1475,
    1482,  1495,  1502,  1511,  1520,  1533,  1534,  1561,  1562,  1575,
    1581,  1594,  1615,  1635,  1639,  1644,  1649,  1654,  1662,  1663,
    1664,  1665,  1672,  1673,  1677,  1685,  1694,  1703,  1708,  1716,
    1722,  1737,  1745,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1767,  1774,  1803,  1811,  1821,  1831,  1848,  1853,  1858,  1863,
    1868,  1873,  1881,  1890,  1897,  1904,  1912,  1918,  1929,  1937,
    1949,  1956,  1968,  1985,  1993,  2001,  2010,  2016,  2028,  2036,
    2045,  2051,  2060,  2068,  2077,  2083,  2092,  2100,  2106,  2113,
    2114,  2115,  2116,  2117,  2118,  2119,  2127,  2136,  2137,  2138,
    2139,  2140,  2141,  2142,  2148,  2156,  2164,  2177,  2187,  2198,
    2207,  2216,  2222,  2223,  2236,  2246,  2252,  2263,  2271,  2282,
    2286,  2292,  2298,  2304,  2310,  2316,  2325,  2334,  2343,  2354,
    2361,  2378,  2384,  2400,  2407,  2416,  2421,  2432,  2442,  2451,
    2463,  2472,  2481,  2491,  2502,  2503,  2507,  2515,  2520,  2525,
    2530,  2541,  2547,  2558,  2566,  2581,  2593,  2607,  2613
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
  "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME",
  "ENUMERATION_CONSTANT", "ALIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "FORCEINLINE", "CONST", "RESTRICT", "VOLATILE",
  "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
  "DOUBLE", "VOID", "WCHAR_T", "__INT8", "__INT16", "__INT32", "__INT64",
  "__PTR32", "__PTR64", "__UNALIGNED", "COMPLEX", "IMAGINARY", "STRUCT",
  "UNION", "ENUM", "ELLIPSIS", "DECLSPEC", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT",
  "THREAD_LOCAL", "__CDECL", "__CLRCALL", "__STDCALL", "__FASTCALL",
  "__THISCALL", "__VECTORCALL", "'('", "')'", "','", "':'", "'['", "']'",
  "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "primary_expression", "constant", "enumeration_constant", "string",
  "generic_selection", "generic_assoc_list", "generic_association",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "DECLSPEC_specifiers",
  "extended_decl_modifier_seq", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator",
  "microsoft_native_pointer_extension", "direct_declarator",
  "vc_specific_modifier", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-429)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2628,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,
    -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,
    -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,
    -429,    36,   -66,   -50,   -15,  -429,    -5,  -429,  -429,   795,
    2795,  2685,  -429,  -429,    30,  -429,  -429,  2795,  2795,  2795,
    -429,  1931,  -429,  -429,   -36,    92,   160,   929,  2119,   995,
    -429,     8,  -429,  -429,  -429,  -429,  -429,  -429,  1229,    10,
    -429,   -72,  -429,  1988,   -48,   131,  1867,  -429,  2795,  -429,
      37,  2842,   136,  -429,  -429,  -429,  -429,  -429,    92,  -429,
      62,   -39,  -429,    87,   105,  -429,   117,  -429,  -429,  -429,
    -429,  -429,  -429,  1120,  1245,  1245,  -429,   120,   126,   929,
    -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,
      61,  -429,   995,  -429,   106,   -70,   156,    46,   189,   128,
     116,   119,   223,     2,  -429,   172,  2888,   -61,  2888,   195,
    -429,   202,  -429,   203,   995,   210,  1741,  -429,  -429,    10,
    1229,  -429,   531,  1537,  -429,   795,  -429,  2498,  1812,  1010,
    -429,  -429,  -429,   875,   -48,  -429,  2842,  2305,  -429,   410,
    -429,   234,   -27,   995,    17,  -429,   179,   232,   217,   929,
    -429,   929,  -429,  -429,  2119,   995,   318,  -429,  -429,   180,
     229,   329,  -429,  -429,  1552,   995,   332,  -429,   995,   995,
     995,   995,   995,   995,   995,   995,   995,   995,   995,   995,
     995,   995,   995,   995,   995,   995,   995,  -429,  -429,  2169,
    1054,    68,   218,    94,  -429,  -429,  -429,   343,   252,  -429,
    -429,   257,  -429,  -429,  -429,   238,   259,   995,   266,   270,
     272,   274,   764,   275,   367,   255,   258,   813,  -429,  -429,
     -69,  -429,  -429,  -429,  -429,   615,  -429,  -429,  -429,  -429,
    -429,  1432,  -429,  -429,  -429,  -429,  -429,  -429,  1704,   279,
     280,  -429,   184,  1372,  -429,   278,   281,  1135,   -48,  2367,
    -429,  -429,   995,  -429,   -22,  -429,   282,  2842,    19,  -429,
    -429,  -429,  -429,   995,   286,   289,   291,  -429,   292,   294,
     295,   296,  -429,  -429,  -429,  -429,  -429,  -429,  -429,  -429,
    -429,  -429,  -429,   995,  -429,   995,  1567,  -429,  -429,   186,
    -429,   -19,  -429,  -429,  -429,  -429,   106,   106,   -70,   -70,
     156,   156,   156,   156,    46,    46,   189,   128,   116,   119,
     223,   190,  -429,   290,   301,   303,  1372,  -429,   304,   308,
    1179,  2240,    94,  -429,  2566,  1260,   307,  -429,  -429,   764,
     311,   764,   995,   995,   995,   335,   699,   298,  -429,  -429,
    -429,    50,  -429,  -429,  -429,   995,   407,  -429,   -20,  1537,
      75,  -429,  1676,  -429,    38,   431,  -429,  -429,  2740,  -429,
     408,   314,  1372,  -429,  -429,   995,  -429,   317,   319,  -429,
    -429,  1104,  -429,   995,  2429,  -429,  -429,  -429,  -429,   316,
     316,  -429,  2064,  -429,  -429,  1432,  -429,  -429,   995,  -429,
     995,   324,  -429,  -429,   321,  1372,  -429,  -429,   995,  -429,
     323,  -429,   328,  1372,  -429,   326,   327,  1304,   310,  -429,
     764,  -429,   193,   198,   206,   334,   845,   845,  -429,  -429,
     330,  -429,  1388,  -429,  -429,  -429,  -429,     8,  1741,  -429,
    1676,  -429,  -429,  -429,  -429,   337,   339,  -429,  -429,  -429,
    -429,  -429,   336,   208,  -429,   348,    78,  -429,  -429,    68,
    -429,   347,   349,  -429,  -429,   351,  1372,  -429,  -429,   995,
    -429,   352,  -429,  -429,   764,   764,   764,   995,  1582,  1597,
    -429,  -429,  -429,  1537,  1414,  -429,  -429,   995,  -429,  2064,
     995,  1417,  -429,    94,  -429,  -429,  -429,   353,   354,  -429,
     383,  -429,  -429,   215,   764,   219,   764,   221,  -429,  -429,
    -429,  -429,  -429,  -429,  -429,   764,   340,  -429,   764,  -429,
     764,  -429,  -429,  -429,  -429
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   131,   110,   111,   112,   114,   115,   178,   179,   174,
     175,   176,   125,   117,   118,   119,   120,   123,   124,   121,
     122,   116,   136,   132,   133,   134,   135,   126,   127,   148,
     149,     0,     0,     0,   177,   180,     0,   113,   304,     0,
      95,    98,   129,   181,     0,   130,   128,   101,   103,   105,
      93,     0,   301,   303,   168,     0,     0,     0,     0,     0,
     189,     0,   206,   207,   208,   209,   210,   211,     0,   215,
      91,     0,   106,   109,   186,     0,     0,    94,    99,    96,
     140,     0,     0,   100,   102,   104,     1,   302,     0,    10,
     172,     0,   169,   145,     0,   177,     0,   146,     2,     7,
       8,    11,    12,     0,     0,     0,     9,     0,     0,     0,
      37,    38,    39,    40,    41,    42,    18,     3,     4,     6,
      30,    43,     0,    45,    49,    52,    55,    60,    63,    65,
      67,    69,    71,    73,    90,     0,   156,   230,   158,     0,
     231,     0,     2,     0,     0,     0,     0,   216,   214,   213,
       0,    92,     0,     0,   307,     0,   306,     0,     0,     0,
     204,   187,   188,     0,   184,    97,     0,     0,   150,     0,
     154,     0,     0,     0,     0,   164,     0,     0,   141,     0,
      34,     0,    31,    32,     0,     0,    43,    75,    88,     0,
       0,     0,    24,    25,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   155,     0,
       0,   234,   228,   235,   157,   182,   173,     0,     0,   190,
     189,     0,   217,   212,   107,   109,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   285,
       0,   283,   284,   270,   271,     0,   281,   272,   273,   274,
     275,     0,   259,   108,   308,   305,   226,   202,   225,     0,
     219,   220,     0,     0,   191,    38,     0,     0,   185,     0,
     137,   151,     0,   152,     0,   159,   163,     0,     0,   166,
     171,   165,   170,     0,     0,     0,     0,   142,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    77,     0,     5,     0,     0,    23,    20,     0,
      28,     0,    22,    46,    47,    48,    50,    51,    53,    54,
      58,    59,    56,    57,    61,    62,    64,    66,    68,    70,
      72,     0,   253,     0,     0,     0,     0,   237,    38,     0,
       0,     0,   232,   229,     0,     0,     0,   200,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,   298,
     299,     0,   286,   280,   282,     0,     0,   261,     0,     0,
       0,   265,     0,   222,     0,   234,   223,   201,     0,   203,
       0,     0,     0,   192,   199,     0,   198,    38,     0,   138,
     161,     0,   153,     0,     0,   167,   147,   143,   144,    35,
       0,    36,     0,    76,    89,     0,    44,    21,     0,    19,
       0,     0,   254,   236,     0,     0,   238,   244,     0,   243,
       0,   255,     0,     0,   245,    38,     0,     0,     0,   276,
       0,   278,     0,     0,     0,     0,     0,     0,   296,   300,
       0,   268,     0,   257,   260,   264,   266,   131,     0,   224,
       0,   218,   221,   227,   194,     0,     0,   195,   197,   160,
     162,   139,     0,     0,    14,     0,     0,    29,    74,     0,
     240,     0,     0,   242,   256,     0,     0,   246,   252,     0,
     251,     0,   269,   277,     0,     0,     0,     0,     0,     0,
     267,   258,   263,     0,     0,   193,   196,     0,    13,     0,
       0,     0,    26,   233,   239,   241,   248,     0,     0,   249,
     288,   289,   290,     0,     0,     0,     0,     0,   262,    17,
      15,    16,    27,   247,   250,     0,     0,   294,     0,   292,
       0,   287,   291,   295,   293
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -429,   284,  -429,  -429,  -429,  -429,  -429,   -54,  -429,  -429,
      45,  -429,   -91,   118,   125,   -12,   121,   247,   251,   253,
     250,   260,  -429,   -11,    44,  -429,   -94,   -21,   -33,    18,
    -429,   320,  -429,   -52,  -429,   -32,  -429,  -429,  -149,  -137,
     159,  -429,    66,  -429,   380,  -155,  -429,   -56,  -429,  -429,
     -29,   254,   -73,   -64,   -60,  -122,  -147,  -429,    86,  -429,
      -3,  -121,  -214,  -145,    63,  -428,  -429,    99,   -67,   -53,
    -429,   -45,  -429,   225,  -303,  -429,  -429,  -429,  -429,   432,
    -429,  -429
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   116,   117,    90,   118,   119,   473,   474,   120,   319,
     186,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   187,   188,   313,   250,   135,    38,   268,
      71,    72,    40,    41,    42,    43,    96,    44,   167,   168,
     137,   284,   285,    45,    91,    92,    46,    47,    48,    49,
     145,   163,    74,    75,    76,   149,   344,   270,   271,   272,
     475,   345,   223,   377,   378,   379,   380,   381,    50,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    51,    52,
      53,   157
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   138,   138,   164,   146,   136,   136,   352,   263,   148,
      73,   269,    82,   147,   170,   189,   222,   279,    39,   292,
      89,   215,    89,   150,   503,   138,   315,    56,   156,   136,
     281,   197,   219,    80,   201,   202,   220,   277,   143,    54,
     154,   160,    69,    57,   151,   158,   134,   372,   134,   159,
       9,    10,    11,   138,   139,   141,   174,   136,    77,    79,
     205,   206,   175,   447,    88,    83,    84,    85,   288,    39,
     191,   192,   193,   401,   289,   452,   315,   221,    58,   419,
     138,   453,   138,   503,   136,   189,   136,   189,    59,   233,
     278,   155,    95,   232,   402,    89,   165,    32,   350,   170,
     170,   321,   121,   147,   121,   144,   190,   323,   324,   325,
     138,   138,   265,    69,   136,   136,   216,   231,   291,   251,
     405,   235,   341,   138,   264,   138,   235,   136,   138,   136,
      81,   219,   136,   292,   160,   220,    55,   166,   404,   171,
     286,    69,   281,   498,   499,   315,   297,   386,   180,   182,
     183,   392,   290,   371,   194,   343,   207,   208,   195,   221,
     196,   351,   134,    93,   147,   220,   449,   121,   203,   204,
     155,   352,   375,   511,   376,   155,   298,   173,   299,   512,
     176,   300,   142,    99,   100,   101,   102,   354,   228,   365,
     455,   355,    94,   330,   331,   332,   333,   262,   177,   189,
       9,    10,    11,   276,   384,   209,   210,   432,   385,   198,
     106,   178,   170,   184,   199,   200,   360,   147,   121,   185,
     170,   232,   251,   138,   425,   416,   134,   136,   212,   301,
     211,   138,   213,   437,   454,   136,   295,   296,   320,   383,
     169,   214,    95,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   400,   108,   459,   349,   513,   217,   281,   442,   443,
     444,   134,   293,   155,   314,   315,   161,   162,   389,   390,
     417,   418,   121,   421,    32,   315,   420,   494,   315,   225,
     147,   221,   495,   315,   232,   218,   226,   224,   227,   147,
     496,   315,   508,   509,   229,   262,   439,   502,   441,   536,
     315,   486,   164,   538,   315,   540,   315,   391,   458,   326,
     327,   398,   385,   316,   221,   169,   169,   121,   328,   329,
     334,   335,   317,   446,   287,   322,   232,   170,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   138,   356,
     357,   358,   136,   153,   450,   359,   138,   413,   528,   414,
     136,   121,   361,   362,   134,   363,   502,   364,   366,   232,
     367,   368,   286,   387,   369,   388,   393,   147,   403,   394,
     406,   232,   470,   407,   155,   408,   409,   493,   410,   411,
     424,   412,   134,    69,   430,   422,   146,   423,   504,   436,
     385,   438,   426,   523,   525,   527,   427,   440,   445,   478,
     451,   463,   464,    60,   448,   467,   415,   468,   479,   480,
     121,   483,   484,   262,   487,   488,   492,   497,   500,   231,
     232,   164,   507,   312,    60,   505,   465,   506,   169,   466,
      61,   520,   521,   522,   510,   514,   169,   515,   121,   516,
     519,   533,   534,   138,   535,   530,   542,   136,   336,   262,
     294,    61,   477,   337,   339,   121,   338,   469,   172,   481,
     234,   537,   482,   539,   462,   340,   353,   485,   476,   456,
     374,   491,   541,    87,     0,   543,     0,   544,     0,   161,
     162,     0,     0,     0,     0,     0,   262,    62,    63,    64,
      65,    66,    67,    68,     0,     0,   282,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,    62,    63,
      64,    65,    66,    67,   460,     0,   283,     0,   220,     0,
     517,     0,     0,   518,   236,    99,   100,   101,   102,   103,
       0,   104,   105,     0,     0,     0,     0,   262,     0,     0,
       0,   529,     0,     0,   531,   262,     0,     0,     0,     0,
       0,     1,   106,   169,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,    27,    28,    29,    30,    31,     0,    32,   237,
     238,   239,     0,   240,   241,   242,   243,   244,   245,   246,
     247,    33,   107,    34,   108,    35,    36,    37,   236,    99,
     100,   101,   102,   103,   109,   104,   105,     0,     0,     0,
       0,   152,   248,   110,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     1,   106,   249,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,    27,    28,    29,    30,
      31,     0,    32,   237,   238,   239,     0,   240,   241,   242,
     243,   244,   245,   246,   247,    33,   107,    34,   108,    35,
      36,    37,   142,    99,   100,   101,   102,   103,   109,   104,
     105,     0,     0,     0,     0,   152,   373,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     1,
     106,   249,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
      27,    28,    29,    30,    31,     0,    32,   236,    99,   100,
     101,   102,   103,     0,   104,   105,     0,     0,     0,    33,
     107,    34,   108,    35,    36,    37,     0,     0,     0,     0,
       0,     0,   109,     0,     0,   106,     0,     0,    60,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   142,    99,   100,   101,
     102,   103,     0,   104,   105,    61,     0,     0,     0,     0,
       0,     0,   237,   238,   239,     0,   240,   241,   242,   243,
     244,   245,   246,   247,   106,   107,     0,   108,   142,    99,
     100,   101,   102,   103,     0,   104,   105,   109,     0,     0,
       0,     0,     0,     0,   152,     0,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   106,     0,    60,     0,
     249,     0,    62,    63,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,   107,     0,   108,     0,    69,     0,
       0,     0,     0,     0,     0,    61,   109,     0,     0,     0,
       0,    70,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,   107,     0,   108,   370,
       0,     0,    98,    99,   100,   101,   102,   103,   109,   104,
     105,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     1,
     106,   249,    62,    63,    64,    65,    66,    67,    68,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
      27,    28,    29,    30,    31,     0,     0,     0,   142,    99,
     100,   101,   102,   103,     0,   104,   105,     0,     0,     0,
     107,    34,   108,   142,    99,   100,   101,   102,   103,     0,
     104,   105,   109,     0,     0,     0,   106,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,   106,     0,     0,     0,   273,     0,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,   142,    99,   100,
     101,   102,   103,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,   108,     0,
       0,     0,     0,     0,     0,   106,     0,     0,   109,   346,
       0,   107,    95,   108,     9,    10,    11,   110,   111,   112,
     113,   114,   115,   109,     0,     0,     0,    60,   274,     0,
       0,     0,   110,   275,   112,   113,   114,   115,     0,     0,
       0,     0,     0,   142,    99,   100,   101,   102,   103,     0,
     104,   105,     0,     0,    61,   107,    95,   108,   142,    99,
     100,   101,   102,   103,     0,   104,   105,   109,     0,     0,
       0,   106,   347,     0,     0,     0,   110,   348,   112,   113,
     114,   115,     0,     0,     0,     0,   106,     0,     0,     0,
     395,     0,     0,     0,     0,     9,    10,    11,     0,     0,
       0,     0,   142,    99,   100,   101,   102,   103,     0,   104,
     105,    62,    63,    64,    65,    66,    67,    68,     0,     0,
     282,   107,     0,   108,     0,     0,     0,    69,     0,     0,
     106,     0,     0,   179,   428,     0,   107,    95,   108,     9,
      10,    11,   110,   111,   112,   113,   114,   115,   109,     0,
       0,     0,    60,   396,     0,     0,     0,   110,   397,   112,
     113,   114,   115,     0,     0,     0,     0,     0,   142,    99,
     100,   101,   102,   103,     0,   104,   105,     0,     0,    61,
     107,    95,   108,   142,    99,   100,   101,   102,   103,     0,
     104,   105,   109,     0,     0,     0,   106,   429,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,   106,     0,     0,     0,   433,     0,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,   142,    99,   100,
     101,   102,   103,     0,   104,   105,    62,    63,    64,    65,
      66,    67,    68,     0,     0,     0,   107,     0,   108,     0,
       0,     0,    69,     0,     0,   106,     0,     0,   181,   489,
       0,   107,    95,   108,     9,    10,    11,   110,   111,   112,
     113,   114,   115,   109,     0,     0,     0,     0,   434,     0,
       0,     0,   110,   435,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   142,    99,   100,   101,   102,
     103,     0,   104,   105,     0,   107,    95,   108,     0,     0,
       0,   142,    99,   100,   101,   102,   103,   109,   104,   105,
       0,     0,   490,   106,     0,     0,   110,   111,   112,   113,
     114,   115,     9,    10,    11,     0,     0,    60,     0,   106,
     142,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,     0,   142,    99,   100,   101,   102,
     103,     0,   104,   105,    61,     0,     0,     0,   106,     0,
       0,     0,     0,   107,    95,   108,     0,     0,     0,     0,
       0,     0,     0,   106,     0,   109,     0,     0,     0,   107,
       0,   108,   161,   162,   110,   111,   112,   113,   114,   115,
       0,   109,     0,     0,     0,   375,     0,   376,   261,   501,
     110,   111,   112,   113,   114,   115,     0,     0,   107,     0,
     108,    62,    63,    64,    65,    66,    67,    68,   479,     0,
     109,     0,     0,   107,   375,   108,   376,   261,   532,   110,
     111,   112,   113,   114,   115,   109,     0,     0,     0,   375,
       0,   376,   261,     0,   110,   111,   112,   113,   114,   115,
     142,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,     0,   142,    99,   100,   101,   102,
     103,     0,   104,   105,     0,     0,     0,     0,   106,     0,
     142,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,   106,     0,   142,    99,   100,   101,   102,
     103,     0,   104,   105,     0,     0,     0,     0,   106,     0,
     142,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,   106,     0,     0,     0,     0,   107,     0,
     108,     0,     0,     0,     0,     0,     0,     0,   106,     0,
     109,     0,     0,   107,     0,   108,     0,   261,     0,   110,
     111,   112,   113,   114,   115,   109,   318,     0,   107,     0,
     108,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     109,     0,     0,   107,     0,   108,     0,   415,     0,   110,
     111,   112,   113,   114,   115,   109,   524,     0,   107,    60,
     108,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     109,   526,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,     0,   457,    60,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    61,     0,     0,    27,    28,    29,
      30,    31,     0,    32,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,    34,     0,
      35,     0,    37,    62,    63,    64,    65,    66,    67,   382,
     342,    61,     0,   220,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,    64,    65,    66,    67,   382,     0,     0,
       0,   220,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     1,     0,    69,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      60,     0,     0,    27,    28,    29,    30,    31,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,    34,     0,    35,    61,    37,     0,
       0,     0,     0,     0,     0,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   162,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,     1,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,    27,    28,    29,    30,    31,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,    34,     0,    35,    36,    37,     1,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    27,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,    33,     0,
      34,     0,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,   153,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   140,     0,     0,    27,    28,    29,    30,    31,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,    34,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
      27,    28,    29,    30,    31,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,    34,     0,    35,     0,    37,    62,    63,    64,    65,
      66,    67,   219,   342,     0,     0,   220,     0,     0,     0,
       1,     0,    69,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,    27,    28,    29,    30,    31,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,    34,     0,    35,     0,    37,     0,     0,     0,
       0,     0,     0,   219,   342,     1,     0,   220,     0,     0,
       0,     0,     0,    69,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,   280,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,   399,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
     471,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    27,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
      34,     0,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,   152,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,    27,    28,    29,
      30,    31,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,    34,     0,
      35,     0,    37,     0,     0,     0,     0,     0,     1,     0,
     431,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    27,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
      34,     0,    35,    36,    37,     1,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    78,    27,    28,    29,    30,
      31,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,    34,     0,    35,
       1,    37,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,    27,    28,    29,    30,    31,   461,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,    34,     0,    35,     1,    37,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,    27,    28,    29,    30,
      31,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,    33,     0,    34,     0,    35,
       0,    37,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,    34,     0,     0,    36,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34
};

static const yytype_int16 yycheck[] =
{
      56,    57,    58,    76,    68,    57,    58,   221,   153,    69,
      39,   158,    44,    69,    81,   109,   137,   166,     0,   174,
       3,    19,     3,    95,   452,    81,    95,    93,    73,    81,
     167,   122,    93,     3,   104,   105,    97,   159,    59,     3,
      73,     3,   103,    93,   116,    93,    57,   116,    59,    97,
      40,    41,    42,   109,    57,    58,    95,   109,    40,    41,
      14,    15,   101,   366,   100,    47,    48,    49,    95,    51,
       9,    10,    11,    95,   101,    95,    95,   137,    93,    98,
     136,   101,   138,   511,   136,   179,   138,   181,    93,   149,
     163,    73,    82,   149,   116,     3,    78,    67,   220,   166,
     167,   195,    57,   159,    59,    97,   109,   198,   199,   200,
     166,   167,   157,   103,   166,   167,   114,   146,   101,   152,
     101,   150,   216,   179,   157,   181,   155,   179,   184,   181,
     100,    93,   184,   288,     3,    97,   100,   100,   287,     3,
     169,   103,   279,   446,   447,    95,   178,   268,   103,   104,
     105,   273,   173,   247,    93,   219,   110,   111,    97,   219,
      99,    93,   173,     3,   220,    97,   116,   122,    12,    13,
     152,   385,    97,    95,    99,   157,   179,   115,   181,   101,
      93,   184,     3,     4,     5,     6,     7,    93,   144,   242,
     115,    97,    32,   205,   206,   207,   208,   153,    93,   293,
      40,    41,    42,   159,   268,    16,    17,   354,   268,   103,
      31,    94,   279,    93,   108,   109,   237,   273,   173,    93,
     287,   277,   255,   279,   346,   316,   237,   279,   112,   185,
     102,   287,   113,   355,   379,   287,     4,     5,   194,   268,
      81,    18,    82,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   282,    83,   384,   220,   479,    94,   404,   362,   363,
     364,   282,    93,   255,    94,    95,    58,    59,    94,    95,
      94,    95,   237,   343,    67,    95,    96,    94,    95,    94,
     346,   351,    94,    95,   350,   136,    94,   138,    95,   355,
      94,    95,    94,    95,    94,   261,   359,   452,   361,    94,
      95,   433,   385,    94,    95,    94,    95,   273,   382,   201,
     202,   277,   382,    94,   384,   166,   167,   282,   203,   204,
     209,   210,     3,   366,   100,     3,   392,   404,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,   404,     6,
      98,    94,   404,   115,   375,    96,   412,   313,   503,   315,
     412,   316,    96,    93,   375,    93,   511,    93,    93,   425,
       3,   116,   401,    94,   116,    95,    98,   433,    96,    98,
      94,   437,   403,    94,   366,    94,    94,   440,    94,    94,
     346,    95,   403,   103,   350,    94,   460,    94,   458,   355,
     460,    94,    98,   497,   498,   499,    98,    96,    73,   420,
       3,     3,    98,     3,   116,    98,   100,    98,    94,    98,
     375,    98,    94,   379,    98,    98,   116,    93,    98,   458,
     486,   504,    96,   115,     3,    98,   392,    98,   279,   395,
      30,   494,   495,   496,    96,    98,   287,    98,   403,    98,
      98,    98,    98,   509,    71,   509,   116,   509,   211,   415,
     176,    30,   418,   212,   214,   420,   213,   401,    88,   425,
     150,   524,   428,   526,   388,   215,   222,   433,   415,   380,
     255,   437,   535,    51,    -1,   538,    -1,   540,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,   452,    87,    88,    89,
      90,    91,    92,    93,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    93,    -1,   116,    -1,    97,    -1,
     486,    -1,    -1,   489,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,   503,    -1,    -1,
      -1,   507,    -1,    -1,   510,   511,    -1,    -1,    -1,    -1,
      -1,    30,    31,   404,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     3,     4,
       5,     6,     7,     8,    93,    10,    11,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,   116,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     3,     4,     5,     6,     7,     8,    93,    10,
      11,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,   116,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    67,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    31,    -1,    -1,     3,    -1,
      -1,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    31,    81,    -1,    83,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    93,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,    31,    -1,     3,    -1,
     116,    -1,    87,    88,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    83,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    93,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,   116,
      -1,    -1,     3,     4,     5,     6,     7,     8,    93,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,   116,    87,    88,    89,    90,    91,    92,    93,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      81,    82,    83,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    93,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    93,    35,
      -1,    81,    82,    83,    40,    41,    42,   102,   103,   104,
     105,   106,   107,    93,    -1,    -1,    -1,     3,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    30,    81,    82,    83,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    93,    -1,    -1,
      -1,    31,    98,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      96,    81,    -1,    83,    -1,    -1,    -1,   103,    -1,    -1,
      31,    -1,    -1,    93,    35,    -1,    81,    82,    83,    40,
      41,    42,   102,   103,   104,   105,   106,   107,    93,    -1,
      -1,    -1,     3,    98,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    30,
      81,    82,    83,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    93,    -1,    -1,    -1,    31,    98,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    87,    88,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    81,    -1,    83,    -1,
      -1,    -1,   103,    -1,    -1,    31,    -1,    -1,    93,    35,
      -1,    81,    82,    83,    40,    41,    42,   102,   103,   104,
     105,   106,   107,    93,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    81,    82,    83,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    93,    10,    11,
      -1,    -1,    98,    31,    -1,    -1,   102,   103,   104,   105,
     106,   107,    40,    41,    42,    -1,    -1,     3,    -1,    31,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    30,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    93,    -1,    -1,    -1,    81,
      -1,    83,    58,    59,   102,   103,   104,   105,   106,   107,
      -1,    93,    -1,    -1,    -1,    97,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,    -1,    81,    -1,
      83,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      93,    -1,    -1,    81,    97,    83,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    93,    -1,    -1,    -1,    97,
      -1,    99,   100,    -1,   102,   103,   104,   105,   106,   107,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    31,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    31,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    31,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    81,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      93,    -1,    -1,    81,    -1,    83,    -1,   100,    -1,   102,
     103,   104,   105,   106,   107,    93,    94,    -1,    81,    -1,
      83,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
      93,    -1,    -1,    81,    -1,    83,    -1,   100,    -1,   102,
     103,   104,   105,   106,   107,    93,    94,    -1,    81,     3,
      83,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,    -1,    30,     3,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    30,    -1,    -1,    61,    62,    63,
      64,    65,    -1,    67,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    30,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,   103,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       3,    -1,    -1,    61,    62,    63,    64,    65,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    84,    30,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    84,    85,    86,    30,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    80,    -1,
      82,    -1,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     3,    -1,    -1,    61,    62,    63,    64,    65,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    82,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    97,    -1,    -1,    -1,
      30,    -1,   103,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    30,    -1,    97,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
     101,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,   100,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      94,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    84,    85,    86,    30,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    84,
      30,    86,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    30,    86,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    80,    -1,    82,    -1,    84,
      -1,    86,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    85,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    61,    62,    63,
      64,    65,    67,    80,    82,    84,    85,    86,   145,   146,
     149,   150,   151,   152,   154,   160,   163,   164,   165,   166,
     185,   195,   196,   197,     3,   100,    93,    93,    93,    93,
       3,    30,    87,    88,    89,    90,    91,    92,    93,   103,
     116,   147,   148,   167,   169,   170,   171,   146,    60,   146,
       3,   100,   152,   146,   146,   146,     0,   196,   100,     3,
     120,   161,   162,     3,    32,    82,   153,   164,     3,     4,
       5,     6,     7,     8,    10,    11,    31,    81,    83,    93,
     102,   103,   104,   105,   106,   107,   118,   119,   121,   122,
     125,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   144,   150,   157,   164,   177,
       3,   177,     3,   144,    97,   167,   170,   164,   171,   172,
      95,   116,   100,   115,   145,   146,   188,   198,    93,    97,
       3,    58,    59,   168,   169,   146,   100,   155,   156,   157,
     185,     3,   161,   115,    95,   101,    93,    93,    94,    93,
     127,    93,   127,   127,    93,    93,   127,   140,   141,   143,
     177,     9,    10,    11,    93,    97,    99,   129,   103,   108,
     109,   104,   105,    12,    13,    14,    15,   110,   111,    16,
      17,   102,   112,   113,    18,    19,   114,    94,   157,    93,
      97,   171,   178,   179,   157,    94,    94,    95,   141,    94,
       3,   167,   164,   171,   148,   167,     3,    68,    69,    70,
      72,    73,    74,    75,    76,    77,    78,    79,   101,   116,
     143,   145,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   100,   141,   180,   145,   188,     3,    94,   146,   173,
     174,   175,   176,    35,    98,   103,   141,   172,   169,   155,
     101,   156,    96,   116,   158,   159,   167,   100,    95,   101,
     144,   101,   162,    93,   118,     4,     5,   152,   177,   177,
     177,   141,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   115,   142,    94,    95,    94,     3,    94,   126,
     141,   143,     3,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   132,   133,   133,   134,   135,   136,   137,
     138,   143,    94,   170,   173,   178,    35,    98,   103,   141,
     172,    93,   179,   168,    93,    97,     6,    98,    94,    96,
     144,    96,    93,    93,    93,   186,    93,     3,   116,   116,
     116,   143,   116,   101,   190,    97,    99,   180,   181,   182,
     183,   184,    93,   167,   170,   171,   178,    94,    95,    94,
      95,   141,   172,    98,    98,    35,    98,   103,   141,   101,
     144,    95,   116,    96,   155,   101,    94,    94,    94,    94,
      94,    94,    95,   141,   141,   100,   129,    94,    95,    98,
      96,   171,    94,    94,   141,   172,    98,    98,    35,    98,
     141,    94,   173,    35,    98,   103,   141,   172,    94,   186,
      96,   186,   143,   143,   143,    73,   145,   191,   116,   116,
     144,     3,    95,   101,   180,   115,   184,    30,   170,   178,
      93,    66,   175,     3,    98,   141,   141,    98,    98,   159,
     144,   101,    69,   123,   124,   177,   181,   141,   140,    94,
      98,   141,   141,    98,    94,   141,   172,    98,    98,    35,
      98,   141,   116,   186,    94,    94,    94,    93,   191,   191,
      98,   101,   180,   182,   171,    98,    98,    96,    94,    95,
      96,    95,   101,   179,    98,    98,    98,   141,   141,    98,
     186,   186,   186,   143,    94,   143,    94,   143,   180,   141,
     124,   141,   101,    98,    98,    71,    94,   186,    94,   186,
      94,   186,   116,   186,   186
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   118,   118,   118,   118,   118,   119,   119,   119,
     120,   121,   121,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   130,   130,   131,
     131,   131,   132,   132,   132,   133,   133,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   143,   143,
     144,   145,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   147,   147,   148,   148,
     149,   149,   149,   149,   149,   149,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   151,   151,   151,
     151,   152,   152,   153,   153,   153,   153,   153,   154,   154,
     155,   155,   156,   156,   156,   157,   157,   157,   157,   158,
     158,   159,   159,   159,   160,   160,   160,   160,   160,   161,
     161,   162,   162,   163,   164,   164,   164,   164,   165,   165,
     165,   165,   166,   166,   167,   167,   167,   168,   168,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   175,   175,   176,   176,   177,   177,
     177,   177,   178,   178,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   180,   180,   180,
     181,   181,   181,   181,   182,   183,   183,   184,   184,   185,
     186,   186,   186,   186,   186,   186,   187,   187,   187,   188,
     188,   189,   189,   190,   190,   191,   191,   192,   192,   192,
     193,   193,   193,   193,   193,   193,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   198
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
       1,     2,     3,     1,     2,     1,     2,     3,     1,     2,
       2,     1,     2,     1,     2,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     6,
       2,     4,     5,     4,     4,     1,     1,     4,     1,     1,
       1,     2,     2,     3,     1,     2,     1,     2,     1,     1,
       3,     2,     3,     1,     4,     5,     5,     6,     2,     1,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     3,     1,     1,     1,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       4,     4,     3,     4,     2,     4,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     3,     2,     2,     3,     1,     1,     3,     2,     3,
       1,     1,     2,     5,     1,     1,     3,     2,     3,     5,
       4,     5,     4,     3,     3,     3,     4,     6,     5,     5,
       6,     4,     4,     2,     3,     3,     4,     3,     4,     1,
       2,     1,     4,     3,     2,     1,     2,     3,     2,     7,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       3,     1,     2,     1,     1,     1,     2,     7,     5,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     4,     3,     1,     2
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
#line 135 "C_grammar.y"
        {
		char* identifier = identifier_function((yyvsp[0].id)); // DEFINITIONS.H
        (yyval.id) = (char*) malloc(strlen(identifier) + 1);
        strcpy((yyval.id), identifier);
		free(identifier);
        free((yyvsp[0].id));
	}
#line 2188 "C_grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 143 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), ascii_function((yyvsp[0].id))); // ASCII_FUNCTIONS.H
		strcpy((yyval.id), check_number((yyvsp[0].id)));   // CONVERSION_FUNCTIONS.H
        free((yyvsp[0].id));
	}
#line 2199 "C_grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 150 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2209 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 156 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 2221 "C_grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 168 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2231 "C_grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 174 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2241 "C_grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 180 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2251 "C_grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 191 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2261 "C_grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 200 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);	
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2271 "C_grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 206 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2281 "C_grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 229 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2291 "C_grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 235 "C_grammar.y"
        {
		if (strstr((yyvsp[-3].id), "[") != NULL)
		{
			char* array = process_arrays((yyvsp[-3].id), (yyvsp[-1].id)); // ARRAY_FUNCTIONS.H
			(yyval.id) = (char*) malloc(strlen(array) + 1);
			strcpy((yyval.id), array);
			free(array);
		}
		else
		{
			(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
			strcpy((yyval.id), (yyvsp[-3].id));
            strcat((yyval.id), "[");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), "]");
		}
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));

	}
#line 2316 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 256 "C_grammar.y"
        {
		// Process function calls (without arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		char* func_name = copystring((yyvsp[-2].id), 3, strlen((yyvsp[-2].id)));
        (yyval.id) = (char*) malloc(16 + 3 + strlen(func_name) + 3 + 1 + 1 + 1);
		strcpy((yyval.id), "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat((yyval.id), "UC_");
		else
			strcat((yyval.id), "LC_");

		strcat((yyval.id), func_name);
		strcat((yyval.id), ", [");
		strcat((yyval.id), "]");
		strcat((yyval.id), ")");
        free((yyvsp[-2].id));
		free(func_name);
	}
#line 2341 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 277 "C_grammar.y"
        {
		// Process function calls (with arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		char *func_name = copystring((yyvsp[-3].id), 3, strlen((yyvsp[-3].id))-3);
        (yyval.id) = (char*) malloc(16+ 3 + strlen(func_name) + 3 + strlen((yyvsp[-1].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat((yyval.id), "UC_");
		else
			strcat((yyval.id), "LC_");

		strcat((yyval.id), func_name);
		strcat((yyval.id), ", [");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), "]");
        strcat((yyval.id), ")");
		free(func_name);
        free((yyvsp[-3].id));
        free((yyvsp[-1].id));
	}
#line 2368 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 300 "C_grammar.y"
        {
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + strlen("struct_access(, )")+ 1);
		sprintf((yyval.id), "struct_access(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2380 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 308 "C_grammar.y"
        {
		// Process linked list statements
        (yyval.id) = (char*) malloc(11 + strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1 + 1);
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
        strcpy((yyval.id), "linkedlist(");
		strcat((yyval.id), (yyvsp[-2].id));
        strcat((yyval.id), ", ");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), ")");
        free((yyvsp[-2].id));
        free((yyvsp[0].id));
	}
#line 2397 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 321 "C_grammar.y"
                {
		// Process statements such as i++;
        (yyval.id) = (char*) malloc(25+(2*strlen((yyvsp[-1].id)))+1);
        // 17 + 1 + 3 + 1 + strlen($1)+3 = 25 + strlen($1)
        // 17 + strlen($1) + 3 + strlen($1) + 3 = 23 + 2*strlen($1)

		strcpy((yyval.id), "\npost_increment(");
		if ( (strstr((yyvsp[-1].id), "dereference") != NULL) && ((yyvsp[-1].id)[0] != '(') )
		{
			strcat((yyval.id), "(");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), " , ");
			strcat((yyval.id), "(");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), "+1)");
            free((yyvsp[-1].id));
		}
		else
		{
			strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), " , ");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), "+1)");
            free((yyvsp[-1].id));
		}
	}
#line 2428 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 348 "C_grammar.y"
        {
		// Process statements such as i--;
        (yyval.id) = (char*) malloc(17+strlen((yyvsp[-1].id))+3+strlen((yyvsp[-1].id))+3+1);
		strcpy((yyval.id), "\npost_decrement(");
        strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), " , ");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), "-1)");
        free((yyvsp[-1].id));
	}
#line 2443 "C_grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 364 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2453 "C_grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 370 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[-2].id));
        strcat((yyval.id), ",");
        strcat((yyval.id), (yyvsp[0].id));
        free((yyvsp[-2].id));
        free((yyvsp[0].id));
    }
#line 2466 "C_grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 382 "C_grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2476 "C_grammar.tab.c"
    break;

  case 31: /* unary_expression: INC_OP unary_expression  */
#line 388 "C_grammar.y"
        {
		// Process statements such as ++i;
        (yyval.id) = (char*) malloc(16 + strlen((yyvsp[0].id)) + 3 + strlen((yyvsp[0].id)) + 3 + 1);
		strcpy((yyval.id), "\npre_increment(");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), "+1)");
        free((yyvsp[0].id));
	}
#line 2491 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: DEC_OP unary_expression  */
#line 399 "C_grammar.y"
        {
		// Process statements such as --i;
        (yyval.id) = (char*) malloc(16 + strlen((yyvsp[0].id)) + 3 + strlen((yyvsp[0].id)) + 3 + 1);
		strcpy((yyval.id), "\npre_decrement(");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), "-1)");
	}
#line 2505 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 409 "C_grammar.y"
        {
		// Process casting expressions
		// DECL_FUNCTIONS.H
		char* unary_cast = process_cast_unary_rule((yyvsp[-1].id), (yyvsp[0].id));
        (yyval.id) = (char*) malloc(strlen(unary_cast) + 1);
		strcpy((yyval.id), unary_cast);
		free(unary_cast);
        free((yyvsp[-1].id));
        free((yyvsp[0].id));
	}
#line 2520 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 420 "C_grammar.y"
        {
		// Process sizeof statements
		(yyval.id) = (char*) malloc(6+1+strlen((yyvsp[0].id))+1+1);
		strcpy((yyval.id), "sizeof");
		if ((yyvsp[0].id)[0] != '(')
		{
			strcat((yyval.id), "(");
			strcat((yyval.id), (yyvsp[0].id));
			strcat((yyval.id), ")");
		}
		else
		{
			strcat((yyval.id), (yyvsp[0].id));
		}
		free((yyvsp[0].id));
	}
#line 2541 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 437 "C_grammar.y"
        {
		// Process sizeof(type) statements
		char* type_processed = change_asterisk((yyvsp[-1].id));
		(yyval.id) = (char*) malloc(6 + 1 + strlen(type_processed) + 1 + 1);
		strcpy((yyval.id), "sizeof");
		strcat((yyval.id), "(");
		strcat((yyval.id), type_processed); 	// DECL_FUNCTIONS.H
		strcat((yyval.id), ")");
		free(type_processed);
		free((yyvsp[-1].id));
	}
#line 2557 "C_grammar.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 449 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(8 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "alignof");
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 2570 "C_grammar.tab.c"
    break;

  case 37: /* unary_operator: '&'  */
#line 461 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(10+1);
		strcpy((yyval.id), "address_of");

	}
#line 2580 "C_grammar.tab.c"
    break;

  case 38: /* unary_operator: '*'  */
#line 467 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "dereference");
	}
#line 2589 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '+'  */
#line 472 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "+");

	}
#line 2599 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '-'  */
#line 478 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "-");
	}
#line 2608 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '~'  */
#line 483 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "~");
	}
#line 2617 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '!'  */
#line 488 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "exclamation");
	}
#line 2626 "C_grammar.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 496 "C_grammar.y"
        {
		// Surround negative numbers with ( and )
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1 + 1);
		if ((yyvsp[0].id)[0] == '-')
		{
			strcpy((yyval.id), "(");
			strcat((yyval.id), (yyvsp[0].id));
			strcat((yyval.id), ")");
		}
		else
		{
			strcpy((yyval.id), (yyvsp[0].id));
		}
		free((yyvsp[0].id));
	}
#line 2646 "C_grammar.tab.c"
    break;

  case 44: /* cast_expression: '(' type_name ')' cast_expression  */
#line 512 "C_grammar.y"
        {
		// Process cast expressions
		char* typename = change_asterisk((yyvsp[-2].id)); // DECL_FUNCTIONS.H
		(yyval.id) = (char*) malloc(6 + strlen(typename) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "cast((");
		strcat((yyval.id), typename);
		strcat((yyval.id), "), ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free(typename);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2664 "C_grammar.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 529 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2674 "C_grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 535 "C_grammar.y"
        {
		// Process * - change '*' to multiply to avoid confusion with the pointer dereference '*'
		(yyval.id) = (char*) malloc(9 + strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "multiply(");		//should not have to do this at all
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2690 "C_grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 547 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "/");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2703 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 556 "C_grammar.y"
        {
		// Process % - change '%' to modulo to avoid confusion with
		// the Prolog comments operator '%'
		(yyval.id) = (char*) malloc(4 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "mod(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2720 "C_grammar.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 572 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2730 "C_grammar.tab.c"
    break;

  case 50: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 578 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "+");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2743 "C_grammar.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 587 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "-");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2756 "C_grammar.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 599 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2766 "C_grammar.tab.c"
    break;

  case 53: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 605 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2779 "C_grammar.tab.c"
    break;

  case 54: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 614 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2792 "C_grammar.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 626 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2802 "C_grammar.tab.c"
    break;

  case 56: /* relational_expression: relational_expression '<' shift_expression  */
#line 632 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2815 "C_grammar.tab.c"
    break;

  case 57: /* relational_expression: relational_expression '>' shift_expression  */
#line 641 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2828 "C_grammar.tab.c"
    break;

  case 58: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 650 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2841 "C_grammar.tab.c"
    break;

  case 59: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 659 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2854 "C_grammar.tab.c"
    break;

  case 60: /* equality_expression: relational_expression  */
#line 672 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2864 "C_grammar.tab.c"
    break;

  case 61: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 678 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "==");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2877 "C_grammar.tab.c"
    break;

  case 62: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 687 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2890 "C_grammar.tab.c"
    break;

  case 63: /* and_expression: equality_expression  */
#line 699 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2900 "C_grammar.tab.c"
    break;

  case 64: /* and_expression: and_expression '&' equality_expression  */
#line 705 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "&");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2913 "C_grammar.tab.c"
    break;

  case 65: /* exclusive_or_expression: and_expression  */
#line 717 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2923 "C_grammar.tab.c"
    break;

  case 66: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 723 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "^");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2936 "C_grammar.tab.c"
    break;

  case 67: /* inclusive_or_expression: exclusive_or_expression  */
#line 735 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2946 "C_grammar.tab.c"
    break;

  case 68: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 741 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "|");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2959 "C_grammar.tab.c"
    break;

  case 69: /* logical_and_expression: inclusive_or_expression  */
#line 753 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2969 "C_grammar.tab.c"
    break;

  case 70: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 759 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "andop(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2984 "C_grammar.tab.c"
    break;

  case 71: /* logical_or_expression: logical_and_expression  */
#line 773 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2994 "C_grammar.tab.c"
    break;

  case 72: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 779 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "orop(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3009 "C_grammar.tab.c"
    break;

  case 73: /* conditional_expression: logical_or_expression  */
#line 793 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3019 "C_grammar.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 799 "C_grammar.y"
        {
		// Process ternary expressions from C to Prolog
		(yyval.id) = (char*) malloc(8 + 11 + strlen((yyvsp[-4].id)) + 2 + 1 + strlen((yyvsp[-2].id)) + 1 + 2 + 1 + strlen((yyvsp[0].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "ternary(");
		strcat((yyval.id), "expression(");
		strcat((yyval.id), (yyvsp[-4].id));
		strcat((yyval.id), "),");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "]");
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), "]");
		strcat((yyval.id), ")");
		free((yyvsp[-4].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3043 "C_grammar.tab.c"
    break;

  case 75: /* assignment_expression: conditional_expression  */
#line 822 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3053 "C_grammar.tab.c"
    break;

  case 76: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 828 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id))+ strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3069 "C_grammar.tab.c"
    break;

  case 77: /* assignment_operator: '='  */
#line 843 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(13 + 1);
		strcpy((yyval.id), "\nassignment(");
	}
#line 3078 "C_grammar.tab.c"
    break;

  case 78: /* assignment_operator: MUL_ASSIGN  */
#line 848 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmul_assignment(");
	}
#line 3087 "C_grammar.tab.c"
    break;

  case 79: /* assignment_operator: DIV_ASSIGN  */
#line 853 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\ndiv_assignment(");
	}
#line 3096 "C_grammar.tab.c"
    break;

  case 80: /* assignment_operator: MOD_ASSIGN  */
#line 858 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmod_assignment(");
	}
#line 3105 "C_grammar.tab.c"
    break;

  case 81: /* assignment_operator: ADD_ASSIGN  */
#line 863 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nadd_assignment(");
	}
#line 3114 "C_grammar.tab.c"
    break;

  case 82: /* assignment_operator: SUB_ASSIGN  */
#line 868 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nsub_assignment(");
	}
#line 3123 "C_grammar.tab.c"
    break;

  case 83: /* assignment_operator: LEFT_ASSIGN  */
#line 873 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(18 + 1);
		strcpy((yyval.id), "\nleft_assignment(");
	}
#line 3132 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: RIGHT_ASSIGN  */
#line 878 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(19 + 1);
		strcpy((yyval.id), "\nright_assignment(");
	}
#line 3141 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: AND_ASSIGN  */
#line 883 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nand_assignment(");
	}
#line 3150 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: XOR_ASSIGN  */
#line 888 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nxor_assignment(");
	}
#line 3159 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: OR_ASSIGN  */
#line 893 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(16 + 1);
		strcpy((yyval.id), "\nor_assignment(");
	}
#line 3168 "C_grammar.tab.c"
    break;

  case 88: /* expression: assignment_expression  */
#line 901 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3178 "C_grammar.tab.c"
    break;

  case 89: /* expression: expression ',' assignment_expression  */
#line 907 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "comma(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
	}
#line 3191 "C_grammar.tab.c"
    break;

  case 90: /* constant_expression: conditional_expression  */
#line 919 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3201 "C_grammar.tab.c"
    break;

  case 91: /* declaration: declaration_specifiers ';'  */
#line 928 "C_grammar.y"
        {
		char* declaration = struct_declaration((yyvsp[-1].id));
		(yyval.id) = (char*) malloc(strlen(declaration) + 1);
		strcpy((yyval.id), declaration);	// STRUCTURES.H
		free(declaration);
		free((yyvsp[-1].id));

		typedef_flag = NO;
		struct_flag = NO;

	}
#line 3217 "C_grammar.tab.c"
    break;

  case 92: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 940 "C_grammar.y"
        {
		if(typedef_flag == YES) {
			typedef_flag = NO;
			char* declaration = process_typedef((yyvsp[-2].id), (yyvsp[-1].id));
			(yyval.id) = (char*) malloc(strlen(declaration) + 1);
			strcpy((yyval.id), declaration);	// STRUCTURES.H
			free(declaration);
		}
		else
		{
			int lenSS;
			char* declaration_string = findvariabledetails((yyvsp[-2].id)); // DECL_FUNCTIONS.H
			(yyval.id) = (char*) malloc(strlen(declaration_string) + 1 + 1);
			strcpy((yyval.id), declaration_string);
			free(declaration_string);
			lenSS = strlen((yyval.id)) - 1;

			if ((yyval.id)[lenSS] != ',')
				strcat((yyval.id), ",");
		}
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		struct_flag = NO;
	}
#line 3246 "C_grammar.tab.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 969 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3258 "C_grammar.tab.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier  */
#line 977 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3268 "C_grammar.tab.c"
    break;

  case 96: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 983 "C_grammar.y"
        {
		// Only append comma if not a type such as "unsigned int"
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen((yyvsp[0].id)) + 1);

		strcpy((yyval.id), (yyvsp[-1].id));
		if ( (strcmp((yyvsp[-1].id), "signed") == 0) || (strcmp((yyvsp[-1].id), "unsigned") == 0) )
		{
		}
		else if ((strcmp((yyvsp[-1].id), "short") == 0) && (strcmp((yyvsp[0].id), "int") == 0))
		{
		}
		else
		{
			strcat((yyval.id), ", ");
		}
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3292 "C_grammar.tab.c"
    break;

  case 97: /* declaration_specifiers: type_specifier __UNALIGNED declaration_specifiers  */
#line 1003 "C_grammar.y"
        {
		// Only append comma if not a type such as "unsigned int"
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);

		strcpy((yyval.id), (yyvsp[-2].id));
		if ( (strcmp((yyvsp[-2].id), "signed") == 0) || (strcmp((yyvsp[-2].id), "unsigned") == 0) )
		{
		}
		else if ((strcmp((yyvsp[-2].id), "short") == 0) && (strcmp((yyvsp[0].id), "int") == 0))
		{
		}
		else
		{
			strcat((yyval.id), ", ");
		}
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3316 "C_grammar.tab.c"
    break;

  case 98: /* declaration_specifiers: type_specifier  */
#line 1023 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3326 "C_grammar.tab.c"
    break;

  case 99: /* declaration_specifiers: type_specifier __UNALIGNED  */
#line 1029 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		free((yyvsp[-1].id));
	}
#line 3336 "C_grammar.tab.c"
    break;

  case 100: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 1035 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3348 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: type_qualifier  */
#line 1043 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3358 "C_grammar.tab.c"
    break;

  case 102: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 1049 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3368 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: function_specifier  */
#line 1055 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1);
		strcpy((yyval.id), "");
	}
#line 3377 "C_grammar.tab.c"
    break;

  case 104: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 1060 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3387 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: alignment_specifier  */
#line 1066 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1);
		strcpy((yyval.id), "");
	}
#line 3396 "C_grammar.tab.c"
    break;

  case 106: /* init_declarator_list: init_declarator  */
#line 1075 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3406 "C_grammar.tab.c"
    break;

  case 107: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 1081 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3419 "C_grammar.tab.c"
    break;

  case 108: /* init_declarator: declarator '=' initializer  */
#line 1093 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		addvariabledetails((yyvsp[-2].id), (yyvsp[0].id)); // DECL_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3431 "C_grammar.tab.c"
    break;

  case 109: /* init_declarator: declarator  */
#line 1101 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		if(typedef_flag == YES)
		{
			char* declaration_cleaned = change_typedef((yyvsp[0].id)); // TYPEDEF_FUNCTIONS.H
			add_typedefs(declaration_cleaned); // TYPEDEF_FUNCTIONS.H
			free(declaration_cleaned);
		}
		else
		{
			// addvariables modifies the passed parameter. Reassigning to temp
			char* temp = (char*) malloc(STRING_LIMIT);
			strcpy(temp, (yyvsp[0].id));
			addvariables(temp, NO);	// DECL_FUNCTIONS.H
			free(temp);
		}
		free((yyvsp[0].id));
	}
#line 3455 "C_grammar.tab.c"
    break;

  case 110: /* storage_class_specifier: TYPEDEF  */
#line 1124 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "typedef");
		set_typedef_flag();	// TYPEDEF_FUNCTIONS.H
	}
#line 3465 "C_grammar.tab.c"
    break;

  case 111: /* storage_class_specifier: EXTERN  */
#line 1130 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "extern");
	}
#line 3474 "C_grammar.tab.c"
    break;

  case 112: /* storage_class_specifier: STATIC  */
#line 1135 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "static_");
	}
#line 3483 "C_grammar.tab.c"
    break;

  case 114: /* storage_class_specifier: AUTO  */
#line 1141 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3492 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: REGISTER  */
#line 1146 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3501 "C_grammar.tab.c"
    break;

  case 116: /* type_specifier: VOID  */
#line 1154 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + 1);
		strcpy((yyval.id), "void");
	}
#line 3510 "C_grammar.tab.c"
    break;

  case 117: /* type_specifier: CHAR  */
#line 1159 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + 1);
		strcpy((yyval.id), "char");
	}
#line 3519 "C_grammar.tab.c"
    break;

  case 118: /* type_specifier: SHORT  */
#line 1164 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + 1);
		strcpy((yyval.id), "short");
	}
#line 3528 "C_grammar.tab.c"
    break;

  case 119: /* type_specifier: INT  */
#line 1169 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(3 + 1);
		strcpy((yyval.id), "int");
	}
#line 3537 "C_grammar.tab.c"
    break;

  case 120: /* type_specifier: LONG  */
#line 1174 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + 1);
		strcpy((yyval.id), "long");
	}
#line 3546 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: FLOAT  */
#line 1179 "C_grammar.y"
        {
		 (yyval.id) = (char*) malloc(5 + 1);
		 strcpy((yyval.id), "float");
	}
#line 3555 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: DOUBLE  */
#line 1184 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "double");
	}
#line 3564 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: SIGNED  */
#line 1189 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "signed");
	}
#line 3573 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: UNSIGNED  */
#line 1194 "C_grammar.y"
        {
		 (yyval.id) = (char*) malloc(8 + 1);
		 strcpy((yyval.id), "unsigned");
	}
#line 3582 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: BOOL  */
#line 1199 "C_grammar.y"
        {
		 (yyval.id) = (char*) malloc(4 + 1);
		 strcpy((yyval.id), "bool");
	}
#line 3591 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: COMPLEX  */
#line 1204 "C_grammar.y"
        {
		 (yyval.id) = (char*) malloc(7 + 1);
		 strcpy((yyval.id), "complex");
	}
#line 3600 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: IMAGINARY  */
#line 1209 "C_grammar.y"
        {
		 (yyval.id) = (char*) malloc(9 + 1);
		 strcpy((yyval.id), "imaginary");
	}
#line 3609 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: struct_or_union_specifier  */
#line 1215 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3619 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: enum_specifier  */
#line 1221 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3629 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: TYPEDEF_NAME  */
#line 1227 "C_grammar.y"
        {
		char* name = change_typedef((yyvsp[0].id));
		(yyval.id) = (char*) malloc(strlen(name) + 1);
		strcpy((yyval.id), name);	 // TYPEDEF_FUNCTIONS.H
		free(name);
		free((yyvsp[0].id));
	}
#line 3641 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: __INT8  */
#line 1235 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "__int8");
	}
#line 3650 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: __INT16  */
#line 1240 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int16");
	}
#line 3659 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: __INT32  */
#line 1245 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int32");
	}
#line 3668 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: __INT64  */
#line 1250 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int64");
	}
#line 3677 "C_grammar.tab.c"
    break;

  case 136: /* type_specifier: WCHAR_T  */
#line 1255 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "wchar_t");
	}
#line 3686 "C_grammar.tab.c"
    break;

  case 137: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 1263 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 3 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), ", [");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3701 "C_grammar.tab.c"
    break;

  case 138: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 1274 "C_grammar.y"
        {
		// change the structure name.
		char * struct_name = (char *) malloc(3 + strlen((yyvsp[-3].id)) + 1);
		if (islower((yyvsp[-3].id)[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, (yyvsp[-3].id));

		(yyval.id) = (char*) malloc(strlen((yyvsp[-4].id)) + 2 + strlen(struct_name) + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-4].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), struct_name);
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");

		free(struct_name);
		free((yyvsp[-4].id));
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3730 "C_grammar.tab.c"
    break;

  case 139: /* struct_or_union_specifier: struct_or_union DECLSPEC_specifiers IDENTIFIER '{' struct_declaration_list '}'  */
#line 1299 "C_grammar.y"
        {
		// change the structure name.
		char* struct_name = (char *) malloc(3 + strlen((yyvsp[-3].id)) + 1);
		if (islower((yyvsp[-3].id)[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, (yyvsp[-3].id));

		(yyval.id) = (char*) malloc(strlen((yyvsp[-5].id)) + 2 + strlen(struct_name) + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-5].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), struct_name);
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");

		free(struct_name);
		free((yyvsp[-5].id));
		free((yyvsp[-4].id));
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3760 "C_grammar.tab.c"
    break;

  case 140: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 1325 "C_grammar.y"
        {
		// change the structure name.
		char * struct_name = (char *) malloc(3 + strlen((yyvsp[0].id)) + 1);
		if (islower((yyvsp[0].id)[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, (yyvsp[0].id));

		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen(struct_name) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), struct_name);
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
		free(struct_name);
	}
#line 3782 "C_grammar.tab.c"
    break;

  case 141: /* DECLSPEC_specifiers: DECLSPEC '(' extended_decl_modifier_seq ')'  */
#line 1346 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1);
		strcpy((yyval.id), "");
	}
#line 3791 "C_grammar.tab.c"
    break;

  case 142: /* DECLSPEC_specifiers: DECLSPEC '(' extended_decl_modifier_seq ')' DECLSPEC_specifiers  */
#line 1351 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1);
		strcpy((yyval.id), "");
		free((yyvsp[0].id));
	}
#line 3801 "C_grammar.tab.c"
    break;

  case 143: /* extended_decl_modifier_seq: ALIGN '(' I_CONSTANT ')'  */
#line 1360 "C_grammar.y"
        {
		free((yyvsp[-1].id));
	}
#line 3809 "C_grammar.tab.c"
    break;

  case 144: /* extended_decl_modifier_seq: ALIGN '(' F_CONSTANT ')'  */
#line 1364 "C_grammar.y"
        {
		free((yyvsp[-1].id));
	}
#line 3817 "C_grammar.tab.c"
    break;

  case 145: /* extended_decl_modifier_seq: IDENTIFIER  */
#line 1368 "C_grammar.y"
        {
		free((yyvsp[0].id));
	}
#line 3825 "C_grammar.tab.c"
    break;

  case 146: /* extended_decl_modifier_seq: type_qualifier  */
#line 1372 "C_grammar.y"
        {
		free((yyvsp[0].id));
	}
#line 3833 "C_grammar.tab.c"
    break;

  case 147: /* extended_decl_modifier_seq: IDENTIFIER '(' primary_expression ')'  */
#line 1376 "C_grammar.y"
        {
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3842 "C_grammar.tab.c"
    break;

  case 148: /* struct_or_union: STRUCT  */
#line 1385 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "struct ");
	}
#line 3851 "C_grammar.tab.c"
    break;

  case 149: /* struct_or_union: UNION  */
#line 1390 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "union ");
	}
#line 3860 "C_grammar.tab.c"
    break;

  case 150: /* struct_declaration_list: struct_declaration  */
#line 1398 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3870 "C_grammar.tab.c"
    break;

  case 151: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1404 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3883 "C_grammar.tab.c"
    break;

  case 153: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 1417 "C_grammar.y"
        {
		if (strstr((yyvsp[-1].id), ",") != NULL) {	// Many variables declared in $2, they must be separated.
			char* struct_definition_string = seperate_fields((yyvsp[-2].id), (yyvsp[-1].id)); // STRUCTURES.H
			(yyval.id) = (char*) malloc(strlen(struct_definition_string) + 1);
			strcpy((yyval.id), struct_definition_string);
			free(struct_definition_string);
		}
		else {	// Build the structure list, removing the 'struct' keyword if present
			char* struct_definition_string = strip_struct((yyvsp[-2].id)); // STRUCTURES.H
			(yyval.id) = (char*) malloc(2 + strlen((yyvsp[-1].id)) + 3 + strlen(struct_definition_string) + 1 + 1);
			strcpy((yyval.id), "([");
			strcat((yyval.id), (yyvsp[-1].id));
			strcat((yyval.id), "], ");
			strcpy((yyvsp[-2].id), struct_definition_string);
			strcat((yyval.id), (yyvsp[-2].id));
			strcat((yyval.id), ")");
			free(struct_definition_string);
		}
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		struct_flag = NO;
	}
#line 3910 "C_grammar.tab.c"
    break;

  case 155: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 1445 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3922 "C_grammar.tab.c"
    break;

  case 156: /* specifier_qualifier_list: type_specifier  */
#line 1453 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3932 "C_grammar.tab.c"
    break;

  case 157: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 1459 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3944 "C_grammar.tab.c"
    break;

  case 158: /* specifier_qualifier_list: type_qualifier  */
#line 1467 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3954 "C_grammar.tab.c"
    break;

  case 159: /* struct_declarator_list: struct_declarator  */
#line 1476 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3965 "C_grammar.tab.c"
    break;

  case 160: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1483 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3979 "C_grammar.tab.c"
    break;

  case 161: /* struct_declarator: ':' constant_expression  */
#line 1496 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3990 "C_grammar.tab.c"
    break;

  case 162: /* struct_declarator: declarator ':' constant_expression  */
#line 1503 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4003 "C_grammar.tab.c"
    break;

  case 163: /* struct_declarator: declarator  */
#line 1512 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4013 "C_grammar.tab.c"
    break;

  case 164: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 1521 "C_grammar.y"
                {
		// Build enumeration list.
		// Pop Scope when '}' is parsed and reset enumerations counter
		(yyval.id) = (char*) malloc(7 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 			// SCOPES.H
		strcat((yyval.id), "]");
		reset_enumcounter(); 	// ENUM_FUNCTIONS.H
		free((yyvsp[-1].id));
	}
#line 4030 "C_grammar.tab.c"
    break;

  case 166: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 1535 "C_grammar.y"
        {
		// Build enumeration list.
		// Change their name to Prolog equivalent using change_enum()
		// Add the name to NAMES file using printnames()
		// Add the literal to Enum linked list using add_enums()
		// Pop Scope when '}' is parsed and reset enumerations counter

		char* enum_name = change_enum((yyvsp[-3].id)); // ENUM_FUNCTIONS.H

		(yyval.id) = (char*) malloc(7 + 1 + strlen(enum_name) + 1 + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);

		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), "[");
		strcat((yyval.id), enum_name);
		strcat((yyval.id), "]");
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
		reset_enumcounter(); // ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4061 "C_grammar.tab.c"
    break;

  case 168: /* enum_specifier: ENUM IDENTIFIER  */
#line 1563 "C_grammar.y"
        {
		// Change enum name to Prolog equivalent using change_enum()
		char* enum_name = change_enum((yyvsp[0].id)); // ENUM_FUNCTIONS.H
		(yyval.id) = (char*) malloc(7 + strlen(enum_name) + 1);
		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), enum_name);
		free((yyvsp[0].id));
		free(enum_name);
	}
#line 4075 "C_grammar.tab.c"
    break;

  case 169: /* enumerator_list: enumerator  */
#line 1576 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4085 "C_grammar.tab.c"
    break;

  case 170: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1582 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4098 "C_grammar.tab.c"
    break;

  case 171: /* enumerator: enumeration_constant '=' constant_expression  */
#line 1595 "C_grammar.y"
        {
		/*
			Process enumeration literals with initializations:
			e.g. enum daYs {mon, tues, wed = 20, thurs, fri = 7};
			Change the enum name to Prolog equivalent using change_enum()
			Add the name to NAMES file using printnames()
			Add the literal to Enum linked list using add_enums(), with its enum value.
		*/
		char *enum_name = change_enum((yyvsp[-2].id)); // ENUM_FUNCTIONS.H

		int i = atoi((yyvsp[0].id)); // change string to integer

		(yyval.id) = (char*) malloc(strlen(enum_name) + 1);
		strcpy((yyval.id), enum_name);
		add_enums((yyvsp[-2].id), i); 			// ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4123 "C_grammar.tab.c"
    break;

  case 172: /* enumerator: enumeration_constant  */
#line 1616 "C_grammar.y"
        {
		/*
			Process enumeration literals.
			Change their name to Prolog equivalent using change_enum()
			Add the name to NAMES file using printnames()
			Add the literal to Enum linked list using add_enums()
		*/
		char* enum_name = change_enum((yyvsp[0].id)); // ENUM_FUNCTIONS.H

		(yyval.id) = (char*) malloc(strlen(enum_name) + 1);
		strcpy((yyval.id), enum_name);
		add_enums((yyvsp[0].id), -1);			// ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[0].id));
	}
#line 4144 "C_grammar.tab.c"
    break;

  case 174: /* type_qualifier: CONST  */
#line 1640 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + 1);
		strcpy((yyval.id), "const");
	}
#line 4153 "C_grammar.tab.c"
    break;

  case 175: /* type_qualifier: RESTRICT  */
#line 1645 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(8 + 1);
		strcpy((yyval.id), "restrict");
	}
#line 4162 "C_grammar.tab.c"
    break;

  case 176: /* type_qualifier: VOLATILE  */
#line 1650 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(8 + 1);
		strcpy((yyval.id), "volatile");
	}
#line 4171 "C_grammar.tab.c"
    break;

  case 177: /* type_qualifier: ATOMIC  */
#line 1655 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "atomic");
	}
#line 4180 "C_grammar.tab.c"
    break;

  case 181: /* function_specifier: DECLSPEC_specifiers  */
#line 1666 "C_grammar.y"
        {
		free((yyvsp[0].id));
	}
#line 4188 "C_grammar.tab.c"
    break;

  case 184: /* declarator: pointer direct_declarator  */
#line 1678 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4200 "C_grammar.tab.c"
    break;

  case 185: /* declarator: pointer microsoft_native_pointer_extension direct_declarator  */
#line 1686 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4213 "C_grammar.tab.c"
    break;

  case 186: /* declarator: direct_declarator  */
#line 1695 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4223 "C_grammar.tab.c"
    break;

  case 187: /* microsoft_native_pointer_extension: __PTR32  */
#line 1704 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1);
		strcpy((yyval.id), "");
	}
#line 4232 "C_grammar.tab.c"
    break;

  case 188: /* microsoft_native_pointer_extension: __PTR64  */
#line 1709 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1);
		strcpy((yyval.id), "");
	}
#line 4241 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: IDENTIFIER  */
#line 1717 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4251 "C_grammar.tab.c"
    break;

  case 190: /* direct_declarator: '(' declarator ')'  */
#line 1723 "C_grammar.y"
        {
		if(typedef_flag == YES) {
			typedef_flag = NO;
			char* declaration_cleaned = change_typedef((yyvsp[-1].id)); // TYPEDEF_FUNCTIONS.H
			add_typedefs(declaration_cleaned); // TYPEDEF_FUNCTIONS.H
			free(declaration_cleaned);
		}

		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4270 "C_grammar.tab.c"
    break;

  case 191: /* direct_declarator: direct_declarator '[' ']'  */
#line 1738 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 4282 "C_grammar.tab.c"
    break;

  case 192: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 1746 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 4295 "C_grammar.tab.c"
    break;

  case 199: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 1761 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4306 "C_grammar.tab.c"
    break;

  case 200: /* direct_declarator: TYPEDEF_NAME '[' assignment_expression ']'  */
#line 1768 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4317 "C_grammar.tab.c"
    break;

  case 201: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 1775 "C_grammar.y"
        {
		/* 	function prototypes and definitions come through this rule.
			in order to distinguish them later on from variables we
			add the string "function_prototype" to $$
			if this is the function definition this will have to be stripped later.
			if it is the function prototype it is left as it is.
		*/
		(yyval.id) = (char*) malloc(19 + strlen((yyvsp[-3].id)) + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 2 + 2 + 1);

		if(typedef_flag == YES) {
			char* declaration_cleaned = change_typedef((yyvsp[-3].id)); // TYPEDEF_FUNCTIONS.H
			add_typedefs(declaration_cleaned); // TYPEDEF_FUNCTIONS.H
			free(declaration_cleaned);
			typedef_flag = NO;
		}

		(yyvsp[-3].id)[0] = convert_tolower((yyvsp[-3].id)[0]);
		strcpy((yyval.id), "function_prototype(");
		strcat((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "]");
		strcat((yyval.id), ", ");
		strcat((yyval.id), ")."); //15 Jun 2024 was strcat($$, ").") full stop removed then added again due to postprocessing mess
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4350 "C_grammar.tab.c"
    break;

  case 202: /* direct_declarator: direct_declarator '(' ')'  */
#line 1804 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 4362 "C_grammar.tab.c"
    break;

  case 203: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 1812 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4376 "C_grammar.tab.c"
    break;

  case 204: /* direct_declarator: vc_specific_modifier IDENTIFIER  */
#line 1822 "C_grammar.y"
        {
		struct_flag = NO;
		
		// Visual C extension
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4390 "C_grammar.tab.c"
    break;

  case 205: /* direct_declarator: '(' vc_specific_modifier declarator ')'  */
#line 1832 "C_grammar.y"
        {
		if(typedef_flag == YES) {
			typedef_flag = NO;
			char* type_definition = change_typedef((yyvsp[-1].id)); // TYPEDEF_FUNCTIONS.H
			add_typedefs(type_definition); // TYPEDEF_FUNCTIONS.H
			free(type_definition);
		}
		// Visual C extension
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 4408 "C_grammar.tab.c"
    break;

  case 206: /* vc_specific_modifier: __CDECL  */
#line 1849 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4417 "C_grammar.tab.c"
    break;

  case 207: /* vc_specific_modifier: __CLRCALL  */
#line 1854 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4426 "C_grammar.tab.c"
    break;

  case 208: /* vc_specific_modifier: __STDCALL  */
#line 1859 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4435 "C_grammar.tab.c"
    break;

  case 209: /* vc_specific_modifier: __FASTCALL  */
#line 1864 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4444 "C_grammar.tab.c"
    break;

  case 210: /* vc_specific_modifier: __THISCALL  */
#line 1869 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4453 "C_grammar.tab.c"
    break;

  case 211: /* vc_specific_modifier: __VECTORCALL  */
#line 1874 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4462 "C_grammar.tab.c"
    break;

  case 212: /* pointer: '*' type_qualifier_list pointer  */
#line 1882 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4475 "C_grammar.tab.c"
    break;

  case 213: /* pointer: '*' type_qualifier_list  */
#line 1891 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4486 "C_grammar.tab.c"
    break;

  case 214: /* pointer: '*' pointer  */
#line 1898 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4497 "C_grammar.tab.c"
    break;

  case 215: /* pointer: '*'  */
#line 1905 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1);
		strcpy((yyval.id), "*");
	}
#line 4506 "C_grammar.tab.c"
    break;

  case 216: /* type_qualifier_list: type_qualifier  */
#line 1913 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4516 "C_grammar.tab.c"
    break;

  case 217: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1919 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4528 "C_grammar.tab.c"
    break;

  case 218: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1930 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 3 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), "...");
		free((yyvsp[-2].id));
	}
#line 4540 "C_grammar.tab.c"
    break;

  case 219: /* parameter_type_list: parameter_list  */
#line 1938 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		int lenSS = strlen((yyvsp[0].id)) - 1;
		if ((yyvsp[0].id)[lenSS] == ',')
			(yyvsp[0].id)[lenSS] = ' ';
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4553 "C_grammar.tab.c"
    break;

  case 220: /* parameter_list: parameter_declaration  */
#line 1950 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
		struct_flag = NO;
	}
#line 4564 "C_grammar.tab.c"
    break;

  case 221: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1957 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
		struct_flag = NO;
	}
#line 4577 "C_grammar.tab.c"
    break;

  case 222: /* parameter_declaration: declaration_specifiers declarator  */
#line 1969 "C_grammar.y"
        {
		if (PListFirstUse == NO)	// PARAMETERS.H
		{
			PListFirstUse = YES;	// PARAMETERS.H
			P = CreatePList();	// PARAMETERS.H
		}
		PushPList((yyvsp[0].id), P);		// PARAMETERS.H
		Push(yylineno);	// SCOPES.H
		addvariables((yyvsp[0].id), YES);			// DECL_FUNCTIONS.H
		char* declaration_string = findvariabledetails((yyvsp[-1].id)); // DECL_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(declaration_string) + 1);
		strcpy((yyval.id), declaration_string);
		free(declaration_string);
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4598 "C_grammar.tab.c"
    break;

  case 223: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1986 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4610 "C_grammar.tab.c"
    break;

  case 224: /* parameter_declaration: declaration_specifiers vc_specific_modifier abstract_declarator  */
#line 1994 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[-1].id));
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 4622 "C_grammar.tab.c"
    break;

  case 225: /* parameter_declaration: declaration_specifiers  */
#line 2002 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4632 "C_grammar.tab.c"
    break;

  case 226: /* identifier_list: IDENTIFIER  */
#line 2011 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4642 "C_grammar.tab.c"
    break;

  case 227: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 2017 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4655 "C_grammar.tab.c"
    break;

  case 228: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 2029 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4667 "C_grammar.tab.c"
    break;

  case 229: /* type_name: specifier_qualifier_list abstract_declarator microsoft_native_pointer_extension  */
#line 2037 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[-1].id));
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4680 "C_grammar.tab.c"
    break;

  case 230: /* type_name: specifier_qualifier_list  */
#line 2046 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4690 "C_grammar.tab.c"
    break;

  case 231: /* type_name: IDENTIFIER  */
#line 2052 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4700 "C_grammar.tab.c"
    break;

  case 232: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 2061 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4712 "C_grammar.tab.c"
    break;

  case 233: /* abstract_declarator: '(' vc_specific_modifier pointer ')' direct_abstract_declarator  */
#line 2069 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4725 "C_grammar.tab.c"
    break;

  case 234: /* abstract_declarator: pointer  */
#line 2078 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4735 "C_grammar.tab.c"
    break;

  case 235: /* abstract_declarator: direct_abstract_declarator  */
#line 2084 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4745 "C_grammar.tab.c"
    break;

  case 236: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 2093 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4757 "C_grammar.tab.c"
    break;

  case 237: /* direct_abstract_declarator: '[' ']'  */
#line 2101 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "]");
	}
#line 4767 "C_grammar.tab.c"
    break;

  case 238: /* direct_abstract_declarator: '[' '*' ']'  */
#line 2107 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
	}
#line 4778 "C_grammar.tab.c"
    break;

  case 245: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 2120 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 4790 "C_grammar.tab.c"
    break;

  case 246: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 2128 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 4803 "C_grammar.tab.c"
    break;

  case 253: /* direct_abstract_declarator: '(' ')'  */
#line 2143 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), ")");
	}
#line 4813 "C_grammar.tab.c"
    break;

  case 254: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 2149 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4825 "C_grammar.tab.c"
    break;

  case 255: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 2157 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 4837 "C_grammar.tab.c"
    break;

  case 256: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 2165 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4851 "C_grammar.tab.c"
    break;

  case 257: /* initializer: '{' initializer_list '}'  */
#line 2178 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");

		free((yyvsp[-1].id));
	}
#line 4865 "C_grammar.tab.c"
    break;

  case 258: /* initializer: '{' initializer_list ',' '}'  */
#line 2188 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "{");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "}");

		free((yyvsp[-2].id));
	}
#line 4880 "C_grammar.tab.c"
    break;

  case 259: /* initializer: assignment_expression  */
#line 2199 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4890 "C_grammar.tab.c"
    break;

  case 260: /* initializer_list: designation initializer  */
#line 2208 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4903 "C_grammar.tab.c"
    break;

  case 261: /* initializer_list: initializer  */
#line 2217 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4913 "C_grammar.tab.c"
    break;

  case 263: /* initializer_list: initializer_list ',' initializer  */
#line 2224 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id)); 
		strcat((yyval.id), ","); 
		strcat((yyval.id), (yyvsp[0].id));

		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4927 "C_grammar.tab.c"
    break;

  case 264: /* designation: designator_list '='  */
#line 2237 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "=");
		free((yyvsp[-1].id));
	}
#line 4938 "C_grammar.tab.c"
    break;

  case 265: /* designator_list: designator  */
#line 2247 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4948 "C_grammar.tab.c"
    break;

  case 266: /* designator_list: designator_list designator  */
#line 2253 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4960 "C_grammar.tab.c"
    break;

  case 267: /* designator: '[' constant_expression ']'  */
#line 2264 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "]");
		free((yyvsp[-1].id));
	}
#line 4972 "C_grammar.tab.c"
    break;

  case 268: /* designator: '.' IDENTIFIER  */
#line 2272 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "access(");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[0].id));
	}
#line 4984 "C_grammar.tab.c"
    break;

  case 270: /* statement: labeled_statement  */
#line 2287 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4994 "C_grammar.tab.c"
    break;

  case 271: /* statement: compound_statement  */
#line 2293 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5004 "C_grammar.tab.c"
    break;

  case 272: /* statement: expression_statement  */
#line 2299 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5014 "C_grammar.tab.c"
    break;

  case 273: /* statement: selection_statement  */
#line 2305 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5024 "C_grammar.tab.c"
    break;

  case 274: /* statement: iteration_statement  */
#line 2311 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5034 "C_grammar.tab.c"
    break;

  case 275: /* statement: jump_statement  */
#line 2317 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5044 "C_grammar.tab.c"
    break;

  case 276: /* labeled_statement: IDENTIFIER ':' statement  */
#line 2326 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5057 "C_grammar.tab.c"
    break;

  case 277: /* labeled_statement: CASE constant_expression ':' statement  */
#line 2335 "C_grammar.y"
        {
		char* case_string = case_statement((yyvsp[-2].id), (yyvsp[0].id)); // SWITCH_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(case_string) + 1);
		strcpy((yyval.id), case_string);
		free(case_string);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5070 "C_grammar.tab.c"
    break;

  case 278: /* labeled_statement: DEFAULT ':' statement  */
#line 2344 "C_grammar.y"
        {
		char* default_string = default_statement((yyvsp[0].id)); // SWITCH_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(default_string) + 1);
		strcpy((yyval.id), default_string);
		free(default_string);
		free((yyvsp[0].id));
	}
#line 5082 "C_grammar.tab.c"
    break;

  case 279: /* compound_statement: '{' '}'  */
#line 2355 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 5093 "C_grammar.tab.c"
    break;

  case 280: /* compound_statement: '{' block_item_list '}'  */
#line 2362 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop();  	// SCOPES.H

		int lenSS = strlen((yyval.id)) - 1;
		if ((yyval.id)[lenSS] == ',')
			(yyval.id)[lenSS] = ']';
		else
			strcat((yyval.id), "]");
		free((yyvsp[-1].id));
	}
#line 5111 "C_grammar.tab.c"
    break;

  case 281: /* block_item_list: block_item  */
#line 2379 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5121 "C_grammar.tab.c"
    break;

  case 282: /* block_item_list: block_item_list block_item  */
#line 2385 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));

		int lenSS = strlen((yyval.id)) - 1;
		if ((yyval.id)[lenSS] != ',')
			strcat((yyval.id), ",");

		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 5138 "C_grammar.tab.c"
    break;

  case 283: /* block_item: declaration  */
#line 2401 "C_grammar.y"
        {

		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5149 "C_grammar.tab.c"
    break;

  case 284: /* block_item: statement  */
#line 2408 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5159 "C_grammar.tab.c"
    break;

  case 285: /* expression_statement: ';'  */
#line 2417 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "null");
	}
#line 5168 "C_grammar.tab.c"
    break;

  case 286: /* expression_statement: expression ';'  */
#line 2422 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(21 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "expression_statement(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 5180 "C_grammar.tab.c"
    break;

  case 287: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 2433 "C_grammar.y"
        {
		char* if_else_statement_definition = ifelse_statement((yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id)); // IF_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(if_else_statement_definition) + 1);
		strcpy((yyval.id), if_else_statement_definition);
		free(if_else_statement_definition);
		free((yyvsp[-4].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5194 "C_grammar.tab.c"
    break;

  case 288: /* selection_statement: IF '(' expression ')' statement  */
#line 2443 "C_grammar.y"
        {
		char* if_statement_definition = if_statement((yyvsp[-2].id), (yyvsp[0].id)); // IF_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(if_statement_definition) + 1);
		strcpy((yyval.id), if_statement_definition);
		free(if_statement_definition);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5207 "C_grammar.tab.c"
    break;

  case 289: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 2452 "C_grammar.y"
        {
		char* switch_statement_definition = switch_statement((yyvsp[-2].id), (yyvsp[0].id)); // SWITCH_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(switch_statement_definition) + 1);
		strcpy((yyval.id), switch_statement_definition);
		free(switch_statement_definition);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5220 "C_grammar.tab.c"
    break;

  case 290: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 2464 "C_grammar.y"
        {
		char* while_statement_definition = while_statement((yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(while_statement_definition) + 1);
		strcpy((yyval.id), while_statement_definition);
		free(while_statement_definition);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5233 "C_grammar.tab.c"
    break;

  case 291: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 2473 "C_grammar.y"
        {
		char* do_statement_definition = do_statement((yyvsp[-5].id), (yyvsp[-2].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(do_statement_definition) + 1);
		strcpy((yyval.id), do_statement_definition);
		free(do_statement_definition);
		free((yyvsp[-5].id));
		free((yyvsp[-2].id));
	}
#line 5246 "C_grammar.tab.c"
    break;

  case 292: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 2482 "C_grammar.y"
        {
		char* for_statement_definition = for2_statement((yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(for_statement_definition) + 1);
		strcpy((yyval.id), for_statement_definition);
		free(for_statement_definition);
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5260 "C_grammar.tab.c"
    break;

  case 293: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 2492 "C_grammar.y"
        {
		char* for_statement_definition = for_statement((yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(for_statement_definition) + 1);
		strcpy((yyval.id), for_statement_definition);
		free(for_statement_definition);
		free((yyvsp[-4].id));
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 5275 "C_grammar.tab.c"
    break;

  case 296: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 2508 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "goto");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ";");
		free((yyvsp[-1].id));
	}
#line 5287 "C_grammar.tab.c"
    break;

  case 297: /* jump_statement: CONTINUE ';'  */
#line 2516 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(8 + 1);
		strcpy((yyval.id), "continue");
	}
#line 5296 "C_grammar.tab.c"
    break;

  case 298: /* jump_statement: BREAK ';'  */
#line 2521 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + 1);
		strcpy((yyval.id), "break");
	}
#line 5305 "C_grammar.tab.c"
    break;

  case 299: /* jump_statement: RETURN ';'  */
#line 2526 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "return");
	}
#line 5314 "C_grammar.tab.c"
    break;

  case 300: /* jump_statement: RETURN expression ';'  */
#line 2531 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "return(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 5326 "C_grammar.tab.c"
    break;

  case 301: /* translation_unit: external_declaration  */
#line 2542 "C_grammar.y"
        {
		//$$ = (char*) malloc(strlen($1) + 1);
		//strcpy($$, $1);
		//free($1);
	}
#line 5336 "C_grammar.tab.c"
    break;

  case 302: /* translation_unit: translation_unit external_declaration  */
#line 2548 "C_grammar.y"
        {
		//$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		//strcpy($$, $1);
		//strcat($$, $2);
		//free($1);
		//free($2);
	}
#line 5348 "C_grammar.tab.c"
    break;

  case 303: /* external_declaration: function_definition  */
#line 2559 "C_grammar.y"
        {
		//$$ = (char*) malloc(strlen($1) + 1);
		//strcpy($$, $1);
		fprintf(pl_file, "%s\n", (yyvsp[0].id));
		free((yyvsp[0].id));
		struct_flag = NO;
	}
#line 5360 "C_grammar.tab.c"
    break;

  case 304: /* external_declaration: declaration  */
#line 2567 "C_grammar.y"
        {
		// Global Variable declarations
		int lenS1 = strlen((yyvsp[0].id)) - 1;
		(yyval.id) = (char*) malloc(20 + strlen((yyvsp[0].id)) + 11 + 1);
		strcpy((yyval.id), "\nglobal_variables([");
		if((yyvsp[0].id)[lenS1] == ',') (yyvsp[0].id)[lenS1] = ' ';
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), "], void),\n");
		fprintf(pl_file, "%s\n", (yyval.id));
		free((yyvsp[0].id));
	}
#line 5376 "C_grammar.tab.c"
    break;

  case 305: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 2582 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 5392 "C_grammar.tab.c"
    break;

  case 306: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 2594 "C_grammar.y"
        {
		// Function Defintions
		char* function = process_functions((yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id));
		(yyval.id) = (char*) malloc(strlen(function) + 1);
		strcpy((yyval.id), function);	// DECL_FUNCTIONS.H
		free(function);
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 5407 "C_grammar.tab.c"
    break;

  case 307: /* declaration_list: declaration  */
#line 2608 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 5417 "C_grammar.tab.c"
    break;

  case 308: /* declaration_list: declaration_list declaration  */
#line 2614 "C_grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 5429 "C_grammar.tab.c"
    break;


#line 5433 "C_grammar.tab.c"

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

#line 2623 "C_grammar.y"

#include <stdio.h>
#include "lex.yy.c"

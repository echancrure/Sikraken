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
#include <ctype.h>
#include "utils.h"
#include "handle_typedefs.h"
#include "string_buffer.h"
#include "stack_of_id_tables.c"

extern int yylex();
extern int yylineno;

extern FILE *yyin;
extern char *yytext;

int debugMode = 0;				//flag to indicate if we are in debug mode set by by -d command line switch
FILE* pl_file;						//the file of containing the Prolog predicated after parsing the target C file
char pl_file_uri[_MAX_PATH];		//the full path to the Pl_file
struct scope *ordinary_ids_scope_stack = NULL;	//stack of id tables to track scopes of is in the ordinary namespace 
StringBuilder *id_names;			//string buffer to hold Prolog var names and their details e.g. a(I_407, 'ch8_1.adb:39:7:i')
int id_counter = 0;					//used to generate unique Prolog var names e.g. I_1, I_2, I_3 etc.
//start: ugly, breaking parsing spirit, flags and temporary variables
int in_member_decl_flag = 0;	//indicate that we are parsing struct or union declarations and that the ids are part of the members namespace
char* tmp_current_decl_id;			//temporary holder for the id currently being declared
char* tmp_current_decl_prolog_var;	//temporary holder for the Prolog var currently being declared

void yyerror(const char*);
void my_exit(int);				//attempts to close handles and delete generated files prior to caling exit(int);


#line 104 "C_grammar.tab.c"

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
  YYSYMBOL_157_2 = 157,                    /* $@2  */
  YYSYMBOL_pointer = 158,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 159,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 160,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 161,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 162,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 163,          /* identifier_list  */
  YYSYMBOL_type_name = 164,                /* type_name  */
  YYSYMBOL_abstract_declarator = 165,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 166, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 167,              /* initializer  */
  YYSYMBOL_initializer_list = 168,         /* initializer_list  */
  YYSYMBOL_designation = 169,              /* designation  */
  YYSYMBOL_designator_list = 170,          /* designator_list  */
  YYSYMBOL_designator = 171,               /* designator  */
  YYSYMBOL_static_assert_declaration = 172, /* static_assert_declaration  */
  YYSYMBOL_statement = 173,                /* statement  */
  YYSYMBOL_labeled_statement = 174,        /* labeled_statement  */
  YYSYMBOL_175_3 = 175,                    /* $@3  */
  YYSYMBOL_176_4 = 176,                    /* $@4  */
  YYSYMBOL_177_5 = 177,                    /* $@5  */
  YYSYMBOL_compound_statement = 178,       /* compound_statement  */
  YYSYMBOL_179_6 = 179,                    /* $@6  */
  YYSYMBOL_block_item_list = 180,          /* block_item_list  */
  YYSYMBOL_181_7 = 181,                    /* $@7  */
  YYSYMBOL_block_item = 182,               /* block_item  */
  YYSYMBOL_expression_statement = 183,     /* expression_statement  */
  YYSYMBOL_selection_statement = 184,      /* selection_statement  */
  YYSYMBOL_185_8 = 185,                    /* $@8  */
  YYSYMBOL_186_9 = 186,                    /* $@9  */
  YYSYMBOL_else_opt = 187,                 /* else_opt  */
  YYSYMBOL_188_10 = 188,                   /* $@10  */
  YYSYMBOL_iteration_statement = 189,      /* iteration_statement  */
  YYSYMBOL_190_11 = 190,                   /* $@11  */
  YYSYMBOL_191_12 = 191,                   /* $@12  */
  YYSYMBOL_192_13 = 192,                   /* $@13  */
  YYSYMBOL_193_14 = 193,                   /* $@14  */
  YYSYMBOL_for_stmt_type = 194,            /* for_stmt_type  */
  YYSYMBOL_195_15 = 195,                   /* $@15  */
  YYSYMBOL_196_16 = 196,                   /* $@16  */
  YYSYMBOL_expression_opt = 197,           /* expression_opt  */
  YYSYMBOL_jump_statement = 198,           /* jump_statement  */
  YYSYMBOL_translation_unit = 199,         /* translation_unit  */
  YYSYMBOL_200_17 = 200,                   /* $@17  */
  YYSYMBOL_external_declaration = 201,     /* external_declaration  */
  YYSYMBOL_function_definition = 202,      /* function_definition  */
  YYSYMBOL_203_18 = 203,                   /* $@18  */
  YYSYMBOL_204_19 = 204,                   /* $@19  */
  YYSYMBOL_declaration_list_opt = 205,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 206,         /* declaration_list  */
  YYSYMBOL_207_20 = 207                    /* $@20  */
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
#define YYLAST   2082

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  304
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  494

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
       0,    76,    76,    84,    85,    86,    87,    91,    92,    93,
      97,   102,   103,   107,   111,   112,   116,   117,   121,   123,
     130,   136,   143,   150,   157,   163,   169,   176,   186,   187,
     197,   198,   205,   212,   218,   224,   233,   234,   238,   239,
     240,   241,   242,   243,   247,   248,   258,   259,   270,   271,
     272,   276,   277,   288,   289,   293,   294,   305,   306,   310,
     311,   322,   323,   324,   325,   330,   331,   342,   343,   347,
     348,   358,   359,   369,   370,   380,   381,   391,   392,   402,
     403,   414,   415,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   440,   441,   451,   455,   459,   467,
     474,   481,   482,   489,   490,   492,   494,   496,   498,   500,
     505,   506,   516,   524,   534,   538,   539,   540,   541,   542,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   565,   572,   580,   590,
     591,   595,   597,   607,   613,   613,   621,   626,   633,   635,
     642,   647,   649,   659,   665,   672,   677,   683,   689,   696,
     703,   712,   714,   724,   731,   736,   740,   741,   742,   743,
     747,   748,   752,   753,   757,   764,   769,   794,   796,   798,
     800,   802,   804,   806,   808,   810,   812,   815,   814,   825,
     831,   836,   843,   849,   855,   860,   862,   872,   878,   883,
     885,   895,   903,   910,   919,   920,   924,   925,   929,   930,
     931,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   950,   951,   952,   953,
     954,   955,   959,   965,   971,   976,   983,   985,   993,  1003,
    1012,  1014,  1024,  1026,  1035,  1045,  1046,  1047,  1048,  1049,
    1050,  1055,  1054,  1060,  1060,  1061,  1061,  1065,  1067,  1066,
    1078,  1079,  1079,  1083,  1084,  1088,  1089,  1093,  1093,  1094,
    1094,  1098,  1099,  1099,  1102,  1102,  1103,  1103,  1104,  1104,
    1104,  1108,  1108,  1109,  1109,  1113,  1114,  1117,  1118,  1119,
    1120,  1121,  1126,  1127,  1127,  1131,  1132,  1137,  1142,  1136,
    1150,  1151,  1155,  1156,  1156
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
  "alignment_specifier", "declarator", "direct_declarator", "$@2",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "static_assert_declaration", "statement",
  "labeled_statement", "$@3", "$@4", "$@5", "compound_statement", "$@6",
  "block_item_list", "$@7", "block_item", "expression_statement",
  "selection_statement", "$@8", "$@9", "else_opt", "$@10",
  "iteration_statement", "$@11", "$@12", "$@13", "$@14", "for_stmt_type",
  "$@15", "$@16", "expression_opt", "jump_statement", "translation_unit",
  "$@17", "external_declaration", "function_definition", "$@18", "$@19",
  "declaration_list_opt", "declaration_list", "$@20", YY_NULLPTR
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

#define YYTABLE_NINF (-302)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1854,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,    15,   -55,   -50,  -320,   -13,
    -320,  -320,    41,  1959,  1959,  -320,    29,  -320,  -320,  1959,
    1959,  1959,  -320,    50,  -320,  -320,   -29,    62,   786,  2011,
    1422,  -320,    27,    -4,  -320,   -54,  -320,   -56,   -19,    52,
    -320,  -320,     2,  1517,  -320,  -320,  -320,  -320,  1854,    62,
    -320,   -10,    89,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    1510,  -320,  -320,     0,    38,   786,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,  -320,   167,  -320,  1531,  1422,
    -320,   122,   145,   221,    43,   219,    40,    53,    49,   139,
      -7,  -320,   107,  2011,   -18,  2011,   109,   119,    88,   147,
    -320,  -320,  -320,    -4,    27,  -320,  1292,  1854,    46,   808,
     -19,  1517,  1697,  -320,   112,  -320,  -320,    92,  1422,    20,
    -320,   786,  -320,  2011,  1422,   176,  -320,  -320,   177,   149,
     225,  -320,  -320,  1380,  1422,   236,   786,  -320,  -320,  -320,
    -320,  -320,  1422,  -320,  -320,  1422,  -320,  -320,  1422,  -320,
    -320,  -320,  -320,  1422,  -320,  -320,  1422,  1422,  1422,  1422,
    1422,  1422,  1422,  -320,  -320,  1645,   896,   140,  -320,   143,
    -320,  -320,  -320,   234,  -320,  -320,  -320,  -320,   146,  1271,
    -320,  -320,  -320,    41,  -320,   165,  -320,  -320,  1959,   181,
    1141,  -320,   172,   175,   919,  1749,  -320,  -320,  -320,    63,
      26,  -320,  -320,  -320,  -320,   196,   204,   205,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  1422,
    -320,  1422,  1401,  -320,  -320,   184,  -320,   144,  -320,   208,
    -320,   122,   145,   221,    43,   219,    40,    53,    49,   139,
     186,  -320,    67,   215,   216,  -320,   218,  1141,  -320,   223,
     226,  1007,   143,  1802,  1030,   220,  1422,   290,  -320,   110,
    1292,    95,  -320,   213,  1854,   222,  -320,   297,   227,  1141,
    -320,  -320,  1422,  -320,   231,   233,  -320,  1422,    72,  -320,
     237,  -320,   232,  -320,   674,  -320,  -320,  1271,  -320,  -320,
    1422,  -320,   232,  1422,  1590,  -320,    75,  -320,  -320,  1906,
    -320,   238,  1141,  -320,  -320,  1422,  -320,   241,  -320,   229,
    1141,  -320,   246,   248,  1118,   235,   252,  -320,  1162,  -320,
    -320,  -320,  -320,   253,  -320,  -320,  -320,  -320,  -320,   257,
     259,  -320,  -320,  -320,    63,  -320,  1422,   239,   192,  -320,
     263,   134,  -320,  -320,  -320,  -320,  -320,   262,   265,  -320,
    -320,   266,  1141,  -320,  -320,  1422,  -320,   267,  -320,  -320,
    -320,  -320,  1292,  -320,   522,  -320,  -320,  -320,  -320,  1422,
    -320,   674,  1422,  1250,  -320,  -320,  -320,  -320,   268,   273,
    -320,  -320,   276,  1422,   281,   286,   287,   288,  -320,   291,
     363,   269,   270,   663,  -320,    83,  -320,  -320,  -320,  -320,
     289,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,   292,  -320,  1422,  1422,  1422,   422,  -320,
     275,  -320,  -320,  -320,    86,  -320,  -320,   522,   422,  -320,
     422,   199,   201,   210,   313,   610,  -320,  -320,  -320,  -320,
     422,  -320,  -320,  -320,  -320,   300,  -320,  -320,   301,  -320,
     422,   422,   422,  1422,   698,   698,  -320,   317,  -320,  -320,
     212,  1422,  1422,   422,  -320,  -320,   280,   302,  -320,  -320,
    -320,   422,  -320,  -320
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   135,   114,   115,   116,   118,   119,   170,   166,   167,
     168,   129,   121,   122,   123,   124,   127,   128,   125,   126,
     120,   130,   131,   139,   140,     0,     0,   169,   171,     0,
     117,   296,     0,   101,   103,   133,     0,   134,   132,   105,
     107,   109,    99,   293,   292,   295,   160,     0,     0,     0,
       0,   176,     0,   194,    97,     0,   110,   297,   175,     0,
     100,   102,   138,     0,   104,   106,   108,     1,     0,     0,
      10,   164,     0,   161,     2,     7,     8,     9,    11,    12,
       0,    36,    37,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    18,     3,     4,     6,    30,    44,     0,     0,
      46,    51,    55,    59,    65,    69,    71,    73,    75,    77,
      79,    96,     0,   148,   207,   150,     0,     0,     0,     0,
     169,   195,   193,   192,     0,    98,     0,   300,   187,     0,
     174,     0,     0,   141,   144,   146,   294,     0,     0,     0,
     156,     0,    33,     0,     0,    44,    81,    94,     0,     0,
       0,    24,    25,     0,     0,     0,     0,    31,    32,    48,
      49,    50,     0,    53,    54,     0,    57,    58,     0,    63,
      64,    61,    62,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,   173,   147,     0,     0,   209,   206,   210,
     149,   172,   165,     0,   177,   196,   191,   111,   113,     0,
     234,   112,   302,     0,   298,   303,   204,   189,     0,     0,
       0,   178,    39,     0,     0,     0,   136,   142,   143,     0,
       0,   158,   163,   157,   162,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    83,     0,
       5,     0,     0,    23,    20,     0,    28,     0,    22,     0,
      47,    52,    56,    60,    66,    70,    72,    74,    76,    78,
       0,   228,   203,     0,   198,   199,     0,     0,   212,    39,
       0,     0,   208,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   240,     0,     0,     0,   190,     0,     0,     0,
     179,   186,     0,   185,    39,     0,   137,     0,     0,   151,
     155,   159,    34,    35,     0,    82,    95,     0,    45,    21,
       0,    19,     0,     0,     0,   201,   209,   202,   229,     0,
     211,     0,     0,   213,   219,     0,   218,     0,   230,     0,
       0,   220,    39,     0,     0,     0,     0,   243,     0,   232,
     235,   239,   241,   258,   299,   304,   188,   205,   181,     0,
       0,   182,   184,   153,     0,   145,     0,     0,     0,    14,
       0,     0,    29,    80,   197,   200,   215,     0,     0,   217,
     231,     0,     0,   221,   227,     0,   226,     0,   244,   242,
     233,   238,     0,   257,     0,   180,   183,   152,   154,     0,
      13,     0,     0,     0,    26,   214,   216,   223,     0,     0,
     224,   237,     2,     0,     0,     0,     0,     0,   276,     0,
       0,     0,     0,     0,   265,     0,   263,   264,   245,   246,
     261,   260,   247,   248,   249,   250,    17,    15,    16,    27,
     222,   225,   251,     0,   255,     0,     0,     0,     0,   278,
       0,   288,   289,   290,     0,   266,   259,     0,     0,   253,
       0,     0,     0,     0,     0,     0,   287,   291,   262,   252,
       0,   256,   267,   269,   274,     0,   283,   281,     0,   254,
       0,     0,     0,     0,     0,     0,   279,   271,   270,   275,
       0,   285,   285,     0,   272,   268,     0,   286,   284,   282,
     280,     0,   277,   273
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -320,  -320,  -320,  -320,  -320,  -320,  -320,    -9,  -320,  -320,
     -47,  -320,  -320,   -90,   224,  -320,   217,  -320,   211,  -320,
     207,  -320,   209,  -320,   203,   214,   228,   206,  -320,   -46,
     131,  -320,   -85,   -45,  -116,     7,  -320,   271,  -320,   -32,
    -320,  -320,   260,  -119,  -320,   -26,  -320,    36,  -320,   323,
    -101,  -320,    31,  -320,  -320,   -22,   -53,  -320,   -28,  -109,
    -135,  -320,    80,  -320,   -21,  -106,  -175,  -111,    87,  -319,
    -320,   120,   -24,  -147,  -320,  -320,  -320,  -320,   117,  -320,
    -320,  -320,   -43,  -265,  -320,  -320,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,  -320,  -320,   -76,  -320,  -320,
    -320,   339,  -320,  -320,  -320,  -320,  -320,  -320
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    71,    94,    95,   358,   359,    96,   245,
     145,    98,    99,   100,   101,   162,   102,   165,   103,   168,
     104,   173,   105,   176,   106,   107,   108,   109,   110,   146,
     147,   239,   415,   112,    31,   203,    55,    56,    33,    34,
      35,    36,   132,   133,   219,   114,   298,   299,    37,    72,
      73,    38,    39,    40,    41,   119,    58,   208,    59,   123,
     263,   264,   265,   209,   360,   266,   189,   278,   279,   280,
     281,   282,    42,   417,   418,   448,   460,   450,   419,   384,
     420,   447,   421,   422,   423,   470,   471,   485,   491,   424,
     472,   438,   455,   483,   468,   475,   474,   488,   425,    43,
      68,    44,    45,   127,   283,   204,   205,   284
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     148,    97,   111,    97,   111,   118,   130,    32,   188,   158,
      57,   202,   272,   217,   181,   201,   113,   113,    46,   382,
     214,    48,  -113,    70,   124,   122,    49,   116,   117,    70,
      51,   113,    62,   142,     8,     9,    10,   134,   224,   135,
      60,    61,   126,  -113,    51,   125,    64,    65,    66,   206,
      67,   157,    97,   113,    69,    51,   148,   128,   185,   169,
     170,   129,   186,    50,   149,    70,    51,   120,    53,   247,
      51,   148,   250,   285,   382,    32,   143,   271,    51,   115,
     115,   113,    53,   113,   121,   131,   187,   184,   138,   190,
     182,    97,   111,   222,   115,   196,   217,   260,    47,   113,
     113,   289,   198,    52,   223,   134,   134,   135,   135,   113,
     301,   113,    63,    53,   144,    97,   115,    52,    97,   224,
     225,    97,   226,   207,   113,   177,    97,    53,    52,    97,
      97,    97,    97,    97,    97,   249,   171,   172,   329,    52,
      54,   272,   297,   314,   115,   179,   115,   186,   178,    53,
     354,   314,   308,    53,   195,   186,   317,   187,   322,   180,
     121,   241,   115,   115,   241,   334,   193,   139,   345,   340,
     220,   355,   115,   140,   115,   276,   221,   277,   150,   151,
     152,   198,   445,   113,   183,   457,   191,   115,   338,   134,
     467,   135,   262,   341,   339,    97,   192,   300,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   159,   481,
     482,   218,   393,   160,   161,   262,   185,   121,   394,   273,
     186,   372,   241,   274,   194,   311,   242,   381,   243,    97,
     111,   336,   163,   164,   316,   166,   167,   174,   175,   248,
     315,   121,   275,   153,   126,   195,   115,   154,  -301,   155,
      97,   111,   353,   290,   240,   241,   291,   200,   286,   287,
     213,   309,   310,   130,   241,   313,    97,   363,   416,   390,
     391,   401,   113,   302,   238,   227,   462,   241,   463,   241,
     262,   303,   381,   304,   246,   312,   316,   464,   241,   486,
     241,   454,   318,   337,   319,   320,   343,   335,   121,   346,
     347,   459,   195,   461,   323,   121,   370,   324,   348,    97,
     111,   388,   351,   469,   352,   307,   356,   270,   389,   366,
     195,   262,   369,   477,   478,   479,   262,   373,   444,   374,
     200,   416,   300,   379,   378,   115,   490,   383,   385,   466,
     386,   288,   392,   395,   493,   295,   396,   397,   400,   430,
     451,   452,   453,   195,   431,   432,    97,   111,   433,   113,
     434,   121,   435,   436,   437,   195,   440,   439,   441,   442,
     305,   449,   306,   446,   456,   465,   473,   484,   476,   492,
     241,   256,   427,   254,   253,   252,   255,   259,   480,   251,
     387,   215,   137,   257,   361,   197,   487,   487,   321,   365,
     344,   342,   327,   195,   458,   333,   489,   136,   258,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
     349,     0,   115,   350,     0,   402,     0,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,   200,     0,
       0,   362,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   367,     0,     0,   368,     0,     0,     0,
       0,   371,     0,     0,     0,   377,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   403,
     404,   405,     0,   406,   407,   408,   409,   410,   411,   412,
     413,     0,    83,     0,    84,     0,     0,     0,    85,     0,
       0,     0,     0,   398,     0,   343,   399,    86,    87,    88,
      89,    90,    91,   200,     0,     0,     0,     0,     0,     0,
     426,   414,     0,   428,   200,   402,     1,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,   403,
     404,   405,     0,   406,   407,   408,   409,   410,   411,   412,
     413,    26,    83,    27,    84,    28,    29,    30,    85,     0,
       0,     0,     0,     0,     0,   343,     0,    86,    87,    88,
      89,    90,    91,    74,     1,    75,    76,    77,    78,    79,
      80,   414,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    74,     0,    75,    76,
      77,    78,    79,    80,     0,    81,    82,     0,     1,    26,
      83,    27,    84,    28,    29,    30,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    74,     0,    75,    76,    77,    78,    79,    80,   414,
      81,    82,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,   357,    83,     0,    84,     0,     0,     0,    85,
       0,     0,     0,     0,     0,    27,     0,     0,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,   443,     0,     0,     0,     0,     0,    83,     0,
      84,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,    74,
       1,    75,    76,    77,    78,    79,    80,   414,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    75,    76,    77,    78,    79,    80,     0,
      81,    82,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   210,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,    83,    27,    84,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,    83,   120,
      84,     0,     0,     0,    85,     0,     0,     0,     0,   211,
       0,     0,     0,    86,   212,    88,    89,    90,    91,    74,
       0,    75,    76,    77,    78,    79,    80,     0,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,    75,    76,    77,    78,    79,    80,
     267,    81,    82,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,    83,   120,    84,     0,
       0,     0,    85,     0,     0,     0,     0,   268,     0,     0,
       0,    86,   269,    88,    89,    90,    91,     0,     0,    83,
     120,    84,     0,     0,     0,    85,     0,     0,     0,     0,
     293,     0,     0,     0,    86,   294,    88,    89,    90,    91,
      74,     0,    75,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    76,    77,    78,    79,
      80,   325,    81,    82,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   330,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,    83,   120,    84,
       0,     0,     0,    85,     0,     0,     0,     0,   326,     0,
       0,     0,    86,    87,    88,    89,    90,    91,     0,     0,
      83,   120,    84,     0,     0,     0,    85,     0,     0,     0,
       0,   331,     0,     0,     0,    86,   332,    88,    89,    90,
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
       0,     0,   276,     0,   277,   199,   380,    86,    87,    88,
      89,    90,    91,    74,     0,    75,    76,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    84,     0,     0,     0,    85,     0,     0,     0,
     276,     0,   277,   199,   429,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,    85,     0,     0,
       0,   276,     0,   277,   199,     0,    86,    87,    88,    89,
      90,    91,    83,     0,    84,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,   199,     0,    86,    87,    88,
      89,    90,    91,    74,     0,    75,    76,    77,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    80,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    84,     0,     0,     0,    85,   244,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    83,     0,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,   307,     0,    86,    87,    88,    89,
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
       0,    27,     0,    28,     0,    30,   314,   261,     0,     0,
     186,     0,     0,     0,     0,     0,    53,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,     0,
      30,   185,   261,     0,     0,   186,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   216,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   296,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,   328,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   364,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      85,    48,    48,    50,    50,    50,    59,     0,   114,    99,
      32,   127,   187,   132,    21,   126,    48,    49,     3,   338,
     129,    76,    78,     3,    78,    53,    76,    48,    49,     3,
       3,    63,     3,    80,    38,    39,    40,    63,   139,    63,
      33,    34,    98,    99,     3,    99,    39,    40,    41,     3,
       0,    98,    99,    85,    83,     3,   141,    76,    76,    16,
      17,    80,    80,    76,    85,     3,     3,    71,    86,   154,
       3,   156,   162,   208,   393,    68,    76,   186,     3,    48,
      49,   113,    86,   115,    53,    83,   114,   113,    98,   115,
      97,   138,   138,   138,    63,   123,   215,   182,    83,   131,
     132,   210,   124,    76,    84,   131,   132,   131,   132,   141,
      84,   143,    83,    86,    76,   162,    85,    76,   165,   220,
     141,   168,   143,    77,   156,    85,   173,    86,    76,   176,
     177,   178,   179,   180,   181,   156,    93,    94,   273,    76,
      99,   316,    79,    76,   113,    96,   115,    80,    95,    86,
      78,    76,   242,    86,   123,    80,   262,   185,   267,    20,
     129,    78,   131,   132,    78,   274,    78,    78,   284,   280,
      78,    99,   141,    84,   143,    80,    84,    82,    11,    12,
      13,   203,    99,   215,    77,    99,    77,   156,    78,   215,
     455,   215,   185,    98,    84,   242,    77,   219,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    86,   474,
     475,    99,    78,    91,    92,   208,    76,   186,    84,    76,
      80,   330,    78,    80,    77,    81,    77,   338,     3,   276,
     276,   276,    87,    88,   262,    14,    15,    18,    19,     3,
     262,   210,     8,    76,    98,   214,   215,    80,    83,    82,
     297,   297,   297,    81,    77,    78,    81,   126,    77,    78,
     129,    77,    78,   316,    78,    79,   313,   313,   384,    77,
      78,   382,   304,    77,    98,   144,    77,    78,    77,    78,
     273,    77,   393,    78,   153,    77,   314,    77,    78,    77,
      78,   438,    77,     3,    78,    77,    83,    77,   267,    77,
       3,   448,   271,   450,    81,   274,    77,    81,    81,   356,
     356,   356,    81,   460,    81,    83,    79,   186,    79,    81,
     289,   314,    81,   470,   471,   472,   319,    81,   413,    81,
     199,   447,   354,    81,    99,   304,   483,    84,    81,   455,
      81,   210,    79,    81,   491,   214,    81,    81,    81,    81,
     435,   436,   437,   322,    81,    79,   403,   403,   403,   391,
      79,   330,    76,    76,    76,   334,     3,    76,    99,    99,
     239,    79,   241,    84,    99,    62,    76,    60,    77,    99,
      78,   178,   391,   176,   173,   168,   177,   181,   473,   165,
     354,   131,    69,   179,   307,   124,   481,   482,   267,   319,
     283,   281,   271,   372,   447,   274,   482,    68,   180,    -1,
      -1,   280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     289,    -1,   391,   292,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,   307,    -1,
      -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,   325,    -1,    -1,    -1,
      -1,   330,    -1,    -1,    -1,   334,    -1,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,   372,    -1,    83,   375,    85,    86,    87,
      88,    89,    90,   382,    -1,    -1,    -1,    -1,    -1,    -1,
     389,    99,    -1,   392,   393,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,     3,     4,     5,     6,     7,     8,     9,
      10,    99,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     3,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,     4,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,     3,    -1,     5,     6,     7,     8,     9,    10,    99,
      12,    13,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    70,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,     3,
       4,     5,     6,     7,     8,     9,    10,    99,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
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
      53,    54,    55,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    32,    33,    34,    35,    36,    37,
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
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
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
      75,   134,   135,   138,   139,   140,   141,   148,   151,   152,
     153,   154,   172,   199,   201,   202,     3,    83,    76,    76,
      76,     3,    76,    86,    99,   136,   137,   155,   156,   158,
     135,   135,     3,    83,   135,   135,   135,     0,   200,    83,
       3,   103,   149,   150,     3,     5,     6,     7,     8,     9,
      10,    12,    13,    70,    72,    76,    85,    86,    87,    88,
      89,    90,   101,   102,   104,   105,   108,   110,   111,   112,
     113,   114,   116,   118,   120,   122,   124,   125,   126,   127,
     128,   129,   133,   139,   145,   152,   164,   164,   133,   155,
      71,   152,   158,   159,    78,    99,    98,   203,    76,    80,
     156,    83,   142,   143,   145,   172,   201,   149,    98,    78,
      84,    76,   110,    76,    76,   110,   129,   130,   132,   164,
      11,    12,    13,    76,    80,    82,    76,   110,   113,    86,
      91,    92,   115,    87,    88,   117,    14,    15,   119,    16,
      17,    93,    94,   121,    18,    19,   123,    85,    95,    96,
      20,    21,    97,    77,   145,    76,    80,   158,   165,   166,
     145,    77,    77,    78,    77,   152,   158,   137,   155,    83,
     130,   167,   134,   135,   205,   206,     3,    77,   157,   163,
      34,    81,    86,   130,   159,   142,    84,   143,    99,   144,
      78,    84,   133,    84,   150,   164,   164,   130,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    98,   131,
      77,    78,    77,     3,    77,   109,   130,   132,     3,   164,
     113,   114,   116,   118,   120,   122,   124,   125,   126,   127,
     132,    77,   135,   160,   161,   162,   165,    34,    81,    86,
     130,   159,   166,    76,    80,     8,    80,    82,   167,   168,
     169,   170,   171,   204,   207,   160,    77,    78,   130,   159,
      81,    81,    34,    81,    86,   130,    84,    79,   146,   147,
     155,    84,    77,    77,    78,   130,   130,    83,   113,    77,
      78,    81,    77,    79,    76,   155,   158,   165,    77,    78,
      77,   130,   159,    81,    81,    34,    81,   130,    77,   160,
      34,    81,    86,   130,   159,    77,   133,     3,    78,    84,
     167,    98,   171,    83,   178,   134,    77,     3,    81,   130,
     130,    81,    81,   133,    78,    99,    79,    58,   106,   107,
     164,   168,   130,   129,    56,   162,    81,   130,   130,    81,
      77,   130,   159,    81,    81,    34,    81,   130,    99,    81,
      84,   167,   169,    84,   179,    81,    81,   147,   133,    79,
      77,    78,    79,    78,    84,    81,    81,    81,   130,   130,
      81,   167,     3,    57,    58,    59,    61,    62,    63,    64,
      65,    66,    67,    68,    99,   132,   134,   173,   174,   178,
     180,   182,   183,   184,   189,   198,   130,   107,   130,    84,
      81,    81,    79,   133,    79,    76,    76,    76,   191,    76,
       3,    99,    99,    99,   132,    99,    84,   181,   175,    79,
     177,   132,   132,   132,   173,   192,    99,    99,   182,   173,
     176,   173,    77,    77,    77,    62,   134,   183,   194,   173,
     185,   186,   190,    76,   196,   195,    77,   173,   173,   173,
     132,   183,   183,   193,    60,   187,    77,   132,   197,   197,
     173,   188,    99,   173
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
     156,   156,   156,   156,   156,   156,   156,   157,   156,   156,
     156,   158,   158,   158,   158,   159,   159,   160,   160,   161,
     161,   162,   162,   162,   163,   163,   164,   164,   165,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   167,   167,   167,   168,   168,   168,   168,   169,
     170,   170,   171,   171,   172,   173,   173,   173,   173,   173,
     173,   175,   174,   176,   174,   177,   174,   178,   179,   178,
     180,   181,   180,   182,   182,   183,   183,   185,   184,   186,
     184,   187,   188,   187,   190,   189,   191,   189,   192,   193,
     189,   195,   194,   196,   194,   197,   197,   198,   198,   198,
     198,   198,   199,   200,   199,   201,   201,   203,   204,   202,
     205,   205,   206,   207,   206
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
       6,     5,     5,     6,     5,     4,     4,     0,     5,     3,
       4,     3,     2,     2,     1,     1,     2,     3,     1,     1,
       3,     2,     2,     1,     1,     3,     2,     1,     2,     1,
       1,     3,     2,     3,     5,     4,     5,     4,     3,     3,
       3,     4,     6,     5,     5,     6,     4,     4,     2,     3,
       3,     4,     3,     4,     1,     2,     1,     4,     3,     2,
       1,     2,     3,     2,     7,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     5,     0,     4,     2,     0,     4,
       1,     0,     3,     1,     1,     1,     2,     0,     7,     0,
       6,     0,     0,     3,     0,     6,     0,     8,     0,     0,
       7,     0,     4,     0,     4,     0,     1,     3,     2,     2,
       2,     3,     1,     0,     3,     1,     1,     0,     0,     6,
       0,     1,     1,     0,     3
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
#line 77 "C_grammar.y"
                {char *Prolog_name;
		 Prolog_name = find_symbol(ordinary_ids_scope_stack, (yyvsp[0].id))->Prolog_name;
		 size_t const size = strlen(Prolog_name) + 1;
		 (yyval.id) = (char*)malloc(size);
         strcpy_s((yyval.id), size, Prolog_name);
		 free((yyvsp[0].id));
		}
#line 2016 "C_grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 84 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2022 "C_grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 85 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2028 "C_grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 86 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "prim4");}
#line 2034 "C_grammar.tab.c"
    break;

  case 6: /* primary_expression: generic_selection  */
#line 87 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "generic_selection");}
#line 2040 "C_grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 91 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2046 "C_grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 92 "C_grammar.y"
                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2052 "C_grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 93 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2058 "C_grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 98 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2064 "C_grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 102 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2070 "C_grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 103 "C_grammar.y"
                                        {simple_str_lit_copy(&(yyval.id), "thisFunctionName");}
#line 2076 "C_grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 122 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2082 "C_grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 124 "C_grammar.y"
                {size_t const size = strlen("index(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "index(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2093 "C_grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 131 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s([])", (yyvsp[-2].id));
		 free((yyvsp[-2].id));
		}
#line 2103 "C_grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 137 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
		 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		}
#line 2114 "C_grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 144 "C_grammar.y"
                {size_t const size = strlen("select(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "select(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2125 "C_grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 151 "C_grammar.y"
                {size_t const size = strlen("struct_pointer(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "struct_pointer(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2136 "C_grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 158 "C_grammar.y"
                {size_t const size = strlen("postfix_inc_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "postfix_inc_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2146 "C_grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 164 "C_grammar.y"
                {size_t const size = strlen("postfix_dec_op()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "postfix_dec_op(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2156 "C_grammar.tab.c"
    break;

  case 26: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 170 "C_grammar.y"
                {size_t const size = strlen("compound_literal(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "compound_literal(%s, %s)", (yyvsp[-4].id), (yyvsp[-1].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 2167 "C_grammar.tab.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 177 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_compound_literal(, )") + strlen((yyvsp[-5].id)) + strlen((yyvsp[-2].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "trailing_comma_compound_literal(%s, %s)", (yyvsp[-5].id), (yyvsp[-2].id));
		 free((yyvsp[-5].id));
		 free((yyvsp[-2].id));
		}
#line 2178 "C_grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 186 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2184 "C_grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 188 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2195 "C_grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 197 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2201 "C_grammar.tab.c"
    break;

  case 31: /* unary_expression: unary_inc_dec unary_expression  */
#line 199 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2212 "C_grammar.tab.c"
    break;

  case 32: /* unary_expression: unary_operator cast_expression  */
#line 206 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2223 "C_grammar.tab.c"
    break;

  case 33: /* unary_expression: SIZEOF unary_expression  */
#line 213 "C_grammar.y"
                {size_t const size = strlen("size_of_exp()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "size_of_exp(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2233 "C_grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 219 "C_grammar.y"
                {size_t const size = strlen("size_of_type()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "size_of_type(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2243 "C_grammar.tab.c"
    break;

  case 35: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 225 "C_grammar.y"
                {size_t const size = strlen("align_of()") + strlen((yyvsp[-1].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "align_of(%s)", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2253 "C_grammar.tab.c"
    break;

  case 36: /* unary_inc_dec: INC_OP  */
#line 233 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_inc_op");}
#line 2259 "C_grammar.tab.c"
    break;

  case 37: /* unary_inc_dec: DEC_OP  */
#line 234 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "prefix_dec_op");}
#line 2265 "C_grammar.tab.c"
    break;

  case 38: /* unary_operator: '&'  */
#line 238 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "addr_of");}
#line 2271 "C_grammar.tab.c"
    break;

  case 39: /* unary_operator: '*'  */
#line 239 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "dereference_op");}
#line 2277 "C_grammar.tab.c"
    break;

  case 40: /* unary_operator: '+'  */
#line 240 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2283 "C_grammar.tab.c"
    break;

  case 41: /* unary_operator: '-'  */
#line 241 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2289 "C_grammar.tab.c"
    break;

  case 42: /* unary_operator: '~'  */
#line 242 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "one_comp_op");}
#line 2295 "C_grammar.tab.c"
    break;

  case 43: /* unary_operator: '!'  */
#line 243 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "not_op");}
#line 2301 "C_grammar.tab.c"
    break;

  case 44: /* cast_expression: unary_expression  */
#line 247 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2307 "C_grammar.tab.c"
    break;

  case 45: /* cast_expression: '(' type_name ')' cast_expression  */
#line 249 "C_grammar.y"
                {size_t const size = strlen("cast(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "cast(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2318 "C_grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: cast_expression  */
#line 258 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2324 "C_grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression multiplicative_expression_op cast_expression  */
#line 260 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2336 "C_grammar.tab.c"
    break;

  case 48: /* multiplicative_expression_op: '*'  */
#line 270 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "multiply_op");}
#line 2342 "C_grammar.tab.c"
    break;

  case 49: /* multiplicative_expression_op: '/'  */
#line 271 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "div_op");}
#line 2348 "C_grammar.tab.c"
    break;

  case 50: /* multiplicative_expression_op: '%'  */
#line 272 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "mod_op");}
#line 2354 "C_grammar.tab.c"
    break;

  case 51: /* additive_expression: multiplicative_expression  */
#line 276 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2360 "C_grammar.tab.c"
    break;

  case 52: /* additive_expression: additive_expression additive_expression_op multiplicative_expression  */
#line 278 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2372 "C_grammar.tab.c"
    break;

  case 53: /* additive_expression_op: '+'  */
#line 288 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "plus_op");}
#line 2378 "C_grammar.tab.c"
    break;

  case 54: /* additive_expression_op: '-'  */
#line 289 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "minus_op");}
#line 2384 "C_grammar.tab.c"
    break;

  case 55: /* shift_expression: additive_expression  */
#line 293 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2390 "C_grammar.tab.c"
    break;

  case 56: /* shift_expression: shift_expression shift_expression_op additive_expression  */
#line 295 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2402 "C_grammar.tab.c"
    break;

  case 57: /* shift_expression_op: LEFT_OP  */
#line 305 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "left_shift_op");}
#line 2408 "C_grammar.tab.c"
    break;

  case 58: /* shift_expression_op: RIGHT_OP  */
#line 306 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "right_shift_op");}
#line 2414 "C_grammar.tab.c"
    break;

  case 59: /* relational_expression: shift_expression  */
#line 310 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2420 "C_grammar.tab.c"
    break;

  case 60: /* relational_expression: relational_expression relational_expression_operator shift_expression  */
#line 312 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2432 "C_grammar.tab.c"
    break;

  case 61: /* relational_expression_operator: '<'  */
#line 322 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_op");}
#line 2438 "C_grammar.tab.c"
    break;

  case 62: /* relational_expression_operator: '>'  */
#line 323 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_op");}
#line 2444 "C_grammar.tab.c"
    break;

  case 63: /* relational_expression_operator: LE_OP  */
#line 324 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "less_or_eq_op");}
#line 2450 "C_grammar.tab.c"
    break;

  case 64: /* relational_expression_operator: GE_OP  */
#line 325 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "greater_or_eq_op");}
#line 2456 "C_grammar.tab.c"
    break;

  case 65: /* equality_expression: relational_expression  */
#line 330 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2462 "C_grammar.tab.c"
    break;

  case 66: /* equality_expression: equality_expression equality_expression_op relational_expression  */
#line 332 "C_grammar.y"
                {size_t const size = strlen("(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2474 "C_grammar.tab.c"
    break;

  case 67: /* equality_expression_op: EQ_OP  */
#line 342 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "equal_op");}
#line 2480 "C_grammar.tab.c"
    break;

  case 68: /* equality_expression_op: NE_OP  */
#line 343 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "not_equal_op");}
#line 2486 "C_grammar.tab.c"
    break;

  case 69: /* and_expression: equality_expression  */
#line 347 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2492 "C_grammar.tab.c"
    break;

  case 70: /* and_expression: and_expression '&' equality_expression  */
#line 349 "C_grammar.y"
                {size_t const size = strlen("bitw_and(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_and(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2503 "C_grammar.tab.c"
    break;

  case 71: /* exclusive_or_expression: and_expression  */
#line 358 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2509 "C_grammar.tab.c"
    break;

  case 72: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 360 "C_grammar.y"
                {size_t const size = strlen("bitw_excl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_excl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2520 "C_grammar.tab.c"
    break;

  case 73: /* inclusive_or_expression: exclusive_or_expression  */
#line 369 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2526 "C_grammar.tab.c"
    break;

  case 74: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 371 "C_grammar.y"
                {size_t const size = strlen("bitw_incl_or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "bitw_incl_or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2537 "C_grammar.tab.c"
    break;

  case 75: /* logical_and_expression: inclusive_or_expression  */
#line 380 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2543 "C_grammar.tab.c"
    break;

  case 76: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 382 "C_grammar.y"
                {size_t const size = strlen("and_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "and_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2554 "C_grammar.tab.c"
    break;

  case 77: /* logical_or_expression: logical_and_expression  */
#line 391 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2560 "C_grammar.tab.c"
    break;

  case 78: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 393 "C_grammar.y"
                {size_t const size = strlen("or_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "or_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2571 "C_grammar.tab.c"
    break;

  case 79: /* conditional_expression: logical_or_expression  */
#line 402 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2577 "C_grammar.tab.c"
    break;

  case 80: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 404 "C_grammar.y"
                {size_t const size = strlen("cond_exp(, , )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "cond_exp(%s, %s, %s)", (yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2589 "C_grammar.tab.c"
    break;

  case 81: /* assignment_expression: conditional_expression  */
#line 414 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2595 "C_grammar.tab.c"
    break;

  case 82: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 416 "C_grammar.y"
                {size_t const size = strlen("%s(%s, %s)") + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s(%s, %s)", (yyvsp[-1].id), (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2607 "C_grammar.tab.c"
    break;

  case 83: /* assignment_operator: '='  */
#line 426 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "assign");}
#line 2613 "C_grammar.tab.c"
    break;

  case 84: /* assignment_operator: MUL_ASSIGN  */
#line 427 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mul_assign");}
#line 2619 "C_grammar.tab.c"
    break;

  case 85: /* assignment_operator: DIV_ASSIGN  */
#line 428 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "div_assign");}
#line 2625 "C_grammar.tab.c"
    break;

  case 86: /* assignment_operator: MOD_ASSIGN  */
#line 429 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "mod_assign");}
#line 2631 "C_grammar.tab.c"
    break;

  case 87: /* assignment_operator: ADD_ASSIGN  */
#line 430 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "add_assign");}
#line 2637 "C_grammar.tab.c"
    break;

  case 88: /* assignment_operator: SUB_ASSIGN  */
#line 431 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "sub_assign");}
#line 2643 "C_grammar.tab.c"
    break;

  case 89: /* assignment_operator: LEFT_ASSIGN  */
#line 432 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "left_assign");}
#line 2649 "C_grammar.tab.c"
    break;

  case 90: /* assignment_operator: RIGHT_ASSIGN  */
#line 433 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "right_assign");}
#line 2655 "C_grammar.tab.c"
    break;

  case 91: /* assignment_operator: AND_ASSIGN  */
#line 434 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "and_assign");}
#line 2661 "C_grammar.tab.c"
    break;

  case 92: /* assignment_operator: XOR_ASSIGN  */
#line 435 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "xor_assign");}
#line 2667 "C_grammar.tab.c"
    break;

  case 93: /* assignment_operator: OR_ASSIGN  */
#line 436 "C_grammar.y"
                                {simple_str_lit_copy(&(yyval.id), "or_assign");}
#line 2673 "C_grammar.tab.c"
    break;

  case 94: /* expression: assignment_expression  */
#line 440 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2679 "C_grammar.tab.c"
    break;

  case 95: /* expression: expression ',' assignment_expression  */
#line 442 "C_grammar.y"
                {size_t const size = strlen("comma_op(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "comma_op(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
		 free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 2690 "C_grammar.tab.c"
    break;

  case 96: /* constant_expression: conditional_expression  */
#line 451 "C_grammar.y"
                                                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2696 "C_grammar.tab.c"
    break;

  case 97: /* declaration: declaration_specifiers ';'  */
#line 456 "C_grammar.y"
                {fprintf(pl_file, "\ndeclaration([%s])", (yyvsp[-1].id));
		 free((yyvsp[-1].id));
		}
#line 2704 "C_grammar.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 460 "C_grammar.y"
                {if (typedef_flag == 1) {	//we were processing typedef declarations
	    	typedef_flag = 0;
	   	 }
	     fprintf(pl_file, "\ndeclaration([%s], [%s])", (yyvsp[-2].id), (yyvsp[-1].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[-1].id));
	  }
#line 2716 "C_grammar.tab.c"
    break;

  case 99: /* declaration: static_assert_declaration  */
#line 468 "C_grammar.y"
                {fprintf(pl_file, "\n%s", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 2724 "C_grammar.tab.c"
    break;

  case 100: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 475 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2735 "C_grammar.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier  */
#line 481 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2741 "C_grammar.tab.c"
    break;

  case 102: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 483 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 2752 "C_grammar.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier  */
#line 489 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2758 "C_grammar.tab.c"
    break;

  case 104: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 491 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier declaration_specifiers"); }
#line 2764 "C_grammar.tab.c"
    break;

  case 105: /* declaration_specifiers: type_qualifier  */
#line 493 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "type_qualifier"); }
#line 2770 "C_grammar.tab.c"
    break;

  case 106: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 495 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier declaration_specifiers"); }
#line 2776 "C_grammar.tab.c"
    break;

  case 107: /* declaration_specifiers: function_specifier  */
#line 497 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "function_specifier"); }
#line 2782 "C_grammar.tab.c"
    break;

  case 108: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 499 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier declaration_specifiers"); }
#line 2788 "C_grammar.tab.c"
    break;

  case 109: /* declaration_specifiers: alignment_specifier  */
#line 501 "C_grammar.y"
{ simple_str_lit_copy(&(yyval.id), "alignment_specifier"); }
#line 2794 "C_grammar.tab.c"
    break;

  case 110: /* init_declarator_list: init_declarator  */
#line 505 "C_grammar.y"
                                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2800 "C_grammar.tab.c"
    break;

  case 111: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 507 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
	     free((yyvsp[0].id));
		}
#line 2811 "C_grammar.tab.c"
    break;

  case 112: /* init_declarator: declarator '=' initializer  */
#line 517 "C_grammar.y"
                {size_t const size = strlen("initialised(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	   	 sprintf_s((yyval.id), size, "initialised(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	   	 //free($3);
		 add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);	//i.e. only after initialisation
	  	}
#line 2823 "C_grammar.tab.c"
    break;

  case 113: /* init_declarator: declarator  */
#line 525 "C_grammar.y"
          {if (typedef_flag == 1) {	// we are parsing one typedef declaration
		 add_typedef_name((yyvsp[0].id));
	   }
	   simple_str_copy(&(yyval.id), (yyvsp[0].id));
	   add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);
	  }
#line 2834 "C_grammar.tab.c"
    break;

  case 114: /* storage_class_specifier: TYPEDEF  */
#line 535 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "typedef");
         typedef_flag = 1;
	    }
#line 2842 "C_grammar.tab.c"
    break;

  case 115: /* storage_class_specifier: EXTERN  */
#line 538 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "extern"); }
#line 2848 "C_grammar.tab.c"
    break;

  case 116: /* storage_class_specifier: STATIC  */
#line 539 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "static"); }
#line 2854 "C_grammar.tab.c"
    break;

  case 117: /* storage_class_specifier: THREAD_LOCAL  */
#line 540 "C_grammar.y"
                        { simple_str_lit_copy(&(yyval.id), "thread_local"); }
#line 2860 "C_grammar.tab.c"
    break;

  case 118: /* storage_class_specifier: AUTO  */
#line 541 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "auto"); }
#line 2866 "C_grammar.tab.c"
    break;

  case 119: /* storage_class_specifier: REGISTER  */
#line 542 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "register"); }
#line 2872 "C_grammar.tab.c"
    break;

  case 120: /* type_specifier: VOID  */
#line 546 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "void"); }
#line 2878 "C_grammar.tab.c"
    break;

  case 121: /* type_specifier: CHAR  */
#line 547 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "char"); }
#line 2884 "C_grammar.tab.c"
    break;

  case 122: /* type_specifier: SHORT  */
#line 548 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "short"); }
#line 2890 "C_grammar.tab.c"
    break;

  case 123: /* type_specifier: INT  */
#line 549 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "int"); }
#line 2896 "C_grammar.tab.c"
    break;

  case 124: /* type_specifier: LONG  */
#line 550 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "long"); }
#line 2902 "C_grammar.tab.c"
    break;

  case 125: /* type_specifier: FLOAT  */
#line 551 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "float"); }
#line 2908 "C_grammar.tab.c"
    break;

  case 126: /* type_specifier: DOUBLE  */
#line 552 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "double"); }
#line 2914 "C_grammar.tab.c"
    break;

  case 127: /* type_specifier: SIGNED  */
#line 553 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "signed"); }
#line 2920 "C_grammar.tab.c"
    break;

  case 128: /* type_specifier: UNSIGNED  */
#line 554 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "unsigned"); }
#line 2926 "C_grammar.tab.c"
    break;

  case 129: /* type_specifier: BOOL  */
#line 555 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "bool"); }
#line 2932 "C_grammar.tab.c"
    break;

  case 130: /* type_specifier: COMPLEX  */
#line 556 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "complex"); }
#line 2938 "C_grammar.tab.c"
    break;

  case 131: /* type_specifier: IMAGINARY  */
#line 557 "C_grammar.y"
                                                { simple_str_lit_copy(&(yyval.id), "imaginary"); }
#line 2944 "C_grammar.tab.c"
    break;

  case 132: /* type_specifier: atomic_type_specifier  */
#line 558 "C_grammar.y"
                                { simple_str_lit_copy(&(yyval.id), "atomic_type_specifier"); }
#line 2950 "C_grammar.tab.c"
    break;

  case 133: /* type_specifier: struct_or_union_specifier  */
#line 559 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2956 "C_grammar.tab.c"
    break;

  case 134: /* type_specifier: enum_specifier  */
#line 560 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2962 "C_grammar.tab.c"
    break;

  case 135: /* type_specifier: TYPEDEF_NAME  */
#line 561 "C_grammar.y"
                                        {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 2968 "C_grammar.tab.c"
    break;

  case 136: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 566 "C_grammar.y"
                {size_t const size = strlen("([])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s([%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
	     free((yyvsp[-1].id));
	    }
#line 2979 "C_grammar.tab.c"
    break;

  case 137: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 573 "C_grammar.y"
                {size_t const size = strlen("(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s(%s, [%s])", (yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
	    }
#line 2991 "C_grammar.tab.c"
    break;

  case 138: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 581 "C_grammar.y"
                {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3002 "C_grammar.tab.c"
    break;

  case 139: /* struct_or_union: STRUCT  */
#line 590 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "struct");}
#line 3008 "C_grammar.tab.c"
    break;

  case 140: /* struct_or_union: UNION  */
#line 591 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "union");}
#line 3014 "C_grammar.tab.c"
    break;

  case 141: /* struct_declaration_list: struct_declaration  */
#line 596 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3020 "C_grammar.tab.c"
    break;

  case 142: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 598 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
	     free((yyvsp[0].id));
	    }
#line 3031 "C_grammar.tab.c"
    break;

  case 143: /* struct_declaration: specifier_qualifier_list ';'  */
#line 608 "C_grammar.y"
                {size_t const size = strlen("struct_decl_anonymous()") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_decl_anonymous(%s)", (yyvsp[-1].id));
	   	 free((yyvsp[-1].id));
        }
#line 3041 "C_grammar.tab.c"
    break;

  case 144: /* $@1: %empty  */
#line 613 "C_grammar.y"
                                   {in_member_decl_flag = 1;}
#line 3047 "C_grammar.tab.c"
    break;

  case 145: /* struct_declaration: specifier_qualifier_list $@1 struct_declarator_list ';'  */
#line 614 "C_grammar.y"
                {in_member_decl_flag = 0;
		 size_t const size = strlen("struct_decl([], )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "struct_decl([%s], %s)", (yyvsp[-3].id), (yyvsp[-1].id));
	   	 free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3059 "C_grammar.tab.c"
    break;

  case 146: /* struct_declaration: static_assert_declaration  */
#line 622 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3065 "C_grammar.tab.c"
    break;

  case 147: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 627 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3076 "C_grammar.tab.c"
    break;

  case 148: /* specifier_qualifier_list: type_specifier  */
#line 634 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3082 "C_grammar.tab.c"
    break;

  case 149: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 636 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	   	 free((yyvsp[-1].id));
	     free((yyvsp[0].id));
        }
#line 3093 "C_grammar.tab.c"
    break;

  case 150: /* specifier_qualifier_list: type_qualifier  */
#line 643 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3099 "C_grammar.tab.c"
    break;

  case 151: /* struct_declarator_list: struct_declarator  */
#line 648 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3105 "C_grammar.tab.c"
    break;

  case 152: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 650 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3116 "C_grammar.tab.c"
    break;

  case 153: /* struct_declarator: ':' constant_expression  */
#line 660 "C_grammar.y"
                {size_t const size = strlen("anonymous_bit_field()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "anonymous_bit_field(%s)", (yyvsp[0].id));
	   	 free((yyvsp[0].id));
        }
#line 3126 "C_grammar.tab.c"
    break;

  case 154: /* struct_declarator: declarator ':' constant_expression  */
#line 666 "C_grammar.y"
                {size_t const size = strlen("bit_field(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "bit_field(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3137 "C_grammar.tab.c"
    break;

  case 155: /* struct_declarator: declarator  */
#line 673 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3143 "C_grammar.tab.c"
    break;

  case 156: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 678 "C_grammar.y"
                {size_t const size = strlen("anonymous_enum([])") + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "anonymous_enum([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
        }
#line 3153 "C_grammar.tab.c"
    break;

  case 157: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 684 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_anonymous_enum([])") + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "trailing_comma_anonymous_enum([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
        }
#line 3163 "C_grammar.tab.c"
    break;

  case 158: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 690 "C_grammar.y"
                {size_t const size = strlen("enum(, [])") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "enum(%s, [%s])", (yyvsp[-3].id), (yyvsp[-1].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
        }
#line 3174 "C_grammar.tab.c"
    break;

  case 159: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 697 "C_grammar.y"
                {size_t const size = strlen("trailing_comma_enum(, [])") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "trailing_comma_enum(%s, [%s])", (yyvsp[-4].id), (yyvsp[-2].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
        }
#line 3185 "C_grammar.tab.c"
    break;

  case 160: /* enum_specifier: ENUM IDENTIFIER  */
#line 704 "C_grammar.y"
                {size_t const size = strlen("forward_enum()") + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "forward_enum(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
        }
#line 3195 "C_grammar.tab.c"
    break;

  case 161: /* enumerator_list: enumerator  */
#line 713 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3201 "C_grammar.tab.c"
    break;

  case 162: /* enumerator_list: enumerator_list ',' enumerator  */
#line 715 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3212 "C_grammar.tab.c"
    break;

  case 163: /* enumerator: enumeration_constant '=' constant_expression  */
#line 725 "C_grammar.y"
                {size_t const size = strlen("init_enum(, )") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
       	 (yyval.id) = (char*)malloc(size);
         sprintf_s((yyval.id), size, "init_enum(%s, %s)", (yyvsp[-2].id), (yyvsp[0].id));
	   	 free((yyvsp[-2].id));
	     free((yyvsp[0].id));
        }
#line 3223 "C_grammar.tab.c"
    break;

  case 164: /* enumerator: enumeration_constant  */
#line 732 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3229 "C_grammar.tab.c"
    break;

  case 166: /* type_qualifier: CONST  */
#line 740 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "const");}
#line 3235 "C_grammar.tab.c"
    break;

  case 167: /* type_qualifier: RESTRICT  */
#line 741 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "restrict");}
#line 3241 "C_grammar.tab.c"
    break;

  case 168: /* type_qualifier: VOLATILE  */
#line 742 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "volatile");}
#line 3247 "C_grammar.tab.c"
    break;

  case 169: /* type_qualifier: ATOMIC  */
#line 743 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "atomic");}
#line 3253 "C_grammar.tab.c"
    break;

  case 170: /* function_specifier: INLINE  */
#line 747 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "inline");}
#line 3259 "C_grammar.tab.c"
    break;

  case 171: /* function_specifier: NORETURN  */
#line 748 "C_grammar.y"
                        {simple_str_lit_copy(&(yyval.id), "noreturn");}
#line 3265 "C_grammar.tab.c"
    break;

  case 174: /* declarator: pointer direct_declarator  */
#line 758 "C_grammar.y"
          {size_t const size = strlen("()") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
       (yyval.id) = (char*)malloc(size);
       sprintf_s((yyval.id), size, "%s(%s)", (yyvsp[-1].id), (yyvsp[0].id));
	   free((yyvsp[-1].id));
	   free((yyvsp[0].id));
      }
#line 3276 "C_grammar.tab.c"
    break;

  case 175: /* declarator: direct_declarator  */
#line 765 "C_grammar.y"
          {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3282 "C_grammar.tab.c"
    break;

  case 176: /* direct_declarator: IDENTIFIER  */
#line 770 "C_grammar.y"
                {id_counter++;
		 char id_counter_str[20];
		 sprintf_s(id_counter_str, 20, "%d", id_counter);
		 char Prolog_var_name[MAX_ID_LENGTH];
		 if (islower((yyvsp[0].id)[0])) {
			Prolog_var_name[0] = toupper((yyvsp[0].id)[0]);
			strcpy_s(&Prolog_var_name[1], MAX_ID_LENGTH-1, &(yyvsp[0].id)[1]);
		 } else {
			strcpy_s(Prolog_var_name, MAX_ID_LENGTH, "UC_");
			strcat_s(Prolog_var_name, MAX_ID_LENGTH, (yyvsp[0].id));
		 }
		 strcat_s(Prolog_var_name, MAX_ID_LENGTH, "_");
		 strcat_s(Prolog_var_name, MAX_ID_LENGTH, id_counter_str);
		 size_t const size = strlen(Prolog_var_name) + 1;
		 (yyval.id) = (char*)malloc(size);
		 strcpy_s((yyval.id), size, Prolog_var_name);
		 //ugly: keep declared identifer details to be pushed after possible initialisation
		 size_t const size1 = strlen((yyvsp[0].id)) + 1;
		 tmp_current_decl_id = (char*)malloc(size1);
		 strcpy_s(tmp_current_decl_id, size1, (yyvsp[0].id));		
		 size_t const size2 = strlen(Prolog_var_name) + 1;
		 tmp_current_decl_prolog_var = (char*)malloc(size2);
		 strcpy_s(tmp_current_decl_prolog_var, size2, Prolog_var_name);
		}
#line 3311 "C_grammar.tab.c"
    break;

  case 177: /* direct_declarator: '(' declarator ')'  */
#line 795 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D1");}
#line 3317 "C_grammar.tab.c"
    break;

  case 178: /* direct_declarator: direct_declarator '[' ']'  */
#line 797 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D2");}
#line 3323 "C_grammar.tab.c"
    break;

  case 179: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 799 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D3");}
#line 3329 "C_grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 801 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D4");}
#line 3335 "C_grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 803 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D5");}
#line 3341 "C_grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 805 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D6");}
#line 3347 "C_grammar.tab.c"
    break;

  case 183: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 807 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D7");}
#line 3353 "C_grammar.tab.c"
    break;

  case 184: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 809 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D8");}
#line 3359 "C_grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 811 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D9");}
#line 3365 "C_grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 813 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D10");}
#line 3371 "C_grammar.tab.c"
    break;

  case 187: /* $@2: %empty  */
#line 815 "C_grammar.y"
                {add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);	//for the function name
		 enter_scope(&ordinary_ids_scope_stack); 	//for parameters
		}
#line 3379 "C_grammar.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '(' $@2 parameter_type_list ')'  */
#line 819 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-4].id), (yyvsp[-1].id));
	     free((yyvsp[-4].id));
		 free((yyvsp[-1].id));
		}
#line 3390 "C_grammar.tab.c"
    break;

  case 189: /* direct_declarator: direct_declarator '(' ')'  */
#line 826 "C_grammar.y"
                {size_t const size = strlen("%s, []") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, []", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3400 "C_grammar.tab.c"
    break;

  case 190: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 832 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "D13");}
#line 3406 "C_grammar.tab.c"
    break;

  case 191: /* pointer: '*' type_qualifier_list pointer  */
#line 837 "C_grammar.y"
                {size_t const size = strlen("pointer???(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer???(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3417 "C_grammar.tab.c"
    break;

  case 192: /* pointer: '*' type_qualifier_list  */
#line 844 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3427 "C_grammar.tab.c"
    break;

  case 193: /* pointer: '*' pointer  */
#line 850 "C_grammar.y"
                {size_t const size = strlen("pointer()") + strlen((yyvsp[0].id)) + 1;
		 (yyval.id) = (char*)malloc(size);
		 sprintf_s((yyval.id), size, "pointer(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3437 "C_grammar.tab.c"
    break;

  case 194: /* pointer: '*'  */
#line 856 "C_grammar.y"
                {simple_str_lit_copy(&(yyval.id), "pointer");}
#line 3443 "C_grammar.tab.c"
    break;

  case 195: /* type_qualifier_list: type_qualifier  */
#line 861 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3449 "C_grammar.tab.c"
    break;

  case 196: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 863 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3460 "C_grammar.tab.c"
    break;

  case 197: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 873 "C_grammar.y"
                {size_t const size = strlen("variable_length_args()") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "variable_length_args(%s)", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3470 "C_grammar.tab.c"
    break;

  case 198: /* parameter_type_list: parameter_list  */
#line 879 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3476 "C_grammar.tab.c"
    break;

  case 199: /* parameter_list: parameter_declaration  */
#line 884 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3482 "C_grammar.tab.c"
    break;

  case 200: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 886 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3493 "C_grammar.tab.c"
    break;

  case 201: /* parameter_declaration: declaration_specifiers declarator  */
#line 896 "C_grammar.y"
                {size_t const size = strlen("param(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "param(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		 add_symbol(ordinary_ids_scope_stack, tmp_current_decl_id, tmp_current_decl_prolog_var);
		}
#line 3505 "C_grammar.tab.c"
    break;

  case 202: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 904 "C_grammar.y"
                {size_t const size = strlen("param_no_decl(%s, dummy_abstract_declarator)") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "param_no_decl(%s, dummy_abstract_declarator)", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		 //free($2);
		}
#line 3516 "C_grammar.tab.c"
    break;

  case 203: /* parameter_declaration: declaration_specifiers  */
#line 911 "C_grammar.y"
                {size_t const size = strlen("param_no_decl(%s, [])") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "param_no_decl(%s, [])", (yyvsp[0].id));
	     free((yyvsp[0].id));
		}
#line 3526 "C_grammar.tab.c"
    break;

  case 206: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 924 "C_grammar.y"
                                                        {simple_str_lit_copy(&(yyval.id), "typenamedummy1");}
#line 3532 "C_grammar.tab.c"
    break;

  case 207: /* type_name: specifier_qualifier_list  */
#line 925 "C_grammar.y"
                                                                                {simple_str_lit_copy(&(yyval.id), "typenamedummy2");}
#line 3538 "C_grammar.tab.c"
    break;

  case 232: /* initializer: '{' initializer_list '}'  */
#line 960 "C_grammar.y"
                {size_t const size = strlen("initializer([])") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "initializer([%s])", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3548 "C_grammar.tab.c"
    break;

  case 233: /* initializer: '{' initializer_list ',' '}'  */
#line 966 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "trailing_comma_initializer([%s])", (yyvsp[-2].id));
	     free((yyvsp[-2].id));
		}
#line 3558 "C_grammar.tab.c"
    break;

  case 234: /* initializer: assignment_expression  */
#line 972 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3564 "C_grammar.tab.c"
    break;

  case 235: /* initializer_list: designation initializer  */
#line 977 "C_grammar.y"
                {size_t const size = strlen("init(, )") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "init(%s, %s)", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3575 "C_grammar.tab.c"
    break;

  case 236: /* initializer_list: initializer  */
#line 984 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3581 "C_grammar.tab.c"
    break;

  case 237: /* initializer_list: initializer_list ',' designation initializer  */
#line 986 "C_grammar.y"
                {size_t const size = strlen(", init(, )") + strlen((yyvsp[-3].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, init(%s, %s)", (yyvsp[-3].id), (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-3].id));
		 free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3593 "C_grammar.tab.c"
    break;

  case 238: /* initializer_list: initializer_list ',' initializer  */
#line 994 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-2].id), (yyvsp[0].id));
	     free((yyvsp[-2].id));
		 free((yyvsp[0].id));
		}
#line 3604 "C_grammar.tab.c"
    break;

  case 239: /* designation: designator_list '='  */
#line 1004 "C_grammar.y"
                {size_t const size = strlen("[]") + strlen((yyvsp[-1].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "[%s]", (yyvsp[-1].id));
	     free((yyvsp[-1].id));
		}
#line 3614 "C_grammar.tab.c"
    break;

  case 240: /* designator_list: designator  */
#line 1013 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[0].id));}
#line 3620 "C_grammar.tab.c"
    break;

  case 241: /* designator_list: designator_list designator  */
#line 1015 "C_grammar.y"
                {size_t const size = strlen(", ") + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "%s, %s", (yyvsp[-1].id), (yyvsp[0].id));
	     free((yyvsp[-1].id));
		 free((yyvsp[0].id));
		}
#line 3631 "C_grammar.tab.c"
    break;

  case 242: /* designator: '[' constant_expression ']'  */
#line 1025 "C_grammar.y"
                {simple_str_copy(&(yyval.id), (yyvsp[-1].id));}
#line 3637 "C_grammar.tab.c"
    break;

  case 243: /* designator: '.' IDENTIFIER  */
#line 1027 "C_grammar.y"
                {size_t const size = strlen("select()") + strlen((yyvsp[0].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "select(%s)", (yyvsp[0].id));
		 free((yyvsp[0].id));
		}
#line 3647 "C_grammar.tab.c"
    break;

  case 244: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 1036 "C_grammar.y"
                {size_t const size = strlen("static_assert(, )") + strlen((yyvsp[-4].id)) + strlen((yyvsp[-2].id)) + 1;
	     (yyval.id) = (char*)malloc(size);
	     sprintf_s((yyval.id), size, "static_assert(%s, %s)", (yyvsp[-4].id), (yyvsp[-2].id));
		 free((yyvsp[-4].id));
		 free((yyvsp[-2].id));
		}
#line 3658 "C_grammar.tab.c"
    break;

  case 251: /* $@3: %empty  */
#line 1055 "C_grammar.y"
                {fprintf(pl_file, "label_stmt($1, "); 
		 free((yyvsp[-1].id));
		}
#line 3666 "C_grammar.tab.c"
    break;

  case 252: /* labeled_statement: IDENTIFIER ':' $@3 statement  */
#line 1059 "C_grammar.y"
                {fprintf(pl_file, ")");}
#line 3672 "C_grammar.tab.c"
    break;

  case 253: /* $@4: %empty  */
#line 1060 "C_grammar.y"
                                       {fprintf(pl_file, "case_stmt($2, "); free((yyvsp[-1].id));}
#line 3678 "C_grammar.tab.c"
    break;

  case 254: /* labeled_statement: CASE constant_expression ':' $@4 statement  */
#line 1060 "C_grammar.y"
                                                                                                 {fprintf(pl_file, ")");}
#line 3684 "C_grammar.tab.c"
    break;

  case 255: /* $@5: %empty  */
#line 1061 "C_grammar.y"
                      {fprintf(pl_file, "default_stmt(");}
#line 3690 "C_grammar.tab.c"
    break;

  case 256: /* labeled_statement: DEFAULT ':' $@5 statement  */
#line 1061 "C_grammar.y"
                                                                     {fprintf(pl_file, ")");}
#line 3696 "C_grammar.tab.c"
    break;

  case 257: /* compound_statement: '{' '}'  */
#line 1065 "C_grammar.y"
                  {fprintf(pl_file, "\ncmp_stmts([])");}
#line 3702 "C_grammar.tab.c"
    break;

  case 258: /* $@6: %empty  */
#line 1067 "C_grammar.y"
                {enter_scope(&ordinary_ids_scope_stack);
		 fprintf(pl_file, "\ncmp_stmts([");
		}
#line 3710 "C_grammar.tab.c"
    break;

  case 259: /* compound_statement: '{' $@6 block_item_list '}'  */
#line 1072 "C_grammar.y"
                {leave_scope(&ordinary_ids_scope_stack);
		 fprintf(pl_file, "\n])");
		}
#line 3718 "C_grammar.tab.c"
    break;

  case 261: /* $@7: %empty  */
#line 1079 "C_grammar.y"
                          {fprintf(pl_file, ", ");}
#line 3724 "C_grammar.tab.c"
    break;

  case 265: /* expression_statement: ';'  */
#line 1088 "C_grammar.y"
                                        {fprintf(pl_file, "stmt()");}
#line 3730 "C_grammar.tab.c"
    break;

  case 266: /* expression_statement: expression ';'  */
#line 1089 "C_grammar.y"
                                {fprintf(pl_file, "\nstmt(%s)", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3736 "C_grammar.tab.c"
    break;

  case 267: /* $@8: %empty  */
#line 1093 "C_grammar.y"
                                {fprintf(pl_file, "\nif_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3742 "C_grammar.tab.c"
    break;

  case 268: /* selection_statement: IF '(' expression ')' $@8 statement else_opt  */
#line 1093 "C_grammar.y"
                                                                                                       {fprintf(pl_file, ")");}
#line 3748 "C_grammar.tab.c"
    break;

  case 269: /* $@9: %empty  */
#line 1094 "C_grammar.y"
                                    {fprintf(pl_file, "\nswitch_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3754 "C_grammar.tab.c"
    break;

  case 270: /* selection_statement: SWITCH '(' expression ')' $@9 statement  */
#line 1094 "C_grammar.y"
                                                                                                        {fprintf(pl_file, ")");}
#line 3760 "C_grammar.tab.c"
    break;

  case 272: /* $@10: %empty  */
#line 1099 "C_grammar.y"
               {fprintf(pl_file, ", ");}
#line 3766 "C_grammar.tab.c"
    break;

  case 274: /* $@11: %empty  */
#line 1102 "C_grammar.y"
                                   {fprintf(pl_file, "\nwhile_stmt(%s, ", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3772 "C_grammar.tab.c"
    break;

  case 275: /* iteration_statement: WHILE '(' expression ')' $@11 statement  */
#line 1102 "C_grammar.y"
                                                                                                    {fprintf(pl_file, ")");}
#line 3778 "C_grammar.tab.c"
    break;

  case 276: /* $@12: %empty  */
#line 1103 "C_grammar.y"
             {fprintf(pl_file, "\ndo_while_stmt(");}
#line 3784 "C_grammar.tab.c"
    break;

  case 277: /* iteration_statement: DO $@12 statement WHILE '(' expression ')' ';'  */
#line 1103 "C_grammar.y"
                                                                                            {fprintf(pl_file, ", %s)", (yyvsp[-2].id)); free((yyvsp[-2].id));}
#line 3790 "C_grammar.tab.c"
    break;

  case 278: /* $@13: %empty  */
#line 1104 "C_grammar.y"
                  {fprintf(pl_file, "\nfor_stmt(");}
#line 3796 "C_grammar.tab.c"
    break;

  case 279: /* $@14: %empty  */
#line 1104 "C_grammar.y"
                                                                       {fprintf(pl_file, ", ");}
#line 3802 "C_grammar.tab.c"
    break;

  case 280: /* iteration_statement: FOR '(' $@13 for_stmt_type ')' $@14 statement  */
#line 1104 "C_grammar.y"
                                                                                                           {fprintf(pl_file, ")");}
#line 3808 "C_grammar.tab.c"
    break;

  case 281: /* $@15: %empty  */
#line 1108 "C_grammar.y"
                               {fprintf(pl_file, ", ");}
#line 3814 "C_grammar.tab.c"
    break;

  case 283: /* $@16: %empty  */
#line 1109 "C_grammar.y"
                      {fprintf(pl_file, ", ");}
#line 3820 "C_grammar.tab.c"
    break;

  case 286: /* expression_opt: expression  */
#line 1114 "C_grammar.y"
                     {fprintf(pl_file, ", %s", (yyvsp[0].id)); free((yyvsp[0].id));}
#line 3826 "C_grammar.tab.c"
    break;

  case 287: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1117 "C_grammar.y"
                                {fprintf(pl_file, "\ngoto_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3832 "C_grammar.tab.c"
    break;

  case 288: /* jump_statement: CONTINUE ';'  */
#line 1118 "C_grammar.y"
                                        {fprintf(pl_file, "\ncontinue_stmt\n");}
#line 3838 "C_grammar.tab.c"
    break;

  case 289: /* jump_statement: BREAK ';'  */
#line 1119 "C_grammar.y"
                                                {fprintf(pl_file, "\nbreak_stmt\n");}
#line 3844 "C_grammar.tab.c"
    break;

  case 290: /* jump_statement: RETURN ';'  */
#line 1120 "C_grammar.y"
                                        {fprintf(pl_file, "\nreturn_stmt\n");}
#line 3850 "C_grammar.tab.c"
    break;

  case 291: /* jump_statement: RETURN expression ';'  */
#line 1121 "C_grammar.y"
                                {fprintf(pl_file, "\nreturn_stmt(%s)\n", (yyvsp[-1].id)); free((yyvsp[-1].id));}
#line 3856 "C_grammar.tab.c"
    break;

  case 293: /* $@17: %empty  */
#line 1127 "C_grammar.y"
                           {fprintf(pl_file, ", \n");}
#line 3862 "C_grammar.tab.c"
    break;

  case 297: /* $@18: %empty  */
#line 1137 "C_grammar.y"
                {fprintf(pl_file, "function(%s, %s, [", (yyvsp[-1].id), (yyvsp[0].id)); 
		 free((yyvsp[-1].id)); 
		 free((yyvsp[0].id));
		}
#line 3871 "C_grammar.tab.c"
    break;

  case 298: /* $@19: %empty  */
#line 1142 "C_grammar.y"
                {fprintf(pl_file, "], ");}
#line 3877 "C_grammar.tab.c"
    break;

  case 299: /* function_definition: declaration_specifiers declarator $@18 declaration_list_opt $@19 compound_statement  */
#line 1144 "C_grammar.y"
                {fprintf(pl_file, ")");
		 leave_scope(&ordinary_ids_scope_stack);	//for the surrounding parameters
		}
#line 3885 "C_grammar.tab.c"
    break;

  case 303: /* $@20: %empty  */
#line 1156 "C_grammar.y"
                           {fprintf(pl_file, ", ");}
#line 3891 "C_grammar.tab.c"
    break;


#line 3895 "C_grammar.tab.c"

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

#line 1159 "C_grammar.y"

int main(int argc, char *argv[]) {				//argc is the total number of strings in the argv array
	char C_file_path[_MAX_PATH];				//directory where the C and .i files are
	char filename_no_ext[_MAX_PATH];
	char i_file_uri[_MAX_PATH];
	FILE *i_file;

	id_names = sb_init();		//initialise the buffer to hold all the Prolog id details
	if (id_names==NULL) {
		fprintf(stderr, "Sikraken parser fatal error: cannot initialise buffer id_names");
		my_exit(2);
	}

	strcpy_s(C_file_path, 3, ".\\");		//default path for input file is current directory, overwrite with -p on command line
	for (int i = 1; i <= argc - 1; i++) {	//processing command line arguments
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'h':
				printf("Usage: .\\sikraken_parser [OPTION]... [FILE]\nParse a C file to Prolog terms.\n\n-h\t Display help information\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\LilyParser -p\".\" get_sign \n\t.\\LilyParser get_sign \n\t.\\LilyParser -p\"C:/Parser/\" sign \n");
				my_exit(0);
			case 'p':	//path to the .i pre-processed input C file
				if (_access(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					my_exit(1);
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
		my_exit(EXIT_FAILURE);
	}
	yyin = i_file;	//set the input to the parser
	sprintf_s(pl_file_uri, _MAX_PATH, "%s%s.pl", C_file_path, filename_no_ext);
	if (fopen_s(&pl_file, pl_file_uri, "w") != 0) {
		fprintf(stderr, ".pl file could created for write at: %s\n", pl_file_uri);
		my_exit(EXIT_FAILURE);
	}
	fprintf(pl_file, "prolog_c([");			//opening predicate
	enter_scope(&ordinary_ids_scope_stack);	//creates the initial scope for ordinary ids namespace
	if (yyparse() != 0) {					//the parser is called
		fprintf(stderr, "Parsing failed.\n");
		my_exit(EXIT_FAILURE);
	}	
	leave_scope(&ordinary_ids_scope_stack);	//destroys the initial scope for ordinary ids namespace
	fprintf(pl_file, "],\nsikraken_xref([\n");				//append all the ids details
	fprintf(pl_file, id_names->str);
	fprintf(pl_file, "\n    ])\n).");
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

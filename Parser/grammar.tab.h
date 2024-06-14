/* A Bison parser, made by GNU Bison 3.5.0.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    FUNC_NAME = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPEDEF_NAME = 285,
    ENUMERATION_CONSTANT = 286,
    ALIGN = 287,
    TYPEDEF = 288,
    EXTERN = 289,
    STATIC = 290,
    AUTO = 291,
    REGISTER = 292,
    INLINE = 293,
    FORCEINLINE = 294,
    CONST = 295,
    RESTRICT = 296,
    VOLATILE = 297,
    BOOL = 298,
    CHAR = 299,
    SHORT = 300,
    INT = 301,
    LONG = 302,
    SIGNED = 303,
    UNSIGNED = 304,
    FLOAT = 305,
    DOUBLE = 306,
    VOID = 307,
    WCHAR_T = 308,
    __INT8 = 309,
    __INT16 = 310,
    __INT32 = 311,
    __INT64 = 312,
    __PTR32 = 313,
    __PTR64 = 314,
    __UNALIGNED = 315,
    COMPLEX = 316,
    IMAGINARY = 317,
    STRUCT = 318,
    UNION = 319,
    ENUM = 320,
    ELLIPSIS = 321,
    DECLSPEC = 322,
    CASE = 323,
    DEFAULT = 324,
    IF = 325,
    ELSE = 326,
    SWITCH = 327,
    WHILE = 328,
    DO = 329,
    FOR = 330,
    GOTO = 331,
    CONTINUE = 332,
    BREAK = 333,
    RETURN = 334,
    ALIGNAS = 335,
    ALIGNOF = 336,
    ATOMIC = 337,
    GENERIC = 338,
    NORETURN = 339,
    STATIC_ASSERT = 340,
    THREAD_LOCAL = 341,
    __CDECL = 342,
    __CLRCALL = 343,
    __STDCALL = 344,
    __FASTCALL = 345,
    __THISCALL = 346,
    __VECTORCALL = 347
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "grammar.y"

	char *id;

#line 154 "grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/****************************************************************************************************/
/* C11 lexer file from https://www.quut.com/c/ANSI-C-grammar-l-2011.html                            */
/* Flex documentation: https://westes.github.io/flex/manual/index.html                        */
/****************************************************************************************************/
/* definition section */
%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

%option yylineno

%{
#include <stdio.h>

#include "C_grammar.tab.h"

extern int is_typedef_name(char*);

void read_comment();
int differentiate_identifiers(char *);

%}

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]



%%
        /* rules section */
"/*"                                        { read_comment(); }
"//".*                                      { /* consume //-comment */ }

"auto"					{ return(AUTO); }
"break"					{ return(BREAK); }
"case"					{ return(CASE); }
"char"					{ return(CHAR); }
"const"					{ return(CONST); }
"continue"				{ return(CONTINUE); }
"default"				{ return(DEFAULT); }
"do"					{ return(DO); }
"double"				{ return(DOUBLE); }
"else"					{ return(ELSE); }
"enum"					{ return(ENUM); }
"extern"				{ return(EXTERN); }
"float"					{ return(FLOAT); }
"for"					{ return(FOR); }
"goto"					{ return(GOTO); }
"if"					{ return(IF); }
"inline"				{ return(INLINE); }
"int"					{ return(INT); }
"long"					{ return(LONG); }
"register"				{ return(REGISTER); }
"restrict"				{ return(RESTRICT); }
"return"				{ return(RETURN); }
"short"					{ return(SHORT); }
"signed"				{ return(SIGNED); }
"sizeof"				{ return(SIZEOF); }
"static"				{ return(STATIC); }
"struct"				{ return(STRUCT); }
"switch"				{ return(SWITCH); }
"typedef"				{ return(TYPEDEF); }
"union"					{ return(UNION); }
"unsigned"				{ return(UNSIGNED); }
"void"					{ return(VOID); }
"volatile"				{ return(VOLATILE); }
"while"					{ return(WHILE); }
"_Alignas"                              { return ALIGNAS; }
"_Alignof"                              { return ALIGNOF; }
"_Atomic"                               { return ATOMIC; }
"_Bool"                                 { return BOOL; }
"_Complex"                              { return COMPLEX; }
"_Generic"                              { return GENERIC; }
"_Imaginary"                            { return IMAGINARY; }
"_Noreturn"                             { return NORETURN; }
"_Static_assert"                        { return STATIC_ASSERT; }
"_Thread_local"                         { return THREAD_LOCAL; }
"__func__"                              { return FUNC_NAME; }

{L}{A}*                     {yylval.id = _strdup(yytext);
                              if (is_typedef_name(yylval.id)) {
                                  return TYPEDEF_NAME;
                              }
                              return IDENTIFIER;
                            }

{HP}{H}+{IS}?				{yylval.id = _strdup(yytext); return I_CONSTANT;}
{NZ}{D}*{IS}?				{yylval.id = _strdup(yytext); return I_CONSTANT;}
"0"{O}*{IS}?				{yylval.id = _strdup(yytext); return I_CONSTANT;}
{CP}?"'"([^'\\\n]|{ES})+"'"	{yylval.id = _strdup(yytext); return I_CONSTANT;}

{D}+{E}{FS}?				{yylval.id = _strdup(yytext); return F_CONSTANT;}
{D}*"."{D}+{E}?{FS}?		{yylval.id = _strdup(yytext); return F_CONSTANT;}
{D}+"."{E}?{FS}?			{yylval.id = _strdup(yytext); return F_CONSTANT;}
{HP}{H}+{P}{FS}?			{yylval.id = _strdup(yytext); return F_CONSTANT;}
{HP}{H}*"."{H}+{P}{FS}?		{yylval.id = _strdup(yytext); return F_CONSTANT;}
{HP}{H}+"."{P}{FS}?			{yylval.id = _strdup(yytext); return F_CONSTANT;}

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{if (yytext[0] == 'L') { //a wide string constant
                                        size_t const size = strlen("wide_string()") + strlen(yytext) - 1 + 1;
                                        yylval.id = (char*)malloc(size);
                                        sprintf_s(yylval.id, size, "wide_string(%s)", &yytext[1]);      //copy from yytext[1] to remove 'L' prefix 
                                     } else {
                                        yylval.id = _strdup(yytext);
                                     }
                                     return STRING_LITERAL;
                                    }

"..."					{ return ELLIPSIS; }
">>="					{ return RIGHT_ASSIGN; }
"<<="					{ return LEFT_ASSIGN; }
"+="					{ return ADD_ASSIGN; }
"-="					{ return SUB_ASSIGN; }
"*="					{ return MUL_ASSIGN; }
"/="					{ return DIV_ASSIGN; }
"%="					{ return MOD_ASSIGN; }
"&="					{ return AND_ASSIGN; }
"^="					{ return XOR_ASSIGN; }
"|="					{ return OR_ASSIGN; }
">>"					{ return RIGHT_OP; }
"<<"					{ return LEFT_OP; }
"++"					{ return INC_OP; }
"--"					{ return DEC_OP; }
"->"					{ return PTR_OP; }
"&&"					{ return AND_OP; }
"||"					{ return OR_OP; }
"<="					{ return LE_OP; }
">="					{ return GE_OP; }
"=="					{ return EQ_OP; }
"!="					{ return NE_OP; }
";"					{ return ';'; }
("{"|"<%")				{ return '{'; }
("}"|"%>")				{ return '}'; }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."					{ return '.'; }
"&"					{ return '&'; }
"!"					{ return '!'; }
"~"					{ return '~'; }
"-"					{ return '-'; }
"+"					{ return '+'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"<"					{ return '<'; }
">"					{ return '>'; }
"^"					{ return '^'; }
"|"					{ return '|'; }
"?"					{ return '?'; }

{WS}+					{ /* whitespace separates tokens */ }
.					{ /* discard bad characters */ }

%%
/* user code section */
int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

void read_comment() {
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
}
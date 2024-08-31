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
#ifdef _MSC_VER
    #define strdup_safe(char_ptr) _strdup(char_ptr)
#else
    #define strdup_safe(char_ptr) strdup(char_ptr)
#endif

#include <stdio.h>

#include "C_grammar.tab.h"

extern int is_typedef_name(char*);

void read_comment();
int differentiate_identifiers(char *);
char *tokenize_number_constants(char *, char *, char **);

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

"__attribute__"[ ]*\([ ]*\([^)]*\)[ ]*\)      { /* Pattern to ignore GCC __attribute__ */ }

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
"_Atomic"{WS}*"("                       { return ATOMIC_SPECIFIER; }
"_Atomic"                               { return ATOMIC; }
"_Bool"                                 { return BOOL; }
"_Complex"                              { return COMPLEX; }
"_Generic"                              { return GENERIC; }
"_Imaginary"                            { return IMAGINARY; }
"_Noreturn"                             { return NORETURN; }
"_Static_assert"                        { return STATIC_ASSERT; }
"_Thread_local"                         { return THREAD_LOCAL; }
"__func__"                              { return FUNC_NAME; }

{L}{A}*                     {yylval.id = strdup_safe(yytext);
                              if (is_typedef_name(yylval.id)) {
                                  return TYPEDEF_NAME;
                              }
                              return IDENTIFIER;
                            }

{HP}{H}+{IS}?				{tokenize_number_constants("hexadecimal", yytext, &yylval.id);
                             return I_CONSTANT;
                            }
{NZ}{D}*{IS}?				{tokenize_number_constants("", yytext, &yylval.id);
                             return I_CONSTANT;
                            }
                            
"0"{O}*{IS}?				{tokenize_number_constants("octal", yytext, &yylval.id);
                             return I_CONSTANT;
                            }
{CP}?"'"([^'\\\n]|{ES})+"'"	{yylval.id = strdup_safe(yytext); return I_CONSTANT;}   //single characters

{D}+{E}{FS}?				{yylval.id = strdup_safe(yytext); return F_CONSTANT;}
{D}*"."{D}+{E}?{FS}?		{yylval.id = strdup_safe(yytext); return F_CONSTANT;}
{D}+"."{E}?{FS}?			{yylval.id = strdup_safe(yytext); return F_CONSTANT;}
{HP}{H}+{P}{FS}?			{yylval.id = strdup_safe(yytext); return F_CONSTANT;}
{HP}{H}*"."{H}+{P}{FS}?		{yylval.id = strdup_safe(yytext); return F_CONSTANT;}
{HP}{H}+"."{P}{FS}?			{yylval.id = strdup_safe(yytext); return F_CONSTANT;}

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{if (yytext[0] == 'L') { //a wide string constant
                                        size_t const size = strlen("wide_string()") + strlen(yytext) - 1 + 1;
                                        yylval.id = (char*)malloc(size);
                                        sprintf_safe(yylval.id, size, "wide_string(%s)", &yytext[1]);      //copy from yytext[1] to remove 'L' prefix 
                                     } else {
                                        yylval.id = strdup_safe(yytext);
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

char * tokenize_number_constants(char * wrapper, char * input, char ** output) {
    int current = strlen(input)-1;
    int has_u = 0, has_l = 0, has_ll = 0;
    int has_suffix = 1;

    while (has_suffix && current >= 0) {
        switch (input[current]) {
            case 'u':
            case 'U':
                has_u = 1;
                break;
            case 'l':
            case 'L':
                if (current >0 && (input[current-1] == 'l' || input[current-1] == 'L')) {
                    has_ll = 1;
                    current--;  //skip the other 'l' or 'LL'
                }
                else has_l = 1;
                break;
            default:
                has_suffix = 0;  
        }
        if (has_suffix) current--;
    }
    int has_wrapper = strcmp(wrapper, "");
    //calculating the length of the result: length of the wrapper + 2 parentheses + length of the prefix, the suffix, the underscore, the parenthesis
    int size = (has_wrapper ? strlen(wrapper) + 2 : 0) + current+1 + 1 + has_u*strlen("unsigned") + has_l*strlen("long") + has_ll*strlen("long_long") + has_u*has_l + has_u*has_ll + (has_u || has_l || has_ll ? 2 : 0);
    *output = (char *)malloc(size);
    char format_string[100];
    if (has_wrapper) strcpy(format_string, "%s("); //starts with the integer type wrapper
    else strcpy(format_string, "");
    if (!has_u && !has_l && !has_ll)
        strcat(format_string, "%.*s");
    else if (has_u && !has_l && !has_ll) 
        strcat(format_string, "unsigned(%.*s)");
    else if (has_u && has_l && !has_ll) 
        strcat(format_string, "unsigned_long(%.*s)");
    else if (has_u && !has_l && has_ll) 
        strcat(format_string, "unsigned_long_long(%.*s)");
    else if (!has_u && has_l && !has_ll) 
        strcat(format_string, "long(%.*s)");
    else if (!has_u && !has_l && has_ll) 
        strcat(format_string, "long_long(%.*s)");
    if (has_wrapper) {
        strcat(format_string, ")"); //adds the wrapper end parenthesis
        snprintf(*output, size, format_string, wrapper, current + 1, input);
    } else {
        snprintf(*output, size, format_string, current + 1, input);
    }
}
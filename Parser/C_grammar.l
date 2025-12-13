/* flex */
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
#include <limits.h>

#include "C_grammar.tab.h"

void read_comment();
int convert_escape_sequence(const char *);
int differentiate_identifiers(char *);
void wrap_integer_constants(char *, char *, char **);
void wrap_floating_point_constants(int, char *, char **);
void add_missing_zero_after_decimal_point(char *, char **);
char *add_missing_zero_before_decimal_point(const char *, int);

int open_parens = 0;        //Declaration in the definitions section

//FSM Section
int read_a_comma_after_tag_name = 0; // set to 1 when a comma is read after a struct/union/enum tag name to avoid double processing in the parser
int FSM_in_PD_mode = 0;             // 1 if we are in the Parameter Declaration FSM mode, 0 if we are in the Variable Declaration FSM mode
int FSM_off = 0;                    // Do not trigger any transactions when lexing IDENTIFIERS because we are in an expression context 
                                    // and do not think that an IDENTIFIER is being declared and perhaps shadow a TYPEDEF_NAME (and wrongly return an IDENTIFIER where it is trule a TYPEDEF_NAME) 
                                    // but still lookup for typedef_names and shadowing identifiers to return IDENTIFIER or TYPEDEF_NAME correctly
                                    // switched off in grammar in only 4 contexts: array dimensions expressions, bit fields, initialisers, enumerator values
                                    // special consideration for GCC statement expressions can can appear within these contexts
                                    // leave the current FSM state unchanged
const char* FSM_mode_str(void);            // return a string representing the current FSM mode for debugging
void FSM_reset(void);               // reset the 2 FSMs to initial state
void FSM_start_statement(void);     // execute the transition in the 2 FSMs, triggered a token that can start a statement is read: in wait states the FSMs go to sink
void FSM_start_type_read(void);     // execute the transition in the 2 FSMs, triggered when a type specifier is read
void FSM_basic_type_read(void);     // execute the transition in the 2 FSMs, triggered when a basic type keyword is read
void FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(enum yytokentype);     // execute the transition in the 2 FSMs, triggered when a TYPEDEF_NAME, typeof(...), STRUCT, UNIUN or ENUM or IDENTIFIER is read
void FSM_COMMA_read(void);          // only when in state PD_DECIDE_PARAM_KIND and a comma is read, we transition to PD_UNNAMED_PARAMETERS

//FSM for Shadow Var Declarations
typedef enum {VD_NONE, VD_WAIT_VAR_TYPE, VD_NOT_VAR_DECL, VD_VAR_DECL} VD_state_t;
VD_state_t VD_state = VD_NONE;

//FSM to Shadow Parameter Declarations
typedef enum {PD_NONE, PD_WAIT_PARAM_TYPE, PD_NOT_PARAM_DECL, PD_DECIDE_PARAM_KIND, PD_UNNAMED_PARAMETERS, PD_WAIT_NAMED_PARAM_TYPE, PD_PARAM_DECL} PD_state_t;
PD_state_t PD_state = PD_NONE;

extern const char *const yytname[];  // to access token names
const char* token_name(int);

int yycolumn = 1;

#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
%}

%x ASM_QUALIFIER
%x ATTRIBUTE

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z$_]
A   [a-zA-Z$_0-9]
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
"#pragma".*                                 { /* Ignore the entire line after `#pragma` */ }
"__extension__"                             { /* Ignoring GCC keyword __extension__ that disables compiler warnings about non-compliant features */ }
"__asm__"[ ]*                               { BEGIN(ASM_QUALIFIER); /* New state for consuming qualifiers in asm constructs */ }
"__asm"[ ]*                                 { BEGIN(ASM_QUALIFIER); /* New state for consuming qualifiers in asm constructs */ }
"asm"[ ]*                                   { BEGIN(ASM_QUALIFIER); /* New state for consuming qualifiers in asm constructs */ }
<ASM_QUALIFIER>"volatile"[ ]* |
<ASM_QUALIFIER>"inline"[ ]* |
<ASM_QUALIFIER>"__inline__"[ ]*             { /* Consume the qualifier and stay in the state to check for more, or transition */
                                              // No return statement; the lexer consumes the text.
                                            }
<ASM_QUALIFIER>\([ ]*                       { // Once the opening parenthesis is seen, start counting
                                              open_parens = 1;
                                              BEGIN(ATTRIBUTE);
                                            }
"__attribute__"[ ]*\([ ]*\(                 { /* Ignoring all GCC __attribute__ at our peril obviously */ 
                                             open_parens = 2;   //Start with the initial two opening parentheses
                                             BEGIN(ATTRIBUTE);  //Enter the ATTRIBUTE start condition to read everything until the final 2 closing parenthesis
                                            }
<ATTRIBUTE>. {                  //use this because flex regular expressions cannot match matching inner parentheses as in __attribute__ ((__nonnull__ (1, 2))) 
    if (yytext[0] == '(') { 
        open_parens++;          //Increment for each additional opening parenthesis
    } 
    else if (yytext[0] == ')') { 
        open_parens--;          //Decrement for each closing parenthesis
        if (open_parens == 0) {
            BEGIN(INITIAL);     //Exit ATTRIBUTE mode after the matched parentheses are balanced
        }
    }
    /* Otherwise, continue reading characters in ATTRIBUTE mode */
}
<ATTRIBUTE><<EOF>> { /* Handle unexpected EOF */
    fprintf(stderr, "Error: Unclosed __attribute__(( found.\n");
    exit(LEXING_FAILURE);
}
"auto"					{ FSM_basic_type_read(); return(AUTO); }
"break"					{ FSM_start_statement(); return(BREAK); }
"case"					{ FSM_start_statement(); return(CASE); }
"char"					{ FSM_basic_type_read(); return(CHAR); }
"const"					{ FSM_start_type_read(); return(CONST); }
"__const"				{ FSM_start_type_read(); return(CONST); }       //GCC version of CONST
"continue"				{ FSM_start_statement(); return(CONTINUE); }
"default"				{ FSM_start_statement(); return(DEFAULT); }
"do"					{ FSM_start_statement(); return(DO); }
"double"				{ FSM_basic_type_read(); return(DOUBLE); }
"else"					{ return(ELSE); }
"enum"					{ FSM_start_type_read(); return(ENUM); }
"extern"				{ FSM_start_type_read(); return(EXTERN); }
"float"					{ FSM_basic_type_read(); return(FLOAT); }
"for"					{ FSM_start_statement(); return(FOR); }
"goto"					{ FSM_start_statement(); in_label_namespace = 1; return(GOTO); } //special namespace for labels GOTO
"if"					{ FSM_start_statement(); return(IF); }
"inline"				{ FSM_start_type_read(); return(INLINE); }
"__inline"				{ FSM_start_type_read(); return(INLINE); }     //GCC version of INLINE
"int"					{ FSM_basic_type_read(); return(INT); }
"long"					{ FSM_basic_type_read(); return(LONG); }
"register"				{ FSM_start_type_read(); return(REGISTER); }
"restrict"				{ FSM_start_type_read(); return(RESTRICT); }
"__restrict"            { FSM_start_type_read(); return(RESTRICT); }   //GCC version of RESTRICT
"return"				{ FSM_start_statement(); return(RETURN); }
"short"					{ FSM_basic_type_read(); return(SHORT); }
"signed"				{ FSM_basic_type_read(); return(SIGNED); }  //signed on its own is allowed, so it is a basic type
"__signed__"			{ FSM_basic_type_read(); return(SIGNED); }  //GCC version of SIGNED
"sizeof"				{ FSM_start_statement(); return(SIZEOF); }
"static"				{ FSM_start_type_read(); return(STATIC); }
"struct"				{ FSM_start_type_read(); return(STRUCT); }
"switch"				{ FSM_start_statement(); return(SWITCH); }
"typedef"				{ FSM_start_type_read(); return(TYPEDEF); }
"union"					{ FSM_start_type_read(); return(UNION); }
"unsigned"				{ FSM_basic_type_read(); return(UNSIGNED); }    //unsigned on its own is allowed, so it is a basic type
"void"					{ FSM_basic_type_read(); return(VOID); }
"volatile"				{ FSM_start_type_read(); return(VOLATILE); }
"__volatile__"			{ FSM_start_type_read(); return(VOLATILE); }   //GCC version of VOLATILE
"while"					{ FSM_start_statement(); return(WHILE); }
"__int128"              { FSM_basic_type_read(); return(INT128); }     //GCC builtin 128-bit integer type
"_Float32"              { FSM_basic_type_read(); return(FLOAT); }      //GCC builtin 32-bit floating-point type
"_Float64"              { FSM_basic_type_read(); return(DOUBLE); }     //GCC builtin 64-bit floating-point type
"__float128"            { FSM_basic_type_read(); return(FLOAT128); }   //GCC builtin 128-bit floating-point type
"_Float128"             { FSM_basic_type_read(); return(FLOAT128); }   //GCC builtin 128-bit floating-point type
"__builtin_offsetof"    { FSM_start_statement(); return(OFFSETOF);}                            //GCC builtin function: first argument is a type_name second a member/identifier
"__builtin_types_compatible_p"    { FSM_start_statement(); return(TYPESCOMPATIBLEP);}    //GCC builtin function: int __builtin_types_compatible_p(type1, type2)
"__builtin_va_arg"      { FSM_start_statement(); return(BUILTIN_VA_ARG); }                      //GCC builtin function: requires-types/member/identifier as arguments
"__builtin_va_list"     { FSM_basic_type_read(); return(VA_LIST); }    //GCC builtin type: variable argument list
"_Alignas"              { FSM_start_type_read(); return ALIGNAS; }     //a type specifier e.g.: _Alignas(type) or _Alignas(constant-expression)
"_Alignof"              { FSM_start_statement(); return ALIGNOF; }
"__alignof__"           { FSM_start_statement(); return ALIGNOF; }      //GCC version of ALIGNOF e.g.: __alignof__(type)
"_Atomic"{WS}*"("       { FSM_start_type_read(); return ATOMIC_SPECIFIER; } //a type specifier
"_Atomic"               { FSM_start_type_read(); return ATOMIC; }  
"_Bool"                 { FSM_basic_type_read(); return BOOL; }
"_Complex"              { FSM_basic_type_read(); return COMPLEX; }
"_Generic"              { FSM_start_type_read(); return GENERIC; }
"_Imaginary"            { FSM_basic_type_read(); return IMAGINARY; }
"_Noreturn"             { FSM_start_type_read(); return NORETURN; }
"_Static_assert"        { FSM_start_statement(); return STATIC_ASSERT; }
"_Thread_local"         { FSM_start_type_read(); return THREAD_LOCAL; }
"__thread"              { FSM_start_type_read(); return THREAD_LOCAL; }
"__PRETTY_FUNCTION__"   { FSM_start_statement(); return FUNC_NAME; }   //__PRETTY_FUNCTION__ is a GCC extension: an enhanced version of __func__; which we ignore 
"__func__"              { FSM_start_statement(); return FUNC_NAME; }
"typeof_unqual"         { FSM_start_type_read(); return TYPEOF_UNQUAL; }   //C23 and GCC extension
"__typeof_unqual__"     { FSM_start_type_read(); return TYPEOF_UNQUAL; }   //C23 and GCC extension
"typeof"                { FSM_start_type_read(); return TYPEOF; }   //C23 and GCC extension
"__typeof__"            { FSM_start_type_read(); return TYPEOF; }   //GCC extension

{L}{A}*                     {size_t const size = strlen(yytext) + 1;
                             yylval.id = (char*)malloc(size);
                             int i = 0;
                             for (; yytext[i] != '\0'; i++) {
                                if (yytext[i] == '$') {
                                    yylval.id[i] = 'Z';         //replace all '$' in C identifers (allowed extension) with the character 'Z' because $ is not allowed in Prolog var names: this is unsound when another identifier already has this name e.g. $1 and Z1 will clash
                                } else {
                                    yylval.id[i] = yytext[i];
                                }
                             }
                             yylval.id[i] = '\0';
                             if (in_tag_declaration || 0 || in_label_namespace) { // these contexts never treat ids as types: no point checking
                                if (debugMode) printf("Lexer FSM: bypassing typedef_name check in mode %s: id: %s is a %s\n", FSM_mode_str(), yylval.id, (in_tag_declaration ? "tag" : (in_member_namespace ? "member" : "label")));
                                return IDENTIFIER; 
                             }
                             int id_status = is_typedef_name(yylval.id);                            
                             if (debugMode) { 
                                printf("Lexer FSM: checking id: %s with status %d with FSM %s in mode %s %s\n", yylval.id, id_status, (FSM_off ? "OFF" : "ON"), FSM_mode_str(), (in_member_namespace ? "(in member namespace)" : ""));
                                fflush(stdout);
                             }
                             if (FSM_off) return (id_status == 1 ? TYPEDEF_NAME : IDENTIFIER);   //when FSM is off, we do not track declaration contexts, but we still differentiate typedef names from identifiers
                             if (id_status == 1) {  // a typedef name
                                if (FSM_in_PD_mode) {
                                    if (PD_state == PD_DECIDE_PARAM_KIND || PD_state == PD_PARAM_DECL) {
                                        add_typedef_id(current_scope, yylval.id, 2);   //2 indicates that it is a SHADOWING IDENTIFIER
                                        if (debugMode) printf("Lexer Debug: declared the SHADOWING PARAMETER of a typedef_name: %s on line %d\n", yylval.id, yylineno);
                                        FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(IDENTIFIER);
                                        return IDENTIFIER;                    
                                    } else {
                                        FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(TYPEDEF_NAME);
                                        return TYPEDEF_NAME;
                                    }
                                } else {    
                                    if (VD_state == VD_VAR_DECL) {
                                        FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(IDENTIFIER);
                                        if (in_member_namespace) return IDENTIFIER;     //members cannot shadow typedef names: they are in a different namespace
                                        else {add_typedef_id(current_scope, yylval.id, 2);    //2 indicates that it is a SHADOWING IDENTIFIER
                                            if (debugMode) printf("Lexer Debug: declared the SHADOWING IDENTIFIER of a typedef_name: %s on line %d\n", yylval.id, yylineno);
                                            return IDENTIFIER;
                                        }
                                    } else if (VD_state == VD_NOT_VAR_DECL) {
                                        if (in_member_namespace) return IDENTIFIER;
                                        return TYPEDEF_NAME;
                                    }
                                    else {
                                        FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(TYPEDEF_NAME);
                                        return TYPEDEF_NAME;
                                    }
                                }
                             }
                             FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(IDENTIFIER);
                             return IDENTIFIER;
                            }

{HP}{H}+{IS}?				{FSM_start_statement();
                             wrap_integer_constants("16'", &yytext[2], &yylval.id);     //hexadecimal integer
                             return I_CONSTANT;
                            }
{NZ}{D}*{IS}?				{FSM_start_statement();
                             wrap_integer_constants("", yytext, &yylval.id);            //decimal integer
                             return I_CONSTANT;
                            }
                            
"0"{O}*{IS}?				{FSM_start_statement();
                             if (isdigit(yytext[1])) wrap_integer_constants("8'", &yytext[1], &yylval.id);  //octal integer 
                             else {     //the second char after 0 is not a digit (it's /0, ofr an IS (u|U)(l|L|ll|LL) char), so it's just the constant 0, rather than a true octal 
                                    yylval.id = (char*)malloc(7);
                                    strcpy(yylval.id, "int(0)");    
                             }
                             return I_CONSTANT;
                            }
{CP}?"'"([^'\\\n]|{ES})+"'"	{//single char 
                             FSM_start_statement();
                             char *content = yytext + (yytext[0] == '\'' ? 1 : 2);  //Skip prefix and opening quote
                             content[strlen(content) - 1] = '\0';                   //Remove closing quote
                             int ascii;
                             if (content[0] == '\\') {                              //it's an escape sequence
                                    ascii = convert_escape_sequence(content);
                             } else {
                                    ascii = (int)content[0];
                             }
                             yylval.id = (char*)malloc(10);
                             sprintf(yylval.id, "int(%d)", ascii);
                             return I_CONSTANT;
                            }       
{D}+{E}{FS}?				{FSM_start_statement();
                             wrap_floating_point_constants(0, yytext, &yylval.id);     //Decimal floating-point constants with an exponent.
                             return F_CONSTANT;
                            }
{D}*"."{D}+{E}?{FS}?		{FSM_start_statement();
                             char *modified_float_literal = add_missing_zero_before_decimal_point(yytext, yyleng);
                             wrap_floating_point_constants(0, modified_float_literal, &yylval.id);     //Decimal floating-point constants with a fractional part.
                             return F_CONSTANT;
                            }
{D}+"."{E}?{FS}?			{FSM_start_statement();
                             char* added_0;
                             add_missing_zero_after_decimal_point(yytext, &added_0);
                             wrap_floating_point_constants(0, added_0, &yylval.id);            //Decimal floating-point constants with a fractional part.
                             return F_CONSTANT;
                            }
{HP}{H}+{P}{FS}?			{FSM_start_statement();
                             wrap_floating_point_constants(1, yytext, &yylval.id);  //Hexadecimal floating-point constants: will fail parser in ECLiPSe
                             return F_CONSTANT;
                            }
{HP}{H}*"."{H}+{P}{FS}?		{FSM_start_statement();
                             wrap_floating_point_constants(1, yytext, &yylval.id);  //Hexadecimal floating-point constants with a fractional part.: will fail parser in ECLiPSe
                             return F_CONSTANT;
                            }
{HP}{H}+"."{P}{FS}?			{FSM_start_statement();
                             char* added_0;
                             add_missing_zero_after_decimal_point(yytext, &added_0);
                             wrap_floating_point_constants(1, added_0, &yylval.id); //Hexadecimal floating-point constants with digits before the decimal point, but none after. : will fail parser in ECLiPSe
                             return F_CONSTANT;
                            }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{FSM_start_statement();
                                     if (yytext[0] == 'L') { //a wide string constant
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
"++"					{ FSM_start_statement(); return INC_OP; }
"--"					{ FSM_start_statement(); return DEC_OP; }
"->"					{ return PTR_OP; }
"&&"					{ return AND_OP; }
"||"					{ return OR_OP; }
"<="					{ return LE_OP; }
">="					{ return GE_OP; }
"=="					{ return EQ_OP; }
"!="					{ return NE_OP; }
";"					    { return ';'; }
("{"|"<%")				{ return '{'; }
("}"|"%>")				{ return '}'; }
","					    { FSM_COMMA_read(); return ','; }
":"					    { return ':'; }
"="					    { return '='; }
"("					    { FSM_start_statement(); return '('; }
")"					    { return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."					    { return '.'; }
"&"					    { FSM_start_statement(); return '&'; }
"!"					    { FSM_start_statement(); return '!'; }
"~"					    { FSM_start_statement(); return '~'; }
"-"					    { FSM_start_statement(); return '-'; }
"+"					    { FSM_start_statement(); return '+'; }
"*"					    { FSM_start_statement(); return '*'; }
"/"					    { return '/'; }
"%"					    { return '%'; }
"<"					    { return '<'; }
">"					    { return '>'; }
"^"					    { return '^'; }
"|"					    { return '|'; }
"?"					    { return '?'; }
{WS}+				    { for (int i = 0; i < yyleng; ++i) {    //handling white space for column counting
                            switch (yytext[i]) {
                                case ' ':  yycolumn += 1; break;
                                case '\v': /* treat like a single column advance */
                                case '\f': yycolumn += 1; break;
                                case '\t': {
                                    const int tabstop = 2; /* pick your tab width */
                                    int advance = tabstop - ((yycolumn - 1) % tabstop);
                                    yycolumn += advance;
                                    break;
                                }
                                case '\n': yycolumn = 1; break;
                                default: yycolumn += 1; break;
                            }
                         }
                        }
.					    { /* discard bad characters */ }

%%
/* user code section */
const char *FSM_mode_str(void) {
    if (FSM_in_PD_mode) {
        if (PD_state == PD_NONE) return "PD_NONE";
        else if (PD_state == PD_WAIT_PARAM_TYPE) return "PD_WAIT_PARAM_TYPE";
        else if (PD_state == PD_NOT_PARAM_DECL) return "PD_NOT_PARAM_DECL";
        else if (PD_state == PD_DECIDE_PARAM_KIND) return "PD_DECIDE_PARAM_KIND";
        else if (PD_state == PD_UNNAMED_PARAMETERS) return "PD_UNNAMED_PARAMETERS";
        else if (PD_state == PD_WAIT_NAMED_PARAM_TYPE) return "PD_WAIT_NAMED_PARAM_TYPE";
        else if (PD_state == PD_PARAM_DECL) return "PD_PARAM_DECL";
        else return "UNKNOWN_PD_STATE";
    } else {
        if (VD_state == VD_NONE) return "VD_NONE";
        else if (VD_state == VD_WAIT_VAR_TYPE) return "VD_WAIT_VAR_TYPE";
        else if (VD_state == VD_NOT_VAR_DECL) return "VD_NOT_VAR_DECL";
        else if (VD_state == VD_VAR_DECL) return "VD_VAR_DECL";
        else return "UNKNOWN_VD_STATE";
    }
}
void FSM_reset(void) {
    PD_state = PD_NONE;
    VD_state = VD_NONE;
}
void FSM_start_statement(void) {
    if (FSM_off) return;
    if (FSM_in_PD_mode) {
        if (PD_state == PD_NONE) PD_state = PD_NOT_PARAM_DECL;
    } else if (VD_state == VD_NONE) VD_state = VD_NOT_VAR_DECL;
}
void FSM_start_type_read(void) {
    if (FSM_off) return;
    if (FSM_in_PD_mode) {
        if (PD_state == PD_NONE) PD_state = PD_WAIT_PARAM_TYPE;
    } else if (VD_state == VD_NONE) VD_state = VD_WAIT_VAR_TYPE;
}
void FSM_basic_type_read(void) {
    if (FSM_off) return;
    if (FSM_in_PD_mode) {
        if (PD_state == PD_WAIT_PARAM_TYPE || PD_state == PD_NONE) PD_state = PD_DECIDE_PARAM_KIND;
        else if (PD_state == PD_WAIT_NAMED_PARAM_TYPE) PD_state = PD_PARAM_DECL;
    } else if (VD_state == VD_WAIT_VAR_TYPE || VD_state == VD_NONE) VD_state = VD_VAR_DECL;
}

//Called above when a TYPEDEF_NAME or IDENTIFIER is read, also called in the grammar when STRUCT, UNION, ENUM, TYPEOF or TYPEOF_UNQUAL is read
void FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(enum yytokentype token) {
    if (FSM_off) return;
    if (FSM_in_PD_mode) {
        if (PD_state == PD_NONE) {
            if (token == IDENTIFIER) PD_state = PD_NOT_PARAM_DECL;
            else PD_state = PD_DECIDE_PARAM_KIND;
        }
        else if (PD_state == PD_WAIT_PARAM_TYPE) PD_state = PD_DECIDE_PARAM_KIND;
        else if (PD_state == PD_DECIDE_PARAM_KIND) PD_state = PD_WAIT_NAMED_PARAM_TYPE;
        else if (PD_state == PD_WAIT_NAMED_PARAM_TYPE) PD_state = PD_PARAM_DECL;
        else if (PD_state == PD_PARAM_DECL) PD_state = PD_WAIT_NAMED_PARAM_TYPE;
    } else if (VD_state == VD_NONE) {
        if (token == IDENTIFIER) VD_state = VD_NOT_VAR_DECL;
            else VD_state = VD_VAR_DECL;
        }
      else if (VD_state == VD_WAIT_VAR_TYPE) VD_state = VD_VAR_DECL;   
}
void FSM_COMMA_read(void) {
    if (FSM_off) return;
    if (debugMode) printf("Lexer Debug: read a COMMA in mode %s\n", FSM_mode_str());
    if (parsed_tag_name1) {
        FSM_COMPLETE_TYPE_OR_IDENTIFIER_read(TYPEDEF_NAME); // a struct_or_union with a tag folowed by a comma is a full type specifier
        read_a_comma_after_tag_name = 1;
        if (debugMode) printf("Lexer Debug: read a COMMA in tag declaration, transitioned to new mode is: %s\n", FSM_mode_str());
    }
    if (FSM_in_PD_mode && (PD_state == PD_DECIDE_PARAM_KIND || PD_state == PD_WAIT_NAMED_PARAM_TYPE)) {
        PD_state = PD_NONE;       
        if (debugMode) printf("Lexer Debug: COMMA read, new mode %s\n", FSM_mode_str());
    }
}

int yywrap(void) {     /* called at end of input */
    return 1;           /* terminate now */
}

void read_comment() {
    int c;
    while ((c = input()) != 0)
        if (c == '*') {
            while ((c = input()) == '*')
                ;
            if (c == '/')
                return;
            if (c == 0)
                break;
        }
}

int convert_escape_sequence(const char *str) {
    if (strcmp(str, "\\0") == 0) return '\0';
    if (strcmp(str, "\\a") == 0) return '\a';
    if (strcmp(str, "\\b") == 0) return '\b';
    if (strcmp(str, "\\?") == 0) return '\?';
    if (strcmp(str, "\\f") == 0) return '\f';
    if (strcmp(str, "\\n") == 0) return '\n';
    if (strcmp(str, "\\r") == 0) return '\r';
    if (strcmp(str, "\\t") == 0) return '\t';
    if (strcmp(str, "\\v") == 0) return '\v';
    if (strcmp(str, "\\\\") == 0) return '\\';
    if (strcmp(str, "\\\'") == 0) return '\'';
    if (strcmp(str, "\\\"") == 0) return '"';
    if (str[1] >= '0' && str[1] <= '7') {   //Handle octal escape
        return (int)strtol(str + 1, NULL, 8);
    }
    if (str[1] == 'x') {                    //Handle hexadecimal escape
        return (int)strtol(str + 2, NULL, 16);
    }
    fprintf(stderr, "Invalid escape sequence: %s\n", str);
    exit(LEXING_FAILURE);
}

//add hexademical or octal wrapper and handle u|l|ll variations
void wrap_integer_constants(char *wrapper, char *input, char **output) {
    int current = strlen(input)-1;
    int has_u = 0, has_l = 0, has_ll = 0;
    int has_suffix = 1;

    while (has_suffix && current >= 0) {    //start from the end and move back until non u|U|l|L character is met
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
    int a = strcmp(wrapper, "");
    //calculating the length of the result: length of the wrapper + length of the prefix, the suffix, the underscore, the parenthesis
    int size = strlen(wrapper) + current+1 + 1 + has_u*strlen("unsigned") + has_l*strlen("long") + has_ll*strlen("long_long") + has_u*has_l + has_u*has_ll + (has_u || has_l || has_ll ? 2 : 0);

    char format_string[100];
    strcpy(format_string, "");

    if (!has_u && !has_l && !has_ll) {              //has no suffix, type depends on value
        unsigned long constant = strtoul(input, NULL, 0);         //the 0 enables automatic detection of base: decimal, octal or hexadecimal
        if (constant <= INT_MAX) {
            strcat(format_string, "int(");
            size += strlen("int()");
        } else if (a && constant <= UINT_MAX) {   //different rule for octals and hexademcimals
            strcat(format_string, "unsigned(");
            size += strlen("unsigned()");
        }
         else if (constant <= TARGET_LONG_MAX) {          //don't use LONG_MAX, values dependents on the target memory model size (32 vs 64 bits) of the program under test, not of the compiler used to generate the parser
            strcat(format_string, "long(");
            size += strlen("long()");
        } else {
            strcat(format_string, "unsigned_long(");   //todo check how long long constants without suffix are handled in gcc/ansi C currently set as unsigned long which is big enough
            size += strlen("unsigned_long()");
        }   
    }
    else if (has_u && !has_l && !has_ll) 
        strcat(format_string, "unsigned(");
    else if (has_u && has_l && !has_ll) 
        strcat(format_string, "unsigned_long(");
    else if (has_u && !has_l && has_ll) 
        strcat(format_string, "unsigned_long_long(");
    else if (!has_u && has_l && !has_ll) 
        strcat(format_string, "long(");
    else if (!has_u && !has_l && has_ll) 
        strcat(format_string, "long_long(");

    if (a) strcat(format_string, "%s");
    
    strcat(format_string, "%.*s)");

    *output = (char *)malloc(size);
    if (a) {
        snprintf(*output, size, format_string, wrapper, current + 1, input);
    } else {
        snprintf(*output, size, format_string, current + 1, input);
    }
}

//handle hexademical floating points and handle f|F|l|L variations
void wrap_floating_point_constants(int is_hexadecimal, char * input, char ** output) {
    int current = strlen(input)-1;
    int has_f = 0, has_l = 0, is_d = 0;
    int has_suffix = 1;

    switch (input[current]) {
        case 'f':
        case 'F':
            has_f = 1;
            break;
        case 'l':
        case 'L':
            has_l = 1;
            break;
        default:
            is_d = 1;
            has_suffix = 0;
    }
    if (has_suffix) current--;

    if (is_hexadecimal) {          //a floating point hexadecimal e.g. 0x1.FFFFFEp+127 becomes hex_float(double,"1.FFFFFE",+127)
        char *fraction = malloc((current + 1) * sizeof(char));
        char *power = malloc((current + 1) * sizeof(char));

        int j = 0, isPower = 0;
        for (int i = 0; i <= current; i++) {
            if (input[i] == 'p') {
                fraction[i - 2] = '\0'; 
                isPower = 1; 
                continue; 
            }
            if (isPower) {
                power[j++] = input[i];
            } else if (i >= 2) { 
                fraction[i - 2] = input[i];
            }
        }
        power[j] = '\0'; 
        char *type = "double";  // Default to "double"
        if (has_f) type = "float";
        else if (has_l) type = "long_double";

        int size = strlen("hex_float") + strlen(type) + strlen(fraction) + strlen(power) + 12; 
        *output = (char *)malloc(size);
        snprintf(*output, size, "hex_float(%s,\"%s\",%s)", type, fraction, power);
        free(fraction);
        free(power);
    }
    else {  //an ordinary decimal floating point literal
        //calculating the length of the result: length of the prefix, the suffix, the parenthesis
        int size = current+1 + 1 + is_d*strlen("double") + has_f*strlen("float") + has_l*strlen("long_double") + (has_f || has_l || is_d ? 2 : 0);
        *output = (char *)malloc(size);
        char format_string[100];
        strcpy(format_string, "");
        if (is_d) strcat(format_string, "double(%.*s)");      //double is the default type for floating points literals
        else if (has_f) strcat(format_string, "float(%.*s)");
        else if (has_l) strcat(format_string, "long_double(%.*s)");
        snprintf(*output, size, format_string, current + 1, input);
    }
}

//float has no digit after decimal point: need to add 0
void add_missing_zero_after_decimal_point(char *input, char **output) {
    size_t len = strlen(input);
    *output = (char*)malloc(len + 1 + 1); // +1 for extra '0'
    strcpy(*output, input);
    char* decimal_point = strchr(*output, '.');
    char* suffix = strpbrk(decimal_point, "eElL"); //returns pointer to first occurrence of character
    if (suffix == NULL) {// No suffix, so it's the end of the string
        suffix = *output + strlen(*output);
    }
    size_t decimal_pos = decimal_point - *output;
    memmove(decimal_point + 2, decimal_point + 1, len - decimal_pos); //copy everything after the decimal point to +1 location
    (*output)[decimal_pos + 1] = '0';    //add the 'missing' 0
}

char *add_missing_zero_before_decimal_point(const char *yytext, int yyleng) {
    if (yytext[0] == '.') {
        char *corrected_token = (char *)malloc(yyleng + 2);
        sprintf(corrected_token, "0%s", yytext);
        return corrected_token;
    } else {
        char *copy = (char *)malloc(yyleng + 1);
        strcpy(copy, yytext);
        return copy;
    }
}
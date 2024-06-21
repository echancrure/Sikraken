#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>	// use pow function

#define STRING_LIMIT 	10000		

#define YES 	1			//	indicates TRUE, USED or SET			
#define NO 		0			//	indicates FALSE, UNUSED or UNSET	

// OTHER DEFINITIONS
#define RADIX 10 // used with the itoa and ultoa functions to indicate a number to base 10 
#define IF_TOKEN 305		//crazy to rely on this
		// The token code for the 'if' token, when parsed.
		// This value is available to the yychar variable, which holds
		// the current lookahead token for the parser.
#define GLOBAL_SCOPE_NUMBER 0 // level of global variables on the stack 

// Extern variables				
extern char* PLFile;	// name of the file that the Prolog terms are written to - the .PL file					
extern int yylineno;	// the number of the line of source code being parsed used for debugging reasons at the moment
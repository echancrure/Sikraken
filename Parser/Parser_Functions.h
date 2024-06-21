#include <stdio.h>
#include <string.h>
#include <conio.h>



#include "C_grammar.tab.c"	

#define STRINGLIMIT 1000

#define ERROR1 	"PARSER -- NUMBER OF INPUT ARGUMENTS IS NOT CORRECT"
#define ERROR2 	"PARSER -- CANNOT CREATE FILE"
#define ERROR3 	"PARSER -- CANNOT OPEN FILE FOR READING FROM"
#define ERROR4 	"PARSER -- CANNOT OPEN FILE TO APPEND TO"
#define ERROR5	"PARSER -- CHECK FOR COMPLILATION ERRORS IN THE CODE UNDER ANALYSIS"
// error codes for the various errors that are caught by the parser.
// execution is aborted if any of these errors are encountered.

char* C_Filename;
char* PLFile;

int yyparse(void);								// extern function yyparse() to parse the file
int parser_error(char errorcode[]);				// prints errors to screen & causes parsing to abort
void yyerror (const char *s);					// in built error reporting for yyparse()

int parser_error(char errorcode[])
{
	// 	When an error is encountered the errorcode passed as parameter
	// 	to this function is output and execution is aborted by calling the exit() function from stdlib.h

	printf("%s\nEXECUTION ABORTED\n", errorcode);
	getch();
	exit(1);	// abort execution
   	return 1;	// denotes erronous termination
}

// in built error reporting function for ayacc -- cannot be changed
void yyerror (const char* s) {
	   fprintf(stderr, "SYNTAX ERROR %s AT LINE NUMBER %d\n", s, yylineno);
}
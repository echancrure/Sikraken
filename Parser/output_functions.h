/*
This header file also contains the functions which write the C names
and their equivalent Prolog names to the .NAMES file.
It also contains the function that causes the printing of the
Prolog terms to the .PL file
*/

extern FILE* pl_file;
char* case_name(char* varname);

char* case_name(char* varname) {
	/*
	This function is called by a variety of other functions defined in the
	header files of the PARSER.
	Its purpose is to change the 'varname' passed as parameter to its Prolog
	equivalent. If the first letter in 'varname' is lower case, the variable
	'name' gets "LC_" and 'varname' copied to it. If the first letter in 'varname'
	is upper case, the variable 'name' gets "UC_" and 'varname' copied to it.
	The variable 'name' is then returned by the function.
	*/
	char* name = (char*)malloc(3 + strlen(varname) + 1);

	if (islower(varname[0])) {
		strcpy(name, "LC_");	//LowerCase Prolog Prefix
	} else {
		strcpy(name, "UC_");	//UpperCase  Prolog Prefix
	}
	strcat(name, varname);
	return name;
}
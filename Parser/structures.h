/*
This header file defines the functions used in the processing of
structures to produce their Prolog terms equivalent.
The functions here are called from the grammar specification
file GRAMMAR.Y
*/

int struct_flag = NO;

char* seperate_fields(char vartype[], char varlist[]);
char* strip_struct(char struct_string[]);
char* struct_declaration(char decl_specifier[]);

char * seperate_fields(char vartype[], char varlist[])	//only called once
{
	/*
	This function is called from the following place in GRAMMAR.Y:

	struct_declaration
		: specifier_qualifier_list struct_declarator_list ';'	
		  { -- call seperate_fields() on $1 and $2 }
		;

	It is called when struct_declarator_list contains a list of fields, rather than a
	single field.
	For example, if a structure is declared as follows:

	   struct point
	   {
   			int a,b,c;
      		short x;
      		etc
	   };

	This would produce the second parameter 'varlist' to be:
		int a,b,c;

	If this is left unprocessed it will be parsed into the following Prolog terms:
		record_declaration_type(struct , Point, [([a,b,c], int), ([x], short)]),

	However what is required is the following:
		record_declaration_type(struct , Point, [([a], int), ([b], int), ([c], int), ([x], short)]),

	The list of variables need to be divided into its respective componenets.
	*/

	char finalstring[STRING_LIMIT];	// build string
	char tempstring[STRING_LIMIT];	// temporary string
	char * commastring;							// string beginning at first comma
	unsigned int nocommas;						// number of commas found in modified varlist
	unsigned int index, newindex;				// while loop control variables
	unsigned int i;								// for loop control variable
	unsigned int difference;					// difference in length of two strings
	
	char* varlist_copy = (char*)malloc(STRING_LIMIT);
	strcpy(varlist_copy, varlist);

	strcpy(finalstring, initialisestring(finalstring, STRING_LIMIT));
	strcpy(tempstring, initialisestring(tempstring, STRING_LIMIT));



	// varlist is of the form "a,b,c". a comma is added to the end of varlist so that the
	// number of commas found in varlist will match the number of variables in varlist i.e.
	// varlist is now "a,b,c,", number of variables = 3 and number commas = 3		
	strcat(varlist_copy, ",");

	// The number of commas in varlist equals the number of variables
	// to be processed, Find this value.
	nocommas = strstrcount(varlist_copy, ",")-1;

	// Begin the holding string of the function. This will be appended
	// to throughout the for loop.
	strcpy(finalstring, " ");

	// For every variable in 'varlist' do....	
	for (i = 1; i <= nocommas; i++)
	{
		// Begin finalstring...
		// varlist = "a,b,c,"	vartype = "int"
		strcat(finalstring, "([");		
		// commastring = ",b,c,"
		commastring = strstr(varlist_copy, ",");
		// difference = 6-5 = 1		
		difference = strlen(varlist_copy) - strlen(commastring);
		
		// Copy the first variable into tempstring. tempstring is "a" after
		// this while loop.
		index = 0;				
		while (index < difference)
		{
			tempstring[index] = varlist_copy[index];
			index++;
		}
	
		// Build this variable information onto finalstring.
		// finalstring is "([a], int), " after this code
		strcat(finalstring, tempstring);	
		strcat(finalstring, "], ");		
		strcat(finalstring, vartype);	
		strcat(finalstring, ")");		
		if (i != nocommas)
		{
			// Only append comma if NOT on final iteration of for loop.
			strcat(finalstring, ", ");	
		}

		// Re-initialise strings for the next for loop iteration.
		strcpy(tempstring, initialisestring(tempstring, STRING_LIMIT));

		// Remove the first variable "a" and its associated commma from the
		// varlist string to give varlist as "b,c," and iterae for loop again
		newindex = strlen(varlist_copy) - (strlen(commastring) - 1);
		index = 0;
		while (newindex < strlen(varlist_copy))
		{
			tempstring[index] = varlist_copy[newindex];
			index++;
			newindex++;
		}
		strcpy(varlist_copy, initialisestring(varlist_copy, STRING_LIMIT));
		strcpy(varlist_copy, tempstring);
		strcpy(tempstring, initialisestring(tempstring, STRING_LIMIT));
	}
	free(varlist_copy);

	char* returnstr = (char*)malloc(strlen(finalstring) + 1);
	strcpy(returnstr, finalstring);
	return returnstr;		
}

char* strip_struct(char struct_string[])	//only called once
{
	/*
		This function is called from the following place in GRAMMAR.Y:

		struct_declaration
			: specifier_qualifier_list struct_declarator_list ';'	
			  { -- call strip_struct() on $1 }
			;
		This function removes the keyword 'struct' from the 'struct_string'
		if it contains such.
	*/

	char* returnstr;
	char* commastring;

	// if the parameter 'struct_string' contains a comma, then the
	// structure has the keyword 'struct' in it. This needs to be removed
	// from the parameter.
	// Example: struct_string = "struct, mystruct"
	//			returnstr = "mystruct"
	if(strstr(struct_string, ",") != NULL)	{
		commastring = strstr(struct_string, ",");
		char* substring = copystring(commastring, 1, strlen(commastring));
		returnstr = (char*)malloc(strlen(substring) + 1);
		strcpy(returnstr, substring);
		free(substring);
	}
	else {// No processing required	
		returnstr = (char*)malloc(strlen(struct_string) + 1);
		strcpy(returnstr, struct_string);
	}
	return returnstr;	
}

char * struct_declaration(char decl_specifier[])	//only call once
{
	/*
		This function is called from the following place in GRAMMAR.Y:
			declaration
			: declaration_specifiers ';'		call struct_declaration()
			| declaration_specifiers init_declarator_list ';'
			;
	
		This function is called when a variable is declared like follows:
				struct IDENTIFIER
				{
					int x;
					etc;
				};
				OR
				struct
				{
					int x;
					etc;
				};
				OR
				struct VariableName;

		i.e. 	in first 2 examples the struct is declared without any variables.
				in last example - this is compilable code but meaningless since
				the struct can never be accessed

		$1 is the parameter called decl_specifier in the function code

		This function parsing the following examples into their Prolog equivalents:

		The following C code:
			struct point 
			{
   				int x;
      			int y;
   			};

		is built into the Prolog terms:
			record_declaration_type(struct , Point, [([x], int), ([y], int)]),

		The following C code:
			struct
   			{
   				int i;
      			int j;
   			};
		is built into the Prolog terms:
			record_declaration_type(struct , [([i], int), ([j], int)]),

		The following C code:
		   struct matrix;

		is built into the prolog terms:
			record_declaration(struct , Matrix),
	*/

	int lenstring;				// used to determine the length of decl_specifier
	char* returnstr = (char*)malloc(STRING_LIMIT);			// return string of the function

	lenstring = strlen(decl_specifier) - 1;	// minus 1 for NULL character

	// Assign the correct Prolog Predicate to the return string
	if (strstr(decl_specifier, "struct ") != NULL) {			// Struct declarations	
		strcpy(returnstr, "\nrecord_declaration");
	}
	else if (strstr(decl_specifier, "enum ") != NULL) {			// Enum declarations							
		strcpy(returnstr, "\nenum_declaration");
	}
	else if (strstr(decl_specifier, "typedef") != NULL) {		// Typedef declarations	
		strcpy(returnstr, "\ntypedef_declaration");
	}
	else {														// Normal variable declarations	
		strcpy(returnstr, "declaration(");
	}

	// If the last character in 'decl_specifier' is a ']', it indicates that
	// a struct has been declared with its list of fields (example 1 above).
	// Therefore, the type of the struct is declared - append "_type"
	if (decl_specifier[lenstring] == ']')
		strcat(returnstr, "_type(");
	else
		strcat(returnstr, "(");
	strcat(returnstr, decl_specifier);
	strcat(returnstr, "),");

	return returnstr;
}

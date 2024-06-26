/*
	This Header File contains an assortment of user-defined functions,
	used to manipulate strings. These functions are used throughout 
	the header files and grammar files, for string manipulation.
*/
#define UPPER_START 	65		// upper case letters begin at ascii value 65	
#define UPPER_END   	90		// upper case letters end at ascii value 90		
#define LOWER_START 	97		// lower case letters begin at ascii value 97	
#define LOWER_END		122		// lower case letters end at ascii value 122	
#define ASCII_DIFF		32		// there is a difference of 32 between upper and lower case ascii letters e.g. A = 65 a = 97

char* upper(char string[]);
char convert_tolower(char ch);
char* last_strstr(char* s1, char* s2);
int mystrstrcount(char* string, char substring);
int strstrcount(char* string, char* substring);
char* initialisestring(char string[], int limit);
char* copystring(char* source, int begin, int howmany);

char* upper(char string[])
{
	/* 	
		This function takes as parameter a string and converts that its to
		its uppercase equivalent.
	*/
		
	unsigned int i = 0;					// control variable of the while loop
	char* newstring = (char*)malloc(strlen(string) + 1 + 1);	// temporary holding string	

	strcpy(newstring, initialisestring(newstring, strlen(string) + 1));

	// Convert the string to UPPER CASE
	while (i < strlen(string))
	{
		if (string[i] >= LOWER_START && string[i] <= LOWER_END)
			newstring[i] = (char)(string[i] - ASCII_DIFF);
		else
			newstring[i] = string[i];
		i++;
	}
	
	char* returnstr = (char*)malloc(strlen(newstring) + 1);
	strcpy(returnstr, newstring);
	free(newstring);
   	return returnstr;			
}


char convert_tolower(char ch) {
	/* 	
		This function takes as parameter a char and converts this char to its lowercase
		equivalent if it is upper case, otherwise it will be unchanged.
		There is a pre-existing C function called tolower() that will perform the same
		task but this function results in the following warning:
			Conversion may lose significant digits
		This is because the parameter and return of this function is of type int and for
		the purposes of this program we need to convert characters.
	*/
   	if (ch >= UPPER_START && ch <= UPPER_END)
   		ch = (char)(ch + ASCII_DIFF);
   	return ch;
}

char* last_strstr(char * s1, char * s2)
{
	/*	
		This function takes as parameter two strings s1 and s2. It will return a pointer
		to the last occurance of s2 in s1 or NULL if it is not in s1
		This code is taken from:
		Title:		Jamsa's C/C++ Programmer's Bible (page 194)
		By:			Kris Jamsa and Lars Klander
		ISBN:		1-884133-25-8
		Publisher:	Jamsa Press
	*/
	int i, j, k, left = 0;

	for (i = 0; s1[i]; i++)
		for(j = i, k = 0; s1[j] == s2[k]; j++, k++)
			if(! s2[k+1])
				left = i;

	return ((left) ? s1+left : NULL);
}


int mystrstrcount(char *string, char substring) {
	/* 	
		This function takes as parameter one string string and one substring, 
		which is a single character. It counts the number of occurances of substring in string
		and returns this number.
	*/
	int i = 0; 
	int count = 0;

	while (string[i] != '\0')
	{
		if (string[i] == substring)
			count++;
		i++;
	}
	return (count);
}

int strstrcount(char *string, char *substring)
{
	/* 	
		This function takes as parameter two strings string and substring. It counts the
		number of occurances of substring in string	and returns this number.
		This code is taken from:
		Title:		Jamsa's C/C++ Programmer's Bible (page 192)
		By:			Kris Jamsa and Lars Klander
		ISBN:		1-884133-25-8
		Publisher:	Jamsa Press
	*/
	int i, j, k, count = 0;
	for (i = 0; string[i]; i++)
		for(j = i, k = 0; string[j] == substring[k]; j++, k++)

			if(! substring[k+1])
				count++;
	return (count);
}

// 15 June 2024 why is it needed to do this? Just a waste of time?
char* initialisestring(char string[], int limit)
{
	/*	
		This function takes as parameter a character array (string) and the amount of
		characters in this character array (limit) and it will return the string having
		first initialised all the positions in the string to NULL - to prevent any random
		characters.
	*/
	int index;
	for (index=0; index < limit; index++)
	{
		string[index] = '\0';
	}
	return string;
}

char* copystring(char* source, int begin, int howmany)
{
	/*	
		This function takes as parameter a source string. It returns a
		string which is a substring of 'source', starting at 'begin' 
		and taking in 'howmany' characters.
		For example:
			source = "hello there"
			begin = 3;
			howmany = 7;
			returns string = "llo the"
	*/
	char* holdstr = (char*)malloc(strlen(source) + 1);
	int index = 0;
  	strcpy(holdstr, initialisestring(holdstr, strlen(source)));

	// Copy the string, beginning at 'begin' for 'howmany' characters
	while (index <= howmany)
	{
		holdstr[index] = source[begin];
		index++;
		begin++;
	}
	
	char* returnstr = (char*)malloc(strlen(holdstr) + 1);
	strcpy(returnstr, holdstr);
	free(holdstr);
	return returnstr;
}

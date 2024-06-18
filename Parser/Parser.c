// Functionality
// **************
// Parse the file (.i file as preprocessed) passed as one of the
// parameters to produce Prolog Terms File ( .PL)

#include <io.h>

#include "Parser_Functions.h"	// User defined header file containing all the functions used in the parser

int main (int argc, char * argv[])
{
	char* filepath = (char*)malloc(STRINGLIMIT);	// path of the original C file -- where .pl
	char* filename = (char*)malloc(STRINGLIMIT);	// name of the file to be parsed (less extension)
	char* C_Filename = (char*)malloc(STRINGLIMIT);	// name of the C file with .c extension
	char* relativepath = (char*)malloc(STRINGLIMIT);// path from where parser is called -- .i file in this path
	char* ifile = (char*)malloc(STRINGLIMIT);		// path (relativepath) and name of the .i file

	PLFile = (char*)malloc(STRINGLIMIT);
	strcpy(filepath, ".\\");

	for (int i = 1; i <= argc - 1; i++) {	//processing comand line arguments
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'h':
				printf("Usage: .\\sikraken_parser [OPTION]... [FILE]\nParse a C file to Prolog terms.\n\n-h\t Display help information\n-p\t Path to the .c/.i file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\LilyParser -p\".\" get_sign \n\t.\\LilyParser get_sign \n\t.\\LilyParser -p\"C:/Parser/\" sign \n");
				exit(0);
			case 'p':	//path to the .i pre-processed input C file
				if (_access(&argv[i][2], 0) == -1) {    //checks if it is a valid directory
					fprintf(stderr, "Sikraken parser error: the indicated source path (via -p switch): %s , cannot be accessed\n", &argv[i][2]);
					exit(1);
				}
				strcpy(filepath, &argv[i][2]);
				break;
			default:
				fprintf(stderr, "Sikraken parser: Unsupported flag '-%c', ignoring.\n", argv[i]);
			}
		}
		else {
			argv[i][strlen(argv[i]) - 2] = '\0';	//cut the out ".c"
			strcpy(filename, argv[i]);
		}
	}
	//printf("DEBUG filename:%s, filepath:%s\n", filename, filepath);

	char I_path[_MAX_PATH];
 	sprintf(I_path, "%s%s.i", filepath, filename);
	if (_access(I_path, 0) != 0) {
		fprintf(stderr, ".i file could not be found: %s\n", I_path);
		exit(1);
	}
	strcpy(C_Filename, filename); 
	strcat(C_Filename, ".c");

	// set up path (filepath) & name of the .PL file (PLFile - global)
	strcpy(PLFile, filepath);		
	strcat(PLFile, "\\\\");
	strcat(PLFile, filename);		
	strcat(PLFile, ".pl");

	// set up path (relativepath) & name of the .i file (ifile)
	strcpy(ifile, filepath);
	strcat(ifile, "\\\\");
	strcat(ifile, filename);		
	strcat(ifile, ".i");

	// print the discontiguous statements -- to PLFile
	//print_discontiguous(PLFile);

	print_start_of_parsed_predicate(PLFile);

	// PARSE the input file	-- parse .i file (ifile)
	parse_file(ifile);

	// print the dummy declarations	 -- to PLFile
	print_dummy_dec(PLFile);

	print_end_of_parsed_predicate(PLFile);

	//remove(ifile);
	printf("Sikraken parser: success");
	return 0;
}

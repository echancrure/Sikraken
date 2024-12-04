/*#include <stdio.h>


int main(){
    signed long int a = 2;
    long signed int b = 1;
    int long signed c = 3;
    const int signed long d = 4;
    int e = 6;
    long int long signed f = 5;
    long int g;
    signed long int g = 6;
    signed long long int const h = 7;
    long j = 9;
    short k = 10;
    unsigned int l = 9, m=10;
    static int n = 11;
    signed m = 10;
    long o = 11.0;


    printf("%ld, %ld, %ld, %ld, %d, %lld, %ld, %lld, %ld, %d, %d \n", a, b, c, d ,e ,f ,g, h, j, k, 0);

    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TOKENS 100  // Maximum number of tokens
#define MAX_LENGTH 256  // Maximum string length

// Function declaration
void process_declaration_specifiers(char a[]);

int main() {
    char input[MAX_LENGTH];

    // Get the input string
    printf("Enter a string separated by commas: ");
    if (fgets(input, MAX_LENGTH, stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Call the function to process the input
        process_declaration_specifiers(input);
        printf("%s \n", input);
    }

    return 0;
}

void process_declaration_specifiers(char a[]) {
typedef struct {
    bool isTypeDef;
    bool isExtern;
    bool isConstant;
    bool isStatic;
    bool isInt;
    bool isChar;
    bool isDouble;
    bool isFloat;
    bool isStruct;
    bool isSigned;
    bool isShort;
    int longCount;
} SpecifierFlags;

    char *token;
    SpecifierFlags flags = {false, false, false, false, true, false, false, false,false, true, false, 0};

    // Tokenize the string using commas and spaces as delimiters
    token = strtok(a, ", ");
    while (token != NULL) {
        if(strcmp(token, "double") == 0){
            flags.isInt = false;
            flags.isDouble = true;
        }else if(strcmp(token, "float") == 0){
            flags.isInt = false;
            flags.isFloat = true;
        }else if (strcmp(token, "char") == 0){
            flags.isInt = false;
            flags.isChar = true;
        } else if (strcmp(token, "long") == 0) {
            flags.longCount++;
        }else if(strcmp(token, "short") == 0){
            flags.isShort = true;
        }else if (strcmp(token, "unsigned") == 0) {
            flags.isSigned = false;
        }else if(strcmp(token, "const") == 0){
            flags.isConstant = true;
        }else if(strcmp(token, "static") == 0){
            flags.isStatic = true;
        }else if(strcmp(token, "extern") == 0){
            flags.isExtern = true;
        }else if(strcmp(token, "typedef") == 0){
            flags.isTypeDef = true;
        }else if(strcmp(token, "struct") == 0){
            flags.isStruct = true;
            flags.isInt = false;
        }
        token = strtok(NULL, ", "); // Get the next token
        printf("%s", token);
    }
    
    if(flags.isInt){
        a[0] = '\0';
        if(flags.isTypeDef){
            strcpy(a, "typedef, ");
        }
        if(flags.isExtern){
            strcat(a, "extern, ");
        }
        if(flags.isConstant){
            strcat(a, "const, ");
        }
        if(flags.isStatic){
            strcat(a, "static, ");
        }
        if(flags.isSigned){
            if(flags.longCount == 1){
                strcat(a, "long");
            }else if(flags.longCount == 2){
                strcat(a, "long, long");
            }else if(flags.isShort){
                strcat(a, "short");
            }else{
                strcat(a, "int");
            }
        }else{
            if(flags.longCount == 1){
                strcat(a, "unsigned, long");
            }else if(flags.longCount == 2){
                strcat(a, "unsigned, long, long");
            }else if(flags.isShort){
                strcat(a, "unsigned, short");
            }else{
                strcat(a, "unsigned, int");
            }
        }
    }
}
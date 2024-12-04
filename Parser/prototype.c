#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 100  // Maximum number of tokens
#define MAX_LENGTH 256  // Maximum string length

int main() {
    char input[MAX_LENGTH];
    char *tokens[MAX_TOKENS];
    int count = 0;

    // Get the input string
    printf("Enter a string separated by commas: ");
    fgets(input, MAX_LENGTH, stdin);

    process_declaration_specifiers(input);
    
    return 0;
}

void process_declaration_specifiers(char a[]) {
    char *token;
    token = strtok(a, ", ");
    while (token != NULL) {
        printf("%s\n", token); // Print each token
        token = strtok(NULL, ", "); // Get the next token
    }
}

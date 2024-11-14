extern int __VERIFIER_nondet_int();
int main() {
    // Standard escape sequences
    char null_char = '\0';             // Null character
    char bell = '\a';                  // Bell (alert)
    char backspace = '\b';             // Backspace
    char formfeed = '\f';
    char question_mark = '\?';
    char tab = '\t';                   // Horizontal tab
    char newline = '\n';               // Newline
    char vertical_tab = '\v';          // Vertical tab
    char form_feed = '\f';             // Form feed
    char carriage_return = '\r';       // Carriage return
    char single_quote = '\'';          // Single quote
    char double_quote = '\"';          // Double quote
    char backslash = '\\';             // Backslash

    // Octal escape sequences
    char octal_A = '\101';             // Octal for 'A' (65 in decimal)
    char octal_B = '\102';             // Octal for 'B' (66 in decimal)
    char octal_space = '\040';         // Octal for space (32 in decimal)
    
    // Hexadecimal escape sequences
    char hex_A = '\x41';               // Hexadecimal for 'A' (65 in decimal)
    char hex_B = '\x42';               // Hexadecimal for 'B' (66 in decimal)
    char hex_space = '\x20';           // Hexadecimal for space (32 in decimal)

    int i = __VERIFIER_nondet_int();
    return 0;
}
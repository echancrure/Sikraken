extern int __VERIFIER_nondet_int();
//#include <stdio.h>
int main() {
    int sol = 0;   
    int nota = __VERIFIER_nondet_int();
    nota = ~nota;
    if (nota == 42) sol++;
    else sol++;




 
    // Bitwise AND (&)
    int a = 12;    // 1100 in binary
    int b = 10;    // 1010 in binary
    int and_result = a & b;  // 1000 in binary -> 8
    if (and_result == 8) sol++;

    // Bitwise OR (|)
    int or_result = a | b;   // 1110 in binary -> 14
    if (or_result == 14) sol++;

    // Bitwise XOR (^)
    int xor_result = a ^ b;  // 0110 in binary -> 6
    if (xor_result == 6) sol++;

    // Bitwise NOT (~)
    unsigned int c = 0x0F;   // 00001111 in binary
    unsigned int not_result = ~c;  // 11110000 in binary (with unsigned) -> 0xFFFFFFF0
    if (not_result == 0xFFFFFFF0) sol++;

    // Bitwise left shift (<<)
    int d = 5;               // 00000101 in binary
    int shift_left = d << 1;  // 00001010 in binary -> 10
    if (shift_left == 10) sol++;

    // Bitwise right shift (>>)
    int shift_right = d >> 1; // 00000010 in binary -> 2
    if (shift_right == 2) sol++;

    // Using bitwise operators with `char` type
    char e = 0x3C;           // 00111100 in binary, 61 in decimal
    char f = 0x0F;           // 00001111 in binary
    char char_and = e & f;    // 00001100 in binary -> 12
    if (char_and == 12) sol++;

    char char_or = e | f;     // 00111111 in binary -> 63
    if (char_or == 63) sol++;

    char char_xor = e ^ f;    // 00110011 in binary -> 51
    if (char_xor == 51) sol++;

    char char_not = ~e;       // 11000011 in binary (2's complement) -> -61
    if (char_not == -61) sol++;
    //printf("sol is %d", sol);
    return 0;
}
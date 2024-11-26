#include <stdio.h>

int main() {
    // Basic Hexadecimal Constants
    int hex0 = 0x0;     // Decimal: 0
    int hex1 = 0x1;     // Decimal: 1
    int hexA = 0xA;     // Decimal: 10
    int hexF = 0xF;     // Decimal: 15

    // Multi-Digit Hexadecimal Constants
    int hex10 = 0x10;   // Decimal: 16
    int hex1F = 0x1F;   // Decimal: 31
    int hex2A = 0x2A;   // Decimal: 42
    int hexFF = 0xFF;   // Decimal: 255
    int hex7FFF = 0x7FFF; // Decimal: 32767

    // Negative Hexadecimal Constants
    int negHex1A = -0x1A; // Decimal: -26
    int negHex80 = -0x80; // Decimal: -128

    // Hexadecimal with Uppercase and Lowercase
    int hexLower = 0x1a; // Decimal: 26 (lowercase)
    int hexUpper = 0x1A; // Decimal: 26 (uppercase)

    // Hexadecimal with Different Data Types
    unsigned int hexUnsigned = 0x1AU; // Unsigned integer
    long hexLong = 0x1AL;             // Long integer
    unsigned long hexULong = 0x1AUL;  // Unsigned long integer

    // Large Hexadecimal Values
    unsigned int hex32bit = 0xFFFFFFFF;           // Max 32-bit unsigned integer
    unsigned long long hex64bit = 0xFFFFFFFFFFFFFFFF; // Max 64-bit unsigned integer

    // Hexadecimal Constants for Bit Masks
    int mask8bit = 0xFF;    // 8-bit mask
    int mask16bit = 0xFFFF; // 16-bit mask

    // Hexadecimal Constants for Memory Addresses
    unsigned int memoryAddr = 0x7FFF0000; // Hypothetical memory address

    // Hexadecimal Constants for Colors
    unsigned int whiteColor = 0xFFFFFF; // White color in RGB
    unsigned int greenColor = 0x00FF00; // Green color in RGB

    // Print all values
    printf("Basic Hex Constants: %d, %d, %d, %d\n", hex0, hex1, hexA, hexF);
    printf("Multi-Digit Hex: %d, %d, %d, %d, %d\n", hex10, hex1F, hex2A, hexFF, hex7FFF);
    printf("Negative Hex: %d, %d\n", negHex1A, negHex80);
    printf("Case Sensitivity: %d, %d\n", hexLower, hexUpper);
    printf("Hex with Types: %u, %ld, %lu\n", hexUnsigned, hexLong, hexULong);
    printf("Large Hex: %u, %llu\n", hex32bit, hex64bit);
    printf("Bit Masks: %d, %d\n", mask8bit, mask16bit);
    printf("Memory Address: 0x%X\n", memoryAddr);
    printf("Colors: 0x%X (White), 0x%X (Green)\n", whiteColor, greenColor);

    return 0;
}

#include <stdio.h>

int main() {
unsigned char uc = 300;
printf("ui:%hhu\n", uc);

unsigned char c = 42;
unsigned char cu = -c;
int ci = -c;
printf("minus unsigned char:%hhu\n", cu);
printf("unary minus to integer:%i\n", ci);

}
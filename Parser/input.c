#include <stdio.h>
int main() {
        for (int i = 0; i < 5; i++) {
            
            if (i == 3) {
                goto end_loops;  // Jump out of both loops when i == 3 and j == 2
            }
            
        }
        printf("statement before label");

    end_loops:
        printf("Exited the loops\n");
        printf("secound statement after label\n");
    
    return 0;
}

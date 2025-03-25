int main() {
    int choice;

    while (1) { // Infinite loop until the user exits
        // Displaying menu options
        printf("\nMenu:\n");
        printf("1. Say Hello\n");
        printf("2. Print a Number\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case for different choices
        switch (choice) {
            case 1:
                printf("Hello, User!\n");
                break;
            case 2:
                printf("Enter a number: ");
                int num;
                scanf("%d", &num);
                printf("You entered: %d\n", num);
                break;
            case 3:
                printf("Exiting the program...\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

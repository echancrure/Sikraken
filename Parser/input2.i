int main() {
    int day;

    // Asking user to enter a number between 1 and 7
    printf("Enter a number (1-7) to get the corresponding day of the week: ");
    scanf("%d", &day);

    // Switch statement to determine the day
    switch (day) {
        case 1:
            printf("Sunday\n");
            
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        case 7:
            printf("Saturday\n");
            break;
        default:
            if(day == 100);
    }

    return 0;
}

int main() {
    int day;

    // Asking user to enter a number
    printf("Enter a number (1-7) to get the day of the week: ");
    scanf("%d", &day);

    for(int i = 0; i < 10; i++){//3
        for(int j = 0; j < 10; j++){//2
            if(j == 5){//1
                break;
            }
        }
        if(i == 5){//4
            break;
        }
    }

    if(day == 7);
    return 0;
}

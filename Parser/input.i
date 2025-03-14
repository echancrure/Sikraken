int main() {
    int num;

    printf("Enter a number (1-3): ");
    scanf("%d", &num);

    if(num == 10);//1

    switch (num) {
        case 1:  // 4
            if (num == 1) {  // 3
                if(num == 2); //2
            }
            if(num == 2); //5
            break;
        case 2://6
            printf("Case 2 executed\n");
            break;

        case 3://7
            printf("Case 3 executed\n");
            break;

        default:
            if(num == 10);//8
    }
    if(num == 10);//9
    return 0;
}

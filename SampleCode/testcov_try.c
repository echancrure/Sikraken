// function_calls.c
extern int __VERIFIER_nondet_int();
int a = 0;
int calculate_output(int input) {
    if (input == 1) {
        a++;
    } else if (input == 2) {
        a++;
    } else if (input == 3) {
        a++;
    } else if (input == 4) {
        a++;
    } else if (input == 5) {
        a++;
    } else if (input == 6) {
        return 6;
    }
    return -1; // default case
}

int main(){
    int output = -1;
    while(1) {
        int input;
        input = __VERIFIER_nondet_int();
        if ((input != 1) && (input != 2) && (input != 3) && (input != 4) && (input != 5) && (input != 6)) return -2;
        output = calculate_output(input);
    }
}
int main() {
    int day;

    (day == 360) ? (void)0 : (void)0;  // Ternary operator doing nothing

    do {
        (day == 10) ? (void)0 : (void)0;
        (day == 20) ? (void)0 : (void)0;
        do {
            (day == 40) ? (void)0 : (void)0;
        } while (day != 50);
        (day == 20) ? (void)0 : (void)0;
    } while (day != 100);

    do {
    } while (day == 120);

    return 0;
}


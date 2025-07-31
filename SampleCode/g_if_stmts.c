 int main() {
    int x = 5, y = 10;

    if (x > 0) {
        if (y > 5) { // No else for the inner if
            x = x + 1;
        }
    } else {
        y = y + 2;
        if (y > 7) {
            x = x + 1;
        } else {
            y = y - 1;
        }
    }
    return x + y;
}

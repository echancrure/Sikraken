 int calculate_output3(int input) {
    int result = input * 2;
    if (result > 10) {
        return result;
    } else {
        result = result - 3;
    }
    return result; 
 }

 int calculate_output2(int input) {
    int result = input * 3;
    if (result > 100) {
        return result;
    } else {
        result = result - 3;
    }
    return calculate_output3(result);
 }

 int calculate_output(int input) {
    int result = input * 2;
    if (result > 1000) {
        return result;
    } else {
        result = result - 3;
    }
    return calculate_output2(result);
 }
 
 int main() {
    int x = 5, y = 10;

    if (x > 0) {
        if (y > 5) { // No else for the inner if
            x = x + 1;
        }
    } else {
        y = y + 2;
        if (y > 7) {
            calculate_output3(y);   // function call as a statement
        } else {
            y = y - 1;
        }
    }
    return calculate_output(x + y);
}

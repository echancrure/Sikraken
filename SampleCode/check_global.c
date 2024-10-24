//check typedef
typedef unsigned char SORT_1;
const SORT_1 mask_SORT_1 = (SORT_1)-1 >> (sizeof(SORT_1) * 8 - 1);
//check if globals can be accessed
int y = 5;
int check_global() {
    return y;
}
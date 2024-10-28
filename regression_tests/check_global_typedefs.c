extern int __VERIFIER_nondet_int();
//check typedef
typedef int Length;
Length len, maxlen;
typedef long Blockno, *Blockptr;    //K&R p. 221
typedef unsigned char SORT_1;
typedef char *__caddr_t;            //sll-buckets-2.c
typedef __caddr_t caddr_t;
const SORT_1 mask_SORT_1 = (SORT_1)-1 >> (sizeof(SORT_1) * 8 - 1);
//check if globals can be accessed
int x = 5;
int main() {
    int y = __VERIFIER_nondet_int();
    return x+y;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    for(int i = 0; i < 5; i++) {
        int j = __VERIFIER_nondet_int();
        switch (j) {
            //if (i == 2) {           //unreachable
            //        i = 100;
            //    }        
            case 0: 
            case 42: 
                i++;
               // if (i == 2) {
               //     i = 100;
               // } 
            case 100: return 1;     //case 42 and case 100 fall through
            case 1: return 10;
            case 2: return 100;
            case 3: return 1000; 
            default: break;
        }
    }
    int k = 8;
    goto end;
    k--;    //unreachable
    end: k++;

/*
    int i, luck = 0;
    do {
        i = __VERIFIER_nondet_int();
        switch (i) {
            case 13 : case 7 :
                luck++;
                luck++;
                break;
            case 666 : case -42 :
                luck--;
                break;
            case 999: 
                luck-=999;
                break;
            case -1000000:
                return i;
            case 42:
                luck +=i;
            default: 
                ;
        }
    } while (i != 1111111);
    return luck;
*/
    return 0;
}
int main() {
    int i = 0;
    
        for (i = 0; i < 5; i++) {//2
            
            if (i == 3) {//1
                goto end_loops;
            }
            
        }
        if(i == 100);//3
    end_loops:
        if(i == 10);//4
    
    return 0;
}

void getRecords(){
    int i = 0;
    if(i == 10);//4
    if(i == 11);
}
void setRecords(){
    
}
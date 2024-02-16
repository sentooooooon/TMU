#include<stdio.h>

void main(){
    int c;
    int a = 0;
    while(1){
        c = getchar();
        if( c == 'End'){
            break;
        }
        printf("%c", c);
    }
}
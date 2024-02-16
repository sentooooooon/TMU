#include<stdio.h>

int main(){
    int a,b,sho;
    sho = 1;
    scanf("%d",&a);
    scanf("%d",&b);
    while(1){
        if(a - b*sho < b){
            break;
        }
        sho++;
    }
    printf("商%d, あまり%d", sho, a - b*sho);
    return 0;
}
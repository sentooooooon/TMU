#include<stdio.h>

int main(){
    int A[100];
    int c = 0;
    while(1){
        int a;
        scanf("%d", &a);
        if(a == 0){
            break;
        }
        A[c] = a;
        c++;
    }
    float sum, ave;
    sum = 0;
    for(int i = 0; i < c ; i++){
        sum += A[i];
    }
    ave  = sum / c;
    printf("合計%f,平均%f", sum,ave);
    return 0;

}
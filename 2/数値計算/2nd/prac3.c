#include<stdio.h>

int main(){
    float A[3][5];
    float sum = 0;
    float sumzennbu = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0; j < 5 ; j++){
            float a;
            scanf("%f", &a);
            A[i][j] = a;
            sum += a;
        }
        printf("%d行の合計、%f\n", i+1, sum);
        sumzennbu += sum;
        sum = 0;
    }

    printf("全部の合計%f\n",sumzennbu);
    return 0;
}

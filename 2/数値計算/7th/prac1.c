#include<stdio.h>


int kaijo(int n){
    if(n ==0 || n == 1){
        return 1;
    }
    else{
        return n*kaijo(n-1);
    }
}

int seki(int n){
    return 0;
}
int main(){
    int ans = 0;
    for(int k = 1; k <= 6; k++){
        int pi = 1;
        int sigma2 = 0;
        for(int i = 1; i <= k; i++){
            pi *= 3*i + 1;
        }
        for(int l = 0; l <= k ; l++){
            sigma2 += kaijo(l) + 6;
        }
        ans += pi + sigma2;
    }
    printf("%d",ans);
    return 0;
}
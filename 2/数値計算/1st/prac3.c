#include<stdio.h>

int main(){
    int ans =1;
    for(int i=5;i>=1;i--){
        ans = i*ans;
    }
    printf("%d",ans);
    return 0;
}
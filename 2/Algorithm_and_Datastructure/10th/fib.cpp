#include<iostream>
using namespace std;

int fib(int n){

    if (n == 1 || n == 0){
        return 1;
    }
    int F[n];
    F[0] = 1;
    F[1] = 1;
    for(int i = 2; i <= n; i ++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
    
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
#include<iostream>
#include<random>
#include<fstream>
using namespace std;
void rnd_exp(int A[], int B[], int n){
    int rd = 22140003;
    mt19937 mt(rd);
    uniform_int_distribution<int> distribution(1,3);
    for(int i = 0; i < n; i++){
        int r = distribution(mt);
        int s = distribution(mt);
        A[i] = r;
        B[i] = s;
    }
}

int main(){
    int a[100];
    int b[100];
    rnd_exp(a,b,100);
    for(int i = 0; i < 50; i++){
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}
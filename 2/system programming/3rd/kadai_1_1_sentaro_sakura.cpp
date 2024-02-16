#include<iostream>
#include<random>
using namespace std;

//ランド関数を作る
void rnd_exp(double A[], doubleB[], int n){
    int rd = 22140003;
    mt19937 gen(rd);
    uniform_real_distribution<double> distribution(0.0,1.0);
    for(int i = 0; i < n; i++){
        double r = distribution(gen);
        A[i] = r;
    }
}
int main(){
    int n = 1000;
    double A[n];
    rnd_exp(A,n);
    double sum1 = 0;
    double sum2 = 0;
    for(int i = 0; i < n ; i++){
        sum1 += A[i];
        sum2 += A[i] * A[i];
    }
    double ave = sum1 / n;
    cout << "平均値： " << sum1/n << endl;
    cout << "分散： " << sum2/n - ave*ave << endl;
    return 0;
}
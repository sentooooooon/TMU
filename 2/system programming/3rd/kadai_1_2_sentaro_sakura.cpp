#include<iostream>
#include<random>
using namespace std;

//ランド関数を作る
void rnd_exp(double A[], int n){
    random_device rd;
    mt19937 gen(rd());
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
    double p1 = 0.3;
    double p2 = 0.5;
    double p3 = 0.7;
    double R1, R2, R3;
    R1 = 0;
    R2 = 0;
    R3 = 0;
    for(int i = 0; i < n; i++){
        if(A[i] < p1){
        }
        else if(p1 <= A[i] && A[i] <= p2 ){
            R1++;
        }
        else if(p2 < A[i] && A[i] <= p3){
            R1++;
            R2++;
        }
        else if(p3 < A[i]){
            R1++;
            R2++;
            R3++;
        }
    }
    cout << "p = 0.3の時" << R1/n << endl;
    cout << "p = 0.5の時" << R2/n << endl;
    cout << "p = 0.7の時" << R3/n << endl;

    return 0;
}
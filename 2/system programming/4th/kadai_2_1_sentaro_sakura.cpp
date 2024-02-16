#include<iostream>
#include<random>
#include<math.h>
#include<iomanip>
#include<fstream>
using namespace std;
void rnd_exp(double A[], double B[], int n){
    int rd = 22140003;
    mt19937 mt(rd);
    uniform_real_distribution<double> distribution(0.0,1.0);
    for(int i = 0; i < n; i++){
        double r = distribution(mt);
        double s = distribution(mt);
        A[i] = r;
        B[i] = s;
    }
}
int main(){
    ofstream of("kadai_2_1.csv");
    of << "n,pi"<<endl;
    int n = 15000;
    double R1[n], R2[n];
    rnd_exp(R1,R2,n);
    int count = 0;
    for(int i = 0; i< n;i++){
        double r;
        r = pow(R1[i],2) + pow(R2[i],2);
        if(r < 1.000)count++;
        double a = i + 1.0;
        of << i+1 << "," << fixed << setprecision(4) << 4.0*(count/(a)) << endl;
    }
    double N = n + 0.0;
    double rat = count/N;
    cout << fixed << setprecision(4) << 4*rat << endl;
    return 0;
}
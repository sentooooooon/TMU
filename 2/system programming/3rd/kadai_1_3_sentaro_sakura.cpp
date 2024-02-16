#include<iostream>
#include<random>
#include<fstream>
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
int GenDice(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 6);
    return distribution(gen);
}

int main(){
    ofstream of("DiceAverage.csv");
    of << "N,Average" <<endl; 
    int n = 1000;
    double A[n];
    rnd_exp(A,n);
    double sum = 0;

    for(int i = 0; i < n; i++){
        sum += GenDice();
        of << i+1 << "," << sum/(i+1) << endl;
    }
    cout << sum/n << endl;
    return 0;
}
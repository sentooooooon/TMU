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
    uniform_int_distribution<int> distribution(1, 9);
    int a = distribution(gen);
    if(a == 7) a = 2;
    if(a == 8) a = 4;
    if(a == 9) a = 6;
    return a;
}

int main(){
    ofstream of("DiceAverage1-A.csv");
    of << "N,Average" <<endl; 
    int n = 1000;
    double A[n];
    rnd_exp(A,n);
    double sum = 0;

    for(int i = 0; i < n; i++){
        sum += GenDice();
        of << i+1 << "," << sum/(i+1) << endl;
    }
    return 0;
}
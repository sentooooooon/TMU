#include<iostream>
#include<random>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

double normal_rand(int n){
    random_device rd;
    mt19937 mt(rd());
    //set mean and median
    double mean = 0.0;
    double var = 1.0;
    //define normal distribution
    normal_distribution<double> dist(mean,var);

    double sum = 0;
    //generate random number for n times
    for(int i =0; i < n; i ++){
        sum += dist(mt);
    }
    return sum / n;
}
int main(){
    //create a file
    ofstream of("kadai_4_1.csv");
    of << "Xn" << endl;
    //set variables
    int n = 10000;
    //
    for(int m = 10; m<= 10000; m *= 10){
       double sum = 0;
       double sum2 = 0;
       for(int i = 0;i < m; i++){
        double rnd = normal_rand(n);
        sum += rnd;
        sum2 += pow(rnd,2);
        if(m == 10000){
            of << rnd << endl;
        }
       }
       cout << "m:" << m << endl;
       cout << fixed << setprecision(7) << "平均値" << sum / m << endl;
       cout << "分散" << (sum2 / m) - pow((sum/m),2) << endl; 
    }


    return 0;
}
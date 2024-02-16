#include<iostream>
#include<random>
#include<fstream>
using namespace std;

double rnd_int(int n){
    random_device rd;
    mt19937 mt(rd());
    //define normal distribution
    uniform_int_distribution<int> dist(1,6);
    double sum = 0;
    //generate random number for n times
    for(int i =0; i < n; i ++){
        sum += dist(mt);
    }
    return sum / n;
}
int main(){
    int n = 10000;
    //file
    ofstream of("kadai_4_2.csv");
    of << "Yn" << endl;
    for(int m = 10; m <= 10000; m *= 10){
        double sum = 0;
        double sum2 = 0;
        for(int i = 0; i < m; i++){
            double Y = rnd_int(n);
            sum += Y;
            sum2 += pow(Y,2);
            if(m == 10000){
                of << Y << endl;
            }
        }
        cout << "m:" << m << endl;
        cout << "平均値" << sum / m << endl;
        cout <<"分散" << (sum2/m) - pow(sum/m,2) << endl;
    }
    return 0;
}
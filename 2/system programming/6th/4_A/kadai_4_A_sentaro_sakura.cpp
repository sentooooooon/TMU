#include<iostream>
#include<random>
#include<fstream>
#include<iomanip>
using namespace std;

double rnd_coin(int n){
    random_device rd;
    mt19937 mt(rd());
    //define normal distribution
    uniform_real_distribution<double> dist(0.0,1.0);
    double sum = 0;
    double p =0.3;
    int head=0;
    int loop=0;;
    while(1){
        loop++;
        if(p > dist(mt)){
            head++;
        }
        if(loop == n){
            break;
        }
    }
    return double(head) / n;
}
int main(){
    int n = 10000;
    //file
    ofstream of("kadai_4_A.csv");
    of << "Pn" << endl;
    for(int m = 10; m <= 10000; m *= 10){
        double sum = 0;
        double sum2 = 0;
        for(int i = 0; i < m; i++){
            double P = rnd_coin(n);
            sum += P;
            sum2 += pow(P,2);
            if(m == 10000){
                of << P << endl;
            }
        }
        cout << "m:" << m << endl;
        cout << "平均値" << sum / m << endl;
        cout << fixed <<setprecision(7) << "分散" << (sum2/m) - pow(sum/m,2) << endl;
    }
    return 0;
}
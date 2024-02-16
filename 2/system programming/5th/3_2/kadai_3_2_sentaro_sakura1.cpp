#include<iostream>
#include<random>
#include<cmath>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

//make random numbers in an array


int main(){
    //set random numbers
    int n = 100000;
    //set probability
    double p = 0.1;
    int seed = 22140003;
    mt19937 mt(seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);
    //set variable
    int count_loop = 0;
    int count_tousen = 0;
    double spnetmoney = 0;
    int stop_hazure = 0;
    //create a file for ratio
    ofstream of("kadai_3_2_ratio1.csv");
    of << "n,tousen" << endl;

    //create a file for  average spent
    ofstream file("kadai_3_2_average_expenditure1.csv");
    file << "n,average" << endl;

    
    while(1){
        double prob = distribution(mt);
        spnetmoney += 500;
        count_loop++;
        if(prob > p){
            count_tousen++;
        }
        if(10000 < count_loop && count_loop < 100000 ){
            double N = n;
            double tousen = count_tousen;
            double hazure = count_loop - count_tousen;
            of << count_loop << "," << tousen/count_loop << endl; 
            file << count_loop << "," << (count_loop*500.0) / count_tousen << endl;
        }
        if(count_tousen == n)break;
    }
    double N = n;
    double tousen = count_tousen;
    double hazure = count_loop - count_tousen;
    cout << "当たる確率が０．9の場合" << endl;
    cout << fixed << setprecision(3) <<  "あたり：" << tousen/count_loop << "はずれ：" << hazure/count_loop << endl;
    cout <<fixed << setprecision(0)<< "平均消費金額" << (count_loop*500) / N<< endl;

    return 0;
}
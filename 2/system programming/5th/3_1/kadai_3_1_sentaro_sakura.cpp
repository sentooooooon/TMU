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
    double p = 0.5;
    int seed = 22140003;
    mt19937 mt(seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);
    //set variable
    int count_loop = 0;
    int count_tousen = 0;
    //create a file for ratio
    ofstream of("kadai_3_1_ratio.csv");
    of << "n,tousen" << endl;

    //create a file for  average spent
    ofstream file("kadai_3_1_average_expenditure.csv");
    file << "n,average" << endl;


    while(1){
        double prob = distribution(mt);
        if(prob > p){
            count_tousen++;
        }
        else if(prob < p){
        }
        count_loop++;
        if(10000 < count_tousen && count_tousen < 100000 ){
            double N = n;
            double tousen = count_tousen;
            double hazure = count_loop - count_tousen;
            of << count_tousen << "," << tousen/count_loop << endl; 
            file << count_tousen << "," << (count_loop*500.0) / count_tousen << endl;
        }
        if(count_tousen == n)break;
    }
    double N = n;
    double tousen = count_tousen;
    double hazure = count_loop - count_tousen;
    cout << fixed << setprecision(3) <<  "あたり：" << tousen/count_loop << "はずれ：" << hazure/count_loop << endl;
    cout <<fixed << setprecision(0)<< "平均消費金額" << (count_loop*500) / N<< endl;
    return 0;
}
#include<iostream>
#include<random>
#include<cmath>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;


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
    int count_people = 0;
    int countfour = 0;
    double spentmoney = 0;
    //create a file for ratio
    ofstream of("kadai_3_3_ratio.csv");
    of << "n,tousen" << endl;

    //create a file for  average spent
    ofstream file("kadai_3_3_average_expenditure.csv");
    file << "n,average" << endl;


    while(1){
        spentmoney += 500.0;
        countfour++;
        count_loop++;
        double prob = distribution(mt);
        if(prob > p){
            count_tousen++;
            countfour = 0;
            count_people++;
            of << count_people << "," << count_tousen / double(count_loop) << endl;
            file << count_people <<"," << spentmoney/ double(count_tousen) << endl;

        }
        else if(countfour == 4 && prob < p){
            countfour = 0;
            count_people++;
            of << count_people << "," << count_tousen / double(count_loop) << endl;
            file << count_people <<"," << spentmoney/ double(count_tousen) << endl;
        }
        if(count_people == n)break;
    }
    double N = n;
    double tousen = count_tousen;
    double hazure = count_loop - count_tousen;
    cout << fixed << setprecision(3) <<  "あたり：" << tousen/count_loop << "はずれ：" << hazure/count_loop << endl;
    cout <<fixed << setprecision(0)<< "平均消費金額" <<  spentmoney/ n<< endl;
    return 0;
}
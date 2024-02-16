#include<iostream>
#include<random>
#include<cmath>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

int main(){

    //set probability
    int seed = 22140003;
    mt19937 mt(seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    //create csv files
    ofstream of("kadai_3_A_average_expenditure.csv");
    ofstream file("kadai_3_A_profits.csv");

    //header
    of << "prob,average" << endl;
    file << "prob,profit" << endl;

    for(double p = 0.1; p<= 0.9; p += 0.1){
        //set variables
        int count_people = 0;
        double price = 500;
        int n = 100000;
        double prof = 20;
        double reven = 0;
        int tousen = 0;
        int count = 0;
        int count_loop = 0;
        double spentmoney = 0;
        //main loop
        while(1){
            spentmoney += 500;
            count_loop++;
            reven += prof;
            if(0 <= count_people && count_people < 5000){
                if(p > distribution(mt)){
                    tousen++;
                    count_people++;
                }
                else{
                    count_people++;
                }
            }
            else if (5000 <= count_people && count_people < 8000){
                count++;
                if(p > distribution(mt)){
                    tousen++;
                    count_people++;
                    count = 0;
                }
                else if(count == 2){
                    count_people++;
                    count = 0;
                }
            }
            else if(8000 <= count_people && count_people < 9500){
                count++;
                if(p > distribution(mt)){
                    tousen++;
                    count_people++;
                    count = 0;
                }
                else if(count == 4){
                    count_people++;
                    count = 0;
                }
            }
            else{
                count++;
                if(p > distribution(mt)){
                    tousen++;
                    count_people++;
                    count = 0;
                }
                else if(count == 6){
                    count_people++;
                    count = 0;
                }
            }
            if(count_people == n){
                break;
            }
        }

        of << p << "," << spentmoney / count_people << endl;
        file << fixed << setprecision(1) << p << "," << reven << endl;
        }
    return 0;
}
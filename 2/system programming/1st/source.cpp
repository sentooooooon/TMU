#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
    ofstream of("Hikaku.csv");
    of << "n,human,comp"<< endl;
    double n = 0;
    double human =  10.0*n;
    double comp = pow(10,-8) * (n*n);
    while(n < 10000){
        of << n << "," << human << "," << comp << endl;
        n++;
        human =  10.0*n;
        comp = pow(10,-8) * (n*n);
    }
    return 0;
    

}
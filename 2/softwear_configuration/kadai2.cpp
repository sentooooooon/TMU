#include<iostream>
#include<cmath>

using namespace std;

void calc(double *xn){
    *xn = sqrt(*xn) + 1;
}

int main(){
    double x0;
    for(int i =0; i < 20; i++){
        calc(&x0);
        cout << x0 << endl;
    }

    return 0;
}
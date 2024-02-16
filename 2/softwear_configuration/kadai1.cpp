#include<iostream>
#include<cmath>

using namespace std;

#define PI 3.1414
#define area(r) (M_PI * r * r)

int main(){
    double r = 30.0;
    double area = area(r);

    cout << area <<endl;
    return 0;
}
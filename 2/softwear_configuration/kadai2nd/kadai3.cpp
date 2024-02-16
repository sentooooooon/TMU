#include<iostream>
#include<cmath>

using namespace std;

class f{
    private:
    double a_;
    public:
    f(double p) : a_{p} {}
    ~f() {}

    double operator()(const double &x) const {
        return cos(a_ * x * x);
    }
};

double func(double x){
    double a = 1.0;
    return cos(a * x * x);
}

double fresnel(double (*F)(double)){
    double sum = 0;
    double gosa = 0.01;
    double d = 0.01;
    double x0 = 0;
    int count = 0;
    while(true){
        double X = (F(x0) + F(x0 + d));
        x0 += d;
        sum += X;
        count ++;
        if(count == 1000)break;
        cout << X << endl;
    }
    return sum;
}

int main(){
    cout << fresnel(func) << endl;
    return 0;
}
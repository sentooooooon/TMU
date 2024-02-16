#include<iostream>

using namespace std;

class COMPLEX
{
private:
double re_;
double im_;
public:
COMPLEX(double re = 0, double im = 0) : re_{re}, im_{im} {}
double re() { return re_; }
double im() { return im_; }
friend COMPLEX operator+(const COMPLEX&, const COMPLEX&);
friend COMPLEX operator-(const COMPLEX&, const COMPLEX&);
friend COMPLEX operator*(const COMPLEX&, const COMPLEX&);
friend COMPLEX operator/(const COMPLEX&, const COMPLEX&);
COMPLEX& operator+=(const COMPLEX&);
COMPLEX conjugate();
friend ostream& operator<<(ostream &os, const COMPLEX& c);
}; 



COMPLEX operator-(const COMPLEX& X, const COMPLEX& Y){
    double r = X.re_ - Y.re_;
    double i = X.im_ - Y.im_;
    COMPLEX Z(r,i);
    return Z;
}

COMPLEX operator*(const COMPLEX& X, const COMPLEX& Y){
    double r = (X.re_*Y.re_) - (X.im_*Y.im_);
    double i = (X.im_*Y.re_) + (X.re_*Y.im_);
    COMPLEX Z(r,i);
    return Z;
}

COMPLEX operator/(const COMPLEX& X, const COMPLEX& Y){
    double r = ((X.re_*Y.re_) + (X.im_*Y.im_)) / ((Y.im_*Y.im_) + (Y.re_*Y.re_));
    double i = ((-X.re_*Y.im_) + (X.im_*Y.re_)) / ((Y.im_*Y.im_) + (Y.re_*Y.re_));
    COMPLEX Z(r,i);
    return Z;
}


int main(){

    COMPLEX x(3,10);
    COMPLEX y(1,1);

    //minus
    COMPLEX z = x - y;
    cout << z.re() << " + " <<  z.im() << "i" << endl;

    //multiple
    z = x * y;
    cout << z.re() << " + " <<  z.im() << "i" << endl;

    //devide
    z = x / y;
    cout << z.re() << " + " <<  z.im() << "i" << endl;

    return 0;
}
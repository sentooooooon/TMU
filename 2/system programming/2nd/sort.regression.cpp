#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
int main(){
    ifstream f_in("sort.time.tsv");
    int C = 6;
    string str[C];
    int K = 1024*8;
    double time[C][K];
    double a[C];
    double b[C];
    // assuming C columns.
    int c = 0;
    string buff;
    while(f_in >> buff){
        if(c < C){
            str[c] = buff;
        }else{
            time[c%C][c/C - 1] = stod(buff);
        }
        ++c;
    }
    K = c/C -1 ;
    cout << "#trial: "<< K<< "\n";
    for(int k=0;k<K;k++){
        for(int j=0;j<C;++j){
            cout << time[j][k] << ", ";
        }
        cout << "\n";
    }
    ofstream f_out("sort.regression.tsv");

    for(int j=0;j<C;++j){
        f_out << str[j] << "-R";
        if(j != C-1){
            f_out << "\t";
        }
        else{
            f_out << "\n";
        }

        // 回帰直線を求める．
        double S_xy=0, S_xx=0, A_x=0, A_y=0;
        for(int k=0;k<K;++k){
            double x = log(time[0][k]);
            double y = log(time[j][k]);
            A_x += x;
            A_y += y;
        }
        A_x /= K;
        A_y /= K;
        for(int k=0;k<K;++k){
            double x = log(time[0][k]);
            double y = log(time[j][k]);
            S_xy += (x-A_x)*(y-A_y);
            S_xx += (x-A_x)*(x-A_x);
        }
        a[j] = S_xy/S_xx;
        b[j] = A_y - a[j]*A_x;
        cout << "a, b: " << a[j] << ", " << b[j] << "\n";
    }

    double x = 32;
    for(int k=0;k<K;++k){ 
        x *= 1.2;
        for(int j=0;j<C;++j){
            f_out << exp(log(x)*a[j]+b[j]);
            if(j != C-1){
                f_out << "\t";
            }
            else{
                f_out << "\n";
            }
        }
    }
}
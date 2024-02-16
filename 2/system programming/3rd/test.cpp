#include <iostream>
#include <random>
using namespace std;

// ランダム数を生成して配列に格納する関数
void rnd_exp(double A[], int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    
    for (int i = 0; i < n; i++) {
        double r = distribution(gen);
        A[i] = r;
    }
}

int main() {
    int n = 1000;
    double B[n];  // double型の配列を宣言
    rnd_exp(B, n); // 関数を呼び出して乱数を生成し、Aに格納

    for(int i =0; i< 30 ; i++){
        cout << B[i] << endl;
    }
    return 0;
}

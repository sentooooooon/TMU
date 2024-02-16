#include<iostream>
#include<random>
#include<fstream>
using namespace std;
void rnd_exp(int A[], int B[], int n){
    int rd = 22140003;
    mt19937 mt(rd);
    uniform_int_distribution<int> distribution(1,3);
    for(int i = 0; i < n; i++){
        int r = distribution(mt);
        int s = distribution(mt);
        A[i] = r;
        B[i] = s;
    }
}
//bool MontyHallNOCHANGE(){}
int main(){
    ofstream of("kadai_2_3.csv");
    of << "n,nochange,change" << endl;
    //1を正解のボックスとする．
    int n = 10000;
    int A[n], B[n];
    int change = 0;
    int Nochange = 0;
    rnd_exp(A,B,n);
    for(int j = 0;j<n;j++){
        if(A[j]==1)Nochange++;
        if(B[j]==2 || B[j] == 3)change++;
        of << j + 1 << ","<< Nochange<<","<< change << endl;
    }
    cout << "変更なし" << Nochange/(n+0.0) << endl;
    cout << "変更あり" << change/(n+0.0) << endl;
    return 0;
    
}
#include<iostream>
#include<string>
#include<random>

using namespace std;
int main(){
    random_device rd;
    mt19937_64 mt(rd());
    uniform_int_distribution<char> cU(30,80);
    string msg;
    for(int i = 0; i < 100; i++){
        char c = cU(mt);
        msg = msg + c;
    }
    cout << msg << endl;
}
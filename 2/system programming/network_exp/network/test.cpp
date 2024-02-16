#include<iostream>
#include<random>
#include<string.h>
#define BUFF_SIZE 64

using namespace std;
int main(){
    char buff[BUFF_SIZE];
    random_device rd;
    mt19937_64 mt(rd());
    uniform_int_distribution<char> cU(30, 80);
    int j = 0;;
    while(true){
        j++;
        if(j == 10)break;
        for(int i =0; i < 64; i++){
            char c = cU(mt);
            buff[i] = c;
        }
        cout << buff<< endl;
        memset(buff, 0 , sizeof(buff));
    }
    return 0;
}
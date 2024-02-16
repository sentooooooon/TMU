#include<stdio.h>
#include<iostream>
using namespace std;
#define PERCENT(a) a * 100

int a = 100;

void countstatic(){
    static int c;
    c++;
    cout << c << endl;
}
int main(){
    for(int i = 0; i < 10; i++){
        countstatic();
    }
}
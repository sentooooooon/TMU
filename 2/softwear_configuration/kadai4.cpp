#include<iostream>

using namespace std;

void plus5_with_pointer(int* x){
    *x = *x + 5;
}

void plus5_without_pointer(int x){
    x = x + 5;
}

int main(){
    int x = 5;
    int *p = &x;

    cout << "ポインタを使ってアドレスを使う方法はいくつかある．以下では２つのやり方を示す．" << endl;
    cout << "xのアドレス: "<< p << endl;
    cout << "xのアドレス: "<< &x << endl;
    cout << "値を表す方法も示す．" << endl;
    cout << "xの値: " << *p << endl;

    cout << "xの値を関数を用いて変更したいときのもポインタが使える．" << endl;
    plus5_without_pointer(x);
    cout << "ポインタを使わない関数で＋５した場合、x: " << x << endl;
    plus5_with_pointer(p);
    cout << "ポインタを使った関数で＋５したとき、x: " << x << endl;

    cout << "----------------------------------------" << endl;
    cout << "ポインタは配列についても有用である．" << endl;
    int vals[] = { 1 ,1 ,2 ,3 ,5, 8, 13};
    int *valptr = vals;
    cout << "配列の先頭の値: "<<*valptr << endl;
    for(int i = 0; i < 7; i++){
        cout  << *(valptr + i) << " ";
    }
    return 0;


    return 0;
}
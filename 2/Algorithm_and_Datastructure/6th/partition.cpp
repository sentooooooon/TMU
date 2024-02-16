#include<iostream>
using namespace std;

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;
    for (int j = p; j <= r-1 ; j++){
        if (A[j] <= x){
            i = i+1;
            //A[i] と A[j] を交換
            int a = A[i];
            A[i] = A[j];
            A[j] = a;
            }
        }
    //A[i+1] と A[r] を交換
    int b = A[i+1];
    A[i+1] = A[r];
    A[r] = b;
    return i+1;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i= 0; i < n; i++){
        cin >> A[i];
    }
    int I = partition(A,0,n-1);
    //cout << I << endl;
    for(int i= 0; i < n; i++){
        if(i == I){
            cout << "[" << A[I] << "] ";
        }
        else if(i == n-1 ){
            cout << A[i] <<endl;
        }
        else{
        cout << A[i] << " ";}}
    return 0;
}
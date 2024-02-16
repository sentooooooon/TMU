#include<iostream>
using namespace std;

int linersearch(int A[], int n, int B[], int m){
    int c = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                c++;
                break;
            }
        }
    }
    return c;
}

int main(){
    int n, m;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        int a; 
        cin >> a;
        A[i] = a;
    }
    cin >> m;
    int B[m];
    for(int j  = 0; j < m; j++){
        int b;
        cin >> b;
        B[j] = b;
    }
    cout << linersearch(A,n,B, m ) << endl;
    return 0;
}
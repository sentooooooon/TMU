#include<iostream>
using namespace std;

bool solve(int i, int m, int A[], int n){
    if (m == 0){
      return true;
}
   if (i >= n){
     return false;
     }
   bool res = solve(i + 1, m, A,n) || solve(i + 1, m - A[i], A,n);
   return res;
}
int main(){
    int n, m;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cin >> m;
    int B[m];
    for(int j = 0; j < m; j++){
        cin >> B[j];
    }

    cout << solve(0,m,A,n) << endl;
}
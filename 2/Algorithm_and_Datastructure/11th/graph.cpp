#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n, 0));

    for(int i = 0; i < n ; i++){

        //uは番号、ｋが出次数
        int u,k;
        cin >> u >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            A[i][x-1] = 1;
        }
    }

    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j != n-1){
            cout << A[i][j] << " ";}
            else{
                cout << A[i][j] << endl;
            }
        }
    }

    return 0;
}
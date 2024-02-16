#include <iostream>
#include<limits>
using namespace std;

int main(){
    //入力
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        a[i] = b;
    }

    int Min = a[0];
    int Max = numeric_limits<float>::infinity();
    Max = Max * -1;
    for(int j =1; j < n; j++){
        Max = max(Max, a[j] - Min);
        Min = min(Min, a[j]);
    }
    
    cout << Max << endl;

    return 0;

}
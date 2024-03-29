#include <algorithm>
#include<iostream>
#include<climits>
using namespace std;


int main(){
	int n,minimum,tmp;
	cin >> n;
	int table[n][n];
	int data[n][2];

	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++)table[i][k] = 0;
		cin >> data[i][0] >> data[i][1];
	}

	for(int i=n-2;i>=0;i--){
		for(int k=0;k<=i;k++){
			if(i==n-2){
				table[n-i-1][k] = data[k][0]*data[k][1]*data[k+1][1];
		}else{
				minimum = INT_MAX;
				for(int p=0;p<=n-i-2;p++){
					tmp=(table[p][k]+table[n-i-p-2][k+p+1])+(data[k][0]*data[k+p][1]*data[k+n-i-1][1]);
					minimum = min(minimum,tmp);
				}
				table[n-i-1][k] = minimum;
			}
		}
	}

	cout << table[n-1][0] << endl;

    return 0;
}
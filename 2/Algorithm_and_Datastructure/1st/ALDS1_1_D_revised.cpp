#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
using namespace std;
static const int MAX = 100000;
static const int RMAX = 100000;

int main(){
	int R[MAX], n;
	int maxv, minv;
	
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++) R[i] = rand()%RMAX;

	chrono::system_clock::time_point t0, t1, t2, t3;


	//Program 2.1

	
	cout << "Program 2.1:" << endl;
	maxv = -RMAX;
	t0 = chrono::system_clock::now(); //計測開始

	//Program 2.1をここに実装

	for (int j = 1; j < n-1; j++){
		for (int i = 0 ; i < j-1; i++){
			maxv = max(maxv, R[j]-R[i]);
		}
	}

	t1 = chrono::system_clock::now(); //計測終了
	cout << "maxv = " << maxv << endl;
	auto time1 = chrono::duration_cast<chrono::microseconds>(t1 - t0).count();
	cout << "time = " << time1 << " [マイクロ秒]" << endl;


	//Program 2.2
	cout << "Program 2.2:" << endl;
	maxv = -RMAX;
	minv = R[0];
	t2 = chrono::system_clock::now(); //計測開始

	//Program 2.2をここに実装
	
	minv = R[0];
	for( int j = 1 ; j < n-1 ;j++){
		maxv = max(maxv, R[j]-minv);
		minv = min(minv, R[j]) ;
	}

	t3 = chrono::system_clock::now(); //計測終了
	cout << "maxv = " << maxv << endl;
	auto time2 = chrono::duration_cast<chrono::microseconds>(t3 - t2).count();
	cout << "time = " << time2 << " [マイクロ秒]" << endl;

	return 0;
}

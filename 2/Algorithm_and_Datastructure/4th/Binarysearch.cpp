#include<iostream>
using namespace std;

int binarysearch(int A[], int n, int B[], int m){
    int c = 0;
    for(int i = 0; i< m ; i ++){
        int key = B[i];
        int left = 0;
        int right  = n-1;
        while(left <= right){
            int mid  = (left + right ) / 2;
            if(A[mid] == key){
                c++;
                break;

            }
            else if(A[mid] > key){
                right  = mid-1;
            }
            else if(A[mid] < key){
                left = mid + 1;
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
    cout << binarysearch(A,n,B, m ) << endl;
    return 0;
}
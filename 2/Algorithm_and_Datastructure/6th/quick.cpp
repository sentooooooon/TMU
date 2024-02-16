#include<iostream>
#include<utility>
#include<string>

using namespace std;

struct card{
    int val;
    string suit;
    int order;
};

int partition(card A[], int p, int r){
    int x = A[r].val;
    int i = p-1;
    for (int j = p; j <= r-1 ; j++){
        if (A[j].val <= x){
            i = i+1;
            //A[i] と A[j] を交換
            card a = A[i];
            A[i] = A[j];
            A[j] = a;
            }
        }
    //A[i+1] と A[r] を交換
    card b = A[i+1];
    A[i+1] = A[r];
    A[r] = b;
    return i+1;
}

void quicksort(card A[], int p, int r){
    if (p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }    
}


int main(){
    int n;
    cin >> n;
    card P[n];
    
    for(int i= 0; i < n; i++){
        cin >> P[i].suit >> P[i].val;
        P[i].order = i;
    }
    //cout << "-----------------------" << endl;
    
    quicksort(P,0, n-1);
    bool CheckStable = true;

    for(int i= 1; i < n; i++){
        if(P[i-1].order >= P[i].order && P[i].val == P[i-1].val){
            CheckStable = false;
        }
    }

    if(CheckStable){
        cout << "Stable" << endl;
    }
    else{cout << "Not stable" << endl;
    }

    for(int i= 0; i < n; i++){
        cout <<  P[i].suit << " " << P[i].val <<endl;
    }
    

    return 0;
}

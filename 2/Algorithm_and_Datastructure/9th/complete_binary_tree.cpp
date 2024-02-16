#include<iostream>
#include<vector>
using namespace std;

void PrintHeap(const vector<int>& Heap , int index ){
    int ParentIndex = index / 2;
    int LeftChild = 2* index ;
    int RightChild = (2*index) + 1;

    cout << "node " << index << ": key = " << Heap[index - 1] << ", ";
    if(ParentIndex > 0){
        cout << "parent key = " << Heap[ParentIndex - 1] << ", ";
    }
    if(LeftChild <= Heap.size()){
        cout << "left key = " << Heap[LeftChild - 1] << ", ";
    }
    if(RightChild <= Heap.size()){
        cout << "right key = " << Heap[RightChild - 1] << ", ";
    }
    cout << endl;

}

int main(){
    int n;
    cin >> n;
    vector<int> heap(n);

    for(int i =0; i < n; i++){
        cin >> heap[i];
    }
    for(int i = 1; i <= n; i++){
        PrintHeap(heap, i);
    }
    return 0;
}
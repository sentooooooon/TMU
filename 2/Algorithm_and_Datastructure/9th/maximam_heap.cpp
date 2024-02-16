#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void maxHeapify(vector<int>& A, int H, int i){
    int l = 2 * i;
    int r = l + 1;
    int largest;
// 左の子、自分、右の子で値が最大のノードを選ぶ
    if (l <= H && A[l - 1] > A[i - 1]){
        largest = l;
}   else{ 
        largest = i;
}
    if (r <= H && A[r - 1] > A[largest - 1]){
        largest = r;
}

    if (largest != i){
        swap(A[i - 1] , A[largest - 1]);
        maxHeapify(A, H ,largest);
        } // 再帰的に呼び出し
}

void buildMaxHeap(vector<int>& A, int H) {
    for (int i = H / 2; i >= 1; --i) {
        maxHeapify(A, H, i);
    }
}

int main(){
    int H;
    cin >> H;

    vector<int> heap(H);
    for (int i = 0; i < H; ++i) {
        cin >> heap[i];
    }

    buildMaxHeap(heap, H);

    // max-ヒープの節点の値を出力
    for (int i = 0; i < H; ++i) {
        cout << " " << heap[i];
    }
    cout << endl;
    return 0;
}
#include<iostream>
using namespace std;

struct Node{
    int parent = -1;
    int left = -1;
    int right = -1;
};

void preorder(int x, Node A[]){
    cout << " " << x;
    if(A[x].left != -1){
        preorder(A[x].left, A);
    }
    if(A[x].right != -1){
        preorder(A[x].right, A);
    }
}

void inorder(int x, Node A[]){
    if(A[x].left != -1){
        inorder(A[x].left, A);
    }
    cout << " " << x;
    if(A[x].right != -1){
        inorder(A[x].right, A);
    }
}

void postorder(int x, Node A[]){
    if(A[x].left != -1){
        postorder(A[x].left, A);
    }
    if(A[x].right != -1){
        postorder(A[x].right, A);
    }
    cout << " " << x ;
}

int findroot(int x, Node A[]){
    if(A[x].parent == -1){
        return x;
    }
    else{
        return findroot(A[x].parent, A);
    }
}

int main(){
    int n;
    cin >> n;
    Node A[n];
    for(int i = 0; i < n; i ++){
        int id, left, right;
        cin >> id >> left >> right;
        A[id].left = left;
        A[id].right = right;
        if(left != -1) A[left].parent = id;  // 左の子が存在する場合のみ親を設定
        if(right != -1) A[right].parent = id;  // 右の子が存在する場合のみ親を設定
    }

    int root = findroot(0, A);

    cout << "Preorder" << endl;
    preorder(root, A);cout << endl;
    cout << "Inorder" << endl;
    inorder(root, A);cout << endl;
    cout <<"Postorder" << endl;
    postorder(root, A);
    cout << endl;
    return 0;
}

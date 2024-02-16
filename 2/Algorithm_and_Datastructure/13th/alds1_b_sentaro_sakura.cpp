#include<iostream>
#include<string>
using namespace std;

struct Node{
    int left = -1;
    int right = -1;
    int parent = -1;
    int sibling = -1;
};

int height(int x, Node A[]){

    int left = A[x].left;
    int right = A[x].right;
    if(A[x].left == -1 && A[x].right == -1){
        return 0;
    }
    if(left == -1 && right != -1){
        return 1 + height(right, A);
    }
    else if(left != -1 && right == -1){
        return 1 + height(left, A);
    }
    else{
    return 1 + max(height(left, A), height(right, A));}
}

int depth(int x, Node A[]){
    if(A[x].parent == -1){
        return 0;
    }

    return 1 + depth(A[x].parent, A);
}

int degree(int x, Node A[]){
    int a = 0;
    if(A[x].left != -1)a++;
    if(A[x].right != -1)a++;
    return a;
}
string judge(int x, Node A[]){
        if(A[x].parent == -1){
            return "root";
        }
        else if(A[x].left != -1 || A[x].right != -1){
            return "internal node";
        }
        else{
            return "leaf";
        }
    }
int main(){
    int n;
    cin >> n;

    Node A[n];

    for(int i =0; i < n; i ++ ){
        Node a;
        int id, left, right;
        cin >> id >> left >> right;
        A[id].left = left;
        A[id].right = right;
        A[left].parent = id;
        A[right].parent = id;
        A[left].sibling = right;
        A[right].sibling = left;
    }

    
    for(int i = 0; i < n; i++){
        cout << "node " << i << ": ";
        cout << "parent = " << A[i].parent << ", ";
        cout << "sibling = " << A[i].sibling << ", ";
        cout << "degree = " << degree(i,A) << ", ";
        cout << "depth = " << depth(i, A) << ", ";
        cout << "height = " << height(i, A) << ", ";
        cout << judge(i, A) << endl;
    }

     return 0;

}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct node{
    int parent = -1;
    vector<int> children;
    int num_of_children;
    int depth=0;
};

string judgetype(node N){
    if(N.parent != -1 && !N.children.empty()){
        return "internal node";
    }
    else if(N.parent != -1){
        return "leaf";
    }
    else{
        return "root";
    }
}

int find_depth(node A[], int n, int i){
    int c = 0;
    node B[n];
    for(int j = 0; j < n ; j++){
        B[j] = A[j];
    }
    while(B[i].parent != -1){
        c++;
        B[i] = B[B[i].parent];
    }
    return c;
}

int main(){
    int parent, num_of_children;
    int n;
    cin >> n;
    node A[n];
    for(int i = 0; i< n; i++){
        int id;
        cin >> id >> num_of_children;
        A[id].num_of_children = num_of_children;
        A[id].children.resize(num_of_children);
        if(num_of_children){
            for(int j = 0; j < num_of_children; j++){
                int child_id;
                cin >> child_id;
                A[id].children[j] = child_id;
                A[child_id].parent = id;
                A[child_id].depth = A[id].depth + 1;
            }
        }
    }

    for(int k = 0; k < n ; k++){
        cout << "node "<<  k << ": " <<  "parent = " << A[k].parent << ", " << "depth = " << find_depth(A, n, k) << ", " << judgetype(A[k]) << ", [";
        for(int a = 0; a < A[k].children.size(); a++){
            if(a == A[k].children.size() - 1 ){
                cout << A[k].children[a] ;
            }
            else{
                cout << A[k].children[a] << ", " ;
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
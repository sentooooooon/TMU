#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Node{
    double key_;
    Node* left;
    Node* right;
    Node* parent;

    //Node(double k) : key_(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* root;

void insert(double key){
    Node *x, *y ,*z;
    z = new Node();
    z->key_ = key;
    z->left = NULL;
    z->right = NULL;
    y = NULL;
    x = root;

    while(x != NULL){
        y = x;
        if(z->key_ < x->key_){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    z->parent = y;

    if(y == NULL){
        root = z;
    }
    else if(z->key_ < y->key_){
        y->left = z;
    }
    else{
        y->right = z;
    }

}

Node* find_node(int x){
    Node *x;

  x = root;
  while (x != NIL && x->key != key) {
    if (key < x->key) x = x->left;
    else x = x->right;
  }
  
  return x;
}

void preorder(Node* node) {
  if (node == NULL) return;
  const int k = node->key_;
  cout << " " << k;
  if (node->left != NULL) preorder(node->left);
  if (node->right != NULL) preorder(node->right); 
}

void inorder(Node* node) {
  if (node == NULL) return;
  if (node->left != NULL) inorder(node->left);
  const int k = node->key_;
  cout << " " << k;
  if (node->right != NULL) inorder(node->right);
}

void print() {
  inorder(root);
  cout << endl;
  preorder(root);
  cout << endl;
}

int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i< n; i++){
        cin >> s;
        int x;
        if(s == "insert"){
            cin >> x;
            insert(x);
        }
        else if( s == "print"){
            print();
        }
        else if( s == "find"){
            cin >> x;
            if(find_node(x)){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}
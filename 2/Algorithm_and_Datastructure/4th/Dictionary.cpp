#include<iostream>
#include<set>
#include<string>
using namespace std;


int main(){
    int n;
    cin >> n;
    string S,T;
    set<string> dict;
    for(int i =0;i < n ; i ++){
        cin >> S >> T;
        if(S == "insert"){
            dict.insert(T);
        }
        else if(dict.count(T)){
            cout <<"yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}
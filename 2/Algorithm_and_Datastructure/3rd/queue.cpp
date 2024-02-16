#include <bits/stdc++.h>
using namespace std;
int main(){
    int q, n, time;
    time =0;
    cin >> n >> q;
    queue<pair<string,int> > Q;
    for(int i=0;i<n;i++){
        string a;
        int b;
        cin >> a >> b;
        Q.push(make_pair(a,b));
    }
    while(!Q.empty()){
        pair<string,int> task = Q.front();
        Q.pop();
        if(task.second <= q){
            cout << task.first << " " << time + task.second << endl;
            time += task.second;
        }
        else{
            task.second -= q;
            time += q;
            Q.push(task);
        }
        
    }
return 0;
}

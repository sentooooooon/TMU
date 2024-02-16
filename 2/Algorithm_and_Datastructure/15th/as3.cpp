#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

int G[34][34];
vector<bool> visited(34, false);

void makeGraph(){
    ifstream file("graph_edgelist.txt");
    while(!file.eof()){
        int a,b;
        file >> a >>b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
}

bool isvisited(){
    int c = 0;
    for(int i = 0;i < visited.size(); i++){
        if(visited[i])c++;
    }
    if(c == visited.size())return true;
    else{
        return false;
    }
}

bool isConnected(){
    queue<int> q;
    int start = 0;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        visited[v] = true;
        q.pop();
        for(int i = 0; i < 34; i++){
            if(visited[i])continue;
            else if(G[v][i] == 1){
                q.push(i);
            }
        }
    }

    if(isvisited())return true;
    else{
        return false;
    }



}
int main(){
    makeGraph();

    cout << "Sentaro Sakura" << endl;
    cout << "student number: 22140003" << endl;
    if(isConnected()){
        cout << "This graph is connected" << endl;
    }
    else{
        cout << "This graph is not connected" << endl;
    }

    return 0;
}
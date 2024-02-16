#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void shortestDistances(int n, const vector<vector<int>>& adjList) {
    vector<int> distances(n + 1, INF);  
    vector<bool> visited(n + 1, false); 
    queue<int> q;
    q.push(1);
    distances[1] = 0;
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (distances[i] == INF) {
            cout << i << " -1" << endl;
        } else {
            cout << i << " " << distances[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjList(n + 1);

    for (int i = 1; i <= n; ++i) {
        int u, k;
        cin >> u >> k;
        adjList[u].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> adjList[u][j];
        }
    }

    shortestDistances(n, adjList);

    return 0;
}

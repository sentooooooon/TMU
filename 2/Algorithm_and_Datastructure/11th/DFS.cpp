#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> d, f;
int timestamp = 1;

void dfs(int v, int n) {
    d[v] = timestamp++;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            visited[i] = true;
            dfs(i, n);
        }
    }

    f[v] = timestamp++;
}

int main() {
    int n;
    cin >> n;

    graph.resize(n, vector<int>(n, 0));

    visited.resize(n, false);
    d.resize(n, 0);
    f.resize(n, 0);

    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            graph[u - 1][v - 1] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, n);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }

    return 0;
}

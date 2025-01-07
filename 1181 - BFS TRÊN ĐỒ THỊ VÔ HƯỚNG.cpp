#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int V, E;

void BFS(int u) {
    visited[u] = 1;
    queue<int> q;
    q.push(u);

    while (q.size()) {
        u = q.front();
        q.pop();

        cout << u << ' ';

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int start;
        cin >> V >> E >> start;

        adj.assign(V + 5, vector<int>());
        visited.assign(V + 5, 0);

        while (E--) {
            int u, v;
            cin >> u >> v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        BFS(start);
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<int> visited;    
int V, E;               

void DFS(int u) {
    cout << u << ' ';
    visited[u] = 1;

    for (int v : adj[u]) 
        if (!visited[v]) 
            DFS(v);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
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

        DFS(start);
        cout << endl; 
    }
    return 0;
}

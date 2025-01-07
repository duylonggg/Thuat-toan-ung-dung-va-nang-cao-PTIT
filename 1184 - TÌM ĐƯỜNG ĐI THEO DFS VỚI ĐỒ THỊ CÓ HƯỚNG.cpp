#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<bool> visited;     
vector<int> path;        
int V, E;

void DFS(int u) {
    visited[u] = true;

    for (int v : adj[u])
        if (!visited[v]) {
            path[v] = u; 
            DFS(v);
        }
}

void find_path(int end) {
    if (!visited[end]) {
        cout << -1 << endl; 
        return;
    }

    stack<int> stk;
    stk.push(end);

    while (path[end]) {
        end = path[end];
        stk.push(end);
    }

    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int start, end;
        cin >> V >> E >> start >> end;

        adj.assign(V + 1, vector<int>());
        visited.assign(V + 1, false);
        path.assign(V + 1, 0); 

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        DFS(start);

        find_path(end);
    }
    return 0;
}

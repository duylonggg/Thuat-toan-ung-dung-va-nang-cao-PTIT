#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define ll          long long
#define pb          push_back

int V, E;
vector<vector<int>> adj;
vector<bool> visited;

void BFS(int u, int end) {
    visited[u] = true;
    queue<int> q;
    q.push(u);

    while (q.size()) {
        u = q.front();
        q.pop();

        if (u == end) {
            visited[end] = true;
            return;
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    tests() {
        cin >> V >> E;

        adj.assign(V + 1, vector<int>());

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        int q;
        cin >> q;
        while (q--) {
            int start, end;
            cin >> start >> end;

            visited.assign(V + 1, false);

            BFS(start, end);

            cout << (visited[end] ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define ll          long long
#define pb          push_back

int V, E;
vector<vector<int>> adj;
vector<int> visited, path;

void BFS(int u) {
    visited[u] = 1;
    queue<int> q;
    q.push(u);

    while (q.size()) {
        u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
                path[v] = u;
            }
        }
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

    while (stk.size()) {
        cout << stk.top() << ' ';
        stk.pop();
    }

    cout << endl;
    return;
}

int main() {
    tests() {
        int start, end;
        cin >> V >> E >> start >> end;

        adj.assign(V + 1, vector<int>());
        visited.assign(V + 1, 0);
        path.assign(V + 1, 0);

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
        }

        BFS(start);

        find_path(end);
    }
    return 0;
}
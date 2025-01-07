#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define ll          long long
#define pb          push_back

int V, E;
vector<vector<int>> adj;
vector<int> low, num;
vector<bool> joint;
vector<int> bridge;
int timeDFS = 0;

void DFS(int u, int par) {
    int child = 0;
    low[u] = num[u] = ++timeDFS;

    for (int v : adj[u]) {
        if (v == par)
            continue;

        if (!num[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] == num[v])
                bridge[v] = u;
            ++child;

            if (u == par) {
                if (child > 1)
                    joint[u] = true;
            }
            else if (low[v] >= num[u]) {
                joint[u] = true;
            }
        }
        else 
            low[u] = min(low[u], num[v]);
    }
}

int main() {
    tests() {
        cin >> V >> E;

        timeDFS = 0;
        bridge.assign(V + 1, 0);
        joint.assign(V + 1, false);
        adj.assign(V + 1, vector<int>());
        low.assign(V + 1, 0);
        num.assign(V + 1, 0);

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        DFS(1, 1);

        for (int i = 1; i <= V; ++i)
            if (joint[i])
                cout << i << ' ';

        cout << endl;
    }
    return 0;
}
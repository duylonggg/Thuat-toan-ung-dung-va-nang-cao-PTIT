#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define ll          long long
#define pb          push_back

int V, E;
vector<vector<int>> adj;
vector<int> joint, num, low;
vector<pair<int, int>> bridges;
int timeDFS;

void DFS(int u, int par) {
    low[u] = num[u] = ++timeDFS;
    int child = 0;

    for (int v : adj[u]) {
        if (v == par)
            continue;

        if (!num[v]) { 
            ++child;
            DFS(v, u);

            low[u] = min(low[u], low[v]);

            if (low[v] == num[v])
                bridges.pb({min(u, v), max(u, v)});

            if (u == par and child > 1) 
                joint[u] = 1;
            else if (low[v] >= num[u]) 
                joint[u] = 1;
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    tests() {
        cin >> V >> E;

        timeDFS = 0;
        joint.assign(V + 1, 0);
        num.assign(V + 1, 0);
        low.assign(V + 1, 0);
        adj.assign(V + 1, vector<int>());
        bridges.clear();

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        for (int i = 1; i <= V; ++i) 
            if (!num[i])
                DFS(i, i);

        sort(bridges.begin(), bridges.end(), [&] (pair<int, int> p1, pair<int, int> p2) {
            if (p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        });

        if (bridges.empty())
            cout << -1;
        else
            for (auto &[u, v] : bridges)
                cout << u << ' ' << v << ' ';
        cout << endl;
    }
    return 0;
}

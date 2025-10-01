#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, rad;
vector<int> order;
vector<bool> seen;
int n, m;

void kosaraju(int u, int pass) {  // pass = 1 (original graph), 2 (reverse graph)
    seen[u] = true;
    vector<int> &neighbor = (pass == 1) ? adj[u] : rad[u];

    for (auto &v : neighbor) {
        if (!seen[v]) kosaraju(v, pass);
    }
    if (pass == 1) order.push_back(u);  // similar to toposort
    // can print u for SCC when pass == 2
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int>());
    rad.assign(n, vector<int>());

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;  // if based-index 1
        adj[u].push_back(v);
        rad[v].push_back(u);
    }

    seen.assign(n, false);  // first pass
    order.clear();          // record the post-order of the origin graph
    for (int u = 0; u < n; ++u) {
        if (!seen[u]) {
            kosaraju(u, 1);
        }
    }

    int num_scc = 0;        // second pass
    seen.assign(n, false);  // explore the SCCs

    for (int u = n - 1; u >= 0; --u) {
        if (!seen[order[u]]) {
            ++num_scc;
            kosaraju(order[u], 2);
        }
    }
    cout << num_scc << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
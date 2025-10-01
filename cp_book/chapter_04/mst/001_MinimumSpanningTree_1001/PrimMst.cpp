#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;  // if based-index 1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int mst = 0;

    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});  // first: weight, second: vertex
    vector<bool> seen(n, false);

    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (seen[u]) continue;
        seen[u] = true;
        mst += w;

        for (auto &[v, wt] : adj[u]) {
            if (seen[v]) continue;
            q.push({wt, v});
        }
    }

    cout << mst << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
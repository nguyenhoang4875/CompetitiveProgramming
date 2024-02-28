#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Topological Order
 * Solution: Using dfs
 *
 * TC: O(n)
 * MC: O(n)
 */

int n, m;
vector<vector<int>> graph;
vector<bool> seen;
vector<int> topoSort;

void dfs(int cur) {
    seen[cur] = true;
    for (auto x : graph[cur]) {
        if (!seen[x]) {
            dfs(x);
        }
    }
    topoSort.push_back(cur);
}

void addEdge(int u, int v) { graph[u].push_back(v); }

void solve() {
    cin >> n >> m;
    graph = vector<vector<int>>(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    topoSort = vector<int>();
    seen = vector<bool>(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) dfs(i);
    }

    reverse(topoSort.begin(), topoSort.end());

    for (auto e : topoSort) {
        cout << e << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
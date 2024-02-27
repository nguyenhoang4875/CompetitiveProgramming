#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Give a graph check if it has cycle or not
 *
 * TC: O(V + E)
 * MC: O(V)
 */

int n, m;
vector<vector<int>> graph;
vector<bool> seen;
bool hasCycle;

bool dfs(int cur, int par) {
    seen[cur] = true;
    for (auto x : graph[cur]) {
        if (!seen[x]) {
            bool sub = dfs(x, cur);
            if (sub) return true;
        } else if (x != par) {
            return true;
        }
    }
    return false;
}

int addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);  // remove if directed graph
}

void solve() {
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    seen = vector<bool>(n + 1, false);
    while (m--) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    hasCycle = false;
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            hasCycle = dfs(i, -1);
        }
        if (hasCycle) break;
    }
    if (hasCycle) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
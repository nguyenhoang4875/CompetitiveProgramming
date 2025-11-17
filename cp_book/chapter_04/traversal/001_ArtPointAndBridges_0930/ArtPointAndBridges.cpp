#include <bits/stdc++.h>

using namespace std;

/**
 * Tarjan Algorithm
 * tin: time to in that node when traversal using dfs
 * low: low-link time of the smallest (lowest) node reachable from that node
 *  when doing a Dfs(including itself)
 */

vector<vector<int>> adj;
vector<pair<int, int>> bridges;
vector<int> arts, tin, low;
vector<bool> seen;
int root, root_children, timer;

void artBridge(int u, int p) {
    seen[u] = true;
    tin[u] = low[u] = timer++;

    for (auto& v : adj[u]) {
        if (!seen[v]) {
            if (u == root) ++root_children;  // special case for root
            artBridge(v, u);

            if (low[v] >= tin[u]) arts[u] = 1;               // for articulation point
            if (low[v] > tin[u]) bridges.push_back({u, v});  // for bridge

            low[u] = min(low[u], low[v]);  // subtree alway update

        } else if (v != p) {               // backedge (non-trivial cycle)
            low[u] = min(low[u], tin[v]);  // then can update
        }
    }
};

void solve() {
    int n, m;  // n : vertices, m: edges
    cin >> n >> m;
    adj.assign(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;  // if based index 1: u, v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    seen.assign(n, false), tin.assign(n, 0), low.assign(n, 0);
    arts.assign(n, 0), bridges.clear();
    timer = 0;

    for (int u = 0; u < n; u++) {
        if (!seen[u]) {
            root = u, root_children = 0;
            artBridge(root, root);
            arts[root] = root_children > 1;  // special case
        }
    }

    vector<int> art_vertex;
    for (int u = 0; u < n; ++u) {
        if (arts[u] == 1) art_vertex.push_back(u);
    }

    // print art_vertex
    cout << "Articulation Points: \n";
    for (auto& x : art_vertex) cout << x + 1 << " ";
    cout << '\n';

    // print bridges
    cout << "Bridges: \n";
    for (auto& [u, v] : bridges) cout << u + 1 << " " << v + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Bellman-Ford Algorithm
 * The Bellman–Ford algorithm finds shortest paths from a starting node to all
 * nodes of the graph. The algorithm can process all kinds of graphs, provided
 * that the graph does not contain a cycle with negative length. If the graph
 * contains a negative cycle, the algorithm can detect this.
 *
 * The weight edges can be negative
 *
 * Note that this algorithm can be used to search for a negative cycle
 * in the entire graph regardless of the starting node
 * This source for directed graph.
 *
 * TC: O(n * m) // n: number of vertices, m: number of edges
 * MC: O(m)
 *
 */

//*** START CODING ***//
const int oo = 1e9;
int n, m, s;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void bellmanFord(int start) {
    dist.assign(n, oo);
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool modified = false;
        for (int u = 0; u < n; ++u) {
            if (dist[u] == oo) continue;
            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w >= dist[v]) continue;
                dist[v] = dist[u] + w;
                modified = true;
            }
        }
        if (!modified) break;
    }
}

bool isNegCycleBellmanFord(int start) {
    bellmanFord(start);
    for (int u = 0; u < n; ++u) {
        if (dist[u] == oo) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m >> s;
    adj.assign(n, vector<pair<int, int>>());
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        // --u, --v; // if base-index 1
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // if undirected edge
    }
    bellmanFord(s);
    bool hasCycle = isNegCycleBellmanFord(s);
    cout << "Negative Cycle Exist: " << (hasCycle ? "Yes" : "No") << '\n';
    if (!hasCycle) {
        for (int u = 0; u < n; ++u) {
            cout << "SSSP(" << s << " " << u << "): " << dist[u] << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

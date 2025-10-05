#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
 * Problem: Minimum Spanning Tree for each edge
 * Solution: Kruskal + Lca
 *
 * TC: O(m log m)
 */

const int N = 200005;
const int LOG = 20;

struct Edge {
    int u, v, w, id;
};

int n, m;
int mst = 0;
Edge edges[N];
int f[N];

// DSU Structure
struct Dsu {
    vector<int> parent, size;
    Dsu(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int find(int v) { return parent[v] = (v == parent[v] ? v : find(parent[v])); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

vector<pair<int, int>> adj[N];
int up[N][LOG];
int maxEdge[N][LOG];
int depth[N];

void dfs(int v, int p, int w) {
    up[v][0] = p;
    maxEdge[v][0] = w;
    for (int i = 1; i < LOG; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        maxEdge[v][i] = max(maxEdge[v][i - 1], maxEdge[up[v][i - 1]][i - 1]);
    }
    for (auto [to, weight] : adj[v]) {
        if (to != p) {
            depth[to] = depth[v] + 1;
            dfs(to, v, weight);
        }
    }
}

int getMaxEdge(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int res = 0;
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            res = max(res, maxEdge[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return res;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            res = max({res, maxEdge[u][i], maxEdge[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    return max({res, maxEdge[u][0], maxEdge[v][0]});
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    Dsu dsu(n);
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    sort(edges + 1, edges + m + 1, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    for (int i = 1; i <= m; ++i) {
        int u = edges[i].u, v = edges[i].v;
        int w = edges[i].w;
        if (dsu.unite(u, v)) {
            mst += w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
    }

    // Initialize Binary Lifting
    depth[1] = 0;
    dfs(1, 1, 0);

    for (int i = 1; i <= m; ++i) {
        int u = edges[i].u, v = edges[i].v;
        int w = edges[i].w;
        int max_w = getMaxEdge(u, v);
        f[edges[i].id] = (dsu.find(u) == dsu.find(v)) ? w - max_w : 0;
    }

    for (int i = 1; i <= m; ++i) {
        cout << mst + f[i] << '\n';
    }

    return 0;
}
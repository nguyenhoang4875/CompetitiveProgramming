template <typename T = int>
struct Lca {
    int root;
    int LG;
    vector<int> depth;
    vector<vector<int>> up;

    Lca(vector<vector<int>>& adj, int _root) {
        root = _root;
        int n = adj.size();
        LG = __lg(n);
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LG + 1));
        dfs(root, adj);
    }

    void dfs(int u, vector<vector<int>>& adj) {
        for (auto v : adj[u]) {
            if (v == up[u][0]) continue;
            depth[v] = depth[u] + 1;

            up[v][0] = u;  // parent of v is u
            for (int j = 1; j <= LG; ++j) { up[v][j] = up[up[v][j - 1]][j - 1]; }

            dfs(v, adj);
        }
    }

    int getLca(int u, int v) {
        if (depth[u] != depth[v]) {
            if (depth[u] < depth[v]) swap(u, v);

            int k = depth[u] - depth[v];
            for (int j = 0; (1 << j) <= k; ++j) {
                if ((k >> j) & 1) u = up[u][j];
            }
        }
        if (u == v) return u;

        int k = __lg(depth[u]);
        for (int j = k; j >= 0; --j) {
            if (up[u][j] != up[v][j]) u = up[u][j], v = up[v][j];
        }
        return up[u][0];
    }

    int getDist(int u, int v) {
        int common = getLca(u, v);
        return depth[u] + depth[v] - 2 * depth[common];
    }
};
#include <bits/stdc++.h>

using namespace std;

/**
 * Problem: Find second best spanning tree
 * https://vjudge.net/problem/UVA-10600
 *
 * TC: O(V * E)
 */

struct Dsu {
    // MUST READ: Okay for both base-index: 0, 1
    int n;
    vector<int> parent, size;

    Dsu() {};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1, 1);  // init size = 1
        for (int v = 0; v <= n; v++) makeSet(v);
    }

    void makeSet(int v) { parent[v] = v; }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int getSize(int v) { return size[findSet(v)]; }
};

using edge = array<int, 3>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;  // if based-index 1
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    int cnt = 0;
    int mst = 0;
    Dsu dsu(n);

    vector<edge> mst_edges;

    for (int i = 0; i < m; ++i) {
        auto& [w, u, v] = edges[i];
        int root_u = dsu.findSet(u);
        int root_v = dsu.findSet(v);
        if (root_u == root_v) continue;
        mst += w;
        dsu.unionSet(u, v);
        mst_edges.push_back(edges[i]);
        ++cnt;
        if (cnt == n - 1) break;
    }

    int second_mst = 2e9;
    for (auto& me : mst_edges) {
        Dsu ds(n);
        int new_cnt = 0;
        int new_mst = 0;
        for (auto& e : edges) {
            if (me == e) continue;
            auto& [nw, nu, nv] = e;
            if (ds.findSet(nu) == ds.findSet(nv)) continue;
            new_mst += nw;
            ds.unionSet(nu, nv);
            ++new_cnt;
            if (new_cnt == n - 1) break;
        }
        if (new_cnt == n - 1) second_mst = min(second_mst, new_mst);  // only update if it is mst
    }
    cout << mst << " " << second_mst << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

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

    for (int i = 0; i < m; ++i) {
        auto [w, u, v] = edges[i];
        int root_u = dsu.findSet(u);
        int root_v = dsu.findSet(v);
        if (root_u == root_v) continue;
        mst += w;
        dsu.unionSet(u, v);
        ++cnt;
        if (cnt == n - 1) break;
    }
    cout << mst << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
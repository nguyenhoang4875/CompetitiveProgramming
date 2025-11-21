#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

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
    int tc = 0;
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if (!n and !m and !q) return;
        if (tc) cout << el;
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
        vector<vii> adj(n);

        for (int i = 0; i < m; ++i) {
            auto [w, u, v] = edges[i];
            int root_u = dsu.findSet(u);
            int root_v = dsu.findSet(v);
            if (root_u == root_v) continue;
            mst += w;
            dsu.unionSet(u, v);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            ++cnt;
            if (cnt == n - 1) break;
        }
        // find max_edge inside mst for path: u -> t
        function<int(int, int, int, int)> findMaxEdge = [&](int u, int p, int t, int cur_max) {
            if (u == t) return cur_max;
            for (auto& [v, w] : adj[u]) {
                if (v == p) continue;
                int res = findMaxEdge(v, u, t, max(cur_max, w));
                if (res != -1) return res;
            }
            return -1LL;
        };

        cout << "Case #" << ++tc << el;
        while (q--) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            int ans = findMaxEdge(u, u, v, -1);
            if (ans == -1) cout << "no path" << el;
            else cout << ans << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
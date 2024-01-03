#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Lowest Common Ancestor (LCA)
 * Solution: Brute force
 *
 * TC: O(n)
 * MC: O(n)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;

vvi graph;
vi parent, depth;

void dfs(int cur, int par) {
    parent[cur] = par;
    depth[cur] = depth[par] + 1;
    for (auto x : graph[cur]) {
        if (x != par) {
            dfs(x, cur);
        }
    }
}

int lca(int u, int v) {
    if (u == v) return u;
    if (depth[u] < depth[v]) swap(u, v);

    // depth[u] >= depth[v]
    int diff = depth[u] - depth[v];
    while (diff--) {
        u = parent[u];
    }

    // depth[u] == depth[v]: keep climbing until u == v
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

void solve() {
    int n, m;
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    parent.clear();
    parent.resize(n + 1);
    depth.clear();
    depth.resize(n + 1);

    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0);

    // For(i, 1, n) {
    //     cout << i << " " << depth[i] << el;
    // }

    cout << lca(9, 12) << el;
    cout << lca(9, 11) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
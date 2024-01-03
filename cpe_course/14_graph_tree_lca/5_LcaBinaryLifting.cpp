#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Lowest Common Ancestor (LCA)
 * Solution: Brute force
 *
 * TC: O(log n) for each time get lca
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
const int LOG = 20;

int up[ms][LOG];
vvi children;
vi depth;

// use this func when pushing two edges: children[u].pb(v), children[v].pb(v)
// careful the case cur = 0 => need par != -1
void dfs(int cur, int par) {
    depth[cur] = depth[par] + 1;

    up[cur][0] = par;
    For(j, 1, LOG - 1) { up[cur][j] = up[up[cur][j - 1]][j - 1]; }
    for (auto x : children[cur]) {
        if (x != par) {
            dfs(x, cur);
        }
    }
}

// use this func when pushing one edge: children[u].pb(v)
void dfs(int a) {
    for (auto b : children[a]) {
        depth[b] = depth[a] + 1;

        up[b][0] = a;
        For(j, 1, LOG - 1) { up[b][j] = up[up[b][j - 1]][j - 1]; }
        dfs(b);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    Ford(j, LOG - 1, 0) {
        if ((diff >> j) & 1) {
            u = up[u][j];
        }
    }
    if (u == v) return u;

    // depth[u] == depth[v]
    Ford(j, LOG - 1, 0) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int lengthFromUtoV(int u, int v) {
    int common = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[common];
}

void solve() {
    int n, m;
    cin >> n >> m;
    children.clear();
    children.resize(n + 1);
    memset(up, 0, sizeof(up));
    depth.clear();
    depth.resize(n + 1);

    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        children[u].pb(v);
    }
    // dfs(1, 0);
    dfs(1);

    // For(i, 1, n) {
    //     cout << i << " : ";
    //     For(j, 0, 4) {
    //         cout << up[i][j] << " ";
    //     }
    //     cout << el;
    // }

    cout << lca(9, 12) << el;
    cout << lca(9, 11) << el;

    cout << lengthFromUtoV(8, 10) << el;
    cout << lengthFromUtoV(9, 10) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Path querys (https://cses.fi/problemset/task/1138/)
 * Solution: Euler tour + Fenwick Tree
 *
 * TC: O(q * log (n))
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

struct FenwickTree {
    int n;
    vector<int> t;
    FenwickTree(int _n) {
        n = _n;
        t.resize(n + 1, 0);
    }
    // custom this function if needed
    int combine(int x, int y) {
        return x + y;
        // return max(x, y); // if max tree
    }

    void add(int i, int val) {
        while (i <= n) {
            t[i] = combine(t[i], val);
            i += i & (-i);
        }
    }
    int get(int i) {
        int val = 0;
        while (i > 0) {
            val = combine(val, t[i]);
            i -= i & -i;
        }
        return val;
    }
    int query(int l, int r) { return get(r) - get(l - 1); }

    void set(int i, int val) { add(i, val - query(i, i)); }
};

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, q;
vvi graph;
vi tin, tout, flat;
int timer = 0;
int val[ms];

void dfs(int cur, int par) {
    tin[cur] = ++timer;
    for (auto x : graph[cur]) {
        if (x != par) {
            dfs(x, cur);
        }
    }
    tout[cur] = timer;
}

void solve() {
    cin >> n >> q;
    For(i, 1, n) cin >> val[i];

    graph = vvi(n + 1);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    tin = vi(n + 1);
    tout = vi(n + 1);
    flat = vi(n + 1);
    dfs(1, 0);

    For(i, 1, n) { cout << i << " " << tin[i] << " " << tout[i] << el; }

    FenwickTree ft(n + 1);
    For(i, 1, n) {
        ft.add(tin[i], val[i]);
        ft.add(tout[i] + 1, -val[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int node, v;
            cin >> node >> v;
            ft.add(tin[node], v - val[node]);
            ft.add(tout[node] + 1, -(v - val[node]));
            val[node] = v;

        } else if (type == 2) {
            int node;
            cin >> node;
            int ans = ft.get(tin[node]);
            cout << ans << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
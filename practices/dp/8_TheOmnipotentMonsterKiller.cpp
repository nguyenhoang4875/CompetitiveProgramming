#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/1988/problem/D
 */

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7, LG = 20;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    vvi adj(n);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    };
    vvi f(LG, vi(n + 1));  // f[i][v] min cost at i-th round for vertex v

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int i = 0; i < LG; i++) f[i][u] = (i + 1) * a[u];

        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);

            int mn1 = oo, mn2 = oo;
            for (int i = 0; i < LG; i++) {
                mn2 = min(mn2, f[i][v]);
                if (mn2 < mn1) swap(mn1, mn2);
            }

            for (int i = 0; i < LG; i++) {
                int val = mn1;
                if (val == f[i][v]) val = mn2;
                f[i][u] += val;
            }
        }
    };
    dfs(0, -1);

    int ans = oo;
    for (int i = 0; i < LG; i++) ans = min(ans, f[i][0]);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
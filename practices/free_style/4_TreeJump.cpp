#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/2070/problem/D
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 998244353;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vvi adj(n);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        int v = i;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi d(n + 1);

    function<void(int, int, int)> dfs = [&](int cur, int par, int level) {
        d[cur] = level;
        for (auto x : adj[cur]) {
            if (x == par) continue;
            dfs(x, cur, level + 1);
        }
    };

    dfs(0, 0, 0);
    int m = *max_element(all(d));
    vvi layer(m + 1);
    for (int i = 0; i <= n; i++) {
        if (d[i]) layer[d[i]].pb(i);
    }
    vi f(n + 1);  // f[v]  has layer: l = sum f[u] (has layer l + 1) - f[x] (child of v) + 1 (for v)
    for (auto v : layer[m]) f[v] = 1;  // basecase

    for (int i = m - 1; i >= 1; i--) {
        int totNext = 0;
        for (auto u : layer[i + 1]) {
            totNext += f[u];
            totNext %= mod;
        }
        for (auto v : layer[i]) {
            for (auto x : adj[v]) {
                if (d[x] != i + 1) continue;
                f[v] = (f[v] - f[x] + mod) % mod;
            }
            f[v] = (totNext + f[v] + 1) % mod;
        }
    }
    int ans = 0;
    for (auto v : adj[0]) {
        ans += f[v];
        ans %= mod;
    }
    ans = (ans + 1) % mod;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}
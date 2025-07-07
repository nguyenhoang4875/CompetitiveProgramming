#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/contest/1592/problem/C
 */

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    vvi adj(n + 1);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int xorAll = 0;
    For(i, 1, n) { xorAll ^= a[i]; }
    if (xorAll == 0) {
        cout << "YES" << el;
        return;
    }
    if (k == 2) {
        cout << "NO" << el;
        return;
    }

    // find xor subtree equal xorAll
    vi f(n + 1);
    map<pii, bool> rm;

    bool found = false;
    int cnt = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        if (found) return;
        f[u] = a[u];
        for (auto& v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            f[u] ^= f[v];
        }
        if (f[u] == xorAll) {
            f[u] = 0;
            cnt += (p != 0);
        }
    };
    dfs(1, 0);
    if (cnt >= 2) cout << "YES" << el;
    else cout << "NO" << el;
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
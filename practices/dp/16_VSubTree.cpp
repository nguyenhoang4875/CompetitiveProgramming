#include <bits/stdc++.h>
#define int long long

/**
 * https://atcoder.jp/contests/dp/tasks/dp_v
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
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi f(n + 1, 1);  // f[u] number way that subtree at root u is black
    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            f[u] = f[u] * (f[v] + 1) % m;
        }
    };

    vi f2(n + 1, 1);  // f2[u] number way out of sub tree root i
    function<void(int, int)> dfs2 = [&](int u, int p) {
        int k = adj[u].size();
        vi pre(k + 2, 1), suf(k + 2, 1);

        for (int i = 0; i < k; i++) {
            int v = adj[u][i];
            pre[i + 1] = pre[i] * (v == p ? 1 : (f[v] + 1)) % m;
        }
        for (int i = k - 1; i >= 0; i--) {
            int v = adj[u][i];
            suf[i] = suf[i + 1] * (v == p ? 1 : (f[v] + 1)) % m;
        }

        int idx = 0;
        for (auto v : adj[u]) {
            if (v == p) {
                idx++;
                continue;
            }
            f2[v] = ((f2[u] + 1) * pre[idx] % m) * suf[idx + 1] % m;
            dfs2(v, u);
            idx++;
        }
    };

    dfs(1, -1);
    f2[1] = 0;
    dfs2(1, -1);

    for (int u = 1; u <= n; u++) {
        int ans = (f[u] * (f2[u] + 1)) % m;
        cout << ans << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
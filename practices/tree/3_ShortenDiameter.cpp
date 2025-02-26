#include <bits/stdc++.h>
#define int long long
/**
 * https://atcoder.jp/contests/agc001/tasks/agc001_c
 */

using namespace std;

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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, k;

void solve() {
    cin >> n >> k;
    vvi adj(n);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi f(n, 0);

    function<int(int, int, int, int)> dfs = [&](int u, int p, int cc, int d) {
        int ret = 0;
        if (d > k) ret++;
        for (auto v : adj[u]) {
            if (v == p) continue;
            ret += dfs(v, u, cc, d + (v != cc));
        }
        return ret;
    };
    int ans = n;
    if (k & 1) {
        k /= 2;
        for (int u = 0; u < n; u++) {
            for (auto v : adj[u]) {
                ans = min(ans, dfs(u, u, v, 0));
            }
        }
    } else {
        k /= 2;
        for (int u = 0; u < n; u++) {
            ans = min(ans, dfs(u, u, u, 0));
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
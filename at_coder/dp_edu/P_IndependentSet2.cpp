#include <bits/stdc++.h>
#define int long long

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
int n;

void solve() {
    cin >> n;
    // cout << "n = " << n << el;
    vvi adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vvi f(n, vi(2));

    function<void(int, int)> dfs = [&](int u, int par) {
        f[u][0] = 1, f[u][1] = 1;  // 0: White, 1: Black

        for (auto v : adj[u]) {
            if (v == par) continue;
            dfs(v, u);

            f[u][0] = f[u][0] * (f[v][0] + f[v][1]) % mod;
            f[u][1] = f[u][1] * f[v][0] % mod;
        }
    };

    dfs(0, -1);
    int ans = (f[0][0] + f[0][1]) % mod;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
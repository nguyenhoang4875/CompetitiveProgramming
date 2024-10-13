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
int n, k;

void solve() {
    cin >> n >> k;

    vvi f(n, vi(3, 1));
    vvi adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= k; i++) {
        int u, color;
        cin >> u >> color;
        u--, color--;
        for (int j = 0; j < 3; j++) {
            if (j != color) {
                f[u][j] = 0;
            }
        }
    }

    function<void(int, int)> dfs = [&](int cur, int par) {
        for (auto x : adj[cur]) {
            if (x == par) continue;
            dfs(x, cur);

            f[cur][0] = f[cur][0] * (f[x][1] + f[x][2]) % mod;
            f[cur][1] = f[cur][1] * (f[x][0] + f[x][2]) % mod;
            f[cur][2] = f[cur][2] * (f[x][0] + f[x][1]) % mod;
        }
    };
    dfs(0, -1);
    int ans = (f[0][0] + f[0][1] + f[0][2]) % mod;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
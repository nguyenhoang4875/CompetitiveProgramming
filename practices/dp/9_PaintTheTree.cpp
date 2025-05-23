#include <bits/stdc++.h>
#define int long long

using namespace std;

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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vvi adj(n);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    };

    vi d(n);
    vi par(n);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        par[u] = p;
        for (auto v : adj[u]) {
            if (v == p) continue;
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    };
    dfs(a, a);
    if (a == b) {
        int ans = 2 * (n - 1) - *max_element(all(d));
        cout << ans << el;
        return;
    }
    int cur = b;
    vi path;
    while (cur != a) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.pb(a);
    reverse(all(path));
    int m = path.size();
    d = vi(n, 0);
    int mid = path[(m - 1) / 2];
    dfs(mid, mid);
    int maxD = *max_element(all(d));
    int ans = 2 * (n - 1) - maxD + (m - 1 - (m - 1) / 2);
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
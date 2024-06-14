#include <bits/stdc++.h>
#define int long long

using namespace std;
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vvi adj(n + m + 5);
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        v += n;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (k == 1) {
        cout << m + n << " " << 0 << el;
        return;
    }
    vii v;
    for (int i = 1; i <= n + m; i++) {
        if (adj[i].size() == 0) continue;
        v.push_back({i, adj[i].size()});
    }

    sort(all(v), [&](pii p1, pii p2) { return p1.S > p2.S; });
    int vx = n, vy = m;
    int ans = 0;
    vii vpx;
    vii vpy;
    for (auto e : v) {
        if (e.F <= n) {
            ans += vx * e.S;
            vpx.pb({e.S, vx});
            vx--;
        } else {
            ans += vy * e.S;
            vpy.pb({e.S, vy});
            vy--;
        }
    }
    map<int, int> mx, my;  // degree and value
    for (auto [b, v] : vpx) {
        if (!mx.count(b)) {
            mx[b] = v;
        } else
            mx[b] = min(mx[b], v);
    }

    for (auto [b, v] : vpy) {
        if (!my.count(b)) {
            my[b] = v;
        } else
            my[b] = min(my[b], v);
    }

    int minDiff = oo;
    for (int u = 1; u <= n; u++) {
        int b = adj[u].size();
        for (auto v : adj[u]) {
            int bv = adj[v].size();
            minDiff = min(minDiff, mx[b] + my[bv]);
        }
    }
    cout << ans << " " << ans - minDiff << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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
    int n;
    cin >> n;
    vvi adj(n + 1);
    vi bac(n + 1);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        bac[u]++;
        bac[v]++;
    }
    int x = -1;
    For(i, 1, n) {
        if (bac[i] == 2) {
            x = i;
            break;
        }
    }
    if (x == -1) {
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
    int l = adj[x][0];
    int r = adj[x][1];
    cout << l << " " << x << el;
    cout << x << " " << r << el;

    function<void(int, int, bool)> dfs = [&](int u, int p, int p2c) {
        for (auto &v : adj[u]) {
            if (v == x or v == p) continue;
            dfs(v, u, p2c ^ 1);
            if (p2c) cout << u << " " << v << el;
            else cout << v << " " << u << el;
        }
    };
    dfs(l, l, true);
    dfs(r, r, false);
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
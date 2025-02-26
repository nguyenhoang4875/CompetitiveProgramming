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
    vector<vii> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }

    vi f(n, 0);

    function<void(int, int)> dfs1 = [&](int u, int p) {
        for (auto [v, w] : adj[u]) {
            if (v == p) continue;
            dfs1(v, u);
            f[0] += w;
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int p) {
        for (auto [v, w] : adj[u]) {
            if (v == p) continue;
            f[v] += f[u] + (w ? -1 : 1);
            dfs2(v, u);
        }
    };
    dfs1(0, 0);

    dfs2(0, 0);

    vi ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() or f[i] < f[ans.back()]) {
            ans.clear();
            ans.pb(i);
        } else if (f[i] == f[ans.back()]) {
            ans.push_back(i);
        }
    }
    cout << f[ans[0]] << el;
    for (auto e : ans) {
        cout << e + 1 << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
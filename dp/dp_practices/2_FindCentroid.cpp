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
    vvi adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi f(n);  // subtree size at root i
    function<void(int, int)> dfs = [&](int u, int par) {
        f[u] = 1;
        for (auto v : adj[u]) {
            if (v == par) continue;
            dfs(v, u);
            f[u] += f[v];
        }
    };

    function<int(int, int)> findCentroid = [&](int u, int par) {
        for (auto v : adj[u]) {
            if (v == par) continue;
            if (f[v] > n / 2) return findCentroid(v, u);
        }
        return u;
    };

    dfs(0, -1);

    cout << findCentroid(0, -1) + 1 << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
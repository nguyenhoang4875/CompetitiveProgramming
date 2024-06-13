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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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
int n;
vvi adj;
vi f;
int ans;
vb seen;

void dfs(int u) {
    int mx1 = 0, mx2 = 0;
    seen[u] = true;
    for (auto v : adj[u]) {
        if (seen[v]) continue;
        dfs(v);
        f[u] = max(f[u], f[v] + 1);
    }
    // should separate calculate to othe part
    for (int v : adj[u]) {
        int deep = f[v] + 1;
        if (deep > mx1) {
            mx2 = mx1;
            mx1 = deep;
        } else if (deep > mx2) {
            mx2 = deep;
        }
    }
    ans = max(ans, mx1 + mx2);
}

void solve() {
    cin >> n;
    adj = vvi(n + 1);
    f = vi(n + 1, 0);
    // f[i]: max deep the subtree with root at i
    seen = vb(n + 1, false);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans = 0;
    dfs(1);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
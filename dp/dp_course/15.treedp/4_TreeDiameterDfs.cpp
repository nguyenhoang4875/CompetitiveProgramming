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
int n;
vvi adj;
int maxDist = 0;
int farNode = 0;
vb seen;

void dfs(int u, int curDist) {
    seen[u] = true;
    if (curDist > maxDist) {
        maxDist = curDist;
        farNode = u;
    }
    for (auto v : adj[u]) {
        if (!seen[v]) dfs(v, curDist + 1);
    }
};

void solve() {
    cin >> n;
    adj = vvi(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (n == 1) {
        cout << 0 << el;
        return;
    }
    maxDist = 0;
    farNode = 0;
    seen = vb(n + 1, false);
    dfs(1, 0);
    maxDist = 0;
    seen = vb(n + 1, false);
    dfs(farNode, 0);
    cout << maxDist << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    // cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
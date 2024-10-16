#include <bits/stdc++.h>
#define int long long

// #DpOnTree

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

void solve() {
    cin >> n;
    adj = vvi(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi subAns(n + 1, 0);   // max deep at i
    vi ans(n + 1, 0);      // max deep at i
    vi subSize(n + 1, 0);  // ans at i

    function<void(int, int)> dfs = [&](int u, int par) {
        int numOfNodes = 1;
        int ans = 0;
        for (int v : adj[u]) {
            if (v == par) continue;
            dfs(v, u);
            numOfNodes += subSize[v];
            ans += subSize[v] + subAns[v];
        }
        subSize[u] = numOfNodes;
        subAns[u] = ans;
    };

    function<void(int, int, int)> cal = [&](int u, int par, int ansPar) {
        ans[u] = subAns[u] + (ansPar + (n - subSize[u]));
        for (auto v : adj[u]) {
            if (v == par) continue;
            cal(v, u, ans[u] - (subAns[v] + subSize[v]));
        }
    };
    dfs(1, 0);
    cal(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
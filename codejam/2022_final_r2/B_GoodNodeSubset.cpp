#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * #DpOnTree
 * 
 * TC: O(n)
 * MC: O(n)
 */

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
int a[ms];

void solve() {
    cin >> n;
    int root = 0;
    vvi adj(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
            root = i;
        else
            adj[tmp].pb(i);
    }

    // f[i][j]: maximum value if vertex i is choose(j = 1) or not choose (j = 0)
    vvi f(n + 5, vi(2, 0));
    function<void(int)> dfs = [&](int u) {
        f[u][0] = 0;
        f[u][1] = a[u];  // choose u not choose all child of u
        for (auto v : adj[u]) {
            dfs(v);
        }
        int t = 0;
        for (auto v : adj[u]) {
            f[u][1] += f[v][0];
            t += max(f[v][0], f[v][1]);  // optional to choose v
        }

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (i == 0) {
                f[u][0] = t - max(f[v][0], f[v][1]) + f[v][1];  // force to choose v
            } else {
                f[u][0] = max(f[u][0], t - max(f[v][0], f[v][1]) + f[v][1]);
            }
        }
    };

    dfs(root);
    int ans = max(f[root][0], f[root][1]);
    cout << ans << el;
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
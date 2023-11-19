#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/HOLI/
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
vii g[ms];
int ans;

// Give us the size of the tree from the node where it is called
int dfs(int u, int parent) {
    int currentTreeSize = 1;
    for (auto p : g[u]) {
        int v = p.F;
        int w = p.S;

        // skip the parent node (which is acting as nbr)
        if (v == parent) continue;

        int childTreeSize = dfs(v, u);
        int edges = 2 * min(childTreeSize, n - childTreeSize) * w;
        ans += edges;
        // update the tree size by adding childTree size
        currentTreeSize += childTreeSize;
    }
    return currentTreeSize;
}

int tc = 0;
void solve() {
    cin >> n;
    For(i, 1, n) g[i].clear();
    int u, v, w;
    For(i, 1, n - 1) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    ans = 0;
    dfs(1, -1);
    cout << "Case #" << ++tc << ": " << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
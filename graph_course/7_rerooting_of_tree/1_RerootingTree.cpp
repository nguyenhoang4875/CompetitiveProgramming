#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Initially all vertices are white. On the first turn choose one vertex
 * and paint it black, it becomes the root node. Then each turn choose a white vertex adjacent
 * to any black vertex and paint it black. Each time choose a vertex you gain the number of points
 * equal to the size of the connected component consisting only of white vertices that contains
 * the choosen vertex. The game end when all vertex are painted black.
 * Maximize the number of points you gain
 *
 * Solution: Rerooting Tree
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
const int ms = 2e5 + 5;
int n;
vector<int> dp;   // dp[i]: the answer whe root is i
vector<int> sub;  // sub[i]: number node int the subtree
vector<vector<int>> graph;
int ans = 0;

int dfs(int cur, int par) {
    sub[cur] = 1;
    dp[cur] = 0;
    for (auto x : graph[cur]) {
        if (x != par) {
            dfs(x, cur);
            dp[cur] += dp[x];
            sub[cur] += sub[x];
        }
    }
    dp[cur] += sub[cur];
}

void rerooting(int from, int to) {
    dp[from] -= dp[to] + sub[to];
    sub[from] -= sub[to];

    dp[to] += dp[from] + sub[from];
    sub[to] += sub[from];
}

void dfsRooting(int cur, int par) {
    ans = max(ans, dp[cur]);
    for (auto x : graph[cur]) {
        if (x != par) {
            // detach node x;
            rerooting(cur, x);
            dfsRooting(x, cur);
            // attach node x
            rerooting(x, cur);
        }
    }
}

void solve() {
    cin >> n;
    dp = vi(n + 1);
    sub = vi(n + 1);
    graph = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, 0);
    dfsRooting(1, 0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
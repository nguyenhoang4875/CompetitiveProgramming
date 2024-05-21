#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://cses.fi/problemset/task/1131
 * Solution: DP on Tree
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
const int ms = 2e5 + 5;
int n;
vi gr[ms];
int f[ms], g[ms];

/*
f[cur] the diameter of the subtree of cur
g[cur] the max length of cur  to any leaf node in its subtree (max depth)

f[x] = max(f[x], max1 + max2)
max1, and max2 is first and second max depth from cur node
*/

void dfs(int cur, int par) {
    int max1 = 0, max2 = 0;

    for (int child : gr[cur]) {
        if (child != par) {
            dfs(child, cur);
            // go to leaf node and go up to root node

            g[cur] = max(g[cur], g[child] + 1);
            f[cur] = max(f[cur], f[child]);

            if (g[child] + 1 > max1) {
                max2 = max1;
                max1 = g[child] + 1;
            } else if (g[child] + 1 > max2) {
                max2 = g[child] + 1;
            }
        }
    }
    f[cur] = max(f[cur], max1 + max2);
}

void solve() {
    cin >> n;
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    dfs(1, -1);  // choose root is 1
    cout << f[1] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Distinct Colors (https://cses.fi/problemset/task/1139/)
 * Solution: Euler tour
 *
 * TC: O(q * log (n))
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
int n, q;
int ans[ms];
vvi graph;
vi tin, tout, flat;
int timer = 0;
int val[ms];
set<int> color[ms];

void dfs(int cur, int par) {
    for (auto x : graph[cur]) {
        if (x != par) {
            dfs(x, cur);
            if (color[cur].size() < color[x].size()) {
                swap(color[cur], color[x]);
            }
            for (auto item : color[x]) color[cur].insert(item);
        }
    }
    ans[cur] = color[cur].size();
}

void solve() {
    cin >> n;
    For(i, 1, n) {
        cin >> val[i];
        color[i].insert(val[i]);
    }

    graph = vvi(n + 1);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0);
    For(i, 1, n) { cout << ans[i] << " "; }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
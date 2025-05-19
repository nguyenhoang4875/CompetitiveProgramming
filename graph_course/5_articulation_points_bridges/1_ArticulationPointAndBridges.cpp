#include <bits/stdc++.h>
#define int long long
/**
 * Tarjan's Algorithm
 * https://cp-algorithms.com/graph/bridge-searching.html
 * https://cp-algorithms.com/graph/cutpoints.html
 */
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;
vector<vector<int>> graph;
set<int> artPoints;
vector<pair<int, int>> bridges;
vector<int> tin, low;
vector<bool> seen;
int timer = 0;

void dfs(int cur, int par) {
    seen[cur] = true;
    low[cur] = tin[cur] = timer++;
    int child = 0;

    for (auto x : graph[cur]) {
        if(x == par) continue;
        if (!seen[x]) {
            dfs(x, cur);
            child++;

            low[cur] = min(low[cur], low[x]);

            // bridges: low[child] > tin[parent]
            // only one path from parent to child
            if (low[x] > tin[cur]) {
                bridges.push_back({cur, x});
            }

            // articulation points: not a root
            // low[child] >= tin[parent]
            if (par != 0 and low[x] >= tin[cur]) {
                artPoints.insert(cur);
            }
        } else {
            // back edge
            low[cur] = min(low[cur], tin[x]);
        }
    }
    // root of the tree has atleast 2 children
    if (par == 0 and child > 1) {
        artPoints.insert(cur);
    }
}

void solve() {
    cin >> n >> m;
    graph = vector<vector<int>>(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    artPoints.clear();
    bridges.clear();
    tin = vector<int>(n + 1);
    low = vector<int>(n + 1);
    seen = vector<bool>(n + 1, false);

    dfs(1, 0);

    for (auto e : artPoints) {
        cout << e << el;
    }
    for (auto e : bridges) {
        cout << e.F << " " << e.S << el;
    }

    cout << el;
    for (int i = 1; i <= n; i++) {
        cout << "i = " << i << el;
        cout << tin[i] << " " << low[i] << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
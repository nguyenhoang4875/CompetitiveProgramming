#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Count number strong connected component(SCC) in DAG
 * Solution: Using Kosaraju algorithms
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
vi gr[ms], grRev[ms];
vb seen;
vi components;
vi order;

void dfs1(int a) {
    seen[a] = true;
    for (auto x : gr[a]) {
        if (!seen[x]) dfs1(x);
    }
    order.pb(a);
}

void dfs2(int a, int com) {
    seen[a] = true;
    components[a] = com;
    for (auto x : grRev[a]) {
        if (!seen[x]) dfs2(x, com);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    seen = vb(n + 1, false);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        gr[u].pb(v);
        grRev[v].pb(u);
    }
    For(i, 1, n) {
        if (!seen[i]) dfs1(i);
    }
    reverse(all(order));
    cout << "Topological ordering: " << el;
    // sort form source node to sink node
    for (auto x : order) cout << x << " ";
    cout << el;

    seen = vb(n + 1, false);
    components = vi(n + 1, 0);
    int com = 1;

    // order is sort from sink node to source node in reverse graph
    for (auto x : order) {
        if (!seen[x]) dfs2(x, com++);
    }

    For(i, 1, n) { cout << i << " " << components[i] << el; }
    cout << "total components = " << (com - 1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
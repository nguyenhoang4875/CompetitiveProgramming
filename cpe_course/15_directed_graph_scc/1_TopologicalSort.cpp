#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Topological Order
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
vb seen;
vvi graph;
vi order;

void dfs(int a) {
    seen[a] = true;
    for (auto x : graph[a]) {
        if (!seen[x]) dfs(x);
    }
    // come back from the subtree
    order.pb(a);
}

void solve() {
    int n, m;
    cin >> n >> m;
    graph = vvi(n + 1);
    seen = vb(n + 1);
    order.clear();
    For(i, 1, m) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
    }
    For(i, 1, n) {
        if (!seen[i]) dfs(i);
    }
    reverse(order.begin(), order.end());

    for (auto x : order) cout << x << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
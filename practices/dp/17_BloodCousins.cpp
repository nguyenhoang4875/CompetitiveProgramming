#include<bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/208/problem/E
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vvi adj(n + 1);
    vi roots;
    For(u, 1, n) {
        int p;
        cin >> p;
        if (p == 0) {
            roots.push_back(u);
        }
        else adj[p].pb(u);
    }

    const int LG = 19;
    vvi up(n + 1, vi(LG + 1, 0));
    int cnt = 0;
    vi depth(n + 1);
    vvi dNode(n + 1);
    vi maxTreeNode(n + 1);
    vi minTreeNode(n + 1);

    function<void(int)> dfs = [&](int u) {
        minTreeNode[u] = cnt++;
        for (auto v : adj[u]) {
            if (v == up[u][0]) continue;
            depth[v] = depth[u] + 1;
            dNode[depth[v]].push_back(cnt);
            up[v][0] = u;  // parent of v is u
            for (int i = 1; i <= LG; ++i) { up[v][i] = up[up[v][i - 1]][i - 1]; }
            dfs(v);
        }
        maxTreeNode[u] = cnt;
    };

    auto getAnc = [&](int u, int k) {
        for (int i = 0; i <= LG; ++i) {
            if ((k >> i) & 1) u = up[u][i];
        }
        return u;
    };

    auto getCousin = [&](int u, int k) {
        int p = getAnc(u, k);
        if (p == 0) return 0LL;
        int d = depth[u];
        auto low = lower_bound(all(dNode[d]), minTreeNode[p]);
        auto up = upper_bound(all(dNode[d]), maxTreeNode[p]);
        return up - low - 1;
    };

    for (auto& r : roots) {
        dfs(r);
    }

    int m;
    cin >> m;
    while (m--) {
        int v, k;
        cin >> v >> k;
        int d = depth[v];
        if (k > d) {
            cout << 0 << " ";
        }
        else {
            cout << getCousin(v, k) << " ";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
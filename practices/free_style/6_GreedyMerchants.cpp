#include <bits/stdc++.h>
#define int long long

using namespace std;

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
const int ms = 2e5 + 5, LG = 17;

void solve() {
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    map<pii, bool> isBridge;
    vii bridges;
    vb seen(n, false);
    vi tin(n, 0), low(n, 0);
    int timer = 0;
    function<void(int, int)> dfsFindBridge = [&](int cur, int par) {
        seen[cur] = true;
        low[cur] = tin[cur] = timer++;
        for (auto x : adj[cur]) {
            if (x == par) continue;
            if (seen[x]) {
                low[cur] = min(low[cur], tin[x]);
            } else {
                dfsFindBridge(x, cur);
                low[cur] = min(low[cur], low[x]);
                if (low[x] > tin[cur]) {
                    bridges.push_back({cur, x});
                    isBridge[{cur, x}] = isBridge[{x, cur}] = true;
                }
            }
        }
    };
    dfsFindBridge(0, -1);

    fill(all(seen), false);
    vi compId(n, 0);

    function<void(int, int)> dfsBuildComponent = [&](int u, int curCom) {
        compId[u] = curCom;
        seen[u] = true;

        for (int v : adj[u]) {
            if (seen[v]) continue;
            if (isBridge[{u, v}]) continue;
            dfsBuildComponent(v, curCom);
        }
    };

    int numCom = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfsBuildComponent(i, numCom);
            numCom++;
        }
    }
    vvi tree(numCom);
    for (auto& [u, v] : bridges) {
        int cu = compId[u];
        int cv = compId[v];
        tree[cu].pb(cv);
        tree[cv].pb(cu);
    }

    vvi up(numCom, vi(LG + 1, -1));
    vi depth(numCom);
    function<void(int, int)> dfsLca = [&](int cur, int par) {
        up[cur][0] = par;
        for (int i = 1; i < LG; i++) {
            if (up[cur][i - 1] != -1) { up[cur][i] = up[up[cur][i - 1]][i - 1]; }
        }

        for (int x : tree[cur]) {
            if (x == par) continue;
            depth[x] = depth[cur] + 1;
            dfsLca(x, cur);
        }
    };

    auto getLca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LG - 1; i >= 0; i--) {
            if (up[u][i] != -1 and depth[up[u][i]] >= depth[v]) { u = up[u][i]; }
        }
        if (u == v) return u;

        for (int i = LG - 1; i >= 0; i--) {
            if (up[u][i] != -1 and up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };

    auto countBridge = [&](int s, int l) {
        int a = compId[s];
        int b = compId[l];
        int lca = getLca(a, b);
        return depth[a] + depth[b] - 2 * depth[lca];
    };

    dfsLca(0, -1);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int s, l;
        cin >> s >> l;
        --s, --l;
        cout << countBridge(s, l) << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
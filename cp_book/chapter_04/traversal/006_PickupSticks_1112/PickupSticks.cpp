#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    Rep(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    vi color(n + 1);

    function<bool(int)> dfs = [&](int u) {
        color[u] = 1;
        for (auto& v : adj[u]) {
            if (color[v] == 0) {
                if (dfs(v)) return true;
            } else if (color[v] == 1) {
                return true;
            }
        }
        color[u] = 2;
        return false;
    };
    bool has_cycle = false;
    For(u, 1, n) {
        if (color[u] == 0) has_cycle |= dfs(u);
    }
    if (has_cycle) {
        cout << "IMPOSSIBLE" << el;
        return;
    }

    vi order;
    vi seen(n + 1);
    function<void(int)> topo = [&](int u) {
        seen[u] = true;
        for (auto& v : adj[u]) {
            if (!seen[v]) topo(v);
        }
        order.pb(u);
    };
    For(u, 1, n) {
        if (!seen[u]) topo(u);
    }
    reverse(all(order));
    Rep(i, order.size()) {
        cout << order[i];
        if (i != order.size() - 1) cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
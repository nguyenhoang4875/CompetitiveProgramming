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
    vector<vii> adj(n);
    Rep(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }

    vb seen(n, false);
    vi par_node(n, -1), par_edge_cost(n);

    function<void(int, int)> dfs = [&](int u, int t) {
        seen[u] = true;
        for (auto& [v, c] : adj[u]) {
            if (seen[v]) continue;
            par_node[v] = u;
            par_edge_cost[v] = c;
            dfs(v, t);
        }
    };

    int k;
    cin >> k;
    while (k--) {
        int u, v, cost;
        cin >> u >> v >> cost;
        --u, --v;
        seen.assign(n, false);
        par_node.assign(n, -1);
        par_edge_cost.assign(n, 0);

        dfs(u, v);

        vi edge_costs;
        int cur = v;
        while (cur != u) {
            int p = par_node[cur];
            int c = par_edge_cost[cur];
            edge_costs.pb(c);
            cur = p;
        }

        int base_cost = accumulate(all(edge_costs), 0LL);
        int base_edges = edge_costs.size();

        if (cost < base_cost) {
            cout << "No" << el;
            continue;
        }
        if (cost == base_cost) {
            cout << "Yes " << base_edges << el;
            continue;
        }

        cost -= base_cost;
        reverse(all(edge_costs));  // cost u -> v
        edge_costs.pop_back();     // remove cost of the last edge to v

        if (base_edges == 1) {
            cout << "No" << el;
            continue;
        }

        // need to construct cost = sum 2 * edge_costs[i] with min number of i

        vi f(cost + 1, oo);
        f[0] = 0;
        int cn = edge_costs.size();
        Rep(i, cn) {
            int dc = 2 * edge_costs[i];
            for (int t = dc; t <= cost; ++t) {
                f[t] = min(f[t], f[t - dc] + 1);
            }
        }
        if (f[cost] == oo) {
            cout << "No" << el;
        } else {
            int tot = base_edges + 2 * f[cost];
            cout << "Yes " << tot << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
        if (tcs) cout << el;
    }
    return 0;
}
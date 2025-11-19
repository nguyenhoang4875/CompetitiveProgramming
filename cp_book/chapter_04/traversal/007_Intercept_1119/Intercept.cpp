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

    vector<vii> adj(n), rad(n);
    Rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        rad[v].pb({u, w});
    }
    int s, t;
    cin >> s >> t;

    vii d1(n, {oo, -1});
    vii d2(n, {oo, -1});

    using node = array<int, 3>;  // {dist, way, vertex}
    using min_pq = priority_queue<node, vector<node>, greater<node>>;
    min_pq q1, q2;
    d1[s] = {0, 1};
    q1.push({0, 1, s});
    d2[t] = {0, 1};
    q2.push({0, 1, t});

    auto dijkstra = [&](min_pq& q, vii& dist, vector<vii>& adj) {
        while (q.size()) {
            auto [d, way, u] = q.top();
            q.pop();
            if (dist[u].F != d or dist[u].S != way) continue;  // check latest [d, way]
            for (auto& [v, w] : adj[u]) {
                int nd = d + w;
                if (nd < dist[v].F) {
                    dist[v] = {nd, way};
                    q.push({nd, way, v});
                } else if (nd == dist[v].F) {
                    dist[v] = {nd, (dist[v].S + way) % mod};
                    q.push({nd, dist[v].S, v});
                }
            }
        }
    };
    dijkstra(q1, d1, adj);
    dijkstra(q2, d2, rad);

    int SS = d1[t].F;
    int T = d1[s].S * d2[s].S;

    Rep(u, n) {
        if (d1[u].F == oo or d2[u].F == oo) continue;
        if (d1[u].F + d2[u].F != SS) continue;
        if (d1[u].S * d2[u].S % mod != T) continue;
        cout << u << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
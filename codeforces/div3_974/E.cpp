#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n, m, h;
vector<vii> adj;
vb hs;

void solve() {
    cin >> n >> m >> h;
    hs = vb(n, false);

    for (int i = 0; i < h; i++) {
        int u;
        cin >> u;
        u--;
        hs[u] = true;
    }
    adj = vector<vii>(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    auto dijkstra = [&](int start, vvi& dist) {
        auto cmp = [&](auto& a, auto& b) {
            return make_pair(dist[a.first][a.second], a) < make_pair(dist[b.first][b.second], b);
        };
        set<pair<int, int>, decltype(cmp)> q(cmp);
        dist[start][0] = 0;
        q.insert({start, 0});

        while (!q.empty()) {
            pii cur = *q.begin();
            q.erase(q.begin());
            int u = cur.F;
            int horse = cur.S | hs[u];

            for (auto& [v, nw] : adj[u]) {
                int td = horse ? nw / 2 : nw;
                int newDist = dist[u][cur.S] + td;
                if (dist[v][horse] > newDist) {
                    dist[v][horse] = newDist;
                    q.insert({v, horse});
                }
            }
        }
    };

    vvi dist1(n + 1, vi(2, oo));
    vvi dist2(n + 1, vi(2, oo));
    // debug(dist1);

    dijkstra(0, dist1);
    dijkstra(n - 1, dist2);

    int ans = oo;
    for (int i = 0; i < n; i++) {
        int val = max(min(dist1[i][0], dist1[i][1]), min(dist2[i][0], dist2[i][1]));
        ans = min(ans, val);
    }
    if (ans == oo) ans = -1;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
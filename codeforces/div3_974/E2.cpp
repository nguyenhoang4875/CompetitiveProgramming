#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#else
#define del
#define debug(x)
#endif

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
        dist[start][0] = 0;
        priority_queue<vi, vvi, greater<vi>> q;
        q.push({0, 0, start});
        vvb seen(n + 1, vb(2, false));

        while (!q.empty()) {
            vi cur = q.top();
            q.pop();
            int w = cur[0];
            int u = cur[2];
            int horse = cur[1] | hs[u];
            // if (w > dist[u][cur[1]]) continue;
            if(seen[u][cur[1]]) continue;
            seen[u][cur[1]] = true;

            for (auto& [v, nw] : adj[u]) {
                int td = horse ? nw / 2 : nw;
                int newDist = dist[u][cur[1]] + td;
                if (dist[v][horse] > newDist) {
                    dist[v][horse] = newDist;
                    q.push({newDist, horse, v});
                }
            }
        }
    };

    vvi dist1(n + 1, vi(2, oo));
    vvi dist2(n + 1, vi(2, oo));

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
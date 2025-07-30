#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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
using node = array<int, 3>;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    vector<vii> adj(n + 1);
    vi can;
    For(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        can.pb(w);
    }
    if (m == 0) {
        cout << -1 << el;
        return;
    }
    sort(all(can));
    can.erase(unique(all(can)), can.end());

    auto check = [&](int cap) {
        priority_queue<pii> q;
        q.push({a[1], 1});
        vi dist(n + 1, -1);
        dist[1] = min(a[1], cap);
        while (!q.empty()) {
            auto [cur, u] = q.top();
            q.pop();
            if (u == n) {
                return true;
            }

            if (cur < dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (dist[u] < w) continue;
                int newDist = min(cur + a[v], cap);
                if (dist[v] >= cap) continue;
                if (newDist > dist[v]) {
                    dist[v] = newDist;
                    q.push({newDist, v});
                }
            }
        }
        return false;
    };
    int l = 0, r = can.size() - 1;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(can[mid])) {
            res = can[mid];
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res << el;
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
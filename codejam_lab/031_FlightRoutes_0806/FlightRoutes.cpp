#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vii> adj(n + 1);
    For(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    priority_queue<pii, vii, greater<pii>> q;
    vector<priority_queue<int>> dist(n + 1);

    q.push({0, 1});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (dist[u].size() and d > dist[u].top()) continue;

        for (auto& [v, w] : adj[u]) {
            int nd = d + w;

            if (dist[v].size() < k or nd < dist[v].top()) {
                q.push({nd, v});
                dist[v].push(nd);
            }
            if (dist[v].size() > k) dist[v].pop();
        }
    }
    vi ans;
    while (dist[n].size()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(all(ans));
    for (auto& e : ans) cout << e << " ";
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
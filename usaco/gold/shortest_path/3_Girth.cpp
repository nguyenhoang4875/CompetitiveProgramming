#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
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

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;

void solve() {
    cin >> n >> m;
    vvi adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    function<int(int)> bfs = [&](int u) {
        int ret = oo;
        vi dist(n, oo);
        dist[u] = 0;
        queue<int> q;
        q.push({u});
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto v : adj[cur]) {
                if (dist[v] == oo) {
                    dist[v] = dist[cur] + 1;
                    q.push(v);
                } else if (dist[cur] <= dist[v]) {
                    // not use dist[cur] != oo due to 2 edges may treated as a cycle: 1-U, 1-V
                    ret = min(ret, 1 + dist[cur] + dist[v]);
                }
            }
        }
        return ret;
    };

    int ans = oo;
    for (int i = 0; i < n; i++) {
        ans = min(ans, bfs(i));
    }
    if (ans == oo) ans = -1;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
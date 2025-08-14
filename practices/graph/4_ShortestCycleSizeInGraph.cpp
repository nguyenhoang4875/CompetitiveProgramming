#include <bits/stdc++.h>

using namespace std;
/**
 * Give undirected graph with n vertices and m edges
 * Find the shortest cycle size, if no cycle print -1
 * TC: O(n * m)
 */

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

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = oo;
    auto bfs = [&](int s) {
        vi d(n + 1, -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &v : adj[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                } else if (d[u] <= d[v]) {
                    ans = min(ans, d[u] + d[v] + 1);
                }
            }
        }
    };

    For(u, 1, n) bfs(u);
    if (ans == oo) ans = -1;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
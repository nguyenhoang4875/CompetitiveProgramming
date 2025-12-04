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
    int n, c;
    cin >> n >> c;

    vi d(n), w(n);
    Rep(i, n) cin >> d[i];
    Rep(i, n) cin >> w[i];

    vvi adj(n);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vvi f(n, vi(15));  // f[u][i]: max profit at sub tree root at u with i-th o'clock

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto& v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);

            for (int t = 1; t <= 12; ++t) {
                int tv = d[v] + t;
                if (tv > 12) tv -= 12;

                // not cut the edge
                int max_val = f[v][tv];

                // cut the edge
                for (int t2 = 1; t2 <= 12; ++t2) {
                    max_val = max(max_val, f[v][t2] - c);
                }

                int tu = d[u] + t;
                if (tu > 12) tu -= 12;

                f[u][tu] += max_val;
            }
        }

        f[u][12] += w[u];
    };
    dfs(0, 0);

    int ans = 0;
    Rep(u, n) {
        For(t, 1, 12) { ans = max(ans, f[u][t]); }
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
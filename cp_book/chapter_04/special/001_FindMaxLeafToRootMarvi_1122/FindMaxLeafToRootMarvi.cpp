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
    int n;
    cin >> n;
    using node = array<int, 3>;
    vector<vector<node>> adj(n + 1);
    Rep(i, n - 1) {
        int u, v, x, t;
        cin >> u >> v >> x >> t;
        adj[u].pb({v, x, t});
        adj[v].pb({u, x, t});
    }

    map<int, int> leaf;
    For(i, 1, n) {
        double k;
        cin >> k;
        if (k != -1) leaf[i] = k;
    }

    function<double(int, int, int, double)> dfs = [&](int u, int p, int r, double max_val) {
        if (u == r) return max_val;

        for (auto& [v, x, t] : adj[u]) {
            if (v == p) continue;

            double new_max_val = max_val;
            if (t == 1) new_max_val = sqrt(new_max_val);
            new_max_val *= 100.0 / x;
            double res = dfs(v, u, r, new_max_val);
            if (res != -1.0) return res;
        }
        return -1.0;
    };

    double ans = 0;
    for (auto& [u, p] : leaf) {
        double need = dfs(u, u, 1, p);
        if (need > ans) ans = need;
    }
    cout << fixed << setprecision(5);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
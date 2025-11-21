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
    map<string, int> encode;
    encode["English"] = 0;
    Rep(i, n) {
        string s;
        cin >> s;
        encode[s] = i + 1;
    }
    n += 1;
    vector<vii> adj(n);
    for (int i = 0; i < m; ++i) {
        string su, sv;
        int w;
        cin >> su >> sv >> w;
        int u = encode[su];
        int v = encode[sv];
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    int ans = 0;
    vb seen(n);
    using node = array<int, 3>;
    priority_queue<node, vector<node>, greater<node>> q;
    q.push({0, 0, 0});  // layer, weight, vetex
    while (q.size()) {
        auto [d, w, u] = q.top();
        q.pop();
        if (seen[u]) continue;
        seen[u] = true;
        ans += w;

        for (auto& [v, ww] : adj[u]) {
            q.push({d + 1, ww, v});
        }
    }

    bool ok = true;
    Rep(i, n) ok &= seen[i];
    if (ok) cout << ans << el;
    else cout << "Impossible" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
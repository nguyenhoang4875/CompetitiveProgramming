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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    cin >> n;
    vvi adj(n);
    vb dead(n, false);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi f(n);  // subtree size at root i
    function<void(int, int)> dfs = [&](int u, int par) {
        f[u] = 1;
        for (auto v : adj[u]) {
            if (v == par or dead[v]) continue;
            dfs(v, u);
            f[u] += f[v];
        }
    };

    function<int(int, int, int)> findCentroid = [&](int num, int u, int par) {
        for (auto v : adj[u]) {
            if (v == par or dead[v]) continue;
            if (2 * f[v] > num) return findCentroid(num, v, u);
        }
        return u;
    };

    vector<char> ans(n);
    function<void(int, char)> process = [&](int u, char ch) {
        dfs(u, -1);
        int cent = findCentroid(f[u], u, -1);

        ans[cent] = ch;
        dead[cent] = true;

        for (auto v : adj[cent]) {
            if (dead[v]) continue;
            process(v, ch + 1);
        }
    };

    process(0, 'A');
    for (auto e : ans) cout << e << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
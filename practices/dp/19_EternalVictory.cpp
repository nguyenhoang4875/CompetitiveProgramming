#include<bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/contest/61/problem/D
 */

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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

void solve() {
    int n; cin >> n;
    vi w(n + 1);
    vector<vii> adj(n + 1);
    int sum = 0;
    For(i, 1, n - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({ v, c });
        adj[v].pb({ u, c });
        sum += c;
    }
    sum *= 2;

    vi f(n + 1); // maximum at root tree i
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        int mx1 = 0, mx2 = 0;
        for (auto& [v, c] : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            f[u] = max(f[u], f[v] + c);
        }
        };
    dfs(1, 0);
    cout << sum - f[1] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
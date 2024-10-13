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
int n, k;

void solve() {
    cin >> n >> k;
    vvi adj(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vvi f(n,
          vi(k + 1, 0));  // f[u][d]: number nodes from subtree root at u and has distance d from u
    int ans = 0;

    function<void(int, int)> dfs = [&](int cur, int par) {
        f[cur][0] = 1;

        for (auto x : adj[cur]) {
            if (x == par) continue;
            dfs(x, cur);

            for (int i = 0; i < k; i++) {
                ans += f[cur][i] * f[x][k - i - 1];
            }

            for (int i = 0; i < k; i++) {
                f[cur][i + 1] += f[x][i];
            }
        }
    };
    dfs(0, -1);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
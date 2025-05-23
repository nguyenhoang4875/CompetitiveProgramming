#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/problemset/problem/1740/E
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
    int n;
    cin >> n;
    vvi adj(n + 1);
    For(i, 2, n) {
        int x;
        cin >> x;
        adj[x].pb(i);
    }
    vi l(n + 1), r(n + 1);
    For(i, 1, n) { cin >> l[i] >> r[i]; }

    vvi f(n + 1, vi(2));  // f[i][1]: max non desc so far with i, f[i][0]: without i

    function<void(int, int)> dfs = [&](int cur, int par) {
        f[cur][0] = 0;
        f[cur][1] = 1;
        int mx = 0;
        for (auto x : adj[cur]) {
            if (x == par) continue;
            dfs(x, cur);
            f[cur][0] += max(f[x][0], f[x][1]);
            mx = max(mx, f[x][1]);
        }
        f[cur][1] += mx;
    };
    dfs(1, 0);
    int ans = max(f[1][0], f[1][1]);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    while (tcs--) { solve(); }
    return 0;
}
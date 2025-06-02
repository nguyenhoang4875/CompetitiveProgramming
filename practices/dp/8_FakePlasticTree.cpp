#include<bits/stdc++.h>
#define int long long
/**
 * https://codeforces.com/problemset/problem/1693/B
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
    vvi adj(n + 1);
    For(i, 2, n) {
        int x; cin >> x;
        adj[x].pb(i);
    }
    vi l(n + 1), r(n + 1);
    For(i, 1, n) {
        cin >> l[i] >> r[i];
    }

    vi f(n + 1); // f[i]: number operation at root (sub) tree i
    vi sum(n + 1); // sum[i]: sum value at vertex i

    function<int(int, int)> dfs = [&](int cur, int par) {
        int tot = 0;
        for (auto x : adj[cur]) {
            if (x == par) continue;
            tot += dfs(x, cur);
            f[cur] += f[x];
        }
        if (tot < l[cur]) {
            f[cur]++;
            return r[cur];
        }
        return min(tot, r[cur]);
    };
    dfs(1, 0);
    cout << f[1] << el
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
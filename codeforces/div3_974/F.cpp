#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#else
#define del
#define debug(x)
#endif

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n, c;

void solve() {
    cin >> n >> c;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vvi adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vvi f(n + 1, vi(2, 0));  // f[i][0] ko bao ve tai i subtree at root i
    // f[i][1]: bao ve tai i subtree at root i

    function<void(int, int)> dfs = [&](int cur, int par) {
        for (int x : adj[cur]) {
            if (x == par) continue;
            dfs(x, cur);
        }

        // ko chon cur
        int v1 = 0;
        for (auto x : adj[cur]) {
            if (x == par) continue;
            v1 += max(f[x][0], f[x][1]);
        }
        f[cur][0] = v1;

        // chon cur
        int v2 = a[cur];
        for (auto x : adj[cur]) {
            if (x == par) continue;
            v2 += max(f[x][0], f[x][1] - 2 * c);
        }
        f[cur][1] = v2;
    };
    dfs(0, -1);
    int ans = max(f[0][0], f[0][1]);
    cout << ans << el;
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
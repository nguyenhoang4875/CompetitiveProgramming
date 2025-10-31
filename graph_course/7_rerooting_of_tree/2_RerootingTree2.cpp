#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Cho cây n đỉnh.
 * Với mỗi đỉnh r làm gốc, xét mọi tập k đỉnh, lấy LCA của chúng, đếm số LCA khác nhau (gọi là cuteness của r).
 * Sum là tổng cuteness của tất cả các r (từ 1 đến n).  Yêu cầu: Tính Sum.
 * 
 * Solution: Rerooting Tree
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vvi adj(n + 2);
    Rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi vsz(n + 1);
    vi ans(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        vsz[u] = 1;

        for (auto v : adj[u]) {
            if (v != p) {
                dfs(v, u);
                vsz[u] += vsz[v];
            }
        }
    };
    dfs(1, 1);
    int cnt = 0;
    For(i, 1, n) {
        if (vsz[i] >= k) ++cnt;
    }
    ans[1] = cnt;

    function<void(int u, int v)> reroot = [&](int u, int v) {
        if (vsz[u] >= k) --cnt;
        if (vsz[v] >= k) --cnt;

        vsz[u] = n - vsz[v];
        vsz[v] = n;

        if (vsz[u] >= k) ++cnt;
        if (vsz[v] >= k) ++cnt;
    };

    function<void(int, int)> dfs1 = [&](int u, int p) {
        for (auto v : adj[u])
            if (v != p) {
                reroot(u, v);
                ans[v] = cnt;
                dfs1(v, u);
                reroot(v, u);
            }
    };
    dfs1(1, 1);
    int sum = 0;
    For(i, 1, n) { sum += ans[i]; }
    cout << sum << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1946/problem/C
 * Solution: Binary search + dfs
 */

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
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    auto check = [&](int x) {
        int numCom = 0;
        function<int(int, int)> dfs = [&](int u, int p) {
            int numNode = 1;
            for (auto v : adj[u]) {
                if (v == p) continue;
                numNode += dfs(v, u);
            }
            if (numNode >= x) {
                numCom++;
                numNode = 0;
            }
            return numNode;
        };
        dfs(0, 0);
        return numCom > k;
    };

    // number of component after remove k edges = k + 1
    // max of min node of a component = n / (k + 1)
    int l = 1, r = n / (k + 1);
    int ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}

#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/PT07X/
 * Solution: DP on Tree
 * 
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//
const int MS = 1e5 + 5;
vi g[MS];
int n;
int memo[MS][2];

int dp(int cur, bool take, int par) {
    if (memo[cur][take] != -1) return memo[cur][take];

    int ans = take;
    for (int x : g[cur]) {
        if (x != par) {
            // x is only the child vertex
            if (take) {
                ans += min(dp(x, 0, cur), dp(x, 1, cur));
            } else {
                ans += dp(x, 1, cur);
            }
        }
    }
    return memo[cur][take] = ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n -1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    memset(memo, -1, sizeof(memo));
    cout << min(dp(1, 0, -1), dp(1, 1, -1)) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
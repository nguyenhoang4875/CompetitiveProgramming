#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Number of ways n can be written by sum of 1, 2, 3
 * Solution: using dp, dp(n) the ways can be written to reach n
 *  dp(n) = dp(n - 1) + dp(n - 2) + dp(n - 3)
 *  dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n;

void solve() {
    cin >> n;
    vi dp(n + 1);
    dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
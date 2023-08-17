#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Given n friends, each can be paired or stay alone. Each friend can
 * be paired once. Find out total number of ways in which friends can be remain
 * single or be paired up. Solution: using dp, dp(n) number of the ways can be
 * pairing or not pairing of n friends dp(n) = dp(n - 1) + (n - 1) * dp(n - 2)
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
        dp[i] = dp[i - 1] + (n - 1) * dp[i - 2];
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
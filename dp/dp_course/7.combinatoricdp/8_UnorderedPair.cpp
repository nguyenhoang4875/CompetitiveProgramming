#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Unordered Pair
 * Solution:
 *  Using dp:
 *   Top down 1: O(n^3)
 *    dp(min, n) => number of way that minimum element is at least min
 *    dp(min, n) = FOR(i = min -> n) SUM(dp(i, n - i))
 *    base case: dp[0] = 1;
 *
 *   Top down 2: O(n^2)
 *    dp(min, n) => number of way that minimum element is at least min
 *    dp(min, n) = dp(min, n - min) + dp(i + 1, n); // take or not take value
 * min
 *
 *   Bottom up: O(n * n )
 *   dp(j) the number of way at j;
 *   dp(j) = FOR(i = n -> 1) (FOR(j = 1 - > j = n) SUM(dp[j - i])) (1) OR
 *   dp(j) = FOR(i = 1 -> n) (FOR(j = i - > j = n) SUM(dp[j - i])) (2)
 *
 *   (1) for dp(min, n) in recursion way: dp(min, n) = dp(min, n - min) + dp(min
 * + 1, n) (2) for dp(max, n) in recursion way: dp(max, n) = dp(max, n - max) +
 * dp(max - 1, n)
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

vvi memo;
// TC: O(n^3) after memorize
int countWaysUnordered(int min, int n) {
    if (n == 0) return 1;
    if (memo[min][n] != -1) return memo[min][n];

    int ans = 0;
    for (int i = min; i <= n; i++) {
        ans += countWaysUnordered(i, n - i);
    }
    return memo[min][n] = ans;
}
// TC: O(n^2)
int countWaysUnordered2(int min, int n) {
    if (n == 0) return 1;
    if (min > n) return 0;
    if (min == n) return 1;

    if (memo[min][n] != -1) return memo[min][n];
    int ans =
        countWaysUnordered2(min, n - min) + countWaysUnordered2(min + 1, n);

    return memo[min][n] = ans;
}

void solve() {
    int n;
    cin >> n;

    memo.resize(n + 1, vi(n + 1, -1));
    // top down approach
    for (int i = 1; i <= n; i++) {
        cout << countWaysUnordered2(1, i) << '\n';
    }
    cout << '\n';

    // cout << countWaysUnordered(1, n) << '\n';

    // bottom up approach
    // O(n^2 )
    // int dp[n + 1];
    // memset(dp, 0, sizeof(dp));
    // dp[0] = 1;

    // for(int i = 1; i <= n; i++) {
    //     for(int j = i; j <= n; j++) {
    //         dp[j] += dp[j - i];
    //     }
    // }
    // for(int i = 1; i <= n; i++) {
    //     cout <<  dp[i] << '\n';
    // }
    // cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
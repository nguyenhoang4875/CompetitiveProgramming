#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem:
 *  Dr. Patel has N stack of plates. Each stack contains K plates. Each plate
 * has a positive value, describing how beautiful it looks. Dr. Patel would like
 * to take exactly P plates to use for dinner tonight. If he would like to take
 * plate in stack, he must also take all of the pates above it in that stack
 * well. Help Dr. Patel to pick P plates that would maximize the total sum of
 * beauty values.
 *
 * Input:
 *  First line: T: number of test cases, each test case has: N, P, K
 *  the N line: contain K integer, describing the beauty value of each stack of
 * plates from top to bottom Output: Maximum total sum of beauty value that Dr.
 * Patel could pick
 *
 * Example:
 * Input:
 *  2
 *  2 4 5
 *  10 10 100 30
 *  80 50 10 50
 *  3 2 3
 *  80 80
 *  15 50
 *  20 10
 *
 * Output:
 * Case #1: 250
 * Case #2: 180
 *
 * Solution:
 *  Dynamic programming:
 *  dp(i, j): the maximum total sum of beauty values from first i-th row, and
 * total j plates using prefix sum to precalculate the sum of each row (minimize
 * the time complexity)
 *
 *  dp(i, j) = for(x = 0 -> k) max(pref(i, x) + dp(i - 1, j - x)) // take x
 * plates from row i-th
 *
 *  TC: O(n * p * k)
 *  MC: o(n * p)
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int tcs, n, k, p;

int solve() {
    cin >> n >> k >> p;
    vvi a(n + 1, vi(k + 1, 0));
    vvi pref(n + 1, vi(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
    }

    // dp array column length should be p
    vvi dp(n + 1, vi(p + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            // dp[i][j]
            // pick j plates from first i rows
            for (int x = 0; x <= min(k, j); x++) {
                dp[i][j] = max(dp[i][j], pref[i][x] + dp[i - 1][j - x]);
            }
        }
    }

    return dp[n][p];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    int tc = 1;
    while (tc <= tcs) {
        cout << "Case #" << tc++ << ":" << solve() << '\n';
    }
    return 0;
}

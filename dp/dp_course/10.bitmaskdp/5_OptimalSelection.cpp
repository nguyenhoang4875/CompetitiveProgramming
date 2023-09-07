#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Given the prices of k products over n days.
 * We want to buy each product exactly once. However,
 * We are allowed to buy at most one product in a day.
 * What is minimum total prices?
 *
 * Examples: k = 3, n = 8
 *  0: 6 9 5 2 8 9 1 6
 *  1: 8 2 6 2 7 5 7 2
 *  2: 5 3 9 7 3 5 1 4
 *
 * Output: 5
 *
 * Solution: Bit mask DP
 * dp[mask][i]: mask = choose products, i: day-th
 * 
 * TC: O(2^n * n * k)
 * MC: O(2^n * k)
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int oo = 1e18;
int n, k;

void solve() {
    cin >> k >> n;

    int price[k][n];
    vector<vector<int>> dp(1 << k, vector<int>(n, oo));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> price[i][j];
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < k; i++) {
        dp[1 << i][0] = price[i][0];
    }

    for (int mask = 0; mask < (1 << k); mask++) {
        for (int d = 1; d < n; d++) {
            // dp[mask][d]
            dp[mask][d] = dp[mask][d - 1];

            for (int x = 0; x < k; x++) {
                if ((mask >> x) & 1) {
                    // unset j-th bit of mask
                    int newMask = mask ^ (1 << x);
                    dp[mask][d] =
                        min(dp[mask][d], dp[newMask][d - 1] + price[x][d]);
                }
            }
        }
    }
    cout << dp[(1 << k) - 1][n - 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
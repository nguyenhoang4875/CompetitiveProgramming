#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: There are a row of n houses, each house can be painted with one of
 *  the three colors. You have to paint all the houses such that no two
 *  adjacent houses have the same color. The cost of painting each house with a
 *  certain color is represented by a n x k cost matrix.
 *  Find the minimum cost to paint all the houses
 *
 * Solution:
 *  dp(i, j) minimum cost of H(...i] if i: i-th house is painted with j: j-th
 * color dp(i, j) = min {dp(i, j), dp(t, j - 1) + cost[i][j]} with t != i
 *
 * TC: O(n * k * k)
 * MC: O(n * k)
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n, k;
int oo = 1e9;

void solve() {
    cin >> n >> k;
    int cost[k][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> cost[i][j];
        }
    }

    int dp[k][n];
    for (int i = 0; i < k; i++) {
        dp[i][0] = cost[i][0];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < k; i++) dp[i][j] = oo;

        for (int i = 0; i < k; i++) {
            for (int t = 0; t < k; t++) {
                if (t != i) {
                    dp[i][j] = min(dp[i][j], dp[t][j - 1] + cost[i][j]);
                }
            }
        }
    }

    int ans = oo;
    for (int i = 0; i < k; i++) {
        ans = min(ans, dp[i][n - 1]);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
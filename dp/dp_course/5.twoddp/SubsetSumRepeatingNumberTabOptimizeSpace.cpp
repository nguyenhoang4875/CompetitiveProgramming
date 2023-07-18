#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Give a SUM and an array of non negative numbers.
 * Determine if subset of array exist with sum equals SUM
 *
 * Solution: Using tabulation dp
 * f(x, y) => whether sum y can be founded by using array [x....]
 * x -> index     y -> sum
 * f(x, y) = f(x - 1, y) | f(x - 1, y - a[x]);
 *
 */

int a[1005];

void solve() {
    int sum, n;
    cin >> sum >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool dp[2][sum + 1];
    // first row dp[0][j]
    // second row dp[1][j]
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false;
    }
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            // dp[th] row is 2nd row
            dp[1][j] = dp[0][j];

            if (j - a[i] >= 0) {
                dp[1][j] |= dp[0][j - a[i]];
            }
        }
        
        // copy 2nd row to 1st row
        // for next i calculation
        for(int j = 0; j <= sum; j++) {
            dp[0][j] = dp[1][j];
        }
    }
    cout << dp[1][sum] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
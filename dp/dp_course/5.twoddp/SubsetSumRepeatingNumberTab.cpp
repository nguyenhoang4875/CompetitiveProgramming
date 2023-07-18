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

    bool dp[n + 1][sum + 1];
    for(int j = 1; j <= sum; j++) {
        dp[0][j] = false;
    }
    dp[0][0]  = true;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            // exclusion
            dp[i][j] = dp[i - 1][j];

            // inclusion
            if(j >= a[i]) {
                dp[i][j] |= dp[i - 1][j - a[i]];
            }
        }
    }
    cout << dp[n][sum] << '\n';
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= sum; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
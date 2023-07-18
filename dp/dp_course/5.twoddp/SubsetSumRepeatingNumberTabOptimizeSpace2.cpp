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
 * Time: O(n * sum), Space: O(sum)
 *
 */

int a[1005];

void solve() {
    int sum, n;
    cin >> sum >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool dp[sum + 1];
    // first row dp[j]
    for (int j = 1; j <= sum; j++) {
        dp[j] = false;
    }
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j - a[i] >= 0) {
                dp[j] |= dp[j - a[i]];
            }
        }
    }
    cout << dp[sum] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
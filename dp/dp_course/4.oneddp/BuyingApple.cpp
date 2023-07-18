#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/ABA12C/
 * Solution: knapsack
 */

int n, k;
int a[105];
int dp[105];
int oo = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[k];
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        dp[i] = oo;
    }

    dp[0] = 0;

    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (a[j] == -1) continue;
            if (j + i <= k && dp[i] != oo)
                dp[j + i] = min(dp[j + i], dp[i] + a[j]);
        }
    }

    if (dp[k] == oo) dp[k] = -1;
    cout << dp[k] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}
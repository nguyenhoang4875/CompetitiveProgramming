#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.codechef.com/ZCOPRAC/problems/ZCO14002
*/


void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    int dp[n + 1]; // dp[i] is the minimum value that the a[i] is selected.
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // base case;
    dp[1] = a[1];
    dp[2] = a[2];
    dp[3] = a[3];

    // other case;
    for(int i = 4; i <= n; i++) {
        dp[i] = a[i]  + min({dp[i - 1], dp[i - 2], dp[i - 3]});
    }

    // return min value to reach a[n];
    int ans = min({dp[n], dp[n - 1], dp[n - 2]});
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1061/C
 * Solution:
 * Time: O(n * sqrt(n)) AC
 * Space: O(n)
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

// *** Start Coding ***
int n;
const int MOD = 1e9 + 7;
int a[100005];
vi dp(1000005);

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        // dp[i%2] = dp[(i + 1)%2];//replace the current row in the DP table
        // with the previous row => takes O(n) time Access j : a[i] is divisible
        // In other words we only need to update DP[i][j] for j being a divisor
        // of a[i]
        vi toUpdate;

        for (int j = 1; j <= sqrt(a[i]); j++) {
            if (a[i] % j == 0) {
                toUpdate.pb(j);
                if (a[i] / j != j) {
                    toUpdate.pb(a[i] / j);
                }
            }
        }
        // Need to be careful that we are updating DP[j] in the correct order

        sort(toUpdate.begin(), toUpdate.end(), greater<int>());

        for (int j :
             toUpdate) {  // Updating DP[i][j] for j being a divisor of a[i]
            // cout<<j<<endl;
            dp[j] += dp[j - 1];  // We are assuming that DP[j - 1] refers to the
                                 // previous DP row which is not updated
            dp[j] %= MOD;
            // DP[i][j] += DP[i - 1][j - 1]
        }  // Transition time from 1 state to the other is O(sqrt(n)) time which is fine
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[i]) % MOD;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
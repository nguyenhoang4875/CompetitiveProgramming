#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: 
 * Solution:
 *  if n > m: YES, based on Pigeonhole principle
 *  if n <= n:
 *  State: dp[i][j] is a boolean value
 *   and it is true if there is a subsequence from the indies 1 to i
 *   which has a sum of j (mod m)
 * 
 *  Base case: for(int i = 1; i <= n; i++) dp[i][a[i]] = true
 * 
 *  Transition:
 *  If(dp[i][j]) continue 
 *  Sub case 1: 
 *      index i in the subsequence(include a[i])
 *      => dp[i][j] =  dp[i - 1][j - a[i]]
 *      because including i means j will decrease by a[i]
 * 
 *  Sub case 2:
 *      index i is not in the subsequence form 1 to i (exclude a[i])
 *      which has a sum of j (mod m)
 *      => dp[i][j] = dp[i - 1][j]
 *  Final answer: dp[n][0]
*/

int n, m;
int a[1000005];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] %= m;
    }

    if(n >= m) {
        cout << "YES\n";
        return;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    for(int i = 1; i <= n; i++){
        dp[i][a[i]] = true;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < m; j++) {
            if(dp[i][j]) continue;

            // include a[i]
            dp[i][j] = dp[i][j] | dp[i - 1][(j - a[i] + m) % m];

            // exclude a[i]
            dp[i][j] = dp[i][j] | dp[i - 1][j];
            
        }
    }
    if(dp[n][0]) cout << "YES\n";
    else cout << "NO\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1061/C
 * Solution:
 * Time: O(n^2) TLE
 * Space: O(2 * n)
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

void solve() {
    cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vvi dp(2, vi(n + 5)); // 2 * N dp table

    for(int i = 1; i <= n; i++) dp[i % 2][0] = 1; // dp[i][0] = 1 for all i going from 1 to n
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i % 2][j] = dp[(i + 1) % 2][j]; // (a + 1) % 2 == (a - 1) % 2
            if(a[i] % j == 0) {
                dp[i % 2][j] = (dp[i % 2][j] + dp[(i + 1) % 2][j - 1]) % MOD;
                // if a[i] is divisible by j 
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + dp[n % 2][i]) % MOD;
    cout << ans << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
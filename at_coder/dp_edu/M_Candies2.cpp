#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Candies
 * Solution: DP + PrefixSum
 *
 * TC: O(n * k)
 * MC: O(n * k)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, k;
int a[ms];
int dp[105][100005];
// number of ways of distributing j candies to first i students

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];

    dp[0][0] = 1;
    // O(n * k ^ 2) brute force solution
    For(i, 1, n) {
        For(j, 0, k) {
            For(kk, 0, min(a[i], j)) {
                dp[i][j] += dp[i - 1][j - kk];
                dp[i][j] %= mod;
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 0; j <= k; j++) {
    // 		// dp[i][j];
    // 		for (int kk = 0; kk <= min(a[i], j); kk++) {
    // 			dp[i][j] += dp[i - 1][j - kk];
    // 		}
    // 	}
    // }

    // For(i, 1, n) {
    //     For(j, 1, k) {
    //         // prefix sum
    //         dp[i - 1][j] += dp[i - 1][j - 1];
    //     }

    //     For(j, 0, k) {
    //         dp[i][j] = dp[i - 1][j];
    //         if (j - a[i] > 0) {
    //             dp[i][j] -= dp[i - 1][j - a[i] - 1];
    //         }
    //         dp[i][j] = (dp[i][j] % mod + mod) % mod;
    //     }
    // }
    cout << dp[n][k] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/**
 * Solution:
 *  - dp[i][x] = number of ways to pick coins with sum x, using the first i coins.
 *  - remove #define int long long to avoid memory limit exceed
 *
 * TC: O(n * target)
 * MC: O(n)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
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

const int mod = 1e9 + 7;
const int ms = 1e2 + 1;
int n, target;
int a[ms];

void solve() {
    cin >> n >> target;
    For(i, 1, n) cin >> a[i];

    // dp[i][x] = number of ways to pick coins with sum x, using the first i coins.
    vvi dp(n + 1, vi(target + 1, 0));
    dp[0][0] = 1;

    For(i, 1, n) {
        For(j, 0, target) {
            dp[i][j] = dp[i - 1][j];
            int left = j - a[i];
            if (left >= 0) {
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
    cout << dp[n][target];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
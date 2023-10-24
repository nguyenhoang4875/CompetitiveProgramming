#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Solution:
 *  dp[x]  = dp[x - 1] + dp[x - 2] + ... + dp[x - 6]
 *  dp[x] % = mod
 *
 *  ans = dp[n]
 *
 * TC: O(n * 6)
 * MC: O(n)
 *
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e6 + 5;
int n;

vi dices = {1, 2, 3, 4, 5, 6};
vi dp(ms);

void solve() {
    cin >> n;
    dp[0] = 1;
    For(i, 1, n) {
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    cout << dp[n];
}

void solve2() {
    cin >> n;
    dp[0] = 1;
    For(i, 0, n) {
        for (int j = 1; j <= 6 and i + j <= n; j++) {
            dp[i + j] += dp[i];
            dp[i + j] %= mod;
        }
    }
    cout << dp[n];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
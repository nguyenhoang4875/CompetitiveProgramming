#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Permutation
 * Solution: Using dp bottom up + prefix sum
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

int n;
string str;

/*
dp[i][s]: for first i-th element and has s (<) remaining

g + s = n - i => g = n - i - s

ans = 0
for: <
ans += Sum[j = 1 -> g] (dp(i + 1, s + j - 1))
     = dp(i + 1, s) + dp(i + 1, s + 1) + ... + dp(i + 1, n - i - 1)
for: >
ans += Sum[j = 1 -> n] (dp(i + 1, j - 1))
     = dp(i + 1, 0) + dp(i + 1, 1) + ... + dp(i + 1, s - 1)

*/

void solve() {
    cin >> n;
    cin >> str;

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    dp[n][0] = 1;

    for (int i = n - 1; i > 0; i--) {
        // prefix sum
        for (int j = 1; j <= n; j++) {
            dp[i + 1][j] += dp[i + 1][j - 1];
        }

        for (int s = 0; s <= n; s++) {
            int g = (n - i - s);
            if (g < 0) continue;

            if (str[i - 1] == '<') {
                dp[i][s] =
                    dp[i + 1][s + g - 1] - (s == 0 ? 0 : dp[i + 1][s - 1]);
            } else {
                dp[i][s] = dp[i + 1][s - 1];
            }
            dp[i][s] %= mod;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[1][i];
    }
    ans += mod;
    ans %= mod;

    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/**
 * dp[i][j] maximum number of page at used first i-th books and total j prices
 * OR
 * dp[i] maximum number of page at used total i prices: using for backward MC: O(n)
 *
 *
 * TC: O(n * x)
 * MC: O(n * x)
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

const int ms = 1e3 + 5;
int n, x;
int h[ms], s[ms];

void solve() {
    cin >> n >> x;
    For(i, 1, n) cin >> h[i];
    For(i, 1, n) cin >> s[i];

    // dp[i][j] maximum number of page at used first i-th books and total j prices
    vvi dp(n + 1, vi(x + 1, 0));
    For(i, 1, n) {
        For(j, 0, x) {
            dp[i][j] = dp[i - 1][j];  // not take s[i]
            if (j >= h[i]) {          // take s[i]
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
            }
        }
    }
    cout << dp[n][x] << '\n';
}

// use only 1-D array for dp when backward of d in pages
void solve2() {
    cin >> n >> x;
    For(i, 1, n) cin >> h[i];
    For(i, 1, n) cin >> s[i];

    // dp[i] maximum number of page at total i prices
    vi dp(x + 1, 0);
    int ans = 0;
    For(i, 1, n) {
        Ford(j, x, 0) {
            if (j - h[i] >= 0) {
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
                ans = max(ans, dp[j]);
            }
        }
    }
    // For(i, 1, x) {
    //     cout << i << " " << dp[i] << "\n";
    // }
    cout << dp[x] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve2();
    return 0;
}
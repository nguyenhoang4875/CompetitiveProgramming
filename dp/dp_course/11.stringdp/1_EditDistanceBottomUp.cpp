#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/EDIST/
   f(i, j) => min of operations so that a[0...i] == b[0...j]]
    using prefix
    final answer => f(a.size(), b.size())

    if(a[i] != b[j])
        dp(i, j) = 1 + min(dp(i -1, j), dp(i, j - 1), dp(i - 1, j - 1))
    else
        dp(i, j) = dp(i - 1, j - 1)

*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//
const int MS = 2005;
const int oo = 2e9;
string a, b;

int memo[MS][MS];
int dp(int i, int j) {
    if (i == a.size() && j == b.size()) return 0;
    if (i == a.size()) return b.size() - j;
    if (j == b.size()) return a.size() - i;
    if (memo[i][j] != -1) return memo[i][j];

    // i < a.size() && j < b.size()
    int ans = oo;
    if (a[i] != b[j]) {
        ans = 1 + min({dp(i + 1, j), dp(i, j + 1), dp(i + 1, j + 1)});
    } else {
        ans = dp(i + 1, j + 1);
    }
    return memo[i][j] = ans;
}

void solve() {
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int dp[n + 5][m + 5];
    // fill base case
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) {
    //         dp[i][j] = oo;
    //     }
    // }
    // dp[0][0] = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] != b[j - 1]) {
                dp[i][j] =
                    1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            } else {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[n][m] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}
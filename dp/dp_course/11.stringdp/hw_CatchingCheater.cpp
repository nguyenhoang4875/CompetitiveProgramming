#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1446/B
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int ms = 5005;
int n, m;
int dp[ms][ms];

void solve() {
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    int ans = 0;
    /* Way 1:
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) - 1;
            dp[i][j] = max(0LL, dp[i][j]);

            if (a[i] == b[j]) {
                dp[i][j] = 2 + dp[i + 1][j + 1];
            }
            ans = max(ans, dp[i][j]);
        }
    }
    */
    // Way 2:
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
            dp[i][j] = max(0LL, dp[i][j]);
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = 2 + dp[i - 1][j - 1];
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
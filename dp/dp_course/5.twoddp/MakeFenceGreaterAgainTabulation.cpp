#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1221/problem/D
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int tcs, n;
int a[300005], b[300005];
int dp[300005][3];
int oo = 1e18;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = oo;
    }

    dp[0][0] = 0;
    dp[0][1] = b[0];
    dp[0][2] = 2 * b[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (a[i - 1] + j != a[i] + k) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + k * b[i]);
                }
            }
        }
    }
    int ans = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
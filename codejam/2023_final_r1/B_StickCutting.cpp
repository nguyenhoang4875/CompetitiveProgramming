#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/contest/problem/1071/2
 * Solution: Using dp
 * length: k cost: a *(Li - k)^2 + b
 * length k, min cost
 * => knapsack 0/1
 * dp[i][j] // j: length l, j: cost
 * TC: O(n * k)
 * MC: O(n * k)
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

const int oo = 2e18;
int n, k, a, b;
int v[105];

void solve() {
    cin >> n >> k >> a >> b;
    int total = 0;
    vi cost(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        total += v[i];
        if (v[i] == 1)
            cost[i] = 0;
        else {
            int t = v[i] - 1;
            cost[i] = a * t * t + b;
        }
    }
    vvi dp(n + 5, vi(10005, oo));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j >= v[i]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + cost[i]);
            }
        }
    }

    int ans = oo;
    for (int i = k; i <= total; i++) {
        ans = min(ans, dp[n][i]);
    }
    ans = dp[n][k];
    cout << ans << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
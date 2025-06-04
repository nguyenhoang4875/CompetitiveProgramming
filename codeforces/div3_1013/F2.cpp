#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) { cin >> grid[i]; }

        int L = d * d - 1;
        int r_allowed = 0;

        while ((r_allowed + 1) * (r_allowed + 1) <= L) { r_allowed++; }

        vector<long long> dp_next(m, 0), dp_curr(m, 0);

        vector<int> indicator(m, 0);
        for (int j = 0; j < m; j++) { indicator[j] = (grid[n - 1][j] == 'X'); }
        vector<long long> prefix(m + 1, 0);
        prefix[0] = 0;
        for (int j = 0; j < m; j++) { prefix[j + 1] = (prefix[j] + indicator[j]) % MOD; }
        for (int j = 0; j < m; j++) {
            if (grid[n - 1][j] == 'X') {
                int low = max(0, j - d);
                int high = min(m - 1, j + d);
                dp_next[j] = (prefix[high + 1] - prefix[low] + MOD) % MOD;
            } else {
                dp_next[j] = 0;
            }
        }

        for (int r = n - 2; r >= 0; r--) {
            vector<long long> X(m, 0);
            vector<long long> prefix_dp(m + 1, 0);
            prefix_dp[0] = 0;
            for (int j = 0; j < m; j++) { prefix_dp[j + 1] = (prefix_dp[j] + dp_next[j]) % MOD; }
            for (int a = 0; a < m; a++) {
                if (grid[r][a] == 'X') {
                    int low = max(0, a - r_allowed);
                    int high = min(m - 1, a + r_allowed);
                    X[a] = (prefix_dp[high + 1] - prefix_dp[low] + MOD) % MOD;
                } else {
                    X[a] = 0;
                }
            }

            vector<long long> prefix_X(m + 1, 0);
            prefix_X[0] = 0;
            for (int a = 0; a < m; a++) { prefix_X[a + 1] = (prefix_X[a] + X[a]) % MOD; }
            for (int b = 0; b < m; b++) {
                if (grid[r][b] == 'X') {
                    int low = max(0, b - d);
                    int high = min(m - 1, b + d);
                    dp_curr[b] = (prefix_X[high + 1] - prefix_X[low] + MOD) % MOD;
                } else {
                    dp_curr[b] = 0;
                }
            }

            dp_next.swap(dp_curr);
        }

        long long ans = 0;
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'X') { ans = (ans + dp_next[j]) % MOD; }
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}

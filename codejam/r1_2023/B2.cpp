#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 505;
const int MAXK = 1005;
int dp[2][MAXN][1 << 10];
int n, m, k;
string s;
bool a[MAXN][MAXN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> s;
        memset(a, false, sizeof(a));
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            a[x][y] = true;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int cur = i % 2;
            int prev = (i - 1) % 2;
            for (int mask = 0; mask < (1 << m); mask++) {
                for (int j = 0; j < m; j++) {
                    dp[cur][j][mask] = 0;
                }
            }
            for (int j = 0; j < m; j++) {
                for (int mask = 0; mask < (1 << m); mask++) {
                    if (a[i][j + 1] || s[j] == '-') {
                        dp[cur][j][mask] = dp[prev][j][mask];
                        continue;
                    }
                    int newMask = (mask << 1) & ((1 << m) - 1);
                    if (j < m - 1) newMask |= (mask & (1 << (m - 1))) >> (m - 1);
                    if (j > 0 && !(mask & 1)) newMask |= 1;
                    dp[cur][j][newMask] = (dp[cur][j][newMask] + dp[prev][j][mask]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (mask & 1) continue;
            ans = (ans + dp[n % 2][m - 1][mask]) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * MLE: memory limit exceeded
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

string a, b;

void solve() {
    cin >> a >> b;
    int n, m;
    n = a.size();
    m = b.size();
    if (n == 0 || m == 0) {
        cout << "0\n";
        return;
    }

    int dp[n + 5][m + 5];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] != b[j - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } else {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[n][m] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
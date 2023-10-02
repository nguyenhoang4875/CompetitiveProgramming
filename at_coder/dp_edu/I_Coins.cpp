#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

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
int n;

void solve() {
    cin >> n;
    double a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<double>> dp(n + 5, vector<double>(n + 5, 0.0));
    dp[0][0] = 1;
    // dp(i, j) has exactly head event on total j events
    for (int total = 1; total <= n; total++) {
        dp[0][total] = (1 - a[total]) * dp[0][total - 1];
        for (int head = 1; head <= total; head++) {
            dp[head][total] += a[total] * dp[head - 1][total - 1];
            dp[head][total] += (1 - a[total]) * dp[head][total - 1];
        }
    }

    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
        ans += dp[i][n];
    }
    cout.precision(10);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
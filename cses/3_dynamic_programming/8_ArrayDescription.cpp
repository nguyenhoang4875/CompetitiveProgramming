#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * dp[i][v] maximum ways of array at firth i-th, if x[i] = v
 * Separately case i = 1 and others
 *
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, m;
int a[ms];

void solve() {
    cin >> n >> m;
    For(i, 1, n) cin >> a[i];

    // dp[i][v] maximum ways of array at firth i-th, if x[i] = v
    vvi dp(n + 1, vi(m + 1, 0));

    if (a[1] == 0) {
        fill(all(dp[1]), 1);
    } else {
        dp[1][a[1]] = 1;
    }

    auto inBound = [](int val) { return val >= 1 and val <= m; };

    For(i, 2, n) {
        if (a[i] == 0) {
            For(j, 0, m) {
                for (int k : {j - 1, j, j + 1}) {
                    if (inBound(k)) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                }
            }

        } else {
            for (int k : {a[i] - 1, a[i], a[i] + 1}) {
                if (inBound(k)) {
                    dp[i][a[i]] += dp[i - 1][k];
                    dp[i][a[i]] %= mod;
                }
            }
        }
    }

    int ans = 0;
    For(i, 1, m) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
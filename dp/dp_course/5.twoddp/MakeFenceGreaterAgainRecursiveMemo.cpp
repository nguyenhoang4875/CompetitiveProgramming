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

int f(int pos, int pre, int state) {
    if (pos == n) return 0;
    if (dp[pos][state] != -1) return dp[pos][state];

    int ans = oo;
    if (a[pos] + 0 != pre) {
        ans = min(ans, f(pos + 1, a[pos] + 0, 0));
    }
    if (a[pos] + 1 != pre) {
        ans = min(ans, b[pos] + f(pos + 1, a[pos] + 1, 1));
    }
    if (a[pos] + 2 != pre) {
        ans = min(ans, 2 * b[pos] + f(pos + 1, a[pos] + 2, 2));
    }

    return dp[pos][state] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = min({f(0, -1, 0), f(0, -1, 1), f(0, -1, 2)});
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
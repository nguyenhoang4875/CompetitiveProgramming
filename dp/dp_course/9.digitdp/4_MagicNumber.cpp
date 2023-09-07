#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/628/D
 * Solution: Using digit DP
 *  - dp(idx, last, digMod) // idx: index
 *    last: is the char is max of current char, digMod: sumDigit % m
 *  - ans %= MOD
 */

const int MOD = 1e9 + 7;
int n, m, d;
string s;

int memo[2005][2][2005];
// 0-based index
int dp(int idx, bool last, int digMod) {
    // base case
    if (idx == n) return digMod == 0;

    if (memo[idx][last][digMod] != -1) return memo[idx][last][digMod];

    int till = last ? s[idx] - '0' : 9;
    int ans = 0;

    if (idx % 2 == 1) {
        // even position place d
        if (d <= till) {
            ans += dp(idx + 1, last && (d == till), (digMod * 10 + d) % m);
            ans %= MOD;
        }
    } else {
        // odd position
        for (int digit = 0; digit <= till; digit++) {
            // odd positions cannot place d
            if (digit == d) continue;
            ans +=
                dp(idx + 1, last && (digit == till), (digMod * 10 + digit) % m);
            ans %= MOD;
        }
    }
    return memo[idx][last][digMod] = ans;
}

int cal(string x) {
    s = x;
    n = s.size();
    memset(memo, -1, sizeof(memo));
    return dp(0, true, 0);
}

void solve() {
    cin >> m >> d;
    string a, b;
    cin >> a >> b;

    int i = a.size() - 1;
    while (i >= 0 && a[i] == '0') {
        a[i] = '9';
        i--;
    }
    a[i] -= 1;  // char of digit at a[i] minus by 1
    int ans = (cal(b) - cal(a) + MOD) % MOD;

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
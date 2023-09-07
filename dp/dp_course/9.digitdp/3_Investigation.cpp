#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: https://lightoj.com/problem/investigation
 * Solution: Using digit dynamic programming
 *  - a, b max is 2^31 - 1 => 10 digits => sum all digit max = 90
 *  => k max = 90;
 *  - if k > 90 => sum all digits can not divisible by k
*/

int tcs, n;
int a, b, k;
string s;

// 10 * 2 * k * k (k max = 90)
int memo[10][2][91][91];

int dp(int idx, bool last, int sumMod, int sumDigMod) {
    // base case
    if (idx == n) {
        return (sumMod % k == 0) && (sumDigMod % k == 0);
    }
    if (memo[idx][last][sumMod][sumDigMod] != -1)
        return memo[idx][last][sumMod][sumDigMod];
    int ans = 0;
    int till = last ? s[idx] - '0' : 9;
    for (int digit = 0; digit <= till; digit++) {
        ans += dp(idx + 1, last && (digit == till), (sumMod * 10 + digit) % k,
                  (sumDigMod + digit) % k);
    }
    return memo[idx][last][sumMod][sumDigMod] = ans;
}

int solve(int x) {
    s = to_string(x);
    n = s.size();
    memset(memo, -1, sizeof(memo));
    return dp(0, true, 0, 0);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    int tc = 1;
    int ans = 0;
    while (tcs--) {
        cin >> a >> b >> k;
        ans = 0;
        if(k <= 90) ans = solve(b) - solve(a - 1);
        // int ans = 0;
        cout << "Case " << tc++ << ": " << ans << '\n';
    }
    return 0;
}
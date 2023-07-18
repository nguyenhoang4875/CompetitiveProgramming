#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/ACODE/
 * Solution:
 *    dp(i) = dp(i + 1) + dp(i + 2)
 *    consider valid case for 1 and 2 characters
 * 
*/
int n;
string s;
int memo[50005];

int dp(int i) {
    if(i == n) return 1;

    if(memo[i] != - 1) return memo[i];
    int ans = 0;
    if(s[i] >= '1' && s[i] <= '9') {
        ans += dp(i + 1);
    }
    if(i + 1 < n && (s[i] == '1')) {
        ans += dp(i + 2);
    }
    if(i + 1 < n && (s[i] == '2' && (s[i + 1] >= '0' && s[i + 1] <= '6'))) {
        ans += dp(i + 2);
    }
    return memo[i] = ans;
}

void solve() {
    while (true) {
        cin >> s;
        memset(memo, -1, sizeof(memo));
        if(s == "0") return;
        n = s.size();
        cout << dp(0) << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

//*** START CODING ***//
/**
 * Problem: https://www.spoj.com/problems/CPCRC1C/
 * Solution: Using Digit DP
 *
 * TC: O(2e4); // memo[10][2][100]
 * MC: O(n);
 */

int n;
string s;
int memo[10][2][100];

int dp(int idx, bool last, int sum) {
    // base case
    if (idx == n) {
        return sum;
    }
    if(memo[idx][last][sum] != -1 ) return memo[idx][last][sum];
    // recursion case
    int till = last ? (s[idx] - '0') : 9;
    int ans = 0;
    for (int digit = 0; digit <= till; digit++) {
        ans += dp(idx + 1, last && (digit == till), sum + digit);
    }
    return memo[idx][last][sum] = ans;
}

int cal(int x) {
    s = to_string(x);
    n = s.size();
    memset(memo, -1, sizeof(memo));
    return dp(0, true, 0);
}

void solve() {
    while (true) {
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        int ans = cal(b) - cal(a - 1);
        cout << ans << '\n';
    }
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
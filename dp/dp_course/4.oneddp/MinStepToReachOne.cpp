#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * You are given a positive integer n.
 * You have to reduce it to 1 by performing the following steps:
 * 1. Reduce it to n - 1
 * 2. If n % 2 == 0 => n /= 2;
 * 3. If n % 3 == 0 => n /= 3;
*/

int n;
int memo[100005];

int f(int n) {
    // base case
    if(n == 1) return 0;
    // recursion case
    // int &a = b; a point to b, if a or b change both change
    int& mn = memo[n]; // add this line to memo

    if(mn != -1) return mn; 
    mn = INT_MAX;
    if(n % 3 == 0) mn = min(mn, f(n / 3));
    if(n % 2 == 0) mn = min(mn, f(n / 2));
    mn = min(mn,f(n - 1));
    mn += 1;
    return  mn;
}

void solve() {
    cin >> n;
    memset(memo, -1, sizeof(memo));
    int oo = 1e9;
    int dp[n + 1] = {0};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        int mn = oo;
        if(i % 3 == 0) mn = min(mn, dp[i / 3] + 1);
        if(i % 2 == 0) mn = min(mn, dp[i / 2] + 1);
        mn = min(mn, dp[i - 1] + 1);
        dp[i] = mn;
    }
    cout << dp[n] << endl;
    cout << f(n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
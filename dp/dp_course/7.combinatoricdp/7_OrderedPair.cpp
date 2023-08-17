#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Ordered Pair
 * Solution:
 *  Using dp:
 *      Top down: O(n * n)
 *      Bottom up: O(n)
 *  Using Math: O(log n)
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

vi memo;

// TC: O(n * n)
int countWaysOrdered(int n) {
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    int ans = 0;

    // for (i...n)
    for (int i = 1; i <= n; i++) {
        ans += countWaysOrdered(n - i);
    }
    return memo[n] = ans;
}

void solve() {
    int n;
    cin >> n;

    // top down approach
    memo.resize(n + 1, -1);
    cout << countWaysOrdered(n) << '\n';

    // bottom up
    // TC: O(n)
    vi dp(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = sum + 1;
        sum += dp[i];
    }
    cout << dp[n] << '\n';

    // Math approach
    // TC: O(log n), ans = 2 ^(n - 1)
    cout << pow(2, n - 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
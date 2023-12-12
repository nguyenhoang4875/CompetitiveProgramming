#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Count the number of Binary Search Tree that can be formed
 * using N nodes, numbered from 1 to N.
 * Example: n = 3 => ans = 5, n = 4 => ans = 14
 *
 * f(n) = sum(i, 1 -> n) f(i - 1) * f(n - i)
 * base case: f(0) = f(1) = 1
 *
 *
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
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
int n;

int countBst(int n) {
    // base case
    if (n == 0 || n == 1) return 1;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = countBst(i - 1);
        int y = countBst(n - i);
        ans += x * y;
    }
    return ans;
}

// O(n * n)
int countBstTopDown(int n, vi dp) {
    // base case
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = countBstTopDown(i - 1, dp);
        int y = countBstTopDown(n - i, dp);
        ans += x * y;
    }
    return dp[n] = ans;
}

int countBstBottomUp(int n) {
    vi dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

void solve() {}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
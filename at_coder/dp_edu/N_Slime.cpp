#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Slime
 * Solution: Using dp
 *  - Split one part to many part and take the minimum value
 *
 * TC: O(n ^ 2)
 * MC: O(n ^ 2)
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
const int ms = 2e5 + 5;
int n;
int a[ms];
int preSum[ms];
vvi memo;

int sum(int l, int r) { return preSum[r] - preSum[l - 1]; }

// dp[i][j]: min cost of operations if a[i...j]
int dp(int l, int r) {
    if (l == r) return 0;
    if (memo[l][r] != -1) return memo[l][r];
    int ans = oo;
    For(i, l, r - 1) { ans = min(ans, dp(l, i) + dp(i + 1, r) + sum(l, r)); }
    return memo[l][r] = ans;
}

void solve() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
        preSum[i] = a[i] + preSum[i - 1];
    }
    memo = vvi(n + 1, vi(n + 1, -1));
    cout << dp(1, n) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
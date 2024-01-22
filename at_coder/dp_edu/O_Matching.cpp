#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Matching => Rook matching problem
 * Pair with one man and one woman 
 * Solution: DP + Bitmask
 * 
 * TC: O(n * 2^n)
 * MC: O(n * 2^n)
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
const int ms = 25;
int n;
int a[ms][ms];
vvi memo;

// dp[i][j]: number of way that take first with i-th men
// and set of j women not taken
int dp(int i, int mask) {
    if (i == n) return 1;
    if (memo[i][mask] != -1) return memo[i][mask];
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (a[i][j] == 1 && (mask >> j) & 1) {
            ans += dp(i + 1, mask ^ (1 << j));
            ans %= mod;
        }
    }
    return memo[i][mask] = ans % mod;
}

void solve() {
    cin >> n;
    For(i, 0, n - 1) { For(j, 0, n - 1) cin >> a[i][j]; }
    int mask = (1 << n) - 1;
    memo = vvi(n + 1, vi(mask + 1, -1));
    // cout << "mask  = " << mask << el;
    cout << dp(0, mask) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
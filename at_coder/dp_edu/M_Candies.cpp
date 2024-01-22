#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Candies
 * Solution: DP use recursion but TLE
 *
 * TC: O(n * k * k) => TLE
 * MC: O(n * k)
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
int n, k;
int a[ms];
int memo[105][100005];

//  dp[i][j]: number of ways of distributing j candies to first i students
int dp(int i, int k) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (i > n) return 0;
    if (memo[i][k] != -1) return memo[i][k];
    int ans = 0;
    for (int val = 0; val <= a[i]; val++) {
        ans = (ans + dp(i + 1, k - val)) % mod;
    }
    return memo[i][k] = ans;
}

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(1, k) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
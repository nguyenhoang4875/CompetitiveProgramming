#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Dequeue
 *  Taro want to max: X - Y
 *  Jiro want to min: X - y
 *  because X + Y = SUM (constant)
 *  => Taro want to max: X - Y
 *  => Jiro want to max: Y - X
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
const int ms = 3e3 + 5;
int n;
int a[ms];
int memo[ms][ms];

// dp[i][j]: maximum value that can be formed form the remaining array
// Taro and Jiro want to max their value in their turn

int dp(int i, int j) {
    if (i == j) return a[i];
    if (memo[i][j] != oo) return memo[i][j];
    int ans = max(a[i] - dp(i + 1, j), a[j] - dp(i, j - 1));
    return memo[i][j] = ans;
}

void solve() {
    cin >> n;
    For(i, 1, n) { cin >> a[i]; }

    For(i, 1, n) {
        For(j, 1, n) { memo[i][j] = memo[i][j] = oo; }
    }

    cout << dp(1, n) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
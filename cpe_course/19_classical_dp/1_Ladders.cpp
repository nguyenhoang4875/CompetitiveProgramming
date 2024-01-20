#include <bits/stdc++.h>
#define int long long

using namespace std;

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
vi memo;

// O(n * k)
int cntWay(int n, int k) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != 0) return memo[n];
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += cntWay(n - i, k);
    }
    return memo[n] = ans;
}

/*
dp[i] = dp[i - 1] + ... + dp[i - k];
dp[i] = dp[i - 1] + (dp[i - 2] ... + dp[i - k] + dp[i - k - 1]) - dp[i - k - 1];

=> dp[i] = 2 * dp[i - 1] - dp[i - k - 1]
*/

// O(n)
int countWayOptimize(int n, int k) {
    vi dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 2 * dp[i - 1];
        if (i > k) dp[i] -= dp[i - k - 1];
    }
    return dp[n];
}

void solve() {
    cin >> n >> k;
    vi dp(n + 1, 0);
    memo = vi(n + 1, 0);
    memo[0] = 1;
    dp[0] = 1;
    // O(n * k)
    for (int i = 1; i <= n; i++) {
        for (int step = 1; step <= k; step++) {
            if (i >= step) {
                dp[i] += dp[i - step];
            }
        }
    }
    cout << dp[n] << el;
    cout << cntWay(n, k) << el;
    cout << countWayOptimize(n, k) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
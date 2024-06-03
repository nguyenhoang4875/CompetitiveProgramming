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
int n;

void solve() {
    cin >> n;
    vi x(n + 1), y(n + 1);
    For(i, 1, n) { cin >> x[i] >> y[i]; }
    vvi dp(n + 1, vi(2, -oo));
    dp[0][0] = 0;
    For(i, 1, n) {
        // Transition for his choice of eating the i-th course
        if (x[i] == 0) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][0], dp[i - 1][1]) + y[i]);
        } else {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + y[i]);
        }

        // Transition for his choice of skipping the i-th course
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1]);
    }
    int ans = max(dp[n][0], dp[n][1]);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
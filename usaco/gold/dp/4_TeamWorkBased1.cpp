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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, k;
int a[ms];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vi dp(n + 5, 0);  // max value i-th cows so far

    for (int i = 1; i <= n; i++) {
        int maxVal = a[i];
        for (int j = 1; j <= k; j++) {
            // range from: t -> i
            int t = i - j + 1;
            if (t < 1) break;
            maxVal = max(maxVal, a[t]);
            dp[i] = max(dp[i], dp[t - 1] + j * maxVal);
        }
    }
    cout << dp[n] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int tcs = 1;
    // cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
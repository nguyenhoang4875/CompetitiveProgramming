#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

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
int n;

void solve() {
    cin >> n;
    // dp[head]
    // if we have i tosses, then tail = i - head

    vector<double> dp(n + 1);
    // dp[i] p-possibility that there are i heads so far

    dp[0] = 1;
    for (int coin = 0; coin < n; coin++) {
        double p;
        cin >> p;
        for (int i = coin + 1; i >= 0; i--) {
            dp[i] = (i == 0 ? 0 : dp[i - 1] * p) + dp[i] * (1 - p);
        }
    }
    double ans = 0;
    for (int head = 0; head <= n; head++) {
        int tail = n - head;
        if (head > tail) {
            ans += dp[head];
        }
    }
    cout.precision(10);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
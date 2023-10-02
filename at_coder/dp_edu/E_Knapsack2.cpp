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
const int ms = 1e5 + 1;
int n, W;
int v[105];
int w[105];
int ans = 0;

void solve() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += v[i];
    }
    vi dp(sum + 5, oo);
    dp[0] = 0;
    // dp[i] the minimum total weight of items with total value exactly i

    for (int i = 1; i <= n; i++) {
        for (int val = sum - v[i]; val >= 0; val--) {
            dp[val + v[i]] = min(dp[val + v[i]], dp[val] + w[i]);
        }
    }
    for (int i = 0; i <= sum; i++) {
        if (dp[i] <= W) {
            ans = max(ans, i);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
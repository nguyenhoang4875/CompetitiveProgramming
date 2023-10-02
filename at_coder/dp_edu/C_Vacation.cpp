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
const int ms = 1e5 + 5;
int n;
int a[ms], b[ms], c[ms];
int dp[ms][5];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    for(int i = 2; i <= n; i++) {
        dp[i][1] = a[i] + max(dp[i - 1][2], dp[i - 1][3]);
        dp[i][2] = b[i] + max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][3] = c[i] + max(dp[i - 1][1], dp[i - 1][2]);
    }
    int ans = max({dp[n][1], dp[n][2], dp[n][3]});
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
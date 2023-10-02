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
int dp[105][ms];
int ans = 0;


void solve() {
    cin >> n >> W;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int len = 0; len <= W; len++) {
            dp[i][len] = max(dp[i][len], dp[i - 1][len]);
            if(len >= w[i]) {
                dp[i][len] = max(dp[i][len], dp[i - 1][len - w[i]] + v[i]);
            }
            ans = max(ans, dp[i][len]);
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
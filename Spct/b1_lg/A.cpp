#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, N, W;
int v[105], w[105]; 
int dp[105][100005]; // dp[i][j] i = number of v, j = weight;

void solve() {
    cin >> N >> W;
    for (int i = 1; i <= N ; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1 ; j <= W ; j++) {
            dp[i][j] = dp[i-1][j]; // not get the element i-th;
            if(j >= w[i]) {
                // consider the max of get or not get element i-th;
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i - 1][j - w[i]]);
            }
        }
    }

    cout << dp[N][W] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> tcs;
    tcs = 1;
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}
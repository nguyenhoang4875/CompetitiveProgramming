#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 2e9;

int total_cost(vector<vector<int>> cost) {
    int n = cost.size();

    vector<vector<int>> dp((1 << n), vector<int>(n, oo));
    dp[1][0] = 0;
    int maxMask = (1 << n) - 1;
    for (int mask = 1; mask <= maxMask; mask++) {
        if (!(mask & 1)) continue;
        for (int cur = 0; cur < n; cur++) {
            if (!((mask >> cur) & 1)) continue;
            for (int to = 0; to < n; to++) {
                if ((mask >> to) & 1) continue;  // already visited to
                int newMask = mask ^ (1 << to);
                dp[newMask][to] =
                    min(dp[newMask][to], cost[cur][to] + dp[mask][cur]);
            }
        }
    }
    int ans = oo;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[maxMask][i] + cost[i][0]);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> cost[i][j];
    int ans = total_cost(cost);
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
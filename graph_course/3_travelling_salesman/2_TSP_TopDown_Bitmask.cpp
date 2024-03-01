#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 2e9, ms = 21;

int n;
int maxMask;
vector<vector<int>> cost;
vector<vector<int>> dp;

int totalCost(int mask, int from) {
    if (mask == maxMask) {
        return cost[from][0];
    }

    if (dp[mask][from] != -1) {
        return dp[mask][from];
    }

    int ans = oo;
    for (int to = 0; to < n; to++) {
        if ((mask >> to) & 1) continue;
        int newMask = mask ^ (1 << to);
        ans = min(ans, cost[from][to] + totalCost(newMask, to));
    }
    return dp[mask][from] = ans;
}

void solve() {
    cin >> n;
    cost = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> cost[i][j];

    maxMask = (1 << n) - 1;
    dp = vector<vector<int>>(1 << n, vector<int>(n, -1));
    int ans = totalCost(1, 0);
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
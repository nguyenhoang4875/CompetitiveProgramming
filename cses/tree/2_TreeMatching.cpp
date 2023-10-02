#include <bits/stdc++.h>
using namespace std;

const int MS = 2e5 + 5;
vector<int> g[MS];
vector<vector<int>> dp(MS, vector<int>(2, 0));
void dfs(int cur, int par) {
    for (auto x : g[cur]) {
        if (x != par) {
            dfs(x, cur);
            dp[cur][0] += max(dp[x][0], dp[x][1]);
        }
    }
    for (auto x : g[cur]) {
        if (x != par) {
            dp[cur][1] =
                max(dp[cur][1],
                    (1 + dp[cur][0] - (max(dp[x][0], dp[x][1]) - dp[x][0])));
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}
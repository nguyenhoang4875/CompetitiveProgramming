#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/KNAPSACK/
 */

int n, s;
int sz[2005];  // size
int v[2005];   // value

int memo[2005][2005];

// recursion: dp top-down
int knapsack(int idx, int size) {
    // base case
    if (idx == 0) return 0;

    if (memo[idx][size] != 0) return memo[idx][size];

    int ans = 0;

    // include item idx
    if (size >= sz[idx]) {
        ans = v[idx] + knapsack(idx - 1, size - sz[idx]);
    }

    // exclude item idx
    ans = max(ans, knapsack(idx - 1, size));
    return memo[idx][size] = ans;
}

// Tabulation: dp bottom-up
int knapsackTab() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            // take item i
            if (j >= sz[i]) {
                memo[i][j] = v[i] + memo[i - 1][j - sz[i]];
            }

            // not take item i
            memo[i][j] = max(memo[i][j], memo[i - 1][j]);
        }
    }
    return memo[n][s];
}

// recursion: 0/N dp top-down
int knapsack0N(int idx, int size) {
    // base case
    if (idx == 0) return 0;
    if (size == 0) return memo[n][size];

    if (memo[idx][size] != 0) return memo[idx][size];

    int ans = 0;

    // include item idx
    if (size >= sz[idx]) {
        ans = v[idx] + knapsack0N(idx, size - sz[idx]);
    }

    // exclude item idx
    ans = max(ans, knapsack0N(idx - 1, size));
    return memo[idx][size] = ans;
}

// Tab: 0/N knapsack
int knapsackTab0N() {
    int dp[s + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        // 0/N knapsack
        for (int j = 0; j <= s; j++) {
            if (j - sz[i] >= 0) dp[j] = max(dp[j], dp[j - sz[i]] + v[i]);
        }
    }

    return dp[s];
}

void solve() {
    cin >> s >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sz[i];
        cin >> v[i];
    }
    cout << knapsack(n, s) << '\n';
    // cout << knapsack0N(n, s) << '\n';
    // cout << knapsackTab() << '\n';
    // cout << knapsackTab0N() << '\n';
}

int a[100];
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem:
 * https://www.codingninjas.com/studio/problems/colorful-knapsack_630415
 */

int colorfulKnapsack(int w[], int c[], int n, int m, int x) {
    vector<int> v[105];

    for (int i = 0; i < n; i++) {
        v[c[i]].push_back(w[i]);
    }

    vector<vector<int>> dp(105, vector<int>(10005));
    for (auto x : v[1]) {
        dp[1][x] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= x; j++) {
            if (dp[i][j]) {
                for (int e : v[i + 1]) {
                    if (j + e <= x) {
                        dp[i + 1][j + e]++;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        if (dp[m][i]) {
            ans = max(ans, i);
        }
    }

    if (ans == 0) return -1;
    return x - ans;
}

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    // int dp[105][10005];
    int w[105] = {0};
    int c[105] = {0};
    vector<int> v[105];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        v[c[i]].push_back(w[i]);
    }

    cout << colorfulKnapsack(w, c, n, m, x) << endl;
    vector<vector<int>> dp(105, vector<int>(10005));
    for (auto x : v[1]) {
        dp[1][x] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= x; j++) {
            if (dp[i][j]) {
                for (int e : v[i + 1]) {
                    if (j + e <= x) {
                        dp[i + 1][j + e]++;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        if (dp[m][i]) {
            ans = max(ans, i);
        }
    }
    // if(ans == 0) return -1;
    if (ans == 0)
        cout << "-1\n";
    else
        cout << x - ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
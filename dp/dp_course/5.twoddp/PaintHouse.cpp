#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: There are a row of n houses, each house can be painted with one of
 *  the three colors: red, blue and green. The cost of painting each house with a
 *  certain color is different. You have to paint all the houses such that no two
 *  adjacent houses have the same color. The cost of painting each house with a
 *  certain color is represented by a n x 3 cost matrix. For example, costs[0][0] 
 *  is the cost of painting house 0 with color read, costs[1][2] is the cost of
 *  painting house 1 with color green, ans so on.
 *  Find the minimum cost to paint all the houses
 * 
 * Solution: 
 *  dp(i, j) minimum cost of H(...i] if i: i-th house is painted with j: j-th color
 *  dp(i, j) = min {dp(i, j), dp(k, j - 1) + cost[i][j]} with k != i
 * 
 * TC: O(3*n)
 * MC: O(3*n)
 * 
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n;
int oo = 1e9;

void solve() {
    cin >> n;
    int cost[3][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    int dp[3][n];
    dp[0][0] = cost[0][0];
    dp[1][0] = cost[1][0];
    dp[2][0] = cost[2][0];

    for(int j = 1; j < n; j++) {
        for(int i = 0; i < 3; i++) dp[i][j] = oo;

        for(int i = 0; i < 3; i++) {
            for(int k = 0; k < 3; k++) {
                if(k != i) {
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost[i][j]);
                }
            }
        }
    }

    int ans = oo;
    for(int i = 0; i < 3; i++) {
        ans = min(ans, dp[i][n - 1]);
    }

    cout << ans << '\n' ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
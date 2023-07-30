#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 * Solution:
 *  dp(i, bool buy, k) for prices[i...] best profit if I have at most K
 *   transactions possible
 *   1. dp(i + k , buy, k); // Do nothing: don't buy / sell
 *   2. Action buy, k >= 1, (buy = true) -> -price[i] + dp(i + 1, false, k);
 *   3. Action sell, (buy = false) -> price[i] + dp(i + 1, true, k - 1);
 *
 * TC: O(n * k) // n size of array prices
 * MC: O(n * k)
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

class Solution {
   public:
    int memo[1001][2][101];
    int dp(int i, bool buy, int k, vector<int>& prices) {
        // base case
        if (i == prices.size() || k == 0) return 0;

        if (memo[i][buy][k] != -1) return memo[i][buy][k];

        // dont' buy/sell
        int ans = dp(i + 1, buy, k, prices);

        if (buy) {
            ans = max(ans, -prices[i] + dp(i + 1, false, k, prices));
        } else {
            ans = max(ans, prices[i] + dp(i + 1, true, k - 1, prices));
        }

        return memo[i][buy][k] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        return dp(0, true, k, prices);
    }
};

void solve() {
    Solution S;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << S.maxProfit(2, prices);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
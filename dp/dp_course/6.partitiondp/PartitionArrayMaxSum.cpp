#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/partition-array-for-maximum-sum/
 *
 * Solution:
 *  dp(i) answer for suffix array start form i-th index
 *  dp(i) = max(dp(j + 1) + max * (j - i - 1)
 *
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
    vector<int> memo;
    int dp(int i, vector<int>& a, int k) {
        // base case
        if (i == a.size()) return 0;
        if (memo[i] != -1) return memo[i];

        int ans = 0, mx = 0;
        for (int j = i; j < min(i + k, (int)a.size()); j++) {
            mx = max(mx, a[j]);
            ans = max(ans, mx * (j - i + 1) + dp(j + 1, a, k));
        }
        return memo[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        memo.resize(a.size(), -1);
        return dp(0, a, k);
    }
};

void solve() {
    Solution S;
    vector<int> a = {1, 15, 7, 9, 2, 5, 10};
    cout << S.maxSumAfterPartitioning(a, 3);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
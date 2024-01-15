#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: Find long increasing subsequence in an array
 * Solution: Using dp
 *  dp(i) -> LIS of sequence if it ends on i-th index
 *  base case: dp(i = 1 -> n) = 1
 *  dp(i) = for(j = 1 -> i -1) max(dp(i), d(j) + 1)
 *
 *  ans = 1;
 *  ans = for(i = 1 -> n) max(ans, dp[i])
 *
 *  TC: O(n*n)
 *  MC: O(n)
 *
 */

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

// O(n log n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

int n;

void solve() {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vi dp(n, 1);

    // O(n*n)
    for (int i = 1; i < n; i++) {
        // dp[] -> lis if it ends on ith index
        for (int j = 0; j <= i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int lis = 1;
    for (int i = 0; i < n; i++) {
        lis = max(lis, dp[i]);
    }
    cout << lis << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
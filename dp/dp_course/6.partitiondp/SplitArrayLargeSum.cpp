#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/split-array-largest-sum/
 * Solution:
 *  dp(i, m) for array start at i-th index,the minimum values of the largest sum
 *   if m partition the array
 *  dp(i, m) = min(j = i -> n - 1) (max(sum(a[i] -> a[j]), dp(j + 1, m - 1))))
 *
 * For DP
 * TC: O(n * n * m) // n size of array prices, m number of partitions
 * MC: O(n * m)
 *
 * For BinarySearch
 * TC: O(n * log(s)) // s: sum all elements of array
 * MC: O(n)
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
    int oo = 1e9;
    vector<vector<int>> memo;
    int dp(int i, vector<int>& a, int m) {
        // base case
        if (i == a.size()) {
            if (m == 0) return 0;
            return oo;
        }

        if (m < 0) return oo;

        // i >= 0 && i < n && m > 0 => can make partitions
        if (memo[i][m] != -1) return memo[i][m];

        int ans = oo, sum = 0;
        for (int j = i; j < a.size(); j++) {
            // i...j
            sum += a[j];
            ans = min(ans, max(sum, dp(j + 1, a, m - 1)));
        }
        return memo[i][m] = ans;
    }

    int splitArray(vector<int>& a, int m) {
        memo.resize(a.size() + 1, vector<int>(m + 1, -1));
        return dp(0, a, m);
    }
};

class SolutionBinarySearch {
   public:
    int oo = 1e9;
    bool check(int val, vector<int>& a, int m) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            if (sum > val) {
                sum = a[i];
                cnt++;
            }
            if (cnt > m) return false;
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& a, int m) {
        int mx = 0;
        int sum = 0;
        for (int e : a) {
            mx = max(mx, e);
            sum += e;
        }

        int l = mx;
        int r = sum;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, a, m)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

void solve() {
    Solution S;
    vector<int> a = {7, 2, 5, 10, 8};
    int m = 2;
    cout << S.splitArray(a, m);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
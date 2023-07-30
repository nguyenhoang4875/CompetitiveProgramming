#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/partition-equal-subset-sum/
 * Solution: same with subsetSum problem
 * TC: (n * t); n: number of elements in array, t: sum of array / 2
 * MC: (n * t)
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
    vector<vector<int>> memo;
    bool subsetSum(int idx, vector<int>& a, int t) {
        if (idx == a.size() || t < 0) return false;
        if (t == 0) return true;

        if (memo[idx][t] != -1) return memo[idx][t];
        bool ans = false;
        // include idx
        if (t - a[idx] >= 0) ans |= subsetSum(idx + 1, a, t - a[idx]);

        // exclude
        ans |= subsetSum(idx + 1, a, t);
        return memo[idx][t] = ans;
    }

    bool canPartition(vector<int>& a) {
        int sum = 0;
        for (auto e : a) {
            sum += e;
        }
        if (sum & 1) return false;
        int t = sum / 2;
        memo.resize(a.size(), vector<int>(t + 1, -1));
        return subsetSum(0, a, t);
    }
};

void solve() {
    Solution S;
    vector<int> a = {1, 5, 11, 5};
    cout << S.canPartition(a) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/interleaving-string
 * Solution: DP top-down
 * TC: O(n * m)
 * MC: O(m * n)
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
    string s1, s2, s3;
    int sz1, sz2, sz3;
    int n, m;
    int memo[1005][1005];

    bool dp(int i, int j) {
        int k = i + j;
        if (k == sz3) return true;
        if (memo[i][j] != -1) return memo[i][j];

        bool ans = 0;
        if (i < sz1 && s1[i] == s3[k]) {
            ans |= dp(i + 1, j);
        }
        if (j < sz2 && s2[j] == s3[k]) {
            ans |= dp(i, j + 1);
        }

        return memo[i][j] = ans;
    }

    bool isInterleave(string _s1, string _s2, string _s3) {
        s1 = _s1, s2 = _s2, s3 = _s3;
        sz1 = s1.size();
        sz2 = s2.size();
        sz3 = s3.size();
        if (sz1 + sz2 != sz3) return false;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};

void solve() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    Solution h;
    cout << h.isInterleave(s1, s2, s3) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
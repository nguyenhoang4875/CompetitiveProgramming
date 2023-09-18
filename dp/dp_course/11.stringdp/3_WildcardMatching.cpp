#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/wildcard-matching/
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
    string s, p;
    int n, m;
    int memo[2005][2005];

    bool dp(int i, int j) {
        if (i == n && j == m) return true;
        if (j == m) return false;

        if (memo[i][j] != -1) return memo[i][j];

        bool ans = false;
        if (i < n && s[i] == p[j]) {
            ans |= dp(i + 1, j + 1);
        }
        if (p[j] == '?') {
            if (i == n) return false;
            ans |= dp(i + 1, j + 1);
        }
        if (p[j] == '*') {
            if (i < n) {
                ans |= dp(i + 1, j);
            }
            ans |= dp(i, j + 1);
        }
        return memo[i][j] = ans;
    }

    bool isMatch(string _s, string _p) {
        s = _s;
        p = _p;
        n = s.size();
        m = p.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};

void solve() {
    string s, p;
    cin >> s >> p;

    Solution ans;
    cout << ans.isMatch(s, p) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
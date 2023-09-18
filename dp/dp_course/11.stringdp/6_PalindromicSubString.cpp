#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/palindromic-substrings
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
    int memo[1005][1005];
    string s;
    bool dp(int i, int j) {
        if (i >= j) return true;
        if (memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = (s[i] == s[j]) ? dp(i + 1, j - 1) : 0;
    }

    int countSubstrings(string _s) {
        s = _s;
        int n = s.size();
        memset(memo, -1, sizeof(memo));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                cnt += dp(i, j);
            }
        }
        return cnt;
    }
};

void solve() {
    string s;
    cin >> s;
    Solution h;
    cout << h.countSubstrings(s);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
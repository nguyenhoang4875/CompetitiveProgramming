#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

class Solution {
   public:
    string s, t;
    int n;
    vector<vector<int>> memo;
    // int memo[1005][1005];

    int dp(int i, int j) {
        if (i == j) return 1;
        if (j - i == 1 && s[i] == s[j]) return 2;
        if (memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if (s[i] == s[j]) {
            ans = 2 + dp(i + 1, j - 1);
        } else {
            ans = max(dp(i + 1, j), dp(i, j - 1));
        }
        return memo[i][j] = ans;
    }

    int longestPalindromeSubseq(string _s) {
        s = _s;
        n = s.size();
        memo.resize(n + 1, vector<int>(n + 1, -1));
        // memset(memo, -1, sizeof(memo));

        return dp(0, n - 1);
    }
};

void solve() {
    string s;
    cin >> s;
    Solution h;
    cout << h.longestPalindromeSubseq(s);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
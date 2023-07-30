#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://leetcode.com/problems/palindrome-partitioning-ii/
 * Solution:
 *  dp(i) min cuts required for palindrome partitioning of s[i...]
 *  dp(i) = min(j = 1 -> n) (dp(j + 1)) + 1
 *
 * TC: O(n * n) // n*n + n*n(for first time calculate memorize palindrome),
 *  n size of string MC: O(n * n)
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
    string s;
    int oo = 1e9;
    vector<vector<int>> memoPa;  // memorize the palindrome of string i->j
    vector<int> memo;            // memorize dp(i)

    // O(n * n) for first time, second time is O(1)
    bool isPalindrome(int i, int j) {
        if (i == j) return true;
        if (i == j - 1) return s[i] == s[j];
        if (memoPa[i][j] != -1) return memoPa[i][j];
        return memoPa[i][j] = isPalindrome(i + 1, j - 1) && (s[i] == s[j]);
    }

    // O(n)
    int dp(int i) {
        if (i == s.size()) return 0;
        if (memo[i] != -1) return memo[i];
        int ans = oo;
        // O(n)
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(i, j)) {
                ans = min(ans, dp(j + 1));
            }
        }
        ans += 1;
        return memo[i] = ans;
    }
    int minCut(string s) {
        this->s = s;  // set s of global variable
        int n = s.size();
        memoPa.resize(n + 1, vector<int>(n + 1, -1));
        memo.resize(n + 1, -1);
        return dp(0) - 1;
    }
};

void solve() {
    Solution S;
    string s;
    cin >> s;
    cout << S.minCut(s);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
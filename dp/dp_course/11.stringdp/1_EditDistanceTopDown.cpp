#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/EDIST/
   f(i, j) => min of operations so that a[i...] == b[j...]
    final answer => f(0, 0)

    Line 1 for string a, line 2 for string b
    1. Delete:
    d(i, j) = dp(i + 1, j) + 1
    d(i, j) = dp(i, j + 1) + 1

    2. Insert
    d(i, j) = dp(i, j + 1) + 1
    d(i, j) = dp(i +1, j) + 1

    3. Replace
    dp(i, j) = dp(i + 1, j + 1) + 1
    dp(i, j) = dp(i + 1, j + 1) + 1

    4. No operation: a[i] == b[i]
    dp(i, j) == dp(i + 1, j + 1)

    if(i == a.size() && j == b.size()) return 0;

    if(i == a.size()) return b.size() - a.size();

    if(j == b.size()) return a.size() - b.size();

    if(i < a.size() && j < b.size()) // todo operations

    if(a[i] != b[j]) {
            dp(i, j) = min(dp(i, j + 1) + 1, dp(i + 1, j) + 1, dp(i + 1, j+1) +
 1);
    }
    else {
            dp(i, j) = dp(i + 1, j + 1);
    }
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//
const int MS = 2005;
const int oo = 2e9;
string a, b;

int memo[MS][MS];
int dp(int i, int j) {
    if (i == a.size() && j == b.size()) return 0;
    if (i == a.size()) return b.size() - j;
    if (j == b.size()) return a.size() - i;
    if (memo[i][j] != -1) return memo[i][j];

    // i < a.size() && j < b.size()
    int ans = oo;
    if (a[i] != b[j]) {
        ans = 1 + min({dp(i + 1, j), dp(i, j + 1), dp(i + 1, j + 1)});
    } else {
        ans = dp(i + 1, j + 1);
    }
    return memo[i][j] = ans;
}

void solve() {
    cin >> a >> b;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}
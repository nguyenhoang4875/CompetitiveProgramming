#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Given a '2 x n' board and tiles size of '2 x 1', count the number of
 * ways to tile the given board using '2 x 1' tiles. A tile can be placed
 * horizontally or vertically.
 *
 * Solution: same with fibonacci
 *  dp(n) number of way to tile 2 x n boards with 2 x 1 tiles
 *  dp(n) = dp(n - 1) + dp(n - 2);
 * TC: O(n)
 * MC: O(n)
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int tcs, n;

vector<int> memo;
int dp(int n) {
    if (n <= 2) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = dp(n - 1) + dp(n - 2);
}

void solve() {
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    cout << dp(n);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
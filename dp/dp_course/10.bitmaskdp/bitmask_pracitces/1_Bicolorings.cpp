#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * https://codeforces.com/problemset/problem/1051/D
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 998244353;
int n, k;
int dp[1005][2005][4];
/*
 dp[i][j][mask]
    i: current column so far
    j: number of components so far
    mask: the current state before(0: WW, 1: WB, 2: BW, 3: WW)
*/

void solve() {
 cin >> n >> k;
   dp[1][1][0] = 1; // WW
   dp[1][2][1] = 1; // WB
   dp[1][2][2] = 1; // BW
   dp[1][1][3] = 1; // BB
   for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i * 2; ++j) {
        dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % mod;
        dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3]) % mod;
        dp[i][j][2] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 2][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % mod;
        dp[i][j][3] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3]) % mod;
      }
   }
   cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % mod << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
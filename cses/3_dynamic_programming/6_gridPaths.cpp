#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * dp[i][j] total paths in cell: (i, j)
 * 
 * TC: O(n * n)
 * MC: O(n * n)
*/

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e3 + 5;
int n;
char a[ms][ms];

void solve() {
    cin >> n;
    For(i, 1, n) {
        For(j, 1, n) {
            cin >> a[i][j];
        }
    }

    // dp[i][j] total paths in cell: (i, j)
    vvi dp(n + 1, vi(n + 1, 0));
    if(a[1][1] == '*') {
        cout << "0\n";
        return;
    }
    dp[1][1] = 1;
    For(i, 1, n) {
        For(j, 1, n) {
            if(a[i][j] == '*') continue;
            dp[i][j] += dp[i - 1] [j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
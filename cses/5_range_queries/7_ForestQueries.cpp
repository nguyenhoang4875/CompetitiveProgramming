#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * dp[i][j] sum total tree at rectangle a[1][1], a[i][j]
 * https://www.techiedelight.com/wp-content/uploads/Result.png
 *
 * TC: O(n * n)
 * MC: O(n * n)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
int n, q;
int a[ms][ms];

void solve() {
    cin >> n >> q;
    For(i, 1, n) {
        For(j, 1, n) {
            char c;
            cin >> c;
            if (c == '*') a[i][j] = 1;
        }
    }

    vvi dp(n + 1, vi(n + 1, 0));

    For(i, 1, n) {
        For(j, 1, n) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
        }
    }

    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans =
            dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
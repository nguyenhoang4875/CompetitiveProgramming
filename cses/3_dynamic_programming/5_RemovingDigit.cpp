#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * dp[x] = minimum number of operations to go from x to zero.
 *
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
const int ms = 1e5 + 5;
int n;

vi getDigits(int n) {
    vi digits;
    while (n) {
        digits.pb(n % 10);
        n /= 10;
    }

    return digits;
}

void solve() {
    cin >> n;
    vi dp(n + 1, oo);
    dp[0] = 0;
    For(i, 1, n) {
        for (auto digit : getDigits(i)) {
            if (i >= digit) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

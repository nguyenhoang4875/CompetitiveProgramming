#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Digit Sum
 * Solution: Using Digit dp
 *
 * TC: O(n * d) n is length of number
 * MC: O(n * d)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
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
int n, d;
string s;
int memo[ms][2][105];

int dp(int idx, bool last, int m) {
    if (idx == n) return m == 0;

    if (memo[idx][last][m] != -1) return memo[idx][last][m];

    int ans = 0;
    int till = last ? s[idx] - '0' : 9;

    For(digit, 0, till) {
        ans += dp(idx + 1, last and (digit == till), (m + digit) % d);
        ans %= mod;
    }
    return memo[idx][last][m] = ans % mod;
}

void solve() {
    cin >> s >> d;
    n = s.size();
    memset(memo, -1, sizeof(memo));
    cout << (dp(0, true, 0) - 1 + mod) % mod << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
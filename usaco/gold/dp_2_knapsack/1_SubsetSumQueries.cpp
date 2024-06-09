#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://atcoder.jp/contests/abc321/tasks/abc321_f
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 998244353;
const int ms = 5e3 + 5;
int n, k;
int dp[ms];

void solve() {
    cin >> n >> k;
    dp[0] = 1;
    auto add = [](int num) {
        for (int i = k; i >= num; i--) {
            dp[i] = (dp[i] + dp[i - num]) % mod;
        }
        cout << dp[k] << el;
    };
    auto rm = [](int num) {
        for (int i = num; i <= k; i++) {
            dp[i] = (dp[i] - dp[i - num] + mod) % mod;
        }
        cout << dp[k] << el;
    };

    for (int i = 1; i <= n; i++) {
        char type;
        int num;
        cin >> type >> num;
        if (type == '+')
            add(num);
        else
            rm(num);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
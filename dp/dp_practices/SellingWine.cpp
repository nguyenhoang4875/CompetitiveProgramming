#include <bits/stdc++.h>
#define int long long

using namespace std;

/*
Given n wines in a row, with integers denoting the cost of each wine respectively.
Each year you can sell the first or the last wine in the row. Let the initial profits from the
wines be P1, P2, P3…Pn. In the Yth year, the profit from the ith wine will be Y*P[i]. The goal is to
calculate the maximum profit that can be earned by selling all the wines.

TC: O(n^2)
MC: O(n^2)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 1e3 + 5;
int n;
int a[ms];
int memo[ms][ms];

int dp(int l, int r, int year) {
    // if (l > r) {
    //     return 0;
    // }
    if (l == r) {
        return a[l] * n;
    }
    if (memo[l][r] != -1) return memo[l][r];
    int left = dp(l + 1, r, year + 1) + a[l] * year;
    int right = dp(l, r - 1, year + 1) + a[r] * year;
    int ans = max(left, right);
    return memo[l][r] = ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(memo, -1, sizeof(memo));
    int ans = dp(1, n, 1);
    cout << ans << el;

    // bottom up
    vvi f(n + 2, vi(n + 2, 0));
    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            int cnt = (n - r) + l;
            f[l][r] = max(f[l + 1][r] + cnt * a[l], f[l][r - 1] + a[r] * cnt);
        }
    }
    cout << f[1][n];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
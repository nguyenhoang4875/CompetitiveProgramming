#include<bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/contest/1525/problem/D
 */

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi one, zero;
    For(i, 1, n) {
        int x;
        cin >> x;
        if (x) one.pb(i);
        else zero.pb(i);
    }
    int m = one.size();
    int k = zero.size();
    vvi f(m + 1, vi(k + 1)); // f[i][j]: min cost for first i-th peple move to first j-th empty chairs
    // basecase
    For(i, 1, m) {
        f[i][0] = oo;
    }
    For(i, 1, k) {
        f[0][k] = 0;
    }
    For(i, 1, m) {
        For(j, 1, k) {
            f[i][j] = min(f[i][j - 1], f[i - 1][j - 1] + abs(one[i - 1] - zero[j - 1]));
        }
    }
    int ans = oo;
    For(i, m, k) ans = min(ans, f[m][i]);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
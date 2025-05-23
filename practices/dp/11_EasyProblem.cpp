#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/problemset/problem/1096/D
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
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
    string s;
    cin >> s;
    s = " " + s;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    vvi f(n + 1, vi(4, oo));  // f[i][j]: i-th point for j-th case: empty, h, ha, har
    f[0][0] = 0;
    For(i, 1, n) {
        char c = s[i];
        if (c == 'h') {
            f[i][0] = f[i - 1][0] + a[i];
            f[i][1] = f[i - 1][0];
            for (int j : {1, 2, 3}) f[i][j] = min(f[i][j], f[i - 1][j]);
        } else if (c == 'a') {
            f[i][1] = f[i - 1][1] + a[i];
            f[i][2] = f[i - 1][1];
            for (int j : {0, 2, 3}) f[i][j] = min(f[i][j], f[i - 1][j]);
        } else if (c == 'r') {
            f[i][2] = f[i - 1][2] + a[i];
            f[i][3] = f[i - 1][2];
            for (int j : {0, 1, 3}) f[i][j] = min(f[i][j], f[i - 1][j]);
        } else if (c == 'd') {
            f[i][3] = f[i - 1][3] + a[i];
            for (int j : {0, 1, 2}) f[i][j] = min(f[i][j], f[i - 1][j]);
        } else {
            For(j, 0, 3) f[i][j] = min(f[i][j], f[i - 1][j]);
        }
    }
    int ans = oo;
    For(i, 0, 3) ans = min(ans, f[n][i]);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
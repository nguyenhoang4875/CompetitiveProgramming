#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://vjudge.net/problem/CodeForces-1969C
 */

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
    int n, k;
    cin >> n >> k;
    vi a(n + 2, 0);
    For(i, 1, n) cin >> a[i];
    a[0] = oo;
    a[n + 1] = oo;

    vvi f(n + 2, vi(11, oo));
    For(i, 0, k) f[0][i] = 0;

    For(i, 1, n) {
        For(j, 0, k) {
            f[i][j] = f[i - 1][j] + a[i];
            int mn = a[i];
            for (int x = 0; x <= j and i - x >= 1; x++) {
                mn = min(mn, a[i - x]);

                f[i][j] = min(f[i][j], f[i - x - 1][j - x] + (x + 1) * mn);
            }
        }
    }
    cout << f[n][k] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
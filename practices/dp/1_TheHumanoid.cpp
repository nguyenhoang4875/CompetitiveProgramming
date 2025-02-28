#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://vjudge.net/problem/CodeForces-1759E
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
int n, h;
int a[ms];

void solve() {
    cin >> n >> h;
    For(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);

    vector<vector<vector<int>>> f(n + 2, vvi(3, vi(2, 0)));
    f[0][0][0] = h;
    For(g, 0, 2) {
        For(b, 0, 1) {
            if (g > 0) f[0][g][b] = 2 * f[0][g - 1][b];
            if (b > 0) f[0][g][b] = 3 * f[0][g][b - 1];
        }
    }
    int ans = n;
    For(i, 1, n) {
        bool ok = false;
        For(g, 0, 2) {
            For(b, 0, 1) {
                if (f[i - 1][g][b] > a[i]) {
                    f[i][g][b] = f[i - 1][g][b] + (a[i] / 2);
                    ok = true;
                }
                if (g > 0) f[i][g][b] = max(f[i][g][b], 2 * f[i][g - 1][b]);
                if (b > 0) f[i][g][b] = max(f[i][g][b], 3 * f[i][g][b - 1]);
            }
        }

        if (!ok) {
            ans = i - 1;
            break;
        }
    }
    cout << ans << el;
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
#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 50 + 5;
int m, x;
pair<int, int> h[ms];

void solve() {
    cin >> m >> x;
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        cin >> h[i].F >> h[i].S;
        sum += h[i].S;
    }

    // f[i][j]: maximum money from i-th month so far has j happiness

    vvi f(m + 1, vi(sum + 1, -1));  // set value can not reach when building f
    // base case
    for (int i = 0; i <= m; i++) {
        f[i][0] = 0;
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= sum; j++) {
            // no buy happy
            if (f[i - 1][j] != -1) f[i][j] = f[i - 1][j] + x;

            // buy happy
            int nj = j - h[i].S;
            if (nj >= 0 and f[i - 1][nj] >= h[i].F) {
                f[i][j] = max(f[i][j], f[i - 1][nj] - h[i].F + x);
            }
            if (f[i][j] >= 0) ans = max(ans, j);
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
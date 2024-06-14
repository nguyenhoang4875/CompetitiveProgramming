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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e3 + 5;
int n, b, c;
vi p, f, d;

int minElectricBill(int N, int B, int C, vi& d, vi& p, vi& f) {
    vvi dp(N + 1, vector<int>(C + 1, oo));

    dp[0][B] = 0;
    int newLevel = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= C; ++j) {
            // Using city-provided electricity and charge battery
            newLevel = min(j + p[i - 1], C);
            dp[i][newLevel] = min(dp[i][newLevel], dp[i - 1][j] + d[i - 1] * f[i - 1]);

            // Using battery
            if (j >= d[i - 1]) {
                newLevel = j - d[i - 1];
                dp[i][newLevel] = min(dp[i][newLevel], dp[i - 1][j]);
            }
        }
    }
    int ret = oo;
    for (int i = B; i <= C; i++) {
        ret = min(ret, dp[N][i]);
    }

    return ret;
}

void solve() {
    cin >> n >> b >> c;
    p = vi(n);
    f = vi(n);
    d = vi(n);
    For(i, 0, n - 1) cin >> p[i];
    For(i, 0, n - 1) cin >> f[i];
    For(i, 0, n - 1) cin >> d[i];

    int ans = minElectricBill(n, b, c, d, p, f);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
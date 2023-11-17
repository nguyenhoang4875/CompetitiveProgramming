#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)
#define LSOne(s) ((s) & (-s))

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
const int ms = 20;
int n;

double dist[ms][ms], memo[1 << 16];

double dp(int mask) {
    double &ans = memo[mask];
    if (ans > -0.5) return ans;
    if (mask == 0) return 0;

    ans = 1e9;
    int two_pow_p1 = LSOne(mask);
    int p1 = __builtin_ctz(two_pow_p1);
    int m = mask - two_pow_p1;
    while (m) {
        int two_pow_p2 = LSOne(m);
        int p2 = __builtin_ctz(two_pow_p2);
        ans = min(ans, dist[p1][p2] + dp(mask ^ two_pow_p1 ^ two_pow_p2));
        m -= two_pow_p2;
    }
    return ans;
}

int tc = 0;
void solve() {
    int x[20], y[20];
    while (cin >> n, n) {
        for (int i = 0; i < 2 * n; i++) {
            string s;
            cin >> s;
            cin >> x[i] >> y[i];
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = i + 1; j < 2 * n; j++) {
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
            }
        }
        for (int i = 0; i < (1 << 16); i++) memo[i] = -1.0;
        cout << fixed << setprecision(2);
        cout << "Case " << ++tc << ": " << dp((1 << 2 * n) - 1) << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define LSOne(x) ((x) & -(x))
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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
    int tc = 0;
    while (true) {
        cin >> n;
        if (!n) return;
        vi x(2 * n + 1), y(2 * n + 1);
        Rep(i, 2 * n) {
            string s;
            cin >> s;
            cin >> x[i] >> y[i];
        }

        double dist[20][20];
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = i + 1; j < 2 * n; j++) {
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
            }
        }

        double memo[1 << 16];
        for (int i = 0; i < (1 << 16); ++i) memo[i] = -1;

        function<double(int)> f = [&](int mask) {
            double &ans = memo[mask];
            if (ans >= 0) return ans;
            if (mask == 0) return 0.0;
            ans = 1e9;

            int v1 = LSOne(mask);
            int p1 = __builtin_ctz(v1);

            int m = mask - v1;
            while (m) {
                int v2 = LSOne(m);
                int p2 = __builtin_ctz(v2);
                ans = min(ans, dist[p1][p2] + f(mask ^ v1 ^ v2));
                m -= v2;
            }
            return ans;
        };
        double ans = f((1 << (2 * n)) - 1);
        cout << fixed << setprecision(2);
        cout << "Case " << ++tc << ": " << ans << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
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
    while (true) {
        int C, n;
        if (!(cin >> C)) return;
        cin >> n;
        vii a(n + 1);
        For(i, 1, n) cin >> a[i].F >> a[i].S;
        vvi f(n + 1, vi(C + 1));
        vvi take(n + 1, vi(C + 1));
        for (int i = 1; i <= n; ++i) {
            for (int c = 1; c <= C; ++c) {
                auto& [v, w] = a[i];
                f[i][c] = f[i - 1][c];
                if (c >= w) {
                    int val = f[i - 1][c - w] + v;
                    if (f[i][c] < val) {
                        f[i][c] = val;
                        take[i][c] = 1;
                    }
                }
            }
        }

        // max_value = f[n][C];
        int c = C;
        vi ans;
        for (int i = n; i >= 1; --i) {
            if (c > 0 and take[i][c]) {
                ans.pb(i);
                c -= a[i].S;
            }
        }
        reverse(all(ans));
        cout << ans.size() << el;
        for (auto& i : ans) cout << i - 1 << " ";
        cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
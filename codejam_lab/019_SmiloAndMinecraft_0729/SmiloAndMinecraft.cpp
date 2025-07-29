#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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
    int n, m, k;
    cin >> n >> m >> k;
    vvi a = vvi(n + 2, vi(m + 2));
    vii v;
    int tot = 0;
    For(i, 1, n) {
        For(j, 1, m) {
            char x;
            cin >> x;
            if (x == 'g') a[i][j] = 1, ++tot;
            if (x == '.') v.push_back({i, j});
        }
    }
    vvi ps = vvi(n + 2, vi(m + 2));
    For(i, 1, n) {
        For(j, 1, m) { ps[i][j] = a[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1]; }
    }

    auto getGold = [&](int x1, int y1, int x2, int y2) {
        return ps[x2][y2] - ps[x2][y1 - 1] - ps[x1 - 1][y2] + ps[x1 - 1][y1 - 1];
    };

    int mn = n * m + 1;
    k -= 1;  // count gold inside not bound of the square
    for (auto& [x, y] : v) {
        int x1 = max(x - k, 1);
        int y1 = max(y - k, 1);
        int x2 = min(x + k, n);
        int y2 = min(y + k, m);
        mn = min(mn, getGold(x1, y1, x2, y2));
    }
    cout << tot - mn << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
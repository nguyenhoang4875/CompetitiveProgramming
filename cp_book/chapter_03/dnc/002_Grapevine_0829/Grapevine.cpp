#include <bits/stdc++.h>

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
        int n, m;
        cin >> n >> m;
        if (!n and !m) return;

        vvi a(n, vi(m));
        Rep(i, n) Rep(j, m) cin >> a[i][j];

        auto getMax = [&](int row, int col, int val) {
            int l = 1, r = min(n - row, m - col);
            int ans = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                // check mid
                bool ok = true;
                int nx = row + mid - 1;
                int ny = col + mid - 1;
                if (nx > n - 1 or ny > m - 1 or a[nx][ny] > val) {
                    ok = false;
                }
                if (ok) {
                    ans = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            return ans;
        };

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            Rep(row, n) {
                auto low = lower_bound(all(a[row]), l);
                if (low == a[row].end()) continue;
                int col = low - a[row].begin();
                ans = max(ans, getMax(row, col, r));
            }
            cout << ans << el;
        }
        cout << "-" << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
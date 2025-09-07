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

int max2dRangeSum(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) a[i][j] += a[i][j - 1];  // prefix sum for row
        }
    }

    int maxSumRect = -oo;

    for (int l = 0; l < m; ++l) {
        for (int r = l; r < m; ++r) {
            int subRect = 0;
            for (int row = 0; row < n; ++row) {
                subRect += a[row][r];
                if (l > 0) subRect -= a[row][l - 1];

                if (subRect < 0) subRect = 0;
                maxSumRect = max(maxSumRect, subRect);
            }
        }
    }
    return maxSumRect;
}

void solve() {
    int n;
    cin >> n;
    vvi a(n, vi(n));
    Rep(i, n) Rep(j, n) cin >> a[i][j];

    cout << max2dRangeSum(a) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
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
    int n;
    int tc = 0;
    while (true) {
        cin >> n;
        if (!n) return;
        vvc a(n, vc(n));
        Rep(i, n) Rep(j, n) { cin >> a[i][j]; }

        bitset<30> row, ld, rd;  // row, left diag, right diag
        int cnt = 0;

        function<void(int)> f = [&](int c) {
            if (c == n) {
                ++cnt;
                return;
            }
            for (int r = 0; r < n; r++) {
                if ((a[r][c] != '*') and !row[r] and !ld[r - c + n - 1] and !rd[r + c]) {
                    row[r] = ld[r - c + n - 1] = rd[r + c] = true;
                    f(c + 1);
                    row[r] = ld[r - c + n - 1] = rd[r + c] = false;
                }
            }
        };
        f(0);
        printf("Case %d: %d\n", ++tc, cnt);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
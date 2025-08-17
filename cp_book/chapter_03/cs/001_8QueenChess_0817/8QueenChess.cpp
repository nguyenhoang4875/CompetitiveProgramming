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
    int x, y;
    cin >> x >> y;
    --x, --y;

    vi row(10);  // row[i]: row of the queen place at column i
    int cnt = 0;

    auto check = [&](int r, int c) {
        for (int pc = 0; pc < c; pc++) {
            if (row[pc] == r or (abs(r - row[pc]) == abs(c - pc))) return false;
        }
        return true;
    };

    function<void(int)> f = [&](int c) {
        if (c == 8) {
            if (row[y] == x) {
                printf("%2d      %d", ++cnt, row[0] + 1);
                for (int j = 1; j < 8; ++j) printf(" %d", row[j] + 1);
                printf("\n");
            }
            return;
        }
        for (int r = 0; r < 8; r++) {
            if (check(r, c)) {
                row[c] = r;
                f(c + 1);
            }
        }
    };

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    f(0);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
        if (tcs) printf("\n");
    }
    return 0;
}
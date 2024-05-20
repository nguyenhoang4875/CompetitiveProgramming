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
const int ms = 2e5 + 5;
int n, m = 3;
int a[ms], ps[ms];
int d[10];
int f[ms][5][2];

int getSum(int l, int r) { return ps[r] - ps[l - 1]; }

void solve() {
    cin >> n;
    for (int i = 1; i <= 3; i++) cin >> d[i];

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];

    // vi p = {1, 2, 3};
    sort(d + 1, d + 3 + 1);
    int ans = -oo;
    do {
        // set init value
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 3; j++) {
                f[i][j][0] = oo;
                f[i][j][1] = -oo;
            }
        }

        // base case
        for (int i = 0; i <= n; i++) {
            f[i][0][0] = 1;
            f[i][0][1] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                // not taken
                f[i][j][1] = f[i - 1][j][1];
                f[i][j][0] = f[i - 1][j][0];

                /// taken postion i for j
                int len = d[j];
                if (i - len >= 0) {
                    if (f[i - len][j - 1][1] != -oo) {
                        f[i][j][1] = max(f[i][j][1], f[i - len][j - 1][1] * getSum(i - len + 1, i));
                        f[i][j][0] = min(f[i][j][0], f[i - len][j - 1][1] * getSum(i - len + 1, i));
                    }
                    if (f[i - len][j - 1][0] != oo) {
                        f[i][j][1] = max(f[i][j][1], f[i - len][j - 1][0] * getSum(i - len + 1, i));
                        f[i][j][0] = min(f[i][j][0], f[i - len][j - 1][0] * getSum(i - len + 1, i));
                    }
                }
            }
        }
        ans = max(ans, f[n][3][1]);

    } while (next_permutation(d + 1, d + 4));
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
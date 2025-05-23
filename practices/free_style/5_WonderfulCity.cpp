#include<bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/2096/problem/C
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
    int n; cin >> n;
    vvi h(n, vi(n));
    Rep(i, n) {
        Rep(j, n) {
            cin >> h[i][j];
        }
    }

    vi a(n), b(n);
    Rep(i, n) cin >> a[i];
    Rep(i, n) cin >> b[i];

    vvi rd(n - 1);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            int t = h[i + 1][j] - h[i][j];
            if (-1 <= t and t <= 1) {
                rd[i].pb(t);
            }
        }
    }

    vvi cd(n - 1);
    for(int j = 0; j < n - 1; j++) {
        for(int i = 0; i < n; i++) {
            int t = h[i][j + 1] - h[i][j];
            if (-1 <= t and t <= 1) {
                cd[j].pb(t);
            }
        }
    }

    auto getMin = [&](vvi &vd, vi& cost) {
        vvb used(n, vb(4, false));

        for(int i = 0; i < n - 1; i++) {
            for(int &d: vd[i]) {
                for(int t = 0; t < 2; t++) {
                    for(int s = 0; s < 2; s++) {
                        if(t - s == d) {
                            used[i][2 * t + s] = true;
                        }
                    }
                }
            }
        }
        vvi f(n, vi(2, oo));
        f[0][0] = 0;
        f[0][1] = cost[0];

        for(int i = 1; i < n; i++) {
            f[i][0] = f[i][1] = oo;
            for (int t = 0; t < 2; t++) {
                for(int s = 0; s < 2; s++) {
                    if(!used[i - 1][2 * t + s] && f[i - 1][t] < oo) {
                        f[i][s] = min(f[i][s], f[i - 1][t] + (s ? cost[i]: 0));
                    }
                }
            }
        }
        return min(f[n - 1][0], f[n - 1][1]);
    };

    int costR = getMin(rd, a);
    int costC = getMin(cd, b);

    int ans = oo;
    if(costR == oo or costC == oo) ans = -1;
    else ans = costR + costC;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}
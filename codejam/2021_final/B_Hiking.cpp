#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define Rof(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define Fore(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

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

int fac[30];
void init() {
    fac[0] = 1;
    For(i, 1, 20) { fac[i] = fac[i - 1] * i % mod; }
}

void solve() {
    int n, m, x, C, D;
    cin >> n >> m >> x >> C >> D;

    vi a(n);
    Rep(i, n) cin >> a[i];
    vi b(m);
    Rep(i, m) cin >> b[i];

    auto getDist = [&](int n, vi& a) {
        vvi f(n + 1);
        f[0].pb(0);
        int maxMask = (1 << n) - 1;
        For(mask, 1, maxMask) {
            int cnt = __builtin_popcount(mask);
            int sum = 0;
            Rep(i, n) {
                if ((mask >> i) & 1) sum += a[i];
            }
            f[cnt].pb(sum);
        }
        For(i, 0, n) sort(all(f[i]));
        return f;
    };

    vvi f1 = getDist(n, a);
    vvi f2 = getDist(m, b);

    auto cntWay = [&](int v1, int v2) {
        int ans = 0;
        For(i, 0, n) {
            for (auto e : f1[i]) {
                For(j, i - 1, i) {
                    if (i == 0 and j == 0) continue;
                    if (j < 0 or j > m) continue;
                    auto up1 = upper_bound(all(f2[j]), v1 - e - (i + j - 1) * x);
                    auto up2 = upper_bound(all(f2[j]), v2 - e - (i + j - 1) * x);
                    if (up1 == up2) continue;
                    int len = up1 - up2;
                    int res = fac[i] * len % mod * fac[j] % mod;
                    ans = (ans + res) % mod;
                }
            }
        }
        return ans;
    };

    int t1 = cntWay(D, C - 1);
    swap(n, m);
    swap(f1, f2);

    int t2 = cntWay(D, C - 1);
    int ans = (t1 + t2 + mod) % mod;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
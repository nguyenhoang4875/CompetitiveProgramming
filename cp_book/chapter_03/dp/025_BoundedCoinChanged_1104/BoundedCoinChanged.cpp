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

int boundedCoinChanged(vi& c, vi& d, int& v) {
    int n = c.size();
    vi f(v + 1);
    f[0] = 1;  // base case
    Rep(i, n) {
        for (int j = c[i]; j <= v; ++j) {
            f[j] += f[j - c[i]];
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1LL << n); ++mask) {
        int cnt = 0, dv = v;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                dv -= (d[i] + 1) * c[i];
                ++cnt;
            }
        }
        if (dv >= 0) {
            if (cnt & 1) ans -= f[dv];
            else ans += f[dv];
        }
    }
    return ans;
};

void solve() {
    int n = 4, q;
    vi c(n);
    Rep(i, n) cin >> c[i];
    cin >> q;
    while (q--) {
        vi d(n);
        Rep(i, n) cin >> d[i];
        int v;
        cin >> v;
        cout << boundedCoinChanged(c, d, v) << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}
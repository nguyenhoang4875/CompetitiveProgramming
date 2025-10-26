#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = (int)distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char* s, Args&&... args) {
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (s[i] && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (s[i] && s[i] != ',') ++i;
        return string(s + st, i - st);
    };
    auto dummy = {(cout << next() << ": " << args << (++cnt < n ? ", " : ""), 0)...};
    (void)dummy;
    cout << " }" << '\n';
}
#else
#define del
#define debug(...)
#endif

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
using vvvi = vector<vvi>;

//*** START CODING ***//

const long long oo = 8e18, ioo = 2e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vii a(n);
    Rep(i, n) cin >> a[i].F >> a[i].S;

    sort(all(a));
    debug(a);

    vi ps(n + 1, 0);
    For(i, 1, n) { ps[i] = ps[i - 1] + a[i - 1].S; }

    vvi fl(n, vi(n, oo));  // min cost out of l, r
    vvi fr(n, vi(n, oo));

    fl[0][n - 1] = 0;
    fr[0][n - 1] = 0;

    Rof(i, n, 1) {
        for (int l = 0; l < n + 1 - i; ++l) {
            int r = l + i - 1;
            if (i == n) continue;

            int sum_w = ps[l] + ps[n] - ps[r + 1];

            int res_l = oo;
            if (l > 0) {
                int d = a[l].F - a[l - 1].F;
                if (fl[l - 1][r] != oo) res_l = min(res_l, d * sum_w + fl[l - 1][r]);
            }
            if (r < n - 1) {
                int d = a[r + 1].F - a[l].F;
                if (fr[l][r + 1] != oo) res_l = min(res_l, d * sum_w + fr[l][r + 1]);
            }
            fl[l][r] = min(fl[l][r], res_l);

            int res_r = oo;
            if (l > 0) {
                int d = a[r].F - a[l - 1].F;
                if (fl[l - 1][r] != oo) res_r = min(res_r, d * sum_w + fl[l - 1][r]);
            }
            if (r < n - 1) {
                int d = a[r + 1].F - a[r].F;
                if (fr[l][r + 1] != oo) res_r = min(res_r, d * sum_w + fr[l][r + 1]);
            }
            fr[l][r] = min(fr[l][r], res_r);
        }
    }
    vi f(n, oo);
    Rep(i, n) f[i] = min(fl[i][i], fr[i][i]);

    auto getAns = [](int s, int b, int c) -> int {
        return s * s + b * s + c;
    };

    int ans = oo;

    // move to at a point
    Rep(i, n) {
        if (f[i] != oo) {
            int s = a[i].F;
            int val = f[i] + s * s;
            ans = min(ans, val);
        }
    }

    // move to not a point
    For(i, 0, n) {
        int ll = 0, rr = 0;
        ;

        if (i == 0) {
            ll = -ioo;
            rr = a[0].F - 1;
        } else if (i == n) {
            ll = a[n - 1].F + 1;
            rr = ioo;
        } else {
            ll = a[i - 1].F + 1;
            rr = a[i].F - 1;
        }

        if (ll > rr) continue;

        auto cal = [&](int b, int c) {
            double ct = -1.0 * b / 2;
            int res = oo;
            if (ct < ll) {
                int s = ll;
                res = getAns(s, b, c);
            } else if (ct > rr) {
                int s = rr;
                res = getAns(s, b, c);
            } else {
                int s1 = floor(ct);
                for (int s = s1 - 5; s <= s1 + 5; ++s) {
                    if (ll <= s and s <= rr) res = min(res, getAns(s, b, c));
                }
            }
            return res;
        };

        if (i > 0) {
            int b = ps[n];
            if (f[i - 1] != oo) {
                int c = f[i - 1] - b * a[i - 1].F;
                int res = cal(b, c);
                ans = min(ans, res);
            }
        }
        if (i < n) {
            int b = -ps[n];
            if (f[i] != oo) {
                int c = f[i] - b * a[i].F;
                int res = cal(b, c);
                ans = min(ans, res);
            }
        }
    }

    cout << ans << el;

    debug("pass");
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
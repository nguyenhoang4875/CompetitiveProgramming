#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

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

    vi ps(n + 1, 0), psm(n + 1, 0);

    For(i, 1, n) {
        ps[i] = ps[i - 1] + a[i - 1].S;
        psm[i] = psm[i - 1] + a[i - 1].F * a[i - 1].S;
    }

    int ans = oo;

    // move to at a point
    Rep(i, n) {
        int s = a[i].F;
        int w = a[i].S;

        int psl = (i == 0) ? 0 : ps[i];
        int psr = (i == n - 1) ? 0 : ps[n] - ps[i + 1];

        int pml = (i == 0) ? 0 : psm[i];
        int pmr = (i == n - 1) ? 0 : psm[n] - psm[i + 1];

        int sum_w = psl + psr;
        int res = oo;

        if (i > 0) {
            int p_min = a[0].F;
            int b = sum_w;
            int c = pmr - pml - 2 * p_min * psr;
            res = min(res, b * s + c);
        }
        if (i < n - 1) {
            int p_max = a[n - 1].F;
            int b = -sum_w;
            int c = pmr - pml + 2 * p_max * psl;
            res = min(res, b * s + c);
        }
        if (res == oo) res = 0;
        res += s * s;
        ans = min(ans, res);
    }
    debug(ans);

    auto getAns = [](int s, int b, int c) -> int {
        return s * s + b * s + c;
    };

    // move to not a point
    For(i, 0, n) {
        int psl = ps[i];
        int psr = ps[n] - ps[i];

        int pml = psm[i];
        int pmr = psm[n] - psm[i];

        int sum_w = psl + psr;

        int ll = 0, rr = 0;
        if (i == 0) {
            ll = -ioo;
            rr = n > 0 ? a[0].F - 1 : 0;
        } else if (i == n) {
            ll = n > 0 ? a[n - 1].F + 1 : 0;
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
                // int s2 = ceil(ct);
                // int v1 = (ll <= s1 and s1 <= rr) ? getAns(s1, b, c) : oo;
                // int v2 = (ll <= s2 and s2 <= rr) ? getAns(s2, b, c) : oo;
                // res = min(v1, v2);
                for(int s = s1 - 5; s < s1 + 5; ++s) {
                    int val = (ll <= s and s1 <= rr) ? getAns(s, b, c) : oo;
                    res = min(res, val);
                }
            }
            return res;
        };

        if (i > 0) {
            int p_min = a[0].F;
            int b = sum_w;
            int c = pmr - pml - 2LL * p_min * psr;
            ans = min(ans, cal(b, c));
        }
        if (i < n) {
            int p_max = a[n - 1].F;
            int b = -sum_w;
            int c = pmr - pml + 2LL * p_max * psl;
            ans = min(ans, cal(b, c));
        }
    }
    debug(ans);
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
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

    vi ps(n + 1, 0), psm(n + 1, 0);

    For(i, 1, n) {
        ps[i] = ps[i - 1] + a[i - 1].S;
        psm[i] = psm[i - 1] + a[i - 1].F * a[i - 1].S;
    }

    auto compute_s = [&](vii &vl, vii &vr, int s) {
        int nl = vl.size();
        int nr = vr.size();
        if (nl + nr == 0) return 0LL;

        vvvi f(nl + 1, vvi(nr + 1, vi(2, oo)));  // for value f[l][r][side]
        vvvi ft(nl + 1, vvi(nr + 1, vi(2, 0)));  // for time

        if (nl > 0) {
            int p = vl[0].F;
            int time = abs(s - p);
            int sum = vl[0].S * time;
            f[1][0][0] = sum;
            ft[1][0][0] = time;
        }

        if (nr > 0) {
            int p = vr[0].F;
            int time = abs(s - p);
            int sum = vr[0].S * time;
            f[0][1][1] = sum;
            ft[0][1][1] = time;
        }

        int sn = nl + nr;

        For(i, 1, sn - 1) {
            For(l, 0, nl) {
                int r = i - l;
                if (r < 0 or r > nr) continue;

                Rep(sd, 2) {
                    if (f[l][r][sd] == oo) continue;
                    int cur_time = ft[l][r][sd];
                    int cur_p = (sd == 0 ? vl[l - 1].F : vr[r - 1].F);

                    if (l < nl) {
                        int new_p = vl[l].F;
                        int new_time = cur_time + abs(cur_p - new_p);
                        int new_sum = f[l][r][sd] + vl[l].S * new_time;
                        int new_l = l + 1, new_r = r, new_sd = 0;

                        if (f[new_l][new_r][new_sd] > new_sum) {
                            f[new_l][new_r][new_sd] = new_sum;
                            ft[new_l][new_r][new_sd] = new_time;
                        }
                    }

                    if (r < nr) {
                        int new_p = vr[r].F;
                        int new_time = cur_time + abs(cur_p - new_p);
                        int new_sum = f[l][r][sd] + vr[r].S * new_time;
                        int new_l = l, new_r = r + 1, new_sd = 1;

                        if (f[new_l][new_r][new_sd] > new_sum) {
                            f[new_l][new_r][new_sd] = new_sum;
                            ft[new_l][new_r][new_sd] = new_time;
                        }
                    }
                }
            }
        }
        int res = oo;
        Rep(sd, 2) { res = min(res, f[nl][nr][sd]); }
        return res;
    };

    int ans = oo;

    // move to at a point
    Rep(i, n) {
        int ss = a[i].F;
        vii vl, vr;
        for (auto& [p, w] : a) {
            if (p < ss) vl.push_back({p, w});
            if (p > ss) vr.pb({p, w});
        }

        reverse(all(vl));
        int res = compute_s(vl, vr, a[i].F);
        debug(i, res);
        ans = min(ans, res + ss * ss);
        debug(i, ans);
    }

    auto getAns = [](int s, int b, int c) -> int {
        return s * s + b * s + c;
    };

    // move to not a point
    For(i, 0, n) {
        int psl = ps[i];
        int psr = ps[n] - ps[i];

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

        int nl = i;
        int nr = n - i;
        vii vl(nl), vr(nr);

        Rep(j, nl) { vl[j] = a[i - 1 - j]; }

        Rep(j, nr) { vr[j] = a[i + j]; }

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
                int s2 = ceil(ct);
                int v1 = (ll <= s1 and s1 <= rr) ? getAns(s1, b, c) : oo;
                int v2 = (ll <= s2 and s2 <= rr) ? getAns(s2, b, c) : oo;
                res = min(v1, v2);
                for (int s = s1 - 5; s < s1 + 5; ++s) {
                    int val = (ll <= s and s1 <= rr) ? getAns(s, b, c) : oo;
                    res = min(res, val);
                }
            }
            return res;
        };

        if (nl > 0) {
            int b = sum_w;

            vii vll = vl;
            vll.erase(vll.begin());

            int pc = compute_s(vll, vr, vl[0].F);
            int c = pc - sum_w * vl[0].F;
            ans = min(ans, cal(b, c));
        }
        if (nr > 0) {
            int b = -sum_w;
            vii vrr = vr;
            vrr.erase(vrr.begin());
            int pc = compute_s(vl, vrr, vr[0].F);
            int c = pc + sum_w * vr[0].F;
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
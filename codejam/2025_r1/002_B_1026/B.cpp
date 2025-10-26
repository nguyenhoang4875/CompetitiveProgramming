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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
using node = array<int, 3>;  // 0: day, 1: type, 2: idx

void solve() {
    int n, k;
    cin >> n >> k;
    vi s(n), e(n), p(n), d(n);

    Rep(i, n) cin >> s[i] >> e[i] >> p[i] >> d[i];

    vector<node> v;
    Rep(i, n) {
        v.pb({s[i], 1, i});
        v.pb({e[i] + 1, 0, i});
    }

    sort(all(v));

    int ans = oo;
    int tot_eng = 0;
    int tot_d = 0;
    int cnt = 0;
    bool first = true;

    debug(v);
    int nv = v.size();
    int i = 0;
    while (i < nv) {
        int cur_d = v[i][0];

        if (!first) {
            if (cnt >= k) {
                int tmp = tot_eng - tot_d * (cur_d - 1);
                ans = min(ans, tmp);
            }
        }

        while (i < nv and v[i][0] == cur_d) {
            auto [dd, type, idx] = v[i];

            int eng = p[idx] + d[idx] * s[idx];
            if (type) {
                tot_eng += eng;
                tot_d += d[idx];
                ++cnt;
            } else {
                tot_eng -= eng;
                tot_d -= d[idx];
                --cnt;
            }
            ++i;
        }
        first = false;
    }
    if (ans == oo) ans = -1; 
    cout << ans << el;
    debug("Pass");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
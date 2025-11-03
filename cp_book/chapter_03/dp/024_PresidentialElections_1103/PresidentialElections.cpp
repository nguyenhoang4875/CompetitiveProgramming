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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi D(n + 1), C(n + 1), F(n + 1), U(n + 1);

    For(i, 1, n) cin >> D[i] >> C[i] >> F[i] >> U[i];
    int SD = 0;
    For(i, 1, n) SD += D[i];
    debug(n, D, C, F, U);
    debug(SD);

    vvi f(n + 1, vi(SD + 1, oo));
    // f[i][j]  min voted needed to convince to make C for first i-th state has exactly j-th point

    f[0][0] = 0;  // base case: không xét state nào, 0 delegates

    For(i, 1, n) {
        // if can not select i-th state
        For(s, 0, SD) f[i][s] = f[i - 1][s];

        for (int s = SD; s >= D[i]; --s) {
            if (f[i - 1][s - D[i]] == oo) continue;

            if (C[i] > F[i] + U[i]) {  // already win
                f[i][s] = min(f[i][s], f[i - 1][s - D[i]]);
            } else if (C[i] + U[i] > F[i]) {  // can win
                int tot = C[i] + F[i] + U[i];
                int need_c = (tot / 2) + 1 - C[i];
                f[i][s] = min(f[i][s], f[i - 1][s - D[i]] + need_c);
            }
        }
    }

    int ans = oo;
    for (int val = SD / 2 + 1; val <= SD; ++val) {
        ans = min(ans, f[n][val]);
    }
    if (ans == oo) cout << "impossible" << el;
    else cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
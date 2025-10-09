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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    while (true) {
        int n, t;
        cin >> n >> t;
        if (!n and !t) break;
        vvi time(n, vi(n));
        Rep(i, n) Rep(j, n) cin >> time[i][j];

        vvi money(n, vi(n));
        Rep(i, n) Rep(j, n) cin >> money[i][j];

        // Top-down

        // vector<vii> memo(n, vii(t + 1, {-1, -1}));

        // f[i][j] {m, t} : Chi phí nhỏ nhất và thời gian thực tế
        // cần để đi từ cur → n-1 (chợ) khi còn lại t_left đơn vị thời gian.
        // function<pii(int, int)> f = [&](int cur, int t_left) {
        //     if (t_left < 0) return pii(oo, oo);
        //     if (cur == n - 1) return pii(0, 0);

        //     if (memo[cur][t_left] != pii(-1, -1)) return memo[cur][t_left];
        //     pii ans = {oo, oo};

        //     Rep(x, n) {
        //         if (cur != x) {
        //             auto [m, t] = f(x, t_left - time[cur][x]);
        //             if (m == oo) continue;
        //             if (m + money[cur][x] < ans.F) {
        //                 ans.F = m + money[cur][x];
        //                 ans.S = t + time[cur][x];
        //             }
        //         }
        //     }
        //     return memo[cur][t_left] = ans;
        // };

        // pii ans = f(0, t);
        // cout << ans.F << " " << ans.S << el;

        // Bottom up
        vvi f(n, vi(t + 1, oo));  // f[i][j]: chi phí nhỏ nhất để đi từ 0 -> i với thời gian đúng là j
        f[0][0] = 0;
        Rep(tt, t + 1) {
            Rep(u, n) {
                if (f[u][tt] == oo) continue;
                Rep(v, n) {
                    if (v == u) continue;
                    int nt = tt + time[u][v];
                    if (nt > t) continue;
                    int nc = f[u][tt] + money[u][v];
                    if (nc < f[v][nt]) f[v][nt] = nc;
                }
            }
        }

        int best_cost = oo, best_time = oo;
        For(i, 0, t) {
            if (best_cost > f[n - 1][i]) {
                best_cost = f[n - 1][i];
                best_time = i;
            }
        }
        cout << best_cost << " " << best_time << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
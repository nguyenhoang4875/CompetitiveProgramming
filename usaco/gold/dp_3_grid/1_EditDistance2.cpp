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

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout <<  '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char* names, Args&&... args) {
    string_view s(names);
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',') ++i;
        return s.substr(st, i - st);
    };
    ((cout << next() << ": " << args << (++cnt < n ? ", " : "")), ...);
    cout << " }" << '\n';
}
#else
#define del
#define debug(...)
#endif


void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vvi f(n + 1, vi(m + 1, oo));
    For(i, 0, n) {
        For(j, 0, m) {
            // base case
            if (i == 0 or j == 0) {
                f[i][j] = i + j;
                continue;
            }
            if(s[i - 1] == t[j - 1]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                // add(in s): f[i][j - 1], remove(in s): f[i - 1][j], change: f[i - 1][j - 1]
                f[i][j] = min({f[i - 1][j - 1], f[i][j - 1], f[i - 1][j]}) + 1;
            }
        }
    }
    debug(f);
    cout << f[n][m];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
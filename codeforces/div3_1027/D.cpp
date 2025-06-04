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
    int n;
    cin >> n;
    vii a(n);
    Rep(i, n) { cin >> a[i].F >> a[i].S; }
    if (n <= 1) {
        cout << n << el;
        return;
    }
    vii b = a;
    // sort a by x;
    sort(all(a), [&](pii p1, pii p2) { return p1.F < p2.F; });

    sort(all(b), [&](pii p1, pii p2) { return p1.S < p2.S; });

    int mny = oo, mxy = -oo;
    For(i, 1, n - 2) {
        mny = min(mny, a[i].S);
        mxy = max(mxy, a[i].S);
    }
    // remove min x
    int minX = a[1].F;
    int maxX = a.back().F;
    int minY = min({mny, a.back().S});
    int maxY = max({mxy, a.back().S});
    int ans = (maxX - minX + 1) * (maxY - minY + 1);
    int t = (maxX - minX + 2) * (maxY - minY + 1);
    t = min(t, (maxX - minX + 1) * (maxY - minY + 2))

    debug(minX, maxX, minY, maxY);
    debug(ans);

    // remove maxX;
    minX = a.front().F;
    maxX = a[n - 2].F;
    minY = min({mny, a.front().S});
    maxY = max({mxy, a.front().S});
    ans = min(ans, (maxX - minX + 1) * (maxY - minY + 1));
    t = min(t, (maxX - minX + 2) * (maxY - minY + 1));
    t = min(t, (maxX - minX + 1) * (maxY - minY + 2));
    debug(minX, maxX, minY, maxY);
    debug(ans);

    int mnx = oo, mxx = -oo;
    For(i, 1, n - 2) {
        mnx = min(mnx, b[i].F);
        mxx = max(mxx, b[i].F);
    }
    // remove min y
    minY = b[1].S;
    maxY = b.back().S;
    minX = min({mnx, b.back().F});
    maxX = max({mxx, b.back().F});
    ans = min(ans, (maxX - minX + 1) * (maxY - minY + 1));
    t = min(t, (maxX - minX + 2) * (maxY - minY + 1));
    t = min(t, (maxX - minX + 1) * (maxY - minY + 2));
    debug(minX, maxX, minY, maxY);
    debug(ans);

    // remove max Y;
    debug(b);
    minY = b.front().S;
    maxY = b[n - 2].S;
    minX = min({mnx, b.front().F});
    maxX = max({mxx, b.front().F});
    ans = min(ans, (maxX - minX + 1) * (maxY - minY + 1));
    t = min(t, (maxX - minX + 2) * (maxY - minY + 1));
    t = min(t, (maxX - minX + 1) * (maxY - minY + 2));
    debug(minX, maxX, minY, maxY);
    if(ans < n) ans = t;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

struct tri {
    pii o, a, b;
};

double area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void solve() {
    int n;
    cin >> n;
    vector<tri> v;
    int mul = 4;

    Rep(i, n) {
        int o, d, x, y;
        cin >> o >> d >> x >> y;
        d *= mul;
        x *= mul;
        y *= mul;
        pii O = {x, y};
        pii A, B;

        if (o == 1) {
            A = {x - d, y};
            B = {x, y + d};
        } else if (o == 2) {
            A = {x + d, y};
            B = {x, y + d};
        } else if (o == 3) {
            A = {x - d, y};
            B = {x, y - d};
        } else {
            A = {x + d, y};
            B = {x, y - d};
        }
        tri t;
        t.o = O;
        t.a = A;
        t.b = B;
        v.push_back(t);
    }

    auto inside = [](pii p, tri t) {
        double a = area(t.o.F, t.o.S, t.a.F, t.a.S, t.b.F, t.b.S);

        double a1 = area(p.F, p.S, t.a.F, t.a.S, t.b.F, t.b.S);
        double a2 = area(t.o.F, t.o.S, p.F, p.S, t.b.F, t.b.S);
        double a3 = area(t.o.F, t.o.S, t.a.F, t.a.S, p.F, p.S);

        return abs(a - (a1 +a2 + a3)) < 1e-6;
    };

    auto check = [&](pii p)  {
        for(auto t: v) {
            if(inside(p, t)) {
                return true;
            }
        }
        return false;
    };
    double ans = 0;
    int cnt = 0;
    for (int i = 0; i <= 100 * mul / 2; i++) {
        for (int j = 0; j <= 100 * mul / 2; j++) {
            int x = i * mul / 2;
            int y = j * mul / 2;

            vii cn = {{x, y}, {x + mul, y}, {x + mul, y + mul}, {x, y + mul}};

            pii center = {x + mul / 2, y + mul / 2};

            vi tmp = {0, 1, 2, 3, 0};
            for (int i = 1; i <= 4; i++) {
                pii aa = cn[tmp[i - 1]];
                pii bb = cn[tmp[i]];
                if(check(center) and check(aa) and check(bb)) {
                    ++cnt;
                }
            }
        }
    }
    cout << cnt << el;
    cout << fixed << setprecision(2);
    cout << ans << el;
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
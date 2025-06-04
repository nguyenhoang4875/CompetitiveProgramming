#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, Container const &x) {
    os << "{ ";
    for (const auto &y : x) os << y << ", ";
    return os << "}";
}
#else
#define del
#define debug(x)
#endif

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for(int i = 0, _n = (n); i < (_n); i++)
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

template <int mod>
struct Mint {
    int v;
    explicit operator int() const { return v; }
    Mint() { v = 0; }
    Mint(long long _v) : v(_v % mod) { v += (v < 0) * mod; }

    friend Mint &operator+=(Mint &a, Mint b) {
        if ((a.v += b.v) >= mod) a.v -= mod;
        return a;
    }

    friend Mint &operator-=(Mint &a, Mint b) {
        if ((a.v -= b.v) < 0) a.v += mod;
        return a;
    }
    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return Mint((long long)a.v * b.v); }
    friend Mint &operator*=(Mint &a, Mint b) { return a = a * b; }
    friend Mint pow(Mint a, long long p) {
        assert(p >= 0);
        return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
    }
    friend Mint inv(Mint a) {
        assert(a.v != 0);
        return pow(a, mod - 2);
    }
    friend Mint invGcd(Mint a) {
        int g = mod, r = a.v, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r;
            swap(g, r);
            x -= q * y;
            swap(x, y);
        }
        assert(g == 1);
        if (x < 0) x += mod;
        return Mint(x);
    }
    friend Mint operator/(Mint a, Mint b) { return a * inv(b); }
    friend ostream &operator<<(ostream &os, const Mint &m) { return os << m.v; }
    friend istream &operator>>(istream &is, Mint &m) {
        long long x;
        is >> x;
        m = Mint(x);
        return is;
    }
};

using mi = Mint<mod>;

void solve() {
    int n, m;
    cin >> n >> m;

    mi nn = mi(n);
    mi mm = mi(m);

    mi f1 = nn * mm;
    m = min(n, m);

    mi f2;
    mi iv2 = inv(mi(2));

    int minVal = m;
    for (int i = 1; i * i <= n; i++) {
        int l = n / (i + 1), r = n / i;
        r = min(r, m);
        if (l >= r) continue;
        minVal = l;
        mi sumR = mi(r) * mi(r + 1) * iv2;
        mi sumL = mi(l) * mi(l + 1) * iv2;
        mi t = mi(sumR - sumL);
        f2 += mi(i) * t;
    }

    for (int i = 1; i <= minVal; i++) { f2 += mi(i) * mi(n / i); }

    mi ans = f1 - f2;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
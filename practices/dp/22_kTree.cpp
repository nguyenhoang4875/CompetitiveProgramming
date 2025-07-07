#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/problemset/problem/431/C
 */

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
template <int mod>
struct Mint {
    int v;
    explicit operator int() const { return v; }
    Mint() { v = 0; }
    Mint(long long _v) : v(_v% mod) { v += (v < 0) * mod; }

    friend Mint& operator+=(Mint& a, Mint b) { if ((a.v += b.v) >= mod) a.v -= mod; return a; }
    friend Mint& operator-=(Mint& a, Mint b) { if ((a.v -= b.v) < 0) a.v += mod; return a; }
    friend Mint& operator++(Mint& a) { return a += 1; }
    friend Mint& operator--(Mint& a) { return a -= 1; }

    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return Mint((long long)a.v * b.v); }
    friend Mint& operator*=(Mint& a, Mint b) { return a = a * b; }
    friend Mint pow(Mint a, long long p) {
        assert(p >= 0);
        return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
    }
    friend Mint inv(Mint a) { assert(a.v != 0); return pow(a, mod - 2); }
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
    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.v; }
    friend istream& operator>>(istream& is, Mint& m) { long long x; is >> x; m = Mint(x); return is; }
    friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
};

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

using mi = Mint<mod>;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<mi> f(n + 1); // f[i]: number of way sum all path = i
    vector<mi> g(n + 1); // g[i]: number of way sull all path = i with each edge < d

    f[0] = g[0] = 1;

    For(i, 1, n) {
        For(j, 1, k) {
            if(i - j < 0) break;
            f[i] += f[i - j];
        }
    }

    For(i, 1, n) {
        For(j, 1, d - 1) {
            if(i - j < 0) break;
            g[i] += g[i - j];
        }
    }
    mi ans = f[n] - g[n];
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
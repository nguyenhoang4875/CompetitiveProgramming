#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % mod) { v += (v < 0) * mod; }

    friend mi &operator+=(mi &a, mi b) {
        if ((a.v += b.v) >= mod) a.v -= mod;
        return a;
    }

    friend mi &operator-=(mi &a, mi b) {
        if ((a.v -= b.v) < 0) a.v += mod;
        return a;
    }
    friend mi operator+(mi a, mi b) { return a += b; }
    friend mi operator-(mi a, mi b) { return a -= b; }
    friend mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
    friend mi &operator*=(mi &a, mi b) { return a = a * b; }
    friend mi pow(mi a, long long p) {
        assert(p >= 0);
        return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
    }
    friend mi inv(mi a) {
        assert(a.v != 0);
        return pow(a, mod - 2);
    }
    friend mi operator/(mi a, mi b) { return a * inv(b); }
    friend ostream &operator<<(ostream &os, const mi &m) { return os << m.v; }
};

int32_t main() {
    mi a = 123;
    mi b = 123;
    cout << a << " " << b << '\n';
    // 123 ^ 123 % mod = 921450052
    cout << (int)pow(a, (int)b) << '\n';
}

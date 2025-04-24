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

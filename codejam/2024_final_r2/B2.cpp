#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
const int ms = 250005, ms2 = ms;

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


template <typename T>
struct SegmentTreeLazy {
    int n;
    vector<T> t, lazy;

    SegmentTreeLazy(int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    SegmentTreeLazy(const vector<T>& a, int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(a, 1, 1, n);
    }

    void build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    // !!! Important update base case for INVALID and push function
    T combine(T v1, T v2) { return v1 + v2; }

    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;
        // update segment tree node
        t[v] += lazy[v] * (tr - tl + 1);  // For min or max:  t[v] += lazy[v];

        if (tl != tr) {
            // propagate the updated value
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }

    T query(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tl > r || tr < l) return 0;  // INVALID
        if (l <= tl and tr <= r) return t[v];

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int l, int r, T val) {
        push(v, tl, tr);
        // not overlapping case
        if (tl > r || tr < l) return;

        // complete overlapping case
        if (l <= tl and tr <= r) {
            t[v] += val * (tr - tl + 1);
            if (tl != tr) {
                lazy[2 * v] += val;
                lazy[2 * v + 1] += val;
            }
            return;
        }

        // partial case
        int mid = (tl + tr) / 2;
        update(2 * v, tl, mid, l, r, val);
        update(2 * v + 1, mid + 1, tr, l, r, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    T query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int l, int r, T val) { update(1, 1, n, l, r, val); }
};

using mi = Mint<mod>;

int n, m;
int SS[ms], X[ms], Y[ms];

int modN(int x) {
    x--;
    x = (x % n + n) % n;
    x++;
    return x;
}

void solve() {
    cin >> n >> m;
    vector<mi> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) cin >> SS[i];
    for (int i = 1; i <= m; i++) cin >> X[i];
    for (int i = 1; i <= m; i++) cin >> Y[i];

    SegmentTreeLazy<mi> st(n);
    st.build(v, 1, 1, n);

    int l2r = 1;
    int root = 1;
    for (int i = 1; i <= m; i++) {
        int s = SS[i], x = X[i], y = Y[i];

        switch (s) {
        case 1:
            root += l2r * x;
            root = modN(root);
            break;
        case 2:
            root -= l2r * x;
            root = modN(root);
            break;
        case 3:
            l2r *= -1;
            break;
        case 4:
            x--;
            if (l2r == 1) {
                int next = root + x;
                if (next <= n) {
                    st.update(root, next, y);
                }
                else {
                    st.update(root, n, y);
                    st.update(1, modN(next), y);
                }
            }
            else {
                int next = root - x;
                if (next >= 1) {
                    st.update(next, root, y);
                }
                else {
                    st.update(1, root, y);
                    st.update(modN(next), n, y);
                }
            }
            break;
        case 5:
            x--;
            mi ret = 0;
            if (l2r == 1) {
                int next = root + x;
                if (next <= n) {
                    ret += st.query(root, next);
                }
                else {
                    ret += st.query(root, n);
                    ret += st.query(1, modN(next));
                }
            }
            else {
                int next = root - x;
                if (next >= 1) {
                    ret += st.query(next, root);
                }
                else {
                    ret += st.query(1, root);
                    ret += st.query(modN(next), n);
                }
            }
            cout << ret << " ";
            break;
        }
    }
    cout << el;
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
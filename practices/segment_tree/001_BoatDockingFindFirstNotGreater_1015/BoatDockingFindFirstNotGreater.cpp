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

//*** START CODING ***//

const long long oo = 9e18 + 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;

template <typename T = int>
struct SegmentTree {
    int n;
    vector<T> t;
    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n);
    };
    SegmentTree(vector<T> a, int _n) {
        n = _n;
        t.resize(4 * n);
        build(a, 1, 1, n);
    };

    void build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    // !!! Important update combine and base case for INVALID
    T combine(T v1, T v2) { return min(v1, v2); }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return oo;  // INVALID
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return combine(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }

    // update a[pos] += delta and also update the value of t array
    void update(int v, int tl, int tr, int pos, T delta) {
        if (tl == tr) t[v] += delta;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2 * v, tl, tm, pos, delta);
            else update(2 * v + 1, tm + 1, tr, pos, delta);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, T delta) { update(1, 1, n, pos, delta); }
    void assign(int pos, T newVal) { update(pos, newVal - query(pos, pos)); }

    int find_fist_not_greater(int val) {
        if (n <= 0) return 0;
        if (t[1] > val) return 0;
        // int v = 1, tl = 1, tr = n;
        // while (tl != tr) {
        //     int tm = (tl + tr) >> 1;
        //     if (t[v << 1] <= val) {
        //         v = v << 1;
        //         tr = tm;
        //     } else {
        //         v = v << 1 | 1;
        //         tl = tm + 1;
        //     }
        // }
        // return tl;
        return find_rec(1, 1, n, val);
    }
    int find_rec(int v, int tl, int tr, int x) {
        // if (t[v] > x) return 0;
        if (tl == tr) return tl;
        int tm = (tl + tr) >> 1;
        if (t[v << 1] <= x) return find_rec(v << 1, tl, tm, x);
        return find_rec((v << 1) | 1, tm + 1, tr, x);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi p(n + 1);
    For(i, 1, n) cin >> p[i];
    vi b(m + 1);
    For(i, 1, m) cin >> b[i];

    SegmentTree<int> st(b, m);
    vi a(n + 1);
    For(i, 1, n) {
        int val = st.find_fist_not_greater(p[i]);
        if (val != 0) {
            a[i] = val;
            st.assign(val, oo);
        }
    }
    int ans = 0;
    For(i, 1, n) { ans += a[i] * i; }
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
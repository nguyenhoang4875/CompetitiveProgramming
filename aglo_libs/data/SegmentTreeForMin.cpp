template <typename T = int>
struct SegmentTree {
    int n;
    vector<T> t;
    const long long INVALID = 2e18;
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

    T combine(T v1, T v2) { return min(v1, v2); }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return INVALID;
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return combine(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }

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
};
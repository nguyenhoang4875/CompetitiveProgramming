/**
 * SegmentTree for Not Accumulate: like min, max, xor, gcd, ...
 * Update: combine function, INVALID value
 */
template <typename T = int>
struct SegmentTreeNotAcc {
    int n;
    vector<T> t, lazy;

    SegmentTreeNotAcc(int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    SegmentTreeNotAcc(const vector<T>& a, int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(a, 1, 1, n);
    }

    void build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    // !!! Important update base case for INVALID and push function
    T combine(T v1, T v2) { return min(v1, v2); }

    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;
        // update segment tree node
        t[v] += lazy[v];  // For min or max:  t[v] += lazy[v];

        if (tl != tr) {
            // propagate the updated value
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }

    T query(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tl > r || tr < l) return 2e18;  // INVALID: for min = oo, max = -oo
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
            t[v] += val;  // For min or max:  t[v] += val;
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
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }

    T query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int l, int r, T val) { update(1, 1, n, l, r, val); }
};

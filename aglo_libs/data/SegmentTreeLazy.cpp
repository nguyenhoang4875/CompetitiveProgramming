template <typename T = int>
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
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }    }

    // !!! Important update base case for INVALID and push function
    T combine(T v1, T v2) { return v1 + v2; }

    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;

        // Apply lazy to current node
        t[v] += lazy[v] * (tr - tl + 1);  // For min or max:  t[v] += lazy[v];

        // Propagate to children
        if (tl != tr) {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }

        // Clear lazy
        lazy[v] = 0;
    }

    T query(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);

        if (tl > r || tr < l) return 0;        // No overlap INVALID: for min = oo, max = -oo
        if (l <= tl and tr <= r) return t[v];  // Complete overlap

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int l, int r, T val) {
        // No overlap
        if (tl > r || tr < l) return;

        // Complete overlap - ONLY update lazy
        if (l <= tl and tr <= r) {
            lazy[v] += val;
            push(v, tl, tr);  // Apply immediately
            return;
        }

        // Partial overlap - push first
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        update(2 * v, tl, mid, l, r, val);
        update(2 * v + 1, mid + 1, tr, l, r, val);

        // Update current node from children (must push children first)
        push(2 * v, tl, mid);
        push(2 * v + 1, mid + 1, tr);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }

    T query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int l, int r, T val) { update(1, 1, n, l, r, val); }
};

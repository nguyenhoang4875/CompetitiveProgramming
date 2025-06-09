template <typename T = int>
struct SegmentTreeLazy {
    int n;
    vector<T> t;
    // lazy tags: range addition and range assignment
    vector<T> lazyAdd, lazySet;
    vector<bool> hasSet;

    // Configuration for different operations:
    // For sum: INIT_VAL = 0, INVALID_VAL = 0
    // For min: INIT_VAL = INF, INVALID_VAL = INF
    const T INIT_VAL = 0;
    const T INVALID_VAL = 0;

    SegmentTreeLazy(int _n) {
        n = _n;
        t.assign(4 * n, INIT_VAL);
        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        hasSet.assign(4 * n, false);
    }

    SegmentTreeLazy(const vector<T>& a, int _n) {
        n = _n;
        t.assign(4 * n, INIT_VAL);
        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        hasSet.assign(4 * n, false);
        build(a, 1, 1, n);
    }

    void build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];  // Use 1-indexed array directly
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            combine(v);
        }
    }

    void combine(int v) {
        // For sum operation
        t[v] = t[2 * v] + t[2 * v + 1];
        // For min operation: t[v] = min(t[2*v], t[2*v+1]);
    }

    void push(int v, int tl, int tr) {
        // Set operation has higher priority than add
        if (hasSet[v]) {
            // For sum: multiply by segment length
            t[v] = lazySet[v] * (tr - tl + 1);
            // For min: t[v] = lazySet[v];

            if (tl != tr) {
                // Propagate set tag to children
                lazySet[2 * v] = lazySet[2 * v + 1] = lazySet[v];
                hasSet[2 * v] = hasSet[2 * v + 1] = true;
                lazyAdd[2 * v] = lazyAdd[2 * v + 1] = 0;  // Clear add tags
            }
            hasSet[v] = false;
            lazySet[v] = 0;
        }

        if (lazyAdd[v] != 0) {
            // For sum: multiply by segment length
            t[v] += lazyAdd[v] * (tr - tl + 1);
            // For min: t[v] += lazyAdd[v];

            if (tl != tr) {
                // Propagate add tag to children
                lazyAdd[2 * v] += lazyAdd[v];
                lazyAdd[2 * v + 1] += lazyAdd[v];
            }
            lazyAdd[v] = 0;
        }
    }

    void updateAdd(int v, int tl, int tr, int l, int r, T val) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazyAdd[v] += val;
            push(v, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        push(2 * v, tl, mid);
        push(2 * v + 1, mid + 1, tr);
        updateAdd(2 * v, tl, mid, l, min(r, mid), val);
        updateAdd(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, val);
        combine(v);
    }

    void updateSet(int v, int tl, int tr, int l, int r, T val) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazySet[v] = val;
            hasSet[v] = true;
            lazyAdd[v] = 0;
            push(v, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        push(2 * v, tl, mid);
        push(2 * v + 1, mid + 1, tr);
        updateSet(2 * v, tl, mid, l, min(r, mid), val);
        updateSet(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, val);
        combine(v);
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return INVALID_VAL;
        push(v, tl, tr);
        if (l == tl && r == tr) {
            return t[v];
        }
        int mid = (tl + tr) / 2;
        T left = query(2 * v, tl, mid, l, min(r, mid));
        T right = query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);

        // For sum operation
        return left + right;
        // For min operation: return min(left, right);
    }

    // Public interface (all 1-indexed)
    void updateAdd(int l, int r, T val) { updateAdd(1, 1, n, l, r, val); }

    void updateSet(int l, int r, T val) { updateSet(1, 1, n, l, r, val); }

    T query(int l, int r) { return query(1, 1, n, l, r); }
};

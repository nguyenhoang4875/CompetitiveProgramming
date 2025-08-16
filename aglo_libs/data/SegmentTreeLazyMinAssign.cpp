/**
 * SegmentTree for Not Accumulate: like min, max, xor, gcd, ...
 * Update: combine function, INVALID value
 */
template <typename T = int>
struct SegmentTreeLazy {
    int n;
    vector<T> t;
    // lazy tags: range addition and range assignment
    vector<T> lazyAdd, lazySet;
    vector<bool> hasSet;

    const T INIT_VAL = 0, INVALID_VAL = 2e18;  // for min

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
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    T combine(T v1, T v2) {
        return min(v1, v2);  // for min
    }

    void push(int v, int tl, int tr) {
        // Set operation has higher priority than add
        if (hasSet[v]) {
            t[v] = lazySet[v];  // for min

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
            t[v] += lazyAdd[v];  // for min

            if (tl != tr) {
                // Propagate add tag to children
                lazyAdd[2 * v] += lazyAdd[v];
                lazyAdd[2 * v + 1] += lazyAdd[v];
            }
            lazyAdd[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T delta) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazyAdd[v] += delta;
            push(v, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        push(2 * v, tl, mid);
        push(2 * v + 1, mid + 1, tr);
        update(2 * v, tl, mid, l, min(r, mid), delta);
        update(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, delta);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }

    void assign(int v, int tl, int tr, int l, int r, T val) {
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
        assign(2 * v, tl, mid, l, min(r, mid), val);
        assign(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, val);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
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

        return combine(left, right);
    }

    // Public interface (all 1-indexed)
    void update(int l, int r, T delta) { update(1, 1, n, l, r, delta); }

    void assign(int l, int r, T val) { assign(1, 1, n, l, r, val); }

    T query(int l, int r) { return query(1, 1, n, l, r); }
};
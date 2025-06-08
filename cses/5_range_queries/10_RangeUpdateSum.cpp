#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T = int>
struct SegmentTreeLazy {
    int n;
    vector<T> t;
    // lazy tags: range addition and range assignment
    vector<T> lazyAdd, lazySet;
    vector<bool> hasSet;

    // If using sum: default t elements = 0, invalid query = 0
    // If switching to min: initialize t to INF, invalid query returns INF
    const T INIT_VAL = 0;     // for sum
    const T INVALID_VAL = 0;  // for sum
    // const T INIT_VAL = numeric_limits<T>::max();   // for min
    // const T INVALID_VAL = numeric_limits<T>::max();// for min

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
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, v * 2, tl, mid);
            build(a, v * 2 + 1, mid + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    // combine for sum (default) or min (if changed)
    T combine(T v1, T v2) const {
        // For sum:
        return v1 + v2;
        // For min:
        // return min(v1, v2);
    }

    void push(int v, int tl, int tr) {
        if (hasSet[v]) {
            // assignment overrides
            // For sum: multiply by segment length
            t[v] = (tr - tl + 1) * lazySet[v];
            // For min: just set t[v] = lazySet[v];
            // t[v] = lazySet[v];

            if (tl != tr) {
                // propagate set tag
                lazySet[2 * v] = lazySet[v];
                hasSet[2 * v] = true;
                lazyAdd[2 * v] = 0;
                lazySet[2 * v + 1] = lazySet[v];
                hasSet[2 * v + 1] = true;
                lazyAdd[2 * v + 1] = 0;
            }
            hasSet[v] = false;
            lazyAdd[v] = 0;
        } else if (lazyAdd[v] != 0) {
            // addition propagation
            // For sum: multiply by segment length
            t[v] += (tr - tl + 1) * lazyAdd[v];
            // For min: t[v] += lazyAdd[v];

            if (tl != tr) {
                if (!hasSet[2 * v]) lazyAdd[2 * v] += lazyAdd[v];
                else lazySet[2 * v] += lazyAdd[v];
                if (!hasSet[2 * v + 1]) lazyAdd[2 * v + 1] += lazyAdd[v];
                else lazySet[2 * v + 1] += lazyAdd[v];
            }
            lazyAdd[v] = 0;
        }
    }

    void updateAdd(int v, int tl, int tr, int l, int r, T val) {
        push(v, tl, tr);
        if (tl > r || tr < l) return;
        if (l <= tl && tr <= r) {
            lazyAdd[v] += val;
            push(v, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        updateAdd(2 * v, tl, mid, l, r, val);
        updateAdd(2 * v + 1, mid + 1, tr, l, r, val);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }

    void updateSet(int v, int tl, int tr, int l, int r, T val) {
        push(v, tl, tr);
        if (tl > r || tr < l) return;
        if (l <= tl && tr <= r) {
            hasSet[v] = true;
            lazySet[v] = val;
            lazyAdd[v] = 0;
            push(v, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        updateSet(2 * v, tl, mid, l, r, val);
        updateSet(2 * v + 1, mid + 1, tr, l, r, val);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }

    T query(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tl > r || tr < l) return INVALID_VAL;
        if (l <= tl && tr <= r) return t[v];
        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    T query(int l, int r) { return query(1, 1, n, l, r); }
    void updateAdd(int l, int r, T val) { updateAdd(1, 1, n, l, r, val); }
    void updateSet(int l, int r, T val) { updateSet(1, 1, n, l, r, val); }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    SegmentTreeLazy<int> st(a, n);
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            int x;
            cin >> a >> b >> x;
            st.updateAdd(a, b, x);
        } else if (type == 2) {
            int a, b;
            int x;
            cin >> a >> b >> x;
            st.updateSet(a, b, x);
        } else if (type == 3) {
            int a, b;
            cin >> a >> b;
            cout << st.query(a, b) << '\n';
        }
    }
    return 0;
}
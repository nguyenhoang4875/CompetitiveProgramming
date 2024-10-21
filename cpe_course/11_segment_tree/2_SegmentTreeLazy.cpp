#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Segment Tree Lazy Propagation: range updates
 *  1. To clear a lazy value
 *  2. To update the segment tree value
 *
 * Update TC: O(log n)
 * Query TC: O(log n)
 *
 */

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;

struct SegmentTreeLazy {
    int n;
    vector<int> t, lazy;

    SegmentTreeLazy(int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    int combine(int v1, int v2) { return (v1 + v2); }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        // not overlapping case
        if (tl > r || tr < l) return 0;

        // lazy propagation / clear the lazy update
        if (lazy[v] != 0) {
            // pending updates
            // update segment tree node
            t[v] = (t[v] + lazy[v] * (tr - tl + 1));

            if (tl != tr) {
                // propagate the updated value
                lazy[2 * v] = (lazy[2 * v] + lazy[v]);
                lazy[2 * v + 1] = (lazy[2 * v + 1] + lazy[v]);
            }
            lazy[v] = 0;
        }

        if (l <= tl and tr <= r) return t[v];

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        if (lazy[v] != 0) {
            t[v] = (t[v] + lazy[v] * (tr - tl + 1));
            if (tl != tr) {
                lazy[2 * v] = (lazy[2 * v] + lazy[v]);
                lazy[2 * v + 1] = (lazy[2 * v + 1] + lazy[v]);
            }
            lazy[v] = 0;
        }

        // no overlapping
        if (tl > r || tr < l) return;

        // complete overlapping case
        if (l <= tl and tr <= r) {
            t[v] = (t[v] + val * (tr - tl + 1));
            if (tl != tr) {
                lazy[2 * v] = (lazy[2 * v] + val);
                lazy[2 * v + 1] = (lazy[2 * v + 1] + val);
            }
            return;
        }

        // partial case
        int mid = (tl + tr) / 2;
        update(2 * v, tl, mid, l, r, val);
        update(2 * v + 1, mid + 1, tr, l, r, val);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }

    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
};

const int ms = 1e5 + 5;
int a[ms], bruteA[ms];

random_device rd;
mt19937 gen(rd());
int random(int l, int r) {
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

int bruteQuery(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum = (sum + bruteA[i]);
    }
    return sum;
}

void bruteUpdate(int l, int r, int val) {
    for (int i = l; i <= r; i++) {
        bruteA[i] = (bruteA[i] + val);
    }
}

void solve() {
    int n = 1e5;
    for (int i = 1; i < n; i++) {
        a[i] = random(-1e9, 1e9);
        bruteA[i] = a[i];
    }

    SegmentTreeLazy st(n);
    st.build(a, 1, 1, n);

    int q = 10000;
    while (q--) {
        int type = random(1, 2);
        int l = random(1, n);
        int r = random(1, n);
        if (l > r) swap(l, r);

        if (type == 1) {
            // update
            int val = random(-1e9, 1e9);
            st.update(l, r, val);
            bruteUpdate(l, r, val);
        } else {
            int sum1 = st.query(l, r);
            int sum2 = bruteQuery(l, r);
            assert(sum1 == sum2);
        }
    }
    cout << "Stress Test Passed" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
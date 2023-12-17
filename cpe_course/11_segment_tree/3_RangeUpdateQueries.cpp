#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];

struct SegmentTreeLazy {
    int n;
    vector<int> t, lazy;

    SegmentTreeLazy(int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    int combine(int v1, int v2) { return v1 + v2; }

    int query(int v, int tl, int tr, int l, int r) {
        // not overlapping case
        if (tl > r || tr < l) return 0;

        // lazy propagation / clear the lazy update
        if (lazy[v] != 0) {
            // pending updates
            // update segment tree node
            t[v] += lazy[v] * (tr - tl + 1);

            if (tl != tr) {
                // propagate the updated value
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }

        if (l <= tl and tr <= r) return t[v];

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r),
                       query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        // not overlapping case
        if (tl > r || tr < l) return;

        if (lazy[v] != 0) {
            t[v] += lazy[v] * (tr - tl + 1);
            if (tl != tr) {
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }

        // overlapping case
        if (l <= tl and tr <= r) {
            t[v] += val * (tr - tl + 1);
            if (tl != tr) {
                lazy[2 * v] += val;
                lazy[2 * v + 1] += val;
            }
            return;
        }

        int mid = (tl + tr) / 2;
        update(2 * v, tl, mid, l, r, val);
        update(2 * v + 1, mid + 1, tr, l, r, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    For(i, 1, n) cin >> a[i];
    SegmentTreeLazy sgt(n);
    sgt.build(a, 1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            sgt.update(a, b, u);
        } else {
            int k;
            cin >> k;
            cout << sgt.query(k, k) << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
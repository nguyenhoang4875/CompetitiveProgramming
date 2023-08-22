#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://oj.vnoi.info/problem/segtree_itez2
 * Solution: Using Segment Tree Sum Range Query
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

struct SegmentTree {
    int n;
    vector<int> t;
    SegmentTree(){};
    SegmentTree(int a[], int _n) : t(4 * n), n(_n) { build(a, 1, 0, n - 1); };

    // Build segment tree
    // In the main program this function will be called with the parameters of
    // the root vertex:   v = 1, tl = 0 and   tr = n - 1 (base-index 1: tl = 1,
    // tr = n)
    void build(int a[], int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    // sum queries,
    // which receives as parameters information about the current vertex/segment
    // (the index  v  and the boundaries  tl  and  tr ) and
    // the information about the boundaries of the query,  l  and r 
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];

        int tm = (tl + tr) / 2;
        return sum(2 * v, tl, tm, l, min(r, tm)) +
               sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    // update a[pos] = newValue and also update the value of t array
    void update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr)
            t[v] = newVal;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * v, tl, tm, pos, newVal);
            else
                update(2 * v + 1, tm + 1, tr, pos, newVal);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    // overloading
    int sum(int l, int r) { return sum(1, 0, n - 1, l, r); }

    void update(int pos, int newVal) {
        return update(1, 0, n - 1, pos, newVal);
    }
};

const int MS = 1e5 + 5;
int n, q;
int a[MS];

void solve() {
    cin >> n >> q;
    SegmentTree sgt(a, n);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            sgt.update(l - 1, r);
        } else {
            cout << sgt.sum(l - 1, r - 1) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
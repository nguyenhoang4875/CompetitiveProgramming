#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Segment tree: https://cp-algorithms.com/data_structures/segment_tree.html
 * Segment tree is a data structure used to effectively query and update ranges
 * of array members.
 * It's typically implemented One important property of Segment Trees is that
 * they require only a linear amount of memory. The standard Segment Tree
 * requires  4n  vertices for working on an array of size  n .
 */

// SegmentTree Sum range query:
struct SegmentTree {
    int n;
    vector<int> t;
    SegmentTree(){};
    SegmentTree(int a[], int _n) : t(4 * n), n(_n) { build(a, 1, 0, n - 1); };

    // Build segment tree
    // In the main program this function will be called with the parameters of
    // the root vertex:   v = 1, tl = 0 and   tr = n - 1
    // (base-index 1: tl = 1, tr = n)
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
    // parameters information about the current vertex/segment
    // (the index  v  and the boundaries  tl  and  tr ) and
    // the boundaries of the query,  l  and r 
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

// SegmentTree max range query:
struct SegmentTreeMax {
    int n;
    vector<int> t;
    SegmentTreeMax(){};
    SegmentTreeMax(int a[], int _n) : t(4 * n), n(_n) {
        build(a, 1, 0, n - 1);
    };

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }

    int getMax(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;  // if array a contain negative integer: return -oo;
        if (l == tl && r == tr) return t[v];

        int tm = (tl + tr) / 2;
        return max(getMax(2 * v, tl, tm, l, min(r, tm)),
                   getMax(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
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
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }

    // overloading
    int getMax(int l, int r) { return getMax(1, 0, n - 1, l, r); }

    void update(int pos, int newVal) {
        return update(1, 0, n - 1, pos, newVal);
    }
};

void printVector(vector<int> t) {
    for (auto e : t) cout << e << ' ';
    cout << '\n';
}

int32_t main() {
    cout << "Segment Tree Test\n";
    int n = 5;
    int a[5] = {1, 3, -2, 8, -7};
    SegmentTree sgt(a, n);
    printVector(sgt.t);
    // sum from index: 1 -> 3 of array a
    int s = sgt.sum(1, 3);
    cout << "s = " << s << endl;  // s = 9 ( 3 - 2 + 8)

    // update a[2] = 3;
    a[2] = 3;
    sgt.update(2, 3);
    printVector(sgt.t);

    int b[5] = {1, 5, 3, 6, 4};
    cout << "\nSegment Tree Max Test \n";
    SegmentTreeMax sgm(b, 5);
    printVector(sgm.t);
    // get max index 0 -> 2 // 5
    cout << sgm.getMax(2, 4) << '\n';
    sgm.update(3, 9);
    cout << sgm.getMax(2, 4) << '\n';
    return 0;
}
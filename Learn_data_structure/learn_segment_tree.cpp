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
 *
 * - Must use based-index 1 for all array or vector
 */

// SegmentTree Sum range query:
struct SegmentTree {
    int n;
    vector<int> t;
    SegmentTree(){};
    SegmentTree(int a[], int _n) : t(4 * n), n(_n) { build(a, 1, 1, n); };

    // Build segment tree
    // In the main program this function will be called with the parameters of
    // the root vertex:   v = 1, tl = 1 and   tr = n
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
    int sum(int l, int r) { return sum(1, 1, n, l, r); }

    void update(int pos, int newVal) { return update(1, 1, n, pos, newVal); }
};

// Finding the maximum (similar for minimum)
struct SegmentTreeMax {
    int n;
    vector<int> t;
    SegmentTreeMax(){};
    SegmentTreeMax(int a[], int _n) : t(4 * n), n(_n) { build(a, 1, 1, n); };

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

    void update(int pos, int newVal) { return update(1, 1, n, pos, newVal); }
};

// Finding the maximum and the number of times it appears
struct SegmentTreeMaxAndTime {
    const int oo = 1e9;
    int n;
    vector<pair<int, int>> t;
    SegmentTreeMaxAndTime(){};
    SegmentTreeMaxAndTime(int a[], int _n) : t(4 * n), n(_n) {
        build(a, 1, 1, n);
    };

    pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) return a;
        if (b.first > a.first) return b;
        return {a.first, a.second + b.second};
    }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr)
            t[v] = {a[tl], 1};
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    pair<int, int> getMax(int v, int tl, int tr, int l, int r) {
        if (l > r) return {-oo, 0};
        if (l == tl && r == tr) return t[v];

        int tm = (tl + tr) / 2;
        return combine(getMax(2 * v, tl, tm, l, min(r, tm)),
                       getMax(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    // update a[pos] = newValue and also update the value of t array
    void update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr)
            t[v] = {newVal, 1};
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * v, tl, tm, pos, newVal);
            else
                update(2 * v + 1, tm + 1, tr, pos, newVal);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    // overloading
    pair<int, int> getMax(int l, int r) { return getMax(1, 1, n, l, r); }

    void update(int pos, int newVal) { return update(1, 1, n, pos, newVal); }
};

// Compute the greatest common divisor / least common multiple
struct SegmentTreeGcd {
    int n;
    vector<int> t;
    SegmentTreeGcd(){};
    SegmentTreeGcd(int a[], int _n) : t(4 * n), n(_n) { build(a, 1, 1, n); };

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = __gcd(t[2 * v], t[2 * v + 1]);
        }
    }

    int getGcd(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;  // if array a contain negative integer: return -oo;
        if (l == tl && r == tr) return t[v];

        int tm = (tl + tr) / 2;
        return __gcd(getGcd(2 * v, tl, tm, l, min(r, tm)),
                     getGcd(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
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
            t[v] = __gcd(t[2 * v], t[2 * v + 1]);
        }
    }

    // overloading
    int getGcd(int l, int r) { return getGcd(1, 1, n, l, r); }

    void update(int pos, int newVal) { return update(1, 1, n, pos, newVal); }

    // to calculate least common multiple
    int lcm(int a, int b) { return a / __gcd(a, b) * b; }
};

// Counting the number of zeros, searching for the  k -th zero
struct SegmentTreeCountSearch {
    int n;
    vector<int> t;
    int val;  // value to count and searching for the k-th times
    SegmentTreeCountSearch(){};
    SegmentTreeCountSearch(int a[], int _n, int _val)
        : t(4 * n), n(_n), val(_val) {
        build(a, 1, 1, n);
    };

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl] == val;
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    int count(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];

        int tm = (tl + tr) / 2;
        return count(2 * v, tl, tm, l, min(r, tm)) +
               count(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    int findKth(int v, int tl, int tr, int k) {
        if (k > t[v]) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if (t[2 * v] >= k) {
            return findKth(2 * v, tl, tm, k);
        } else {
            return findKth(2 * v + 1, tm + 1, tr, k - t[2 * v]);
        }
    }

    // update a[pos] = newValue and also update the value of t array
    void update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr)
            t[v] = newVal == val;
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
    int count(int l, int r) { return count(1, 1, n, l, r); }
    int findKth(int k) { return findKth(1, 1, n, k); }

    void update(int pos, int newVal) { return update(1, 1, n, pos, newVal); }
};

void printVector(vector<int> t) {
    for (auto e : t) cout << e << ' ';
    cout << '\n';
}

int32_t main() {
    cout << "Segment Tree Test\n";
    int n = 5;
    int a[6] = {0, 1, 3, -2, 8, -7};
    SegmentTree sgt(a, n);
    printVector(sgt.t);
    // sum from index: 1 -> 3 of array a
    int s = sgt.sum(1, 3);
    cout << "sum range: [1, 3] = " << s << endl;  // s = 2 (1 + 3 - 2)

    // update a[2] = 3;
    cout << "update a[2] = 3\n";
    a[2] = 3;
    sgt.update(3, 3);
    printVector(sgt.t);

    cout << "\nSegment Tree Max Test \n";
    int b[6] = {0, 1, 5, 3, 6, 4};
    SegmentTreeMax sgm(b, 5);
    printVector(sgm.t);
    cout << "get max range: [2, 4] = " << sgm.getMax(2, 4) << '\n';  // 6
    cout << "update a[3] = 9\n";
    sgm.update(3, 9);
    cout << "get max range: [2, 4] = " << sgm.getMax(2, 4) << '\n';  // 9

    cout << "\nSegment Tree Max and Time Test \n";
    int c[6] = {0, 1, 5, 3, 5, 4};
    SegmentTreeMaxAndTime stmt(c, 5);
    pair<int, int> p = stmt.getMax(1, 5);
    cout << "max and time in range: [1, 5] max = " << p.first
         << " time = " << p.second << '\n';  // 5 2

    // update c[3] = 9;
    cout << "update a[3] = 9\n";
    stmt.update(3, 9);
    p = stmt.getMax(1, 5);
    cout << "max and time in range: [1, 5] max = " << p.first
         << " time = " << p.second << '\n';  // 9 1

    cout << "\nSegment Tree Gcd Test \n";
    int d[7] = {0, 1, 2, 4, 8, 3, 9};
    SegmentTreeGcd stGcd(d, 6);
    printVector(stGcd.t);
    cout << "get gcd range: [2, 4] = " << stGcd.getGcd(2, 4) << '\n';  // 2
    cout << "update a[2] = 4\n";
    stGcd.update(2, 4);
    cout << "get gcd range: [2, 4] = " << stGcd.getGcd(2, 4) << '\n';  // 4

    cout << "\nSegment Tree Count Search value Test \n";
    int e[7] = {0, 1, 0, 1, 0, 0, 9};
    int val = 0;  // count and search 0
    SegmentTreeCountSearch stCs(e, 6, val);
    printVector(stCs.t);
    cout << "count of 0 range: [2, 5] = " << stCs.count(2, 5) << '\n';  // 3
    cout << "searching for 2-th = " << stCs.findKth(2) << '\n';         // 4
    cout << "update a[3] = 0\n";
    stCs.update(3, 0);
    cout << "count of 0 range: [2, 5] = " << stCs.count(2, 5) << '\n';  // 4

    return 0;
}
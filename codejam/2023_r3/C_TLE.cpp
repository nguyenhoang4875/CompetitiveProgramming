#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/contest/problem/1113/3
 * Solution: TLE
 *  - Segment Tree
 *  - Binary search
 *  - Math in base
 */

struct SegmentTree {
    int n;
    vector<int> t;
    vector<int> cnt;
    SegmentTree(){};
    SegmentTree(int _n) : t(4 * _n), cnt(4 * _n), n(_n){};

    void update(int v, int tl, int tr, int newVal) {
        // cout << "update" << endl;
        if (newVal < tl || newVal > tr) return;
        if (tl == tr) {
            t[v] += newVal;
            cnt[v]++;
            return;
        }

        int mid = (tl + tr) / 2;
        update(2 * v, tl, mid, newVal);
        update(2 * v + 1, mid + 1, tr, newVal);
        t[v] = t[2 * v] + t[2 * v + 1];
        cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
    }
    int getSum(int v, int tl, int tr, int l, int r) {
        if (tr < l || tl > r) return 0;

        if (tl >= l && tr <= r) {
            return t[v];
        }
        int mid = (tl + tr) / 2;
        return getSum(2 * v, tl, mid, l, r) +
               getSum(2 * v + 1, mid + 1, tr, l, r);
    }
    int getCnt(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0;
        if (tl >= l && tr <= r) {
            return cnt[v];
        }

        int mid = (tl + tr) / 2;
        return getCnt(2 * v, tl, mid, l, r) +
               getCnt(2 * v + 1, mid + 1, tr, l, r);
    }

    // overloading
    void update(int newVal) { update(1, 0, n - 1, newVal); }
    int getSum(int l, int r) { return getSum(1, 0, n - 1, l, r); }

    int getCnt(int l, int r) { return getCnt(1, 0, n - 1, l, r); }
};

int const MS = 5e5 + 5;
int n, m;
int v[MS];
int q[MS];
int w[MS];

// find x in original array:
int binGetCountMin(SegmentTree& st, int k) {
    int val = -1;
    int l = 0, r = 1e6 + 2;
    while (l <= r) {
        int mid = (l + r) / 2;
        // cout << mid << " " << st.getCnt(0, mid) << endl;
        if (st.getCnt(0, mid) >= k) {
            val = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return val;
}

int binGetCountMax(SegmentTree& st, int k) {
    int val = -1;
    int l = 0, r = 1e6 + 2;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (st.getCnt(mid, 1e6 + 2) >= k) {
            val = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return val;
}
void solve() {
    // cin
    cin >> n >> m;
    SegmentTree st(1e6 + 3);
    int base = 5e5 + 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st.update(v[i] + base);
    }
    for (int i = 0; i < m; i++) {
        cin >> q[i] >> w[i];
    }

    /*
     Q1: Add wi and array v
     Q2: Update all values in v by adding wi
     Q3: Sum wi largest numbers among v
     Q4: Sum wi smallest numbers among v
     */

    vector<int> va;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (q[i] == 1) {
            st.update(w[i] + base);
        } else if (q[i] == 2) {
            base -= w[i];
        } else if (q[i] == 3) {
            int ai = 0;
            int val = binGetCountMax(st, w[i]);
            ai = st.getSum(val, 1e6 + 2);
            int k = st.getCnt(val, 1e6 + 2);
            if (k > w[i]) ai -= (k - w[i]) * val;
            // cout << base << " " << w[i] << " " << ai << endl;
            ai -= w[i] * base;
            cout << ai << " ";
            // va.pb(ai);
        } else {  // q[i] = 4
            int ai = 0;
            int val = binGetCountMin(st, w[i]);
            ai = st.getSum(0, val);
            int k = st.getCnt(0, val);
            if (k > w[i]) ai -= val * (k - w[i]);
            ai -= w[i] * base;
            // va.pb(ai);
            cout << ai << " ";
        }
    }
    // for (auto e : va) cout << e << " ";
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

struct SegmentTree {
    vector<int> st;
    int n;

    void init(int _n) {
        n = _n;
        st.clear();
        st.resize(4 * n);
    }

    void build(int l, int r, int node, int a[]) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2 + 1, a);
        build(mid + 1, r, node * 2 + 2, a);
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

    void update(int l, int r, int inDup, int val, int node) {
        if (l == r) {
            st[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (inDup >= l && inDup <= mid) {
            update(l, mid, inDup, val, node * 2 + 1);
        } else {
            update(mid + 1, r, inDup, val, node * 2 + 2);
        }
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }
    int query(int si, int se, int l, int r, int node) {
        if (se < l || si > r || l > r) {
            return INT_MAX;
        }
        if (si >= l && se <= r) return st[node];

        int mid = (si + se) / 2;
        int q1 = query(si, mid, l, r, node * 2 + 1);
        int q2 = query(mid + 1, se, l, r, node * 2 + 2);
        return min(q1, q2);
    }

    // override
    void build(int n, int a[]) {
        init(n);
        build(0, n - 1, 0, a);
    }
    int query(int l, int r) { return query(0, n - 1, l, r, 0); }
    void update(int index, int val) { update(0, n - 1, index, val, 0); }
};

const int oo = 1e18, mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n], b[n], dp[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = INT_MAX;
    }
    SegmentTree sgt;
    sgt.build(n, b);

    for (int i = 0; i < k; i++) {
        dp[i] = a[i];
        sgt.update(i, dp[i]);
    }

    for (int i = k; i < n; i++) {
        int mn = sgt.query(i - k, i - 1);
        dp[i] = mn + a[i];
        sgt.update(i, dp[i]);
    }

    cout << sgt.query(n - k, n - 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Monotonic stack + Segment Tree
 */

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

template <typename T = int>
struct SegmentTree {
    int n;
    vector<T> vmn, vmx;
    SegmentTree(int _n) {
        n = _n;
        vmn.resize(4 * n);
        vmx.resize(4 * n);
    };
    SegmentTree(vector<T> a, int _n) {
        n = _n;
        vmn.resize(4 * n);
        vmx.resize(4 * n);
        build(a, 1, 1, n);
    };

    void build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) vmn[v] = vmx[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            vmn[v] = combine_min(vmn[2 * v], vmn[2 * v + 1]);
            vmx[v] = combine_max(vmx[2 * v], vmx[2 * v + 1]);
        }
    }

    // !!! Important update combine and base case for INVALID
    T combine_min(T v1, T v2) { return min(v1, v2); }
    T combine_max(T v1, T v2) { return max(v1, v2); }

    T query_min(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return oo;  // INVALID
        if (l <= tl && tr <= r) return vmn[v];

        int tm = (tl + tr) / 2;
        return combine_min(query_min(2 * v, tl, tm, l, r), query_min(2 * v + 1, tm + 1, tr, l, r));
    }
    T query_max(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return -oo;  // INVALID
        if (l <= tl && tr <= r) return vmx[v];

        int tm = (tl + tr) / 2;
        return combine_max(query_max(2 * v, tl, tm, l, r), query_max(2 * v + 1, tm + 1, tr, l, r));
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    vi l(n + 1), r(n + 1);

    vector<int> st;
    For(i, 1, n) {
        while (st.size() and a[st.back()] <= a[i]) st.pop_back();

        if (st.size()) l[i] = st.back() + 1;
        else l[i] = 1;

        st.push_back(i);
    }

    st.clear();
    Rof(i, n, 1) {
        while (st.size() and a[st.back()] < a[i]) st.pop_back();

        if (st.size()) r[i] = st.back() - 1;
        else r[i] = n;

        st.push_back(i);
    }

    int m = n + 1;
    vi pre(m + 1);
    For(i, 1, n) pre[i + 1] = pre[i] + a[i];

    SegmentTree<int> sgt(pre, m);

    int ans = -oo;

    For(i, 1, n) {
        int v1 = sgt.query_max(1, 1, m, i + 1, r[i] + 1);
        int v2 = sgt.query_min(1, 1, m, l[i], i);
        ans = max(ans, v1 - v2 - a[i]);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}
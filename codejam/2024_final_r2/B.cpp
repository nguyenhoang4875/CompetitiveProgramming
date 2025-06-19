#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
template <typename T = int>
struct SegmentTreeLazy {
    int n;
    vector<T> t, lazy;

    SegmentTreeLazy(int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    SegmentTreeLazy(const vector<T>& a, int _n) {
        n = _n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(a, 1, 1, n);
    }

    void build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }    }

    // !!! Important update base case for INVALID and push function
    T combine(T v1, T v2) { return v1 + v2; }

    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;

        // Apply lazy to current node
        t[v] += lazy[v] * (tr - tl + 1);  // For min or max:  t[v] += lazy[v];

        // Propagate to children
        if (tl != tr) {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }

        // Clear lazy
        lazy[v] = 0;
    }

    T query(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);

        if (tl > r || tr < l) return 0;        // No overlap INVALID: for min = oo, max = -oo
        if (l <= tl and tr <= r) return t[v];  // Complete overlap

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int l, int r, T val) {
        // No overlap
        if (tl > r || tr < l) return;

        // Complete overlap - ONLY update lazy
        if (l <= tl and tr <= r) {
            lazy[v] += val;
            push(v, tl, tr);  // Apply immediately
            return;
        }

        // Partial overlap - push first
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        update(2 * v, tl, mid, l, r, val);
        update(2 * v + 1, mid + 1, tr, l, r, val);

        // Update current node from children (must push children first)
        push(2 * v, tl, mid);
        push(2 * v + 1, mid + 1, tr);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }

    T query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int l, int r, T val) { update(1, 1, n, l, r, val); }
};


const int ms = 250005, ms2 = ms;
int n, m;
int SS[ms2], X[ms2], Y[ms2];

int modN(int x) {
    x--;
    x = (x % n + n) % n;
    x++;
    return x;
}

void solve() {
    cin >> n >> m;
    vi v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) cin >> SS[i];
    for (int i = 1; i <= m; i++) cin >> X[i];
    for (int i = 1; i <= m; i++) cin >> Y[i];

    SegmentTreeLazy st(n);
    st.build(v, 1, 1, n);

    int l2r = 1;
    int root = 1;
    for (int i = 1; i <= m; i++) {
        int s = SS[i], x = X[i], y = Y[i];

        switch (s) {
            case 1:
                root += l2r * x;
                root = modN(root);
                break;
            case 2:
                root -= l2r * x;
                root = modN(root);
                break;
            case 3:
                l2r *= -1;
                break;
            case 4:
                x--;
                if (l2r == 1) {
                    int next = root + x;
                    if (next <= n) {
                        st.update(root, next, y);
                    } else {
                        st.update(root, n, y);
                        st.update(1, modN(next), y);
                    }
                } else {
                    int next = root - x;
                    if (next >= 1) {
                        st.update(next, root, y);
                    } else {
                        st.update(1, root, y);
                        st.update(modN(next), n, y);
                    }
                }
                break;
            case 5:
                x--;
                int ret = 0;
                if (l2r == 1) {
                    int next = root + x;
                    if (next <= n) {
                        ret += st.query(root, next);
                        ret %= mod;
                    } else {
                        ret += st.query(root, n);
                        ret %= mod;
                        ret += st.query(1, modN(next));
                        ret %= mod;
                    }
                } else {
                    int next = root - x;
                    if (next >= 1) {
                        ret += st.query(next, root);
                        ret %= mod;
                    } else {
                        ret += st.query(1, root);
                        ret %= mod;
                        ret += st.query(modN(next), n);
                        ret %= mod;
                    }
                }
                cout << ret % mod << " ";
                break;
        }
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
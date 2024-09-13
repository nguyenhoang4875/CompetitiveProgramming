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
const int ms = 2e5 + 5;
int n, m, k, d;

struct SegmentTree {
    int n;
    vector<int> t;

    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n, 0);
    }

    int combine(int v1, int v2) { return min(v1, v2); }

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
        if (tl > r || tr < l) return oo;
        if (l <= tl and tr <= r) return t[v];

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] += val;
        } else {
            int mid = (tl + tr) / 2;
            if (pos <= mid)
                update(2 * v, tl, mid, pos, val);
            else
                update(2 * v + 1, mid + 1, tr, pos, val);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }
    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, int val) { update(1, 1, n, pos, val); }
    void set(int pos, int val) { update(pos, val - query(pos, pos)); }
};

void solve() {
    cin >> n >> m >> k >> d;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // f[i][j] is minimum cost to build a bridges on row i and end at j
    vi ret(n);
    for (int i = 0; i < n; i++) {
        SegmentTree sgt(m);
        sgt.update(1, 1);
        int l, r;
        for (int j = 1; j < m - 1; j++) {
            int t = j + 1;
            l = max(1LL, t - d - 1);
            r = max(1LL, t - 1);
            sgt.update(t, sgt.query(l, r) + a[i][j] + 1);
        }
        l = max(1LL, m - d - 1);
        r = max(1LL, m - 1);
        ret[i] = 1 + sgt.query(l, r);
    }

    // two pointers for k consecutive bridges
    int ans = oo;
    int l = 0;
    int sum = 0;
    for (int r = 0; r < n; r++) {
        sum += ret[r];
        if (r - l + 1 == k) {
            ans = min(ans, sum);
            sum -= ret[l];
            l++;
        }
    }
    cout << ans << el;
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
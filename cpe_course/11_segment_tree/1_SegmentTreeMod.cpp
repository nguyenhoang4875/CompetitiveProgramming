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
const int ms = 1e5 + 5;

struct SegmentTree {
    int n;
    vector<int> t;

    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n, 0);
    }

    // IMPORTANT:update combine MUST update base case of OUT RANGE (*) (l, r) in query function
    int combine(int v1, int v2) { return (v1 + v2) % mod; }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl] % mod;
        } else {
            int mid = (tl + tr) / 2;
            build(a, 2 * v, tl, mid);
            build(a, 2 * v + 1, mid + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0;  // base case OUT RANGE (*)
        if (l <= tl and tr <= r) return t[v];

        int mid = (tl + tr) / 2;
        return combine(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = (t[v] + val) % mod;
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
    void set(int pos, int val) { update(pos, (val - query(pos, pos) + mod) % mod); }
};

void solve() {
    int n = 8;
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree sgt(n);

    sgt.build(a, 1, 1, n);
    cout << sgt.query(1, 3) << el;
    sgt.update(1, 100);
    cout << sgt.query(1, 3) << el;
    sgt.set(1, 100);
    cout << sgt.query(1, 3) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
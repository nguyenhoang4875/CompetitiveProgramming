#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n, q;
vi tree;

int query(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) return tree[v];
    if (l > tr || r < tl) return 2e9;

    int mid = (tl + tr) / 2;
    return min(query(2 * v, tl, mid, l, r),
               query(2 * v + 1, mid + 1, tr, l, r));
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
    } else {
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update(2 * v, tl, mid, pos, val);
        } else {
            update(2 * v + 1, mid + 1, tr, pos, val);
        }
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}

void update(int i, int v, int n) {
    tree[n + i] = v;
    for (int j = (n + i) / 2; j >= 1; j /= 2) {
        tree[j] = min(tree[2 * j], tree[2 * j + 1]);
    }
}

void solve() {
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    n = 1 << ((int)ceil(log2(n)));
    a.resize(n);

    tree.resize(2 * n);
    // build segment tree
    for (int i = 0; i < n; i++) {
        tree[n + i] = a[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    int type, l, r;
    while (q--) {
        cin >> type >> l >> r;
        if (type == 1) {
            l--;
            update(1, 0, n - 1, l, r);
        } else {
            l--;
            r--;
            cout << query(1, 0, n - 1, l, r) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
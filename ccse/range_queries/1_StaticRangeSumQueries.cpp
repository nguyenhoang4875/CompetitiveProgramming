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
    if(l <= tl && tr <= r) return tree[v];
    if(l > tr || r < tl) return 0;
 
    int mid = (tl + tr) / 2;
    return query(2 * v, tl, mid, l, r) + query(2 * v + 1, mid + 1, tr, l, r);
}
 
void solve() {
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    n = 1 << ((int) ceil(log2(n)));
    a.resize(n);
 
    tree.resize(2 * n);
    // build segment tree
    for (int i = 0; i < n; i++) {
        tree[n + i] = a[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(1, 0, n - 1, l, r) << '\n';
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();

    return 0;
}
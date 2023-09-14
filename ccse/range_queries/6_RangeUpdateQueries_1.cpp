#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> tree;
void updateBit(int index, int val) {
    while (index <= n) {
        tree[index] += val;
        index += index & (-index);
    }
}

void updateRange(int l, int r, int val) {
    updateBit(l, val);
    updateBit(r + 1, -val);
}

void initBitTree(int a[], int _n) {
    n = _n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) updateRange(i, i, a[i]);
}

int get(int index) {
    int sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    initBitTree(a, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            updateRange(l, r, u);

        } else {
            int k;
            cin >> k;
            cout << get(k) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

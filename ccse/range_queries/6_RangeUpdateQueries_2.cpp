#include <bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTreeRangeUpdatePointQuery {
    int n;
    vector<int> tree;

    FenwickTreeRangeUpdatePointQuery(int _n, int a[]) {
        n = _n;
        tree.resize(n + 1);
        for (int i = 1; i <= n; i++) updateRange(i, i, a[i]);
    }
    void updateBit(int index, int val) {
        while (index <= n) {
            tree[index] += val;
            index += index & (-index);
        }
    }

    void updateRange(int l, int r, int val) {
        // Increase value at 'l' by 'val'
        updateBit(l, val);

        // Decrease value at 'r+1' by 'val'
        updateBit(r + 1, -val);
    }

    int get(int index) {
        int sum = 0;  // Initialize result

        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    int b[n + 1];
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) cin >> a[i];

    FenwickTreeRangeUpdatePointQuery ft(n, a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            // l--;
            // r--;
            ft.updateRange(l, r, u);

        } else {
            int k;
            cin >> k;
            // k--;
            cout << ft.get(k) << '\n';
        }
    }
}

// Driver program to test above function
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

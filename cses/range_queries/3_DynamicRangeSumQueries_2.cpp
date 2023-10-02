#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://cses.fi/problemset/task/1648
 * Solution: Using Fenwick tree
*/

struct FenwickTreeRangeQueryPointUpdate {
    // must using based-one index for both: tree and val
    int n;
    vector<int> tree;

    // Create an empty FenwickTree
    FenwickTreeRangeQueryPointUpdate(int _n) : n(_n), tree(n + 1){};

    // Create an empty FenwickTree
    FenwickTreeRangeQueryPointUpdate(int _n, int a[]) {
        n = _n;
        tree.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            add(i, a[i]);
        }
    }

    // Computes the prefix sum form [1, i], O(log(n))
    int prefixSum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);  // equal: i &= ~(i & -1)  clear right most bit of i
        }
        return sum;
    }

    // Returns the sum of the interval [l, r], O(log(n))
    int sum(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }

    // Get value at index i
    int get(int i) { return sum(i, i); }

    // Add v to index i O(log(n))
    void add(int i, int v) {
        while (i <= n) {
            tree[i] += v;
            i += (i & -i);
        }
    }

    // set index i to equal to v, O(log(n))
    void set(int i, int v) {
        add(i, v - sum(i, i));  // sum(i, i) == a[i]
    }
};
int n, q;

void solve() {
    cin >> n >> q;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    FenwickTreeRangeQueryPointUpdate ft(n, a);
    
    int type, l, r;
    while (q--) {
        cin >> type >> l >> r;
        if (type == 1) {
            ft.set(l, r);
        } else {
            cout << ft.sum(l, r) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
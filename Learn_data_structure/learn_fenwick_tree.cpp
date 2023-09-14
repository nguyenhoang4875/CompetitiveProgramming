#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

/**
 * Fenwick Tree:
 * - Must using based-index 1 for all array or vector
 */

// Range queries and point updates
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
        };
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

// Range Updates and Point Query

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
    int n = 4;
    int a[5] = {0, 1, 2, 2, 4};  // base-index 1: ignore the first element

    cout << "FenwickTreeRangeQueryPointUpdate:\n";
    FenwickTreeRangeQueryPointUpdate ftRq(n, a);
    cout << ftRq.sum(1, 4) << '\n';  // 9
    ftRq.add(3, 1);                  // Add 1 to index 3;

    cout << ftRq.sum(1, 4) << '\n';  // 10
    ftRq.set(4, 0);                  // set index 4 to have value 0

    cout << ftRq.sum(1, 4) << '\n';  // 6
    cout << ftRq.get(2) << '\n';     // 2
    cout << '\n';

    int n2 = 6;
    int a2[7] = {0,  1, -2, 3,
                 -4, 5, -6};  // based-index 1: ignore first element

    cout << "FenwickTreeRangeUpdatePointQuery:\n";
    FenwickTreeRangeUpdatePointQuery ftRu(n2, a2);

    ftRu.updateRange(1, 4, 10);   // add 10 to interval [1, 4], O(log(n))
    cout << ftRu.get(1) << '\n';  // 11
    cout << ftRu.get(4) << '\n';  // 6
    cout << ftRu.get(5) << '\n';  // 5

    ftRu.updateRange(3, 6, -20);  // add -20 to interval [3, 6], O(log(n))
    cout << ftRu.get(3) << '\n';  // -7
    cout << ftRu.get(4) << '\n';  // -14
    cout << ftRu.get(5) << '\n';  // -15
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>

#include <iostream>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://cses.fi/problemset/task/1648
 * Solution: Using Fenwick tree iterator
 *          
 */

int n, q;
vector<int> tree;

void add(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += i & -i;
    }
}

int prefixSum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= i & -i;
    }
    return sum;
}

int sum(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }

int get(int i) { return sum(i, i); }

void setVal(int i, int v) { add(i, v - sum(i, i)); }

void initTree(int a[]) {
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        add(i, a[i]);
    }
}

void solve() {
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    initTree(a);

    int type, l, r;
    while (q--) {
        cin >> type >> l >> r;
        if (type == 1) {
            setVal(l, r);
        } else {
            cout << sum(l, r) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
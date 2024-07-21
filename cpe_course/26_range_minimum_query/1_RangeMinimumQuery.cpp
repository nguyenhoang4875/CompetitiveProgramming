#include <bits/stdc++.h>
/**
 * Range Minimum Query
 *
 * O(n log n) for build and O(1) for query
 *
 * Can change combine function to: min, max, gcd, or, and
 * Based-index 1
 */

using namespace std;
#define MASK(i) (1LL << (i))

const int MS = 300005, LOG = 19;
int n;
int a[MS];
int table[MS][LOG + 1];

int combine(int u, int v) { return min(u, v); }

void preCal() {
    for (int i = 1; i <= n; i++) {
        table[i][0] = a[i];
    }
    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i <= n - MASK(j) + 1; i++) {
            table[i][j] = combine(table[i][j - 1], table[i + MASK(j - 1)][j - 1]);
        }
    }
}

int getVal(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return combine(table[l][k], table[r - MASK(k) + 1][k]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    preCal();
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << getVal(l, r) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
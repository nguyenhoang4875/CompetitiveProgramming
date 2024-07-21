#include <bits/stdc++.h>
#define int long long
#define el '\n'

using namespace std;
#define MASK(i) (1LL << (i))

const int MS = 100005, LOG = 19;
int n;
int a[MS];
int table[MS][LOG + 1];

inline int combine(int u, int v) { return max(u, v); }

void preCal() {
    for (int i = 0; i < n; i++) {
        table[i][0] = a[i];
    }
    for (int j = 1; MASK(j) <= n; j++) {
        for (int i = 0; i < n - MASK(j) + 1; i++) {
            table[i][j] = combine(table[i][j - 1], table[i + MASK(j - 1)][j - 1]);
        }
    }
}

inline int getVal(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return combine(table[l][k], table[r - MASK(k) + 1][k]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    preCal();
    int q;
    cin >> q;
    int sum = 0;
    int l, r;
    cin >> l >> r;
    sum += getVal(min(l, r), max(l, r));
    q--;
    while (q--) {
        l += 7;
        while (l >= n - 1) l -= (n - 1);
        r += 11;
        while (r >= n) r -= n;
        sum += getVal(min(l, r), max(l, r));
    }
    cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

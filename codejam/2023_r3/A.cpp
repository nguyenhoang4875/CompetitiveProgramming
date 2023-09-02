#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/contest/problem/1113/1
 * Solution: Brute force
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int MS = 1e5 + 5;
int n, pa, pb;
int a[MS];

void solve() {
    cin >> n >> pa >> pb;
    if (pa > pb) swap(pa, pb);
    int cnt = 0;
    int sumA = 0, sumB = 0;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        int da = 2 * abs(pa - x);
        int db = 2 * abs(pb - x);
        if (da == db) {
            cnt++;
        } else if (da <= db) {
            sumA += da;
        } else {
            sumB += db;
        }
    }
    int d = pb - pa;
    while (cnt--) {
        if (sumA <= sumB) {
            sumA += d;
        } else {
            sumB += d;
        }
    }
    cout << (sumA + sumB) << " " << abs(sumA - sumB) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
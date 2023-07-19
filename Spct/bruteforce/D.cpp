#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1798/problem/A
 * Solution: brute force and sway a[i], b[i]
 */

int tcs, n;
int a[105], b[105];

void swap(int i) {
    int temp = a[i];
    a[i] = b[i];
    b[i] = temp;
}

bool check() {
    bool found = true;
    // if a[n] is max of a
    for (int i = 1; i < n; i++) {
        if (a[i] > a[n]) {
            swap(i);
            if (a[i] > a[n]) {
                found = false;
                break;
            }
        }
    }
    if (found) {
        for (int i = 1; i < n; i++) {
            if (b[i] > b[n]) {
                found = false;
                break;
            }
        }
    }
    return found;
}

void solve() {
    cin >> n;
    int maxA = 0, maxB = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    if (check()) {
        cout << "YES\n";
        return;
    }
    swap(n);
    if (check())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
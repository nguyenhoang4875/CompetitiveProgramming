#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/570/problem/B
 */

int n, m;

void solve() {
    cin >> n >> m;
    int a = 0;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    int mid = n / 2;
    if (n % 2 == 0) {
        if (m == mid)
            a = mid + 1;
        else if (m < mid) {
            a = m + 1;
        } else
            a = m - 1;
    } else {
        mid += 1;
        if (m == mid) {
            a = mid - 1;
        } else if (m < mid) {
            a = m + 1;
        } else
            a = m - 1;
    }
    cout << a << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
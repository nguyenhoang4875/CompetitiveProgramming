#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1415/problem/A
 * Solution: get max the distance of 4 corners
*/
int tcs;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int ans = 0;
    ans = max(ans, abs(1 - x) + abs(1 - y));
    ans = max(ans, abs(1 - x) + abs(m - y));
    ans = max(ans, abs(n - x) + abs(1 - y));
    ans = max(ans, abs(n - x) + abs(m - y));
    cout << ans << '\n';
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
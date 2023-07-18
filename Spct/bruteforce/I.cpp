#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1121/problem/B
 * Solution: brute force for each color
*/

int tcs, n, k;
set<int> si;
int a[100005];

void solve() {
    cin >> n >> k;
    si.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        si.insert(a[i]);
    }

    int ans = 1e9;
    for (int color : si) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != color) {
                cnt++;
                i += k - 1;
            }
        }
        ans = min(ans, cnt);
    }
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
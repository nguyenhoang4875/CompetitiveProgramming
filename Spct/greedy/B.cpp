#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/458493/problem/B
 */

int tcs, n;
unordered_map<int, int> m;

void solve() {
    m.clear();
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        m[x] = i;
    }

    int ans = -1;
    for (auto e1 : m) {
        for (auto e2 : m) {
            if (__gcd(e1.first, e2.first) == 1) {
                ans = max(ans, e1.second + e2.second);
            }
        }
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
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1121/problem/B
 * Solution: brute force for each sum a[i] + a[j] O(n ^ 2)
*/

int tcs, n;
set<int> si;
int a[1005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<int, int> mi;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = a[i] + a[j];
            mi[sum]++;
        }
    }

    int ans = 0;
    for (auto e : mi) {
        ans = max(ans, e.second);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
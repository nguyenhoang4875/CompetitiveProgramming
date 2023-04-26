#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/contest/1288/problem/A
*/

using namespace std;

int tcs, n, d;

void solve() {
    cin >> n >> d;
    if (n >= 1e5) {
        cout << "YES\n";
        return;
    }
    for (int x = 0; x <= n; x++)
        if (x + ((d + x) / (x + 1)) <= n) {
            cout << "YES\n";
            return;
        }
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
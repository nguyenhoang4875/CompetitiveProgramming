#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, a, b;

void solve() {
    cin >> a >> b;

    int ans = a + b;
    for (int m = 1; m < 100000; m++) {
        ans = min (ans, ((a + m - 1) / m) + ((b + m - 1) / m) + (m - 1));
    }

    cout << ans << endl;

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
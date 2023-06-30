#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x);
        y = y >> 1; // y = y/2
        x = (x * x);
    }
    return res;
}

void solve() {
    cin >> n >> k;
    k = min(k , 30LL);
    int ans = min(n + 1, power(2, k));
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
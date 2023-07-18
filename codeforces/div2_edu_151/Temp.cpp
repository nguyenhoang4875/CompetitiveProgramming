#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, x, y, a, b;

int gcd(int a, int b) {
    return b == 0 ? a: gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void solve() {
    cin >> x >> y >> a >> b;
    int m = lcm(x, y);

    int t1 = a / m;
    int t2 = b / m;
    int ans = t2 - t1;
    if(a % m == 0) ans += 1;
    cout << ans << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // cin >> tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}
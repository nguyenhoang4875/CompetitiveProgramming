#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[100005];


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        ans = __gcd(ans, abs(a[i] - a[n - i + 1]));
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
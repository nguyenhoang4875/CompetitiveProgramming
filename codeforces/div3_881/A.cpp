#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[55];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    int ans = 0;
    while(l < r) {
        ans += a[r] - a[l];
        l++, r--;
    }
    cout  << ans << endl;


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
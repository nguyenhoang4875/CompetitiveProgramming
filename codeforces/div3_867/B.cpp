#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] ;
    sort(a + 1, a + 1 + n, greater<int>());
    int ans1 = a[1] * a[2];
    int ans2 = a[n-1] * a[n];
    int ans = max(ans1, ans2);
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
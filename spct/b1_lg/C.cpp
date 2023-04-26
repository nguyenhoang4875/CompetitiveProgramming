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
    sort(a+1, a + n + 1);
    int m1 = a[n] * a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4];
    int m2 = a[1] * a[2] * a[n] * a[n - 1] * a[n - 2] ;
    int m3 = a[1] * a[2] * a[3] * a[4] * a[n] ;
    cout << max({m1, m2, m3}) << endl;
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

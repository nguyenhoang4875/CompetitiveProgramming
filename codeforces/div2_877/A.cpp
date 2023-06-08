#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[105];

void solve() {
    cin >> n;  
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(a[1] < 0)  cout << a[1] << "\n";
    else cout << a[n] << "\n";
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
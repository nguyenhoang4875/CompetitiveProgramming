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

    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            cnt++;
        } else {
            cnt = 0;
        }
        ans = max(ans, cnt);
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
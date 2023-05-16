#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];
int b[200005];
int MOD = 1e9 + 7;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ans = 1;

    int j = 1;
    for (int i = 1; i <= n; i++) {
        if(a[i] <= b[i]) {
            ans = 0;
            break;
        }
        while (j <= n && a[i] > b[j]) {
            j++;
        }
        ans *= (j - i);
        ans %= MOD;
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
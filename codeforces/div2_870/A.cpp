#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[105];

void solve() {
    cin >> n;
    int x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = -1;
    for (int i = 0; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if(a[j] > i) cnt++;
        }
        if(cnt == i) {
            ans = i;
            break;
        }
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
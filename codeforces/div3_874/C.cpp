#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(a[1] % 2 == 0) {
        for (int i = 2; i <= n; i++) {
           if(a[i] % 2 == 1)  {
                cout << "NO" << endl;
                return;
           }
        }
        cout << "YES" << endl;
    } else {
        cout << "YES" << endl;
    }


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
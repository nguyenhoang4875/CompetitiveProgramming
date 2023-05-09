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

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if(i == a[j]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO" << endl;

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
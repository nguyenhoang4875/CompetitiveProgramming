#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;
int a[1005][1005];

void solve() {
    cin >> n >> m;
    int idx = 1;
    for (int i = 1; i < n; i += 2) {
       for (int j = 1; j <= m; j++)  {
            a[idx][j] = i*m + j;
       }
       idx++;
    }
    for (int i = 0; i < n; i += 2) {
       for (int j = 1; j <= m; j++)  {
            a[idx][j] = i*m + j;
       }
       idx++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

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
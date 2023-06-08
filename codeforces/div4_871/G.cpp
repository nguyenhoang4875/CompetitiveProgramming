#include <bits/stdc++.h>
#define int long long


using namespace std;

int tcs, n;
int ans[2000005];
int cur = 1;
int a[1500][1500];

void preCalculate() {
    for (int i = 1; i < 1500; i++) {
        for (int j = i - 1; j >= 1; j--) {
            a[j][i - j] = a[j-1][i-j] + a[j][i-j-1] - a[j-1][i-j- 1] + cur * cur;
            ans[cur] = a[j][i - j];
            // cout << "cur = " << cur << " ans[cur] = " << ans[cur] << endl;;
            cur++;
        }
    }

    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 1; j <= 10 ; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

void solve() {
    cin >> n;
    cout << ans[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    preCalculate();
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
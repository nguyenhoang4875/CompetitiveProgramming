#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k;

int c2n(int n) {
    return n * (n -1) / 2;
}

void solve() {
    cin >> n >> k;
    int kk = 0;
    for (int i = 0; i <= n; i++) {
        int cnt = c2n(i) + c2n(n - i);
        if(cnt == k) {
            cout << "YES" << endl;
            for (int j = 1; j <= n; j++) {
                if(j <= i) cout << "1 ";
                else cout << "-1 ";
            }
            cout << endl;
            return;
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
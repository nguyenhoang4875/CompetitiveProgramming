#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[300005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n == 2 && a[1] > a[2]) {
        cout << "NO" << endl;
        return;
    }
    bool gr = false;
    int k = 0;
    for (int i = 2; i <= n ; i++) {
        if(a[i] != a[1]) {
            k = i;
            if(a[i] < a[1]) gr = true;
            break;
        }
        if(i == n) {
            cout << "YES" << endl;
            return;

        }
    }
    // cout << "k = " << k << endl;

    int cnt = 0;
    if(gr) {
        for (int i = k; i <= n; i++) {
            if(a[i] > a[i-1]) {
                cnt++;
            }
        }
    } else {
        for (int i = k; i <= n; i++) {
            if(a[i] < a[i-1]) {
                cnt++;
            }
        }
    }

    if(cnt <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
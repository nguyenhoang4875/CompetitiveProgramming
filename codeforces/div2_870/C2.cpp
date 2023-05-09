#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;


void solve() {
    cin >> n >> m;
    if(n == 1 || m == 1) {
        cout << "YES" << endl;
        return;
    }
    if(n % 2 == 0 || n <= m) {
        cout << "NO" << endl;
        return;
    }

    int size = min(m, (int) (1LL*sqrtl(n)));
    for (int i = 3, j ; i <= size ; i++) {
        if(n % i == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

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
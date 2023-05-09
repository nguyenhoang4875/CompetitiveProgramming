#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;

bool find(int n,int m) {
    if(n == m) return true;
    if(n % 3 != 0) return false;
    return find(n / 3, m) || find(2 *n / 3, m);
}

void solve() {
    cin >> n >> m;

    if(find(n, m)) {
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
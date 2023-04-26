#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;

void solve() {
    cin >> n >> m;
    vector<pair<int, int>> v (n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        if(x >= v[i].first) {
            x = max(x, v[i].second);
        } else break;
    }
    if(x >= m) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
   cin.tie(nullptr);

    // cin >> tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}
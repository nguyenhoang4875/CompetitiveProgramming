#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    vector<pair<int, int>> v;
    int a, b;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(a > b) cnt++;
    };
    cout << cnt << "\n";

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
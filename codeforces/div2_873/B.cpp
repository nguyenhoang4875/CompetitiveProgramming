#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    vector<int> vd;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if(x != i) {
            vd.push_back(abs(x - i));
        }
    }

    int ans = 0;
    for (int e: vd) ans = __gcd(ans, e);
    cout << ans << endl;

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
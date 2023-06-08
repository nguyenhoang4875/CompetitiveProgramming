#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, x, k;

void solve() {
    cin >> x >> k;
    if(x % k != 0) {
        cout << "1\n";
        cout << x << "\n";
    } else {
        cout << 2 << endl;
        cout << 1 <<" " << x - 1 << "\n";
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
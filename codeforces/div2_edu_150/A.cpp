#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    if(n  > 4) cout << "Alice\n";
    else cout << "Bob\n";
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
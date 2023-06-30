#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    int sum = 1;
    while(n != 1) {
        sum += n;
        n /= 2;
    }
    cout << sum << '\n';

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
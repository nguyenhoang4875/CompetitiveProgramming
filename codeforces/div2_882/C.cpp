#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[100005];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    int temp = 0;
    for(int i = 1; i <= n; i++) {
        temp ^= a[i];
        sum = max(temp, sum);
        sum = max(sum, a[i]);
    }
    cout << sum << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int mask = (1 << 8) - 1;
    // cout << mask << endl;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a, b;

void solve() {
   cin >> a >> b;
   b++;
   int ans = a * (to_string(b).size() - 1);
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
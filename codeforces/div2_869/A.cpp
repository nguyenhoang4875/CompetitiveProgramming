#include <bits/stdc++.h>
#define int long long
/**
 * https://codeforces.com/contest/1818/problem/A
*/
using namespace std;

int tcs, n, k;


void solve() {
    cin >> n >> k;
    string t[n+5];
    int ans = n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        if(t[i] != t[1]) {
            ans--;
        }
    }
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
#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/contest/1814/problem/A
 * using gcd
*/

using namespace std;

int tcs, n, k;

void solve() {
    cin >> n >> k;
    int mx = n / k;
    int x = gcd(2, k);
    if(n % x == 0) {
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
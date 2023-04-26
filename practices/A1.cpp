#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/contest/1288/problem/A
*/

using namespace std;

int tcs, n, d;

void solve() {
    cin >> n >> d;
    int x = (n - 1) / 2;
    if((n - x) * (x+1) >= d) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;

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
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1612/problem/A
 * Solution: brute force for x <= 50, y <= 50
*/

int tcs, x, y;

void solve() {
    cin >> x >> y;
    int xc = 0, yc = 0;
    for(xc = 0; xc <= 50; xc++) {
        for(yc = 0; yc <= 50; yc++) {
            int ac = abs(xc) + abs(yc);
            int bc = abs(x - xc) + abs(y - yc);
            if(ac == bc) {
                cout << xc << " " << yc << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n";
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
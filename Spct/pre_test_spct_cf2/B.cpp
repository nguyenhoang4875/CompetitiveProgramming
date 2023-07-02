#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Note: 1 + 2 + ... + n = n * (n+1) / 2
 * if(x > k*k) return 2 * k - 1;
 * 3 cases: x > half, x == half and x > half
 * for x > half: x = k * k - x => same with case 1
*/

int tcs, k, x;

void solve() {
    cin >> k >> x;
    if(x >= k * k) {
        cout << (2 * k - 1) << '\n';
        return;
    }
    int ans = 0;
    int half = k * (k + 1) / 2;

    int num;
    if(x < half) {
        num = sqrtl(2 * x);
        if(num * (num + 1) < 2 * x) num += 1;
    } else if(x == half) {
        num = k;
    } else {
        x = k * k - x;
        int m = sqrtl(2 * x);
        num = (2 * k - 1) - m;
        if(2 * x  < m * (m + 1)) num += 1; // if remain less
    }
    ans += num;
    cout << ans << '\n';
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

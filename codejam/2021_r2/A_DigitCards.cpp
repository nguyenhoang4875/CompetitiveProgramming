#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/21394
 * Solution: Greedy: sort desc num and the construct the answer
 */

//*** START CODING ***//

int tcs, n;
int a[15];
void solve() {
    n = 0;
    for (int i = 1; i <= 9; i++) {
        cin >> a[i];
        n += a[i];
    }
    a[9] += a[6];
    a[6] = 0;

    string num = "";
    int t;
    for (int i = 9; i >= 1; i--) {
        t = a[i];
        while (t--) {
            num += to_string(i);
        }
    }
    // cout << "num = " << num << endl;
    string l = "", r = "";
    for (int i = 0; i < n; i++) {
        if (i & 1)
            r += num[i];
        else
            l += num[i];
    }
    reverse(r.begin(), r.end());
    string ans = l + r;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
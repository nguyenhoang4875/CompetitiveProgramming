#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1419/A
 * Solution: Brute force
 *
 * TC: O(n)  n: number of element in array a
 * MC: O(n)
 */

int tcs, n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    int cntOdd1 = 0;
    int cntEven2 = 0;
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        // odd position
        if (i % 2 == 0 && digit % 2 == 1) cntOdd1++;
        if (i % 2 == 1 && digit % 2 == 0) cntEven2++;
    }
    int ans = 0;
    if (cntOdd1 == 0 && cntEven2 == 0) {
        if (n % 2 == 0)
            ans = 1;
        else
            ans = 2;
    } else if (cntOdd1 == 0 || cntEven2 == 0) {
        if (cntOdd1)
            ans = 1;
        else
            ans = 2;
    } else {
        if (n % 2 == 1)
            ans = 1;
        else
            ans = 2;
    }
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
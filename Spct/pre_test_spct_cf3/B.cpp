#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1538/C
 * Solution: Binary search
 *  - For each a[i]:
 *      find the pl the min index of j: a[i] + a[j] >= l (only take j > i)
 *      find the pr the max index of j: a[i] + a[j] <= r (only take j > i)
 *  - if(pr > pl) ans += pl - pr + 1;
 *
 * TC: O(n * log(n))
 * MC: O(n)
 *
 */

//*** START CODING ***//

int tcs, n, x, y;
int a[200005];

int binarySearchMin(int idx, int val) {
    int pos = -1;
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[idx] + a[mid] >= val) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return pos;
}
int binarySearchMax(int idx, int val) {
    int pos = -1;
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[idx] + a[mid] <= val) {
            pos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return pos;
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // int pl = binarySearchMin(i, x);
        // int pr = binarySearchMax(i, y);
        int pl = lower_bound(a + 1, a + n + 1, x - a[i]) - (a + 1);
        int pr = upper_bound(a + 1, a + n + 1, y - a[i]) - (a + 2);
        if (pl == -1 || pr == -1) continue;
        if (pl <= i) pl = i + 1;  // only take index greater than i
        if (pl > pr) continue;
        ans += pr - pl + 1;
    }
    cout << ans << '\n';
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
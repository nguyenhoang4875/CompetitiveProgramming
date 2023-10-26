#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
7 2
1 3 8 10 18 20 25
5
*/

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, L, k;
int a[ms];

bool check(int val) {
    int cnt = 0;
    int cover = -1;
    for (int i = 1; i <= n; i++) {
        if (cover < a[i]) {
            cnt++;
            cover = a[i] + 2 * val; // range can coverage
        }
        if (cnt > k) return false;
    }
    return true;
}

void solve() {
    cin >> n >> L >> k;
    int minA = oo;
    int maxA = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        minA = min(minA, a[i]);
        maxA = max(maxA, a[i]);
    }
    if(k >= n) {
        cout << "0\n";
        return;
    }
    sort(a + 1, a + n + 1);  // sort for binary search (if a is not sorted)

    // binary search to find min of radius
    // observe:
    /*
        if r = (min + max) / 2 =>  r is valid answer
        so if r is more large so it will be is answer.
        so for each r we have:
        F F F ... F T T T
        We need to find the minimum of v so it is answer
    */
    int ans = -1;
    int l = 1, r = (minA + maxA) / 2 + 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * max of: a1 + a2 + a3 - (r - l)
 * <=> (a1 + r) + a2 + (a3 - r) max
*/

int tcs, n;
int a[100005];
int preMax[100005]; // precalculate preMax: max of (a[i] + i) count to i
int sufMax[100005]; // precalculate subMax: max of (a[i] - i) count to i

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    preMax[1] = a[1] + 1;
    for (int i = 2; i <= n; i++) {
        preMax[i] = max(preMax[i - 1], a[i] + i);
    }

    sufMax[n] = a[n] - n;
    for (int i = n - 1; i >= 1; i--) {
        sufMax[i] = max(sufMax[i+1], a[i] - i);
    }

    int ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        ans = max(ans, preMax[i - 1] + a[i] + sufMax[i+1]);
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
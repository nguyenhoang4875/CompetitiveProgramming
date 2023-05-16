#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // unique is used to remove duplicates of any element present consecutively in a range[first, last)
    n = unique(a.begin(), a.end()) - a.begin();
    a.resize(n);
    int ans = 0;
    for (int i = 0; i < n ; i++) {
        if(i == 0 || i == n - 1 || (a[i] > a[i - 1]) == (a[i] > a[i+1])) {
            ans += 1;
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
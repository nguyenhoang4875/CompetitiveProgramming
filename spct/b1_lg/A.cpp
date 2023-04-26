#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    int remain = sum - avg * n;
    if(remain == 0) {
        cout << 0 << endl;
        return;
    }
    // choose a[i] in remain and choose a[j] in other part sum = |a[i] - a[j] = 1, otherwise sum = 0
    cout << remain * (n - remain) << endl;
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
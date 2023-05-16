#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k;
int a[200005];

void solve() {
    cin >> n  >> k;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a  + 1, a + n + 1);
    int l = 1, r = n;
    if(k == 1) {
        int twoMin = a[l] + a[l+1];
        int oneMax = a[r];
        sum -= min(twoMin, oneMax);
        cout << sum << endl;
        return;
    }
    // cout << "sum = " << sum << endl;
    while (k-- >= 2) {
        int twoMin = a[l] + a[l+1];
        int oneMax = a[r];
        if(oneMax >= twoMin) {
            r--;
            sum -= oneMax;
        } else {
            int nextL = l + 1;
            int preR = r -1;
            int t1 = twoMin + a[nextL] + a[nextL + 1];
            int t2 = oneMax + a[preR];
            if(t1 >= t2) {
                r--;
                sum -= oneMax;
            } else {
                l += 2;
                sum -= twoMin;
            }
        }
    }

    int twoMin = a[l] + a[l+1];
    int oneMax = a[r];
    sum -= min(twoMin, oneMax);
    cout << sum << endl;
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
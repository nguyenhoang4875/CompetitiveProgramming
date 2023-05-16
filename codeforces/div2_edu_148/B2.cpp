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
    // cout << "sum = " << sum << endl;

    vector<int> L(k + 5, 0);
    vector<int> R(k + 5, 0);
    L[0] = 0;
    int idl = 1;
    for (int i = 1; i <= 2*k; i+= 2) {
        L[idl] = a[i] + a[i+1];
        L[idl] += L[idl-1];
        idl++;
    }
    R[0] = 0;
    int idx = 1;
    for (int i = n; i >= n - k; i--) {
        R[idx] = a[i];
        R[idx] += R[idx -1];
        idx++;
    }

    // cout << "-------------L----------------" << endl;
    // for (int i = 1; i <= k; i++) {
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    // cout << "-------------R----------------" << endl;
    // for (int i = 1; i <= k; i++) {
    //     cout << R[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, sum - L[i] - R[k - i]);
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
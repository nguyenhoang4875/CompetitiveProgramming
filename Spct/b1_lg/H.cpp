#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k;

void solve() {
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }
    int sum = v[0];
    sort(v.begin() + 1, v.end(), greater<int>());
    for (int i = 1; i < n; i++) {
        if(i <= k) sum += v[i];
        else sum -= v[i];
    }
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> tcs;
    tcs = 1;
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}
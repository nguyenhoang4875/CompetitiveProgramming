#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> v[1005];
int a[1005];
int tcs, n;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int k = 1; k <= n; k++) {
        int i = a[k];
        int temp = a[k];
        int l = k, r = k;
        while(l >= 1 && a[l] <= temp) temp = a[l], l--;
        l++;
        temp = a[k];
        while(r <= n && a[r] <= temp) temp = a[r], r++;
        r--;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
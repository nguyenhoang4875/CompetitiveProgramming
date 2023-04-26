#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[100005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int l = i;
        int r = i+1;
        if(a[l] != a[r]) {
            int v1 = a[l];
            int v2 = a[r];
            int temp = 2;
            while (--l >= 1 && ++r <= n && a[l] == v1 && a[r] == v2)  temp += 2;
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
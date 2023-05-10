#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[100005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    int cnt = 0;
    int sum = 0;
    int free = 0;
    for (int i = 1; i <= n; i++) {
        cnt++;
        sum += a[i];
        if(cnt == 3) {
            free += a[i];
            cnt = 0;
        }
    }
    cout << (sum - free) << endl;
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
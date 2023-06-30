#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];


void solve() {
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += abs(a[i]);
    }
    int time = 0;
    for(int i = 1; i<= n; i++) {
        if(a[i] < 0) {
            while (i <= n && a[i] <= 0) {
                i++;
            }
            time++;
        }
    }
    cout << sum << ' ' << time << '\n';

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
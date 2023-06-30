#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;
int a[55];
int b[55];

void solve() {
    cin >> n >> m;
    int sumA = 0, sumB= 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sumA += a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        sumB += b[i];
    }
    if(sumA > sumB) {
        cout << "Tsondu";
    } else if(sumA == sumB) {
        cout << "Draw";
    } else {
        cout << "Tenzing";
    }
    cout << '\n';

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
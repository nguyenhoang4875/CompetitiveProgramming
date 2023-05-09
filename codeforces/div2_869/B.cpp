#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void solve() {
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    int a[n+5];
    for (int i = 1; i <= n; i++) a[i] = i;

    for (int i = 1; i <= n; i += 2) {
        swap(a[i], a[i+1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
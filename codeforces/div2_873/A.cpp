#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[205];

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = n ; i >= 2; i--) {
        a[i] = i; // => A[i] luôn chi hết cho i
        sum += a[i];
    }
    a[1] = (sum / n + 1) * n - sum; // Tìm A[1] sao cho tổng A[1] -> A[n] chi hết cho N
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
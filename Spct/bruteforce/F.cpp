#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    if(n == 3) {
        cout << "NO\n";
        return;
    }
    if(n % 2 == 1) {
        cout << "YES\n";
        int t1 = (n / 2 - 1);
        int t2 = -(n / 2);
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) cout << t1 << ' ';
            else cout << t2 << ' ';
        }
        cout << '\n';
        return;
    }
    cout << "YES\n";
    int val = 1;
    for(int i = 1; i <= n ;i++) {
        cout << val << " ";
        val *= - 1;
    }
    cout << "\n";
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
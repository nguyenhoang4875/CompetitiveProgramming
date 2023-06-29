#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

void solve() {
    int sum = 0;
    cin >> n;

    int x;
    for (int i = 1; i <= n; i++) {
       cin >> x; 
       sum ^= x;
    }
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
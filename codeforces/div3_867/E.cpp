#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;

void solve() {
    cin >> n;
    cin >> s; 
    s = " " + s;
    cout << "s = " << s << endl;
    if(n % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        int l = i;
        int r = n - i + 1;
        cout << l << " " << r << endl;
        if(s[i] == s[n - i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
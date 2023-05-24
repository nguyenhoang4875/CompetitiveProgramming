#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    string s;
    cin >> s;
    char c0 = s[0];
    
    for (char c: s) {
        if(c != c0) {
            cout << s.size() - 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
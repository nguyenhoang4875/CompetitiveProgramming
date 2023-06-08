#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    int mx = 0;
    int cnt = 1;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i+1]) {
            cnt++;
        } else {
            mx = max(mx, cnt);
            cnt = 1;
        }
    }
    mx = max(mx, cnt);
    int ans = mx + 1;

    cout << ans << endl;

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
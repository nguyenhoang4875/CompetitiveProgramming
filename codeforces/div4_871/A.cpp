#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;
string a = "codeforces";
void solve() {
    cin >> s;
    int cnt = 0;
    
    for (int i = 0; i <= 9 ; i++) {
        if(s[i] != a[i]) cnt++;
    }
    cout << cnt << endl;

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
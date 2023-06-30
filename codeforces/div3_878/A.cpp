#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    string ans = "";
    for(int i = 0; i < n; i++) {
        ans += s[i];
        i++;
        while(i < n &&  s[i] != ans[ans.size() - 1]) i++;
    }
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
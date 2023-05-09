#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    if(n % 2 == 0) {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    vector<int> ans;
    while (n > 1) {
        cnt++;
        if(((n - 1) / 2) % 2 == 1) {
            n = (n - 1) / 2;
            ans.push_back(2);
        } else {
            n = (n + 1) / 2;
            ans.push_back(1);
        }
        if(cnt > 40) {
            cout << -1 << endl;
            return;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << cnt << endl;
    for (int e : ans) cout << e << " ";
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
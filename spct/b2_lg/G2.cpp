#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    vector<int> cnt(5005, 0);
    vector<int> ans;
    int x;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= 5001; i++) {
        if(cnt[i]) {
            ans.push_back(i);
            cnt[i]--;
        }
    }
    for (int i = 5001; i >= 1; i--) {
        if(cnt[i] > 0 && ans.back() != i) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int e: ans) {
        cout << e << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
   cin.tie(nullptr);

    // cin >> tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    vector<pair<int, int>> vp(n);
        int s, e;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        vp[i] = {s, e};
    }

    // sort asc by time end
    sort(vp.begin(), vp.end(), [&] (pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    });

    int cnt = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if(x <= vp[i].first) {
            cnt++;
            x = vp[i].second;
        }
    }
    cout << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> tcs;
    tcs = 1;
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}
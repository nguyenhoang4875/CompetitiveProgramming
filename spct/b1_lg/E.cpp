#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k;

struct meeting {
    int s , e, c; // s: start, e: end, c: cost
};

void solve() {
    cin >> n;
    vector<meeting> v(n);
    for (int i = 0; i < n; i++) {
       cin >> v[i].s >> v[i].e >> v[i].c; 
    }

    // sort by end time of the meeting 
    sort(v.begin(), v.end(), [&](meeting m1, meeting m2) {
        return m1.e < m2.e;
    });

    vector<int> dp(n+1, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = v[i].c;
        for (int j = 0; j < i ; j++) {
            if(v[i].s >= v[j].e) {
                dp[i] = max(dp[i], dp[j] + v[i].c);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
   cin.tie(nullptr);

    // cin >> tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
}
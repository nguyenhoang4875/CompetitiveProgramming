#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
vector<int> sum;
unordered_map<int, int> mii;

void solve() {
    cin >> n;
    mii.clear();
    int x;
    for (int i = 1;i <= n; i++) {
        cin >> x;
        mii[x]++;
    }

    int ans = 0;
    for(auto e: mii) {
        int x = e.first;
        for (int total: sum) {
            int y = total - x;
            if(mii.count(y)) {
                ans += e.second * mii[y];
            }
        }
    }
    ans /= 2;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sum.push_back(202021);
    sum.push_back(20202021);
    for (int i = 0; i <= 9; i++) {
        int x = (20200 + i) * 10000 + 2021;
        sum.push_back(x);
    }

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs;
int n;
vector<pair<int, int>> vii;

void solve() {
    vii.clear();
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vii.push_back({x, i});
    }
    sort(vii.begin(), vii.end(), [&] (pair<int, int> p1, pair<int, int > p2) {
        return p1.first < p2.first;
    });

    int sq = (int) sqrt(2 * n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if(vii[i].first > sq) break;
        for (int j = i+1; j < n; j++) {
            // cout << vii[i].first << " " << vii[j].first << endl;
            if(vii[i].first * vii[j].first == (vii[i].second + vii[j].second)) ans++;
            else if(vii[i].first * vii[j].first > 2 * n) break;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tcs;
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}
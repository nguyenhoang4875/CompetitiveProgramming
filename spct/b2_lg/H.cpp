#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, s;

void solve() {
    cin >> s >> n;
    vector<pair<int, int>> v(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = {x, y};
    }
    sort(v.begin(), v.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.first == p2.first) return p1.second > p2.second;
        else return p1.first < p2.first;
    });
    int i = 0;
    for (i = 0; i < n; i++) {
        if(s > v[i].first) {
            s += v[i].second;
        } else break;
    }
    if(i == n) cout << "YES" << endl;
    else cout << "NO" << endl;

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
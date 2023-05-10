#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    vector<pair<int, int>> v(n);
    int a, b;
    for (int i = 0; i < n ; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.second == p2.second) return p1.first > p2.first;
        else return p1.second > p2.second;
    });

    int tb = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if(tb > 0) {
            tb--;
            sum += v[i].first;
            tb += v[i].second;
        } else {
            break;
        }
    }
    cout << sum << endl;
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
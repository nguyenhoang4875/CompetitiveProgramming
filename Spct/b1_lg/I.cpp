#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, c;

void solve() {
    cin >> n >> c;
    vector<pair<int, int>> v(n);
    int a, b;
    for (int i = 0; i < n ; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.first == p2.first) return p1.second > p2.second; 
        else return p1.first < p2.first;
    });
    if(c < v[0].first) {
        cout << 0 << endl;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(c >= v[i].first) {
            cnt++;
            c += v[i].second;
        } else {
            break;
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
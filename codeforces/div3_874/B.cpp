#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k;

void solve() {
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a[i] = {i, x};
    }
    sort(a.begin(), a.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    });

    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b.begin(), b.end());

    bool check = true;
    for (int i = 0; i < n; i++) {
        a[i].second = b[i];
    }
    sort(a.begin(), a.end(), [&](pair<int, int> p1, pair<int, int> p2) {
       return p1.first < p2.first;
    });

    for (auto e: a) {
        cout << e.second << " ";
    }
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
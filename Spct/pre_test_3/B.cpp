#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[105];
int l, r;
int oo = 1e9;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> l >> r;
    sort(a + 1, a + n + 1);

    vector<pair<int , int>> ans;
    // for left value
    int i = l;
    int minI = oo;
    for(int k = 1; k <= n; k++) {
        minI = min(minI, abs(a[k] - i));
    }
    ans.push_back({i, minI});

    // for right value
    i = r;
    minI = oo;
    for(int k = 1; k <= n; k++) {
        minI = min(minI, abs(a[k] - i));
    }
    ans.push_back({i, minI});

    // for other cases
    for(int i = 1; i < n; i++) {
        int dist = a[i+1] - a[i];
        int val = a[i] + dist / 2;
        if(l <= val && val <= r) ans.push_back({val, dist / 2});
    }

    sort(ans.begin(), ans.end(), [&](pair<int, int> e1, pair<int, int> e2) {
        if(e1.second == e2.second) return e1.first < e2.first;
        return e1.second > e2.second;
    });
    cout << ans[0].first << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
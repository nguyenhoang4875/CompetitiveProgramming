#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, t;
int a[55], b[55];

struct video {
    int index, time, value;
};

void solve() {
    cin >> n >> t;
    int tmp = 0;
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
        a[i] += tmp;
        tmp++;
    } 
    for (int i = 1; i <= n ; i++) cin >> b[i];
    vector<video> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = {i, a[i], b[i]};
    }

    sort(v.begin() + 1, v.end(), [&](video v1, video v2) {
        if(v1.value == v2.value) {
            return v1.time < v2.time;
        }
        return v1.value > v2.value;
    });
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if(v[i].time <= t) {
            ans = v[i].index;
            break;
        }
    }
    cout << ans << endl;
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
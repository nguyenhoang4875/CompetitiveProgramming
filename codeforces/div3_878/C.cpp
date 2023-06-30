#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k, q;
int a[200005];
vector<int> v;
int ans;

void solve() {
    cin >> n >> k >> q;
    
    v.clear();
    int cnt;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(a[i] <= q) {
            cnt = 1;
            while(++i <= n && a[i] <= q) cnt++;
            if(cnt >= k) v.push_back(cnt);
        }
    }
    ans = 0;
    for(int num: v) {
        for(int i = k; i <= num; i++) {
            ans += num - i + 1;
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
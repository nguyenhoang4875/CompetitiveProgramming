#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int n, k;
int a[200005];

bool check(int x) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > x) {
            cnt += a[i] / x;
            if(a[i] % x == 0) cnt--;
            if(cnt > k) return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];




    int l = 1;
    int r = *max_element(a + 1, a + n + 1);
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
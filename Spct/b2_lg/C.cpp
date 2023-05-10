#include<bits/stdc++.h>
#define int long long

using namespace std;
int INF = 2e9;

int tcs, n;
int a[200005];
int b[200005];

int binary_search(int val) {
    int l = 1;
    int r = n;
    int mid;
    int ans = INF;
    while (l <= r) {
        mid =  l + (r - l) / 2;
       if(b[mid] < val * mid) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    } 
    return ans;
}

void solve() {
    cin >> n; 
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
    };
    sort(a+ 1, a + n +1);
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = b[i-1] + a[i]; 
    }
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        int ans = binary_search(x);
        if(ans != INF) {
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
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
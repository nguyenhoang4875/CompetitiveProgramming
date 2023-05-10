#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[100005];

bool binary_search(int val) {
    int l = 1;
    int r = n;
    int mid;
    while (l <= r) {
        mid =  l + (r - l) / 2;
        if(a[mid] == val) {
            return true;
        } else if(val < a[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    } 
    return false;
}

void solve() {
    cin >> n; 
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
    };
    sort(a+ 1, a + n +1);
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        if(binary_search(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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
#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

int getBit(int n, int k) {
    return  n & (1 << (k-1));
}

void solve() {
    cin >> n;
    for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
        string ans = "";
        for (int i = n ; i >= 1 ; i--) {
          if(getBit(bitmask, i)) ans += "1";
          else ans += "0";
        }
        cout << ans << endl;
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
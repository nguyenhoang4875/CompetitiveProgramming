#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1794/problem/C
*/
int tcs, n;

void solve() {
    cin >> n; 
    int a[n+1];
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    int ans[n+1];
    ans[1] = 1;
    for (int k = 2; k <= n ; k++ ) {
        int len = ans[k-1] + 1; // get max len before + 1;
        for (int i = k -  ans[k - 1]; i <= k; i++) {
            if(a[i] < len) {
                len--;
            } else {
                ans[k] = len;
                break;
            }
        }
    }
    for (int i = 1; i <= n ; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tcs;
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}
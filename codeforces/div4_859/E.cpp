#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1807/problem/E
*/

int tcs, n;

void solve() {
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = a[i-1] + x;
    }
    int l = 1, r = n;
    int res = 0;

    while (l <= r) {
        string cmd = "?";
        int k = (r - l) / 2 +1;
        int mid = l + (r - l) / 2;
        cmd+= (k+1);
        for (int i = l; i <= mid; i++) {
            cmd += i;
        }
        cout << cmd;
        // printf("%s", cmd);
        cin >> res;
        if(res == a[mid] - a[l-1]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        if(a[mid] == a[mid] - a[mid -1]) {
            cout << "!" << mid;
            return;
        }

    }
    cout << fflush;
      
}

int main() {

    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}
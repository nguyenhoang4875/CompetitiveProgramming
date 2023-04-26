#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1807/problem/A
*/

int tcs, n, q;



void solve() {
    cin >> n;
    cin >> q;
    int l, r, k;

    vector<long long> a(n+2, 0);
    a[0] = 0;
    vector<long long> pre(n+2, 0);
    vector<long long> sub(n+2, 0);
    pre[1] = 0;
    pre[0] = 0;
    sub[n] = 0;


    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n ; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }

    for (int i = n; i >= 1 ; i--) {
        sub[i] = sub[i+1] + a[i+1];
    }

    long long sum = 0;
    while (q-- > 0) {
    cin >> l >>  r >> k;
        sum = pre[l] + sub[r] + (r - l + 1) * k;
        if(sum % 2 != 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
      
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}
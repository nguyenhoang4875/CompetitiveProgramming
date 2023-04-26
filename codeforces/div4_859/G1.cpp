#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1807/problem/G1
*/

int tcs, n, q;



void solve() {
    cin >> n;
    vector<int> a(n);
    int ma = 0;
    long long sum = 0;
    for (int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        sum += x;
        ma = max(ma, x);
        // a[i] = x;
    }
    
    if(ma <= n && sum <= n * (n+1) / 2) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
      
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
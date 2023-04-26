#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1807/problem/A
*/

int tcs, n;

void solve() {
    int sa = 0, sb = 0;
    cin >> n;
    for (int i = 1; i <= n ; i++) {
        int x;
        cin >> x;
        if(x % 2 == 0) sa += x;
        else sb += x;
    }
    if(sa > sb) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
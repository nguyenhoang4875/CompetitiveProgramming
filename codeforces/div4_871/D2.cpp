#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int tcs, n, m;
 
 
 
void solve() {
    cin >> n >> m;
 
    if(3*m == 2*n || 3 * m == n || m == n) {
        cout << "YES" << endl;
        return;
    }
    
    if( m > n || n % 3 != 0) {
        cout << "NO" << endl;
        return;
    }
 
    int a = m , b = m;
    int cnt = 0;
    while (a <= n) {
        int temp = a;
        a = 3 * temp / 2;
        b = 3 * temp;
        if(a == n || b == n) {
            cout << "YES" << endl;
            return;
        }
        if(a == temp) break;
    }
    a = m, b = m;
    while ( b <=  n) {
        int temp = b;
        a *= 3 * temp / 2;
        b *= 3 * temp;
        if(a == n || b == n) {
            cout << "YES" << endl;
            return;
        }
    }
 
    cout << "NO" << endl;
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
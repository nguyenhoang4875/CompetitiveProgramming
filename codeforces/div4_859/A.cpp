#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1807/problem/A
*/

int tcs, n;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a <= c) {
        cout << "+" << endl;
    } else {
        cout << "-" << endl;
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
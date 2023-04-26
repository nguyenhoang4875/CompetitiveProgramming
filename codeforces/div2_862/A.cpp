#include<bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/contest/1805/problem/A
*/

int tcs, n;
int a[1010];

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
        sum ^= a[i];
    }
    if(n % 2 == 0) {
        if(sum == 0)  cout << 0 << endl;
        else cout << -1 << endl;
    } else {
        if(sum <= 256) cout << sum << endl;
        else cout << -1 << endl;

    }

}

int main() {
    cin >> tcs;
    while (tcs--) {
        solve();
    }
        
    return 0;
}
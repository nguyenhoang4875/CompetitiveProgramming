#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/66/problem/D
*/

int tcs, n;
int a[55];

void solve() {
    cin >> n;
    if(n <= 2) {
        cout << "-1\n";
        return;
    }
    a[1] = 2 * 3;
    a[2] = 3 * 5;
    a[3] = 2 * 5;
    int temp = 2 * 3 * 5;
    for(int i = 4; i <= n; i++) {
        a[i] = temp *(i - 3);
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
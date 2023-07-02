#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Count how many wat to fill: 4xN using 1x4 and 4x1 tiles
 * f(n) = f(n - 1) + f(n - 4)
*/

// using recursion, can improve by using dp
int cal(int n) {
    if(n <= 3) return 1; // base case
    return cal(n - 1) + cal(n -4) ;
}

void solve() {
    int n;
    cin >> n;
    cout << cal(n) << endl;;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
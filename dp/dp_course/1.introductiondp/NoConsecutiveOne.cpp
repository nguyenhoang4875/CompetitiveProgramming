#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Number of ways to fill an array with 0s and 1s
 * that there are no consecutive 1s
 * 
 * Solution: f(n) = f(n - 1) + f(n - 2) // same with fibonacci number
*/

int fun(int index, int n, bool previousOne) {
    // base case
    if(index == n + 1) return 1;

    int ans = 0;

    // recursion case
    // either place 0 here
    ans += fun(index + 1, n, false);

    // or place 1 here
    if(previousOne == false) {
        ans += fun(index + 1, n, true);
    }

    return ans;

}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << fun(1, i, false) << '\n';
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}